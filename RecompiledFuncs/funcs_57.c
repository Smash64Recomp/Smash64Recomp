#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftLinkSpecialHiUpdateWeaponPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163B80: lb          $t6, 0x2B5($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X2B5);
    // 0x80163B84: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80163B88: sb          $t7, 0x2B5($a1)
    MEM_B(0X2B5, ctx->r5) = ctx->r15;
    // 0x80163B8C: lb          $t8, 0x2B5($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X2B5);
    // 0x80163B90: bgez        $t8, L_80163BA4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80163B94: andi        $t9, $t8, 0x3
        ctx->r25 = ctx->r24 & 0X3;
            goto L_80163BA4;
    }
    // 0x80163B94: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80163B98: beq         $t9, $zero, L_80163BA4
    if (ctx->r25 == 0) {
        // 0x80163B9C: nop
    
            goto L_80163BA4;
    }
    // 0x80163B9C: nop

    // 0x80163BA0: addiu       $t9, $t9, -0x4
    ctx->r25 = ADD32(ctx->r25, -0X4);
L_80163BA4:
    // 0x80163BA4: sb          $t9, 0x2B5($a1)
    MEM_B(0X2B5, ctx->r5) = ctx->r25;
    // 0x80163BA8: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80163BAC: lb          $t3, 0x2B5($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X2B5);
    // 0x80163BB0: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80163BB4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80163BB8: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80163BBC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80163BC0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80163BC4: nop

    // 0x80163BC8: sh          $t2, 0x29C($t5)
    MEM_H(0X29C, ctx->r13) = ctx->r10;
    // 0x80163BCC: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80163BD0: lb          $t9, 0x2B5($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X2B5);
    // 0x80163BD4: lwc1        $f8, 0x20($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80163BD8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80163BDC: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80163BE0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80163BE4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80163BE8: jr          $ra
    // 0x80163BEC: sh          $t8, 0x2A4($t1)
    MEM_H(0X2A4, ctx->r9) = ctx->r24;
    return;
    // 0x80163BEC: sh          $t8, 0x2A4($t1)
    MEM_H(0X2A4, ctx->r9) = ctx->r24;
;}
RECOMP_FUNC void ftNessSpecialAirLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801554B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801554B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801554B8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801554BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801554C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801554C4: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x801554C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801554CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801554D0: jal         0x800E6F24
    // 0x801554D4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801554D4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801554D8: jal         0x800E0830
    // 0x801554DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801554DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801554E0: jal         0x80155454
    // 0x801554E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftNessSpecialLw_InitStatusVars(rdram, ctx);
        goto after_2;
    // 0x801554E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801554E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801554EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801554F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801554F4: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801554F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801554FC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80155500: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
    // 0x80155504: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x80155508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015550C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80155510: jr          $ra
    // 0x80155514: nop

    return;
    // 0x80155514: nop

;}
RECOMP_FUNC void ftParamSetDamageShuffle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7F8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E7F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7F94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E7F98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800E7F9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E7FA0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800E7FA4: jal         0x800EA1C0
    // 0x800E7FA8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    ftParamGetHitLag(rdram, ctx);
        goto after_0;
    // 0x800E7FA8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800E7FAC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800E7FB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E7FB4: lwc1        $f8, -0x160($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X160);
    // 0x800E7FB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E7FBC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800E7FC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7FC4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E7FC8: sb          $zero, 0x272($v1)
    MEM_B(0X272, ctx->r3) = 0;
    // 0x800E7FCC: sb          $a0, 0x274($v1)
    MEM_B(0X274, ctx->r3) = ctx->r4;
    // 0x800E7FD0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E7FD4: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800E7FD8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800E7FDC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800E7FE0: nop

    // 0x800E7FE4: sh          $t7, 0x276($v1)
    MEM_H(0X276, ctx->r3) = ctx->r15;
    // 0x800E7FE8: lbu         $t8, -0x4850($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4850);
    // 0x800E7FEC: sb          $t8, 0x273($v1)
    MEM_B(0X273, ctx->r3) = ctx->r24;
    // 0x800E7FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7FF8: jr          $ra
    // 0x800E7FFC: nop

    return;
    // 0x800E7FFC: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePortraitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132D64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80132D68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80132D6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132D70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80132D74: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
L_80132D78:
    // 0x80132D78: jal         0x80132BA4
    // 0x80132D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameMakePortrait(rdram, ctx);
        goto after_0;
    // 0x80132D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80132D80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80132D84: bne         $s0, $s1, L_80132D78
    if (ctx->r16 != ctx->r17) {
        // 0x80132D88: nop
    
            goto L_80132D78;
    }
    // 0x80132D88: nop

    // 0x80132D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132D90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80132D94: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80132D98: jr          $ra
    // 0x80132D9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80132D9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void grYosterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80108964: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80108968: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8010896C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80108970: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80108974: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80108978: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010897C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80108980: addiu       $s1, $s1, 0x13F0
    ctx->r17 = ADD32(ctx->r17, 0X13F0);
    // 0x80108984: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80108988: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8010898C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_80108990:
    // 0x80108990: lbu         $v0, 0x1C($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1C);
    // 0x80108994: beq         $v0, $zero, L_801089AC
    if (ctx->r2 == 0) {
        // 0x80108998: nop
    
            goto L_801089AC;
    }
    // 0x80108998: nop

    // 0x8010899C: beq         $v0, $s2, L_801089BC
    if (ctx->r2 == ctx->r18) {
        // 0x801089A0: nop
    
            goto L_801089BC;
    }
    // 0x801089A0: nop

    // 0x801089A4: b           L_801089C4
    // 0x801089A8: nop

        goto L_801089C4;
    // 0x801089A8: nop

L_801089AC:
    // 0x801089AC: jal         0x80108634
    // 0x801089B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    grYosterUpdateCloudSolid(rdram, ctx);
        goto after_0;
    // 0x801089B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801089B4: b           L_801089C4
    // 0x801089B8: nop

        goto L_801089C4;
    // 0x801089B8: nop

L_801089BC:
    // 0x801089BC: jal         0x80108814
    // 0x801089C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    grYosterUpdateCloudEvaporate(rdram, ctx);
        goto after_1;
    // 0x801089C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_801089C4:
    // 0x801089C4: jal         0x80108890
    // 0x801089C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    grYosterUpdateCloudAnim(rdram, ctx);
        goto after_2;
    // 0x801089C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801089CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801089D0: bne         $s0, $s3, L_80108990
    if (ctx->r16 != ctx->r19) {
        // 0x801089D4: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80108990;
    }
    // 0x801089D4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x801089D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801089DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801089E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801089E4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801089E8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801089EC: jr          $ra
    // 0x801089F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801089F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80026174_26D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026174: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026178: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002617C: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x80026180: bnel        $at, $zero, L_80026190
    if (ctx->r1 != 0) {
        // 0x80026184: lw          $v0, 0x28($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X28);
            goto L_80026190;
    }
    goto skip_0;
    // 0x80026184: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    skip_0:
    // 0x80026188: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x8002618C: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
L_80026190:
    // 0x80026190: sb          $a1, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r5;
    // 0x80026194: beq         $v0, $zero, L_800261B0
    if (ctx->r2 == 0) {
        // 0x80026198: nop
    
            goto L_800261B0;
    }
    // 0x80026198: nop

    // 0x8002619C: lbu         $t6, 0x22($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X22);
    // 0x800261A0: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800261A4: mflo        $t7
    ctx->r15 = lo;
    // 0x800261A8: sra         $t8, $t7, 7
    ctx->r24 = S32(SIGNED(ctx->r15) >> 7);
    // 0x800261AC: sb          $t8, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r24;
L_800261B0:
    // 0x800261B0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800261B4: lw          $v0, -0x11F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X11F0);
    // 0x800261B8: beq         $v0, $zero, L_800261FC
    if (ctx->r2 == 0) {
        // 0x800261BC: nop
    
            goto L_800261FC;
    }
    // 0x800261BC: nop

L_800261C0:
    // 0x800261C0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800261C4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800261C8: bne         $a0, $t9, L_800261F4
    if (ctx->r4 != ctx->r25) {
        // 0x800261CC: nop
    
            goto L_800261F4;
    }
    // 0x800261CC: nop

    // 0x800261D0: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    // 0x800261D4: sb          $a1, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r5;
    // 0x800261D8: beq         $a2, $zero, L_800261F4
    if (ctx->r6 == 0) {
        // 0x800261DC: nop
    
            goto L_800261F4;
    }
    // 0x800261DC: nop

    // 0x800261E0: lbu         $t0, 0x22($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X22);
    // 0x800261E4: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800261E8: mflo        $t1
    ctx->r9 = lo;
    // 0x800261EC: sra         $t2, $t1, 7
    ctx->r10 = S32(SIGNED(ctx->r9) >> 7);
    // 0x800261F0: sb          $t2, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r10;
L_800261F4:
    // 0x800261F4: bne         $v1, $zero, L_800261C0
    if (ctx->r3 != 0) {
        // 0x800261F8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800261C0;
    }
    // 0x800261F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800261FC:
    // 0x800261FC: jr          $ra
    // 0x80026200: nop

    return;
    // 0x80026200: nop

;}
RECOMP_FUNC void func_ovl8_8037C1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C1AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C1B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8037C1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C1B8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037C1BC: jal         0x80375D54
    // 0x8037C1C0: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
    func_ovl8_80375D54(rdram, ctx);
        goto after_0;
    // 0x8037C1C0: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
    after_0:
    // 0x8037C1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C1C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C1CC: jr          $ra
    // 0x8037C1D0: nop

    return;
    // 0x8037C1D0: nop

;}
RECOMP_FUNC void func_ovl8_8037A9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A9F4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8037A9F8: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8037A9FC: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8037AA00: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x8037AA04: lhu         $t9, 0x4($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X4);
    // 0x8037AA08: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8037AA0C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8037AA10: sh          $t0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r8;
    // 0x8037AA14: lhu         $t2, 0x6($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X6);
    // 0x8037AA18: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x8037AA1C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8037AA20: jr          $ra
    // 0x8037AA24: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
    return;
    // 0x8037AA24: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
;}
RECOMP_FUNC void ftNessSpecialLwDecReleaseLag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155204: lw          $v0, 0xB18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB18);
    // 0x80155208: beq         $v0, $zero, L_80155214
    if (ctx->r2 == 0) {
        // 0x8015520C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80155214;
    }
    // 0x8015520C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80155210: sw          $t6, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r14;
L_80155214:
    // 0x80155214: jr          $ra
    // 0x80155218: nop

    return;
    // 0x80155218: nop

;}
RECOMP_FUNC void ftNessSpecialHiJibakuInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154DBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80154DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80154DC4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80154DC8: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x80154DCC: sw          $t6, 0xB28($v0)
    MEM_W(0XB28, ctx->r2) = ctx->r14;
    // 0x80154DD0: jal         0x80154758
    // 0x80154DD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftNessSpecialHiUpdateModelPitch(rdram, ctx);
        goto after_0;
    // 0x80154DD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80154DD8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80154DDC: lw          $t7, 0x9C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C8);
    // 0x80154DE0: sw          $zero, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = 0;
    // 0x80154DE4: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x80154DE8: sb          $t8, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r24;
    // 0x80154DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80154DF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154DF4: jr          $ra
    // 0x80154DF8: nop

    return;
    // 0x80154DF8: nop

;}
RECOMP_FUNC void func_ovl8_803720D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803720D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803720D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803720DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803720E0: beq         $a0, $zero, L_8037216C
    if (ctx->r4 == 0) {
        // 0x803720E4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8037216C;
    }
    // 0x803720E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803720E8: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x803720EC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803720F0: addiu       $t6, $t6, -0x7520
    ctx->r14 = ADD32(ctx->r14, -0X7520);
    // 0x803720F4: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803720F8: addiu       $t7, $t7, -0x74C0
    ctx->r15 = ADD32(ctx->r15, -0X74C0);
    // 0x803720FC: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x80372100: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80372104: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80372108: beql        $a0, $zero, L_80372120
    if (ctx->r4 == 0) {
        // 0x8037210C: lw          $a0, 0x4($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X4);
            goto L_80372120;
    }
    goto skip_0;
    // 0x8037210C: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    skip_0:
    // 0x80372110: jal         0x80009A84
    // 0x80372114: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80372114: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80372118: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8037211C: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
L_80372120:
    // 0x80372120: beql        $a0, $zero, L_80372138
    if (ctx->r4 == 0) {
        // 0x80372124: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80372138;
    }
    goto skip_1;
    // 0x80372124: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80372128: jal         0x80009A84
    // 0x8037212C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x8037212C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80372130: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80372134: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_80372138:
    // 0x80372138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037213C: beql        $t9, $zero, L_80372158
    if (ctx->r25 == 0) {
        // 0x80372140: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80372158;
    }
    goto skip_2;
    // 0x80372140: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80372144: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    // 0x80372148: jal         0x803718C4
    // 0x8037214C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x8037214C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80372150: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80372154: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_80372158:
    // 0x80372158: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8037215C: beql        $t1, $zero, L_80372170
    if (ctx->r9 == 0) {
        // 0x80372160: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80372170;
    }
    goto skip_3;
    // 0x80372160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80372164: jal         0x803717C0
    // 0x80372168: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x80372168: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
L_8037216C:
    // 0x8037216C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80372170:
    // 0x80372170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372174: jr          $ra
    // 0x80372178: nop

    return;
    // 0x80372178: nop

;}
RECOMP_FUNC void ftComputerGetOwnWeaponPositionKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B44: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80131B48: lw          $v0, 0x6704($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6704);
    // 0x80131B4C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80131B50: beql        $v0, $zero, L_80131B98
    if (ctx->r2 == 0) {
        // 0x80131B54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80131B98;
    }
    goto skip_0;
    // 0x80131B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80131B58: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80131B5C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_80131B60:
    // 0x80131B60: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80131B64: bnel        $a1, $t6, L_80131B8C
    if (ctx->r5 != ctx->r14) {
        // 0x80131B68: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80131B8C;
    }
    goto skip_1;
    // 0x80131B68: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x80131B6C: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x80131B70: bnel        $a2, $t7, L_80131B8C
    if (ctx->r6 != ctx->r15) {
        // 0x80131B74: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80131B8C;
    }
    goto skip_2;
    // 0x80131B74: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x80131B78: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80131B7C: lw          $v0, 0x74($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X74);
    // 0x80131B80: jr          $ra
    // 0x80131B84: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    return;
    // 0x80131B84: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80131B88: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80131B8C:
    // 0x80131B8C: bnel        $v0, $zero, L_80131B60
    if (ctx->r2 != 0) {
        // 0x80131B90: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_80131B60;
    }
    goto skip_3;
    // 0x80131B90: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_3:
    // 0x80131B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131B98:
    // 0x80131B98: jr          $ra
    // 0x80131B9C: nop

    return;
    // 0x80131B9C: nop

;}
RECOMP_FUNC void ftCommonWaitCheckInputSuccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E258: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013E25C: lb          $v1, 0x1C2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C2);
    // 0x8013E260: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x8013E264: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013E268: mflo        $t7
    ctx->r15 = lo;
    // 0x8013E26C: bltz        $t7, L_8013E290
    if (SIGNED(ctx->r15) < 0) {
        // 0x8013E270: nop
    
            goto L_8013E290;
    }
    // 0x8013E270: nop

    // 0x8013E274: bgez        $v1, L_8013E284
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8013E278: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8013E284;
    }
    // 0x8013E278: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013E27C: b           L_8013E284
    // 0x8013E280: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8013E284;
    // 0x8013E280: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8013E284:
    // 0x8013E284: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8013E288: beq         $at, $zero, L_8013E298
    if (ctx->r1 == 0) {
        // 0x8013E28C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013E298;
    }
    // 0x8013E28C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013E290:
    // 0x8013E290: jr          $ra
    // 0x8013E294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013E294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013E298:
    // 0x8013E298: jr          $ra
    // 0x8013E29C: nop

    return;
    // 0x8013E29C: nop

;}
RECOMP_FUNC void mnPlayers1PGameDetectBack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136D04: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136D08: lw          $t6, -0x708C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X708C);
    // 0x80136D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136D14: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80136D18: bne         $at, $zero, L_80136D48
    if (ctx->r1 != 0) {
        // 0x80136D1C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_80136D48;
    }
    // 0x80136D1C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80136D20: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80136D24: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80136D28: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80136D2C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80136D30: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x80136D34: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x80136D38: beql        $t9, $zero, L_80136D4C
    if (ctx->r25 == 0) {
        // 0x80136D3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136D4C;
    }
    goto skip_0;
    // 0x80136D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80136D40: jal         0x80136CB8
    // 0x80136D44: nop

    mnPlayers1PGameBackTo1PMode(rdram, ctx);
        goto after_0;
    // 0x80136D44: nop

    after_0:
L_80136D48:
    // 0x80136D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136D4C:
    // 0x80136D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136D50: jr          $ra
    // 0x80136D54: nop

    return;
    // 0x80136D54: nop

;}
RECOMP_FUNC void ftCommonCliffWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144DAC: jal         0x80145620
    // 0x80144DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonCliffAttackCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x80144DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80144DB4: bnel        $v0, $zero, L_80144DE8
    if (ctx->r2 != 0) {
        // 0x80144DB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144DE8;
    }
    goto skip_0;
    // 0x80144DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80144DBC: jal         0x801457E0
    // 0x80144DC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonCliffEscapeCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80144DC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80144DC4: bnel        $v0, $zero, L_80144DE8
    if (ctx->r2 != 0) {
        // 0x80144DC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144DE8;
    }
    goto skip_1;
    // 0x80144DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80144DCC: jal         0x80145084
    // 0x80144DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonCliffClimbOrFallCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x80144DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80144DD4: bnel        $v0, $zero, L_80144DE8
    if (ctx->r2 != 0) {
        // 0x80144DD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144DE8;
    }
    goto skip_2;
    // 0x80144DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80144DDC: jal         0x80144E84
    // 0x80144DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonCliffWaitCheckFall(rdram, ctx);
        goto after_3;
    // 0x80144DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80144DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144DE8:
    // 0x80144DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144DEC: jr          $ra
    // 0x80144DF0: nop

    return;
    // 0x80144DF0: nop

;}
RECOMP_FUNC void syMatrixSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B780: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8001B784: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B788: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001B78C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001B790: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8001B794: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001B798: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x8001B79C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8001B7A0: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001B7A4: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8001B7A8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8001B7AC: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8001B7B0: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8001B7B4: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x8001B7B8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001B7BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001B7C0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001B7C4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8001B7C8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8001B7CC: and         $t7, $v0, $a2
    ctx->r15 = ctx->r2 & ctx->r6;
    // 0x8001B7D0: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8001B7D4: sra         $t0, $v1, 16
    ctx->r8 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001B7D8: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x8001B7DC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001B7E0: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8001B7E4: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x8001B7E8: sw          $t1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r9;
    // 0x8001B7EC: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001B7F0: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8001B7F4: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x8001B7F8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001B7FC: sw          $t5, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r13;
    // 0x8001B800: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8001B804: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001B808: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8001B80C: nop

    // 0x8001B810: and         $t3, $a1, $a2
    ctx->r11 = ctx->r5 & ctx->r6;
    // 0x8001B814: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x8001B818: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
    // 0x8001B81C: jr          $ra
    // 0x8001B820: sw          $t4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r12;
    return;
    // 0x8001B820: sw          $t4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void itFushigibanaWeaponRazorProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184970: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80184974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184978: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018497C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80184980: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80184984: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x80184988: jal         0x801680EC
    // 0x8018498C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8018498C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80184990: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80184994: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80184998: jal         0x8001863C
    // 0x8018499C: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8018499C: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x801849A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801849A4: lwc1        $f4, -0x30C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30C8);
    // 0x801849A8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801849AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801849B0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801849B4: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x801849B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801849BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801849C0: swc1        $f6, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f6.u32l;
    // 0x801849C4: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x801849C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801849CC: swc1        $f8, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f8.u32l;
    // 0x801849D0: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x801849D4: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x801849D8: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x801849DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801849E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801849E4: jr          $ra
    // 0x801849E8: nop

    return;
    // 0x801849E8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetCSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334C0: addiu       $at, $zero, 0xE10
    ctx->r1 = ADD32(0, 0XE10);
    // 0x801334C4: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x801334C8: mfhi        $v1
    ctx->r3 = hi;
    // 0x801334CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801334D0: nop

    // 0x801334D4: div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // 0x801334D8: bne         $a1, $zero, L_801334E4
    if (ctx->r5 != 0) {
        // 0x801334DC: nop
    
            goto L_801334E4;
    }
    // 0x801334DC: nop

    // 0x801334E0: break       7
    do_break(2148742368);
L_801334E4:
    // 0x801334E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801334E8: bne         $a1, $at, L_801334FC
    if (ctx->r5 != ctx->r1) {
        // 0x801334EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801334FC;
    }
    // 0x801334EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801334F0: bne         $v1, $at, L_801334FC
    if (ctx->r3 != ctx->r1) {
        // 0x801334F4: nop
    
            goto L_801334FC;
    }
    // 0x801334F4: nop

    // 0x801334F8: break       6
    do_break(2148742392);
L_801334FC:
    // 0x801334FC: mfhi        $t6
    ctx->r14 = hi;
    // 0x80133500: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133504: lwc1        $f8, 0x75E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75E0);
    // 0x80133508: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8013350C: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80133510: mfhi        $t9
    ctx->r25 = hi;
    // 0x80133514: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80133518: nop

    // 0x8013351C: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x80133520: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133524: mflo        $t0
    ctx->r8 = lo;
    // 0x80133528: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8013352C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80133530: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80133534: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80133538: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8013353C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80133540: bne         $a1, $zero, L_8013354C
    if (ctx->r5 != 0) {
        // 0x80133544: nop
    
            goto L_8013354C;
    }
    // 0x80133544: nop

    // 0x80133548: break       7
    do_break(2148742472);
L_8013354C:
    // 0x8013354C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133550: bne         $a1, $at, L_80133564
    if (ctx->r5 != ctx->r1) {
        // 0x80133554: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133564;
    }
    // 0x80133554: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133558: bne         $t9, $at, L_80133564
    if (ctx->r25 != ctx->r1) {
        // 0x8013355C: nop
    
            goto L_80133564;
    }
    // 0x8013355C: nop

    // 0x80133560: break       6
    do_break(2148742496);
L_80133564:
    // 0x80133564: addu        $v0, $t1, $t8
    ctx->r2 = ADD32(ctx->r9, ctx->r24);
    // 0x80133568: jr          $ra
    // 0x8013356C: nop

    return;
    // 0x8013356C: nop

;}
RECOMP_FUNC void ftParamModifyDamageCollID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8BC8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E8BCC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800E8BD0: addiu       $v1, $zero, 0x1E4
    ctx->r3 = ADD32(0, 0X1E4);
    // 0x800E8BD4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_800E8BD8:
    // 0x800E8BD8: lw          $t6, 0x5C0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X5C0);
    // 0x800E8BDC: addiu       $t0, $t0, 0x2C
    ctx->r8 = ADD32(ctx->r8, 0X2C);
    // 0x800E8BE0: bne         $a1, $t6, L_800E8C60
    if (ctx->r5 != ctx->r14) {
        // 0x800E8BE4: nop
    
            goto L_800E8C60;
    }
    // 0x800E8BE4: nop

    // 0x800E8BE8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800E8BEC: addiu       $v1, $t1, 0x5BC
    ctx->r3 = ADD32(ctx->r9, 0X5BC);
    // 0x800E8BF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800E8BF4: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x800E8BF8: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800E8BFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E8C00: sw          $t7, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r15;
    // 0x800E8C04: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x800E8C08: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x800E8C0C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800E8C10: sw          $t2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r10;
    // 0x800E8C14: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800E8C18: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x800E8C1C: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800E8C20: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x800E8C24: lwc1        $f4, 0x5DC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X5DC);
    // 0x800E8C28: lwc1        $f8, 0x5E0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X5E0);
    // 0x800E8C2C: lwc1        $f16, 0x5E4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X5E4);
    // 0x800E8C30: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800E8C34: nop

    // 0x800E8C38: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E8C3C: nop

    // 0x800E8C40: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800E8C44: swc1        $f6, 0x5DC($t1)
    MEM_W(0X5DC, ctx->r9) = ctx->f6.u32l;
    // 0x800E8C48: swc1        $f10, 0x5E0($t1)
    MEM_W(0X5E0, ctx->r9) = ctx->f10.u32l;
    // 0x800E8C4C: swc1        $f18, 0x5E4($t1)
    MEM_W(0X5E4, ctx->r9) = ctx->f18.u32l;
    // 0x800E8C50: lbu         $t4, 0x18C($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E8C54: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x800E8C58: jr          $ra
    // 0x800E8C5C: sb          $t5, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r13;
    return;
    // 0x800E8C5C: sb          $t5, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r13;
L_800E8C60:
    // 0x800E8C60: bne         $t0, $v1, L_800E8BD8
    if (ctx->r8 != ctx->r3) {
        // 0x800E8C64: addiu       $t1, $t1, 0x2C
        ctx->r9 = ADD32(ctx->r9, 0X2C);
            goto L_800E8BD8;
    }
    // 0x800E8C64: addiu       $t1, $t1, 0x2C
    ctx->r9 = ADD32(ctx->r9, 0X2C);
    // 0x800E8C68: jr          $ra
    // 0x800E8C6C: nop

    return;
    // 0x800E8C6C: nop

;}
RECOMP_FUNC void func_ovl8_803820B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803820B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803820B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803820B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803820BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803820C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803820C4: bne         $a0, $zero, L_803820DC
    if (ctx->r4 != 0) {
        // 0x803820C8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_803820DC;
    }
    // 0x803820C8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803820CC: jal         0x803717A0
    // 0x803820D0: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803820D0: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x803820D4: beq         $v0, $zero, L_80382148
    if (ctx->r2 == 0) {
        // 0x803820D8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80382148;
    }
    // 0x803820D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803820DC:
    // 0x803820DC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x803820E0: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x803820E4: addiu       $a1, $s0, 0x9C
    ctx->r5 = ADD32(ctx->r16, 0X9C);
    // 0x803820E8: bnel        $t6, $zero, L_8038210C
    if (ctx->r14 != 0) {
        // 0x803820EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8038210C;
    }
    goto skip_0;
    // 0x803820EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x803820F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803820F4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x803820F8: jal         0x803717E0
    // 0x803820FC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803820FC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80382100: jal         0x8037C2D0
    // 0x80382104: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80382104: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80382108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8038210C:
    // 0x8038210C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80382110: jal         0x803733AC
    // 0x80382114: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803733AC(rdram, ctx);
        goto after_3;
    // 0x80382114: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80382118: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038211C: addiu       $t7, $t7, -0x42E0
    ctx->r15 = ADD32(ctx->r15, -0X42E0);
    // 0x80382120: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80382124: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80382128: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038212C: addiu       $t8, $t8, -0x4210
    ctx->r24 = ADD32(ctx->r24, -0X4210);
    // 0x80382130: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80382134: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80382138: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8038213C: addiu       $t0, $t0, -0x40B8
    ctx->r8 = ADD32(ctx->r8, -0X40B8);
    // 0x80382140: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x80382144: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_80382148:
    // 0x80382148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8038214C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80382154: jr          $ra
    // 0x80382158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80382158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itMainClearColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80172FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80172FC4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80172FC8: jal         0x800E9838
    // 0x80172FCC: addiu       $a0, $v0, 0x2D8
    ctx->r4 = ADD32(ctx->r2, 0X2D8);
    ftParamResetColAnim(rdram, ctx);
        goto after_0;
    // 0x80172FCC: addiu       $a0, $v0, 0x2D8
    ctx->r4 = ADD32(ctx->r2, 0X2D8);
    after_0:
    // 0x80172FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80172FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80172FD8: jr          $ra
    // 0x80172FDC: nop

    return;
    // 0x80172FDC: nop

;}
RECOMP_FUNC void grDisplayLayer0PriProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104D90: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80104D94: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80104D98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104D9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104DA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104DA4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104DA8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104DAC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80104DB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104DB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104DB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104DBC: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x80104DC0: ori         $t9, $t9, 0xFFFE
    ctx->r25 = ctx->r25 | 0XFFFE;
    // 0x80104DC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104DC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104DCC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104DD0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104DD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104DD8: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x80104DDC: lui         $t2, 0x55
    ctx->r10 = S32(0X55 << 16);
    // 0x80104DE0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80104DE4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80104DE8: ori         $t2, $t2, 0x2048
    ctx->r10 = ctx->r10 | 0X2048;
    // 0x80104DEC: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x80104DF0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80104DF4: jal         0x80014038
    // 0x80104DF8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x80104DF8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_0:
    // 0x80104DFC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80104E00: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80104E04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104E08: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80104E0C: lui         $t6, 0xD9FF
    ctx->r14 = S32(0XD9FF << 16);
    // 0x80104E10: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80104E14: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80104E18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104E1C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80104E20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104E24: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80104E28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80104E2C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80104E30: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80104E34: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80104E38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104E3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104E40: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80104E44: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x80104E48: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104E4C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104E50: ori         $t0, $t0, 0x2078
    ctx->r8 = ctx->r8 | 0X2078;
    // 0x80104E54: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80104E58: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104E5C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80104E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104E68: jr          $ra
    // 0x80104E6C: nop

    return;
    // 0x80104E6C: nop

;}
RECOMP_FUNC void lbParticleAllocStructs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE418: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CE41C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CE420: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800CE424: addiu       $s1, $s1, 0x6350
    ctx->r17 = ADD32(ctx->r17, 0X6350);
    // 0x800CE428: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CE42C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CE430: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CE434: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CE438: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800CE43C: addiu       $v1, $v1, 0x6398
    ctx->r3 = ADD32(ctx->r3, 0X6398);
    // 0x800CE440: addiu       $v0, $v0, 0x6358
    ctx->r2 = ADD32(ctx->r2, 0X6358);
L_800CE444:
    // 0x800CE444: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800CE448: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800CE44C: bne         $at, $zero, L_800CE444
    if (ctx->r1 != 0) {
        // 0x800CE450: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800CE444;
    }
    // 0x800CE450: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800CE454: addiu       $s0, $a0, -0x1
    ctx->r16 = ADD32(ctx->r4, -0X1);
    // 0x800CE458: bltz        $s0, L_800CE490
    if (SIGNED(ctx->r16) < 0) {
        // 0x800CE45C: addiu       $a0, $zero, 0x60
        ctx->r4 = ADD32(0, 0X60);
            goto L_800CE490;
    }
L_800CE45C:
    // 0x800CE45C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CE460: jal         0x80004980
    // 0x800CE464: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800CE464: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800CE468: bnel        $v0, $zero, L_800CE47C
    if (ctx->r2 != 0) {
        // 0x800CE46C: lw          $t6, 0x0($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X0);
            goto L_800CE47C;
    }
    goto skip_0;
    // 0x800CE46C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x800CE470: b           L_800CE4D0
    // 0x800CE474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CE4D0;
    // 0x800CE474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CE478: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_800CE47C:
    // 0x800CE47C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800CE480: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CE484: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800CE488: bgez        $s0, L_800CE45C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800CE48C: sw          $v0, 0x6350($at)
        MEM_W(0X6350, ctx->r1) = ctx->r2;
            goto L_800CE45C;
    }
    // 0x800CE48C: sw          $v0, 0x6350($at)
    MEM_W(0X6350, ctx->r1) = ctx->r2;
L_800CE490:
    // 0x800CE490: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CE494: sh          $zero, 0x6448($at)
    MEM_H(0X6448, ctx->r1) = 0;
    // 0x800CE498: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CE49C: sh          $zero, 0x644E($at)
    MEM_H(0X644E, ctx->r1) = 0;
    // 0x800CE4A0: jal         0x8000B198
    // 0x800CE4A4: addiu       $a0, $zero, -0x6
    ctx->r4 = ADD32(0, -0X6);
    gcFindGObjByID(rdram, ctx);
        goto after_1;
    // 0x800CE4A4: addiu       $a0, $zero, -0x6
    ctx->r4 = ADD32(0, -0X6);
    after_1:
    // 0x800CE4A8: beq         $v0, $zero, L_800CE4B8
    if (ctx->r2 == 0) {
        // 0x800CE4AC: nop
    
            goto L_800CE4B8;
    }
    // 0x800CE4AC: nop

    // 0x800CE4B0: b           L_800CE4D0
    // 0x800CE4B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CE4D0;
    // 0x800CE4B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE4B8:
    // 0x800CE4B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CE4BC: addiu       $a1, $a1, 0xC74
    ctx->r5 = ADD32(ctx->r5, 0XC74);
    // 0x800CE4C0: addiu       $a0, $zero, -0x6
    ctx->r4 = ADD32(0, -0X6);
    // 0x800CE4C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CE4C8: jal         0x80009968
    // 0x800CE4CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x800CE4CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
L_800CE4D0:
    // 0x800CE4D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE4D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CE4D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CE4DC: jr          $ra
    // 0x800CE4E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800CE4E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbySpecialAirNTurnProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162998: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8016299C: jal         0x800DE6E4
    // 0x801629A0: addiu       $a1, $a1, 0x2E70
    ctx->r5 = ADD32(ctx->r5, 0X2E70);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801629A0: addiu       $a1, $a1, 0x2E70
    ctx->r5 = ADD32(ctx->r5, 0X2E70);
    after_0:
    // 0x801629A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801629A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801629AC: jr          $ra
    // 0x801629B0: nop

    return;
    // 0x801629B0: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltGroundAddAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80169654: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80169658: lw          $v0, 0x10C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10C4);
    // 0x8016965C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80169660: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80169664: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80169668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016966C: addiu       $t7, $t7, 0x1AE0
    ctx->r15 = ADD32(ctx->r15, 0X1AE0);
    // 0x80169670: addiu       $t6, $t6, 0x1A20
    ctx->r14 = ADD32(ctx->r14, 0X1A20);
    // 0x80169674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80169678: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8016967C: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x80169680: jal         0x8000BED8
    // 0x80169684: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    gcAddAnimAll(rdram, ctx);
        goto after_0;
    // 0x80169684: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    after_0:
    // 0x80169688: jal         0x8000DF34
    // 0x8016968C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8016968C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80169690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80169694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80169698: jr          $ra
    // 0x8016969C: nop

    return;
    // 0x8016969C: nop

;}
RECOMP_FUNC void itRShellFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017A988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A98C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017A990: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017A994: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017A998: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017A99C: sw          $t9, 0x248($a0)
    MEM_W(0X248, ctx->r4) = ctx->r25;
    // 0x8017A9A0: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x8017A9A4: jal         0x80173F78
    // 0x8017A9A8: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x8017A9A8: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x8017A9AC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017A9B0: addiu       $a1, $a1, -0x5A5C
    ctx->r5 = ADD32(ctx->r5, -0X5A5C);
    // 0x8017A9B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017A9B8: jal         0x80172EC8
    // 0x8017A9BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017A9BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017A9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A9C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017A9C8: jr          $ra
    // 0x8017A9CC: nop

    return;
    // 0x8017A9CC: nop

;}
RECOMP_FUNC void gcAppendAObjToMObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007E90: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80007E94: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80007E98: jr          $ra
    // 0x80007E9C: sw          $a1, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r5;
    return;
    // 0x80007E9C: sw          $a1, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_ovl8_80383618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038361C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80383620: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80383624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383628: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8038362C: beql        $t6, $zero, L_803836C8
    if (ctx->r14 == 0) {
        // 0x80383630: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803836C8;
    }
    goto skip_0;
    // 0x80383630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80383634: lh          $v0, 0x44($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X44);
    // 0x80383638: lh          $t7, 0x40($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X40);
    // 0x8038363C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80383640: beql        $at, $zero, L_803836C8
    if (ctx->r1 == 0) {
        // 0x80383644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803836C8;
    }
    goto skip_1;
    // 0x80383644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80383648: lh          $t0, 0x42($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X42);
    // 0x8038364C: subu        $a2, $v0, $t0
    ctx->r6 = SUB32(ctx->r2, ctx->r8);
    // 0x80383650: blezl       $a2, L_80383678
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80383654: lw          $t1, 0x3C($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X3C);
            goto L_80383678;
    }
    goto skip_2;
    // 0x80383654: lw          $t1, 0x3C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X3C);
    skip_2:
    // 0x80383658: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x8038365C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80383660: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x80383664: jal         0x8037B760
    // 0x80383668: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    func_ovl8_8037B760(rdram, ctx);
        goto after_0;
    // 0x80383668: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    after_0:
    // 0x8038366C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80383670: lh          $t0, 0x42($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X42);
    // 0x80383674: lw          $t1, 0x3C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X3C);
L_80383678:
    // 0x80383678: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x8038367C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80383680: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80383684: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x80383688: lh          $t3, 0x44($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X44);
    // 0x8038368C: lw          $t5, 0x3C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X3C);
    // 0x80383690: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80383694: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80383698: sh          $t4, 0x44($a3)
    MEM_H(0X44, ctx->r7) = ctx->r12;
    // 0x8038369C: lh          $t6, 0x44($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X44);
    // 0x803836A0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x803836A4: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x803836A8: lw          $v1, 0x38($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X38);
    // 0x803836AC: sw          $t8, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r24;
    // 0x803836B0: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803836B4: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x803836B8: lh          $t1, 0x118($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X118);
    // 0x803836BC: jalr        $t9
    // 0x803836C0: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803836C0: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    after_1:
    // 0x803836C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803836C8:
    // 0x803836C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803836CC: jr          $ra
    // 0x803836D0: nop

    return;
    // 0x803836D0: nop

;}
RECOMP_FUNC void itHarisenThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175358: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017535C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80175360: addiu       $a1, $a1, -0x6554
    ctx->r5 = ADD32(ctx->r5, -0X6554);
    // 0x80175364: jal         0x80172EC8
    // 0x80175368: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80175368: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8017536C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80175370: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80175374: lwc1        $f4, -0x3320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3320);
    // 0x80175378: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8017537C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80175380: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x80175384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017538C: jr          $ra
    // 0x80175390: nop

    return;
    // 0x80175390: nop

;}
RECOMP_FUNC void gcSleepCurrentGObjThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B1EC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000B1F0: lw          $v0, 0x6A60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A60);
    // 0x8000B1F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000B1F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000B1FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B200: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x8000B204: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000B208: lui         $at, 0xFEDC
    ctx->r1 = S32(0XFEDC << 16);
    // 0x8000B20C: lw          $t7, 0x1B8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1B8);
    // 0x8000B210: ori         $at, $at, 0xBA98
    ctx->r1 = ctx->r1 | 0XBA98;
    // 0x8000B214: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000B218: lw          $t8, 0x38($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X38);
    // 0x8000B21C: lw          $t9, 0x3C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X3C);
    // 0x8000B220: bnel        $t8, $zero, L_8000B234
    if (ctx->r24 != 0) {
        // 0x8000B224: lw          $t0, 0x18($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X18);
            goto L_8000B234;
    }
    goto skip_0;
    // 0x8000B224: lw          $t0, 0x18($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X18);
    skip_0:
    // 0x8000B228: beq         $t9, $at, L_8000B240
    if (ctx->r25 == ctx->r1) {
        // 0x8000B22C: nop
    
            goto L_8000B240;
    }
    // 0x8000B22C: nop

    // 0x8000B230: lw          $t0, 0x18($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X18);
L_8000B234:
    // 0x8000B234: addiu       $a0, $a0, -0x2260
    ctx->r4 = ADD32(ctx->r4, -0X2260);
    // 0x8000B238: jal         0x80023624
    // 0x8000B23C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x8000B23C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_0:
L_8000B240:
    // 0x8000B240: beq         $s0, $zero, L_8000B270
    if (ctx->r16 == 0) {
        // 0x8000B244: lui         $s1, 0x8004
        ctx->r17 = S32(0X8004 << 16);
            goto L_8000B270;
    }
    // 0x8000B244: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8000B248: addiu       $s1, $s1, 0x6A70
    ctx->r17 = ADD32(ctx->r17, 0X6A70);
    // 0x8000B24C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000B250:
    // 0x8000B250: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000B254: jal         0x80030000
    // 0x8000B258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8000B258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8000B25C: jal         0x80030150
    // 0x8000B260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osStopThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8000B260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8000B264: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8000B268: bnel        $s0, $zero, L_8000B250
    if (ctx->r16 != 0) {
        // 0x8000B26C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000B250;
    }
    goto skip_1;
    // 0x8000B26C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
L_8000B270:
    // 0x8000B270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B274: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000B278: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000B27C: jr          $ra
    // 0x8000B280: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000B280: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_80385598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8038559C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803855A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803855A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803855A8: beq         $a0, $zero, L_80385620
    if (ctx->r4 == 0) {
        // 0x803855AC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80385620;
    }
    // 0x803855AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803855B0: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x803855B4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803855B8: addiu       $t6, $t6, -0x26A0
    ctx->r14 = ADD32(ctx->r14, -0X26A0);
    // 0x803855BC: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803855C0: addiu       $t7, $t7, -0x2580
    ctx->r15 = ADD32(ctx->r15, -0X2580);
    // 0x803855C4: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x803855C8: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x803855CC: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x803855D0: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803855D4: addiu       $t9, $t9, -0x2428
    ctx->r25 = ADD32(ctx->r25, -0X2428);
    // 0x803855D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803855DC: jal         0x803848CC
    // 0x803855E0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_803848CC(rdram, ctx);
        goto after_0;
    // 0x803855E0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x803855E4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x803855E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803855EC: beql        $t1, $zero, L_8038560C
    if (ctx->r9 == 0) {
        // 0x803855F0: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8038560C;
    }
    goto skip_0;
    // 0x803855F0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x803855F4: jal         0x8037C30C
    // 0x803855F8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x803855F8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x803855FC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80385600: jal         0x803718C4
    // 0x80385604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x80385604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80385608: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_8038560C:
    // 0x8038560C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80385610: beql        $t3, $zero, L_80385624
    if (ctx->r11 == 0) {
        // 0x80385614: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80385624;
    }
    goto skip_1;
    // 0x80385614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80385618: jal         0x803717C0
    // 0x8038561C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x8038561C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80385620:
    // 0x80385620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80385624:
    // 0x80385624: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80385628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8038562C: jr          $ra
    // 0x80385630: nop

    return;
    // 0x80385630: nop

;}
RECOMP_FUNC void syUtilsFind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018CEC: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x80018CF0: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018CF4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80018CF8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80018CFC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80018D00: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80018D04: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80018D08: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80018D0C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80018D10: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80018D14: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80018D18: mflo        $t7
    ctx->r15 = lo;
    // 0x80018D1C: addu        $s6, $a1, $t7
    ctx->r22 = ADD32(ctx->r5, ctx->r15);
    // 0x80018D20: sltu        $at, $s6, $a1
    ctx->r1 = ctx->r22 < ctx->r5 ? 1 : 0;
    // 0x80018D24: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80018D28: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80018D2C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80018D30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80018D34: bne         $at, $zero, L_80018DE8
    if (ctx->r1 != 0) {
        // 0x80018D38: or          $s5, $a1, $zero
        ctx->r21 = ctx->r5 | 0;
            goto L_80018DE8;
    }
    // 0x80018D38: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80018D3C: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x80018D40: srl         $v0, $a2, 1
    ctx->r2 = S32(U32(ctx->r6) >> 1);
L_80018D44:
    // 0x80018D44: beq         $v0, $zero, L_80018DB4
    if (ctx->r2 == 0) {
        // 0x80018D48: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80018DB4;
    }
    // 0x80018D48: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80018D4C: andi        $s2, $a2, 0x1
    ctx->r18 = ctx->r6 & 0X1;
    // 0x80018D50: beq         $s2, $zero, L_80018D60
    if (ctx->r18 == 0) {
        // 0x80018D54: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_80018D60;
    }
    // 0x80018D54: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80018D58: b           L_80018D60
    // 0x80018D5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80018D60;
    // 0x80018D5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80018D60:
    // 0x80018D60: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018D64: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80018D68: mflo        $t8
    ctx->r24 = lo;
    // 0x80018D6C: addu        $s0, $t8, $s5
    ctx->r16 = ADD32(ctx->r24, ctx->r21);
    // 0x80018D70: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80018D74: jalr        $s7
    // 0x80018D78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
        goto after_0;
    // 0x80018D78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80018D7C: bne         $v0, $zero, L_80018D8C
    if (ctx->r2 != 0) {
        // 0x80018D80: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_80018D8C;
    }
    // 0x80018D80: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80018D84: b           L_80018DEC
    // 0x80018D88: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80018DEC;
    // 0x80018D88: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80018D8C:
    // 0x80018D8C: bgez        $v0, L_80018DAC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80018D90: nop
    
            goto L_80018DAC;
    }
    // 0x80018D90: nop

    // 0x80018D94: beq         $s2, $zero, L_80018DA4
    if (ctx->r18 == 0) {
        // 0x80018D98: subu        $s6, $s0, $s4
        ctx->r22 = SUB32(ctx->r16, ctx->r20);
            goto L_80018DA4;
    }
    // 0x80018D98: subu        $s6, $s0, $s4
    ctx->r22 = SUB32(ctx->r16, ctx->r20);
    // 0x80018D9C: b           L_80018DDC
    // 0x80018DA0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
        goto L_80018DDC;
    // 0x80018DA0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
L_80018DA4:
    // 0x80018DA4: b           L_80018DDC
    // 0x80018DA8: addiu       $a2, $s1, -0x1
    ctx->r6 = ADD32(ctx->r17, -0X1);
        goto L_80018DDC;
    // 0x80018DA8: addiu       $a2, $s1, -0x1
    ctx->r6 = ADD32(ctx->r17, -0X1);
L_80018DAC:
    // 0x80018DAC: b           L_80018DDC
    // 0x80018DB0: addu        $s5, $s3, $s4
    ctx->r21 = ADD32(ctx->r19, ctx->r20);
        goto L_80018DDC;
    // 0x80018DB0: addu        $s5, $s3, $s4
    ctx->r21 = ADD32(ctx->r19, ctx->r20);
L_80018DB4:
    // 0x80018DB4: beq         $a2, $zero, L_80018DE8
    if (ctx->r6 == 0) {
        // 0x80018DB8: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_80018DE8;
    }
    // 0x80018DB8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80018DBC: jalr        $s7
    // 0x80018DC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
        goto after_1;
    // 0x80018DC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x80018DC4: beq         $v0, $zero, L_80018DD4
    if (ctx->r2 == 0) {
        // 0x80018DC8: or          $v1, $s5, $zero
        ctx->r3 = ctx->r21 | 0;
            goto L_80018DD4;
    }
    // 0x80018DC8: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
    // 0x80018DCC: b           L_80018DEC
    // 0x80018DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80018DEC;
    // 0x80018DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018DD4:
    // 0x80018DD4: b           L_80018DEC
    // 0x80018DD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80018DEC;
    // 0x80018DD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80018DDC:
    // 0x80018DDC: sltu        $at, $s6, $s5
    ctx->r1 = ctx->r22 < ctx->r21 ? 1 : 0;
    // 0x80018DE0: beql        $at, $zero, L_80018D44
    if (ctx->r1 == 0) {
        // 0x80018DE4: srl         $v0, $a2, 1
        ctx->r2 = S32(U32(ctx->r6) >> 1);
            goto L_80018D44;
    }
    goto skip_0;
    // 0x80018DE4: srl         $v0, $a2, 1
    ctx->r2 = S32(U32(ctx->r6) >> 1);
    skip_0:
L_80018DE8:
    // 0x80018DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018DEC:
    // 0x80018DEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80018DF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80018DF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80018DF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80018DFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80018E00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80018E04: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80018E08: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80018E0C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80018E10: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80018E14: jr          $ra
    // 0x80018E18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80018E18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void dbFallsStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6688: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D668C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6690: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D6694: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x800D6698: addiu       $a0, $a0, 0x68A4
    ctx->r4 = ADD32(ctx->r4, 0X68A4);
    // 0x800D669C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D66A0: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x800D66A4: jal         0x80007024
    // 0x800D66A8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x800D66A8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x800D66AC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x800D66B0: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D66B4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D66B8: addiu       $t9, $t9, 0x6A00
    ctx->r25 = ADD32(ctx->r25, 0X6A00);
    // 0x800D66BC: addiu       $t8, $t8, 0x2A00
    ctx->r24 = ADD32(ctx->r24, 0X2A00);
    // 0x800D66C0: addiu       $a0, $a0, 0x68C0
    ctx->r4 = ADD32(ctx->r4, 0X68C0);
    // 0x800D66C4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800D66C8: jal         0x8000683C
    // 0x800D66CC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x800D66CC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x800D66D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D66D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D66D8: jr          $ra
    // 0x800D66DC: nop

    return;
    // 0x800D66DC: nop

;}
RECOMP_FUNC void gcDrawDObjDLHead1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013E8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013E94: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80013E98: jal         0x80013D90
    // 0x80013E9C: addiu       $a1, $a1, 0x65B4
    ctx->r5 = ADD32(ctx->r5, 0X65B4);
    gcDrawDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80013E9C: addiu       $a1, $a1, 0x65B4
    ctx->r5 = ADD32(ctx->r5, 0X65B4);
    after_0:
    // 0x80013EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013EA8: jr          $ra
    // 0x80013EAC: nop

    return;
    // 0x80013EAC: nop

;}
RECOMP_FUNC void mnVSRecordDrawIndivGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801330FC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133100: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133104: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133108: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8013310C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80133110: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133114: lui         $a3, 0x6
    ctx->r7 = S32(0X6 << 16);
    // 0x80133118: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013311C: lui         $t7, 0xF649
    ctx->r15 = S32(0XF649 << 16);
    // 0x80133120: ori         $a3, $a3, 0x8240
    ctx->r7 = ctx->r7 | 0X8240;
    // 0x80133124: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x80133128: lui         $t1, 0x6
    ctx->r9 = S32(0X6 << 16);
    // 0x8013312C: lui         $t0, 0xF649
    ctx->r8 = S32(0XF649 << 16);
    // 0x80133130: ori         $t0, $t0, 0x4000
    ctx->r8 = ctx->r8 | 0X4000;
    // 0x80133134: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x80133138: addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    // 0x8013313C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133140: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
L_80133144:
    // 0x80133144: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133148: andi        $a1, $a2, 0x3FF
    ctx->r5 = ctx->r6 & 0X3FF;
    // 0x8013314C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80133150: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80133154: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133158: slti        $at, $a2, 0xD9
    ctx->r1 = SIGNED(ctx->r6) < 0XD9 ? 1 : 0;
    // 0x8013315C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133160: or          $t9, $a1, $t0
    ctx->r25 = ctx->r5 | ctx->r8;
    // 0x80133164: or          $t6, $a1, $t1
    ctx->r14 = ctx->r5 | ctx->r9;
    // 0x80133168: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013316C: bne         $at, $zero, L_80133144
    if (ctx->r1 != 0) {
        // 0x80133170: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_80133144;
    }
    // 0x80133170: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133174: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133178: lui         $t8, 0xF606
    ctx->r24 = S32(0XF606 << 16);
    // 0x8013317C: ori         $t8, $t8, 0x8334
    ctx->r24 = ctx->r24 | 0X8334;
    // 0x80133180: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133184: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133188: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8013318C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133190: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133194: lui         $t7, 0x10
    ctx->r15 = S32(0X10 << 16);
    // 0x80133198: lui         $t6, 0xF610
    ctx->r14 = S32(0XF610 << 16);
    // 0x8013319C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801331A0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801331A4: ori         $t6, $t6, 0x4334
    ctx->r14 = ctx->r14 | 0X4334;
    // 0x801331A8: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x801331AC: addiu       $a3, $zero, 0x67
    ctx->r7 = ADD32(0, 0X67);
    // 0x801331B0: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    // 0x801331B4: addiu       $t1, $zero, 0x7A
    ctx->r9 = ADD32(0, 0X7A);
    // 0x801331B8: addiu       $t3, $zero, 0x8D
    ctx->r11 = ADD32(0, 0X8D);
    // 0x801331BC: addiu       $s0, $zero, 0x171
    ctx->r16 = ADD32(0, 0X171);
    // 0x801331C0: lui         $t5, 0xF600
    ctx->r13 = S32(0XF600 << 16);
    // 0x801331C4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801331C8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_801331CC:
    // 0x801331CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801331D0: andi        $a1, $a2, 0x3FF
    ctx->r5 = ctx->r6 & 0X3FF;
    // 0x801331D4: sll         $a1, $a1, 14
    ctx->r5 = S32(ctx->r5 << 14);
    // 0x801331D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801331DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801331E0: or          $t9, $a1, $t5
    ctx->r25 = ctx->r5 | ctx->r13;
    // 0x801331E4: ori         $t6, $t9, 0x334
    ctx->r14 = ctx->r25 | 0X334;
    // 0x801331E8: ori         $t7, $a1, 0x240
    ctx->r15 = ctx->r5 | 0X240;
    // 0x801331EC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801331F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801331F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801331F8: andi        $t0, $a3, 0x3FF
    ctx->r8 = ctx->r7 & 0X3FF;
    // 0x801331FC: sll         $t0, $t0, 14
    ctx->r8 = S32(ctx->r8 << 14);
    // 0x80133200: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133204: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133208: or          $t9, $t0, $t5
    ctx->r25 = ctx->r8 | ctx->r13;
    // 0x8013320C: ori         $t6, $t9, 0x334
    ctx->r14 = ctx->r25 | 0X334;
    // 0x80133210: ori         $t7, $t0, 0x240
    ctx->r15 = ctx->r8 | 0X240;
    // 0x80133214: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133218: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013321C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133220: andi        $t2, $t1, 0x3FF
    ctx->r10 = ctx->r9 & 0X3FF;
    // 0x80133224: sll         $t2, $t2, 14
    ctx->r10 = S32(ctx->r10 << 14);
    // 0x80133228: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013322C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133230: or          $t9, $t2, $t5
    ctx->r25 = ctx->r10 | ctx->r13;
    // 0x80133234: ori         $t6, $t9, 0x334
    ctx->r14 = ctx->r25 | 0X334;
    // 0x80133238: ori         $t7, $t2, 0x240
    ctx->r15 = ctx->r10 | 0X240;
    // 0x8013323C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133240: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133244: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133248: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x8013324C: sll         $t4, $t4, 14
    ctx->r12 = S32(ctx->r12 << 14);
    // 0x80133250: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x80133254: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133258: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8013325C: ori         $t6, $t9, 0x334
    ctx->r14 = ctx->r25 | 0X334;
    // 0x80133260: ori         $t7, $t4, 0x240
    ctx->r15 = ctx->r12 | 0X240;
    // 0x80133264: addiu       $t3, $t3, 0x4C
    ctx->r11 = ADD32(ctx->r11, 0X4C);
    // 0x80133268: addiu       $t1, $t1, 0x4C
    ctx->r9 = ADD32(ctx->r9, 0X4C);
    // 0x8013326C: addiu       $a3, $a3, 0x4C
    ctx->r7 = ADD32(ctx->r7, 0X4C);
    // 0x80133270: addiu       $a2, $a2, 0x4C
    ctx->r6 = ADD32(ctx->r6, 0X4C);
    // 0x80133274: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133278: bne         $t3, $s0, L_801331CC
    if (ctx->r11 != ctx->r16) {
        // 0x8013327C: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_801331CC;
    }
    // 0x8013327C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133280: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80133284: jr          $ra
    // 0x80133288: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80133288: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void efManagerSparkleWhiteMultiExplodeMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801005C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801005CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801005D0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801005D4: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801005D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801005DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801005E0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x801005E4: jal         0x800CE9E8
    // 0x801005E8: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x801005E8: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x801005EC: beq         $v0, $zero, L_80100654
    if (ctx->r2 == 0) {
        // 0x801005F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80100654;
    }
    // 0x801005F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801005F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801005F8: jal         0x800CE1DC
    // 0x801005FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x801005FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80100600: beq         $v0, $zero, L_80100648
    if (ctx->r2 == 0) {
        // 0x80100604: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80100648;
    }
    // 0x80100604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100608: jal         0x800CEA14
    // 0x8010060C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x8010060C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80100610: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80100614: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80100618: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x8010061C: bnel        $t6, $zero, L_80100630
    if (ctx->r14 != 0) {
        // 0x80100620: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_80100630;
    }
    goto skip_0;
    // 0x80100620: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80100624: b           L_80100658
    // 0x80100628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100658;
    // 0x80100628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010062C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_80100630:
    // 0x80100630: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80100634: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80100638: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8010063C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80100640: b           L_80100654
    // 0x80100644: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80100654;
    // 0x80100644: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_80100648:
    // 0x80100648: jal         0x800CEA40
    // 0x8010064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x8010064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80100650: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80100654:
    // 0x80100654: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80100658:
    // 0x80100658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010065C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100660: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80100664: jr          $ra
    // 0x80100668: nop

    return;
    // 0x80100668: nop

;}
RECOMP_FUNC void ftBossGootsubusuWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159D34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80159D38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80159D3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80159D40: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80159D44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159D48: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x80159D4C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159D50: jal         0x800E6F24
    // 0x80159D54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159D54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80159D58: jal         0x80018994
    // 0x80159D5C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80159D5C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
    // 0x80159D60: addiu       $t6, $v0, 0x3C
    ctx->r14 = ADD32(ctx->r2, 0X3C);
    // 0x80159D64: sh          $t6, 0xB18($s0)
    MEM_H(0XB18, ctx->r16) = ctx->r14;
    // 0x80159D68: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    // 0x80159D6C: jal         0x800F4428
    // 0x80159D70: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_2;
    // 0x80159D70: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80159D74: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80159D78: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    // 0x80159D7C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80159D80: jal         0x800F4408
    // 0x80159D84: swc1        $f4, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f4.u32l;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_3;
    // 0x80159D84: swc1        $f4, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80159D88: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80159D8C: swc1        $f6, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f6.u32l;
    // 0x80159D90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80159D94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80159D98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80159D9C: jr          $ra
    // 0x80159DA0: nop

    return;
    // 0x80159DA0: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwDecideMapCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FCE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FCEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FCF0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015FCF4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015FCF8: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x8015FCFC: bne         $t6, $zero, L_8015FD38
    if (ctx->r14 != 0) {
        // 0x8015FD00: nop
    
            goto L_8015FD38;
    }
    // 0x8015FD00: nop

    // 0x8015FD04: lw          $t7, 0x188($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X188);
    // 0x8015FD08: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015FD0C: beq         $t7, $zero, L_8015FD28
    if (ctx->r15 == 0) {
        // 0x8015FD10: nop
    
            goto L_8015FD28;
    }
    // 0x8015FD10: nop

    // 0x8015FD14: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015FD18: jal         0x800DDE84
    // 0x8015FD1C: addiu       $a1, $a1, -0x350
    ctx->r5 = ADD32(ctx->r5, -0X350);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8015FD1C: addiu       $a1, $a1, -0x350
    ctx->r5 = ADD32(ctx->r5, -0X350);
    after_0:
    // 0x8015FD20: b           L_8015FD44
    // 0x8015FD24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015FD44;
    // 0x8015FD24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015FD28:
    // 0x8015FD28: jal         0x800DDDDC
    // 0x8015FD2C: addiu       $a1, $a1, -0x350
    ctx->r5 = ADD32(ctx->r5, -0X350);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_1;
    // 0x8015FD2C: addiu       $a1, $a1, -0x350
    ctx->r5 = ADD32(ctx->r5, -0X350);
    after_1:
    // 0x8015FD30: b           L_8015FD44
    // 0x8015FD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015FD44;
    // 0x8015FD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015FD38:
    // 0x8015FD38: jal         0x800DE6E4
    // 0x8015FD3C: addiu       $a1, $a1, -0x338
    ctx->r5 = ADD32(ctx->r5, -0X338);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_2;
    // 0x8015FD3C: addiu       $a1, $a1, -0x338
    ctx->r5 = ADD32(ctx->r5, -0X338);
    after_2:
    // 0x8015FD40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015FD44:
    // 0x8015FD44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FD48: jr          $ra
    // 0x8015FD4C: nop

    return;
    // 0x8015FD4C: nop

;}
RECOMP_FUNC void syMatrixRotDF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D2A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D2A4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D2A8: lwc1        $f4, -0x1C3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C3C);
    // 0x8001D2AC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D2B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D2B4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8001D2B8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D2BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D2C0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001D2C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D2C8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D2CC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D2D0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001D2D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8001D2D8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8001D2DC: jal         0x8001BA78
    // 0x8001D2E0: nop

    syMatrixRotRF(rdram, ctx);
        goto after_0;
    // 0x8001D2E0: nop

    after_0:
    // 0x8001D2E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D2E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D2EC: jr          $ra
    // 0x8001D2F0: nop

    return;
    // 0x8001D2F0: nop

;}
RECOMP_FUNC void syAudioBnkfPatchBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E708: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E70C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001E710: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001E714: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001E718: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001E71C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001E720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E724: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x8001E728: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8001E72C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001E730: bne         $t6, $zero, L_8001E7A0
    if (ctx->r14 != 0) {
        // 0x8001E734: or          $s4, $a2, $zero
        ctx->r20 = ctx->r6 | 0;
            goto L_8001E7A0;
    }
    // 0x8001E734: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001E738: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8001E73C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E740: sb          $t7, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r15;
    // 0x8001E744: beq         $v0, $zero, L_8001E758
    if (ctx->r2 == 0) {
        // 0x8001E748: addu        $t8, $v0, $a1
        ctx->r24 = ADD32(ctx->r2, ctx->r5);
            goto L_8001E758;
    }
    // 0x8001E748: addu        $t8, $v0, $a1
    ctx->r24 = ADD32(ctx->r2, ctx->r5);
    // 0x8001E74C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8001E750: jal         0x8001E7C0
    // 0x8001E754: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    syAudioBnkfPatchInst(rdram, ctx);
        goto after_0;
    // 0x8001E754: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
L_8001E758:
    // 0x8001E758: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x8001E75C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001E760: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x8001E764: blezl       $t9, L_8001E7A4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001E768: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001E7A4;
    }
    goto skip_0;
    // 0x8001E768: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8001E76C: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
L_8001E770:
    // 0x8001E770: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001E774: addu        $a0, $t0, $s2
    ctx->r4 = ADD32(ctx->r8, ctx->r18);
    // 0x8001E778: beq         $a0, $zero, L_8001E788
    if (ctx->r4 == 0) {
        // 0x8001E77C: sw          $a0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r4;
            goto L_8001E788;
    }
    // 0x8001E77C: sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    // 0x8001E780: jal         0x8001E7C0
    // 0x8001E784: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    syAudioBnkfPatchInst(rdram, ctx);
        goto after_1;
    // 0x8001E784: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_1:
L_8001E788:
    // 0x8001E788: lh          $t2, 0x0($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X0);
    // 0x8001E78C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001E790: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E794: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001E798: bnel        $at, $zero, L_8001E770
    if (ctx->r1 != 0) {
        // 0x8001E79C: lw          $t0, 0xC($s0)
        ctx->r8 = MEM_W(ctx->r16, 0XC);
            goto L_8001E770;
    }
    goto skip_1;
    // 0x8001E79C: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    skip_1:
L_8001E7A0:
    // 0x8001E7A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001E7A4:
    // 0x8001E7A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E7A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E7AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E7B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E7B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E7B8: jr          $ra
    // 0x8001E7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonCliffWaitCheckFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144E84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144E8C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144E90: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80144E94: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    // 0x80144E98: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80144E9C: bne         $t7, $zero, L_80144EC0
    if (ctx->r15 != 0) {
        // 0x80144EA0: sw          $t7, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = ctx->r15;
            goto L_80144EC0;
    }
    // 0x80144EA0: sw          $t7, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r15;
    // 0x80144EA4: sw          $t9, 0x15C($v0)
    MEM_W(0X15C, ctx->r2) = ctx->r25;
    // 0x80144EA8: jal         0x80144CF8
    // 0x80144EAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonCliffCommonProcDamage(rdram, ctx);
        goto after_0;
    // 0x80144EAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80144EB0: jal         0x801436A0
    // 0x80144EB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonDamageFallSetStatusFromCliffWait(rdram, ctx);
        goto after_1;
    // 0x80144EB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80144EB8: b           L_80144EC4
    // 0x80144EBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80144EC4;
    // 0x80144EBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80144EC0:
    // 0x80144EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80144EC4:
    // 0x80144EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144ECC: jr          $ra
    // 0x80144ED0: nop

    return;
    // 0x80144ED0: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801543E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801543E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801543EC: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801543F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801543F4: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x801543F8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801543FC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80154400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80154404: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80154408: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8015440C: bc1f        L_80154428
    if (!c1cs) {
        // 0x80154410: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80154428;
    }
    // 0x80154410: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154414: lwc1        $f8, -0x3A50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A50);
    // 0x80154418: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015441C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80154420: jal         0x801438F0
    // 0x80154424: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_0;
    // 0x80154424: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
L_80154428:
    // 0x80154428: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015442C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80154430: jr          $ra
    // 0x80154434: nop

    return;
    // 0x80154434: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BD24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015BD28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BD2C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015BD30: jal         0x800D9480
    // 0x8015BD34: addiu       $a1, $a1, -0x3FF0
    ctx->r5 = ADD32(ctx->r5, -0X3FF0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BD34: addiu       $a1, $a1, -0x3FF0
    ctx->r5 = ADD32(ctx->r5, -0X3FF0);
    after_0:
    // 0x8015BD38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015BD3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BD40: jr          $ra
    // 0x8015BD44: nop

    return;
    // 0x8015BD44: nop

;}
RECOMP_FUNC void mvOpeningFoxPosedFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D998: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D99C: lw          $v1, -0x1E08($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1E08);
    // 0x8018D9A0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018D9A4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9A8: beq         $v1, $at, L_8018D9D0
    if (ctx->r3 == ctx->r1) {
        // 0x8018D9AC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018D9D0;
    }
    // 0x8018D9AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018D9B0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8018D9B4: beq         $v0, $at, L_8018D9E4
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9B8: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9E4;
    }
    // 0x8018D9B8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9BC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018D9C0: beq         $v0, $at, L_8018D9F8
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9C4: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9F8;
    }
    // 0x8018D9C4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9C8: b           L_8018DA08
    // 0x8018D9CC: addiu       $a1, $a1, -0x1DF0
    ctx->r5 = ADD32(ctx->r5, -0X1DF0);
        goto L_8018DA08;
    // 0x8018D9CC: addiu       $a1, $a1, -0x1DF0
    ctx->r5 = ADD32(ctx->r5, -0X1DF0);
L_8018D9D0:
    // 0x8018D9D0: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8018D9D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D9D8: addiu       $a1, $a1, -0x1DF0
    ctx->r5 = ADD32(ctx->r5, -0X1DF0);
    // 0x8018D9DC: b           L_8018DA08
    // 0x8018D9E0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8018DA08;
    // 0x8018D9E0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8018D9E4:
    // 0x8018D9E4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018D9E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D9EC: addiu       $a1, $a1, -0x1DF0
    ctx->r5 = ADD32(ctx->r5, -0X1DF0);
    // 0x8018D9F0: b           L_8018DA08
    // 0x8018D9F4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8018DA08;
    // 0x8018D9F4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_8018D9F8:
    // 0x8018D9F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018D9FC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA00: addiu       $a1, $a1, -0x1DF0
    ctx->r5 = ADD32(ctx->r5, -0X1DF0);
    // 0x8018DA04: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA08:
    // 0x8018DA08: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8018DA0C: bne         $at, $zero, L_8018DA2C
    if (ctx->r1 != 0) {
        // 0x8018DA10: slti        $at, $v1, 0x2D
        ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
            goto L_8018DA2C;
    }
    // 0x8018DA10: slti        $at, $v1, 0x2D
    ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
    // 0x8018DA14: beq         $at, $zero, L_8018DA2C
    if (ctx->r1 == 0) {
        // 0x8018DA18: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018DA2C;
    }
    // 0x8018DA18: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DA1C: lwc1        $f16, -0x1E20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E20);
    // 0x8018DA20: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA24: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA28: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8018DA2C:
    // 0x8018DA2C: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    // 0x8018DA30: bne         $at, $zero, L_8018DA50
    if (ctx->r1 != 0) {
        // 0x8018DA34: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8018DA50;
    }
    // 0x8018DA34: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018DA38: beq         $at, $zero, L_8018DA50
    if (ctx->r1 == 0) {
        // 0x8018DA3C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8018DA50;
    }
    // 0x8018DA3C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018DA40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA44: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DA4C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA50:
    // 0x8018DA50: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DA54: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA58: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8018DA5C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018DA60: jr          $ra
    // 0x8018DA64: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018DA64: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void mnPlayers1PGameRecallPuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136BD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80136BD8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136BDC: addiu       $a0, $a0, -0x7118
    ctx->r4 = ADD32(ctx->r4, -0X7118);
    // 0x80136BE0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80136BE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80136BE8: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    // 0x80136BEC: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80136BF0: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80136BF4: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    // 0x80136BF8: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80136BFC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80136C00: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x80136C04: lwc1        $f4, 0x58($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X58);
    // 0x80136C08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80136C0C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80136C10: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80136C14: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x80136C18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80136C1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136C20: lwc1        $f6, 0x5C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x80136C24: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80136C28: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80136C2C: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80136C30: lwc1        $f8, 0x58($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80136C34: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80136C38: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80136C3C: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80136C40: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80136C44: nop

    // 0x80136C48: bc1fl       L_80136C58
    if (!c1cs) {
        // 0x80136C4C: lw          $t0, 0x74($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X74);
            goto L_80136C58;
    }
    goto skip_0;
    // 0x80136C4C: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
    skip_0:
    // 0x80136C50: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x80136C54: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
L_80136C58:
    // 0x80136C58: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80136C5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136C60: lwc1        $f18, 0x5C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x80136C64: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80136C68: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
    // 0x80136C6C: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80136C70: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80136C74: nop

    // 0x80136C78: bc1fl       L_80136C8C
    if (!c1cs) {
        // 0x80136C7C: lwc1        $f2, 0x40($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
            goto L_80136C8C;
    }
    goto skip_1;
    // 0x80136C7C: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    skip_1:
    // 0x80136C80: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    // 0x80136C84: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80136C88: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
L_80136C8C:
    // 0x80136C8C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80136C90: nop

    // 0x80136C94: bc1fl       L_80136CAC
    if (!c1cs) {
        // 0x80136C98: sub.s       $f10, $f2, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_80136CAC;
    }
    goto skip_2;
    // 0x80136C98: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    skip_2:
    // 0x80136C9C: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80136CA0: jr          $ra
    // 0x80136CA4: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80136CA4: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x80136CA8: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
L_80136CAC:
    // 0x80136CAC: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x80136CB0: jr          $ra
    // 0x80136CB4: nop

    return;
    // 0x80136CB4: nop

;}
RECOMP_FUNC void itBombHeiWalkInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177848: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017784C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80177850: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80177854: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80177858: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017785C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80177860: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80177864: lw          $t6, 0x2D4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2D4);
    // 0x80177868: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8017786C: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80177870: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80177874: lbu         $t8, 0x2CE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2CE);
    // 0x80177878: sh          $zero, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = 0;
    // 0x8017787C: sh          $t0, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r8;
    // 0x80177880: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x80177884: jal         0x8017275C
    // 0x80177888: sb          $t9, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r25;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_0;
    // 0x80177888: sb          $t9, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r25;
    after_0:
    // 0x8017788C: lw          $t1, 0x2D4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2D4);
    // 0x80177890: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80177894: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80177898: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8017789C: addiu       $t3, $t3, 0x33F8
    ctx->r11 = ADD32(ctx->r11, 0X33F8);
    // 0x801778A0: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x801778A4: addiu       $t5, $t5, 0x35B8
    ctx->r13 = ADD32(ctx->r13, 0X35B8);
    // 0x801778A8: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x801778AC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x801778B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801778B4: jal         0x8000BD54
    // 0x801778B8: lw          $a0, 0x80($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X80);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x801778B8: lw          $a0, 0x80($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X80);
    after_1:
    // 0x801778BC: jal         0x8000DF34
    // 0x801778C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x801778C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801778C4: jal         0x800FC67C
    // 0x801778C8: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_3;
    // 0x801778C8: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    after_3:
    // 0x801778CC: beq         $v0, $zero, L_80177984
    if (ctx->r2 == 0) {
        // 0x801778D0: nop
    
            goto L_80177984;
    }
    // 0x801778D0: nop

    // 0x801778D4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x801778D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801778DC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x801778E0: bne         $t7, $at, L_8017793C
    if (ctx->r15 != ctx->r1) {
        // 0x801778E4: nop
    
            goto L_8017793C;
    }
    // 0x801778E4: nop

    // 0x801778E8: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    // 0x801778EC: jal         0x800F4428
    // 0x801778F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_4;
    // 0x801778F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x801778F4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x801778F8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801778FC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80177900: lh          $t0, 0x30($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X30);
    // 0x80177904: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80177908: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017790C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80177910: nop

    // 0x80177914: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80177918: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8017791C: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x80177920: nop

    // 0x80177924: bc1f        L_80177984
    if (!c1cs) {
        // 0x80177928: nop
    
            goto L_80177984;
    }
    // 0x80177928: nop

    // 0x8017792C: jal         0x80177104
    // 0x80177930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itBombHeiCommonSetWalkLR(rdram, ctx);
        goto after_5;
    // 0x80177930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80177934: b           L_80177984
    // 0x80177938: nop

        goto L_80177984;
    // 0x80177938: nop

L_8017793C:
    // 0x8017793C: jal         0x800F4408
    // 0x80177940: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_6;
    // 0x80177940: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    after_6:
    // 0x80177944: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80177948: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8017794C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80177950: lh          $t3, 0x30($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X30);
    // 0x80177954: lwc1        $f18, 0x1C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80177958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017795C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80177960: nop

    // 0x80177964: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80177968: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8017796C: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x80177970: nop

    // 0x80177974: bc1f        L_80177984
    if (!c1cs) {
        // 0x80177978: nop
    
            goto L_80177984;
    }
    // 0x80177978: nop

    // 0x8017797C: jal         0x80177104
    // 0x80177980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itBombHeiCommonSetWalkLR(rdram, ctx);
        goto after_7;
    // 0x80177980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_80177984:
    // 0x80177984: jal         0x8017279C
    // 0x80177988: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainClearOwnerStats(rdram, ctx);
        goto after_8;
    // 0x80177988: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8017798C: jal         0x800269C0
    // 0x80177990: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80177990: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_9:
    // 0x80177994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80177998: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8017799C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801779A0: jr          $ra
    // 0x801779A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801779A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mvOpeningPortraitsFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132624: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132628: addiu       $v1, $v1, 0x29E8
    ctx->r3 = ADD32(ctx->r3, 0X29E8);
    // 0x8013262C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80132630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132638: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013263C: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80132640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132644: bne         $at, $zero, L_80132708
    if (ctx->r1 != 0) {
        // 0x80132648: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80132708;
    }
    // 0x80132648: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013264C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132650: addiu       $a2, $a2, 0x29F4
    ctx->r6 = ADD32(ctx->r6, 0X29F4);
    // 0x80132654: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80132658: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x8013265C: beq         $v0, $zero, L_80132668
    if (ctx->r2 == 0) {
        // 0x80132660: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132668;
    }
    // 0x80132660: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80132664: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80132668:
    // 0x80132668: jal         0x80390A04
    // 0x8013266C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x8013266C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80132670: beq         $v0, $zero, L_8013268C
    if (ctx->r2 == 0) {
        // 0x80132674: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_8013268C;
    }
    // 0x80132674: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132678: jal         0x80390AC0
    // 0x8013267C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x8013267C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80132680: beq         $v0, $zero, L_8013268C
    if (ctx->r2 == 0) {
        // 0x80132684: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8013268C;
    }
    // 0x80132684: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132688: sw          $zero, 0x29F4($at)
    MEM_W(0X29F4, ctx->r1) = 0;
L_8013268C:
    // 0x8013268C: jal         0x8039076C
    // 0x80132690: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80132690: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x80132694: beq         $v0, $zero, L_801326B4
    if (ctx->r2 == 0) {
        // 0x80132698: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_801326B4;
    }
    // 0x80132698: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013269C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801326A0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801326A4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x801326A8: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x801326AC: jal         0x80005C74
    // 0x801326B0: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x801326B0: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
L_801326B4:
    // 0x801326B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801326B8: lw          $v0, 0x29E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29E8);
    // 0x801326BC: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x801326C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801326C4: bnel        $v0, $at, L_801326E8
    if (ctx->r2 != ctx->r1) {
        // 0x801326C8: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_801326E8;
    }
    goto skip_0;
    // 0x801326C8: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    skip_0:
    // 0x801326CC: jal         0x80009A84
    // 0x801326D0: lw          $a0, 0x29F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29F0);
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x801326D0: lw          $a0, 0x29F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29F0);
    after_4:
    // 0x801326D4: jal         0x80131CAC
    // 0x801326D8: nop

    mvOpeningPortraitsMakeSet2(rdram, ctx);
        goto after_5;
    // 0x801326D8: nop

    after_5:
    // 0x801326DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801326E0: lw          $v0, 0x29E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X29E8);
    // 0x801326E4: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
L_801326E8:
    // 0x801326E8: bne         $v0, $at, L_80132708
    if (ctx->r2 != ctx->r1) {
        // 0x801326EC: addiu       $t3, $zero, 0x1E
        ctx->r11 = ADD32(0, 0X1E);
            goto L_80132708;
    }
    // 0x801326EC: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x801326F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801326F4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801326F8: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x801326FC: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x80132700: jal         0x80005C74
    // 0x80132704: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x80132704: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    after_6:
L_80132708:
    // 0x80132708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013270C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132710: jr          $ra
    // 0x80132714: nop

    return;
    // 0x80132714: nop

;}
RECOMP_FUNC void ftLinkSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016380C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163810: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80163814: jal         0x800DE6E4
    // 0x80163818: addiu       $a1, $a1, 0x38EC
    ctx->r5 = ADD32(ctx->r5, 0X38EC);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80163818: addiu       $a1, $a1, 0x38EC
    ctx->r5 = ADD32(ctx->r5, 0X38EC);
    after_0:
    // 0x8016381C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163824: jr          $ra
    // 0x80163828: nop

    return;
    // 0x80163828: nop

;}
RECOMP_FUNC void ftBossOkuhikouki2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801596B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801596B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801596B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801596BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801596C0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801596C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801596C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801596CC: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x801596D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801596D4: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x801596D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801596DC: jal         0x800E6F24
    // 0x801596E0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801596E0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x801596E4: jal         0x800E0830
    // 0x801596E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801596E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801596EC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x801596F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801596F4: lwc1        $f6, -0x3830($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3830);
    // 0x801596F8: lwc1        $f4, 0xB18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB18);
    // 0x801596FC: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80159700: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80159704: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80159708: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015970C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80159710: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80159714: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80159718: lwc1        $f16, -0x382C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X382C);
    // 0x8015971C: lwc1        $f10, 0xB1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XB1C);
    // 0x80159720: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80159724: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80159728: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8015972C: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80159730: lwc1        $f4, -0x3828($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3828);
    // 0x80159734: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80159738: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8015973C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80159740: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80159744: lwc1        $f8, -0x3824($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3824);
    // 0x80159748: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8015974C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80159750: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80159754: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80159758: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8015975C: jal         0x8010D0A4
    // 0x80159760: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    gmCameraSetStatusMapZoom(rdram, ctx);
        goto after_2;
    // 0x80159760: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80159764: jal         0x80158604
    // 0x80159768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossCommonSetUseFogColor(rdram, ctx);
        goto after_3;
    // 0x80159768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8015976C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80159770: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80159774: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80159778: jr          $ra
    // 0x8015977C: nop

    return;
    // 0x8015977C: nop

;}
RECOMP_FUNC void func_ovl8_803714A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803714A0: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x803714A4: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x803714A8: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x803714AC: jr          $ra
    // 0x803714B0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    return;
    // 0x803714B0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayers1PGameAnnounceFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135B30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80135B34: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135B3C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80135B40: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80135B44: addiu       $t7, $t7, -0x7444
    ctx->r15 = ADD32(ctx->r15, -0X7444);
    // 0x80135B48: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80135B4C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80135B50: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80135B54: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80135B58: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80135B5C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80135B60: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80135B64: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80135B68: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80135B6C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80135B70: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80135B74: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80135B78: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80135B7C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80135B80: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80135B84: lw          $a0, 0x74($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X74);
    // 0x80135B88: beq         $a0, $zero, L_80135BB0
    if (ctx->r4 == 0) {
        // 0x80135B8C: nop
    
            goto L_80135BB0;
    }
    // 0x80135B8C: nop

    // 0x80135B90: lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X26);
    // 0x80135B94: beq         $v0, $zero, L_80135BB0
    if (ctx->r2 == 0) {
        // 0x80135B98: nop
    
            goto L_80135BB0;
    }
    // 0x80135B98: nop

    // 0x80135B9C: lhu         $t0, 0x78($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X78);
    // 0x80135BA0: bne         $t0, $v0, L_80135BB0
    if (ctx->r8 != ctx->r2) {
        // 0x80135BA4: nop
    
            goto L_80135BB0;
    }
    // 0x80135BA4: nop

    // 0x80135BA8: jal         0x80026738
    // 0x80135BAC: nop

    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x80135BAC: nop

    after_0:
L_80135BB0:
    // 0x80135BB0: jal         0x800269C0
    // 0x80135BB4: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80135BB4: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    after_1:
    // 0x80135BB8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80135BBC: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80135BC0: lw          $t1, 0x20($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X20);
    // 0x80135BC4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80135BC8: addu        $a0, $sp, $t2
    ctx->r4 = ADD32(ctx->r29, ctx->r10);
    // 0x80135BCC: jal         0x800269C0
    // 0x80135BD0: lhu         $a0, 0x20($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X20);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80135BD0: lhu         $a0, 0x20($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X20);
    after_2:
    // 0x80135BD4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80135BD8: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80135BDC: beq         $v0, $zero, L_80135BEC
    if (ctx->r2 == 0) {
        // 0x80135BE0: sw          $v0, 0x74($v1)
        MEM_W(0X74, ctx->r3) = ctx->r2;
            goto L_80135BEC;
    }
    // 0x80135BE0: sw          $v0, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r2;
    // 0x80135BE4: lhu         $t3, 0x26($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X26);
    // 0x80135BE8: sh          $t3, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r11;
L_80135BEC:
    // 0x80135BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135BF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80135BF4: jr          $ra
    // 0x80135BF8: nop

    return;
    // 0x80135BF8: nop

;}
RECOMP_FUNC void func_ovl28_801342B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801342B0: jr          $ra
    // 0x801342B4: nop

    return;
    // 0x801342B4: nop

;}
RECOMP_FUNC void mnPlayersVSSetCursorPuckOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801375A8: addiu       $a2, $zero, 0xBC
    ctx->r6 = ADD32(0, 0XBC);
    // 0x801375AC: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801375B0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801375B4: addiu       $a1, $a1, -0x4578
    ctx->r5 = ADD32(ctx->r5, -0X4578);
    // 0x801375B8: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x801375BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801375C0: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x801375C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801375C8: mflo        $t6
    ctx->r14 = lo;
    // 0x801375CC: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x801375D0: lw          $t7, 0x80($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X80);
    // 0x801375D4: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801375D8: mflo        $t8
    ctx->r24 = lo;
    // 0x801375DC: addu        $v1, $a1, $t8
    ctx->r3 = ADD32(ctx->r5, ctx->r24);
    // 0x801375E0: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x801375E4: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x801375E8: lwc1        $f4, 0x58($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X58);
    // 0x801375EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801375F0: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
    // 0x801375F4: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x801375F8: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x801375FC: lwc1        $f10, 0x5C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X5C);
    // 0x80137600: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80137604: jr          $ra
    // 0x80137608: swc1        $f18, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x80137608: swc1        $f18, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void ftCommonCliffAttackSlow1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80145694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145698: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8014569C: jal         0x800D9480
    // 0x801456A0: addiu       $a1, $a1, 0x5794
    ctx->r5 = ADD32(ctx->r5, 0X5794);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801456A0: addiu       $a1, $a1, 0x5794
    ctx->r5 = ADD32(ctx->r5, 0X5794);
    after_0:
    // 0x801456A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801456A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801456AC: jr          $ra
    // 0x801456B0: nop

    return;
    // 0x801456B0: nop

;}
RECOMP_FUNC void sc1PGameGetNextFreePlayerPort(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D280: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018D284: bne         $a0, $at, L_8018D294
    if (ctx->r4 != ctx->r1) {
        // 0x8018D288: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_8018D294;
    }
    // 0x8018D288: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8018D28C: jr          $ra
    // 0x8018D290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8018D290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018D294:
    // 0x8018D294: jr          $ra
    // 0x8018D298: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8018D298: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftKirbySpecialNEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016279C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801627A0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801627A4: jal         0x800DDDDC
    // 0x801627A8: addiu       $a1, $a1, 0x2B50
    ctx->r5 = ADD32(ctx->r5, 0X2B50);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801627A8: addiu       $a1, $a1, 0x2B50
    ctx->r5 = ADD32(ctx->r5, 0X2B50);
    after_0:
    // 0x801627AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801627B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801627B4: jr          $ra
    // 0x801627B8: nop

    return;
    // 0x801627B8: nop

;}
RECOMP_FUNC void efManagerConfettiMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104554: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80104558: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010455C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80104560: beq         $a1, $zero, L_80104580
    if (ctx->r5 == 0) {
        // 0x80104564: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80104580;
    }
    // 0x80104564: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80104568: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010456C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80104570: jal         0x800CE9E8
    // 0x80104574: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80104574: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_0:
    // 0x80104578: b           L_80104598
    // 0x8010457C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80104598;
    // 0x8010457C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80104580:
    // 0x80104580: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104584: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80104588: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x8010458C: jal         0x800CE9E8
    // 0x80104590: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_1;
    // 0x80104590: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    after_1:
    // 0x80104594: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80104598:
    // 0x80104598: beq         $v0, $zero, L_801045FC
    if (ctx->r2 == 0) {
        // 0x8010459C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801045FC;
    }
    // 0x8010459C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801045A0: jal         0x800CE1DC
    // 0x801045A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_2;
    // 0x801045A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x801045A8: beq         $v0, $zero, L_801045F0
    if (ctx->r2 == 0) {
        // 0x801045AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801045F0;
    }
    // 0x801045AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801045B0: jal         0x800CEA14
    // 0x801045B4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_3;
    // 0x801045B4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x801045B8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801045BC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801045C0: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x801045C4: bnel        $t6, $zero, L_801045D8
    if (ctx->r14 != 0) {
        // 0x801045C8: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_801045D8;
    }
    goto skip_0;
    // 0x801045C8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x801045CC: b           L_80104600
    // 0x801045D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104600;
    // 0x801045D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801045D4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_801045D8:
    // 0x801045D8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801045DC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801045E0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801045E4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801045E8: b           L_801045FC
    // 0x801045EC: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_801045FC;
    // 0x801045EC: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_801045F0:
    // 0x801045F0: jal         0x800CEA40
    // 0x801045F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_4;
    // 0x801045F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801045F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801045FC:
    // 0x801045FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80104600:
    // 0x80104600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80104604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80104608: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010460C: jr          $ra
    // 0x80104610: nop

    return;
    // 0x80104610: nop

;}
RECOMP_FUNC void ftSamusSpecialNLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D734: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8015D738: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015D73C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015D740: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015D744: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8015D748: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015D74C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8015D750: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x8015D754: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015D758: jal         0x800E6F24
    // 0x8015D75C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D75C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015D760: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8015D764: addiu       $t7, $t7, -0x2CC8
    ctx->r15 = ADD32(ctx->r15, -0X2CC8);
    // 0x8015D768: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8015D76C: sw          $t7, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r15;
    // 0x8015D770: sw          $t8, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r24;
    // 0x8015D774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015D778: jal         0x8015D35C
    // 0x8015D77C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    ftSamusSpecialNGetChargeShotPosition(rdram, ctx);
        goto after_1;
    // 0x8015D77C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8015D780: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8015D784: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8015D788: lw          $a2, 0xADC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XADC);
    // 0x8015D78C: jal         0x80168DDC
    // 0x8015D790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    wpSamusChargeShotMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x8015D790: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8015D794: sw          $v0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r2;
    // 0x8015D798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015D79C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015D7A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8015D7A4: jr          $ra
    // 0x8015D7A8: nop

    return;
    // 0x8015D7A8: nop

;}
RECOMP_FUNC void ftCommonAttack100StartCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F4EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014F4F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014F4F4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014F4F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014F4FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8014F500: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8014F504: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F508: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8014F55C;
    }
    // 0x8014F508: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8014F50C: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F510: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8014F55C;
    }
    // 0x8014F510: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8014F514: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F518: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8014F55C;
    }
    // 0x8014F518: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8014F51C: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F520: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8014F55C;
    }
    // 0x8014F520: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8014F524: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F528: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8014F55C;
    }
    // 0x8014F528: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8014F52C: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F530: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8014F55C;
    }
    // 0x8014F530: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8014F534: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F538: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_8014F55C;
    }
    // 0x8014F538: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8014F53C: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F540: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8014F55C;
    }
    // 0x8014F540: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8014F544: beq         $v0, $at, L_8014F55C
    if (ctx->r2 == ctx->r1) {
        // 0x8014F548: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8014F55C;
    }
    // 0x8014F548: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8014F54C: beql        $v0, $at, L_8014F560
    if (ctx->r2 == ctx->r1) {
        // 0x8014F550: lhu         $a0, 0x1B4($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X1B4);
            goto L_8014F560;
    }
    goto skip_0;
    // 0x8014F550: lhu         $a0, 0x1B4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1B4);
    skip_0:
    // 0x8014F554: b           L_8014F660
    // 0x8014F558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014F660;
    // 0x8014F558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014F55C:
    // 0x8014F55C: lhu         $a0, 0x1B4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1B4);
L_8014F560:
    // 0x8014F560: lhu         $t6, 0x1BE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1BE);
    // 0x8014F564: and         $t7, $t6, $a0
    ctx->r15 = ctx->r14 & ctx->r4;
    // 0x8014F568: bnel        $t7, $zero, L_8014F584
    if (ctx->r15 != 0) {
        // 0x8014F56C: lw          $t0, 0x158($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X158);
            goto L_8014F584;
    }
    goto skip_1;
    // 0x8014F56C: lw          $t0, 0x158($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X158);
    skip_1:
    // 0x8014F570: lhu         $t8, 0x1C0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X1C0);
    // 0x8014F574: and         $t9, $t8, $a0
    ctx->r25 = ctx->r24 & ctx->r4;
    // 0x8014F578: beql        $t9, $zero, L_8014F660
    if (ctx->r25 == 0) {
        // 0x8014F57C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014F660;
    }
    goto skip_2;
    // 0x8014F57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8014F580: lw          $t0, 0x158($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X158);
L_8014F584:
    // 0x8014F584: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8014F588: sltiu       $at, $t2, 0x18
    ctx->r1 = ctx->r10 < 0X18 ? 1 : 0;
    // 0x8014F58C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8014F590: beq         $at, $zero, L_8014F610
    if (ctx->r1 == 0) {
        // 0x8014F594: sw          $t1, 0x158($v1)
        MEM_W(0X158, ctx->r3) = ctx->r9;
            goto L_8014F610;
    }
    // 0x8014F594: sw          $t1, 0x158($v1)
    MEM_W(0X158, ctx->r3) = ctx->r9;
    // 0x8014F598: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8014F59C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F5A0: addu        $at, $at, $t2
    gpr jr_addend_8014F5A8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8014F5A4: lw          $t2, -0x3BC0($at)
    ctx->r10 = ADD32(ctx->r1, -0X3BC0);
    // 0x8014F5A8: jr          $t2
    // 0x8014F5AC: nop

    switch (jr_addend_8014F5A8 >> 2) {
        case 0: goto L_8014F5B0; break;
        case 1: goto L_8014F610; break;
        case 2: goto L_8014F610; break;
        case 3: goto L_8014F610; break;
        case 4: goto L_8014F5C4; break;
        case 5: goto L_8014F610; break;
        case 6: goto L_8014F600; break;
        case 7: goto L_8014F5D8; break;
        case 8: goto L_8014F610; break;
        case 9: goto L_8014F5EC; break;
        case 10: goto L_8014F610; break;
        case 11: goto L_8014F610; break;
        case 12: goto L_8014F610; break;
        case 13: goto L_8014F610; break;
        case 14: goto L_8014F5B0; break;
        case 15: goto L_8014F610; break;
        case 16: goto L_8014F610; break;
        case 17: goto L_8014F610; break;
        case 18: goto L_8014F5C4; break;
        case 19: goto L_8014F610; break;
        case 20: goto L_8014F600; break;
        case 21: goto L_8014F5D8; break;
        case 22: goto L_8014F610; break;
        case 23: goto L_8014F5EC; break;
        default: switch_error(__func__, 0x8014F5A8, 0x8018C440);
    }
    // 0x8014F5AC: nop

L_8014F5B0:
    // 0x8014F5B0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8014F5B4: addiu       $t4, $zero, 0xBF
    ctx->r12 = ADD32(0, 0XBF);
    // 0x8014F5B8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8014F5BC: b           L_8014F610
    // 0x8014F5C0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
        goto L_8014F610;
    // 0x8014F5C0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
L_8014F5C4:
    // 0x8014F5C4: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8014F5C8: addiu       $t6, $zero, 0xBF
    ctx->r14 = ADD32(0, 0XBF);
    // 0x8014F5CC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8014F5D0: b           L_8014F610
    // 0x8014F5D4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
        goto L_8014F610;
    // 0x8014F5D4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_8014F5D8:
    // 0x8014F5D8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8014F5DC: addiu       $t8, $zero, 0xBF
    ctx->r24 = ADD32(0, 0XBF);
    // 0x8014F5E0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8014F5E4: b           L_8014F610
    // 0x8014F5E8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_8014F610;
    // 0x8014F5E8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_8014F5EC:
    // 0x8014F5EC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8014F5F0: addiu       $t0, $zero, 0xBF
    ctx->r8 = ADD32(0, 0XBF);
    // 0x8014F5F4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8014F5F8: b           L_8014F610
    // 0x8014F5FC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_8014F610;
    // 0x8014F5FC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8014F600:
    // 0x8014F600: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8014F604: addiu       $t2, $zero, 0xDC
    ctx->r10 = ADD32(0, 0XDC);
    // 0x8014F608: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8014F60C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
L_8014F610:
    // 0x8014F610: lw          $t3, 0x158($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X158);
    // 0x8014F614: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F618: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8014F61C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8014F620: bnel        $at, $zero, L_8014F660
    if (ctx->r1 != 0) {
        // 0x8014F624: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014F660;
    }
    goto skip_3;
    // 0x8014F624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8014F628: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x8014F62C: bnel        $t5, $t6, L_8014F654
    if (ctx->r13 != ctx->r14) {
        // 0x8014F630: lbu         $t9, 0x18D($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X18D);
            goto L_8014F654;
    }
    goto skip_4;
    // 0x8014F630: lbu         $t9, 0x18D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18D);
    skip_4:
    // 0x8014F634: lw          $t7, 0x180($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X180);
    // 0x8014F638: beql        $t7, $zero, L_8014F654
    if (ctx->r15 == 0) {
        // 0x8014F63C: lbu         $t9, 0x18D($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X18D);
            goto L_8014F654;
    }
    goto skip_5;
    // 0x8014F63C: lbu         $t9, 0x18D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18D);
    skip_5:
    // 0x8014F640: jal         0x8014F0F4
    // 0x8014F644: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonAttack100StartSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014F644: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8014F648: b           L_8014F660
    // 0x8014F64C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014F660;
    // 0x8014F64C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014F650: lbu         $t9, 0x18D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18D);
L_8014F654:
    // 0x8014F654: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x8014F658: sb          $t0, 0x18D($v1)
    MEM_B(0X18D, ctx->r3) = ctx->r8;
    // 0x8014F65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014F660:
    // 0x8014F660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014F664: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014F668: jr          $ra
    // 0x8014F66C: nop

    return;
    // 0x8014F66C: nop

;}
RECOMP_FUNC void itMainMakeMonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173228: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8017322C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80173230: lbu         $t7, 0x4937($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4937);
    // 0x80173234: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80173238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017323C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80173240: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80173244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80173248: lw          $t2, 0x84($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X84);
    // 0x8017324C: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80173250: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80173254: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80173258: beq         $t8, $zero, L_801732A0
    if (ctx->r24 == 0) {
        // 0x8017325C: swc1        $f4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
            goto L_801732A0;
    }
    // 0x8017325C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80173260: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    // 0x80173264: jal         0x80018994
    // 0x80173268: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80173268: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    after_0:
    // 0x8017326C: bne         $v0, $zero, L_801732A0
    if (ctx->r2 != 0) {
        // 0x80173270: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_801732A0;
    }
    // 0x80173270: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80173274: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80173278: addiu       $t0, $t0, -0x2FA0
    ctx->r8 = ADD32(ctx->r8, -0X2FA0);
    // 0x8017327C: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x80173280: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x80173284: beq         $t1, $v1, L_801732A0
    if (ctx->r9 == ctx->r3) {
        // 0x80173288: nop
    
            goto L_801732A0;
    }
    // 0x80173288: nop

    // 0x8017328C: lbu         $t9, 0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1);
    // 0x80173290: beq         $t1, $t9, L_801732A0
    if (ctx->r9 == ctx->r25) {
        // 0x80173294: nop
    
            goto L_801732A0;
    }
    // 0x80173294: nop

    // 0x80173298: b           L_80173308
    // 0x8017329C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
        goto L_80173308;
    // 0x8017329C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_801732A0:
    // 0x801732A0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801732A4: addiu       $t0, $t0, -0x2FA0
    ctx->r8 = ADD32(ctx->r8, -0X2FA0);
    // 0x801732A8: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x801732AC: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x801732B0: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x801732B4: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
L_801732B8:
    // 0x801732B8: beql        $v0, $t3, L_801732DC
    if (ctx->r2 == ctx->r11) {
        // 0x801732BC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801732DC;
    }
    goto skip_0;
    // 0x801732BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x801732C0: lbu         $t4, 0x1($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1);
    // 0x801732C4: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x801732C8: beql        $v0, $t4, L_801732DC
    if (ctx->r2 == ctx->r12) {
        // 0x801732CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801732DC;
    }
    goto skip_1;
    // 0x801732CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x801732D0: sb          $v0, -0x1E($t5)
    MEM_B(-0X1E, ctx->r13) = ctx->r2;
    // 0x801732D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801732D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_801732DC:
    // 0x801732DC: bnel        $v0, $t1, L_801732B8
    if (ctx->r2 != ctx->r9) {
        // 0x801732E0: lbu         $t3, 0x0($t0)
        ctx->r11 = MEM_BU(ctx->r8, 0X0);
            goto L_801732B8;
    }
    goto skip_2;
    // 0x801732E0: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    skip_2:
    // 0x801732E4: lbu         $a0, 0x2E($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X2E);
    // 0x801732E8: jal         0x80018994
    // 0x801732EC: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x801732EC: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    after_1:
    // 0x801732F0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801732F4: addiu       $t0, $t0, -0x2FA0
    ctx->r8 = ADD32(ctx->r8, -0X2FA0);
    // 0x801732F8: addu        $t6, $t0, $v0
    ctx->r14 = ADD32(ctx->r8, ctx->r2);
    // 0x801732FC: lbu         $a1, 0x2($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2);
    // 0x80173300: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x80173304: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
L_80173308:
    // 0x80173308: lbu         $v0, 0x2E($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X2E);
    // 0x8017330C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80173310: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x80173314: beq         $v0, $at, L_80173324
    if (ctx->r2 == ctx->r1) {
        // 0x80173318: lui         $t9, 0x8000
        ctx->r25 = S32(0X8000 << 16);
            goto L_80173324;
    }
    // 0x80173318: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8017331C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80173320: sb          $t7, 0x2E($t0)
    MEM_B(0X2E, ctx->r8) = ctx->r15;
L_80173324:
    // 0x80173324: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80173328: sb          $v1, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r3;
    // 0x8017332C: sb          $a1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r5;
    // 0x80173330: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x80173334: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x80173338: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017333C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x80173340: jal         0x8016F238
    // 0x80173344: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    itManagerMakeItemKind(rdram, ctx);
        goto after_2;
    // 0x80173344: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_2:
    // 0x80173348: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x8017334C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80173350: beq         $v0, $zero, L_801733D0
    if (ctx->r2 == 0) {
        // 0x80173354: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801733D0;
    }
    // 0x80173354: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80173358: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8017335C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80173360: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80173364: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80173368: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x8017336C: lbu         $t4, 0x14($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X14);
    // 0x80173370: sb          $t4, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r12;
    // 0x80173374: lbu         $t5, 0x15($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X15);
    // 0x80173378: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8017337C: sb          $t5, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r13;
    // 0x80173380: lbu         $t6, 0x16($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X16);
    // 0x80173384: sb          $t6, 0x16($v1)
    MEM_B(0X16, ctx->r3) = ctx->r14;
    // 0x80173388: lw          $t7, 0x18($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X18);
    // 0x8017338C: sw          $t7, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r15;
    // 0x80173390: lw          $t8, 0x374($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X374);
    // 0x80173394: sw          $t8, 0x374($v1)
    MEM_W(0X374, ctx->r3) = ctx->r24;
    // 0x80173398: lw          $t9, 0x50E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50E8);
    // 0x8017339C: lbu         $t3, 0x0($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X0);
    // 0x801733A0: bnel        $t3, $at, L_801733D4
    if (ctx->r11 != ctx->r1) {
        // 0x801733A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801733D4;
    }
    goto skip_3;
    // 0x801733A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801733A8: lbu         $t4, 0x4AE3($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AE3);
    // 0x801733AC: andi        $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 & 0XFF;
    // 0x801733B0: bnel        $t4, $t5, L_801733D4
    if (ctx->r12 != ctx->r13) {
        // 0x801733B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801733D4;
    }
    goto skip_4;
    // 0x801733B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x801733B8: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x801733BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801733C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801733C4: bnel        $t1, $t6, L_801733D4
    if (ctx->r9 != ctx->r14) {
        // 0x801733C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801733D4;
    }
    goto skip_5;
    // 0x801733C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x801733CC: sb          $t7, 0x36AD($at)
    MEM_B(0X36AD, ctx->r1) = ctx->r15;
L_801733D0:
    // 0x801733D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801733D4:
    // 0x801733D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801733D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801733DC: jr          $ra
    // 0x801733E0: nop

    return;
    // 0x801733E0: nop

;}
RECOMP_FUNC void lbCommonDrawSObjAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCF00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CCF04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CCF08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CCF0C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CCF10: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x800CCF14: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800CCF18: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800CCF1C: beql        $s0, $zero, L_800CCF64
    if (ctx->r16 == 0) {
        // 0x800CCF20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CCF64;
    }
    goto skip_0;
    // 0x800CCF20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800CCF24: lhu         $t6, 0x24($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X24);
L_800CCF28:
    // 0x800CCF28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CCF2C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800CCF30: bnel        $t7, $zero, L_800CCF58
    if (ctx->r15 != 0) {
        // 0x800CCF34: lw          $s0, 0x8($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X8);
            goto L_800CCF58;
    }
    goto skip_1;
    // 0x800CCF34: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x800CCF38: jal         0x800CC118
    // 0x800CCF3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    lbCommonPrepSObjAttr(rdram, ctx);
        goto after_0;
    // 0x800CCF3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800CCF40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CCF44: jal         0x800CC818
    // 0x800CCF48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    lbCommonPrepSObjDraw(rdram, ctx);
        goto after_1;
    // 0x800CCF48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800CCF4C: jal         0x800CCED8
    // 0x800CCF50: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    lbCommonSetExternSpriteParams(rdram, ctx);
        goto after_2;
    // 0x800CCF50: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x800CCF54: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
L_800CCF58:
    // 0x800CCF58: bnel        $s0, $zero, L_800CCF28
    if (ctx->r16 != 0) {
        // 0x800CCF5C: lhu         $t6, 0x24($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X24);
            goto L_800CCF28;
    }
    goto skip_2;
    // 0x800CCF5C: lhu         $t6, 0x24($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X24);
    skip_2:
    // 0x800CCF60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CCF64:
    // 0x800CCF64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CCF68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CCF6C: jr          $ra
    // 0x800CCF70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800CCF70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gmCameraPlayerMagnifyProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E134: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010E138: lbu         $t6, 0x1581($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1581);
    // 0x8010E13C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010E140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E144: beq         $t6, $zero, L_8010E194
    if (ctx->r14 == 0) {
        // 0x8010E148: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8010E194;
    }
    // 0x8010E148: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8010E14C: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x8010E150: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8010E154: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x8010E158: jal         0x80016EDC
    // 0x8010E15C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcPrepCameraMatrix(rdram, ctx);
        goto after_0;
    // 0x8010E15C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010E160: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8010E164: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8010E168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010E16C: lw          $t8, 0x80($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X80);
    // 0x8010E170: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8010E174: beq         $t9, $zero, L_8010E184
    if (ctx->r25 == 0) {
        // 0x8010E178: nop
    
            goto L_8010E184;
    }
    // 0x8010E178: nop

    // 0x8010E17C: b           L_8010E184
    // 0x8010E180: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010E184;
    // 0x8010E180: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010E184:
    // 0x8010E184: jal         0x80017B80
    // 0x8010E188: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_1;
    // 0x8010E188: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8010E18C: jal         0x80017CC8
    // 0x8010E190: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80017CC8(rdram, ctx);
        goto after_2;
    // 0x8010E190: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_8010E194:
    // 0x8010E194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010E19C: jr          $ra
    // 0x8010E1A0: nop

    return;
    // 0x8010E1A0: nop

;}
RECOMP_FUNC void ftCommonAppealCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014E768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E76C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014E770: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8014E774: lhu         $t7, 0x1BA($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1BA);
    // 0x8014E778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014E77C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8014E780: beq         $t8, $zero, L_8014E798
    if (ctx->r24 == 0) {
        // 0x8014E784: nop
    
            goto L_8014E798;
    }
    // 0x8014E784: nop

    // 0x8014E788: jal         0x8014E6E0
    // 0x8014E78C: nop

    ftCommonAppealSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014E78C: nop

    after_0:
    // 0x8014E790: b           L_8014E798
    // 0x8014E794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014E798;
    // 0x8014E794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014E798:
    // 0x8014E798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014E79C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E7A0: jr          $ra
    // 0x8014E7A4: nop

    return;
    // 0x8014E7A4: nop

;}
RECOMP_FUNC void gcSetDObjPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008004: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80008008: addiu       $v0, $v0, 0x6A30
    ctx->r2 = ADD32(ctx->r2, 0X6A30);
    // 0x8000800C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80008010: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80008014: addiu       $v1, $v1, 0x6A34
    ctx->r3 = ADD32(ctx->r3, 0X6A34);
    // 0x80008018: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000801C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80008020: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80008024: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80008028: jr          $ra
    // 0x8000802C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x8000802C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void itLinkBombThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80186150: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80186154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80186158: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8018615C: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80186160: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80186164: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x80186168: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8018616C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80186170: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80186174: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x80186178: addiu       $a3, $a3, 0x5FD8
    ctx->r7 = ADD32(ctx->r7, 0X5FD8);
    // 0x8018617C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80186180: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80186184: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80186188: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8018618C: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80186190: jal         0x80173D24
    // 0x80186194: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    itMapCheckMapReboundProcAll(rdram, ctx);
        goto after_0;
    // 0x80186194: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80186198: beq         $v0, $zero, L_80186210
    if (ctx->r2 == 0) {
        // 0x8018619C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80186210;
    }
    // 0x8018619C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801861A0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801861A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801861A8: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x801861AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801861B0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801861B4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801861B8: bc1fl       L_801861CC
    if (!c1cs) {
        // 0x801861BC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801861CC;
    }
    goto skip_0;
    // 0x801861BC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x801861C0: b           L_801861CC
    // 0x801861C4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_801861CC;
    // 0x801861C4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x801861C8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801861CC:
    // 0x801861CC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801861D0: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801861D4: bc1t        L_80186208
    if (c1cs) {
        // 0x801861D8: nop
    
            goto L_80186208;
    }
    // 0x801861D8: nop

    // 0x801861DC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801861E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801861E4: bc1fl       L_801861F8
    if (!c1cs) {
        // 0x801861E8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801861F8;
    }
    goto skip_1;
    // 0x801861E8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_1:
    // 0x801861EC: b           L_801861F8
    // 0x801861F0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_801861F8;
    // 0x801861F0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x801861F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801861F8:
    // 0x801861F8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801861FC: nop

    // 0x80186200: bc1fl       L_80186214
    if (!c1cs) {
        // 0x80186204: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80186214;
    }
    goto skip_2;
    // 0x80186204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_80186208:
    // 0x80186208: jal         0x80186368
    // 0x8018620C: nop

    itLinkBombExplodeInitVars(rdram, ctx);
        goto after_1;
    // 0x8018620C: nop

    after_1:
L_80186210:
    // 0x80186210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80186214:
    // 0x80186214: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80186218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018621C: jr          $ra
    // 0x80186220: nop

    return;
    // 0x80186220: nop

;}
RECOMP_FUNC void ftParamSetStatUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA780: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EA784: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EA788: addiu       $t7, $sp, 0x1E
    ctx->r15 = ADD32(ctx->r29, 0X1E);
    // 0x800EA78C: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800EA790: jal         0x800EA74C
    // 0x800EA794: sh          $t9, 0x28E($a0)
    MEM_H(0X28E, ctx->r4) = ctx->r25;
    ftParamGetStatUpdateCount(rdram, ctx);
        goto after_0;
    // 0x800EA794: sh          $t9, 0x28E($a0)
    MEM_H(0X28E, ctx->r4) = ctx->r25;
    after_0:
    // 0x800EA798: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800EA79C: sh          $v0, 0x290($t0)
    MEM_H(0X290, ctx->r8) = ctx->r2;
    // 0x800EA7A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA7A8: jr          $ra
    // 0x800EA7AC: nop

    return;
    // 0x800EA7AC: nop

;}
RECOMP_FUNC void itKamexFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801808A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801808A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801808AC: jal         0x80180860
    // 0x801808B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itKamexFallInitVars(rdram, ctx);
        goto after_0;
    // 0x801808B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801808B4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801808B8: addiu       $a1, $a1, -0x50EC
    ctx->r5 = ADD32(ctx->r5, -0X50EC);
    // 0x801808BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801808C0: jal         0x80172EC8
    // 0x801808C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801808C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801808C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801808CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801808D0: jr          $ra
    // 0x801808D4: nop

    return;
    // 0x801808D4: nop

;}
RECOMP_FUNC void ftCommonTwisterShootFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143CC4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80143CC8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80143CCC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80143CD0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80143CD4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80143CD8: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x80143CDC: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80143CE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80143CE4: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80143CE8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80143CEC: addiu       $t7, $t7, 0x14
    ctx->r15 = ADD32(ctx->r15, 0X14);
    // 0x80143CF0: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80143CF4: addiu       $t9, $t9, 0xBC
    ctx->r25 = ADD32(ctx->r25, 0XBC);
    // 0x80143CF8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80143CFC: swc1        $f4, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f4.u32l;
    // 0x80143D00: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80143D04: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x80143D08: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80143D0C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80143D10: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x80143D14: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80143D18: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80143D1C: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x80143D20: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x80143D24: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80143D28: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80143D2C: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x80143D30: lwc1        $f6, 0x68($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X68);
    // 0x80143D34: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80143D38: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80143D3C: lbu         $t5, 0x12($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X12);
    // 0x80143D40: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80143D44: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80143D48: jal         0x800E9D78
    // 0x80143D4C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_0;
    // 0x80143D4C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x80143D50: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80143D54: jal         0x800E8AAC
    // 0x80143D58: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    ftParamGetBestHitStatusAll(rdram, ctx);
        goto after_1;
    // 0x80143D58: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x80143D5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80143D60: beq         $v0, $at, L_80143D70
    if (ctx->r2 == ctx->r1) {
        // 0x80143D64: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_80143D70;
    }
    // 0x80143D64: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80143D68: b           L_80143D74
    // 0x80143D6C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80143D74;
    // 0x80143D6C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80143D70:
    // 0x80143D70: lw          $s1, 0x4($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X4);
L_80143D74:
    // 0x80143D74: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80143D78: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80143D7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80143D80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80143D84: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80143D88: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80143D8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80143D90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80143D94: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x80143D98: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80143D9C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80143DA0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80143DA4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80143DA8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80143DAC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80143DB0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80143DB4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80143DB8: jal         0x80140EE4
    // 0x80143DBC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_2;
    // 0x80143DBC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_2:
    // 0x80143DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80143DC4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80143DC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80143DCC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80143DD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143DD4: jal         0x800EAA2C
    // 0x80143DD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_3;
    // 0x80143DD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x80143DDC: beq         $s1, $zero, L_80143DEC
    if (ctx->r17 == 0) {
        // 0x80143DE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80143DEC;
    }
    // 0x80143DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80143DE4: jal         0x800EA248
    // 0x80143DE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftParamUpdateDamage(rdram, ctx);
        goto after_4;
    // 0x80143DE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_80143DEC:
    // 0x80143DEC: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x80143DF0: sw          $t2, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r10;
    // 0x80143DF4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80143DF8: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80143DFC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80143E00: jr          $ra
    // 0x80143E04: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80143E04: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_ovl8_8038597C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038597C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80385980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385984: jal         0x803725DC
    // 0x80385988: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_ovl8_803725DC(rdram, ctx);
        goto after_0;
    // 0x80385988: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_0:
    // 0x8038598C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80385994: jr          $ra
    // 0x80385998: nop

    return;
    // 0x80385998: nop

;}
RECOMP_FUNC void ftCommonDashProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EC58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013EC5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EC60: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8013EC64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013EC68: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8013EC6C: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8013EC70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8013EC74: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8013EC78: lw          $v0, 0x9C8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9C8);
    // 0x8013EC7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8013EC80: bc1f        L_8013EC98
    if (!c1cs) {
        // 0x8013EC84: nop
    
            goto L_8013EC98;
    }
    // 0x8013EC84: nop

    // 0x8013EC88: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    // 0x8013EC8C: jal         0x800D8978
    // 0x8013EC90: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    ftPhysicsSetGroundVelFriction(rdram, ctx);
        goto after_0;
    // 0x8013EC90: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013EC94: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8013EC98:
    // 0x8013EC98: jal         0x800D87D0
    // 0x8013EC9C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_1;
    // 0x8013EC9C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8013ECA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013ECA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013ECA8: jr          $ra
    // 0x8013ECAC: nop

    return;
    // 0x8013ECAC: nop

;}
RECOMP_FUNC void mvOpeningCliffMakeOcarina(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013202C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132038: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8013203C: jal         0x80009968
    // 0x80132040: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132040: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132044: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132048: lw          $t6, 0x2998($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2998);
    // 0x8013204C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132050: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132054: addiu       $t7, $t7, 0x67A0
    ctx->r15 = ADD32(ctx->r15, 0X67A0);
    // 0x80132058: sw          $v0, 0x27D0($at)
    MEM_W(0X27D0, ctx->r1) = ctx->r2;
    // 0x8013205C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132068: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x8013206C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80132070: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80132074: jal         0x8000F590
    // 0x80132078: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_1;
    // 0x80132078: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x8013207C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132080: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132084: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132088: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x8013208C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132090: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132094: jal         0x80009DF4
    // 0x80132098: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80132098: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x8013209C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801320A0: addiu       $v0, $v0, 0x27D4
    ctx->r2 = ADD32(ctx->r2, 0X27D4);
    // 0x801320A4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801320A8: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x801320AC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801320B0: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x801320B4: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801320B8: addiu       $t9, $t9, 0x6850
    ctx->r25 = ADD32(ctx->r25, 0X6850);
    // 0x801320BC: lwc1        $f4, 0x40($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801320C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801320C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801320C8: swc1        $f4, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f4.u32l;
    // 0x801320CC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801320D0: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x801320D4: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x801320D8: lwc1        $f6, 0x44($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X44);
    // 0x801320DC: swc1        $f6, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f6.u32l;
    // 0x801320E0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801320E4: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x801320E8: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x801320EC: lwc1        $f8, 0x48($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X48);
    // 0x801320F0: swc1        $f8, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f8.u32l;
    // 0x801320F4: lw          $t8, 0x2998($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2998);
    // 0x801320F8: jal         0x8000BD8C
    // 0x801320FC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x801320FC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x80132100: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132104: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80132108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013210C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132110: jal         0x80008188
    // 0x80132114: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80132114: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80132118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013211C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132124: jr          $ra
    // 0x80132128: nop

    return;
    // 0x80132128: nop

;}
RECOMP_FUNC void mnPlayersVSFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B0C8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8013B0CC: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8013B0D0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8013B0D4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013B0D8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013B0DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013B0E0: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8013B0E4: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8013B0E8: addiu       $t8, $t8, -0x3F20
    ctx->r24 = ADD32(ctx->r24, -0X3F20);
    // 0x8013B0EC: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x8013B0F0: addiu       $t0, $t0, -0x3F58
    ctx->r8 = ADD32(ctx->r8, -0X3F58);
    // 0x8013B0F4: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8013B0F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013B0FC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8013B100: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8013B104: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8013B108: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8013B10C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8013B110: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8013B114: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x8013B118: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8013B11C: jal         0x800CDF78
    // 0x8013B120: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8013B120: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x8013B124: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8013B128: addiu       $s0, $s0, -0x4C60
    ctx->r16 = ADD32(ctx->r16, -0X4C60);
    // 0x8013B12C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013B130: jal         0x800CDEEC
    // 0x8013B134: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013B134: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x8013B138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013B13C: jal         0x80004980
    // 0x8013B140: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8013B140: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8013B144: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8013B148: addiu       $a2, $a2, -0x3B60
    ctx->r6 = ADD32(ctx->r6, -0X3B60);
    // 0x8013B14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013B150: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8013B154: jal         0x800CDE04
    // 0x8013B158: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8013B158: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8013B15C: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8013B160: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013B164: addiu       $a1, $a1, -0x56E0
    ctx->r5 = ADD32(ctx->r5, -0X56E0);
    // 0x8013B168: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8013B16C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8013B170: jal         0x80009968
    // 0x8013B174: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x8013B174: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_4:
    // 0x8013B178: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8013B17C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013B180: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8013B184: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8013B188: jal         0x8000B9FC
    // 0x8013B18C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x8013B18C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8013B190: jal         0x80115890
    // 0x8013B194: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x8013B194: nop

    after_6:
    // 0x8013B198: jal         0x800FD300
    // 0x8013B19C: nop

    efManagerInitEffects(rdram, ctx);
        goto after_7;
    // 0x8013B19C: nop

    after_7:
    // 0x8013B1A0: jal         0x8013A2A4
    // 0x8013B1A4: nop

    mnPlayersVSUpdateControllerOrders(rdram, ctx);
        goto after_8;
    // 0x8013B1A4: nop

    after_8:
    // 0x8013B1A8: jal         0x8013AEC8
    // 0x8013B1AC: nop

    mnPlayersVSInitVars(rdram, ctx);
        goto after_9;
    // 0x8013B1AC: nop

    after_9:
    // 0x8013B1B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013B1B4: jal         0x800D7194
    // 0x8013B1B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_10;
    // 0x8013B1B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x8013B1BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8013B1C0:
    // 0x8013B1C0: jal         0x800D786C
    // 0x8013B1C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_11;
    // 0x8013B1C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8013B1C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8013B1CC: slti        $at, $s0, 0xC
    ctx->r1 = SIGNED(ctx->r16) < 0XC ? 1 : 0;
    // 0x8013B1D0: bne         $at, $zero, L_8013B1C0
    if (ctx->r1 != 0) {
        // 0x8013B1D4: nop
    
            goto L_8013B1C0;
    }
    // 0x8013B1D4: nop

    // 0x8013B1D8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8013B1DC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8013B1E0: addiu       $s0, $s0, 0xD9C
    ctx->r16 = ADD32(ctx->r16, 0XD9C);
    // 0x8013B1E4: addiu       $v1, $v1, -0x4578
    ctx->r3 = ADD32(ctx->r3, -0X4578);
L_8013B1E8:
    // 0x8013B1E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8013B1EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8013B1F0: jal         0x80004980
    // 0x8013B1F4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    syTaskmanMalloc(rdram, ctx);
        goto after_12;
    // 0x8013B1F4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_12:
    // 0x8013B1F8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8013B1FC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013B200: addiu       $t2, $t2, -0x4288
    ctx->r10 = ADD32(ctx->r10, -0X4288);
    // 0x8013B204: addiu       $v1, $v1, 0xBC
    ctx->r3 = ADD32(ctx->r3, 0XBC);
    // 0x8013B208: bne         $v1, $t2, L_8013B1E8
    if (ctx->r3 != ctx->r10) {
        // 0x8013B20C: sw          $v0, -0x88($v1)
        MEM_W(-0X88, ctx->r3) = ctx->r2;
            goto L_8013B1E8;
    }
    // 0x8013B20C: sw          $v0, -0x88($v1)
    MEM_W(-0X88, ctx->r3) = ctx->r2;
    // 0x8013B210: jal         0x80132D1C
    // 0x8013B214: nop

    mnPlayersVSMakePortraitCamera(rdram, ctx);
        goto after_13;
    // 0x8013B214: nop

    after_13:
    // 0x8013B218: jal         0x80138B6C
    // 0x8013B21C: nop

    mnPlayersVSMakeCursorCamera(rdram, ctx);
        goto after_14;
    // 0x8013B21C: nop

    after_14:
    // 0x8013B220: jal         0x80138C0C
    // 0x8013B224: nop

    mnPlayersVSMakePuckCamera(rdram, ctx);
        goto after_15;
    // 0x8013B224: nop

    after_15:
    // 0x8013B228: jal         0x8013303C
    // 0x8013B22C: nop

    mnPlayersVSMakePlayerKindCamera(rdram, ctx);
        goto after_16;
    // 0x8013B22C: nop

    after_16:
    // 0x8013B230: jal         0x80132EFC
    // 0x8013B234: nop

    mnPlayersVSMakeGateCamera(rdram, ctx);
        goto after_17;
    // 0x8013B234: nop

    after_17:
    // 0x8013B238: jal         0x80132F9C
    // 0x8013B23C: nop

    mnPlayersVSMakePlayerKindSelectCamera(rdram, ctx);
        goto after_18;
    // 0x8013B23C: nop

    after_18:
    // 0x8013B240: jal         0x80134C64
    // 0x8013B244: nop

    mnPlayersVSMakeFighterCamera(rdram, ctx);
        goto after_19;
    // 0x8013B244: nop

    after_19:
    // 0x8013B248: jal         0x801330DC
    // 0x8013B24C: nop

    mnPlayersVSMakeTeamSelectCamera(rdram, ctx);
        goto after_20;
    // 0x8013B24C: nop

    after_20:
    // 0x8013B250: jal         0x80138CAC
    // 0x8013B254: nop

    mnPlayersVSMakeHandicapLevelCamera(rdram, ctx);
        goto after_21;
    // 0x8013B254: nop

    after_21:
    // 0x8013B258: jal         0x80132DBC
    // 0x8013B25C: nop

    mnPlayersVSMakePortraitWallpaperCamera(rdram, ctx);
        goto after_22;
    // 0x8013B25C: nop

    after_22:
    // 0x8013B260: jal         0x80132E5C
    // 0x8013B264: nop

    mnPlayersVSMakePortraitFlashCamera(rdram, ctx);
        goto after_23;
    // 0x8013B264: nop

    after_23:
    // 0x8013B268: jal         0x80138D4C
    // 0x8013B26C: nop

    mnPlayersVSMakeReadyCamera(rdram, ctx);
        goto after_24;
    // 0x8013B26C: nop

    after_24:
    // 0x8013B270: jal         0x80134284
    // 0x8013B274: nop

    mnPlayersVSMakeWallpaper(rdram, ctx);
        goto after_25;
    // 0x8013B274: nop

    after_25:
    // 0x8013B278: jal         0x801326DC
    // 0x8013B27C: nop

    mnPlayersVSMakePortraitAll(rdram, ctx);
        goto after_26;
    // 0x8013B27C: nop

    after_26:
    // 0x8013B280: jal         0x8013B090
    // 0x8013B284: nop

    mnPlayersVSInitSlotAll(rdram, ctx);
        goto after_27;
    // 0x8013B284: nop

    after_27:
    // 0x8013B288: jal         0x801343B0
    // 0x8013B28C: nop

    mnPlayersVSMakeLabels(rdram, ctx);
        goto after_28;
    // 0x8013B28C: nop

    after_28:
    // 0x8013B290: jal         0x8013992C
    // 0x8013B294: nop

    mnPlayersVSMakePuckAdjust(rdram, ctx);
        goto after_29;
    // 0x8013B294: nop

    after_29:
    // 0x8013B298: jal         0x801399E8
    // 0x8013B29C: nop

    mnPlayersVSMakePuckGlow(rdram, ctx);
        goto after_30;
    // 0x8013B29C: nop

    after_30:
    // 0x8013B2A0: jal         0x80139B4C
    // 0x8013B2A4: nop

    mnPlayersVSMakeCostumeSync(rdram, ctx);
        goto after_31;
    // 0x8013B2A4: nop

    after_31:
    // 0x8013B2A8: jal         0x80139C84
    // 0x8013B2AC: nop

    mnPlayersVSMakeSpotlight(rdram, ctx);
        goto after_32;
    // 0x8013B2AC: nop

    after_32:
    // 0x8013B2B0: jal         0x80139E60
    // 0x8013B2B4: nop

    mnPlayersVSMakeReady(rdram, ctx);
        goto after_33;
    // 0x8013B2B4: nop

    after_33:
    // 0x8013B2B8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8013B2BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013B2C0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8013B2C4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8013B2C8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8013B2CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8013B2D0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8013B2D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8013B2D8: jal         0x803904E0
    // 0x8013B2DC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_34;
    // 0x8013B2DC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_34:
    // 0x8013B2E0: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8013B2E4: lbu         $t5, 0x4AD1($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4AD1);
    // 0x8013B2E8: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8013B2EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013B2F0: beq         $t5, $at, L_8013B300
    if (ctx->r13 == ctx->r1) {
        // 0x8013B2F4: nop
    
            goto L_8013B300;
    }
    // 0x8013B2F4: nop

    // 0x8013B2F8: jal         0x80020AB4
    // 0x8013B2FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    syAudioPlayBGM(rdram, ctx);
        goto after_35;
    // 0x8013B2FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_35:
L_8013B300:
    // 0x8013B300: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013B304: lbu         $t6, 0x4D0A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4D0A);
    // 0x8013B308: bne         $t6, $zero, L_8013B320
    if (ctx->r14 != 0) {
        // 0x8013B30C: nop
    
            goto L_8013B320;
    }
    // 0x8013B30C: nop

    // 0x8013B310: jal         0x800269C0
    // 0x8013B314: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800269C0_275C0(rdram, ctx);
        goto after_36;
    // 0x8013B314: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_36:
    // 0x8013B318: b           L_8013B32C
    // 0x8013B31C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8013B32C;
    // 0x8013B31C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8013B320:
    // 0x8013B320: jal         0x800269C0
    // 0x8013B324: addiu       $a0, $zero, 0x20E
    ctx->r4 = ADD32(0, 0X20E);
    func_800269C0_275C0(rdram, ctx);
        goto after_37;
    // 0x8013B324: addiu       $a0, $zero, 0x20E
    ctx->r4 = ADD32(0, 0X20E);
    after_37:
    // 0x8013B328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8013B32C:
    // 0x8013B32C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013B330: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8013B334: jr          $ra
    // 0x8013B338: nop

    return;
    // 0x8013B338: nop

;}
RECOMP_FUNC void mnTitleMakeLogoNoOpening(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80132F40: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132F44: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132F48: lw          $t9, 0x45A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X45A0);
    // 0x80132F4C: lw          $t8, 0x42D0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X42D0);
    // 0x80132F50: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132F54: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80132F58: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132F5C: addiu       $t6, $t6, 0x2DFC
    ctx->r14 = ADD32(ctx->r14, 0X2DFC);
    // 0x80132F60: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132F64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132F68: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132F6C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80132F70: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132F74: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80132F78: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80132F7C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80132F80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132F84: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80132F88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80132F8C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80132F90: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80132F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132F98: jal         0x800CD050
    // 0x80132F9C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80132F9C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x80132FA0: lw          $a1, 0x74($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X74);
    // 0x80132FA4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132FA8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80132FAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132FB0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80132FB4: sh          $t3, 0x24($a1)
    MEM_H(0X24, ctx->r5) = ctx->r11;
    // 0x80132FB8: sb          $t4, 0x28($a1)
    MEM_B(0X28, ctx->r5) = ctx->r12;
    // 0x80132FBC: sb          $zero, 0x29($a1)
    MEM_B(0X29, ctx->r5) = 0;
    // 0x80132FC0: jal         0x80132764
    // 0x80132FC4: sb          $zero, 0x2A($a1)
    MEM_B(0X2A, ctx->r5) = 0;
    mnTitleSetPosition(rdram, ctx);
        goto after_1;
    // 0x80132FC4: sb          $zero, 0x2A($a1)
    MEM_B(0X2A, ctx->r5) = 0;
    after_1:
    // 0x80132FC8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80132FCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80132FD0: jr          $ra
    // 0x80132FD4: nop

    return;
    // 0x80132FD4: nop

;}
RECOMP_FUNC void itMLuckyDisappearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801813D0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801813D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801813D8: lhu         $a1, 0x352($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X352);
    // 0x801813DC: bne         $a1, $zero, L_801813EC
    if (ctx->r5 != 0) {
        // 0x801813E0: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_801813EC;
    }
    // 0x801813E0: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x801813E4: jr          $ra
    // 0x801813E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801813E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801813EC:
    // 0x801813EC: sh          $t6, 0x352($v1)
    MEM_H(0X352, ctx->r3) = ctx->r14;
    // 0x801813F0: jr          $ra
    // 0x801813F4: nop

    return;
    // 0x801813F4: nop

;}
RECOMP_FUNC void wpMainVelGroundTransferAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168044: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168048: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8016804C: lwc1        $f6, 0xB0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x80168050: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80168054: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80168058: lwc1        $f16, 0xAC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x8016805C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80168060: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80168064: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80168068: nop

    // 0x8016806C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80168070: nop

    // 0x80168074: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80168078: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8016807C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80168080: jr          $ra
    // 0x80168084: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80168084: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void mvOpeningPikachuSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D0C4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018D0C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018D0CC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D0D0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018D0DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018D0E0: addiu       $t8, $t8, -0x1D78
    ctx->r24 = ADD32(ctx->r24, -0X1D78);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x1BF8
    ctx->r8 = ADD32(ctx->r8, -0X1BF8);
    // 0x8018D0EC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018D0F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018D0F4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018D0F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018D0FC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018D100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018D104: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018D108: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018D10C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018D110: jal         0x800CDF78
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018D118: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D11C: addiu       $a0, $a0, -0x1F04
    ctx->r4 = ADD32(ctx->r4, -0X1F04);
    // 0x8018D120: jal         0x800CDEEC
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8018D128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D12C: jal         0x80004980
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018D134: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D138: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018D13C: addiu       $a2, $a2, -0x1BC0
    ctx->r6 = ADD32(ctx->r6, -0X1BC0);
    // 0x8018D140: addiu       $a0, $a0, -0x1F04
    ctx->r4 = ADD32(ctx->r4, -0X1F04);
    // 0x8018D144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8018D148: jal         0x800CDE04
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018D150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D154: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018D158: jr          $ra
    // 0x8018D15C: nop

    return;
    // 0x8018D15C: nop

;}
RECOMP_FUNC void mnCharactersCheckFighterAnimEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132768: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8013276C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80132770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132774: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80132778: nop

    // 0x8013277C: bc1f        L_8013278C
    if (!c1cs) {
        // 0x80132780: nop
    
            goto L_8013278C;
    }
    // 0x80132780: nop

    // 0x80132784: jr          $ra
    // 0x80132788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80132788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013278C:
    // 0x8013278C: jr          $ra
    // 0x80132790: nop

    return;
    // 0x80132790: nop

;}
RECOMP_FUNC void ftBossOkuhikouki1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159524: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80159528: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015952C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80159530: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159534: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x80159538: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015953C: jal         0x800E6F24
    // 0x80159540: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159540: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80159544: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80159548: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8015954C: lw          $a2, 0x84($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X84);
    // 0x80159550: lw          $a0, 0xADC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XADC);
    // 0x80159554: addiu       $a1, $a2, 0xB18
    ctx->r5 = ADD32(ctx->r6, 0XB18);
    // 0x80159558: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8015955C: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x80159560: lw          $v1, 0xEC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XEC);
    // 0x80159564: beq         $v1, $at, L_8015957C
    if (ctx->r3 == ctx->r1) {
        // 0x80159568: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8015957C;
    }
    // 0x80159568: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8015956C: beql        $v1, $at, L_80159580
    if (ctx->r3 == ctx->r1) {
        // 0x80159570: lw          $a3, 0x8($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X8);
            goto L_80159580;
    }
    goto skip_0;
    // 0x80159570: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x80159574: b           L_80159580
    // 0x80159578: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_80159580;
    // 0x80159578: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8015957C:
    // 0x8015957C: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
L_80159580:
    // 0x80159580: jal         0x8015839C
    // 0x80159584: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftBossCommonGetPositionCenter(rdram, ctx);
        goto after_1;
    // 0x80159584: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80159588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015958C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80159590: jr          $ra
    // 0x80159594: nop

    return;
    // 0x80159594: nop

;}
RECOMP_FUNC void mvOpeningPortraitsCoverProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132200: addiu       $a1, $a1, 0x29E8
    ctx->r5 = ADD32(ctx->r5, 0X29E8);
    // 0x80132204: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80132208: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x8013220C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132210: bne         $v1, $at, L_80132228
    if (ctx->r3 != ctx->r1) {
        // 0x80132214: lui         $at, 0xC424
        ctx->r1 = S32(0XC424 << 16);
            goto L_80132228;
    }
    // 0x80132214: lui         $at, 0xC424
    ctx->r1 = S32(0XC424 << 16);
    // 0x80132218: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8013221C: nop

    // 0x80132220: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x80132224: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
L_80132228:
    // 0x80132228: lui         $at, 0xC424
    ctx->r1 = S32(0XC424 << 16);
    // 0x8013222C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132230: slti        $at, $v1, 0x4B
    ctx->r1 = SIGNED(ctx->r3) < 0X4B ? 1 : 0;
    // 0x80132234: beq         $at, $zero, L_80132284
    if (ctx->r1 == 0) {
        // 0x80132238: lui         $at, 0x4424
        ctx->r1 = S32(0X4424 << 16);
            goto L_80132284;
    }
    // 0x80132238: lui         $at, 0x4424
    ctx->r1 = S32(0X4424 << 16);
    // 0x8013223C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132240: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80132244: lui         $at, 0x42BA
    ctx->r1 = S32(0X42BA << 16);
    // 0x80132248: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8013224C: nop

    // 0x80132250: bc1fl       L_801322C8
    if (!c1cs) {
        // 0x80132254: lw          $v1, 0x0($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X0);
            goto L_801322C8;
    }
    goto skip_0;
    // 0x80132254: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80132258: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013225C: nop

    // 0x80132260: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80132264: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132268: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013226C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80132270: nop

    // 0x80132274: bc1fl       L_801322C8
    if (!c1cs) {
        // 0x80132278: lw          $v1, 0x0($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X0);
            goto L_801322C8;
    }
    goto skip_1;
    // 0x80132278: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x8013227C: b           L_801322C4
    // 0x80132280: swc1        $f12, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f12.u32l;
        goto L_801322C4;
    // 0x80132280: swc1        $f12, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f12.u32l;
L_80132284:
    // 0x80132284: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80132288: lui         $at, 0x42BA
    ctx->r1 = S32(0X42BA << 16);
    // 0x8013228C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80132290: nop

    // 0x80132294: bc1fl       L_801322C8
    if (!c1cs) {
        // 0x80132298: lw          $v1, 0x0($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X0);
            goto L_801322C8;
    }
    goto skip_2;
    // 0x80132298: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    skip_2:
    // 0x8013229C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801322A0: nop

    // 0x801322A4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801322A8: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801322AC: lwc1        $f18, 0x58($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801322B0: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x801322B4: nop

    // 0x801322B8: bc1fl       L_801322C8
    if (!c1cs) {
        // 0x801322BC: lw          $v1, 0x0($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X0);
            goto L_801322C8;
    }
    goto skip_3;
    // 0x801322BC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    skip_3:
    // 0x801322C0: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
L_801322C4:
    // 0x801322C4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
L_801322C8:
    // 0x801322C8: lui         $at, 0x4424
    ctx->r1 = S32(0X4424 << 16);
    // 0x801322CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801322D0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801322D4: beq         $v1, $at, L_80132330
    if (ctx->r3 == ctx->r1) {
        // 0x801322D8: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80132330;
    }
    // 0x801322D8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801322DC: beq         $v1, $at, L_80132368
    if (ctx->r3 == ctx->r1) {
        // 0x801322E0: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80132368;
    }
    // 0x801322E0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801322E4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x801322E8: beq         $v1, $at, L_8013234C
    if (ctx->r3 == ctx->r1) {
        // 0x801322EC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8013234C;
    }
    // 0x801322EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801322F0: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x801322F4: beq         $v1, $at, L_80132384
    if (ctx->r3 == ctx->r1) {
        // 0x801322F8: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_80132384;
    }
    // 0x801322F8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801322FC: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80132300: beq         $v1, $at, L_801323D8
    if (ctx->r3 == ctx->r1) {
        // 0x80132304: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_801323D8;
    }
    // 0x80132304: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80132308: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8013230C: beq         $v1, $at, L_801323A0
    if (ctx->r3 == ctx->r1) {
        // 0x80132310: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_801323A0;
    }
    // 0x80132310: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80132314: beq         $v1, $at, L_801323F4
    if (ctx->r3 == ctx->r1) {
        // 0x80132318: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_801323F4;
    }
    // 0x80132318: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8013231C: addiu       $at, $zero, 0x87
    ctx->r1 = ADD32(0, 0X87);
    // 0x80132320: beq         $v1, $at, L_801323BC
    if (ctx->r3 == ctx->r1) {
        // 0x80132324: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_801323BC;
    }
    // 0x80132324: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132328: jr          $ra
    // 0x8013232C: nop

    return;
    // 0x8013232C: nop

L_80132330:
    // 0x80132330: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132334: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132338: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x8013233C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132340: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x80132344: jr          $ra
    // 0x80132348: sw          $zero, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = 0;
    return;
    // 0x80132348: sw          $zero, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = 0;
L_8013234C:
    // 0x8013234C: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80132350: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132354: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x80132358: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013235C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132360: jr          $ra
    // 0x80132364: sw          $t6, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r14;
    return;
    // 0x80132364: sw          $t6, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r14;
L_80132368:
    // 0x80132368: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8013236C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132370: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x80132374: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132378: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x8013237C: jr          $ra
    // 0x80132380: sw          $t7, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r15;
    return;
    // 0x80132380: sw          $t7, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r15;
L_80132384:
    // 0x80132384: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80132388: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013238C: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x80132390: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132394: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132398: jr          $ra
    // 0x8013239C: sw          $t8, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r24;
    return;
    // 0x8013239C: sw          $t8, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r24;
L_801323A0:
    // 0x801323A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801323A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801323A8: swc1        $f12, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f12.u32l;
    // 0x801323AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801323B0: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x801323B4: jr          $ra
    // 0x801323B8: sw          $zero, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = 0;
    return;
    // 0x801323B8: sw          $zero, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = 0;
L_801323BC:
    // 0x801323BC: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x801323C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801323C4: swc1        $f12, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f12.u32l;
    // 0x801323C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801323CC: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801323D0: jr          $ra
    // 0x801323D4: sw          $t9, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r25;
    return;
    // 0x801323D4: sw          $t9, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r25;
L_801323D8:
    // 0x801323D8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801323DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801323E0: swc1        $f12, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f12.u32l;
    // 0x801323E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801323E8: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x801323EC: jr          $ra
    // 0x801323F0: sw          $t0, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r8;
    return;
    // 0x801323F0: sw          $t0, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r8;
L_801323F4:
    // 0x801323F4: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x801323F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801323FC: swc1        $f12, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f12.u32l;
    // 0x80132400: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132404: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132408: sw          $t1, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = ctx->r9;
    // 0x8013240C: jr          $ra
    // 0x80132410: nop

    return;
    // 0x80132410: nop

;}
RECOMP_FUNC void mn1PModeMakeLink3Camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132690: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132694: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132698: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013269C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801326A0: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801326A4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801326A8: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801326AC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801326B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801326B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801326B8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801326BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801326C0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801326C4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801326C8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801326CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801326D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801326D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801326D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801326DC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801326E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801326E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801326E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801326EC: jal         0x8000B93C
    // 0x801326F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801326F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801326F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801326F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801326FC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132700: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132704: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132708: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013270C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132710: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132714: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132718: jal         0x80007080
    // 0x8013271C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013271C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132720: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132724: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132728: jr          $ra
    // 0x8013272C: nop

    return;
    // 0x8013272C: nop

;}
RECOMP_FUNC void ftMainPlayAnimEventsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E0834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E0838: jal         0x800E07D4
    // 0x800E083C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftMainPlayAnim(rdram, ctx);
        goto after_0;
    // 0x800E083C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E0840: jal         0x800E02A8
    // 0x800E0844: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftMainUpdateMotionEventsAll(rdram, ctx);
        goto after_1;
    // 0x800E0844: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800E0848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E084C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E0850: jr          $ra
    // 0x800E0854: nop

    return;
    // 0x800E0854: nop

;}
RECOMP_FUNC void ftCommonGuardOffProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148F74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80148F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148F7C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80148F80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80148F84: jal         0x80148304
    // 0x80148F88: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonGuardUpdateShieldVars(rdram, ctx);
        goto after_0;
    // 0x80148F88: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80148F8C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80148F90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80148F94: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80148F98: bnel        $t8, $zero, L_80148FB4
    if (ctx->r24 != 0) {
        // 0x80148F9C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80148FB4;
    }
    goto skip_0;
    // 0x80148F9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80148FA0: jal         0x80149510
    // 0x80148FA4: nop

    ftCommonShieldBreakFlyCommonSetStatus(rdram, ctx);
        goto after_1;
    // 0x80148FA4: nop

    after_1:
    // 0x80148FA8: b           L_80148FE4
    // 0x80148FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80148FE4;
    // 0x80148FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148FB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80148FB4:
    // 0x80148FB4: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80148FB8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80148FBC: nop

    // 0x80148FC0: bc1f        L_80148FD8
    if (!c1cs) {
        // 0x80148FC4: nop
    
            goto L_80148FD8;
    }
    // 0x80148FC4: nop

    // 0x80148FC8: jal         0x8013E1C8
    // 0x80148FCC: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x80148FCC: nop

    after_2:
    // 0x80148FD0: b           L_80148FE4
    // 0x80148FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80148FE4;
    // 0x80148FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80148FD8:
    // 0x80148FD8: jal         0x80148714
    // 0x80148FDC: nop

    ftCommonGuardUpdateJoints(rdram, ctx);
        goto after_3;
    // 0x80148FDC: nop

    after_3:
    // 0x80148FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80148FE4:
    // 0x80148FE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80148FE8: jr          $ra
    // 0x80148FEC: nop

    return;
    // 0x80148FEC: nop

;}
RECOMP_FUNC void ftCommonGuardOnSetHitStatusYoshi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80148148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014814C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80148150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80148154: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80148158: jal         0x800E8884
    // 0x8014815C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_0;
    // 0x8014815C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80148160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148164: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80148168: jal         0x800E8884
    // 0x8014816C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_1;
    // 0x8014816C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80148170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148174: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80148178: jal         0x800E8884
    // 0x8014817C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_2;
    // 0x8014817C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80148180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148184: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80148188: jal         0x800E8884
    // 0x8014818C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_3;
    // 0x8014818C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x80148190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148194: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80148198: jal         0x800E8884
    // 0x8014819C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_4;
    // 0x8014819C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801481A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801481A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x801481A8: jal         0x800E8884
    // 0x801481AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_5;
    // 0x801481AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x801481B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801481B4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x801481B8: jal         0x800E8884
    // 0x801481BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_6;
    // 0x801481BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x801481C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801481C4: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x801481C8: jal         0x800E8884
    // 0x801481CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_7;
    // 0x801481CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x801481D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801481D4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x801481D8: jal         0x800E8884
    // 0x801481DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_8;
    // 0x801481DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x801481E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801481E4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x801481E8: jal         0x800E8884
    // 0x801481EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_9;
    // 0x801481EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x801481F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801481F4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x801481F8: jal         0x800E8884
    // 0x801481FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_10;
    // 0x801481FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x80148200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80148204: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80148208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014820C: jr          $ra
    // 0x80148210: nop

    return;
    // 0x80148210: nop

;}
RECOMP_FUNC void mnTitleUpdateFireSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A6C: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80132A70: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132A74: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132A78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80132A7C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80132A80: lw          $t8, 0x41F0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X41F0);
    // 0x80132A84: lw          $t9, 0x45A4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X45A4);
    // 0x80132A88: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x80132A8C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80132A90: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80132A94: addiu       $t4, $t2, 0x3C
    ctx->r12 = ADD32(ctx->r10, 0X3C);
L_80132A98:
    // 0x80132A98: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x80132A9C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80132AA0: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80132AA4: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80132AA8: lw          $t0, -0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, -0X8);
    // 0x80132AAC: sw          $t0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r8;
    // 0x80132AB0: lw          $t1, -0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, -0X4);
    // 0x80132AB4: bne         $t2, $t4, L_80132A98
    if (ctx->r10 != ctx->r12) {
        // 0x80132AB8: sw          $t1, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r9;
            goto L_80132A98;
    }
    // 0x80132AB8: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x80132ABC: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x80132AC0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132AC4: sw          $t1, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r9;
    // 0x80132AC8: lw          $t0, 0x4($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4);
    // 0x80132ACC: sw          $t0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r8;
    // 0x80132AD0: beq         $a1, $zero, L_80132AE8
    if (ctx->r5 == 0) {
        // 0x80132AD4: sh          $t5, 0x24($a0)
        MEM_H(0X24, ctx->r4) = ctx->r13;
            goto L_80132AE8;
    }
    // 0x80132AD4: sh          $t5, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r13;
    // 0x80132AD8: lui         $at, 0x4118
    ctx->r1 = S32(0X4118 << 16);
    // 0x80132ADC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132AE0: b           L_80132AF4
    // 0x80132AE4: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
        goto L_80132AF4;
    // 0x80132AE4: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
L_80132AE8:
    // 0x80132AE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132AEC: nop

    // 0x80132AF0: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
L_80132AF4:
    // 0x80132AF4: beq         $a1, $zero, L_80132B0C
    if (ctx->r5 == 0) {
        // 0x80132AF8: lui         $at, 0x4108
        ctx->r1 = S32(0X4108 << 16);
            goto L_80132B0C;
    }
    // 0x80132AF8: lui         $at, 0x4108
    ctx->r1 = S32(0X4108 << 16);
    // 0x80132AFC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80132B00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132B04: b           L_80132B18
    // 0x80132B08: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
        goto L_80132B18;
    // 0x80132B08: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
L_80132B0C:
    // 0x80132B0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132B10: nop

    // 0x80132B14: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
L_80132B18:
    // 0x80132B18: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80132B1C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132B20: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x80132B24: bne         $at, $zero, L_80132B30
    if (ctx->r1 != 0) {
        // 0x80132B28: sw          $t7, 0x54($a0)
        MEM_W(0X54, ctx->r4) = ctx->r15;
            goto L_80132B30;
    }
    // 0x80132B28: sw          $t7, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r15;
    // 0x80132B2C: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
L_80132B30:
    // 0x80132B30: jr          $ra
    // 0x80132B34: nop

    return;
    // 0x80132B34: nop

;}
RECOMP_FUNC void func_ovl8_80371CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371CC0: lw          $a1, 0x4C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4C);
    // 0x80371CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80371CC8: beq         $a1, $zero, L_80371CF0
    if (ctx->r5 == 0) {
        // 0x80371CCC: nop
    
            goto L_80371CF0;
    }
    // 0x80371CCC: nop

    // 0x80371CD0: lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X20);
    // 0x80371CD4: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80371CD8: lw          $t9, 0xBC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBC);
    // 0x80371CDC: lh          $t6, 0xB8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB8);
    // 0x80371CE0: jalr        $t9
    // 0x80371CE4: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80371CE4: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x80371CE8: b           L_80371CF4
    // 0x80371CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80371CF4;
    // 0x80371CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80371CF0:
    // 0x80371CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80371CF4:
    // 0x80371CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371CF8: jr          $ra
    // 0x80371CFC: nop

    return;
    // 0x80371CFC: nop

;}
RECOMP_FUNC void syAudioBnkfPatchInst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E7C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001E7C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001E7CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001E7D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001E7D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001E7D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E7DC: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x8001E7E0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8001E7E4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001E7E8: bne         $t6, $zero, L_8001E838
    if (ctx->r14 != 0) {
        // 0x8001E7EC: or          $s4, $a2, $zero
        ctx->r20 = ctx->r6 | 0;
            goto L_8001E838;
    }
    // 0x8001E7EC: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001E7F0: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    // 0x8001E7F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E7F8: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
    // 0x8001E7FC: blez        $t8, L_8001E838
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001E800: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001E838;
    }
    // 0x8001E800: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001E804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E808: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
L_8001E80C:
    // 0x8001E80C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001E810: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8001E814: addu        $a0, $t9, $s2
    ctx->r4 = ADD32(ctx->r25, ctx->r18);
    // 0x8001E818: jal         0x8001E858
    // 0x8001E81C: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    syAudioBnkfPatchSound(rdram, ctx);
        goto after_0;
    // 0x8001E81C: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    after_0:
    // 0x8001E820: lh          $t1, 0xE($s3)
    ctx->r9 = MEM_H(ctx->r19, 0XE);
    // 0x8001E824: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001E828: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E82C: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001E830: bnel        $at, $zero, L_8001E80C
    if (ctx->r1 != 0) {
        // 0x8001E834: lw          $t9, 0x10($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X10);
            goto L_8001E80C;
    }
    goto skip_0;
    // 0x8001E834: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    skip_0:
L_8001E838:
    // 0x8001E838: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E83C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E840: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E844: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E848: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E84C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E850: jr          $ra
    // 0x8001E854: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E854: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnStartupLogoThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80131B04: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80131B08: lui         $at, 0xBF1B
    ctx->r1 = S32(0XBF1B << 16);
    // 0x80131B0C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80131B10: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80131B14: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80131B18: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80131B1C: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80131B20: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80131B24: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80131B28: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80131B2C: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x80131B30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80131B34: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x80131B38: subu        $t6, $s2, $s0
    ctx->r14 = SUB32(ctx->r18, ctx->r16);
L_80131B3C:
    // 0x80131B3C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80131B40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80131B44: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80131B48: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80131B4C: nop

    // 0x80131B50: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80131B54: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x80131B58: jal         0x8000B1E8
    // 0x80131B5C: swc1        $f10, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f10.u32l;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80131B5C: swc1        $f10, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f10.u32l;
    after_0:
    // 0x80131B60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80131B64: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x80131B68: bnel        $at, $zero, L_80131B3C
    if (ctx->r1 != 0) {
        // 0x80131B6C: subu        $t6, $s2, $s0
        ctx->r14 = SUB32(ctx->r18, ctx->r16);
            goto L_80131B3C;
    }
    goto skip_0;
    // 0x80131B6C: subu        $t6, $s2, $s0
    ctx->r14 = SUB32(ctx->r18, ctx->r16);
    skip_0:
    // 0x80131B70: swc1        $f20, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
    // 0x80131B74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80131B78:
    // 0x80131B78: jal         0x8000B1E8
    // 0x80131B7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x80131B7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80131B80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80131B84: slti        $at, $s0, 0x18
    ctx->r1 = SIGNED(ctx->r16) < 0X18 ? 1 : 0;
    // 0x80131B88: bne         $at, $zero, L_80131B78
    if (ctx->r1 != 0) {
        // 0x80131B8C: nop
    
            goto L_80131B78;
    }
    // 0x80131B8C: nop

    // 0x80131B90: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B94: addiu       $t7, $t7, 0x1F50
    ctx->r15 = ADD32(ctx->r15, 0X1F50);
    // 0x80131B98: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131B9C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x80131BA0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80131BA4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80131BA8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80131BAC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80131BB0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80131BB4: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x80131BB8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80131BBC: jal         0x800D4060
    // 0x80131BC0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_2;
    // 0x80131BC0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_2:
    // 0x80131BC4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80131BC8: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
L_80131BCC:
    // 0x80131BCC: jal         0x8000B1E8
    // 0x80131BD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_3;
    // 0x80131BD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80131BD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80131BD8: bne         $s0, $s1, L_80131BCC
    if (ctx->r16 != ctx->r17) {
        // 0x80131BDC: nop
    
            goto L_80131BCC;
    }
    // 0x80131BDC: nop

    // 0x80131BE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131BE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131BE8: sw          $t1, 0x2074($at)
    MEM_W(0X2074, ctx->r1) = ctx->r9;
L_80131BEC:
    // 0x80131BEC: jal         0x8000B1E8
    // 0x80131BF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_4;
    // 0x80131BF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80131BF4: b           L_80131BEC
    // 0x80131BF8: nop

        goto L_80131BEC;
    // 0x80131BF8: nop

    // 0x80131BFC: nop

    // 0x80131C00: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80131C04: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80131C08: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80131C0C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80131C10: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80131C14: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80131C18: jr          $ra
    // 0x80131C1C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80131C1C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftMarioSpecialHiInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156418: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015641C: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80156420: jr          $ra
    // 0x80156424: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x80156424: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}
RECOMP_FUNC void ftFoxSpecialAirHiEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C7D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015C7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C7DC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015C7E0: jal         0x800DE80C
    // 0x8015C7E4: addiu       $a1, $a1, -0x3808
    ctx->r5 = ADD32(ctx->r5, -0X3808);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x8015C7E4: addiu       $a1, $a1, -0x3808
    ctx->r5 = ADD32(ctx->r5, -0X3808);
    after_0:
    // 0x8015C7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015C7EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015C7F0: jr          $ra
    // 0x8015C7F4: nop

    return;
    // 0x8015C7F4: nop

;}
RECOMP_FUNC void SC1PGameBossWallpaper1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191DAC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80191DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80191DB4: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x80191DB8: bnel        $t6, $at, L_80191DF4
    if (ctx->r14 != ctx->r1) {
        // 0x80191DBC: lw          $t7, 0x84($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X84);
            goto L_80191DF4;
    }
    goto skip_0;
    // 0x80191DBC: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    skip_0:
    // 0x80191DC0: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80191DC4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191DC8: ldc1        $f8, 0x2F78($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X2F78);
    // 0x80191DCC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80191DD0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80191DD4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80191DD8: swc1        $f16, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f16.u32l;
    // 0x80191DDC: lw          $a1, 0x78($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X78);
    // 0x80191DE0: jal         0x8000BB4C
    // 0x80191DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcSetAllAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x80191DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80191DE8: b           L_80191E10
    // 0x80191DEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80191E10;
    // 0x80191DEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80191DF0: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
L_80191DF4:
    // 0x80191DF4: slti        $at, $t7, 0xFF
    ctx->r1 = SIGNED(ctx->r15) < 0XFF ? 1 : 0;
    // 0x80191DF8: beq         $at, $zero, L_80191E10
    if (ctx->r1 == 0) {
        // 0x80191DFC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80191E10;
    }
    // 0x80191DFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191E00: lwc1        $f4, 0x2F80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2F80);
    // 0x80191E04: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80191E08: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80191E0C: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
L_80191E10:
    // 0x80191E10: jal         0x80191AEC
    // 0x80191E14: nop

    SC1PGameBossWallpaper3ProcUpdate0(rdram, ctx);
        goto after_1;
    // 0x80191E14: nop

    after_1:
    // 0x80191E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191E20: jr          $ra
    // 0x80191E24: nop

    return;
    // 0x80191E24: nop

;}
RECOMP_FUNC void mnPlayersVSCheckHandicapAuto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137120: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80137124: lbu         $t6, 0x4D10($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4D10);
    // 0x80137128: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013712C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80137130: bne         $t6, $at, L_80137140
    if (ctx->r14 != ctx->r1) {
        // 0x80137134: nop
    
            goto L_80137140;
    }
    // 0x80137134: nop

    // 0x80137138: jr          $ra
    // 0x8013713C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013713C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80137140:
    // 0x80137140: jr          $ra
    // 0x80137144: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80137144: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftMainSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6F24: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800E6F28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E6F2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E6F30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E6F34: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800E6F38: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800E6F3C: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x800E6F40: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x800E6F44: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x800E6F48: addiu       $t8, $sp, 0x64
    ctx->r24 = ADD32(ctx->r29, 0X64);
    // 0x800E6F4C: lw          $t7, 0x9C8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X9C8);
    // 0x800E6F50: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800E6F54: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800E6F58: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    // 0x800E6F5C: lhu         $t0, 0x28E($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X28E);
    // 0x800E6F60: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x800E6F64: lb          $t2, 0x191($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X191);
    // 0x800E6F68: bgezl       $t2, L_800E6F90
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800E6F6C: lbu         $a1, 0xF($s1)
        ctx->r5 = MEM_BU(ctx->r17, 0XF);
            goto L_800E6F90;
    }
    goto skip_0;
    // 0x800E6F6C: lbu         $a1, 0xF($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XF);
    skip_0:
    // 0x800E6F70: jal         0x800E0654
    // 0x800E6F74: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftMainUpdateMotionEventsForwardEffect(rdram, ctx);
        goto after_0;
    // 0x800E6F74: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_0:
    // 0x800E6F78: lw          $v0, 0x9D8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9D8);
    // 0x800E6F7C: beql        $v0, $zero, L_800E6F90
    if (ctx->r2 == 0) {
        // 0x800E6F80: lbu         $a1, 0xF($s1)
        ctx->r5 = MEM_BU(ctx->r17, 0XF);
            goto L_800E6F90;
    }
    goto skip_1;
    // 0x800E6F80: lbu         $a1, 0xF($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XF);
    skip_1:
    // 0x800E6F84: jalr        $v0
    // 0x800E6F88: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800E6F88: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_1:
    // 0x800E6F8C: lbu         $a1, 0xF($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XF);
L_800E6F90:
    // 0x800E6F90: lbu         $t4, 0xE($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XE);
    // 0x800E6F94: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x800E6F98: beq         $a1, $t4, L_800E6FB0
    if (ctx->r5 == ctx->r12) {
        // 0x800E6F9C: sw          $t3, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r11;
            goto L_800E6FB0;
    }
    // 0x800E6F9C: sw          $t3, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r11;
    // 0x800E6FA0: jal         0x800E9198
    // 0x800E6FA4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_2;
    // 0x800E6FA4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_2:
    // 0x800E6FA8: lbu         $t5, 0xF($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XF);
    // 0x800E6FAC: sb          $t5, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r13;
L_800E6FB0:
    // 0x800E6FB0: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x800E6FB4: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
    // 0x800E6FB8: bnel        $t6, $zero, L_800E6FDC
    if (ctx->r14 != 0) {
        // 0x800E6FBC: andi        $t9, $s0, 0x200
        ctx->r25 = ctx->r16 & 0X200;
            goto L_800E6FDC;
    }
    goto skip_2;
    // 0x800E6FBC: andi        $t9, $s0, 0x200
    ctx->r25 = ctx->r16 & 0X200;
    skip_2:
    // 0x800E6FC0: lw          $t7, 0x18C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X18C);
    // 0x800E6FC4: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x800E6FC8: beql        $t8, $zero, L_800E6FDC
    if (ctx->r24 == 0) {
        // 0x800E6FCC: andi        $t9, $s0, 0x200
        ctx->r25 = ctx->r16 & 0X200;
            goto L_800E6FDC;
    }
    goto skip_3;
    // 0x800E6FCC: andi        $t9, $s0, 0x200
    ctx->r25 = ctx->r16 & 0X200;
    skip_3:
    // 0x800E6FD0: jal         0x800E8518
    // 0x800E6FD4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftParamClearAttackCollAll(rdram, ctx);
        goto after_3;
    // 0x800E6FD4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_3:
    // 0x800E6FD8: andi        $t9, $s0, 0x200
    ctx->r25 = ctx->r16 & 0X200;
L_800E6FDC:
    // 0x800E6FDC: bne         $t9, $zero, L_800E6FE8
    if (ctx->r25 != 0) {
        // 0x800E6FE0: andi        $t0, $s0, 0x10
        ctx->r8 = ctx->r16 & 0X10;
            goto L_800E6FE8;
    }
    // 0x800E6FE0: andi        $t0, $s0, 0x10
    ctx->r8 = ctx->r16 & 0X10;
    // 0x800E6FE4: sw          $zero, 0x278($s1)
    MEM_W(0X278, ctx->r17) = 0;
L_800E6FE8:
    // 0x800E6FE8: bnel        $t0, $zero, L_800E702C
    if (ctx->r8 != 0) {
        // 0x800E6FEC: lw          $t5, 0x18C($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X18C);
            goto L_800E702C;
    }
    goto skip_4;
    // 0x800E6FEC: lw          $t5, 0x18C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18C);
    skip_4:
    // 0x800E6FF0: lw          $t1, 0x18C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X18C);
    // 0x800E6FF4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800E6FF8: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x800E6FFC: bgezl       $t3, L_800E7010
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800E7000: lw          $t4, 0x5B8($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X5B8);
            goto L_800E7010;
    }
    goto skip_5;
    // 0x800E7000: lw          $t4, 0x5B8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X5B8);
    skip_5:
    // 0x800E7004: jal         0x800E880C
    // 0x800E7008: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetHitStatusPartAll(rdram, ctx);
        goto after_4;
    // 0x800E7008: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x800E700C: lw          $t4, 0x5B8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X5B8);
L_800E7010:
    // 0x800E7010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E7014: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800E7018: beql        $t4, $at, L_800E702C
    if (ctx->r12 == ctx->r1) {
        // 0x800E701C: lw          $t5, 0x18C($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X18C);
            goto L_800E702C;
    }
    goto skip_6;
    // 0x800E701C: lw          $t5, 0x18C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18C);
    skip_6:
    // 0x800E7020: jal         0x800E8A24
    // 0x800E7024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_5;
    // 0x800E7024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800E7028: lw          $t5, 0x18C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18C);
L_800E702C:
    // 0x800E702C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800E7030: bgezl       $t7, L_800E7044
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800E7034: andi        $t8, $s0, 0x20
        ctx->r24 = ctx->r16 & 0X20;
            goto L_800E7044;
    }
    goto skip_7;
    // 0x800E7034: andi        $t8, $s0, 0x20
    ctx->r24 = ctx->r16 & 0X20;
    skip_7:
    // 0x800E7038: jal         0x800E8B00
    // 0x800E703C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftParamResetFighterDamageCollsAll(rdram, ctx);
        goto after_6;
    // 0x800E703C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_6:
    // 0x800E7040: andi        $t8, $s0, 0x20
    ctx->r24 = ctx->r16 & 0X20;
L_800E7044:
    // 0x800E7044: bnel        $t8, $zero, L_800E7068
    if (ctx->r24 != 0) {
        // 0x800E7048: andi        $t2, $s0, 0x80
        ctx->r10 = ctx->r16 & 0X80;
            goto L_800E7068;
    }
    goto skip_8;
    // 0x800E7048: andi        $t2, $s0, 0x80
    ctx->r10 = ctx->r16 & 0X80;
    skip_8:
    // 0x800E704C: lw          $t9, 0x18C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X18C);
    // 0x800E7050: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800E7054: bgezl       $t1, L_800E7068
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800E7058: andi        $t2, $s0, 0x80
        ctx->r10 = ctx->r16 & 0X80;
            goto L_800E7068;
    }
    goto skip_9;
    // 0x800E7058: andi        $t2, $s0, 0x80
    ctx->r10 = ctx->r16 & 0X80;
    skip_9:
    // 0x800E705C: jal         0x800E8ECC
    // 0x800E7060: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftParamResetModelPartAll(rdram, ctx);
        goto after_7;
    // 0x800E7060: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_7:
    // 0x800E7064: andi        $t2, $s0, 0x80
    ctx->r10 = ctx->r16 & 0X80;
L_800E7068:
    // 0x800E7068: bnel        $t2, $zero, L_800E708C
    if (ctx->r10 != 0) {
        // 0x800E706C: andi        $t6, $s0, 0x2
        ctx->r14 = ctx->r16 & 0X2;
            goto L_800E708C;
    }
    goto skip_10;
    // 0x800E706C: andi        $t6, $s0, 0x2
    ctx->r14 = ctx->r16 & 0X2;
    skip_10:
    // 0x800E7070: lw          $t3, 0x18C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X18C);
    // 0x800E7074: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x800E7078: bgezl       $t5, L_800E708C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800E707C: andi        $t6, $s0, 0x2
        ctx->r14 = ctx->r16 & 0X2;
            goto L_800E708C;
    }
    goto skip_11;
    // 0x800E707C: andi        $t6, $s0, 0x2
    ctx->r14 = ctx->r16 & 0X2;
    skip_11:
    // 0x800E7080: jal         0x800E96B0
    // 0x800E7084: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftParamResetTexturePartAll(rdram, ctx);
        goto after_8;
    // 0x800E7084: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_8:
    // 0x800E7088: andi        $t6, $s0, 0x2
    ctx->r14 = ctx->r16 & 0X2;
L_800E708C:
    // 0x800E708C: bnel        $t6, $zero, L_800E70BC
    if (ctx->r14 != 0) {
        // 0x800E7090: andi        $t0, $s0, 0x4
        ctx->r8 = ctx->r16 & 0X4;
            goto L_800E70BC;
    }
    goto skip_12;
    // 0x800E7090: andi        $t0, $s0, 0x4
    ctx->r8 = ctx->r16 & 0X4;
    skip_12:
    // 0x800E7094: lw          $t7, 0xA64($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XA64);
    // 0x800E7098: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800E709C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800E70A0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800E70A4: lbu         $t9, -0x242B($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X242B);
    // 0x800E70A8: beql        $t9, $zero, L_800E70BC
    if (ctx->r25 == 0) {
        // 0x800E70AC: andi        $t0, $s0, 0x4
        ctx->r8 = ctx->r16 & 0X4;
            goto L_800E70BC;
    }
    goto skip_13;
    // 0x800E70AC: andi        $t0, $s0, 0x4
    ctx->r8 = ctx->r16 & 0X4;
    skip_13:
    // 0x800E70B0: jal         0x800E98D4
    // 0x800E70B4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_9;
    // 0x800E70B4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_9:
    // 0x800E70B8: andi        $t0, $s0, 0x4
    ctx->r8 = ctx->r16 & 0X4;
L_800E70BC:
    // 0x800E70BC: bnel        $t0, $zero, L_800E70E0
    if (ctx->r8 != 0) {
        // 0x800E70C0: lbu         $t4, 0x18C($s1)
        ctx->r12 = MEM_BU(ctx->r17, 0X18C);
            goto L_800E70E0;
    }
    goto skip_14;
    // 0x800E70C0: lbu         $t4, 0x18C($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18C);
    skip_14:
    // 0x800E70C4: lw          $t1, 0x18C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X18C);
    // 0x800E70C8: sll         $t3, $t1, 27
    ctx->r11 = S32(ctx->r9 << 27);
    // 0x800E70CC: bgezl       $t3, L_800E70E0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800E70D0: lbu         $t4, 0x18C($s1)
        ctx->r12 = MEM_BU(ctx->r17, 0X18C);
            goto L_800E70E0;
    }
    goto skip_15;
    // 0x800E70D0: lbu         $t4, 0x18C($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18C);
    skip_15:
    // 0x800E70D4: jal         0x800E9C3C
    // 0x800E70D8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftParamProcStopEffect(rdram, ctx);
        goto after_10;
    // 0x800E70D8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_10:
    // 0x800E70DC: lbu         $t4, 0x18C($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18C);
L_800E70E0:
    // 0x800E70E0: lbu         $t6, 0x18D($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X18D);
    // 0x800E70E4: lbu         $t8, 0x18F($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X18F);
    // 0x800E70E8: andi        $t0, $s0, 0x8
    ctx->r8 = ctx->r16 & 0X8;
    // 0x800E70EC: andi        $t5, $t4, 0xFFFB
    ctx->r13 = ctx->r12 & 0XFFFB;
    // 0x800E70F0: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x800E70F4: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x800E70F8: sb          $t5, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r13;
    // 0x800E70FC: sb          $t7, 0x18D($s1)
    MEM_B(0X18D, ctx->r17) = ctx->r15;
    // 0x800E7100: bne         $t0, $zero, L_800E7110
    if (ctx->r8 != 0) {
        // 0x800E7104: sb          $t9, 0x18F($s1)
        MEM_B(0X18F, ctx->r17) = ctx->r25;
            goto L_800E7110;
    }
    // 0x800E7104: sb          $t9, 0x18F($s1)
    MEM_B(0X18F, ctx->r17) = ctx->r25;
    // 0x800E7108: andi        $t2, $t7, 0xF7
    ctx->r10 = ctx->r15 & 0XF7;
    // 0x800E710C: sb          $t2, 0x18D($s1)
    MEM_B(0X18D, ctx->r17) = ctx->r10;
L_800E7110:
    // 0x800E7110: lbu         $t5, 0x18E($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X18E);
    // 0x800E7114: lbu         $t3, 0x18D($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X18D);
    // 0x800E7118: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E711C: andi        $t7, $t5, 0xFF7F
    ctx->r15 = ctx->r13 & 0XFF7F;
    // 0x800E7120: andi        $t9, $t7, 0xBF
    ctx->r25 = ctx->r15 & 0XBF;
    // 0x800E7124: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x800E7128: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x800E712C: sb          $t7, 0x18E($s1)
    MEM_B(0X18E, ctx->r17) = ctx->r15;
    // 0x800E7130: andi        $t1, $t9, 0xEF
    ctx->r9 = ctx->r25 & 0XEF;
    // 0x800E7134: sb          $t9, 0x18E($s1)
    MEM_B(0X18E, ctx->r17) = ctx->r25;
    // 0x800E7138: sb          $t1, 0x18E($s1)
    MEM_B(0X18E, ctx->r17) = ctx->r9;
    // 0x800E713C: andi        $t2, $t1, 0xFB
    ctx->r10 = ctx->r9 & 0XFB;
    // 0x800E7140: sb          $t4, 0x18D($s1)
    MEM_B(0X18D, ctx->r17) = ctx->r12;
    // 0x800E7144: beq         $t3, $at, L_800E71C4
    if (ctx->r11 == ctx->r1) {
        // 0x800E7148: sb          $t2, 0x18E($s1)
        MEM_B(0X18E, ctx->r17) = ctx->r10;
            goto L_800E71C4;
    }
    // 0x800E7148: sb          $t2, 0x18E($s1)
    MEM_B(0X18E, ctx->r17) = ctx->r10;
    // 0x800E714C: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x800E7150: jal         0x80115630
    // 0x800E7154: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    gmRumbleStopRumbleID(rdram, ctx);
        goto after_11;
    // 0x800E7154: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x800E7158: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x800E715C: jal         0x80115630
    // 0x800E7160: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    gmRumbleStopRumbleID(rdram, ctx);
        goto after_12;
    // 0x800E7160: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x800E7164: andi        $t4, $s0, 0x4000
    ctx->r12 = ctx->r16 & 0X4000;
    // 0x800E7168: bne         $t4, $zero, L_800E7178
    if (ctx->r12 != 0) {
        // 0x800E716C: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_800E7178;
    }
    // 0x800E716C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800E7170: jal         0x80115630
    // 0x800E7174: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    gmRumbleStopRumbleID(rdram, ctx);
        goto after_13;
    // 0x800E7174: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    after_13:
L_800E7178:
    // 0x800E7178: lw          $t5, 0x44($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X44);
    // 0x800E717C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E7180: lwc1        $f8, -0x170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X170);
    // 0x800E7184: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800E7188: lw          $t6, 0x8E8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8E8);
    // 0x800E718C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E7190: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E7194: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E7198: swc1        $f10, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f10.u32l;
    // 0x800E719C: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800E71A0: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x800E71A4: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x800E71A8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800E71AC: lw          $t1, 0x8E8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8E8);
    // 0x800E71B0: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x800E71B4: lwc1        $f16, 0x38($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X38);
    // 0x800E71B8: swc1        $f16, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f16.u32l;
    // 0x800E71BC: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x800E71C0: swc1        $f0, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f0.u32l;
L_800E71C4:
    // 0x800E71C4: lbu         $t2, 0x18F($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X18F);
    // 0x800E71C8: lw          $t6, 0x14C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14C);
    // 0x800E71CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E71D0: andi        $t4, $t2, 0xFFF7
    ctx->r12 = ctx->r10 & 0XFFF7;
    // 0x800E71D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E71D8: sb          $t4, 0x18F($s1)
    MEM_B(0X18F, ctx->r17) = ctx->r12;
    // 0x800E71DC: andi        $t5, $t4, 0xFE
    ctx->r13 = ctx->r12 & 0XFE;
    // 0x800E71E0: sb          $t5, 0x18F($s1)
    MEM_B(0X18F, ctx->r17) = ctx->r13;
    // 0x800E71E4: bne         $t6, $zero, L_800E71FC
    if (ctx->r14 != 0) {
        // 0x800E71E8: swc1        $f18, 0x81C($s1)
        MEM_W(0X81C, ctx->r17) = ctx->f18.u32l;
            goto L_800E71FC;
    }
    // 0x800E71E8: swc1        $f18, 0x81C($s1)
    MEM_W(0X81C, ctx->r17) = ctx->f18.u32l;
    // 0x800E71EC: andi        $t7, $s0, 0x1000
    ctx->r15 = ctx->r16 & 0X1000;
    // 0x800E71F0: bne         $t7, $zero, L_800E71FC
    if (ctx->r15 != 0) {
        // 0x800E71F4: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_800E71FC;
    }
    // 0x800E71F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800E71F8: sw          $t8, 0x80C($s1)
    MEM_W(0X80C, ctx->r17) = ctx->r24;
L_800E71FC:
    // 0x800E71FC: andi        $t9, $s0, 0x40
    ctx->r25 = ctx->r16 & 0X40;
    // 0x800E7200: bne         $t9, $zero, L_800E7214
    if (ctx->r25 != 0) {
        // 0x800E7204: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800E7214;
    }
    // 0x800E7204: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800E7208: lbu         $t0, 0x190($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X190);
    // 0x800E720C: andi        $t1, $t0, 0xFF1F
    ctx->r9 = ctx->r8 & 0XFF1F;
    // 0x800E7210: sb          $t1, 0x190($s1)
    MEM_B(0X190, ctx->r17) = ctx->r9;
L_800E7214:
    // 0x800E7214: lbu         $t4, 0x190($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X190);
    // 0x800E7218: sw          $t2, 0x144($s1)
    MEM_W(0X144, ctx->r17) = ctx->r10;
    // 0x800E721C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E7220: ori         $t6, $t4, 0x2
    ctx->r14 = ctx->r12 | 0X2;
    // 0x800E7224: sb          $t6, 0x190($s1)
    MEM_B(0X190, ctx->r17) = ctx->r14;
    // 0x800E7228: andi        $t7, $t6, 0xFE
    ctx->r15 = ctx->r14 & 0XFE;
    // 0x800E722C: sb          $t7, 0x190($s1)
    MEM_B(0X190, ctx->r17) = ctx->r15;
    // 0x800E7230: jal         0x800E8098
    // 0x800E7234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_14;
    // 0x800E7234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x800E7238: lbu         $t8, 0x191($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X191);
    // 0x800E723C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E7240: andi        $t6, $s0, 0x800
    ctx->r14 = ctx->r16 & 0X800;
    // 0x800E7244: andi        $t0, $t8, 0xFFBF
    ctx->r8 = ctx->r24 & 0XFFBF;
    // 0x800E7248: andi        $t2, $t0, 0xDF
    ctx->r10 = ctx->r8 & 0XDF;
    // 0x800E724C: sb          $t0, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r8;
    // 0x800E7250: sb          $t2, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r10;
    // 0x800E7254: andi        $t3, $t2, 0xEF
    ctx->r11 = ctx->r10 & 0XEF;
    // 0x800E7258: sb          $t3, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r11;
    // 0x800E725C: lhu         $t4, 0x190($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X190);
    // 0x800E7260: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x800E7264: beq         $t5, $at, L_800E7270
    if (ctx->r13 == ctx->r1) {
        // 0x800E7268: andi        $t7, $t3, 0xF0
        ctx->r15 = ctx->r11 & 0XF0;
            goto L_800E7270;
    }
    // 0x800E7268: andi        $t7, $t3, 0xF0
    ctx->r15 = ctx->r11 & 0XF0;
    // 0x800E726C: sb          $t7, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r15;
L_800E7270:
    // 0x800E7270: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E7274: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E7278: andi        $t8, $s0, 0x100
    ctx->r24 = ctx->r16 & 0X100;
    // 0x800E727C: bne         $t8, $zero, L_800E7288
    if (ctx->r24 != 0) {
        // 0x800E7280: swc1        $f4, 0x864($s1)
        MEM_W(0X864, ctx->r17) = ctx->f4.u32l;
            goto L_800E7288;
    }
    // 0x800E7280: swc1        $f4, 0x864($s1)
    MEM_W(0X864, ctx->r17) = ctx->f4.u32l;
    // 0x800E7284: sw          $zero, 0x174($s1)
    MEM_W(0X174, ctx->r17) = 0;
L_800E7288:
    // 0x800E7288: lbu         $t9, 0x192($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X192);
    // 0x800E728C: andi        $t5, $s0, 0x400
    ctx->r13 = ctx->r16 & 0X400;
    // 0x800E7290: andi        $t1, $t9, 0xFF7F
    ctx->r9 = ctx->r25 & 0XFF7F;
    // 0x800E7294: andi        $t3, $t1, 0xDF
    ctx->r11 = ctx->r9 & 0XDF;
    // 0x800E7298: sb          $t1, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r9;
    // 0x800E729C: sb          $t3, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r11;
    // 0x800E72A0: andi        $t4, $t3, 0xBF
    ctx->r12 = ctx->r11 & 0XBF;
    // 0x800E72A4: bne         $t5, $zero, L_800E72B0
    if (ctx->r13 != 0) {
        // 0x800E72A8: sb          $t4, 0x192($s1)
        MEM_B(0X192, ctx->r17) = ctx->r12;
            goto L_800E72B0;
    }
    // 0x800E72A8: sb          $t4, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r12;
    // 0x800E72AC: sh          $zero, 0x276($s1)
    MEM_H(0X276, ctx->r17) = 0;
L_800E72B0:
    // 0x800E72B0: bnel        $t6, $zero, L_800E72C4
    if (ctx->r14 != 0) {
        // 0x800E72B4: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_800E72C4;
    }
    goto skip_16;
    // 0x800E72B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_16:
    // 0x800E72B8: jal         0x800E81E4
    // 0x800E72BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamStopLoopSFX(rdram, ctx);
        goto after_15;
    // 0x800E72BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x800E72C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_800E72C4:
    // 0x800E72C4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800E72C8: andi        $t7, $s0, 0x2000
    ctx->r15 = ctx->r16 & 0X2000;
    // 0x800E72CC: swc1        $f6, 0x7E8($s1)
    MEM_W(0X7E8, ctx->r17) = ctx->f6.u32l;
    // 0x800E72D0: bne         $t7, $zero, L_800E72E0
    if (ctx->r15 != 0) {
        // 0x800E72D4: swc1        $f8, 0x7EC($s1)
        MEM_W(0X7EC, ctx->r17) = ctx->f8.u32l;
            goto L_800E72E0;
    }
    // 0x800E72D4: swc1        $f8, 0x7EC($s1)
    MEM_W(0X7EC, ctx->r17) = ctx->f8.u32l;
    // 0x800E72D8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800E72DC: sb          $t8, 0xA9D($s1)
    MEM_B(0XA9D, ctx->r17) = ctx->r24;
L_800E72E0:
    // 0x800E72E0: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x800E72E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800E72E8: beq         $v0, $at, L_800E7314
    if (ctx->r2 == ctx->r1) {
        // 0x800E72EC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800E7314;
    }
    // 0x800E72EC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800E72F0: beq         $v0, $at, L_800E7314
    if (ctx->r2 == ctx->r1) {
        // 0x800E72F4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_800E7314;
    }
    // 0x800E72F4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800E72F8: beq         $v0, $at, L_800E7314
    if (ctx->r2 == ctx->r1) {
        // 0x800E72FC: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800E7314;
    }
    // 0x800E72FC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800E7300: beql        $v0, $at, L_800E7318
    if (ctx->r2 == ctx->r1) {
        // 0x800E7304: lw          $t9, 0x20($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X20);
            goto L_800E7318;
    }
    goto skip_17;
    // 0x800E7304: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    skip_17:
    // 0x800E7308: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800E730C: nop

    // 0x800E7310: swc1        $f10, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f10.u32l;
L_800E7314:
    // 0x800E7314: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
L_800E7318:
    // 0x800E7318: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E731C: beql        $t9, $at, L_800E7348
    if (ctx->r25 == ctx->r1) {
        // 0x800E7320: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_800E7348;
    }
    goto skip_18;
    // 0x800E7320: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    skip_18:
    // 0x800E7324: lbu         $t0, 0x16($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X16);
    // 0x800E7328: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800E732C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800E7330: beq         $t0, $at, L_800E7344
    if (ctx->r8 == ctx->r1) {
        // 0x800E7334: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_800E7344;
    }
    // 0x800E7334: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800E7338: jal         0x800E827C
    // 0x800E733C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    ftParamMoveDLLink(rdram, ctx);
        goto after_16;
    // 0x800E733C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    after_16:
    // 0x800E7340: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
L_800E7344:
    // 0x800E7344: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
L_800E7348:
    // 0x800E7348: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800E734C: bne         $at, $zero, L_800E735C
    if (ctx->r1 != 0) {
        // 0x800E7350: sw          $zero, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = 0;
            goto L_800E735C;
    }
    // 0x800E7350: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x800E7354: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x800E7358: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800E735C:
    // 0x800E735C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800E7360: ori         $at, $at, 0xF
    ctx->r1 = ctx->r1 | 0XF;
    // 0x800E7364: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800E7368: bne         $at, $zero, L_800E7398
    if (ctx->r1 != 0) {
        // 0x800E736C: lui         $t3, 0x8039
        ctx->r11 = S32(0X8039 << 16);
            goto L_800E7398;
    }
    // 0x800E736C: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x800E7370: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x800E7374: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x800E7378: ori         $at, $at, 0xFFF1
    ctx->r1 = ctx->r1 | 0XFFF1;
    // 0x800E737C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800E7380: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800E7384: lw          $t3, 0xD20($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD20);
    // 0x800E7388: addu        $t4, $v0, $at
    ctx->r12 = ADD32(ctx->r2, ctx->r1);
    // 0x800E738C: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x800E7390: b           L_800E7420
    // 0x800E7394: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
        goto L_800E7420;
    // 0x800E7394: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
L_800E7398:
    // 0x800E7398: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800E739C: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800E73A0: bne         $at, $zero, L_800E73C0
    if (ctx->r1 != 0) {
        // 0x800E73A4: lui         $t5, 0x8039
        ctx->r13 = S32(0X8039 << 16);
            goto L_800E73C0;
    }
    // 0x800E73A4: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x800E73A8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800E73AC: addiu       $t5, $t5, 0xBE8
    ctx->r13 = ADD32(ctx->r13, 0XBE8);
    // 0x800E73B0: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x800E73B4: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800E73B8: b           L_800E7420
    // 0x800E73BC: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
        goto L_800E7420;
    // 0x800E73BC: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
L_800E73C0:
    // 0x800E73C0: slti        $at, $v0, 0xDC
    ctx->r1 = SIGNED(ctx->r2) < 0XDC ? 1 : 0;
    // 0x800E73C4: bnel        $at, $zero, L_800E73F4
    if (ctx->r1 != 0) {
        // 0x800E73C8: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_800E73F4;
    }
    goto skip_19;
    // 0x800E73C8: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    skip_19:
    // 0x800E73CC: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800E73D0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800E73D4: addiu       $t0, $v0, -0xDC
    ctx->r8 = ADD32(ctx->r2, -0XDC);
    // 0x800E73D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800E73DC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800E73E0: lw          $t9, -0x48C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X48C0);
    // 0x800E73E4: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x800E73E8: b           L_800E7420
    // 0x800E73EC: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
        goto L_800E7420;
    // 0x800E73EC: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x800E73F0: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
L_800E73F4:
    // 0x800E73F4: bne         $at, $zero, L_800E7414
    if (ctx->r1 != 0) {
        // 0x800E73F8: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_800E7414;
    }
    // 0x800E73F8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800E73FC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E7400: addiu       $t1, $t1, -0x71B0
    ctx->r9 = ADD32(ctx->r9, -0X71B0);
    // 0x800E7404: addiu       $t2, $v0, -0x6
    ctx->r10 = ADD32(ctx->r2, -0X6);
    // 0x800E7408: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x800E740C: b           L_800E7420
    // 0x800E7410: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
        goto L_800E7420;
    // 0x800E7410: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
L_800E7414:
    // 0x800E7414: addiu       $t3, $t3, -0x7228
    ctx->r11 = ADD32(ctx->r11, -0X7228);
    // 0x800E7418: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x800E741C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
L_800E7420:
    // 0x800E7420: lw          $t4, 0x20($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X20);
    // 0x800E7424: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E7428: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800E742C: beq         $t4, $at, L_800E74B4
    if (ctx->r12 == ctx->r1) {
        // 0x800E7430: lw          $t5, 0x80($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X80);
            goto L_800E74B4;
    }
    // 0x800E7430: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x800E7434: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x800E7438: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800E743C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x800E7440: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800E7444: addu        $s0, $t5, $v1
    ctx->r16 = ADD32(ctx->r13, ctx->r3);
    // 0x800E7448: lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X0);
    // 0x800E744C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E7450: andi        $a1, $a1, 0x3F
    ctx->r5 = ctx->r5 & 0X3F;
    // 0x800E7454: beq         $a1, $zero, L_800E7468
    if (ctx->r5 == 0) {
        // 0x800E7458: nop
    
            goto L_800E7468;
    }
    // 0x800E7458: nop

    // 0x800E745C: lw          $t6, 0x288($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X288);
    // 0x800E7460: beql        $t6, $a1, L_800E7478
    if (ctx->r14 == ctx->r5) {
        // 0x800E7464: lw          $t8, 0x80($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X80);
            goto L_800E7478;
    }
    goto skip_20;
    // 0x800E7464: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    skip_20:
L_800E7468:
    // 0x800E7468: jal         0x800EA5E8
    // 0x800E746C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    ftParamSetMotionID(rdram, ctx);
        goto after_17;
    // 0x800E746C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_17:
    // 0x800E7470: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800E7474: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
L_800E7478:
    // 0x800E7478: addiu       $t7, $sp, 0x60
    ctx->r15 = ADD32(ctx->r29, 0X60);
    // 0x800E747C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E7480: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800E7484: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x800E7488: sh          $t1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r9;
    // 0x800E748C: lhu         $v0, 0x60($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X60);
    // 0x800E7490: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800E7494: beq         $v0, $zero, L_800E74AC
    if (ctx->r2 == 0) {
        // 0x800E7498: nop
    
            goto L_800E74AC;
    }
    // 0x800E7498: nop

    // 0x800E749C: lw          $t2, 0x28C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X28C);
    // 0x800E74A0: andi        $t3, $t2, 0x3FF
    ctx->r11 = ctx->r10 & 0X3FF;
    // 0x800E74A4: beql        $t3, $v0, L_800E74B8
    if (ctx->r11 == ctx->r2) {
        // 0x800E74A8: lw          $v0, 0xA0C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0XA0C);
            goto L_800E74B8;
    }
    goto skip_21;
    // 0x800E74A8: lw          $v0, 0xA0C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA0C);
    skip_21:
L_800E74AC:
    // 0x800E74AC: jal         0x800EA778
    // 0x800E74B0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    ftParamSetStatUpdate(rdram, ctx);
        goto after_18;
    // 0x800E74B0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_18:
L_800E74B4:
    // 0x800E74B4: lw          $v0, 0xA0C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA0C);
L_800E74B8:
    // 0x800E74B8: beql        $v0, $zero, L_800E74D0
    if (ctx->r2 == 0) {
        // 0x800E74BC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800E74D0;
    }
    goto skip_22;
    // 0x800E74BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_22:
    // 0x800E74C0: jalr        $v0
    // 0x800E74C4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_19;
    // 0x800E74C4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_19:
    // 0x800E74C8: sw          $zero, 0xA0C($s1)
    MEM_W(0XA0C, ctx->r17) = 0;
    // 0x800E74CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800E74D0:
    // 0x800E74D0: jal         0x800EA7B0
    // 0x800E74D4: lhu         $a1, 0x64($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X64);
    ftParamUpdate1PGameAttackStats(rdram, ctx);
        goto after_20;
    // 0x800E74D4: lhu         $a1, 0x64($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X64);
    after_20:
    // 0x800E74D8: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800E74DC: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x800E74E0: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800E74E4: beq         $t4, $zero, L_800E7510
    if (ctx->r12 == 0) {
        // 0x800E74E8: sll         $t6, $t5, 2
        ctx->r14 = S32(ctx->r13 << 2);
            goto L_800E7510;
    }
    // 0x800E74E8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800E74EC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800E74F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E74F4: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x800E74F8: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800E74FC: lw          $v1, 0x9C4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X9C4);
    // 0x800E7500: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800E7504: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
    // 0x800E7508: b           L_800E7534
    // 0x800E750C: lw          $a0, 0x64($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X64);
        goto L_800E7534;
    // 0x800E750C: lw          $a0, 0x64($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X64);
L_800E7510:
    // 0x800E7510: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800E7514: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800E7518: lw          $v1, 0x9C4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X9C4);
    // 0x800E751C: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x800E7520: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800E7524: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800E7528: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x800E752C: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
    // 0x800E7530: lw          $a0, 0x68($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X68);
L_800E7534:
    // 0x800E7534: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E7538: beq         $v0, $at, L_800E79EC
    if (ctx->r2 == ctx->r1) {
        // 0x800E753C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800E79EC;
    }
    // 0x800E753C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E7540: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800E7544: beq         $v0, $at, L_800E79EC
    if (ctx->r2 == ctx->r1) {
        // 0x800E7548: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_800E79EC;
    }
    // 0x800E7548: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800E754C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800E7550: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800E7554: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x800E7558: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800E755C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800E7560: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800E7564: sll         $t8, $t4, 30
    ctx->r24 = S32(ctx->r12 << 30);
    // 0x800E7568: bgezl       $t8, L_800E7588
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E756C: lw          $a0, 0x0($t1)
        ctx->r4 = MEM_W(ctx->r9, 0X0);
            goto L_800E7588;
    }
    goto skip_23;
    // 0x800E756C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    skip_23:
    // 0x800E7570: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800E7574: lw          $t7, 0x38($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X38);
    // 0x800E7578: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x800E757C: b           L_800E75A8
    // 0x800E7580: sw          $t0, 0x9CC($s1)
    MEM_W(0X9CC, ctx->r17) = ctx->r8;
        goto L_800E75A8;
    // 0x800E7580: sw          $t0, 0x9CC($s1)
    MEM_W(0X9CC, ctx->r17) = ctx->r8;
    // 0x800E7584: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
L_800E7588:
    // 0x800E7588: beql        $a0, $zero, L_800E75A8
    if (ctx->r4 == 0) {
        // 0x800E758C: sw          $zero, 0x9CC($s1)
        MEM_W(0X9CC, ctx->r17) = 0;
            goto L_800E75A8;
    }
    goto skip_24;
    // 0x800E758C: sw          $zero, 0x9CC($s1)
    MEM_W(0X9CC, ctx->r17) = 0;
    skip_24:
    // 0x800E7590: jal         0x800CDDD8
    // 0x800E7594: lw          $a1, 0x9D0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X9D0);
    lbRelocGetForceExternHeapFile(rdram, ctx);
        goto after_21;
    // 0x800E7594: lw          $a1, 0x9D0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X9D0);
    after_21:
    // 0x800E7598: lw          $t2, 0x9D0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X9D0);
    // 0x800E759C: b           L_800E75A8
    // 0x800E75A0: sw          $t2, 0x9CC($s1)
    MEM_W(0X9CC, ctx->r17) = ctx->r10;
        goto L_800E75A8;
    // 0x800E75A0: sw          $t2, 0x9CC($s1)
    MEM_W(0X9CC, ctx->r17) = ctx->r10;
    // 0x800E75A4: sw          $zero, 0x9CC($s1)
    MEM_W(0X9CC, ctx->r17) = 0;
L_800E75A8:
    // 0x800E75A8: lw          $t3, 0x9CC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X9CC);
    // 0x800E75AC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800E75B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E75B4: beql        $t3, $zero, L_800E78E4
    if (ctx->r11 == 0) {
        // 0x800E75B8: lw          $t3, 0x80($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X80);
            goto L_800E78E4;
    }
    goto skip_25;
    // 0x800E75B8: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    skip_25:
    // 0x800E75BC: lw          $t4, 0x198($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X198);
    // 0x800E75C0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800E75C4: addiu       $a0, $zero, -0x20
    ctx->r4 = ADD32(0, -0X20);
    // 0x800E75C8: and         $v1, $t4, $a0
    ctx->r3 = ctx->r12 & ctx->r4;
    // 0x800E75CC: sw          $t8, 0x198($s1)
    MEM_W(0X198, ctx->r17) = ctx->r24;
    // 0x800E75D0: bne         $v1, $zero, L_800E75DC
    if (ctx->r3 != 0) {
        // 0x800E75D4: and         $v0, $t8, $a0
        ctx->r2 = ctx->r24 & ctx->r4;
            goto L_800E75DC;
    }
    // 0x800E75D4: and         $v0, $t8, $a0
    ctx->r2 = ctx->r24 & ctx->r4;
    // 0x800E75D8: beq         $v0, $zero, L_800E766C
    if (ctx->r2 == 0) {
        // 0x800E75DC: sll         $t9, $v1, 0
        ctx->r25 = S32(ctx->r3 << 0);
            goto L_800E766C;
    }
L_800E75DC:
    // 0x800E75DC: sll         $t9, $v1, 0
    ctx->r25 = S32(ctx->r3 << 0);
L_800E75E0:
    // 0x800E75E0: bltz        $t9, L_800E7610
    if (SIGNED(ctx->r25) < 0) {
        // 0x800E75E4: lui         $a2, 0x8000
        ctx->r6 = S32(0X8000 << 16);
            goto L_800E7610;
    }
    // 0x800E75E4: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800E75E8: and         $t7, $v0, $a2
    ctx->r15 = ctx->r2 & ctx->r6;
    // 0x800E75EC: beq         $t7, $zero, L_800E7654
    if (ctx->r15 == 0) {
        // 0x800E75F0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800E7654;
    }
    // 0x800E75F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E75F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E75F8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800E75FC: jal         0x800E69C4
    // 0x800E7600: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    ftMainUpdateHiddenPartID(rdram, ctx);
        goto after_22;
    // 0x800E7600: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    after_22:
    // 0x800E7604: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x800E7608: b           L_800E7654
    // 0x800E760C: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
        goto L_800E7654;
    // 0x800E760C: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
L_800E7610:
    // 0x800E7610: and         $t0, $v0, $a2
    ctx->r8 = ctx->r2 & ctx->r6;
    // 0x800E7614: beq         $t0, $zero, L_800E763C
    if (ctx->r8 == 0) {
        // 0x800E7618: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800E763C;
    }
    // 0x800E7618: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E761C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E7620: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E7624: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800E7628: jal         0x800E6CE0
    // 0x800E762C: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    ftMainAddHiddenPartID(rdram, ctx);
        goto after_23;
    // 0x800E762C: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    after_23:
    // 0x800E7630: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x800E7634: b           L_800E7654
    // 0x800E7638: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
        goto L_800E7654;
    // 0x800E7638: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
L_800E763C:
    // 0x800E763C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E7640: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800E7644: jal         0x800E6E00
    // 0x800E7648: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    ftMainEjectHiddenPartID(rdram, ctx);
        goto after_24;
    // 0x800E7648: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    after_24:
    // 0x800E764C: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x800E7650: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
L_800E7654:
    // 0x800E7654: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800E7658: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800E765C: bne         $v1, $zero, L_800E75DC
    if (ctx->r3 != 0) {
        // 0x800E7660: sll         $v0, $v0, 1
        ctx->r2 = S32(ctx->r2 << 1);
            goto L_800E75DC;
    }
    // 0x800E7660: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800E7664: bnel        $v0, $zero, L_800E75E0
    if (ctx->r2 != 0) {
        // 0x800E7668: sll         $t9, $v1, 0
        ctx->r25 = S32(ctx->r3 << 0);
            goto L_800E75E0;
    }
    goto skip_26;
    // 0x800E7668: sll         $t9, $v1, 0
    ctx->r25 = S32(ctx->r3 << 0);
    skip_26:
L_800E766C:
    // 0x800E766C: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x800E7670: lbu         $t3, 0xE($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XE);
    // 0x800E7674: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800E7678: lw          $t2, 0x2D4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2D4);
    // 0x800E767C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800E7680: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x800E7684: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x800E7688: lw          $v1, -0x10($t6)
    ctx->r3 = MEM_W(ctx->r14, -0X10);
    // 0x800E768C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E7690: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800E7694: beql        $a1, $t8, L_800E770C
    if (ctx->r5 == ctx->r24) {
        // 0x800E7698: lw          $a0, 0x198($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X198);
            goto L_800E770C;
    }
    goto skip_27;
    // 0x800E7698: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
    skip_27:
    // 0x800E769C: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
L_800E76A0:
    // 0x800E76A0: beql        $v0, $zero, L_800E76F8
    if (ctx->r2 == 0) {
        // 0x800E76A4: lw          $t2, 0x2C($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X2C);
            goto L_800E76F8;
    }
    goto skip_28;
    // 0x800E76A4: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    skip_28:
    // 0x800E76A8: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800E76AC: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x800E76B0: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800E76B4: sw          $t5, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r13;
    // 0x800E76B8: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x800E76BC: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x800E76C0: lw          $t0, 0x14($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X14);
    // 0x800E76C4: sw          $t0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r8;
    // 0x800E76C8: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x800E76CC: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
    // 0x800E76D0: lw          $t0, 0x1C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1C);
    // 0x800E76D4: sw          $t0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r8;
    // 0x800E76D8: lw          $t3, 0x20($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X20);
    // 0x800E76DC: sw          $t3, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r11;
    // 0x800E76E0: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x800E76E4: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x800E76E8: lw          $t3, 0x28($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X28);
    // 0x800E76EC: sb          $zero, 0x54($v0)
    MEM_B(0X54, ctx->r2) = 0;
    // 0x800E76F0: sw          $t3, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r11;
    // 0x800E76F4: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
L_800E76F8:
    // 0x800E76F8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800E76FC: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
    // 0x800E7700: bnel        $a1, $t2, L_800E76A0
    if (ctx->r5 != ctx->r10) {
        // 0x800E7704: lw          $v0, 0x8E8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8E8);
            goto L_800E76A0;
    }
    goto skip_29;
    // 0x800E7704: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    skip_29:
    // 0x800E7708: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
L_800E770C:
    // 0x800E770C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800E7710: bgezl       $t6, L_800E773C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E7714: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800E773C;
    }
    goto skip_30;
    // 0x800E7714: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_30:
    // 0x800E7718: lw          $v0, 0x8EC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8EC);
    // 0x800E771C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E7720: sb          $zero, 0x54($v0)
    MEM_B(0X54, ctx->r2) = 0;
    // 0x800E7724: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800E7728: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x800E772C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800E7730: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x800E7734: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
    // 0x800E7738: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800E773C:
    // 0x800E773C: srl         $t8, $a0, 31
    ctx->r24 = S32(U32(ctx->r4) >> 31);
    // 0x800E7740: beql        $t8, $zero, L_800E7788
    if (ctx->r24 == 0) {
        // 0x800E7744: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_800E7788;
    }
    goto skip_31;
    // 0x800E7744: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    skip_31:
    // 0x800E7748: lw          $v0, 0x8F0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8F0);
    // 0x800E774C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E7750: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E7754: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E7758: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800E775C: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x800E7760: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800E7764: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x800E7768: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x800E776C: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x800E7770: sb          $zero, 0x54($v0)
    MEM_B(0X54, ctx->r2) = 0;
    // 0x800E7774: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x800E7778: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x800E777C: swc1        $f4, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f4.u32l;
    // 0x800E7780: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
    // 0x800E7784: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
L_800E7788:
    // 0x800E7788: bgez        $t9, L_800E77C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E778C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800E77C8;
    }
    // 0x800E778C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E7790: lw          $v0, 0x8F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8F4);
    // 0x800E7794: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E7798: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E779C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800E77A0: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800E77A4: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x800E77A8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800E77AC: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x800E77B0: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x800E77B4: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x800E77B8: sb          $zero, 0x54($v0)
    MEM_B(0X54, ctx->r2) = 0;
    // 0x800E77BC: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x800E77C0: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x800E77C4: swc1        $f10, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f10.u32l;
L_800E77C8:
    // 0x800E77C8: lw          $t7, 0x8E8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8E8);
    // 0x800E77CC: lw          $a1, 0x9CC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X9CC);
    // 0x800E77D0: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x800E77D4: jal         0x800C87F4
    // 0x800E77D8: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    lbCommonAddFighterPartsFigatree(rdram, ctx);
        goto after_25;
    // 0x800E77D8: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    after_25:
    // 0x800E77DC: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800E77E0: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800E77E4: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x800E77E8: lwc1        $f18, 0x78($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X78);
    // 0x800E77EC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800E77F0: nop

    // 0x800E77F4: bc1tl       L_800E780C
    if (c1cs) {
        // 0x800E77F8: lw          $a0, 0x198($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X198);
            goto L_800E780C;
    }
    goto skip_32;
    // 0x800E77F8: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
    skip_32:
    // 0x800E77FC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800E7800: jal         0x8000BB04
    // 0x800E7804: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    gcSetAnimSpeed(rdram, ctx);
        goto after_26;
    // 0x800E7804: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_26:
    // 0x800E7808: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
L_800E780C:
    // 0x800E780C: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x800E7810: bgezl       $t2, L_800E7848
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800E7814: lw          $t6, 0x190($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X190);
            goto L_800E7848;
    }
    goto skip_33;
    // 0x800E7814: lw          $t6, 0x190($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X190);
    skip_33:
    // 0x800E7818: lw          $v0, 0x8EC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8EC);
    // 0x800E781C: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x800E7820: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x800E7824: sw          $v1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r3;
    // 0x800E7828: sw          $a1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r5;
    // 0x800E782C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800E7830: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x800E7834: lw          $t4, 0x14($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X14);
    // 0x800E7838: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800E783C: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800E7840: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
    // 0x800E7844: lw          $t6, 0x190($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X190);
L_800E7848:
    // 0x800E7848: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800E784C: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x800E7850: bgez        $t5, L_800E7878
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800E7854: nop
    
            goto L_800E7878;
    }
    // 0x800E7854: nop

    // 0x800E7858: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800E785C: bnel        $v0, $zero, L_800E7894
    if (ctx->r2 != 0) {
        // 0x800E7860: lbu         $t1, 0x190($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X190);
            goto L_800E7894;
    }
    goto skip_34;
    // 0x800E7860: lbu         $t1, 0x190($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X190);
    skip_34:
    // 0x800E7864: jal         0x800EB6EC
    // 0x800E7868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamSetAnimLocks(rdram, ctx);
        goto after_27;
    // 0x800E7868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x800E786C: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
    // 0x800E7870: b           L_800E7890
    // 0x800E7874: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
        goto L_800E7890;
    // 0x800E7874: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
L_800E7878:
    // 0x800E7878: beql        $v0, $zero, L_800E7894
    if (ctx->r2 == 0) {
        // 0x800E787C: lbu         $t1, 0x190($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X190);
            goto L_800E7894;
    }
    goto skip_35;
    // 0x800E787C: lbu         $t1, 0x190($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X190);
    skip_35:
    // 0x800E7880: jal         0x800EB7F4
    // 0x800E7884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamClearAnimLocks(rdram, ctx);
        goto after_28;
    // 0x800E7884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x800E7888: lw          $a0, 0x198($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X198);
    // 0x800E788C: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
L_800E7890:
    // 0x800E7890: lbu         $t1, 0x190($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X190);
L_800E7894:
    // 0x800E7894: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x800E7898: andi        $t7, $t9, 0x10
    ctx->r15 = ctx->r25 & 0X10;
    // 0x800E789C: andi        $t0, $t1, 0xFFEF
    ctx->r8 = ctx->r9 & 0XFFEF;
    // 0x800E78A0: or          $t3, $t7, $t0
    ctx->r11 = ctx->r15 | ctx->r8;
    // 0x800E78A4: sb          $t3, 0x190($s1)
    MEM_B(0X190, ctx->r17) = ctx->r11;
    // 0x800E78A8: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x800E78AC: sll         $t8, $a0, 29
    ctx->r24 = S32(ctx->r4 << 29);
    // 0x800E78B0: lw          $t4, 0x324($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X324);
    // 0x800E78B4: beql        $t4, $zero, L_800E78E4
    if (ctx->r12 == 0) {
        // 0x800E78B8: lw          $t3, 0x80($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X80);
            goto L_800E78E4;
    }
    goto skip_36;
    // 0x800E78B8: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    skip_36:
    // 0x800E78BC: bgezl       $t8, L_800E78D8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E78C0: lbu         $t7, 0x18F($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X18F);
            goto L_800E78D8;
    }
    goto skip_37;
    // 0x800E78C0: lbu         $t7, 0x18F($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X18F);
    skip_37:
    // 0x800E78C4: lbu         $t5, 0x18F($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X18F);
    // 0x800E78C8: andi        $t9, $t5, 0xFFFB
    ctx->r25 = ctx->r13 & 0XFFFB;
    // 0x800E78CC: b           L_800E78E0
    // 0x800E78D0: sb          $t9, 0x18F($s1)
    MEM_B(0X18F, ctx->r17) = ctx->r25;
        goto L_800E78E0;
    // 0x800E78D0: sb          $t9, 0x18F($s1)
    MEM_B(0X18F, ctx->r17) = ctx->r25;
    // 0x800E78D4: lbu         $t7, 0x18F($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X18F);
L_800E78D8:
    // 0x800E78D8: ori         $t0, $t7, 0x4
    ctx->r8 = ctx->r15 | 0X4;
    // 0x800E78DC: sb          $t0, 0x18F($s1)
    MEM_B(0X18F, ctx->r17) = ctx->r8;
L_800E78E0:
    // 0x800E78E0: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
L_800E78E4:
    // 0x800E78E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800E78E8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800E78EC: beq         $t3, $zero, L_800E7948
    if (ctx->r11 == 0) {
        // 0x800E78F0: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_800E7948;
    }
    // 0x800E78F0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800E78F4: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x800E78F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E78FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E7900: beq         $a0, $at, L_800E793C
    if (ctx->r4 == ctx->r1) {
        // 0x800E7904: nop
    
            goto L_800E793C;
    }
    // 0x800E7904: nop

    // 0x800E7908: lw          $t4, 0x198($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X198);
    // 0x800E790C: lw          $v1, 0x9C4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X9C4);
    // 0x800E7910: sll         $t8, $t4, 27
    ctx->r24 = S32(ctx->r12 << 27);
    // 0x800E7914: bgezl       $t8, L_800E7930
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E7918: lw          $t9, 0x2C($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X2C);
            goto L_800E7930;
    }
    goto skip_38;
    // 0x800E7918: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    skip_38:
    // 0x800E791C: lw          $t5, 0x30($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X30);
    // 0x800E7920: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x800E7924: b           L_800E793C
    // 0x800E7928: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
        goto L_800E793C;
    // 0x800E7928: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800E792C: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
L_800E7930:
    // 0x800E7930: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800E7934: b           L_800E793C
    // 0x800E7938: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
        goto L_800E793C;
    // 0x800E7938: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
L_800E793C:
    // 0x800E793C: sw          $v0, 0x8AC($s1)
    MEM_W(0X8AC, ctx->r17) = ctx->r2;
    // 0x800E7940: b           L_800E796C
    // 0x800E7944: sw          $v0, 0x86C($s1)
    MEM_W(0X86C, ctx->r17) = ctx->r2;
        goto L_800E796C;
    // 0x800E7944: sw          $v0, 0x86C($s1)
    MEM_W(0X86C, ctx->r17) = ctx->r2;
L_800E7948:
    // 0x800E7948: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x800E794C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E7950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E7954: beq         $a0, $at, L_800E7964
    if (ctx->r4 == ctx->r1) {
        // 0x800E7958: nop
    
            goto L_800E7964;
    }
    // 0x800E7958: nop

    // 0x800E795C: b           L_800E7964
    // 0x800E7960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800E7964;
    // 0x800E7960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800E7964:
    // 0x800E7964: sw          $v0, 0x8AC($s1)
    MEM_W(0X8AC, ctx->r17) = ctx->r2;
    // 0x800E7968: sw          $v0, 0x86C($s1)
    MEM_W(0X86C, ctx->r17) = ctx->r2;
L_800E796C:
    // 0x800E796C: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800E7970: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800E7974: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800E7978: lw          $t0, 0x74($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X74);
    // 0x800E797C: addiu       $v0, $s1, 0x20
    ctx->r2 = ADD32(ctx->r17, 0X20);
    // 0x800E7980: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800E7984: lwc1        $f4, 0x78($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X78);
    // 0x800E7988: sw          $zero, 0x870($s1)
    MEM_W(0X870, ctx->r17) = 0;
    // 0x800E798C: sw          $zero, 0x8B0($s1)
    MEM_W(0X8B0, ctx->r17) = 0;
    // 0x800E7990: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800E7994: swc1        $f0, 0x8A8($s1)
    MEM_W(0X8A8, ctx->r17) = ctx->f0.u32l;
    // 0x800E7998: swc1        $f0, 0x868($s1)
    MEM_W(0X868, ctx->r17) = ctx->f0.u32l;
L_800E799C:
    // 0x800E799C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800E79A0: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800E79A4: sw          $zero, 0x88C($v0)
    MEM_W(0X88C, ctx->r2) = 0;
    // 0x800E79A8: bne         $s0, $v1, L_800E799C
    if (ctx->r16 != ctx->r3) {
        // 0x800E79AC: sw          $zero, 0x84C($v0)
        MEM_W(0X84C, ctx->r2) = 0;
            goto L_800E799C;
    }
    // 0x800E79AC: sw          $zero, 0x84C($v0)
    MEM_W(0X84C, ctx->r2) = 0;
    // 0x800E79B0: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800E79B4: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800E79B8: nop

    // 0x800E79BC: bc1t        L_800E79D4
    if (c1cs) {
        // 0x800E79C0: nop
    
            goto L_800E79D4;
    }
    // 0x800E79C0: nop

    // 0x800E79C4: jal         0x800E0858
    // 0x800E79C8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftMainPlayAnimEventsForward(rdram, ctx);
        goto after_29;
    // 0x800E79C8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_29:
    // 0x800E79CC: b           L_800E7A0C
    // 0x800E79D0: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
        goto L_800E7A0C;
    // 0x800E79D0: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
L_800E79D4:
    // 0x800E79D4: jal         0x800E0830
    // 0x800E79D8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_30;
    // 0x800E79D8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_30:
    // 0x800E79DC: jal         0x800E11C8
    // 0x800E79E0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    ftMainRunUpdateColAnim(rdram, ctx);
        goto after_31;
    // 0x800E79E0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    after_31:
    // 0x800E79E4: b           L_800E7A0C
    // 0x800E79E8: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
        goto L_800E7A0C;
    // 0x800E79E8: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
L_800E79EC:
    // 0x800E79EC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800E79F0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800E79F4:
    // 0x800E79F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800E79F8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800E79FC: sw          $zero, 0x88C($v0)
    MEM_W(0X88C, ctx->r2) = 0;
    // 0x800E7A00: bne         $s0, $v1, L_800E79F4
    if (ctx->r16 != ctx->r3) {
        // 0x800E7A04: sw          $zero, 0x84C($v0)
        MEM_W(0X84C, ctx->r2) = 0;
            goto L_800E79F4;
    }
    // 0x800E7A04: sw          $zero, 0x84C($v0)
    MEM_W(0X84C, ctx->r2) = 0;
    // 0x800E7A08: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
L_800E7A0C:
    // 0x800E7A0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E7A10: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800E7A14: beq         $t3, $at, L_800E7A84
    if (ctx->r11 == ctx->r1) {
        // 0x800E7A18: lw          $t0, 0x7C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X7C);
            goto L_800E7A84;
    }
    // 0x800E7A18: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800E7A1C: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800E7A20: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800E7A24: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800E7A28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E7A2C: addu        $s0, $t2, $t6
    ctx->r16 = ADD32(ctx->r10, ctx->r14);
    // 0x800E7A30: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800E7A34: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800E7A38: addiu       $t7, $t7, -0x1EB0
    ctx->r15 = ADD32(ctx->r15, -0X1EB0);
    // 0x800E7A3C: sw          $t8, 0x9D4($s1)
    MEM_W(0X9D4, ctx->r17) = ctx->r24;
    // 0x800E7A40: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x800E7A44: sw          $t5, 0x9DC($s1)
    MEM_W(0X9DC, ctx->r17) = ctx->r13;
    // 0x800E7A48: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800E7A4C: sw          $t9, 0x9E0($s1)
    MEM_W(0X9E0, ctx->r17) = ctx->r25;
    // 0x800E7A50: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x800E7A54: sw          $t7, 0x9E8($s1)
    MEM_W(0X9E8, ctx->r17) = ctx->r15;
    // 0x800E7A58: sw          $zero, 0x9D8($s1)
    MEM_W(0X9D8, ctx->r17) = 0;
    // 0x800E7A5C: sw          $zero, 0x9EC($s1)
    MEM_W(0X9EC, ctx->r17) = 0;
    // 0x800E7A60: sw          $zero, 0x9F0($s1)
    MEM_W(0X9F0, ctx->r17) = 0;
    // 0x800E7A64: sw          $zero, 0x9F8($s1)
    MEM_W(0X9F8, ctx->r17) = 0;
    // 0x800E7A68: sw          $zero, 0x9F4($s1)
    MEM_W(0X9F4, ctx->r17) = 0;
    // 0x800E7A6C: sw          $zero, 0x9FC($s1)
    MEM_W(0X9FC, ctx->r17) = 0;
    // 0x800E7A70: sw          $zero, 0xA00($s1)
    MEM_W(0XA00, ctx->r17) = 0;
    // 0x800E7A74: sw          $zero, 0xA04($s1)
    MEM_W(0XA04, ctx->r17) = 0;
    // 0x800E7A78: sw          $zero, 0xA08($s1)
    MEM_W(0XA08, ctx->r17) = 0;
    // 0x800E7A7C: b           L_800E7AA4
    // 0x800E7A80: sw          $t1, 0x9E4($s1)
    MEM_W(0X9E4, ctx->r17) = ctx->r9;
        goto L_800E7AA4;
    // 0x800E7A80: sw          $t1, 0x9E4($s1)
    MEM_W(0X9E4, ctx->r17) = ctx->r9;
L_800E7A84:
    // 0x800E7A84: beq         $t0, $zero, L_800E7AA0
    if (ctx->r8 == 0) {
        // 0x800E7A88: lw          $t3, 0x74($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X74);
            goto L_800E7AA0;
    }
    // 0x800E7A88: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x800E7A8C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800E7A90: addu        $t2, $t0, $t4
    ctx->r10 = ADD32(ctx->r8, ctx->r12);
    // 0x800E7A94: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x800E7A98: b           L_800E7AA4
    // 0x800E7A9C: sw          $t6, 0x9D4($s1)
    MEM_W(0X9D4, ctx->r17) = ctx->r14;
        goto L_800E7AA4;
    // 0x800E7A9C: sw          $t6, 0x9D4($s1)
    MEM_W(0X9D4, ctx->r17) = ctx->r14;
L_800E7AA0:
    // 0x800E7AA0: sw          $zero, 0x9D4($s1)
    MEM_W(0X9D4, ctx->r17) = 0;
L_800E7AA4:
    // 0x800E7AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7AA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E7AAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E7AB0: jr          $ra
    // 0x800E7AB4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800E7AB4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void ftKirbySpecialNLoopSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162B04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162B08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162B0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162B10: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162B14: jal         0x800DEEC8
    // 0x80162B18: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162B18: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162B1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162B20: addiu       $t7, $zero, 0x4825
    ctx->r15 = ADD32(0, 0X4825);
    // 0x80162B24: addiu       $a1, $zero, 0x117
    ctx->r5 = ADD32(0, 0X117);
    // 0x80162B28: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162B2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162B30: jal         0x800E6F24
    // 0x80162B34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162B34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162B38: jal         0x80161E3C
    // 0x80162B3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbySpecialNSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x80162B3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80162B40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162B44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162B48: jr          $ra
    // 0x80162B4C: nop

    return;
    // 0x80162B4C: nop

;}
RECOMP_FUNC void itMLuckyFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80181078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018107C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80181080: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80181084: jal         0x80173680
    // 0x80181088: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x80181088: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8018108C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80181090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80181094: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x80181098: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8018109C: beql        $t7, $zero, L_801810D0
    if (ctx->r15 == 0) {
        // 0x801810A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801810D0;
    }
    goto skip_0;
    // 0x801810A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801810A4: lhu         $t8, 0x33E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X33E);
    // 0x801810A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801810AC: beq         $t8, $zero, L_801810C4
    if (ctx->r24 == 0) {
        // 0x801810B0: swc1        $f4, 0x30($v0)
        MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
            goto L_801810C4;
    }
    // 0x801810B0: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x801810B4: jal         0x801813A8
    // 0x801810B8: nop

    itMLuckyMakeEggSetStatus(rdram, ctx);
        goto after_1;
    // 0x801810B8: nop

    after_1:
    // 0x801810BC: b           L_801810D0
    // 0x801810C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801810D0;
    // 0x801810C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801810C4:
    // 0x801810C4: jal         0x801813F8
    // 0x801810C8: nop

    itMLuckyDisappearSetStatus(rdram, ctx);
        goto after_2;
    // 0x801810C8: nop

    after_2:
    // 0x801810CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801810D0:
    // 0x801810D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801810D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801810D8: jr          $ra
    // 0x801810DC: nop

    return;
    // 0x801810DC: nop

;}
RECOMP_FUNC void ftCommonDeadDownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C1C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8013C1C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013C1CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013C1D0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013C1D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013C1D8: jal         0x8013C050
    // 0x8013C1DC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    ftCommonDeadResetCommonVars(rdram, ctx);
        goto after_0;
    // 0x8013C1DC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013C1E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013C1E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013C1E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013C1EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013C1F0: jal         0x800E6F24
    // 0x8013C1F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013C1F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8013C1F8: jal         0x8013C0B0
    // 0x8013C1FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDeadResetSpecialStats(rdram, ctx);
        goto after_2;
    // 0x8013C1FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013C200: jal         0x8013C120
    // 0x8013C204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDeadInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8013C204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013C208: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x8013C20C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8013C210: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8013C214: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8013C218: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013C21C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013C220: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8013C224: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8013C228: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8013C22C: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8013C230: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8013C234: lw          $t0, 0x50E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50E8);
    // 0x8013C238: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8013C23C: beql        $t1, $at, L_8013C29C
    if (ctx->r9 == ctx->r1) {
        // 0x8013C240: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8013C29C;
    }
    goto skip_0;
    // 0x8013C240: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8013C244: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8013C248: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8013C24C: lh          $t2, 0x70($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X70);
    // 0x8013C250: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8013C254: nop

    // 0x8013C258: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013C25C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8013C260: nop

    // 0x8013C264: bc1fl       L_8013C274
    if (!c1cs) {
        // 0x8013C268: lh          $t3, 0x72($v0)
        ctx->r11 = MEM_H(ctx->r2, 0X72);
            goto L_8013C274;
    }
    goto skip_1;
    // 0x8013C268: lh          $t3, 0x72($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X72);
    skip_1:
    // 0x8013C26C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8013C270: lh          $t3, 0x72($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X72);
L_8013C274:
    // 0x8013C274: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8013C278: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8013C27C: nop

    // 0x8013C280: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013C284: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8013C288: nop

    // 0x8013C28C: bc1fl       L_8013C29C
    if (!c1cs) {
        // 0x8013C290: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8013C29C;
    }
    goto skip_2;
    // 0x8013C290: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8013C294: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8013C298: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_8013C29C:
    // 0x8013C29C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013C2A0: jal         0x801021C0
    // 0x8013C2A4: lbu         $a1, 0xD($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0XD);
    efManagerDeadExplodeMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8013C2A4: lbu         $a1, 0xD($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0XD);
    after_4:
    // 0x8013C2A8: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8013C2AC: jal         0x80115BF0
    // 0x8013C2B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifScreenFlashSetColAnimID(rdram, ctx);
        goto after_5;
    // 0x8013C2B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8013C2B4: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8013C2B8: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x8013C2BC: lbu         $v0, 0x1($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X1);
    // 0x8013C2C0: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x8013C2C4: bne         $at, $zero, L_8013C2D0
    if (ctx->r1 != 0) {
        // 0x8013C2C8: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_8013C2D0;
    }
    // 0x8013C2C8: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8013C2CC: bne         $at, $zero, L_8013C2E4
    if (ctx->r1 != 0) {
        // 0x8013C2D0: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_8013C2E4;
    }
L_8013C2D0:
    // 0x8013C2D0: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8013C2D4: bne         $at, $zero, L_8013C2EC
    if (ctx->r1 != 0) {
        // 0x8013C2D8: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_8013C2EC;
    }
    // 0x8013C2D8: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8013C2DC: beql        $at, $zero, L_8013C2F0
    if (ctx->r1 == 0) {
        // 0x8013C2E0: addiu       $v0, $zero, 0x9A
        ctx->r2 = ADD32(0, 0X9A);
            goto L_8013C2F0;
    }
    goto skip_3;
    // 0x8013C2E0: addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
    skip_3:
L_8013C2E4:
    // 0x8013C2E4: b           L_8013C2F0
    // 0x8013C2E8: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
        goto L_8013C2F0;
    // 0x8013C2E8: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
L_8013C2EC:
    // 0x8013C2EC: addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
L_8013C2F0:
    // 0x8013C2F0: jal         0x8013BC60
    // 0x8013C2F4: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_6;
    // 0x8013C2F4: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_6:
    // 0x8013C2F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013C2FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013C300: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013C304: jr          $ra
    // 0x8013C308: nop

    return;
    // 0x8013C308: nop

;}
RECOMP_FUNC void ftHammerUpdateStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F36E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F36E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F36E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F36EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F36F0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800F36F4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800F36F8: lw          $v0, 0xB14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB14);
    // 0x800F36FC: beq         $v0, $zero, L_800F370C
    if (ctx->r2 == 0) {
        // 0x800F3700: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800F370C;
    }
    // 0x800F3700: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800F3704: sw          $t7, 0xB14($s0)
    MEM_W(0XB14, ctx->r16) = ctx->r15;
    // 0x800F3708: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800F370C:
    // 0x800F370C: bne         $v0, $at, L_800F3720
    if (ctx->r2 != ctx->r1) {
        // 0x800F3710: nop
    
            goto L_800F3720;
    }
    // 0x800F3710: nop

    // 0x800F3714: jal         0x80176110
    // 0x800F3718: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itHammerCommonSetColAnim(rdram, ctx);
        goto after_0;
    // 0x800F3718: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_0:
    // 0x800F371C: lw          $v0, 0xB14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB14);
L_800F3720:
    // 0x800F3720: bnel        $v0, $zero, L_800F3784
    if (ctx->r2 != 0) {
        // 0x800F3724: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F3784;
    }
    goto skip_0;
    // 0x800F3724: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800F3728: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800F372C: jal         0x801728D4
    // 0x800F3730: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itMainDestroyItem(rdram, ctx);
        goto after_1;
    // 0x800F3730: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_1:
    // 0x800F3734: jal         0x800E7B54
    // 0x800F3738: nop

    ftParamTryUpdateItemMusic(rdram, ctx);
        goto after_2;
    // 0x800F3738: nop

    after_2:
    // 0x800F373C: lw          $t8, 0xA64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XA64);
    // 0x800F3740: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x800F3744: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800F3748: bne         $t8, $at, L_800F3754
    if (ctx->r24 != ctx->r1) {
        // 0x800F374C: nop
    
            goto L_800F3754;
    }
    // 0x800F374C: nop

    // 0x800F3750: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_800F3754:
    // 0x800F3754: jal         0x800F37CC
    // 0x800F3758: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftHammerCheckStatusHammerAll(rdram, ctx);
        goto after_3;
    // 0x800F3758: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x800F375C: beql        $v0, $zero, L_800F3770
    if (ctx->r2 == 0) {
        // 0x800F3760: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_800F3770;
    }
    goto skip_1;
    // 0x800F3760: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x800F3764: jal         0x800DEE54
    // 0x800F3768: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_4;
    // 0x800F3768: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x800F376C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_800F3770:
    // 0x800F3770: beql        $t0, $zero, L_800F3784
    if (ctx->r8 == 0) {
        // 0x800F3774: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F3784;
    }
    goto skip_2;
    // 0x800F3774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800F3778: jal         0x800E98D4
    // 0x800F377C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_5;
    // 0x800F377C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x800F3780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F3784:
    // 0x800F3784: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F3788: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F378C: jr          $ra
    // 0x800F3790: nop

    return;
    // 0x800F3790: nop

;}
RECOMP_FUNC void sc1PStageClearInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133C88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C8C: sw          $zero, 0x52CC($at)
    MEM_W(0X52CC, ctx->r1) = 0;
    // 0x80133C90: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133C94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C98: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133C9C: sw          $zero, 0x52D0($at)
    MEM_W(0X52D0, ctx->r1) = 0;
    // 0x80133CA0: lbu         $t6, 0x17($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X17);
    // 0x80133CA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133CA8: addiu       $a0, $a0, 0x52EC
    ctx->r4 = ADD32(ctx->r4, 0X52EC);
    // 0x80133CAC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80133CB0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80133CB4: lbu         $t7, 0x493A($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X493A);
    // 0x80133CB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133CC0: sw          $t7, 0x52E4($at)
    MEM_W(0X52E4, ctx->r1) = ctx->r15;
    // 0x80133CC4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80133CC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133CD0: beq         $v0, $at, L_80133D00
    if (ctx->r2 == ctx->r1) {
        // 0x80133CD4: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80133D00;
    }
    // 0x80133CD4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80133CD8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133CDC: beq         $v0, $at, L_80133D00
    if (ctx->r2 == ctx->r1) {
        // 0x80133CE0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80133D00;
    }
    // 0x80133CE0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80133CE4: beq         $v0, $at, L_80133D00
    if (ctx->r2 == ctx->r1) {
        // 0x80133CE8: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80133D00;
    }
    // 0x80133CE8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80133CEC: beq         $v0, $at, L_80133D18
    if (ctx->r2 == ctx->r1) {
        // 0x80133CF0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80133D18;
    }
    // 0x80133CF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133CF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CF8: b           L_80133D20
    // 0x80133CFC: sw          $zero, 0x52D4($at)
    MEM_W(0X52D4, ctx->r1) = 0;
        goto L_80133D20;
    // 0x80133CFC: sw          $zero, 0x52D4($at)
    MEM_W(0X52D4, ctx->r1) = 0;
L_80133D00:
    // 0x80133D00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D04: sw          $t8, 0x52D4($at)
    MEM_W(0X52D4, ctx->r1) = ctx->r24;
    // 0x80133D08: lbu         $t9, 0x38($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X38);
    // 0x80133D0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D10: b           L_80133D20
    // 0x80133D14: sw          $t9, 0x53A4($at)
    MEM_W(0X53A4, ctx->r1) = ctx->r25;
        goto L_80133D20;
    // 0x80133D14: sw          $t9, 0x53A4($at)
    MEM_W(0X53A4, ctx->r1) = ctx->r25;
L_80133D18:
    // 0x80133D18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D1C: sw          $t0, 0x52D4($at)
    MEM_W(0X52D4, ctx->r1) = ctx->r8;
L_80133D20:
    // 0x80133D20: lw          $t1, 0x1C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1C);
    // 0x80133D24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D28: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80133D2C: sw          $t1, 0x52DC($at)
    MEM_W(0X52DC, ctx->r1) = ctx->r9;
    // 0x80133D30: lbu         $t2, 0x13($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X13);
    // 0x80133D34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D38: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133D3C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80133D40: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80133D44: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80133D48: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80133D4C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80133D50: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80133D54: lw          $t4, 0x4B6C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4B6C);
    // 0x80133D58: addiu       $v0, $v0, 0x5320
    ctx->r2 = ADD32(ctx->r2, 0X5320);
    // 0x80133D5C: sw          $t4, 0x52E0($at)
    MEM_W(0X52E0, ctx->r1) = ctx->r12;
    // 0x80133D60: lw          $t5, 0x20($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X20);
    // 0x80133D64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D68: sw          $t5, 0x52E8($at)
    MEM_W(0X52E8, ctx->r1) = ctx->r13;
    // 0x80133D6C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x80133D70: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x80133D74: lw          $t8, 0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X34);
    // 0x80133D78: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133D7C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133D80: jal         0x8013305C
    // 0x80133D84: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    sc1PStageClearCheckHaveBonusStats(rdram, ctx);
        goto after_0;
    // 0x80133D84: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    after_0:
    // 0x80133D88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D8C: sw          $v0, 0x52D8($at)
    MEM_W(0X52D8, ctx->r1) = ctx->r2;
    // 0x80133D90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D94: sw          $zero, 0x532C($at)
    MEM_W(0X532C, ctx->r1) = 0;
    // 0x80133D98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133DA0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133DA4: sw          $zero, 0x53A0($at)
    MEM_W(0X53A0, ctx->r1) = 0;
    // 0x80133DA8: addiu       $v1, $v1, 0x5350
    ctx->r3 = ADD32(ctx->r3, 0X5350);
    // 0x80133DAC: addiu       $v0, $v0, 0x5378
    ctx->r2 = ADD32(ctx->r2, 0X5378);
L_80133DB0:
    // 0x80133DB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80133DB4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80133DB8: bne         $at, $zero, L_80133DB0
    if (ctx->r1 != 0) {
        // 0x80133DBC: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_80133DB0;
    }
    // 0x80133DBC: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x80133DC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133DC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133DC8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133DCC: addiu       $v1, $v1, 0x53A0
    ctx->r3 = ADD32(ctx->r3, 0X53A0);
    // 0x80133DD0: addiu       $v0, $v0, 0x5380
    ctx->r2 = ADD32(ctx->r2, 0X5380);
    // 0x80133DD4: sw          $zero, 0x5378($at)
    MEM_W(0X5378, ctx->r1) = 0;
    // 0x80133DD8: sw          $zero, 0x537C($at)
    MEM_W(0X537C, ctx->r1) = 0;
L_80133DDC:
    // 0x80133DDC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80133DE0: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x80133DE4: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x80133DE8: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80133DEC: bne         $v0, $v1, L_80133DDC
    if (ctx->r2 != ctx->r3) {
        // 0x80133DF0: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_80133DDC;
    }
    // 0x80133DF0: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x80133DF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133DF8: sw          $zero, 0x52F8($at)
    MEM_W(0X52F8, ctx->r1) = 0;
    // 0x80133DFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E00: sw          $zero, 0x52FC($at)
    MEM_W(0X52FC, ctx->r1) = 0;
    // 0x80133E04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E08: sw          $zero, 0x5318($at)
    MEM_W(0X5318, ctx->r1) = 0;
    // 0x80133E0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E10: sw          $zero, 0x5334($at)
    MEM_W(0X5334, ctx->r1) = 0;
    // 0x80133E14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133E18: lw          $v0, 0x52D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52D4);
    // 0x80133E1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E20: sw          $zero, 0x5338($at)
    MEM_W(0X5338, ctx->r1) = 0;
    // 0x80133E24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E28: beq         $v0, $zero, L_80133E3C
    if (ctx->r2 == 0) {
        // 0x80133E2C: sw          $zero, 0x533C($at)
        MEM_W(0X533C, ctx->r1) = 0;
            goto L_80133E3C;
    }
    // 0x80133E2C: sw          $zero, 0x533C($at)
    MEM_W(0X533C, ctx->r1) = 0;
    // 0x80133E30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133E34: bnel        $v0, $at, L_80133EE0
    if (ctx->r2 != ctx->r1) {
        // 0x80133E38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133EE0;
    }
    goto skip_0;
    // 0x80133E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80133E3C:
    // 0x80133E3C: jal         0x80133F28
    // 0x80133E40: nop

    sc1PStageClearCheckNoTimer(rdram, ctx);
        goto after_1;
    // 0x80133E40: nop

    after_1:
    // 0x80133E44: beq         $v0, $zero, L_80133E80
    if (ctx->r2 == 0) {
        // 0x80133E48: addiu       $t3, $zero, 0xA
        ctx->r11 = ADD32(0, 0XA);
            goto L_80133E80;
    }
    // 0x80133E48: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80133E4C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80133E50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E54: sw          $t9, 0x53B8($at)
    MEM_W(0X53B8, ctx->r1) = ctx->r25;
    // 0x80133E58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E5C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80133E60: sw          $t0, 0x53BC($at)
    MEM_W(0X53BC, ctx->r1) = ctx->r8;
    // 0x80133E64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E68: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x80133E6C: sw          $t1, 0x53C0($at)
    MEM_W(0X53C0, ctx->r1) = ctx->r9;
    // 0x80133E70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E74: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x80133E78: b           L_80133EDC
    // 0x80133E7C: sw          $t2, 0x53C4($at)
    MEM_W(0X53C4, ctx->r1) = ctx->r10;
        goto L_80133EDC;
    // 0x80133E7C: sw          $t2, 0x53C4($at)
    MEM_W(0X53C4, ctx->r1) = ctx->r10;
L_80133E80:
    // 0x80133E80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E84: sw          $t3, 0x53A8($at)
    MEM_W(0X53A8, ctx->r1) = ctx->r11;
    // 0x80133E88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E8C: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80133E90: sw          $t4, 0x53AC($at)
    MEM_W(0X53AC, ctx->r1) = ctx->r12;
    // 0x80133E94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E98: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80133E9C: sw          $t5, 0x53B0($at)
    MEM_W(0X53B0, ctx->r1) = ctx->r13;
    // 0x80133EA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133EA4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80133EA8: sw          $t6, 0x53B4($at)
    MEM_W(0X53B4, ctx->r1) = ctx->r14;
    // 0x80133EAC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133EB0: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80133EB4: sw          $t7, 0x53B8($at)
    MEM_W(0X53B8, ctx->r1) = ctx->r15;
    // 0x80133EB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133EBC: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80133EC0: sw          $t8, 0x53BC($at)
    MEM_W(0X53BC, ctx->r1) = ctx->r24;
    // 0x80133EC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133EC8: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80133ECC: sw          $t9, 0x53C0($at)
    MEM_W(0X53C0, ctx->r1) = ctx->r25;
    // 0x80133ED0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133ED4: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x80133ED8: sw          $t0, 0x53C4($at)
    MEM_W(0X53C4, ctx->r1) = ctx->r8;
L_80133EDC:
    // 0x80133EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133EE0:
    // 0x80133EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133EE4: jr          $ra
    // 0x80133EE8: nop

    return;
    // 0x80133EE8: nop

;}
RECOMP_FUNC void itBombHeiCommonSetWalkLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177104: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80177108: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017710C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80177110: addiu       $t8, $t8, 0x33F8
    ctx->r24 = ADD32(ctx->r24, 0X33F8);
    // 0x80177114: lw          $t6, 0x2D4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2D4);
    // 0x80177118: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8017711C: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80177120: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80177124: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80177128: addiu       $t9, $t9, 0x34C0
    ctx->r25 = ADD32(ctx->r25, 0X34C0);
    // 0x8017712C: addiu       $t1, $t1, 0x3310
    ctx->r9 = ADD32(ctx->r9, 0X3310);
    // 0x80177130: subu        $a3, $t7, $t8
    ctx->r7 = SUB32(ctx->r15, ctx->r24);
    // 0x80177134: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80177138: addu        $a2, $a3, $t9
    ctx->r6 = ADD32(ctx->r7, ctx->r25);
    // 0x8017713C: beq         $a1, $zero, L_80177160
    if (ctx->r5 == 0) {
        // 0x80177140: addu        $t0, $a3, $t1
        ctx->r8 = ADD32(ctx->r7, ctx->r9);
            goto L_80177160;
    }
    // 0x80177140: addu        $t0, $a3, $t1
    ctx->r8 = ADD32(ctx->r7, ctx->r9);
    // 0x80177144: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80177148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017714C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80177150: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x80177154: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x80177158: jr          $ra
    // 0x8017715C: sw          $t0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r8;
    return;
    // 0x8017715C: sw          $t0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r8;
L_80177160:
    // 0x80177160: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x80177164: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80177168: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8017716C: sw          $t3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r11;
    // 0x80177170: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x80177174: sw          $a2, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r6;
    // 0x80177178: jr          $ra
    // 0x8017717C: nop

    return;
    // 0x8017717C: nop

;}
RECOMP_FUNC void ftKirbySpecialNLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016201C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80162020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162024: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80162028: lw          $t6, 0x18C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18C);
    // 0x8016202C: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x80162030: bltzl       $t8, L_8016206C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80162034: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016206C;
    }
    goto skip_0;
    // 0x80162034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80162038: lw          $t9, 0x17C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X17C);
    // 0x8016203C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80162040: bnel        $t9, $at, L_8016206C
    if (ctx->r25 != ctx->r1) {
        // 0x80162044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016206C;
    }
    goto skip_1;
    // 0x80162044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80162048: jal         0x801042B4
    // 0x8016204C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerKirbyInhaleWindMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016204C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80162050: beq         $v0, $zero, L_80162068
    if (ctx->r2 == 0) {
        // 0x80162054: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80162068;
    }
    // 0x80162054: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80162058: lbu         $t1, 0x18F($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X18F);
    // 0x8016205C: sw          $zero, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = 0;
    // 0x80162060: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80162064: sb          $t2, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r10;
L_80162068:
    // 0x80162068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016206C:
    // 0x8016206C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80162070: jr          $ra
    // 0x80162074: nop

    return;
    // 0x80162074: nop

;}
RECOMP_FUNC void gcMoveGObjCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009B4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80009B50: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80009B54: lbu         $s1, 0x33($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X33);
    // 0x80009B58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80009B5C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80009B60: slti        $at, $s1, 0x21
    ctx->r1 = SIGNED(ctx->r17) < 0X21 ? 1 : 0;
    // 0x80009B64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009B68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80009B6C: bne         $at, $zero, L_80009B90
    if (ctx->r1 != 0) {
        // 0x80009B70: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_80009B90;
    }
    // 0x80009B70: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80009B74: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80009B78: addiu       $a0, $a0, -0x24D4
    ctx->r4 = ADD32(ctx->r4, -0X24D4);
    // 0x80009B7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80009B80: jal         0x80023624
    // 0x80009B84: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80009B84: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80009B88:
    // 0x80009B88: b           L_80009B88
    pause_self(rdram);
    // 0x80009B8C: nop

L_80009B90:
    // 0x80009B90: bnel        $s0, $zero, L_80009BA4
    if (ctx->r16 != 0) {
        // 0x80009B94: lw          $t6, 0x18($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X18);
            goto L_80009BA4;
    }
    goto skip_0;
    // 0x80009B94: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x80009B98: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80009B9C: lw          $s0, 0x6A54($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6A54);
    // 0x80009BA0: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
L_80009BA4:
    // 0x80009BA4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80009BA8: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80009BAC: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80009BB0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80009BB4: beq         $s1, $zero, L_80009BD4
    if (ctx->r17 == 0) {
        // 0x80009BB8: nop
    
            goto L_80009BD4;
    }
    // 0x80009BB8: nop

L_80009BBC:
    // 0x80009BBC: jal         0x80007784
    // 0x80009BC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80007784(rdram, ctx);
        goto after_1;
    // 0x80009BC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80009BC4: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80009BC8: bne         $s1, $zero, L_80009BBC
    if (ctx->r17 != 0) {
        // 0x80009BCC: nop
    
            goto L_80009BBC;
    }
    // 0x80009BCC: nop

    // 0x80009BD0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
L_80009BD4:
    // 0x80009BD4: jal         0x80007B30
    // 0x80009BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveGObjFromLinkedList(rdram, ctx);
        goto after_2;
    // 0x80009BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80009BDC: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x80009BE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009BE4: sb          $t8, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r24;
    // 0x80009BE8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80009BEC: sw          $t9, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r25;
    // 0x80009BF0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80009BF4: beq         $t0, $zero, L_80009C20
    if (ctx->r8 == 0) {
        // 0x80009BF8: nop
    
            goto L_80009C20;
    }
    // 0x80009BF8: nop

    // 0x80009BFC: beq         $t0, $at, L_80009C30
    if (ctx->r8 == ctx->r1) {
        // 0x80009C00: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80009C30;
    }
    // 0x80009C00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80009C04: beq         $t0, $at, L_80009C40
    if (ctx->r8 == ctx->r1) {
        // 0x80009C08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80009C40;
    }
    // 0x80009C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009C0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80009C10: beq         $t0, $at, L_80009C50
    if (ctx->r8 == ctx->r1) {
        // 0x80009C14: lw          $t1, 0x38($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X38);
            goto L_80009C50;
    }
    // 0x80009C14: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80009C18: b           L_80009C60
    // 0x80009C1C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
        goto L_80009C60;
    // 0x80009C1C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_80009C20:
    // 0x80009C20: jal         0x80007A3C
    // 0x80009C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcLinkGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80009C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80009C28: b           L_80009C60
    // 0x80009C2C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
        goto L_80009C60;
    // 0x80009C2C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_80009C30:
    // 0x80009C30: jal         0x80007AA8
    // 0x80009C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcLinkGObjSPBefore(rdram, ctx);
        goto after_4;
    // 0x80009C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80009C38: b           L_80009C60
    // 0x80009C3C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
        goto L_80009C60;
    // 0x80009C3C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_80009C40:
    // 0x80009C40: jal         0x800079D4
    // 0x80009C44: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    gcLinkGObjAfter(rdram, ctx);
        goto after_5;
    // 0x80009C44: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x80009C48: b           L_80009C60
    // 0x80009C4C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
        goto L_80009C60;
    // 0x80009C4C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_80009C50:
    // 0x80009C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009C54: jal         0x800079D4
    // 0x80009C58: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    gcLinkGObjAfter(rdram, ctx);
        goto after_6;
    // 0x80009C58: lw          $a1, 0x8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X8);
    after_6:
    // 0x80009C5C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_80009C60:
    // 0x80009C60: beql        $t2, $zero, L_80009C80
    if (ctx->r10 == 0) {
        // 0x80009C64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80009C80;
    }
    goto skip_1;
    // 0x80009C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80009C68:
    // 0x80009C68: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80009C6C: jal         0x80007680
    // 0x80009C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcLinkGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80009C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80009C74: bne         $s0, $zero, L_80009C68
    if (ctx->r16 != 0) {
        // 0x80009C78: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80009C68;
    }
    // 0x80009C78: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80009C7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80009C80:
    // 0x80009C80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80009C84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80009C88: jr          $ra
    // 0x80009C8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80009C8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

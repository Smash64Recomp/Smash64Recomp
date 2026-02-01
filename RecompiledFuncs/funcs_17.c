#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftKirbyCopyPurinSpecialAirNProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801518EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801518F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801518F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801518F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801518FC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80151900: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x80151904: beql        $t7, $zero, L_80151978
    if (ctx->r15 == 0) {
        // 0x80151908: lw          $v0, 0x184($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X184);
            goto L_80151978;
    }
    goto skip_0;
    // 0x80151908: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
    skip_0:
    // 0x8015190C: lw          $t8, 0xAF0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XAF0);
    // 0x80151910: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x80151914: lb          $a0, 0x1C3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C3);
    // 0x80151918: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8015191C: jal         0x80151874
    // 0x80151920: sw          $t9, 0xAF0($s0)
    MEM_W(0XAF0, ctx->r16) = ctx->r25;
    ftKirbyCopyPurinSpecialNGetAngle(rdram, ctx);
        goto after_0;
    // 0x80151920: sw          $t9, 0xAF0($s0)
    MEM_W(0XAF0, ctx->r16) = ctx->r25;
    after_0:
    // 0x80151924: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80151928: jal         0x800303F0
    // 0x8015192C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8015192C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80151930: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80151934: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80151938: nop

    // 0x8015193C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80151940: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x80151944: jal         0x80035CD0
    // 0x80151948: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80151948: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015194C: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80151950: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80151954: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80151958: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8015195C: nop

    // 0x80151960: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80151964: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80151968: nop

    // 0x8015196C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80151970: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80151974: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
L_80151978:
    // 0x80151978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015197C: beq         $v0, $zero, L_8015199C
    if (ctx->r2 == 0) {
        // 0x80151980: nop
    
            goto L_8015199C;
    }
    // 0x80151980: nop

    // 0x80151984: beq         $v0, $at, L_801519AC
    if (ctx->r2 == ctx->r1) {
        // 0x80151988: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801519AC;
    }
    // 0x80151988: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8015198C: beq         $v0, $at, L_801519D4
    if (ctx->r2 == ctx->r1) {
        // 0x80151990: nop
    
            goto L_801519D4;
    }
    // 0x80151990: nop

    // 0x80151994: b           L_801519E0
    // 0x80151998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801519E0;
    // 0x80151998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015199C:
    // 0x8015199C: jal         0x800D91EC
    // 0x801519A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPhysicsApplyAirVelFriction(rdram, ctx);
        goto after_3;
    // 0x801519A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x801519A4: b           L_801519E0
    // 0x801519A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801519E0;
    // 0x801519A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801519AC:
    // 0x801519AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801519B0: lwc1        $f0, -0x3ACC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3ACC);
    // 0x801519B4: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x801519B8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801519BC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801519C0: nop

    // 0x801519C4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801519C8: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x801519CC: b           L_801519DC
    // 0x801519D0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
        goto L_801519DC;
    // 0x801519D0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_801519D4:
    // 0x801519D4: jal         0x800D9160
    // 0x801519D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPhysicsApplyAirVelDriftFastFall(rdram, ctx);
        goto after_4;
    // 0x801519D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
L_801519DC:
    // 0x801519DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801519E0:
    // 0x801519E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801519E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801519E8: jr          $ra
    // 0x801519EC: nop

    return;
    // 0x801519EC: nop

;}
RECOMP_FUNC void gmCameraRunFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CECC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8010CED0: lw          $t9, 0x14BC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X14BC);
    // 0x8010CED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CEDC: jalr        $t9
    // 0x8010CEE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8010CEE0: nop

    after_0:
    // 0x8010CEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CEE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CEEC: jr          $ra
    // 0x8010CEF0: nop

    return;
    // 0x8010CEF0: nop

;}
RECOMP_FUNC void gcDrawDObjTreeDLLinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001445C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80014460: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80014464: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80014468: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001446C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80014470: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80014474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014478: lbu         $t6, 0x54($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X54);
    // 0x8001447C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80014480: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80014484: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80014488: bne         $t7, $zero, L_8001471C
    if (ctx->r15 != 0) {
        // 0x8001448C: lui         $s2, 0x8004
        ctx->r18 = S32(0X8004 << 16);
            goto L_8001471C;
    }
    // 0x8001448C: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80014490: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014494: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80014498: addiu       $s2, $s2, 0x70B0
    ctx->r18 = ADD32(ctx->r18, 0X70B0);
    // 0x8001449C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800144A0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800144A4: lw          $a2, 0x50($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X50);
    // 0x800144A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800144AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800144B0: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800144B4: jal         0x80010D70
    // 0x800144B8: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x800144B8: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_0:
    // 0x800144BC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800144C0: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800144C4: beql        $a2, $zero, L_80014624
    if (ctx->r6 == 0) {
        // 0x800144C8: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80014624;
    }
    goto skip_0;
    // 0x800144C8: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_0:
    // 0x800144CC: lbu         $t9, 0x54($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X54);
    // 0x800144D0: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x800144D4: bnel        $t5, $zero, L_80014624
    if (ctx->r13 != 0) {
        // 0x800144D8: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80014624;
    }
    goto skip_1;
    // 0x800144D8: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_1:
    // 0x800144DC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800144E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800144E4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800144E8: beq         $v0, $at, L_80014620
    if (ctx->r2 == ctx->r1) {
        // 0x800144EC: addiu       $s1, $s1, 0x65B0
        ctx->r17 = ADD32(ctx->r17, 0X65B0);
            goto L_80014620;
    }
    // 0x800144EC: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800144F0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800144F4: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x800144F8: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
L_800144FC:
    // 0x800144FC: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80014500: addu        $t7, $a3, $s0
    ctx->r15 = ADD32(ctx->r7, ctx->r16);
    // 0x80014504: beql        $t6, $zero, L_80014610
    if (ctx->r14 == 0) {
        // 0x80014508: lw          $v0, 0x8($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X8);
            goto L_80014610;
    }
    goto skip_2;
    // 0x80014508: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    skip_2:
    // 0x8001450C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80014510: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80014514: beq         $t8, $a0, L_8001457C
    if (ctx->r24 == ctx->r4) {
        // 0x80014518: addu        $t9, $s1, $s0
        ctx->r25 = ADD32(ctx->r17, ctx->r16);
            goto L_8001457C;
    }
    // 0x80014518: addu        $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
L_8001451C:
    // 0x8001451C: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80014520: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80014524: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80014528: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8001452C: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x80014530: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80014534: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80014538: addu        $v1, $s1, $t9
    ctx->r3 = ADD32(ctx->r17, ctx->r25);
    // 0x8001453C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80014540: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80014544: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80014548: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8001454C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80014550: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x80014554: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80014558: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8001455C: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x80014560: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80014564: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80014568: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8001456C: addu        $t6, $a3, $s0
    ctx->r14 = ADD32(ctx->r7, ctx->r16);
    // 0x80014570: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80014574: bnel        $t7, $a0, L_8001451C
    if (ctx->r15 != ctx->r4) {
        // 0x80014578: addu        $t9, $s1, $s0
        ctx->r25 = ADD32(ctx->r17, ctx->r16);
            goto L_8001451C;
    }
    goto skip_3;
    // 0x80014578: addu        $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    skip_3:
L_8001457C:
    // 0x8001457C: lw          $t8, 0x80($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X80);
    // 0x80014580: beql        $t8, $zero, L_800145F0
    if (ctx->r24 == 0) {
        // 0x80014584: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_800145F0;
    }
    goto skip_4;
    // 0x80014584: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    skip_4:
    // 0x80014588: bne         $s4, $zero, L_800145C8
    if (ctx->r20 != 0) {
        // 0x8001458C: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_800145C8;
    }
    // 0x8001458C: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x80014590: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80014594: lw          $s4, 0x65E4($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X65E4);
    // 0x80014598: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001459C: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    // 0x800145A0: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x800145A4: jal         0x80012D90
    // 0x800145A8: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x800145A8: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_1:
    // 0x800145AC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800145B0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800145B4: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x800145B8: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800145BC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800145C0: b           L_800145EC
    // 0x800145C4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
        goto L_800145EC;
    // 0x800145C4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_800145C8:
    // 0x800145C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800145CC: lui         $t5, 0xDB06
    ctx->r13 = S32(0XDB06 << 16);
    // 0x800145D0: ori         $t5, $t5, 0x38
    ctx->r13 = ctx->r13 | 0X38;
    // 0x800145D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800145D8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800145DC: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x800145E0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800145E4: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800145E8: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_800145EC:
    // 0x800145EC: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
L_800145F0:
    // 0x800145F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800145F4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800145F8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800145FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80014600: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80014604: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x80014608: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001460C: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
L_80014610:
    // 0x80014610: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80014614: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80014618: bnel        $v0, $at, L_800144FC
    if (ctx->r2 != ctx->r1) {
        // 0x8001461C: lw          $t6, 0x4($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X4);
            goto L_800144FC;
    }
    goto skip_5;
    // 0x8001461C: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    skip_5:
L_80014620:
    // 0x80014620: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
L_80014624:
    // 0x80014624: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80014628: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x8001462C: beql        $a0, $zero, L_80014644
    if (ctx->r4 == 0) {
        // 0x80014630: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80014644;
    }
    goto skip_6;
    // 0x80014630: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    skip_6:
    // 0x80014634: jal         0x8001445C
    // 0x80014638: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    gcDrawDObjTreeDLLinks(rdram, ctx);
        goto after_2;
    // 0x80014638: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_2:
    // 0x8001463C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80014640: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_80014644:
    // 0x80014644: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80014648: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8001464C: lui         $t1, 0xD838
    ctx->r9 = S32(0XD838 << 16);
    // 0x80014650: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x80014654: addiu       $t4, $t4, 0x70C8
    ctx->r12 = ADD32(ctx->r12, 0X70C8);
    // 0x80014658: addiu       $a2, $a2, 0x70B8
    ctx->r6 = ADD32(ctx->r6, 0X70B8);
    // 0x8001465C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80014660: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80014664: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80014668: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
L_8001466C:
    // 0x8001466C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80014670: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80014674: sltu        $at, $a1, $t5
    ctx->r1 = ctx->r5 < ctx->r13 ? 1 : 0;
    // 0x80014678: beql        $at, $zero, L_800146C0
    if (ctx->r1 == 0) {
        // 0x8001467C: lw          $t9, 0x4($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X4);
            goto L_800146C0;
    }
    goto skip_7;
    // 0x8001467C: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    skip_7:
    // 0x80014680: beq         $t3, $zero, L_800146BC
    if (ctx->r11 == 0) {
        // 0x80014684: sw          $a1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r5;
            goto L_800146BC;
    }
    // 0x80014684: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80014688: lw          $t6, 0x14($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X14);
    // 0x8001468C: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x80014690: beql        $t0, $t6, L_800146A8
    if (ctx->r8 == ctx->r14) {
        // 0x80014694: lw          $a0, 0x0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X0);
            goto L_800146A8;
    }
    goto skip_8;
    // 0x80014694: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    skip_8:
    // 0x80014698: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x8001469C: beql        $t7, $zero, L_800146C0
    if (ctx->r15 == 0) {
        // 0x800146A0: lw          $t9, 0x4($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X4);
            goto L_800146C0;
    }
    goto skip_9;
    // 0x800146A0: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    skip_9:
    // 0x800146A4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_800146A8:
    // 0x800146A8: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x800146AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800146B0: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x800146B4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800146B8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
L_800146BC:
    // 0x800146BC: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
L_800146C0:
    // 0x800146C0: sltu        $at, $a1, $t9
    ctx->r1 = ctx->r5 < ctx->r25 ? 1 : 0;
    // 0x800146C4: beql        $at, $zero, L_80014708
    if (ctx->r1 == 0) {
        // 0x800146C8: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80014708;
    }
    goto skip_10;
    // 0x800146C8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_10:
    // 0x800146CC: beq         $t3, $zero, L_80014704
    if (ctx->r11 == 0) {
        // 0x800146D0: sw          $a1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r5;
            goto L_80014704;
    }
    // 0x800146D0: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x800146D4: lw          $t5, 0x14($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X14);
    // 0x800146D8: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x800146DC: beql        $t0, $t5, L_800146F4
    if (ctx->r8 == ctx->r13) {
        // 0x800146E0: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_800146F4;
    }
    goto skip_11;
    // 0x800146E0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_11:
    // 0x800146E4: lw          $t6, 0x8($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X8);
    // 0x800146E8: beql        $t6, $zero, L_80014708
    if (ctx->r14 == 0) {
        // 0x800146EC: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80014708;
    }
    goto skip_12;
    // 0x800146EC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_12:
    // 0x800146F0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_800146F4:
    // 0x800146F4: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x800146F8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800146FC: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80014700: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_80014704:
    // 0x80014704: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80014708:
    // 0x80014708: bne         $a2, $t4, L_8001466C
    if (ctx->r6 != ctx->r12) {
        // 0x8001470C: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8001466C;
    }
    // 0x8001470C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80014710: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80014714: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014718: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_8001471C:
    // 0x8001471C: lw          $t8, 0xC($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XC);
    // 0x80014720: bnel        $t8, $zero, L_8001474C
    if (ctx->r24 != 0) {
        // 0x80014724: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001474C;
    }
    goto skip_13;
    // 0x80014724: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_13:
    // 0x80014728: lw          $s0, 0x8($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X8);
    // 0x8001472C: beql        $s0, $zero, L_8001474C
    if (ctx->r16 == 0) {
        // 0x80014730: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001474C;
    }
    goto skip_14;
    // 0x80014730: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
L_80014734:
    // 0x80014734: jal         0x8001445C
    // 0x80014738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcDrawDObjTreeDLLinks(rdram, ctx);
        goto after_3;
    // 0x80014738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8001473C: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80014740: bne         $s0, $zero, L_80014734
    if (ctx->r16 != 0) {
        // 0x80014744: nop
    
            goto L_80014734;
    }
    // 0x80014744: nop

    // 0x80014748: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001474C:
    // 0x8001474C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80014750: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80014754: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80014758: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001475C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80014760: jr          $ra
    // 0x80014764: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80014764: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftCaptainSpecialAirLwProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FE6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FE70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FE74: jal         0x8015FC30
    // 0x8015FE78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCaptainSpecialLwUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x8015FE78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015FE7C: jal         0x800D93E4
    // 0x8015FE80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_1;
    // 0x8015FE80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015FE84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FE88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FE8C: jr          $ra
    // 0x8015FE90: nop

    return;
    // 0x8015FE90: nop

;}
RECOMP_FUNC void gcRemoveAnimAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BC58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BC5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000BC60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000BC64: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8000BC68: beql        $s1, $zero, L_8000BCAC
    if (ctx->r17 == 0) {
        // 0x8000BC6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000BCAC;
    }
    goto skip_0;
    // 0x8000BC6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8000BC70:
    // 0x8000BC70: jal         0x80008EE4
    // 0x8000BC74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcRemoveAObjFromDObj(rdram, ctx);
        goto after_0;
    // 0x8000BC74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8000BC78: lw          $s0, 0x80($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X80);
    // 0x8000BC7C: beq         $s0, $zero, L_8000BC98
    if (ctx->r16 == 0) {
        // 0x8000BC80: nop
    
            goto L_8000BC98;
    }
    // 0x8000BC80: nop

L_8000BC84:
    // 0x8000BC84: jal         0x80008FB0
    // 0x8000BC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveAObjFromMObj(rdram, ctx);
        goto after_1;
    // 0x8000BC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000BC8C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000BC90: bne         $s0, $zero, L_8000BC84
    if (ctx->r16 != 0) {
        // 0x8000BC94: nop
    
            goto L_8000BC84;
    }
    // 0x8000BC94: nop

L_8000BC98:
    // 0x8000BC98: jal         0x8000BAA0
    // 0x8000BC9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_2;
    // 0x8000BC9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8000BCA0: bne         $v0, $zero, L_8000BC70
    if (ctx->r2 != 0) {
        // 0x8000BCA4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000BC70;
    }
    // 0x8000BCA4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000BCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000BCAC:
    // 0x8000BCAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000BCB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000BCB4: jr          $ra
    // 0x8000BCB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000BCB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gmCameraSetStatusPrev(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D00C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010D010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D014: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010D018: jal         0x8010CEF4
    // 0x8010D01C: lw          $a0, 0x14B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14B8);
    gmCameraSetStatus(rdram, ctx);
        goto after_0;
    // 0x8010D01C: lw          $a0, 0x14B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14B8);
    after_0:
    // 0x8010D020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010D028: jr          $ra
    // 0x8010D02C: nop

    return;
    // 0x8010D02C: nop

;}
RECOMP_FUNC void syTaskmanMalloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004984: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80004988: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000498C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004994: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004998: jal         0x80006CEC
    // 0x8000499C: addiu       $a0, $a0, 0x65E8
    ctx->r4 = ADD32(ctx->r4, 0X65E8);
    syMallocSet(rdram, ctx);
        goto after_0;
    // 0x8000499C: addiu       $a0, $a0, 0x65E8
    ctx->r4 = ADD32(ctx->r4, 0X65E8);
    after_0:
    // 0x800049A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049A8: jr          $ra
    // 0x800049AC: nop

    return;
    // 0x800049AC: nop

;}
RECOMP_FUNC void ftYoshiSpecialNReleaseSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E8F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E8FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E900: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8015E904: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E908: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015E90C: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8015E910: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015E914: jal         0x800E6F24
    // 0x8015E918: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015E918: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015E91C: jal         0x800E0830
    // 0x8015E920: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015E920: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015E924: jal         0x8015E8C4
    // 0x8015E928: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftYoshiSpecialNReleaseInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015E928: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015E92C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E930: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E934: jr          $ra
    // 0x8015E938: nop

    return;
    // 0x8015E938: nop

;}
RECOMP_FUNC void mnCharactersCheckHaveFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133510: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80133514: beq         $a0, $at, L_80133538
    if (ctx->r4 == ctx->r1) {
        // 0x80133518: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_80133538;
    }
    // 0x80133518: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013351C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133520: beq         $a0, $at, L_80133538
    if (ctx->r4 == ctx->r1) {
        // 0x80133524: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80133538;
    }
    // 0x80133524: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80133528: beq         $a0, $at, L_80133538
    if (ctx->r4 == ctx->r1) {
        // 0x8013352C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80133538;
    }
    // 0x8013352C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80133530: bne         $a0, $at, L_80133560
    if (ctx->r4 != ctx->r1) {
        // 0x80133534: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80133560;
    }
    // 0x80133534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133538:
    // 0x80133538: lhu         $t6, 0x6700($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X6700);
    // 0x8013353C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80133540: sllv        $t8, $t7, $a0
    ctx->r24 = S32(ctx->r15 << (ctx->r4 & 31));
    // 0x80133544: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x80133548: beq         $t9, $zero, L_80133558
    if (ctx->r25 == 0) {
        // 0x8013354C: nop
    
            goto L_80133558;
    }
    // 0x8013354C: nop

    // 0x80133550: jr          $ra
    // 0x80133554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80133554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133558:
    // 0x80133558: jr          $ra
    // 0x8013355C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013355C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133560:
    // 0x80133560: jr          $ra
    // 0x80133564: nop

    return;
    // 0x80133564: nop

;}
RECOMP_FUNC void wpManagerGetGroupID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801655A0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801655A4: addiu       $a0, $a0, -0x3008
    ctx->r4 = ADD32(ctx->r4, -0X3008);
    // 0x801655A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801655AC: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x801655B0: bne         $t6, $zero, L_801655C0
    if (ctx->r14 != 0) {
        // 0x801655B4: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_801655C0;
    }
    // 0x801655B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801655B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801655BC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_801655C0:
    // 0x801655C0: jr          $ra
    // 0x801655C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801655C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnPlayersVSDestroyTeamSelectAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801328B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801328B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801328B8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801328BC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801328C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801328C4: addiu       $s1, $s1, -0x4288
    ctx->r17 = ADD32(ctx->r17, -0X4288);
    // 0x801328C8: addiu       $s0, $s0, -0x4578
    ctx->r16 = ADD32(ctx->r16, -0X4578);
    // 0x801328CC: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
L_801328D0:
    // 0x801328D0: beql        $a0, $zero, L_801328E8
    if (ctx->r4 == 0) {
        // 0x801328D4: addiu       $s0, $s0, 0xBC
        ctx->r16 = ADD32(ctx->r16, 0XBC);
            goto L_801328E8;
    }
    goto skip_0;
    // 0x801328D4: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
    skip_0:
    // 0x801328D8: jal         0x80009A84
    // 0x801328DC: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801328DC: nop

    after_0:
    // 0x801328E0: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x801328E4: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
L_801328E8:
    // 0x801328E8: bnel        $s0, $s1, L_801328D0
    if (ctx->r16 != ctx->r17) {
        // 0x801328EC: lw          $a0, 0x1C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X1C);
            goto L_801328D0;
    }
    goto skip_1;
    // 0x801328EC: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    skip_1:
    // 0x801328F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801328F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801328F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801328FC: jr          $ra
    // 0x80132900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80132900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void sc1PTrainingModeFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801905A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801905AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801905B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801905B4: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x801905B8: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x801905BC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801905C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801905C4: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801905C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801905CC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801905D0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801905D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801905D8: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x801905DC: jal         0x800FCB70
    // 0x801905E0: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x801905E0: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x801905E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801905E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801905EC: jr          $ra
    // 0x801905F0: nop

    return;
    // 0x801905F0: nop

;}
RECOMP_FUNC void gcDrawDObjTreeDLLinksForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014768: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001476C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80014770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014774: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001477C: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80014780: jal         0x8001445C
    // 0x80014784: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    gcDrawDObjTreeDLLinks(rdram, ctx);
        goto after_0;
    // 0x80014784: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    after_0:
    // 0x80014788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001478C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014790: jr          $ra
    // 0x80014794: nop

    return;
    // 0x80014794: nop

;}
RECOMP_FUNC void func_ovl8_80373BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373BD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80373BD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80373BDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80373BE0: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80373BE4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80373BE8: lh          $t7, 0xB8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB8);
    // 0x80373BEC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80373BF0: lw          $t9, 0xBC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBC);
    // 0x80373BF4: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    // 0x80373BF8: jalr        $t9
    // 0x80373BFC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373BFC: nop

    after_0:
    // 0x80373C00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80373C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80373C08: jr          $ra
    // 0x80373C0C: nop

    return;
    // 0x80373C0C: nop

;}
RECOMP_FUNC void ftCommonJumpAerialMultiCheckJumpButtonHold(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014012C: lhu         $t6, 0x1BC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X1BC);
    // 0x80140130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80140134: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80140138: beq         $t7, $zero, L_80140148
    if (ctx->r15 == 0) {
        // 0x8014013C: nop
    
            goto L_80140148;
    }
    // 0x8014013C: nop

    // 0x80140140: jr          $ra
    // 0x80140144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80140144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140148:
    // 0x80140148: jr          $ra
    // 0x8014014C: nop

    return;
    // 0x8014014C: nop

;}
RECOMP_FUNC void gmCameraAnimFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CC74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CC78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CC7C: jal         0x8010CBE4
    // 0x8010CC80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gmCameraUpdateAnimVel(rdram, ctx);
        goto after_0;
    // 0x8010CC80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010CC84: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8010CC88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010CC8C: lwc1        $f4, 0xC48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC48);
    // 0x8010CC90: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8010CC94: lwc1        $f6, 0x74($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X74);
    // 0x8010CC98: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8010CC9C: nop

    // 0x8010CCA0: bc1fl       L_8010CCB4
    if (!c1cs) {
        // 0x8010CCA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010CCB4;
    }
    goto skip_0;
    // 0x8010CCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010CCA8: jal         0x8010CF20
    // 0x8010CCAC: nop

    gmCameraSetStatusDefault(rdram, ctx);
        goto after_1;
    // 0x8010CCAC: nop

    after_1:
    // 0x8010CCB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010CCB4:
    // 0x8010CCB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CCB8: jr          $ra
    // 0x8010CCBC: nop

    return;
    // 0x8010CCBC: nop

;}
RECOMP_FUNC void func_8000EE40_FA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EE40: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8000EE44: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8000EE48: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8000EE4C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8000EE50: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8000EE54: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8000EE58: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8000EE5C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8000EE60: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8000EE64: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8000EE68: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8000EE6C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8000EE70: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8000EE74: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8000EE78: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8000EE7C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000EE80: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8000EE84: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8000EE88: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8000EE8C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x8000EE90: beq         $s0, $zero, L_8000F020
    if (ctx->r16 == 0) {
        // 0x8000EE94: swc1        $f22, 0x78($a0)
        MEM_W(0X78, ctx->r4) = ctx->f22.u32l;
            goto L_8000F020;
    }
    // 0x8000EE94: swc1        $f22, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f22.u32l;
    // 0x8000EE98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000EE9C: lwc1        $f20, -0x2050($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2050);
    // 0x8000EEA0: addiu       $s7, $zero, 0xB
    ctx->r23 = ADD32(0, 0XB);
    // 0x8000EEA4: addiu       $s6, $sp, 0x7C
    ctx->r22 = ADD32(ctx->r29, 0X7C);
    // 0x8000EEA8: addiu       $s5, $sp, 0x70
    ctx->r21 = ADD32(ctx->r29, 0X70);
    // 0x8000EEAC: addiu       $s4, $sp, 0x84
    ctx->r20 = ADD32(ctx->r29, 0X84);
    // 0x8000EEB0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_8000EEB4:
    // 0x8000EEB4: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8000EEB8: beql        $a1, $zero, L_8000EFB4
    if (ctx->r5 == 0) {
        // 0x8000EEBC: swc1        $f20, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
            goto L_8000EFB4;
    }
    goto skip_0;
    // 0x8000EEBC: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x8000EEC0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8000EEC4: jal         0x8000BD1C
    // 0x8000EEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8000EEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000EECC: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EED0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000EED4: sb          $t7, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r15;
    // 0x8000EED8: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
L_8000EEDC:
    // 0x8000EEDC: beq         $s1, $s3, L_8000EF9C
    if (ctx->r17 == ctx->r19) {
        // 0x8000EEE0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000EF9C;
    }
    // 0x8000EEE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000EEE4: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x8000EEE8: sw          $s6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r22;
    // 0x8000EEEC: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // 0x8000EEF0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8000EEF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000EEF8: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x8000EEFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000EF00: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8000EF04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000EF08: jal         0x8000E164
    // 0x8000EF0C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    gcCheckGetDObjNoAxisTrack(rdram, ctx);
        goto after_1;
    // 0x8000EF0C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8000EF10: addiu       $t9, $s1, -0x1
    ctx->r25 = ADD32(ctx->r17, -0X1);
    // 0x8000EF14: sltiu       $at, $t9, 0xA
    ctx->r1 = ctx->r25 < 0XA ? 1 : 0;
    // 0x8000EF18: beq         $at, $zero, L_8000EF9C
    if (ctx->r1 == 0) {
        // 0x8000EF1C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8000EF9C;
    }
    // 0x8000EF1C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000EF20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000EF24: addu        $at, $at, $t9
    gpr jr_addend_8000EF2C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8000EF28: lw          $t9, -0x204C($at)
    ctx->r25 = ADD32(ctx->r1, -0X204C);
    // 0x8000EF2C: jr          $t9
    // 0x8000EF30: nop

    switch (jr_addend_8000EF2C >> 2) {
        case 0: goto L_8000EF34; break;
        case 1: goto L_8000EF40; break;
        case 2: goto L_8000EF4C; break;
        case 3: goto L_8000EF9C; break;
        case 4: goto L_8000EF58; break;
        case 5: goto L_8000EF64; break;
        case 6: goto L_8000EF70; break;
        case 7: goto L_8000EF7C; break;
        case 8: goto L_8000EF88; break;
        case 9: goto L_8000EF94; break;
        default: switch_error(__func__, 0x8000EF2C, 0x8003DFB4);
    }
    // 0x8000EF30: nop

L_8000EF34:
    // 0x8000EF34: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF38: b           L_8000EF9C
    // 0x8000EF3C: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
        goto L_8000EF9C;
    // 0x8000EF3C: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_8000EF40:
    // 0x8000EF40: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF44: b           L_8000EF9C
    // 0x8000EF48: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
        goto L_8000EF9C;
    // 0x8000EF48: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
L_8000EF4C:
    // 0x8000EF4C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF50: b           L_8000EF9C
    // 0x8000EF54: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
        goto L_8000EF9C;
    // 0x8000EF54: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
L_8000EF58:
    // 0x8000EF58: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF5C: b           L_8000EF9C
    // 0x8000EF60: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
        goto L_8000EF9C;
    // 0x8000EF60: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
L_8000EF64:
    // 0x8000EF64: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF68: b           L_8000EF9C
    // 0x8000EF6C: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
        goto L_8000EF9C;
    // 0x8000EF6C: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
L_8000EF70:
    // 0x8000EF70: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF74: b           L_8000EF9C
    // 0x8000EF78: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
        goto L_8000EF9C;
    // 0x8000EF78: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_8000EF7C:
    // 0x8000EF7C: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF80: b           L_8000EF9C
    // 0x8000EF84: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
        goto L_8000EF9C;
    // 0x8000EF84: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
L_8000EF88:
    // 0x8000EF88: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF8C: b           L_8000EF9C
    // 0x8000EF90: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
        goto L_8000EF9C;
    // 0x8000EF90: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
L_8000EF94:
    // 0x8000EF94: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8000EF98: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
L_8000EF9C:
    // 0x8000EF9C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000EFA0: bne         $s1, $s7, L_8000EEDC
    if (ctx->r17 != ctx->r23) {
        // 0x8000EFA4: nop
    
            goto L_8000EEDC;
    }
    // 0x8000EFA4: nop

    // 0x8000EFA8: b           L_8000F004
    // 0x8000EFAC: nop

        goto L_8000F004;
    // 0x8000EFAC: nop

    // 0x8000EFB0: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
L_8000EFB4:
    // 0x8000EFB4: beq         $s2, $zero, L_8000F004
    if (ctx->r18 == 0) {
        // 0x8000EFB8: sb          $zero, 0x55($s0)
        MEM_B(0X55, ctx->r16) = 0;
            goto L_8000F004;
    }
    // 0x8000EFB8: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x8000EFBC: lw          $t1, 0x8($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X8);
    // 0x8000EFC0: sw          $t1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r9;
    // 0x8000EFC4: lw          $t0, 0xC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC);
    // 0x8000EFC8: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x8000EFCC: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
    // 0x8000EFD0: sw          $t1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r9;
    // 0x8000EFD4: lw          $t3, 0x14($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X14);
    // 0x8000EFD8: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x8000EFDC: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x8000EFE0: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
    // 0x8000EFE4: lw          $t3, 0x1C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X1C);
    // 0x8000EFE8: sw          $t3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r11;
    // 0x8000EFEC: lw          $t5, 0x20($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X20);
    // 0x8000EFF0: sw          $t5, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r13;
    // 0x8000EFF4: lw          $t4, 0x24($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X24);
    // 0x8000EFF8: sw          $t4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r12;
    // 0x8000EFFC: lw          $t5, 0x28($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X28);
    // 0x8000F000: sw          $t5, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r13;
L_8000F004:
    // 0x8000F004: beq         $s2, $zero, L_8000F010
    if (ctx->r18 == 0) {
        // 0x8000F008: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_8000F010;
    }
    // 0x8000F008: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8000F00C: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
L_8000F010:
    // 0x8000F010: jal         0x8000BAA0
    // 0x8000F014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_2;
    // 0x8000F014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8000F018: bne         $v0, $zero, L_8000EEB4
    if (ctx->r2 != 0) {
        // 0x8000F01C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000EEB4;
    }
    // 0x8000F01C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000F020:
    // 0x8000F020: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8000F024: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8000F028: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8000F02C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8000F030: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8000F034: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8000F038: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8000F03C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8000F040: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8000F044: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8000F048: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8000F04C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8000F050: jr          $ra
    // 0x8000F054: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8000F054: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void mnPlayers1PBonusGetNextPortraitX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132030: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132034: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132038: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x8013203C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80132040: addiu       $t6, $t6, 0x70C0
    ctx->r14 = ADD32(ctx->r14, 0X70C0);
    // 0x80132044: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80132048: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x8013204C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80132050:
    // 0x80132050: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132054: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132058: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8013205C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132060: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132064: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132068: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013206C: bne         $t6, $t0, L_80132050
    if (ctx->r14 != ctx->r8) {
        // 0x80132070: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132050;
    }
    // 0x80132070: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132074: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132078: addiu       $t1, $t1, 0x70F0
    ctx->r9 = ADD32(ctx->r9, 0X70F0);
    // 0x8013207C: addiu       $t5, $t1, 0x30
    ctx->r13 = ADD32(ctx->r9, 0X30);
    // 0x80132080: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_80132084:
    // 0x80132084: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80132088: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8013208C: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80132090: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x80132094: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x80132098: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x8013209C: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x801320A0: bne         $t1, $t5, L_80132084
    if (ctx->r9 != ctx->r13) {
        // 0x801320A4: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_80132084;
    }
    // 0x801320A4: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x801320A8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x801320AC: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x801320B0: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801320B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801320B8: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x801320BC: nop

    // 0x801320C0: bc1fl       L_801320D8
    if (!c1cs) {
        // 0x801320C4: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_801320D8;
    }
    goto skip_0;
    // 0x801320C4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x801320C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801320CC: b           L_8013213C
    // 0x801320D0: nop

        goto L_8013213C;
    // 0x801320D0: nop

    // 0x801320D4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_801320D8:
    // 0x801320D8: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x801320DC: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x801320E0: bc1fl       L_80132118
    if (!c1cs) {
        // 0x801320E4: lwc1        $f6, 0x0($t9)
        ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
            goto L_80132118;
    }
    goto skip_1;
    // 0x801320E4: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    skip_1:
    // 0x801320E8: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801320EC: add.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x801320F0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801320F4: nop

    // 0x801320F8: bc1fl       L_8013210C
    if (!c1cs) {
        // 0x801320FC: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_8013210C;
    }
    goto skip_2;
    // 0x801320FC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x80132100: b           L_8013213C
    // 0x80132104: nop

        goto L_8013213C;
    // 0x80132104: nop

    // 0x80132108: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8013210C:
    // 0x8013210C: b           L_8013213C
    // 0x80132110: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8013213C;
    // 0x80132110: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80132114: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
L_80132118:
    // 0x80132118: add.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8013211C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80132120: nop

    // 0x80132124: bc1fl       L_80132138
    if (!c1cs) {
        // 0x80132128: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80132138;
    }
    goto skip_3;
    // 0x80132128: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_3:
    // 0x8013212C: b           L_80132138
    // 0x80132130: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80132138;
    // 0x80132130: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80132134: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80132138:
    // 0x80132138: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8013213C:
    // 0x8013213C: jr          $ra
    // 0x80132140: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80132140: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void ftBossTsutsuku1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159EA8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80159EAC: jal         0x800D9480
    // 0x80159EB0: addiu       $a1, $a1, -0x5F90
    ctx->r5 = ADD32(ctx->r5, -0X5F90);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159EB0: addiu       $a1, $a1, -0x5F90
    ctx->r5 = ADD32(ctx->r5, -0X5F90);
    after_0:
    // 0x80159EB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159EB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159EBC: jr          $ra
    // 0x80159EC0: nop

    return;
    // 0x80159EC0: nop

;}
RECOMP_FUNC void func_80009F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009F28: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80009F2C: sb          $t6, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r14;
    // 0x80009F30: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x80009F34: sw          $a1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r5;
    // 0x80009F38: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80009F3C: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x80009F40: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80009F44: sw          $t9, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r25;
    // 0x80009F48: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x80009F4C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80009F50: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80009F54: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    // 0x80009F58: sw          $t0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r8;
    // 0x80009F5C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80009F60: sw          $t7, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r15;
    // 0x80009F64: lw          $t2, -0x4918($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4918);
    // 0x80009F68: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80009F6C: jr          $ra
    // 0x80009F70: sb          $t3, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r11;
    return;
    // 0x80009F70: sb          $t3, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void efManagerFlameStaticMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEB58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FEB5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FEB60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FEB64: jal         0x800FD4B8
    // 0x800FEB68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FEB68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800FEB6C: bne         $v0, $zero, L_800FEB7C
    if (ctx->r2 != 0) {
        // 0x800FEB70: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FEB7C;
    }
    // 0x800FEB70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FEB74: b           L_800FECA8
    // 0x800FEB78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FECA8;
    // 0x800FEB78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FEB7C:
    // 0x800FEB7C: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FEB80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FEB84: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FEB88: jal         0x80009968
    // 0x800FEB8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FEB8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FEB90: bne         $v0, $zero, L_800FEBA8
    if (ctx->r2 != 0) {
        // 0x800FEB94: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FEBA8;
    }
    // 0x800FEB94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FEB98: jal         0x800FD4F8
    // 0x800FEB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FEB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FEBA0: b           L_800FECA8
    // 0x800FEBA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FECA8;
    // 0x800FEBA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FEBA8:
    // 0x800FEBA8: sw          $s0, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r16;
    // 0x800FEBAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FEBB0: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FEBB4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800FEBB8: jal         0x800CE9E8
    // 0x800FEBBC: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FEBBC: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_3:
    // 0x800FEBC0: beq         $v0, $zero, L_800FEC98
    if (ctx->r2 == 0) {
        // 0x800FEBC4: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800FEC98;
    }
    // 0x800FEBC4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800FEBC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FEBCC: jal         0x800CE1DC
    // 0x800FEBD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FEBD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FEBD4: beq         $v0, $zero, L_800FEC88
    if (ctx->r2 == 0) {
        // 0x800FEBD8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800FEC88;
    }
    // 0x800FEBD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800FEBDC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800FEBE0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800FEBE4: addiu       $t7, $t7, -0x2478
    ctx->r15 = ADD32(ctx->r15, -0X2478);
    // 0x800FEBE8: sw          $t7, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r15;
    // 0x800FEBEC: sw          $t6, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r14;
    // 0x800FEBF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800FEBF4: jal         0x800CEA14
    // 0x800FEBF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FEBF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x800FEBFC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FEC00: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FEC04: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FEC08: lhu         $t8, 0x2A($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2A);
    // 0x800FEC0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800FEC10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FEC14: bne         $t8, $zero, L_800FEC24
    if (ctx->r24 != 0) {
        // 0x800FEC18: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800FEC24;
    }
    // 0x800FEC18: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800FEC1C: b           L_800FECA8
    // 0x800FEC20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FECA8;
    // 0x800FEC20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FEC24:
    // 0x800FEC24: jal         0x80008188
    // 0x800FEC28: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FEC28: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x800FEC2C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FEC30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FEC34: sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // 0x800FEC38: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800FEC3C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800FEC40: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800FEC44: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800FEC48: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x800FEC4C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x800FEC50: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x800FEC54: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800FEC58: jal         0x80018948
    // 0x800FEC5C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FEC5C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    after_7:
    // 0x800FEC60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FEC64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FEC68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FEC6C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FEC70: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEC74: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FEC78: swc1        $f2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f2.u32l;
    // 0x800FEC7C: swc1        $f2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f2.u32l;
    // 0x800FEC80: b           L_800FECA4
    // 0x800FEC84: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
        goto L_800FECA4;
    // 0x800FEC84: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
L_800FEC88:
    // 0x800FEC88: jal         0x800FDB3C
    // 0x800FEC8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_8;
    // 0x800FEC8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x800FEC90: b           L_800FECA4
    // 0x800FEC94: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_800FECA4;
    // 0x800FEC94: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_800FEC98:
    // 0x800FEC98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FEC9C: jal         0x800FDB3C
    // 0x800FECA0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_9;
    // 0x800FECA0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_9:
L_800FECA4:
    // 0x800FECA4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800FECA8:
    // 0x800FECA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FECAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FECB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FECB4: jr          $ra
    // 0x800FECB8: nop

    return;
    // 0x800FECB8: nop

;}
RECOMP_FUNC void ftCommonItemThrowProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014661C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146620: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80146624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80146628: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x8014662C: bne         $t6, $at, L_80146644
    if (ctx->r14 != ctx->r1) {
        // 0x80146630: nop
    
            goto L_80146644;
    }
    // 0x80146630: nop

    // 0x80146634: jal         0x800D90E0
    // 0x80146638: nop

    ftPhysicsApplyAirVelDrift(rdram, ctx);
        goto after_0;
    // 0x80146638: nop

    after_0:
    // 0x8014663C: b           L_80146650
    // 0x80146640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80146650;
    // 0x80146640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80146644:
    // 0x80146644: jal         0x800D8BB4
    // 0x80146648: nop

    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_1;
    // 0x80146648: nop

    after_1:
    // 0x8014664C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80146650:
    // 0x80146650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146654: jr          $ra
    // 0x80146658: nop

    return;
    // 0x80146658: nop

;}
RECOMP_FUNC void ftCommonDamageFallSetStatusFromDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143664: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80143668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014366C: addiu       $t6, $zero, 0x108
    ctx->r14 = ADD32(0, 0X108);
    // 0x80143670: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80143674: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80143678: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x8014367C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80143680: jal         0x800E6F24
    // 0x80143684: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80143684: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80143688: jal         0x80143630
    // 0x8014368C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDamageFallClampRumble(rdram, ctx);
        goto after_1;
    // 0x8014368C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80143690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80143694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80143698: jr          $ra
    // 0x8014369C: nop

    return;
    // 0x8014369C: nop

;}
RECOMP_FUNC void gcSetupCustomDObjsWithMObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F720: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8000F724: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000F728: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000F72C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000F730: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8000F734: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8000F738: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8000F73C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000F740: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000F744: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000F748: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000F74C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000F750: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000F754: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000F758: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x8000F75C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x8000F760: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8000F764: addiu       $v0, $sp, 0x64
    ctx->r2 = ADD32(ctx->r29, 0X64);
    // 0x8000F768: addiu       $v1, $sp, 0xA4
    ctx->r3 = ADD32(ctx->r29, 0XA4);
L_8000F76C:
    // 0x8000F76C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000F770: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8000F774: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x8000F778: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000F77C: bne         $v0, $v1, L_8000F76C
    if (ctx->r2 != ctx->r3) {
        // 0x8000F780: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_8000F76C;
    }
    // 0x8000F780: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8000F784: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000F788: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8000F78C: lbu         $fp, 0xCB($sp)
    ctx->r30 = MEM_BU(ctx->r29, 0XCB);
    // 0x8000F790: beq         $v0, $at, L_8000F8C4
    if (ctx->r2 == ctx->r1) {
        // 0x8000F794: lbu         $s7, 0xC7($sp)
        ctx->r23 = MEM_BU(ctx->r29, 0XC7);
            goto L_8000F8C4;
    }
    // 0x8000F794: lbu         $s7, 0xC7($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0XC7);
    // 0x8000F798: lbu         $s6, 0xC3($sp)
    ctx->r22 = MEM_BU(ctx->r29, 0XC3);
    // 0x8000F79C: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
L_8000F7A0:
    // 0x8000F7A0: beq         $v1, $zero, L_8000F7C8
    if (ctx->r3 == 0) {
        // 0x8000F7A4: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_8000F7C8;
    }
    // 0x8000F7A4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8000F7A8: addiu       $t7, $sp, 0x5C
    ctx->r15 = ADD32(ctx->r29, 0X5C);
    // 0x8000F7AC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x8000F7B0: lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X4);
    // 0x8000F7B4: jal         0x800093F4
    // 0x8000F7B8: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x8000F7B8: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    after_0:
    // 0x8000F7BC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000F7C0: b           L_8000F7DC
    // 0x8000F7C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8000F7DC;
    // 0x8000F7C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8000F7C8:
    // 0x8000F7C8: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x8000F7CC: jal         0x800092D0
    // 0x8000F7D0: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x8000F7D0: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    after_1:
    // 0x8000F7D4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8000F7D8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8000F7DC:
    // 0x8000F7DC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000F7E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F7E4: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x8000F7E8: andi        $v0, $v0, 0xF000
    ctx->r2 = ctx->r2 & 0XF000;
    // 0x8000F7EC: beq         $v0, $zero, L_8000F814
    if (ctx->r2 == 0) {
        // 0x8000F7F0: andi        $a2, $s7, 0xFF
        ctx->r6 = ctx->r23 & 0XFF;
            goto L_8000F814;
    }
    // 0x8000F7F0: andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    // 0x8000F7F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F7F8: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x8000F7FC: andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    // 0x8000F800: andi        $a3, $fp, 0xFF
    ctx->r7 = ctx->r30 & 0XFF;
    // 0x8000F804: jal         0x8000F364
    // 0x8000F808: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    gcDecideDObj3TransformsKind(rdram, ctx);
        goto after_2;
    // 0x8000F808: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8000F80C: b           L_8000F820
    // 0x8000F810: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
        goto L_8000F820;
    // 0x8000F810: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
L_8000F814:
    // 0x8000F814: jal         0x8000F2FC
    // 0x8000F818: andi        $a3, $fp, 0xFF
    ctx->r7 = ctx->r30 & 0XFF;
    gcAddDObj3TransformsKind(rdram, ctx);
        goto after_3;
    // 0x8000F818: andi        $a3, $fp, 0xFF
    ctx->r7 = ctx->r30 & 0XFF;
    after_3:
    // 0x8000F81C: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
L_8000F820:
    // 0x8000F820: sw          $t9, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r25;
    // 0x8000F824: lw          $t8, 0xC($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XC);
    // 0x8000F828: sw          $t8, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r24;
    // 0x8000F82C: lw          $t9, 0x10($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X10);
    // 0x8000F830: sw          $t9, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r25;
    // 0x8000F834: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x8000F838: sw          $t1, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r9;
    // 0x8000F83C: lw          $t0, 0x18($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X18);
    // 0x8000F840: sw          $t0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r8;
    // 0x8000F844: lw          $t1, 0x1C($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X1C);
    // 0x8000F848: sw          $t1, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r9;
    // 0x8000F84C: lw          $t3, 0x20($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X20);
    // 0x8000F850: sw          $t3, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r11;
    // 0x8000F854: lw          $t2, 0x24($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X24);
    // 0x8000F858: sw          $t2, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r10;
    // 0x8000F85C: lw          $t3, 0x28($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X28);
    // 0x8000F860: beq         $s4, $zero, L_8000F8A0
    if (ctx->r20 == 0) {
        // 0x8000F864: sw          $t3, 0x48($s2)
        MEM_W(0X48, ctx->r18) = ctx->r11;
            goto L_8000F8A0;
    }
    // 0x8000F864: sw          $t3, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->r11;
    // 0x8000F868: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000F86C: beql        $v0, $zero, L_8000F8A0
    if (ctx->r2 == 0) {
        // 0x8000F870: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_8000F8A0;
    }
    goto skip_0;
    // 0x8000F870: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_0:
    // 0x8000F874: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x8000F878: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F87C: beq         $s1, $zero, L_8000F89C
    if (ctx->r17 == 0) {
        // 0x8000F880: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000F89C;
    }
    // 0x8000F880: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8000F884:
    // 0x8000F884: jal         0x800090DC
    // 0x8000F888: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcAddMObjForDObj(rdram, ctx);
        goto after_4;
    // 0x8000F888: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8000F88C: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x8000F890: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F894: bnel        $s1, $zero, L_8000F884
    if (ctx->r17 != 0) {
        // 0x8000F898: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000F884;
    }
    goto skip_1;
    // 0x8000F898: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_8000F89C:
    // 0x8000F89C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_8000F8A0:
    // 0x8000F8A0: beql        $s5, $zero, L_8000F8B4
    if (ctx->r21 == 0) {
        // 0x8000F8A4: lw          $v0, 0x2C($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X2C);
            goto L_8000F8B4;
    }
    goto skip_2;
    // 0x8000F8A4: lw          $v0, 0x2C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X2C);
    skip_2:
    // 0x8000F8A8: sw          $s2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r18;
    // 0x8000F8AC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8000F8B0: lw          $v0, 0x2C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X2C);
L_8000F8B4:
    // 0x8000F8B4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8000F8B8: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    // 0x8000F8BC: bnel        $v0, $at, L_8000F7A0
    if (ctx->r2 != ctx->r1) {
        // 0x8000F8C0: andi        $v1, $v0, 0xFFF
        ctx->r3 = ctx->r2 & 0XFFF;
            goto L_8000F7A0;
    }
    goto skip_3;
    // 0x8000F8C0: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    skip_3:
L_8000F8C4:
    // 0x8000F8C4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000F8C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000F8CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000F8D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000F8D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F8D8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000F8DC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000F8E0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000F8E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F8E8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000F8EC: jr          $ra
    // 0x8000F8F0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8000F8F0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void ftPikachuSpecialLwStartInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151FA8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80151FAC: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x80151FB0: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80151FB4: jr          $ra
    // 0x80151FB8: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
    return;
    // 0x80151FB8: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
;}
RECOMP_FUNC void mvOpeningYoshiMakeMotionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D40C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D410: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D414: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D418: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D41C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D420: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D424: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D428: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018D42C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018D430: addiu       $t6, $t6, -0x1F40
    ctx->r14 = ADD32(ctx->r14, -0X1F40);
    // 0x8018D434: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D438: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D43C: addiu       $s0, $s0, -0x1DB8
    ctx->r16 = ADD32(ctx->r16, -0X1DB8);
    // 0x8018D440: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D444: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018D448: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D44C: addiu       $t9, $t9, -0x1F24
    ctx->r25 = ADD32(ctx->r25, -0X1F24);
    // 0x8018D450: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8018D454: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8018D458: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D45C: addiu       $s1, $s1, -0x1D98
    ctx->r17 = ADD32(ctx->r17, -0X1D98);
    // 0x8018D460: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8018D464: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8018D468: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D46C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8018D470: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D474: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8018D478: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8018D47C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8018D480: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8018D484: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8018D488: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8018D48C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018D490: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8018D494: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x8018D498: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018D49C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8018D4A0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8018D4A4: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8018D4A8: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8018D4AC: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8018D4B0: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8018D4B4: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8018D4B8: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8018D4BC: jal         0x8010DB2C
    // 0x8018D4C0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D4C0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    after_0:
    // 0x8018D4C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018D4C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D4CC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D4D0: addiu       $v1, $v1, -0x1DC8
    ctx->r3 = ADD32(ctx->r3, -0X1DC8);
    // 0x8018D4D4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D4D8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018D4DC: lw          $s2, 0x74($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D4E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D4EC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018D4F0: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018D4F4: jal         0x80007080
    // 0x8018D4F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D4F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D4FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D500: lwc1        $f6, -0x1DF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DF4);
    // 0x8018D504: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D508: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8018D50C: jal         0x8000B39C
    // 0x8018D510: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D510: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    after_2:
    // 0x8018D514: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D518: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D51C: addiu       $a1, $a1, -0x2CEC
    ctx->r5 = ADD32(ctx->r5, -0X2CEC);
    // 0x8018D520: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    // 0x8018D524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D528: jal         0x80008188
    // 0x8018D52C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018D52C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018D530: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D534: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D538: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D53C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D540: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D544: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D548: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D54C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D550: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D554: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D558: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018D55C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D560: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D564: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D568: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D56C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018D570: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D574: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D578: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D57C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8018D580: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D584: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D588: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8018D58C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D590: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018D594: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018D598: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D59C: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018D5A0: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5A4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5A8: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018D5AC: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5B0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D5B4: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5B8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D5BC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5C0: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5C4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5C8: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5CC: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5D0: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5D4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D5D8: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8018D5DC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D5E0: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8018D5E4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D5E8: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x8018D5EC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D5F0: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D5F4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D5F8: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8018D5FC: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D600: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
    // 0x8018D604: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D608: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D60C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D610: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D614: jr          $ra
    // 0x8018D618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018D618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnVSRecordMakeTableHeadersCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135A8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135A90: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135A94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135A98: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135A9C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80135AA0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80135AA4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80135AA8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135AAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135AB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135AB4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135AB8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135ABC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135AC0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135AC4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135AC8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135ACC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135AD0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135AD4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135AD8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135ADC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80135AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135AE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80135AE8: jal         0x8000B93C
    // 0x80135AEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135AEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135AF0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135AF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135AF8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135AFC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135B00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135B04: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135B08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135B0C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135B10: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80135B14: jal         0x80007080
    // 0x80135B18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135B18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135B1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135B20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135B24: jr          $ra
    // 0x80135B28: nop

    return;
    // 0x80135B28: nop

;}
RECOMP_FUNC void mnCharactersInitRecentMotionKinds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132794: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132798: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013279C: addiu       $a0, $a0, 0x6714
    ctx->r4 = ADD32(ctx->r4, 0X6714);
    // 0x801327A0: addiu       $v1, $v1, 0x6708
    ctx->r3 = ADD32(ctx->r3, 0X6708);
    // 0x801327A4: addiu       $v0, $zero, 0x27
    ctx->r2 = ADD32(0, 0X27);
L_801327A8:
    // 0x801327A8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801327AC: bne         $v1, $a0, L_801327A8
    if (ctx->r3 != ctx->r4) {
        // 0x801327B0: sw          $v0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r2;
            goto L_801327A8;
    }
    // 0x801327B0: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x801327B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801327B8: jr          $ra
    // 0x801327BC: sw          $zero, 0x6714($at)
    MEM_W(0X6714, ctx->r1) = 0;
    return;
    // 0x801327BC: sw          $zero, 0x6714($at)
    MEM_W(0X6714, ctx->r1) = 0;
;}
RECOMP_FUNC void mnModeSelectInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132558: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8013255C: lbu         $v0, 0x4AD1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD1);
    // 0x80132560: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80132564: addiu       $t0, $zero, 0x4650
    ctx->r8 = ADD32(0, 0X4650);
    // 0x80132568: beq         $v0, $at, L_8013259C
    if (ctx->r2 == ctx->r1) {
        // 0x8013256C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8013259C;
    }
    // 0x8013256C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80132570: beq         $v0, $at, L_801325A8
    if (ctx->r2 == ctx->r1) {
        // 0x80132574: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_801325A8;
    }
    // 0x80132574: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80132578: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x8013257C: beq         $v0, $at, L_801325B4
    if (ctx->r2 == ctx->r1) {
        // 0x80132580: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_801325B4;
    }
    // 0x80132580: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80132584: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x80132588: beq         $v0, $at, L_801325C0
    if (ctx->r2 == ctx->r1) {
        // 0x8013258C: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_801325C0;
    }
    // 0x8013258C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80132590: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132594: b           L_801325C8
    // 0x80132598: sw          $zero, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = 0;
        goto L_801325C8;
    // 0x80132598: sw          $zero, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = 0;
L_8013259C:
    // 0x8013259C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325A0: b           L_801325C8
    // 0x801325A4: sw          $zero, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = 0;
        goto L_801325C8;
    // 0x801325A4: sw          $zero, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = 0;
L_801325A8:
    // 0x801325A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325AC: b           L_801325C8
    // 0x801325B0: sw          $t6, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = ctx->r14;
        goto L_801325C8;
    // 0x801325B0: sw          $t6, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = ctx->r14;
L_801325B4:
    // 0x801325B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325B8: b           L_801325C8
    // 0x801325BC: sw          $t7, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = ctx->r15;
        goto L_801325C8;
    // 0x801325BC: sw          $t7, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = ctx->r15;
L_801325C0:
    // 0x801325C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325C4: sw          $t8, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = ctx->r24;
L_801325C8:
    // 0x801325C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801325D0: sw          $zero, 0x2C9C($at)
    MEM_W(0X2C9C, ctx->r1) = 0;
    // 0x801325D4: addiu       $v0, $v0, 0x2CA0
    ctx->r2 = ADD32(ctx->r2, 0X2CA0);
    // 0x801325D8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801325DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325E0: jr          $ra
    // 0x801325E4: sw          $t0, 0x2CA4($at)
    MEM_W(0X2CA4, ctx->r1) = ctx->r8;
    return;
    // 0x801325E4: sw          $t0, 0x2CA4($at)
    MEM_W(0X2CA4, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void mvOpeningDonkeyMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D194: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018D198: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D19C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018D1A0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8018D1A4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8018D1A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018D1AC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018D1B0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D1B4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018D1B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018D1BC: addiu       $t7, $t7, -0x1F3C
    ctx->r15 = ADD32(ctx->r15, -0X1F3C);
    // 0x8018D1C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018D1C4: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x8018D1C8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018D1CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D1D0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8018D1D4: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D1D8: addiu       $t1, $t1, -0x1F30
    ctx->r9 = ADD32(ctx->r9, -0X1F30);
    // 0x8018D1DC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018D1E0: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018D1E4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018D1E8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D1EC: addiu       $t0, $sp, 0x5C
    ctx->r8 = ADD32(ctx->r29, 0X5C);
    // 0x8018D1F0: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8018D1F4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8018D1F8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018D1FC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8018D200: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018D204: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018D208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D20C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D210: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8018D214: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8018D218: jal         0x80009968
    // 0x8018D21C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D21C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    after_0:
    // 0x8018D220: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D224: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018D228: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8018D22C: sw          $v0, -0x1E34($at)
    MEM_W(-0X1E34, ctx->r1) = ctx->r2;
    // 0x8018D230: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018D234: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018D238: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018D23C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D240: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018D244: jal         0x80009DF4
    // 0x8018D248: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D248: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018D24C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8018D250: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
    // 0x8018D254: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x8018D258: beq         $t5, $zero, L_8018D2D4
    if (ctx->r13 == 0) {
        // 0x8018D25C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018D2D4;
    }
    // 0x8018D25C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D260: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018D264: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018D268: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018D26C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D270: addiu       $s2, $s2, -0x1C20
    ctx->r18 = ADD32(ctx->r18, -0X1C20);
    // 0x8018D274: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D278: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
    // 0x8018D27C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8018D280:
    // 0x8018D280: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018D284: jal         0x800CCFDC
    // 0x8018D288: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018D288: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x8018D28C: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D294: and         $t0, $t8, $s3
    ctx->r8 = ctx->r24 & ctx->r19;
    // 0x8018D298: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018D29C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8018D2A0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8018D2A4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D2A8: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8018D2AC: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018D2B0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D2B4: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8018D2B8: jal         0x8018D160
    // 0x8018D2BC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    mvOpeningDonkeyInitName(rdram, ctx);
        goto after_3;
    // 0x8018D2BC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_3:
    // 0x8018D2C0: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8018D2C4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018D2C8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8018D2CC: bnel        $v0, $zero, L_8018D280
    if (ctx->r2 != 0) {
        // 0x8018D2D0: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8018D280;
    }
    goto skip_0;
    // 0x8018D2D0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8018D2D4:
    // 0x8018D2D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D2D8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018D2DC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018D2E0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D2E4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018D2E8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018D2EC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D2F0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8018D2F4: jr          $ra
    // 0x8018D2F8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8018D2F8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ftManagerDestroyFighterWeapons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D799C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x800D79A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800D79A4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800D79A8: beq         $v0, $at, L_800D79D8
    if (ctx->r2 == ctx->r1) {
        // 0x800D79AC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800D79D8;
    }
    // 0x800D79AC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800D79B0: beq         $v0, $at, L_800D79C8
    if (ctx->r2 == ctx->r1) {
        // 0x800D79B4: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_800D79C8;
    }
    // 0x800D79B4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800D79B8: beq         $v0, $at, L_800D79D8
    if (ctx->r2 == ctx->r1) {
        // 0x800D79BC: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_800D79D8;
    }
    // 0x800D79BC: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x800D79C0: bnel        $v0, $at, L_800D79E4
    if (ctx->r2 != ctx->r1) {
        // 0x800D79C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D79E4;
    }
    goto skip_0;
    // 0x800D79C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800D79C8:
    // 0x800D79C8: jal         0x80164650
    // 0x800D79CC: nop

    ftKirbyCopyLinkSpecialNDestroyBoomerang(rdram, ctx);
        goto after_0;
    // 0x800D79CC: nop

    after_0:
    // 0x800D79D0: b           L_800D79E4
    // 0x800D79D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D79E4;
    // 0x800D79D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D79D8:
    // 0x800D79D8: jal         0x801636D0
    // 0x800D79DC: nop

    ftLinkSpecialNDestroyBoomerang(rdram, ctx);
        goto after_1;
    // 0x800D79DC: nop

    after_1:
    // 0x800D79E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D79E4:
    // 0x800D79E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D79E8: jr          $ra
    // 0x800D79EC: nop

    return;
    // 0x800D79EC: nop

;}
RECOMP_FUNC void func_ovl2_801155C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801155C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801155C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801155CC: jal         0x800044B4
    // 0x801155D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syControllerInitRumble(rdram, ctx);
        goto after_0;
    // 0x801155D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801155D4: jal         0x80004494
    // 0x801155D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    syControllerStopRumble(rdram, ctx);
        goto after_1;
    // 0x801155D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801155DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801155E0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801155E4: addiu       $t8, $t8, 0x19F0
    ctx->r24 = ADD32(ctx->r24, 0X19F0);
    // 0x801155E8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801155EC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801155F0: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x801155F4: beql        $t9, $zero, L_80115604
    if (ctx->r25 == 0) {
        // 0x801155F8: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_80115604;
    }
    goto skip_0;
    // 0x801155F8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x801155FC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80115600: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_80115604:
    // 0x80115604: beql        $v0, $zero, L_80115624
    if (ctx->r2 == 0) {
        // 0x80115608: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80115624;
    }
    goto skip_1;
    // 0x80115608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8011560C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
L_80115610:
    // 0x80115610: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x80115614: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80115618: bnel        $v0, $zero, L_80115610
    if (ctx->r2 != 0) {
        // 0x8011561C: lw          $t0, 0x0($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X0);
            goto L_80115610;
    }
    goto skip_2;
    // 0x8011561C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x80115620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80115624:
    // 0x80115624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80115628: jr          $ra
    // 0x8011562C: nop

    return;
    // 0x8011562C: nop

;}
RECOMP_FUNC void func_ovl8_803858B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803858B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803858B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803858B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803858BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803858C0: beq         $a0, $zero, L_80385968
    if (ctx->r4 == 0) {
        // 0x803858C4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80385968;
    }
    // 0x803858C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803858C8: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x803858CC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803858D0: addiu       $t6, $t6, -0x2400
    ctx->r14 = ADD32(ctx->r14, -0X2400);
    // 0x803858D4: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803858D8: addiu       $t7, $t7, -0x2328
    ctx->r15 = ADD32(ctx->r15, -0X2328);
    // 0x803858DC: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x803858E0: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x803858E4: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x803858E8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803858EC: addiu       $t9, $t9, -0x21D0
    ctx->r25 = ADD32(ctx->r25, -0X21D0);
    // 0x803858F0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x803858F4: addiu       $t1, $t1, -0x21A8
    ctx->r9 = ADD32(ctx->r9, -0X21A8);
    // 0x803858F8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x803858FC: sw          $t1, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r9;
    // 0x80385900: lw          $a0, 0xB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XB0);
    // 0x80385904: beql        $a0, $zero, L_80385918
    if (ctx->r4 == 0) {
        // 0x80385908: addiu       $a0, $s0, 0x40
        ctx->r4 = ADD32(ctx->r16, 0X40);
            goto L_80385918;
    }
    goto skip_0;
    // 0x80385908: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    skip_0:
    // 0x8038590C: jal         0x8037B3E4
    // 0x80385910: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x80385910: nop

    after_0:
    // 0x80385914: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
L_80385918:
    // 0x80385918: jal         0x80372554
    // 0x8038591C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80372554(rdram, ctx);
        goto after_1;
    // 0x8038591C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80385920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80385924: jal         0x80382224
    // 0x80385928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80382224(rdram, ctx);
        goto after_2;
    // 0x80385928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8038592C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80385930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80385934: beql        $t2, $zero, L_80385954
    if (ctx->r10 == 0) {
        // 0x80385938: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80385954;
    }
    goto skip_1;
    // 0x80385938: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8038593C: jal         0x8037C30C
    // 0x80385940: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_3;
    // 0x80385940: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x80385944: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80385948: jal         0x803718C4
    // 0x8038594C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_4;
    // 0x8038594C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80385950: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80385954:
    // 0x80385954: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80385958: beql        $t4, $zero, L_8038596C
    if (ctx->r12 == 0) {
        // 0x8038595C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8038596C;
    }
    goto skip_2;
    // 0x8038595C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80385960: jal         0x803717C0
    // 0x80385964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_5;
    // 0x80385964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80385968:
    // 0x80385968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8038596C:
    // 0x8038596C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80385970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80385974: jr          $ra
    // 0x80385978: nop

    return;
    // 0x80385978: nop

;}
RECOMP_FUNC void func_ovl8_80371DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371DD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80371DD4: jr          $ra
    // 0x80371DD8: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    return;
    // 0x80371DD8: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void mvOpeningRoomMakeScene3Cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801336A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801336AC: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x801336B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801336B4: addiu       $v0, $v0, 0x7EC0
    ctx->r2 = ADD32(ctx->r2, 0X7EC0);
    // 0x801336B8: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x801336BC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801336C0: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x801336C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801336C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801336CC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801336D0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x801336D4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801336D8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801336DC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801336E0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801336E4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801336E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801336EC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x801336F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801336F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801336F8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801336FC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133700: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133704: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133708: jal         0x8000B93C
    // 0x8013370C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013370C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133710: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133714: sw          $v0, 0x4CE8($at)
    MEM_W(0X4CE8, ctx->r1) = ctx->r2;
    // 0x80133718: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8013371C: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80133720: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80133724: jal         0x80008CF0
    // 0x80133728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_1;
    // 0x80133728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8013372C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80133730: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80133734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133738: jal         0x80008CF0
    // 0x8013373C: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x8013373C: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    after_2:
    // 0x80133740: jal         0x80133590
    // 0x80133744: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    mvOpeningRoomInitScene3Cameras(rdram, ctx);
        goto after_3;
    // 0x80133744: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_3:
    // 0x80133748: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8013374C: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80133750: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80133754: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x80133758: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8013375C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80133760: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133764: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133768: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013376C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80133770: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80133774: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80133778: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8013377C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80133780: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80133784: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80133788: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013378C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133790: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133794: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133798: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013379C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801337A0: jal         0x8000B93C
    // 0x801337A4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    gcMakeCameraGObj(rdram, ctx);
        goto after_4;
    // 0x801337A4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x801337A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801337AC: sw          $v0, 0x4CEC($at)
    MEM_W(0X4CEC, ctx->r1) = ctx->r2;
    // 0x801337B0: jal         0x80133590
    // 0x801337B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mvOpeningRoomInitScene3Cameras(rdram, ctx);
        goto after_5;
    // 0x801337B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x801337B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801337BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801337C0: jr          $ra
    // 0x801337C4: nop

    return;
    // 0x801337C4: nop

;}
RECOMP_FUNC void mvOpeningKirbyMakePosedWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D970: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D974: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D978: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D97C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D980: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8018D984: jal         0x80009968
    // 0x8018D988: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D988: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D98C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D990: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D994: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D998: addiu       $a1, $a1, -0x2790
    ctx->r5 = ADD32(ctx->r5, -0X2790);
    // 0x8018D99C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D9A0: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8018D9A4: jal         0x80009DF4
    // 0x8018D9A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D9A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D9AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D9B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D9B4: jr          $ra
    // 0x8018D9B8: nop

    return;
    // 0x8018D9B8: nop

;}
RECOMP_FUNC void mnSoundTestMakeStartButtonSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D10: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132D14: lw          $t6, 0x4478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4478);
    // 0x80132D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132D1C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132D24: addiu       $t7, $t7, 0x1D50
    ctx->r15 = ADD32(ctx->r15, 0X1D50);
    // 0x80132D28: jal         0x800CCFDC
    // 0x80132D2C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132D2C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132D30: lui         $at, 0x42F2
    ctx->r1 = S32(0X42F2 << 16);
    // 0x80132D34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132D38: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x80132D3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132D40: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132D44: addiu       $t9, $zero, 0x81
    ctx->r25 = ADD32(0, 0X81);
    // 0x80132D48: addiu       $t0, $zero, 0x6A
    ctx->r8 = ADD32(0, 0X6A);
    // 0x80132D4C: addiu       $t1, $zero, 0x62
    ctx->r9 = ADD32(0, 0X62);
    // 0x80132D50: addiu       $t2, $zero, 0x3B
    ctx->r10 = ADD32(0, 0X3B);
    // 0x80132D54: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80132D58: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x80132D5C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132D60: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80132D64: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80132D68: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80132D6C: sb          $t2, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r10;
    // 0x80132D70: sb          $t3, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r11;
    // 0x80132D74: sb          $t4, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r12;
    // 0x80132D78: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132D7C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132D84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132D88: jr          $ra
    // 0x80132D8C: nop

    return;
    // 0x80132D8C: nop

;}
RECOMP_FUNC void ftSamusSpecialNStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D3EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D3F4: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015D3F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015D3FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015D400: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015D404: nop

    // 0x8015D408: bc1fl       L_8015D458
    if (!c1cs) {
        // 0x8015D40C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015D458;
    }
    goto skip_0;
    // 0x8015D40C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015D410: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x8015D414: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015D418: bnel        $t6, $at, L_8015D434
    if (ctx->r14 != ctx->r1) {
        // 0x8015D41C: lw          $t7, 0xB18($v0)
        ctx->r15 = MEM_W(ctx->r2, 0XB18);
            goto L_8015D434;
    }
    goto skip_1;
    // 0x8015D41C: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
    skip_1:
    // 0x8015D420: jal         0x8015DAA8
    // 0x8015D424: nop

    ftSamusSpecialAirNEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D424: nop

    after_0:
    // 0x8015D428: b           L_8015D458
    // 0x8015D42C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015D458;
    // 0x8015D42C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D430: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
L_8015D434:
    // 0x8015D434: beq         $t7, $zero, L_8015D44C
    if (ctx->r15 == 0) {
        // 0x8015D438: nop
    
            goto L_8015D44C;
    }
    // 0x8015D438: nop

    // 0x8015D43C: jal         0x8015DA60
    // 0x8015D440: nop

    ftSamusSpecialNEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015D440: nop

    after_1:
    // 0x8015D444: b           L_8015D458
    // 0x8015D448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015D458;
    // 0x8015D448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015D44C:
    // 0x8015D44C: jal         0x8015D734
    // 0x8015D450: nop

    ftSamusSpecialNLoopSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015D450: nop

    after_2:
    // 0x8015D454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015D458:
    // 0x8015D458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D45C: jr          $ra
    // 0x8015D460: nop

    return;
    // 0x8015D460: nop

;}
RECOMP_FUNC void mnVSRecordGetCharacterID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013232C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132330: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80132334: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80132338: beq         $a0, $at, L_8013237C
    if (ctx->r4 == ctx->r1) {
        // 0x8013233C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8013237C;
    }
    // 0x8013233C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80132340: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80132344: beq         $a0, $at, L_8013236C
    if (ctx->r4 == ctx->r1) {
        // 0x80132348: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_8013236C;
    }
    // 0x80132348: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x8013234C: beq         $a0, $at, L_80132364
    if (ctx->r4 == ctx->r1) {
        // 0x80132350: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80132364;
    }
    // 0x80132350: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80132354: beq         $a0, $at, L_80132374
    if (ctx->r4 == ctx->r1) {
        // 0x80132358: nop
    
            goto L_80132374;
    }
    // 0x80132358: nop

    // 0x8013235C: b           L_80132384
    // 0x80132360: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
        goto L_80132384;
    // 0x80132360: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
L_80132364:
    // 0x80132364: jr          $ra
    // 0x80132368: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    return;
    // 0x80132368: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_8013236C:
    // 0x8013236C: jr          $ra
    // 0x80132370: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80132370: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80132374:
    // 0x80132374: jr          $ra
    // 0x80132378: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80132378: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_8013237C:
    // 0x8013237C: jr          $ra
    // 0x80132380: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    return;
    // 0x80132380: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_80132384:
    // 0x80132384: bne         $at, $zero, L_80132394
    if (ctx->r1 != 0) {
        // 0x80132388: slti        $at, $v1, 0x5B
        ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
            goto L_80132394;
    }
    // 0x80132388: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
    // 0x8013238C: bne         $at, $zero, L_8013239C
    if (ctx->r1 != 0) {
        // 0x80132390: addiu       $v0, $v1, -0x41
        ctx->r2 = ADD32(ctx->r3, -0X41);
            goto L_8013239C;
    }
    // 0x80132390: addiu       $v0, $v1, -0x41
    ctx->r2 = ADD32(ctx->r3, -0X41);
L_80132394:
    // 0x80132394: jr          $ra
    // 0x80132398: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    return;
    // 0x80132398: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_8013239C:
    // 0x8013239C: jr          $ra
    // 0x801323A0: nop

    return;
    // 0x801323A0: nop

;}
RECOMP_FUNC void mnMessageApplyUnlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801321A8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801321AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801321B0: addiu       $t6, $t6, 0x259C
    ctx->r14 = ADD32(ctx->r14, 0X259C);
    // 0x801321B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801321B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x801321BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x801321C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801321C4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x801321C8: lw          $v1, 0x2658($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2658);
    // 0x801321CC: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x801321D0: lbu         $t9, 0x457($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X457);
    // 0x801321D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801321D8: sllv        $t1, $t0, $v1
    ctx->r9 = S32(ctx->r8 << (ctx->r3 & 31));
    // 0x801321DC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x801321E0: sb          $t2, 0x457($a0)
    MEM_B(0X457, ctx->r4) = ctx->r10;
    // 0x801321E4: beq         $v1, $zero, L_80132204
    if (ctx->r3 == 0) {
        // 0x801321E8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80132204;
    }
    // 0x801321E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801321EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801321F0: beq         $v0, $at, L_80132204
    if (ctx->r2 == ctx->r1) {
        // 0x801321F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132204;
    }
    // 0x801321F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801321F8: beq         $v0, $at, L_80132204
    if (ctx->r2 == ctx->r1) {
        // 0x801321FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80132204;
    }
    // 0x801321FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132200: bne         $v0, $at, L_80132224
    if (ctx->r2 != ctx->r1) {
        // 0x80132204: addu        $t3, $a1, $v1
        ctx->r11 = ADD32(ctx->r5, ctx->r3);
            goto L_80132224;
    }
L_80132204:
    // 0x80132204: addu        $t3, $a1, $v1
    ctx->r11 = ADD32(ctx->r5, ctx->r3);
    // 0x80132208: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x8013220C: lhu         $t4, 0x458($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X458);
    // 0x80132210: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132214: sllv        $t6, $t5, $v0
    ctx->r14 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x80132218: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8013221C: sh          $t7, 0x458($a0)
    MEM_H(0X458, ctx->r4) = ctx->r15;
    // 0x80132220: sb          $v0, 0x456($a0)
    MEM_B(0X456, ctx->r4) = ctx->r2;
L_80132224:
    // 0x80132224: jal         0x800D45F4
    // 0x80132228: nop

    lbBackupWrite(rdram, ctx);
        goto after_0;
    // 0x80132228: nop

    after_0:
    // 0x8013222C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132230: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132234: jr          $ra
    // 0x80132238: nop

    return;
    // 0x80132238: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152724: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015272C: jal         0x80152718
    // 0x80152730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftPikachuSpecialLwClearProcDamage(rdram, ctx);
        goto after_0;
    // 0x80152730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80152734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80152738: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x8015273C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80152740: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80152744: jal         0x800E6F24
    // 0x80152748: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152748: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015274C: jal         0x800E0830
    // 0x80152750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80152750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80152754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152758: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015275C: jr          $ra
    // 0x80152760: nop

    return;
    // 0x80152760: nop

;}
RECOMP_FUNC void ftCommonPassiveStandSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144700: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80144704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80144708: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014470C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80144710: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80144714: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80144718: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8014471C: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x80144720: bnel        $t8, $at, L_80144734
    if (ctx->r24 != ctx->r1) {
        // 0x80144724: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80144734;
    }
    goto skip_0;
    // 0x80144724: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80144728: jal         0x800DEE98
    // 0x8014472C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8014472C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x80144730: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80144734:
    // 0x80144734: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80144738: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014473C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80144740: jal         0x800E6F24
    // 0x80144744: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80144744: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80144748: jal         0x800E9CE8
    // 0x8014474C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftParamVelDamageTransferGround(rdram, ctx);
        goto after_2;
    // 0x8014474C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80144750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80144754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80144758: jr          $ra
    // 0x8014475C: nop

    return;
    // 0x8014475C: nop

;}
RECOMP_FUNC void efManagerFoxReflectorMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100FA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80100FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100FB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100FB4: jal         0x800FDB1C
    // 0x80100FB8: addiu       $a0, $a0, -0x1F14
    ctx->r4 = ADD32(ctx->r4, -0X1F14);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x80100FB8: addiu       $a0, $a0, -0x1F14
    ctx->r4 = ADD32(ctx->r4, -0X1F14);
    after_0:
    // 0x80100FBC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80100FC0: bne         $v0, $zero, L_80100FD0
    if (ctx->r2 != 0) {
        // 0x80100FC4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80100FD0;
    }
    // 0x80100FC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100FC8: b           L_80100FF8
    // 0x80100FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100FF8;
    // 0x80100FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100FD0:
    // 0x80100FD0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80100FD4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80100FD8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80100FDC: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80100FE0: lw          $t6, 0x84($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X84);
    // 0x80100FE4: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80100FE8: lw          $t7, 0x8E8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8E8);
    // 0x80100FEC: sw          $t7, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->r15;
    // 0x80100FF0: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80100FF4: sw          $t9, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r25;
L_80100FF8:
    // 0x80100FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101000: jr          $ra
    // 0x80101004: nop

    return;
    // 0x80101004: nop

;}
RECOMP_FUNC void ifCommonBattleEndPlaySoundQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011379C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801137A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801137A4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801137A8: addiu       $s2, $s2, 0x1829
    ctx->r18 = ADD32(ctx->r18, 0X1829);
    // 0x801137AC: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x801137B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801137B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801137B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801137BC: blez        $t6, L_801137EC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801137C0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801137EC;
    }
    // 0x801137C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801137C4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801137C8: addiu       $s1, $s1, 0x1808
    ctx->r17 = ADD32(ctx->r17, 0X1808);
L_801137CC:
    // 0x801137CC: jal         0x800269C0
    // 0x801137D0: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x801137D0: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    after_0:
    // 0x801137D4: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x801137D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801137DC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x801137E0: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801137E4: bne         $at, $zero, L_801137CC
    if (ctx->r1 != 0) {
        // 0x801137E8: nop
    
            goto L_801137CC;
    }
    // 0x801137E8: nop

L_801137EC:
    // 0x801137EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801137F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801137F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801137F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801137FC: jr          $ra
    // 0x80113800: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80113800: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonHeavyGetProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145F10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80145F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145F18: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80145F1C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80145F20: jal         0x800DDDA8
    // 0x80145F24: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80145F24: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80145F28: bne         $v0, $zero, L_80145F64
    if (ctx->r2 != 0) {
        // 0x80145F2C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80145F64;
    }
    // 0x80145F2C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80145F30: lw          $t6, 0x84C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X84C);
    // 0x80145F34: beq         $t6, $zero, L_80145F5C
    if (ctx->r14 == 0) {
        // 0x80145F38: nop
    
            goto L_80145F5C;
    }
    // 0x80145F38: nop

    // 0x80145F3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80145F40: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80145F44: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80145F48: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80145F4C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80145F50: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80145F54: jal         0x80172AEC
    // 0x80145F58: lw          $a0, 0x84C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_1;
    // 0x80145F58: lw          $a0, 0x84C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84C);
    after_1:
L_80145F5C:
    // 0x80145F5C: jal         0x8013F9E0
    // 0x80145F60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonFallSetStatus(rdram, ctx);
        goto after_2;
    // 0x80145F60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_80145F64:
    // 0x80145F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80145F68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80145F6C: jr          $ra
    // 0x80145F70: nop

    return;
    // 0x80145F70: nop

;}
RECOMP_FUNC void ftCommonFallSpecialProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80143734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143738: jal         0x8014019C
    // 0x8014373C: nop

    ftCommonJumpAerialCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014373C: nop

    after_0:
    // 0x80143740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80143744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80143748: jr          $ra
    // 0x8014374C: nop

    return;
    // 0x8014374C: nop

;}
RECOMP_FUNC void syUtilsRandIntRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001899C: jal         0x80018910
    // 0x800189A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsRandUShort(rdram, ctx);
        goto after_0;
    // 0x800189A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800189A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800189A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800189AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800189B0: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800189B4: mflo        $v0
    ctx->r2 = lo;
    // 0x800189B8: bgez        $v0, L_800189C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800189BC: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_800189C8;
    }
    // 0x800189BC: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x800189C0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800189C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
L_800189C8:
    // 0x800189C8: sra         $v0, $at, 16
    ctx->r2 = S32(SIGNED(ctx->r1) >> 16);
    // 0x800189CC: jr          $ra
    // 0x800189D0: nop

    return;
    // 0x800189D0: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckSelectFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135C04: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80135C08: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80135C0C: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x80135C10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135C14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80135C18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135C1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80135C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135C24: beq         $t6, $at, L_80135C34
    if (ctx->r14 == ctx->r1) {
        // 0x80135C28: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80135C34;
    }
    // 0x80135C28: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80135C2C: b           L_80135C78
    // 0x80135C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80135C78;
    // 0x80135C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135C34:
    // 0x80135C34: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x80135C38: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80135C3C: beq         $t7, $at, L_80135C6C
    if (ctx->r15 == ctx->r1) {
        // 0x80135C40: nop
    
            goto L_80135C6C;
    }
    // 0x80135C40: nop

    // 0x80135C44: jal         0x80132384
    // 0x80135C48: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    mnPlayers1PGameSelectFighterPuck(rdram, ctx);
        goto after_0;
    // 0x80135C48: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80135C4C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80135C50: lw          $t8, -0x708C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X708C);
    // 0x80135C54: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80135C58: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80135C5C: addiu       $t9, $t8, 0x1E
    ctx->r25 = ADD32(ctx->r24, 0X1E);
    // 0x80135C60: sw          $t9, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r25;
    // 0x80135C64: b           L_80135C78
    // 0x80135C68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80135C78;
    // 0x80135C68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135C6C:
    // 0x80135C6C: jal         0x800269C0
    // 0x80135C70: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80135C70: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_1:
    // 0x80135C74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135C78:
    // 0x80135C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135C80: jr          $ra
    // 0x80135C84: nop

    return;
    // 0x80135C84: nop

;}
RECOMP_FUNC void mvOpeningStandoffMakeLightningFlashCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132384: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132388: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013238C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132390: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132394: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80132398: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013239C: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x801323A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801323A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801323A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801323AC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801323B0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801323B4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801323B8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801323BC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801323C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801323C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801323C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801323CC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801323D0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801323D4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801323D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801323DC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801323E0: jal         0x8000B93C
    // 0x801323E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801323E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801323E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801323EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801323F0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801323F4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801323F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801323FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132400: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132404: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132408: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013240C: jal         0x80007080
    // 0x80132410: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132410: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132414: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132418: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013241C: jr          $ra
    // 0x80132420: nop

    return;
    // 0x80132420: nop

;}
RECOMP_FUNC void mnNoControllerMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6490: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D6494: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800D6498: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D649C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x800D64A0: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x800D64A4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800D64A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D64AC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800D64B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D64B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800D64B8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800D64BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800D64C0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800D64C4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800D64C8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800D64CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D64D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D64D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800D64D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D64DC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800D64E0: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x800D64E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D64E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D64EC: jal         0x8000B93C
    // 0x800D64F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x800D64F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800D64F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800D64F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D64FC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800D6500: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x800D6504: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x800D6508: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D650C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800D6510: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800D6514: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x800D6518: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x800D651C: jal         0x80007080
    // 0x800D6520: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x800D6520: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800D6524: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D6528: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800D652C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800D6530: jr          $ra
    // 0x800D6534: nop

    return;
    // 0x800D6534: nop

;}

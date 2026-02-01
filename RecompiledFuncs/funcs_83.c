#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void unref_80006AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AD0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80006AD4: lw          $t6, 0x54BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X54BC);
    // 0x80006AD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80006ADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006AE0: bne         $t6, $at, L_80006AF0
    if (ctx->r14 != ctx->r1) {
        // 0x80006AE4: nop
    
            goto L_80006AF0;
    }
    // 0x80006AE4: nop

    // 0x80006AE8: jr          $ra
    // 0x80006AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006AF0:
    // 0x80006AF0: jr          $ra
    // 0x80006AF4: nop

    return;
    // 0x80006AF4: nop

;}
RECOMP_FUNC void ifCommonBattlePauseUpdateInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801142EC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801142F0: lbu         $t6, 0x17E4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X17E4);
    // 0x801142F4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801142F8: lbu         $a3, 0x1828($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X1828);
    // 0x801142FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80114300: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80114304: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80114308: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8011430C: addiu       $t8, $t8, 0x5228
    ctx->r24 = ADD32(ctx->r24, 0X5228);
    // 0x80114310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114314: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80114318: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8011431C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114320: bne         $a3, $at, L_8011445C
    if (ctx->r7 != ctx->r1) {
        // 0x80114324: lhu         $a2, 0x2($a1)
        ctx->r6 = MEM_HU(ctx->r5, 0X2);
            goto L_8011445C;
    }
    // 0x80114324: lhu         $a2, 0x2($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X2);
    // 0x80114328: lb          $v0, 0x8($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X8);
    // 0x8011432C: lb          $a0, 0x9($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X9);
    // 0x80114330: bgez        $v0, L_80114340
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80114334: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80114340;
    }
    // 0x80114334: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80114338: b           L_80114340
    // 0x8011433C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80114340;
    // 0x8011433C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80114340:
    // 0x80114340: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80114344: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80114348: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8011434C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80114350: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80114354: nop

    // 0x80114358: bc1f        L_801143C8
    if (!c1cs) {
        // 0x8011435C: nop
    
            goto L_801143C8;
    }
    // 0x8011435C: nop

    // 0x80114360: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80114364: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114368: lwc1        $f2, 0xC94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XC94);
    // 0x8011436C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80114370: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114374: lwc1        $f16, 0xC98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC98);
    // 0x80114378: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8011437C: addiu       $v1, $v1, 0x1468
    ctx->r3 = ADD32(ctx->r3, 0X1468);
    // 0x80114380: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80114384: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80114388: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011438C: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80114390: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80114394: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80114398: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8011439C: nop

    // 0x801143A0: bc1f        L_801143B0
    if (!c1cs) {
        // 0x801143A4: nop
    
            goto L_801143B0;
    }
    // 0x801143A4: nop

    // 0x801143A8: b           L_801143C8
    // 0x801143AC: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
        goto L_801143C8;
    // 0x801143AC: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_801143B0:
    // 0x801143B0: lwc1        $f2, 0xC9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XC9C);
    // 0x801143B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801143B8: nop

    // 0x801143BC: bc1f        L_801143C8
    if (!c1cs) {
        // 0x801143C0: nop
    
            goto L_801143C8;
    }
    // 0x801143C0: nop

    // 0x801143C4: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_801143C8:
    // 0x801143C8: bgez        $a0, L_801143D8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801143CC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_801143D8;
    }
    // 0x801143CC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x801143D0: b           L_801143D8
    // 0x801143D4: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
        goto L_801143D8;
    // 0x801143D4: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
L_801143D8:
    // 0x801143D8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x801143DC: nop

    // 0x801143E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801143E4: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x801143E8: nop

    // 0x801143EC: bc1f        L_8011445C
    if (!c1cs) {
        // 0x801143F0: nop
    
            goto L_8011445C;
    }
    // 0x801143F0: nop

    // 0x801143F4: mtc1        $a0, $f16
    ctx->f16.u32l = ctx->r4;
    // 0x801143F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801143FC: lwc1        $f2, 0xCA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XCA0);
    // 0x80114400: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80114404: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114408: lwc1        $f18, 0xCA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XCA4);
    // 0x8011440C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80114410: addiu       $v0, $v0, 0x1464
    ctx->r2 = ADD32(ctx->r2, 0X1464);
    // 0x80114414: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80114418: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8011441C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114420: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80114424: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80114428: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8011442C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80114430: nop

    // 0x80114434: bc1f        L_80114444
    if (!c1cs) {
        // 0x80114438: nop
    
            goto L_80114444;
    }
    // 0x80114438: nop

    // 0x8011443C: b           L_8011445C
    // 0x80114440: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
        goto L_8011445C;
    // 0x80114440: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_80114444:
    // 0x80114444: lwc1        $f2, 0xCA8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XCA8);
    // 0x80114448: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8011444C: nop

    // 0x80114450: bc1f        L_8011445C
    if (!c1cs) {
        // 0x80114454: nop
    
            goto L_8011445C;
    }
    // 0x80114454: nop

    // 0x80114458: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8011445C:
    // 0x8011445C: beq         $a2, $zero, L_80114560
    if (ctx->r6 == 0) {
        // 0x80114460: andi        $t9, $a2, 0x1000
        ctx->r25 = ctx->r6 & 0X1000;
            goto L_80114560;
    }
    // 0x80114460: andi        $t9, $a2, 0x1000
    ctx->r25 = ctx->r6 & 0X1000;
    // 0x80114464: beq         $t9, $zero, L_801144A4
    if (ctx->r25 == 0) {
        // 0x80114468: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801144A4;
    }
    // 0x80114468: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8011446C: beq         $a3, $zero, L_8011448C
    if (ctx->r7 == 0) {
        // 0x80114470: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8011448C;
    }
    // 0x80114470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114474: jal         0x8010D00C
    // 0x80114478: nop

    gmCameraSetStatusPrev(rdram, ctx);
        goto after_0;
    // 0x80114478: nop

    after_0:
    // 0x8011447C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80114480: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114484: b           L_80114490
    // 0x80114488: sh          $t0, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = ctx->r8;
        goto L_80114490;
    // 0x80114488: sh          $t0, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = ctx->r8;
L_8011448C:
    // 0x8011448C: sh          $zero, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = 0;
L_80114490:
    // 0x80114490: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80114494: lw          $t2, 0x50E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E8);
    // 0x80114498: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8011449C: b           L_80114578
    // 0x801144A0: sb          $t1, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r9;
        goto L_80114578;
    // 0x801144A0: sb          $t1, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r9;
L_801144A4:
    // 0x801144A4: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x801144A8: andi        $t8, $a0, 0x20
    ctx->r24 = ctx->r4 & 0X20;
    // 0x801144AC: andi        $t3, $v1, 0x8000
    ctx->r11 = ctx->r3 & 0X8000;
    // 0x801144B0: beq         $t3, $zero, L_80114514
    if (ctx->r11 == 0) {
        // 0x801144B4: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_80114514;
    }
    // 0x801144B4: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x801144B8: beq         $t4, $zero, L_80114514
    if (ctx->r12 == 0) {
        // 0x801144BC: andi        $t5, $v1, 0x10
        ctx->r13 = ctx->r3 & 0X10;
            goto L_80114514;
    }
    // 0x801144BC: andi        $t5, $v1, 0x10
    ctx->r13 = ctx->r3 & 0X10;
    // 0x801144C0: beq         $t5, $zero, L_80114514
    if (ctx->r13 == 0) {
        // 0x801144C4: andi        $t6, $v1, 0x2000
        ctx->r14 = ctx->r3 & 0X2000;
            goto L_80114514;
    }
    // 0x801144C4: andi        $t6, $v1, 0x2000
    ctx->r14 = ctx->r3 & 0X2000;
    // 0x801144C8: beq         $t6, $zero, L_80114514
    if (ctx->r14 == 0) {
        // 0x801144CC: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80114514;
    }
    // 0x801144CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801144D0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801144D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801144D8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801144DC: sb          $t7, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r15;
    // 0x801144E0: addiu       $a0, $a0, 0x3638
    ctx->r4 = ADD32(ctx->r4, 0X3638);
    // 0x801144E4: jal         0x8000AF58
    // 0x801144E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcFuncGObjAll(rdram, ctx);
        goto after_1;
    // 0x801144E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x801144EC: jal         0x800266A0
    // 0x801144F0: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_2;
    // 0x801144F0: nop

    after_2:
    // 0x801144F4: jal         0x801157EC
    // 0x801144F8: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_3;
    // 0x801144F8: nop

    after_3:
    // 0x801144FC: jal         0x80113F9C
    // 0x80114500: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ifCommonBattlePauseSetGObjFlagsAll(rdram, ctx);
        goto after_4;
    // 0x80114500: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80114504: jal         0x801142B4
    // 0x80114508: nop

    ifCommonBattleInterfaceProcSet(rdram, ctx);
        goto after_5;
    // 0x80114508: nop

    after_5:
    // 0x8011450C: b           L_8011457C
    // 0x80114510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8011457C;
    // 0x80114510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80114514:
    // 0x80114514: beq         $t8, $zero, L_80114560
    if (ctx->r24 == 0) {
        // 0x80114518: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80114560;
    }
    // 0x80114518: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8011451C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80114520: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80114524: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80114528: bne         $t9, $at, L_80114560
    if (ctx->r25 != ctx->r1) {
        // 0x8011452C: nop
    
            goto L_80114560;
    }
    // 0x8011452C: nop

    // 0x80114530: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x80114534: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80114538: beq         $t0, $at, L_80114560
    if (ctx->r8 == ctx->r1) {
        // 0x8011453C: nop
    
            goto L_80114560;
    }
    // 0x8011453C: nop

    // 0x80114540: jal         0x800266A0
    // 0x80114544: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_6;
    // 0x80114544: nop

    after_6:
    // 0x80114548: jal         0x801157EC
    // 0x8011454C: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_7;
    // 0x8011454C: nop

    after_7:
    // 0x80114550: jal         0x80005C74
    // 0x80114554: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_8;
    // 0x80114554: nop

    after_8:
    // 0x80114558: b           L_8011457C
    // 0x8011455C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8011457C;
    // 0x8011455C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80114560:
    // 0x80114560: beq         $a3, $zero, L_80114578
    if (ctx->r7 == 0) {
        // 0x80114564: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80114578;
    }
    // 0x80114564: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80114568: jal         0x8010CECC
    // 0x8011456C: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    gmCameraRunFuncCamera(rdram, ctx);
        goto after_9;
    // 0x8011456C: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    after_9:
    // 0x80114570: jal         0x80104CD0
    // 0x80114574: nop

    grWallpaperRunProcessAll(rdram, ctx);
        goto after_10;
    // 0x80114574: nop

    after_10:
L_80114578:
    // 0x80114578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8011457C:
    // 0x8011457C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114580: jr          $ra
    // 0x80114584: nop

    return;
    // 0x80114584: nop

;}
RECOMP_FUNC void mnPlayersVSPuckAdjustPortraitEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139460: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80139464: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80139468: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8013946C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80139470: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80139474: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80139478: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x8013947C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80139480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80139484: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80139488: lw          $a0, 0x48($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X48);
    // 0x8013948C: jal         0x80132168
    // 0x80139490: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mnPlayersVSGetPortrait(rdram, ctx);
        goto after_0;
    // 0x80139490: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80139494: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80139498: bne         $at, $zero, L_801394A8
    if (ctx->r1 != 0) {
        // 0x8013949C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_801394A8;
    }
    // 0x8013949C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801394A0: b           L_801394AC
    // 0x801394A4: addiu       $a0, $v0, -0x6
    ctx->r4 = ADD32(ctx->r2, -0X6);
        goto L_801394AC;
    // 0x801394A4: addiu       $a0, $v0, -0x6
    ctx->r4 = ADD32(ctx->r2, -0X6);
L_801394A8:
    // 0x801394A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_801394AC:
    // 0x801394AC: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801394B0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x801394B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801394B8: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x801394BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801394C0: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x801394C4: addiu       $t9, $t8, 0x19
    ctx->r25 = ADD32(ctx->r24, 0X19);
    // 0x801394C8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801394CC: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801394D0: bne         $at, $zero, L_801394E0
    if (ctx->r1 != 0) {
        // 0x801394D4: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801394E0;
    }
    // 0x801394D4: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801394D8: b           L_801394E4
    // 0x801394DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_801394E4;
    // 0x801394DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801394E0:
    // 0x801394E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801394E4:
    // 0x801394E4: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x801394E8: lwc1        $f6, 0x90($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X90);
    // 0x801394EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801394F0: lw          $v0, 0x74($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X74);
    // 0x801394F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801394F8: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x801394FC: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80139500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139504: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80139508: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8013950C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80139510: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80139514: lwc1        $f6, 0x94($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X94);
    // 0x80139518: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013951C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80139520: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80139524: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80139528: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8013952C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80139530: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139534: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80139538: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8013953C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80139540: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80139544: addiu       $t2, $t1, 0x24
    ctx->r10 = ADD32(ctx->r9, 0X24);
    // 0x80139548: bc1f        L_80139564
    if (!c1cs) {
        // 0x8013954C: add.s       $f2, $f10, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_80139564;
    }
    // 0x8013954C: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80139550: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80139554: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80139558: nop

    // 0x8013955C: div.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80139560: swc1        $f8, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f8.u32l;
L_80139564:
    // 0x80139564: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80139568: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013956C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80139570: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80139574: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80139578: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8013957C: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80139580: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80139584: nop

    // 0x80139588: bc1fl       L_801395AC
    if (!c1cs) {
        // 0x8013958C: mtc1        $t2, $f6
        ctx->f6.u32l = ctx->r10;
            goto L_801395AC;
    }
    goto skip_0;
    // 0x8013958C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    skip_0:
    // 0x80139590: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80139594: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80139598: nop

    // 0x8013959C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801395A0: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801395A4: swc1        $f4, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f4.u32l;
    // 0x801395A8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
L_801395AC:
    // 0x801395AC: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x801395B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801395B4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801395B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801395BC: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801395C0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801395C4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801395C8: nop

    // 0x801395CC: bc1fl       L_801395E4
    if (!c1cs) {
        // 0x801395D0: sub.s       $f12, $f6, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
            goto L_801395E4;
    }
    goto skip_1;
    // 0x801395D0: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
    skip_1:
    // 0x801395D4: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x801395D8: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x801395DC: swc1        $f10, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f10.u32l;
    // 0x801395E0: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
L_801395E4:
    // 0x801395E4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x801395E8: nop

    // 0x801395EC: bc1fl       L_80139610
    if (!c1cs) {
        // 0x801395F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80139610;
    }
    goto skip_2;
    // 0x801395F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801395F4: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x801395F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801395FC: nop

    // 0x80139600: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80139604: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80139608: swc1        $f6, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f6.u32l;
    // 0x8013960C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80139610:
    // 0x80139610: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80139614: jr          $ra
    // 0x80139618: nop

    return;
    // 0x80139618: nop

;}
RECOMP_FUNC void wpLinkBoomerangCheckOwnerCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D35C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016D360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D364: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016D368: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8016D36C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8016D370: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8016D374: lbu         $t7, 0x2A2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2A2);
    // 0x8016D378: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8016D37C: beql        $t8, $zero, L_8016D400
    if (ctx->r24 == 0) {
        // 0x8016D380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016D400;
    }
    goto skip_0;
    // 0x8016D380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8016D384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016D388: nop

    // 0x8016D38C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8016D390: nop

    // 0x8016D394: bc1fl       L_8016D400
    if (!c1cs) {
        // 0x8016D398: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016D400;
    }
    goto skip_1;
    // 0x8016D398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8016D39C: lw          $a0, 0x29C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X29C);
    // 0x8016D3A0: beq         $a0, $zero, L_8016D3EC
    if (ctx->r4 == 0) {
        // 0x8016D3A4: nop
    
            goto L_8016D3EC;
    }
    // 0x8016D3A4: nop

    // 0x8016D3A8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016D3AC: lh          $t0, 0x192($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X192);
    // 0x8016D3B0: bgez        $t0, L_8016D3EC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8016D3B4: nop
    
            goto L_8016D3EC;
    }
    // 0x8016D3B4: nop

    // 0x8016D3B8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8016D3BC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8016D3C0: beq         $v1, $at, L_8016D3D0
    if (ctx->r3 == ctx->r1) {
        // 0x8016D3C4: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8016D3D0;
    }
    // 0x8016D3C4: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8016D3C8: bne         $v1, $at, L_8016D3E0
    if (ctx->r3 != ctx->r1) {
        // 0x8016D3CC: nop
    
            goto L_8016D3E0;
    }
    // 0x8016D3CC: nop

L_8016D3D0:
    // 0x8016D3D0: jal         0x80164A40
    // 0x8016D3D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftKirbyCopyLinkSpecialNGetSetStatus(rdram, ctx);
        goto after_0;
    // 0x8016D3D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8016D3D8: b           L_8016D3EC
    // 0x8016D3DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
        goto L_8016D3EC;
    // 0x8016D3DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_8016D3E0:
    // 0x8016D3E0: jal         0x80163ACC
    // 0x8016D3E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftLinkSpecialNGetSetStatus(rdram, ctx);
        goto after_1;
    // 0x8016D3E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8016D3E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_8016D3EC:
    // 0x8016D3EC: jal         0x8016D31C
    // 0x8016D3F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    wpLinkBoomerangClearGObjs(rdram, ctx);
        goto after_2;
    // 0x8016D3F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8016D3F4: jal         0x8016800C
    // 0x8016D3F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    wpMainDestroyWeapon(rdram, ctx);
        goto after_3;
    // 0x8016D3F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8016D3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016D400:
    // 0x8016D400: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016D404: jr          $ra
    // 0x8016D408: nop

    return;
    // 0x8016D408: nop

;}
RECOMP_FUNC void mvOpeningDonkeyFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE48: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DE4C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DE50: addiu       $v1, $v1, -0x1C18
    ctx->r3 = ADD32(ctx->r3, -0X1C18);
    // 0x8018DE54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DE58: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE5C: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DE60: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018DE64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DE68: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018DE6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8018DE70: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DE74: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018DE78:
    // 0x8018DE78: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DE7C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DE80: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DE84: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DE88: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DE8C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DE90: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DE94: bne         $t6, $t0, L_8018DE78
    if (ctx->r14 != ctx->r8) {
        // 0x8018DE98: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DE78;
    }
    // 0x8018DE98: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DE9C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DEA0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DEA4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DEA8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8018DEAC: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8018DEB0: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
    // 0x8018DEB4: sb          $t3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r11;
    // 0x8018DEB8: sb          $a1, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r5;
    // 0x8018DEBC: jal         0x8018D0C0
    // 0x8018DEC0: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    mvOpeningDonkeySetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DEC0: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    after_0:
    // 0x8018DEC4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DEC8: addiu       $a1, $a1, -0x2280
    ctx->r5 = ADD32(ctx->r5, -0X2280);
    // 0x8018DECC: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018DED0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018DED4: jal         0x80009968
    // 0x8018DED8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018DED8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DEDC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8018DEE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DEE4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DEE8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DEEC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DEF0: jal         0x8000B9FC
    // 0x8018DEF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DEF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018DEF8: jal         0x8018DE3C
    // 0x8018DEFC: nop

    mvOpeningDonkeyInitVars(rdram, ctx);
        goto after_3;
    // 0x8018DEFC: nop

    after_3:
    // 0x8018DF00: jal         0x80115890
    // 0x8018DF04: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018DF04: nop

    after_4:
    // 0x8018DF08: jal         0x800EC130
    // 0x8018DF0C: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018DF0C: nop

    after_5:
    // 0x8018DF10: jal         0x800FC284
    // 0x8018DF14: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018DF14: nop

    after_6:
    // 0x8018DF18: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DF1C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DF20: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DF24: jal         0x8010E598
    // 0x8018DF28: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018DF28: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018DF2C: jal         0x8010DB54
    // 0x8018DF30: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018DF30: nop

    after_8:
    // 0x8018DF34: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DF38: jal         0x800D7194
    // 0x8018DF3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8018DF3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018DF40: jal         0x801654B0
    // 0x8018DF44: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_10;
    // 0x8018DF44: nop

    after_10:
    // 0x8018DF48: jal         0x8016DEA0
    // 0x8018DF4C: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018DF4C: nop

    after_11:
    // 0x8018DF50: jal         0x800FD300
    // 0x8018DF54: nop

    efManagerInitEffects(rdram, ctx);
        goto after_12;
    // 0x8018DF54: nop

    after_12:
    // 0x8018DF58: jal         0x800D786C
    // 0x8018DF5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8018DF5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x8018DF60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DF64: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8018DF68: jal         0x80004980
    // 0x8018DF6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_14;
    // 0x8018DF6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x8018DF70: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DF74: jal         0x8018DB50
    // 0x8018DF78: sw          $v0, -0x1E24($at)
    MEM_W(-0X1E24, ctx->r1) = ctx->r2;
    mvOpeningDonkeyMakeNameCamera(rdram, ctx);
        goto after_15;
    // 0x8018DF78: sw          $v0, -0x1E24($at)
    MEM_W(-0X1E24, ctx->r1) = ctx->r2;
    after_15:
    // 0x8018DF7C: jal         0x8018DCD8
    // 0x8018DF80: nop

    mvOpeningDonkeyMakePosedWallpaperCamera(rdram, ctx);
        goto after_16;
    // 0x8018DF80: nop

    after_16:
    // 0x8018DF84: jal         0x8018DBF0
    // 0x8018DF88: nop

    mvOpeningDonkeyMakePosedFighterCamera(rdram, ctx);
        goto after_17;
    // 0x8018DF88: nop

    after_17:
    // 0x8018DF8C: jal         0x8018D194
    // 0x8018DF90: nop

    mvOpeningDonkeyMakeName(rdram, ctx);
        goto after_18;
    // 0x8018DF90: nop

    after_18:
    // 0x8018DF94: jal         0x8000092C
    // 0x8018DF98: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x8018DF98: nop

    after_19:
    // 0x8018DF9C: sltiu       $at, $v0, 0x645
    ctx->r1 = ctx->r2 < 0X645 ? 1 : 0;
    // 0x8018DFA0: beql        $at, $zero, L_8018DFC0
    if (ctx->r1 == 0) {
        // 0x8018DFA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018DFC0;
    }
    goto skip_0;
    // 0x8018DFA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018DFA8:
    // 0x8018DFA8: jal         0x8000092C
    // 0x8018DFAC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x8018DFAC: nop

    after_20:
    // 0x8018DFB0: sltiu       $at, $v0, 0x645
    ctx->r1 = ctx->r2 < 0X645 ? 1 : 0;
    // 0x8018DFB4: bne         $at, $zero, L_8018DFA8
    if (ctx->r1 != 0) {
        // 0x8018DFB8: nop
    
            goto L_8018DFA8;
    }
    // 0x8018DFB8: nop

    // 0x8018DFBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DFC0:
    // 0x8018DFC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018DFC4: jr          $ra
    // 0x8018DFC8: nop

    return;
    // 0x8018DFC8: nop

;}
RECOMP_FUNC void itMarumineCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183914: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80183918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018391C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80183920: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80183924: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80183928: lwc1        $f6, 0x350($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X350);
    // 0x8018392C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80183930: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80183934: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80183938: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8018393C: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80183940: lwc1        $f16, 0x354($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X354);
    // 0x80183944: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80183948: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x8018394C: lwc1        $f4, -0x310C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X310C);
    // 0x80183950: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80183954: nop

    // 0x80183958: bc1fl       L_80183998
    if (!c1cs) {
        // 0x8018395C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80183998;
    }
    goto skip_0;
    // 0x8018395C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80183960: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80183964: jal         0x8017275C
    // 0x80183968: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_0;
    // 0x80183968: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018396C: jal         0x8017279C
    // 0x80183970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x80183970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80183974: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80183978: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018397C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80183980: swc1        $f0, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->f0.u32l;
    // 0x80183984: jal         0x801837A0
    // 0x80183988: swc1        $f0, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->f0.u32l;
    itMarumineExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_2;
    // 0x80183988: swc1        $f0, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->f0.u32l;
    after_2:
    // 0x8018398C: jal         0x800269C0
    // 0x80183990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80183990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80183994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80183998:
    // 0x80183998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018399C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801839A0: jr          $ra
    // 0x801839A4: nop

    return;
    // 0x801839A4: nop

;}
RECOMP_FUNC void lbCommonInitCameraPersp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD4C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD4C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD4C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CD4CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CD4D0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800CD4D4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800CD4D8: jal         0x80008CF0
    // 0x800CD4DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcAddXObjForCamera(rdram, ctx);
        goto after_0;
    // 0x800CD4DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CD4E0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800CD4E4: addiu       $t6, $t6, -0x4788
    ctx->r14 = ADD32(ctx->r14, -0X4788);
    // 0x800CD4E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CD4EC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800CD4F0: sw          $t8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r24;
    // 0x800CD4F4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800CD4F8: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800CD4FC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800CD500: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x800CD504: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800CD508: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x800CD50C: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x800CD510: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x800CD514: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800CD518: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x800CD51C: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x800CD520: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x800CD524: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x800CD528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD52C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD530: jr          $ra
    // 0x800CD534: nop

    return;
    // 0x800CD534: nop

;}
RECOMP_FUNC void mnSoundTestMusicProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324FC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132500: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132504: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132508: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013250C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80132510: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132514: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132518: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013251C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80132520: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132524: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80132528: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8013252C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132530: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132534: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x80132538: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013253C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132540: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132544: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132548: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x8013254C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132550: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132554: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132558: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8013255C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132560: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x80132564: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132568: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013256C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132570: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132574: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132578: lw          $t8, 0x4310($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4310);
    // 0x8013257C: lw          $t6, 0x4330($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4330);
    // 0x80132580: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80132584: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132588: lw          $t8, 0x4320($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4320);
    // 0x8013258C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80132590: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80132594: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80132598: or          $a0, $t6, $t7
    ctx->r4 = ctx->r14 | ctx->r15;
    // 0x8013259C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x801325A0: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801325A4: andi        $t7, $t6, 0xF800
    ctx->r15 = ctx->r14 & 0XF800;
    // 0x801325A8: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x801325AC: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x801325B0: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x801325B4: sra         $t6, $a0, 13
    ctx->r14 = S32(SIGNED(ctx->r4) >> 13);
    // 0x801325B8: andi        $t8, $t6, 0x7C0
    ctx->r24 = ctx->r14 & 0X7C0;
    // 0x801325BC: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x801325C0: sra         $t6, $a0, 10
    ctx->r14 = S32(SIGNED(ctx->r4) >> 10);
    // 0x801325C4: andi        $t9, $t6, 0x3E
    ctx->r25 = ctx->r14 & 0X3E;
    // 0x801325C8: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x801325CC: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x801325D0: or          $t6, $t1, $t8
    ctx->r14 = ctx->r9 | ctx->r24;
    // 0x801325D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801325D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801325DC: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801325E0: lui         $t9, 0xF61C
    ctx->r25 = S32(0XF61C << 16);
    // 0x801325E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801325E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801325EC: ori         $t9, $t9, 0xE4
    ctx->r25 = ctx->r25 | 0XE4;
    // 0x801325F0: ori         $t8, $t8, 0x80E0
    ctx->r24 = ctx->r24 | 0X80E0;
    // 0x801325F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801325F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801325FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132600: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80132604: lui         $t7, 0xF61C
    ctx->r15 = S32(0XF61C << 16);
    // 0x80132608: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013260C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132610: ori         $t7, $t7, 0x180
    ctx->r15 = ctx->r15 | 0X180;
    // 0x80132614: ori         $t9, $t9, 0x817C
    ctx->r25 = ctx->r25 | 0X817C;
    // 0x80132618: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013261C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132620: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132624: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132628: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8013262C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132630: jr          $ra
    // 0x80132634: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x80132634: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void mnVSResultsCheckExit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E18: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131E1C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80131E20: lw          $t7, -0x63E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X63E8);
    // 0x80131E24: lw          $t6, -0x6488($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6488);
    // 0x80131E28: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80131E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131E30: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80131E34: bne         $at, $zero, L_80131EA8
    if (ctx->r1 != 0) {
        // 0x80131E38: nop
    
            goto L_80131EA8;
    }
    // 0x80131E38: nop

    // 0x80131E3C: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x80131E40: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80131E44: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x80131E48: beq         $t9, $zero, L_80131E58
    if (ctx->r25 == 0) {
        // 0x80131E4C: nop
    
            goto L_80131E58;
    }
    // 0x80131E4C: nop

    // 0x80131E50: jr          $ra
    // 0x80131E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131E58:
    // 0x80131E58: lhu         $t0, 0x5234($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X5234);
    // 0x80131E5C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80131E60: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x80131E64: beq         $t1, $zero, L_80131E74
    if (ctx->r9 == 0) {
        // 0x80131E68: nop
    
            goto L_80131E74;
    }
    // 0x80131E68: nop

    // 0x80131E6C: jr          $ra
    // 0x80131E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131E74:
    // 0x80131E74: lhu         $t2, 0x523E($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X523E);
    // 0x80131E78: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80131E7C: andi        $t3, $t2, 0x1000
    ctx->r11 = ctx->r10 & 0X1000;
    // 0x80131E80: beq         $t3, $zero, L_80131E90
    if (ctx->r11 == 0) {
        // 0x80131E84: nop
    
            goto L_80131E90;
    }
    // 0x80131E84: nop

    // 0x80131E88: jr          $ra
    // 0x80131E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131E90:
    // 0x80131E90: lhu         $t4, 0x5248($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X5248);
    // 0x80131E94: andi        $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 & 0X1000;
    // 0x80131E98: beq         $t5, $zero, L_80131EA8
    if (ctx->r13 == 0) {
        // 0x80131E9C: nop
    
            goto L_80131EA8;
    }
    // 0x80131E9C: nop

    // 0x80131EA0: jr          $ra
    // 0x80131EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131EA8:
    // 0x80131EA8: jr          $ra
    // 0x80131EAC: nop

    return;
    // 0x80131EAC: nop

;}
RECOMP_FUNC void itSwordThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174C98: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80174C9C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174CA0: addiu       $a3, $a3, 0x4BE4
    ctx->r7 = ADD32(ctx->r7, 0X4BE4);
    // 0x80174CA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80174CA8: jal         0x80173B24
    // 0x80174CAC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174CAC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80174CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174CB8: jr          $ra
    // 0x80174CBC: nop

    return;
    // 0x80174CBC: nop

;}
RECOMP_FUNC void itHeartWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017472C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174730: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80174734: jal         0x801735A0
    // 0x80174738: addiu       $a1, $a1, 0x47B4
    ctx->r5 = ADD32(ctx->r5, 0X47B4);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80174738: addiu       $a1, $a1, 0x47B4
    ctx->r5 = ADD32(ctx->r5, 0X47B4);
    after_0:
    // 0x8017473C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174748: jr          $ra
    // 0x8017474C: nop

    return;
    // 0x8017474C: nop

;}
RECOMP_FUNC void func_ovl8_803732B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803732B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803732B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803732B8: jal         0x80373160
    // 0x803732BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_ovl8_80373160(rdram, ctx);
        goto after_0;
    // 0x803732BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x803732C0: beq         $v0, $zero, L_803732F4
    if (ctx->r2 == 0) {
        // 0x803732C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803732F4;
    }
    // 0x803732C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x803732C8: beql        $v0, $zero, L_803732F8
    if (ctx->r2 == 0) {
        // 0x803732CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803732F8;
    }
    goto skip_0;
    // 0x803732CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x803732D0: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_803732D4:
    // 0x803732D4: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803732D8: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x803732DC: lh          $t6, 0x148($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X148);
    // 0x803732E0: jalr        $t9
    // 0x803732E4: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803732E4: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_1:
    // 0x803732E8: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
    // 0x803732EC: bnel        $s0, $zero, L_803732D4
    if (ctx->r16 != 0) {
        // 0x803732F0: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_803732D4;
    }
    goto skip_1;
    // 0x803732F0: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_1:
L_803732F4:
    // 0x803732F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803732F8:
    // 0x803732F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803732FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80373300: jr          $ra
    // 0x80373304: nop

    return;
    // 0x80373304: nop

;}
RECOMP_FUNC void ftCommonRebirthCommonUpdateHaloWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D1D4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D1D8: lw          $v1, 0xB30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB30);
    // 0x8013D1DC: beq         $v1, $zero, L_8013D1E8
    if (ctx->r3 == 0) {
        // 0x8013D1E0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8013D1E8;
    }
    // 0x8013D1E0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8013D1E4: sw          $t6, 0xB30($v0)
    MEM_W(0XB30, ctx->r2) = ctx->r14;
L_8013D1E8:
    // 0x8013D1E8: lw          $v1, 0xB38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB38);
    // 0x8013D1EC: beq         $v1, $zero, L_8013D1F8
    if (ctx->r3 == 0) {
        // 0x8013D1F0: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8013D1F8;
    }
    // 0x8013D1F0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8013D1F4: sw          $t7, 0xB38($v0)
    MEM_W(0XB38, ctx->r2) = ctx->r15;
L_8013D1F8:
    // 0x8013D1F8: jr          $ra
    // 0x8013D1FC: nop

    return;
    // 0x8013D1FC: nop

;}
RECOMP_FUNC void func_ovl8_80384AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384AF0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80384AF4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80384AF8: sh          $zero, 0x3E($a0)
    MEM_H(0X3E, ctx->r4) = 0;
    // 0x80384AFC: beq         $a1, $zero, L_80384B30
    if (ctx->r5 == 0) {
        // 0x80384B00: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80384B30;
    }
    // 0x80384B00: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80384B04: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80384B08: beql        $t6, $zero, L_80384B34
    if (ctx->r14 == 0) {
        // 0x80384B0C: lw          $v0, 0x30($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X30);
            goto L_80384B34;
    }
    goto skip_0;
    // 0x80384B0C: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    skip_0:
    // 0x80384B10: lh          $t7, 0x3E($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X3E);
L_80384B14:
    // 0x80384B14: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80384B18: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80384B1C: beq         $v0, $zero, L_80384B30
    if (ctx->r2 == 0) {
        // 0x80384B20: sh          $t8, 0x3E($a2)
        MEM_H(0X3E, ctx->r6) = ctx->r24;
            goto L_80384B30;
    }
    // 0x80384B20: sh          $t8, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = ctx->r24;
    // 0x80384B24: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80384B28: bnel        $t9, $zero, L_80384B14
    if (ctx->r25 != 0) {
        // 0x80384B2C: lh          $t7, 0x3E($a2)
        ctx->r15 = MEM_H(ctx->r6, 0X3E);
            goto L_80384B14;
    }
    goto skip_1;
    // 0x80384B2C: lh          $t7, 0x3E($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X3E);
    skip_1:
L_80384B30:
    // 0x80384B30: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
L_80384B34:
    // 0x80384B34: sw          $a3, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r7;
    // 0x80384B38: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80384B3C: lh          $t0, 0x50($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X50);
    // 0x80384B40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80384B44: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80384B48: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    // 0x80384B4C: jalr        $t9
    // 0x80384B50: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384B50: nop

    after_0:
    // 0x80384B54: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80384B58: lh          $t2, 0x3E($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X3E);
    // 0x80384B5C: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80384B60: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80384B64: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x80384B68: lh          $t1, 0x58($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X58);
    // 0x80384B6C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80384B70: addu        $a0, $t1, $a2
    ctx->r4 = ADD32(ctx->r9, ctx->r6);
    // 0x80384B74: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80384B78: jalr        $t9
    // 0x80384B7C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80384B7C: nop

    after_1:
    // 0x80384B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384B88: jr          $ra
    // 0x80384B8C: nop

    return;
    // 0x80384B8C: nop

;}
RECOMP_FUNC void mvOpeningStandoffLightningFlashProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321D8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801321DC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801321E0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801321E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801321E8: lui         $a0, 0xE700
    ctx->r4 = S32(0XE700 << 16);
    // 0x801321EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801321F0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801321F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801321F8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x801321FC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80132200: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80132204: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80132208: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013220C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80132210: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80132214: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132218: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013221C: lw          $a3, 0x29D0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X29D0);
    // 0x80132220: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80132224: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x80132228: slti        $at, $a3, 0x14
    ctx->r1 = SIGNED(ctx->r7) < 0X14 ? 1 : 0;
    // 0x8013222C: bne         $at, $zero, L_80132238
    if (ctx->r1 != 0) {
        // 0x80132230: slti        $at, $a3, 0x17
        ctx->r1 = SIGNED(ctx->r7) < 0X17 ? 1 : 0;
            goto L_80132238;
    }
    // 0x80132230: slti        $at, $a3, 0x17
    ctx->r1 = SIGNED(ctx->r7) < 0X17 ? 1 : 0;
    // 0x80132234: bne         $at, $zero, L_8013225C
    if (ctx->r1 != 0) {
        // 0x80132238: slti        $at, $a3, 0x96
        ctx->r1 = SIGNED(ctx->r7) < 0X96 ? 1 : 0;
            goto L_8013225C;
    }
L_80132238:
    // 0x80132238: slti        $at, $a3, 0x96
    ctx->r1 = SIGNED(ctx->r7) < 0X96 ? 1 : 0;
    // 0x8013223C: bne         $at, $zero, L_80132248
    if (ctx->r1 != 0) {
        // 0x80132240: slti        $at, $a3, 0x99
        ctx->r1 = SIGNED(ctx->r7) < 0X99 ? 1 : 0;
            goto L_80132248;
    }
    // 0x80132240: slti        $at, $a3, 0x99
    ctx->r1 = SIGNED(ctx->r7) < 0X99 ? 1 : 0;
    // 0x80132244: bne         $at, $zero, L_8013225C
    if (ctx->r1 != 0) {
        // 0x80132248: slti        $at, $a3, 0x105
        ctx->r1 = SIGNED(ctx->r7) < 0X105 ? 1 : 0;
            goto L_8013225C;
    }
L_80132248:
    // 0x80132248: slti        $at, $a3, 0x105
    ctx->r1 = SIGNED(ctx->r7) < 0X105 ? 1 : 0;
    // 0x8013224C: bne         $at, $zero, L_8013227C
    if (ctx->r1 != 0) {
        // 0x80132250: slti        $at, $a3, 0x108
        ctx->r1 = SIGNED(ctx->r7) < 0X108 ? 1 : 0;
            goto L_8013227C;
    }
    // 0x80132250: slti        $at, $a3, 0x108
    ctx->r1 = SIGNED(ctx->r7) < 0X108 ? 1 : 0;
    // 0x80132254: beql        $at, $zero, L_80132280
    if (ctx->r1 == 0) {
        // 0x80132258: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_80132280;
    }
    goto skip_0;
    // 0x80132258: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_8013225C:
    // 0x8013225C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80132260: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80132264: addiu       $t4, $zero, -0xC0
    ctx->r12 = ADD32(0, -0XC0);
    // 0x80132268: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013226C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80132270: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80132274: b           L_80132298
    // 0x80132278: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_80132298;
    // 0x80132278: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8013227C:
    // 0x8013227C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_80132280:
    // 0x80132280: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80132284: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x80132288: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8013228C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80132290: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132294: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80132298:
    // 0x80132298: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8013229C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801322A0: lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // 0x801322A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801322A8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801322AC: ori         $t3, $t3, 0xF6FB
    ctx->r11 = ctx->r11 | 0XF6FB;
    // 0x801322B0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801322B4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801322B8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801322BC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801322C0: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x801322C4: ori         $t5, $t5, 0x41C8
    ctx->r13 = ctx->r13 | 0X41C8;
    // 0x801322C8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801322CC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801322D0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801322D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801322D8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801322DC: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801322E0: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x801322E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801322E8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801322EC: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x801322F0: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x801322F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801322F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801322FC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80132300: lui         $t4, 0x55
    ctx->r12 = S32(0X55 << 16);
    // 0x80132304: ori         $t4, $t4, 0x2078
    ctx->r12 = ctx->r12 | 0X2078;
    // 0x80132308: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013230C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80132310: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132314: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80132318: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8013231C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80132320: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80132324: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80132328: jr          $ra
    // 0x8013232C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    return;
    // 0x8013232C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void ftCommonCaptureWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A980: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8014A984: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014A988: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014A98C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8014A990: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8014A994: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014A998: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8014A99C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8014A9A0: lw          $v0, 0x844($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X844);
    // 0x8014A9A4: addiu       $t7, $s0, 0xF8
    ctx->r15 = ADD32(ctx->r16, 0XF8);
    // 0x8014A9A8: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x8014A9AC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8014A9B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8014A9B4: addiu       $a3, $s0, 0xF4
    ctx->r7 = ADD32(ctx->r16, 0XF4);
    // 0x8014A9B8: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    // 0x8014A9BC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8014A9C0: jal         0x800F3DD8
    // 0x8014A9C4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_0;
    // 0x8014A9C4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014A9C8: beq         $v0, $zero, L_8014A9F4
    if (ctx->r2 == 0) {
        // 0x8014A9CC: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_8014A9F4;
    }
    // 0x8014A9CC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8014A9D0: lw          $t8, 0xEC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XEC);
    // 0x8014A9D4: sw          $t8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->r24;
    // 0x8014A9D8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8014A9DC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8014A9E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014A9E4: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8014A9E8: sw          $zero, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = 0;
    // 0x8014A9EC: b           L_8014AA44
    // 0x8014A9F0: sb          $zero, 0x148($s0)
    MEM_B(0X148, ctx->r16) = 0;
        goto L_8014AA44;
    // 0x8014A9F0: sb          $zero, 0x148($s0)
    MEM_B(0X148, ctx->r16) = 0;
L_8014A9F4:
    // 0x8014A9F4: lw          $t9, 0x44($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X44);
    // 0x8014A9F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014A9FC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8014AA00: bne         $t9, $at, L_8014AA1C
    if (ctx->r25 != ctx->r1) {
        // 0x8014AA04: nop
    
            goto L_8014AA1C;
    }
    // 0x8014AA04: nop

    // 0x8014AA08: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    // 0x8014AA0C: jal         0x800F4408
    // 0x8014AA10: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x8014AA10: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8014AA14: b           L_8014AA28
    // 0x8014AA18: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
        goto L_8014AA28;
    // 0x8014AA18: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
L_8014AA1C:
    // 0x8014AA1C: jal         0x800F4428
    // 0x8014AA20: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_2;
    // 0x8014AA20: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    after_2:
    // 0x8014AA24: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
L_8014AA28:
    // 0x8014AA28: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8014AA2C: jal         0x800DE324
    // 0x8014AA30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    mpCommonSetFighterProjectFloor(rdram, ctx);
        goto after_3;
    // 0x8014AA30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x8014AA34: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014AA38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8014AA3C: sw          $t0, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r8;
    // 0x8014AA40: sb          $t1, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r9;
L_8014AA44:
    // 0x8014AA44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014AA48: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014AA4C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8014AA50: jr          $ra
    // 0x8014AA54: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8014AA54: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mvOpeningPortraitsMakePortraitsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801324D4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801324D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801324DC: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801324E0: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801324E4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801324E8: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x801324EC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801324F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801324F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801324F8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801324FC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132500: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132504: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132508: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013250C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132510: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132514: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132518: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013251C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132520: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132528: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013252C: jal         0x8000B93C
    // 0x80132530: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132530: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132534: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132538: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013253C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132540: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132548: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013254C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132550: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132554: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132558: jal         0x80007080
    // 0x8013255C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013255C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132560: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132564: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132568: jr          $ra
    // 0x8013256C: nop

    return;
    // 0x8013256C: nop

;}
RECOMP_FUNC void itHarisenThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801752F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801752FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175300: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80175304: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80175308: addiu       $a3, $a3, 0x51F4
    ctx->r7 = ADD32(ctx->r7, 0X51F4);
    // 0x8017530C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80175310: jal         0x80173B24
    // 0x80175314: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80175314: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80175318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017531C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175320: jr          $ra
    // 0x80175324: nop

    return;
    // 0x80175324: nop

;}
RECOMP_FUNC void lbParticleEjectGeneratorDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3C54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D3C58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D3C5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D3C60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D3C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3C68: lbu         $t6, 0xF($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XF);
    // 0x800D3C6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D3C70: bnel        $t6, $at, L_800D3CCC
    if (ctx->r14 != ctx->r1) {
        // 0x800D3C74: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D3CCC;
    }
    goto skip_0;
    // 0x800D3C74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800D3C78: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x800D3C7C: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800D3C80: addiu       $s2, $s2, 0x639C
    ctx->r18 = ADD32(ctx->r18, 0X639C);
    // 0x800D3C84: beql        $s1, $zero, L_800D3CCC
    if (ctx->r17 == 0) {
        // 0x800D3C88: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D3CCC;
    }
    goto skip_1;
    // 0x800D3C88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_800D3C8C:
    // 0x800D3C8C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800D3C90: beq         $a0, $zero, L_800D3CB8
    if (ctx->r4 == 0) {
        // 0x800D3C94: nop
    
            goto L_800D3CB8;
    }
    // 0x800D3C94: nop

L_800D3C98:
    // 0x800D3C98: lw          $t7, 0x48($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X48);
    // 0x800D3C9C: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800D3CA0: bne         $s1, $t7, L_800D3CB0
    if (ctx->r17 != ctx->r15) {
        // 0x800D3CA4: nop
    
            goto L_800D3CB0;
    }
    // 0x800D3CA4: nop

    // 0x800D3CA8: jal         0x800D3884
    // 0x800D3CAC: nop

    lbParticleEjectGenerator(rdram, ctx);
        goto after_0;
    // 0x800D3CAC: nop

    after_0:
L_800D3CB0:
    // 0x800D3CB0: bne         $s0, $zero, L_800D3C98
    if (ctx->r16 != 0) {
        // 0x800D3CB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D3C98;
    }
    // 0x800D3CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D3CB8:
    // 0x800D3CB8: jal         0x8000BAA0
    // 0x800D3CBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_1;
    // 0x800D3CBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800D3CC0: bne         $v0, $zero, L_800D3C8C
    if (ctx->r2 != 0) {
        // 0x800D3CC4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800D3C8C;
    }
    // 0x800D3CC4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D3CC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D3CCC:
    // 0x800D3CCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3CD0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3CD4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D3CD8: jr          $ra
    // 0x800D3CDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D3CDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sc1PTrainingModeMakeSpeedDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E774: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018E778: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018E77C: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018E780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E784: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018E788: jal         0x80009968
    // 0x8018E78C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018E78C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018E790: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E794: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018E798: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018E79C: sw          $v0, 0xBA0($at)
    MEM_W(0XBA0, ctx->r1) = ctx->r2;
    // 0x8018E7A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018E7A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018E7A8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018E7AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E7B0: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018E7B4: jal         0x80009DF4
    // 0x8018E7B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018E7B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018E7BC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E7C0: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018E7C4: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x8018E7C8: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x8018E7CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018E7D0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018E7D4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018E7D8: jal         0x800CCFDC
    // 0x8018E7DC: lw          $a1, 0x6C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X6C);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018E7DC: lw          $a1, 0x6C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X6C);
    after_2:
    // 0x8018E7E0: lui         $at, 0x438A
    ctx->r1 = S32(0X438A << 16);
    // 0x8018E7E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E7E8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018E7EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E7F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E7F4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8018E7F8: jal         0x8018E300
    // 0x8018E7FC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    sc1PTrainingModeInitSpriteEnvColors(rdram, ctx);
        goto after_3;
    // 0x8018E7FC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x8018E800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E804: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018E808: jr          $ra
    // 0x8018E80C: nop

    return;
    // 0x8018E80C: nop

;}
RECOMP_FUNC void func_ovl8_803758B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803758B0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803758B4: lw          $t6, -0x1034($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1034);
    // 0x803758B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803758BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803758C0: lw          $v1, 0x10($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X10);
    // 0x803758C4: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803758C8: lw          $t9, 0xEC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XEC);
    // 0x803758CC: lh          $t7, 0xE8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE8);
    // 0x803758D0: jalr        $t9
    // 0x803758D4: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803758D4: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_0:
    // 0x803758D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803758DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803758E0: jr          $ra
    // 0x803758E4: nop

    return;
    // 0x803758E4: nop

;}
RECOMP_FUNC void func_ovl51_8018D668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D668: jr          $ra
    // 0x8018D66C: nop

    return;
    // 0x8018D66C: nop

;}
RECOMP_FUNC void ftMainSetHitHazard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E1E8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800E1E90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E1E94: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800E1E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E1E9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E1EA0: beq         $a3, $at, L_800E1EBC
    if (ctx->r7 == ctx->r1) {
        // 0x800E1EA4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800E1EBC;
    }
    // 0x800E1EA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E1EA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E1EAC: beq         $a3, $at, L_800E1ED0
    if (ctx->r7 == ctx->r1) {
        // 0x800E1EB0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800E1ED0;
    }
    // 0x800E1EB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E1EB4: b           L_800E1EDC
    // 0x800E1EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E1EDC;
    // 0x800E1EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E1EBC:
    // 0x800E1EBC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E1EC0: jal         0x80143BC4
    // 0x800E1EC4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftCommonTwisterSetStatus(rdram, ctx);
        goto after_0;
    // 0x800E1EC4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800E1EC8: b           L_800E1EDC
    // 0x800E1ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E1EDC;
    // 0x800E1ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E1ED0:
    // 0x800E1ED0: jal         0x80143F30
    // 0x800E1ED4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftCommonTaruCannSetStatus(rdram, ctx);
        goto after_1;
    // 0x800E1ED4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800E1ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E1EDC:
    // 0x800E1EDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E1EE0: jr          $ra
    // 0x800E1EE4: nop

    return;
    // 0x800E1EE4: nop

;}
RECOMP_FUNC void mnSoundTestFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133964: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80133968: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013396C: addiu       $t8, $t8, 0x4218
    ctx->r24 = ADD32(ctx->r24, 0X4218);
    // 0x80133970: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80133974: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80133978: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x8013397C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133980: jr          $ra
    // 0x80133984: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80133984: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void itStarRodFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177EEC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80177EF0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80177EF4: addiu       $a3, $a3, 0x7F18
    ctx->r7 = ADD32(ctx->r7, 0X7F18);
    // 0x80177EF8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80177EFC: jal         0x80173B24
    // 0x80177F00: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80177F00: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80177F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177F10: jr          $ra
    // 0x80177F14: nop

    return;
    // 0x80177F14: nop

;}
RECOMP_FUNC void sc1PIntroMakeVSFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133398: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8013339C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801333A0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801333A4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801333A8: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x801333AC: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x801333B0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801333B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801333B8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x801333BC: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x801333C0: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
L_801333C4:
    // 0x801333C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801333C8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801333CC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801333D0: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801333D4: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801333D8: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801333DC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801333E0: bne         $t7, $t0, L_801333C4
    if (ctx->r15 != ctx->r8) {
        // 0x801333E4: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801333C4;
    }
    // 0x801333E4: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801333E8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801333EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801333F0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801333F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801333F8: jal         0x800EC0EC
    // 0x801333FC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x801333FC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x80133400: sb          $v0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r2;
    // 0x80133404: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80133408: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8013340C: addiu       $t2, $t2, 0x3170
    ctx->r10 = ADD32(ctx->r10, 0X3170);
    // 0x80133410: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80133414: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80133418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013341C: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x80133420: sb          $zero, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = 0;
    // 0x80133424: sb          $t3, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r11;
    // 0x80133428: sb          $t4, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r12;
    // 0x8013342C: beq         $s1, $at, L_8013343C
    if (ctx->r17 == ctx->r1) {
        // 0x80133430: sw          $t1, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r9;
            goto L_8013343C;
    }
    // 0x80133430: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x80133434: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80133438: bne         $s1, $at, L_80133444
    if (ctx->r17 != ctx->r1) {
        // 0x8013343C: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_80133444;
    }
L_8013343C:
    // 0x8013343C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80133440: sb          $t5, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r13;
L_80133444:
    // 0x80133444: jal         0x800D7F3C
    // 0x80133448: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80133448: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8013344C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80133450: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80133454: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133458: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8013345C: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x80133460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133464: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133468: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8013346C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80133470: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80133474: jal         0x800E6F24
    // 0x80133478: nop

    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80133478: nop

    after_2:
    // 0x8013347C: jal         0x8000DF34
    // 0x80133480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x80133480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80133484: jal         0x8000B39C
    // 0x80133488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEndProcessAll(rdram, ctx);
        goto after_4;
    // 0x80133488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013348C: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    // 0x80133490: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80133494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133498: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8013349C: sw          $t7, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->r15;
    // 0x801334A0: lbu         $a1, 0x83($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X83);
    // 0x801334A4: jal         0x8000A0D0
    // 0x801334A8: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    gcMoveGObjDL(rdram, ctx);
        goto after_5;
    // 0x801334A8: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    after_5:
    // 0x801334AC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801334B0: addiu       $a1, $a1, 0x2F84
    ctx->r5 = ADD32(ctx->r5, 0X2F84);
    // 0x801334B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801334B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801334BC: jal         0x80008188
    // 0x801334C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x801334C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x801334C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801334C8: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x801334CC: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x801334D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801334D4: swc1        $f2, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f2.u32l;
    // 0x801334D8: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x801334DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801334E0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801334E4: swc1        $f2, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f2.u32l;
    // 0x801334E8: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x801334EC: swc1        $f2, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f2.u32l;
    // 0x801334F0: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x801334F4: swc1        $f0, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f0.u32l;
    // 0x801334F8: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x801334FC: swc1        $f0, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f0.u32l;
    // 0x80133500: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80133504: beq         $s1, $at, L_80133538
    if (ctx->r17 == ctx->r1) {
        // 0x80133508: swc1        $f0, 0x48($t3)
        MEM_W(0X48, ctx->r11) = ctx->f0.u32l;
            goto L_80133538;
    }
    // 0x80133508: swc1        $f0, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f0.u32l;
    // 0x8013350C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133510: beq         $s1, $at, L_80133538
    if (ctx->r17 == ctx->r1) {
        // 0x80133514: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80133538;
    }
    // 0x80133514: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80133518: beq         $s1, $at, L_80133538
    if (ctx->r17 == ctx->r1) {
        // 0x8013351C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80133538;
    }
    // 0x8013351C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133520: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80133524: jal         0x8013312C
    // 0x80133528: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    sc1PIntroGetVSFighterPositionZ(rdram, ctx);
        goto after_7;
    // 0x80133528: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    after_7:
    // 0x8013352C: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80133530: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x80133534: swc1        $f0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f0.u32l;
L_80133538:
    // 0x80133538: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8013353C: bne         $s1, $at, L_80133568
    if (ctx->r17 != ctx->r1) {
        // 0x80133540: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80133568;
    }
    // 0x80133540: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80133544: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80133548: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013354C: lbu         $t0, 0xA88($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0XA88);
    // 0x80133550: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80133554: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133558: ori         $t7, $t0, 0x40
    ctx->r15 = ctx->r8 | 0X40;
    // 0x8013355C: sb          $t7, 0xA88($v1)
    MEM_B(0XA88, ctx->r3) = ctx->r15;
    // 0x80133560: swc1        $f6, 0xA74($v1)
    MEM_W(0XA74, ctx->r3) = ctx->f6.u32l;
    // 0x80133564: swc1        $f8, 0xA78($v1)
    MEM_W(0XA78, ctx->r3) = ctx->f8.u32l;
L_80133568:
    // 0x80133568: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013356C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80133570: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80133574: jr          $ra
    // 0x80133578: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80133578: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void ftCommonLGunShootProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801471C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801471C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801471C8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801471CC: jal         0x800DDE84
    // 0x801471D0: addiu       $a1, $a1, 0x7258
    ctx->r5 = ADD32(ctx->r5, 0X7258);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x801471D0: addiu       $a1, $a1, 0x7258
    ctx->r5 = ADD32(ctx->r5, 0X7258);
    after_0:
    // 0x801471D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801471D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801471DC: jr          $ra
    // 0x801471E0: nop

    return;
    // 0x801471E0: nop

;}
RECOMP_FUNC void gcRunGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A40C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A410: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A414: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A418: sw          $t6, -0x478C($at)
    MEM_W(-0X478C, ctx->r1) = ctx->r14;
    // 0x8000A41C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A424: sw          $a0, 0x6A54($at)
    MEM_W(0X6A54, ctx->r1) = ctx->r4;
    // 0x8000A428: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000A42C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8000A430: jalr        $t9
    // 0x8000A434: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8000A434: nop

    after_0:
    // 0x8000A438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000A43C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A440: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000A444: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x8000A448: sw          $zero, 0x6A54($at)
    MEM_W(0X6A54, ctx->r1) = 0;
    // 0x8000A44C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A450: addiu       $v1, $v1, 0x6A64
    ctx->r3 = ADD32(ctx->r3, 0X6A64);
    // 0x8000A454: sw          $zero, -0x478C($at)
    MEM_W(-0X478C, ctx->r1) = 0;
    // 0x8000A458: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A45C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A460: beql        $v0, $zero, L_8000A48C
    if (ctx->r2 == 0) {
        // 0x8000A464: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000A48C;
    }
    goto skip_0;
    // 0x8000A464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000A468: beql        $v0, $at, L_8000A47C
    if (ctx->r2 == ctx->r1) {
        // 0x8000A46C: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8000A47C;
    }
    goto skip_1;
    // 0x8000A46C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_1:
    // 0x8000A470: b           L_8000A488
    // 0x8000A474: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8000A488;
    // 0x8000A474: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000A478: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000A47C:
    // 0x8000A47C: jal         0x80009A84
    // 0x8000A480: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x8000A480: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8000A484: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_8000A488:
    // 0x8000A488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000A48C:
    // 0x8000A48C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A490: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8000A494: jr          $ra
    // 0x8000A498: nop

    return;
    // 0x8000A498: nop

;}
RECOMP_FUNC void gcAddDObjForGObjTraRotSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F098: jal         0x800092D0
    // 0x8000F09C: nop

    gcAddDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x8000F09C: nop

    after_0:
    // 0x8000F0A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000F0A4: jal         0x8000F058
    // 0x8000F0A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjTransformTraRotSca(rdram, ctx);
        goto after_1;
    // 0x8000F0A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000F0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F0B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F0B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F0B8: jr          $ra
    // 0x8000F0BC: nop

    return;
    // 0x8000F0BC: nop

;}
RECOMP_FUNC void ftCommonDamageFlyRollUpdateModelPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140744: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80140748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014074C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80140750: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80140754: lwc1        $f6, 0x54($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80140758: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8014075C: lwc1        $f10, 0x58($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80140760: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80140764: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80140768: jal         0x8001863C
    // 0x8014076C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8014076C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80140770: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80140774: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80140778: lw          $t7, 0x8F8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8F8);
    // 0x8014077C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80140780: nop

    // 0x80140784: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80140788: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8014078C: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    // 0x80140790: jal         0x800EB528
    // 0x80140794: lw          $a0, 0x8F8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8F8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_1;
    // 0x80140794: lw          $a0, 0x8F8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8F8);
    after_1:
    // 0x80140798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014079C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801407A0: jr          $ra
    // 0x801407A4: nop

    return;
    // 0x801407A4: nop

;}
RECOMP_FUNC void mvOpeningRoomMakePulledFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132330: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80132334: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80132338: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x8013233C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132340: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80132344: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
L_80132348:
    // 0x80132348: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013234C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132350: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132354: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132358: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8013235C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132360: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132364: bne         $t7, $t0, L_80132348
    if (ctx->r15 != ctx->r8) {
        // 0x80132368: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132348;
    }
    // 0x80132368: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8013236C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132374: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132378: jal         0x800EC0EC
    // 0x8013237C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8013237C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80132380: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132384: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132388: lw          $t1, 0x4CDC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4CDC);
    // 0x8013238C: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80132390: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80132394: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80132398: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8013239C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801323A0: jal         0x800D7F3C
    // 0x801323A4: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x801323A4: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    after_1:
    // 0x801323A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801323AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801323B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801323B4: sw          $v0, 0x4D04($at)
    MEM_W(0X4D04, ctx->r1) = ctx->r2;
    // 0x801323B8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x801323BC: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x801323C0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x801323C4: ori         $a1, $a1, 0x8
    ctx->r5 = ctx->r5 | 0X8;
    // 0x801323C8: swc1        $f0, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f0.u32l;
    // 0x801323CC: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x801323D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801323D4: swc1        $f0, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f0.u32l;
    // 0x801323D8: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x801323DC: jal         0x803905CC
    // 0x801323E0: swc1        $f0, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f0.u32l;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x801323E0: swc1        $f0, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f0.u32l;
    after_2:
    // 0x801323E4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x801323E8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801323EC: jal         0x8000A0D0
    // 0x801323F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x801323F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x801323F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801323F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801323FC: jr          $ra
    // 0x80132400: nop

    return;
    // 0x80132400: nop

;}
RECOMP_FUNC void func_ovl8_8037B654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B654: bgez        $a0, L_8037B664
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8037B658: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8037B664;
    }
    // 0x8037B658: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8037B65C: b           L_8037B668
    // 0x8037B660: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_8037B668;
    // 0x8037B660: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_8037B664:
    // 0x8037B664: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8037B668:
    // 0x8037B668: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8037B66C: bgez        $a0, L_8037B688
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8037B670: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8037B688;
    }
    // 0x8037B670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037B674: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x8037B678: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8037B67C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037B680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8037B684: addu        $t7, $a2, $zero
    ctx->r15 = ADD32(ctx->r6, 0);
L_8037B688:
    // 0x8037B688: lui         $a3, 0x3B9A
    ctx->r7 = S32(0X3B9A << 16);
    // 0x8037B68C: ori         $a3, $a3, 0xCA00
    ctx->r7 = ctx->r7 | 0XCA00;
    // 0x8037B690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037B694: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_8037B698:
    // 0x8037B698: div         $zero, $v1, $a3
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r7)));
    // 0x8037B69C: mflo        $t1
    ctx->r9 = lo;
    // 0x8037B6A0: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8037B6A4: bne         $a3, $zero, L_8037B6B0
    if (ctx->r7 != 0) {
        // 0x8037B6A8: nop
    
            goto L_8037B6B0;
    }
    // 0x8037B6A8: nop

    // 0x8037B6AC: break       7
    do_break(2151134892);
L_8037B6B0:
    // 0x8037B6B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037B6B4: bne         $a3, $at, L_8037B6C8
    if (ctx->r7 != ctx->r1) {
        // 0x8037B6B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037B6C8;
    }
    // 0x8037B6B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037B6BC: bne         $v1, $at, L_8037B6C8
    if (ctx->r3 != ctx->r1) {
        // 0x8037B6C0: nop
    
            goto L_8037B6C8;
    }
    // 0x8037B6C0: nop

    // 0x8037B6C4: break       6
    do_break(2151134916);
L_8037B6C8:
    // 0x8037B6C8: bnel        $t1, $zero, L_8037B6DC
    if (ctx->r9 != 0) {
        // 0x8037B6CC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8037B6DC;
    }
    goto skip_0;
    // 0x8037B6CC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_0:
    // 0x8037B6D0: beq         $a0, $zero, L_8037B6EC
    if (ctx->r4 == 0) {
        // 0x8037B6D4: nop
    
            goto L_8037B6EC;
    }
    // 0x8037B6D4: nop

    // 0x8037B6D8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8037B6DC:
    // 0x8037B6DC: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x8037B6E0: addiu       $t8, $t1, 0x30
    ctx->r24 = ADD32(ctx->r9, 0X30);
    // 0x8037B6E4: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8037B6E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8037B6EC:
    // 0x8037B6EC: beq         $t1, $zero, L_8037B708
    if (ctx->r9 == 0) {
        // 0x8037B6F0: nop
    
            goto L_8037B708;
    }
    // 0x8037B6F0: nop

    // 0x8037B6F4: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B6F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8037B6FC: mflo        $t3
    ctx->r11 = lo;
    // 0x8037B700: subu        $v1, $v1, $t3
    ctx->r3 = SUB32(ctx->r3, ctx->r11);
    // 0x8037B704: nop

L_8037B708:
    // 0x8037B708: div         $zero, $a3, $t2
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r10)));
    // 0x8037B70C: bne         $t2, $zero, L_8037B718
    if (ctx->r10 != 0) {
        // 0x8037B710: nop
    
            goto L_8037B718;
    }
    // 0x8037B710: nop

    // 0x8037B714: break       7
    do_break(2151134996);
L_8037B718:
    // 0x8037B718: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037B71C: bne         $t2, $at, L_8037B730
    if (ctx->r10 != ctx->r1) {
        // 0x8037B720: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037B730;
    }
    // 0x8037B720: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037B724: bne         $a3, $at, L_8037B730
    if (ctx->r7 != ctx->r1) {
        // 0x8037B728: nop
    
            goto L_8037B730;
    }
    // 0x8037B728: nop

    // 0x8037B72C: break       6
    do_break(2151135020);
L_8037B730:
    // 0x8037B730: mflo        $a3
    ctx->r7 = lo;
    // 0x8037B734: bne         $a3, $zero, L_8037B698
    if (ctx->r7 != 0) {
        // 0x8037B738: nop
    
            goto L_8037B698;
    }
    // 0x8037B738: nop

    // 0x8037B73C: beq         $a1, $zero, L_8037B750
    if (ctx->r5 == 0) {
        // 0x8037B740: addiu       $t5, $zero, 0x30
        ctx->r13 = ADD32(0, 0X30);
            goto L_8037B750;
    }
    // 0x8037B740: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x8037B744: addu        $t4, $a2, $a1
    ctx->r12 = ADD32(ctx->r6, ctx->r5);
    // 0x8037B748: jr          $ra
    // 0x8037B74C: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    return;
    // 0x8037B74C: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
L_8037B750:
    // 0x8037B750: sb          $t5, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r13;
    // 0x8037B754: sb          $zero, 0x1($a2)
    MEM_B(0X1, ctx->r6) = 0;
    // 0x8037B758: jr          $ra
    // 0x8037B75C: nop

    return;
    // 0x8037B75C: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164940: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80164944: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80164948: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016494C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80164950: addiu       $t6, $t6, 0x47D0
    ctx->r14 = ADD32(ctx->r14, 0X47D0);
    // 0x80164954: lw          $t7, 0xAF8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XAF8);
    // 0x80164958: addiu       $a1, $zero, 0x11F
    ctx->r5 = ADD32(0, 0X11F);
    // 0x8016495C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80164960: beq         $t7, $zero, L_80164998
    if (ctx->r15 == 0) {
        // 0x80164964: sw          $t6, 0xA0C($v0)
        MEM_W(0XA0C, ctx->r2) = ctx->r14;
            goto L_80164998;
    }
    // 0x80164964: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x80164968: addiu       $a1, $zero, 0x121
    ctx->r5 = ADD32(0, 0X121);
    // 0x8016496C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80164970: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80164974: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80164978: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8016497C: jal         0x800E6F24
    // 0x80164980: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80164980: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164984: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80164988: lbu         $t9, 0x192($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X192);
    // 0x8016498C: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80164990: b           L_801649A8
    // 0x80164994: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
        goto L_801649A8;
    // 0x80164994: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
L_80164998:
    // 0x80164998: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8016499C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801649A0: jal         0x800E6F24
    // 0x801649A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801649A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
L_801649A8:
    // 0x801649A8: jal         0x800E0830
    // 0x801649AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801649AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801649B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801649B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801649B8: jr          $ra
    // 0x801649BC: nop

    return;
    // 0x801649BC: nop

;}
RECOMP_FUNC void ftLinkSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163A4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163A50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163A54: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80163A58: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80163A5C: addiu       $t6, $t6, 0x3850
    ctx->r14 = ADD32(ctx->r14, 0X3850);
    // 0x80163A60: lw          $t7, 0xADC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XADC);
    // 0x80163A64: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80163A68: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163A6C: beq         $t7, $zero, L_80163AA4
    if (ctx->r15 == 0) {
        // 0x80163A70: sw          $t6, 0xA0C($v0)
        MEM_W(0XA0C, ctx->r2) = ctx->r14;
            goto L_80163AA4;
    }
    // 0x80163A70: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x80163A74: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x80163A78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163A7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163A80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80163A84: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80163A88: jal         0x800E6F24
    // 0x80163A8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163A8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80163A90: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80163A94: lbu         $t9, 0x192($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X192);
    // 0x80163A98: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80163A9C: b           L_80163AB4
    // 0x80163AA0: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
        goto L_80163AB4;
    // 0x80163AA0: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
L_80163AA4:
    // 0x80163AA4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163AA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80163AAC: jal         0x800E6F24
    // 0x80163AB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80163AB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
L_80163AB4:
    // 0x80163AB4: jal         0x800E0830
    // 0x80163AB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80163AB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80163ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163AC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80163AC4: jr          $ra
    // 0x80163AC8: nop

    return;
    // 0x80163AC8: nop

;}
RECOMP_FUNC void mnTitlePlayAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801325D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801325DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801325E0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801325E4: lw          $v0, 0x74($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X74);
    // 0x801325E8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x801325EC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801325F0: jal         0x8000DF34
    // 0x801325F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x801325F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801325F8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x801325FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80132600: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80132604: beq         $v0, $zero, L_80132694
    if (ctx->r2 == 0) {
        // 0x80132608: lw          $v1, 0x10($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X10);
            goto L_80132694;
    }
    // 0x80132608: lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X10);
    // 0x8013260C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132610: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80132614: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132618: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8013261C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132620: nop

    // 0x80132624: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
L_80132628:
    // 0x80132628: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8013262C: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x80132630: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80132634: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80132638: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8013263C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132640: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80132644: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80132648: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8013264C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80132650: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80132654: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80132658: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8013265C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80132660: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132664: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80132668: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8013266C: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80132670: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80132674: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80132678: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8013267C: sub.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80132680: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132684: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x80132688: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8013268C: bnel        $v0, $zero, L_80132628
    if (ctx->r2 != 0) {
        // 0x80132690: lh          $t6, 0x14($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X14);
            goto L_80132628;
    }
    goto skip_0;
    // 0x80132690: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    skip_0:
L_80132694:
    // 0x80132694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013269C: jr          $ra
    // 0x801326A0: nop

    return;
    // 0x801326A0: nop

;}
RECOMP_FUNC void func_ovl8_8037ABDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037ABDC: lw          $t6, 0x30($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X30);
    // 0x8037ABE0: lw          $t7, 0x38($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X38);
    // 0x8037ABE4: bnel        $t6, $t7, L_8037AC04
    if (ctx->r14 != ctx->r15) {
        // 0x8037ABE8: lw          $t0, 0x34($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X34);
            goto L_8037AC04;
    }
    goto skip_0;
    // 0x8037ABE8: lw          $t0, 0x34($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X34);
    skip_0:
    // 0x8037ABEC: lw          $t8, 0x20($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X20);
    // 0x8037ABF0: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x8037ABF4: lw          $t9, 0x24($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X24);
    // 0x8037ABF8: b           L_8037AC9C
    // 0x8037ABFC: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
        goto L_8037AC9C;
    // 0x8037ABFC: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x8037AC00: lw          $t0, 0x34($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X34);
L_8037AC04:
    // 0x8037AC04: bgezl       $t0, L_8037AC40
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8037AC08: lw          $v1, 0x28($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X28);
            goto L_8037AC40;
    }
    goto skip_1;
    // 0x8037AC08: lw          $v1, 0x28($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X28);
    skip_1:
    // 0x8037AC0C: lw          $v1, 0x28($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X28);
    // 0x8037AC10: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x8037AC14: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8037AC18: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8037AC1C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8037AC20: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8037AC24: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8037AC28: lw          $t5, 0x34($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X34);
    // 0x8037AC2C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8037AC30: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8037AC34: b           L_8037AC8C
    // 0x8037AC38: sw          $t8, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r24;
        goto L_8037AC8C;
    // 0x8037AC38: sw          $t8, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r24;
    // 0x8037AC3C: lw          $v1, 0x28($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X28);
L_8037AC40:
    // 0x8037AC40: lw          $t0, 0x18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X18);
    // 0x8037AC44: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8037AC48: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8037AC4C: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x8037AC50: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8037AC54: lw          $t4, 0x1C($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X1C);
    // 0x8037AC58: lw          $v1, 0x2C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X2C);
    // 0x8037AC5C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8037AC60: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8037AC64: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8037AC68: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8037AC6C: lw          $t8, 0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC);
    // 0x8037AC70: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x8037AC74: lw          $t7, 0x34($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X34);
    // 0x8037AC78: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8037AC7C: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x8037AC80: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8037AC84: subu        $t4, $t9, $t1
    ctx->r12 = SUB32(ctx->r25, ctx->r9);
    // 0x8037AC88: sw          $t4, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r12;
L_8037AC8C:
    // 0x8037AC8C: lw          $t3, 0x20($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X20);
    // 0x8037AC90: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8037AC94: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x8037AC98: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
L_8037AC9C:
    // 0x8037AC9C: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x8037ACA0: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8037ACA4: jr          $ra
    // 0x8037ACA8: sw          $t5, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r13;
    return;
    // 0x8037ACA8: sw          $t5, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r13;
;}
RECOMP_FUNC void ftCommonJumpAerialProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013FC4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013FC50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013FC54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013FC58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013FC5C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013FC60: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013FC64: jal         0x800D8DB0
    // 0x8013FC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsCheckSetFastFall(rdram, ctx);
        goto after_0;
    // 0x8013FC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013FC6C: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x8013FC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FC74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013FC78: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8013FC7C: bgez        $t8, L_8013FC94
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8013FC80: nop
    
            goto L_8013FC94;
    }
    // 0x8013FC80: nop

    // 0x8013FC84: jal         0x800D8DA0
    // 0x8013FC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsApplyFastFall(rdram, ctx);
        goto after_1;
    // 0x8013FC88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013FC8C: b           L_8013FCA0
    // 0x8013FC90: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
        goto L_8013FCA0;
    // 0x8013FC90: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_8013FC94:
    // 0x8013FC94: jal         0x800D8E50
    // 0x8013FC98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_2;
    // 0x8013FC98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8013FC9C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_8013FCA0:
    // 0x8013FCA0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8013FCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FCA8: beq         $v0, $at, L_8013FCD4
    if (ctx->r2 == ctx->r1) {
        // 0x8013FCAC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8013FCD4;
    }
    // 0x8013FCAC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013FCB0: beq         $v0, $at, L_8013FD18
    if (ctx->r2 == ctx->r1) {
        // 0x8013FCB4: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8013FD18;
    }
    // 0x8013FCB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013FCB8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8013FCBC: beq         $v0, $at, L_8013FCD4
    if (ctx->r2 == ctx->r1) {
        // 0x8013FCC0: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_8013FCD4;
    }
    // 0x8013FCC0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8013FCC4: beq         $v0, $at, L_8013FD18
    if (ctx->r2 == ctx->r1) {
        // 0x8013FCC8: nop
    
            goto L_8013FD18;
    }
    // 0x8013FCC8: nop

    // 0x8013FCCC: b           L_8013FD58
    // 0x8013FCD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8013FD58;
    // 0x8013FCD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8013FCD4:
    // 0x8013FCD4: jal         0x800D8FA8
    // 0x8013FCD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_3;
    // 0x8013FCD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8013FCDC: bne         $v0, $zero, L_8013FD54
    if (ctx->r2 != 0) {
        // 0x8013FCE0: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8013FD54;
    }
    // 0x8013FCE0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013FCE4: lwc1        $f0, -0x3F2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3F2C);
    // 0x8013FCE8: lwc1        $f4, 0x4C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8013FCEC: lwc1        $f8, 0x50($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8013FCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FCF4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8013FCF8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8013FCFC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8013FD00: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8013FD04: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8013FD08: jal         0x800D8FC8
    // 0x8013FD0C: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_4;
    // 0x8013FD0C: nop

    after_4:
    // 0x8013FD10: b           L_8013FD58
    // 0x8013FD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8013FD58;
    // 0x8013FD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8013FD18:
    // 0x8013FD18: jal         0x800D8FA8
    // 0x8013FD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_5;
    // 0x8013FD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013FD20: bne         $v0, $zero, L_8013FD54
    if (ctx->r2 != 0) {
        // 0x8013FD24: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8013FD54;
    }
    // 0x8013FD24: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013FD28: lwc1        $f0, -0x3F28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3F28);
    // 0x8013FD2C: lwc1        $f16, 0x4C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8013FD30: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8013FD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FD38: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8013FD3C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8013FD40: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8013FD44: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8013FD48: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8013FD4C: jal         0x800D8FC8
    // 0x8013FD50: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_6;
    // 0x8013FD50: nop

    after_6:
L_8013FD54:
    // 0x8013FD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8013FD58:
    // 0x8013FD58: jal         0x800D9074
    // 0x8013FD5C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_7;
    // 0x8013FD5C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8013FD60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013FD64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8013FD68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013FD6C: jr          $ra
    // 0x8013FD70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8013FD70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonWallDamageCheckGoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141C6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80141C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141C74: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80141C78: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80141C7C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80141C80: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80141C84: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80141C88: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80141C8C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80141C90: lwc1        $f6, 0x20($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80141C94: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80141C98: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80141C9C: lhu         $v1, 0xB24($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB24);
    // 0x80141CA0: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x80141CA4: beq         $t8, $zero, L_80141CDC
    if (ctx->r24 == 0) {
        // 0x80141CA8: andi        $t9, $v1, 0x20
        ctx->r25 = ctx->r3 & 0X20;
            goto L_80141CDC;
    }
    // 0x80141CA8: andi        $t9, $v1, 0x20
    ctx->r25 = ctx->r3 & 0X20;
    // 0x80141CAC: lwc1        $f16, 0xBC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x80141CB0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80141CB4: addiu       $a1, $v0, 0x120
    ctx->r5 = ADD32(ctx->r2, 0X120);
    // 0x80141CB8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80141CBC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80141CC0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80141CC4: lwc1        $f6, 0xB4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x80141CC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80141CCC: jal         0x80141B08
    // 0x80141CD0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    ftCommonWallDamageSetStatus(rdram, ctx);
        goto after_0;
    // 0x80141CD0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80141CD4: b           L_80141D44
    // 0x80141CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80141D44;
    // 0x80141CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80141CDC:
    // 0x80141CDC: beq         $t9, $zero, L_80141D18
    if (ctx->r25 == 0) {
        // 0x80141CE0: andi        $t0, $v1, 0x400
        ctx->r8 = ctx->r3 & 0X400;
            goto L_80141D18;
    }
    // 0x80141CE0: andi        $t0, $v1, 0x400
    ctx->r8 = ctx->r3 & 0X400;
    // 0x80141CE4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80141CE8: lwc1        $f16, 0xBC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x80141CEC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80141CF0: addiu       $a1, $v0, 0x134
    ctx->r5 = ADD32(ctx->r2, 0X134);
    // 0x80141CF4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80141CF8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80141CFC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80141D00: lwc1        $f6, 0xB4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x80141D04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80141D08: jal         0x80141B08
    // 0x80141D0C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    ftCommonWallDamageSetStatus(rdram, ctx);
        goto after_1;
    // 0x80141D0C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80141D10: b           L_80141D44
    // 0x80141D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80141D44;
    // 0x80141D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80141D18:
    // 0x80141D18: beq         $t0, $zero, L_80141D40
    if (ctx->r8 == 0) {
        // 0x80141D1C: lwc1        $f10, 0x24($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80141D40;
    }
    // 0x80141D1C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80141D20: lwc1        $f16, 0xB0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x80141D24: addiu       $a1, $v0, 0x10C
    ctx->r5 = ADD32(ctx->r2, 0X10C);
    // 0x80141D28: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80141D2C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80141D30: jal         0x80141B08
    // 0x80141D34: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    ftCommonWallDamageSetStatus(rdram, ctx);
        goto after_2;
    // 0x80141D34: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80141D38: b           L_80141D44
    // 0x80141D3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80141D44;
    // 0x80141D3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80141D40:
    // 0x80141D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80141D44:
    // 0x80141D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80141D48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80141D4C: jr          $ra
    // 0x80141D50: nop

    return;
    // 0x80141D50: nop

;}
RECOMP_FUNC void mnPlayers1PBonusPuckProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135BF4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80135BF8: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x80135BFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80135C00: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x80135C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135C08: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80135C0C: bne         $t7, $zero, L_80135C34
    if (ctx->r15 != 0) {
        // 0x80135C10: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_80135C34;
    }
    // 0x80135C10: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80135C14: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    // 0x80135C18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80135C1C: beq         $v0, $t8, L_80135C34
    if (ctx->r2 == ctx->r24) {
        // 0x80135C20: nop
    
            goto L_80135C34;
    }
    // 0x80135C20: nop

    // 0x80135C24: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x80135C28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80135C2C: bnel        $v0, $t9, L_80135C40
    if (ctx->r2 != ctx->r25) {
        // 0x80135C30: sw          $t0, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r8;
            goto L_80135C40;
    }
    goto skip_0;
    // 0x80135C30: sw          $t0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r8;
    skip_0:
L_80135C34:
    // 0x80135C34: b           L_80135C40
    // 0x80135C38: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80135C40;
    // 0x80135C38: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80135C3C: sw          $t0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r8;
L_80135C40:
    // 0x80135C40: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x80135C44: bne         $t1, $zero, L_80135CAC
    if (ctx->r9 != 0) {
        // 0x80135C48: nop
    
            goto L_80135CAC;
    }
    // 0x80135C48: nop

    // 0x80135C4C: lw          $t2, 0x50($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X50);
    // 0x80135C50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80135C54: beq         $t2, $at, L_80135CAC
    if (ctx->r10 == ctx->r1) {
        // 0x80135C58: nop
    
            goto L_80135CAC;
    }
    // 0x80135C58: nop

    // 0x80135C5C: lw          $t3, 0x70($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X70);
    // 0x80135C60: bne         $t3, $zero, L_80135CB4
    if (ctx->r11 != 0) {
        // 0x80135C64: nop
    
            goto L_80135CB4;
    }
    // 0x80135C64: nop

    // 0x80135C68: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80135C6C: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80135C70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135C74: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x80135C78: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80135C7C: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80135C80: lwc1        $f4, 0x58($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X58);
    // 0x80135C84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80135C88: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135C8C: swc1        $f8, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f8.u32l;
    // 0x80135C90: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80135C94: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80135C98: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80135C9C: lwc1        $f10, 0x5C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x80135CA0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80135CA4: b           L_80135CB4
    // 0x80135CA8: swc1        $f18, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f18.u32l;
        goto L_80135CB4;
    // 0x80135CA8: swc1        $f18, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f18.u32l;
L_80135CAC:
    // 0x80135CAC: jal         0x80135BB4
    // 0x80135CB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PBonusMovePuck(rdram, ctx);
        goto after_0;
    // 0x80135CB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
L_80135CB4:
    // 0x80135CB4: jal         0x80134F6C
    // 0x80135CB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PBonusGetPuckFighterKind(rdram, ctx);
        goto after_1;
    // 0x80135CB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80135CBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80135CC0: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x80135CC4: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
    // 0x80135CC8: bne         $t0, $zero, L_80135CF0
    if (ctx->r8 != 0) {
        // 0x80135CCC: nop
    
            goto L_80135CF0;
    }
    // 0x80135CCC: nop

    // 0x80135CD0: lw          $t1, 0x20($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X20);
    // 0x80135CD4: beq         $v0, $t1, L_80135CF0
    if (ctx->r2 == ctx->r9) {
        // 0x80135CD8: nop
    
            goto L_80135CF0;
    }
    // 0x80135CD8: nop

    // 0x80135CDC: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x80135CE0: jal         0x8013476C
    // 0x80135CE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PBonusUpdateFighter(rdram, ctx);
        goto after_2;
    // 0x80135CE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80135CE8: jal         0x801347F8
    // 0x80135CEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PBonusUpdateNameAndEmblem(rdram, ctx);
        goto after_3;
    // 0x80135CEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_80135CF0:
    // 0x80135CF0: jal         0x80133BCC
    // 0x80135CF4: nop

    mnPlayers1PBonusMakeHiScore(rdram, ctx);
        goto after_4;
    // 0x80135CF4: nop

    after_4:
    // 0x80135CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135CFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80135D00: jr          $ra
    // 0x80135D04: nop

    return;
    // 0x80135D04: nop

;}
RECOMP_FUNC void ftCaptainSpecialHiProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160370: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160378: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8016037C: lw          $t6, 0x180($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X180);
    // 0x80160380: beql        $t6, $zero, L_801603E4
    if (ctx->r14 == 0) {
        // 0x80160384: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801603E4;
    }
    goto skip_0;
    // 0x80160384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80160388: lb          $v0, 0x1C2($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C2);
    // 0x8016038C: sw          $zero, 0x180($a1)
    MEM_W(0X180, ctx->r5) = 0;
    // 0x80160390: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80160394: bgez        $v0, L_801603A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80160398: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801603A4;
    }
    // 0x80160398: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8016039C: b           L_801603A4
    // 0x801603A0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_801603A4;
    // 0x801603A0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_801603A4:
    // 0x801603A4: slti        $at, $v1, 0x13
    ctx->r1 = SIGNED(ctx->r3) < 0X13 ? 1 : 0;
    // 0x801603A8: bnel        $at, $zero, L_801603E4
    if (ctx->r1 != 0) {
        // 0x801603AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801603E4;
    }
    goto skip_1;
    // 0x801603AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801603B0: jal         0x800E8044
    // 0x801603B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamSetStickLR(rdram, ctx);
        goto after_0;
    // 0x801603B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801603B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801603BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801603C0: lwc1        $f8, -0x36FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X36FC);
    // 0x801603C4: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x801603C8: lw          $t8, 0x8E8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8E8);
    // 0x801603CC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801603D0: nop

    // 0x801603D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801603D8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801603DC: swc1        $f10, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f10.u32l;
    // 0x801603E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801603E4:
    // 0x801603E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801603E8: jr          $ra
    // 0x801603EC: nop

    return;
    // 0x801603EC: nop

;}
RECOMP_FUNC void mpCollisionGetCeilEdgeR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F444C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4450: jal         0x800F41EC
    // 0x800F4454: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    mpCollisionGetLREdge(rdram, ctx);
        goto after_0;
    // 0x800F4454: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800F4458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F445C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4460: jr          $ra
    // 0x800F4464: nop

    return;
    // 0x800F4464: nop

;}
RECOMP_FUNC void func_ovl8_80371764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037176C: jal         0x80371560
    // 0x80371770: addiu       $a0, $a0, -0xC
    ctx->r4 = ADD32(ctx->r4, -0XC);
    func_ovl8_80371560(rdram, ctx);
        goto after_0;
    // 0x80371770: addiu       $a0, $a0, -0xC
    ctx->r4 = ADD32(ctx->r4, -0XC);
    after_0:
    // 0x80371774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037177C: jr          $ra
    // 0x80371780: nop

    return;
    // 0x80371780: nop

;}
RECOMP_FUNC void mnVSResultsMakePlayerTagCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133E7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133E80: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133E84: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133E88: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133E8C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80133E90: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133E94: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80133E98: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133E9C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133EA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133EA4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133EA8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133EAC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133EB0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133EB4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133EB8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133EBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133EC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133EC4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133EC8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133ECC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133ED4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133ED8: jal         0x8000B93C
    // 0x80133EDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133EDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133EE0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133EE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133EE8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133EEC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133EF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133EF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133EF8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133EFC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133F00: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133F04: jal         0x80007080
    // 0x80133F08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133F08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133F0C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133F10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133F14: jr          $ra
    // 0x80133F18: nop

    return;
    // 0x80133F18: nop

;}
RECOMP_FUNC void scStaffrollJobAndNameThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013369C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801336A0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801336A4: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x801336A8: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x801336AC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x801336B0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x801336B4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x801336B8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x801336BC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801336C0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801336C4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801336C8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801336CC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801336D0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801336D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801336D8: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x801336DC: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x801336E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801336E4: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x801336E8: addiu       $s7, $s7, -0x5740
    ctx->r23 = ADD32(ctx->r23, -0X5740);
    // 0x801336EC: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
    // 0x801336F0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x801336F4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x801336F8: beql        $t7, $zero, L_80133718
    if (ctx->r15 == 0) {
        // 0x801336FC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80133718;
    }
    goto skip_0;
    // 0x801336FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
L_80133700:
    // 0x80133700: jal         0x8000B1E8
    // 0x80133704: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80133704: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80133708: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8013370C: bne         $t8, $zero, L_80133700
    if (ctx->r24 != 0) {
        // 0x80133710: nop
    
            goto L_80133700;
    }
    // 0x80133710: nop

    // 0x80133714: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80133718:
    // 0x80133718: sw          $zero, 0x7C($s6)
    MEM_W(0X7C, ctx->r22) = 0;
    // 0x8013371C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80133720: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80133724: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x80133728: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x8013372C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80133730: addiu       $s4, $s4, -0x5720
    ctx->r20 = ADD32(ctx->r20, -0X5720);
    // 0x80133734: addiu       $s5, $s5, -0x5744
    ctx->r21 = ADD32(ctx->r21, -0X5744);
    // 0x80133738: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8013373C: bc1t        L_801337F0
    if (c1cs) {
        // 0x80133740: addiu       $s3, $sp, 0x68
        ctx->r19 = ADD32(ctx->r29, 0X68);
            goto L_801337F0;
    }
    // 0x80133740: addiu       $s3, $sp, 0x68
    ctx->r19 = ADD32(ctx->r29, 0X68);
    // 0x80133744: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80133748: lui         $at, 0x42C6
    ctx->r1 = S32(0X42C6 << 16);
    // 0x8013374C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80133750: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80133754: addiu       $s2, $s2, -0x5724
    ctx->r18 = ADD32(ctx->r18, -0X5724);
L_80133758:
    // 0x80133758: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8013375C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133760: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80133764: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80133768: jal         0x8000BD1C
    // 0x8013376C: nop

    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8013376C: nop

    after_1:
    // 0x80133770: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80133774: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x80133778: jal         0x8001E530
    // 0x8013377C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    syInterpCubic(rdram, ctx);
        goto after_2;
    // 0x8013377C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x80133780: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80133784: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80133788: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8013378C: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x80133790: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80133794: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x80133798: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8013379C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801337A0: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
    // 0x801337A4: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801337A8: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x801337AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801337B0: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x801337B4: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801337B8: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x801337BC: nop

    // 0x801337C0: bc1f        L_801337CC
    if (!c1cs) {
        // 0x801337C4: nop
    
            goto L_801337CC;
    }
    // 0x801337C4: nop

    // 0x801337C8: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
L_801337CC:
    // 0x801337CC: jal         0x8000DF34
    // 0x801337D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x801337D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x801337D4: jal         0x8000B1E8
    // 0x801337D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_4;
    // 0x801337D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x801337DC: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801337E0: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x801337E4: nop

    // 0x801337E8: bc1f        L_80133758
    if (!c1cs) {
        // 0x801337EC: nop
    
            goto L_80133758;
    }
    // 0x801337EC: nop

L_801337F0:
    // 0x801337F0: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x801337F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801337F8: bne         $v0, $t9, L_80133804
    if (ctx->r2 != ctx->r25) {
        // 0x801337FC: nop
    
            goto L_80133804;
    }
    // 0x801337FC: nop

    // 0x80133800: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
L_80133804:
    // 0x80133804: jal         0x80133684
    // 0x80133808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SCStaffrollNameSetPrevAlloc(rdram, ctx);
        goto after_5;
    // 0x80133808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013380C: jal         0x80009A84
    // 0x80133810: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_6;
    // 0x80133810: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80133814: jal         0x8000B1E8
    // 0x80133818: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_7;
    // 0x80133818: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8013381C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80133820: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80133824: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80133828: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8013382C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80133830: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80133834: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80133838: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8013383C: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80133840: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80133844: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80133848: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x8013384C: jr          $ra
    // 0x80133850: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80133850: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void ftManagerAllocFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7194: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x800D7198: subu        $a2, $a2, $a1
    ctx->r6 = SUB32(ctx->r6, ctx->r5);
    // 0x800D719C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800D71A0: subu        $a2, $a2, $a1
    ctx->r6 = SUB32(ctx->r6, ctx->r5);
    // 0x800D71A4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800D71A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D71AC: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x800D71B0: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800D71B4: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x800D71B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D71BC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800D71C0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800D71C4: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800D71C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D71CC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x800D71D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800D71D4: jal         0x80004980
    // 0x800D71D8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800D71D8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_0:
    // 0x800D71DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D71E0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800D71E4: addiu       $a3, $a3, 0xD84
    ctx->r7 = ADD32(ctx->r7, 0XD84);
    // 0x800D71E8: addiu       $v1, $v1, 0xD80
    ctx->r3 = ADD32(ctx->r3, 0XD80);
    // 0x800D71EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800D71F0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800D71F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800D71F8: jal         0x800315B0
    // 0x800D71FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _bzero(rdram, ctx);
        goto after_1;
    // 0x800D71FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D7200: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800D7204: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800D7208: addiu       $a3, $a3, 0xD84
    ctx->r7 = ADD32(ctx->r7, 0XD84);
    // 0x800D720C: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800D7210: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800D7214: blez        $a1, L_800D72EC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D7218: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800D72EC;
    }
    // 0x800D7218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D721C: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x800D7220: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800D7224: beq         $v0, $zero, L_800D726C
    if (ctx->r2 == 0) {
        // 0x800D7228: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D726C;
    }
    // 0x800D7228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D722C: sll         $v1, $zero, 2
    ctx->r3 = S32(0 << 2);
    // 0x800D7230: subu        $v1, $v1, $zero
    ctx->r3 = SUB32(ctx->r3, 0);
    // 0x800D7234: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800D7238: subu        $v1, $v1, $zero
    ctx->r3 = SUB32(ctx->r3, 0);
    // 0x800D723C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800D7240: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800D7244: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
L_800D7248:
    // 0x800D7248: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800D724C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D7250: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x800D7254: addiu       $t8, $t7, 0xB50
    ctx->r24 = ADD32(ctx->r15, 0XB50);
    // 0x800D7258: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x800D725C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800D7260: bne         $a0, $a2, L_800D7248
    if (ctx->r4 != ctx->r6) {
        // 0x800D7264: addiu       $v1, $v1, 0xB50
        ctx->r3 = ADD32(ctx->r3, 0XB50);
            goto L_800D7248;
    }
    // 0x800D7264: addiu       $v1, $v1, 0xB50
    ctx->r3 = ADD32(ctx->r3, 0XB50);
    // 0x800D7268: beq         $a2, $a1, L_800D72EC
    if (ctx->r6 == ctx->r5) {
        // 0x800D726C: sll         $v1, $a2, 2
        ctx->r3 = S32(ctx->r6 << 2);
            goto L_800D72EC;
    }
L_800D726C:
    // 0x800D726C: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x800D7270: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800D7274: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800D7278: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800D727C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800D7280: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800D7284: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800D7288: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800D728C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
L_800D7290:
    // 0x800D7290: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800D7294: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800D7298: addu        $t3, $v1, $v0
    ctx->r11 = ADD32(ctx->r3, ctx->r2);
    // 0x800D729C: addiu       $t4, $t3, 0xB50
    ctx->r12 = ADD32(ctx->r11, 0XB50);
    // 0x800D72A0: addu        $t5, $v0, $v1
    ctx->r13 = ADD32(ctx->r2, ctx->r3);
    // 0x800D72A4: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800D72A8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800D72AC: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x800D72B0: addiu       $t7, $t6, 0x16A0
    ctx->r15 = ADD32(ctx->r14, 0X16A0);
    // 0x800D72B4: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x800D72B8: sw          $t7, 0xB50($t8)
    MEM_W(0XB50, ctx->r24) = ctx->r15;
    // 0x800D72BC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800D72C0: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x800D72C4: addiu       $t3, $t9, 0x21F0
    ctx->r11 = ADD32(ctx->r25, 0X21F0);
    // 0x800D72C8: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x800D72CC: sw          $t3, 0x16A0($t4)
    MEM_W(0X16A0, ctx->r12) = ctx->r11;
    // 0x800D72D0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800D72D4: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x800D72D8: addiu       $t6, $t5, 0x2D40
    ctx->r14 = ADD32(ctx->r13, 0X2D40);
    // 0x800D72DC: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x800D72E0: sw          $t6, 0x21F0($t7)
    MEM_W(0X21F0, ctx->r15) = ctx->r14;
    // 0x800D72E4: bne         $a2, $a1, L_800D7290
    if (ctx->r6 != ctx->r5) {
        // 0x800D72E8: addiu       $v1, $v1, 0x2D40
        ctx->r3 = ADD32(ctx->r3, 0X2D40);
            goto L_800D7290;
    }
    // 0x800D72E8: addiu       $v1, $v1, 0x2D40
    ctx->r3 = ADD32(ctx->r3, 0X2D40);
L_800D72EC:
    // 0x800D72EC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800D72F0: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x800D72F4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D72F8: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x800D72FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D7300: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x800D7304: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800D7308: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D730C: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x800D7310: sll         $a0, $t0, 6
    ctx->r4 = S32(ctx->r8 << 6);
    // 0x800D7314: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800D7318: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x800D731C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800D7320: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x800D7324: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x800D7328: subu        $a0, $a0, $t0
    ctx->r4 = SUB32(ctx->r4, ctx->r8);
    // 0x800D732C: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800D7330: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800D7334: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x800D7338: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D733C: jal         0x80004980
    // 0x800D7340: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x800D7340: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x800D7344: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7348: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800D734C: addiu       $a0, $a0, 0xD8C
    ctx->r4 = ADD32(ctx->r4, 0XD8C);
    // 0x800D7350: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800D7354: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D7358: sw          $v0, 0xD88($at)
    MEM_W(0XD88, ctx->r1) = ctx->r2;
    // 0x800D735C: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x800D7360: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800D7364: addu        $t0, $t0, $at
    ctx->r8 = ADD32(ctx->r8, ctx->r1);
    // 0x800D7368: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800D736C: addu        $t0, $t0, $at
    ctx->r8 = ADD32(ctx->r8, ctx->r1);
    // 0x800D7370: addiu       $a3, $t0, -0x1
    ctx->r7 = ADD32(ctx->r8, -0X1);
    // 0x800D7374: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800D7378: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800D737C: blez        $a3, L_800D7434
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800D7380: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D7434;
    }
    // 0x800D7380: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D7384: addiu       $v1, $t0, -0x1
    ctx->r3 = ADD32(ctx->r8, -0X1);
    // 0x800D7388: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800D738C: beq         $v1, $zero, L_800D73C4
    if (ctx->r3 == 0) {
        // 0x800D7390: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800D73C4;
    }
    // 0x800D7390: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800D7394: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800D7398: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800D739C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
L_800D73A0:
    // 0x800D73A0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D73A4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D73A8: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x800D73AC: addiu       $t5, $t4, 0xE0
    ctx->r13 = ADD32(ctx->r12, 0XE0);
    // 0x800D73B0: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x800D73B4: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x800D73B8: bne         $a1, $a2, L_800D73A0
    if (ctx->r5 != ctx->r6) {
        // 0x800D73BC: addiu       $v0, $v0, 0xE0
        ctx->r2 = ADD32(ctx->r2, 0XE0);
            goto L_800D73A0;
    }
    // 0x800D73BC: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, 0XE0);
    // 0x800D73C0: beq         $a2, $a3, L_800D742C
    if (ctx->r6 == ctx->r7) {
        // 0x800D73C4: sll         $v0, $a2, 3
        ctx->r2 = S32(ctx->r6 << 3);
            goto L_800D742C;
    }
L_800D73C4:
    // 0x800D73C4: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800D73C8: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800D73CC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
L_800D73D0:
    // 0x800D73D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D73D4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800D73D8: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x800D73DC: addiu       $t8, $t7, 0xE0
    ctx->r24 = ADD32(ctx->r15, 0XE0);
    // 0x800D73E0: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x800D73E4: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x800D73E8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D73EC: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x800D73F0: addiu       $t4, $t3, 0x1C0
    ctx->r12 = ADD32(ctx->r11, 0X1C0);
    // 0x800D73F4: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x800D73F8: sw          $t4, 0xE8($t5)
    MEM_W(0XE8, ctx->r13) = ctx->r12;
    // 0x800D73FC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D7400: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x800D7404: addiu       $t7, $t6, 0x2A0
    ctx->r15 = ADD32(ctx->r14, 0X2A0);
    // 0x800D7408: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x800D740C: sw          $t7, 0x1C8($t8)
    MEM_W(0X1C8, ctx->r24) = ctx->r15;
    // 0x800D7410: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D7414: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x800D7418: addiu       $t3, $t9, 0x380
    ctx->r11 = ADD32(ctx->r25, 0X380);
    // 0x800D741C: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x800D7420: sw          $t3, 0x2A8($t4)
    MEM_W(0X2A8, ctx->r12) = ctx->r11;
    // 0x800D7424: bne         $a2, $a3, L_800D73D0
    if (ctx->r6 != ctx->r7) {
        // 0x800D7428: addiu       $v0, $v0, 0x380
        ctx->r2 = ADD32(ctx->r2, 0X380);
            goto L_800D73D0;
    }
    // 0x800D7428: addiu       $v0, $v0, 0x380
    ctx->r2 = ADD32(ctx->r2, 0X380);
L_800D742C:
    // 0x800D742C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D7430: lw          $v1, 0xD8C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XD8C);
L_800D7434:
    // 0x800D7434: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x800D7438: subu        $t5, $t5, $a2
    ctx->r13 = SUB32(ctx->r13, ctx->r6);
    // 0x800D743C: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800D7440: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x800D7444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D7448: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    // 0x800D744C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D7450: sw          $v0, 0xD90($at)
    MEM_W(0XD90, ctx->r1) = ctx->r2;
    // 0x800D7454: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D7458: sh          $v0, 0xD94($at)
    MEM_H(0XD94, ctx->r1) = ctx->r2;
    // 0x800D745C: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x800D7460: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D7464: addiu       $a0, $a0, 0xA3
    ctx->r4 = ADD32(ctx->r4, 0XA3);
    // 0x800D7468: sh          $v0, 0xD96($at)
    MEM_H(0XD96, ctx->r1) = ctx->r2;
    // 0x800D746C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D7470: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800D7474: jal         0x800CDBD0
    // 0x800D7478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    lbRelocGetFileSize(rdram, ctx);
        goto after_3;
    // 0x800D7478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800D747C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D7480: jal         0x80004980
    // 0x800D7484: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_4;
    // 0x800D7484: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x800D7488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D748C: jal         0x800CDC88
    // 0x800D7490: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_5;
    // 0x800D7490: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x800D7494: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x800D7498: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D749C: addiu       $a0, $a0, 0xC9
    ctx->r4 = ADD32(ctx->r4, 0XC9);
    // 0x800D74A0: sw          $v0, 0xD98($at)
    MEM_W(0XD98, ctx->r1) = ctx->r2;
    // 0x800D74A4: jal         0x800CDBD0
    // 0x800D74A8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_6;
    // 0x800D74A8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_6:
    // 0x800D74AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D74B0: jal         0x80004980
    // 0x800D74B4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_7;
    // 0x800D74B4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x800D74B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D74BC: jal         0x800CDC88
    // 0x800D74C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_8;
    // 0x800D74C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x800D74C4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800D74C8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800D74CC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800D74D0: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x800D74D4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800D74D8: addiu       $a3, $a3, 0x523C
    ctx->r7 = ADD32(ctx->r7, 0X523C);
    // 0x800D74DC: addiu       $a1, $a1, 0x50F8
    ctx->r5 = ADD32(ctx->r5, 0X50F8);
    // 0x800D74E0: addiu       $a2, $a2, 0x6E10
    ctx->r6 = ADD32(ctx->r6, 0X6E10);
    // 0x800D74E4: andi        $t1, $v1, 0x2
    ctx->r9 = ctx->r3 & 0X2;
    // 0x800D74E8: andi        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 & 0X1;
L_800D74EC:
    // 0x800D74EC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800D74F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D74F4: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x800D74F8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800D74FC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800D7500: beq         $t1, $zero, L_800D7518
    if (ctx->r9 == 0) {
        // 0x800D7504: sw          $t8, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r24;
            goto L_800D7518;
    }
    // 0x800D7504: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800D7508: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800D750C: beq         $v0, $zero, L_800D7518
    if (ctx->r2 == 0) {
        // 0x800D7510: nop
    
            goto L_800D7518;
    }
    // 0x800D7510: nop

    // 0x800D7514: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D7518:
    // 0x800D7518: beql        $t0, $zero, L_800D7538
    if (ctx->r8 == 0) {
        // 0x800D751C: sltu        $at, $t2, $v1
        ctx->r1 = ctx->r10 < ctx->r3 ? 1 : 0;
            goto L_800D7538;
    }
    goto skip_0;
    // 0x800D751C: sltu        $at, $t2, $v1
    ctx->r1 = ctx->r10 < ctx->r3 ? 1 : 0;
    skip_0:
    // 0x800D7520: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800D7524: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800D7528: beql        $at, $zero, L_800D7538
    if (ctx->r1 == 0) {
        // 0x800D752C: sltu        $at, $t2, $v1
        ctx->r1 = ctx->r10 < ctx->r3 ? 1 : 0;
            goto L_800D7538;
    }
    goto skip_1;
    // 0x800D752C: sltu        $at, $t2, $v1
    ctx->r1 = ctx->r10 < ctx->r3 ? 1 : 0;
    skip_1:
    // 0x800D7530: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D7534: sltu        $at, $t2, $v1
    ctx->r1 = ctx->r10 < ctx->r3 ? 1 : 0;
L_800D7538:
    // 0x800D7538: beq         $at, $zero, L_800D7544
    if (ctx->r1 == 0) {
        // 0x800D753C: sw          $v1, 0x74($a0)
        MEM_W(0X74, ctx->r4) = ctx->r3;
            goto L_800D7544;
    }
    // 0x800D753C: sw          $v1, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r3;
    // 0x800D7540: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
L_800D7544:
    // 0x800D7544: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x800D7548: bne         $a1, $a3, L_800D74EC
    if (ctx->r5 != ctx->r7) {
        // 0x800D754C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800D74EC;
    }
    // 0x800D754C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800D7550: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D7554: beq         $t0, $zero, L_800D7584
    if (ctx->r8 == 0) {
        // 0x800D7558: sw          $t2, 0xD9C($at)
        MEM_W(0XD9C, ctx->r1) = ctx->r10;
            goto L_800D7584;
    }
    // 0x800D7558: sw          $t2, 0xD9C($at)
    MEM_W(0XD9C, ctx->r1) = ctx->r10;
    // 0x800D755C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800D7560: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800D7564: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800D7568: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800D756C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800D7570: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D7574: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800D7578: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800D757C: jal         0x803904E0
    // 0x800D7580: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_9;
    // 0x800D7580: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_9:
L_800D7584:
    // 0x800D7584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D7588: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D758C: jr          $ra
    // 0x800D7590: nop

    return;
    // 0x800D7590: nop

;}
RECOMP_FUNC void mpCollisionGetVertexFlagsLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCAC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FCACC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FCAD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FCAD4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FCAD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCADC: beq         $a0, $at, L_800FCAF0
    if (ctx->r4 == ctx->r1) {
        // 0x800FCAE0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FCAF0;
    }
    // 0x800FCAE0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FCAE4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FCAE8: bne         $a0, $at, L_800FCB14
    if (ctx->r4 != ctx->r1) {
        // 0x800FCAEC: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FCB14;
    }
    // 0x800FCAEC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FCAF0:
    // 0x800FCAF0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FCAF4: addiu       $s0, $s0, 0x758
    ctx->r16 = ADD32(ctx->r16, 0X758);
    // 0x800FCAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FCAFC:
    // 0x800FCAFC: jal         0x80023624
    // 0x800FCB00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FCB00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FCB04: jal         0x800A3040
    // 0x800FCB08: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FCB08: nop

    after_1:
    // 0x800FCB0C: b           L_800FCAFC
    // 0x800FCB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FCAFC;
    // 0x800FCB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FCB14:
    // 0x800FCB14: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800FCB18: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FCB1C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800FCB20: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FCB24: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800FCB28: lw          $t1, 0x1374($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1374);
    // 0x800FCB2C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800FCB30: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800FCB34: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x800FCB38: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800FCB3C: lw          $t5, 0x1370($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1370);
    // 0x800FCB40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCB44: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800FCB48: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800FCB4C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800FCB50: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800FCB54: lhu         $v0, 0x4($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X4);
    // 0x800FCB58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FCB5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FCB60: jr          $ra
    // 0x800FCB64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FCB64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void scStaffrollGetPauseStatusResume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131B04: lbu         $t6, -0x56FC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X56FC);
    // 0x80131B08: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80131B0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131B10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80131B14: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80131B18: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80131B1C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80131B20: lhu         $v0, 0x522A($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X522A);
    // 0x80131B24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131B28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131B2C: andi        $t8, $v0, 0xF000
    ctx->r24 = ctx->r2 & 0XF000;
    // 0x80131B30: beq         $t8, $zero, L_80131B9C
    if (ctx->r24 == 0) {
        // 0x80131B34: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80131B9C;
    }
    // 0x80131B34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131B38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80131B3C: lw          $a0, -0x5738($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5738);
    // 0x80131B40: beq         $a0, $zero, L_80131B50
    if (ctx->r4 == 0) {
        // 0x80131B44: nop
    
            goto L_80131B50;
    }
    // 0x80131B44: nop

    // 0x80131B48: jal         0x8000B2B8
    // 0x80131B4C: nop

    gcResumeGObjProcessAll(rdram, ctx);
        goto after_0;
    // 0x80131B4C: nop

    after_0:
L_80131B50:
    // 0x80131B50: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80131B54: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x80131B58: beq         $s0, $zero, L_80131B74
    if (ctx->r16 == 0) {
        // 0x80131B5C: nop
    
            goto L_80131B74;
    }
    // 0x80131B5C: nop

L_80131B60:
    // 0x80131B60: jal         0x8000B2B8
    // 0x80131B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_1;
    // 0x80131B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80131B68: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x80131B6C: bne         $s0, $zero, L_80131B60
    if (ctx->r16 != 0) {
        // 0x80131B70: nop
    
            goto L_80131B60;
    }
    // 0x80131B70: nop

L_80131B74:
    // 0x80131B74: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80131B78: lw          $s0, 0x6700($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6700);
    // 0x80131B7C: beql        $s0, $zero, L_80131B9C
    if (ctx->r16 == 0) {
        // 0x80131B80: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131B9C;
    }
    goto skip_0;
    // 0x80131B80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_0:
L_80131B84:
    // 0x80131B84: jal         0x8000B2B8
    // 0x80131B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_2;
    // 0x80131B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80131B8C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x80131B90: bne         $s0, $zero, L_80131B84
    if (ctx->r16 != 0) {
        // 0x80131B94: nop
    
            goto L_80131B84;
    }
    // 0x80131B94: nop

    // 0x80131B98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80131B9C:
    // 0x80131B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131BA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131BA8: jr          $ra
    // 0x80131BAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131BAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_80382A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80382A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80382A88: jal         0x80381308
    // 0x80382A8C: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_ovl8_80381308(rdram, ctx);
        goto after_0;
    // 0x80382A8C: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_0:
    // 0x80382A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80382A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80382A98: jr          $ra
    // 0x80382A9C: nop

    return;
    // 0x80382A9C: nop

;}
RECOMP_FUNC void func_ovl27_8013702C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013702C: jr          $ra
    // 0x80137030: nop

    return;
    // 0x80137030: nop

;}
RECOMP_FUNC void mpCollisionCheckLRSurfaceFlat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7D24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F7D28: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800F7D2C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800F7D30: nop

    // 0x800F7D34: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800F7D38: nop

    // 0x800F7D3C: bc1fl       L_800F7D84
    if (!c1cs) {
        // 0x800F7D40: mtc1        $a0, $f10
        ctx->f10.u32l = ctx->r4;
            goto L_800F7D84;
    }
    goto skip_0;
    // 0x800F7D40: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    skip_0:
    // 0x800F7D44: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800F7D48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7D4C: lwc1        $f6, 0x888($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X888);
    // 0x800F7D50: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F7D54: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800F7D58: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800F7D5C: nop

    // 0x800F7D60: bc1t        L_800F7D78
    if (c1cs) {
        // 0x800F7D64: nop
    
            goto L_800F7D78;
    }
    // 0x800F7D64: nop

    // 0x800F7D68: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x800F7D6C: nop

    // 0x800F7D70: bc1fl       L_800F7DC0
    if (!c1cs) {
        // 0x800F7D74: lwc1        $f16, 0x40($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
            goto L_800F7DC0;
    }
    goto skip_1;
    // 0x800F7D74: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    skip_1:
L_800F7D78:
    // 0x800F7D78: b           L_800F7EF8
    // 0x800F7D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7EF8;
    // 0x800F7D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7D80: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
L_800F7D84:
    // 0x800F7D84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7D88: lwc1        $f4, 0x88C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X88C);
    // 0x800F7D8C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F7D90: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800F7D94: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800F7D98: nop

    // 0x800F7D9C: bc1t        L_800F7DB4
    if (c1cs) {
        // 0x800F7DA0: nop
    
            goto L_800F7DB4;
    }
    // 0x800F7DA0: nop

    // 0x800F7DA4: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x800F7DA8: nop

    // 0x800F7DAC: bc1fl       L_800F7DC0
    if (!c1cs) {
        // 0x800F7DB0: lwc1        $f16, 0x40($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
            goto L_800F7DC0;
    }
    goto skip_2;
    // 0x800F7DB0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    skip_2:
L_800F7DB4:
    // 0x800F7DB4: b           L_800F7EF8
    // 0x800F7DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7EF8;
    // 0x800F7DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7DBC: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
L_800F7DC0:
    // 0x800F7DC0: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800F7DC4: subu        $t6, $a2, $a1
    ctx->r14 = SUB32(ctx->r6, ctx->r5);
    // 0x800F7DC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800F7DCC: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800F7DD0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800F7DD4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800F7DD8: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800F7DDC: lwc1        $f2, 0x4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F7DE0: bgez        $t6, L_800F7DF4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800F7DE4: lwc1        $f4, 0x4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
            goto L_800F7DF4;
    }
    // 0x800F7DE4: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F7DE8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800F7DEC: b           L_800F7DF4
    // 0x800F7DF0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_800F7DF4;
    // 0x800F7DF0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800F7DF4:
    // 0x800F7DF4: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800F7DF8: nop

    // 0x800F7DFC: bc1fl       L_800F7E58
    if (!c1cs) {
        // 0x800F7E00: mtc1        $v1, $f10
        ctx->f10.u32l = ctx->r3;
            goto L_800F7E58;
    }
    goto skip_3;
    // 0x800F7E00: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    skip_3:
    // 0x800F7E04: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F7E08: nop

    // 0x800F7E0C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F7E10: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800F7E14: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F7E18: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800F7E1C: nop

    // 0x800F7E20: bc1t        L_800F7E4C
    if (c1cs) {
        // 0x800F7E24: nop
    
            goto L_800F7E4C;
    }
    // 0x800F7E24: nop

    // 0x800F7E28: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800F7E2C: nop

    // 0x800F7E30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F7E34: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x800F7E38: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800F7E3C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800F7E40: nop

    // 0x800F7E44: bc1fl       L_800F7EA8
    if (!c1cs) {
        // 0x800F7E48: sub.s       $f6, $f0, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800F7EA8;
    }
    goto skip_4;
    // 0x800F7E48: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    skip_4:
L_800F7E4C:
    // 0x800F7E4C: b           L_800F7EF8
    // 0x800F7E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7EF8;
    // 0x800F7E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7E54: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
L_800F7E58:
    // 0x800F7E58: nop

    // 0x800F7E5C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F7E60: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800F7E64: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F7E68: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800F7E6C: nop

    // 0x800F7E70: bc1t        L_800F7E9C
    if (c1cs) {
        // 0x800F7E74: nop
    
            goto L_800F7E9C;
    }
    // 0x800F7E74: nop

    // 0x800F7E78: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800F7E7C: nop

    // 0x800F7E80: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F7E84: swc1        $f10, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f10.u32l;
    // 0x800F7E88: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800F7E8C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800F7E90: nop

    // 0x800F7E94: bc1fl       L_800F7EA8
    if (!c1cs) {
        // 0x800F7E98: sub.s       $f6, $f0, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800F7EA8;
    }
    goto skip_5;
    // 0x800F7E98: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    skip_5:
L_800F7E9C:
    // 0x800F7E9C: b           L_800F7EF8
    // 0x800F7EA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7EF8;
    // 0x800F7EA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7EA4: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
L_800F7EA8:
    // 0x800F7EA8: sub.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F7EAC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F7EB0: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800F7EB4: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F7EB8: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800F7EBC: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800F7EC0: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800F7EC4: nop

    // 0x800F7EC8: bc1t        L_800F7EE0
    if (c1cs) {
        // 0x800F7ECC: nop
    
            goto L_800F7EE0;
    }
    // 0x800F7ECC: nop

    // 0x800F7ED0: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x800F7ED4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800F7ED8: bc1fl       L_800F7EEC
    if (!c1cs) {
        // 0x800F7EDC: swc1        $f0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
            goto L_800F7EEC;
    }
    goto skip_6;
    // 0x800F7EDC: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    skip_6:
L_800F7EE0:
    // 0x800F7EE0: b           L_800F7EF8
    // 0x800F7EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7EF8;
    // 0x800F7EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7EE8: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
L_800F7EEC:
    // 0x800F7EEC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800F7EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F7EF4: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
L_800F7EF8:
    // 0x800F7EF8: jr          $ra
    // 0x800F7EFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800F7EFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

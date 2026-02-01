#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftBossCommonSetPosAddVelPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801581BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801581C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801581C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801581C8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x801581CC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801581D0: addiu       $t8, $sp, 0x3C
    ctx->r24 = ADD32(ctx->r29, 0X3C);
    // 0x801581D4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801581D8: lw          $t6, 0xADC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XADC);
    // 0x801581DC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801581E0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x801581E4: lw          $t7, 0x84($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X84);
    // 0x801581E8: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x801581EC: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x801581F0: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x801581F4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x801581F8: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x801581FC: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80158200: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x80158204: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x80158208: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8015820C: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x80158210: jal         0x80018910
    // 0x80158214: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    syUtilsRandUShort(rdram, ctx);
        goto after_0;
    // 0x80158214: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80158218: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x8015821C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80158220: beq         $t2, $zero, L_80158230
    if (ctx->r10 == 0) {
        // 0x80158224: lwc1        $f12, 0x58($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80158230;
    }
    // 0x80158224: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80158228: b           L_80158234
    // 0x8015822C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80158234;
    // 0x8015822C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80158230:
    // 0x80158230: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
L_80158234:
    // 0x80158234: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80158238: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8015823C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80158240: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80158244: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80158248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8015824C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80158250: lw          $a0, 0xEC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XEC);
    // 0x80158254: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x80158258: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8015825C: jal         0x800F3DD8
    // 0x80158260: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_1;
    // 0x80158260: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80158264: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80158268: beq         $v0, $zero, L_8015827C
    if (ctx->r2 == 0) {
        // 0x8015826C: lwc1        $f12, 0x58($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
            goto L_8015827C;
    }
    // 0x8015826C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80158270: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80158274: b           L_801582DC
    // 0x80158278: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_801582DC;
    // 0x80158278: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
L_8015827C:
    // 0x8015827C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80158280: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80158284: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80158288: nop

    // 0x8015828C: bc1fl       L_801582A4
    if (!c1cs) {
        // 0x80158290: add.s       $f18, $f2, $f12
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f12.fl;
            goto L_801582A4;
    }
    goto skip_0;
    // 0x80158290: add.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f12.fl;
    skip_0:
    // 0x80158294: sub.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80158298: b           L_801582A8
    // 0x8015829C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
        goto L_801582A8;
    // 0x8015829C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x801582A0: add.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f12.fl;
L_801582A4:
    // 0x801582A4: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
L_801582A8:
    // 0x801582A8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x801582AC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x801582B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801582B4: lw          $a0, 0xEC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XEC);
    // 0x801582B8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x801582BC: jal         0x800F3DD8
    // 0x801582C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_2;
    // 0x801582C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x801582C4: beq         $v0, $zero, L_801582D8
    if (ctx->r2 == 0) {
        // 0x801582C8: lwc1        $f2, 0x38($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801582D8;
    }
    // 0x801582C8: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801582CC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801582D0: b           L_801582DC
    // 0x801582D4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
        goto L_801582DC;
    // 0x801582D4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
L_801582D8:
    // 0x801582D8: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_801582DC:
    // 0x801582DC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801582E0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801582E4: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801582E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801582EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801582F0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801582F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801582F8: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801582FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80158300: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80158304: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80158308: jr          $ra
    // 0x8015830C: nop

    return;
    // 0x8015830C: nop

;}
RECOMP_FUNC void lbCommonRotScaFuncMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA144: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA148: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800CA14C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CA150: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CA154: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800CA158: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800CA15C: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x800CA160: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CA164: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x800CA168: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800CA16C: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800CA170: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800CA174: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800CA178: jal         0x800C82AC
    // 0x800CA17C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    lbCommonMatrixRotSca(rdram, ctx);
        goto after_0;
    // 0x800CA17C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800CA180: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA184: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800CA188: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA18C: jr          $ra
    // 0x800CA190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CA190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void sc1PIntroStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134D98: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80134D9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134DA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134DA4: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80134DA8: addiu       $a0, $a0, 0x5B38
    ctx->r4 = ADD32(ctx->r4, 0X5B38);
    // 0x80134DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134DB0: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80134DB4: jal         0x80007024
    // 0x80134DB8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80134DB8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80134DBC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80134DC0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134DC4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134DC8: addiu       $t9, $t9, 0x6070
    ctx->r25 = ADD32(ctx->r25, 0X6070);
    // 0x80134DCC: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80134DD0: addiu       $a0, $a0, 0x5B54
    ctx->r4 = ADD32(ctx->r4, 0X5B54);
    // 0x80134DD4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80134DD8: jal         0x800A2698
    // 0x80134DDC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x80134DDC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80134DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134DE8: jr          $ra
    // 0x80134DEC: nop

    return;
    // 0x80134DEC: nop

;}
RECOMP_FUNC void mnPlayersVSMakeCursorCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138B6C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80138B70: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80138B74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80138B78: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80138B7C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80138B80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80138B84: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80138B88: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80138B8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80138B90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80138B94: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80138B98: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80138B9C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80138BA0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80138BA4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80138BA8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80138BAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80138BB0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80138BB4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80138BB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80138BBC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80138BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80138BC4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80138BC8: jal         0x8000B93C
    // 0x80138BCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80138BCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80138BD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80138BD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80138BD8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80138BDC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80138BE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80138BE4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80138BE8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80138BEC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80138BF0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80138BF4: jal         0x80007080
    // 0x80138BF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80138BF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80138BFC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80138C00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80138C04: jr          $ra
    // 0x80138C08: nop

    return;
    // 0x80138C08: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNLoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157A18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80157A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157A20: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80157A24: lw          $t6, 0x14C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14C);
    // 0x80157A28: bnel        $t6, $zero, L_80157A44
    if (ctx->r14 != 0) {
        // 0x80157A2C: lhu         $t7, 0x1B6($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
            goto L_80157A44;
    }
    goto skip_0;
    // 0x80157A2C: lhu         $t7, 0x1B6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
    skip_0:
    // 0x80157A30: jal         0x8014935C
    // 0x80157A34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonEscapeCheckInterruptSpecialNDonkey(rdram, ctx);
        goto after_0;
    // 0x80157A34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80157A38: bne         $v0, $zero, L_80157A7C
    if (ctx->r2 != 0) {
        // 0x80157A3C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80157A7C;
    }
    // 0x80157A3C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80157A40: lhu         $t7, 0x1B6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
L_80157A44:
    // 0x80157A44: lhu         $t8, 0x1B4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X1B4);
    // 0x80157A48: lhu         $v0, 0x1BE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1BE);
    // 0x80157A4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80157A50: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80157A54: and         $t0, $v0, $t9
    ctx->r8 = ctx->r2 & ctx->r25;
    // 0x80157A58: beq         $t0, $zero, L_80157A68
    if (ctx->r8 == 0) {
        // 0x80157A5C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80157A68;
    }
    // 0x80157A5C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80157A60: sw          $t1, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r9;
    // 0x80157A64: lhu         $v0, 0x1BE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1BE);
L_80157A68:
    // 0x80157A68: lhu         $t2, 0x1B8($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X1B8);
    // 0x80157A6C: and         $t3, $v0, $t2
    ctx->r11 = ctx->r2 & ctx->r10;
    // 0x80157A70: beql        $t3, $zero, L_80157A80
    if (ctx->r11 == 0) {
        // 0x80157A74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80157A80;
    }
    goto skip_1;
    // 0x80157A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80157A78: sw          $t4, 0xB24($v1)
    MEM_W(0XB24, ctx->r3) = ctx->r12;
L_80157A7C:
    // 0x80157A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80157A80:
    // 0x80157A80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80157A84: jr          $ra
    // 0x80157A88: nop

    return;
    // 0x80157A88: nop

;}
RECOMP_FUNC void ftKeyProcessKeyEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115B10: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80115B14: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80115B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80115B1C: lw          $t6, 0xA98($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA98);
    // 0x80115B20: addiu       $a0, $v0, 0xA94
    ctx->r4 = ADD32(ctx->r2, 0XA94);
    // 0x80115B24: beq         $t6, $zero, L_80115BE4
    if (ctx->r14 == 0) {
        // 0x80115B28: nop
    
            goto L_80115BE4;
    }
    // 0x80115B28: nop

    // 0x80115B2C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80115B30: beq         $v1, $zero, L_80115B3C
    if (ctx->r3 == 0) {
        // 0x80115B34: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80115B3C;
    }
    // 0x80115B34: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80115B38: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80115B3C:
    // 0x80115B3C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_80115B40:
    // 0x80115B40: beq         $a1, $zero, L_80115BE4
    if (ctx->r5 == 0) {
        // 0x80115B44: nop
    
            goto L_80115BE4;
    }
    // 0x80115B44: nop

L_80115B48:
    // 0x80115B48: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80115B4C: addiu       $t6, $a1, 0x2
    ctx->r14 = ADD32(ctx->r5, 0X2);
    // 0x80115B50: bgtz        $t8, L_80115BE4
    if (SIGNED(ctx->r24) > 0) {
        // 0x80115B54: nop
    
            goto L_80115BE4;
    }
    // 0x80115B54: nop

    // 0x80115B58: lhu         $t9, 0x0($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X0);
    // 0x80115B5C: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x80115B60: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80115B64: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80115B68: srl         $v1, $v1, 12
    ctx->r3 = S32(U32(ctx->r3) >> 12);
    // 0x80115B6C: beql        $v1, $zero, L_80115B90
    if (ctx->r3 == 0) {
        // 0x80115B70: sw          $zero, 0x4($a0)
        MEM_W(0X4, ctx->r4) = 0;
            goto L_80115B90;
    }
    goto skip_0;
    // 0x80115B70: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    skip_0:
    // 0x80115B74: beql        $v1, $a2, L_80115B9C
    if (ctx->r3 == ctx->r6) {
        // 0x80115B78: addiu       $t1, $a1, 0x2
        ctx->r9 = ADD32(ctx->r5, 0X2);
            goto L_80115B9C;
    }
    goto skip_1;
    // 0x80115B78: addiu       $t1, $a1, 0x2
    ctx->r9 = ADD32(ctx->r5, 0X2);
    skip_1:
    // 0x80115B7C: beql        $v1, $a3, L_80115BBC
    if (ctx->r3 == ctx->r7) {
        // 0x80115B80: sw          $t6, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r14;
            goto L_80115BBC;
    }
    goto skip_2;
    // 0x80115B80: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    skip_2:
    // 0x80115B84: b           L_80115B40
    // 0x80115B88: nop

        goto L_80115B40;
    // 0x80115B88: nop

    // 0x80115B8C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80115B90:
    // 0x80115B90: b           L_80115B40
    // 0x80115B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80115B40;
    // 0x80115B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80115B98: addiu       $t1, $a1, 0x2
    ctx->r9 = ADD32(ctx->r5, 0X2);
L_80115B9C:
    // 0x80115B9C: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80115BA0: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80115BA4: sh          $t3, 0x1C6($v0)
    MEM_H(0X1C6, ctx->r2) = ctx->r11;
    // 0x80115BA8: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x80115BAC: addiu       $a1, $t4, 0x2
    ctx->r5 = ADD32(ctx->r12, 0X2);
    // 0x80115BB0: b           L_80115B40
    // 0x80115BB4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
        goto L_80115B40;
    // 0x80115BB4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80115BB8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_80115BBC:
    // 0x80115BBC: lb          $t8, 0x0($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X0);
    // 0x80115BC0: addiu       $v1, $v0, 0x1C6
    ctx->r3 = ADD32(ctx->r2, 0X1C6);
    // 0x80115BC4: sb          $t8, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r24;
    // 0x80115BC8: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80115BCC: lb          $t0, 0x1($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X1);
    // 0x80115BD0: sb          $t0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r8;
    // 0x80115BD4: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80115BD8: addiu       $a1, $t1, 0x2
    ctx->r5 = ADD32(ctx->r9, 0X2);
    // 0x80115BDC: bne         $a1, $zero, L_80115B48
    if (ctx->r5 != 0) {
        // 0x80115BE0: sw          $a1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r5;
            goto L_80115B48;
    }
    // 0x80115BE0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
L_80115BE4:
    // 0x80115BE4: jr          $ra
    // 0x80115BE8: nop

    return;
    // 0x80115BE8: nop

;}
RECOMP_FUNC void ftCommonTwisterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801439D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801439D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801439D8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801439DC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801439E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801439E4: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x801439E8: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x801439EC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801439F0: sw          $t8, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r24;
    // 0x801439F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801439F8: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x801439FC: nop

    // 0x80143A00: bc1fl       L_80143A14
    if (!c1cs) {
        // 0x80143A04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80143A14;
    }
    goto skip_0;
    // 0x80143A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80143A08: jal         0x80143CC4
    // 0x80143A0C: nop

    ftCommonTwisterShootFighter(rdram, ctx);
        goto after_0;
    // 0x80143A0C: nop

    after_0:
    // 0x80143A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143A14:
    // 0x80143A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80143A18: jr          $ra
    // 0x80143A1C: nop

    return;
    // 0x80143A1C: nop

;}
RECOMP_FUNC void ftParamGetItemMusicLength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7AD0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800E7AD4: beq         $a0, $at, L_800E7AEC
    if (ctx->r4 == ctx->r1) {
        // 0x800E7AD8: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800E7AEC;
    }
    // 0x800E7AD8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800E7ADC: bne         $a0, $at, L_800E7AF4
    if (ctx->r4 != ctx->r1) {
        // 0x800E7AE0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E7AF4;
    }
    // 0x800E7AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E7AE4: jr          $ra
    // 0x800E7AE8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x800E7AE8: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_800E7AEC:
    // 0x800E7AEC: jr          $ra
    // 0x800E7AF0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800E7AF0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800E7AF4:
    // 0x800E7AF4: jr          $ra
    // 0x800E7AF8: nop

    return;
    // 0x800E7AF8: nop

;}
RECOMP_FUNC void grBonus3TaruBombProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B5F0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010B5F4: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010B5F8: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8010B5FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010B600: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B604: bne         $v0, $zero, L_8010B64C
    if (ctx->r2 != 0) {
        // 0x8010B608: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_8010B64C;
    }
    // 0x8010B608: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010B60C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010B610: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010B614: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8010B618: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010B61C: addiu       $a2, $a2, 0x13F8
    ctx->r6 = ADD32(ctx->r6, 0X13F8);
    // 0x8010B620: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010B624: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8010B628: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8010B62C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8010B630: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8010B634: jal         0x8016EA78
    // 0x8010B638: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_0;
    // 0x8010B638: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8010B63C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010B640: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010B644: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    // 0x8010B648: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8010B64C:
    // 0x8010B64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B650: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8010B654: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x8010B658: jr          $ra
    // 0x8010B65C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8010B65C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftKirbySpecialAirNWaitSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162DD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162DD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162DD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162DDC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162DE0: jal         0x800DEE98
    // 0x80162DE4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80162DE4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162DE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162DEC: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162DF0: addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
    // 0x80162DF4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162DF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162DFC: jal         0x800E6F24
    // 0x80162E00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162E00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162E04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162E08: jal         0x800E8098
    // 0x80162E0C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162E0C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162E18: jr          $ra
    // 0x80162E1C: nop

    return;
    // 0x80162E1C: nop

;}
RECOMP_FUNC void mnTitleMakePressStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133504: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80133508: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013350C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80133510: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80133514: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80133518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013351C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80133520: jal         0x80009968
    // 0x80133524: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133524: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133528: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013352C: lw          $t6, 0x45A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X45A0);
    // 0x80133530: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80133534: addiu       $t7, $t7, 0x62C0
    ctx->r15 = ADD32(ctx->r15, 0X62C0);
    // 0x80133538: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013353C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133544: jal         0x8000F120
    // 0x80133548: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80133548: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x8013354C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133550: lw          $t8, 0x45A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X45A0);
    // 0x80133554: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80133558: addiu       $t9, $t9, 0x58D0
    ctx->r25 = ADD32(ctx->r25, 0X58D0);
    // 0x8013355C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133560: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80133564: jal         0x8000BD8C
    // 0x80133568: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddAnimJointAll(rdram, ctx);
        goto after_2;
    // 0x80133568: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x8013356C: jal         0x8000DF34
    // 0x80133570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x80133570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80133574: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80133578: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8013357C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133580: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80133584: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80133588: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013358C: jal         0x80009968
    // 0x80133590: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80133590: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_4:
    // 0x80133594: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133598: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8013359C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801335A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801335A4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801335A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801335AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801335B0: jal         0x80009DF4
    // 0x801335B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_5;
    // 0x801335B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x801335B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801335BC: addiu       $a1, $a1, 0x26A4
    ctx->r5 = ADD32(ctx->r5, 0X26A4);
    // 0x801335C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801335C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801335C8: jal         0x80008188
    // 0x801335CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x801335CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x801335D0: sw          $s0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->r16;
    // 0x801335D4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801335D8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801335DC: lw          $t4, 0x45A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X45A0);
    // 0x801335E0: lw          $t3, 0x42C4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X42C4);
    // 0x801335E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801335E8: jal         0x800CCFDC
    // 0x801335EC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x801335EC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_7:
    // 0x801335F0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801335F4: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801335F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801335FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80133600: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133604: jal         0x80132764
    // 0x80133608: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    mnTitleSetPosition(rdram, ctx);
        goto after_8;
    // 0x80133608: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_8:
    // 0x8013360C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133610: jal         0x8013282C
    // 0x80133614: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    mnTitleSetColors(rdram, ctx);
        goto after_9;
    // 0x80133614: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_9:
    // 0x80133618: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013361C: sw          $t6, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r14;
    // 0x80133620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133624: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80133628: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013362C: jr          $ra
    // 0x80133630: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80133630: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void itRShellSpinCheckCollisionEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AC84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017AC88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017AC8C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017AC90: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8017AC94: lw          $t6, 0x2D4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017AC98: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8017AC9C: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8017ACA0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8017ACA4: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    // 0x8017ACA8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8017ACAC: jal         0x800FC67C
    // 0x8017ACB0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x8017ACB0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017ACB4: beq         $v0, $zero, L_8017AD6C
    if (ctx->r2 == 0) {
        // 0x8017ACB8: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8017AD6C;
    }
    // 0x8017ACB8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8017ACBC: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x8017ACC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017ACC4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8017ACC8: bne         $t8, $at, L_8017AD24
    if (ctx->r24 != ctx->r1) {
        // 0x8017ACCC: nop
    
            goto L_8017AD24;
    }
    // 0x8017ACCC: nop

    // 0x8017ACD0: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    // 0x8017ACD4: jal         0x800F4428
    // 0x8017ACD8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x8017ACD8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8017ACDC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8017ACE0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8017ACE4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8017ACE8: lh          $t1, 0x30($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X30);
    // 0x8017ACEC: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8017ACF0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8017ACF4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8017ACF8: nop

    // 0x8017ACFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017AD00: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8017AD04: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x8017AD08: nop

    // 0x8017AD0C: bc1fl       L_8017AD70
    if (!c1cs) {
        // 0x8017AD10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017AD70;
    }
    goto skip_0;
    // 0x8017AD10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017AD14: jal         0x8017AC40
    // 0x8017AD18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itRShellSpinEdgeInvertVelLR(rdram, ctx);
        goto after_2;
    // 0x8017AD18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8017AD1C: b           L_8017AD70
    // 0x8017AD20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8017AD70;
    // 0x8017AD20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017AD24:
    // 0x8017AD24: jal         0x800F4408
    // 0x8017AD28: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_3;
    // 0x8017AD28: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    after_3:
    // 0x8017AD2C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8017AD30: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8017AD34: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8017AD38: lh          $t4, 0x30($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X30);
    // 0x8017AD3C: lwc1        $f18, 0x1C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8017AD40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8017AD44: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8017AD48: nop

    // 0x8017AD4C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017AD50: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8017AD54: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8017AD58: nop

    // 0x8017AD5C: bc1fl       L_8017AD70
    if (!c1cs) {
        // 0x8017AD60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017AD70;
    }
    goto skip_1;
    // 0x8017AD60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8017AD64: jal         0x8017AC40
    // 0x8017AD68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itRShellSpinEdgeInvertVelLR(rdram, ctx);
        goto after_4;
    // 0x8017AD68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_8017AD6C:
    // 0x8017AD6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017AD70:
    // 0x8017AD70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017AD74: jr          $ra
    // 0x8017AD78: nop

    return;
    // 0x8017AD78: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNEatSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163458: jal         0x80163018
    // 0x8016345C: addiu       $a1, $zero, 0x11A
    ctx->r5 = ADD32(0, 0X11A);
    ftKirbySpecialNEatSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x8016345C: addiu       $a1, $zero, 0x11A
    ctx->r5 = ADD32(0, 0X11A);
    after_0:
    // 0x80163460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163468: jr          $ra
    // 0x8016346C: nop

    return;
    // 0x8016346C: nop

;}
RECOMP_FUNC void lbParticleSetStructPosAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3CE0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D3CE4: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800D3CE8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D3CEC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D3CF0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800D3CF4: addiu       $a0, $a0, 0x6398
    ctx->r4 = ADD32(ctx->r4, 0X6398);
    // 0x800D3CF8: addiu       $v1, $v1, 0x6358
    ctx->r3 = ADD32(ctx->r3, 0X6358);
    // 0x800D3CFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_800D3D00:
    // 0x800D3D00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D3D04: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800D3D08: beq         $v0, $zero, L_800D3D28
    if (ctx->r2 == 0) {
        // 0x800D3D0C: nop
    
            goto L_800D3D28;
    }
    // 0x800D3D0C: nop

    // 0x800D3D10: swc1        $f12, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f12.u32l;
L_800D3D14:
    // 0x800D3D14: swc1        $f14, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f14.u32l;
    // 0x800D3D18: swc1        $f20, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f20.u32l;
    // 0x800D3D1C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800D3D20: bnel        $v0, $zero, L_800D3D14
    if (ctx->r2 != 0) {
        // 0x800D3D24: swc1        $f12, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->f12.u32l;
            goto L_800D3D14;
    }
    goto skip_0;
    // 0x800D3D24: swc1        $f12, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f12.u32l;
    skip_0:
L_800D3D28:
    // 0x800D3D28: bnel        $at, $zero, L_800D3D00
    if (ctx->r1 != 0) {
        // 0x800D3D2C: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_800D3D00;
    }
    goto skip_1;
    // 0x800D3D2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800D3D30: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D3D34: lw          $v0, 0x639C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X639C);
    // 0x800D3D38: beql        $v0, $zero, L_800D3D5C
    if (ctx->r2 == 0) {
        // 0x800D3D3C: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_800D3D5C;
    }
    goto skip_2;
    // 0x800D3D3C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_2:
    // 0x800D3D40: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
L_800D3D44:
    // 0x800D3D44: swc1        $f14, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f14.u32l;
    // 0x800D3D48: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x800D3D4C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800D3D50: bnel        $v0, $zero, L_800D3D44
    if (ctx->r2 != 0) {
        // 0x800D3D54: swc1        $f12, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
            goto L_800D3D44;
    }
    goto skip_3;
    // 0x800D3D54: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    skip_3:
    // 0x800D3D58: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_800D3D5C:
    // 0x800D3D5C: jr          $ra
    // 0x800D3D60: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D3D60: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void ftSamusSpecialNLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015D70C: jal         0x8015D394
    // 0x8015D710: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftSamusSpecialNSetChargeShotPosition(rdram, ctx);
        goto after_0;
    // 0x8015D710: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015D714: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015D718: addiu       $a1, $a1, -0x2558
    ctx->r5 = ADD32(ctx->r5, -0X2558);
    // 0x8015D71C: jal         0x800DDE84
    // 0x8015D720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_1;
    // 0x8015D720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015D724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D72C: jr          $ra
    // 0x8015D730: nop

    return;
    // 0x8015D730: nop

;}
RECOMP_FUNC void mn1PModeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132910: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132914: lbu         $v0, 0x4AD1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD1);
    // 0x80132918: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8013291C: beq         $v0, $at, L_8013294C
    if (ctx->r2 == ctx->r1) {
        // 0x80132920: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8013294C;
    }
    // 0x80132920: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80132924: beq         $v0, $at, L_80132958
    if (ctx->r2 == ctx->r1) {
        // 0x80132928: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80132958;
    }
    // 0x80132928: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013292C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80132930: beq         $v0, $at, L_80132964
    if (ctx->r2 == ctx->r1) {
        // 0x80132934: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80132964;
    }
    // 0x80132934: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80132938: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8013293C: beq         $v0, $at, L_80132970
    if (ctx->r2 == ctx->r1) {
        // 0x80132940: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_80132970;
    }
    // 0x80132940: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80132944: b           L_80132978
    // 0x80132948: nop

        goto L_80132978;
    // 0x80132948: nop

L_8013294C:
    // 0x8013294C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132950: b           L_80132978
    // 0x80132954: sw          $zero, 0x31B8($at)
    MEM_W(0X31B8, ctx->r1) = 0;
        goto L_80132978;
    // 0x80132954: sw          $zero, 0x31B8($at)
    MEM_W(0X31B8, ctx->r1) = 0;
L_80132958:
    // 0x80132958: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013295C: b           L_80132978
    // 0x80132960: sw          $t6, 0x31B8($at)
    MEM_W(0X31B8, ctx->r1) = ctx->r14;
        goto L_80132978;
    // 0x80132960: sw          $t6, 0x31B8($at)
    MEM_W(0X31B8, ctx->r1) = ctx->r14;
L_80132964:
    // 0x80132964: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132968: b           L_80132978
    // 0x8013296C: sw          $t7, 0x31B8($at)
    MEM_W(0X31B8, ctx->r1) = ctx->r15;
        goto L_80132978;
    // 0x8013296C: sw          $t7, 0x31B8($at)
    MEM_W(0X31B8, ctx->r1) = ctx->r15;
L_80132970:
    // 0x80132970: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132974: sw          $t8, 0x31B8($at)
    MEM_W(0X31B8, ctx->r1) = ctx->r24;
L_80132978:
    // 0x80132978: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013297C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132980: sw          $zero, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = 0;
    // 0x80132984: addiu       $v0, $v0, 0x31C8
    ctx->r2 = ADD32(ctx->r2, 0X31C8);
    // 0x80132988: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8013298C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132990: sw          $zero, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = 0;
    // 0x80132994: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80132998: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013299C: addiu       $t0, $t9, 0x4650
    ctx->r8 = ADD32(ctx->r25, 0X4650);
    // 0x801329A0: jr          $ra
    // 0x801329A4: sw          $t0, 0x31CC($at)
    MEM_W(0X31CC, ctx->r1) = ctx->r8;
    return;
    // 0x801329A4: sw          $t0, 0x31CC($at)
    MEM_W(0X31CC, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void mnVSRecordGetKOs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131B78: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80131B7C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80131B80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131B84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131B88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131B8C: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80131B90: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80131B94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80131B98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80131B9C: addiu       $s3, $s3, 0x44E0
    ctx->r19 = ADD32(ctx->r19, 0X44E0);
    // 0x80131BA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80131BA4: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
L_80131BA8:
    // 0x80131BA8: jal         0x801326EC
    // 0x80131BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_0;
    // 0x80131BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80131BB0: beq         $v0, $zero, L_80131BDC
    if (ctx->r2 == 0) {
        // 0x80131BB4: sll         $t6, $s2, 2
        ctx->r14 = S32(ctx->r18 << 2);
            goto L_80131BDC;
    }
    // 0x80131BB4: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80131BB8: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x80131BBC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80131BC0: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x80131BC4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80131BC8: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80131BCC: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x80131BD0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80131BD4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80131BD8: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
L_80131BDC:
    // 0x80131BDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80131BE0: bne         $s0, $s4, L_80131BA8
    if (ctx->r16 != ctx->r20) {
        // 0x80131BE4: nop
    
            goto L_80131BA8;
    }
    // 0x80131BE4: nop

    // 0x80131BE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80131BEC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80131BF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131BF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131BF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131BFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80131C00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80131C04: jr          $ra
    // 0x80131C08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131C08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayersVSCenterPuckInPortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013879C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801387A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801387A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801387A8: jal         0x80132168
    // 0x801387AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSGetPortrait(rdram, ctx);
        goto after_0;
    // 0x801387AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801387B0: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801387B4: bne         $at, $zero, L_801387FC
    if (ctx->r1 != 0) {
        // 0x801387B8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_801387FC;
    }
    // 0x801387B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801387BC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801387C0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x801387C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801387C8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x801387CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801387D0: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x801387D4: addiu       $t7, $t6, -0xEA
    ctx->r15 = ADD32(ctx->r14, -0XEA);
    // 0x801387D8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801387DC: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x801387E0: lui         $at, 0x42B2
    ctx->r1 = S32(0X42B2 << 16);
    // 0x801387E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801387E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801387EC: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x801387F0: lw          $t9, 0x74($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X74);
    // 0x801387F4: b           L_80138838
    // 0x801387F8: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
        goto L_80138838;
    // 0x801387F8: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
L_801387FC:
    // 0x801387FC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80138800: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80138804: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80138808: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8013880C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80138810: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80138814: addiu       $t1, $t0, 0x24
    ctx->r9 = ADD32(ctx->r8, 0X24);
    // 0x80138818: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8013881C: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x80138820: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80138824: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80138828: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013882C: swc1        $f16, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f16.u32l;
    // 0x80138830: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    // 0x80138834: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
L_80138838:
    // 0x80138838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013883C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80138840: jr          $ra
    // 0x80138844: nop

    return;
    // 0x80138844: nop

;}
RECOMP_FUNC void mvOpeningKirbyMakeMotionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D41C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D420: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D424: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D428: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D42C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D430: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D434: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D438: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018D43C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018D440: addiu       $t6, $t6, -0x1F50
    ctx->r14 = ADD32(ctx->r14, -0X1F50);
    // 0x8018D444: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D448: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D44C: addiu       $s0, $s0, -0x1DB8
    ctx->r16 = ADD32(ctx->r16, -0X1DB8);
    // 0x8018D450: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D454: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018D458: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D45C: addiu       $t9, $t9, -0x1F34
    ctx->r25 = ADD32(ctx->r25, -0X1F34);
    // 0x8018D460: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8018D464: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8018D468: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D46C: addiu       $s1, $s1, -0x1D98
    ctx->r17 = ADD32(ctx->r17, -0X1D98);
    // 0x8018D470: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8018D474: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8018D478: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D47C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8018D480: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D484: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8018D488: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8018D48C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8018D490: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8018D494: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8018D498: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8018D49C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018D4A0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8018D4A4: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x8018D4A8: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018D4AC: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8018D4B0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8018D4B4: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8018D4B8: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8018D4BC: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8018D4C0: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8018D4C4: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8018D4C8: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8018D4CC: jal         0x8010DB2C
    // 0x8018D4D0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D4D0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    after_0:
    // 0x8018D4D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018D4D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D4DC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D4E0: addiu       $v1, $v1, -0x1DC8
    ctx->r3 = ADD32(ctx->r3, -0X1DC8);
    // 0x8018D4E4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D4E8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D4EC: lw          $s2, 0x74($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D4F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D4FC: lui         $a3, 0x4352
    ctx->r7 = S32(0X4352 << 16);
    // 0x8018D500: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018D504: jal         0x80007080
    // 0x8018D508: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D508: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D50C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D510: lwc1        $f6, -0x1DF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DF4);
    // 0x8018D514: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D518: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8018D51C: jal         0x8000B39C
    // 0x8018D520: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D520: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    after_2:
    // 0x8018D524: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D528: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D52C: addiu       $a1, $a1, -0x2CDC
    ctx->r5 = ADD32(ctx->r5, -0X2CDC);
    // 0x8018D530: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    // 0x8018D534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D538: jal         0x80008188
    // 0x8018D53C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018D53C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018D540: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D544: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D548: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D54C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D550: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D554: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D558: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D55C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D560: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D564: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D568: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018D56C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D570: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D574: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D578: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D57C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018D580: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D584: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D588: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D58C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8018D590: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D594: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D598: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8018D59C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D5A0: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018D5A4: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018D5A8: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5AC: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018D5B0: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5B4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5B8: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018D5BC: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5C0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D5C4: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5C8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D5CC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5D0: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5D4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5D8: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5DC: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5E0: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5E4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D5E8: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8018D5EC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D5F0: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8018D5F4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D5F8: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x8018D5FC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D600: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D604: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D608: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8018D60C: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D610: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
    // 0x8018D614: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D618: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D61C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D620: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D624: jr          $ra
    // 0x8018D628: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018D628: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mvOpeningStandoffFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801325E0: addiu       $v1, $v1, 0x29D0
    ctx->r3 = ADD32(ctx->r3, 0X29D0);
    // 0x801325E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801325E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801325EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801325F0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801325F4: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x801325F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801325FC: bne         $at, $zero, L_80132698
    if (ctx->r1 != 0) {
        // 0x80132600: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80132698;
    }
    // 0x80132600: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132604: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132608: addiu       $a2, $a2, 0x29DC
    ctx->r6 = ADD32(ctx->r6, 0X29DC);
    // 0x8013260C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80132610: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132614: beq         $v0, $zero, L_80132620
    if (ctx->r2 == 0) {
        // 0x80132618: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132620;
    }
    // 0x80132618: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8013261C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80132620:
    // 0x80132620: jal         0x80390A04
    // 0x80132624: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80132624: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80132628: beq         $v0, $zero, L_80132644
    if (ctx->r2 == 0) {
        // 0x8013262C: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_80132644;
    }
    // 0x8013262C: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132630: jal         0x80390AC0
    // 0x80132634: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80132634: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80132638: beq         $v0, $zero, L_80132644
    if (ctx->r2 == 0) {
        // 0x8013263C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132644;
    }
    // 0x8013263C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132640: sw          $zero, 0x29DC($at)
    MEM_W(0X29DC, ctx->r1) = 0;
L_80132644:
    // 0x80132644: jal         0x8039076C
    // 0x80132648: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80132648: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x8013264C: beq         $v0, $zero, L_8013266C
    if (ctx->r2 == 0) {
        // 0x80132650: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8013266C;
    }
    // 0x80132650: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132654: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132658: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8013265C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80132660: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80132664: jal         0x80005C74
    // 0x80132668: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80132668: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
L_8013266C:
    // 0x8013266C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132670: lw          $t2, 0x29D0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X29D0);
    // 0x80132674: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132678: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x8013267C: bne         $t2, $at, L_80132698
    if (ctx->r10 != ctx->r1) {
        // 0x80132680: addiu       $v0, $v0, 0x4AD0
        ctx->r2 = ADD32(ctx->r2, 0X4AD0);
            goto L_80132698;
    }
    // 0x80132680: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132684: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80132688: addiu       $t4, $zero, 0x2B
    ctx->r12 = ADD32(0, 0X2B);
    // 0x8013268C: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80132690: jal         0x80005C74
    // 0x80132694: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x80132694: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    after_4:
L_80132698:
    // 0x80132698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013269C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801326A0: jr          $ra
    // 0x801326A4: nop

    return;
    // 0x801326A4: nop

;}
RECOMP_FUNC void ftNessAppearEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DF14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013DF18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013DF1C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013DF20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013DF24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013DF28: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    // 0x8013DF2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013DF30: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x8013DF34: bne         $t6, $at, L_8013DF44
    if (ctx->r14 != ctx->r1) {
        // 0x8013DF38: addiu       $a1, $zero, 0xE1
        ctx->r5 = ADD32(0, 0XE1);
            goto L_8013DF44;
    }
    // 0x8013DF38: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x8013DF3C: b           L_8013DF44
    // 0x8013DF40: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
        goto L_8013DF44;
    // 0x8013DF40: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
L_8013DF44:
    // 0x8013DF44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8013DF48: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8013DF4C: jal         0x800E6F24
    // 0x8013DF50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013DF50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013DF54: jal         0x8013DBAC
    // 0x8013DF58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonAppearInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x8013DF58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8013DF5C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013DF60: lbu         $t8, 0x18E($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013DF64: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x8013DF68: sb          $t9, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r25;
    // 0x8013DF6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013DF70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013DF74: jr          $ra
    // 0x8013DF78: nop

    return;
    // 0x8013DF78: nop

;}
RECOMP_FUNC void mvOpeningSamusMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DBC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DBCC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018DBD0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DBD4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018DBD8: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018DBDC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DBE0: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018DBE4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DBE8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DBEC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DBF0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DBF4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DBF8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DBFC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DC00: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DC04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DC08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC0C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DC10: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DC14: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DC18: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DC1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC20: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DC24: jal         0x8000B93C
    // 0x8018DC28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DC28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC2C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DC30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DC34: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DC38: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC40: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DC44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DC48: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DC4C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DC50: jal         0x80007080
    // 0x8018DC54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DC54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DC58: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DC5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018DC60: jr          $ra
    // 0x8018DC64: nop

    return;
    // 0x8018DC64: nop

;}
RECOMP_FUNC void mnSoundTestUpdateNumberSprites(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013319C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801331A0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801331A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801331A8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801331AC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801331B0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x801331B4: lw          $a1, 0x4348($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4348);
    // 0x801331B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801331BC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x801331C0: beq         $v0, $zero, L_801331E4
    if (ctx->r2 == 0) {
        // 0x801331C4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_801331E4;
    }
    // 0x801331C4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801331C8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x801331CC: sh          $v1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r3;
L_801331D0:
    // 0x801331D0: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x801331D4: bnel        $v0, $zero, L_801331D0
    if (ctx->r2 != 0) {
        // 0x801331D8: sh          $v1, 0x24($v0)
        MEM_H(0X24, ctx->r2) = ctx->r3;
            goto L_801331D0;
    }
    goto skip_0;
    // 0x801331D8: sh          $v1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r3;
    skip_0:
    // 0x801331DC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x801331E0: lw          $v0, 0x74($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X74);
L_801331E4:
    // 0x801331E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801331E8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801331EC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801331F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331F4: addiu       $a0, $a0, 0x41A4
    ctx->r4 = ADD32(ctx->r4, 0X41A4);
    // 0x801331F8: addiu       $a3, $a3, 0x4468
    ctx->r7 = ADD32(ctx->r7, 0X4468);
    // 0x801331FC: addiu       $t0, $t0, 0x41CC
    ctx->r8 = ADD32(ctx->r8, 0X41CC);
    // 0x80133200: lwc1        $f2, 0x42F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X42F0);
    // 0x80133204: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80133208: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013320C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_80133210:
    // 0x80133210: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x80133214: mfhi        $v1
    ctx->r3 = hi;
    // 0x80133218: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8013321C: addu        $t9, $a0, $v1
    ctx->r25 = ADD32(ctx->r4, ctx->r3);
    // 0x80133220: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80133224: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x80133228: bne         $a2, $zero, L_80133234
    if (ctx->r6 != 0) {
        // 0x8013322C: nop
    
            goto L_80133234;
    }
    // 0x8013322C: nop

    // 0x80133230: break       7
    do_break(2148741680);
L_80133234:
    // 0x80133234: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133238: bne         $a2, $at, L_8013324C
    if (ctx->r6 != ctx->r1) {
        // 0x8013323C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8013324C;
    }
    // 0x8013323C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133240: bne         $a1, $at, L_8013324C
    if (ctx->r5 != ctx->r1) {
        // 0x80133244: nop
    
            goto L_8013324C;
    }
    // 0x80133244: nop

    // 0x80133248: break       6
    do_break(2148741704);
L_8013324C:
    // 0x8013324C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80133250: addiu       $t9, $t5, 0x3C
    ctx->r25 = ADD32(ctx->r13, 0X3C);
    // 0x80133254: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
L_80133258:
    // 0x80133258: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8013325C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80133260: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80133264: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80133268: lw          $t6, -0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X8);
    // 0x8013326C: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x80133270: lw          $t7, -0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, -0X4);
    // 0x80133274: bne         $t5, $t9, L_80133258
    if (ctx->r13 != ctx->r25) {
        // 0x80133278: sw          $t7, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->r15;
            goto L_80133258;
    }
    // 0x80133278: sw          $t7, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r15;
    // 0x8013327C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x80133280: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80133284: addu        $t3, $t0, $v1
    ctx->r11 = ADD32(ctx->r8, ctx->r3);
    // 0x80133288: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013328C: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80133290: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80133294: sw          $t6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r14;
    // 0x80133298: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8013329C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801332A0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801332A4: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801332A8: or          $t9, $t4, $zero
    ctx->r25 = ctx->r12 | 0;
    // 0x801332AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801332B0: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801332B4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801332B8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801332BC: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x801332C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801332C4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801332C8: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x801332CC: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x801332D0: sw          $t4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r12;
    // 0x801332D4: beq         $a1, $zero, L_801332E0
    if (ctx->r5 == 0) {
        // 0x801332D8: add.s       $f0, $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
            goto L_801332E0;
    }
    // 0x801332D8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801332DC: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
L_801332E0:
    // 0x801332E0: bne         $a1, $zero, L_80133210
    if (ctx->r5 != 0) {
        // 0x801332E4: nop
    
            goto L_80133210;
    }
    // 0x801332E4: nop

    // 0x801332E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801332EC: jal         0x80133058
    // 0x801332F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnSoundTestUpdateNumberPositions(rdram, ctx);
        goto after_0;
    // 0x801332F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x801332F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801332F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801332FC: jr          $ra
    // 0x80133300: nop

    return;
    // 0x80133300: nop

;}
RECOMP_FUNC void itProcessProcItemMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016F538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016F53C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016F540: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8016F544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016F548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016F54C: lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X20);
    // 0x8016F550: beq         $v0, $zero, L_8016F560
    if (ctx->r2 == 0) {
        // 0x8016F554: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8016F560;
    }
    // 0x8016F554: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8016F558: sw          $t6, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r14;
    // 0x8016F55C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8016F560:
    // 0x8016F560: bne         $v0, $zero, L_8016F578
    if (ctx->r2 != 0) {
        // 0x8016F564: nop
    
            goto L_8016F578;
    }
    // 0x8016F564: nop

    // 0x8016F568: jal         0x8000DF34
    // 0x8016F56C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x8016F56C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8016F570: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016F574: lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X20);
L_8016F578:
    // 0x8016F578: bnel        $v0, $zero, L_8016F5B4
    if (ctx->r2 != 0) {
        // 0x8016F57C: lh          $t8, 0x2CE($a2)
        ctx->r24 = MEM_H(ctx->r6, 0X2CE);
            goto L_8016F5B4;
    }
    goto skip_0;
    // 0x8016F57C: lh          $t8, 0x2CE($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2CE);
    skip_0:
    // 0x8016F580: lw          $v0, 0x378($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X378);
    // 0x8016F584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016F588: beql        $v0, $zero, L_8016F5B4
    if (ctx->r2 == 0) {
        // 0x8016F58C: lh          $t8, 0x2CE($a2)
        ctx->r24 = MEM_H(ctx->r6, 0X2CE);
            goto L_8016F5B4;
    }
    goto skip_1;
    // 0x8016F58C: lh          $t8, 0x2CE($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2CE);
    skip_1:
    // 0x8016F590: jalr        $v0
    // 0x8016F594: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8016F594: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8016F598: beq         $v0, $zero, L_8016F5B0
    if (ctx->r2 == 0) {
        // 0x8016F59C: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8016F5B0;
    }
    // 0x8016F59C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016F5A0: jal         0x801728D4
    // 0x8016F5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainDestroyItem(rdram, ctx);
        goto after_2;
    // 0x8016F5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8016F5A8: b           L_8016F920
    // 0x8016F5AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8016F920;
    // 0x8016F5AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016F5B0:
    // 0x8016F5B0: lh          $t8, 0x2CE($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2CE);
L_8016F5B4:
    // 0x8016F5B4: bgezl       $t8, L_8016F64C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8016F5B8: sw          $zero, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = 0;
            goto L_8016F64C;
    }
    goto skip_2;
    // 0x8016F5B8: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    skip_2:
    // 0x8016F5BC: lhu         $v0, 0x2D2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2D2);
    // 0x8016F5C0: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x8016F5C4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8016F5C8: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x8016F5CC: andi        $t3, $v0, 0xF
    ctx->r11 = ctx->r2 & 0XF;
    // 0x8016F5D0: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8016F5D4: andi        $v1, $t4, 0xFFFF
    ctx->r3 = ctx->r12 & 0XFFFF;
    // 0x8016F5D8: srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // 0x8016F5DC: sltiu       $at, $v1, 0xB5
    ctx->r1 = ctx->r3 < 0XB5 ? 1 : 0;
    // 0x8016F5E0: beq         $at, $zero, L_8016F624
    if (ctx->r1 == 0) {
        // 0x8016F5E4: sh          $t4, 0x2D2($a2)
        MEM_H(0X2D2, ctx->r6) = ctx->r12;
            goto L_8016F624;
    }
    // 0x8016F5E4: sh          $t4, 0x2D2($a2)
    MEM_H(0X2D2, ctx->r6) = ctx->r12;
    // 0x8016F5E8: bne         $v1, $zero, L_8016F610
    if (ctx->r3 != 0) {
        // 0x8016F5EC: andi        $t5, $v1, 0x1
        ctx->r13 = ctx->r3 & 0X1;
            goto L_8016F610;
    }
    // 0x8016F5EC: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x8016F5F0: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016F5F4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016F5F8: jal         0x8010066C
    // 0x8016F5FC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8016F5FC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8016F600: jal         0x801728D4
    // 0x8016F604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainDestroyItem(rdram, ctx);
        goto after_4;
    // 0x8016F604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8016F608: b           L_8016F920
    // 0x8016F60C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8016F920;
    // 0x8016F60C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016F610:
    // 0x8016F610: beql        $t5, $zero, L_8016F628
    if (ctx->r13 == 0) {
        // 0x8016F614: lbu         $v0, 0x34C($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X34C);
            goto L_8016F628;
    }
    goto skip_3;
    // 0x8016F614: lbu         $v0, 0x34C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X34C);
    skip_3:
    // 0x8016F618: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x8016F61C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8016F620: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
L_8016F624:
    // 0x8016F624: lbu         $v0, 0x34C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X34C);
L_8016F628:
    // 0x8016F628: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8016F62C: bnel        $v0, $zero, L_8016F640
    if (ctx->r2 != 0) {
        // 0x8016F630: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8016F640;
    }
    goto skip_4;
    // 0x8016F630: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    skip_4:
    // 0x8016F634: sb          $t8, 0x34C($a2)
    MEM_B(0X34C, ctx->r6) = ctx->r24;
    // 0x8016F638: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
    // 0x8016F63C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
L_8016F640:
    // 0x8016F640: b           L_8016F64C
    // 0x8016F644: sb          $t9, 0x34C($a2)
    MEM_B(0X34C, ctx->r6) = ctx->r25;
        goto L_8016F64C;
    // 0x8016F644: sb          $t9, 0x34C($a2)
    MEM_B(0X34C, ctx->r6) = ctx->r25;
    // 0x8016F648: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_8016F64C:
    // 0x8016F64C: lw          $t0, 0x2CC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X2CC);
    // 0x8016F650: sll         $t2, $t0, 17
    ctx->r10 = S32(ctx->r8 << 17);
    // 0x8016F654: bltz        $t2, L_8016F914
    if (SIGNED(ctx->r10) < 0) {
        // 0x8016F658: nop
    
            goto L_8016F914;
    }
    // 0x8016F658: nop

    // 0x8016F65C: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    // 0x8016F660: lw          $t5, 0x20($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X20);
    // 0x8016F664: lw          $t4, 0x1C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1C);
    // 0x8016F668: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8016F66C: sw          $t4, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r12;
    // 0x8016F670: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8016F674: sw          $t3, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r11;
    // 0x8016F678: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x8016F67C: bne         $t5, $zero, L_8016F6B4
    if (ctx->r13 != 0) {
        // 0x8016F680: sw          $t4, 0x48($a2)
        MEM_W(0X48, ctx->r6) = ctx->r12;
            goto L_8016F6B4;
    }
    // 0x8016F680: sw          $t4, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->r12;
    // 0x8016F684: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8016F688: lwc1        $f6, 0x2C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x8016F68C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8016F690: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F694: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8016F698: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8016F69C: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x8016F6A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016F6A4: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8016F6A8: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x8016F6AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F6B0: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
L_8016F6B4:
    // 0x8016F6B4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8016F6B8: lwc1        $f16, 0x40($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X40);
    // 0x8016F6BC: lwc1        $f6, 0x44($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X44);
    // 0x8016F6C0: lw          $t6, 0x2CC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2CC);
    // 0x8016F6C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8016F6C8: lwc1        $f16, 0x48($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X48);
    // 0x8016F6CC: sll         $t8, $t6, 25
    ctx->r24 = S32(ctx->r14 << 25);
    // 0x8016F6D0: swc1        $f18, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f18.u32l;
    // 0x8016F6D4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8016F6D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8016F6DC: swc1        $f8, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f8.u32l;
    // 0x8016F6E0: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8016F6E4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8016F6E8: bgez        $t8, L_8016F760
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8016F6EC: swc1        $f18, 0x54($a2)
        MEM_W(0X54, ctx->r6) = ctx->f18.u32l;
            goto L_8016F760;
    }
    // 0x8016F6EC: swc1        $f18, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f18.u32l;
    // 0x8016F6F0: lhu         $a0, 0x2D0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2D0);
    // 0x8016F6F4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8016F6F8: jal         0x800FC67C
    // 0x8016F6FC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_5;
    // 0x8016F6FC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_5:
    // 0x8016F700: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8016F704: beq         $v0, $zero, L_8016F760
    if (ctx->r2 == 0) {
        // 0x8016F708: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8016F760;
    }
    // 0x8016F708: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016F70C: lhu         $a0, 0x2D0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2D0);
    // 0x8016F710: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8016F714: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8016F718: jal         0x800FA7B8
    // 0x8016F71C: addiu       $a1, $a2, 0x58
    ctx->r5 = ADD32(ctx->r6, 0X58);
    mpCollisionGetSpeedLineID(rdram, ctx);
        goto after_6;
    // 0x8016F71C: addiu       $a1, $a2, 0x58
    ctx->r5 = ADD32(ctx->r6, 0X58);
    after_6:
    // 0x8016F720: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016F724: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8016F728: addiu       $v0, $a2, 0x38
    ctx->r2 = ADD32(ctx->r6, 0X38);
    // 0x8016F72C: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8016F730: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8016F734: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8016F738: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F73C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8016F740: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8016F744: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8016F748: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016F74C: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8016F750: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8016F754: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F758: b           L_8016F800
    // 0x8016F75C: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
        goto L_8016F800;
    // 0x8016F75C: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
L_8016F760:
    // 0x8016F760: lw          $t9, 0x108($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X108);
    // 0x8016F764: bnel        $t9, $zero, L_8016F7F0
    if (ctx->r25 != 0) {
        // 0x8016F768: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8016F7F0;
    }
    goto skip_5;
    // 0x8016F768: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_5:
    // 0x8016F76C: lw          $a0, 0xAC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XAC);
    // 0x8016F770: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016F774: beq         $a0, $at, L_8016F7EC
    if (ctx->r4 == ctx->r1) {
        // 0x8016F778: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8016F7EC;
    }
    // 0x8016F778: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8016F77C: beql        $a0, $at, L_8016F7F0
    if (ctx->r4 == ctx->r1) {
        // 0x8016F780: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8016F7F0;
    }
    goto skip_6;
    // 0x8016F780: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_6:
    // 0x8016F784: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8016F788: jal         0x800FC67C
    // 0x8016F78C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_7;
    // 0x8016F78C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_7:
    // 0x8016F790: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8016F794: beq         $v0, $zero, L_8016F7EC
    if (ctx->r2 == 0) {
        // 0x8016F798: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8016F7EC;
    }
    // 0x8016F798: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016F79C: lw          $a0, 0xAC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XAC);
    // 0x8016F7A0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8016F7A4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8016F7A8: jal         0x800FA7B8
    // 0x8016F7AC: addiu       $a1, $a2, 0x58
    ctx->r5 = ADD32(ctx->r6, 0X58);
    mpCollisionGetSpeedLineID(rdram, ctx);
        goto after_8;
    // 0x8016F7AC: addiu       $a1, $a2, 0x58
    ctx->r5 = ADD32(ctx->r6, 0X58);
    after_8:
    // 0x8016F7B0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8016F7B4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016F7B8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8016F7BC: lwc1        $f16, 0x58($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X58);
    // 0x8016F7C0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8016F7C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016F7C8: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8016F7CC: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x8016F7D0: lwc1        $f6, 0x5C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x8016F7D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F7D8: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x8016F7DC: lwc1        $f16, 0x60($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X60);
    // 0x8016F7E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016F7E4: b           L_8016F800
    // 0x8016F7E8: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
        goto L_8016F800;
    // 0x8016F7E8: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
L_8016F7EC:
    // 0x8016F7EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8016F7F0:
    // 0x8016F7F0: nop

    // 0x8016F7F4: swc1        $f0, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f0.u32l;
    // 0x8016F7F8: swc1        $f0, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f0.u32l;
    // 0x8016F7FC: swc1        $f0, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f0.u32l;
L_8016F800:
    // 0x8016F800: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8016F804: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8016F808: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8016F80C: lh          $t0, 0x76($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X76);
    // 0x8016F810: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8016F814: nop

    // 0x8016F818: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016F81C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8016F820: nop

    // 0x8016F824: bc1tl       L_8016F894
    if (c1cs) {
        // 0x8016F828: lw          $v0, 0x398($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X398);
            goto L_8016F894;
    }
    goto skip_7;
    // 0x8016F828: lw          $v0, 0x398($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X398);
    skip_7:
    // 0x8016F82C: lh          $t1, 0x78($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X78);
    // 0x8016F830: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8016F834: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8016F838: nop

    // 0x8016F83C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016F840: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8016F844: nop

    // 0x8016F848: bc1tl       L_8016F894
    if (c1cs) {
        // 0x8016F84C: lw          $v0, 0x398($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X398);
            goto L_8016F894;
    }
    goto skip_8;
    // 0x8016F84C: lw          $v0, 0x398($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X398);
    skip_8:
    // 0x8016F850: lh          $t2, 0x7A($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X7A);
    // 0x8016F854: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8016F858: nop

    // 0x8016F85C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8016F860: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8016F864: nop

    // 0x8016F868: bc1tl       L_8016F894
    if (c1cs) {
        // 0x8016F86C: lw          $v0, 0x398($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X398);
            goto L_8016F894;
    }
    goto skip_9;
    // 0x8016F86C: lw          $v0, 0x398($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X398);
    skip_9:
    // 0x8016F870: lh          $t3, 0x74($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X74);
    // 0x8016F874: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8016F878: nop

    // 0x8016F87C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016F880: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8016F884: nop

    // 0x8016F888: bc1fl       L_8016F8C4
    if (!c1cs) {
        // 0x8016F88C: lw          $v0, 0x37C($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X37C);
            goto L_8016F8C4;
    }
    goto skip_10;
    // 0x8016F88C: lw          $v0, 0x37C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X37C);
    skip_10:
    // 0x8016F890: lw          $v0, 0x398($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X398);
L_8016F894:
    // 0x8016F894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016F898: beq         $v0, $zero, L_8016F8B0
    if (ctx->r2 == 0) {
        // 0x8016F89C: nop
    
            goto L_8016F8B0;
    }
    // 0x8016F89C: nop

    // 0x8016F8A0: jalr        $v0
    // 0x8016F8A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x8016F8A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_9:
    // 0x8016F8A8: beq         $v0, $zero, L_8016F8C0
    if (ctx->r2 == 0) {
        // 0x8016F8AC: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8016F8C0;
    }
    // 0x8016F8AC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_8016F8B0:
    // 0x8016F8B0: jal         0x801728D4
    // 0x8016F8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainDestroyItem(rdram, ctx);
        goto after_10;
    // 0x8016F8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8016F8B8: b           L_8016F920
    // 0x8016F8BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8016F920;
    // 0x8016F8BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016F8C0:
    // 0x8016F8C0: lw          $v0, 0x37C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X37C);
L_8016F8C4:
    // 0x8016F8C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016F8C8: beq         $v0, $zero, L_8016F904
    if (ctx->r2 == 0) {
        // 0x8016F8CC: nop
    
            goto L_8016F904;
    }
    // 0x8016F8CC: nop

    // 0x8016F8D0: lhu         $t4, 0x8E($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X8E);
    // 0x8016F8D4: sh          $zero, 0x8E($a2)
    MEM_H(0X8E, ctx->r6) = 0;
    // 0x8016F8D8: sw          $zero, 0x9C($a2)
    MEM_W(0X9C, ctx->r6) = 0;
    // 0x8016F8DC: sh          $zero, 0x92($a2)
    MEM_H(0X92, ctx->r6) = 0;
    // 0x8016F8E0: sh          $zero, 0x90($a2)
    MEM_H(0X90, ctx->r6) = 0;
    // 0x8016F8E4: jalr        $v0
    // 0x8016F8E8: sh          $t4, 0x8C($a2)
    MEM_H(0X8C, ctx->r6) = ctx->r12;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_11;
    // 0x8016F8E8: sh          $t4, 0x8C($a2)
    MEM_H(0X8C, ctx->r6) = ctx->r12;
    after_11:
    // 0x8016F8EC: beq         $v0, $zero, L_8016F904
    if (ctx->r2 == 0) {
        // 0x8016F8F0: nop
    
            goto L_8016F904;
    }
    // 0x8016F8F0: nop

    // 0x8016F8F4: jal         0x801728D4
    // 0x8016F8F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainDestroyItem(rdram, ctx);
        goto after_12;
    // 0x8016F8F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8016F8FC: b           L_8016F920
    // 0x8016F900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8016F920;
    // 0x8016F900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016F904:
    // 0x8016F904: jal         0x8016F280
    // 0x8016F908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_13;
    // 0x8016F908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8016F90C: jal         0x8016F3D4
    // 0x8016F910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itProcessUpdateAttackRecords(rdram, ctx);
        goto after_14;
    // 0x8016F910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_8016F914:
    // 0x8016F914: jal         0x801713B0
    // 0x8016F918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itVisualsUpdateColAnim(rdram, ctx);
        goto after_15;
    // 0x8016F918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8016F91C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016F920:
    // 0x8016F920: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016F924: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016F928: jr          $ra
    // 0x8016F92C: nop

    return;
    // 0x8016F92C: nop

;}
RECOMP_FUNC void dbMapsFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D64A0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800D64A4: lhu         $t6, 0x5472($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X5472);
    // 0x800D64A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D64AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D64B0: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x800D64B4: beq         $t7, $zero, L_800D64F8
    if (ctx->r15 == 0) {
        // 0x800D64B8: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800D64F8;
    }
    // 0x800D64B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D64BC: lui         $t8, 0x8037
    ctx->r24 = S32(0X8037 << 16);
    // 0x800D64C0: lw          $t8, 0x1420($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1420);
    // 0x800D64C4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800D64C8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800D64CC: beq         $t8, $zero, L_800D64E4
    if (ctx->r24 == 0) {
        // 0x800D64D0: addiu       $a2, $zero, 0x64
        ctx->r6 = ADD32(0, 0X64);
            goto L_800D64E4;
    }
    // 0x800D64D0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x800D64D4: jal         0x800D6490
    // 0x800D64D8: nop

    dbMapsExitFuncMenu(rdram, ctx);
        goto after_0;
    // 0x800D64D8: nop

    after_0:
    // 0x800D64DC: b           L_800D64F8
    // 0x800D64E0: nop

        goto L_800D64F8;
    // 0x800D64E0: nop

L_800D64E4:
    // 0x800D64E4: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800D64E8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800D64EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D64F0: jal         0x80369D78
    // 0x800D64F4: addiu       $a3, $a3, 0x672C
    ctx->r7 = ADD32(ctx->r7, 0X672C);
    dbMenuMakeMenu(rdram, ctx);
        goto after_1;
    // 0x800D64F4: addiu       $a3, $a3, 0x672C
    ctx->r7 = ADD32(ctx->r7, 0X672C);
    after_1:
L_800D64F8:
    // 0x800D64F8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800D64FC: lw          $t0, 0x6680($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6680);
    // 0x800D6500: beql        $t0, $zero, L_800D65A0
    if (ctx->r8 == 0) {
        // 0x800D6504: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D65A0;
    }
    goto skip_0;
    // 0x800D6504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800D6508: jal         0x80369EC0
    // 0x800D650C: nop

    dbMenuDestroyMenu(rdram, ctx);
        goto after_2;
    // 0x800D650C: nop

    after_2:
    // 0x800D6510: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800D6514: lw          $t1, 0x6684($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6684);
    // 0x800D6518: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D651C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x800D6520: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x800D6524: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
    // 0x800D6528: slti        $at, $v1, 0x11
    ctx->r1 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // 0x800D652C: sb          $t1, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r9;
    // 0x800D6530: bne         $at, $zero, L_800D658C
    if (ctx->r1 != 0) {
        // 0x800D6534: sb          $t2, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r10;
            goto L_800D658C;
    }
    // 0x800D6534: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    // 0x800D6538: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D653C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800D6540: addiu       $a0, $a0, 0x4B18
    ctx->r4 = ADD32(ctx->r4, 0X4B18);
    // 0x800D6544: addiu       $t3, $t3, 0x4D08
    ctx->r11 = ADD32(ctx->r11, 0X4D08);
    // 0x800D6548: addiu       $t7, $t3, 0x1EC
    ctx->r15 = ADD32(ctx->r11, 0X1EC);
    // 0x800D654C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
L_800D6550:
    // 0x800D6550: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800D6554: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800D6558: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800D655C: sw          $t5, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r13;
    // 0x800D6560: lw          $t4, -0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X8);
    // 0x800D6564: sw          $t4, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r12;
    // 0x800D6568: lw          $t5, -0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, -0X4);
    // 0x800D656C: bne         $t3, $t7, L_800D6550
    if (ctx->r11 != ctx->r15) {
        // 0x800D6570: sw          $t5, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r13;
            goto L_800D6550;
    }
    // 0x800D6570: sw          $t5, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r13;
    // 0x800D6574: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800D6578: addiu       $t8, $zero, 0x35
    ctx->r24 = ADD32(0, 0X35);
    // 0x800D657C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800D6580: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x800D6584: b           L_800D6594
    // 0x800D6588: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
        goto L_800D6594;
    // 0x800D6588: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_800D658C:
    // 0x800D658C: addiu       $t9, $zero, 0x16
    ctx->r25 = ADD32(0, 0X16);
    // 0x800D6590: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_800D6594:
    // 0x800D6594: jal         0x80005C74
    // 0x800D6598: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x800D6598: nop

    after_3:
    // 0x800D659C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D65A0:
    // 0x800D65A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D65A4: jr          $ra
    // 0x800D65A8: nop

    return;
    // 0x800D65A8: nop

;}
RECOMP_FUNC void func_ovl8_80374C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374C0C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374C10: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x80374C14: lh          $t6, 0x70($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X70);
    // 0x80374C18: jalr        $t9
    // 0x80374C1C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374C1C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374C28: jr          $ra
    // 0x80374C2C: nop

    return;
    // 0x80374C2C: nop

;}
RECOMP_FUNC void itHammerHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017623C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176244: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80176248: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017624C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80176250: addiu       $a1, $a1, -0x625C
    ctx->r5 = ADD32(ctx->r5, -0X625C);
    // 0x80176254: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80176258: jal         0x80172EC8
    // 0x8017625C: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017625C: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x80176260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176268: jr          $ra
    // 0x8017626C: nop

    return;
    // 0x8017626C: nop

;}
RECOMP_FUNC void itBombHeiCommonSetHitStatusNone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177218: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017721C: jr          $ra
    // 0x80177220: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    return;
    // 0x80177220: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
;}
RECOMP_FUNC void ftCommonCliffQuickProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144EE8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80144EEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80144EF0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80144EF4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80144EF8: nop

    // 0x80144EFC: bc1fl       L_80144F58
    if (!c1cs) {
        // 0x80144F00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144F58;
    }
    goto skip_0;
    // 0x80144F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80144F04: lw          $v0, 0xB18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB18);
    // 0x80144F08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80144F0C: beq         $v0, $zero, L_80144F2C
    if (ctx->r2 == 0) {
        // 0x80144F10: nop
    
            goto L_80144F2C;
    }
    // 0x80144F10: nop

    // 0x80144F14: beq         $v0, $at, L_80144F3C
    if (ctx->r2 == ctx->r1) {
        // 0x80144F18: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80144F3C;
    }
    // 0x80144F18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80144F1C: beq         $v0, $at, L_80144F4C
    if (ctx->r2 == ctx->r1) {
        // 0x80144F20: nop
    
            goto L_80144F4C;
    }
    // 0x80144F20: nop

    // 0x80144F24: b           L_80144F58
    // 0x80144F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80144F58;
    // 0x80144F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144F2C:
    // 0x80144F2C: jal         0x801451F0
    // 0x80144F30: nop

    ftCommonCliffClimbQuick1SetStatus(rdram, ctx);
        goto after_0;
    // 0x80144F30: nop

    after_0:
    // 0x80144F34: b           L_80144F58
    // 0x80144F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80144F58;
    // 0x80144F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144F3C:
    // 0x80144F3C: jal         0x801456B4
    // 0x80144F40: nop

    ftCommonCliffAttackQuick1SetStatus(rdram, ctx);
        goto after_1;
    // 0x80144F40: nop

    after_1:
    // 0x80144F44: b           L_80144F58
    // 0x80144F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80144F58;
    // 0x80144F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144F4C:
    // 0x80144F4C: jal         0x8014586C
    // 0x80144F50: nop

    ftCommonCliffEscapeQuick1SetStatus(rdram, ctx);
        goto after_2;
    // 0x80144F50: nop

    after_2:
    // 0x80144F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144F58:
    // 0x80144F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144F5C: jr          $ra
    // 0x80144F60: nop

    return;
    // 0x80144F60: nop

;}
RECOMP_FUNC void mnTitleFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134074: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80134078: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013407C: addiu       $t8, $t8, 0x4348
    ctx->r24 = ADD32(ctx->r24, 0X4348);
    // 0x80134080: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80134084: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80134088: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x8013408C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134090: jr          $ra
    // 0x80134094: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80134094: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void func_ovl2_800DDF74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDF74: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800DDF78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DDF7C: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800DDF80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DDF84: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800DDF88: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800DDF8C: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x800DDF90: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800DDF94: lw          $a0, 0xEC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XEC);
    // 0x800DDF98: addiu       $t7, $sp, 0x64
    ctx->r15 = ADD32(ctx->r29, 0X64);
    // 0x800DDF9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800DDFA0: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DDFA4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800DDFA8: jal         0x800F3DD8
    // 0x800DDFAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_0;
    // 0x800DDFAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800DDFB0: beq         $v0, $zero, L_800DDFD8
    if (ctx->r2 == 0) {
        // 0x800DDFB4: lw          $t0, 0x74($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X74);
            goto L_800DDFD8;
    }
    // 0x800DDFB4: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800DDFB8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800DDFBC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DDFC0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800DDFC4: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x800DDFC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DDFCC: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x800DDFD0: b           L_800DE020
    // 0x800DDFD4: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
        goto L_800DE020;
    // 0x800DDFD4: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
L_800DDFD8:
    // 0x800DDFD8: lw          $a0, 0xEC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XEC);
    // 0x800DDFDC: jal         0x800F4428
    // 0x800DDFE0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x800DDFE0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x800DDFE4: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800DDFE8: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DDFEC: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800DDFF0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800DDFF4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DDFF8: nop

    // 0x800DDFFC: bc1fl       L_800DE010
    if (!c1cs) {
        // 0x800DE000: lw          $t2, 0x70($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X70);
            goto L_800DE010;
    }
    goto skip_0;
    // 0x800DE000: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x800DE004: jal         0x800F4408
    // 0x800DE008: lw          $a0, 0xEC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XEC);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_2;
    // 0x800DE008: lw          $a0, 0xEC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XEC);
    after_2:
    // 0x800DE00C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
L_800DE010:
    // 0x800DE010: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800DE014: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x800DE018: lwc1        $f6, 0x20($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X20);
    // 0x800DE01C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
L_800DE020:
    // 0x800DE020: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800DE024: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE028: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800DE02C: nop

    // 0x800DE030: bc1fl       L_800DE044
    if (!c1cs) {
        // 0x800DE034: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800DE044;
    }
    goto skip_1;
    // 0x800DE034: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x800DE038: b           L_800DE044
    // 0x800DE03C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_800DE044;
    // 0x800DE03C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800DE040: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800DE044:
    // 0x800DE044: lwc1        $f10, -0x500($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X500);
    // 0x800DE048: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800DE04C: nop

    // 0x800DE050: bc1fl       L_800DE064
    if (!c1cs) {
        // 0x800DE054: lwc1        $f16, 0x4($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DE064;
    }
    goto skip_2;
    // 0x800DE054: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x800DE058: b           L_800DE13C
    // 0x800DE05C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DE13C;
    // 0x800DE05C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DE060: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
L_800DE064:
    // 0x800DE064: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800DE068: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800DE06C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800DE070: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DE074: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800DE078: lw          $v0, 0x74($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X74);
    // 0x800DE07C: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800DE080: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800DE084: nop

    // 0x800DE088: bc1fl       L_800DE0F8
    if (!c1cs) {
        // 0x800DE08C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800DE0F8;
    }
    goto skip_3;
    // 0x800DE08C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x800DE090: lwc1        $f12, 0x1C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800DE094: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DE098: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800DE09C: nop

    // 0x800DE0A0: bc1fl       L_800DE0B8
    if (!c1cs) {
        // 0x800DE0A4: sub.s       $f2, $f12, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_800DE0B8;
    }
    goto skip_4;
    // 0x800DE0A4: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    skip_4:
    // 0x800DE0A8: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800DE0AC: b           L_800DE0B8
    // 0x800DE0B0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_800DE0B8;
    // 0x800DE0B0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800DE0B4: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
L_800DE0B8:
    // 0x800DE0B8: lwc1        $f12, 0x320($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X320);
    // 0x800DE0BC: jal         0x800184E0
    // 0x800DE0C0: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    syUtilsTan(rdram, ctx);
        goto after_3;
    // 0x800DE0C0: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800DE0C4: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800DE0C8: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800DE0CC: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DE0D0: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800DE0D4: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x800DE0D8: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800DE0DC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800DE0E0: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800DE0E4: nop

    // 0x800DE0E8: bc1fl       L_800DE0F8
    if (!c1cs) {
        // 0x800DE0EC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800DE0F8;
    }
    goto skip_5;
    // 0x800DE0EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_5:
    // 0x800DE0F0: swc1        $f12, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f12.u32l;
    // 0x800DE0F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800DE0F8:
    // 0x800DE0F8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x800DE0FC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800DE100: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800DE104: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800DE108: jal         0x800EDF24
    // 0x800DE10C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_4;
    // 0x800DE10C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800DE110: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800DE114: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800DE118: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DE11C: lwc1        $f4, 0x31C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X31C);
    // 0x800DE120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DE124: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800DE128: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800DE12C: nop

    // 0x800DE130: bc1f        L_800DE13C
    if (!c1cs) {
        // 0x800DE134: nop
    
            goto L_800DE13C;
    }
    // 0x800DE134: nop

    // 0x800DE138: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_800DE13C:
    // 0x800DE13C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DE140: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DE144: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800DE148: jr          $ra
    // 0x800DE14C: nop

    return;
    // 0x800DE14C: nop

;}
RECOMP_FUNC void wpProcessProcHitCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80166BE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80166BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80166BEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80166BF0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80166BF4: lw          $t7, 0x234($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X234);
    // 0x80166BF8: bnel        $t7, $zero, L_80166C10
    if (ctx->r15 != 0) {
        // 0x80166BFC: lw          $v0, 0x280($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X280);
            goto L_80166C10;
    }
    goto skip_0;
    // 0x80166BFC: lw          $v0, 0x280($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X280);
    skip_0:
    // 0x80166C00: lw          $t8, 0x238($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X238);
    // 0x80166C04: beql        $t8, $zero, L_80166C40
    if (ctx->r24 == 0) {
        // 0x80166C08: lw          $t9, 0x240($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X240);
            goto L_80166C40;
    }
    goto skip_1;
    // 0x80166C08: lw          $t9, 0x240($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X240);
    skip_1:
    // 0x80166C0C: lw          $v0, 0x280($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X280);
L_80166C10:
    // 0x80166C10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80166C14: beql        $v0, $zero, L_80166C40
    if (ctx->r2 == 0) {
        // 0x80166C18: lw          $t9, 0x240($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X240);
            goto L_80166C40;
    }
    goto skip_2;
    // 0x80166C18: lw          $t9, 0x240($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X240);
    skip_2:
    // 0x80166C1C: jalr        $v0
    // 0x80166C20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80166C20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80166C24: beq         $v0, $zero, L_80166C3C
    if (ctx->r2 == 0) {
        // 0x80166C28: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80166C3C;
    }
    // 0x80166C28: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80166C2C: jal         0x8016800C
    // 0x80166C30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    wpMainDestroyWeapon(rdram, ctx);
        goto after_1;
    // 0x80166C30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80166C34: b           L_80166E68
    // 0x80166C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80166E68;
    // 0x80166C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80166C3C:
    // 0x80166C3C: lw          $t9, 0x240($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X240);
L_80166C40:
    // 0x80166C40: beql        $t9, $zero, L_80166D10
    if (ctx->r25 == 0) {
        // 0x80166C44: lw          $t4, 0x23C($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X23C);
            goto L_80166D10;
    }
    goto skip_3;
    // 0x80166C44: lw          $t4, 0x23C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X23C);
    skip_3:
    // 0x80166C48: lw          $t0, 0x148($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X148);
    // 0x80166C4C: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x80166C50: bgezl       $t2, L_80166CE0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80166C54: lw          $v0, 0x284($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X284);
            goto L_80166CE0;
    }
    goto skip_4;
    // 0x80166C54: lw          $v0, 0x284($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X284);
    skip_4:
    // 0x80166C58: lw          $t3, 0xFC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XFC);
    // 0x80166C5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80166C60: bne         $t3, $at, L_80166CDC
    if (ctx->r11 != ctx->r1) {
        // 0x80166C64: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80166CDC;
    }
    // 0x80166C64: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80166C68: lwc1        $f4, -0x3590($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3590);
    // 0x80166C6C: lwc1        $f0, 0x244($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X244);
    // 0x80166C70: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80166C74: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80166C78: nop

    // 0x80166C7C: bc1fl       L_80166CE0
    if (!c1cs) {
        // 0x80166C80: lw          $v0, 0x284($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X284);
            goto L_80166CE0;
    }
    goto skip_5;
    // 0x80166C80: lw          $v0, 0x284($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X284);
    skip_5:
    // 0x80166C84: lwc1        $f6, -0x358C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X358C);
    // 0x80166C88: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80166C8C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80166C90: swc1        $f8, 0x244($v1)
    MEM_W(0X244, ctx->r3) = ctx->f8.u32l;
    // 0x80166C94: lwc1        $f10, 0x244($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X244);
    // 0x80166C98: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80166C9C: nop

    // 0x80166CA0: bc1fl       L_80166CB0
    if (!c1cs) {
        // 0x80166CA4: lw          $v0, 0x288($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X288);
            goto L_80166CB0;
    }
    goto skip_6;
    // 0x80166CA4: lw          $v0, 0x288($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X288);
    skip_6:
    // 0x80166CA8: swc1        $f2, 0x244($v1)
    MEM_W(0X244, ctx->r3) = ctx->f2.u32l;
    // 0x80166CAC: lw          $v0, 0x288($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X288);
L_80166CB0:
    // 0x80166CB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80166CB4: beql        $v0, $zero, L_80166D10
    if (ctx->r2 == 0) {
        // 0x80166CB8: lw          $t4, 0x23C($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X23C);
            goto L_80166D10;
    }
    goto skip_7;
    // 0x80166CB8: lw          $t4, 0x23C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X23C);
    skip_7:
    // 0x80166CBC: jalr        $v0
    // 0x80166CC0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80166CC0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80166CC4: beq         $v0, $zero, L_80166D0C
    if (ctx->r2 == 0) {
        // 0x80166CC8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80166D0C;
    }
    // 0x80166CC8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80166CCC: jal         0x8016800C
    // 0x80166CD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    wpMainDestroyWeapon(rdram, ctx);
        goto after_3;
    // 0x80166CD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80166CD4: b           L_80166E68
    // 0x80166CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80166E68;
    // 0x80166CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80166CDC:
    // 0x80166CDC: lw          $v0, 0x284($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X284);
L_80166CE0:
    // 0x80166CE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80166CE4: beql        $v0, $zero, L_80166D10
    if (ctx->r2 == 0) {
        // 0x80166CE8: lw          $t4, 0x23C($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X23C);
            goto L_80166D10;
    }
    goto skip_8;
    // 0x80166CE8: lw          $t4, 0x23C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X23C);
    skip_8:
    // 0x80166CEC: jalr        $v0
    // 0x80166CF0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80166CF0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x80166CF4: beq         $v0, $zero, L_80166D0C
    if (ctx->r2 == 0) {
        // 0x80166CF8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80166D0C;
    }
    // 0x80166CF8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80166CFC: jal         0x8016800C
    // 0x80166D00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    wpMainDestroyWeapon(rdram, ctx);
        goto after_5;
    // 0x80166D00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80166D04: b           L_80166E68
    // 0x80166D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80166E68;
    // 0x80166D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80166D0C:
    // 0x80166D0C: lw          $t4, 0x23C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X23C);
L_80166D10:
    // 0x80166D10: beql        $t4, $zero, L_80166D4C
    if (ctx->r12 == 0) {
        // 0x80166D14: lw          $a0, 0x254($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X254);
            goto L_80166D4C;
    }
    goto skip_9;
    // 0x80166D14: lw          $a0, 0x254($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X254);
    skip_9:
    // 0x80166D18: lw          $v0, 0x28C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28C);
    // 0x80166D1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80166D20: beql        $v0, $zero, L_80166D4C
    if (ctx->r2 == 0) {
        // 0x80166D24: lw          $a0, 0x254($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X254);
            goto L_80166D4C;
    }
    goto skip_10;
    // 0x80166D24: lw          $a0, 0x254($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X254);
    skip_10:
    // 0x80166D28: jalr        $v0
    // 0x80166D2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80166D2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80166D30: beq         $v0, $zero, L_80166D48
    if (ctx->r2 == 0) {
        // 0x80166D34: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80166D48;
    }
    // 0x80166D34: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80166D38: jal         0x8016800C
    // 0x80166D3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    wpMainDestroyWeapon(rdram, ctx);
        goto after_7;
    // 0x80166D3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80166D40: b           L_80166E68
    // 0x80166D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80166E68;
    // 0x80166D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80166D48:
    // 0x80166D48: lw          $a0, 0x254($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X254);
L_80166D4C:
    // 0x80166D4C: beql        $a0, $zero, L_80166E18
    if (ctx->r4 == 0) {
        // 0x80166D50: lw          $t1, 0x25C($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X25C);
            goto L_80166E18;
    }
    goto skip_11;
    // 0x80166D50: lw          $t1, 0x25C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X25C);
    skip_11:
    // 0x80166D54: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x80166D58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80166D5C: lw          $a1, 0x290($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X290);
    // 0x80166D60: lhu         $t1, 0x258($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X258);
    // 0x80166D64: lbu         $t5, 0xC($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XC);
    // 0x80166D68: lhu         $t2, 0x25A($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X25A);
    // 0x80166D6C: sb          $t5, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r13;
    // 0x80166D70: lbu         $t6, 0xD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XD);
    // 0x80166D74: sb          $t6, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r14;
    // 0x80166D78: lw          $t7, 0xB4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB4C);
    // 0x80166D7C: sw          $t7, 0x2BC($v1)
    MEM_W(0X2BC, ctx->r3) = ctx->r15;
    // 0x80166D80: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x80166D84: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x80166D88: lbu         $t9, 0x12($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X12);
    // 0x80166D8C: sh          $t1, 0x14C($v1)
    MEM_H(0X14C, ctx->r3) = ctx->r9;
    // 0x80166D90: sh          $t2, 0x14E($v1)
    MEM_H(0X14E, ctx->r3) = ctx->r10;
    // 0x80166D94: beq         $a1, $zero, L_80166DC0
    if (ctx->r5 == 0) {
        // 0x80166D98: sb          $t9, 0x12($v1)
        MEM_B(0X12, ctx->r3) = ctx->r25;
            goto L_80166DC0;
    }
    // 0x80166D98: sb          $t9, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r25;
    // 0x80166D9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80166DA0: jalr        $a1
    // 0x80166DA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_8;
    // 0x80166DA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_8:
    // 0x80166DA8: beq         $v0, $zero, L_80166DC0
    if (ctx->r2 == 0) {
        // 0x80166DAC: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80166DC0;
    }
    // 0x80166DAC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80166DB0: jal         0x8016800C
    // 0x80166DB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    wpMainDestroyWeapon(rdram, ctx);
        goto after_9;
    // 0x80166DB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80166DB8: b           L_80166E68
    // 0x80166DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80166E68;
    // 0x80166DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80166DC0:
    // 0x80166DC0: lw          $t3, 0x26C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X26C);
    // 0x80166DC4: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80166DC8: bltzl       $t5, L_80166E18
    if (SIGNED(ctx->r13) < 0) {
        // 0x80166DCC: lw          $t1, 0x25C($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X25C);
            goto L_80166E18;
    }
    goto skip_12;
    // 0x80166DCC: lw          $t1, 0x25C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X25C);
    skip_12:
    // 0x80166DD0: lw          $t6, 0x104($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X104);
    // 0x80166DD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80166DD8: lwc1        $f4, -0x3588($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3588);
    // 0x80166DDC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80166DE0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80166DE4: lwc1        $f8, -0x3584($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3584);
    // 0x80166DE8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80166DEC: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x80166DF0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80166DF4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80166DF8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80166DFC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80166E00: nop

    // 0x80166E04: slti        $at, $t8, 0x65
    ctx->r1 = SIGNED(ctx->r24) < 0X65 ? 1 : 0;
    // 0x80166E08: bne         $at, $zero, L_80166E14
    if (ctx->r1 != 0) {
        // 0x80166E0C: sw          $t8, 0x104($v1)
        MEM_W(0X104, ctx->r3) = ctx->r24;
            goto L_80166E14;
    }
    // 0x80166E0C: sw          $t8, 0x104($v1)
    MEM_W(0X104, ctx->r3) = ctx->r24;
    // 0x80166E10: sw          $t0, 0x104($v1)
    MEM_W(0X104, ctx->r3) = ctx->r8;
L_80166E14:
    // 0x80166E14: lw          $t1, 0x25C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X25C);
L_80166E18:
    // 0x80166E18: beql        $t1, $zero, L_80166E54
    if (ctx->r9 == 0) {
        // 0x80166E1C: sw          $zero, 0x234($v1)
        MEM_W(0X234, ctx->r3) = 0;
            goto L_80166E54;
    }
    goto skip_13;
    // 0x80166E1C: sw          $zero, 0x234($v1)
    MEM_W(0X234, ctx->r3) = 0;
    skip_13:
    // 0x80166E20: lw          $v0, 0x294($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X294);
    // 0x80166E24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80166E28: beql        $v0, $zero, L_80166E54
    if (ctx->r2 == 0) {
        // 0x80166E2C: sw          $zero, 0x234($v1)
        MEM_W(0X234, ctx->r3) = 0;
            goto L_80166E54;
    }
    goto skip_14;
    // 0x80166E2C: sw          $zero, 0x234($v1)
    MEM_W(0X234, ctx->r3) = 0;
    skip_14:
    // 0x80166E30: jalr        $v0
    // 0x80166E34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_10;
    // 0x80166E34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_10:
    // 0x80166E38: beq         $v0, $zero, L_80166E50
    if (ctx->r2 == 0) {
        // 0x80166E3C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80166E50;
    }
    // 0x80166E3C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80166E40: jal         0x8016800C
    // 0x80166E44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    wpMainDestroyWeapon(rdram, ctx);
        goto after_11;
    // 0x80166E44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x80166E48: b           L_80166E68
    // 0x80166E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80166E68;
    // 0x80166E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80166E50:
    // 0x80166E50: sw          $zero, 0x234($v1)
    MEM_W(0X234, ctx->r3) = 0;
L_80166E54:
    // 0x80166E54: sw          $zero, 0x238($v1)
    MEM_W(0X238, ctx->r3) = 0;
    // 0x80166E58: sw          $zero, 0x23C($v1)
    MEM_W(0X23C, ctx->r3) = 0;
    // 0x80166E5C: sw          $zero, 0x240($v1)
    MEM_W(0X240, ctx->r3) = 0;
    // 0x80166E60: sw          $zero, 0x254($v1)
    MEM_W(0X254, ctx->r3) = 0;
    // 0x80166E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80166E68:
    // 0x80166E68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80166E6C: jr          $ra
    // 0x80166E70: nop

    return;
    // 0x80166E70: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CEC: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80131CF0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80131CF4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131CF8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80131CFC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80131D00: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x80131D04: addiu       $t6, $t6, 0x6FB0
    ctx->r14 = ADD32(ctx->r14, 0X6FB0);
    // 0x80131D08: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80131D0C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80131D10: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80131D14: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80131D18: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80131D1C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80131D20: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80131D24: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80131D28: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80131D2C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80131D30: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80131D34: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80131D38: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131D3C: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80131D40: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80131D44: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80131D48:
    // 0x80131D48: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D4C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131D50: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131D54: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131D58: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131D5C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131D60: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131D64: bne         $t6, $t0, L_80131D48
    if (ctx->r14 != ctx->r8) {
        // 0x80131D68: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131D48;
    }
    // 0x80131D68: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131D6C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D70: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80131D74: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80131D78: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80131D7C: bgez        $s3, L_80131D88
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80131D80: lwc1        $f20, 0xA0($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
            goto L_80131D88;
    }
    // 0x80131D80: lwc1        $f20, 0xA0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80131D84: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80131D88:
    // 0x80131D88: div         $zero, $s3, $s6
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r22)));
    // 0x80131D8C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80131D90: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80131D94: addiu       $s7, $s7, 0x7DF8
    ctx->r23 = ADD32(ctx->r23, 0X7DF8);
    // 0x80131D98: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80131D9C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80131DA0: lw          $t5, 0x24($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X24);
    // 0x80131DA4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80131DA8: bne         $s6, $zero, L_80131DB4
    if (ctx->r22 != 0) {
        // 0x80131DAC: nop
    
            goto L_80131DB4;
    }
    // 0x80131DAC: nop

    // 0x80131DB0: break       7
    do_break(2148736432);
L_80131DB4:
    // 0x80131DB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131DB8: bne         $s6, $at, L_80131DCC
    if (ctx->r22 != ctx->r1) {
        // 0x80131DBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131DCC;
    }
    // 0x80131DBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131DC0: bne         $s3, $at, L_80131DCC
    if (ctx->r19 != ctx->r1) {
        // 0x80131DC4: nop
    
            goto L_80131DCC;
    }
    // 0x80131DC4: nop

    // 0x80131DC8: break       6
    do_break(2148736456);
L_80131DCC:
    // 0x80131DCC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80131DD0: jal         0x800CCFDC
    // 0x80131DD4: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131DD4: nop

    after_0:
    // 0x80131DD8: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x80131DDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131DE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DE4: jal         0x80131BF8
    // 0x80131DE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnPlayers1PBonusSetDigitColors(rdram, ctx);
        goto after_1;
    // 0x80131DE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80131DEC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80131DF0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80131DF4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80131DF8: lw          $s5, 0xB0($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB0);
    // 0x80131DFC: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131E00: sub.s       $f20, $f4, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80131E04: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80131E08: beq         $s5, $zero, L_80131E1C
    if (ctx->r21 == 0) {
        // 0x80131E0C: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80131E1C;
    }
    // 0x80131E0C: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131E10: lw          $s2, 0xAC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XAC);
    // 0x80131E14: b           L_80131E30
    // 0x80131E18: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131E30;
    // 0x80131E18: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131E1C:
    // 0x80131E1C: lw          $s2, 0xAC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XAC);
    // 0x80131E20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131E24: jal         0x80131C40
    // 0x80131E28: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PBonusGetNumberDigitCount(rdram, ctx);
        goto after_2;
    // 0x80131E28: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80131E2C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131E30:
    // 0x80131E30: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80131E34: bne         $at, $zero, L_80131F20
    if (ctx->r1 != 0) {
        // 0x80131E38: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131F20;
    }
    // 0x80131E38: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80131E3C:
    // 0x80131E3C: jal         0x80131B58
    // 0x80131E40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PBonusGetPowerOf(rdram, ctx);
        goto after_3;
    // 0x80131E40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80131E44: beq         $v0, $zero, L_80131E8C
    if (ctx->r2 == 0) {
        // 0x80131E48: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131E8C;
    }
    // 0x80131E48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131E4C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80131E50: jal         0x80131B58
    // 0x80131E54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PBonusGetPowerOf(rdram, ctx);
        goto after_4;
    // 0x80131E54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80131E58: div         $zero, $s3, $v0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r2)));
    // 0x80131E5C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131E60: bne         $v0, $zero, L_80131E6C
    if (ctx->r2 != 0) {
        // 0x80131E64: nop
    
            goto L_80131E6C;
    }
    // 0x80131E64: nop

    // 0x80131E68: break       7
    do_break(2148736616);
L_80131E6C:
    // 0x80131E6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131E70: bne         $v0, $at, L_80131E84
    if (ctx->r2 != ctx->r1) {
        // 0x80131E74: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131E84;
    }
    // 0x80131E74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131E78: bne         $s3, $at, L_80131E84
    if (ctx->r19 != ctx->r1) {
        // 0x80131E7C: nop
    
            goto L_80131E84;
    }
    // 0x80131E7C: nop

    // 0x80131E80: break       6
    do_break(2148736640);
L_80131E84:
    // 0x80131E84: b           L_80131E8C
    // 0x80131E88: nop

        goto L_80131E8C;
    // 0x80131E88: nop

L_80131E8C:
    // 0x80131E8C: div         $zero, $v1, $s6
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r22)));
    // 0x80131E90: mfhi        $t0
    ctx->r8 = hi;
    // 0x80131E94: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80131E98: addu        $t9, $sp, $t6
    ctx->r25 = ADD32(ctx->r29, ctx->r14);
    // 0x80131E9C: lw          $t9, 0x70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70);
    // 0x80131EA0: lw          $t7, 0x24($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X24);
    // 0x80131EA4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80131EA8: bne         $s6, $zero, L_80131EB4
    if (ctx->r22 != 0) {
        // 0x80131EAC: nop
    
            goto L_80131EB4;
    }
    // 0x80131EAC: nop

    // 0x80131EB0: break       7
    do_break(2148736688);
L_80131EB4:
    // 0x80131EB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131EB8: bne         $s6, $at, L_80131ECC
    if (ctx->r22 != ctx->r1) {
        // 0x80131EBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131ECC;
    }
    // 0x80131EBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131EC0: bne         $v1, $at, L_80131ECC
    if (ctx->r3 != ctx->r1) {
        // 0x80131EC4: nop
    
            goto L_80131ECC;
    }
    // 0x80131EC4: nop

    // 0x80131EC8: break       6
    do_break(2148736712);
L_80131ECC:
    // 0x80131ECC: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    // 0x80131ED0: jal         0x800CCFDC
    // 0x80131ED4: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80131ED4: nop

    after_5:
    // 0x80131ED8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131EDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EE0: jal         0x80131BF8
    // 0x80131EE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnPlayers1PBonusSetDigitColors(rdram, ctx);
        goto after_6;
    // 0x80131EE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80131EE8: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80131EEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80131EF0: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131EF4: beq         $s5, $zero, L_80131F04
    if (ctx->r21 == 0) {
        // 0x80131EF8: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80131F04;
    }
    // 0x80131EF8: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131EFC: b           L_80131F14
    // 0x80131F00: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131F14;
    // 0x80131F00: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131F04:
    // 0x80131F04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131F08: jal         0x80131C40
    // 0x80131F0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PBonusGetNumberDigitCount(rdram, ctx);
        goto after_7;
    // 0x80131F0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80131F10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131F14:
    // 0x80131F14: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80131F18: bnel        $at, $zero, L_80131E3C
    if (ctx->r1 != 0) {
        // 0x80131F1C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131E3C;
    }
    goto skip_0;
    // 0x80131F1C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_0:
L_80131F20:
    // 0x80131F20: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80131F24: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80131F28: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80131F2C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80131F30: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80131F34: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80131F38: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80131F3C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F40: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80131F44: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80131F48: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80131F4C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80131F50: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80131F54: jr          $ra
    // 0x80131F58: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80131F58: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void gcDrawDObjTreeDLDoubleArray(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015890: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80015894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80015898: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001589C: lbu         $v0, 0x54($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X54);
    // 0x800158A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800158A4: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x800158A8: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x800158AC: bne         $t6, $zero, L_80015A18
    if (ctx->r14 != 0) {
        // 0x800158B0: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80015A18;
    }
    // 0x800158B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800158B4: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x800158B8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800158BC: beq         $s0, $zero, L_800158DC
    if (ctx->r16 == 0) {
        // 0x800158C0: swc1        $f4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
            goto L_800158DC;
    }
    // 0x800158C0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800158C4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800158C8: lw          $t7, 0x72A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72A8);
    // 0x800158CC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800158D0: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800158D4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800158D8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_800158DC:
    // 0x800158DC: beq         $s0, $zero, L_8001591C
    if (ctx->r16 == 0) {
        // 0x800158E0: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_8001591C;
    }
    // 0x800158E0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800158E4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800158E8: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x800158EC: beq         $t1, $zero, L_8001591C
    if (ctx->r9 == 0) {
        // 0x800158F0: nop
    
            goto L_8001591C;
    }
    // 0x800158F0: nop

    // 0x800158F4: bne         $t2, $zero, L_8001591C
    if (ctx->r10 != 0) {
        // 0x800158F8: lui         $a3, 0x8004
        ctx->r7 = S32(0X8004 << 16);
            goto L_8001591C;
    }
    // 0x800158F8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800158FC: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x80015900: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80015904: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x80015908: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8001590C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80015910: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80015914: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80015918: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_8001591C:
    // 0x8001591C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80015920: addiu       $a0, $a3, 0x65B0
    ctx->r4 = ADD32(ctx->r7, 0X65B0);
    // 0x80015924: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80015928: jal         0x80010D70
    // 0x8001592C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x8001592C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x80015930: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80015934: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x80015938: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001593C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80015940: beq         $s0, $zero, L_800159A4
    if (ctx->r16 == 0) {
        // 0x80015944: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_800159A4;
    }
    // 0x80015944: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80015948: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x8001594C: beql        $t6, $zero, L_800159A8
    if (ctx->r14 == 0) {
        // 0x80015950: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_800159A8;
    }
    goto skip_0;
    // 0x80015950: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_0:
    // 0x80015954: lbu         $t7, 0x54($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X54);
    // 0x80015958: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8001595C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80015960: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80015964: bnel        $t8, $zero, L_800159A8
    if (ctx->r24 != 0) {
        // 0x80015968: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_800159A8;
    }
    goto skip_1;
    // 0x80015968: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_1:
    // 0x8001596C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80015970: jal         0x80012D90
    // 0x80015974: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x80015974: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x80015978: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8001597C: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x80015980: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80015984: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80015988: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001598C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80015990: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80015994: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x80015998: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8001599C: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x800159A0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_800159A4:
    // 0x800159A4: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
L_800159A8:
    // 0x800159A8: beql        $a0, $zero, L_800159C8
    if (ctx->r4 == 0) {
        // 0x800159AC: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_800159C8;
    }
    goto skip_2;
    // 0x800159AC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x800159B0: jal         0x80015890
    // 0x800159B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcDrawDObjTreeDLDoubleArray(rdram, ctx);
        goto after_2;
    // 0x800159B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x800159B8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800159BC: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x800159C0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800159C4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_800159C8:
    // 0x800159C8: beql        $t3, $zero, L_80015A10
    if (ctx->r11 == 0) {
        // 0x800159CC: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80015A10;
    }
    goto skip_3;
    // 0x800159CC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x800159D0: lw          $t4, 0x14($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X14);
    // 0x800159D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800159D8: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800159DC: beql        $t4, $at, L_800159F4
    if (ctx->r12 == ctx->r1) {
        // 0x800159E0: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_800159F4;
    }
    goto skip_4;
    // 0x800159E0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    skip_4:
    // 0x800159E4: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800159E8: beql        $t5, $zero, L_80015A10
    if (ctx->r13 == 0) {
        // 0x800159EC: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80015A10;
    }
    goto skip_5;
    // 0x800159EC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800159F0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_800159F4:
    // 0x800159F4: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800159F8: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800159FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80015A00: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80015A04: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80015A08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80015A0C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_80015A10:
    // 0x80015A10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015A14: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_80015A18:
    // 0x80015A18: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x80015A1C: bnel        $t9, $zero, L_80015A48
    if (ctx->r25 != 0) {
        // 0x80015A20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80015A48;
    }
    goto skip_6;
    // 0x80015A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80015A24: lw          $s0, 0x8($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X8);
    // 0x80015A28: beql        $s0, $zero, L_80015A48
    if (ctx->r16 == 0) {
        // 0x80015A2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80015A48;
    }
    goto skip_7;
    // 0x80015A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_80015A30:
    // 0x80015A30: jal         0x80015890
    // 0x80015A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcDrawDObjTreeDLDoubleArray(rdram, ctx);
        goto after_3;
    // 0x80015A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80015A38: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80015A3C: bne         $s0, $zero, L_80015A30
    if (ctx->r16 != 0) {
        // 0x80015A40: nop
    
            goto L_80015A30;
    }
    // 0x80015A40: nop

    // 0x80015A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80015A48:
    // 0x80015A48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80015A4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80015A50: jr          $ra
    // 0x80015A54: nop

    return;
    // 0x80015A54: nop

;}
RECOMP_FUNC void func_ovl26_801345F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801345F0: jr          $ra
    // 0x801345F4: nop

    return;
    // 0x801345F4: nop

;}
RECOMP_FUNC void itCapsuleHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801740FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174104: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174108: addiu       $a1, $a1, -0x699C
    ctx->r5 = ADD32(ctx->r5, -0X699C);
    // 0x8017410C: jal         0x80172EC8
    // 0x80174110: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80174110: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80174114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017411C: jr          $ra
    // 0x80174120: nop

    return;
    // 0x80174120: nop

;}
RECOMP_FUNC void mnVSResultsWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D84: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132D88: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132D8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132D98: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80132D9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132DA0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132DA4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132DA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132DAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132DB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132DB4: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80132DB8: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80132DBC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132DC0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132DC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132DC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132DCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132DD0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80132DD4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80132DD8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80132DDC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80132DE0: lbu         $t4, 0x29($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X29);
    // 0x80132DE4: lbu         $t7, 0x28($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X28);
    // 0x80132DE8: lbu         $t9, 0x2A($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2A);
    // 0x80132DEC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80132DF0: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x80132DF4: lbu         $t7, 0x2B($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2B);
    // 0x80132DF8: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80132DFC: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x80132E00: or          $t8, $t6, $t4
    ctx->r24 = ctx->r14 | ctx->r12;
    // 0x80132E04: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80132E08: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132E0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132E10: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80132E14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132E18: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132E1C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80132E20: lbu         $t6, 0x61($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X61);
    // 0x80132E24: lbu         $t8, 0x60($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X60);
    // 0x80132E28: lbu         $t9, 0x62($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X62);
    // 0x80132E2C: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x80132E30: sll         $t7, $t8, 24
    ctx->r15 = S32(ctx->r24 << 24);
    // 0x80132E34: lbu         $t8, 0x63($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X63);
    // 0x80132E38: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x80132E3C: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x80132E40: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80132E44: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80132E48: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132E4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132E50: lui         $t6, 0xFC30
    ctx->r14 = S32(0XFC30 << 16);
    // 0x80132E54: lui         $t4, 0x55FE
    ctx->r12 = S32(0X55FE << 16);
    // 0x80132E58: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80132E5C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132E60: ori         $t4, $t4, 0xFD7E
    ctx->r12 = ctx->r12 | 0XFD7E;
    // 0x80132E64: ori         $t6, $t6, 0xFE61
    ctx->r14 = ctx->r14 | 0XFE61;
    // 0x80132E68: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132E6C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80132E70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132E74: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80132E78: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80132E7C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132E80: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132E84: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132E88: ori         $t9, $t9, 0x2048
    ctx->r25 = ctx->r25 | 0X2048;
    // 0x80132E8C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132E90: jal         0x800CCF74
    // 0x80132E94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x80132E94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_0:
    // 0x80132E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132EA0: jr          $ra
    // 0x80132EA4: nop

    return;
    // 0x80132EA4: nop

;}
RECOMP_FUNC void func_ovl0_800C99CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C99CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C99D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C99D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C99D8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800C99DC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C99E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C99E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C99E8: addiu       $t6, $t6, 0x5CA0
    ctx->r14 = ADD32(ctx->r14, 0X5CA0);
    // 0x800C99EC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800C99F0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C99F4: lw          $a0, 0x84($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X84);
    // 0x800C99F8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800C99FC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800C9A00: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800C9A04: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800C9A08: jal         0x800EDF24
    // 0x800C9A0C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x800C9A0C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    after_0:
    // 0x800C9A10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C9A14: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800C9A18: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9A1C: jal         0x8001B9C4
    // 0x800C9A20: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    syMatrixTra(rdram, ctx);
        goto after_1;
    // 0x800C9A20: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800C9A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9A28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C9A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C9A30: jr          $ra
    // 0x800C9A34: nop

    return;
    // 0x800C9A34: nop

;}
RECOMP_FUNC void unref_80015860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015860: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015864: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001586C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015874: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80015878: jal         0x80015520
    // 0x8001587C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    func_80015520(rdram, ctx);
        goto after_0;
    // 0x8001587C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    after_0:
    // 0x80015880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015888: jr          $ra
    // 0x8001588C: nop

    return;
    // 0x8001588C: nop

;}
RECOMP_FUNC void wpLinkSpinAttackProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C9B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C9B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C9BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016C9C0: lb          $t6, 0x2B4($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X2B4);
    // 0x8016C9C4: beql        $t6, $zero, L_8016C9D8
    if (ctx->r14 == 0) {
        // 0x8016C9C8: lwc1        $f2, 0x2AC($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X2AC);
            goto L_8016C9D8;
    }
    goto skip_0;
    // 0x8016C9C8: lwc1        $f2, 0x2AC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2AC);
    skip_0:
    // 0x8016C9CC: b           L_8016CA8C
    // 0x8016C9D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016CA8C;
    // 0x8016C9D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016C9D4: lwc1        $f2, 0x2AC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2AC);
L_8016C9D8:
    // 0x8016C9D8: lwc1        $f14, 0x2B0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X2B0);
    // 0x8016C9DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8016C9E0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8016C9E4: nop

    // 0x8016C9E8: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8016C9EC: jal         0x80033510
    // 0x8016C9F0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8016C9F0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8016C9F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8016C9F8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C9FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CA00: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8016CA04: nop

    // 0x8016CA08: bc1fl       L_8016CA8C
    if (!c1cs) {
        // 0x8016CA0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016CA8C;
    }
    goto skip_1;
    // 0x8016CA0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8016CA10: lwc1        $f14, -0x34A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X34A0);
    // 0x8016CA14: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8016CA18: nop

    // 0x8016CA1C: bc1fl       L_8016CA30
    if (!c1cs) {
        // 0x8016CA20: sub.s       $f12, $f0, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
            goto L_8016CA30;
    }
    goto skip_2;
    // 0x8016CA20: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    skip_2:
    // 0x8016CA24: b           L_8016CA30
    // 0x8016CA28: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_8016CA30;
    // 0x8016CA28: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8016CA2C: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
L_8016CA30:
    // 0x8016CA30: lwc1        $f8, 0x2AC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2AC);
    // 0x8016CA34: lwc1        $f18, 0x2B0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X2B0);
    // 0x8016CA38: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8016CA3C: lwc1        $f8, 0x110($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X110);
    // 0x8016CA40: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8016CA44: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8016CA48: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8016CA4C: swc1        $f16, 0x2AC($v0)
    MEM_W(0X2AC, ctx->r2) = ctx->f16.u32l;
    // 0x8016CA50: lwc1        $f2, 0x2AC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2AC);
    // 0x8016CA54: lwc1        $f16, 0x114($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X114);
    // 0x8016CA58: lwc1        $f4, 0x11C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X11C);
    // 0x8016CA5C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8016CA60: lwc1        $f8, 0x120($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X120);
    // 0x8016CA64: swc1        $f10, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f10.u32l;
    // 0x8016CA68: swc1        $f6, 0x2B0($v0)
    MEM_W(0X2B0, ctx->r2) = ctx->f6.u32l;
    // 0x8016CA6C: lwc1        $f14, 0x2B0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X2B0);
    // 0x8016CA70: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8016CA74: add.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8016CA78: swc1        $f6, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->f6.u32l;
    // 0x8016CA7C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8016CA80: swc1        $f18, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f18.u32l;
    // 0x8016CA84: swc1        $f10, 0x120($v0)
    MEM_W(0X120, ctx->r2) = ctx->f10.u32l;
    // 0x8016CA88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016CA8C:
    // 0x8016CA8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016CA90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016CA94: jr          $ra
    // 0x8016CA98: nop

    return;
    // 0x8016CA98: nop

;}
RECOMP_FUNC void ftKirbyThrowFLandingProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A538: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014A53C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014A540: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014A544: lw          $t6, 0x14C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14C);
    // 0x8014A548: bnel        $t6, $zero, L_8014A564
    if (ctx->r14 != 0) {
        // 0x8014A54C: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_8014A564;
    }
    goto skip_0;
    // 0x8014A54C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_0:
    // 0x8014A550: jal         0x80149B78
    // 0x8014A554: nop

    ftCommonCatchProcMap(rdram, ctx);
        goto after_0;
    // 0x8014A554: nop

    after_0:
    // 0x8014A558: b           L_8014A5A0
    // 0x8014A55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014A5A0;
    // 0x8014A55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014A560: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_8014A564:
    // 0x8014A564: jal         0x800DE6B0
    // 0x8014A568: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_1;
    // 0x8014A568: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8014A56C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014A570: beq         $v0, $zero, L_8014A59C
    if (ctx->r2 == 0) {
        // 0x8014A574: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8014A59C;
    }
    // 0x8014A574: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014A578: lwc1        $f4, 0x4C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8014A57C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014A580: nop

    // 0x8014A584: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8014A588: nop

    // 0x8014A58C: bc1fl       L_8014A5A0
    if (!c1cs) {
        // 0x8014A590: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014A5A0;
    }
    goto skip_1;
    // 0x8014A590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8014A594: jal         0x800DE8E4
    // 0x8014A598: nop

    mpCommonSetFighterWaitOrLanding(rdram, ctx);
        goto after_2;
    // 0x8014A598: nop

    after_2:
L_8014A59C:
    // 0x8014A59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014A5A0:
    // 0x8014A5A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014A5A4: jr          $ra
    // 0x8014A5A8: nop

    return;
    // 0x8014A5A8: nop

;}
RECOMP_FUNC void ftYoshiSpecialLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EFE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015EFE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015EFEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015EFF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015EFF4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015EFF8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8015EFFC: addiu       $t7, $t7, -0x102C
    ctx->r15 = ADD32(ctx->r15, -0X102C);
    // 0x8015F000: sw          $t7, 0xA0C($s0)
    MEM_W(0XA0C, ctx->r16) = ctx->r15;
    // 0x8015F004: jal         0x800DEEC8
    // 0x8015F008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015F008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015F00C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015F010: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8015F014: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015F018: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015F01C: jal         0x800E6F24
    // 0x8015F020: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015F020: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015F024: jal         0x800E0830
    // 0x8015F028: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015F028: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015F02C: lw          $t8, 0x9C8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X9C8);
    // 0x8015F030: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x8015F034: sb          $t9, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r25;
    // 0x8015F038: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015F03C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015F040: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015F044: jr          $ra
    // 0x8015F048: nop

    return;
    // 0x8015F048: nop

;}
RECOMP_FUNC void itProcessProcHitCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801710C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801710C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801710CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801710D0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801710D4: lw          $v0, 0x298($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X298);
    // 0x801710D8: beql        $v0, $zero, L_80171138
    if (ctx->r2 == 0) {
        // 0x801710DC: lw          $t1, 0x264($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X264);
            goto L_80171138;
    }
    goto skip_0;
    // 0x801710DC: lw          $t1, 0x264($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X264);
    skip_0:
    // 0x801710E0: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x801710E4: addiu       $t0, $zero, 0x3E7
    ctx->r8 = ADD32(0, 0X3E7);
    // 0x801710E8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801710EC: slti        $at, $t8, 0x3E8
    ctx->r1 = SIGNED(ctx->r24) < 0X3E8 ? 1 : 0;
    // 0x801710F0: bne         $at, $zero, L_80171100
    if (ctx->r1 != 0) {
        // 0x801710F4: sw          $t8, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r24;
            goto L_80171100;
    }
    // 0x801710F4: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x801710F8: sw          $t0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r8;
    // 0x801710FC: lw          $v0, 0x298($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X298);
L_80171100:
    // 0x80171100: lw          $a1, 0x394($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X394);
    // 0x80171104: sw          $v0, 0x2BC($v1)
    MEM_W(0X2BC, ctx->r3) = ctx->r2;
    // 0x80171108: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017110C: beql        $a1, $zero, L_80171138
    if (ctx->r5 == 0) {
        // 0x80171110: lw          $t1, 0x264($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X264);
            goto L_80171138;
    }
    goto skip_1;
    // 0x80171110: lw          $t1, 0x264($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X264);
    skip_1:
    // 0x80171114: jalr        $a1
    // 0x80171118: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x80171118: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017111C: beq         $v0, $zero, L_80171134
    if (ctx->r2 == 0) {
        // 0x80171120: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80171134;
    }
    // 0x80171120: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80171124: jal         0x801728D4
    // 0x80171128: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainDestroyItem(rdram, ctx);
        goto after_1;
    // 0x80171128: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017112C: b           L_801713A4
    // 0x80171130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801713A4;
    // 0x80171130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171134:
    // 0x80171134: lw          $t1, 0x264($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X264);
L_80171138:
    // 0x80171138: bnel        $t1, $zero, L_80171150
    if (ctx->r9 != 0) {
        // 0x8017113C: lw          $v0, 0x380($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X380);
            goto L_80171150;
    }
    goto skip_2;
    // 0x8017113C: lw          $v0, 0x380($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X380);
    skip_2:
    // 0x80171140: lw          $t2, 0x26C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X26C);
    // 0x80171144: beql        $t2, $zero, L_80171180
    if (ctx->r10 == 0) {
        // 0x80171148: lw          $t3, 0x274($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X274);
            goto L_80171180;
    }
    goto skip_3;
    // 0x80171148: lw          $t3, 0x274($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X274);
    skip_3:
    // 0x8017114C: lw          $v0, 0x380($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X380);
L_80171150:
    // 0x80171150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80171154: beql        $v0, $zero, L_80171180
    if (ctx->r2 == 0) {
        // 0x80171158: lw          $t3, 0x274($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X274);
            goto L_80171180;
    }
    goto skip_4;
    // 0x80171158: lw          $t3, 0x274($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X274);
    skip_4:
    // 0x8017115C: jalr        $v0
    // 0x80171160: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80171160: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80171164: beq         $v0, $zero, L_8017117C
    if (ctx->r2 == 0) {
        // 0x80171168: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8017117C;
    }
    // 0x80171168: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017116C: jal         0x801728D4
    // 0x80171170: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainDestroyItem(rdram, ctx);
        goto after_3;
    // 0x80171170: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80171174: b           L_801713A4
    // 0x80171178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801713A4;
    // 0x80171178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017117C:
    // 0x8017117C: lw          $t3, 0x274($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X274);
L_80171180:
    // 0x80171180: beql        $t3, $zero, L_80171258
    if (ctx->r11 == 0) {
        // 0x80171184: lw          $t8, 0x270($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X270);
            goto L_80171258;
    }
    goto skip_5;
    // 0x80171184: lw          $t8, 0x270($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X270);
    skip_5:
    // 0x80171188: lw          $t4, 0x158($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X158);
    // 0x8017118C: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80171190: bgezl       $t6, L_80171228
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80171194: lw          $v0, 0x384($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X384);
            goto L_80171228;
    }
    goto skip_6;
    // 0x80171194: lw          $v0, 0x384($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X384);
    skip_6:
    // 0x80171198: lw          $t7, 0x108($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X108);
    // 0x8017119C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801711A0: bne         $t7, $at, L_80171224
    if (ctx->r15 != ctx->r1) {
        // 0x801711A4: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80171224;
    }
    // 0x801711A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801711A8: lwc1        $f4, -0x33A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X33A8);
    // 0x801711AC: lwc1        $f0, 0x278($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X278);
    // 0x801711B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801711B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801711B8: nop

    // 0x801711BC: bc1fl       L_80171228
    if (!c1cs) {
        // 0x801711C0: lw          $v0, 0x384($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X384);
            goto L_80171228;
    }
    goto skip_7;
    // 0x801711C0: lw          $v0, 0x384($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X384);
    skip_7:
    // 0x801711C4: lwc1        $f6, -0x33A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X33A4);
    // 0x801711C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801711CC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801711D0: swc1        $f8, 0x278($v1)
    MEM_W(0X278, ctx->r3) = ctx->f8.u32l;
    // 0x801711D4: lwc1        $f10, 0x278($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X278);
    // 0x801711D8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x801711DC: nop

    // 0x801711E0: bc1fl       L_801711F8
    if (!c1cs) {
        // 0x801711E4: lw          $v0, 0x388($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X388);
            goto L_801711F8;
    }
    goto skip_8;
    // 0x801711E4: lw          $v0, 0x388($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X388);
    skip_8:
    // 0x801711E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801711EC: nop

    // 0x801711F0: swc1        $f18, 0x278($v1)
    MEM_W(0X278, ctx->r3) = ctx->f18.u32l;
    // 0x801711F4: lw          $v0, 0x388($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X388);
L_801711F8:
    // 0x801711F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801711FC: beql        $v0, $zero, L_80171258
    if (ctx->r2 == 0) {
        // 0x80171200: lw          $t8, 0x270($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X270);
            goto L_80171258;
    }
    goto skip_9;
    // 0x80171200: lw          $t8, 0x270($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X270);
    skip_9:
    // 0x80171204: jalr        $v0
    // 0x80171208: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80171208: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8017120C: beq         $v0, $zero, L_80171254
    if (ctx->r2 == 0) {
        // 0x80171210: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80171254;
    }
    // 0x80171210: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80171214: jal         0x801728D4
    // 0x80171218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainDestroyItem(rdram, ctx);
        goto after_5;
    // 0x80171218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8017121C: b           L_801713A4
    // 0x80171220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801713A4;
    // 0x80171220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171224:
    // 0x80171224: lw          $v0, 0x384($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X384);
L_80171228:
    // 0x80171228: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017122C: beql        $v0, $zero, L_80171258
    if (ctx->r2 == 0) {
        // 0x80171230: lw          $t8, 0x270($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X270);
            goto L_80171258;
    }
    goto skip_10;
    // 0x80171230: lw          $t8, 0x270($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X270);
    skip_10:
    // 0x80171234: jalr        $v0
    // 0x80171238: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80171238: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_6:
    // 0x8017123C: beq         $v0, $zero, L_80171254
    if (ctx->r2 == 0) {
        // 0x80171240: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80171254;
    }
    // 0x80171240: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80171244: jal         0x801728D4
    // 0x80171248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainDestroyItem(rdram, ctx);
        goto after_7;
    // 0x80171248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8017124C: b           L_801713A4
    // 0x80171250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801713A4;
    // 0x80171250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171254:
    // 0x80171254: lw          $t8, 0x270($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X270);
L_80171258:
    // 0x80171258: beql        $t8, $zero, L_80171294
    if (ctx->r24 == 0) {
        // 0x8017125C: lw          $a0, 0x288($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X288);
            goto L_80171294;
    }
    goto skip_11;
    // 0x8017125C: lw          $a0, 0x288($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X288);
    skip_11:
    // 0x80171260: lw          $v0, 0x38C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X38C);
    // 0x80171264: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80171268: beql        $v0, $zero, L_80171294
    if (ctx->r2 == 0) {
        // 0x8017126C: lw          $a0, 0x288($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X288);
            goto L_80171294;
    }
    goto skip_12;
    // 0x8017126C: lw          $a0, 0x288($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X288);
    skip_12:
    // 0x80171270: jalr        $v0
    // 0x80171274: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x80171274: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_8:
    // 0x80171278: beq         $v0, $zero, L_80171290
    if (ctx->r2 == 0) {
        // 0x8017127C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80171290;
    }
    // 0x8017127C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80171280: jal         0x801728D4
    // 0x80171284: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainDestroyItem(rdram, ctx);
        goto after_9;
    // 0x80171284: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80171288: b           L_801713A4
    // 0x8017128C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801713A4;
    // 0x8017128C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171290:
    // 0x80171290: lw          $a0, 0x288($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X288);
L_80171294:
    // 0x80171294: beql        $a0, $zero, L_80171358
    if (ctx->r4 == 0) {
        // 0x80171298: lw          $a0, 0x2BC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X2BC);
            goto L_80171358;
    }
    goto skip_13;
    // 0x80171298: lw          $a0, 0x2BC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2BC);
    skip_13:
    // 0x8017129C: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x801712A0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801712A4: lw          $a1, 0x390($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X390);
    // 0x801712A8: lhu         $t4, 0x28C($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X28C);
    // 0x801712AC: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    // 0x801712B0: lhu         $t5, 0x28E($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X28E);
    // 0x801712B4: sb          $t9, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r25;
    // 0x801712B8: lbu         $t0, 0xD($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XD);
    // 0x801712BC: sb          $t0, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r8;
    // 0x801712C0: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x801712C4: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x801712C8: lbu         $t2, 0x12($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X12);
    // 0x801712CC: sh          $t4, 0x15C($v1)
    MEM_H(0X15C, ctx->r3) = ctx->r12;
    // 0x801712D0: sh          $t5, 0x15E($v1)
    MEM_H(0X15E, ctx->r3) = ctx->r13;
    // 0x801712D4: beq         $a1, $zero, L_80171300
    if (ctx->r5 == 0) {
        // 0x801712D8: sb          $t2, 0x16($v1)
        MEM_B(0X16, ctx->r3) = ctx->r10;
            goto L_80171300;
    }
    // 0x801712D8: sb          $t2, 0x16($v1)
    MEM_B(0X16, ctx->r3) = ctx->r10;
    // 0x801712DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801712E0: jalr        $a1
    // 0x801712E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_10;
    // 0x801712E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_10:
    // 0x801712E8: beq         $v0, $zero, L_80171300
    if (ctx->r2 == 0) {
        // 0x801712EC: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80171300;
    }
    // 0x801712EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801712F0: jal         0x801728D4
    // 0x801712F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainDestroyItem(rdram, ctx);
        goto after_11;
    // 0x801712F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x801712F8: b           L_801713A4
    // 0x801712FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801713A4;
    // 0x801712FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171300:
    // 0x80171300: lw          $t6, 0x2D0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2D0);
    // 0x80171304: sll         $t8, $t6, 30
    ctx->r24 = S32(ctx->r14 << 30);
    // 0x80171308: bltzl       $t8, L_80171358
    if (SIGNED(ctx->r24) < 0) {
        // 0x8017130C: lw          $a0, 0x2BC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X2BC);
            goto L_80171358;
    }
    goto skip_14;
    // 0x8017130C: lw          $a0, 0x2BC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2BC);
    skip_14:
    // 0x80171310: lw          $t9, 0x110($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X110);
    // 0x80171314: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80171318: lwc1        $f8, -0x33A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X33A0);
    // 0x8017131C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80171320: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80171324: lwc1        $f16, -0x339C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X339C);
    // 0x80171328: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017132C: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80171330: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80171334: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80171338: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8017133C: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80171340: nop

    // 0x80171344: slti        $at, $t1, 0x65
    ctx->r1 = SIGNED(ctx->r9) < 0X65 ? 1 : 0;
    // 0x80171348: bne         $at, $zero, L_80171354
    if (ctx->r1 != 0) {
        // 0x8017134C: sw          $t1, 0x110($v1)
        MEM_W(0X110, ctx->r3) = ctx->r9;
            goto L_80171354;
    }
    // 0x8017134C: sw          $t1, 0x110($v1)
    MEM_W(0X110, ctx->r3) = ctx->r9;
    // 0x80171350: sw          $t3, 0x110($v1)
    MEM_W(0X110, ctx->r3) = ctx->r11;
L_80171354:
    // 0x80171354: lw          $a0, 0x2BC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2BC);
L_80171358:
    // 0x80171358: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8017135C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80171360: beql        $a0, $zero, L_8017137C
    if (ctx->r4 == 0) {
        // 0x80171364: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8017137C;
    }
    goto skip_15;
    // 0x80171364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_15:
    // 0x80171368: jal         0x800EA1C0
    // 0x8017136C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftParamGetHitLag(rdram, ctx);
        goto after_12;
    // 0x8017136C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_12:
    // 0x80171370: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80171374: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x80171378: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8017137C:
    // 0x8017137C: sw          $zero, 0x264($v1)
    MEM_W(0X264, ctx->r3) = 0;
    // 0x80171380: sw          $zero, 0x26C($v1)
    MEM_W(0X26C, ctx->r3) = 0;
    // 0x80171384: sw          $zero, 0x270($v1)
    MEM_W(0X270, ctx->r3) = 0;
    // 0x80171388: sw          $zero, 0x274($v1)
    MEM_W(0X274, ctx->r3) = 0;
    // 0x8017138C: sw          $zero, 0x288($v1)
    MEM_W(0X288, ctx->r3) = 0;
    // 0x80171390: sw          $zero, 0x290($v1)
    MEM_W(0X290, ctx->r3) = 0;
    // 0x80171394: sw          $zero, 0x298($v1)
    MEM_W(0X298, ctx->r3) = 0;
    // 0x80171398: sw          $zero, 0x2BC($v1)
    MEM_W(0X2BC, ctx->r3) = 0;
    // 0x8017139C: swc1        $f6, 0x294($v1)
    MEM_W(0X294, ctx->r3) = ctx->f6.u32l;
    // 0x801713A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801713A4:
    // 0x801713A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801713A8: jr          $ra
    // 0x801713AC: nop

    return;
    // 0x801713AC: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePortraitFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013405C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80134060: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80134064: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80134068: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013406C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80134070: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80134074: addiu       $t8, $t8, -0x7AA8
    ctx->r24 = ADD32(ctx->r24, -0X7AA8);
    // 0x80134078: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8013407C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134080: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80134084: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80134088: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013408C: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x80134090: jal         0x80132020
    // 0x80134094: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    mnPlayers1PTrainingGetPortrait(rdram, ctx);
        goto after_0;
    // 0x80134094: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80134098: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013409C: jal         0x80133F68
    // 0x801340A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayers1PTrainingDestroyPortraitFlash(rdram, ctx);
        goto after_1;
    // 0x801340A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x801340A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801340A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801340AC: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x801340B0: jal         0x80009968
    // 0x801340B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x801340B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801340B8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801340BC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x801340C0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801340C4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801340C8: sw          $v0, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->r2;
    // 0x801340CC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801340D0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801340D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801340D8: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    // 0x801340DC: jal         0x80009DF4
    // 0x801340E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x801340E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x801340E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x801340E8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x801340EC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801340F0: addiu       $a1, $a1, 0x3FB4
    ctx->r5 = ADD32(ctx->r5, 0X3FB4);
    // 0x801340F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801340F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801340FC: jal         0x80008188
    // 0x80134100: sw          $t1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r9;
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80134100: sw          $t1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r9;
    after_4:
    // 0x80134104: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80134108: lw          $t2, -0x7350($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7350);
    // 0x8013410C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80134110: addiu       $t3, $t3, 0x6F0
    ctx->r11 = ADD32(ctx->r11, 0X6F0);
    // 0x80134114: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80134118: jal         0x800CCFDC
    // 0x8013411C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8013411C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_5:
    // 0x80134120: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80134124: bne         $at, $zero, L_80134134
    if (ctx->r1 != 0) {
        // 0x80134128: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80134134;
    }
    // 0x80134128: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8013412C: b           L_80134134
    // 0x80134130: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
        goto L_80134134;
    // 0x80134130: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
L_80134134:
    // 0x80134134: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80134138: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8013413C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80134140: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80134144: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80134148: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x8013414C: addiu       $t5, $t4, 0x1A
    ctx->r13 = ADD32(ctx->r12, 0X1A);
    // 0x80134150: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80134154: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80134158: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013415C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134160: bne         $at, $zero, L_80134170
    if (ctx->r1 != 0) {
        // 0x80134164: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_80134170;
    }
    // 0x80134164: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80134168: b           L_80134170
    // 0x8013416C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80134170;
    // 0x8013416C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80134170:
    // 0x80134170: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80134174: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80134178: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013417C: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80134180: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80134184: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80134188: addiu       $t7, $t6, 0x25
    ctx->r15 = ADD32(ctx->r14, 0X25);
    // 0x8013418C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80134190: nop

    // 0x80134194: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134198: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x8013419C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801341A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801341A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801341A8: jr          $ra
    // 0x801341AC: nop

    return;
    // 0x801341AC: nop

;}
RECOMP_FUNC void ftCommonThrownSetStatusQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AC0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014AC10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014AC14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014AC18: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8014AC1C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014AC20: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8014AC24: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014AC28: lw          $t6, 0x844($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X844);
    // 0x8014AC2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014AC30: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014AC34: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x8014AC38: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8014AC3C: sw          $t8, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r24;
    // 0x8014AC40: sb          $t9, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r25;
    // 0x8014AC44: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014AC48: jal         0x800E6F24
    // 0x8014AC4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014AC4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8014AC50: jal         0x800E0830
    // 0x8014AC54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8014AC54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8014AC58: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8014AC5C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8014AC60: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8014AC64: beq         $v0, $at, L_8014AC74
    if (ctx->r2 == ctx->r1) {
        // 0x8014AC68: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8014AC74;
    }
    // 0x8014AC68: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8014AC6C: bnel        $v0, $at, L_8014AC90
    if (ctx->r2 != ctx->r1) {
        // 0x8014AC70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8014AC90;
    }
    goto skip_0;
    // 0x8014AC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_8014AC74:
    // 0x8014AC74: lbu         $t2, 0x18D($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X18D);
    // 0x8014AC78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8014AC7C: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8014AC80: sb          $t3, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r11;
    // 0x8014AC84: jal         0x800E8A24
    // 0x8014AC88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_2;
    // 0x8014AC88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8014AC8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8014AC90:
    // 0x8014AC90: jal         0x800E8098
    // 0x8014AC94: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_3;
    // 0x8014AC94: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_3:
    // 0x8014AC98: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8014AC9C: sw          $t4, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r12;
    // 0x8014ACA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014ACA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014ACA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014ACAC: jr          $ra
    // 0x8014ACB0: nop

    return;
    // 0x8014ACB0: nop

;}
RECOMP_FUNC void ftYoshiSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E5EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015E5F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E5F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015E5F8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015E5FC: jal         0x800DEEC8
    // 0x8015E600: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015E600: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015E604: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015E608: addiu       $t7, $zero, 0x25
    ctx->r15 = ADD32(0, 0X25);
    // 0x8015E60C: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x8015E610: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E614: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015E618: jal         0x800E6F24
    // 0x8015E61C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E61C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015E620: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E624: addiu       $a1, $a1, -0x1780
    ctx->r5 = ADD32(ctx->r5, -0X1780);
    // 0x8015E628: jal         0x8015E310
    // 0x8015E62C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftYoshiSpecialNSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x8015E62C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015E630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015E638: jr          $ra
    // 0x8015E63C: nop

    return;
    // 0x8015E63C: nop

;}
RECOMP_FUNC void func_80015C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015C0C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80015C10: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80015C14: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80015C18: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80015C1C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80015C20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80015C24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80015C28: lbu         $t6, 0x54($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X54);
    // 0x80015C2C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80015C30: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80015C34: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80015C38: bne         $t7, $zero, L_80015F20
    if (ctx->r15 != 0) {
        // 0x80015C3C: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80015F20;
    }
    // 0x80015C3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015C40: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80015C44: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80015C48: addiu       $s2, $s2, 0x70B0
    ctx->r18 = ADD32(ctx->r18, 0X70B0);
    // 0x80015C4C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80015C50: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x80015C54: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80015C58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015C5C: beql        $s0, $zero, L_80015C7C
    if (ctx->r16 == 0) {
        // 0x80015C60: lw          $t6, 0x0($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X0);
            goto L_80015C7C;
    }
    goto skip_0;
    // 0x80015C60: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x80015C64: lw          $t8, 0x72A8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72A8);
    // 0x80015C68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80015C6C: addu        $t5, $s0, $t9
    ctx->r13 = ADD32(ctx->r16, ctx->r25);
    // 0x80015C70: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x80015C74: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80015C78: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
L_80015C7C:
    // 0x80015C7C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80015C80: jal         0x80010D70
    // 0x80015C84: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x80015C84: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80015C88: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80015C8C: beq         $s0, $zero, L_80015E24
    if (ctx->r16 == 0) {
        // 0x80015C90: or          $t4, $v0, $zero
        ctx->r12 = ctx->r2 | 0;
            goto L_80015E24;
    }
    // 0x80015C90: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x80015C94: beql        $a2, $zero, L_80015E28
    if (ctx->r6 == 0) {
        // 0x80015C98: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80015E28;
    }
    goto skip_1;
    // 0x80015C98: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_1:
    // 0x80015C9C: lbu         $t7, 0x54($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X54);
    // 0x80015CA0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80015CA4: bnel        $t8, $zero, L_80015E28
    if (ctx->r24 != 0) {
        // 0x80015CA8: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80015E28;
    }
    goto skip_2;
    // 0x80015CA8: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_2:
    // 0x80015CAC: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80015CB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80015CB4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80015CB8: beq         $a1, $at, L_80015E24
    if (ctx->r5 == ctx->r1) {
        // 0x80015CBC: addiu       $s1, $s1, 0x65B0
        ctx->r17 = ADD32(ctx->r17, 0X65B0);
            goto L_80015E24;
    }
    // 0x80015CBC: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80015CC0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80015CC4: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x80015CC8: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x80015CCC: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
L_80015CD0:
    // 0x80015CD0: beql        $t9, $zero, L_80015E14
    if (ctx->r25 == 0) {
        // 0x80015CD4: lw          $a1, 0xC($a2)
        ctx->r5 = MEM_W(ctx->r6, 0XC);
            goto L_80015E14;
    }
    goto skip_3;
    // 0x80015CD4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    skip_3:
    // 0x80015CD8: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
    // 0x80015CDC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80015CE0: addu        $v1, $s1, $t6
    ctx->r3 = ADD32(ctx->r17, ctx->r14);
    // 0x80015CE4: beql        $t5, $zero, L_80015D0C
    if (ctx->r13 == 0) {
        // 0x80015CE8: sll         $s0, $a1, 2
        ctx->r16 = S32(ctx->r5 << 2);
            goto L_80015D0C;
    }
    goto skip_4;
    // 0x80015CE8: sll         $s0, $a1, 2
    ctx->r16 = S32(ctx->r5 << 2);
    skip_4:
    // 0x80015CEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80015CF0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80015CF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80015CF8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80015CFC: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x80015D00: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80015D04: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80015D08: sll         $s0, $a1, 2
    ctx->r16 = S32(ctx->r5 << 2);
L_80015D0C:
    // 0x80015D0C: addu        $t9, $a3, $s0
    ctx->r25 = ADD32(ctx->r7, ctx->r16);
    // 0x80015D10: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80015D14: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80015D18: beq         $t5, $a0, L_80015D80
    if (ctx->r13 == ctx->r4) {
        // 0x80015D1C: addu        $t6, $s1, $s0
        ctx->r14 = ADD32(ctx->r17, ctx->r16);
            goto L_80015D80;
    }
    // 0x80015D1C: addu        $t6, $s1, $s0
    ctx->r14 = ADD32(ctx->r17, ctx->r16);
L_80015D20:
    // 0x80015D20: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80015D24: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80015D28: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80015D2C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80015D30: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80015D34: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80015D38: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80015D3C: addu        $v1, $s1, $t6
    ctx->r3 = ADD32(ctx->r17, ctx->r14);
    // 0x80015D40: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80015D44: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80015D48: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80015D4C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80015D50: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80015D54: addu        $v0, $a3, $t5
    ctx->r2 = ADD32(ctx->r7, ctx->r13);
    // 0x80015D58: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80015D5C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80015D60: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80015D64: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80015D68: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80015D6C: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80015D70: addu        $t8, $a3, $s0
    ctx->r24 = ADD32(ctx->r7, ctx->r16);
    // 0x80015D74: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80015D78: bnel        $t9, $a0, L_80015D20
    if (ctx->r25 != ctx->r4) {
        // 0x80015D7C: addu        $t6, $s1, $s0
        ctx->r14 = ADD32(ctx->r17, ctx->r16);
            goto L_80015D20;
    }
    goto skip_5;
    // 0x80015D7C: addu        $t6, $s1, $s0
    ctx->r14 = ADD32(ctx->r17, ctx->r16);
    skip_5:
L_80015D80:
    // 0x80015D80: lw          $t5, 0x80($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X80);
    // 0x80015D84: beql        $t5, $zero, L_80015DF8
    if (ctx->r13 == 0) {
        // 0x80015D88: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_80015DF8;
    }
    goto skip_6;
    // 0x80015D88: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    skip_6:
    // 0x80015D8C: bne         $s4, $zero, L_80015DD0
    if (ctx->r20 != 0) {
        // 0x80015D90: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_80015DD0;
    }
    // 0x80015D90: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x80015D94: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80015D98: lw          $s4, 0x65E4($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X65E4);
    // 0x80015D9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015DA0: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    // 0x80015DA4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80015DA8: jal         0x80012D90
    // 0x80015DAC: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x80015DAC: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    after_1:
    // 0x80015DB0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80015DB4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80015DB8: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x80015DBC: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80015DC0: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x80015DC4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80015DC8: b           L_80015DF4
    // 0x80015DCC: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
        goto L_80015DF4;
    // 0x80015DCC: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_80015DD0:
    // 0x80015DD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80015DD4: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x80015DD8: ori         $t7, $t7, 0x38
    ctx->r15 = ctx->r15 | 0X38;
    // 0x80015DDC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80015DE0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80015DE4: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x80015DE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80015DEC: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80015DF0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_80015DF4:
    // 0x80015DF4: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
L_80015DF8:
    // 0x80015DF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80015DFC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80015E00: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80015E04: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80015E08: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80015E0C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80015E10: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
L_80015E14:
    // 0x80015E14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80015E18: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80015E1C: bnel        $a1, $at, L_80015CD0
    if (ctx->r5 != ctx->r1) {
        // 0x80015E20: lw          $t9, 0x8($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X8);
            goto L_80015CD0;
    }
    goto skip_7;
    // 0x80015E20: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    skip_7:
L_80015E24:
    // 0x80015E24: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
L_80015E28:
    // 0x80015E28: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80015E2C: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80015E30: beql        $a0, $zero, L_80015E48
    if (ctx->r4 == 0) {
        // 0x80015E34: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_80015E48;
    }
    goto skip_8;
    // 0x80015E34: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    skip_8:
    // 0x80015E38: jal         0x80015C0C
    // 0x80015E3C: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    func_80015C0C(rdram, ctx);
        goto after_2;
    // 0x80015E3C: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    after_2:
    // 0x80015E40: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80015E44: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
L_80015E48:
    // 0x80015E48: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80015E4C: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80015E50: lui         $t1, 0xD838
    ctx->r9 = S32(0XD838 << 16);
    // 0x80015E54: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x80015E58: addiu       $t3, $t3, 0x70C8
    ctx->r11 = ADD32(ctx->r11, 0X70C8);
    // 0x80015E5C: addiu       $a2, $a2, 0x70B8
    ctx->r6 = ADD32(ctx->r6, 0X70B8);
    // 0x80015E60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80015E64: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80015E68: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80015E6C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
L_80015E70:
    // 0x80015E70: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80015E74: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80015E78: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x80015E7C: beql        $at, $zero, L_80015EC4
    if (ctx->r1 == 0) {
        // 0x80015E80: lw          $t5, 0x4($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X4);
            goto L_80015EC4;
    }
    goto skip_9;
    // 0x80015E80: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
    skip_9:
    // 0x80015E84: beq         $t4, $zero, L_80015EC0
    if (ctx->r12 == 0) {
        // 0x80015E88: sw          $a1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r5;
            goto L_80015EC0;
    }
    // 0x80015E88: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80015E8C: lw          $t7, 0x14($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X14);
    // 0x80015E90: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x80015E94: beql        $t0, $t7, L_80015EAC
    if (ctx->r8 == ctx->r15) {
        // 0x80015E98: lw          $a0, 0x0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X0);
            goto L_80015EAC;
    }
    goto skip_10;
    // 0x80015E98: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    skip_10:
    // 0x80015E9C: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x80015EA0: beql        $t8, $zero, L_80015EC4
    if (ctx->r24 == 0) {
        // 0x80015EA4: lw          $t5, 0x4($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X4);
            goto L_80015EC4;
    }
    goto skip_11;
    // 0x80015EA4: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
    skip_11:
    // 0x80015EA8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_80015EAC:
    // 0x80015EAC: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80015EB0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80015EB4: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80015EB8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80015EBC: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
L_80015EC0:
    // 0x80015EC0: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
L_80015EC4:
    // 0x80015EC4: sltu        $at, $a1, $t5
    ctx->r1 = ctx->r5 < ctx->r13 ? 1 : 0;
    // 0x80015EC8: beql        $at, $zero, L_80015F0C
    if (ctx->r1 == 0) {
        // 0x80015ECC: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80015F0C;
    }
    goto skip_12;
    // 0x80015ECC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_12:
    // 0x80015ED0: beq         $t4, $zero, L_80015F08
    if (ctx->r12 == 0) {
        // 0x80015ED4: sw          $a1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r5;
            goto L_80015F08;
    }
    // 0x80015ED4: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x80015ED8: lw          $t6, 0x14($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X14);
    // 0x80015EDC: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x80015EE0: beql        $t0, $t6, L_80015EF8
    if (ctx->r8 == ctx->r14) {
        // 0x80015EE4: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_80015EF8;
    }
    goto skip_13;
    // 0x80015EE4: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_13:
    // 0x80015EE8: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x80015EEC: beql        $t7, $zero, L_80015F0C
    if (ctx->r15 == 0) {
        // 0x80015EF0: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80015F0C;
    }
    goto skip_14;
    // 0x80015EF0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_14:
    // 0x80015EF4: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_80015EF8:
    // 0x80015EF8: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80015EFC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80015F00: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80015F04: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_80015F08:
    // 0x80015F08: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80015F0C:
    // 0x80015F0C: bne         $a2, $t3, L_80015E70
    if (ctx->r6 != ctx->r11) {
        // 0x80015F10: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80015E70;
    }
    // 0x80015F10: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80015F14: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80015F18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015F1C: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_80015F20:
    // 0x80015F20: lw          $t9, 0xC($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XC);
    // 0x80015F24: bnel        $t9, $zero, L_80015F50
    if (ctx->r25 != 0) {
        // 0x80015F28: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80015F50;
    }
    goto skip_15;
    // 0x80015F28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x80015F2C: lw          $s0, 0x8($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X8);
    // 0x80015F30: beql        $s0, $zero, L_80015F50
    if (ctx->r16 == 0) {
        // 0x80015F34: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80015F50;
    }
    goto skip_16;
    // 0x80015F34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
L_80015F38:
    // 0x80015F38: jal         0x80015C0C
    // 0x80015F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80015C0C(rdram, ctx);
        goto after_3;
    // 0x80015F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80015F40: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80015F44: bne         $s0, $zero, L_80015F38
    if (ctx->r16 != 0) {
        // 0x80015F48: nop
    
            goto L_80015F38;
    }
    // 0x80015F48: nop

    // 0x80015F4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80015F50:
    // 0x80015F50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80015F54: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80015F58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80015F5C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80015F60: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80015F64: jr          $ra
    // 0x80015F68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80015F68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void itPowerBlockWaitProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C15C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C164: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017C168: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8017C16C: addiu       $t6, $t6, -0x3EF0
    ctx->r14 = ADD32(ctx->r14, -0X3EF0);
    // 0x8017C170: lw          $t7, 0x2D4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017C174: sw          $t6, 0x378($v0)
    MEM_W(0X378, ctx->r2) = ctx->r14;
    // 0x8017C178: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x8017C17C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8017C180: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8017C184: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017C188: addiu       $t9, $t9, 0x11F8
    ctx->r25 = ADD32(ctx->r25, 0X11F8);
    // 0x8017C18C: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x8017C190: addiu       $t1, $t1, 0x1288
    ctx->r9 = ADD32(ctx->r9, 0X1288);
    // 0x8017C194: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8017C198: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8017C19C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8017C1A0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8017C1A4: jal         0x8000BD1C
    // 0x8017C1A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8017C1A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x8017C1AC: jal         0x8000DF34
    // 0x8017C1B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8017C1B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017C1B4: jal         0x800269C0
    // 0x8017C1B8: addiu       $a0, $zero, 0x117
    ctx->r4 = ADD32(0, 0X117);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8017C1B8: addiu       $a0, $zero, 0x117
    ctx->r4 = ADD32(0, 0X117);
    after_2:
    // 0x8017C1BC: jal         0x801008F4
    // 0x8017C1C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8017C1C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8017C1C4: jal         0x80109B4C
    // 0x8017C1C8: nop

    grInishiePowerBlockSetDamage(rdram, ctx);
        goto after_4;
    // 0x8017C1C8: nop

    after_4:
    // 0x8017C1CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C1D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C1D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C1D8: jr          $ra
    // 0x8017C1DC: nop

    return;
    // 0x8017C1DC: nop

;}
RECOMP_FUNC void gcCheckGetDObjNoAxisTrack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000E168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000E16C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000E170: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000E174: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000E178: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8000E17C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8000E180: lbu         $a1, 0x43($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X43);
    // 0x8000E184: jal         0x8000E008
    // 0x8000E188: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    gcGetTrackAObj(rdram, ctx);
        goto after_0;
    // 0x8000E188: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x8000E18C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000E190: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E194: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8000E198: beq         $v0, $zero, L_8000E208
    if (ctx->r2 == 0) {
        // 0x8000E19C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000E208;
    }
    // 0x8000E19C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000E1A0: lbu         $t6, 0x5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5);
    // 0x8000E1A4: beql        $t6, $zero, L_8000E20C
    if (ctx->r14 == 0) {
        // 0x8000E1A8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8000E20C;
    }
    goto skip_0;
    // 0x8000E1A8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    skip_0:
    // 0x8000E1AC: bne         $v1, $zero, L_8000E1DC
    if (ctx->r3 != 0) {
        // 0x8000E1B0: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_8000E1DC;
    }
    // 0x8000E1B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000E1B4: lwc1        $f4, -0x2088($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2088);
    // 0x8000E1B8: lwc1        $f6, 0x74($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X74);
    // 0x8000E1BC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8000E1C0: nop

    // 0x8000E1C4: bc1t        L_8000E1DC
    if (c1cs) {
        // 0x8000E1C8: nop
    
            goto L_8000E1DC;
    }
    // 0x8000E1C8: nop

    // 0x8000E1CC: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000E1D0: lwc1        $f10, 0x78($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X78);
    // 0x8000E1D4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000E1D8: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
L_8000E1DC:
    // 0x8000E1DC: jal         0x8000CB94
    // 0x8000E1E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    gcGetAObjValue(rdram, ctx);
        goto after_1;
    // 0x8000E1E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8000E1E4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8000E1E8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8000E1EC: beql        $t7, $zero, L_8000E414
    if (ctx->r15 == 0) {
        // 0x8000E1F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000E414;
    }
    goto skip_1;
    // 0x8000E1F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8000E1F4: jal         0x8000CC40
    // 0x8000E1F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcGetAObjRate(rdram, ctx);
        goto after_2;
    // 0x8000E1F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8000E1FC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8000E200: b           L_8000E410
    // 0x8000E204: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
        goto L_8000E410;
    // 0x8000E204: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_8000E208:
    // 0x8000E208: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000E20C:
    // 0x8000E20C: beq         $a3, $v0, L_8000E224
    if (ctx->r7 == ctx->r2) {
        // 0x8000E210: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8000E224;
    }
    // 0x8000E210: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000E214: beq         $a3, $at, L_8000E224
    if (ctx->r7 == ctx->r1) {
        // 0x8000E218: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8000E224;
    }
    // 0x8000E218: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000E21C: bne         $a3, $at, L_8000E3D8
    if (ctx->r7 != ctx->r1) {
        // 0x8000E220: nop
    
            goto L_8000E3D8;
    }
    // 0x8000E220: nop

L_8000E224:
    // 0x8000E224: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8000E228: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000E22C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000E230: beq         $t0, $zero, L_8000E284
    if (ctx->r8 == 0) {
        // 0x8000E234: nop
    
            goto L_8000E284;
    }
    // 0x8000E234: nop

    // 0x8000E238: beq         $a3, $v0, L_8000E260
    if (ctx->r7 == ctx->r2) {
        // 0x8000E23C: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8000E260;
    }
    // 0x8000E23C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000E240: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000E244: beq         $a3, $at, L_8000E26C
    if (ctx->r7 == ctx->r1) {
        // 0x8000E248: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8000E26C;
    }
    // 0x8000E248: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000E24C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000E250: beq         $a3, $at, L_8000E278
    if (ctx->r7 == ctx->r1) {
        // 0x8000E254: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8000E278;
    }
    // 0x8000E254: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000E258: b           L_8000E414
    // 0x8000E25C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E414;
    // 0x8000E25C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E260:
    // 0x8000E260: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000E264: b           L_8000E410
    // 0x8000E268: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
        goto L_8000E410;
    // 0x8000E268: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_8000E26C:
    // 0x8000E26C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000E270: b           L_8000E410
    // 0x8000E274: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
        goto L_8000E410;
    // 0x8000E274: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
L_8000E278:
    // 0x8000E278: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000E27C: b           L_8000E410
    // 0x8000E280: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_8000E410;
    // 0x8000E280: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_8000E284:
    // 0x8000E284: jal         0x8000E008
    // 0x8000E288: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    gcGetTrackAObj(rdram, ctx);
        goto after_3;
    // 0x8000E288: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x8000E28C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000E290: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E294: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8000E298: beq         $v0, $zero, L_8000E39C
    if (ctx->r2 == 0) {
        // 0x8000E29C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000E39C;
    }
    // 0x8000E29C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000E2A0: lbu         $t1, 0x5($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X5);
    // 0x8000E2A4: beq         $t1, $zero, L_8000E39C
    if (ctx->r9 == 0) {
        // 0x8000E2A8: nop
    
            goto L_8000E39C;
    }
    // 0x8000E2A8: nop

    // 0x8000E2AC: bne         $v1, $zero, L_8000E2DC
    if (ctx->r3 != 0) {
        // 0x8000E2B0: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_8000E2DC;
    }
    // 0x8000E2B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000E2B4: lwc1        $f8, -0x2084($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2084);
    // 0x8000E2B8: lwc1        $f10, 0x74($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X74);
    // 0x8000E2BC: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8000E2C0: nop

    // 0x8000E2C4: bc1t        L_8000E2DC
    if (c1cs) {
        // 0x8000E2C8: nop
    
            goto L_8000E2DC;
    }
    // 0x8000E2C8: nop

    // 0x8000E2CC: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000E2D0: lwc1        $f18, 0x78($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X78);
    // 0x8000E2D4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000E2D8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
L_8000E2DC:
    // 0x8000E2DC: jal         0x8000CB94
    // 0x8000E2E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    gcGetAObjValue(rdram, ctx);
        goto after_4;
    // 0x8000E2E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_4:
    // 0x8000E2E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000E2E8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8000E2EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E2F0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8000E2F4: nop

    // 0x8000E2F8: bc1fl       L_8000E310
    if (!c1cs) {
        // 0x8000E2FC: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8000E310;
    }
    goto skip_2;
    // 0x8000E2FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_2:
    // 0x8000E300: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x8000E304: b           L_8000E32C
    // 0x8000E308: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
        goto L_8000E32C;
    // 0x8000E308: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000E30C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8000E310:
    // 0x8000E310: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000E314: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8000E318: nop

    // 0x8000E31C: bc1fl       L_8000E330
    if (!c1cs) {
        // 0x8000E320: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8000E330;
    }
    goto skip_3;
    // 0x8000E320: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8000E324: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x8000E328: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
L_8000E32C:
    // 0x8000E32C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_8000E330:
    // 0x8000E330: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8000E334: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000E338: jal         0x8001E530
    // 0x8000E33C: lw          $a1, 0x20($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X20);
    syInterpCubic(rdram, ctx);
        goto after_5;
    // 0x8000E33C: lw          $a1, 0x20($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X20);
    after_5:
    // 0x8000E340: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8000E344: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000E348: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000E34C: beq         $a3, $at, L_8000E36C
    if (ctx->r7 == ctx->r1) {
        // 0x8000E350: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8000E36C;
    }
    // 0x8000E350: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000E354: beq         $a3, $at, L_8000E378
    if (ctx->r7 == ctx->r1) {
        // 0x8000E358: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8000E378;
    }
    // 0x8000E358: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000E35C: beql        $a3, $at, L_8000E388
    if (ctx->r7 == ctx->r1) {
        // 0x8000E360: lwc1        $f10, 0x8($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
            goto L_8000E388;
    }
    goto skip_4;
    // 0x8000E360: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    skip_4:
    // 0x8000E364: b           L_8000E390
    // 0x8000E368: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
        goto L_8000E390;
    // 0x8000E368: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
L_8000E36C:
    // 0x8000E36C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000E370: b           L_8000E38C
    // 0x8000E374: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_8000E38C;
    // 0x8000E374: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_8000E378:
    // 0x8000E378: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000E37C: b           L_8000E38C
    // 0x8000E380: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_8000E38C;
    // 0x8000E380: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x8000E384: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
L_8000E388:
    // 0x8000E388: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_8000E38C:
    // 0x8000E38C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
L_8000E390:
    // 0x8000E390: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000E394: b           L_8000E410
    // 0x8000E398: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_8000E410;
    // 0x8000E398: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_8000E39C:
    // 0x8000E39C: bne         $v1, $zero, L_8000E3C8
    if (ctx->r3 != 0) {
        // 0x8000E3A0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8000E3C8;
    }
    // 0x8000E3A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000E3A4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E3A8: bne         $a0, $zero, L_8000E3B8
    if (ctx->r4 != 0) {
        // 0x8000E3AC: nop
    
            goto L_8000E3B8;
    }
    // 0x8000E3AC: nop

    // 0x8000E3B0: b           L_8000E414
    // 0x8000E3B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000E414;
    // 0x8000E3B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E3B8:
    // 0x8000E3B8: jal         0x8000E0F4
    // 0x8000E3BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    gcGetDObjDescAxisTrack(rdram, ctx);
        goto after_6;
    // 0x8000E3BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
    // 0x8000E3C0: b           L_8000E410
    // 0x8000E3C4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_8000E410;
    // 0x8000E3C4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8000E3C8:
    // 0x8000E3C8: jal         0x8000E084
    // 0x8000E3CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    gcGetDObjAxisTrack(rdram, ctx);
        goto after_7;
    // 0x8000E3CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_7:
    // 0x8000E3D0: b           L_8000E410
    // 0x8000E3D4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_8000E410;
    // 0x8000E3D4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8000E3D8:
    // 0x8000E3D8: bne         $v1, $zero, L_8000E404
    if (ctx->r3 != 0) {
        // 0x8000E3DC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8000E404;
    }
    // 0x8000E3DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000E3E0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E3E4: bne         $a0, $zero, L_8000E3F4
    if (ctx->r4 != 0) {
        // 0x8000E3E8: nop
    
            goto L_8000E3F4;
    }
    // 0x8000E3E8: nop

    // 0x8000E3EC: b           L_8000E414
    // 0x8000E3F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000E414;
    // 0x8000E3F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E3F4:
    // 0x8000E3F4: jal         0x8000E0F4
    // 0x8000E3F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    gcGetDObjDescAxisTrack(rdram, ctx);
        goto after_8;
    // 0x8000E3F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x8000E3FC: b           L_8000E410
    // 0x8000E400: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_8000E410;
    // 0x8000E400: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8000E404:
    // 0x8000E404: jal         0x8000E084
    // 0x8000E408: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    gcGetDObjAxisTrack(rdram, ctx);
        goto after_9;
    // 0x8000E408: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_9:
    // 0x8000E40C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8000E410:
    // 0x8000E410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E414:
    // 0x8000E414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E418: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000E41C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000E420: jr          $ra
    // 0x8000E424: nop

    return;
    // 0x8000E424: nop

;}
RECOMP_FUNC void itRShellCommonProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B31C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B324: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017B328: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017B32C: lbu         $t7, 0x355($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X355);
    // 0x8017B330: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8017B334: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8017B338: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8017B33C: lw          $a1, 0x74($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X74);
    // 0x8017B340: bne         $t9, $zero, L_8017B350
    if (ctx->r25 != 0) {
        // 0x8017B344: sb          $t8, 0x355($v0)
        MEM_B(0X355, ctx->r2) = ctx->r24;
            goto L_8017B350;
    }
    // 0x8017B344: sb          $t8, 0x355($v0)
    MEM_B(0X355, ctx->r2) = ctx->r24;
    // 0x8017B348: b           L_8017B408
    // 0x8017B34C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017B408;
    // 0x8017B34C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017B350:
    // 0x8017B350: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8017B354: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8017B358: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8017B35C: nop

    // 0x8017B360: bc1fl       L_8017B3A8
    if (!c1cs) {
        // 0x8017B364: lwc1        $f0, 0x2C($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
            goto L_8017B3A8;
    }
    goto skip_0;
    // 0x8017B364: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    skip_0:
    // 0x8017B368: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8017B36C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B370: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8017B374: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x8017B378: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8017B37C: nop

    // 0x8017B380: bc1fl       L_8017B3E0
    if (!c1cs) {
        // 0x8017B384: lw          $t2, 0x24($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X24);
            goto L_8017B3E0;
    }
    goto skip_1;
    // 0x8017B384: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    skip_1:
    // 0x8017B388: lwc1        $f16, 0x358($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X358);
    // 0x8017B38C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8017B390: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8017B394: swc1        $f10, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f10.u32l;
    // 0x8017B398: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8017B39C: b           L_8017B3DC
    // 0x8017B3A0: swc1        $f18, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->f18.u32l;
        goto L_8017B3DC;
    // 0x8017B3A0: swc1        $f18, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->f18.u32l;
    // 0x8017B3A4: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_8017B3A8:
    // 0x8017B3A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B3AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8017B3B0: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x8017B3B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8017B3B8: nop

    // 0x8017B3BC: bc1fl       L_8017B3E0
    if (!c1cs) {
        // 0x8017B3C0: lw          $t2, 0x24($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X24);
            goto L_8017B3E0;
    }
    goto skip_2;
    // 0x8017B3C0: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    skip_2:
    // 0x8017B3C4: lwc1        $f8, 0x358($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X358);
    // 0x8017B3C8: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8017B3CC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8017B3D0: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x8017B3D4: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8017B3D8: swc1        $f10, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->f10.u32l;
L_8017B3DC:
    // 0x8017B3DC: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
L_8017B3E0:
    // 0x8017B3E0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8017B3E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B3E8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8017B3EC: nop

    // 0x8017B3F0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017B3F4: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8017B3F8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8017B3FC: jal         0x8017279C
    // 0x8017B400: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    itMainClearOwnerStats(rdram, ctx);
        goto after_0;
    // 0x8017B400: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    after_0:
    // 0x8017B404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017B408:
    // 0x8017B408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B40C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B410: jr          $ra
    // 0x8017B414: nop

    return;
    // 0x8017B414: nop

;}

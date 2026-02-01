#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void syVectorDist3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019AB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80019AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019AB8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019ABC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019AC0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019AC4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80019AC8: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019ACC: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019AD0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80019AD4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80019AD8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019ADC: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019AE0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80019AE4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019AE8: jal         0x80018F7C
    // 0x80019AEC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    syVectorMag3D(rdram, ctx);
        goto after_0;
    // 0x80019AEC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80019AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019AF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80019AF8: jr          $ra
    // 0x80019AFC: nop

    return;
    // 0x80019AFC: nop

;}
RECOMP_FUNC void mnVSItemSwitchMakeAppearance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132224: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80132228: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013222C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132230: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80132234: addiu       $t7, $t7, 0x32F0
    ctx->r15 = ADD32(ctx->r15, 0X32F0);
    // 0x80132238: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013223C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132240: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x80132244: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132248: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013224C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80132250: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132254: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132258: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8013225C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132260: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80132264: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80132268: addiu       $t1, $t1, 0x3308
    ctx->r9 = ADD32(ctx->r9, 0X3308);
    // 0x8013226C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80132270: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80132274: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80132278: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8013227C: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x80132280: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80132284: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80132288: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8013228C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80132290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132294: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80132298: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8013229C: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x801322A0: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x801322A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801322A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801322AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801322B0: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x801322B4: jal         0x80009968
    // 0x801322B8: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801322B8: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x801322BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322C0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801322C4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801322C8: sw          $v0, 0x33E0($at)
    MEM_W(0X33E0, ctx->r1) = ctx->r2;
    // 0x801322CC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x801322D0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801322D4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801322D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801322DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801322E0: jal         0x80009DF4
    // 0x801322E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801322E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801322E8: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x801322EC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801322F0: lw          $t6, 0x3530($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3530);
    // 0x801322F4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x801322F8: addu        $t5, $sp, $v1
    ctx->r13 = ADD32(ctx->r29, ctx->r3);
    // 0x801322FC: lw          $t5, 0x28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X28);
    // 0x80132300: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80132304: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80132308: jal         0x800CCFDC
    // 0x8013230C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8013230C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x80132310: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80132314: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80132318: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8013231C: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x80132320: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132324: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80132328: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8013232C: addu        $t1, $sp, $v1
    ctx->r9 = ADD32(ctx->r29, ctx->r3);
    // 0x80132330: lw          $t1, 0x40($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X40);
    // 0x80132334: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132338: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8013233C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80132340: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80132344: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132348: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013234C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132350: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132354: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013235C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80132360: jr          $ra
    // 0x80132364: nop

    return;
    // 0x80132364: nop

;}
RECOMP_FUNC void mnCharactersMakeFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133404: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133408: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8013340C: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x80133410: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133414: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x80133418: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x8013341C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80133420: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133424: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80133428: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013342C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133430: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80133434: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80133438: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8013343C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80133440: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80133444: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133448: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013344C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133450: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133454: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133458: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013345C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133464: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133468: jal         0x8000B93C
    // 0x8013346C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013346C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133470: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133474: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133478: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013347C: addiu       $t0, $t0, 0x66E0
    ctx->r8 = ADD32(ctx->r8, 0X66E0);
    // 0x80133480: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80133484: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133488: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013348C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133490: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133494: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133498: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013349C: sw          $t6, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r14;
    // 0x801334A0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801334A4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x801334A8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801334AC: jal         0x80007080
    // 0x801334B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801334B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801334B4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x801334B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801334BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801334C0: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x801334C4: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x801334C8: lwc1        $f6, 0x65C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X65C4);
    // 0x801334CC: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x801334D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801334D4: lui         $at, 0x43B9
    ctx->r1 = S32(0X43B9 << 16);
    // 0x801334D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801334DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801334E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801334E4: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x801334E8: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x801334EC: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x801334F0: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x801334F4: swc1        $f8, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f8.u32l;
    // 0x801334F8: swc1        $f10, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f10.u32l;
    // 0x801334FC: swc1        $f16, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f16.u32l;
    // 0x80133500: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133504: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80133508: jr          $ra
    // 0x8013350C: nop

    return;
    // 0x8013350C: nop

;}
RECOMP_FUNC void func_ovl8_803773CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803773CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803773D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803773D4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x803773D8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x803773DC: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x803773E0: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x803773E4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x803773E8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x803773EC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x803773F0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x803773F4: sltiu       $at, $a1, 0x4
    ctx->r1 = ctx->r5 < 0X4 ? 1 : 0;
    // 0x803773F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803773FC: beq         $at, $zero, L_80377ACC
    if (ctx->r1 == 0) {
        // 0x80377400: lh          $t0, 0x2($a0)
        ctx->r8 = MEM_H(ctx->r4, 0X2);
            goto L_80377ACC;
    }
    // 0x80377400: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80377404: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80377408: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037740C: addu        $at, $at, $t6
    gpr jr_addend_80377414 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80377410: lw          $t6, -0x11F8($at)
    ctx->r14 = ADD32(ctx->r1, -0X11F8);
    // 0x80377414: jr          $t6
    // 0x80377418: nop

    switch (jr_addend_80377414 >> 2) {
        case 0: goto L_80377ACC; break;
        case 1: goto L_8037741C; break;
        case 2: goto L_8037762C; break;
        case 3: goto L_80377884; break;
        default: switch_error(__func__, 0x80377414, 0x8038EE08);
    }
    // 0x80377418: nop

L_8037741C:
    // 0x8037741C: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x80377420: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80377424: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80377428: blez        $v0, L_80377ACC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8037742C: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_80377ACC;
    }
    // 0x8037742C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80377430: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80377434: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80377438: addiu       $t2, $t2, -0x60A4
    ctx->r10 = ADD32(ctx->r10, -0X60A4);
    // 0x8037743C: addiu       $t3, $t3, -0x60A0
    ctx->r11 = ADD32(ctx->r11, -0X60A0);
    // 0x80377440: lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X4);
    // 0x80377444: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_80377448:
    // 0x80377448: blez        $v1, L_8037760C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8037744C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8037760C;
    }
    // 0x8037744C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80377450: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
L_80377454:
    // 0x80377454: bnel        $a1, $t4, L_80377490
    if (ctx->r5 != ctx->r12) {
        // 0x80377458: lh          $t8, 0x2($a2)
        ctx->r24 = MEM_H(ctx->r6, 0X2);
            goto L_80377490;
    }
    goto skip_0;
    // 0x80377458: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    skip_0:
    // 0x8037745C: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x80377460: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80377464: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x80377468: addu        $v0, $t7, $t1
    ctx->r2 = ADD32(ctx->r15, ctx->r9);
    // 0x8037746C: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377470: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
    // 0x80377474: lbu         $s2, 0x3($t2)
    ctx->r18 = MEM_BU(ctx->r10, 0X3);
    // 0x80377478: mflo        $t9
    ctx->r25 = lo;
    // 0x8037747C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80377480: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80377484: b           L_8037754C
    // 0x80377488: addu        $s3, $t7, $a0
    ctx->r19 = ADD32(ctx->r15, ctx->r4);
        goto L_8037754C;
    // 0x80377488: addu        $s3, $t7, $a0
    ctx->r19 = ADD32(ctx->r15, ctx->r4);
    // 0x8037748C: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
L_80377490:
    // 0x80377490: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x80377494: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
    // 0x80377498: beq         $a3, $zero, L_803774F8
    if (ctx->r7 == 0) {
        // 0x8037749C: nop
    
            goto L_803774F8;
    }
    // 0x8037749C: nop

    // 0x803774A0: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x803774A4: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x803774A8: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x803774AC: beq         $t6, $zero, L_803774D4
    if (ctx->r14 == 0) {
        // 0x803774B0: nop
    
            goto L_803774D4;
    }
    // 0x803774B0: nop

    // 0x803774B4: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803774B8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x803774BC: mflo        $t8
    ctx->r24 = lo;
    // 0x803774C0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x803774C4: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x803774C8: addu        $s3, $t6, $a0
    ctx->r19 = ADD32(ctx->r14, ctx->r4);
    // 0x803774CC: b           L_80377518
    // 0x803774D0: lbu         $s4, -0x4($s3)
    ctx->r20 = MEM_BU(ctx->r19, -0X4);
        goto L_80377518;
    // 0x803774D0: lbu         $s4, -0x4($s3)
    ctx->r20 = MEM_BU(ctx->r19, -0X4);
L_803774D4:
    // 0x803774D4: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803774D8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x803774DC: mflo        $t8
    ctx->r24 = lo;
    // 0x803774E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x803774E4: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x803774E8: addu        $s3, $t6, $a0
    ctx->r19 = ADD32(ctx->r14, ctx->r4);
    // 0x803774EC: lbu         $s2, 0x4($s3)
    ctx->r18 = MEM_BU(ctx->r19, 0X4);
    // 0x803774F0: b           L_80377518
    // 0x803774F4: andi        $s4, $s2, 0xFF
    ctx->r20 = ctx->r18 & 0XFF;
        goto L_80377518;
    // 0x803774F4: andi        $s4, $s2, 0xFF
    ctx->r20 = ctx->r18 & 0XFF;
L_803774F8:
    // 0x803774F8: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803774FC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80377500: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x80377504: mflo        $t8
    ctx->r24 = lo;
    // 0x80377508: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8037750C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80377510: addu        $s3, $t6, $a0
    ctx->r19 = ADD32(ctx->r14, ctx->r4);
    // 0x80377514: lbu         $s4, 0x0($s3)
    ctx->r20 = MEM_BU(ctx->r19, 0X0);
L_80377518:
    // 0x80377518: beq         $t5, $a1, L_80377530
    if (ctx->r13 == ctx->r5) {
        // 0x8037751C: andi        $s2, $s4, 0xFF
        ctx->r18 = ctx->r20 & 0XFF;
            goto L_80377530;
    }
    // 0x8037751C: andi        $s2, $s4, 0xFF
    ctx->r18 = ctx->r20 & 0XFF;
    // 0x80377520: beql        $s1, $a1, L_80377544
    if (ctx->r17 == ctx->r5) {
        // 0x80377524: lw          $t8, 0x0($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X0);
            goto L_80377544;
    }
    goto skip_1;
    // 0x80377524: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    skip_1:
    // 0x80377528: b           L_8037754C
    // 0x8037752C: nop

        goto L_8037754C;
    // 0x8037752C: nop

L_80377530:
    // 0x80377530: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80377534: or          $s2, $s4, $t7
    ctx->r18 = ctx->r20 | ctx->r15;
    // 0x80377538: b           L_8037754C
    // 0x8037753C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
        goto L_8037754C;
    // 0x8037753C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x80377540: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
L_80377544:
    // 0x80377544: xor         $s2, $s4, $t8
    ctx->r18 = ctx->r20 ^ ctx->r24;
    // 0x80377548: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
L_8037754C:
    // 0x8037754C: beq         $a3, $zero, L_803775E8
    if (ctx->r7 == 0) {
        // 0x80377550: addu        $t9, $v1, $a0
        ctx->r25 = ADD32(ctx->r3, ctx->r4);
            goto L_803775E8;
    }
    // 0x80377550: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x80377554: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x80377558: beql        $t6, $zero, L_803775BC
    if (ctx->r14 == 0) {
        // 0x8037755C: sb          $s2, 0x4($s3)
        MEM_B(0X4, ctx->r19) = ctx->r18;
            goto L_803775BC;
    }
    goto skip_2;
    // 0x8037755C: sb          $s2, 0x4($s3)
    MEM_B(0X4, ctx->r19) = ctx->r18;
    skip_2:
    // 0x80377560: sb          $s2, -0x4($s3)
    MEM_B(-0X4, ctx->r19) = ctx->r18;
    // 0x80377564: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x80377568: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8037756C: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x80377570: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377574: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80377578: mflo        $t6
    ctx->r14 = lo;
    // 0x8037757C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80377580: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80377584: addu        $t6, $t7, $a0
    ctx->r14 = ADD32(ctx->r15, ctx->r4);
    // 0x80377588: sb          $s2, -0x4($t6)
    MEM_B(-0X4, ctx->r14) = ctx->r18;
    // 0x8037758C: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x80377590: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80377594: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x80377598: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037759C: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x803775A0: mflo        $t6
    ctx->r14 = lo;
    // 0x803775A4: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x803775A8: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x803775AC: addu        $t6, $t8, $a0
    ctx->r14 = ADD32(ctx->r24, ctx->r4);
    // 0x803775B0: b           L_803775EC
    // 0x803775B4: sb          $s2, -0x4($t6)
    MEM_B(-0X4, ctx->r14) = ctx->r18;
        goto L_803775EC;
    // 0x803775B4: sb          $s2, -0x4($t6)
    MEM_B(-0X4, ctx->r14) = ctx->r18;
    // 0x803775B8: sb          $s2, 0x4($s3)
    MEM_B(0X4, ctx->r19) = ctx->r18;
L_803775BC:
    // 0x803775BC: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x803775C0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x803775C4: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x803775C8: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803775CC: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x803775D0: mflo        $t6
    ctx->r14 = lo;
    // 0x803775D4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x803775D8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x803775DC: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x803775E0: b           L_803775EC
    // 0x803775E4: sb          $s2, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r18;
        goto L_803775EC;
    // 0x803775E4: sb          $s2, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r18;
L_803775E8:
    // 0x803775E8: sb          $s2, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r18;
L_803775EC:
    // 0x803775EC: lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X4);
    // 0x803775F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803775F4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x803775F8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x803775FC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80377600: bnel        $at, $zero, L_80377454
    if (ctx->r1 != 0) {
        // 0x80377604: lw          $a1, 0x0($t3)
        ctx->r5 = MEM_W(ctx->r11, 0X0);
            goto L_80377454;
    }
    goto skip_3;
    // 0x80377604: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    skip_3:
    // 0x80377608: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
L_8037760C:
    // 0x8037760C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80377610: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x80377614: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80377618: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037761C: bne         $at, $zero, L_80377448
    if (ctx->r1 != 0) {
        // 0x80377620: nop
    
            goto L_80377448;
    }
    // 0x80377620: nop

    // 0x80377624: b           L_80377AD0
    // 0x80377628: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_80377AD0;
    // 0x80377628: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8037762C:
    // 0x8037762C: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x80377630: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80377634: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80377638: blez        $v0, L_80377ACC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8037763C: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_80377ACC;
    }
    // 0x8037763C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80377640: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80377644: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80377648: addiu       $t2, $t2, -0x60A4
    ctx->r10 = ADD32(ctx->r10, -0X60A4);
    // 0x8037764C: addiu       $t3, $t3, -0x60A0
    ctx->r11 = ADD32(ctx->r11, -0X60A0);
    // 0x80377650: lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X4);
    // 0x80377654: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_80377658:
    // 0x80377658: blez        $v1, L_80377864
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8037765C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80377864;
    }
    // 0x8037765C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80377660: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
L_80377664:
    // 0x80377664: bnel        $a1, $t4, L_803776AC
    if (ctx->r5 != ctx->r12) {
        // 0x80377668: lh          $t6, 0x2($a2)
        ctx->r14 = MEM_H(ctx->r6, 0X2);
            goto L_803776AC;
    }
    goto skip_4;
    // 0x80377668: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    skip_4:
    // 0x8037766C: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x80377670: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x80377674: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80377678: addu        $v0, $t7, $t1
    ctx->r2 = ADD32(ctx->r15, ctx->r9);
    // 0x8037767C: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377680: sll         $s3, $a0, 1
    ctx->r19 = S32(ctx->r4 << 1);
    // 0x80377684: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
    // 0x80377688: lhu         $s2, 0x2($t2)
    ctx->r18 = MEM_HU(ctx->r10, 0X2);
    // 0x8037768C: mflo        $t9
    ctx->r25 = lo;
    // 0x80377690: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80377694: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80377698: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8037769C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x803776A0: b           L_8037778C
    // 0x803776A4: addu        $s4, $t8, $s3
    ctx->r20 = ADD32(ctx->r24, ctx->r19);
        goto L_8037778C;
    // 0x803776A4: addu        $s4, $t8, $s3
    ctx->r20 = ADD32(ctx->r24, ctx->r19);
    // 0x803776A8: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
L_803776AC:
    // 0x803776AC: addu        $v0, $t6, $t1
    ctx->r2 = ADD32(ctx->r14, ctx->r9);
    // 0x803776B0: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
    // 0x803776B4: beq         $a3, $zero, L_8037772C
    if (ctx->r7 == 0) {
        // 0x803776B8: nop
    
            goto L_8037772C;
    }
    // 0x803776B8: nop

    // 0x803776BC: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x803776C0: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x803776C4: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x803776C8: beq         $t9, $zero, L_803776FC
    if (ctx->r25 == 0) {
        // 0x803776CC: nop
    
            goto L_803776FC;
    }
    // 0x803776CC: nop

    // 0x803776D0: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803776D4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x803776D8: sll         $s3, $a0, 1
    ctx->r19 = S32(ctx->r4 << 1);
    // 0x803776DC: mflo        $t6
    ctx->r14 = lo;
    // 0x803776E0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x803776E4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x803776E8: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x803776EC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x803776F0: addu        $s4, $t8, $s3
    ctx->r20 = ADD32(ctx->r24, ctx->r19);
    // 0x803776F4: b           L_80377758
    // 0x803776F8: lhu         $s5, -0x4($s4)
    ctx->r21 = MEM_HU(ctx->r20, -0X4);
        goto L_80377758;
    // 0x803776F8: lhu         $s5, -0x4($s4)
    ctx->r21 = MEM_HU(ctx->r20, -0X4);
L_803776FC:
    // 0x803776FC: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377700: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80377704: sll         $s3, $a0, 1
    ctx->r19 = S32(ctx->r4 << 1);
    // 0x80377708: mflo        $t9
    ctx->r25 = lo;
    // 0x8037770C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80377710: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80377714: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80377718: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8037771C: addu        $s4, $t7, $s3
    ctx->r20 = ADD32(ctx->r15, ctx->r19);
    // 0x80377720: lhu         $s2, 0x4($s4)
    ctx->r18 = MEM_HU(ctx->r20, 0X4);
    // 0x80377724: b           L_80377758
    // 0x80377728: andi        $s5, $s2, 0xFFFF
    ctx->r21 = ctx->r18 & 0XFFFF;
        goto L_80377758;
    // 0x80377728: andi        $s5, $s2, 0xFFFF
    ctx->r21 = ctx->r18 & 0XFFFF;
L_8037772C:
    // 0x8037772C: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377730: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x80377734: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80377738: sll         $s3, $a0, 1
    ctx->r19 = S32(ctx->r4 << 1);
    // 0x8037773C: mflo        $t8
    ctx->r24 = lo;
    // 0x80377740: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80377744: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80377748: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8037774C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80377750: addu        $s4, $t6, $s3
    ctx->r20 = ADD32(ctx->r14, ctx->r19);
    // 0x80377754: lhu         $s5, 0x0($s4)
    ctx->r21 = MEM_HU(ctx->r20, 0X0);
L_80377758:
    // 0x80377758: beq         $t5, $a1, L_80377770
    if (ctx->r13 == ctx->r5) {
        // 0x8037775C: andi        $s2, $s5, 0xFFFF
        ctx->r18 = ctx->r21 & 0XFFFF;
            goto L_80377770;
    }
    // 0x8037775C: andi        $s2, $s5, 0xFFFF
    ctx->r18 = ctx->r21 & 0XFFFF;
    // 0x80377760: beql        $s1, $a1, L_80377784
    if (ctx->r17 == ctx->r5) {
        // 0x80377764: lw          $t7, 0x0($t2)
        ctx->r15 = MEM_W(ctx->r10, 0X0);
            goto L_80377784;
    }
    goto skip_5;
    // 0x80377764: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    skip_5:
    // 0x80377768: b           L_8037778C
    // 0x8037776C: nop

        goto L_8037778C;
    // 0x8037776C: nop

L_80377770:
    // 0x80377770: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80377774: or          $s2, $s5, $t9
    ctx->r18 = ctx->r21 | ctx->r25;
    // 0x80377778: b           L_8037778C
    // 0x8037777C: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
        goto L_8037778C;
    // 0x8037777C: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x80377780: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
L_80377784:
    // 0x80377784: xor         $s2, $s5, $t7
    ctx->r18 = ctx->r21 ^ ctx->r15;
    // 0x80377788: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
L_8037778C:
    // 0x8037778C: beq         $a3, $zero, L_80377840
    if (ctx->r7 == 0) {
        // 0x80377790: addu        $t8, $v1, $a0
        ctx->r24 = ADD32(ctx->r3, ctx->r4);
            goto L_80377840;
    }
    // 0x80377790: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x80377794: andi        $t6, $t8, 0x2
    ctx->r14 = ctx->r24 & 0X2;
    // 0x80377798: beql        $t6, $zero, L_8037780C
    if (ctx->r14 == 0) {
        // 0x8037779C: sh          $s2, 0x4($s4)
        MEM_H(0X4, ctx->r20) = ctx->r18;
            goto L_8037780C;
    }
    goto skip_6;
    // 0x8037779C: sh          $s2, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r18;
    skip_6:
    // 0x803777A0: sh          $s2, -0x4($s4)
    MEM_H(-0X4, ctx->r20) = ctx->r18;
    // 0x803777A4: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x803777A8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x803777AC: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x803777B0: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803777B4: mflo        $t6
    ctx->r14 = lo;
    // 0x803777B8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x803777BC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x803777C0: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x803777C4: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x803777C8: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x803777CC: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x803777D0: sh          $s2, -0x4($t6)
    MEM_H(-0X4, ctx->r14) = ctx->r18;
    // 0x803777D4: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x803777D8: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x803777DC: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x803777E0: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803777E4: mflo        $t6
    ctx->r14 = lo;
    // 0x803777E8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x803777EC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x803777F0: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x803777F4: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x803777F8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x803777FC: addu        $t6, $t9, $s3
    ctx->r14 = ADD32(ctx->r25, ctx->r19);
    // 0x80377800: b           L_80377844
    // 0x80377804: sh          $s2, -0x4($t6)
    MEM_H(-0X4, ctx->r14) = ctx->r18;
        goto L_80377844;
    // 0x80377804: sh          $s2, -0x4($t6)
    MEM_H(-0X4, ctx->r14) = ctx->r18;
    // 0x80377808: sh          $s2, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r18;
L_8037780C:
    // 0x8037780C: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x80377810: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80377814: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x80377818: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037781C: mflo        $t6
    ctx->r14 = lo;
    // 0x80377820: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80377824: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80377828: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8037782C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80377830: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80377834: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x80377838: b           L_80377844
    // 0x8037783C: sh          $s2, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r18;
        goto L_80377844;
    // 0x8037783C: sh          $s2, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r18;
L_80377840:
    // 0x80377840: sh          $s2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r18;
L_80377844:
    // 0x80377844: lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X4);
    // 0x80377848: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8037784C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80377850: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80377854: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80377858: bnel        $at, $zero, L_80377664
    if (ctx->r1 != 0) {
        // 0x8037785C: lw          $a1, 0x0($t3)
        ctx->r5 = MEM_W(ctx->r11, 0X0);
            goto L_80377664;
    }
    goto skip_7;
    // 0x8037785C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    skip_7:
    // 0x80377860: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
L_80377864:
    // 0x80377864: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80377868: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x8037786C: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80377870: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80377874: bne         $at, $zero, L_80377658
    if (ctx->r1 != 0) {
        // 0x80377878: nop
    
            goto L_80377658;
    }
    // 0x80377878: nop

    // 0x8037787C: b           L_80377AD0
    // 0x80377880: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_80377AD0;
    // 0x80377880: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_80377884:
    // 0x80377884: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x80377888: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8037788C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80377890: blez        $v0, L_80377ACC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80377894: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_80377ACC;
    }
    // 0x80377894: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80377898: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037789C: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x803778A0: addiu       $t2, $t2, -0x60A4
    ctx->r10 = ADD32(ctx->r10, -0X60A4);
    // 0x803778A4: addiu       $t3, $t3, -0x60A0
    ctx->r11 = ADD32(ctx->r11, -0X60A0);
    // 0x803778A8: lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X4);
    // 0x803778AC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_803778B0:
    // 0x803778B0: blez        $v1, L_80377AB4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x803778B4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80377AB4;
    }
    // 0x803778B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x803778B8: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
L_803778BC:
    // 0x803778BC: bnel        $a1, $t4, L_80377904
    if (ctx->r5 != ctx->r12) {
        // 0x803778C0: lh          $t6, 0x2($a2)
        ctx->r14 = MEM_H(ctx->r6, 0X2);
            goto L_80377904;
    }
    goto skip_8;
    // 0x803778C0: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    skip_8:
    // 0x803778C4: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x803778C8: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x803778CC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x803778D0: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x803778D4: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803778D8: sll         $s3, $a0, 2
    ctx->r19 = S32(ctx->r4 << 2);
    // 0x803778DC: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
    // 0x803778E0: lw          $s2, 0x0($t2)
    ctx->r18 = MEM_W(ctx->r10, 0X0);
    // 0x803778E4: mflo        $t8
    ctx->r24 = lo;
    // 0x803778E8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x803778EC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x803778F0: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x803778F4: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x803778F8: b           L_803779DC
    // 0x803778FC: addu        $s4, $t7, $s3
    ctx->r20 = ADD32(ctx->r15, ctx->r19);
        goto L_803779DC;
    // 0x803778FC: addu        $s4, $t7, $s3
    ctx->r20 = ADD32(ctx->r15, ctx->r19);
    // 0x80377900: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
L_80377904:
    // 0x80377904: addu        $v0, $t6, $t1
    ctx->r2 = ADD32(ctx->r14, ctx->r9);
    // 0x80377908: andi        $a3, $v0, 0x1
    ctx->r7 = ctx->r2 & 0X1;
    // 0x8037790C: beq         $a3, $zero, L_80377984
    if (ctx->r7 == 0) {
        // 0x80377910: nop
    
            goto L_80377984;
    }
    // 0x80377910: nop

    // 0x80377914: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x80377918: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x8037791C: andi        $t8, $t9, 0x2
    ctx->r24 = ctx->r25 & 0X2;
    // 0x80377920: beq         $t8, $zero, L_80377954
    if (ctx->r24 == 0) {
        // 0x80377924: nop
    
            goto L_80377954;
    }
    // 0x80377924: nop

    // 0x80377928: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037792C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80377930: sll         $s3, $a0, 2
    ctx->r19 = S32(ctx->r4 << 2);
    // 0x80377934: mflo        $t6
    ctx->r14 = lo;
    // 0x80377938: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8037793C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80377940: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80377944: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80377948: addu        $s4, $t7, $s3
    ctx->r20 = ADD32(ctx->r15, ctx->r19);
    // 0x8037794C: b           L_803779B0
    // 0x80377950: lw          $s5, -0x8($s4)
    ctx->r21 = MEM_W(ctx->r20, -0X8);
        goto L_803779B0;
    // 0x80377950: lw          $s5, -0x8($s4)
    ctx->r21 = MEM_W(ctx->r20, -0X8);
L_80377954:
    // 0x80377954: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377958: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8037795C: sll         $s3, $a0, 2
    ctx->r19 = S32(ctx->r4 << 2);
    // 0x80377960: mflo        $t8
    ctx->r24 = lo;
    // 0x80377964: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80377968: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8037796C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80377970: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80377974: addu        $s4, $t9, $s3
    ctx->r20 = ADD32(ctx->r25, ctx->r19);
    // 0x80377978: lw          $s2, 0x8($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X8);
    // 0x8037797C: b           L_803779B0
    // 0x80377980: or          $s5, $s2, $zero
    ctx->r21 = ctx->r18 | 0;
        goto L_803779B0;
    // 0x80377980: or          $s5, $s2, $zero
    ctx->r21 = ctx->r18 | 0;
L_80377984:
    // 0x80377984: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377988: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x8037798C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80377990: sll         $s3, $a0, 2
    ctx->r19 = S32(ctx->r4 << 2);
    // 0x80377994: mflo        $t7
    ctx->r15 = lo;
    // 0x80377998: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8037799C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x803779A0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x803779A4: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x803779A8: addu        $s4, $t6, $s3
    ctx->r20 = ADD32(ctx->r14, ctx->r19);
    // 0x803779AC: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
L_803779B0:
    // 0x803779B0: beq         $t5, $a1, L_803779C8
    if (ctx->r13 == ctx->r5) {
        // 0x803779B4: or          $s2, $s5, $zero
        ctx->r18 = ctx->r21 | 0;
            goto L_803779C8;
    }
    // 0x803779B4: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x803779B8: beql        $s1, $a1, L_803779D8
    if (ctx->r17 == ctx->r5) {
        // 0x803779BC: lw          $t9, 0x0($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X0);
            goto L_803779D8;
    }
    goto skip_9;
    // 0x803779BC: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    skip_9:
    // 0x803779C0: b           L_803779DC
    // 0x803779C4: nop

        goto L_803779DC;
    // 0x803779C4: nop

L_803779C8:
    // 0x803779C8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x803779CC: b           L_803779DC
    // 0x803779D0: or          $s2, $s5, $t8
    ctx->r18 = ctx->r21 | ctx->r24;
        goto L_803779DC;
    // 0x803779D0: or          $s2, $s5, $t8
    ctx->r18 = ctx->r21 | ctx->r24;
    // 0x803779D4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
L_803779D8:
    // 0x803779D8: xor         $s2, $s5, $t9
    ctx->r18 = ctx->r21 ^ ctx->r25;
L_803779DC:
    // 0x803779DC: beq         $a3, $zero, L_80377A90
    if (ctx->r7 == 0) {
        // 0x803779E0: addu        $t7, $v1, $a0
        ctx->r15 = ADD32(ctx->r3, ctx->r4);
            goto L_80377A90;
    }
    // 0x803779E0: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x803779E4: andi        $t6, $t7, 0x2
    ctx->r14 = ctx->r15 & 0X2;
    // 0x803779E8: beql        $t6, $zero, L_80377A5C
    if (ctx->r14 == 0) {
        // 0x803779EC: sw          $s2, 0x8($s4)
        MEM_W(0X8, ctx->r20) = ctx->r18;
            goto L_80377A5C;
    }
    goto skip_10;
    // 0x803779EC: sw          $s2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r18;
    skip_10:
    // 0x803779F0: sw          $s2, -0x8($s4)
    MEM_W(-0X8, ctx->r20) = ctx->r18;
    // 0x803779F4: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x803779F8: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x803779FC: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x80377A00: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377A04: mflo        $t6
    ctx->r14 = lo;
    // 0x80377A08: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80377A0C: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80377A10: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80377A14: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80377A18: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80377A1C: addu        $t6, $t9, $s3
    ctx->r14 = ADD32(ctx->r25, ctx->r19);
    // 0x80377A20: sw          $s2, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r18;
    // 0x80377A24: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x80377A28: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80377A2C: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x80377A30: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377A34: mflo        $t6
    ctx->r14 = lo;
    // 0x80377A38: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80377A3C: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80377A40: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80377A44: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80377A48: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80377A4C: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x80377A50: b           L_80377A94
    // 0x80377A54: sw          $s2, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r18;
        goto L_80377A94;
    // 0x80377A54: sw          $s2, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r18;
    // 0x80377A58: sw          $s2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r18;
L_80377A5C:
    // 0x80377A5C: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x80377A60: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80377A64: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x80377A68: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377A6C: mflo        $t6
    ctx->r14 = lo;
    // 0x80377A70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80377A74: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80377A78: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80377A7C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80377A80: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80377A84: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x80377A88: b           L_80377A94
    // 0x80377A8C: sw          $s2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r18;
        goto L_80377A94;
    // 0x80377A8C: sw          $s2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r18;
L_80377A90:
    // 0x80377A90: sw          $s2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r18;
L_80377A94:
    // 0x80377A94: lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X4);
    // 0x80377A98: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80377A9C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80377AA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80377AA4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80377AA8: bnel        $at, $zero, L_803778BC
    if (ctx->r1 != 0) {
        // 0x80377AAC: lw          $a1, 0x0($t3)
        ctx->r5 = MEM_W(ctx->r11, 0X0);
            goto L_803778BC;
    }
    goto skip_11;
    // 0x80377AAC: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    skip_11:
    // 0x80377AB0: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
L_80377AB4:
    // 0x80377AB4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80377AB8: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x80377ABC: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80377AC0: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80377AC4: bne         $at, $zero, L_803778B0
    if (ctx->r1 != 0) {
        // 0x80377AC8: nop
    
            goto L_803778B0;
    }
    // 0x80377AC8: nop

L_80377ACC:
    // 0x80377ACC: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_80377AD0:
    // 0x80377AD0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80377AD4: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80377AD8: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80377ADC: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80377AE0: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80377AE4: jr          $ra
    // 0x80377AE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80377AE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_80377374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377374: beq         $a0, $zero, L_803773A8
    if (ctx->r4 == 0) {
        // 0x80377378: lui         $v0, 0x8039
        ctx->r2 = S32(0X8039 << 16);
            goto L_803773A8;
    }
    // 0x80377378: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037737C: lwl         $t7, 0x0($a0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r4, 0X0);
    // 0x80377380: lwr         $t7, 0x3($a0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r4, 0X3);
    // 0x80377384: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80377388: addiu       $v0, $v0, -0x6098
    ctx->r2 = ADD32(ctx->r2, -0X6098);
    // 0x8037738C: swl         $t7, 0x0($v0)
    do_swl(rdram, 0X0, ctx->r2, ctx->r15);
    // 0x80377390: swr         $t7, 0x3($v0)
    do_swr(rdram, 0X3, ctx->r2, ctx->r15);
    // 0x80377394: lwl         $t6, 0x4($a0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r4, 0X4);
    // 0x80377398: lwr         $t6, 0x7($a0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r4, 0X7);
    // 0x8037739C: swl         $t6, 0x4($v0)
    do_swl(rdram, 0X4, ctx->r2, ctx->r14);
    // 0x803773A0: jr          $ra
    // 0x803773A4: swr         $t6, 0x7($v0)
    do_swr(rdram, 0X7, ctx->r2, ctx->r14);
    return;
    // 0x803773A4: swr         $t6, 0x7($v0)
    do_swr(rdram, 0X7, ctx->r2, ctx->r14);
L_803773A8:
    // 0x803773A8: addiu       $v0, $v0, -0x6098
    ctx->r2 = ADD32(ctx->r2, -0X6098);
    // 0x803773AC: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x803773B0: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x803773B4: addiu       $t0, $zero, 0x7FFF
    ctx->r8 = ADD32(0, 0X7FFF);
    // 0x803773B8: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
    // 0x803773BC: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x803773C0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x803773C4: jr          $ra
    // 0x803773C8: nop

    return;
    // 0x803773C8: nop

;}
RECOMP_FUNC void scExplainHideTapSpark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DEA0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DEA4: lw          $t7, -0x1608($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1608);
    // 0x8018DEA8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018DEAC: jr          $ra
    // 0x8018DEB0: sw          $t6, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r14;
    return;
    // 0x8018DEB0: sw          $t6, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void mn1PModeSetOptionSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B28: addiu       $t6, $t6, 0x30C8
    ctx->r14 = ADD32(ctx->r14, 0X30C8);
    // 0x80131B2C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131B30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80131B34: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x80131B38: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131B3C: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80131B40: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131B44: addiu       $t9, $t9, 0x30D0
    ctx->r25 = ADD32(ctx->r25, 0X30D0);
    // 0x80131B48: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80131B4C: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80131B50: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x80131B54: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131B58: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80131B5C: lhu         $t3, 0x4($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X4);
    // 0x80131B60: addiu       $t4, $t4, 0x30D8
    ctx->r12 = ADD32(ctx->r12, 0X30D8);
    // 0x80131B64: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80131B68: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    // 0x80131B6C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80131B70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80131B74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131B78: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80131B7C: lhu         $t6, 0x4($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X4);
    // 0x80131B80: beq         $a1, $zero, L_80131BA8
    if (ctx->r5 == 0) {
        // 0x80131B84: sh          $t6, 0x4($t1)
        MEM_H(0X4, ctx->r9) = ctx->r14;
            goto L_80131BA8;
    }
    // 0x80131B84: sh          $t6, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r14;
    // 0x80131B88: beq         $a1, $at, L_80131BA0
    if (ctx->r5 == ctx->r1) {
        // 0x80131B8C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80131BA0;
    }
    // 0x80131B8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131B90: beq         $a1, $at, L_80131BB0
    if (ctx->r5 == ctx->r1) {
        // 0x80131B94: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80131BB0;
    }
    // 0x80131B94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131B98: b           L_80131BB0
    // 0x80131B9C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80131BB0;
    // 0x80131B9C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80131BA0:
    // 0x80131BA0: b           L_80131BB0
    // 0x80131BA4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80131BB0;
    // 0x80131BA4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80131BA8:
    // 0x80131BA8: b           L_80131BB0
    // 0x80131BAC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80131BB0;
    // 0x80131BAC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80131BB0:
    // 0x80131BB0: beq         $a2, $zero, L_80131BC4
    if (ctx->r6 == 0) {
        // 0x80131BB4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80131BC4;
    }
    // 0x80131BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131BB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131BBC: bne         $a2, $at, L_80131BCC
    if (ctx->r6 != ctx->r1) {
        // 0x80131BC0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80131BCC;
    }
    // 0x80131BC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80131BC4:
    // 0x80131BC4: b           L_80131BCC
    // 0x80131BC8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80131BCC;
    // 0x80131BC8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80131BCC:
    // 0x80131BCC: blez        $v1, L_80131CFC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80131BD0: lw          $a0, 0x74($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X74);
            goto L_80131CFC;
    }
    // 0x80131BD0: lw          $a0, 0x74($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X74);
    // 0x80131BD4: andi        $a3, $v1, 0x3
    ctx->r7 = ctx->r3 & 0X3;
    // 0x80131BD8: beq         $a3, $zero, L_80131C24
    if (ctx->r7 == 0) {
        // 0x80131BDC: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80131C24;
    }
    // 0x80131BDC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_80131BE0:
    // 0x80131BE0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80131BE4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80131BE8: sb          $t7, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r15;
    // 0x80131BEC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80131BF0: sb          $t8, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r24;
    // 0x80131BF4: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x80131BF8: sb          $t9, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r25;
    // 0x80131BFC: lbu         $t2, 0x3($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X3);
    // 0x80131C00: sb          $t2, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r10;
    // 0x80131C04: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
    // 0x80131C08: sb          $t3, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r11;
    // 0x80131C0C: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    // 0x80131C10: sb          $t4, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r12;
    // 0x80131C14: bne         $a2, $a1, L_80131BE0
    if (ctx->r6 != ctx->r5) {
        // 0x80131C18: lw          $a0, 0x8($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X8);
            goto L_80131BE0;
    }
    // 0x80131C18: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x80131C1C: beq         $a1, $v1, L_80131CFC
    if (ctx->r5 == ctx->r3) {
        // 0x80131C20: nop
    
            goto L_80131CFC;
    }
    // 0x80131C20: nop

L_80131C24:
    // 0x80131C24: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80131C28: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80131C2C: sb          $t5, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r13;
    // 0x80131C30: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80131C34: sb          $t6, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r14;
    // 0x80131C38: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x80131C3C: sb          $t7, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r15;
    // 0x80131C40: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80131C44: sb          $t8, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r24;
    // 0x80131C48: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80131C4C: sb          $t9, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r25;
    // 0x80131C50: lbu         $t2, 0x5($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X5);
    // 0x80131C54: sb          $t2, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r10;
    // 0x80131C58: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80131C5C: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x80131C60: sb          $t3, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r11;
    // 0x80131C64: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x80131C68: sb          $t4, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r12;
    // 0x80131C6C: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x80131C70: sb          $t5, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r13;
    // 0x80131C74: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x80131C78: sb          $t6, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r14;
    // 0x80131C7C: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80131C80: sb          $t7, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r15;
    // 0x80131C84: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x80131C88: sb          $t8, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r24;
    // 0x80131C8C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80131C90: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x80131C94: sb          $t9, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r25;
    // 0x80131C98: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x80131C9C: sb          $t2, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r10;
    // 0x80131CA0: lbu         $t3, 0x2($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2);
    // 0x80131CA4: sb          $t3, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r11;
    // 0x80131CA8: lbu         $t4, 0x3($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3);
    // 0x80131CAC: sb          $t4, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r12;
    // 0x80131CB0: lbu         $t5, 0x4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4);
    // 0x80131CB4: sb          $t5, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r13;
    // 0x80131CB8: lbu         $t6, 0x5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5);
    // 0x80131CBC: sb          $t6, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r14;
    // 0x80131CC0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80131CC4: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x80131CC8: sb          $t7, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r15;
    // 0x80131CCC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80131CD0: sb          $t8, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r24;
    // 0x80131CD4: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x80131CD8: sb          $t9, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r25;
    // 0x80131CDC: lbu         $t2, 0x3($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X3);
    // 0x80131CE0: sb          $t2, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r10;
    // 0x80131CE4: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
    // 0x80131CE8: sb          $t3, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r11;
    // 0x80131CEC: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    // 0x80131CF0: sb          $t4, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r12;
    // 0x80131CF4: bne         $a1, $v1, L_80131C24
    if (ctx->r5 != ctx->r3) {
        // 0x80131CF8: lw          $a0, 0x8($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X8);
            goto L_80131C24;
    }
    // 0x80131CF8: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
L_80131CFC:
    // 0x80131CFC: jr          $ra
    // 0x80131D00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80131D00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftYoshiJumpAerialProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013FB6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013FB70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013FB74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013FB78: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013FB7C: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013FB80: jal         0x800D9414
    // 0x8013FB84: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_0;
    // 0x8013FB84: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013FB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FB8C: jal         0x800D8FA8
    // 0x8013FB90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x8013FB90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8013FB94: bne         $v0, $zero, L_8013FBB0
    if (ctx->r2 != 0) {
        // 0x8013FB98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8013FBB0;
    }
    // 0x8013FB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FB9C: jal         0x800D9044
    // 0x8013FBA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftPhysicsClampAirVelXStickDefault(rdram, ctx);
        goto after_2;
    // 0x8013FBA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8013FBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FBA8: jal         0x800D9074
    // 0x8013FBAC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_3;
    // 0x8013FBAC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
L_8013FBB0:
    // 0x8013FBB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013FBB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013FBB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013FBBC: jr          $ra
    // 0x8013FBC0: nop

    return;
    // 0x8013FBC0: nop

;}
RECOMP_FUNC void mnPlayersVSMakePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139098: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8013909C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801390A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801390A4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801390A8: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x801390AC: addiu       $t6, $t6, -0x4724
    ctx->r14 = ADD32(ctx->r14, -0X4724);
    // 0x801390B0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801390B4: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x801390B8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801390BC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801390C0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801390C4: addiu       $t9, $t9, -0x4714
    ctx->r25 = ADD32(ctx->r25, -0X4714);
    // 0x801390C8: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
    // 0x801390CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801390D0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801390D4: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x801390D8: addiu       $t4, $t4, -0x4704
    ctx->r12 = ADD32(ctx->r12, -0X4704);
    // 0x801390DC: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x801390E0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801390E4: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x801390E8: addiu       $t8, $zero, 0x21
    ctx->r24 = ADD32(0, 0X21);
    // 0x801390EC: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x801390F0: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x801390F4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801390F8: addiu       $t7, $t7, -0x7060
    ctx->r15 = ADD32(ctx->r15, -0X7060);
    // 0x801390FC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80139100: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80139104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80139108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013910C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80139110: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x80139114: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80139118: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013911C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80139120: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x80139124: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80139128: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x8013912C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80139130: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80139134: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80139138: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8013913C: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80139140: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80139144: sw          $t6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r14;
    // 0x80139148: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x8013914C: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80139150: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80139154: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80139158: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013915C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x80139160: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80139164: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80139168: addu        $t3, $v0, $t0
    ctx->r11 = ADD32(ctx->r2, ctx->r8);
    // 0x8013916C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80139170: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80139174: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80139178: lw          $t5, -0x3B60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3B60);
    // 0x8013917C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80139180: addiu       $t8, $t8, -0x7708
    ctx->r24 = ADD32(ctx->r24, -0X7708);
    // 0x80139184: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80139188: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013918C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80139190: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80139194: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80139198: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8013919C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801391A0: jal         0x800CD050
    // 0x801391A4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x801391A4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_0:
    // 0x801391A8: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x801391AC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801391B0: addiu       $t2, $t2, -0x4578
    ctx->r10 = ADD32(ctx->r10, -0X4578);
    // 0x801391B4: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x801391B8: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x801391BC: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x801391C0: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x801391C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801391C8: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x801391CC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x801391D0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x801391D4: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x801391D8: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x801391DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801391E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801391E4: bne         $a0, $at, L_80139208
    if (ctx->r4 != ctx->r1) {
        // 0x801391E8: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80139208;
    }
    // 0x801391E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801391EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801391F0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x801391F4: jal         0x801386E4
    // 0x801391F8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    mnPlayersVSUpdatePuck(rdram, ctx);
        goto after_1;
    // 0x801391F8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_1:
    // 0x801391FC: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80139200: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80139204: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
L_80139208:
    // 0x80139208: bnel        $a0, $zero, L_80139240
    if (ctx->r4 != 0) {
        // 0x8013920C: lw          $a1, 0x48($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X48);
            goto L_80139240;
    }
    goto skip_0;
    // 0x8013920C: lw          $a1, 0x48($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X48);
    skip_0:
    // 0x80139210: lw          $t3, 0x80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X80);
    // 0x80139214: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80139218: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8013921C: beq         $t3, $at, L_8013923C
    if (ctx->r11 == ctx->r1) {
        // 0x80139220: addu        $a2, $sp, $t0
        ctx->r6 = ADD32(ctx->r29, ctx->r8);
            goto L_8013923C;
    }
    // 0x80139220: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x80139224: lw          $a2, 0x50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X50);
    // 0x80139228: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x8013922C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80139230: jal         0x8000A0D0
    // 0x80139234: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_2;
    // 0x80139234: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_2:
    // 0x80139238: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
L_8013923C:
    // 0x8013923C: lw          $a1, 0x48($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X48);
L_80139240:
    // 0x80139240: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80139244: bne         $a1, $at, L_8013926C
    if (ctx->r5 != ctx->r1) {
        // 0x80139248: lui         $at, 0x424C
        ctx->r1 = S32(0X424C << 16);
            goto L_8013926C;
    }
    // 0x80139248: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8013924C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139250: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80139254: lui         $at, 0x4321
    ctx->r1 = S32(0X4321 << 16);
    // 0x80139258: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013925C: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x80139260: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80139264: b           L_80139274
    // 0x80139268: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
        goto L_80139274;
    // 0x80139268: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
L_8013926C:
    // 0x8013926C: jal         0x80138798
    // 0x80139270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSCenterPuckInPortrait(rdram, ctx);
        goto after_3;
    // 0x80139270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80139274:
    // 0x80139274: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80139278: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x8013927C: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80139280: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80139284: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80139288: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8013928C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80139290: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80139294: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80139298: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8013929C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x801392A0: jr          $ra
    // 0x801392A4: nop

    return;
    // 0x801392A4: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801534E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801534E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801534E8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801534EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801534F0: jal         0x800DE7D8
    // 0x801534F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    mpCommonCheckFighterCliff(rdram, ctx);
        goto after_0;
    // 0x801534F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801534F8: beq         $v0, $zero, L_80153534
    if (ctx->r2 == 0) {
        // 0x801534FC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80153534;
    }
    // 0x801534FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80153500: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80153504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80153508: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8015350C: lhu         $t8, 0xD2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XD2);
    // 0x80153510: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x80153514: beq         $t9, $zero, L_8015352C
    if (ctx->r25 == 0) {
        // 0x80153518: nop
    
            goto L_8015352C;
    }
    // 0x80153518: nop

    // 0x8015351C: jal         0x80144C24
    // 0x80153520: nop

    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153520: nop

    after_1:
    // 0x80153524: b           L_80153538
    // 0x80153528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80153538;
    // 0x80153528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015352C:
    // 0x8015352C: jal         0x80142E3C
    // 0x80153530: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    ftCommonLandingFallSpecialSetStatus(rdram, ctx);
        goto after_2;
    // 0x80153530: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    after_2:
L_80153534:
    // 0x80153534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80153538:
    // 0x80153538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015353C: jr          $ra
    // 0x80153540: nop

    return;
    // 0x80153540: nop

;}
RECOMP_FUNC void itMBallOpenAirProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CCBC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017CCC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017CCC4: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x8017CCC8: lhu         $v0, 0x33E($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X33E);
    // 0x8017CCCC: bnel        $v0, $zero, L_8017CD6C
    if (ctx->r2 != 0) {
        // 0x8017CCD0: lw          $v1, 0x358($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X358);
            goto L_8017CD6C;
    }
    goto skip_0;
    // 0x8017CCD0: lw          $v1, 0x358($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X358);
    skip_0:
    // 0x8017CCD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017CCD8: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8017CCDC: lw          $v0, -0x6BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BB0);
    // 0x8017CCE0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8017CCE4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8017CCE8: bne         $v0, $zero, L_8017CD00
    if (ctx->r2 != 0) {
        // 0x8017CCEC: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_8017CD00;
    }
    // 0x8017CCEC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8017CCF0: jal         0x80173228
    // 0x8017CCF4: nop

    itMainMakeMonster(rdram, ctx);
        goto after_0;
    // 0x8017CCF4: nop

    after_0:
    // 0x8017CCF8: b           L_8017CD9C
    // 0x8017CCFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017CD9C;
    // 0x8017CCFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017CD00:
    // 0x8017CD00: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8017CD04: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8017CD08: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x8017CD0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017CD10: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8017CD14: addiu       $a1, $v0, 0x1F
    ctx->r5 = ADD32(ctx->r2, 0X1F);
    // 0x8017CD18: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x8017CD1C: jal         0x8016F238
    // 0x8017CD20: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    itManagerMakeItemKind(rdram, ctx);
        goto after_1;
    // 0x8017CD20: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_1:
    // 0x8017CD24: beq         $v0, $zero, L_8017CD60
    if (ctx->r2 == 0) {
        // 0x8017CD28: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_8017CD60;
    }
    // 0x8017CD28: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8017CD2C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8017CD30: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x8017CD34: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8017CD38: lbu         $t8, 0x14($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X14);
    // 0x8017CD3C: sb          $t8, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r24;
    // 0x8017CD40: lbu         $t9, 0x15($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X15);
    // 0x8017CD44: sb          $t9, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r25;
    // 0x8017CD48: lbu         $t1, 0x16($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X16);
    // 0x8017CD4C: sb          $t1, 0x16($v1)
    MEM_B(0X16, ctx->r3) = ctx->r9;
    // 0x8017CD50: lw          $t2, 0x18($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X18);
    // 0x8017CD54: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x8017CD58: lw          $t3, 0x374($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X374);
    // 0x8017CD5C: sw          $t3, 0x374($v1)
    MEM_W(0X374, ctx->r3) = ctx->r11;
L_8017CD60:
    // 0x8017CD60: b           L_8017CD9C
    // 0x8017CD64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017CD9C;
    // 0x8017CD64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017CD68: lw          $v1, 0x358($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X358);
L_8017CD6C:
    // 0x8017CD6C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8017CD70: sh          $t4, 0x33E($t0)
    MEM_H(0X33E, ctx->r8) = ctx->r12;
    // 0x8017CD74: beq         $v1, $zero, L_8017CD9C
    if (ctx->r3 == 0) {
        // 0x8017CD78: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8017CD9C;
    }
    // 0x8017CD78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017CD7C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017CD80: lw          $t5, 0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X74);
    // 0x8017CD84: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8017CD88: sw          $t8, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r24;
    // 0x8017CD8C: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8017CD90: sw          $t7, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r15;
    // 0x8017CD94: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8017CD98: sw          $t8, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r24;
L_8017CD9C:
    // 0x8017CD9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017CDA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017CDA4: jr          $ra
    // 0x8017CDA8: nop

    return;
    // 0x8017CDA8: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwSetAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FCB0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015FCB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8015FCB8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8015FCBC: sw          $t6, 0x14C($v0)
    MEM_W(0X14C, ctx->r2) = ctx->r14;
    // 0x8015FCC0: jr          $ra
    // 0x8015FCC4: sb          $t7, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r15;
    return;
    // 0x8015FCC4: sb          $t7, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_ovl8_80372A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372A50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80372A54: jal         0x80373168
    // 0x80372A58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_ovl8_80373168(rdram, ctx);
        goto after_0;
    // 0x80372A58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80372A5C: beq         $v0, $zero, L_80372A74
    if (ctx->r2 == 0) {
        // 0x80372A60: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80372A74;
    }
    // 0x80372A60: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80372A64: sw          $a1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r5;
    // 0x80372A68: sw          $v0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r2;
    // 0x80372A6C: b           L_80372A84
    // 0x80372A70: sw          $zero, 0x28($a1)
    MEM_W(0X28, ctx->r5) = 0;
        goto L_80372A84;
    // 0x80372A70: sw          $zero, 0x28($a1)
    MEM_W(0X28, ctx->r5) = 0;
L_80372A74:
    // 0x80372A74: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80372A78: sw          $a1, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r5;
    // 0x80372A7C: sw          $zero, 0x24($a1)
    MEM_W(0X24, ctx->r5) = 0;
    // 0x80372A80: sw          $zero, 0x28($a1)
    MEM_W(0X28, ctx->r5) = 0;
L_80372A84:
    // 0x80372A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372A8C: jr          $ra
    // 0x80372A90: nop

    return;
    // 0x80372A90: nop

;}
RECOMP_FUNC void itStarmieWeaponSwiftMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80182534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182538: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018253C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80182540: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80182544: addiu       $a1, $a1, -0x4E1C
    ctx->r5 = ADD32(ctx->r5, -0X4E1C);
    // 0x80182548: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8018254C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80182550: jal         0x801655C8
    // 0x80182554: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80182554: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80182558: bne         $v0, $zero, L_80182568
    if (ctx->r2 != 0) {
        // 0x8018255C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80182568;
    }
    // 0x8018255C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80182560: b           L_801825F8
    // 0x80182564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801825F8;
    // 0x80182564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80182568:
    // 0x80182568: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8018256C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80182570: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80182574: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x80182578: lw          $v1, 0x84($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X84);
    // 0x8018257C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80182580: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80182584: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x80182588: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018258C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80182590: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x80182594: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80182598: lw          $a3, 0x74($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X74);
    // 0x8018259C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801825A0: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    // 0x801825A4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801825A8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801825AC: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x801825B0: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801825B4: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x801825B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801825BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801825C0: jal         0x8010066C
    // 0x801825C4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801825C4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x801825C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801825CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801825D0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x801825D4: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
    // 0x801825D8: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x801825DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801825E0: bne         $t4, $at, L_801825F4
    if (ctx->r12 != ctx->r1) {
        // 0x801825E4: sw          $t3, 0x268($v1)
        MEM_W(0X268, ctx->r3) = ctx->r11;
            goto L_801825F4;
    }
    // 0x801825E4: sw          $t3, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r11;
    // 0x801825E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801825EC: lwc1        $f16, -0x3138($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3138);
    // 0x801825F0: swc1        $f16, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f16.u32l;
L_801825F4:
    // 0x801825F4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_801825F8:
    // 0x801825F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801825FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80182600: jr          $ra
    // 0x80182604: nop

    return;
    // 0x80182604: nop

;}
RECOMP_FUNC void mpProcessRunFloorEdgeAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9F84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9F8C: jal         0x800D9A00
    // 0x800D9F90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpProcessCheckFloorEdgeCollisionL(rdram, ctx);
        goto after_0;
    // 0x800D9F90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D9F94: beq         $v0, $zero, L_800D9FA4
    if (ctx->r2 == 0) {
        // 0x800D9F98: nop
    
            goto L_800D9FA4;
    }
    // 0x800D9F98: nop

    // 0x800D9F9C: jal         0x800D9AB0
    // 0x800D9FA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpProcessFloorEdgeLAdjust(rdram, ctx);
        goto after_1;
    // 0x800D9FA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_800D9FA4:
    // 0x800D9FA4: jal         0x800D9CC0
    // 0x800D9FA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpProcessCheckFloorEdgeCollisionR(rdram, ctx);
        goto after_2;
    // 0x800D9FA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800D9FAC: beql        $v0, $zero, L_800D9FC0
    if (ctx->r2 == 0) {
        // 0x800D9FB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9FC0;
    }
    goto skip_0;
    // 0x800D9FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D9FB4: jal         0x800D9D70
    // 0x800D9FB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpProcessFloorEdgeRAdjust(rdram, ctx);
        goto after_3;
    // 0x800D9FB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800D9FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9FC0:
    // 0x800D9FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9FC4: jr          $ra
    // 0x800D9FC8: nop

    return;
    // 0x800D9FC8: nop

;}
RECOMP_FUNC void mnVSItemSwitchMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131DEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131DF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131DF8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131DFC: jal         0x80009968
    // 0x80131E00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131E04: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131E08: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131E0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131E10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131E14: addiu       $a1, $a1, 0x1CA4
    ctx->r5 = ADD32(ctx->r5, 0X1CA4);
    // 0x80131E18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131E20: jal         0x80009DF4
    // 0x80131E24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131E24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131E28: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131E2C: lw          $t7, 0x3530($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3530);
    // 0x80131E30: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131E34: addiu       $t8, $t8, 0x9A8
    ctx->r24 = ADD32(ctx->r24, 0X9A8);
    // 0x80131E38: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131E3C: jal         0x800CCFDC
    // 0x80131E40: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131E40: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131E44: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E48: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80131E4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131E50: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80131E54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131E58: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131E5C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131E60: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131E64: addiu       $t3, $zero, 0xF2
    ctx->r11 = ADD32(0, 0XF2);
    // 0x80131E68: addiu       $t4, $zero, 0xC7
    ctx->r12 = ADD32(0, 0XC7);
    // 0x80131E6C: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x80131E70: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131E74: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80131E78: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80131E7C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80131E80: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80131E84: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80131E88: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80131E8C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131E90: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131E94: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131E98: lw          $t6, 0x3530($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3530);
    // 0x80131E9C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131EA0: addiu       $t7, $t7, 0xB20
    ctx->r15 = ADD32(ctx->r15, 0XB20);
    // 0x80131EA4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131EA8: jal         0x800CCFDC
    // 0x80131EAC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131EAC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x80131EB0: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131EB4: lui         $at, 0x435E
    ctx->r1 = S32(0X435E << 16);
    // 0x80131EB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131EBC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80131EC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131EC4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131EC8: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80131ECC: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131ED0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80131ED4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131ED8: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131EDC: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131EE0: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131EE4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131EE8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80131EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131EF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131EF4: jr          $ra
    // 0x80131EF8: nop

    return;
    // 0x80131EF8: nop

;}
RECOMP_FUNC void ftCommonYoshiEggProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CB24: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014CB28: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x8014CB2C: beq         $v1, $zero, L_8014CC04
    if (ctx->r3 == 0) {
        // 0x8014CB30: nop
    
            goto L_8014CC04;
    }
    // 0x8014CB30: nop

    // 0x8014CB34: lw          $t7, 0x14C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14C);
    // 0x8014CB38: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
    // 0x8014CB3C: bne         $t7, $zero, L_8014CBF4
    if (ctx->r15 != 0) {
        // 0x8014CB40: lw          $a0, 0x10($t6)
        ctx->r4 = MEM_W(ctx->r14, 0X10);
            goto L_8014CBF4;
    }
    // 0x8014CB40: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x8014CB44: lb          $v1, 0x1C3($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C3);
    // 0x8014CB48: bgez        $v1, L_8014CB58
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8014CB4C: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_8014CB58;
    }
    // 0x8014CB4C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8014CB50: b           L_8014CB58
    // 0x8014CB54: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
        goto L_8014CB58;
    // 0x8014CB54: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
L_8014CB58:
    // 0x8014CB58: slti        $at, $a1, 0x1A
    ctx->r1 = SIGNED(ctx->r5) < 0X1A ? 1 : 0;
    // 0x8014CB5C: bnel        $at, $zero, L_8014CB98
    if (ctx->r1 != 0) {
        // 0x8014CB60: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8014CB98;
    }
    goto skip_0;
    // 0x8014CB60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8014CB64: bgez        $v1, L_8014CB74
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8014CB68: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8014CB74;
    }
    // 0x8014CB68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014CB6C: b           L_8014CB74
    // 0x8014CB70: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8014CB74;
    // 0x8014CB70: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8014CB74:
    // 0x8014CB74: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8014CB78: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8014CB7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014CB80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014CB84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014CB88: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8014CB8C: b           L_8014CBA0
    // 0x8014CB90: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
        goto L_8014CBA0;
    // 0x8014CB90: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x8014CB94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8014CB98:
    // 0x8014CB98: nop

    // 0x8014CB9C: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
L_8014CBA0:
    // 0x8014CBA0: lb          $v1, 0x1C2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C2);
    // 0x8014CBA4: bgez        $v1, L_8014CBB4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8014CBA8: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_8014CBB4;
    }
    // 0x8014CBA8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8014CBAC: b           L_8014CBB4
    // 0x8014CBB0: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
        goto L_8014CBB4;
    // 0x8014CBB0: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
L_8014CBB4:
    // 0x8014CBB4: slti        $at, $a1, 0x1A
    ctx->r1 = SIGNED(ctx->r5) < 0X1A ? 1 : 0;
    // 0x8014CBB8: bne         $at, $zero, L_8014CBEC
    if (ctx->r1 != 0) {
        // 0x8014CBBC: nop
    
            goto L_8014CBEC;
    }
    // 0x8014CBBC: nop

    // 0x8014CBC0: bgez        $v1, L_8014CBD0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8014CBC4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8014CBD0;
    }
    // 0x8014CBC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014CBC8: b           L_8014CBD0
    // 0x8014CBCC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8014CBD0;
    // 0x8014CBCC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8014CBD0:
    // 0x8014CBD0: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x8014CBD4: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8014CBD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014CBDC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014CBE0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8014CBE4: jr          $ra
    // 0x8014CBE8: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8014CBE8: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
L_8014CBEC:
    // 0x8014CBEC: jr          $ra
    // 0x8014CBF0: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8014CBF0: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
L_8014CBF4:
    // 0x8014CBF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014CBF8: nop

    // 0x8014CBFC: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8014CC00: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
L_8014CC04:
    // 0x8014CC04: jr          $ra
    // 0x8014CC08: nop

    return;
    // 0x8014CC08: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageSetShowInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E690: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010E694: lw          $t6, 0x15F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X15F8);
    // 0x8010E698: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010E69C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010E6A0: beq         $t6, $zero, L_8010E6B4
    if (ctx->r14 == 0) {
        // 0x8010E6A4: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_8010E6B4;
    }
    // 0x8010E6A4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8010E6A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8010E6AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E6B0: sb          $t7, 0x1601($at)
    MEM_B(0X1601, ctx->r1) = ctx->r15;
L_8010E6B4:
    // 0x8010E6B4: lw          $t8, 0x1664($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1664);
    // 0x8010E6B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8010E6BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E6C0: beq         $t8, $zero, L_8010E6CC
    if (ctx->r24 == 0) {
        // 0x8010E6C4: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8010E6CC;
    }
    // 0x8010E6C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8010E6C8: sb          $t9, 0x166D($at)
    MEM_B(0X166D, ctx->r1) = ctx->r25;
L_8010E6CC:
    // 0x8010E6CC: lw          $t0, 0x16D0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16D0);
    // 0x8010E6D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E6D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8010E6D8: beq         $t0, $zero, L_8010E6E4
    if (ctx->r8 == 0) {
        // 0x8010E6DC: nop
    
            goto L_8010E6E4;
    }
    // 0x8010E6DC: nop

    // 0x8010E6E0: sb          $t1, 0x16D9($at)
    MEM_B(0X16D9, ctx->r1) = ctx->r9;
L_8010E6E4:
    // 0x8010E6E4: lw          $t2, 0x173C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X173C);
    // 0x8010E6E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E6EC: beq         $t2, $zero, L_8010E6F8
    if (ctx->r10 == 0) {
        // 0x8010E6F0: nop
    
            goto L_8010E6F8;
    }
    // 0x8010E6F0: nop

    // 0x8010E6F4: sb          $t3, 0x1745($at)
    MEM_B(0X1745, ctx->r1) = ctx->r11;
L_8010E6F8:
    // 0x8010E6F8: jr          $ra
    // 0x8010E6FC: nop

    return;
    // 0x8010E6FC: nop

;}
RECOMP_FUNC void func_ovl8_8037C2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C2D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C2D4: bne         $a0, $zero, L_8037C2EC
    if (ctx->r4 != 0) {
        // 0x8037C2D8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8037C2EC;
    }
    // 0x8037C2D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C2DC: jal         0x803717A0
    // 0x8037C2E0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037C2E0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x8037C2E4: beq         $v0, $zero, L_8037C2F8
    if (ctx->r2 == 0) {
        // 0x8037C2E8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037C2F8;
    }
    // 0x8037C2E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8037C2EC:
    // 0x8037C2EC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037C2F0: addiu       $t6, $t6, -0x5E90
    ctx->r14 = ADD32(ctx->r14, -0X5E90);
    // 0x8037C2F4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
L_8037C2F8:
    // 0x8037C2F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C2FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C300: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037C304: jr          $ra
    // 0x8037C308: nop

    return;
    // 0x8037C308: nop

;}
RECOMP_FUNC void ftBossWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80158F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80158F7C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80158F80: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x80158F84: bne         $t6, $zero, L_80158F9C
    if (ctx->r14 != 0) {
        // 0x80158F88: nop
    
            goto L_80158F9C;
    }
    // 0x80158F88: nop

    // 0x80158F8C: jal         0x80158824
    // 0x80158F90: nop

    ftBossWaitDecideStatusPlayer(rdram, ctx);
        goto after_0;
    // 0x80158F90: nop

    after_0:
    // 0x80158F94: b           L_80158FA8
    // 0x80158F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80158FA8;
    // 0x80158F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80158F9C:
    // 0x80158F9C: jal         0x80158C34
    // 0x80158FA0: nop

    ftBossWaitDecideStatusComputer(rdram, ctx);
        goto after_1;
    // 0x80158FA0: nop

    after_1:
    // 0x80158FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80158FA8:
    // 0x80158FA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80158FAC: jr          $ra
    // 0x80158FB0: nop

    return;
    // 0x80158FB0: nop

;}
RECOMP_FUNC void gmRumbleUpdateEventCheckEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801150F0: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x801150F4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x801150F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801150FC: bnel        $v1, $zero, L_80115168
    if (ctx->r3 != 0) {
        // 0x80115100: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80115168;
    }
    goto skip_0;
    // 0x80115100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80115104: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
L_80115108:
    // 0x80115108: srl         $t7, $t6, 13
    ctx->r15 = S32(U32(ctx->r14) >> 13);
    // 0x8011510C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80115110: beq         $at, $zero, L_8011515C
    if (ctx->r1 == 0) {
        // 0x80115114: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8011515C;
    }
    // 0x80115114: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80115118: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011511C: addu        $at, $at, $t7
    gpr jr_addend_80115124 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80115120: lw          $t7, 0xCF8($at)
    ctx->r15 = ADD32(ctx->r1, 0XCF8);
    // 0x80115124: jr          $t7
    // 0x80115128: nop

    switch (jr_addend_80115124 >> 2) {
        case 0: goto L_8011512C; break;
        case 1: goto L_80115134; break;
        case 2: goto L_80115134; break;
        case 3: goto L_8011513C; break;
        case 4: goto L_80115144; break;
        default: switch_error(__func__, 0x80115124, 0x80130CF8);
    }
    // 0x80115128: nop

L_8011512C:
    // 0x8011512C: jr          $ra
    // 0x80115130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80115130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80115134:
    // 0x80115134: b           L_8011515C
    // 0x80115138: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8011515C;
    // 0x80115138: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8011513C:
    // 0x8011513C: b           L_8011515C
    // 0x80115140: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
        goto L_8011515C;
    // 0x80115140: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_80115144:
    // 0x80115144: lhu         $t8, 0x4($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X4);
    // 0x80115148: bnel        $a1, $t8, L_8011515C
    if (ctx->r5 != ctx->r24) {
        // 0x8011514C: lw          $v0, 0xC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XC);
            goto L_8011515C;
    }
    goto skip_1;
    // 0x8011514C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    skip_1:
    // 0x80115150: b           L_8011515C
    // 0x80115154: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
        goto L_8011515C;
    // 0x80115154: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80115158: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
L_8011515C:
    // 0x8011515C: beql        $v1, $zero, L_80115108
    if (ctx->r3 == 0) {
        // 0x80115160: lhu         $t6, 0x0($v0)
        ctx->r14 = MEM_HU(ctx->r2, 0X0);
            goto L_80115108;
    }
    goto skip_2;
    // 0x80115160: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    skip_2:
    // 0x80115164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80115168:
    // 0x80115168: jr          $ra
    // 0x8011516C: nop

    return;
    // 0x8011516C: nop

;}
RECOMP_FUNC void ftMarioSpecialLwSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156808: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015680C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156810: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80156814: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80156818: jal         0x801567A4
    // 0x8015681C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMarioSpecialAirLwSetDisableRise(rdram, ctx);
        goto after_0;
    // 0x8015681C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80156820: jal         0x800DEEC8
    // 0x80156824: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x80156824: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80156828: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015682C: addiu       $t7, $zero, 0x4000
    ctx->r15 = ADD32(0, 0X4000);
    // 0x80156830: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x80156834: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80156838: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015683C: jal         0x800E6F24
    // 0x80156840: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80156840: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80156844: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80156848: jal         0x800D8D10
    // 0x8015684C: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    ftPhysicsClampAirVelY(rdram, ctx);
        goto after_3;
    // 0x8015684C: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    after_3:
    // 0x80156850: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80156854: jal         0x800D8E78
    // 0x80156858: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_4;
    // 0x80156858: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    after_4:
    // 0x8015685C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80156860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156864: jr          $ra
    // 0x80156868: nop

    return;
    // 0x80156868: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialNUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160810: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160818: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016081C: lw          $t6, 0x18C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18C);
    // 0x80160820: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x80160824: bltzl       $t8, L_80160864
    if (SIGNED(ctx->r24) < 0) {
        // 0x80160828: lw          $t3, 0x17C($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X17C);
            goto L_80160864;
    }
    goto skip_0;
    // 0x80160828: lw          $t3, 0x17C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X17C);
    skip_0:
    // 0x8016082C: lw          $t9, 0x17C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X17C);
    // 0x80160830: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80160834: bnel        $t9, $at, L_80160888
    if (ctx->r25 != ctx->r1) {
        // 0x80160838: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80160888;
    }
    goto skip_1;
    // 0x80160838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8016083C: jal         0x80101F84
    // 0x80160840: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerCaptainFalconPunchMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80160840: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80160844: beq         $v0, $zero, L_80160858
    if (ctx->r2 == 0) {
        // 0x80160848: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80160858;
    }
    // 0x80160848: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8016084C: lbu         $t1, 0x18F($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X18F);
    // 0x80160850: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80160854: sb          $t2, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r10;
L_80160858:
    // 0x80160858: b           L_80160884
    // 0x8016085C: sw          $zero, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = 0;
        goto L_80160884;
    // 0x8016085C: sw          $zero, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = 0;
    // 0x80160860: lw          $t3, 0x17C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X17C);
L_80160864:
    // 0x80160864: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80160868: bnel        $t3, $at, L_80160888
    if (ctx->r11 != ctx->r1) {
        // 0x8016086C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80160888;
    }
    goto skip_2;
    // 0x8016086C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80160870: jal         0x800E9C3C
    // 0x80160874: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftParamProcStopEffect(rdram, ctx);
        goto after_1;
    // 0x80160874: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80160878: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8016087C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80160880: sw          $t4, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->r12;
L_80160884:
    // 0x80160884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80160888:
    // 0x80160888: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016088C: jr          $ra
    // 0x80160890: nop

    return;
    // 0x80160890: nop

;}
RECOMP_FUNC void sc1PChallengerMakeFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F58: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80131F5C: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80131F60: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x80131F64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131F68: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x80131F6C: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x80131F70: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80131F74: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131F78: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131F7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131F80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131F84: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80131F88: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80131F8C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80131F90: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80131F94: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131F98: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131F9C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131FA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FA4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131FA8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131FAC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131FB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80131FB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131FBC: jal         0x8000B93C
    // 0x80131FC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131FC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FC4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131FC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131FCC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80131FD0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131FD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131FD8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80131FDC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131FE0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80131FE4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80131FE8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80131FEC: jal         0x80007080
    // 0x80131FF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80131FF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80131FF4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80131FF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131FFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132000: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80132004: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80132008: lwc1        $f6, 0x2470($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2470);
    // 0x8013200C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132010: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132014: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x80132018: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x8013201C: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80132020: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80132024: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x80132028: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x8013202C: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80132030: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132034: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80132038: jr          $ra
    // 0x8013203C: nop

    return;
    // 0x8013203C: nop

;}
RECOMP_FUNC void efManagerYoshiEggExplodeMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103A88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80103A8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80103A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80103A94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103A98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80103A9C: lw          $a0, 0x1004($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1004);
    // 0x80103AA0: jal         0x800CE9E8
    // 0x80103AA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80103AA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80103AA8: beq         $v0, $zero, L_80103B10
    if (ctx->r2 == 0) {
        // 0x80103AAC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80103B10;
    }
    // 0x80103AAC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80103AB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80103AB4: jal         0x800CE1DC
    // 0x80103AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80103AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80103ABC: beq         $v0, $zero, L_80103B04
    if (ctx->r2 == 0) {
        // 0x80103AC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80103B04;
    }
    // 0x80103AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103AC4: jal         0x800CEA14
    // 0x80103AC8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x80103AC8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80103ACC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80103AD0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80103AD4: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80103AD8: bnel        $t6, $zero, L_80103AEC
    if (ctx->r14 != 0) {
        // 0x80103ADC: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_80103AEC;
    }
    goto skip_0;
    // 0x80103ADC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80103AE0: b           L_80103B14
    // 0x80103AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103B14;
    // 0x80103AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80103AE8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_80103AEC:
    // 0x80103AEC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80103AF0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80103AF4: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80103AF8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80103AFC: b           L_80103B10
    // 0x80103B00: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80103B10;
    // 0x80103B00: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_80103B04:
    // 0x80103B04: jal         0x800CEA40
    // 0x80103B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80103B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80103B0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80103B10:
    // 0x80103B10: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80103B14:
    // 0x80103B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103B18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103B1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80103B20: jr          $ra
    // 0x80103B24: nop

    return;
    // 0x80103B24: nop

;}
RECOMP_FUNC void func_ovl8_80371638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037163C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80371640: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80371644: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80371648: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037164C: sw          $a1, -0x119C($at)
    MEM_W(-0X119C, ctx->r1) = ctx->r5;
    // 0x80371650: addiu       $v1, $v1, -0x11A0
    ctx->r3 = ADD32(ctx->r3, -0X11A0);
    // 0x80371654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371658: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037165C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80371660: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80371664: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80371668: sw          $t7, -0x1198($at)
    MEM_W(-0X1198, ctx->r1) = ctx->r15;
    // 0x8037166C: addiu       $a0, $a0, -0x1190
    ctx->r4 = ADD32(ctx->r4, -0X1190);
    // 0x80371670: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80371674: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80371678: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8037167C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80371680: sw          $a3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r7;
    // 0x80371684: jal         0x80371460
    // 0x80371688: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    func_ovl8_80371460(rdram, ctx);
        goto after_0;
    // 0x80371688: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    after_0:
    // 0x8037168C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371694: jr          $ra
    // 0x80371698: nop

    return;
    // 0x80371698: nop

;}
RECOMP_FUNC void efManagerQuakeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801007D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801007DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801007E0: jal         0x8000DF34
    // 0x801007E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x801007E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x801007E8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x801007EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801007F0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801007F4: lwc1        $f6, 0x78($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X78);
    // 0x801007F8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801007FC: nop

    // 0x80100800: bc1f        L_80100824
    if (!c1cs) {
        // 0x80100804: nop
    
            goto L_80100824;
    }
    // 0x80100804: nop

    // 0x80100808: lw          $a0, 0x84($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X84);
    // 0x8010080C: jal         0x800FD4F8
    // 0x80100810: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x80100810: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_1:
    // 0x80100814: jal         0x80009A84
    // 0x80100818: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80100818: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8010081C: b           L_801008AC
    // 0x80100820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801008AC;
    // 0x80100820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80100824:
    // 0x80100824: lw          $t6, 0x1460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1460);
    // 0x80100828: lw          $v1, 0x74($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X74);
    // 0x8010082C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80100830: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80100834: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80100838: addiu       $a1, $v0, 0x48
    ctx->r5 = ADD32(ctx->r2, 0X48);
    // 0x8010083C: jal         0x8001902C
    // 0x80100840: addiu       $a2, $v0, 0x3C
    ctx->r6 = ADD32(ctx->r2, 0X3C);
    syVectorDiff3D(rdram, ctx);
        goto after_3;
    // 0x80100840: addiu       $a2, $v0, 0x3C
    ctx->r6 = ADD32(ctx->r2, 0X3C);
    after_3:
    // 0x80100844: jal         0x80018F7C
    // 0x80100848: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    syVectorMag3D(rdram, ctx);
        goto after_4;
    // 0x80100848: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x8010084C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80100850: lwc1        $f12, 0x9C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X9C8);
    // 0x80100854: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80100858: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8010085C: nop

    // 0x80100860: bc1fl       L_8010088C
    if (!c1cs) {
        // 0x80100864: lwc1        $f4, 0x24($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
            goto L_8010088C;
    }
    goto skip_0;
    // 0x80100864: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    skip_0:
    // 0x80100868: div.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8010086C: lwc1        $f8, 0x24($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80100870: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80100874: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80100878: lwc1        $f16, 0x20($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8010087C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80100880: b           L_80100898
    // 0x80100884: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
        goto L_80100898;
    // 0x80100884: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80100888: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
L_8010088C:
    // 0x8010088C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80100890: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80100894: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
L_80100898:
    // 0x80100898: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010089C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x801008A0: jal         0x8010D128
    // 0x801008A4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    gmCameraSetVelAt(rdram, ctx);
        goto after_5;
    // 0x801008A4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x801008A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801008AC:
    // 0x801008AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801008B0: jr          $ra
    // 0x801008B4: nop

    return;
    // 0x801008B4: nop

;}
RECOMP_FUNC void ftCommonDamageCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801404E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801404E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801404E8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801404EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801404F0: jal         0x801404B8
    // 0x801404F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonDamageDecHitStunSetPublic(rdram, ctx);
        goto after_0;
    // 0x801404F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801404F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801404FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80140500: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80140504: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80140508: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8014050C: nop

    // 0x80140510: bc1fl       L_80140530
    if (!c1cs) {
        // 0x80140514: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140530;
    }
    goto skip_0;
    // 0x80140514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80140518: lw          $t8, 0xB18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XB18);
    // 0x8014051C: bnel        $t8, $zero, L_80140530
    if (ctx->r24 != 0) {
        // 0x80140520: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140530;
    }
    goto skip_1;
    // 0x80140520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80140524: jal         0x800DEE54
    // 0x80140528: nop

    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_1;
    // 0x80140528: nop

    after_1:
    // 0x8014052C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140530:
    // 0x80140530: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80140534: jr          $ra
    // 0x80140538: nop

    return;
    // 0x80140538: nop

;}
RECOMP_FUNC void syUtilsArcSin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001873C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018740: lwc1        $f4, -0x1C88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C88);
    // 0x80018744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001874C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80018750: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80018754: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018758: bc1f        L_8001876C
    if (!c1cs) {
        // 0x8001875C: nop
    
            goto L_8001876C;
    }
    // 0x8001875C: nop

    // 0x80018760: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018764: b           L_800187B0
    // 0x80018768: lwc1        $f0, -0x1C84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C84);
        goto L_800187B0;
    // 0x80018768: lwc1        $f0, -0x1C84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C84);
L_8001876C:
    // 0x8001876C: lwc1        $f6, -0x1C80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C80);
    // 0x80018770: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018774: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80018778: nop

    // 0x8001877C: bc1f        L_8001878C
    if (!c1cs) {
        // 0x80018780: nop
    
            goto L_8001878C;
    }
    // 0x80018780: nop

    // 0x80018784: b           L_800187B0
    // 0x80018788: lwc1        $f0, -0x1C7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C7C);
        goto L_800187B0;
    // 0x80018788: lwc1        $f0, -0x1C7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C7C);
L_8001878C:
    // 0x8001878C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018790: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018794: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018798: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x8001879C: jal         0x80033510
    // 0x800187A0: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800187A0: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x800187A4: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800187A8: jal         0x80018514
    // 0x800187AC: div.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    syUtilsArcTan(rdram, ctx);
        goto after_1;
    // 0x800187AC: div.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    after_1:
L_800187B0:
    // 0x800187B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800187B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800187B8: jr          $ra
    // 0x800187BC: nop

    return;
    // 0x800187BC: nop

;}
RECOMP_FUNC void ftKirbyCopyPurinSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151A78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80151A7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151A80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80151A84: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80151A88: jal         0x800DEEC8
    // 0x80151A8C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80151A8C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151A90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80151A94: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80151A98: addiu       $a1, $zero, 0x126
    ctx->r5 = ADD32(0, 0X126);
    // 0x80151A9C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80151AA0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151AA4: jal         0x800E6F24
    // 0x80151AA8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151AA8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151AAC: jal         0x800D8EB8
    // 0x80151AB0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80151AB0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80151AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151AB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80151ABC: jr          $ra
    // 0x80151AC0: nop

    return;
    // 0x80151AC0: nop

;}
RECOMP_FUNC void wpMainGetStaledDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168128: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8016812C: lwc1        $f8, 0x108($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X108);
    // 0x80168130: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80168134: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80168138: lwc1        $f16, -0x3578($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3578);
    // 0x8016813C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80168140: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80168144: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80168148: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8016814C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80168150: jr          $ra
    // 0x80168154: nop

    return;
    // 0x80168154: nop

;}
RECOMP_FUNC void itHammerWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801761C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801761C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801761CC: jal         0x80172E74
    // 0x801761D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x801761D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801761D4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801761D8: addiu       $a1, $a1, -0x625C
    ctx->r5 = ADD32(ctx->r5, -0X625C);
    // 0x801761DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801761E0: jal         0x80172EC8
    // 0x801761E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801761E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801761E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801761EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801761F0: jr          $ra
    // 0x801761F4: nop

    return;
    // 0x801761F4: nop

;}
RECOMP_FUNC void mnCharactersMakeStoryCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133004: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133008: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013300C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133010: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80133014: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133018: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8013301C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133020: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133024: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133028: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013302C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133030: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133034: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133038: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013303C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133040: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133044: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133048: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013304C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133050: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133058: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013305C: jal         0x8000B93C
    // 0x80133060: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133060: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133064: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133068: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013306C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133070: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133074: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133078: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013307C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133080: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133084: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133088: jal         0x80007080
    // 0x8013308C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013308C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133090: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133094: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133098: jr          $ra
    // 0x8013309C: nop

    return;
    // 0x8013309C: nop

;}
RECOMP_FUNC void mnMessageMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131B2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131B30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131B34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131B38: jal         0x80009968
    // 0x80131B3C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131B3C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131B40: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131B44: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131B48: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131B4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131B50: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131B54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131B58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131B5C: jal         0x80009DF4
    // 0x80131B60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131B60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131B64: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B68: lw          $t7, 0x2988($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2988);
    // 0x80131B6C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B70: addiu       $t8, $t8, -0x8000
    ctx->r24 = ADD32(ctx->r24, -0X8000);
    // 0x80131B74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131B78: jal         0x800CCFDC
    // 0x80131B7C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131B7C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131B80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131B84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131B88: nop

    // 0x80131B8C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131B90: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80131B94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B9C: jr          $ra
    // 0x80131BA0: nop

    return;
    // 0x80131BA0: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetStatusSelected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F88: sltiu       $at, $a0, 0xC
    ctx->r1 = ctx->r4 < 0XC ? 1 : 0;
    // 0x80133F8C: beq         $at, $zero, L_80133FD8
    if (ctx->r1 == 0) {
        // 0x80133F90: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80133FD8;
    }
    // 0x80133F90: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80133F94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F98: addu        $at, $at, $t6
    gpr jr_addend_80133FA0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80133F9C: lw          $t6, 0x75EC($at)
    ctx->r14 = ADD32(ctx->r1, 0X75EC);
    // 0x80133FA0: jr          $t6
    // 0x80133FA4: nop

    switch (jr_addend_80133FA0 >> 2) {
        case 0: goto L_80133FCC; break;
        case 1: goto L_80133FA8; break;
        case 2: goto L_80133FB4; break;
        case 3: goto L_80133FA8; break;
        case 4: goto L_80133FB4; break;
        case 5: goto L_80133FB4; break;
        case 6: goto L_80133FC0; break;
        case 7: goto L_80133FB4; break;
        case 8: goto L_80133FCC; break;
        case 9: goto L_80133FD8; break;
        case 10: goto L_80133FC0; break;
        case 11: goto L_80133FC0; break;
        default: switch_error(__func__, 0x80133FA0, 0x801375EC);
    }
    // 0x80133FA4: nop

L_80133FA8:
    // 0x80133FA8: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133FAC: jr          $ra
    // 0x80133FB0: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    return;
    // 0x80133FB0: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
L_80133FB4:
    // 0x80133FB4: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133FB8: jr          $ra
    // 0x80133FBC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    return;
    // 0x80133FBC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
L_80133FC0:
    // 0x80133FC0: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133FC4: jr          $ra
    // 0x80133FC8: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    return;
    // 0x80133FC8: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_80133FCC:
    // 0x80133FCC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133FD0: jr          $ra
    // 0x80133FD4: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    return;
    // 0x80133FD4: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
L_80133FD8:
    // 0x80133FD8: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133FDC: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80133FE0: jr          $ra
    // 0x80133FE4: nop

    return;
    // 0x80133FE4: nop

;}
RECOMP_FUNC void itGShellSpinAirInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178F18: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178F1C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80178F20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80178F24: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80178F28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80178F2C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80178F30: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80178F34: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80178F38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80178F3C: bc1fl       L_80178F50
    if (!c1cs) {
        // 0x80178F40: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80178F50;
    }
    goto skip_0;
    // 0x80178F40: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x80178F44: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x80178F48: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80178F4C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80178F50:
    // 0x80178F50: nop

    // 0x80178F54: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80178F58: nop

    // 0x80178F5C: bc1fl       L_80178F70
    if (!c1cs) {
        // 0x80178F60: c.lt.s      $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
            goto L_80178F70;
    }
    goto skip_1;
    // 0x80178F60: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    skip_1:
    // 0x80178F64: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x80178F68: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80178F6C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
L_80178F70:
    // 0x80178F70: nop

    // 0x80178F74: bc1fl       L_80178F88
    if (!c1cs) {
        // 0x80178F78: sw          $t7, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r15;
            goto L_80178F88;
    }
    goto skip_2;
    // 0x80178F78: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    skip_2:
    // 0x80178F7C: b           L_80178F88
    // 0x80178F80: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
        goto L_80178F88;
    // 0x80178F80: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x80178F84: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
L_80178F88:
    // 0x80178F88: lbu         $t8, 0x2CF($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2CF);
    // 0x80178F8C: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x80178F90: jal         0x8017275C
    // 0x80178F94: sb          $t9, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r25;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_0;
    // 0x80178F94: sb          $t9, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r25;
    after_0:
    // 0x80178F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178FA0: jr          $ra
    // 0x80178FA4: nop

    return;
    // 0x80178FA4: nop

;}
RECOMP_FUNC void wpLinkBoomerangProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D4B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016D4BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D4C0: jal         0x8016D31C
    // 0x8016D4C4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpLinkBoomerangClearGObjs(rdram, ctx);
        goto after_0;
    // 0x8016D4C4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8016D4C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016D4CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016D4D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016D4D4: jr          $ra
    // 0x8016D4D8: nop

    return;
    // 0x8016D4D8: nop

;}
RECOMP_FUNC void sc1PGameSetGameStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D160: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D164: lbu         $v0, 0x4AE7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AE7);
    // 0x8018D168: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D16C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D170: sw          $t6, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = ctx->r14;
    // 0x8018D174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D178: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018D17C: beq         $v0, $at, L_8018D190
    if (ctx->r2 == ctx->r1) {
        // 0x8018D180: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8018D190;
    }
    // 0x8018D180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D184: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018D188: bnel        $v0, $at, L_8018D19C
    if (ctx->r2 != ctx->r1) {
        // 0x8018D18C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D19C;
    }
    goto skip_0;
    // 0x8018D18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8018D190:
    // 0x8018D190: jal         0x800FC3E8
    // 0x8018D194: nop

    mpCollisionSetPlayBGM(rdram, ctx);
        goto after_0;
    // 0x8018D194: nop

    after_0:
    // 0x8018D198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D19C:
    // 0x8018D19C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D1A0: jr          $ra
    // 0x8018D1A4: nop

    return;
    // 0x8018D1A4: nop

;}
RECOMP_FUNC void ftSamusSpecialAirNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DAA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015DAAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015DAB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015DAB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015DAB8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015DABC: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x8015DAC0: bnel        $t7, $zero, L_8015DADC
    if (ctx->r15 != 0) {
        // 0x8015DAC4: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8015DADC;
    }
    goto skip_0;
    // 0x8015DAC4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    skip_0:
    // 0x8015DAC8: jal         0x800DEEC8
    // 0x8015DACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015DACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015DAD0: jal         0x800D8EB8
    // 0x8015DAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_1;
    // 0x8015DAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8015DAD8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
L_8015DADC:
    // 0x8015DADC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8015DAE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015DAE4: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x8015DAE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015DAEC: jal         0x800E6F24
    // 0x8015DAF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015DAF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8015DAF4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8015DAF8: addiu       $t9, $t9, -0x2CC8
    ctx->r25 = ADD32(ctx->r25, -0X2CC8);
    // 0x8015DAFC: sw          $t9, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r25;
    // 0x8015DB00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015DB04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015DB08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015DB0C: jr          $ra
    // 0x8015DB10: nop

    return;
    // 0x8015DB10: nop

;}
RECOMP_FUNC void mnTitleFireCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133770: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133774: lw          $v0, 0x445C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X445C);
    // 0x80133778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013377C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133780: lw          $t6, 0x4448($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4448);
    // 0x80133784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133788: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013378C: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80133790: bne         $at, $zero, L_80133A84
    if (ctx->r1 != 0) {
        // 0x80133794: lw          $a2, 0x74($t6)
        ctx->r6 = MEM_W(ctx->r14, 0X74);
            goto L_80133A84;
    }
    // 0x80133794: lw          $a2, 0x74($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X74);
    // 0x80133798: slti        $at, $v0, 0x6F
    ctx->r1 = SIGNED(ctx->r2) < 0X6F ? 1 : 0;
    // 0x8013379C: beq         $at, $zero, L_80133804
    if (ctx->r1 == 0) {
        // 0x801337A0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80133804;
    }
    // 0x801337A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801337A4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801337A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801337AC: addiu       $a0, $a0, 0x447C
    ctx->r4 = ADD32(ctx->r4, 0X447C);
    // 0x801337B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801337B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801337B8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801337BC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801337C0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801337C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801337C8: addiu       $a3, $a3, 0x4480
    ctx->r7 = ADD32(ctx->r7, 0X4480);
    // 0x801337CC: addiu       $t0, $t0, 0x4484
    ctx->r8 = ADD32(ctx->r8, 0X4484);
    // 0x801337D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801337D4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x801337D8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801337DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801337E0: nop

    // 0x801337E4: bc1f        L_801337F4
    if (!c1cs) {
        // 0x801337E8: nop
    
            goto L_801337F4;
    }
    // 0x801337E8: nop

    // 0x801337EC: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x801337F0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_801337F4:
    // 0x801337F4: lwc1        $f2, 0x4480($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X4480);
    // 0x801337F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801337FC: b           L_801339B4
    // 0x80133800: lwc1        $f12, 0x4484($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4484);
        goto L_801339B4;
    // 0x80133800: lwc1        $f12, 0x4484($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4484);
L_80133804:
    // 0x80133804: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133808: addiu       $v1, $v1, 0x4478
    ctx->r3 = ADD32(ctx->r3, 0X4478);
    // 0x8013380C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133810: bne         $v0, $zero, L_80133944
    if (ctx->r2 != 0) {
        // 0x80133814: addiu       $t7, $zero, 0x104
        ctx->r15 = ADD32(0, 0X104);
            goto L_80133944;
    }
    // 0x80133814: addiu       $t7, $zero, 0x104
    ctx->r15 = ADD32(0, 0X104);
    // 0x80133818: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013381C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80133820: jal         0x80018A30
    // 0x80133824: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_0;
    // 0x80133824: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80133828: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013382C: addiu       $a1, $a1, 0x4494
    ctx->r5 = ADD32(ctx->r5, 0X4494);
    // 0x80133830: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80133834: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80133838: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013383C: bne         $v0, $t8, L_80133858
    if (ctx->r2 != ctx->r24) {
        // 0x80133840: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80133858;
    }
    // 0x80133840: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133844: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80133848: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8013384C: bne         $at, $zero, L_80133858
    if (ctx->r1 != 0) {
        // 0x80133850: nop
    
            goto L_80133858;
    }
    // 0x80133850: nop

    // 0x80133854: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80133858:
    // 0x80133858: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013385C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80133860: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80133864: lbu         $t9, 0x4318($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4318);
    // 0x80133868: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8013386C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133870: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80133874: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80133878: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013387C: addiu       $t0, $t0, 0x4484
    ctx->r8 = ADD32(ctx->r8, 0X4484);
    // 0x80133880: addiu       $a3, $a3, 0x4480
    ctx->r7 = ADD32(ctx->r7, 0X4480);
    // 0x80133884: addiu       $a0, $a0, 0x447C
    ctx->r4 = ADD32(ctx->r4, 0X447C);
    // 0x80133888: bgez        $t9, L_801338A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8013388C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801338A0;
    }
    // 0x8013388C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80133890: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133894: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133898: nop

    // 0x8013389C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801338A0:
    // 0x801338A0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801338A4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801338A8: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x801338AC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801338B0: lbu         $t1, 0x4320($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4320);
    // 0x801338B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338B8: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801338BC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801338C0: nop

    // 0x801338C4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801338C8: bgez        $t1, L_801338E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801338CC: swc1        $f8, 0x4488($at)
        MEM_W(0X4488, ctx->r1) = ctx->f8.u32l;
            goto L_801338E0;
    }
    // 0x801338CC: swc1        $f8, 0x4488($at)
    MEM_W(0X4488, ctx->r1) = ctx->f8.u32l;
    // 0x801338D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801338D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801338D8: nop

    // 0x801338DC: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_801338E0:
    // 0x801338E0: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801338E4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801338E8: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x801338EC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801338F0: lbu         $t2, 0x4328($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4328);
    // 0x801338F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338F8: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801338FC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80133900: nop

    // 0x80133904: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80133908: bgez        $t2, L_80133920
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8013390C: swc1        $f8, 0x448C($at)
        MEM_W(0X448C, ctx->r1) = ctx->f8.u32l;
            goto L_80133920;
    }
    // 0x8013390C: swc1        $f8, 0x448C($at)
    MEM_W(0X448C, ctx->r1) = ctx->f8.u32l;
    // 0x80133910: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133914: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133918: nop

    // 0x8013391C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80133920:
    // 0x80133920: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80133924: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133928: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013392C: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80133930: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133934: addiu       $v1, $v1, 0x4478
    ctx->r3 = ADD32(ctx->r3, 0X4478);
    // 0x80133938: lw          $v0, 0x4478($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4478);
    // 0x8013393C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80133940: swc1        $f8, 0x4490($at)
    MEM_W(0X4490, ctx->r1) = ctx->f8.u32l;
L_80133944:
    // 0x80133944: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133948: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8013394C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133950: addiu       $t0, $t0, 0x4484
    ctx->r8 = ADD32(ctx->r8, 0X4484);
    // 0x80133954: addiu       $a3, $a3, 0x4480
    ctx->r7 = ADD32(ctx->r7, 0X4480);
    // 0x80133958: addiu       $a0, $a0, 0x447C
    ctx->r4 = ADD32(ctx->r4, 0X447C);
    // 0x8013395C: slti        $at, $v0, 0x50
    ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x80133960: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133964: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80133968: bne         $at, $zero, L_801339AC
    if (ctx->r1 != 0) {
        // 0x8013396C: lwc1        $f12, 0x0($t0)
        ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
            goto L_801339AC;
    }
    // 0x8013396C: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80133970: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133974: lwc1        $f10, 0x4488($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4488);
    // 0x80133978: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013397C: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80133980: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80133984: lwc1        $f16, 0x448C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X448C);
    // 0x80133988: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013398C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133990: add.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80133994: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80133998: lwc1        $f6, 0x4490($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4490);
    // 0x8013399C: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801339A0: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x801339A4: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x801339A8: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
L_801339AC:
    // 0x801339AC: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x801339B0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_801339B4:
    // 0x801339B4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801339B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801339BC: nop

    // 0x801339C0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x801339C4: nop

    // 0x801339C8: bc1fl       L_801339DC
    if (!c1cs) {
        // 0x801339CC: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_801339DC;
    }
    goto skip_0;
    // 0x801339CC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_0:
    // 0x801339D0: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
    // 0x801339D4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801339D8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_801339DC:
    // 0x801339DC: nop

    // 0x801339E0: bc1fl       L_801339F4
    if (!c1cs) {
        // 0x801339E4: c.lt.s      $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
            goto L_801339F4;
    }
    goto skip_1;
    // 0x801339E4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    skip_1:
    // 0x801339E8: swc1        $f14, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f14.u32l;
    // 0x801339EC: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801339F0: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
L_801339F4:
    // 0x801339F4: nop

    // 0x801339F8: bc1fl       L_80133A0C
    if (!c1cs) {
        // 0x801339FC: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80133A0C;
    }
    goto skip_2;
    // 0x801339FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_2:
    // 0x80133A00: swc1        $f14, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f14.u32l;
    // 0x80133A04: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80133A08: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80133A0C:
    // 0x80133A0C: nop

    // 0x80133A10: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80133A14: nop

    // 0x80133A18: bc1fl       L_80133A2C
    if (!c1cs) {
        // 0x80133A1C: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_80133A2C;
    }
    goto skip_3;
    // 0x80133A1C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_3:
    // 0x80133A20: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
    // 0x80133A24: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133A28: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_80133A2C:
    // 0x80133A2C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80133A30: bc1fl       L_80133A44
    if (!c1cs) {
        // 0x80133A34: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_80133A44;
    }
    goto skip_4;
    // 0x80133A34: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_4:
    // 0x80133A38: swc1        $f14, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f14.u32l;
    // 0x80133A3C: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80133A40: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_80133A44:
    // 0x80133A44: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80133A48: bc1fl       L_80133A5C
    if (!c1cs) {
        // 0x80133A4C: trunc.w.s   $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
            goto L_80133A5C;
    }
    goto skip_5;
    // 0x80133A4C: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    skip_5:
    // 0x80133A50: swc1        $f14, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f14.u32l;
    // 0x80133A54: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80133A58: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
L_80133A5C:
    // 0x80133A5C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80133A60: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80133A64: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80133A68: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80133A6C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80133A70: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x80133A74: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80133A78: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80133A7C: ori         $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 | 0XFF;
    // 0x80133A80: sw          $t7, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r15;
L_80133A84:
    // 0x80133A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80133A8C: jr          $ra
    // 0x80133A90: nop

    return;
    // 0x80133A90: nop

;}
RECOMP_FUNC void mnPlayersVSDestroyTeamSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132824: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80132828: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013282C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80132830: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80132834: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132838: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x8013283C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80132840: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80132844: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x80132848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013284C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132850: beq         $a1, $zero, L_80132868
    if (ctx->r5 == 0) {
        // 0x80132854: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80132868;
    }
    // 0x80132854: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80132858: jal         0x80009A84
    // 0x8013285C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8013285C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80132860: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80132864: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
L_80132868:
    // 0x80132868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013286C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132870: jr          $ra
    // 0x80132874: nop

    return;
    // 0x80132874: nop

;}
RECOMP_FUNC void itMLuckyFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018104C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181050: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80181054: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80181058: jal         0x80172558
    // 0x8018105C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8018105C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_0:
    // 0x80181060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018106C: jr          $ra
    // 0x80181070: nop

    return;
    // 0x80181070: nop

;}
RECOMP_FUNC void efManagerShieldProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010102C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80101030: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80101034: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80101038: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x8010103C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80101040: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80101044: beq         $t6, $zero, L_80101054
    if (ctx->r14 == 0) {
        // 0x80101048: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80101054;
    }
    // 0x80101048: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8010104C: b           L_80101058
    // 0x80101050: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
        goto L_80101058;
    // 0x80101050: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_80101054:
    // 0x80101054: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
L_80101058:
    // 0x80101058: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8010105C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80101060: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80101064: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101068: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8010106C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101070: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101074: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80101078: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8010107C: addiu       $t4, $t4, -0x1EEC
    ctx->r12 = ADD32(ctx->r12, -0X1EEC);
    // 0x80101080: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101084: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80101088: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8010108C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80101090: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80101094: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80101098: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x8010109C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x801010A0: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x801010A4: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x801010A8: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801010AC: or          $t8, $t3, $t6
    ctx->r24 = ctx->r11 | ctx->r14;
    // 0x801010B0: ori         $t9, $t8, 0xC0
    ctx->r25 = ctx->r24 | 0XC0;
    // 0x801010B4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801010B8: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x801010BC: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x801010C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801010C4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x801010C8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801010CC: lbu         $t5, 0x5($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X5);
    // 0x801010D0: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    // 0x801010D4: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x801010D8: sll         $t3, $t5, 8
    ctx->r11 = S32(ctx->r13 << 8);
    // 0x801010DC: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x801010E0: or          $t7, $t3, $t9
    ctx->r15 = ctx->r11 | ctx->r25;
    // 0x801010E4: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x801010E8: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x801010EC: ori         $t8, $t6, 0xC0
    ctx->r24 = ctx->r14 | 0XC0;
    // 0x801010F0: jal         0x80014768
    // 0x801010F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x801010F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    after_0:
    // 0x801010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801010FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101100: jr          $ra
    // 0x80101104: nop

    return;
    // 0x80101104: nop

;}
RECOMP_FUNC void itManagerGetNextStructAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DFAC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8016DFB0: addiu       $a0, $a0, -0x2F6C
    ctx->r4 = ADD32(ctx->r4, -0X2F6C);
    // 0x8016DFB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8016DFB8: bnel        $v1, $zero, L_8016DFCC
    if (ctx->r3 != 0) {
        // 0x8016DFBC: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8016DFCC;
    }
    goto skip_0;
    // 0x8016DFBC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8016DFC0: jr          $ra
    // 0x8016DFC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016DFC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016DFC8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8016DFCC:
    // 0x8016DFCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8016DFD0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8016DFD4: jr          $ra
    // 0x8016DFD8: nop

    return;
    // 0x8016DFD8: nop

;}
RECOMP_FUNC void mnPlayers1PGameStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138558: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013855C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80138560: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80138564: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80138568: addiu       $a0, $a0, -0x7370
    ctx->r4 = ADD32(ctx->r4, -0X7370);
    // 0x8013856C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138570: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80138574: jal         0x80007024
    // 0x80138578: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80138578: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8013857C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80138580: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80138584: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80138588: addiu       $t9, $t9, -0x6930
    ctx->r25 = ADD32(ctx->r25, -0X6930);
    // 0x8013858C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80138590: addiu       $a0, $a0, -0x7354
    ctx->r4 = ADD32(ctx->r4, -0X7354);
    // 0x80138594: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80138598: jal         0x8000683C
    // 0x8013859C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8013859C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801385A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801385A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801385A8: jr          $ra
    // 0x801385AC: nop

    return;
    // 0x801385AC: nop

;}
RECOMP_FUNC void itMainCommonProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801733E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801733E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801733EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801733F0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801733F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801733F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801733FC: lwc1        $f4, 0x278($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X278);
    // 0x80173400: addiu       $a0, $v0, 0x2C
    ctx->r4 = ADD32(ctx->r2, 0X2C);
    // 0x80173404: addiu       $a1, $v0, 0x27C
    ctx->r5 = ADD32(ctx->r2, 0X27C);
    // 0x80173408: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017340C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80173410: jal         0x80019438
    // 0x80173414: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x80173414: nop

    after_0:
    // 0x80173418: jal         0x80172508
    // 0x8017341C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainSetSpinVelLR(rdram, ctx);
        goto after_1;
    // 0x8017341C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80173420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80173424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80173428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017342C: jr          $ra
    // 0x80173430: nop

    return;
    // 0x80173430: nop

;}
RECOMP_FUNC void mpCommonCheckSetFighterEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDA6C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800DDA70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DDA74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DDA78: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800DDA7C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800DDA80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800DDA84: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x800DDA88: jal         0x800FC67C
    // 0x800DDA8C: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x800DDA8C: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    after_0:
    // 0x800DDA90: bne         $v0, $zero, L_800DDAA0
    if (ctx->r2 != 0) {
        // 0x800DDA94: lw          $a0, 0x74($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X74);
            goto L_800DDAA0;
    }
    // 0x800DDA94: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800DDA98: b           L_800DDC3C
    // 0x800DDA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DDC3C;
    // 0x800DDA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DDAA0:
    // 0x800DDAA0: jal         0x800F4428
    // 0x800DDAA4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x800DDAA4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x800DDAA8: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800DDAAC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800DDAB0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800DDAB4: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800DDAB8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800DDABC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x800DDAC0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800DDAC4: addiu       $t8, $sp, 0x34
    ctx->r24 = ADD32(ctx->r29, 0X34);
    // 0x800DDAC8: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800DDACC: bc1f        L_800DDB50
    if (!c1cs) {
        // 0x800DDAD0: nop
    
            goto L_800DDB50;
    }
    // 0x800DDAD0: nop

    // 0x800DDAD4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800DDAD8: jal         0x800F3DD8
    // 0x800DDADC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_2;
    // 0x800DDADC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x800DDAE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DDAE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800DDAE8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800DDAEC: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800DDAF0: addiu       $v0, $s0, 0xB0
    ctx->r2 = ADD32(ctx->r16, 0XB0);
    // 0x800DDAF4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800DDAF8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DDAFC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DDB00: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800DDB04: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800DDB08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DDB0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800DDB10: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800DDB14: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800DDB18: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800DDB1C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800DDB20: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DDB24: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800DDB28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DDB2C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DDB30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DDB34: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800DDB38: jal         0x800F7F00
    // 0x800DDB3C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_3;
    // 0x800DDB3C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x800DDB40: bne         $v0, $zero, L_800DDBDC
    if (ctx->r2 != 0) {
        // 0x800DDB44: nop
    
            goto L_800DDBDC;
    }
    // 0x800DDB44: nop

    // 0x800DDB48: b           L_800DDBE8
    // 0x800DDB4C: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
        goto L_800DDBE8;
    // 0x800DDB4C: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
L_800DDB50:
    // 0x800DDB50: jal         0x800F4408
    // 0x800DDB54: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x800DDB54: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x800DDB58: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800DDB5C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800DDB60: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800DDB64: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800DDB68: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800DDB6C: jal         0x800F3DD8
    // 0x800DDB70: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_5;
    // 0x800DDB70: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x800DDB74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DDB78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800DDB7C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800DDB80: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800DDB84: addiu       $v0, $s0, 0xB0
    ctx->r2 = ADD32(ctx->r16, 0XB0);
    // 0x800DDB88: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800DDB8C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DDB90: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DDB94: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800DDB98: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800DDB9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DDBA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800DDBA4: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800DDBA8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800DDBAC: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800DDBB0: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800DDBB4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DDBB8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800DDBBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DDBC0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DDBC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DDBC8: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800DDBCC: jal         0x800F6B58
    // 0x800DDBD0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_6;
    // 0x800DDBD0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x800DDBD4: beql        $v0, $zero, L_800DDBE8
    if (ctx->r2 == 0) {
        // 0x800DDBD8: addiu       $t1, $sp, 0x58
        ctx->r9 = ADD32(ctx->r29, 0X58);
            goto L_800DDBE8;
    }
    goto skip_0;
    // 0x800DDBD8: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
    skip_0:
L_800DDBDC:
    // 0x800DDBDC: b           L_800DDC3C
    // 0x800DDBE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DDC3C;
    // 0x800DDBE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DDBE4: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
L_800DDBE8:
    // 0x800DDBE8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800DDBEC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800DDBF0: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x800DDBF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800DDBF8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800DDBFC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800DDC00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DDC04: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800DDC08: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800DDC0C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x800DDC10: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800DDC14: sw          $t4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->r12;
    // 0x800DDC18: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800DDC1C: sw          $t5, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r13;
    // 0x800DDC20: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800DDC24: sw          $t8, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r24;
    // 0x800DDC28: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800DDC2C: sw          $t7, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->r15;
    // 0x800DDC30: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800DDC34: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x800DDC38: sw          $t8, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r24;
L_800DDC3C:
    // 0x800DDC3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DDC40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DDC44: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800DDC48: jr          $ra
    // 0x800DDC4C: nop

    return;
    // 0x800DDC4C: nop

;}
RECOMP_FUNC void mvOpeningMarioPosedWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D844: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D848: addiu       $t3, $t3, 0x65B0
    ctx->r11 = ADD32(ctx->r11, 0X65B0);
    // 0x8018D84C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D850: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D854: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D858: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D85C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018D860: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D864: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D868: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D86C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018D870: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018D874: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D878: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D87C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D880: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018D884: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D888: lui         $t7, 0xA0AA
    ctx->r15 = S32(0XA0AA << 16);
    // 0x8018D88C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018D890: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D894: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D898: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D89C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D8A0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D8A4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8A8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8018D8AC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8018D8B0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D8B4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D8B8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018D8BC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8018D8C0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D8C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D8C8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8CC: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018D8D0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018D8D4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D8D8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D8DC: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018D8E0: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8018D8E4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D8E8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D8EC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8F0: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8018D8F4: lui         $t6, 0xF61B
    ctx->r14 = S32(0XF61B << 16);
    // 0x8018D8F8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D8FC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D900: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x8018D904: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x8018D908: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D90C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D910: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D914: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8018D918: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8018D91C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D920: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D924: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D928: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D92C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D930: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D934: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D938: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D93C: jr          $ra
    // 0x8018D940: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x8018D940: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void mvOpeningFoxMotionCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D314: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D318: lw          $t6, -0x1E08($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1E08);
    // 0x8018D31C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D320: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018D324: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8018D328: bne         $at, $zero, L_8018D404
    if (ctx->r1 != 0) {
        // 0x8018D32C: addiu       $v1, $v1, -0x1DC8
        ctx->r3 = ADD32(ctx->r3, -0X1DC8);
            goto L_8018D404;
    }
    // 0x8018D32C: addiu       $v1, $v1, -0x1DC8
    ctx->r3 = ADD32(ctx->r3, -0X1DC8);
    // 0x8018D330: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D334: addiu       $a0, $a0, -0x1DE8
    ctx->r4 = ADD32(ctx->r4, -0X1DE8);
    // 0x8018D338: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018D33C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D340: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018D344: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D348: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D34C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018D350: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D354: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D358: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018D35C: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D360: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018D364: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D368: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D36C: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D370: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D374: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018D378: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8018D37C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018D380: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018D384: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D388: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D38C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D390: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018D394: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x8018D398: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018D39C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8018D3A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3A4: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3AC: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8018D3B0: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3B4: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018D3B8: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8018D3BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3C0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3C4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3C8: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8018D3CC: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3D0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8018D3D4: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8018D3D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3DC: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3E4: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8018D3E8: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3EC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8018D3F0: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8018D3F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3F8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3FC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D400: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_8018D404:
    // 0x8018D404: jr          $ra
    // 0x8018D408: nop

    return;
    // 0x8018D408: nop

;}
RECOMP_FUNC void ftCommonDamageAirCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014093C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80140940: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80140944: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80140948: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8014094C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80140950: jal         0x800DEDAC
    // 0x80140954: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpCommonCheckFighterDamageCollision(rdram, ctx);
        goto after_0;
    // 0x80140954: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80140958: beql        $v0, $zero, L_801409AC
    if (ctx->r2 == 0) {
        // 0x8014095C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801409AC;
    }
    goto skip_0;
    // 0x8014095C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80140960: jal         0x80141C6C
    // 0x80140964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonWallDamageCheckGoto(rdram, ctx);
        goto after_1;
    // 0x80140964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80140968: bne         $v0, $zero, L_801409A8
    if (ctx->r2 != 0) {
        // 0x8014096C: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_801409A8;
    }
    // 0x8014096C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80140970: lhu         $t8, 0xB24($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XB24);
    // 0x80140974: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x80140978: beql        $t9, $zero, L_801409AC
    if (ctx->r25 == 0) {
        // 0x8014097C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801409AC;
    }
    goto skip_1;
    // 0x8014097C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80140980: jal         0x80144760
    // 0x80140984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassiveStandCheckInterruptDamage(rdram, ctx);
        goto after_2;
    // 0x80140984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80140988: bnel        $v0, $zero, L_801409AC
    if (ctx->r2 != 0) {
        // 0x8014098C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801409AC;
    }
    goto skip_2;
    // 0x8014098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80140990: jal         0x801446BC
    // 0x80140994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassiveCheckInterruptDamage(rdram, ctx);
        goto after_3;
    // 0x80140994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80140998: bnel        $v0, $zero, L_801409AC
    if (ctx->r2 != 0) {
        // 0x8014099C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801409AC;
    }
    goto skip_3;
    // 0x8014099C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801409A0: jal         0x80144498
    // 0x801409A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDownBounceSetStatus(rdram, ctx);
        goto after_4;
    // 0x801409A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_801409A8:
    // 0x801409A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801409AC:
    // 0x801409AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801409B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801409B4: jr          $ra
    // 0x801409B8: nop

    return;
    // 0x801409B8: nop

;}

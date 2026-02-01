#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSRecordMakeRankingTableHeaders(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135108: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8013510C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80135110: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80135114: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80135118: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8013511C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80135120: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80135124: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80135128: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8013512C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80135130: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80135134: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80135138: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8013513C: addiu       $t7, $t7, 0x693C
    ctx->r15 = ADD32(ctx->r15, 0X693C);
    // 0x80135140: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80135144: addiu       $t6, $sp, 0x9C
    ctx->r14 = ADD32(ctx->r29, 0X9C);
    // 0x80135148: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013514C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80135150: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80135154: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80135158: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013515C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80135160: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80135164: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80135168: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8013516C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80135170: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80135174: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80135178: addiu       $t1, $t1, 0x6958
    ctx->r9 = ADD32(ctx->r9, 0X6958);
    // 0x8013517C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80135180: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x80135184: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80135188: addiu       $t0, $sp, 0x80
    ctx->r8 = ADD32(ctx->r29, 0X80);
    // 0x8013518C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80135190: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80135194: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80135198: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8013519C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801351A0: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x801351A4: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x801351A8: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x801351AC: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x801351B0: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x801351B4: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x801351B8: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x801351BC: addiu       $v0, $sp, 0x80
    ctx->r2 = ADD32(ctx->r29, 0X80);
    // 0x801351C0: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x801351C4: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
L_801351C8:
    // 0x801351C8: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x801351CC: bnel        $at, $zero, L_801351DC
    if (ctx->r1 != 0) {
        // 0x801351D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_801351DC;
    }
    goto skip_0;
    // 0x801351D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x801351D4: addiu       $a0, $a0, -0x7
    ctx->r4 = ADD32(ctx->r4, -0X7);
    // 0x801351D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_801351DC:
    // 0x801351DC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x801351E0: sw          $a0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r4;
    // 0x801351E4: bne         $at, $zero, L_801351C8
    if (ctx->r1 != 0) {
        // 0x801351E8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801351C8;
    }
    // 0x801351E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801351EC: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x801351F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801351F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801351F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801351FC: jal         0x80009968
    // 0x80135200: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80135200: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x80135204: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80135208: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8013520C: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // 0x80135210: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80135214: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80135218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013521C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80135220: jal         0x80009DF4
    // 0x80135224: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80135224: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80135228: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8013522C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80135230: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80135234: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80135238: addiu       $s1, $zero, 0x30
    ctx->r17 = ADD32(0, 0X30);
    // 0x8013523C: addiu       $s2, $s2, 0x6D88
    ctx->r18 = ADD32(ctx->r18, 0X6D88);
    // 0x80135240: addiu       $s7, $s7, 0x6630
    ctx->r23 = ADD32(ctx->r23, 0X6630);
    // 0x80135244: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x80135248: addiu       $fp, $sp, 0x80
    ctx->r30 = ADD32(ctx->r29, 0X80);
    // 0x8013524C: addiu       $s6, $zero, 0x92
    ctx->r22 = ADD32(0, 0X92);
    // 0x80135250: addiu       $s5, $zero, 0x88
    ctx->r21 = ADD32(0, 0X88);
    // 0x80135254: addiu       $s4, $zero, 0x8A
    ctx->r20 = ADD32(0, 0X8A);
    // 0x80135258: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
L_8013525C:
    // 0x8013525C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80135260: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80135264: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x80135268: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8013526C: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x80135270: lw          $t7, 0x9C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X9C);
    // 0x80135274: jal         0x800CCFDC
    // 0x80135278: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80135278: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013527C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80135280: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80135284: and         $t1, $t9, $s3
    ctx->r9 = ctx->r25 & ctx->r19;
    // 0x80135288: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013528C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80135290: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80135294: lw          $t3, -0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, -0X4);
    // 0x80135298: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8013529C: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x801352A0: lw          $t5, 0x80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X80);
    // 0x801352A4: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x801352A8: sb          $s4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r20;
    // 0x801352AC: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x801352B0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801352B4: sb          $s5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r21;
    // 0x801352B8: sb          $s6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r22;
    // 0x801352BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801352C0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x801352C4: lw          $t7, -0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, -0X4);
    // 0x801352C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801352CC: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x801352D0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801352D4: bne         $s0, $fp, L_8013525C
    if (ctx->r16 != ctx->r30) {
        // 0x801352D8: addu        $s1, $s1, $t0
        ctx->r17 = ADD32(ctx->r17, ctx->r8);
            goto L_8013525C;
    }
    // 0x801352D8: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x801352DC: jal         0x8013388C
    // 0x801352E0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    mnVSRecordMakeRowIcons(rdram, ctx);
        goto after_3;
    // 0x801352E0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    after_3:
    // 0x801352E4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801352E8: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x801352EC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801352F0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801352F4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801352F8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801352FC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80135300: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80135304: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80135308: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8013530C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80135310: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80135314: jr          $ra
    // 0x80135318: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80135318: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void efManagerStarRodSparkMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFEA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FFEA8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800FFEAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFEB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FFEB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800FFEB8: jal         0x800FDAFC
    // 0x800FFEBC: addiu       $a0, $a0, -0x2014
    ctx->r4 = ADD32(ctx->r4, -0X2014);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FFEBC: addiu       $a0, $a0, -0x2014
    ctx->r4 = ADD32(ctx->r4, -0X2014);
    after_0:
    // 0x800FFEC0: beq         $v0, $zero, L_800FFF60
    if (ctx->r2 == 0) {
        // 0x800FFEC4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FFF60;
    }
    // 0x800FFEC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FFEC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FFECC: lw          $v0, 0x74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X74);
    // 0x800FFED0: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x800FFED4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800FFED8: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x800FFEDC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800FFEE0: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x800FFEE4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800FFEE8: sw          $t8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r24;
    // 0x800FFEEC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800FFEF0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800FFEF4: jal         0x80018948
    // 0x800FFEF8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x800FFEF8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800FFEFC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800FFF00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800FFF04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FFF08: lwc1        $f4, 0x9A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9A8);
    // 0x800FFF0C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800FFF10: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFF14: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FFF18: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FFF1C: swc1        $f12, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f12.u32l;
    // 0x800FFF20: swc1        $f12, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f12.u32l;
    // 0x800FFF24: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800FFF28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FFF2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FFF30: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x800FFF34: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800FFF38: addiu       $t0, $zero, 0x3E
    ctx->r8 = ADD32(0, 0X3E);
    // 0x800FFF3C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800FFF40: nop

    // 0x800FFF44: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FFF48: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800FFF4C: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    // 0x800FFF50: lwc1        $f18, 0x9AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9AC);
    // 0x800FFF54: sw          $t0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r8;
    // 0x800FFF58: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800FFF5C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
L_800FFF60:
    // 0x800FFF60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFF64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FFF68: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800FFF6C: jr          $ra
    // 0x800FFF70: nop

    return;
    // 0x800FFF70: nop

;}
RECOMP_FUNC void ftKirbyCopyFoxSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156DD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80156DDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156DE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80156DE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80156DE8: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80156DEC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80156DF0: jal         0x800E6F24
    // 0x80156DF4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80156DF4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80156DF8: jal         0x800E0830
    // 0x80156DFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80156DFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80156E00: jal         0x80156DC8
    // 0x80156E04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyFoxSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80156E04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80156E08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80156E0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80156E10: jr          $ra
    // 0x80156E14: nop

    return;
    // 0x80156E14: nop

;}
RECOMP_FUNC void wpDisplayDObjTreeDLLinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016763C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80167640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80167644: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80167648: jal         0x80167520
    // 0x8016764C: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    wpDisplayMain(rdram, ctx);
        goto after_0;
    // 0x8016764C: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    after_0:
    // 0x80167650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80167654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167658: jr          $ra
    // 0x8016765C: nop

    return;
    // 0x8016765C: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164860: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80164864: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80164868: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016486C: jal         0x800DEE98
    // 0x80164870: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80164870: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80164874: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80164878: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8016487C: addiu       $a1, $zero, 0x11F
    ctx->r5 = ADD32(0, 0X11F);
    // 0x80164880: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80164884: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80164888: jal         0x800E6F24
    // 0x8016488C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8016488C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80164890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80164894: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80164898: jr          $ra
    // 0x8016489C: nop

    return;
    // 0x8016489C: nop

;}
RECOMP_FUNC void ftDonkeySpecialHiSetStatusFlagGA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B8E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015B8EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015B8F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015B8F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8015B8F8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015B8FC: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x8015B900: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015B904: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x8015B908: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015B90C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015B910: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015B914: jal         0x800E6F24
    // 0x8015B918: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015B918: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015B91C: jal         0x800E0830
    // 0x8015B920: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015B920: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8015B924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015B928: jal         0x800D8E78
    // 0x8015B92C: lui         $a1, 0x4218
    ctx->r5 = S32(0X4218 << 16);
    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_2;
    // 0x8015B92C: lui         $a1, 0x4218
    ctx->r5 = S32(0X4218 << 16);
    after_2:
    // 0x8015B930: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8015B934: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8015B938: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x8015B93C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8015B940: sw          $t9, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r25;
    // 0x8015B944: sb          $t8, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r24;
    // 0x8015B948: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8015B94C: bnel        $t0, $zero, L_8015B964
    if (ctx->r8 != 0) {
        // 0x8015B950: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8015B964;
    }
    goto skip_0;
    // 0x8015B950: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8015B954: lbu         $t1, 0x28E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X28E);
    // 0x8015B958: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8015B95C: sb          $t2, 0x28E($s0)
    MEM_B(0X28E, ctx->r16) = ctx->r10;
    // 0x8015B960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015B964:
    // 0x8015B964: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015B968: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015B96C: jr          $ra
    // 0x8015B970: nop

    return;
    // 0x8015B970: nop

;}
RECOMP_FUNC void mnVSResultsStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138E64: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80138E68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80138E6C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80138E70: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80138E74: addiu       $a0, $a0, -0x68F0
    ctx->r4 = ADD32(ctx->r4, -0X68F0);
    // 0x80138E78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80138E7C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80138E80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80138E84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80138E88: jal         0x80007024
    // 0x80138E8C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80138E8C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80138E90: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80138E94: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80138E98: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80138E9C: addiu       $t9, $t9, -0x5F90
    ctx->r25 = ADD32(ctx->r25, -0X5F90);
    // 0x80138EA0: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80138EA4: addiu       $a0, $a0, -0x68D4
    ctx->r4 = ADD32(ctx->r4, -0X68D4);
    // 0x80138EA8: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80138EAC: jal         0x800A2698
    // 0x80138EB0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x80138EB0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80138EB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80138EB8: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80138EBC:
    // 0x80138EBC: jal         0x800044B4
    // 0x80138EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerInitRumble(rdram, ctx);
        goto after_2;
    // 0x80138EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80138EC4: jal         0x80004494
    // 0x80138EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerStopRumble(rdram, ctx);
        goto after_3;
    // 0x80138EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80138ECC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80138ED0: bne         $s0, $s1, L_80138EBC
    if (ctx->r16 != ctx->r17) {
        // 0x80138ED4: nop
    
            goto L_80138EBC;
    }
    // 0x80138ED4: nop

    // 0x80138ED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80138EDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80138EE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80138EE4: jr          $ra
    // 0x80138EE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80138EE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnVSResultsAnnounceWinner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EB0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80131EB4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80131EB8: addiu       $t7, $t7, -0x7058
    ctx->r15 = ADD32(ctx->r15, -0X7058);
    // 0x80131EBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131EC0: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80131EC4: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
L_80131EC8:
    // 0x80131EC8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131ECC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131ED0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131ED4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131ED8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131EDC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131EE0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131EE4: bne         $t7, $t0, L_80131EC8
    if (ctx->r15 != ctx->r8) {
        // 0x80131EE8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131EC8;
    }
    // 0x80131EE8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131EEC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80131EF0: addiu       $t2, $t2, -0x7028
    ctx->r10 = ADD32(ctx->r10, -0X7028);
    // 0x80131EF4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131EF8: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x80131EFC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80131F00: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80131F04: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80131F08: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80131F0C: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80131F10: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80131F14: lw          $t5, -0x63F0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X63F0);
    // 0x80131F18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80131F1C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80131F20: bne         $t5, $at, L_80131F68
    if (ctx->r13 != ctx->r1) {
        // 0x80131F24: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_80131F68;
    }
    // 0x80131F24: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80131F28: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80131F2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131F30: beq         $v0, $at, L_80131F48
    if (ctx->r2 == ctx->r1) {
        // 0x80131F34: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80131F48;
    }
    // 0x80131F34: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80131F38: beq         $v0, $at, L_80131F58
    if (ctx->r2 == ctx->r1) {
        // 0x80131F3C: nop
    
            goto L_80131F58;
    }
    // 0x80131F3C: nop

    // 0x80131F40: b           L_80132050
    // 0x80131F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80131F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131F48:
    // 0x80131F48: jal         0x800269C0
    // 0x80131F4C: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80131F4C: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    after_0:
    // 0x80131F50: b           L_80132050
    // 0x80131F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80131F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131F58:
    // 0x80131F58: jal         0x800269C0
    // 0x80131F5C: addiu       $a0, $zero, 0x270
    ctx->r4 = ADD32(0, 0X270);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80131F5C: addiu       $a0, $zero, 0x270
    ctx->r4 = ADD32(0, 0X270);
    after_1:
    // 0x80131F60: b           L_80132050
    // 0x80131F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80131F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131F68:
    // 0x80131F68: lbu         $t0, -0x63EC($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X63EC);
    // 0x80131F6C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80131F70: bne         $t0, $zero, L_80131FEC
    if (ctx->r8 != 0) {
        // 0x80131F74: nop
    
            goto L_80131FEC;
    }
    // 0x80131F74: nop

    // 0x80131F78: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80131F7C: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80131F80: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80131F84: beq         $v0, $at, L_80131FA4
    if (ctx->r2 == ctx->r1) {
        // 0x80131F88: addiu       $at, $zero, 0xD2
        ctx->r1 = ADD32(0, 0XD2);
            goto L_80131FA4;
    }
    // 0x80131F88: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x80131F8C: beq         $v0, $at, L_80131FB4
    if (ctx->r2 == ctx->r1) {
        // 0x80131F90: addiu       $at, $zero, 0x10E
        ctx->r1 = ADD32(0, 0X10E);
            goto L_80131FB4;
    }
    // 0x80131F90: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
    // 0x80131F94: beq         $v0, $at, L_80131FDC
    if (ctx->r2 == ctx->r1) {
        // 0x80131F98: nop
    
            goto L_80131FDC;
    }
    // 0x80131F98: nop

    // 0x80131F9C: b           L_80132050
    // 0x80131FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80131FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131FA4:
    // 0x80131FA4: jal         0x800269C0
    // 0x80131FA8: addiu       $a0, $zero, 0x216
    ctx->r4 = ADD32(0, 0X216);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80131FA8: addiu       $a0, $zero, 0x216
    ctx->r4 = ADD32(0, 0X216);
    after_2:
    // 0x80131FAC: b           L_80132050
    // 0x80131FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80131FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131FB4:
    // 0x80131FB4: jal         0x8013234C
    // 0x80131FB8: nop

    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_3;
    // 0x80131FB8: nop

    after_3:
    // 0x80131FBC: jal         0x80133148
    // 0x80131FC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_4;
    // 0x80131FC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80131FC4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80131FC8: addu        $a0, $sp, $t7
    ctx->r4 = ADD32(ctx->r29, ctx->r15);
    // 0x80131FCC: jal         0x800269C0
    // 0x80131FD0: lhu         $a0, 0x32($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X32);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80131FD0: lhu         $a0, 0x32($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X32);
    after_5:
    // 0x80131FD4: b           L_80132050
    // 0x80131FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80131FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131FDC:
    // 0x80131FDC: jal         0x800269C0
    // 0x80131FE0: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x80131FE0: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_6:
    // 0x80131FE4: b           L_80132050
    // 0x80131FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80131FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131FEC:
    // 0x80131FEC: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80131FF0: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80131FF4: beq         $v0, $at, L_80132014
    if (ctx->r2 == ctx->r1) {
        // 0x80131FF8: addiu       $at, $zero, 0x82
        ctx->r1 = ADD32(0, 0X82);
            goto L_80132014;
    }
    // 0x80131FF8: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x80131FFC: beq         $v0, $at, L_80132034
    if (ctx->r2 == ctx->r1) {
        // 0x80132000: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_80132034;
    }
    // 0x80132000: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80132004: beq         $v0, $at, L_80132044
    if (ctx->r2 == ctx->r1) {
        // 0x80132008: nop
    
            goto L_80132044;
    }
    // 0x80132008: nop

    // 0x8013200C: b           L_80132050
    // 0x80132010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80132010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132014:
    // 0x80132014: jal         0x80132A2C
    // 0x80132018: nop

    mnVSResultsGetWinTeam(rdram, ctx);
        goto after_7;
    // 0x80132018: nop

    after_7:
    // 0x8013201C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80132020: addu        $a0, $sp, $t6
    ctx->r4 = ADD32(ctx->r29, ctx->r14);
    // 0x80132024: jal         0x800269C0
    // 0x80132028: lhu         $a0, 0x26($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X26);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x80132028: lhu         $a0, 0x26($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X26);
    after_8:
    // 0x8013202C: b           L_80132050
    // 0x80132030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80132030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132034:
    // 0x80132034: jal         0x800269C0
    // 0x80132038: addiu       $a0, $zero, 0x215
    ctx->r4 = ADD32(0, 0X215);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80132038: addiu       $a0, $zero, 0x215
    ctx->r4 = ADD32(0, 0X215);
    after_9:
    // 0x8013203C: b           L_80132050
    // 0x80132040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132050;
    // 0x80132040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132044:
    // 0x80132044: jal         0x800269C0
    // 0x80132048: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    func_800269C0_275C0(rdram, ctx);
        goto after_10;
    // 0x80132048: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_10:
    // 0x8013204C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132050:
    // 0x80132050: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80132054: jr          $ra
    // 0x80132058: nop

    return;
    // 0x80132058: nop

;}
RECOMP_FUNC void mpCollisionAllocYakumono(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB584: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FB588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB58C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800FB590: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800FB594: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800FB598: beq         $v0, $t6, L_800FB5B4
    if (ctx->r2 == ctx->r14) {
        // 0x800FB59C: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_800FB5B4;
    }
    // 0x800FB59C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FB5A0: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
L_800FB5A4:
    // 0x800FB5A4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800FB5A8: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x800FB5AC: bnel        $v0, $t7, L_800FB5A4
    if (ctx->r2 != ctx->r15) {
        // 0x800FB5B0: lw          $t7, 0x2C($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X2C);
            goto L_800FB5A4;
    }
    goto skip_0;
    // 0x800FB5B0: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    skip_0:
L_800FB5B4:
    // 0x800FB5B4: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x800FB5B8: jal         0x80004980
    // 0x800FB5BC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800FB5BC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FB5C0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB5C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FB5C8: sw          $v0, 0x1304($at)
    MEM_W(0X1304, ctx->r1) = ctx->r2;
    // 0x800FB5CC: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x800FB5D0: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // 0x800FB5D4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800FB5D8: jal         0x80004980
    // 0x800FB5DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x800FB5DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800FB5E0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB5E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FB5E8: addiu       $a0, $a0, 0x137C
    ctx->r4 = ADD32(ctx->r4, 0X137C);
    // 0x800FB5EC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800FB5F0: blez        $a2, L_800FB7F4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800FB5F4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800FB7F4;
    }
    // 0x800FB5F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FB5F8: andi        $v1, $a2, 0x3
    ctx->r3 = ctx->r6 & 0X3;
    // 0x800FB5FC: beq         $v1, $zero, L_800FB680
    if (ctx->r3 == 0) {
        // 0x800FB600: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_800FB680;
    }
    // 0x800FB600: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800FB604: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
    // 0x800FB608: subu        $v0, $v0, $zero
    ctx->r2 = SUB32(ctx->r2, 0);
    // 0x800FB60C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FB610: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FB614: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800FB618: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800FB61C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800FB620: swc1        $f2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f2.u32l;
    // 0x800FB624: beq         $a3, $a1, L_800FB660
    if (ctx->r7 == ctx->r5) {
        // 0x800FB628: lw          $t0, 0x0($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X0);
            goto L_800FB660;
    }
    // 0x800FB628: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
L_800FB62C:
    // 0x800FB62C: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x800FB630: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FB634: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800FB638: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800FB63C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800FB640: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800FB644: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
    // 0x800FB648: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800FB64C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800FB650: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800FB654: swc1        $f2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f2.u32l;
    // 0x800FB658: bne         $a3, $a1, L_800FB62C
    if (ctx->r7 != ctx->r5) {
        // 0x800FB65C: lw          $t0, 0x0($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X0);
            goto L_800FB62C;
    }
    // 0x800FB65C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
L_800FB660:
    // 0x800FB660: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x800FB664: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FB668: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800FB66C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800FB670: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800FB674: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800FB678: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
    // 0x800FB67C: beq         $a1, $a2, L_800FB7F4
    if (ctx->r5 == ctx->r6) {
        // 0x800FB680: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_800FB7F4;
    }
L_800FB680:
    // 0x800FB680: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800FB684: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
    // 0x800FB688: subu        $a3, $a3, $a2
    ctx->r7 = SUB32(ctx->r7, ctx->r6);
    // 0x800FB68C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800FB690: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800FB694: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800FB698: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x800FB69C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800FB6A0: addiu       $a3, $a3, -0x30
    ctx->r7 = ADD32(ctx->r7, -0X30);
    // 0x800FB6A4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800FB6A8: swc1        $f2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f2.u32l;
    // 0x800FB6AC: beq         $v0, $a3, L_800FB75C
    if (ctx->r2 == ctx->r7) {
        // 0x800FB6B0: lw          $t5, 0x0($a0)
        ctx->r13 = MEM_W(ctx->r4, 0X0);
            goto L_800FB75C;
    }
    // 0x800FB6B0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
L_800FB6B4:
    // 0x800FB6B4: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x800FB6B8: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FB6BC: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800FB6C0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800FB6C4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800FB6C8: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x800FB6CC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800FB6D0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800FB6D4: swc1        $f2, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f2.u32l;
    // 0x800FB6D8: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800FB6DC: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x800FB6E0: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800FB6E4: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
    // 0x800FB6E8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800FB6EC: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800FB6F0: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x800FB6F4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800FB6F8: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800FB6FC: swc1        $f2, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f2.u32l;
    // 0x800FB700: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800FB704: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x800FB708: lwc1        $f18, 0x20($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800FB70C: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x800FB710: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800FB714: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800FB718: swc1        $f18, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f18.u32l;
    // 0x800FB71C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800FB720: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800FB724: swc1        $f2, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f2.u32l;
    // 0x800FB728: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800FB72C: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x800FB730: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800FB734: swc1        $f18, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f18.u32l;
    // 0x800FB738: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800FB73C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800FB740: swc1        $f18, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f18.u32l;
    // 0x800FB744: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800FB748: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800FB74C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800FB750: swc1        $f2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f2.u32l;
    // 0x800FB754: bne         $v0, $a3, L_800FB6B4
    if (ctx->r2 != ctx->r7) {
        // 0x800FB758: lw          $t5, 0x0($a0)
        ctx->r13 = MEM_W(ctx->r4, 0X0);
            goto L_800FB6B4;
    }
    // 0x800FB758: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
L_800FB75C:
    // 0x800FB75C: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x800FB760: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FB764: addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // 0x800FB768: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800FB76C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800FB770: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800FB774: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x800FB778: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800FB77C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800FB780: swc1        $f2, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f2.u32l;
    // 0x800FB784: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800FB788: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x800FB78C: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800FB790: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
    // 0x800FB794: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800FB798: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800FB79C: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    // 0x800FB7A0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800FB7A4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800FB7A8: swc1        $f2, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f2.u32l;
    // 0x800FB7AC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800FB7B0: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x800FB7B4: lwc1        $f18, 0x20($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800FB7B8: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x800FB7BC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800FB7C0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800FB7C4: swc1        $f18, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f18.u32l;
    // 0x800FB7C8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800FB7CC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800FB7D0: swc1        $f2, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f2.u32l;
    // 0x800FB7D4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800FB7D8: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x800FB7DC: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800FB7E0: swc1        $f18, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f18.u32l;
    // 0x800FB7E4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800FB7E8: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800FB7EC: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800FB7F0: swc1        $f18, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f18.u32l;
L_800FB7F4:
    // 0x800FB7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB7F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FB7FC: sw          $a2, 0x138C($at)
    MEM_W(0X138C, ctx->r1) = ctx->r6;
    // 0x800FB800: jr          $ra
    // 0x800FB804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FB804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itLinkBombWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80185F7C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80185F80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80185F84: lbu         $t8, 0x2CE($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80185F88: sw          $zero, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = 0;
    // 0x80185F8C: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80185F90: ori         $t0, $t8, 0x80
    ctx->r8 = ctx->r24 | 0X80;
    // 0x80185F94: andi        $t1, $t0, 0xCF
    ctx->r9 = ctx->r8 & 0XCF;
    // 0x80185F98: sb          $t0, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r8;
    // 0x80185F9C: sb          $t1, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r9;
    // 0x80185FA0: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80185FA4: jal         0x80173F54
    // 0x80185FA8: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    itMapSetGround(rdram, ctx);
        goto after_0;
    // 0x80185FA8: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x80185FAC: jal         0x80185CD4
    // 0x80185FB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itLinkBombCommonSetHitStatusNormal(rdram, ctx);
        goto after_1;
    // 0x80185FB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80185FB4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80185FB8: addiu       $a1, $a1, -0x490C
    ctx->r5 = ADD32(ctx->r5, -0X490C);
    // 0x80185FBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80185FC0: jal         0x80172EC8
    // 0x80185FC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80185FC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80185FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185FCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80185FD0: jr          $ra
    // 0x80185FD4: nop

    return;
    // 0x80185FD4: nop

;}
RECOMP_FUNC void unref_80017E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017E5C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80017E60: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x80017E64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80017E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017E6C: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80017E70: jal         0x800053CC
    // 0x80017E74: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800053CC(rdram, ctx);
        goto after_0;
    // 0x80017E74: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80017E78: jal         0x80004F78
    // 0x80017E7C: nop

    func_80004F78(rdram, ctx);
        goto after_1;
    // 0x80017E7C: nop

    after_1:
    // 0x80017E80: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80017E84: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80017E88: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80017E8C: jal         0x8001663C
    // 0x80017E90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001663C(rdram, ctx);
        goto after_2;
    // 0x80017E90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80017E94: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80017E98: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80017E9C: jal         0x80016EDC
    // 0x80017EA0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    gcPrepCameraMatrix(rdram, ctx);
        goto after_3;
    // 0x80017EA0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80017EA4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80017EA8: jal         0x8001783C
    // 0x80017EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcRunFuncCamera(rdram, ctx);
        goto after_4;
    // 0x80017EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80017EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017EB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017EB8: jr          $ra
    // 0x80017EBC: nop

    return;
    // 0x80017EBC: nop

;}
RECOMP_FUNC void gcMakeSpriteGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B8BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000B8C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000B8C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000B8C8: jal         0x80009968
    // 0x8000B8CC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8000B8CC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x8000B8D0: bne         $v0, $zero, L_8000B8E0
    if (ctx->r2 != 0) {
        // 0x8000B8D4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000B8E0;
    }
    // 0x8000B8D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B8D8: b           L_8000B928
    // 0x8000B8DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B928;
    // 0x8000B8DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B8E0:
    // 0x8000B8E0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000B8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B8E8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8000B8EC: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B8F0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8000B8F4: jal         0x80009DF4
    // 0x8000B8F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8000B8F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8000B8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B900: jal         0x80009614
    // 0x8000B904: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    gcAddSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8000B904: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8000B908: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8000B90C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B910: lbu         $a2, 0x4F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X4F);
    // 0x8000B914: beql        $a1, $zero, L_8000B928
    if (ctx->r5 == 0) {
        // 0x8000B918: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8000B928;
    }
    goto skip_0;
    // 0x8000B918: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
    // 0x8000B91C: jal         0x80008188
    // 0x8000B920: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8000B920: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x8000B924: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8000B928:
    // 0x8000B928: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B92C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000B930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000B934: jr          $ra
    // 0x8000B938: nop

    return;
    // 0x8000B938: nop

;}
RECOMP_FUNC void func_ovl47_80132330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132330: jr          $ra
    // 0x80132334: nop

    return;
    // 0x80132334: nop

;}
RECOMP_FUNC void ftSamusSpecialAirNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DBDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015DBE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015DBE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015DBE8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015DBEC: jal         0x8015DB14
    // 0x8015DBF0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    ftSamusSpecialNStartGetAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x8015DBF0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015DBF4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8015DBF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015DBFC: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x8015DC00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015DC04: jal         0x800E6F24
    // 0x8015DC08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015DC08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015DC0C: jal         0x800E0830
    // 0x8015DC10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015DC10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015DC14: jal         0x8015DB4C
    // 0x8015DC18: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftSamusSpecialNStartInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8015DC18: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8015DC1C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8015DC20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8015DC24: sw          $t7, 0xB18($t8)
    MEM_W(0XB18, ctx->r24) = ctx->r15;
    // 0x8015DC28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015DC2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015DC30: jr          $ra
    // 0x8015DC34: nop

    return;
    // 0x8015DC34: nop

;}
RECOMP_FUNC void ftParamPauseEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9C78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800E9C7C: lbu         $t7, 0x10($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X10);
    // 0x800E9C80: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x800E9C84: jr          $ra
    // 0x800E9C88: sb          $t8, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r24;
    return;
    // 0x800E9C88: sb          $t8, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void wpYoshiEggThrowInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C07C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C084: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016C088: lb          $a1, 0x29E($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X29E);
    // 0x8016C08C: bgez        $a1, L_8016C09C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8016C090: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8016C09C;
    }
    // 0x8016C090: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8016C094: b           L_8016C09C
    // 0x8016C098: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
        goto L_8016C09C;
    // 0x8016C098: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
L_8016C09C:
    // 0x8016C09C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8016C0A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016C0A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8016C0A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016C0AC: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8016C0B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016C0B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C0B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016C0BC: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016C0C0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8016C0C4: nop

    // 0x8016C0C8: bc1f        L_8016C0D4
    if (!c1cs) {
        // 0x8016C0CC: nop
    
            goto L_8016C0D4;
    }
    // 0x8016C0CC: nop

    // 0x8016C0D0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8016C0D4:
    // 0x8016C0D4: lwc1        $f10, -0x34E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X34E0);
    // 0x8016C0D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C0DC: lwc1        $f16, -0x34DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X34DC);
    // 0x8016C0E0: mul.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8016C0E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C0E8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8016C0EC: nop

    // 0x8016C0F0: bc1f        L_8016C100
    if (!c1cs) {
        // 0x8016C0F4: nop
    
            goto L_8016C100;
    }
    // 0x8016C0F4: nop

    // 0x8016C0F8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8016C0FC: nop

L_8016C100:
    // 0x8016C100: bgez        $a1, L_8016C110
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8016C104: nop
    
            goto L_8016C110;
    }
    // 0x8016C104: nop

    // 0x8016C108: b           L_8016C110
    // 0x8016C10C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8016C110;
    // 0x8016C10C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8016C110:
    // 0x8016C110: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8016C114: lb          $t6, 0x29F($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X29F);
    // 0x8016C118: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8016C11C: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8016C120: blez        $t6, L_8016C138
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8016C124: nop
    
            goto L_8016C138;
    }
    // 0x8016C124: nop

    // 0x8016C128: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C12C: lwc1        $f6, -0x34D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X34D8);
    // 0x8016C130: b           L_8016C140
    // 0x8016C134: sub.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f12.fl;
        goto L_8016C140;
    // 0x8016C134: sub.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f12.fl;
L_8016C138:
    // 0x8016C138: lwc1        $f8, -0x34D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X34D4);
    // 0x8016C13C: sub.s       $f12, $f8, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f12.fl;
L_8016C140:
    // 0x8016C140: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8016C144: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016C148: jal         0x800303F0
    // 0x8016C14C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8016C14C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8016C150: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C154: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C158: lwc1        $f18, -0x34D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X34D0);
    // 0x8016C15C: lh          $t7, 0x2A0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2A0);
    // 0x8016C160: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8016C164: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016C168: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8016C16C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8016C170: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8016C174: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8016C178: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016C17C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8016C180: jal         0x80035CD0
    // 0x8016C184: swc1        $f10, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f10.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8016C184: swc1        $f10, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f10.u32l;
    after_1:
    // 0x8016C188: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C18C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C190: lwc1        $f18, -0x34CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X34CC);
    // 0x8016C194: lh          $t8, 0x2A0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2A0);
    // 0x8016C198: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8016C19C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016C1A0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8016C1A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8016C1A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C1AC: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8016C1B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8016C1B4: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8016C1B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016C1BC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8016C1C0: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x8016C1C4: lwc1        $f16, -0x34C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X34C8);
    // 0x8016C1C8: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8016C1CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016C1D0: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8016C1D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C1D8: lwc1        $f8, -0x34C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X34C4);
    // 0x8016C1DC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8016C1E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016C1E4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8016C1E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8016C1EC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016C1F0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8016C1F4: swc1        $f18, 0x2A4($v1)
    MEM_W(0X2A4, ctx->r3) = ctx->f18.u32l;
    // 0x8016C1F8: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8016C1FC: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x8016C200: jal         0x80165F60
    // 0x8016C204: sw          $t0, 0x100($v1)
    MEM_W(0X100, ctx->r3) = ctx->r8;
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_2;
    // 0x8016C204: sw          $t0, 0x100($v1)
    MEM_W(0X100, ctx->r3) = ctx->r8;
    after_2:
    // 0x8016C208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C20C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016C210: jr          $ra
    // 0x8016C214: nop

    return;
    // 0x8016C214: nop

;}
RECOMP_FUNC void sc1PTrainingModeGetItemCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D4D0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8018D4D4: lw          $v0, 0x6700($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6700);
    // 0x8018D4D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018D4DC: beq         $v0, $zero, L_8018D510
    if (ctx->r2 == 0) {
        // 0x8018D4E0: nop
    
            goto L_8018D510;
    }
    // 0x8018D4E0: nop

    // 0x8018D4E4: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
L_8018D4E8:
    // 0x8018D4E8: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x8018D4EC: slti        $at, $a0, 0x14
    ctx->r1 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x8018D4F0: bne         $at, $zero, L_8018D500
    if (ctx->r1 != 0) {
        // 0x8018D4F4: slti        $at, $a0, 0x20
        ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
            goto L_8018D500;
    }
    // 0x8018D4F4: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x8018D4F8: bnel        $at, $zero, L_8018D508
    if (ctx->r1 != 0) {
        // 0x8018D4FC: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_8018D508;
    }
    goto skip_0;
    // 0x8018D4FC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_0:
L_8018D500:
    // 0x8018D500: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8018D504: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_8018D508:
    // 0x8018D508: bnel        $v0, $zero, L_8018D4E8
    if (ctx->r2 != 0) {
        // 0x8018D50C: lw          $t6, 0x84($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X84);
            goto L_8018D4E8;
    }
    goto skip_1;
    // 0x8018D50C: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    skip_1:
L_8018D510:
    // 0x8018D510: jr          $ra
    // 0x8018D514: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8018D514: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftKirbyCopyPurinSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801519F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801519F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801519F8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801519FC: jal         0x800DDDDC
    // 0x80151A00: addiu       $a1, $a1, 0x1A78
    ctx->r5 = ADD32(ctx->r5, 0X1A78);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80151A00: addiu       $a1, $a1, 0x1A78
    ctx->r5 = ADD32(ctx->r5, 0X1A78);
    after_0:
    // 0x80151A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151A08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151A0C: jr          $ra
    // 0x80151A10: nop

    return;
    // 0x80151A10: nop

;}
RECOMP_FUNC void gmCollisionCheckItemAttackDamageCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F06E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F06EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F06F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800F06F4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800F06F8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800F06FC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800F0700: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x800F0704: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800F0708: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800F070C: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800F0710: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x800F0714: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800F0718: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F071C: addiu       $t5, $t8, 0x14
    ctx->r13 = ADD32(ctx->r24, 0X14);
    // 0x800F0720: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x800F0724: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800F0728: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800F072C: lw          $t9, 0x74($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X74);
    // 0x800F0730: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800F0734: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800F0738: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x800F073C: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800F0740: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x800F0744: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F0748: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x800F074C: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    // 0x800F0750: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x800F0754: lw          $t0, 0x74($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X74);
    // 0x800F0758: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800F075C: lwc1        $f4, 0x24($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X24);
    // 0x800F0760: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0764: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800F0768: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x800F076C: lw          $a2, 0x2C($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X2C);
    // 0x800F0770: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800F0774: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800F0778: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800F077C: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x800F0780: addiu       $t9, $t7, 0x40
    ctx->r25 = ADD32(ctx->r15, 0X40);
    // 0x800F0784: jal         0x800EE300
    // 0x800F0788: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    gmCollisionTestRectangle(rdram, ctx);
        goto after_0;
    // 0x800F0788: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x800F078C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F0790: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F0794: jr          $ra
    // 0x800F0798: nop

    return;
    // 0x800F0798: nop

;}
RECOMP_FUNC void ftCommonDeadUpStarSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C740: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013C744: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013C748: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8013C74C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013C750: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013C754: jal         0x8013C050
    // 0x8013C758: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftCommonDeadResetCommonVars(rdram, ctx);
        goto after_0;
    // 0x8013C758: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8013C75C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013C760: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8013C764: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013C768: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013C76C: jal         0x800E6F24
    // 0x8013C770: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013C770: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8013C774: jal         0x800D9444
    // 0x8013C778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_2;
    // 0x8013C778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8013C77C: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8013C780: lbu         $t9, 0x191($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X191);
    // 0x8013C784: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013C788: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8013C78C: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x8013C790: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x8013C794: sw          $t8, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r24;
    // 0x8013C798: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8013C79C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013C7A0: sw          $t7, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r15;
    // 0x8013C7A4: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8013C7A8: sb          $t1, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r9;
    // 0x8013C7AC: sw          $t2, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r10;
    // 0x8013C7B0: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8013C7B4: jal         0x8013C0B0
    // 0x8013C7B8: sw          $t8, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r24;
    ftCommonDeadResetSpecialStats(rdram, ctx);
        goto after_3;
    // 0x8013C7B8: sw          $t8, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r24;
    after_3:
    // 0x8013C7BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013C7C0: jal         0x800E7F7C
    // 0x8013C7C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_4;
    // 0x8013C7C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8013C7C8: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013C7CC: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x8013C7D0: lhu         $a0, 0xB8($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0XB8);
    // 0x8013C7D4: beql        $a0, $at, L_8013C7E8
    if (ctx->r4 == ctx->r1) {
        // 0x8013C7D8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013C7E8;
    }
    goto skip_0;
    // 0x8013C7D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8013C7DC: jal         0x800269C0
    // 0x8013C7E0: nop

    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x8013C7E0: nop

    after_5:
    // 0x8013C7E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8013C7E8:
    // 0x8013C7E8: jal         0x800E827C
    // 0x8013C7EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamMoveDLLink(rdram, ctx);
        goto after_6;
    // 0x8013C7EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8013C7F0: jal         0x800E98B0
    // 0x8013C7F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamResetFighterColAnim(rdram, ctx);
        goto after_7;
    // 0x8013C7F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8013C7F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013C7FC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C800: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8013C804: jr          $ra
    // 0x8013C808: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8013C808: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void lbCommonSetExternSpriteParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCED8: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x800CCEDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCEE0: sh          $t6, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r14;
    // 0x800CCEE4: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x800CCEE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCEEC: sh          $t7, 0x62B2($at)
    MEM_H(0X62B2, ctx->r1) = ctx->r15;
    // 0x800CCEF0: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x800CCEF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCEF8: jr          $ra
    // 0x800CCEFC: sw          $t8, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = ctx->r24;
    return;
    // 0x800CCEFC: sw          $t8, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void mnPlayers1PTrainingGetStatusSelected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013361C: sltiu       $at, $a0, 0xC
    ctx->r1 = ctx->r4 < 0XC ? 1 : 0;
    // 0x80133620: beq         $at, $zero, L_8013366C
    if (ctx->r1 == 0) {
        // 0x80133624: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8013366C;
    }
    // 0x80133624: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80133628: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013362C: addu        $at, $at, $t6
    gpr jr_addend_80133634 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80133630: lw          $t6, -0x7B20($at)
    ctx->r14 = ADD32(ctx->r1, -0X7B20);
    // 0x80133634: jr          $t6
    // 0x80133638: nop

    switch (jr_addend_80133634 >> 2) {
        case 0: goto L_80133660; break;
        case 1: goto L_8013363C; break;
        case 2: goto L_80133648; break;
        case 3: goto L_8013363C; break;
        case 4: goto L_80133648; break;
        case 5: goto L_80133648; break;
        case 6: goto L_80133654; break;
        case 7: goto L_80133648; break;
        case 8: goto L_80133660; break;
        case 9: goto L_8013366C; break;
        case 10: goto L_80133654; break;
        case 11: goto L_80133654; break;
        default: switch_error(__func__, 0x80133634, 0x801384E0);
    }
    // 0x80133638: nop

L_8013363C:
    // 0x8013363C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133640: jr          $ra
    // 0x80133644: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    return;
    // 0x80133644: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
L_80133648:
    // 0x80133648: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8013364C: jr          $ra
    // 0x80133650: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    return;
    // 0x80133650: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
L_80133654:
    // 0x80133654: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133658: jr          $ra
    // 0x8013365C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    return;
    // 0x8013365C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_80133660:
    // 0x80133660: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133664: jr          $ra
    // 0x80133668: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    return;
    // 0x80133668: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
L_8013366C:
    // 0x8013366C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80133670: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80133674: jr          $ra
    // 0x80133678: nop

    return;
    // 0x80133678: nop

;}
RECOMP_FUNC void itNyarsWeaponCoinProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017F278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F27C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017F280: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017F284: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8017F288: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8017F28C: jal         0x801680EC
    // 0x8017F290: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8017F290: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017F294: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F298: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8017F29C: jal         0x8001863C
    // 0x8017F2A0: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8017F2A0: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x8017F2A4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8017F2A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F2AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017F2B0: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x8017F2B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017F2B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F2BC: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x8017F2C0: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x8017F2C4: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x8017F2C8: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x8017F2CC: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8017F2D0: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x8017F2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F2D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F2DC: jr          $ra
    // 0x8017F2E0: nop

    return;
    // 0x8017F2E0: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNReleaseSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F530: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F538: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F53C: jal         0x800DEE98
    // 0x8015F540: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015F540: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015F544: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015F548: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8015F54C: addiu       $a1, $zero, 0x12B
    ctx->r5 = ADD32(0, 0X12B);
    // 0x8015F550: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F554: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015F558: jal         0x800E6F24
    // 0x8015F55C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015F55C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015F560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F564: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F568: jr          $ra
    // 0x8015F56C: nop

    return;
    // 0x8015F56C: nop

;}
RECOMP_FUNC void ftMainProcSearchHitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6178: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E617C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E6180: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E6184: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E6188: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E618C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E6190: lw          $t6, 0x190($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X190);
    // 0x800E6194: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x800E6198: bltzl       $t8, L_800E61DC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800E619C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E61DC;
    }
    goto skip_0;
    // 0x800E619C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800E61A0: jal         0x800E4870
    // 0x800E61A4: sw          $zero, 0x11C0($at)
    MEM_W(0X11C0, ctx->r1) = 0;
    ftMainSearchHitFighter(rdram, ctx);
        goto after_0;
    // 0x800E61A4: sw          $zero, 0x11C0($at)
    MEM_W(0X11C0, ctx->r1) = 0;
    after_0:
    // 0x800E61A8: jal         0x800E55DC
    // 0x800E61AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainSearchHitItem(rdram, ctx);
        goto after_1;
    // 0x800E61AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800E61B0: jal         0x800E4ED4
    // 0x800E61B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainSearchHitWeapon(rdram, ctx);
        goto after_2;
    // 0x800E61B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800E61B8: jal         0x800E5D20
    // 0x800E61BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainSearchGroundHit(rdram, ctx);
        goto after_3;
    // 0x800E61BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800E61C0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800E61C4: lw          $t9, 0x11C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11C0);
    // 0x800E61C8: beql        $t9, $zero, L_800E61DC
    if (ctx->r25 == 0) {
        // 0x800E61CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E61DC;
    }
    goto skip_1;
    // 0x800E61CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800E61D0: jal         0x800E3EBC
    // 0x800E61D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainProcessHitCollisionStatsMain(rdram, ctx);
        goto after_4;
    // 0x800E61D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800E61D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E61DC:
    // 0x800E61DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E61E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E61E4: jr          $ra
    // 0x800E61E8: nop

    return;
    // 0x800E61E8: nop

;}
RECOMP_FUNC void gmCameraSetStatusMapZoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D0A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010D0A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D0AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010D0B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010D0B4: jal         0x8010CEF4
    // 0x8010D0B8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    gmCameraSetStatus(rdram, ctx);
        goto after_0;
    // 0x8010D0B8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8010D0BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8010D0C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010D0C4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8010D0C8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8010D0CC: addiu       $t6, $t6, 0x150C
    ctx->r14 = ADD32(ctx->r14, 0X150C);
    // 0x8010D0D0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8010D0D4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8010D0D8: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8010D0DC: addiu       $t9, $t9, 0x1518
    ctx->r25 = ADD32(ctx->r25, 0X1518);
    // 0x8010D0E0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8010D0E4: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8010D0E8: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8010D0EC: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x8010D0F0: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8010D0F4: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8010D0F8: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x8010D0FC: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x8010D100: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x8010D104: jal         0x8001902C
    // 0x8010D108: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    syVectorDiff3D(rdram, ctx);
        goto after_1;
    // 0x8010D108: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    after_1:
    // 0x8010D10C: jal         0x80018F7C
    // 0x8010D110: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    syVectorMag3D(rdram, ctx);
        goto after_2;
    // 0x8010D110: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8010D114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D118: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D11C: swc1        $f0, 0x14C0($at)
    MEM_W(0X14C0, ctx->r1) = ctx->f0.u32l;
    // 0x8010D120: jr          $ra
    // 0x8010D124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8010D124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnSoundTestFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801338F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801338FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133900: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133904: addiu       $a1, $a1, 0x2244
    ctx->r5 = ADD32(ctx->r5, 0X2244);
    // 0x80133908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013390C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133910: jal         0x80009968
    // 0x80133914: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133914: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133918: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8013391C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133920: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80133924: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80133928: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8013392C: jal         0x8000B9FC
    // 0x80133930: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_1;
    // 0x80133930: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x80133934: jal         0x801322B8
    // 0x80133938: nop

    mnSoundTestSetupFiles(rdram, ctx);
        goto after_2;
    // 0x80133938: nop

    after_2:
    // 0x8013393C: jal         0x80133858
    // 0x80133940: nop

    mnSoundTestInitVars(rdram, ctx);
        goto after_3;
    // 0x80133940: nop

    after_3:
    // 0x80133944: jal         0x801336D8
    // 0x80133948: nop

    mnSoundTestMakeAllSObjs(rdram, ctx);
        goto after_4;
    // 0x80133948: nop

    after_4:
    // 0x8013394C: jal         0x80133728
    // 0x80133950: nop

    mnSoundTestMakeCameras(rdram, ctx);
        goto after_5;
    // 0x80133950: nop

    after_5:
    // 0x80133954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013395C: jr          $ra
    // 0x80133960: nop

    return;
    // 0x80133960: nop

;}
RECOMP_FUNC void sySchedulerDpFullSync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002340: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002344: lw          $v0, 0x4ECC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ECC);
    // 0x80002348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000234C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002350: beq         $v0, $zero, L_80002408
    if (ctx->r2 == 0) {
        // 0x80002354: nop
    
            goto L_80002408;
    }
    // 0x80002354: nop

    // 0x80002358: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8000235C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002360: bne         $t6, $at, L_80002408
    if (ctx->r14 != ctx->r1) {
        // 0x80002364: nop
    
            goto L_80002408;
    }
    // 0x80002364: nop

    // 0x80002368: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000236C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002370: bne         $t7, $at, L_800023F4
    if (ctx->r15 != ctx->r1) {
        // 0x80002374: nop
    
            goto L_800023F4;
    }
    // 0x80002374: nop

    // 0x80002378: lw          $a0, 0x6C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6C);
    // 0x8000237C: beql        $a0, $zero, L_80002398
    if (ctx->r4 == 0) {
        // 0x80002380: lw          $a0, 0x20($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X20);
            goto L_80002398;
    }
    goto skip_0;
    // 0x80002380: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    skip_0:
    // 0x80002384: jal         0x800017B8
    // 0x80002388: nop

    sySchedulerSetNextFramebuffer(rdram, ctx);
        goto after_0;
    // 0x80002388: nop

    after_0:
    // 0x8000238C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002390: lw          $v0, 0x4ECC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ECC);
    // 0x80002394: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
L_80002398:
    // 0x80002398: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000239C: beql        $a0, $zero, L_800023B8
    if (ctx->r4 == 0) {
        // 0x800023A0: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_800023B8;
    }
    goto skip_1;
    // 0x800023A0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_1:
    // 0x800023A4: jal         0x80030000
    // 0x800023A8: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800023A8: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    after_1:
    // 0x800023AC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800023B0: lw          $v0, 0x4ECC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ECC);
    // 0x800023B4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
L_800023B8:
    // 0x800023B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800023BC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800023C0: bne         $t8, $at, L_800023F4
    if (ctx->r24 != ctx->r1) {
        // 0x800023C4: nop
    
            goto L_800023F4;
    }
    // 0x800023C4: nop

    // 0x800023C8: lw          $a0, 0x4ED0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4ED0);
    // 0x800023CC: jal         0x800306CC
    // 0x800023D0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x800023D0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_2:
    // 0x800023D4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800023D8: lw          $a0, 0x4ED0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4ED0);
    // 0x800023DC: jal         0x8003085C
    // 0x800023E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x800023E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x800023E4: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800023E8: lw          $t0, 0x4ED0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4ED0);
    // 0x800023EC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800023F0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
L_800023F4:
    // 0x800023F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800023F8: jal         0x80001E64
    // 0x800023FC: sw          $zero, 0x4ECC($at)
    MEM_W(0X4ECC, ctx->r1) = 0;
    sySchedulerExecuteTasksAll(rdram, ctx);
        goto after_4;
    // 0x800023FC: sw          $zero, 0x4ECC($at)
    MEM_W(0X4ECC, ctx->r1) = 0;
    after_4:
    // 0x80002400: b           L_800024E0
    // 0x80002404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800024E0;
    // 0x80002404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002408:
    // 0x80002408: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000240C: lw          $v0, 0x4EE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EE4);
    // 0x80002410: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80002414: beq         $v0, $zero, L_80002464
    if (ctx->r2 == 0) {
        // 0x80002418: nop
    
            goto L_80002464;
    }
    // 0x80002418: nop

    // 0x8000241C: lw          $a0, 0x6C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6C);
    // 0x80002420: beql        $a0, $zero, L_8000243C
    if (ctx->r4 == 0) {
        // 0x80002424: lw          $a0, 0x20($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X20);
            goto L_8000243C;
    }
    goto skip_2;
    // 0x80002424: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    skip_2:
    // 0x80002428: jal         0x800017B8
    // 0x8000242C: nop

    sySchedulerSetNextFramebuffer(rdram, ctx);
        goto after_5;
    // 0x8000242C: nop

    after_5:
    // 0x80002430: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002434: lw          $v0, 0x4EE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EE4);
    // 0x80002438: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
L_8000243C:
    // 0x8000243C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80002440: beq         $a0, $zero, L_80002450
    if (ctx->r4 == 0) {
        // 0x80002444: nop
    
            goto L_80002450;
    }
    // 0x80002444: nop

    // 0x80002448: jal         0x80030000
    // 0x8000244C: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x8000244C: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    after_6:
L_80002450:
    // 0x80002450: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002454: jal         0x80001FF4
    // 0x80002458: sw          $zero, 0x4EE4($at)
    MEM_W(0X4EE4, ctx->r1) = 0;
    func_80001FF4(rdram, ctx);
        goto after_7;
    // 0x80002458: sw          $zero, 0x4EE4($at)
    MEM_W(0X4EE4, ctx->r1) = 0;
    after_7:
    // 0x8000245C: b           L_800024E0
    // 0x80002460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800024E0;
    // 0x80002460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002464:
    // 0x80002464: lw          $a3, 0x4ED4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4ED4);
    // 0x80002468: beql        $a3, $zero, L_800024E0
    if (ctx->r7 == 0) {
        // 0x8000246C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800024E0;
    }
    goto skip_3;
    // 0x8000246C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80002470: lw          $t1, 0x18($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X18);
    // 0x80002474: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002478: bnel        $t1, $at, L_800024E0
    if (ctx->r9 != ctx->r1) {
        // 0x8000247C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800024E0;
    }
    goto skip_4;
    // 0x8000247C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80002480: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80002484: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002488: bne         $t2, $at, L_800024D4
    if (ctx->r10 != ctx->r1) {
        // 0x8000248C: nop
    
            goto L_800024D4;
    }
    // 0x8000248C: nop

    // 0x80002490: lw          $a0, 0x6C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X6C);
    // 0x80002494: beql        $a0, $zero, L_800024B0
    if (ctx->r4 == 0) {
        // 0x80002498: lw          $a0, 0x20($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X20);
            goto L_800024B0;
    }
    goto skip_5;
    // 0x80002498: lw          $a0, 0x20($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X20);
    skip_5:
    // 0x8000249C: jal         0x800017B8
    // 0x800024A0: nop

    sySchedulerSetNextFramebuffer(rdram, ctx);
        goto after_8;
    // 0x800024A0: nop

    after_8:
    // 0x800024A4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800024A8: lw          $a3, 0x4ED4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4ED4);
    // 0x800024AC: lw          $a0, 0x20($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X20);
L_800024B0:
    // 0x800024B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800024B4: beq         $a0, $zero, L_800024CC
    if (ctx->r4 == 0) {
        // 0x800024B8: nop
    
            goto L_800024CC;
    }
    // 0x800024B8: nop

    // 0x800024BC: jal         0x80030000
    // 0x800024C0: lw          $a1, 0x1C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x800024C0: lw          $a1, 0x1C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X1C);
    after_9:
    // 0x800024C4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800024C8: lw          $a3, 0x4ED4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4ED4);
L_800024CC:
    // 0x800024CC: jal         0x80000DD4
    // 0x800024D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    sySchedulerRemovePausedQueue(rdram, ctx);
        goto after_10;
    // 0x800024D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_10:
L_800024D4:
    // 0x800024D4: jal         0x80001E64
    // 0x800024D8: nop

    sySchedulerExecuteTasksAll(rdram, ctx);
        goto after_11;
    // 0x800024D8: nop

    after_11:
    // 0x800024DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800024E0:
    // 0x800024E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800024E4: jr          $ra
    // 0x800024E8: nop

    return;
    // 0x800024E8: nop

;}
RECOMP_FUNC void mnPlayersVSCheckGameModeInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135270: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135274: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135278: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013527C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135280: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80135284: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135288: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013528C: lui         $at, 0x4309
    ctx->r1 = S32(0X4309 << 16);
    // 0x80135290: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135294: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80135298: nop

    // 0x8013529C: bc1f        L_801352C4
    if (!c1cs) {
        // 0x801352A0: nop
    
            goto L_801352C4;
    }
    // 0x801352A0: nop

    // 0x801352A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801352A8: nop

    // 0x801352AC: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x801352B0: nop

    // 0x801352B4: bc1f        L_801352C4
    if (!c1cs) {
        // 0x801352B8: nop
    
            goto L_801352C4;
    }
    // 0x801352B8: nop

    // 0x801352BC: b           L_801352C4
    // 0x801352C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801352C4;
    // 0x801352C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801352C4:
    // 0x801352C4: beq         $v1, $zero, L_80135328
    if (ctx->r3 == 0) {
        // 0x801352C8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80135328;
    }
    // 0x801352C8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801352CC: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801352D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801352D4: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801352D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801352DC: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801352E0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801352E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801352E8: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x801352EC: nop

    // 0x801352F0: bc1f        L_80135318
    if (!c1cs) {
        // 0x801352F4: nop
    
            goto L_80135318;
    }
    // 0x801352F4: nop

    // 0x801352F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801352FC: nop

    // 0x80135300: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80135304: nop

    // 0x80135308: bc1f        L_80135318
    if (!c1cs) {
        // 0x8013530C: nop
    
            goto L_80135318;
    }
    // 0x8013530C: nop

    // 0x80135310: b           L_80135318
    // 0x80135314: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135318;
    // 0x80135314: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135318:
    // 0x80135318: beql        $v1, $zero, L_8013532C
    if (ctx->r3 == 0) {
        // 0x8013531C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013532C;
    }
    goto skip_0;
    // 0x8013531C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80135320: jr          $ra
    // 0x80135324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135328:
    // 0x80135328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013532C:
    // 0x8013532C: jr          $ra
    // 0x80135330: nop

    return;
    // 0x80135330: nop

;}
RECOMP_FUNC void mpCollisionGetLineDistanceFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F39F0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800F39F4: subu        $t6, $a3, $a1
    ctx->r14 = SUB32(ctx->r7, ctx->r5);
    // 0x800F39F8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800F39FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F3A00: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800F3A04: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x800F3A08: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F3A0C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800F3A10: sub.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x800F3A14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F3A18: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800F3A1C: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800F3A20: nop

    // 0x800F3A24: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F3A28: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800F3A2C: jr          $ra
    // 0x800F3A30: add.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f10.fl;
    return;
    // 0x800F3A30: add.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f10.fl;
;}
RECOMP_FUNC void mnPlayers1PBonusMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801330CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801330D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801330D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801330D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801330DC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801330E0: jal         0x80009968
    // 0x801330E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801330E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801330E8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801330EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801330F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801330F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801330F8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801330FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133100: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80133104: jal         0x80009DF4
    // 0x80133108: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133108: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013310C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133110: lw          $t7, 0x7E00($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7E00);
    // 0x80133114: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133118: addiu       $t8, $t8, 0x440
    ctx->r24 = ADD32(ctx->r24, 0X440);
    // 0x8013311C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133120: jal         0x800CCFDC
    // 0x80133124: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133124: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80133128: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013312C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133130: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80133134: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80133138: addiu       $t1, $zero, 0x12C
    ctx->r9 = ADD32(0, 0X12C);
    // 0x8013313C: addiu       $t2, $zero, 0xDC
    ctx->r10 = ADD32(0, 0XDC);
    // 0x80133140: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80133144: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80133148: sb          $t9, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r25;
    // 0x8013314C: sb          $t0, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r8;
    // 0x80133150: sh          $t1, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r9;
    // 0x80133154: sh          $t2, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r10;
    // 0x80133158: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8013315C: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80133160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133164: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133168: jr          $ra
    // 0x8013316C: nop

    return;
    // 0x8013316C: nop

;}
RECOMP_FUNC void itCapsuleDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017421C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80174220: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80174224: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174228: addiu       $a3, $a3, 0x4064
    ctx->r7 = ADD32(ctx->r7, 0X4064);
    // 0x8017422C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80174230: jal         0x80173B24
    // 0x80174234: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174234: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80174238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017423C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174240: jr          $ra
    // 0x80174244: nop

    return;
    // 0x80174244: nop

;}
RECOMP_FUNC void scStaffrollMakeCompanyTextSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EF0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132EF4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80132EF8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80132EFC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80132F00: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80132F04: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80132F08: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80132F0C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80132F10: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80132F14: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80132F18: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80132F1C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80132F20: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80132F24: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80132F28: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80132F2C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80132F30: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80132F34: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80132F38: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x80132F3C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80132F40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80132F44: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80132F48: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80132F4C: addiu       $t9, $t9, -0x602C
    ctx->r25 = ADD32(ctx->r25, -0X602C);
    // 0x80132F50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80132F54: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80132F58: lw          $v1, -0x5FCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5FCC);
    // 0x80132F5C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80132F60: beq         $v1, $at, L_8013313C
    if (ctx->r3 == ctx->r1) {
        // 0x80132F64: sll         $t8, $v1, 3
        ctx->r24 = S32(ctx->r3 << 3);
            goto L_8013313C;
    }
    // 0x80132F64: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80132F68: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80132F6C: lw          $s5, 0x4($v0)
    ctx->r21 = MEM_W(ctx->r2, 0X4);
    // 0x80132F70: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80132F74: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80132F78: blez        $s5, L_8013313C
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80132F7C: lw          $a0, 0x0($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X0);
            goto L_8013313C;
    }
    // 0x80132F7C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80132F80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132F84: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80132F88: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80132F8C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80132F90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132F94: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80132F98: addiu       $t1, $t1, -0x61F8
    ctx->r9 = ADD32(ctx->r9, -0X61F8);
    // 0x80132F9C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80132FA0: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80132FA4: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80132FA8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80132FAC: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80132FB0: addiu       $s3, $s3, -0x5CB8
    ctx->r19 = ADD32(ctx->r19, -0X5CB8);
    // 0x80132FB4: addiu       $s7, $s7, -0x55F0
    ctx->r23 = ADD32(ctx->r23, -0X55F0);
    // 0x80132FB8: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x80132FBC: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80132FC0: addiu       $s6, $zero, -0x21
    ctx->r22 = ADD32(0, -0X21);
    // 0x80132FC4: addiu       $s4, $zero, 0x80
    ctx->r20 = ADD32(0, 0X80);
L_80132FC8:
    // 0x80132FC8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80132FCC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80132FD0: beq         $s6, $s0, L_8013312C
    if (ctx->r22 == ctx->r16) {
        // 0x80132FD4: sll         $t2, $s0, 3
        ctx->r10 = S32(ctx->r16 << 3);
            goto L_8013312C;
    }
    // 0x80132FD4: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x80132FD8: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80132FDC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80132FE0: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x80132FE4: mov.s       $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    ctx->f20.fl = ctx->f30.fl;
    // 0x80132FE8: jal         0x800CCFDC
    // 0x80132FEC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132FEC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_0:
    // 0x80132FF0: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80132FF4: sh          $fp, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r30;
    // 0x80132FF8: swc1        $f24, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f24.u32l;
    // 0x80132FFC: swc1        $f24, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f24.u32l;
    // 0x80133000: sb          $s4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r20;
    // 0x80133004: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80133008: sb          $s4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r20;
    // 0x8013300C: swc1        $f22, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f22.u32l;
    // 0x80133010: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80133014: slti        $at, $s0, 0x1A
    ctx->r1 = SIGNED(ctx->r16) < 0X1A ? 1 : 0;
    // 0x80133018: bne         $at, $zero, L_80133088
    if (ctx->r1 != 0) {
        // 0x8013301C: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_80133088;
    }
    // 0x8013301C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80133020: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133024: mov.s       $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
            goto L_80133084;
    }
    // 0x80133024: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    // 0x80133028: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8013302C: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133030: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80133084;
    }
    // 0x80133030: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80133034: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133038: addiu       $at, $zero, 0x21
        ctx->r1 = ADD32(0, 0X21);
            goto L_80133084;
    }
    // 0x80133038: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8013303C: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133040: addiu       $at, $zero, 0x22
        ctx->r1 = ADD32(0, 0X22);
            goto L_80133084;
    }
    // 0x80133040: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80133044: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133048: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_80133084;
    }
    // 0x80133048: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x8013304C: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133050: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_80133084;
    }
    // 0x80133050: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80133054: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133058: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_80133084;
    }
    // 0x80133058: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8013305C: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133060: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_80133084;
    }
    // 0x80133060: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80133064: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133068: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_80133084;
    }
    // 0x80133068: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8013306C: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133070: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_80133084;
    }
    // 0x80133070: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80133074: beq         $s0, $at, L_80133084
    if (ctx->r16 == ctx->r1) {
        // 0x80133078: addiu       $at, $zero, 0x43
        ctx->r1 = ADD32(0, 0X43);
            goto L_80133084;
    }
    // 0x80133078: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x8013307C: bnel        $s0, $at, L_8013308C
    if (ctx->r16 != ctx->r1) {
        // 0x80133080: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_8013308C;
    }
    goto skip_0;
    // 0x80133080: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    skip_0:
L_80133084:
    // 0x80133084: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
L_80133088:
    // 0x80133088: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
L_8013308C:
    // 0x8013308C: beq         $s0, $at, L_8013309C
    if (ctx->r16 == ctx->r1) {
        // 0x80133090: addiu       $at, $zero, 0x48
        ctx->r1 = ADD32(0, 0X48);
            goto L_8013309C;
    }
    // 0x80133090: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x80133094: bnel        $s0, $at, L_801330A4
    if (ctx->r16 != ctx->r1) {
        // 0x80133098: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_801330A4;
    }
    goto skip_1;
    // 0x80133098: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    skip_1:
L_8013309C:
    // 0x8013309C: mov.s       $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    ctx->f20.fl = ctx->f30.fl;
    // 0x801330A0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
L_801330A4:
    // 0x801330A4: bne         $s0, $at, L_801330B8
    if (ctx->r16 != ctx->r1) {
        // 0x801330A8: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_801330B8;
    }
    // 0x801330A8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801330AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801330B0: nop

    // 0x801330B4: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
L_801330B8:
    // 0x801330B8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x801330BC: bne         $s0, $at, L_801330D0
    if (ctx->r16 != ctx->r1) {
        // 0x801330C0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801330D0;
    }
    // 0x801330C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801330C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801330C8: nop

    // 0x801330CC: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_801330D0:
    // 0x801330D0: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x801330D4: bne         $s0, $at, L_801330E8
    if (ctx->r16 != ctx->r1) {
        // 0x801330D8: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_801330E8;
    }
    // 0x801330D8: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x801330DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801330E0: nop

    // 0x801330E4: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
L_801330E8:
    // 0x801330E8: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x801330EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801330F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801330F4: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x801330F8: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x801330FC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80133100: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80133104: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x80133108: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8013310C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80133110: bgez        $t0, L_80133124
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80133114: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80133124;
    }
    // 0x80133114: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80133118: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013311C: nop

    // 0x80133120: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80133124:
    // 0x80133124: b           L_80133130
    // 0x80133128: add.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f4.fl;
        goto L_80133130;
    // 0x80133128: add.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f4.fl;
L_8013312C:
    // 0x8013312C: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
L_80133130:
    // 0x80133130: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80133134: bne         $s2, $s5, L_80132FC8
    if (ctx->r18 != ctx->r21) {
        // 0x80133138: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80132FC8;
    }
    // 0x80133138: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8013313C:
    // 0x8013313C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80133140: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80133144: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80133148: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8013314C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80133150: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80133154: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80133158: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8013315C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80133160: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80133164: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80133168: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8013316C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80133170: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80133174: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80133178: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8013317C: jr          $ra
    // 0x80133180: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80133180: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void mvOpeningRoomMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132F48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132F4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132F54: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80132F58: jal         0x80009968
    // 0x80132F5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132F5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132F60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132F64: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132F68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132F6C: sw          $v0, 0x4D44($at)
    MEM_W(0X4D44, ctx->r1) = ctx->r2;
    // 0x80132F70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132F74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132F78: addiu       $a1, $a1, 0x2DE8
    ctx->r5 = ADD32(ctx->r5, 0X2DE8);
    // 0x80132F7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132F80: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80132F84: jal         0x80009DF4
    // 0x80132F88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132F88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132F8C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132F90: lw          $t7, 0x50CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50CC);
    // 0x80132F94: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80132F98: addiu       $t8, $t8, 0x6C88
    ctx->r24 = ADD32(ctx->r24, 0X6C88);
    // 0x80132F9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132FA0: jal         0x800CCFDC
    // 0x80132FA4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132FA4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132FA8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132FAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132FB0: nop

    // 0x80132FB4: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132FB8: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132FC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132FC4: jr          $ra
    // 0x80132FC8: nop

    return;
    // 0x80132FC8: nop

;}
RECOMP_FUNC void func_ovl8_8037D34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D34C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037D350: lw          $a0, -0x57A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X57A0);
    // 0x8037D354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037D358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037D35C: beql        $a0, $zero, L_8037D378
    if (ctx->r4 == 0) {
        // 0x8037D360: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037D378;
    }
    goto skip_0;
    // 0x8037D360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037D364: jal         0x80009A84
    // 0x8037D368: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8037D368: nop

    after_0:
    // 0x8037D36C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D370: sw          $zero, -0x57A0($at)
    MEM_W(-0X57A0, ctx->r1) = 0;
    // 0x8037D374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037D378:
    // 0x8037D378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037D37C: jr          $ra
    // 0x8037D380: nop

    return;
    // 0x8037D380: nop

;}
RECOMP_FUNC void mvOpeningStandoffStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013286C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132874: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132878: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8013287C: addiu       $a0, $a0, 0x2908
    ctx->r4 = ADD32(ctx->r4, 0X2908);
    // 0x80132880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132884: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132888: jal         0x80007024
    // 0x8013288C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8013288C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132890: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132894: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132898: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013289C: addiu       $t9, $t9, 0x2BA0
    ctx->r25 = ADD32(ctx->r25, 0X2BA0);
    // 0x801328A0: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801328A4: addiu       $a0, $a0, 0x2924
    ctx->r4 = ADD32(ctx->r4, 0X2924);
    // 0x801328A8: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801328AC: jal         0x8000683C
    // 0x801328B0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801328B0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801328B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801328B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801328BC: jr          $ra
    // 0x801328C0: nop

    return;
    // 0x801328C0: nop

;}
RECOMP_FUNC void mvOpeningDonkeyFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DFCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DFD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DFD4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018DFD8: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018DFDC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018DFE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018DFE4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018DFE8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018DFEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018DFF0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018DFF4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018DFF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018DFFC: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E000: jal         0x800FCB70
    // 0x8018E004: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E004: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E00C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E010: jr          $ra
    // 0x8018E014: nop

    return;
    // 0x8018E014: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNStartGetAnimSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015767C: lw          $t6, 0xAE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XAE0);
    // 0x80157680: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80157684: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80157688: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8015768C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80157690: lwc1        $f10, -0x3910($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3910);
    // 0x80157694: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80157698: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8015769C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801576A0: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801576A4: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801576A8: add.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801576AC: jr          $ra
    // 0x801576B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x801576B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void ftKirbySpecialNEatSetStatusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163018: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8016301C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163020: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80163024: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80163028: addiu       $t8, $t8, -0x7200
    ctx->r24 = ADD32(ctx->r24, -0X7200);
    // 0x8016302C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80163030: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80163034: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x80163038: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8016303C: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x80163040: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80163044: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80163048: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8016304C: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x80163050: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80163054: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80163058: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8016305C: jal         0x800E6F24
    // 0x80163060: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163060: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80163064: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80163068: jal         0x800E8098
    // 0x8016306C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x8016306C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x80163070: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80163074: lw          $v0, 0x9E8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X9E8);
    // 0x80163078: beq         $v0, $zero, L_80163088
    if (ctx->r2 == 0) {
        // 0x8016307C: nop
    
            goto L_80163088;
    }
    // 0x8016307C: nop

    // 0x80163080: jalr        $v0
    // 0x80163084: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80163084: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
L_80163088:
    // 0x80163088: jal         0x800E0830
    // 0x8016308C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x8016308C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80163090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163094: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80163098: jr          $ra
    // 0x8016309C: nop

    return;
    // 0x8016309C: nop

;}
RECOMP_FUNC void ftKirbySpecialLwHoldProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161974: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161978: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8016197C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80161980: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80161984: jal         0x800DDDA8
    // 0x80161988: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80161988: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016198C: bnel        $v0, $zero, L_801619D0
    if (ctx->r2 != 0) {
        // 0x80161990: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801619D0;
    }
    goto skip_0;
    // 0x80161990: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80161994: jal         0x800DEEC8
    // 0x80161998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x80161998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8016199C: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x801619A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801619A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801619A8: addiu       $a1, $zero, 0x10B
    ctx->r5 = ADD32(0, 0X10B);
    // 0x801619AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801619B0: jal         0x800E6F24
    // 0x801619B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x801619B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x801619B8: lbu         $t8, 0x191($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X191);
    // 0x801619BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801619C0: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x801619C4: jal         0x80161468
    // 0x801619C8: sb          $t9, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r25;
    ftKirbySpecialLwSetDropFallVel(rdram, ctx);
        goto after_3;
    // 0x801619C8: sb          $t9, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r25;
    after_3:
    // 0x801619CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801619D0:
    // 0x801619D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801619D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801619D8: jr          $ra
    // 0x801619DC: nop

    return;
    // 0x801619DC: nop

;}
RECOMP_FUNC void scStaffrollMakeHighlightGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327A4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801327A8: lw          $t6, -0x5734($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5734);
    // 0x801327AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801327B0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x801327B4: lw          $v0, 0x6714($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6714);
    // 0x801327B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801327BC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801327C0: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x801327C4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x801327C8: bne         $v0, $zero, L_80132850
    if (ctx->r2 != 0) {
        // 0x801327CC: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80132850;
    }
    // 0x801327CC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801327D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801327D4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x801327D8: jal         0x80009968
    // 0x801327DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801327DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801327E0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801327E4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801327E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801327EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801327F0: addiu       $a1, $a1, 0x2144
    ctx->r5 = ADD32(ctx->r5, 0X2144);
    // 0x801327F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801327F8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801327FC: jal         0x80009DF4
    // 0x80132800: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132800: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132804: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132808: addiu       $a1, $a1, 0x270C
    ctx->r5 = ADD32(ctx->r5, 0X270C);
    // 0x8013280C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80132810: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132814: jal         0x80008188
    // 0x80132818: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132818: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8013281C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80132820: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80132824: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132828: lwc1        $f4, 0x58($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X58);
    // 0x8013282C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80132830: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80132834: swc1        $f8, -0x5710($at)
    MEM_W(-0X5710, ctx->r1) = ctx->f8.u32l;
    // 0x80132838: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8013283C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132840: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80132844: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80132848: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8013284C: swc1        $f18, -0x570C($at)
    MEM_W(-0X570C, ctx->r1) = ctx->f18.u32l;
L_80132850:
    // 0x80132850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132854: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80132858: jr          $ra
    // 0x8013285C: nop

    return;
    // 0x8013285C: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNWaitProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801626C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801626C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801626C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801626CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801626D0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801626D4: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x801626D8: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x801626DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801626E0: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x801626E4: bgezl       $t8, L_80162700
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801626E8: lwc1        $f0, 0x58($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
            goto L_80162700;
    }
    goto skip_0;
    // 0x801626E8: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
    skip_0:
    // 0x801626EC: jal         0x800D8DA0
    // 0x801626F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyFastFall(rdram, ctx);
        goto after_0;
    // 0x801626F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x801626F4: b           L_80162724
    // 0x801626F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80162724;
    // 0x801626F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801626FC: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
L_80162700:
    // 0x80162700: lwc1        $f2, 0x5C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x80162704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80162708: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8016270C: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80162710: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80162714: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80162718: jal         0x800D8D68
    // 0x8016271C: nop

    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_1;
    // 0x8016271C: nop

    after_1:
    // 0x80162720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80162724:
    // 0x80162724: jal         0x800D8FA8
    // 0x80162728: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_2;
    // 0x80162728: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8016272C: bne         $v0, $zero, L_8016273C
    if (ctx->r2 != 0) {
        // 0x80162730: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016273C;
    }
    // 0x80162730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80162734: jal         0x800D9074
    // 0x80162738: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_3;
    // 0x80162738: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_8016273C:
    // 0x8016273C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162740: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80162744: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80162748: jr          $ra
    // 0x8016274C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8016274C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonAttackAirLwProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150988: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015098C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80150990: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80150994: beq         $v1, $at, L_801509A4
    if (ctx->r3 == ctx->r1) {
        // 0x80150998: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_801509A4;
    }
    // 0x80150998: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8015099C: bne         $v1, $at, L_801509F0
    if (ctx->r3 != ctx->r1) {
        // 0x801509A0: nop
    
            goto L_801509F0;
    }
    // 0x801509A0: nop

L_801509A4:
    // 0x801509A4: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x801509A8: beq         $v1, $zero, L_801509F0
    if (ctx->r3 == 0) {
        // 0x801509AC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_801509F0;
    }
    // 0x801509AC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x801509B0: bne         $t6, $zero, L_801509F0
    if (ctx->r14 != 0) {
        // 0x801509B4: sw          $t6, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r14;
            goto L_801509F0;
    }
    // 0x801509B4: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    // 0x801509B8: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x801509BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801509C0: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801509C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801509C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801509CC: nop

    // 0x801509D0: bc1f        L_801509F0
    if (!c1cs) {
        // 0x801509D4: nop
    
            goto L_801509F0;
    }
    // 0x801509D4: nop

    // 0x801509D8: jal         0x800E8668
    // 0x801509DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftParamRefreshAttackCollID(rdram, ctx);
        goto after_0;
    // 0x801509DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801509E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801509E4: jal         0x800E8668
    // 0x801509E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamRefreshAttackCollID(rdram, ctx);
        goto after_1;
    // 0x801509E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801509EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_801509F0:
    // 0x801509F0: jal         0x800D94E8
    // 0x801509F4: nop

    ftAnimEndSetFall(rdram, ctx);
        goto after_2;
    // 0x801509F4: nop

    after_2:
    // 0x801509F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801509FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150A00: jr          $ra
    // 0x80150A04: nop

    return;
    // 0x80150A04: nop

;}
RECOMP_FUNC void syDebugFramebufferPrintFloatReg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800227F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800227F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800227FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80022800: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80022804: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80022808: lui         $at, 0x7F80
    ctx->r1 = S32(0X7F80 << 16);
    // 0x8002280C: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
    // 0x80022810: srl         $v1, $v1, 23
    ctx->r3 = S32(U32(ctx->r3) >> 23);
    // 0x80022814: addiu       $v1, $v1, -0x7F
    ctx->r3 = ADD32(ctx->r3, -0X7F);
    // 0x80022818: slti        $at, $v1, -0x7E
    ctx->r1 = SIGNED(ctx->r3) < -0X7E ? 1 : 0;
    // 0x8002281C: bne         $at, $zero, L_8002282C
    if (ctx->r1 != 0) {
        // 0x80022820: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_8002282C;
    }
    // 0x80022820: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x80022824: bnel        $at, $zero, L_80022838
    if (ctx->r1 != 0) {
        // 0x80022828: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80022838;
    }
    goto skip_0;
    // 0x80022828: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_8002282C:
    // 0x8002282C: bne         $v0, $zero, L_8002285C
    if (ctx->r2 != 0) {
        // 0x80022830: lui         $a2, 0x8004
        ctx->r6 = S32(0X8004 << 16);
            goto L_8002285C;
    }
    // 0x80022830: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022834: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80022838:
    // 0x80022838: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8002283C: addiu       $a2, $a2, -0x19DC
    ctx->r6 = ADD32(ctx->r6, -0X19DC);
    // 0x80022840: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80022844: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80022848: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002284C: jal         0x80022664
    // 0x80022850: sdc1        $f6, 0x10($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X10, ctx->r29);
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_0;
    // 0x80022850: sdc1        $f6, 0x10($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X10, ctx->r29);
    after_0:
    // 0x80022854: b           L_80022870
    // 0x80022858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80022870;
    // 0x80022858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002285C:
    // 0x8002285C: addiu       $a2, $a2, -0x19D0
    ctx->r6 = ADD32(ctx->r6, -0X19D0);
    // 0x80022860: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80022864: jal         0x80022664
    // 0x80022868: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_1;
    // 0x80022868: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x8002286C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80022870:
    // 0x80022870: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022874: jr          $ra
    // 0x80022878: nop

    return;
    // 0x80022878: nop

;}
RECOMP_FUNC void itManagerSetPrevStructAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DFDC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8016DFE0: addiu       $v0, $v0, -0x2F6C
    ctx->r2 = ADD32(ctx->r2, -0X2F6C);
    // 0x8016DFE4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8016DFE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8016DFEC: jr          $ra
    // 0x8016DFF0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8016DFF0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void mnPlayers1PTrainingGetNextPortraitX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C70: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80131C74: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131C78: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80131C7C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80131C80: addiu       $t6, $t6, 0x7FB0
    ctx->r14 = ADD32(ctx->r14, 0X7FB0);
    // 0x80131C84: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80131C88: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80131C8C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131C90:
    // 0x80131C90: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131C94: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131C98: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131C9C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131CA0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131CA4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131CA8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131CAC: bne         $t6, $t0, L_80131C90
    if (ctx->r14 != ctx->r8) {
        // 0x80131CB0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131C90;
    }
    // 0x80131CB0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131CB4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131CB8: addiu       $t1, $t1, 0x7FE0
    ctx->r9 = ADD32(ctx->r9, 0X7FE0);
    // 0x80131CBC: addiu       $t5, $t1, 0x30
    ctx->r13 = ADD32(ctx->r9, 0X30);
    // 0x80131CC0: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_80131CC4:
    // 0x80131CC4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131CC8: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80131CCC: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80131CD0: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x80131CD4: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x80131CD8: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x80131CDC: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x80131CE0: bne         $t1, $t5, L_80131CC4
    if (ctx->r9 != ctx->r13) {
        // 0x80131CE4: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_80131CC4;
    }
    // 0x80131CE4: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x80131CE8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80131CEC: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x80131CF0: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80131CF4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80131CF8: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80131CFC: nop

    // 0x80131D00: bc1fl       L_80131D18
    if (!c1cs) {
        // 0x80131D04: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80131D18;
    }
    goto skip_0;
    // 0x80131D04: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x80131D08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131D0C: b           L_80131D7C
    // 0x80131D10: nop

        goto L_80131D7C;
    // 0x80131D10: nop

    // 0x80131D14: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80131D18:
    // 0x80131D18: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x80131D1C: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x80131D20: bc1fl       L_80131D58
    if (!c1cs) {
        // 0x80131D24: lwc1        $f6, 0x0($t9)
        ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
            goto L_80131D58;
    }
    goto skip_1;
    // 0x80131D24: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    skip_1:
    // 0x80131D28: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80131D2C: add.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80131D30: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80131D34: nop

    // 0x80131D38: bc1fl       L_80131D4C
    if (!c1cs) {
        // 0x80131D3C: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80131D4C;
    }
    goto skip_2;
    // 0x80131D3C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x80131D40: b           L_80131D7C
    // 0x80131D44: nop

        goto L_80131D7C;
    // 0x80131D44: nop

    // 0x80131D48: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80131D4C:
    // 0x80131D4C: b           L_80131D7C
    // 0x80131D50: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80131D7C;
    // 0x80131D50: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80131D54: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
L_80131D58:
    // 0x80131D58: add.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80131D5C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80131D60: nop

    // 0x80131D64: bc1fl       L_80131D78
    if (!c1cs) {
        // 0x80131D68: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80131D78;
    }
    goto skip_3;
    // 0x80131D68: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_3:
    // 0x80131D6C: b           L_80131D78
    // 0x80131D70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80131D78;
    // 0x80131D70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80131D74: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80131D78:
    // 0x80131D78: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80131D7C:
    // 0x80131D7C: jr          $ra
    // 0x80131D80: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80131D80: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void wpLinkBoomerangProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D4DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016D4E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016D4E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016D4E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016D4EC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8016D4F0: jal         0x80167FE8
    // 0x8016D4F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8016D4F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8016D4F8: bne         $v0, $zero, L_8016D514
    if (ctx->r2 != 0) {
        // 0x8016D4FC: nop
    
            goto L_8016D514;
    }
    // 0x8016D4FC: nop

    // 0x8016D500: jal         0x8016CCA0
    // 0x8016D504: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    wpLinkBoomerangCheckOffCamera(rdram, ctx);
        goto after_1;
    // 0x8016D504: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8016D508: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016D50C: bnel        $v0, $at, L_8016D528
    if (ctx->r2 != ctx->r1) {
        // 0x8016D510: lbu         $v0, 0x2A2($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X2A2);
            goto L_8016D528;
    }
    goto skip_0;
    // 0x8016D510: lbu         $v0, 0x2A2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2A2);
    skip_0:
L_8016D514:
    // 0x8016D514: jal         0x8016D31C
    // 0x8016D518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpLinkBoomerangClearGObjs(rdram, ctx);
        goto after_2;
    // 0x8016D518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8016D51C: b           L_8016D5D8
    // 0x8016D520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016D5D8;
    // 0x8016D520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016D524: lbu         $v0, 0x2A2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2A2);
L_8016D528:
    // 0x8016D528: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8016D52C: beq         $t7, $zero, L_8016D544
    if (ctx->r15 == 0) {
        // 0x8016D530: andi        $t8, $v0, 0x20
        ctx->r24 = ctx->r2 & 0X20;
            goto L_8016D544;
    }
    // 0x8016D530: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x8016D534: jal         0x8016D31C
    // 0x8016D538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpLinkBoomerangClearGObjs(rdram, ctx);
        goto after_3;
    // 0x8016D538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8016D53C: b           L_8016D5D8
    // 0x8016D540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016D5D8;
    // 0x8016D540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016D544:
    // 0x8016D544: beq         $t8, $zero, L_8016D554
    if (ctx->r24 == 0) {
        // 0x8016D548: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_8016D554;
    }
    // 0x8016D548: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8016D54C: b           L_8016D5D8
    // 0x8016D550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016D5D8;
    // 0x8016D550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016D554:
    // 0x8016D554: beq         $t9, $zero, L_8016D590
    if (ctx->r25 == 0) {
        // 0x8016D558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016D590;
    }
    // 0x8016D558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016D55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016D560: jal         0x8016CE90
    // 0x8016D564: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    wpLinkBoomerangAddVelSqrt(rdram, ctx);
        goto after_4;
    // 0x8016D564: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x8016D568: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8016D56C: jal         0x8016CF48
    // 0x8016D570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpLinkBoomerangUpdateVelLR(rdram, ctx);
        goto after_5;
    // 0x8016D570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8016D574: jal         0x8016D0E4
    // 0x8016D578: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    wpLinkBoomerangGetDistUpdateAngle(rdram, ctx);
        goto after_6;
    // 0x8016D578: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8016D57C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8016D580: jal         0x8016D35C
    // 0x8016D584: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    wpLinkBoomerangCheckOwnerCatch(rdram, ctx);
        goto after_7;
    // 0x8016D584: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8016D588: b           L_8016D5D8
    // 0x8016D58C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016D5D8;
    // 0x8016D58C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016D590:
    // 0x8016D590: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x8016D594: jal         0x8016CEEC
    // 0x8016D598: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    wpLinkBoomerangSubVelSqrt(rdram, ctx);
        goto after_8;
    // 0x8016D598: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_8:
    // 0x8016D59C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8016D5A0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8016D5A4: jal         0x8016CF48
    // 0x8016D5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpLinkBoomerangUpdateVelLR(rdram, ctx);
        goto after_9;
    // 0x8016D5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8016D5AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8016D5B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016D5B4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8016D5B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8016D5BC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8016D5C0: nop

    // 0x8016D5C4: bc1fl       L_8016D5D8
    if (!c1cs) {
        // 0x8016D5C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016D5D8;
    }
    goto skip_1;
    // 0x8016D5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8016D5CC: jal         0x8016CDC8
    // 0x8016D5D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    wpLinkBoomerangSetReturnVars(rdram, ctx);
        goto after_10;
    // 0x8016D5D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8016D5D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016D5D8:
    // 0x8016D5D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D5DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016D5E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016D5E4: jr          $ra
    // 0x8016D5E8: nop

    return;
    // 0x8016D5E8: nop

;}
RECOMP_FUNC void func_ovl8_8038215C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038215C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80382160: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80382164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382168: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038216C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80382170: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80382174: bne         $a0, $zero, L_8038218C
    if (ctx->r4 != 0) {
        // 0x80382178: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_8038218C;
    }
    // 0x80382178: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8038217C: jal         0x803717A0
    // 0x80382180: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382180: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x80382184: beq         $v0, $zero, L_80382210
    if (ctx->r2 == 0) {
        // 0x80382188: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80382210;
    }
    // 0x80382188: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8038218C:
    // 0x8038218C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80382190: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80382194: addiu       $a1, $s0, 0x9C
    ctx->r5 = ADD32(ctx->r16, 0X9C);
    // 0x80382198: bnel        $t6, $zero, L_803821BC
    if (ctx->r14 != 0) {
        // 0x8038219C: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_803821BC;
    }
    goto skip_0;
    // 0x8038219C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x803821A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803821A4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x803821A8: jal         0x803717E0
    // 0x803821AC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803821AC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x803821B0: jal         0x8037C2D0
    // 0x803821B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803821B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x803821B8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_803821BC:
    // 0x803821BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803821C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x803821C4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x803821C8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x803821CC: jal         0x8037345C
    // 0x803821D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_8037345C(rdram, ctx);
        goto after_3;
    // 0x803821D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x803821D4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x803821D8: addiu       $t8, $t8, -0x42E0
    ctx->r24 = ADD32(ctx->r24, -0X42E0);
    // 0x803821DC: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x803821E0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x803821E4: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803821E8: addiu       $t9, $t9, -0x4210
    ctx->r25 = ADD32(ctx->r25, -0X4210);
    // 0x803821EC: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x803821F0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x803821F4: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x803821F8: addiu       $t1, $t1, -0x40B8
    ctx->r9 = ADD32(ctx->r9, -0X40B8);
    // 0x803821FC: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80382200: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80382204: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80382208: jal         0x803822D8
    // 0x8038220C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803822D8(rdram, ctx);
        goto after_4;
    // 0x8038220C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80382210:
    // 0x80382210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80382214: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382218: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8038221C: jr          $ra
    // 0x80382220: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80382220: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gmCameraPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C55C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010C560: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8010C564: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010C568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C56C: addiu       $a2, $a3, 0x48
    ctx->r6 = ADD32(ctx->r7, 0X48);
    // 0x8010C570: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8010C574: jal         0x8001902C
    // 0x8010C578: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x8010C578: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8010C57C: jal         0x80018F7C
    // 0x8010C580: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x8010C580: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8010C584: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8010C588: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8010C58C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010C590: jal         0x80018EE0
    // 0x8010C594: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x8010C594: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8010C598: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8010C59C: jal         0x800190B0
    // 0x8010C5A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    syVectorScale3D(rdram, ctx);
        goto after_3;
    // 0x8010C5A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8010C5A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010C5A8: jal         0x80018FBC
    // 0x8010C5AC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    syVectorAdd3D(rdram, ctx);
        goto after_4;
    // 0x8010C5AC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x8010C5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C5B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010C5B8: jr          $ra
    // 0x8010C5BC: nop

    return;
    // 0x8010C5BC: nop

;}
RECOMP_FUNC void ftCommonTurnRunSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F208: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013F20C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013F210: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013F214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013F218: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x8013F21C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013F220: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013F224: jal         0x800E6F24
    // 0x8013F228: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013F228: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013F22C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013F230: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8013F234: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x8013F238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F23C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013F240: jr          $ra
    // 0x8013F244: nop

    return;
    // 0x8013F244: nop

;}

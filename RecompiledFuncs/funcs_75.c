#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void unref_80009E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009E38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009E3C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80009E40: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80009E44: bne         $a0, $zero, L_80009E54
    if (ctx->r4 != 0) {
        // 0x80009E48: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80009E54;
    }
    // 0x80009E48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009E4C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80009E50: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_80009E54:
    // 0x80009E54: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80009E58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009E5C: jal         0x80009D78
    // 0x80009E60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gcLinkGObjDLCommon(rdram, ctx);
        goto after_0;
    // 0x80009E60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80009E64: jal         0x80007C6C
    // 0x80009E68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcDLLinkGObjHead(rdram, ctx);
        goto after_1;
    // 0x80009E68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80009E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009E74: jr          $ra
    // 0x80009E78: nop

    return;
    // 0x80009E78: nop

;}
RECOMP_FUNC void mvOpeningRoomLogoWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132404: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132408: lw          $t6, 0x4CE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4CE4);
    // 0x8013240C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80132410: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132414: slti        $at, $t6, 0x3C
    ctx->r1 = SIGNED(ctx->r14) < 0X3C ? 1 : 0;
    // 0x80132418: bne         $at, $zero, L_80132440
    if (ctx->r1 != 0) {
        // 0x8013241C: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_80132440;
    }
    // 0x8013241C: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x80132420: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132424: addiu       $t3, $t3, 0x4D38
    ctx->r11 = ADD32(ctx->r11, 0X4D38);
    // 0x80132428: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8013242C: blez        $v0, L_80132440
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80132430: addiu       $t7, $v0, -0xD
        ctx->r15 = ADD32(ctx->r2, -0XD);
            goto L_80132440;
    }
    // 0x80132430: addiu       $t7, $v0, -0xD
    ctx->r15 = ADD32(ctx->r2, -0XD);
    // 0x80132434: bgez        $t7, L_80132440
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80132438: sw          $t7, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r15;
            goto L_80132440;
    }
    // 0x80132438: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8013243C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_80132440:
    // 0x80132440: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
    // 0x80132444: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80132448: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x8013244C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132450: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80132454: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132458: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8013245C: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
    // 0x80132460: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80132464: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132468: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8013246C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80132470: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132474: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132478: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
    // 0x8013247C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80132480: addiu       $t3, $t3, 0x4D38
    ctx->r11 = ADD32(ctx->r11, 0X4D38);
    // 0x80132484: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80132488: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8013248C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132490: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80132494: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80132498: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8013249C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801324A0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801324A4: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
    // 0x801324A8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x801324AC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x801324B0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801324B4: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x801324B8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801324BC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801324C0: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
    // 0x801324C4: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x801324C8: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801324CC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801324D0: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x801324D4: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801324D8: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x801324DC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801324E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801324E4: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
    // 0x801324E8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801324EC: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x801324F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801324F4: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x801324F8: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x801324FC: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x80132500: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80132504: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132508: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
    // 0x8013250C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132510: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80132514: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132518: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8013251C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132520: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132524: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
    // 0x80132528: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x8013252C: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132530: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80132534: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80132538: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8013253C: jr          $ra
    // 0x80132540: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    return;
    // 0x80132540: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
;}
RECOMP_FUNC void dbCubeExit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80131BC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131BC4: jr          $ra
    // 0x80131BC8: sw          $t6, 0x3138($at)
    MEM_W(0X3138, ctx->r1) = ctx->r14;
    return;
    // 0x80131BC8: sw          $t6, 0x3138($at)
    MEM_W(0X3138, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mnVSOptionsMakeDamageDigitSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CC8: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80131CCC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80131CD0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131CD4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80131CD8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80131CDC: addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // 0x80131CE0: addiu       $t6, $t6, 0x4708
    ctx->r14 = ADD32(ctx->r14, 0X4708);
    // 0x80131CE4: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80131CE8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80131CEC: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80131CF0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80131CF4: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80131CF8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80131CFC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80131D00: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80131D04: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80131D08: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80131D0C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80131D10: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80131D14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131D18: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x80131D1C: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80131D20: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80131D24:
    // 0x80131D24: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D28: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131D2C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131D30: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131D34: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131D38: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131D3C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131D40: bne         $t6, $t0, L_80131D24
    if (ctx->r14 != ctx->r8) {
        // 0x80131D44: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131D24;
    }
    // 0x80131D44: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131D48: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D4C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131D50: addiu       $t2, $t2, 0x4730
    ctx->r10 = ADD32(ctx->r10, 0X4730);
    // 0x80131D54: addiu       $t5, $t2, 0x24
    ctx->r13 = ADD32(ctx->r10, 0X24);
    // 0x80131D58: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x80131D5C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_80131D60:
    // 0x80131D60: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131D64: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80131D68: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80131D6C: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80131D70: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80131D74: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80131D78: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80131D7C: bne         $t2, $t5, L_80131D60
    if (ctx->r10 != ctx->r13) {
        // 0x80131D80: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80131D60;
    }
    // 0x80131D80: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80131D84: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131D88: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80131D8C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80131D90: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80131D94: bgez        $s3, L_80131DA0
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80131D98: lwc1        $f20, 0xC8($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0XC8);
            goto L_80131DA0;
    }
    // 0x80131D98: lwc1        $f20, 0xC8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80131D9C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80131DA0:
    // 0x80131DA0: div         $zero, $s3, $s6
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r22)));
    // 0x80131DA4: mfhi        $t0
    ctx->r8 = hi;
    // 0x80131DA8: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80131DAC: addiu       $s7, $s7, 0x49D8
    ctx->r23 = ADD32(ctx->r23, 0X49D8);
    // 0x80131DB0: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x80131DB4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80131DB8: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80131DBC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80131DC0: bne         $s6, $zero, L_80131DCC
    if (ctx->r22 != 0) {
        // 0x80131DC4: nop
    
            goto L_80131DCC;
    }
    // 0x80131DC4: nop

    // 0x80131DC8: break       7
    do_break(2148736456);
L_80131DCC:
    // 0x80131DCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131DD0: bne         $s6, $at, L_80131DE4
    if (ctx->r22 != ctx->r1) {
        // 0x80131DD4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131DE4;
    }
    // 0x80131DD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131DD8: bne         $s3, $at, L_80131DE4
    if (ctx->r19 != ctx->r1) {
        // 0x80131DDC: nop
    
            goto L_80131DE4;
    }
    // 0x80131DDC: nop

    // 0x80131DE0: break       6
    do_break(2148736480);
L_80131DE4:
    // 0x80131DE4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80131DE8: jal         0x800CCFDC
    // 0x80131DEC: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131DEC: nop

    after_0:
    // 0x80131DF0: lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD0);
    // 0x80131DF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131DF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DFC: jal         0x80131BEC
    // 0x80131E00: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnVSOptionsSetDamageDigitSpriteColors(rdram, ctx);
        goto after_1;
    // 0x80131E00: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80131E04: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80131E08: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80131E0C: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80131E10: lw          $s5, 0xD8($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XD8);
    // 0x80131E14: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131E18: sub.s       $f20, $f4, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80131E1C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80131E20: beq         $s5, $zero, L_80131E34
    if (ctx->r21 == 0) {
        // 0x80131E24: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80131E34;
    }
    // 0x80131E24: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131E28: lw          $s2, 0xD4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD4);
    // 0x80131E2C: b           L_80131E48
    // 0x80131E30: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131E48;
    // 0x80131E30: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131E34:
    // 0x80131E34: lw          $s2, 0xD4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD4);
    // 0x80131E38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131E3C: jal         0x80131C1C
    // 0x80131E40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnVSOptionsGetDamageDigitCount(rdram, ctx);
        goto after_2;
    // 0x80131E40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80131E44: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131E48:
    // 0x80131E48: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80131E4C: bne         $at, $zero, L_80131F38
    if (ctx->r1 != 0) {
        // 0x80131E50: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131F38;
    }
    // 0x80131E50: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80131E54:
    // 0x80131E54: jal         0x80131B4C
    // 0x80131E58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnVSOptionsGetPowerOf(rdram, ctx);
        goto after_3;
    // 0x80131E58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80131E5C: beq         $v0, $zero, L_80131EA4
    if (ctx->r2 == 0) {
        // 0x80131E60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131EA4;
    }
    // 0x80131E60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131E64: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80131E68: jal         0x80131B4C
    // 0x80131E6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnVSOptionsGetPowerOf(rdram, ctx);
        goto after_4;
    // 0x80131E6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80131E70: div         $zero, $s3, $v0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r2)));
    // 0x80131E74: mflo        $v1
    ctx->r3 = lo;
    // 0x80131E78: bne         $v0, $zero, L_80131E84
    if (ctx->r2 != 0) {
        // 0x80131E7C: nop
    
            goto L_80131E84;
    }
    // 0x80131E7C: nop

    // 0x80131E80: break       7
    do_break(2148736640);
L_80131E84:
    // 0x80131E84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131E88: bne         $v0, $at, L_80131E9C
    if (ctx->r2 != ctx->r1) {
        // 0x80131E8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131E9C;
    }
    // 0x80131E8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131E90: bne         $s3, $at, L_80131E9C
    if (ctx->r19 != ctx->r1) {
        // 0x80131E94: nop
    
            goto L_80131E9C;
    }
    // 0x80131E94: nop

    // 0x80131E98: break       6
    do_break(2148736664);
L_80131E9C:
    // 0x80131E9C: b           L_80131EA4
    // 0x80131EA0: nop

        goto L_80131EA4;
    // 0x80131EA0: nop

L_80131EA4:
    // 0x80131EA4: div         $zero, $v1, $s6
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r22)));
    // 0x80131EA8: mfhi        $t5
    ctx->r13 = hi;
    // 0x80131EAC: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x80131EB0: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x80131EB4: lw          $t1, 0x98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X98);
    // 0x80131EB8: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80131EBC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80131EC0: bne         $s6, $zero, L_80131ECC
    if (ctx->r22 != 0) {
        // 0x80131EC4: nop
    
            goto L_80131ECC;
    }
    // 0x80131EC4: nop

    // 0x80131EC8: break       7
    do_break(2148736712);
L_80131ECC:
    // 0x80131ECC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131ED0: bne         $s6, $at, L_80131EE4
    if (ctx->r22 != ctx->r1) {
        // 0x80131ED4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131EE4;
    }
    // 0x80131ED4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131ED8: bne         $v1, $at, L_80131EE4
    if (ctx->r3 != ctx->r1) {
        // 0x80131EDC: nop
    
            goto L_80131EE4;
    }
    // 0x80131EDC: nop

    // 0x80131EE0: break       6
    do_break(2148736736);
L_80131EE4:
    // 0x80131EE4: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    // 0x80131EE8: jal         0x800CCFDC
    // 0x80131EEC: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80131EEC: nop

    after_5:
    // 0x80131EF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131EF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EF8: jal         0x80131BEC
    // 0x80131EFC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnVSOptionsSetDamageDigitSpriteColors(rdram, ctx);
        goto after_6;
    // 0x80131EFC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80131F00: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80131F04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80131F08: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131F0C: beq         $s5, $zero, L_80131F1C
    if (ctx->r21 == 0) {
        // 0x80131F10: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80131F1C;
    }
    // 0x80131F10: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131F14: b           L_80131F2C
    // 0x80131F18: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131F2C;
    // 0x80131F18: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131F1C:
    // 0x80131F1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131F20: jal         0x80131C1C
    // 0x80131F24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnVSOptionsGetDamageDigitCount(rdram, ctx);
        goto after_7;
    // 0x80131F24: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80131F28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131F2C:
    // 0x80131F2C: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80131F30: bnel        $at, $zero, L_80131E54
    if (ctx->r1 != 0) {
        // 0x80131F34: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131E54;
    }
    goto skip_0;
    // 0x80131F34: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_0:
L_80131F38:
    // 0x80131F38: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80131F3C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80131F40: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80131F44: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80131F48: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80131F4C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80131F50: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80131F54: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F58: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80131F5C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80131F60: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80131F64: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80131F68: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80131F6C: jr          $ra
    // 0x80131F70: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80131F70: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_ovl8_80374CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374CF8: jr          $ra
    // 0x80374CFC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    return;
    // 0x80374CFC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
;}
RECOMP_FUNC void mnVSOptionsCheckHaveItemSwitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80131B28: lbu         $t6, 0x4937($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4937);
    // 0x80131B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131B30: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x80131B34: beq         $t7, $zero, L_80131B44
    if (ctx->r15 == 0) {
        // 0x80131B38: nop
    
            goto L_80131B44;
    }
    // 0x80131B38: nop

    // 0x80131B3C: jr          $ra
    // 0x80131B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B44:
    // 0x80131B44: jr          $ra
    // 0x80131B48: nop

    return;
    // 0x80131B48: nop

;}
RECOMP_FUNC void mvOpeningRunFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B60: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80131B64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80131B68: jal         0x8000DF34
    // 0x80131B6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x80131B6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80131B70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80131B74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80131B78: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80131B7C: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80131B80: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80131B84: swc1        $f4, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f4.u32l;
    // 0x80131B88: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80131B8C: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x80131B90: lwc1        $f6, 0x20($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80131B94: swc1        $f6, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f6.u32l;
    // 0x80131B98: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80131B9C: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x80131BA0: lwc1        $f8, 0x24($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80131BA4: swc1        $f8, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f8.u32l;
    // 0x80131BA8: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80131BAC: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x80131BB0: lwc1        $f10, 0x30($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X30);
    // 0x80131BB4: swc1        $f10, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f10.u32l;
    // 0x80131BB8: lw          $t4, 0x74($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X74);
    // 0x80131BBC: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80131BC0: lwc1        $f16, 0x34($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X34);
    // 0x80131BC4: swc1        $f16, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f16.u32l;
    // 0x80131BC8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80131BCC: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80131BD0: lwc1        $f18, 0x38($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80131BD4: swc1        $f18, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f18.u32l;
    // 0x80131BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131BDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131BE0: jr          $ra
    // 0x80131BE4: nop

    return;
    // 0x80131BE4: nop

;}
RECOMP_FUNC void func_ovl8_80372B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372B48: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80372B4C: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x80372B50: lh          $t6, 0x80($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X80);
    // 0x80372B54: jalr        $t9
    // 0x80372B58: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80372B58: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80372B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372B60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372B64: jr          $ra
    // 0x80372B68: nop

    return;
    // 0x80372B68: nop

;}
RECOMP_FUNC void itLGunFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801754F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801754F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801754F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801754FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80175500: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80175504: jal         0x80172558
    // 0x80175508: lui         $a2, 0x4302
    ctx->r6 = S32(0X4302 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80175508: lui         $a2, 0x4302
    ctx->r6 = S32(0X4302 << 16);
    after_0:
    // 0x8017550C: jal         0x801713F4
    // 0x80175510: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80175510: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80175514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017551C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175520: jr          $ra
    // 0x80175524: nop

    return;
    // 0x80175524: nop

;}
RECOMP_FUNC void func_80018300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018300: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80018304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018308: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001830C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80018310: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80018314: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x80018318: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8001831C: lw          $a3, 0x6678($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6678);
    // 0x80018320: lh          $v0, 0x10($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X10);
    // 0x80018324: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x80018328: lh          $a1, 0x12($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X12);
    // 0x8001832C: lh          $a2, 0xA($s1)
    ctx->r6 = MEM_H(ctx->r17, 0XA);
    // 0x80018330: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80018334: lw          $t7, -0x46C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X46C8);
    // 0x80018338: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8001833C: bgez        $v0, L_80018348
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80018340: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_80018348;
    }
    // 0x80018340: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x80018344: addiu       $at, $v0, 0x3
    ctx->r1 = ADD32(ctx->r2, 0X3);
L_80018348:
    // 0x80018348: sra         $v0, $at, 2
    ctx->r2 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8001834C: bgez        $v1, L_80018358
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80018350: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80018358;
    }
    // 0x80018350: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80018354: addiu       $at, $v1, 0x3
    ctx->r1 = ADD32(ctx->r3, 0X3);
L_80018358:
    // 0x80018358: sra         $v1, $at, 2
    ctx->r3 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8001835C: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x80018360: bgez        $a1, L_8001836C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80018364: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_8001836C;
    }
    // 0x80018364: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x80018368: addiu       $at, $a1, 0x3
    ctx->r1 = ADD32(ctx->r5, 0X3);
L_8001836C:
    // 0x8001836C: sra         $a1, $at, 2
    ctx->r5 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80018370: bgez        $a2, L_8001837C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80018374: addu        $at, $a2, $zero
        ctx->r1 = ADD32(ctx->r6, 0);
            goto L_8001837C;
    }
    // 0x80018374: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80018378: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
L_8001837C:
    // 0x8001837C: sra         $a2, $at, 2
    ctx->r6 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80018380: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x80018384: div         $zero, $a3, $at
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r1)));
    // 0x80018388: mflo        $t0
    ctx->r8 = lo;
    // 0x8001838C: subu        $t3, $a1, $a2
    ctx->r11 = SUB32(ctx->r5, ctx->r6);
    // 0x80018390: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x80018394: multu       $t0, $t7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018398: addu        $t5, $a2, $a1
    ctx->r13 = ADD32(ctx->r6, ctx->r5);
    // 0x8001839C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800183A0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800183A4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800183A8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800183AC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800183B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800183B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800183B8: mflo        $t1
    ctx->r9 = lo;
    // 0x800183BC: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800183C0: beq         $at, $zero, L_800183CC
    if (ctx->r1 == 0) {
        // 0x800183C4: nop
    
            goto L_800183CC;
    }
    // 0x800183C4: nop

    // 0x800183C8: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_800183CC:
    // 0x800183CC: lw          $v0, 0x667C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X667C);
    // 0x800183D0: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800183D4: lw          $t8, -0x46D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X46D0);
    // 0x800183D8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800183DC: mflo        $v1
    ctx->r3 = lo;
    // 0x800183E0: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x800183E4: nop

    // 0x800183E8: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800183EC: mflo        $a0
    ctx->r4 = lo;
    // 0x800183F0: slt         $at, $t3, $a0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800183F4: beq         $at, $zero, L_80018400
    if (ctx->r1 == 0) {
        // 0x800183F8: nop
    
            goto L_80018400;
    }
    // 0x800183F8: nop

    // 0x800183FC: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
L_80018400:
    // 0x80018400: lw          $t9, -0x46C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X46C4);
    // 0x80018404: multu       $t0, $t9
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018408: mflo        $t6
    ctx->r14 = lo;
    // 0x8001840C: subu        $a0, $a3, $t6
    ctx->r4 = SUB32(ctx->r7, ctx->r14);
    // 0x80018410: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80018414: beq         $at, $zero, L_80018420
    if (ctx->r1 == 0) {
        // 0x80018418: nop
    
            goto L_80018420;
    }
    // 0x80018418: nop

    // 0x8001841C: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_80018420:
    // 0x80018420: lw          $t7, -0x46CC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X46CC);
    // 0x80018424: multu       $v1, $t7
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018428: mflo        $t8
    ctx->r24 = lo;
    // 0x8001842C: subu        $a0, $v0, $t8
    ctx->r4 = SUB32(ctx->r2, ctx->r24);
    // 0x80018430: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80018434: beql        $at, $zero, L_80018444
    if (ctx->r1 == 0) {
        // 0x80018438: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80018444;
    }
    goto skip_0;
    // 0x80018438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8001843C: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
    // 0x80018440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80018444:
    // 0x80018444: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80018448: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8001844C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80018450: jal         0x8001663C
    // 0x80018454: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    func_8001663C(rdram, ctx);
        goto after_0;
    // 0x80018454: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x80018458: jal         0x80024FD4
    // 0x8001845C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    spInit(rdram, ctx);
        goto after_1;
    // 0x8001845C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80018460: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80018464: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80018468: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001846C: jal         0x80023894
    // 0x80018470: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    spScissor(rdram, ctx);
        goto after_2;
    // 0x80018470: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80018474: lw          $t9, 0x80($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X80);
    // 0x80018478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001847C: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x80018480: beq         $t6, $zero, L_80018490
    if (ctx->r14 == 0) {
        // 0x80018484: nop
    
            goto L_80018490;
    }
    // 0x80018484: nop

    // 0x80018488: b           L_80018490
    // 0x8001848C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80018490;
    // 0x8001848C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80018490:
    // 0x80018490: jal         0x80017B80
    // 0x80018494: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    gcCaptureCameraGObj(rdram, ctx);
        goto after_3;
    // 0x80018494: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80018498: jal         0x80025E30
    // 0x8001849C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    spFinish(rdram, ctx);
        goto after_4;
    // 0x8001849C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800184A0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800184A4: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800184A8: ori         $t6, $t6, 0xC00
    ctx->r14 = ctx->r14 | 0XC00;
    // 0x800184AC: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x800184B0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800184B4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800184B8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800184BC: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800184C0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800184C4: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800184C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800184CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800184D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800184D4: jr          $ra
    // 0x800184D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800184D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void gcAddAnimJointAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000BD90: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000BD94: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000BD98: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000BD9C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000BDA0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000BDA4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000BDA8: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8000BDAC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8000BDB0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000BDB4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8000BDB8: beq         $s0, $zero, L_8000BE08
    if (ctx->r16 == 0) {
        // 0x8000BDBC: swc1        $f20, 0x78($a0)
        MEM_W(0X78, ctx->r4) = ctx->f20.u32l;
            goto L_8000BE08;
    }
    // 0x8000BDBC: swc1        $f20, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f20.u32l;
    // 0x8000BDC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000BDC4: lwc1        $f22, -0x2228($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2228);
L_8000BDC8:
    // 0x8000BDC8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8000BDCC: beql        $a1, $zero, L_8000BDF0
    if (ctx->r5 == 0) {
        // 0x8000BDD0: swc1        $f22, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
            goto L_8000BDF0;
    }
    goto skip_0;
    // 0x8000BDD0: swc1        $f22, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
    skip_0:
    // 0x8000BDD4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8000BDD8: jal         0x8000BD1C
    // 0x8000BDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8000BDDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BDE0: sb          $s2, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r18;
    // 0x8000BDE4: b           L_8000BDF4
    // 0x8000BDE8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8000BDF4;
    // 0x8000BDE8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000BDEC: swc1        $f22, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
L_8000BDF0:
    // 0x8000BDF0: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
L_8000BDF4:
    // 0x8000BDF4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000BDF8: jal         0x8000BAA0
    // 0x8000BDFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_1;
    // 0x8000BDFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000BE00: bne         $v0, $zero, L_8000BDC8
    if (ctx->r2 != 0) {
        // 0x8000BE04: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000BDC8;
    }
    // 0x8000BE04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000BE08:
    // 0x8000BE08: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000BE0C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000BE10: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000BE14: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000BE18: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BE1C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000BE20: jr          $ra
    // 0x8000BE24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000BE24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void itLinkBombDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80186314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80186318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018631C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80186320: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80186324: jal         0x80185CD4
    // 0x80186328: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itLinkBombCommonSetHitStatusNormal(rdram, ctx);
        goto after_0;
    // 0x80186328: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8018632C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80186330: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80186334: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80186338: lbu         $t8, 0x2CF($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2CF);
    // 0x8018633C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80186340: addiu       $a1, $a1, -0x490C
    ctx->r5 = ADD32(ctx->r5, -0X490C);
    // 0x80186344: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80186348: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018634C: sh          $t6, 0x352($v0)
    MEM_H(0X352, ctx->r2) = ctx->r14;
    // 0x80186350: jal         0x80172EC8
    // 0x80186354: sb          $t9, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r25;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80186354: sb          $t9, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r25;
    after_1:
    // 0x80186358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018635C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80186360: jr          $ra
    // 0x80186364: nop

    return;
    // 0x80186364: nop

;}
RECOMP_FUNC void func_ovl8_8037319C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037319C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803731A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803731A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x803731A8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x803731AC: jal         0x80373168
    // 0x803731B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_ovl8_80373168(rdram, ctx);
        goto after_0;
    // 0x803731B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x803731B4: bne         $v0, $zero, L_803731C4
    if (ctx->r2 != 0) {
        // 0x803731B8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803731C4;
    }
    // 0x803731B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x803731BC: b           L_80373204
    // 0x803731C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80373204;
    // 0x803731C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803731C4:
    // 0x803731C4: beql        $v0, $zero, L_80373204
    if (ctx->r2 == 0) {
        // 0x803731C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80373204;
    }
    goto skip_0;
    // 0x803731C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x803731CC: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_803731D0:
    // 0x803731D0: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803731D4: lw          $t9, 0xFC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XFC);
    // 0x803731D8: lh          $t6, 0xF8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XF8);
    // 0x803731DC: jalr        $t9
    // 0x803731E0: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803731E0: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_1:
    // 0x803731E4: bnel        $v0, $s1, L_803731F8
    if (ctx->r2 != ctx->r17) {
        // 0x803731E8: lw          $s0, 0x24($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X24);
            goto L_803731F8;
    }
    goto skip_1;
    // 0x803731E8: lw          $s0, 0x24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x803731EC: b           L_80373204
    // 0x803731F0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80373204;
    // 0x803731F0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x803731F4: lw          $s0, 0x24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X24);
L_803731F8:
    // 0x803731F8: bnel        $s0, $zero, L_803731D0
    if (ctx->r16 != 0) {
        // 0x803731FC: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_803731D0;
    }
    goto skip_2;
    // 0x803731FC: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x80373200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80373204:
    // 0x80373204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80373208: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037320C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80373210: jr          $ra
    // 0x80373214: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80373214: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnDataInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327B4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801327B8: lbu         $v0, 0x4AD1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD1);
    // 0x801327BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801327C0: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x801327C4: beq         $v0, $at, L_801327E4
    if (ctx->r2 == ctx->r1) {
        // 0x801327C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801327E4;
    }
    // 0x801327C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801327CC: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x801327D0: beq         $v0, $at, L_801327F4
    if (ctx->r2 == ctx->r1) {
        // 0x801327D4: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_801327F4;
    }
    // 0x801327D4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801327D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801327DC: b           L_801327FC
    // 0x801327E0: sw          $zero, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = 0;
        goto L_801327FC;
    // 0x801327E0: sw          $zero, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = 0;
L_801327E4:
    // 0x801327E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801327E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801327EC: b           L_801327FC
    // 0x801327F0: sw          $t6, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = ctx->r14;
        goto L_801327FC;
    // 0x801327F0: sw          $t6, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = ctx->r14;
L_801327F4:
    // 0x801327F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801327F8: sw          $t7, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = ctx->r15;
L_801327FC:
    // 0x801327FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132800: jal         0x80131B24
    // 0x80132804: sw          $zero, 0x3080($at)
    MEM_W(0X3080, ctx->r1) = 0;
    mnDataCheckSoundTestUnlocked(rdram, ctx);
        goto after_0;
    // 0x80132804: sw          $zero, 0x3080($at)
    MEM_W(0X3080, ctx->r1) = 0;
    after_0:
    // 0x80132808: beq         $v0, $zero, L_8013282C
    if (ctx->r2 == 0) {
        // 0x8013280C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8013282C;
    }
    // 0x8013280C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132810: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80132814: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132818: sw          $t8, 0x3084($at)
    MEM_W(0X3084, ctx->r1) = ctx->r24;
    // 0x8013281C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132820: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132824: b           L_8013283C
    // 0x80132828: sw          $t9, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->r25;
        goto L_8013283C;
    // 0x80132828: sw          $t9, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->r25;
L_8013282C:
    // 0x8013282C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132830: sw          $t0, 0x3084($at)
    MEM_W(0X3084, ctx->r1) = ctx->r8;
    // 0x80132834: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132838: sw          $zero, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = 0;
L_8013283C:
    // 0x8013283C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132840: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132844: sw          $zero, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = 0;
    // 0x80132848: addiu       $v0, $v0, 0x3094
    ctx->r2 = ADD32(ctx->r2, 0X3094);
    // 0x8013284C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80132850: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132854: sw          $zero, 0x308C($at)
    MEM_W(0X308C, ctx->r1) = 0;
    // 0x80132858: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8013285C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132860: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132864: addiu       $t2, $t1, 0x4650
    ctx->r10 = ADD32(ctx->r9, 0X4650);
    // 0x80132868: sw          $t2, 0x3098($at)
    MEM_W(0X3098, ctx->r1) = ctx->r10;
    // 0x8013286C: jr          $ra
    // 0x80132870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80132870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnPlayers1PTrainingMakeFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801339A4: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x801339A8: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x801339AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801339B0: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x801339B4: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x801339B8: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801339BC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801339C0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801339C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801339C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801339CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801339D0: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801339D4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801339D8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801339DC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801339E0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801339E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801339E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801339EC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801339F0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801339F4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801339F8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801339FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133A00: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133A04: jal         0x8000B93C
    // 0x80133A08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133A08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133A0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133A10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133A14: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133A18: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133A1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133A20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133A24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133A28: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133A2C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133A30: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80133A34: jal         0x80007080
    // 0x80133A38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133A38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133A3C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80133A40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133A44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80133A48: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80133A4C: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80133A50: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80133A54: lwc1        $f6, -0x7ACC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7ACC);
    // 0x80133A58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80133A5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133A60: sw          $t4, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r12;
    // 0x80133A64: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x80133A68: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80133A6C: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80133A70: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80133A74: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x80133A78: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80133A7C: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80133A80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133A84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80133A88: jr          $ra
    // 0x80133A8C: nop

    return;
    // 0x80133A8C: nop

;}
RECOMP_FUNC void ftMainUpdateShieldStatItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E36F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E36FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E3700: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E3704: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E3708: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E370C: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800E3710: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800E3714: jal         0x801727F4
    // 0x800E3718: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    itMainGetDamageOutput(rdram, ctx);
        goto after_0;
    // 0x800E3718: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E371C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800E3720: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E3724: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800E3728: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x800E372C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E3730: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800E3734: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800E3738: bgez        $t8, L_800E3748
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E373C: nop
    
            goto L_800E3748;
    }
    // 0x800E373C: nop

    // 0x800E3740: b           L_800E3748
    // 0x800E3744: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_800E3748;
    // 0x800E3744: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800E3748:
    // 0x800E3748: jal         0x8016F930
    // 0x800E374C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    itProcessSetHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x800E374C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_1:
    // 0x800E3750: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3754: lw          $t9, 0x274($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X274);
    // 0x800E3758: addiu       $a0, $s0, 0x27C
    ctx->r4 = ADD32(ctx->r16, 0X27C);
    // 0x800E375C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E3760: beql        $at, $zero, L_800E37BC
    if (ctx->r1 == 0) {
        // 0x800E3764: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_800E37BC;
    }
    goto skip_0;
    // 0x800E3764: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x800E3768: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E376C: sw          $v1, 0x274($s0)
    MEM_W(0X274, ctx->r16) = ctx->r3;
    // 0x800E3770: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800E3774: swc1        $f0, 0x27C($s0)
    MEM_W(0X27C, ctx->r16) = ctx->f0.u32l;
    // 0x800E3778: swc1        $f0, 0x280($s0)
    MEM_W(0X280, ctx->r16) = ctx->f0.u32l;
    // 0x800E377C: swc1        $f4, 0x278($s0)
    MEM_W(0X278, ctx->r16) = ctx->f4.u32l;
    // 0x800E3780: lw          $t0, 0x44($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X44);
    // 0x800E3784: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E3788: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800E378C: bne         $t0, $at, L_800E37A4
    if (ctx->r8 != ctx->r1) {
        // 0x800E3790: lw          $t1, 0x5C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X5C);
            goto L_800E37A4;
    }
    // 0x800E3790: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800E3794: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800E3798: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800E379C: b           L_800E37AC
    // 0x800E37A0: swc1        $f8, 0x284($s0)
    MEM_W(0X284, ctx->r16) = ctx->f8.u32l;
        goto L_800E37AC;
    // 0x800E37A0: swc1        $f8, 0x284($s0)
    MEM_W(0X284, ctx->r16) = ctx->f8.u32l;
L_800E37A4:
    // 0x800E37A4: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800E37A8: swc1        $f10, 0x284($s0)
    MEM_W(0X284, ctx->r16) = ctx->f10.u32l;
L_800E37AC:
    // 0x800E37AC: jal         0x80018EE0
    // 0x800E37B0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x800E37B0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800E37B4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800E37B8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_800E37BC:
    // 0x800E37BC: lw          $t3, 0x7CC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X7CC);
    // 0x800E37C0: lw          $t7, 0x7C8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C8);
    // 0x800E37C4: lw          $t5, 0x40($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X40);
    // 0x800E37C8: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800E37CC: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E37D0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800E37D4: beq         $at, $zero, L_800E3814
    if (ctx->r1 == 0) {
        // 0x800E37D8: sw          $t6, 0x7CC($s1)
        MEM_W(0X7CC, ctx->r17) = ctx->r14;
            goto L_800E3814;
    }
    // 0x800E37D8: sw          $t6, 0x7CC($s1)
    MEM_W(0X7CC, ctx->r17) = ctx->r14;
    // 0x800E37DC: sw          $v1, 0x7C8($s1)
    MEM_W(0X7C8, ctx->r17) = ctx->r3;
    // 0x800E37E0: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800E37E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800E37E8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800E37EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800E37F0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800E37F4: nop

    // 0x800E37F8: bc1fl       L_800E380C
    if (!c1cs) {
        // 0x800E37FC: sw          $t9, 0x7D0($s1)
        MEM_W(0X7D0, ctx->r17) = ctx->r25;
            goto L_800E380C;
    }
    goto skip_1;
    // 0x800E37FC: sw          $t9, 0x7D0($s1)
    MEM_W(0X7D0, ctx->r17) = ctx->r25;
    skip_1:
    // 0x800E3800: b           L_800E380C
    // 0x800E3804: sw          $t8, 0x7D0($s1)
    MEM_W(0X7D0, ctx->r17) = ctx->r24;
        goto L_800E380C;
    // 0x800E3804: sw          $t8, 0x7D0($s1)
    MEM_W(0X7D0, ctx->r17) = ctx->r24;
    // 0x800E3808: sw          $t9, 0x7D0($s1)
    MEM_W(0X7D0, ctx->r17) = ctx->r25;
L_800E380C:
    // 0x800E380C: lbu         $t0, 0x15($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X15);
    // 0x800E3810: sw          $t0, 0x7D4($s1)
    MEM_W(0X7D4, ctx->r17) = ctx->r8;
L_800E3814:
    // 0x800E3814: lw          $t1, 0x8F4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8F4);
    // 0x800E3818: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x800E381C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E3820: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800E3824: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800E3828: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800E382C: jal         0x800F0EB4
    // 0x800E3830: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    gmCollisionGetItemAttackShieldPosition(rdram, ctx);
        goto after_3;
    // 0x800E3830: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_3:
    // 0x800E3834: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800E3838: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800E383C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E3840: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x800E3844: jal         0x80100BF0
    // 0x800E3848: addu        $a1, $t3, $v1
    ctx->r5 = ADD32(ctx->r11, ctx->r3);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_4;
    // 0x800E3848: addu        $a1, $t3, $v1
    ctx->r5 = ADD32(ctx->r11, ctx->r3);
    after_4:
    // 0x800E384C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E3850: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E3854: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E3858: jr          $ra
    // 0x800E385C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E385C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gmCameraLookAtFuncMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D250: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8010D254: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8010D258: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x8010D25C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8010D260: lw          $s1, 0xC($v1)
    ctx->r17 = MEM_W(ctx->r3, 0XC);
    // 0x8010D264: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8010D268: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8010D26C: addiu       $t6, $s1, 0x40
    ctx->r14 = ADD32(ctx->r17, 0X40);
    // 0x8010D270: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8010D274: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8010D278: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8010D27C: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8010D280: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x8010D284: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8010D288: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x8010D28C: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x8010D290: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8010D294: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8010D298: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x8010D29C: addiu       $s2, $s2, 0x6FA8
    ctx->r18 = ADD32(ctx->r18, 0X6FA8);
    // 0x8010D2A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8010D2A4: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8010D2A8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x8010D2AC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8010D2B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010D2B4: jal         0x8001B248
    // 0x8010D2B8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixPerspFastF(rdram, ctx);
        goto after_0;
    // 0x8010D2B8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8010D2BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010D2C0: jal         0x80019C70
    // 0x8010D2C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8010D2C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8010D2C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8010D2CC: sw          $s1, 0x6FA0($at)
    MEM_W(0X6FA0, ctx->r1) = ctx->r17;
    // 0x8010D2D0: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8010D2D4: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x8010D2D8: lw          $a2, 0x3C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X3C);
    // 0x8010D2DC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8010D2E0: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8010D2E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010D2E8: addiu       $a1, $a1, 0x1548
    ctx->r5 = ADD32(ctx->r5, 0X1548);
    // 0x8010D2EC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8010D2F0: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8010D2F4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8010D2F8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8010D2FC: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8010D300: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8010D304: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8010D308: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8010D30C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8010D310: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8010D314: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8010D318: jal         0x8001A744
    // 0x8010D31C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    syMatrixLookAtReflectF(rdram, ctx);
        goto after_2;
    // 0x8010D31C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8010D320: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010D324: addiu       $a2, $a2, 0x1470
    ctx->r6 = ADD32(ctx->r6, 0X1470);
    // 0x8010D328: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8010D32C: jal         0x80034980
    // 0x8010D330: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    guMtxCatF(rdram, ctx);
        goto after_3;
    // 0x8010D330: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x8010D334: jal         0x8010D154
    // 0x8010D338: nop

    gmCameraGetMatrixMax(rdram, ctx);
        goto after_4;
    // 0x8010D338: nop

    after_4:
    // 0x8010D33C: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x8010D340: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010D344: nop

    // 0x8010D348: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8010D34C: nop

    // 0x8010D350: bc1f        L_8010D3FC
    if (!c1cs) {
        // 0x8010D354: nop
    
            goto L_8010D3FC;
    }
    // 0x8010D354: nop

    // 0x8010D358: div.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8010D35C: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8010D360: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x8010D364: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x8010D368: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8010D36C: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8010D370: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010D374: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8010D378: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8010D37C: jal         0x8001B248
    // 0x8010D380: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    syMatrixPerspFastF(rdram, ctx);
        goto after_5;
    // 0x8010D380: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8010D384: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010D388: jal         0x80019C70
    // 0x8010D38C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syMatrixF2L(rdram, ctx);
        goto after_6;
    // 0x8010D38C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8010D390: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8010D394: sw          $s1, 0x6FA0($at)
    MEM_W(0X6FA0, ctx->r1) = ctx->r17;
    // 0x8010D398: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8010D39C: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x8010D3A0: lw          $a2, 0x3C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X3C);
    // 0x8010D3A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8010D3A8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8010D3AC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010D3B0: addiu       $a1, $a1, 0x1548
    ctx->r5 = ADD32(ctx->r5, 0X1548);
    // 0x8010D3B4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8010D3B8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8010D3BC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8010D3C0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8010D3C4: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8010D3C8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8010D3CC: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8010D3D0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8010D3D4: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8010D3D8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8010D3DC: lwc1        $f6, 0x5C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8010D3E0: jal         0x8001A744
    // 0x8010D3E4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    syMatrixLookAtReflectF(rdram, ctx);
        goto after_7;
    // 0x8010D3E4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8010D3E8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010D3EC: addiu       $a2, $a2, 0x1470
    ctx->r6 = ADD32(ctx->r6, 0X1470);
    // 0x8010D3F0: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8010D3F4: jal         0x80034980
    // 0x8010D3F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    guMtxCatF(rdram, ctx);
        goto after_8;
    // 0x8010D3F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
L_8010D3FC:
    // 0x8010D3FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010D400: addiu       $a0, $a0, 0x1470
    ctx->r4 = ADD32(ctx->r4, 0X1470);
    // 0x8010D404: jal         0x80019C70
    // 0x8010D408: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    syMatrixF2L(rdram, ctx);
        goto after_9;
    // 0x8010D408: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    after_9:
    // 0x8010D40C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8010D410: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8010D414: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8010D418: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8010D41C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x8010D420: jr          $ra
    // 0x8010D424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8010D424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void scExplainMakeSpecialMoveRGB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018DB48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018DB4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018DB50: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018DB54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DB58: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018DB5C: jal         0x80009968
    // 0x8018DB60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018DB60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DB64: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018DB6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DB70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DB74: addiu       $a1, $a1, -0x27F8
    ctx->r5 = ADD32(ctx->r5, -0X27F8);
    // 0x8018DB78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DB7C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018DB80: jal         0x80009DF4
    // 0x8018DB84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018DB84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DB88: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DB8C: lw          $t7, -0x1620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1620);
    // 0x8018DB90: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8018DB94: addiu       $t8, $t8, 0x5E40
    ctx->r24 = ADD32(ctx->r24, 0X5E40);
    // 0x8018DB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB9C: jal         0x800092D0
    // 0x8018DBA0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018DBA0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8018DBA4: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8018DBA8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8018DBAC: jal         0x80008CC0
    // 0x8018DBB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8018DBB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8018DBB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DBB8: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x8018DBBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018DBC0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8018DBC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018DBC8: jr          $ra
    // 0x8018DBCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018DBCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftDonkeySpecialNLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015B08C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B090: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015B094: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015B098: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015B09C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8015B0A0: nop

    // 0x8015B0A4: bc1fl       L_8015B17C
    if (!c1cs) {
        // 0x8015B0A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015B17C;
    }
    goto skip_0;
    // 0x8015B0A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015B0AC: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8015B0B0: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8015B0B4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8015B0B8: nop

    // 0x8015B0BC: bc1fl       L_8015B17C
    if (!c1cs) {
        // 0x8015B0C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015B17C;
    }
    goto skip_1;
    // 0x8015B0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8015B0C4: lw          $t7, 0xB20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB20);
    // 0x8015B0C8: beql        $t7, $zero, L_8015B120
    if (ctx->r15 == 0) {
        // 0x8015B0CC: lw          $t0, 0xB24($v0)
        ctx->r8 = MEM_W(ctx->r2, 0XB24);
            goto L_8015B120;
    }
    goto skip_2;
    // 0x8015B0CC: lw          $t0, 0xB24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB24);
    skip_2:
    // 0x8015B0D0: lw          $v1, 0xADC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XADC);
    // 0x8015B0D4: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x8015B0D8: beq         $at, $zero, L_8015B11C
    if (ctx->r1 == 0) {
        // 0x8015B0DC: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8015B11C;
    }
    // 0x8015B0DC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8015B0E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8015B0E4: bne         $t8, $at, L_8015B11C
    if (ctx->r24 != ctx->r1) {
        // 0x8015B0E8: sw          $t8, 0xADC($v0)
        MEM_W(0XADC, ctx->r2) = ctx->r24;
            goto L_8015B11C;
    }
    // 0x8015B0E8: sw          $t8, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = ctx->r24;
    // 0x8015B0EC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x8015B0F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8015B0F4: jal         0x8000BB04
    // 0x8015B0F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    gcSetAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x8015B0F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015B0FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015B100: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8015B104: jal         0x800E9814
    // 0x8015B108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_1;
    // 0x8015B108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8015B10C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B110: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8015B114: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015B118: sw          $v1, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = ctx->r3;
L_8015B11C:
    // 0x8015B11C: lw          $t0, 0xB24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB24);
L_8015B120:
    // 0x8015B120: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8015B124: beql        $t0, $zero, L_8015B140
    if (ctx->r8 == 0) {
        // 0x8015B128: lw          $t1, 0xB18($v0)
        ctx->r9 = MEM_W(ctx->r2, 0XB18);
            goto L_8015B140;
    }
    goto skip_3;
    // 0x8015B128: lw          $t1, 0xB18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XB18);
    skip_3:
    // 0x8015B12C: jal         0x800DEE54
    // 0x8015B130: nop

    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_2;
    // 0x8015B130: nop

    after_2:
    // 0x8015B134: b           L_8015B17C
    // 0x8015B138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015B17C;
    // 0x8015B138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B13C: lw          $t1, 0xB18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XB18);
L_8015B140:
    // 0x8015B140: beql        $t1, $zero, L_8015B178
    if (ctx->r9 == 0) {
        // 0x8015B144: sw          $v1, 0xB20($v0)
        MEM_W(0XB20, ctx->r2) = ctx->r3;
            goto L_8015B178;
    }
    goto skip_4;
    // 0x8015B144: sw          $v1, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r3;
    skip_4:
    // 0x8015B148: lw          $t2, 0x14C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14C);
    // 0x8015B14C: bne         $v1, $t2, L_8015B164
    if (ctx->r3 != ctx->r10) {
        // 0x8015B150: nop
    
            goto L_8015B164;
    }
    // 0x8015B150: nop

    // 0x8015B154: jal         0x8015B598
    // 0x8015B158: nop

    ftDonkeySpecialAirNEndSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015B158: nop

    after_3:
    // 0x8015B15C: b           L_8015B17C
    // 0x8015B160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015B17C;
    // 0x8015B160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015B164:
    // 0x8015B164: jal         0x8015B51C
    // 0x8015B168: nop

    ftDonkeySpecialNEndSetStatus(rdram, ctx);
        goto after_4;
    // 0x8015B168: nop

    after_4:
    // 0x8015B16C: b           L_8015B17C
    // 0x8015B170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015B17C;
    // 0x8015B170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B174: sw          $v1, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r3;
L_8015B178:
    // 0x8015B178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015B17C:
    // 0x8015B17C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015B180: jr          $ra
    // 0x8015B184: nop

    return;
    // 0x8015B184: nop

;}
RECOMP_FUNC void ftParamUpdateAnimKeys(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E82B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800E82BC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800E82C0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800E82C4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800E82C8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800E82CC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800E82D0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800E82D4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800E82D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E82DC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800E82E0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800E82E4: lw          $s6, 0x84($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X84);
    // 0x800E82E8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800E82EC: lw          $t6, 0x28($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X28);
    // 0x800E82F0: addiu       $s3, $s6, 0x8E8
    ctx->r19 = ADD32(ctx->r22, 0X8E8);
    // 0x800E82F4: beql        $t6, $at, L_800E8420
    if (ctx->r14 == ctx->r1) {
        // 0x800E82F8: lw          $t7, 0x18C($s6)
        ctx->r15 = MEM_W(ctx->r22, 0X18C);
            goto L_800E8420;
    }
    goto skip_0;
    // 0x800E82F8: lw          $t7, 0x18C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X18C);
    skip_0:
    // 0x800E82FC: lw          $t7, 0x18C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X18C);
    // 0x800E8300: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E8304: addiu       $s5, $zero, 0x25
    ctx->r21 = ADD32(0, 0X25);
    // 0x800E8308: sll         $t9, $t7, 29
    ctx->r25 = S32(ctx->r15 << 29);
    // 0x800E830C: bgez        $t9, L_800E83A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E8310: nop
    
            goto L_800E83A4;
    }
    // 0x800E8310: nop

    // 0x800E8314: lw          $t0, 0x9C8($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X9C8);
    // 0x800E8318: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E831C: addiu       $s5, $zero, 0x25
    ctx->r21 = ADD32(0, 0X25);
    // 0x800E8320: lw          $s4, 0x324($t0)
    ctx->r20 = MEM_W(ctx->r8, 0X324);
L_800E8324:
    // 0x800E8324: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x800E8328: beql        $s1, $zero, L_800E8390
    if (ctx->r17 == 0) {
        // 0x800E832C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E8390;
    }
    goto skip_1;
    // 0x800E832C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800E8330: lw          $t1, 0x198($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X198);
    // 0x800E8334: sll         $t3, $t1, 28
    ctx->r11 = S32(ctx->r9 << 28);
    // 0x800E8338: bgez        $t3, L_800E8350
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800E833C: nop
    
            goto L_800E8350;
    }
    // 0x800E833C: nop

    // 0x800E8340: jal         0x8000BFE8
    // 0x800E8344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x800E8344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800E8348: b           L_800E835C
    // 0x800E834C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800E835C;
    // 0x800E834C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800E8350:
    // 0x800E8350: jal         0x800EC238
    // 0x800E8354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftAnimParseDObjFigatree(rdram, ctx);
        goto after_1;
    // 0x800E8354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800E8358: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800E835C:
    // 0x800E835C: jal         0x800C9488
    // 0x800E8360: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    lbCommonPlayTranslateScaledDObjAnim(rdram, ctx);
        goto after_2;
    // 0x800E8360: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x800E8364: lw          $s0, 0x80($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X80);
    // 0x800E8368: beql        $s0, $zero, L_800E8390
    if (ctx->r16 == 0) {
        // 0x800E836C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E8390;
    }
    goto skip_2;
    // 0x800E836C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
L_800E8370:
    // 0x800E8370: jal         0x8000CF6C
    // 0x800E8374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcParseMObjMatAnimJoint(rdram, ctx);
        goto after_3;
    // 0x800E8374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800E8378: jal         0x8000DA40
    // 0x800E837C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayMObjMatAnim(rdram, ctx);
        goto after_4;
    // 0x800E837C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800E8380: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800E8384: bne         $s0, $zero, L_800E8370
    if (ctx->r16 != 0) {
        // 0x800E8388: nop
    
            goto L_800E8370;
    }
    // 0x800E8388: nop

    // 0x800E838C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800E8390:
    // 0x800E8390: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800E8394: bne         $s2, $s5, L_800E8324
    if (ctx->r18 != ctx->r21) {
        // 0x800E8398: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_800E8324;
    }
    // 0x800E8398: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x800E839C: b           L_800E84EC
    // 0x800E83A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800E84EC;
    // 0x800E83A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800E83A4:
    // 0x800E83A4: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x800E83A8: beql        $s1, $zero, L_800E840C
    if (ctx->r17 == 0) {
        // 0x800E83AC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E840C;
    }
    goto skip_3;
    // 0x800E83AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x800E83B0: lw          $t4, 0x198($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X198);
    // 0x800E83B4: sll         $t6, $t4, 28
    ctx->r14 = S32(ctx->r12 << 28);
    // 0x800E83B8: bgez        $t6, L_800E83D0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E83BC: nop
    
            goto L_800E83D0;
    }
    // 0x800E83BC: nop

    // 0x800E83C0: jal         0x8000BFE8
    // 0x800E83C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_5;
    // 0x800E83C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800E83C8: b           L_800E83D8
    // 0x800E83CC: nop

        goto L_800E83D8;
    // 0x800E83CC: nop

L_800E83D0:
    // 0x800E83D0: jal         0x800EC238
    // 0x800E83D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftAnimParseDObjFigatree(rdram, ctx);
        goto after_6;
    // 0x800E83D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_800E83D8:
    // 0x800E83D8: jal         0x8000CCBC
    // 0x800E83DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_7;
    // 0x800E83DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800E83E0: lw          $s0, 0x80($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X80);
    // 0x800E83E4: beql        $s0, $zero, L_800E840C
    if (ctx->r16 == 0) {
        // 0x800E83E8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E840C;
    }
    goto skip_4;
    // 0x800E83E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
L_800E83EC:
    // 0x800E83EC: jal         0x8000CF6C
    // 0x800E83F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcParseMObjMatAnimJoint(rdram, ctx);
        goto after_8;
    // 0x800E83F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800E83F4: jal         0x8000DA40
    // 0x800E83F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayMObjMatAnim(rdram, ctx);
        goto after_9;
    // 0x800E83F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800E83FC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800E8400: bne         $s0, $zero, L_800E83EC
    if (ctx->r16 != 0) {
        // 0x800E8404: nop
    
            goto L_800E83EC;
    }
    // 0x800E8404: nop

    // 0x800E8408: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800E840C:
    // 0x800E840C: bne         $s2, $s5, L_800E83A4
    if (ctx->r18 != ctx->r21) {
        // 0x800E8410: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800E83A4;
    }
    // 0x800E8410: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800E8414: b           L_800E84EC
    // 0x800E8418: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800E84EC;
    // 0x800E8418: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800E841C: lw          $t7, 0x18C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X18C);
L_800E8420:
    // 0x800E8420: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E8424: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E8428: sll         $t9, $t7, 29
    ctx->r25 = S32(ctx->r15 << 29);
    // 0x800E842C: bgez        $t9, L_800E84A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E8430: addiu       $s5, $zero, 0x25
        ctx->r21 = ADD32(0, 0X25);
            goto L_800E84A0;
    }
    // 0x800E8430: addiu       $s5, $zero, 0x25
    ctx->r21 = ADD32(0, 0X25);
    // 0x800E8434: lw          $t0, 0x9C8($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X9C8);
    // 0x800E8438: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E843C: lwc1        $f22, -0x15C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X15C);
    // 0x800E8440: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E8444: addiu       $s5, $zero, 0x25
    ctx->r21 = ADD32(0, 0X25);
    // 0x800E8448: lw          $s0, 0x324($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X324);
L_800E844C:
    // 0x800E844C: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x800E8450: beql        $s1, $zero, L_800E848C
    if (ctx->r17 == 0) {
        // 0x800E8454: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E848C;
    }
    goto skip_5;
    // 0x800E8454: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_5:
    // 0x800E8458: lw          $v0, 0x84($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X84);
    // 0x800E845C: beql        $v0, $zero, L_800E848C
    if (ctx->r2 == 0) {
        // 0x800E8460: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E848C;
    }
    goto skip_6;
    // 0x800E8460: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x800E8464: lbu         $t1, 0xE($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XE);
    // 0x800E8468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E846C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E8470: beql        $t1, $zero, L_800E848C
    if (ctx->r9 == 0) {
        // 0x800E8474: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E848C;
    }
    goto skip_7;
    // 0x800E8474: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_7:
    // 0x800E8478: lwc1        $f20, 0x74($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800E847C: jal         0x800C9488
    // 0x800E8480: swc1        $f22, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f22.u32l;
    lbCommonPlayTranslateScaledDObjAnim(rdram, ctx);
        goto after_10;
    // 0x800E8480: swc1        $f22, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f22.u32l;
    after_10:
    // 0x800E8484: swc1        $f20, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f20.u32l;
    // 0x800E8488: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800E848C:
    // 0x800E848C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800E8490: bne         $s2, $s5, L_800E844C
    if (ctx->r18 != ctx->r21) {
        // 0x800E8494: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800E844C;
    }
    // 0x800E8494: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800E8498: b           L_800E84EC
    // 0x800E849C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800E84EC;
    // 0x800E849C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800E84A0:
    // 0x800E84A0: lwc1        $f22, -0x158($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X158);
L_800E84A4:
    // 0x800E84A4: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x800E84A8: beql        $s1, $zero, L_800E84E0
    if (ctx->r17 == 0) {
        // 0x800E84AC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E84E0;
    }
    goto skip_8;
    // 0x800E84AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_8:
    // 0x800E84B0: lw          $v0, 0x84($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X84);
    // 0x800E84B4: beql        $v0, $zero, L_800E84E0
    if (ctx->r2 == 0) {
        // 0x800E84B8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E84E0;
    }
    goto skip_9;
    // 0x800E84B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_9:
    // 0x800E84BC: lbu         $t2, 0xE($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XE);
    // 0x800E84C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E84C4: beql        $t2, $zero, L_800E84E0
    if (ctx->r10 == 0) {
        // 0x800E84C8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E84E0;
    }
    goto skip_10;
    // 0x800E84C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_10:
    // 0x800E84CC: lwc1        $f20, 0x74($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800E84D0: jal         0x8000CCBC
    // 0x800E84D4: swc1        $f22, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f22.u32l;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_11;
    // 0x800E84D4: swc1        $f22, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f22.u32l;
    after_11:
    // 0x800E84D8: swc1        $f20, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f20.u32l;
    // 0x800E84DC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800E84E0:
    // 0x800E84E0: bne         $s2, $s5, L_800E84A4
    if (ctx->r18 != ctx->r21) {
        // 0x800E84E4: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800E84A4;
    }
    // 0x800E84E4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800E84E8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800E84EC:
    // 0x800E84EC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E84F0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800E84F4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E84F8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800E84FC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800E8500: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800E8504: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800E8508: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800E850C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800E8510: jr          $ra
    // 0x800E8514: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800E8514: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftDonkeySpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B5EC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015B5F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8015B5F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8015B5F8: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015B5FC: bnel        $t6, $at, L_8015B610
    if (ctx->r14 != ctx->r1) {
        // 0x8015B600: sw          $zero, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = 0;
            goto L_8015B610;
    }
    goto skip_0;
    // 0x8015B600: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    skip_0:
    // 0x8015B604: b           L_8015B610
    // 0x8015B608: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
        goto L_8015B610;
    // 0x8015B608: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x8015B60C: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
L_8015B610:
    // 0x8015B610: sw          $zero, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = 0;
    // 0x8015B614: jr          $ra
    // 0x8015B618: sw          $zero, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = 0;
    return;
    // 0x8015B618: sw          $zero, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = 0;
;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNLoopSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157B14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80157B18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157B1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80157B20: jal         0x800DEE98
    // 0x80157B24: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80157B24: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80157B28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80157B2C: addiu       $t7, $zero, 0x4002
    ctx->r15 = ADD32(0, 0X4002);
    // 0x80157B30: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x80157B34: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80157B38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80157B3C: jal         0x800E6F24
    // 0x80157B40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80157B40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80157B44: jal         0x80157AD4
    // 0x80157B48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyDonkeySpecialNLoopSetProcDamageAnimSpeed(rdram, ctx);
        goto after_2;
    // 0x80157B48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80157B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157B50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80157B54: jr          $ra
    // 0x80157B58: nop

    return;
    // 0x80157B58: nop

;}
RECOMP_FUNC void ftFoxSpecialLwLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CCE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015CCE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015CCE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015CCEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015CCF0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015CCF4: jal         0x8015CBA4
    // 0x8015CCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialLwUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x8015CCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015CCFC: jal         0x8015CB80
    // 0x8015CD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialLwCheckSetRelease(rdram, ctx);
        goto after_1;
    // 0x8015CD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8015CD04: jal         0x8015CBD4
    // 0x8015CD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialLwDecReleaseLag(rdram, ctx);
        goto after_2;
    // 0x8015CD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8015CD0C: lw          $t7, 0xB18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB18);
    // 0x8015CD10: bgtzl       $t7, L_8015CD4C
    if (SIGNED(ctx->r15) > 0) {
        // 0x8015CD14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015CD4C;
    }
    goto skip_0;
    // 0x8015CD14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8015CD18: lw          $t8, 0xB20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB20);
    // 0x8015CD1C: beql        $t8, $zero, L_8015CD4C
    if (ctx->r24 == 0) {
        // 0x8015CD20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015CD4C;
    }
    goto skip_1;
    // 0x8015CD20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8015CD24: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x8015CD28: bne         $t9, $zero, L_8015CD40
    if (ctx->r25 != 0) {
        // 0x8015CD2C: nop
    
            goto L_8015CD40;
    }
    // 0x8015CD2C: nop

    // 0x8015CD30: jal         0x8015D180
    // 0x8015CD34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialLwEndSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015CD34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8015CD38: b           L_8015CD4C
    // 0x8015CD3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8015CD4C;
    // 0x8015CD3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015CD40:
    // 0x8015CD40: jal         0x8015D1B0
    // 0x8015CD44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialAirLwEndSetStatus(rdram, ctx);
        goto after_4;
    // 0x8015CD44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8015CD48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015CD4C:
    // 0x8015CD4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015CD50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015CD54: jr          $ra
    // 0x8015CD58: nop

    return;
    // 0x8015CD58: nop

;}
RECOMP_FUNC void gcSetCameraMatrixMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017830: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017834: jr          $ra
    // 0x80017838: sw          $a0, 0x70A8($at)
    MEM_W(0X70A8, ctx->r1) = ctx->r4;
    return;
    // 0x80017838: sw          $a0, 0x70A8($at)
    MEM_W(0X70A8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void ftPikachuSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151C18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151C1C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151C20: jal         0x800DDE84
    // 0x80151C24: addiu       $a1, $a1, 0x1CB0
    ctx->r5 = ADD32(ctx->r5, 0X1CB0);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80151C24: addiu       $a1, $a1, 0x1CB0
    ctx->r5 = ADD32(ctx->r5, 0X1CB0);
    after_0:
    // 0x80151C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151C30: jr          $ra
    // 0x80151C34: nop

    return;
    // 0x80151C34: nop

;}
RECOMP_FUNC void ftParamResetFighterColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E98B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E98B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E98B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E98BC: jal         0x800E9838
    // 0x800E98C0: addiu       $a0, $v0, 0xA28
    ctx->r4 = ADD32(ctx->r2, 0XA28);
    ftParamResetColAnim(rdram, ctx);
        goto after_0;
    // 0x800E98C0: addiu       $a0, $v0, 0xA28
    ctx->r4 = ADD32(ctx->r2, 0XA28);
    after_0:
    // 0x800E98C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E98C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E98CC: jr          $ra
    // 0x800E98D0: nop

    return;
    // 0x800E98D0: nop

;}
RECOMP_FUNC void itRShellFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A74C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A754: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017A758: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8017A75C: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x8017A760: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8017A764: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8017A768: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8017A76C: jal         0x80172558
    // 0x8017A770: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017A770: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8017A774: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A778: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017A77C: lbu         $v0, 0x350($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X350);
    // 0x8017A780: bnel        $v0, $zero, L_8017A7A4
    if (ctx->r2 != 0) {
        // 0x8017A784: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8017A7A4;
    }
    goto skip_0;
    // 0x8017A784: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x8017A788: jal         0x8017279C
    // 0x8017A78C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8017A78C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8017A790: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A794: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017A798: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x8017A79C: sb          $t7, 0x350($a3)
    MEM_B(0X350, ctx->r7) = ctx->r15;
    // 0x8017A7A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8017A7A4:
    // 0x8017A7A4: beq         $v0, $at, L_8017A7B0
    if (ctx->r2 == ctx->r1) {
        // 0x8017A7A8: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8017A7B0;
    }
    // 0x8017A7A8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8017A7AC: sb          $t8, 0x350($a3)
    MEM_B(0X350, ctx->r7) = ctx->r24;
L_8017A7B0:
    // 0x8017A7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A7B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017A7B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017A7BC: jr          $ra
    // 0x8017A7C0: nop

    return;
    // 0x8017A7C0: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateItemDisplaySprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E90C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E910: addiu       $a0, $a0, 0xB58
    ctx->r4 = ADD32(ctx->r4, 0XB58);
    // 0x8018E914: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8018E918: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8018E91C: lw          $t8, 0x28($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X28);
    // 0x8018E920: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8018E924: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018E928: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8018E92C: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x8018E930: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x8018E934: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8018E938: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x8018E93C: addiu       $t6, $t2, 0x3C
    ctx->r14 = ADD32(ctx->r10, 0X3C);
L_8018E940:
    // 0x8018E940: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8018E944: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8018E948: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8018E94C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8018E950: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x8018E954: sw          $t3, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r11;
    // 0x8018E958: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x8018E95C: bne         $t2, $t6, L_8018E940
    if (ctx->r10 != ctx->r14) {
        // 0x8018E960: sw          $t4, 0xC($t5)
        MEM_W(0XC, ctx->r13) = ctx->r12;
            goto L_8018E940;
    }
    // 0x8018E960: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x8018E964: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8018E968: addiu       $t9, $zero, 0x124
    ctx->r25 = ADD32(0, 0X124);
    // 0x8018E96C: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
    // 0x8018E970: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8018E974: sw          $t3, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r11;
    // 0x8018E978: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x8018E97C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8018E980: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8018E984: nop

    // 0x8018E988: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E98C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8018E990: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x8018E994: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8018E998: nop

    // 0x8018E99C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018E9A0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8018E9A4: jr          $ra
    // 0x8018E9A8: swc1        $f10, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f10.u32l;
    return;
    // 0x8018E9A8: swc1        $f10, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_ovl13_80131BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BCC: jr          $ra
    // 0x80131BD0: nop

    return;
    // 0x80131BD0: nop

;}
RECOMP_FUNC void ftCommonKneeBendProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F2A8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013F2AC: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8013F2B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013F2B4: lwc1        $f4, 0xB1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x8013F2B8: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8013F2BC: lw          $t7, 0xB20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB20);
    // 0x8013F2C0: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x8013F2C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013F2C8: bne         $t7, $at, L_8013F304
    if (ctx->r15 != ctx->r1) {
        // 0x8013F2CC: swc1        $f8, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
            goto L_8013F304;
    }
    // 0x8013F2CC: swc1        $f8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
    // 0x8013F2D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8013F2D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013F2D8: lwc1        $f16, 0xB1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x8013F2DC: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8013F2E0: nop

    // 0x8013F2E4: bc1fl       L_8013F308
    if (!c1cs) {
        // 0x8013F2E8: lwc1        $f18, 0xB1C($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
            goto L_8013F308;
    }
    goto skip_0;
    // 0x8013F2E8: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
    skip_0:
    // 0x8013F2EC: lhu         $t8, 0x1C0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1C0);
    // 0x8013F2F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013F2F4: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8013F2F8: beql        $t9, $zero, L_8013F308
    if (ctx->r25 == 0) {
        // 0x8013F2FC: lwc1        $f18, 0xB1C($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
            goto L_8013F308;
    }
    goto skip_1;
    // 0x8013F2FC: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
    skip_1:
    // 0x8013F300: sw          $t0, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = ctx->r8;
L_8013F304:
    // 0x8013F304: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
L_8013F308:
    // 0x8013F308: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8013F30C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x8013F310: nop

    // 0x8013F314: bc1fl       L_8013F328
    if (!c1cs) {
        // 0x8013F318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F328;
    }
    goto skip_2;
    // 0x8013F318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8013F31C: jal         0x8013F880
    // 0x8013F320: nop

    ftCommonJumpSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013F320: nop

    after_0:
    // 0x8013F324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F328:
    // 0x8013F328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F32C: jr          $ra
    // 0x8013F330: nop

    return;
    // 0x8013F330: nop

;}
RECOMP_FUNC void scAutoDemoFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D6DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D6E4: jal         0x8018D134
    // 0x8018D6E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    scAutoDemoDetectExit(rdram, ctx);
        goto after_0;
    // 0x8018D6E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D6EC: jal         0x8018D674
    // 0x8018D6F0: nop

    scAutoDemoUpdateFocus(rdram, ctx);
        goto after_1;
    // 0x8018D6F0: nop

    after_1:
    // 0x8018D6F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D6F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D6FC: jr          $ra
    // 0x8018D700: nop

    return;
    // 0x8018D700: nop

;}
RECOMP_FUNC void func_ovl8_80375E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80375E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375E10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80375E14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80375E18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80375E1C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80375E20: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80375E24: lh          $t7, 0x50($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X50);
    // 0x80375E28: jalr        $t9
    // 0x80375E2C: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80375E2C: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    after_0:
    // 0x80375E30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80375E34: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    // 0x80375E38: jal         0x80375B8C
    // 0x80375E3C: lhu         $a2, 0x2A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2A);
    func_ovl8_80375B8C(rdram, ctx);
        goto after_1;
    // 0x80375E3C: lhu         $a2, 0x2A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2A);
    after_1:
    // 0x80375E40: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80375E44: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80375E48: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80375E4C: sw          $t8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r24;
    // 0x80375E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80375E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80375E58: jr          $ra
    // 0x80375E5C: nop

    return;
    // 0x80375E5C: nop

;}
RECOMP_FUNC void lbParticleGeneratorFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2C4C: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x800D2C50: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x800D2C54: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800D2C58: lw          $s0, 0x639C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X639C);
    // 0x800D2C5C: sw          $s4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r20;
    // 0x800D2C60: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800D2C64: addiu       $s4, $s4, 0x6458
    ctx->r20 = ADD32(ctx->r20, 0X6458);
    // 0x800D2C68: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x800D2C6C: sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // 0x800D2C70: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x800D2C74: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x800D2C78: sdc1        $f30, 0x70($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X70, ctx->r29);
    // 0x800D2C7C: sdc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X68, ctx->r29);
    // 0x800D2C80: sdc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X60, ctx->r29);
    // 0x800D2C84: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x800D2C88: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x800D2C8C: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x800D2C90: sw          $a0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r4;
    // 0x800D2C94: beq         $s0, $zero, L_800D3504
    if (ctx->r16 == 0) {
        // 0x800D2C98: sw          $zero, 0x0($s4)
        MEM_W(0X0, ctx->r20) = 0;
            goto L_800D3504;
    }
    // 0x800D2C98: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x800D2C9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2CA0: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800D2CA4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800D2CA8: addiu       $s3, $s3, 0x6440
    ctx->r19 = ADD32(ctx->r19, 0X6440);
    // 0x800D2CAC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800D2CB0: addiu       $s1, $sp, 0x11C
    ctx->r17 = ADD32(ctx->r29, 0X11C);
    // 0x800D2CB4: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
L_800D2CB8:
    // 0x800D2CB8: lbu         $t3, 0x9($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X9);
    // 0x800D2CBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D2CC0: lw          $t2, 0x7C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X7C);
    // 0x800D2CC4: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x800D2CC8: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x800D2CCC: sllv        $t8, $t6, $t5
    ctx->r24 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800D2CD0: and         $t9, $t2, $t8
    ctx->r25 = ctx->r10 & ctx->r24;
    // 0x800D2CD4: beql        $t9, $zero, L_800D2CEC
    if (ctx->r25 == 0) {
        // 0x800D2CD8: lhu         $t1, 0x6($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X6);
            goto L_800D2CEC;
    }
    goto skip_0;
    // 0x800D2CD8: lhu         $t1, 0x6($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6);
    skip_0:
    // 0x800D2CDC: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x800D2CE0: b           L_800D34FC
    // 0x800D2CE4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
        goto L_800D34FC;
    // 0x800D2CE4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800D2CE8: lhu         $t1, 0x6($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6);
L_800D2CEC:
    // 0x800D2CEC: andi        $t0, $t1, 0x800
    ctx->r8 = ctx->r9 & 0X800;
    // 0x800D2CF0: beql        $t0, $zero, L_800D2D08
    if (ctx->r8 == 0) {
        // 0x800D2CF4: lwc1        $f0, 0x40($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
            goto L_800D2D08;
    }
    goto skip_1;
    // 0x800D2CF4: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    skip_1:
    // 0x800D2CF8: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x800D2CFC: b           L_800D34FC
    // 0x800D2D00: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
        goto L_800D34FC;
    // 0x800D2D00: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800D2D04: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
L_800D2D08:
    // 0x800D2D08: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800D2D0C: nop

    // 0x800D2D10: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800D2D14: nop

    // 0x800D2D18: bc1f        L_800D2D30
    if (!c1cs) {
        // 0x800D2D1C: nop
    
            goto L_800D2D30;
    }
    // 0x800D2D1C: nop

    // 0x800D2D20: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800D2D24: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800D2D28: b           L_800D2D54
    // 0x800D2D2C: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
        goto L_800D2D54;
    // 0x800D2D2C: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
L_800D2D30:
    // 0x800D2D30: jal         0x80018948
    // 0x800D2D34: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x800D2D34: nop

    after_0:
    // 0x800D2D38: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800D2D3C: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800D2D40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2D44: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800D2D48: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800D2D4C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D2D50: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
L_800D2D54:
    // 0x800D2D54: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800D2D58: c.le.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl <= ctx->f2.fl;
    // 0x800D2D5C: nop

    // 0x800D2D60: bc1fl       L_800D2E6C
    if (!c1cs) {
        // 0x800D2D64: c.le.s      $f26, $f2
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl <= ctx->f2.fl;
            goto L_800D2E6C;
    }
    goto skip_2;
    // 0x800D2D64: c.le.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl <= ctx->f2.fl;
    skip_2:
    // 0x800D2D68: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800D2D6C: addiu       $a0, $sp, 0x128
    ctx->r4 = ADD32(ctx->r29, 0X128);
    // 0x800D2D70: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
    // 0x800D2D74: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800D2D78: swc1        $f6, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f6.u32l;
    // 0x800D2D7C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D2D80: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x800D2D84: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x800D2D88: beql        $a2, $zero, L_800D2DB4
    if (ctx->r6 == 0) {
        // 0x800D2D8C: lbu         $v0, 0x8($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X8);
            goto L_800D2DB4;
    }
    goto skip_3;
    // 0x800D2D8C: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    skip_3:
    // 0x800D2D90: jal         0x800D27F8
    // 0x800D2D94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    lbParticleGetPosVelDObj(rdram, ctx);
        goto after_1;
    // 0x800D2D94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800D2D98: lwc1        $f4, 0x128($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X128);
    // 0x800D2D9C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800D2DA0: lwc1        $f10, 0x12C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800D2DA4: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x800D2DA8: lwc1        $f6, 0x130($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X130);
    // 0x800D2DAC: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x800D2DB0: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
L_800D2DB4:
    // 0x800D2DB4: beq         $v0, $zero, L_800D2DCC
    if (ctx->r2 == 0) {
        // 0x800D2DB8: nop
    
            goto L_800D2DCC;
    }
    // 0x800D2DB8: nop

    // 0x800D2DBC: beq         $v0, $s2, L_800D2DCC
    if (ctx->r2 == ctx->r18) {
        // 0x800D2DC0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800D2DCC;
    }
    // 0x800D2DC0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D2DC4: bne         $v0, $at, L_800D2E1C
    if (ctx->r2 != ctx->r1) {
        // 0x800D2DC8: nop
    
            goto L_800D2E1C;
    }
    // 0x800D2DC8: nop

L_800D2DCC:
    // 0x800D2DCC: jal         0x80018948
    // 0x800D2DD0: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x800D2DD0: nop

    after_2:
    // 0x800D2DD4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800D2DD8: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800D2DDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2DE0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800D2DE4: sub.s       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800D2DE8: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800D2DEC: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800D2DF0: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
    // 0x800D2DF4: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800D2DF8: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800D2DFC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800D2E00: nop

    // 0x800D2E04: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800D2E08: nop

    // 0x800D2E0C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D2E10: div.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800D2E14: b           L_800D2E68
    // 0x800D2E18: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
        goto L_800D2E68;
    // 0x800D2E18: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
L_800D2E1C:
    // 0x800D2E1C: jal         0x80018948
    // 0x800D2E20: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x800D2E20: nop

    after_3:
    // 0x800D2E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D2E28: lwc1        $f6, 0x6264($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6264);
    // 0x800D2E2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D2E30: lwc1        $f4, 0x6268($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6268);
    // 0x800D2E34: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D2E38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2E3C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800D2E40: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x800D2E44: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800D2E48: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800D2E4C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800D2E50: nop

    // 0x800D2E54: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D2E58: nop

    // 0x800D2E5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D2E60: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D2E64: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
L_800D2E68:
    // 0x800D2E68: c.le.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl <= ctx->f2.fl;
L_800D2E6C:
    // 0x800D2E6C: nop

    // 0x800D2E70: bc1fl       L_800D3424
    if (!c1cs) {
        // 0x800D2E74: lhu         $v0, 0xE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XE);
            goto L_800D3424;
    }
    goto skip_4;
    // 0x800D2E74: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
    skip_4:
    // 0x800D2E78: lbu         $t5, 0x8($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X8);
L_800D2E7C:
    // 0x800D2E7C: sltiu       $at, $t5, 0x5
    ctx->r1 = ctx->r13 < 0X5 ? 1 : 0;
    // 0x800D2E80: beq         $at, $zero, L_800D33E8
    if (ctx->r1 == 0) {
        // 0x800D2E84: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800D33E8;
    }
    // 0x800D2E84: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800D2E88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D2E8C: addu        $at, $at, $t5
    gpr jr_addend_800D2E94 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800D2E90: lw          $t5, 0x626C($at)
    ctx->r13 = ADD32(ctx->r1, 0X626C);
    // 0x800D2E94: jr          $t5
    // 0x800D2E98: nop

    switch (jr_addend_800D2E94 >> 2) {
        case 0: goto L_800D2E9C; break;
        case 1: goto L_800D31E0; break;
        case 2: goto L_800D3294; break;
        case 3: goto L_800D2E9C; break;
        case 4: goto L_800D2E9C; break;
        default: switch_error(__func__, 0x800D2E94, 0x800D626C);
    }
    // 0x800D2E98: nop

L_800D2E9C:
    // 0x800D2E9C: lwc1        $f12, 0x120($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800D2EA0: lwc1        $f14, 0x124($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800D2EA4: lwc1        $f20, 0x11C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800D2EA8: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800D2EAC: jal         0x8001863C
    // 0x800D2EB0: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_4;
    // 0x800D2EB0: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    after_4:
    // 0x800D2EB4: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x800D2EB8: jal         0x800303F0
    // 0x800D2EBC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800D2EBC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x800D2EC0: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x800D2EC4: jal         0x80035CD0
    // 0x800D2EC8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    __cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x800D2EC8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_6:
    // 0x800D2ECC: mul.s       $f6, $f22, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x800D2ED0: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x800D2ED4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800D2ED8: mul.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800D2EDC: jal         0x8001863C
    // 0x800D2EE0: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_7;
    // 0x800D2EE0: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    after_7:
    // 0x800D2EE4: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x800D2EE8: jal         0x800303F0
    // 0x800D2EEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x800D2EEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x800D2EF0: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    // 0x800D2EF4: jal         0x80035CD0
    // 0x800D2EF8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x800D2EF8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_9:
    // 0x800D2EFC: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800D2F00: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
    // 0x800D2F04: swc1        $f30, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f30.u32l;
    // 0x800D2F08: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800D2F0C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D2F10: mul.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800D2F14: jal         0x80033510
    // 0x800D2F18: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x800D2F18: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_10:
    // 0x800D2F1C: swc1        $f0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f0.u32l;
    // 0x800D2F20: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800D2F24: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800D2F28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2F2C: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x800D2F30: nop

    // 0x800D2F34: bc1f        L_800D2F50
    if (!c1cs) {
        // 0x800D2F38: nop
    
            goto L_800D2F50;
    }
    // 0x800D2F38: nop

    // 0x800D2F3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D2F40: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800D2F44: neg.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = -ctx->f2.fl;
    // 0x800D2F48: b           L_800D2F88
    // 0x800D2F4C: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
        goto L_800D2F88;
    // 0x800D2F4C: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
L_800D2F50:
    // 0x800D2F50: jal         0x80018948
    // 0x800D2F54: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_11;
    // 0x800D2F54: nop

    after_11:
    // 0x800D2F58: swc1        $f0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f0.u32l;
    // 0x800D2F5C: lbu         $t2, 0x8($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X8);
    // 0x800D2F60: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800D2F64: beql        $t2, $zero, L_800D2F80
    if (ctx->r10 == 0) {
        // 0x800D2F68: lwc1        $f10, 0x38($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
            goto L_800D2F80;
    }
    goto skip_5;
    // 0x800D2F68: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    skip_5:
    // 0x800D2F6C: jal         0x80033510
    // 0x800D2F70: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x800D2F70: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_12:
    // 0x800D2F74: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800D2F78: swc1        $f0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f0.u32l;
    // 0x800D2F7C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
L_800D2F80:
    // 0x800D2F80: mul.s       $f20, $f10, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D2F84: nop

L_800D2F88:
    // 0x800D2F88: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800D2F8C: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800D2F90: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800D2F94: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800D2F98: nop

    // 0x800D2F9C: bc1f        L_800D2FB4
    if (!c1cs) {
        // 0x800D2FA0: nop
    
            goto L_800D2FB4;
    }
    // 0x800D2FA0: nop

    // 0x800D2FA4: add.s       $f22, $f6, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D2FA8: neg.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = -ctx->f0.fl;
    // 0x800D2FAC: b           L_800D2FDC
    // 0x800D2FB0: swc1        $f22, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f22.u32l;
        goto L_800D2FDC;
    // 0x800D2FB0: swc1        $f22, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f22.u32l;
L_800D2FB4:
    // 0x800D2FB4: jal         0x80018948
    // 0x800D2FB8: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_13;
    // 0x800D2FB8: nop

    after_13:
    // 0x800D2FBC: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800D2FC0: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800D2FC4: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800D2FC8: sub.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800D2FCC: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D2FD0: add.s       $f22, $f4, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800D2FD4: mul.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x800D2FD8: nop

L_800D2FDC:
    // 0x800D2FDC: jal         0x80035CD0
    // 0x800D2FE0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    __cosf_recomp(rdram, ctx);
        goto after_14;
    // 0x800D2FE0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_14:
    // 0x800D2FE4: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800D2FE8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800D2FEC: jal         0x800303F0
    // 0x800D2FF0: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_15;
    // 0x800D2FF0: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x800D2FF4: mul.s       $f26, $f0, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800D2FF8: jal         0x800303F0
    // 0x800D2FFC: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    __sinf_recomp(rdram, ctx);
        goto after_16;
    // 0x800D2FFC: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_16:
    // 0x800D3000: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800D3004: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800D3008: swc1        $f22, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f22.u32l;
    // 0x800D300C: mul.s       $f28, $f0, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D3010: jal         0x80035CD0
    // 0x800D3014: nop

    __cosf_recomp(rdram, ctx);
        goto after_17;
    // 0x800D3014: nop

    after_17:
    // 0x800D3018: mul.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800D301C: jal         0x800303F0
    // 0x800D3020: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    __sinf_recomp(rdram, ctx);
        goto after_18;
    // 0x800D3020: lwc1        $f12, 0xDC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XDC);
    after_18:
    // 0x800D3024: mul.s       $f22, $f0, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800D3028: jal         0x80035CD0
    // 0x800D302C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    __cosf_recomp(rdram, ctx);
        goto after_19;
    // 0x800D302C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_19:
    // 0x800D3030: lwc1        $f24, 0xEC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800D3034: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800D3038: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800D303C: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800D3040: mul.s       $f4, $f24, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x800D3044: lwc1        $f16, 0xF8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800D3048: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    // 0x800D304C: lwc1        $f10, 0xFC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800D3050: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x800D3054: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800D3058: neg.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = -ctx->f24.fl;
    // 0x800D305C: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800D3060: add.s       $f30, $f4, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800D3064: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D3068: nop

    // 0x800D306C: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800D3070: nop

    // 0x800D3074: mul.s       $f4, $f26, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x800D3078: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D307C: add.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800D3080: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800D3084: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800D3088: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800D308C: swc1        $f4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f4.u32l;
    // 0x800D3090: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D3094: nop

    // 0x800D3098: mul.s       $f8, $f26, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x800D309C: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800D30A0: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800D30A4: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800D30A8: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    // 0x800D30AC: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D30B0: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800D30B4: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800D30B8: swc1        $f8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f8.u32l;
    // 0x800D30BC: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800D30C0: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800D30C4: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x800D30C8: lwc1        $f0, 0xB4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800D30CC: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800D30D0: add.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D30D4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800D30D8: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x800D30DC: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800D30E0: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800D30E4: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800D30E8: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x800D30EC: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x800D30F0: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D30F4: nop

    // 0x800D30F8: mul.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x800D30FC: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800D3100: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800D3104: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800D3108: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x800D310C: mul.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800D3110: nop

    // 0x800D3114: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800D3118: add.s       $f26, $f10, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D311C: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800D3120: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800D3124: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800D3128: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800D312C: lbu         $t8, 0x8($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X8);
    // 0x800D3130: mov.s       $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    ctx->f16.fl = ctx->f26.fl;
    // 0x800D3134: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D3138: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800D313C: mul.s       $f8, $f22, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x800D3140: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800D3144: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D3148: nop

    // 0x800D314C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800D3150: add.s       $f28, $f4, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D3154: bne         $s2, $t8, L_800D3174
    if (ctx->r18 != ctx->r24) {
        // 0x800D3158: mov.s       $f18, $f28
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    ctx->f18.fl = ctx->f28.fl;
            goto L_800D3174;
    }
    // 0x800D3158: mov.s       $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    ctx->f18.fl = ctx->f28.fl;
    // 0x800D315C: mul.s       $f14, $f24, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800D3160: nop

    // 0x800D3164: mul.s       $f16, $f26, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800D3168: nop

    // 0x800D316C: mul.s       $f18, $f28, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x800D3170: nop

L_800D3174:
    // 0x800D3174: lhu         $t9, 0xC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XC);
    // 0x800D3178: lbu         $a0, 0x9($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9);
    // 0x800D317C: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x800D3180: lhu         $a2, 0xA($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XA);
    // 0x800D3184: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800D3188: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800D318C: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800D3190: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x800D3194: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800D3198: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x800D319C: swc1        $f30, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f30.u32l;
    // 0x800D31A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D31A4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800D31A8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800D31AC: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800D31B0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800D31B4: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D31B8: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800D31BC: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800D31C0: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800D31C4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800D31C8: jal         0x800CE7A8
    // 0x800D31CC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    lbParticleMakeParam(rdram, ctx);
        goto after_20;
    // 0x800D31CC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x800D31D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D31D4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800D31D8: b           L_800D3404
    // 0x800D31DC: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
        goto L_800D3404;
    // 0x800D31DC: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
L_800D31E0:
    // 0x800D31E0: jal         0x80018948
    // 0x800D31E4: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_21;
    // 0x800D31E4: nop

    after_21:
    // 0x800D31E8: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800D31EC: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800D31F0: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800D31F4: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800D31F8: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800D31FC: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800D3200: lhu         $t1, 0xC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XC);
    // 0x800D3204: sub.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800D3208: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800D320C: lbu         $a0, 0x9($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9);
    // 0x800D3210: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x800D3214: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D3218: lhu         $a2, 0xA($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XA);
    // 0x800D321C: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800D3220: add.s       $f30, $f2, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800D3224: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800D3228: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800D322C: add.s       $f18, $f12, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800D3230: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800D3234: swc1        $f30, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f30.u32l;
    // 0x800D3238: sub.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800D323C: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800D3240: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x800D3244: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800D3248: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D324C: lwc1        $f8, 0x124($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800D3250: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800D3254: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800D3258: add.s       $f16, $f14, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x800D325C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800D3260: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800D3264: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800D3268: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D326C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800D3270: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800D3274: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800D3278: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800D327C: jal         0x800CE7A8
    // 0x800D3280: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    lbParticleMakeParam(rdram, ctx);
        goto after_22;
    // 0x800D3280: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x800D3284: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D3288: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800D328C: b           L_800D3404
    // 0x800D3290: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
        goto L_800D3404;
    // 0x800D3290: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
L_800D3294:
    // 0x800D3294: lwc1        $f12, 0x120($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800D3298: lwc1        $f14, 0x124($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800D329C: lwc1        $f20, 0x11C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800D32A0: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800D32A4: jal         0x8001863C
    // 0x800D32A8: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_23;
    // 0x800D32A8: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    after_23:
    // 0x800D32AC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x800D32B0: jal         0x800303F0
    // 0x800D32B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_24;
    // 0x800D32B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_24:
    // 0x800D32B8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x800D32BC: jal         0x80035CD0
    // 0x800D32C0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    __cosf_recomp(rdram, ctx);
        goto after_25;
    // 0x800D32C0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_25:
    // 0x800D32C4: mul.s       $f8, $f22, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x800D32C8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800D32CC: mul.s       $f6, $f24, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800D32D0: jal         0x8001863C
    // 0x800D32D4: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_26;
    // 0x800D32D4: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    after_26:
    // 0x800D32D8: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800D32DC: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x800D32E0: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800D32E4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D32E8: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800D32EC: jal         0x80033510
    // 0x800D32F0: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_27;
    // 0x800D32F0: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_27:
    // 0x800D32F4: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x800D32F8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800D32FC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800D3300: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D3304: c.lt.s      $f4, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f4.fl < ctx->f30.fl;
    // 0x800D3308: nop

    // 0x800D330C: bc1f        L_800D3320
    if (!c1cs) {
        // 0x800D3310: nop
    
            goto L_800D3320;
    }
    // 0x800D3310: nop

    // 0x800D3314: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800D3318: b           L_800D3330
    // 0x800D331C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
        goto L_800D3330;
    // 0x800D331C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
L_800D3320:
    // 0x800D3320: jal         0x80018948
    // 0x800D3324: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_28;
    // 0x800D3324: nop

    after_28:
    // 0x800D3328: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800D332C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
L_800D3330:
    // 0x800D3330: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800D3334: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800D3338: c.lt.s      $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f10.fl < ctx->f30.fl;
    // 0x800D333C: nop

    // 0x800D3340: bc1f        L_800D3354
    if (!c1cs) {
        // 0x800D3344: nop
    
            goto L_800D3354;
    }
    // 0x800D3344: nop

    // 0x800D3348: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D334C: b           L_800D336C
    // 0x800D3350: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
        goto L_800D336C;
    // 0x800D3350: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
L_800D3354:
    // 0x800D3354: jal         0x80018948
    // 0x800D3358: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_29;
    // 0x800D3358: nop

    after_29:
    // 0x800D335C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D3360: lwc1        $f10, 0x6280($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6280);
    // 0x800D3364: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800D3368: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
L_800D336C:
    // 0x800D336C: swc1        $f22, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f22.u32l;
    // 0x800D3370: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x800D3374: lhu         $t0, 0xC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC);
    // 0x800D3378: lbu         $a0, 0x9($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9);
    // 0x800D337C: lhu         $a2, 0xA($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0XA);
    // 0x800D3380: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800D3384: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800D3388: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800D338C: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800D3390: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800D3394: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800D3398: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800D339C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800D33A0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800D33A4: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x800D33A8: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800D33AC: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800D33B0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800D33B4: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x800D33B8: swc1        $f26, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f26.u32l;
    // 0x800D33BC: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x800D33C0: jal         0x800CE7A8
    // 0x800D33C4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    lbParticleMakeParam(rdram, ctx);
        goto after_30;
    // 0x800D33C4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_30:
    // 0x800D33C8: beq         $v0, $zero, L_800D33DC
    if (ctx->r2 == 0) {
        // 0x800D33CC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800D33DC;
    }
    // 0x800D33CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D33D0: lhu         $t7, 0x54($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X54);
    // 0x800D33D4: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x800D33D8: sh          $t3, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r11;
L_800D33DC:
    // 0x800D33DC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800D33E0: b           L_800D3404
    // 0x800D33E4: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
        goto L_800D3404;
    // 0x800D33E4: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
L_800D33E8:
    // 0x800D33E8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800D33EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D33F0: beql        $v0, $zero, L_800D3408
    if (ctx->r2 == 0) {
        // 0x800D33F4: sub.s       $f10, $f2, $f26
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f26.fl;
            goto L_800D3408;
    }
    goto skip_6;
    // 0x800D33F4: sub.s       $f10, $f2, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f26.fl;
    skip_6:
    // 0x800D33F8: jalr        $v0
    // 0x800D33FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_31;
    // 0x800D33FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x800D3400: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
L_800D3404:
    // 0x800D3404: sub.s       $f10, $f2, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f26.fl;
L_800D3408:
    // 0x800D3408: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x800D340C: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800D3410: c.le.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl <= ctx->f2.fl;
    // 0x800D3414: nop

    // 0x800D3418: bc1tl       L_800D2E7C
    if (c1cs) {
        // 0x800D341C: lbu         $t5, 0x8($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X8);
            goto L_800D2E7C;
    }
    goto skip_7;
    // 0x800D341C: lbu         $t5, 0x8($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X8);
    skip_7:
    // 0x800D3420: lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XE);
L_800D3424:
    // 0x800D3424: beq         $v0, $zero, L_800D34F4
    if (ctx->r2 == 0) {
        // 0x800D3428: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800D34F4;
    }
    // 0x800D3428: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800D342C: andi        $t6, $t4, 0xFFFF
    ctx->r14 = ctx->r12 & 0XFFFF;
    // 0x800D3430: bne         $t6, $zero, L_800D34F4
    if (ctx->r14 != 0) {
        // 0x800D3434: sh          $t4, 0xE($s0)
        MEM_H(0XE, ctx->r16) = ctx->r12;
            goto L_800D34F4;
    }
    // 0x800D3434: sh          $t4, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r12;
    // 0x800D3438: lbu         $t5, 0x8($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X8);
    // 0x800D343C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D3440: bnel        $t5, $at, L_800D346C
    if (ctx->r13 != ctx->r1) {
        // 0x800D3444: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800D346C;
    }
    goto skip_8;
    // 0x800D3444: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_8:
    // 0x800D3448: lhu         $t2, 0x54($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X54);
    // 0x800D344C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D3450: beql        $t2, $zero, L_800D346C
    if (ctx->r10 == 0) {
        // 0x800D3454: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800D346C;
    }
    goto skip_9;
    // 0x800D3454: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_9:
    // 0x800D3458: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D345C: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
    // 0x800D3460: b           L_800D34F4
    // 0x800D3464: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
        goto L_800D34F4;
    // 0x800D3464: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x800D3468: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_800D346C:
    // 0x800D346C: bnel        $v0, $zero, L_800D3488
    if (ctx->r2 != 0) {
        // 0x800D3470: lw          $t1, 0x0($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X0);
            goto L_800D3488;
    }
    goto skip_10;
    // 0x800D3470: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    skip_10:
    // 0x800D3474: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800D3478: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D347C: b           L_800D348C
    // 0x800D3480: sw          $t9, 0x639C($at)
    MEM_W(0X639C, ctx->r1) = ctx->r25;
        goto L_800D348C;
    // 0x800D3480: sw          $t9, 0x639C($at)
    MEM_W(0X639C, ctx->r1) = ctx->r25;
    // 0x800D3484: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
L_800D3488:
    // 0x800D3488: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800D348C:
    // 0x800D348C: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800D3490: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800D3494: beq         $a0, $zero, L_800D34C4
    if (ctx->r4 == 0) {
        // 0x800D3498: nop
    
            goto L_800D34C4;
    }
    // 0x800D3498: nop

    // 0x800D349C: lhu         $t0, 0x2A($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X2A);
    // 0x800D34A0: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x800D34A4: sh          $t7, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r15;
    // 0x800D34A8: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800D34AC: lhu         $t3, 0x2A($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X2A);
    // 0x800D34B0: bne         $t3, $zero, L_800D34C4
    if (ctx->r11 != 0) {
        // 0x800D34B4: nop
    
            goto L_800D34C4;
    }
    // 0x800D34B4: nop

    // 0x800D34B8: jal         0x800CE188
    // 0x800D34BC: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    lbParticleEjectTransform(rdram, ctx);
        goto after_32;
    // 0x800D34BC: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    after_32:
    // 0x800D34C0: lw          $v0, 0x138($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X138);
L_800D34C4:
    // 0x800D34C4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800D34C8: lw          $t4, 0x6398($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6398);
    // 0x800D34CC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800D34D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D34D4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800D34D8: lhu         $t6, 0x644A($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X644A);
    // 0x800D34DC: sw          $s0, 0x6398($at)
    MEM_W(0X6398, ctx->r1) = ctx->r16;
    // 0x800D34E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D34E4: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x800D34E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D34EC: b           L_800D34FC
    // 0x800D34F0: sh          $t5, 0x644A($at)
    MEM_H(0X644A, ctx->r1) = ctx->r13;
        goto L_800D34FC;
    // 0x800D34F0: sh          $t5, 0x644A($at)
    MEM_H(0X644A, ctx->r1) = ctx->r13;
L_800D34F4:
    // 0x800D34F4: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x800D34F8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D34FC:
    // 0x800D34FC: bnel        $s0, $zero, L_800D2CB8
    if (ctx->r16 != 0) {
        // 0x800D3500: lw          $t7, 0x140($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X140);
            goto L_800D2CB8;
    }
    goto skip_11;
    // 0x800D3500: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    skip_11:
L_800D3504:
    // 0x800D3504: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x800D3508: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x800D350C: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x800D3510: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x800D3514: ldc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X60);
    // 0x800D3518: ldc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X68);
    // 0x800D351C: ldc1        $f30, 0x70($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X70);
    // 0x800D3520: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x800D3524: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x800D3528: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x800D352C: lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X84);
    // 0x800D3530: lw          $s4, 0x88($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X88);
    // 0x800D3534: jr          $ra
    // 0x800D3538: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x800D3538: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void gcFuncGObjByLinkEx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AFE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000AFE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000AFEC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8000AFF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8000AFF4: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x8000AFF8: lw          $s0, 0x66F0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66F0);
    // 0x8000AFFC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000B000: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000B004: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000B008: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000B00C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8000B010: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000B014: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x8000B018: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000B01C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000B020: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000B024: beq         $s0, $zero, L_8000B060
    if (ctx->r16 == 0) {
        // 0x8000B028: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000B060;
    }
    // 0x8000B028: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000B02C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8000B030:
    // 0x8000B030: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x8000B034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B038: jalr        $s5
    // 0x8000B03C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r21)(rdram, ctx);
        goto after_0;
    // 0x8000B03C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8000B040: beq         $v0, $zero, L_8000B058
    if (ctx->r2 == 0) {
        // 0x8000B044: nop
    
            goto L_8000B058;
    }
    // 0x8000B044: nop

    // 0x8000B048: bne         $s6, $s2, L_8000B058
    if (ctx->r22 != ctx->r18) {
        // 0x8000B04C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8000B058;
    }
    // 0x8000B04C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8000B050: b           L_8000B068
    // 0x8000B054: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8000B068;
    // 0x8000B054: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000B058:
    // 0x8000B058: bne         $s1, $zero, L_8000B030
    if (ctx->r17 != 0) {
        // 0x8000B05C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000B030;
    }
    // 0x8000B05C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8000B060:
    // 0x8000B060: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8000B064: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000B068:
    // 0x8000B068: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000B06C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B070: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000B074: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000B078: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000B07C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B080: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000B084: jr          $ra
    // 0x8000B088: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000B088: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void wpManagerSetPrevStructAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80165588: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8016558C: addiu       $v0, $v0, -0x3010
    ctx->r2 = ADD32(ctx->r2, -0X3010);
    // 0x80165590: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80165594: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80165598: jr          $ra
    // 0x8016559C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8016559C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void ftCommonThrownSetStatusNoDamageRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B5B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8014B5B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8014B5BC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8014B5C0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8014B5C4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014B5C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014B5CC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8014B5D0: lwc1        $f0, 0x7E8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X7E8);
    // 0x8014B5D4: lwc1        $f12, 0x7E4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X7E4);
    // 0x8014B5D8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8014B5DC: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8014B5E0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8014B5E4: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8014B5E8: bc1fl       L_8014B5FC
    if (!c1cs) {
        // 0x8014B5EC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8014B5FC;
    }
    goto skip_0;
    // 0x8014B5EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8014B5F0: b           L_8014B5FC
    // 0x8014B5F4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8014B5FC;
    // 0x8014B5F4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8014B5F8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8014B5FC:
    // 0x8014B5FC: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8014B600: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8014B604: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8014B608: swc1        $f4, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f4.u32l;
    // 0x8014B60C: lw          $t1, -0x790C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X790C);
    // 0x8014B610: lw          $t0, -0x7914($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7914);
    // 0x8014B614: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8014B618: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8014B61C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8014B620: lw          $t2, 0x9C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014B624: lw          $a2, -0x791C($t9)
    ctx->r6 = MEM_W(ctx->r25, -0X791C);
    // 0x8014B628: lw          $a3, -0x7910($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7910);
    // 0x8014B62C: lwc1        $f6, 0x68($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X68);
    // 0x8014B630: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8014B634: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8014B638: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8014B63C: lbu         $t4, 0x12($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X12);
    // 0x8014B640: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8014B644: jal         0x800E9D78
    // 0x8014B648: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_0;
    // 0x8014B648: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_0:
    // 0x8014B64C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8014B650: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8014B654: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014B658: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8014B65C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014B660: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8014B664: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014B668: bc1f        L_8014B678
    if (!c1cs) {
        // 0x8014B66C: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8014B678;
    }
    // 0x8014B66C: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8014B670: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8014B674: nop

L_8014B678:
    // 0x8014B678: lw          $t5, -0x7918($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7918);
    // 0x8014B67C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8014B680: lw          $t8, -0x7908($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7908);
    // 0x8014B684: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8014B688: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x8014B68C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8014B690: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014B694: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014B698: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8014B69C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8014B6A0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8014B6A4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8014B6A8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8014B6AC: lw          $a1, -0x7920($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7920);
    // 0x8014B6B0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8014B6B4: jal         0x80140EE4
    // 0x8014B6B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_1;
    // 0x8014B6B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_1:
    // 0x8014B6BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014B6C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8014B6C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014B6C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014B6CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014B6D0: jal         0x800EAA2C
    // 0x8014B6D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_2;
    // 0x8014B6D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8014B6D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8014B6DC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8014B6E0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8014B6E4: jr          $ra
    // 0x8014B6E8: nop

    return;
    // 0x8014B6E8: nop

;}
RECOMP_FUNC void itTaruWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179CF0: jal         0x80172E74
    // 0x80179CF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80179CF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80179CF8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179CFC: addiu       $a1, $a1, -0x5B7C
    ctx->r5 = ADD32(ctx->r5, -0X5B7C);
    // 0x80179D00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80179D04: jal         0x80172EC8
    // 0x80179D08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80179D08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80179D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179D14: jr          $ra
    // 0x80179D18: nop

    return;
    // 0x80179D18: nop

;}
RECOMP_FUNC void func_80026958_27558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026958: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002695C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026960: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80026964: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80026968: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002696C: jal         0x80030350
    // 0x80026970: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026970: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026974: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80026978: jal         0x80026844
    // 0x8002697C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    func_80026844_27444(rdram, ctx);
        goto after_1;
    // 0x8002697C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80026980: beq         $v0, $zero, L_8002699C
    if (ctx->r2 == 0) {
        // 0x80026984: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8002699C;
    }
    // 0x80026984: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80026988: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8002698C: lw          $t6, -0x11F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X11F0);
    // 0x80026990: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80026994: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80026998: sw          $v0, -0x11F0($at)
    MEM_W(-0X11F0, ctx->r1) = ctx->r2;
L_8002699C:
    // 0x8002699C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800269A0: jal         0x80030350
    // 0x800269A4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x800269A4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800269A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800269AC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800269B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800269B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800269B8: jr          $ra
    // 0x800269BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800269BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_80373ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373ABC: jr          $ra
    // 0x80373AC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80373AC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_ovl27_80134EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134EB8: jr          $ra
    // 0x80134EBC: nop

    return;
    // 0x80134EBC: nop

;}
RECOMP_FUNC void sc1PChallengerFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801321C4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801321C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801321CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801321D0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801321D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801321D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801321DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801321E0: addiu       $t8, $t8, 0x24D8
    ctx->r24 = ADD32(ctx->r24, 0X24D8);
    // 0x801321E4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801321E8: addiu       $t0, $t0, 0x24A0
    ctx->r8 = ADD32(ctx->r8, 0X24A0);
    // 0x801321EC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801321F0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x801321F4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x801321F8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801321FC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80132200: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80132204: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80132208: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8013220C: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80132210: jal         0x800CDF78
    // 0x80132214: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132214: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80132218: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013221C: addiu       $a0, $a0, 0x2370
    ctx->r4 = ADD32(ctx->r4, 0X2370);
    // 0x80132220: jal         0x800CDEEC
    // 0x80132224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80132228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013222C: jal         0x80004980
    // 0x80132230: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132230: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132234: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132238: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013223C: addiu       $a2, $a2, 0x27F8
    ctx->r6 = ADD32(ctx->r6, 0X27F8);
    // 0x80132240: addiu       $a0, $a0, 0x2370
    ctx->r4 = ADD32(ctx->r4, 0X2370);
    // 0x80132244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132248: jal         0x800CDE04
    // 0x8013224C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8013224C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132250: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132254: addiu       $a1, $a1, 0x2118
    ctx->r5 = ADD32(ctx->r5, 0X2118);
    // 0x80132258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013225C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132260: jal         0x80009968
    // 0x80132264: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132264: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132268: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8013226C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132270: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132274: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132278: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8013227C: jal         0x8000B9FC
    // 0x80132280: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132280: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80132284: jal         0x801320E0
    // 0x80132288: nop

    sc1PChallengerInitVars(rdram, ctx);
        goto after_6;
    // 0x80132288: nop

    after_6:
    // 0x8013228C: jal         0x80115890
    // 0x80132290: nop

    efParticleInitAll(rdram, ctx);
        goto after_7;
    // 0x80132290: nop

    after_7:
    // 0x80132294: jal         0x800FD300
    // 0x80132298: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x80132298: nop

    after_8:
    // 0x8013229C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801322A0: jal         0x800D7194
    // 0x801322A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x801322A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x801322A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801322AC: jal         0x800D786C
    // 0x801322B0: lw          $a0, 0x2488($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2488);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x801322B0: lw          $a0, 0x2488($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2488);
    after_10:
    // 0x801322B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801322B8: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801322BC: jal         0x80004980
    // 0x801322C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x801322C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x801322C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322C8: jal         0x80132040
    // 0x801322CC: sw          $v0, 0x248C($at)
    MEM_W(0X248C, ctx->r1) = ctx->r2;
    sc1PChallengerMakeDecalsCamera(rdram, ctx);
        goto after_12;
    // 0x801322CC: sw          $v0, 0x248C($at)
    MEM_W(0X248C, ctx->r1) = ctx->r2;
    after_12:
    // 0x801322D0: jal         0x80131F58
    // 0x801322D4: nop

    sc1PChallengerMakeFighterCamera(rdram, ctx);
        goto after_13;
    // 0x801322D4: nop

    after_13:
    // 0x801322D8: jal         0x80131C40
    // 0x801322DC: nop

    sc1PChallengerMakeDecals(rdram, ctx);
        goto after_14;
    // 0x801322DC: nop

    after_14:
    // 0x801322E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801322E4: jal         0x80131E3C
    // 0x801322E8: lw          $a0, 0x2488($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2488);
    sc1PChallengerMakeFighter(rdram, ctx);
        goto after_15;
    // 0x801322E8: lw          $a0, 0x2488($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2488);
    after_15:
    // 0x801322EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801322F0: jal         0x80020AB4
    // 0x801322F4: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    syAudioPlayBGM(rdram, ctx);
        goto after_16;
    // 0x801322F4: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_16:
    // 0x801322F8: jal         0x800269C0
    // 0x801322FC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800269C0_275C0(rdram, ctx);
        goto after_17;
    // 0x801322FC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_17:
    // 0x80132300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132304: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132308: jr          $ra
    // 0x8013230C: nop

    return;
    // 0x8013230C: nop

;}
RECOMP_FUNC void itMainApplyGravityClampTVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172558: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017255C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80172560: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80172564: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80172568: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8017256C: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80172570: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80172574: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80172578: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8017257C: jal         0x800C7A84
    // 0x80172580: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    lbCommonMag2D(rdram, ctx);
        goto after_0;
    // 0x80172580: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80172584: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80172588: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8017258C: nop

    // 0x80172590: bc1fl       L_801725B0
    if (!c1cs) {
        // 0x80172594: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801725B0;
    }
    goto skip_0;
    // 0x80172594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80172598: jal         0x800C7A00
    // 0x8017259C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    lbCommonNormDist2D(rdram, ctx);
        goto after_1;
    // 0x8017259C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x801725A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801725A4: jal         0x800C7AE0
    // 0x801725A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    lbCommonScale2D(rdram, ctx);
        goto after_2;
    // 0x801725A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801725AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801725B0:
    // 0x801725B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801725B4: jr          $ra
    // 0x801725B8: nop

    return;
    // 0x801725B8: nop

;}
RECOMP_FUNC void gcResumeGObjProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B304: bne         $a0, $zero, L_8000B314
    if (ctx->r4 != 0) {
        // 0x8000B308: nop
    
            goto L_8000B314;
    }
    // 0x8000B308: nop

    // 0x8000B30C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000B310: lw          $a0, 0x6A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A60);
L_8000B314:
    // 0x8000B314: jr          $ra
    // 0x8000B318: sb          $zero, 0x15($a0)
    MEM_B(0X15, ctx->r4) = 0;
    return;
    // 0x8000B318: sb          $zero, 0x15($a0)
    MEM_B(0X15, ctx->r4) = 0;
;}
RECOMP_FUNC void mnVSRecordMakePortraitStatsArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132A84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132A88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132A8C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132A90: jal         0x80009968
    // 0x80132A94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132A94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132A98: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132A9C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132AA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132AA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132AA8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132AB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132AB4: jal         0x80009DF4
    // 0x80132AB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132AB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132ABC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132AC0: addiu       $a1, $a1, 0x2A50
    ctx->r5 = ADD32(ctx->r5, 0X2A50);
    // 0x80132AC4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132AC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132ACC: jal         0x80008188
    // 0x80132AD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132AD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132AD4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132AD8: lw          $t7, 0x6D8C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D8C);
    // 0x80132ADC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132AE0: addiu       $t8, $t8, 0xBE0
    ctx->r24 = ADD32(ctx->r24, 0XBE0);
    // 0x80132AE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132AE8: jal         0x800CCFDC
    // 0x80132AEC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132AEC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80132AF0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132AF4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80132AF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132AFC: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x80132B00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132B04: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132B08: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132B0C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132B10: addiu       $t3, $zero, 0xE3
    ctx->r11 = ADD32(0, 0XE3);
    // 0x80132B14: addiu       $t4, $zero, 0x7D
    ctx->r12 = ADD32(0, 0X7D);
    // 0x80132B18: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80132B1C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132B20: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132B24: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132B28: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80132B2C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132B30: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132B34: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132B38: lw          $t6, 0x6D8C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D8C);
    // 0x80132B3C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132B40: addiu       $t7, $t7, 0xC80
    ctx->r15 = ADD32(ctx->r15, 0XC80);
    // 0x80132B44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132B48: jal         0x800CCFDC
    // 0x80132B4C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132B4C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_4:
    // 0x80132B50: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132B54: lui         $at, 0x42D2
    ctx->r1 = S32(0X42D2 << 16);
    // 0x80132B58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132B5C: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x80132B60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132B64: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80132B68: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132B6C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80132B70: addiu       $t2, $zero, 0xE3
    ctx->r10 = ADD32(0, 0XE3);
    // 0x80132B74: addiu       $t3, $zero, 0x7D
    ctx->r11 = ADD32(0, 0X7D);
    // 0x80132B78: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80132B7C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132B80: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80132B84: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80132B88: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x80132B8C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132B90: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132B94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132B9C: jr          $ra
    // 0x80132BA0: nop

    return;
    // 0x80132BA0: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueSetupCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801335D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801335DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801335E0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801335E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801335E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801335EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801335F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801335F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801335F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801335FC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80133600: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133604: jal         0x80007080
    // 0x80133608: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_0;
    // 0x80133608: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8013360C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80133610: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133614: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80133618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013361C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80133620: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133624: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80133628: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013362C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133630: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80133634: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133638: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8013363C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133640: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133644: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80133648: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x8013364C: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x80133650: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80133654: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80133658: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8013365C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80133660: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80133664: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80133668: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8013366C: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80133670: lwc1        $f6, 0x42EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X42EC);
    // 0x80133674: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80133678: sw          $t6, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r14;
    // 0x8013367C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80133680: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133684: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80133688: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013368C: jr          $ra
    // 0x80133690: nop

    return;
    // 0x80133690: nop

;}
RECOMP_FUNC void ftKirbySpecialNWaitSetStatusFromTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162FA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80162FAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162FB0: jal         0x80162F60
    // 0x80162FB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftKirbySpecialNWaitUpdateLR(rdram, ctx);
        goto after_0;
    // 0x80162FB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162FB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80162FBC: addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
    // 0x80162FC0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80162FC4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80162FC8: jal         0x800E6F24
    // 0x80162FCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162FCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80162FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80162FD8: jr          $ra
    // 0x80162FDC: nop

    return;
    // 0x80162FDC: nop

;}
RECOMP_FUNC void ftSamusSpecialAirHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DE54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015DE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015DE5C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015DE60: lw          $a1, 0x9C8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X9C8);
    // 0x8015DE64: jal         0x800D8E50
    // 0x8015DE68: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_0;
    // 0x8015DE68: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015DE6C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8015DE70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8015DE74: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8015DE78: jal         0x800D8FC8
    // 0x8015DE7C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_1;
    // 0x8015DE7C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_1:
    // 0x8015DE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015DE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015DE88: jr          $ra
    // 0x8015DE8C: nop

    return;
    // 0x8015DE8C: nop

;}
RECOMP_FUNC void ftMainUpdateShieldStatFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2A90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E2A94: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E2A98: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800E2A9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E2AA0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E2AA4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800E2AA8: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x800E2AAC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E2AB0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800E2AB4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800E2AB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E2ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800E2AC0: jal         0x800E26BC
    // 0x800E2AC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    ftMainSetHitInteractStats(rdram, ctx);
        goto after_0;
    // 0x800E2AC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800E2AC8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800E2ACC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800E2AD0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800E2AD4: lw          $t6, 0x7BC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7BC);
    // 0x800E2AD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E2ADC: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E2AE0: beql        $at, $zero, L_800E2AF4
    if (ctx->r1 == 0) {
        // 0x800E2AE4: lw          $t7, 0x7CC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X7CC);
            goto L_800E2AF4;
    }
    goto skip_0;
    // 0x800E2AE4: lw          $t7, 0x7CC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7CC);
    skip_0:
    // 0x800E2AE8: sw          $v0, 0x7BC($a0)
    MEM_W(0X7BC, ctx->r4) = ctx->r2;
    // 0x800E2AEC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800E2AF0: lw          $t7, 0x7CC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7CC);
L_800E2AF4:
    // 0x800E2AF4: lw          $t9, 0x38($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X38);
    // 0x800E2AF8: lw          $t1, 0x7C8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C8);
    // 0x800E2AFC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E2B00: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800E2B04: sw          $t0, 0x7CC($s0)
    MEM_W(0X7CC, ctx->r16) = ctx->r8;
    // 0x800E2B08: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800E2B0C: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E2B10: beql        $at, $zero, L_800E2B60
    if (ctx->r1 == 0) {
        // 0x800E2B14: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_800E2B60;
    }
    goto skip_1;
    // 0x800E2B14: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    skip_1:
    // 0x800E2B18: sw          $v0, 0x7C8($s0)
    MEM_W(0X7C8, ctx->r16) = ctx->r2;
    // 0x800E2B1C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800E2B20: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x800E2B24: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800E2B28: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x800E2B2C: lwc1        $f4, 0x1C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800E2B30: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800E2B34: lwc1        $f6, 0x1C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x800E2B38: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800E2B3C: nop

    // 0x800E2B40: bc1fl       L_800E2B54
    if (!c1cs) {
        // 0x800E2B44: sw          $t6, 0x7D0($s0)
        MEM_W(0X7D0, ctx->r16) = ctx->r14;
            goto L_800E2B54;
    }
    goto skip_2;
    // 0x800E2B44: sw          $t6, 0x7D0($s0)
    MEM_W(0X7D0, ctx->r16) = ctx->r14;
    skip_2:
    // 0x800E2B48: b           L_800E2B54
    // 0x800E2B4C: sw          $t5, 0x7D0($s0)
    MEM_W(0X7D0, ctx->r16) = ctx->r13;
        goto L_800E2B54;
    // 0x800E2B4C: sw          $t5, 0x7D0($s0)
    MEM_W(0X7D0, ctx->r16) = ctx->r13;
    // 0x800E2B50: sw          $t6, 0x7D0($s0)
    MEM_W(0X7D0, ctx->r16) = ctx->r14;
L_800E2B54:
    // 0x800E2B54: lbu         $t7, 0xD($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD);
    // 0x800E2B58: sw          $t7, 0x7D4($s0)
    MEM_W(0X7D4, ctx->r16) = ctx->r15;
    // 0x800E2B5C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
L_800E2B60:
    // 0x800E2B60: jal         0x800F0B78
    // 0x800E2B64: lw          $a3, 0x8F4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8F4);
    gmCollisionGetFighterAttackShieldPosition(rdram, ctx);
        goto after_1;
    // 0x800E2B64: lw          $a3, 0x8F4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8F4);
    after_1:
    // 0x800E2B68: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800E2B6C: jal         0x80100BF0
    // 0x800E2B70: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_2;
    // 0x800E2B70: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    after_2:
    // 0x800E2B74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E2B78: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2B7C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E2B80: jr          $ra
    // 0x800E2B84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800E2B84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnPlayers1PTrainingGetPortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132020: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132024: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132028: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x8013202C: addiu       $t6, $t6, -0x7F3C
    ctx->r14 = ADD32(ctx->r14, -0X7F3C);
    // 0x80132030: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80132034: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80132038:
    // 0x80132038: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013203C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132040: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132044: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132048: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8013204C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132050: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132054: bne         $t6, $t0, L_80132038
    if (ctx->r14 != ctx->r8) {
        // 0x80132058: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132038;
    }
    // 0x80132058: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8013205C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80132060: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80132064: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80132068: jr          $ra
    // 0x8013206C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013206C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mpCollisionSetYakumonoOnID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC58C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC590: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC594: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FC598: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FC59C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC5A0: beq         $a0, $at, L_800FC5B4
    if (ctx->r4 == ctx->r1) {
        // 0x800FC5A4: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FC5B4;
    }
    // 0x800FC5A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC5A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FC5AC: bne         $a0, $at, L_800FC5D8
    if (ctx->r4 != ctx->r1) {
        // 0x800FC5B0: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800FC5D8;
    }
    // 0x800FC5B0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
L_800FC5B4:
    // 0x800FC5B4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC5B8: addiu       $s0, $s0, 0x6BC
    ctx->r16 = ADD32(ctx->r16, 0X6BC);
    // 0x800FC5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC5C0:
    // 0x800FC5C0: jal         0x80023624
    // 0x800FC5C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FC5C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FC5C8: jal         0x800A3040
    // 0x800FC5CC: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FC5CC: nop

    after_1:
    // 0x800FC5D0: b           L_800FC5C0
    // 0x800FC5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FC5C0;
    // 0x800FC5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC5D8:
    // 0x800FC5D8: lw          $t7, 0x1304($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1304);
    // 0x800FC5DC: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800FC5E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800FC5E4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800FC5E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800FC5EC: sw          $t6, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r14;
    // 0x800FC5F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC5F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC5F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC5FC: jr          $ra
    // 0x800FC600: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FC600: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

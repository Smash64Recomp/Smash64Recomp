#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl8_803841E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803841E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x803841E4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x803841E8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x803841EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803841F0: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x803841F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803841F8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x803841FC: bne         $a0, $zero, L_80384214
    if (ctx->r4 != 0) {
        // 0x80384200: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80384214;
    }
    // 0x80384200: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80384204: jal         0x803717A0
    // 0x80384208: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80384208: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    after_0:
    // 0x8038420C: beq         $v0, $zero, L_80384328
    if (ctx->r2 == 0) {
        // 0x80384210: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80384328;
    }
    // 0x80384210: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80384214:
    // 0x80384214: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80384218: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8038421C: addiu       $a1, $s0, 0xC8
    ctx->r5 = ADD32(ctx->r16, 0XC8);
    // 0x80384220: bnel        $t6, $zero, L_80384244
    if (ctx->r14 != 0) {
        // 0x80384224: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_80384244;
    }
    goto skip_0;
    // 0x80384224: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80384228: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8038422C: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x80384230: jal         0x803717E0
    // 0x80384234: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80384234: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_1:
    // 0x80384238: jal         0x8037C2D0
    // 0x8038423C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8038423C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80384240: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_80384244:
    // 0x80384244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80384248: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8038424C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80384250: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80384254: jal         0x80383450
    // 0x80384258: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_80383450(rdram, ctx);
        goto after_3;
    // 0x80384258: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8038425C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80384260: jal         0x80372430
    // 0x80384264: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_ovl8_80372430(rdram, ctx);
        goto after_4;
    // 0x80384264: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x80384268: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038426C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80384270: addiu       $t8, $t8, -0x3270
    ctx->r24 = ADD32(ctx->r24, -0X3270);
    // 0x80384274: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80384278: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8038427C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80384280: addiu       $t9, $t9, -0x3120
    ctx->r25 = ADD32(ctx->r25, -0X3120);
    // 0x80384284: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x80384288: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8038428C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80384290: addiu       $t1, $t1, -0x2FC8
    ctx->r9 = ADD32(ctx->r9, -0X2FC8);
    // 0x80384294: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80384298: addiu       $t3, $t3, -0x2FA0
    ctx->r11 = ADD32(ctx->r11, -0X2FA0);
    // 0x8038429C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x803842A0: beq         $a1, $zero, L_803842BC
    if (ctx->r5 == 0) {
        // 0x803842A4: sw          $t3, 0x64($s0)
        MEM_W(0X64, ctx->r16) = ctx->r11;
            goto L_803842BC;
    }
    // 0x803842A4: sw          $t3, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r11;
    // 0x803842A8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x803842AC: lw          $t9, 0x10C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10C);
    // 0x803842B0: lh          $t4, 0x108($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X108);
    // 0x803842B4: jalr        $t9
    // 0x803842B8: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x803842B8: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    after_5:
L_803842BC:
    // 0x803842BC: lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X10);
    // 0x803842C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x803842C4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x803842C8: bnel        $v0, $at, L_803842DC
    if (ctx->r2 != ctx->r1) {
        // 0x803842CC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_803842DC;
    }
    goto skip_1;
    // 0x803842CC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_1:
    // 0x803842D0: b           L_803842E8
    // 0x803842D4: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
        goto L_803842E8;
    // 0x803842D4: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x803842D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_803842DC:
    // 0x803842DC: bne         $v0, $at, L_803842E8
    if (ctx->r2 != ctx->r1) {
        // 0x803842E0: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_803842E8;
    }
    // 0x803842E0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x803842E4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_803842E8:
    // 0x803842E8: lhu         $t7, 0x4($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X4);
    // 0x803842EC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x803842F0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x803842F4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x803842F8: lhu         $t8, 0x6($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X6);
    // 0x803842FC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80384300: jal         0x8037B85C
    // 0x80384304: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    func_ovl8_8037B85C(rdram, ctx);
        goto after_6;
    // 0x80384304: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    after_6:
    // 0x80384308: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8038430C: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80384310: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x80384314: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80384318: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8038431C: jal         0x8037ACAC
    // 0x80384320: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_7;
    // 0x80384320: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_7:
    // 0x80384324: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
L_80384328:
    // 0x80384328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8038432C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80384330: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80384334: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80384338: jr          $ra
    // 0x8038433C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8038433C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnVSRecordMakeRankingHighlightCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135BCC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135BD0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135BD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135BD8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135BDC: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80135BE0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80135BE4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80135BE8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135BEC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135BF0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135BF4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135BF8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135BFC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135C00: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135C04: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135C08: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135C0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135C10: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135C14: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135C18: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135C1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80135C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135C24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80135C28: jal         0x8000B93C
    // 0x80135C2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135C2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135C30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135C34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135C38: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135C3C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135C40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135C44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135C48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135C4C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135C50: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80135C54: jal         0x80007080
    // 0x80135C58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135C58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135C5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135C60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135C64: jr          $ra
    // 0x80135C68: nop

    return;
    // 0x80135C68: nop

;}
RECOMP_FUNC void func_ovl8_803801DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803801DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x803801E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803801E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803801E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803801EC: beq         $a0, $zero, L_803801F8
    if (ctx->r4 == 0) {
        // 0x803801F0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_803801F8;
    }
    // 0x803801F0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x803801F4: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
L_803801F8:
    // 0x803801F8: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x803801FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80380200: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x80380204: bne         $t6, $at, L_80380218
    if (ctx->r14 != ctx->r1) {
        // 0x80380208: addiu       $t4, $s0, 0xBC
        ctx->r12 = ADD32(ctx->r16, 0XBC);
            goto L_80380218;
    }
    // 0x80380208: addiu       $t4, $s0, 0xBC
    ctx->r12 = ADD32(ctx->r16, 0XBC);
    // 0x8038020C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80380210: b           L_80380264
    // 0x80380214: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_80380264;
    // 0x80380214: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80380218:
    // 0x80380218: beq         $s0, $zero, L_80380224
    if (ctx->r16 == 0) {
        // 0x8038021C: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80380224;
    }
    // 0x8038021C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80380220: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
L_80380224:
    // 0x80380224: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80380228: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8038022C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80380230: bne         $t8, $at, L_80380240
    if (ctx->r24 != ctx->r1) {
        // 0x80380234: nop
    
            goto L_80380240;
    }
    // 0x80380234: nop

    // 0x80380238: b           L_80380264
    // 0x8038023C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80380264;
    // 0x8038023C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80380240:
    // 0x80380240: beq         $s0, $zero, L_8038024C
    if (ctx->r16 == 0) {
        // 0x80380244: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8038024C;
    }
    // 0x80380244: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80380248: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
L_8038024C:
    // 0x8038024C: lhu         $t0, 0x24($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X24);
    // 0x80380250: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80380254: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80380258: bnel        $t0, $at, L_80380268
    if (ctx->r8 != ctx->r1) {
        // 0x8038025C: lw          $v1, 0x18($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X18);
            goto L_80380268;
    }
    goto skip_0;
    // 0x8038025C: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x80380260: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80380264:
    // 0x80380264: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
L_80380268:
    // 0x80380268: sw          $zero, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = 0;
    // 0x8038026C: sw          $zero, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = 0;
    // 0x80380270: lh          $t2, 0xC0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XC0);
    // 0x80380274: lw          $a1, 0xB4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB4);
    // 0x80380278: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8038027C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80380280: lw          $t9, 0xC4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC4);
    // 0x80380284: addiu       $a2, $s0, 0xB0
    ctx->r6 = ADD32(ctx->r16, 0XB0);
    // 0x80380288: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8038028C: jalr        $t9
    // 0x80380290: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80380290: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    after_0:
    // 0x80380294: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80380298: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8038029C: beq         $s0, $zero, L_803802A8
    if (ctx->r16 == 0) {
        // 0x803802A0: sw          $t5, 0xB8($s0)
        MEM_W(0XB8, ctx->r16) = ctx->r13;
            goto L_803802A8;
    }
    // 0x803802A0: sw          $t5, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r13;
    // 0x803802A4: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
L_803802A8:
    // 0x803802A8: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x803802AC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803802B0: beq         $s0, $zero, L_803802BC
    if (ctx->r16 == 0) {
        // 0x803802B4: sh          $t6, 0x48($sp)
        MEM_H(0X48, ctx->r29) = ctx->r14;
            goto L_803802BC;
    }
    // 0x803802B4: sh          $t6, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r14;
    // 0x803802B8: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
L_803802BC:
    // 0x803802BC: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x803802C0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x803802C4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x803802C8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x803802CC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803802D0: sh          $t7, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r15;
    // 0x803802D4: sh          $t8, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r24;
    // 0x803802D8: jal         0x8037C0CC
    // 0x803802DC: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    func_ovl8_8037C0CC(rdram, ctx);
        goto after_1;
    // 0x803802DC: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    after_1:
    // 0x803802E0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x803802E4: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    // 0x803802E8: jal         0x8037A8BC
    // 0x803802EC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_ovl8_8037A8BC(rdram, ctx);
        goto after_2;
    // 0x803802EC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x803802F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x803802F4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x803802F8: jal         0x8037A8BC
    // 0x803802FC: addiu       $a0, $a0, 0x5C
    ctx->r4 = ADD32(ctx->r4, 0X5C);
    func_ovl8_8037A8BC(rdram, ctx);
        goto after_3;
    // 0x803802FC: addiu       $a0, $a0, 0x5C
    ctx->r4 = ADD32(ctx->r4, 0X5C);
    after_3:
    // 0x80380300: lh          $t1, 0x48($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X48);
    // 0x80380304: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x80380308: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8038030C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80380310: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80380314: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x80380318: lh          $t3, 0x4A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X4A);
    // 0x8038031C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80380320: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80380324: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x80380328: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8038032C: sh          $t9, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r25;
    // 0x80380330: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x80380334: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80380338: beq         $s0, $zero, L_80380344
    if (ctx->r16 == 0) {
        // 0x8038033C: sh          $t6, 0x8($t7)
        MEM_H(0X8, ctx->r15) = ctx->r14;
            goto L_80380344;
    }
    // 0x8038033C: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80380340: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
L_80380344:
    // 0x80380344: lhu         $t8, 0x6($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X6);
    // 0x80380348: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8038034C: beq         $s0, $zero, L_80380358
    if (ctx->r16 == 0) {
        // 0x80380350: sw          $t8, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r24;
            goto L_80380358;
    }
    // 0x80380350: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80380354: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
L_80380358:
    // 0x80380358: lhu         $t0, 0x8($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X8);
    // 0x8038035C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80380360: jal         0x8037B85C
    // 0x80380364: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_ovl8_8037B85C(rdram, ctx);
        goto after_4;
    // 0x80380364: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_4:
    // 0x80380368: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8038036C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80380370: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80380374: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80380378: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8038037C: jal         0x8037ACAC
    // 0x80380380: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_5;
    // 0x80380380: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_5:
    // 0x80380384: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x80380388: sw          $v0, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r2;
    // 0x8038038C: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x80380390: lw          $t9, 0xBC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XBC);
    // 0x80380394: lh          $t2, 0xB8($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XB8);
    // 0x80380398: jalr        $t9
    // 0x8038039C: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8038039C: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    after_6:
    // 0x803803A0: lui         $t3, 0x8038
    ctx->r11 = S32(0X8038 << 16);
    // 0x803803A4: addiu       $t3, $t3, -0x416C
    ctx->r11 = ADD32(ctx->r11, -0X416C);
    // 0x803803A8: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x803803AC: lui         $a3, 0x8038
    ctx->r7 = S32(0X8038 << 16);
    // 0x803803B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x803803B4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x803803B8: addiu       $a3, $a3, -0x41CC
    ctx->r7 = ADD32(ctx->r7, -0X41CC);
    // 0x803803BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x803803C0: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x803803C4: jal         0x803723AC
    // 0x803803C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_ovl8_803723AC(rdram, ctx);
        goto after_7;
    // 0x803803C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x803803CC: beq         $s0, $zero, L_803803D8
    if (ctx->r16 == 0) {
        // 0x803803D0: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_803803D8;
    }
    // 0x803803D0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803803D4: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
L_803803D8:
    // 0x803803D8: beq         $s0, $zero, L_803803E4
    if (ctx->r16 == 0) {
        // 0x803803DC: or          $a3, $s0, $zero
        ctx->r7 = ctx->r16 | 0;
            goto L_803803E4;
    }
    // 0x803803DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x803803E0: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
L_803803E4:
    // 0x803803E4: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x803803E8: lh          $a1, 0x2($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X2);
    // 0x803803EC: lh          $a2, 0x4($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X4);
    // 0x803803F0: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x803803F4: lh          $t5, 0x50($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X50);
    // 0x803803F8: jalr        $t9
    // 0x803803FC: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x803803FC: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    after_8:
    // 0x80380400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80380404: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80380408: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8038040C: jr          $ra
    // 0x80380410: nop

    return;
    // 0x80380410: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueGetScoreDigitCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131C38: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131C3C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80131C40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131C44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131C48: blez        $a1, L_80131CC0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80131C4C: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80131CC0;
    }
    // 0x80131C4C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80131C50:
    // 0x80131C50: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80131C54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80131C58: jal         0x80131B58
    // 0x80131C5C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    mnPlayers1PGameContinueGetPowerOf(rdram, ctx);
        goto after_0;
    // 0x80131C5C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80131C60: beq         $v0, $zero, L_80131CA8
    if (ctx->r2 == 0) {
        // 0x80131C64: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131CA8;
    }
    // 0x80131C64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131C68: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80131C6C: jal         0x80131B58
    // 0x80131C70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PGameContinueGetPowerOf(rdram, ctx);
        goto after_1;
    // 0x80131C70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80131C74: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80131C78: mflo        $v1
    ctx->r3 = lo;
    // 0x80131C7C: bne         $v0, $zero, L_80131C88
    if (ctx->r2 != 0) {
        // 0x80131C80: nop
    
            goto L_80131C88;
    }
    // 0x80131C80: nop

    // 0x80131C84: break       7
    do_break(2148736132);
L_80131C88:
    // 0x80131C88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131C8C: bne         $v0, $at, L_80131CA0
    if (ctx->r2 != ctx->r1) {
        // 0x80131C90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131CA0;
    }
    // 0x80131C90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131C94: bne         $s2, $at, L_80131CA0
    if (ctx->r18 != ctx->r1) {
        // 0x80131C98: nop
    
            goto L_80131CA0;
    }
    // 0x80131C98: nop

    // 0x80131C9C: break       6
    do_break(2148736156);
L_80131CA0:
    // 0x80131CA0: b           L_80131CA8
    // 0x80131CA4: nop

        goto L_80131CA8;
    // 0x80131CA4: nop

L_80131CA8:
    // 0x80131CA8: beq         $v1, $zero, L_80131CB8
    if (ctx->r3 == 0) {
        // 0x80131CAC: nop
    
            goto L_80131CB8;
    }
    // 0x80131CAC: nop

    // 0x80131CB0: b           L_80131CC4
    // 0x80131CB4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80131CC4;
    // 0x80131CB4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80131CB8:
    // 0x80131CB8: bne         $s0, $zero, L_80131C50
    if (ctx->r16 != 0) {
        // 0x80131CBC: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80131C50;
    }
    // 0x80131CBC: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80131CC0:
    // 0x80131CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131CC4:
    // 0x80131CC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131CC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131CCC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CD0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131CD4: jr          $ra
    // 0x80131CD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131CD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonJumpAerialProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013FB2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013FB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013FB34: jal         0x80150F08
    // 0x8013FB38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonSpecialAirCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013FB38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013FB3C: bnel        $v0, $zero, L_8013FB60
    if (ctx->r2 != 0) {
        // 0x8013FB40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013FB60;
    }
    goto skip_0;
    // 0x8013FB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013FB44: jal         0x80150B00
    // 0x8013FB48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonAttackAirCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013FB48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013FB4C: bnel        $v0, $zero, L_8013FB60
    if (ctx->r2 != 0) {
        // 0x8013FB50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013FB60;
    }
    goto skip_1;
    // 0x8013FB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013FB54: jal         0x8014019C
    // 0x8013FB58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonJumpAerialCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8013FB58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8013FB5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013FB60:
    // 0x8013FB60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013FB64: jr          $ra
    // 0x8013FB68: nop

    return;
    // 0x8013FB68: nop

;}
RECOMP_FUNC void scExplainProcUpdateControlStickSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D6DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D6E4: jal         0x8000DF34
    // 0x8018D6E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x8018D6E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D6EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8018D6F0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018D6F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D6F8: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8018D6FC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D700: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x8018D704: lwc1        $f6, 0xA0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XA0);
    // 0x8018D708: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8018D70C: nop

    // 0x8018D710: bc1fl       L_8018D73C
    if (!c1cs) {
        // 0x8018D714: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D73C;
    }
    goto skip_0;
    // 0x8018D714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D718: lbu         $v0, -0x15DF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X15DF);
    // 0x8018D71C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018D720: beq         $v0, $at, L_8018D730
    if (ctx->r2 == ctx->r1) {
        // 0x8018D724: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8018D730;
    }
    // 0x8018D724: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8018D728: bnel        $v0, $at, L_8018D73C
    if (ctx->r2 != ctx->r1) {
        // 0x8018D72C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D73C;
    }
    goto skip_1;
    // 0x8018D72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8018D730:
    // 0x8018D730: jal         0x8018D8E8
    // 0x8018D734: nop

    scExplainUpdateTapSparkEffect(rdram, ctx);
        goto after_1;
    // 0x8018D734: nop

    after_1:
    // 0x8018D738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D73C:
    // 0x8018D73C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D740: jr          $ra
    // 0x8018D744: nop

    return;
    // 0x8018D744: nop

;}
RECOMP_FUNC void gmCameraSetStatusPlayerZoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CF44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CF48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010CF50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010CF54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010CF58: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010CF5C: jal         0x8010CEF4
    // 0x8010CF60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gmCameraSetStatus(rdram, ctx);
        goto after_0;
    // 0x8010CF60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8010CF64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010CF68: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010CF6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CF70: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8010CF74: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010CF78: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010CF7C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010CF80: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010CF84: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010CF88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CF8C: sw          $t6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r14;
    // 0x8010CF90: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x8010CF94: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    // 0x8010CF98: swc1        $f8, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f8.u32l;
    // 0x8010CF9C: swc1        $f10, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f10.u32l;
    // 0x8010CFA0: jr          $ra
    // 0x8010CFA4: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x8010CFA4: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void ifCommonAnnounceFailureInitInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114DD4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80114DD8: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80114DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114DE4: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80114DE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80114DEC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80114DF0: beq         $t7, $at, L_80114E14
    if (ctx->r15 == ctx->r1) {
        // 0x80114DF4: addiu       $a0, $a0, 0x4B40
        ctx->r4 = ADD32(ctx->r4, 0X4B40);
            goto L_80114E14;
    }
    // 0x80114DF4: addiu       $a0, $a0, 0x4B40
    ctx->r4 = ADD32(ctx->r4, 0X4B40);
    // 0x80114DF8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80114DFC: addiu       $a1, $a1, 0x42B4
    ctx->r5 = ADD32(ctx->r5, 0X42B4);
    // 0x80114E00: addiu       $a2, $zero, 0x1CC
    ctx->r6 = ADD32(0, 0X1CC);
    // 0x80114E04: jal         0x80114B80
    // 0x80114E08: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    ifCommonBattleSetInterface(rdram, ctx);
        goto after_0;
    // 0x80114E08: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    after_0:
    // 0x80114E0C: jal         0x80114A48
    // 0x80114E10: nop

    ifCommonAnnounceFailureMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80114E10: nop

    after_1:
L_80114E14:
    // 0x80114E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114E1C: jr          $ra
    // 0x80114E20: nop

    return;
    // 0x80114E20: nop

;}
RECOMP_FUNC void func_ovl8_803743C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803743C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x803743C4: jr          $ra
    // 0x803743C8: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
    return;
    // 0x803743C8: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_ovl29_801347F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801347F0: jr          $ra
    // 0x801347F4: nop

    return;
    // 0x801347F4: nop

;}
RECOMP_FUNC void gcSetMatAnimJointSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BBB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000BBB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000BBB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000BBBC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000BBC0: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8000BBC4: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8000BBC8: beql        $s0, $zero, L_8000BC00
    if (ctx->r16 == 0) {
        // 0x8000BBCC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000BC00;
    }
    goto skip_0;
    // 0x8000BBCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8000BBD0:
    // 0x8000BBD0: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
    // 0x8000BBD4: beq         $v0, $zero, L_8000BBEC
    if (ctx->r2 == 0) {
        // 0x8000BBD8: nop
    
            goto L_8000BBEC;
    }
    // 0x8000BBD8: nop

    // 0x8000BBDC: swc1        $f20, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f20.u32l;
L_8000BBE0:
    // 0x8000BBE0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000BBE4: bnel        $v0, $zero, L_8000BBE0
    if (ctx->r2 != 0) {
        // 0x8000BBE8: swc1        $f20, 0x9C($v0)
        MEM_W(0X9C, ctx->r2) = ctx->f20.u32l;
            goto L_8000BBE0;
    }
    goto skip_1;
    // 0x8000BBE8: swc1        $f20, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f20.u32l;
    skip_1:
L_8000BBEC:
    // 0x8000BBEC: jal         0x8000BAA0
    // 0x8000BBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_0;
    // 0x8000BBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BBF4: bne         $v0, $zero, L_8000BBD0
    if (ctx->r2 != 0) {
        // 0x8000BBF8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000BBD0;
    }
    // 0x8000BBF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000BBFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000BC00:
    // 0x8000BC00: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000BC04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000BC08: jr          $ra
    // 0x8000BC0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000BC0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void scStaffrollStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801351B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801351BC: lui         $v0, 0x8023
    ctx->r2 = S32(0X8023 << 16);
    // 0x801351C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801351C4: ori         $v0, $v0, 0xE000
    ctx->r2 = ctx->r2 | 0XE000;
    // 0x801351C8: lui         $a1, 0x8040
    ctx->r5 = S32(0X8040 << 16);
L_801351CC:
    // 0x801351CC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801351D0: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x801351D4: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x801351D8: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x801351DC: bne         $v0, $a1, L_801351CC
    if (ctx->r2 != ctx->r5) {
        // 0x801351E0: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_801351CC;
    }
    // 0x801351E0: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801351E4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801351E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801351EC: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801351F0: addiu       $a0, $a0, -0x58F8
    ctx->r4 = ADD32(ctx->r4, -0X58F8);
    // 0x801351F4: addiu       $t7, $t6, -0x3200
    ctx->r15 = ADD32(ctx->r14, -0X3200);
    // 0x801351F8: jal         0x80007024
    // 0x801351FC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801351FC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80135200: lui         $t8, 0x8023
    ctx->r24 = S32(0X8023 << 16);
    // 0x80135204: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80135208: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8013520C: addiu       $t9, $t9, -0x55A0
    ctx->r25 = ADD32(ctx->r25, -0X55A0);
    // 0x80135210: ori         $t8, $t8, 0xE000
    ctx->r24 = ctx->r24 | 0XE000;
    // 0x80135214: addiu       $a0, $a0, -0x58DC
    ctx->r4 = ADD32(ctx->r4, -0X58DC);
    // 0x80135218: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8013521C: jal         0x8000683C
    // 0x80135220: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80135220: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80135224: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80135228: addiu       $v0, $v1, 0x2A00
    ctx->r2 = ADD32(ctx->r3, 0X2A00);
    // 0x8013522C: lui         $a1, 0x8040
    ctx->r5 = S32(0X8040 << 16);
    // 0x80135230: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80135234: beq         $at, $zero, L_8013524C
    if (ctx->r1 == 0) {
        // 0x80135238: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8013524C;
    }
    // 0x80135238: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013523C:
    // 0x8013523C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80135240: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80135244: bne         $at, $zero, L_8013523C
    if (ctx->r1 != 0) {
        // 0x80135248: sh          $v1, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r3;
            goto L_8013523C;
    }
    // 0x80135248: sh          $v1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r3;
L_8013524C:
    // 0x8013524C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135254: jr          $ra
    // 0x80135258: nop

    return;
    // 0x80135258: nop

;}
RECOMP_FUNC void mnScreenAdjustBackupOffsets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013204C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132050: lwc1        $f4, 0x2928($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x80132054: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132058: addiu       $v0, $v0, 0x44E0
    ctx->r2 = ADD32(ctx->r2, 0X44E0);
    // 0x8013205C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80132060: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013206C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80132070: nop

    // 0x80132074: sh          $t7, 0x452($v0)
    MEM_H(0X452, ctx->r2) = ctx->r15;
    // 0x80132078: lwc1        $f8, 0x292C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X292C);
    // 0x8013207C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80132080: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80132084: jal         0x800D45F4
    // 0x80132088: sh          $t9, 0x454($v0)
    MEM_H(0X454, ctx->r2) = ctx->r25;
    lbBackupWrite(rdram, ctx);
        goto after_0;
    // 0x80132088: sh          $t9, 0x454($v0)
    MEM_H(0X454, ctx->r2) = ctx->r25;
    after_0:
    // 0x8013208C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132094: jr          $ra
    // 0x80132098: nop

    return;
    // 0x80132098: nop

;}
RECOMP_FUNC void mnPlayersVSMakeStockSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134198: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013419C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801341A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801341A4: lw          $a0, -0x4288($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4288);
    // 0x801341A8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801341AC: beq         $a0, $zero, L_801341BC
    if (ctx->r4 == 0) {
        // 0x801341B0: nop
    
            goto L_801341BC;
    }
    // 0x801341B0: nop

    // 0x801341B4: jal         0x80009A84
    // 0x801341B8: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801341B8: nop

    after_0:
L_801341BC:
    // 0x801341BC: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801341C0: lw          $t9, -0x3B60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3B60);
    // 0x801341C4: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801341C8: addiu       $t0, $t0, 0x5270
    ctx->r8 = ADD32(ctx->r8, 0X5270);
    // 0x801341CC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801341D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801341D4: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x801341D8: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x801341DC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801341E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801341E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801341E8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801341EC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801341F0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801341F4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801341F8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801341FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80134200: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134204: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80134208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013420C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134210: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80134214: jal         0x800CD050
    // 0x80134218: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_1;
    // 0x80134218: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_1:
    // 0x8013421C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134220: sw          $v0, -0x4288($at)
    MEM_W(-0X4288, ctx->r1) = ctx->r2;
    // 0x80134224: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80134228: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013422C: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80134230: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80134234: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134238: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x8013423C: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80134240: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80134244: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
    // 0x80134248: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013424C: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80134250: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80134254: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x80134258: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013425C: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80134260: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80134264: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80134268: lw          $a0, -0x4280($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4280);
    // 0x8013426C: jal         0x80134094
    // 0x80134270: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    mnPlayersVSMakeStockSetting(rdram, ctx);
        goto after_2;
    // 0x80134270: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_2:
    // 0x80134274: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80134278: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013427C: jr          $ra
    // 0x80134280: nop

    return;
    // 0x80134280: nop

;}
RECOMP_FUNC void grZebesAcidUpdateRise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010833C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80108340: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80108344: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80108348: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8010834C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80108350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108354: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80108358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010835C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80108360: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80108364: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80108368: swc1        $f10, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f10.u32l;
    // 0x8010836C: lhu         $t8, 0x14($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X14);
    // 0x80108370: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80108374: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80108378: bne         $t0, $zero, L_801083AC
    if (ctx->r8 != 0) {
        // 0x8010837C: sh          $t9, 0x14($v0)
        MEM_H(0X14, ctx->r2) = ctx->r25;
            goto L_801083AC;
    }
    // 0x8010837C: sh          $t9, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r25;
    // 0x80108380: lbu         $t2, 0x17($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X17);
    // 0x80108384: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80108388: sb          $t1, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r9;
    // 0x8010838C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80108390: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80108394: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x80108398: bne         $at, $zero, L_801083A4
    if (ctx->r1 != 0) {
        // 0x8010839C: sb          $t3, 0x17($v0)
        MEM_B(0X17, ctx->r2) = ctx->r11;
            goto L_801083A4;
    }
    // 0x8010839C: sb          $t3, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r11;
    // 0x801083A0: sb          $zero, 0x17($v0)
    MEM_B(0X17, ctx->r2) = 0;
L_801083A4:
    // 0x801083A4: jal         0x80108088
    // 0x801083A8: nop

    grZebesAcidSetRandomWait(rdram, ctx);
        goto after_0;
    // 0x801083A8: nop

    after_0:
L_801083AC:
    // 0x801083AC: jal         0x80108268
    // 0x801083B0: nop

    grZebesAcidUpdateRumble(rdram, ctx);
        goto after_1;
    // 0x801083B0: nop

    after_1:
    // 0x801083B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801083B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801083BC: jr          $ra
    // 0x801083C0: nop

    return;
    // 0x801083C0: nop

;}
RECOMP_FUNC void ftCommonDamageSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801405E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801405E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801405EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801405F0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801405F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801405F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801405FC: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x80140600: addiu       $t7, $zero, 0x1400
    ctx->r15 = ADD32(0, 0X1400);
    // 0x80140604: bnel        $t6, $zero, L_80140664
    if (ctx->r14 != 0) {
        // 0x80140608: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80140664;
    }
    goto skip_0;
    // 0x80140608: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8014060C: lw          $a1, 0xB44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB44);
    // 0x80140610: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80140614: jal         0x800E6F24
    // 0x80140618: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80140618: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8014061C: jal         0x800E0830
    // 0x80140620: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80140620: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80140624: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80140628: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x8014062C: bnel        $t8, $at, L_80140640
    if (ctx->r24 != ctx->r1) {
        // 0x80140630: lbu         $t0, 0x18F($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X18F);
            goto L_80140640;
    }
    goto skip_1;
    // 0x80140630: lbu         $t0, 0x18F($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18F);
    skip_1:
    // 0x80140634: jal         0x80140744
    // 0x80140638: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonDamageFlyRollUpdateModelPitch(rdram, ctx);
        goto after_2;
    // 0x80140638: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8014063C: lbu         $t0, 0x18F($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18F);
L_80140640:
    // 0x80140640: lw          $t2, 0xB48($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB48);
    // 0x80140644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80140648: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8014064C: beq         $t2, $zero, L_80140660
    if (ctx->r10 == 0) {
        // 0x80140650: sb          $t1, 0x18F($s0)
        MEM_B(0X18F, ctx->r16) = ctx->r9;
            goto L_80140660;
    }
    // 0x80140650: sb          $t1, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r9;
    // 0x80140654: sw          $zero, 0xB48($s0)
    MEM_W(0XB48, ctx->r16) = 0;
    // 0x80140658: jal         0x800EA8EC
    // 0x8014065C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetTimedHitStatusInvincible(rdram, ctx);
        goto after_3;
    // 0x8014065C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80140660:
    // 0x80140660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80140664:
    // 0x80140664: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80140668: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014066C: jr          $ra
    // 0x80140670: nop

    return;
    // 0x80140670: nop

;}
RECOMP_FUNC void n_alSynStartVoiceParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DB84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DB88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DB8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002DB90: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002DB94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8002DB98: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8002DB9C: beql        $t6, $zero, L_8002DC58
    if (ctx->r14 == 0) {
        // 0x8002DBA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002DC58;
    }
    goto skip_0;
    // 0x8002DBA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002DBA4: jal         0x8002C618
    // 0x8002DBA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002DBA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002DBAC: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    // 0x8002DBB0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002DBB4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002DBB8: bgez        $a1, L_8002DBC8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8002DBBC: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8002DBC8;
    }
    // 0x8002DBBC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8002DBC0: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    // 0x8002DBC4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8002DBC8:
    // 0x8002DBC8: beq         $v0, $zero, L_8002DC54
    if (ctx->r2 == 0) {
        // 0x8002DBCC: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_8002DC54;
    }
    // 0x8002DBCC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002DBD0: lw          $t7, -0x2CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CEC);
    // 0x8002DBD4: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x8002DBD8: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x8002DBDC: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8002DBE0: lw          $t1, 0x88($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X88);
    // 0x8002DBE4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8002DBE8: sh          $t3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r11;
    // 0x8002DBEC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8002DBF0: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x8002DBF4: lh          $t4, 0x1A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X1A);
    // 0x8002DBF8: addiu       $t7, $zero, 0x5F
    ctx->r15 = ADD32(0, 0X5F);
    // 0x8002DBFC: sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
    // 0x8002DC00: lbu         $t5, 0x33($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X33);
    // 0x8002DC04: sb          $t5, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r13;
    // 0x8002DC08: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x8002DC0C: sb          $a1, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r5;
    // 0x8002DC10: sb          $zero, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = 0;
    // 0x8002DC14: sb          $t7, 0x1D($a2)
    MEM_B(0X1D, ctx->r6) = ctx->r15;
    // 0x8002DC18: sh          $t6, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r14;
    // 0x8002DC1C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002DC20: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x8002DC24: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8002DC28: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8002DC2C: jal         0x8002C54C
    // 0x8002DC30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _n_timeToSamples(rdram, ctx);
        goto after_1;
    // 0x8002DC30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8002DC34: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DC38: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002DC3C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002DC40: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x8002DC44: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002DC48: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x8002DC4C: jal         0x8002A230
    // 0x8002DC50: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    n_alEnvmixerParam(rdram, ctx);
        goto after_2;
    // 0x8002DC50: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    after_2:
L_8002DC54:
    // 0x8002DC54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002DC58:
    // 0x8002DC58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DC5C: jr          $ra
    // 0x8002DC60: nop

    return;
    // 0x8002DC60: nop

;}
RECOMP_FUNC void sc1PGameSetupFiles(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8018D0E0: addiu       $t8, $t8, 0x3068
    ctx->r24 = ADD32(ctx->r24, 0X3068);
    // 0x8018D0E4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8018D0E8: addiu       $t0, $t0, 0x3388
    ctx->r8 = ADD32(ctx->r8, 0X3388);
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
    // 0x8018D118: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018D11C: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018D120: jal         0x800CDEEC
    // 0x8018D124: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018D124: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
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
    // 0x8018D134: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018D138: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018D13C: addiu       $a2, $a2, 0xD40
    ctx->r6 = ADD32(ctx->r6, 0XD40);
    // 0x8018D140: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018D144: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
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
RECOMP_FUNC void wpPikachuThunderHeadProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016A798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A79C: jal         0x80167C04
    // 0x8016A7A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8016A7A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016A7A4: beq         $v0, $zero, L_8016A7D4
    if (ctx->r2 == 0) {
        // 0x8016A7A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8016A7D4;
    }
    // 0x8016A7A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8016A7AC: jal         0x8016A640
    // 0x8016A7B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpPikachuThunderHeadSetDestroy(rdram, ctx);
        goto after_1;
    // 0x8016A7B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8016A7B4: jal         0x801008F4
    // 0x8016A7B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8016A7B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8016A7BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016A7C0: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8016A7C4: jal         0x80100480
    // 0x8016A7C8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8016A7C8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8016A7CC: b           L_8016A7D8
    // 0x8016A7D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A7D8;
    // 0x8016A7D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A7D4:
    // 0x8016A7D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A7D8:
    // 0x8016A7D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016A7DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016A7E0: jr          $ra
    // 0x8016A7E4: nop

    return;
    // 0x8016A7E4: nop

;}
RECOMP_FUNC void ftCommonGuardCheckInterruptEscape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80148F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148F2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80148F30: lhu         $t6, 0x1BC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BC);
    // 0x80148F34: lhu         $t7, 0x1B8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B8);
    // 0x80148F38: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80148F3C: beql        $t8, $zero, L_80148F64
    if (ctx->r24 == 0) {
        // 0x80148F40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80148F64;
    }
    goto skip_0;
    // 0x80148F40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80148F44: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80148F48: beql        $t9, $zero, L_80148F64
    if (ctx->r25 == 0) {
        // 0x80148F4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80148F64;
    }
    goto skip_1;
    // 0x80148F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80148F50: jal         0x80148E30
    // 0x80148F54: nop

    ftCommonGuardSetStatusFromEscape(rdram, ctx);
        goto after_0;
    // 0x80148F54: nop

    after_0:
    // 0x80148F58: b           L_80148F64
    // 0x80148F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80148F64;
    // 0x80148F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80148F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80148F64:
    // 0x80148F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80148F6C: jr          $ra
    // 0x80148F70: nop

    return;
    // 0x80148F70: nop

;}
RECOMP_FUNC void mnOptionSetSoundToggleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D2C: beq         $a1, $zero, L_80131D64
    if (ctx->r5 == 0) {
        // 0x80131D30: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80131D64;
    }
    // 0x80131D30: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131D34: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131D38: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80131D3C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80131D40: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131D44: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131D48: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131D4C: sb          $a0, 0x28($t6)
    MEM_B(0X28, ctx->r14) = ctx->r4;
    // 0x80131D50: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80131D54: sb          $a0, 0x29($t7)
    MEM_B(0X29, ctx->r15) = ctx->r4;
    // 0x80131D58: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80131D5C: jr          $ra
    // 0x80131D60: sb          $a0, 0x2A($t8)
    MEM_B(0X2A, ctx->r24) = ctx->r4;
    return;
    // 0x80131D60: sb          $a0, 0x2A($t8)
    MEM_B(0X2A, ctx->r24) = ctx->r4;
L_80131D64:
    // 0x80131D64: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80131D68: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80131D6C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131D70: sb          $a0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r4;
    // 0x80131D74: sb          $a0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r4;
    // 0x80131D78: sb          $a0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r4;
    // 0x80131D7C: sb          $v1, 0x28($t9)
    MEM_B(0X28, ctx->r25) = ctx->r3;
    // 0x80131D80: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80131D84: sb          $v1, 0x29($t0)
    MEM_B(0X29, ctx->r8) = ctx->r3;
    // 0x80131D88: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80131D8C: sb          $v1, 0x2A($t1)
    MEM_B(0X2A, ctx->r9) = ctx->r3;
    // 0x80131D90: jr          $ra
    // 0x80131D94: nop

    return;
    // 0x80131D94: nop

;}
RECOMP_FUNC void mnVSOptionsMakeTeamAttackOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132968: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013296C: lw          $t6, 0x4904($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4904);
    // 0x80132970: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132974: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132978: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8013297C: beq         $t6, $zero, L_8013298C
    if (ctx->r14 == 0) {
        // 0x80132980: sw          $s0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r16;
            goto L_8013298C;
    }
    // 0x80132980: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80132984: b           L_80132990
    // 0x80132988: addiu       $s1, $zero, 0x5A
    ctx->r17 = ADD32(0, 0X5A);
        goto L_80132990;
    // 0x80132988: addiu       $s1, $zero, 0x5A
    ctx->r17 = ADD32(0, 0X5A);
L_8013298C:
    // 0x8013298C: addiu       $s1, $zero, 0x61
    ctx->r17 = ADD32(0, 0X61);
L_80132990:
    // 0x80132990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132998: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8013299C: jal         0x80009968
    // 0x801329A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801329A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801329A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329A8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801329AC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801329B0: sw          $v0, 0x48C4($at)
    MEM_W(0X48C4, ctx->r1) = ctx->r2;
    // 0x801329B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801329B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801329BC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801329C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801329C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801329C8: jal         0x80009DF4
    // 0x801329CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801329CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801329D0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801329D4: lw          $t8, 0x49DC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X49DC);
    // 0x801329D8: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801329DC: addiu       $t9, $t9, 0x33D8
    ctx->r25 = ADD32(ctx->r25, 0X33D8);
    // 0x801329E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801329E4: jal         0x800CCFDC
    // 0x801329E8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801329E8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x801329EC: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x801329F0: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x801329F4: lui         $at, 0x42D4
    ctx->r1 = S32(0X42D4 << 16);
    // 0x801329F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801329FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132A00: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132A04: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132A08: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132A0C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132A10: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132A14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132A18: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132A1C: lw          $a1, 0x48E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E0);
    // 0x80132A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A24: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    // 0x80132A28: jal         0x80131F74
    // 0x80132A2C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80132A2C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80132A30: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132A34: lw          $t4, 0x49DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X49DC);
    // 0x80132A38: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80132A3C: addiu       $t5, $t5, 0x3968
    ctx->r13 = ADD32(ctx->r13, 0X3968);
    // 0x80132A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A44: jal         0x800CCFDC
    // 0x80132A48: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132A48: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x80132A4C: addiu       $t1, $s1, 0x1
    ctx->r9 = ADD32(ctx->r17, 0X1);
    // 0x80132A50: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80132A54: addiu       $t0, $s1, 0x2
    ctx->r8 = ADD32(ctx->r17, 0X2);
    // 0x80132A58: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80132A5C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132A60: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132A64: lui         $at, 0x42E8
    ctx->r1 = S32(0X42E8 << 16);
    // 0x80132A68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132A6C: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132A70: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132A74: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132A78: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132A7C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80132A80: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132A84: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132A88: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132A8C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132A90: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A98: lui         $a1, 0x4354
    ctx->r5 = S32(0X4354 << 16);
    // 0x80132A9C: jal         0x80132078
    // 0x80132AA0: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    mnVSOptionsMakeOnOffToggle(rdram, ctx);
        goto after_5;
    // 0x80132AA0: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    after_5:
    // 0x80132AA4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132AA8: lw          $a1, 0x48E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E8);
    // 0x80132AAC: jal         0x80131FFC
    // 0x80132AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSOptionsSetToggleSpriteColors(rdram, ctx);
        goto after_6;
    // 0x80132AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80132AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132AB8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80132ABC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132AC0: jr          $ra
    // 0x80132AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80132AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayers1PBonusResetPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134724: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134728: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x8013472C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134734: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x80134738: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8013473C: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x80134740: sw          $a0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r4;
    // 0x80134744: sw          $a0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r4;
    // 0x80134748: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x8013474C: jal         0x80134BB0
    // 0x80134750: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    mnPlayers1PBonusUpdateCursorGrabPriorities(rdram, ctx);
        goto after_0;
    // 0x80134750: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_0:
    // 0x80134754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134758: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013475C: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x80134760: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x80134764: jr          $ra
    // 0x80134768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80134768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_ovl8_80371960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371960: jr          $ra
    // 0x80371964: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371964: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void wpLinkBoomerangMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DA78: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8016DA7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016DA80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8016DA84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8016DA88: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8016DA8C: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x8016DA90: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8016DA94: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8016DA98: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8016DA9C: lui         $at, 0x4391
    ctx->r1 = S32(0X4391 << 16);
    // 0x8016DAA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016DAA4: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8016DAA8: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x8016DAAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016DAB0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016DAB4: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x8016DAB8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8016DABC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8016DAC0: addiu       $a1, $a1, -0x6C60
    ctx->r5 = ADD32(ctx->r5, -0X6C60);
    // 0x8016DAC4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016DAC8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8016DACC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016DAD0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8016DAD4: lw          $t8, 0x44($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X44);
    // 0x8016DAD8: bne         $t8, $at, L_8016DAF4
    if (ctx->r24 != ctx->r1) {
        // 0x8016DADC: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_8016DAF4;
    }
    // 0x8016DADC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8016DAE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016DAE4: nop

    // 0x8016DAE8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016DAEC: b           L_8016DB08
    // 0x8016DAF0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
        goto L_8016DB08;
    // 0x8016DAF0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_8016DAF4:
    // 0x8016DAF4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8016DAF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016DAFC: nop

    // 0x8016DB00: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8016DB04: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
L_8016DB08:
    // 0x8016DB08: jal         0x801655C8
    // 0x8016DB0C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016DB0C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016DB10: bne         $v0, $zero, L_8016DB20
    if (ctx->r2 != 0) {
        // 0x8016DB14: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_8016DB20;
    }
    // 0x8016DB14: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8016DB18: b           L_8016DBE0
    // 0x8016DB1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016DBE0;
    // 0x8016DB1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016DB20:
    // 0x8016DB20: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x8016DB24: lw          $t9, 0x44($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X44);
    // 0x8016DB28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016DB2C: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x8016DB30: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x8016DB34: lw          $t0, 0xB18($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XB18);
    // 0x8016DB38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8016DB3C: lui         $a3, 0x42AA
    ctx->r7 = S32(0X42AA << 16);
    // 0x8016DB40: bne         $t0, $at, L_8016DB6C
    if (ctx->r8 != ctx->r1) {
        // 0x8016DB44: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_8016DB6C;
    }
    // 0x8016DB44: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8016DB48: addiu       $t1, $zero, 0xBE
    ctx->r9 = ADD32(0, 0XBE);
    // 0x8016DB4C: sw          $t1, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r9;
    // 0x8016DB50: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8016DB54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8016DB58: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8016DB5C: jal         0x8016D914
    // 0x8016DB60: lui         $a3, 0x42E4
    ctx->r7 = S32(0X42E4 << 16);
    wpLinkBoomerangGetAngleSetVel(rdram, ctx);
        goto after_1;
    // 0x8016DB60: lui         $a3, 0x42E4
    ctx->r7 = S32(0X42E4 << 16);
    after_1:
    // 0x8016DB64: b           L_8016DB7C
    // 0x8016DB68: swc1        $f0, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->f0.u32l;
        goto L_8016DB7C;
    // 0x8016DB68: swc1        $f0, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->f0.u32l;
L_8016DB6C:
    // 0x8016DB6C: sw          $t2, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r10;
    // 0x8016DB70: jal         0x8016D914
    // 0x8016DB74: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    wpLinkBoomerangGetAngleSetVel(rdram, ctx);
        goto after_2;
    // 0x8016DB74: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_2:
    // 0x8016DB78: swc1        $f0, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->f0.u32l;
L_8016DB7C:
    // 0x8016DB7C: lbu         $t6, 0x26C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X26C);
    // 0x8016DB80: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8016DB84: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8016DB88: addiu       $t3, $t3, -0x2884
    ctx->r11 = ADD32(ctx->r11, -0X2884);
    // 0x8016DB8C: addiu       $t4, $t4, -0x2B48
    ctx->r12 = ADD32(ctx->r12, -0X2B48);
    // 0x8016DB90: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x8016DB94: sw          $t3, 0x28C($s0)
    MEM_W(0X28C, ctx->r16) = ctx->r11;
    // 0x8016DB98: sw          $t4, 0x298($s0)
    MEM_W(0X298, ctx->r16) = ctx->r12;
    // 0x8016DB9C: sb          $t7, 0x26C($s0)
    MEM_B(0X26C, ctx->r16) = ctx->r15;
    // 0x8016DBA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016DBA4: jal         0x80167F08
    // 0x8016DBA8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    wpMainPlayFGM(rdram, ctx);
        goto after_3;
    // 0x8016DBA8: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    after_3:
    // 0x8016DBAC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8016DBB0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8016DBB4: addiu       $t0, $zero, 0x82
    ctx->r8 = ADD32(0, 0X82);
    // 0x8016DBB8: sb          $t9, 0x2A2($s0)
    MEM_B(0X2A2, ctx->r16) = ctx->r25;
    // 0x8016DBBC: sb          $t0, 0x2A1($s0)
    MEM_B(0X2A1, ctx->r16) = ctx->r8;
    // 0x8016DBC0: sb          $zero, 0x2A3($s0)
    MEM_B(0X2A3, ctx->r16) = 0;
    // 0x8016DBC4: sw          $t8, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = ctx->r24;
    // 0x8016DBC8: jal         0x80167FA0
    // 0x8016DBCC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_4;
    // 0x8016DBCC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x8016DBD0: lbu         $t2, 0x260($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X260);
    // 0x8016DBD4: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x8016DBD8: sb          $t3, 0x260($s0)
    MEM_B(0X260, ctx->r16) = ctx->r11;
    // 0x8016DBDC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8016DBE0:
    // 0x8016DBE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016DBE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8016DBE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8016DBEC: jr          $ra
    // 0x8016DBF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8016DBF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftNessSpecialAirLwHoldSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015562C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80155630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155634: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80155638: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015563C: jal         0x800DEE98
    // 0x80155640: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80155640: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80155644: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80155648: addiu       $t7, $zero, 0x97
    ctx->r15 = ADD32(0, 0X97);
    // 0x8015564C: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x80155650: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155654: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155658: jal         0x800E6F24
    // 0x8015565C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015565C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80155660: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80155664: lbu         $t9, 0x18D($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X18D);
    // 0x80155668: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8015566C: sb          $t0, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r8;
    // 0x80155670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155674: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80155678: jr          $ra
    // 0x8015567C: nop

    return;
    // 0x8015567C: nop

;}
RECOMP_FUNC void n_alSynAddSndPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D6A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D6AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D6B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002D6B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8002D6B8: jal         0x80030350
    // 0x8002D6BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8002D6BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8002D6C0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8002D6C4: addiu       $v1, $v1, -0x2CEC
    ctx->r3 = ADD32(ctx->r3, -0X2CEC);
    // 0x8002D6C8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002D6CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8002D6D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002D6D4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8002D6D8: sw          $t7, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r15;
    // 0x8002D6DC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002D6E0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002D6E4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8002D6E8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8002D6EC: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    // 0x8002D6F0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8002D6F4: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8002D6F8: bne         $t1, $zero, L_8002D704
    if (ctx->r9 != 0) {
        // 0x8002D6FC: nop
    
            goto L_8002D704;
    }
    // 0x8002D6FC: nop

    // 0x8002D700: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
L_8002D704:
    // 0x8002D704: jal         0x80030350
    // 0x8002D708: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8002D708: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8002D70C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D714: jr          $ra
    // 0x8002D718: nop

    return;
    // 0x8002D718: nop

;}
RECOMP_FUNC void ftSamusSpecialAirNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D4C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D4C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D4C8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015D4CC: jal         0x800DE6E4
    // 0x8015D4D0: addiu       $a1, $a1, -0x2B1C
    ctx->r5 = ADD32(ctx->r5, -0X2B1C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015D4D0: addiu       $a1, $a1, -0x2B1C
    ctx->r5 = ADD32(ctx->r5, -0X2B1C);
    after_0:
    // 0x8015D4D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D4D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D4DC: jr          $ra
    // 0x8015D4E0: nop

    return;
    // 0x8015D4E0: nop

;}
RECOMP_FUNC void ftCommonCatchProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149A18: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80149A1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80149A20: lwc1        $f0, 0xB18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XB18);
    // 0x80149A24: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80149A28: nop

    // 0x80149A2C: bc1fl       L_80149A5C
    if (!c1cs) {
        // 0x80149A30: lw          $v1, 0x184($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X184);
            goto L_80149A5C;
    }
    goto skip_0;
    // 0x80149A30: lw          $v1, 0x184($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X184);
    skip_0:
    // 0x80149A34: lwc1        $f4, 0xB1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x80149A38: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80149A3C: swc1        $f6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f6.u32l;
    // 0x80149A40: lwc1        $f8, 0xB18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XB18);
    // 0x80149A44: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x80149A48: nop

    // 0x80149A4C: bc1fl       L_80149A5C
    if (!c1cs) {
        // 0x80149A50: lw          $v1, 0x184($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X184);
            goto L_80149A5C;
    }
    goto skip_1;
    // 0x80149A50: lw          $v1, 0x184($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X184);
    skip_1:
    // 0x80149A54: swc1        $f2, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f2.u32l;
    // 0x80149A58: lw          $v1, 0x184($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X184);
L_80149A5C:
    // 0x80149A5C: beq         $v1, $zero, L_80149AB0
    if (ctx->r3 == 0) {
        // 0x80149A60: nop
    
            goto L_80149AB0;
    }
    // 0x80149A60: nop

    // 0x80149A64: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80149A68: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80149A6C: bgez        $v1, L_80149A80
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80149A70: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80149A80;
    }
    // 0x80149A70: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80149A74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80149A78: nop

    // 0x80149A7C: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_80149A80:
    // 0x80149A80: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x80149A84: swc1        $f0, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f0.u32l;
    // 0x80149A88: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80149A8C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80149A90: bgez        $t6, L_80149AA4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80149A94: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80149AA4;
    }
    // 0x80149A94: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80149A98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80149A9C: nop

    // 0x80149AA0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80149AA4:
    // 0x80149AA4: div.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80149AA8: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80149AAC: swc1        $f8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
L_80149AB0:
    // 0x80149AB0: jal         0x800D94C4
    // 0x80149AB4: nop

    ftAnimEndSetWait(rdram, ctx);
        goto after_0;
    // 0x80149AB4: nop

    after_0:
    // 0x80149AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149AC0: jr          $ra
    // 0x80149AC4: nop

    return;
    // 0x80149AC4: nop

;}
RECOMP_FUNC void syUtilsRandSeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800188D8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800188DC: lw          $t6, -0x46BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X46BC);
    // 0x800188E0: jr          $ra
    // 0x800188E4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    return;
    // 0x800188E4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void ftYoshiSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E79C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015E7A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E7A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015E7A8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8015E7AC: addiu       $t6, $t6, -0x1A78
    ctx->r14 = ADD32(ctx->r14, -0X1A78);
    // 0x8015E7B0: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x8015E7B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015E7B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015E7BC: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x8015E7C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015E7C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015E7C8: jal         0x800E6F24
    // 0x8015E7CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015E7CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015E7D0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E7D4: addiu       $a1, $a1, -0x1780
    ctx->r5 = ADD32(ctx->r5, -0X1780);
    // 0x8015E7D8: jal         0x8015E310
    // 0x8015E7DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftYoshiSpecialNSetCatchParams(rdram, ctx);
        goto after_1;
    // 0x8015E7DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8015E7E0: jal         0x800E0830
    // 0x8015E7E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015E7E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015E7E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E7EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015E7F0: jr          $ra
    // 0x8015E7F4: nop

    return;
    // 0x8015E7F4: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetTotalMins(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133570: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133574: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133578: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8013357C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133580: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133584: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80133588: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013358C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_80133590:
    // 0x80133590: jal         0x801322BC
    // 0x80133594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusCheckFighterLocked(rdram, ctx);
        goto after_0;
    // 0x80133594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80133598: bnel        $v0, $zero, L_801335B8
    if (ctx->r2 != 0) {
        // 0x8013359C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801335B8;
    }
    goto skip_0;
    // 0x8013359C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801335A0: jal         0x80133410
    // 0x801335A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusGetBestTime(rdram, ctx);
        goto after_1;
    // 0x801335A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801335A8: jal         0x80133488
    // 0x801335AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PBonusGetMins(rdram, ctx);
        goto after_2;
    // 0x801335AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x801335B0: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x801335B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801335B8:
    // 0x801335B8: bne         $s0, $s2, L_80133590
    if (ctx->r16 != ctx->r18) {
        // 0x801335BC: nop
    
            goto L_80133590;
    }
    // 0x801335BC: nop

    // 0x801335C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801335C4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x801335C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801335CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801335D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801335D4: jr          $ra
    // 0x801335D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801335D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftMainGetGroundHitObstacle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E5C30: lw          $t6, 0x170($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X170);
    // 0x800E5C34: bnel        $t6, $zero, L_800E5D18
    if (ctx->r14 != 0) {
        // 0x800E5C38: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E5D18;
    }
    goto skip_0;
    // 0x800E5C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800E5C3C: lw          $t7, 0x14C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14C);
    // 0x800E5C40: bnel        $t7, $zero, L_800E5D18
    if (ctx->r15 != 0) {
        // 0x800E5C44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E5D18;
    }
    goto skip_1;
    // 0x800E5C44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800E5C48: lw          $v0, 0xEC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XEC);
    // 0x800E5C4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E5C50: beq         $v0, $at, L_800E5D14
    if (ctx->r2 == ctx->r1) {
        // 0x800E5C54: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_800E5D14;
    }
    // 0x800E5C54: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800E5C58: beql        $v0, $at, L_800E5D18
    if (ctx->r2 == ctx->r1) {
        // 0x800E5C5C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E5D18;
    }
    goto skip_2;
    // 0x800E5C5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800E5C60: lw          $t8, 0xF4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XF4);
    // 0x800E5C64: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800E5C68: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x800E5C6C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800E5C70: addiu       $t0, $t9, -0x7
    ctx->r8 = ADD32(ctx->r25, -0X7);
    // 0x800E5C74: sltiu       $at, $t0, 0x9
    ctx->r1 = ctx->r8 < 0X9 ? 1 : 0;
    // 0x800E5C78: beq         $at, $zero, L_800E5D0C
    if (ctx->r1 == 0) {
        // 0x800E5C7C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_800E5D0C;
    }
    // 0x800E5C7C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800E5C80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E5C84: addu        $at, $at, $t0
    gpr jr_addend_800E5C8C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800E5C88: lw          $t0, -0x19C($at)
    ctx->r8 = ADD32(ctx->r1, -0X19C);
    // 0x800E5C8C: jr          $t0
    // 0x800E5C90: nop

    switch (jr_addend_800E5C8C >> 2) {
        case 0: goto L_800E5C94; break;
        case 1: goto L_800E5CA8; break;
        case 2: goto L_800E5CBC; break;
        case 3: goto L_800E5CD0; break;
        case 4: goto L_800E5CE4; break;
        case 5: goto L_800E5D0C; break;
        case 6: goto L_800E5D0C; break;
        case 7: goto L_800E5D0C; break;
        case 8: goto L_800E5CF8; break;
        default: switch_error(__func__, 0x800E5C8C, 0x8012FE64);
    }
    // 0x800E5C90: nop

L_800E5C94:
    // 0x800E5C94: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E5C98: addiu       $t1, $t1, -0x72D0
    ctx->r9 = ADD32(ctx->r9, -0X72D0);
    // 0x800E5C9C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800E5CA0: jr          $ra
    // 0x800E5CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E5CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E5CA8:
    // 0x800E5CA8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800E5CAC: addiu       $t2, $t2, -0x72B4
    ctx->r10 = ADD32(ctx->r10, -0X72B4);
    // 0x800E5CB0: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800E5CB4: jr          $ra
    // 0x800E5CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E5CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E5CBC:
    // 0x800E5CBC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800E5CC0: addiu       $t3, $t3, -0x7298
    ctx->r11 = ADD32(ctx->r11, -0X7298);
    // 0x800E5CC4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800E5CC8: jr          $ra
    // 0x800E5CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E5CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E5CD0:
    // 0x800E5CD0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800E5CD4: addiu       $t4, $t4, -0x727C
    ctx->r12 = ADD32(ctx->r12, -0X727C);
    // 0x800E5CD8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800E5CDC: jr          $ra
    // 0x800E5CE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E5CE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E5CE4:
    // 0x800E5CE4: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800E5CE8: addiu       $t5, $t5, -0x7260
    ctx->r13 = ADD32(ctx->r13, -0X7260);
    // 0x800E5CEC: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800E5CF0: jr          $ra
    // 0x800E5CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E5CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E5CF8:
    // 0x800E5CF8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E5CFC: addiu       $t6, $t6, -0x7244
    ctx->r14 = ADD32(ctx->r14, -0X7244);
    // 0x800E5D00: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800E5D04: jr          $ra
    // 0x800E5D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E5D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E5D0C:
    // 0x800E5D0C: jr          $ra
    // 0x800E5D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E5D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E5D14:
    // 0x800E5D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E5D18:
    // 0x800E5D18: jr          $ra
    // 0x800E5D1C: nop

    return;
    // 0x800E5D1C: nop

;}
RECOMP_FUNC void ifCommonAnnounceTimeUpMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112814: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80112818: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011281C: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80112820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80112824: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80112828: jal         0x80009968
    // 0x8011282C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8011282C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80112830: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80112834: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80112838: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8011283C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80112840: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80112844: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80112848: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8011284C: jal         0x80009DF4
    // 0x80112850: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80112850: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80112854: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80112858: addiu       $a2, $a2, -0x121C
    ctx->r6 = ADD32(ctx->r6, -0X121C);
    // 0x8011285C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80112860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80112864: jal         0x80112024
    // 0x80112868: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    ifCommonAnnounceSetAttr(rdram, ctx);
        goto after_2;
    // 0x80112868: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_2:
    // 0x8011286C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80112870: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80112874: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80112878: jr          $ra
    // 0x8011287C: nop

    return;
    // 0x8011287C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakePortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132798: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8013279C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801327A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801327A4: addiu       $t7, $t7, 0x7234
    ctx->r15 = ADD32(ctx->r15, 0X7234);
    // 0x801327A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801327AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801327B0: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x801327B4: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
L_801327B8:
    // 0x801327B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801327BC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801327C0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801327C4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801327C8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801327CC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801327D0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801327D4: bne         $t7, $t0, L_801327B8
    if (ctx->r15 != ctx->r8) {
        // 0x801327D8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801327B8;
    }
    // 0x801327D8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801327DC: jal         0x80132390
    // 0x801327E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x801327E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801327E4: jal         0x801322BC
    // 0x801327E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PBonusCheckFighterLocked(rdram, ctx);
        goto after_1;
    // 0x801327E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801327EC: beq         $v0, $zero, L_80132804
    if (ctx->r2 == 0) {
        // 0x801327F0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80132804;
    }
    // 0x801327F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801327F4: jal         0x801324F0
    // 0x801327F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusMakePortraitShadow(rdram, ctx);
        goto after_2;
    // 0x801327F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801327FC: b           L_80132A48
    // 0x80132800: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80132A48;
    // 0x80132800: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132804:
    // 0x80132804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132808: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8013280C: jal         0x80009968
    // 0x80132810: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80132810: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80132814: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132818: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013281C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132820: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80132824: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132828: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013282C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132830: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80132834: jal         0x80009DF4
    // 0x80132838: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x80132838: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x8013283C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80132840: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132844: addiu       $a1, $a1, 0x2150
    ctx->r5 = ADD32(ctx->r5, 0X2150);
    // 0x80132848: sw          $s0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r16;
    // 0x8013284C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80132850: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132854: jal         0x80008188
    // 0x80132858: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132858: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8013285C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132860: lw          $t2, 0x7E08($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7E08);
    // 0x80132864: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132868: addiu       $t3, $t3, 0x24D0
    ctx->r11 = ADD32(ctx->r11, 0X24D0);
    // 0x8013286C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80132870: jal         0x800CCFDC
    // 0x80132874: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132874: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x80132878: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x8013287C: bne         $at, $zero, L_8013288C
    if (ctx->r1 != 0) {
        // 0x80132880: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8013288C;
    }
    // 0x80132880: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80132884: b           L_80132890
    // 0x80132888: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
        goto L_80132890;
    // 0x80132888: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
L_8013288C:
    // 0x8013288C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80132890:
    // 0x80132890: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80132894: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80132898: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8013289C: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x801328A0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801328A4: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x801328A8: addiu       $t5, $t4, 0x19
    ctx->r13 = ADD32(ctx->r12, 0X19);
    // 0x801328AC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801328B0: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x801328B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801328B8: bne         $at, $zero, L_801328C8
    if (ctx->r1 != 0) {
        // 0x801328BC: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_801328C8;
    }
    // 0x801328BC: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x801328C0: b           L_801328CC
    // 0x801328C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801328CC;
    // 0x801328C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801328C8:
    // 0x801328C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801328CC:
    // 0x801328CC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801328D0: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801328D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801328D8: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801328DC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801328E0: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801328E4: addiu       $t7, $t0, 0x24
    ctx->r15 = ADD32(ctx->r8, 0X24);
    // 0x801328E8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801328EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801328F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801328F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801328F8: jal         0x801321CC
    // 0x801328FC: swc1        $f10, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f10.u32l;
    mnPlayers1PBonusSetPortraitWallpaperPosition(rdram, ctx);
        goto after_7;
    // 0x801328FC: swc1        $f10, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f10.u32l;
    after_7:
    // 0x80132900: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132908: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x8013290C: jal         0x80009968
    // 0x80132910: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_8;
    // 0x80132910: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_8:
    // 0x80132914: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132918: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8013291C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132920: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132924: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132928: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8013292C: jal         0x80009DF4
    // 0x80132930: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_9;
    // 0x80132930: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_9:
    // 0x80132934: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80132938: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8013293C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132940: jal         0x80008188
    // 0x80132944: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_10;
    // 0x80132944: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80132948: jal         0x80132390
    // 0x8013294C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusGetFighterKind(rdram, ctx);
        goto after_11;
    // 0x8013294C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80132950: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80132954: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80132958: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013295C: lw          $t1, 0x7E08($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7E08);
    // 0x80132960: lw          $t9, 0x34($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X34);
    // 0x80132964: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80132968: jal         0x800CCFDC
    // 0x8013296C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_12;
    // 0x8013296C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_12:
    // 0x80132970: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80132974: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80132978: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8013297C: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80132980: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132984: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80132988: bne         $at, $zero, L_80132998
    if (ctx->r1 != 0) {
        // 0x8013298C: sh          $t5, 0x24($v0)
        MEM_H(0X24, ctx->r2) = ctx->r13;
            goto L_80132998;
    }
    // 0x8013298C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132990: b           L_8013299C
    // 0x80132994: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
        goto L_8013299C;
    // 0x80132994: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
L_80132998:
    // 0x80132998: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_8013299C:
    // 0x8013299C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801329A0: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801329A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801329A8: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801329AC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801329B0: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x801329B4: addiu       $t7, $t0, 0x19
    ctx->r15 = ADD32(ctx->r8, 0X19);
    // 0x801329B8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801329BC: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x801329C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801329C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801329C8: bne         $at, $zero, L_801329D8
    if (ctx->r1 != 0) {
        // 0x801329CC: swc1        $f18, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
            goto L_801329D8;
    }
    // 0x801329CC: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x801329D0: b           L_801329D8
    // 0x801329D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801329D8;
    // 0x801329D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801329D8:
    // 0x801329D8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801329DC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801329E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801329E4: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801329E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801329EC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801329F0: addiu       $t8, $t6, 0x24
    ctx->r24 = ADD32(ctx->r14, 0X24);
    // 0x801329F4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801329F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801329FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132A00: swc1        $f6, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f6.u32l;
    // 0x80132A04: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80132A08: sw          $s0, 0x84($t9)
    MEM_W(0X84, ctx->r25) = ctx->r16;
    // 0x80132A0C: jal         0x80132390
    // 0x80132A10: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    mnPlayers1PBonusGetFighterKind(rdram, ctx);
        goto after_13;
    // 0x80132A10: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    after_13:
    // 0x80132A14: jal         0x80132144
    // 0x80132A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PBonusCheckFighterCrossed(rdram, ctx);
        goto after_14;
    // 0x80132A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80132A1C: beq         $v0, $zero, L_80132A38
    if (ctx->r2 == 0) {
        // 0x80132A20: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_80132A38;
    }
    // 0x80132A20: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80132A24: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80132A28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80132A2C: jal         0x80132228
    // 0x80132A30: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    mnPlayers1PBonusPortraitAddCross(rdram, ctx);
        goto after_15;
    // 0x80132A30: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    after_15:
    // 0x80132A34: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80132A38:
    // 0x80132A38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80132A3C: jal         0x801321CC
    // 0x80132A40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PBonusSetPortraitWallpaperPosition(rdram, ctx);
        goto after_16;
    // 0x80132A40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x80132A44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132A48:
    // 0x80132A48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132A4C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80132A50: jr          $ra
    // 0x80132A54: nop

    return;
    // 0x80132A54: nop

;}
RECOMP_FUNC void efManagerFoxReflectorSetAnimID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100E84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100E8C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80100E90: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80100E94: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80100E98: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x80100E9C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80100EA0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80100EA4: lw          $t8, 0xEA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XEA0);
    // 0x80100EA8: lw          $t7, -0x1F24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1F24);
    // 0x80100EAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80100EB0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80100EB4: jal         0x8000BD8C
    // 0x80100EB8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddAnimJointAll(rdram, ctx);
        goto after_0;
    // 0x80100EB8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80100EBC: jal         0x8000DF34
    // 0x80100EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x80100EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80100EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100ECC: jr          $ra
    // 0x80100ED0: nop

    return;
    // 0x80100ED0: nop

;}
RECOMP_FUNC void ftComputerFollowObjectiveTrackItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80138108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013810C: jal         0x80136550
    // 0x80138110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftComputerCheckTargetItemInRange(rdram, ctx);
        goto after_0;
    // 0x80138110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80138114: beq         $v0, $zero, L_80138144
    if (ctx->r2 == 0) {
        // 0x80138118: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80138144;
    }
    // 0x80138118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013811C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80138120: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80138124: beq         $v0, $at, L_80138134
    if (ctx->r2 == ctx->r1) {
        // 0x80138128: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_80138134;
    }
    // 0x80138128: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013812C: bne         $v0, $at, L_80138144
    if (ctx->r2 != ctx->r1) {
        // 0x80138130: nop
    
            goto L_80138144;
    }
    // 0x80138130: nop

L_80138134:
    // 0x80138134: jal         0x80132564
    // 0x80138138: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_1;
    // 0x80138138: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_1:
    // 0x8013813C: b           L_80138150
    // 0x80138140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138150;
    // 0x80138140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138144:
    // 0x80138144: jal         0x80134E98
    // 0x80138148: nop

    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_2;
    // 0x80138148: nop

    after_2:
    // 0x8013814C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138150:
    // 0x80138150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80138154: jr          $ra
    // 0x80138158: nop

    return;
    // 0x80138158: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueGameOverInitSprites(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C1C: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80132C20: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80132C24: addiu       $t0, $zero, 0x1A
    ctx->r8 = ADD32(0, 0X1A);
    // 0x80132C28: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132C2C: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80132C30: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132C34: addiu       $t1, $zero, 0xE6
    ctx->r9 = ADD32(0, 0XE6);
    // 0x80132C38: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80132C3C: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x80132C40: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80132C44: sb          $t1, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r9;
    // 0x80132C48: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80132C4C: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80132C50: jr          $ra
    // 0x80132C54: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x80132C54: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void efGroundUpdateStepPositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801160E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801160EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801160F0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801160F4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801160F8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801160FC: jal         0x80115F5C
    // 0x80116100: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    efGroundCommonProcUpdate(rdram, ctx);
        goto after_0;
    // 0x80116100: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80116104: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80116108: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8011610C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80116110: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x80116114: bnel        $a0, $at, L_80116134
    if (ctx->r4 != ctx->r1) {
        // 0x80116118: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80116134;
    }
    goto skip_0;
    // 0x80116118: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x8011611C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80116120: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80116124: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80116128: nop

    // 0x8011612C: bc1t        L_80116154
    if (c1cs) {
        // 0x80116130: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80116154;
    }
    // 0x80116130: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80116134:
    // 0x80116134: bnel        $a0, $at, L_80116164
    if (ctx->r4 != ctx->r1) {
        // 0x80116138: lwc1        $f18, 0x40($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
            goto L_80116164;
    }
    goto skip_1;
    // 0x80116138: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    skip_1:
    // 0x8011613C: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80116140: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80116144: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80116148: nop

    // 0x8011614C: bc1fl       L_80116164
    if (!c1cs) {
        // 0x80116150: lwc1        $f18, 0x40($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
            goto L_80116164;
    }
    goto skip_2;
    // 0x80116150: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    skip_2:
L_80116154:
    // 0x80116154: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80116158: nop

    // 0x8011615C: swc1        $f16, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f16.u32l;
    // 0x80116160: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
L_80116164:
    // 0x80116164: lwc1        $f4, 0x28($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80116168: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8011616C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80116170: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80116174: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x80116178: lwc1        $f10, 0x28($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X28);
    // 0x8011617C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80116180: swc1        $f16, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f16.u32l;
    // 0x80116184: lwc1        $f4, 0x28($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80116188: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8011618C: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80116190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80116194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80116198: jr          $ra
    // 0x8011619C: nop

    return;
    // 0x8011619C: nop

;}
RECOMP_FUNC void syDmaLoadOverlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002BE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002BE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002BEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80002BF0: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80002BF4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80002BF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002BFC: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x80002C00: beq         $v1, $zero, L_80002C24
    if (ctx->r3 == 0) {
        // 0x80002C04: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80002C24;
    }
    // 0x80002C04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002C08: jal         0x800344B0
    // 0x80002C0C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    osInvalICache_recomp(rdram, ctx);
        goto after_0;
    // 0x80002C0C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_0:
    // 0x80002C10: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80002C14: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x80002C18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002C1C: jal         0x80034530
    // 0x80002C20: subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80002C20: subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    after_1:
L_80002C24:
    // 0x80002C24: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80002C28: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x80002C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002C30: subu        $v1, $t8, $v0
    ctx->r3 = SUB32(ctx->r24, ctx->r2);
    // 0x80002C34: beql        $v1, $zero, L_80002C48
    if (ctx->r3 == 0) {
        // 0x80002C38: lw          $a1, 0x0($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X0);
            goto L_80002C48;
    }
    goto skip_0;
    // 0x80002C38: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80002C3C: jal         0x80034530
    // 0x80002C40: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x80002C40: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x80002C44: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
L_80002C48:
    // 0x80002C48: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80002C4C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002C50: subu        $a3, $t9, $a1
    ctx->r7 = SUB32(ctx->r25, ctx->r5);
    // 0x80002C54: beql        $a3, $zero, L_80002C70
    if (ctx->r7 == 0) {
        // 0x80002C58: lw          $v0, 0x1C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1C);
            goto L_80002C70;
    }
    goto skip_1;
    // 0x80002C58: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    skip_1:
    // 0x80002C5C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80002C60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80002C64: jal         0x80002A90
    // 0x80002C68: lw          $a0, 0x5040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5040);
    syDmaCopy(rdram, ctx);
        goto after_3;
    // 0x80002C68: lw          $a0, 0x5040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5040);
    after_3:
    // 0x80002C6C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_80002C70:
    // 0x80002C70: lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20);
    // 0x80002C74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002C78: subu        $v1, $t0, $v0
    ctx->r3 = SUB32(ctx->r8, ctx->r2);
    // 0x80002C7C: beql        $v1, $zero, L_80002C90
    if (ctx->r3 == 0) {
        // 0x80002C80: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80002C90;
    }
    goto skip_2;
    // 0x80002C80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80002C84: jal         0x800315B0
    // 0x80002C88: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    _bzero(rdram, ctx);
        goto after_4;
    // 0x80002C88: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x80002C8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80002C90:
    // 0x80002C90: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80002C94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80002C98: jr          $ra
    // 0x80002C9C: nop

    return;
    // 0x80002C9C: nop

;}
RECOMP_FUNC void mnCharactersMakeDecals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131D4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131D50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D58: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80131D5C: jal         0x80009968
    // 0x80131D60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D64: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131D68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131D6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131D70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131D74: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D7C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131D80: jal         0x80009DF4
    // 0x80131D84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131D84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131D88: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131D8C: lw          $t7, 0x6A7C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A7C);
    // 0x80131D90: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131D94: addiu       $t8, $t8, 0xB40
    ctx->r24 = ADD32(ctx->r24, 0XB40);
    // 0x80131D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D9C: jal         0x800CCFDC
    // 0x80131DA0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131DA0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131DA4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131DA8: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80131DAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131DB0: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80131DB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131DB8: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131DBC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131DC0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131DC4: addiu       $t3, $zero, 0x5F
    ctx->r11 = ADD32(0, 0X5F);
    // 0x80131DC8: addiu       $t4, $zero, 0x58
    ctx->r12 = ADD32(0, 0X58);
    // 0x80131DCC: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x80131DD0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131DD4: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80131DD8: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80131DDC: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80131DE0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131DE4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131DE8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131DEC: lw          $t6, 0x6A78($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A78);
    // 0x80131DF0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131DF4: addiu       $t7, $t7, 0x630
    ctx->r15 = ADD32(ctx->r15, 0X630);
    // 0x80131DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131DFC: jal         0x800CCFDC
    // 0x80131E00: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131E00: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x80131E04: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E08: lui         $at, 0x431D
    ctx->r1 = S32(0X431D << 16);
    // 0x80131E0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131E10: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80131E14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131E18: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80131E1C: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131E20: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80131E24: addiu       $t2, $zero, 0xF2
    ctx->r10 = ADD32(0, 0XF2);
    // 0x80131E28: addiu       $t3, $zero, 0xC7
    ctx->r11 = ADD32(0, 0XC7);
    // 0x80131E2C: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x80131E30: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131E34: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80131E38: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80131E3C: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x80131E40: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80131E44: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80131E48: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80131E4C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80131E50: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131E54: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80131E58: lw          $t5, 0x6A7C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6A7C);
    // 0x80131E5C: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80131E60: addiu       $t6, $t6, 0xBE0
    ctx->r14 = ADD32(ctx->r14, 0XBE0);
    // 0x80131E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E68: jal         0x800CCFDC
    // 0x80131E6C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131E6C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_4:
    // 0x80131E70: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E78: addiu       $t1, $zero, 0xE3
    ctx->r9 = ADD32(0, 0XE3);
    // 0x80131E7C: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x80131E80: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131E84: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80131E88: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131E8C: lwc1        $f16, 0x65B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X65B0);
    // 0x80131E90: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80131E94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80131E98: addiu       $t2, $zero, 0x7D
    ctx->r10 = ADD32(0, 0X7D);
    // 0x80131E9C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80131EA0: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x80131EA4: sb          $t2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r10;
    // 0x80131EA8: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
    // 0x80131EAC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131EB0: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80131EB4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80131EB8: lw          $t4, 0x6A7C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6A7C);
    // 0x80131EBC: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80131EC0: addiu       $t5, $t5, 0xC80
    ctx->r13 = ADD32(ctx->r13, 0XC80);
    // 0x80131EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EC8: jal         0x800CCFDC
    // 0x80131ECC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80131ECC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x80131ED0: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80131ED4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131ED8: addiu       $t0, $zero, 0xE3
    ctx->r8 = ADD32(0, 0XE3);
    // 0x80131EDC: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131EE0: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131EE4: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131EE8: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131EEC: lwc1        $f4, 0x65B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65B4);
    // 0x80131EF0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80131EF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131EF8: addiu       $t1, $zero, 0x7D
    ctx->r9 = ADD32(0, 0X7D);
    // 0x80131EFC: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80131F00: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x80131F04: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x80131F08: sb          $t2, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r10;
    // 0x80131F0C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131F10: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131F14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131F18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131F1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131F20: jr          $ra
    // 0x80131F24: nop

    return;
    // 0x80131F24: nop

;}
RECOMP_FUNC void gcMakeGObjAfter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800099E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800099EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800099F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800099F4: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x800099F8: lw          $a3, 0x10($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X10);
    // 0x800099FC: jal         0x800098A4
    // 0x80009A00: lbu         $a2, 0xC($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XC);
    gcInitGObjCommon(rdram, ctx);
        goto after_0;
    // 0x80009A00: lbu         $a2, 0xC($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XC);
    after_0:
    // 0x80009A04: bne         $v0, $zero, L_80009A14
    if (ctx->r2 != 0) {
        // 0x80009A08: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80009A14;
    }
    // 0x80009A08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80009A0C: b           L_80009A24
    // 0x80009A10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80009A24;
    // 0x80009A10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009A14:
    // 0x80009A14: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80009A18: jal         0x800079D4
    // 0x80009A1C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    gcLinkGObjAfter(rdram, ctx);
        goto after_1;
    // 0x80009A1C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80009A20: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80009A24:
    // 0x80009A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80009A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009A2C: jr          $ra
    // 0x80009A30: nop

    return;
    // 0x80009A30: nop

;}
RECOMP_FUNC void func_ovl8_8038120C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038120C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80381210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80381214: beq         $a0, $zero, L_8038124C
    if (ctx->r4 == 0) {
        // 0x80381218: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8038124C;
    }
    // 0x80381218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038121C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80381220: addiu       $t6, $t6, -0x43CC
    ctx->r14 = ADD32(ctx->r14, -0X43CC);
    // 0x80381224: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    // 0x80381228: jal         0x80381908
    // 0x8038122C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_ovl8_80381908(rdram, ctx);
        goto after_0;
    // 0x8038122C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80381230: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80381234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80381238: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8038123C: beql        $t8, $zero, L_80381250
    if (ctx->r24 == 0) {
        // 0x80381240: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80381250;
    }
    goto skip_0;
    // 0x80381240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80381244: jal         0x803717C0
    // 0x80381248: nop

    func_ovl8_803717C0(rdram, ctx);
        goto after_1;
    // 0x80381248: nop

    after_1:
L_8038124C:
    // 0x8038124C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80381250:
    // 0x80381250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80381254: jr          $ra
    // 0x80381258: nop

    return;
    // 0x80381258: nop

;}
RECOMP_FUNC void func_80004AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004AB0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80004AB4: lw          $t6, 0x6630($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6630);
    // 0x80004AB8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80004ABC: addiu       $t8, $t8, 0x6570
    ctx->r24 = ADD32(ctx->r24, 0X6570);
    // 0x80004AC0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80004AC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004AC8: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80004ACC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80004AD0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004AD4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80004AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004ADC: addiu       $a2, $a2, 0x65C0
    ctx->r6 = ADD32(ctx->r6, 0X65C0);
    // 0x80004AE0: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80004AE4: addiu       $a1, $a1, 0x65C0
    ctx->r5 = ADD32(ctx->r5, 0X65C0);
    // 0x80004AE8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80004AEC:
    // 0x80004AEC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80004AF0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80004AF4: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    // 0x80004AF8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80004AFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80004B00: sw          $v1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r3;
    // 0x80004B04: bne         $at, $zero, L_80004AEC
    if (ctx->r1 != 0) {
        // 0x80004B08: sw          $v1, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r3;
            goto L_80004AEC;
    }
    // 0x80004B08: sw          $v1, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r3;
    // 0x80004B0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80004B10: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80004B14: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80004B18:
    // 0x80004B18: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80004B1C: beq         $t9, $zero, L_80004B7C
    if (ctx->r25 == 0) {
        // 0x80004B20: lui         $t0, 0x8004
        ctx->r8 = S32(0X8004 << 16);
            goto L_80004B7C;
    }
    // 0x80004B20: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80004B24: addiu       $t0, $t0, 0x65B0
    ctx->r8 = ADD32(ctx->r8, 0X65B0);
    // 0x80004B28: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x80004B2C: addu        $a0, $a1, $t0
    ctx->r4 = ADD32(ctx->r5, ctx->r8);
    // 0x80004B30: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80004B34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004B38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80004B3C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80004B40: jal         0x80007174
    // 0x80004B44: sw          $t1, 0x662C($at)
    MEM_W(0X662C, ctx->r1) = ctx->r9;
    syRdpResetSettings(rdram, ctx);
        goto after_0;
    // 0x80004B44: sw          $t1, 0x662C($at)
    MEM_W(0X662C, ctx->r1) = ctx->r9;
    after_0:
    // 0x80004B48: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80004B4C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80004B50: lui         $t3, 0xDF00
    ctx->r11 = S32(0XDF00 << 16);
    // 0x80004B54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80004B58: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004B5C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80004B60: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80004B64: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80004B68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80004B6C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80004B70: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80004B74: b           L_80004B88
    // 0x80004B78: sw          $t4, 0x65C0($at)
    MEM_W(0X65C0, ctx->r1) = ctx->r12;
        goto L_80004B88;
    // 0x80004B78: sw          $t4, 0x65C0($at)
    MEM_W(0X65C0, ctx->r1) = ctx->r12;
L_80004B7C:
    // 0x80004B7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004B80: bne         $v1, $a0, L_80004B18
    if (ctx->r3 != ctx->r4) {
        // 0x80004B84: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80004B18;
    }
    // 0x80004B84: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80004B88:
    // 0x80004B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004B8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004B90: sh          $zero, 0x6628($at)
    MEM_H(0X6628, ctx->r1) = 0;
    // 0x80004B94: jr          $ra
    // 0x80004B98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80004B98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_ovl8_8037C6DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C6DC: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8037C6E0: beql        $v0, $zero, L_8037C704
    if (ctx->r2 == 0) {
        // 0x8037C6E4: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_8037C704;
    }
    goto skip_0;
    // 0x8037C6E4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    skip_0:
    // 0x8037C6E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8037C6EC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8037C6F0: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8037C6F4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8037C6F8: jr          $ra
    // 0x8037C6FC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    return;
    // 0x8037C6FC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8037C700: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8037C704:
    // 0x8037C704: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8037C708: jr          $ra
    // 0x8037C70C: nop

    return;
    // 0x8037C70C: nop

;}
RECOMP_FUNC void func_ovl8_80377FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377FE4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80377FE8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80377FEC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80377FF0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80377FF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80377FF8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80377FFC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80378000: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80378004: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80378008: addiu       $s3, $sp, 0x3C
    ctx->r19 = ADD32(ctx->r29, 0X3C);
    // 0x8037800C: lh          $a1, 0x2($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2);
    // 0x80378010: lh          $a3, 0x2($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X2);
    // 0x80378014: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x80378018: jal         0x8037AA88
    // 0x8037801C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_ovl8_8037AA88(rdram, ctx);
        goto after_0;
    // 0x8037801C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // 0x80378020: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80378024: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80378028:
    // 0x80378028: jal         0x8037ABDC
    // 0x8037802C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_ovl8_8037ABDC(rdram, ctx);
        goto after_1;
    // 0x8037802C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x80378030: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80378034: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80378038: jal         0x80377F50
    // 0x8037803C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_ovl8_80377F50(rdram, ctx);
        goto after_2;
    // 0x8037803C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80378040: bgtzl       $s0, L_80378028
    if (SIGNED(ctx->r16) > 0) {
        // 0x80378044: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80378028;
    }
    goto skip_0;
    // 0x80378044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80378048: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8037804C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80378050: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80378054: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80378058: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8037805C: jr          $ra
    // 0x80378060: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80378060: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void scAutoDemoSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E0C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018E0C4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018E0C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018E0CC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018E0D0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018E0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E0D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018E0DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018E0E0: addiu       $t8, $t8, -0x1B00
    ctx->r24 = ADD32(ctx->r24, -0X1B00);
    // 0x8018E0E4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8018E0E8: addiu       $t0, $t0, -0x17E0
    ctx->r8 = ADD32(ctx->r8, -0X17E0);
    // 0x8018E0EC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018E0F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018E0F4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018E0F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018E0FC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018E100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018E104: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018E108: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018E10C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018E110: jal         0x800CDF78
    // 0x8018E114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018E114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018E118: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018E11C: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018E120: jal         0x800CDEEC
    // 0x8018E124: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018E124: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8018E128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E12C: jal         0x80004980
    // 0x8018E130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018E130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018E134: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018E138: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E13C: addiu       $a2, $a2, 0xD40
    ctx->r6 = ADD32(ctx->r6, 0XD40);
    // 0x8018E140: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018E144: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8018E148: jal         0x800CDE04
    // 0x8018E14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018E14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018E150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E154: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018E158: jr          $ra
    // 0x8018E15C: nop

    return;
    // 0x8018E15C: nop

;}
RECOMP_FUNC void gmCameraMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DB54: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010DB58: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8010DB5C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010DB60: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8010DB64: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8010DB68: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010DB6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8010DB70: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8010DB74: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8010DB78: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8010DB7C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8010DB80: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8010DB84: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8010DB88: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8010DB8C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8010DB90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8010DB94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010DB98: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8010DB9C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8010DBA0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8010DBA4: addiu       $a0, $zero, 0x3EB
    ctx->r4 = ADD32(0, 0X3EB);
    // 0x8010DBA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010DBAC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8010DBB0: jal         0x8000B93C
    // 0x8010DBB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010DBB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010DBB8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010DBBC: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8010DBC0: lw          $t4, 0x20($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20);
    // 0x8010DBC4: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
    // 0x8010DBC8: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x8010DBCC: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8010DBD0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8010DBD4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8010DBD8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8010DBDC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8010DBE0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010DBE4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8010DBE8: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x8010DBEC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010DBF0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010DBF4: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    // 0x8010DBF8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010DBFC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010DC00: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010DC04: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8010DC08: jal         0x80007080
    // 0x8010DC0C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8010DC0C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8010DC10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010DC14: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8010DC18: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010DC1C: jr          $ra
    // 0x8010DC20: nop

    return;
    // 0x8010DC20: nop

;}
RECOMP_FUNC void ftPhysicsCheckSetFastFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8DB8: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x800D8DBC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D8DC0: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800D8DC4: bltzl       $t8, L_800D8E44
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D8DC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D8E44;
    }
    goto skip_0;
    // 0x800D8DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D8DCC: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800D8DD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D8DD4: nop

    // 0x800D8DD8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800D8DDC: nop

    // 0x800D8DE0: bc1fl       L_800D8E44
    if (!c1cs) {
        // 0x800D8DE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D8E44;
    }
    goto skip_1;
    // 0x800D8DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800D8DE8: lb          $t9, 0x1C3($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X1C3);
    // 0x800D8DEC: slti        $at, $t9, -0x34
    ctx->r1 = SIGNED(ctx->r25) < -0X34 ? 1 : 0;
    // 0x800D8DF0: beql        $at, $zero, L_800D8E44
    if (ctx->r1 == 0) {
        // 0x800D8DF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D8E44;
    }
    goto skip_2;
    // 0x800D8DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800D8DF8: lbu         $t0, 0x269($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X269);
    // 0x800D8DFC: addiu       $t4, $zero, 0xFE
    ctx->r12 = ADD32(0, 0XFE);
    // 0x800D8E00: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800D8E04: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x800D8E08: beql        $at, $zero, L_800D8E44
    if (ctx->r1 == 0) {
        // 0x800D8E0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D8E44;
    }
    goto skip_3;
    // 0x800D8E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800D8E10: lbu         $t2, 0x18D($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X18D);
    // 0x800D8E14: sb          $t4, 0x269($a0)
    MEM_B(0X269, ctx->r4) = ctx->r12;
    // 0x800D8E18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D8E1C: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x800D8E20: sb          $t3, 0x18D($a0)
    MEM_B(0X18D, ctx->r4) = ctx->r11;
    // 0x800D8E24: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x800D8E28: jal         0x800E9814
    // 0x800D8E2C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x800D8E2C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D8E30: beq         $v0, $zero, L_800D8E40
    if (ctx->r2 == 0) {
        // 0x800D8E34: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_800D8E40;
    }
    // 0x800D8E34: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800D8E38: jal         0x800E11C8
    // 0x800D8E3C: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    ftMainRunUpdateColAnim(rdram, ctx);
        goto after_1;
    // 0x800D8E3C: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    after_1:
L_800D8E40:
    // 0x800D8E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D8E44:
    // 0x800D8E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8E48: jr          $ra
    // 0x800D8E4C: nop

    return;
    // 0x800D8E4C: nop

;}
RECOMP_FUNC void itNyarsWeaponCoinProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F1A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017F1A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F1AC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8017F1B0: jal         0x80100ACC
    // 0x8017F1B4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDamageCoinMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8017F1B4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8017F1B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F1BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017F1C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017F1C4: jr          $ra
    // 0x8017F1C8: nop

    return;
    // 0x8017F1C8: nop

;}

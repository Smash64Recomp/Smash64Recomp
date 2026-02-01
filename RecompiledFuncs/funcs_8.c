#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sc1PStageClearCheckNoTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F28: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80133F2C: lbu         $t6, 0x4AE6($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE6);
    // 0x80133F30: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80133F34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80133F38: bne         $t6, $at, L_80133F48
    if (ctx->r14 != ctx->r1) {
        // 0x80133F3C: nop
    
            goto L_80133F48;
    }
    // 0x80133F3C: nop

    // 0x80133F40: jr          $ra
    // 0x80133F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80133F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133F48:
    // 0x80133F48: jr          $ra
    // 0x80133F4C: nop

    return;
    // 0x80133F4C: nop

;}
RECOMP_FUNC void lbParticleMakeChildScriptID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE6B8: andi        $v0, $a1, 0x7
    ctx->r2 = ctx->r5 & 0X7;
    // 0x800CE6BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CE6C0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800CE6C4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CE6C8: bne         $at, $zero, L_800CE6D8
    if (ctx->r1 != 0) {
        // 0x800CE6CC: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_800CE6D8;
    }
    // 0x800CE6CC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800CE6D0: b           L_800CE798
    // 0x800CE6D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CE798;
    // 0x800CE6D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE6D8:
    // 0x800CE6D8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800CE6DC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CE6E0: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800CE6E4: lw          $t7, 0x63C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63C0);
    // 0x800CE6E8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CE6EC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800CE6F0: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800CE6F4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CE6F8: bne         $at, $zero, L_800CE708
    if (ctx->r1 != 0) {
        // 0x800CE6FC: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_800CE708;
    }
    // 0x800CE6FC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CE700: b           L_800CE798
    // 0x800CE704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CE798;
    // 0x800CE704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE708:
    // 0x800CE708: lw          $t8, 0x6400($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6400);
    // 0x800CE70C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800CE710: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CE714: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800CE718: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800CE71C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800CE720: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x800CE724: lhu         $a3, 0x2($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0X2);
    // 0x800CE728: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x800CE72C: addiu       $t2, $v0, 0x30
    ctx->r10 = ADD32(ctx->r2, 0X30);
    // 0x800CE730: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800CE734: lhu         $t3, 0x6($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X6);
    // 0x800CE738: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800CE73C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800CE740: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800CE744: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800CE748: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CE74C: lw          $t4, 0x6420($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6420);
    // 0x800CE750: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800CE754: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800CE758: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CE75C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800CE760: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800CE764: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CE768: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800CE76C: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CE770: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800CE774: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CE778: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x800CE77C: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CE780: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x800CE784: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CE788: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x800CE78C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800CE790: jal         0x800CE4E4
    // 0x800CE794: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    lbParticleMakeStruct(rdram, ctx);
        goto after_0;
    // 0x800CE794: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    after_0:
L_800CE798:
    // 0x800CE798: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CE79C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CE7A0: jr          $ra
    // 0x800CE7A4: nop

    return;
    // 0x800CE7A4: nop

;}
RECOMP_FUNC void itLinkBombCommonSetHitStatusNormal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185CD4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80185CD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80185CDC: jr          $ra
    // 0x80185CE0: sw          $t6, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r14;
    return;
    // 0x80185CE0: sw          $t6, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void gcDrawDObjTreeMultiList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001490C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80014914: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014918: lbu         $t6, 0x54($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X54);
    // 0x8001491C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80014920: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x80014924: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80014928: bne         $t7, $zero, L_80014A44
    if (ctx->r15 != 0) {
        // 0x8001492C: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80014A44;
    }
    // 0x8001492C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014930: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80014934: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80014938: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x8001493C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80014940: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80014944: jal         0x80010D70
    // 0x80014948: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x80014948: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001494C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80014950: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80014954: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80014958: beq         $s0, $zero, L_800149D0
    if (ctx->r16 == 0) {
        // 0x8001495C: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_800149D0;
    }
    // 0x8001495C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80014960: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80014964: lw          $t8, 0x72A8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72A8);
    // 0x80014968: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001496C: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80014970: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80014974: beql        $t1, $zero, L_800149D4
    if (ctx->r9 == 0) {
        // 0x80014978: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_800149D4;
    }
    goto skip_0;
    // 0x80014978: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_0:
    // 0x8001497C: lbu         $t2, 0x54($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X54);
    // 0x80014980: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80014984: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80014988: bnel        $t3, $zero, L_800149D4
    if (ctx->r11 != 0) {
        // 0x8001498C: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_800149D4;
    }
    goto skip_1;
    // 0x8001498C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_1:
    // 0x80014990: jal         0x80012D90
    // 0x80014994: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x80014994: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_1:
    // 0x80014998: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8001499C: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x800149A0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800149A4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800149A8: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800149AC: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800149B0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800149B4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800149B8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800149BC: lw          $t6, 0x72A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72A8);
    // 0x800149C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800149C4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800149C8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800149CC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800149D0:
    // 0x800149D0: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
L_800149D4:
    // 0x800149D4: beql        $a0, $zero, L_800149F4
    if (ctx->r4 == 0) {
        // 0x800149D8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800149F4;
    }
    goto skip_2;
    // 0x800149D8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x800149DC: jal         0x8001490C
    // 0x800149E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcDrawDObjTreeMultiList(rdram, ctx);
        goto after_2;
    // 0x800149E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x800149E4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800149E8: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x800149EC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800149F0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_800149F4:
    // 0x800149F4: beql        $t0, $zero, L_80014A3C
    if (ctx->r8 == 0) {
        // 0x800149F8: lwc1        $f6, 0x20($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80014A3C;
    }
    goto skip_3;
    // 0x800149F8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    skip_3:
    // 0x800149FC: lw          $t1, 0x14($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X14);
    // 0x80014A00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014A04: lui         $t4, 0xD838
    ctx->r12 = S32(0XD838 << 16);
    // 0x80014A08: beql        $t1, $at, L_80014A20
    if (ctx->r9 == ctx->r1) {
        // 0x80014A0C: lw          $v1, 0x0($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X0);
            goto L_80014A20;
    }
    goto skip_4;
    // 0x80014A0C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    skip_4:
    // 0x80014A10: lw          $t2, 0x8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8);
    // 0x80014A14: beql        $t2, $zero, L_80014A3C
    if (ctx->r10 == 0) {
        // 0x80014A18: lwc1        $f6, 0x20($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80014A3C;
    }
    goto skip_5;
    // 0x80014A18: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    skip_5:
    // 0x80014A1C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
L_80014A20:
    // 0x80014A20: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x80014A24: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x80014A28: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80014A2C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80014A30: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80014A34: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80014A38: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
L_80014A3C:
    // 0x80014A3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014A40: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_80014A44:
    // 0x80014A44: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x80014A48: bnel        $t6, $zero, L_80014A74
    if (ctx->r14 != 0) {
        // 0x80014A4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80014A74;
    }
    goto skip_6;
    // 0x80014A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80014A50: lw          $s0, 0x8($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X8);
    // 0x80014A54: beql        $s0, $zero, L_80014A74
    if (ctx->r16 == 0) {
        // 0x80014A58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80014A74;
    }
    goto skip_7;
    // 0x80014A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_80014A5C:
    // 0x80014A5C: jal         0x8001490C
    // 0x80014A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcDrawDObjTreeMultiList(rdram, ctx);
        goto after_3;
    // 0x80014A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80014A64: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80014A68: bne         $s0, $zero, L_80014A5C
    if (ctx->r16 != 0) {
        // 0x80014A6C: nop
    
            goto L_80014A5C;
    }
    // 0x80014A6C: nop

    // 0x80014A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80014A74:
    // 0x80014A74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80014A78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014A7C: jr          $ra
    // 0x80014A80: nop

    return;
    // 0x80014A80: nop

;}
RECOMP_FUNC void mvOpeningYamabukiFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801320E0: addiu       $v1, $v1, 0x248C
    ctx->r3 = ADD32(ctx->r3, 0X248C);
    // 0x801320E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801320E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801320EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801320F0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801320F4: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x801320F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801320FC: bne         $at, $zero, L_80132198
    if (ctx->r1 != 0) {
        // 0x80132100: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80132198;
    }
    // 0x80132100: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132104: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132108: addiu       $a2, $a2, 0x249C
    ctx->r6 = ADD32(ctx->r6, 0X249C);
    // 0x8013210C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80132110: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132114: beq         $v0, $zero, L_80132120
    if (ctx->r2 == 0) {
        // 0x80132118: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132120;
    }
    // 0x80132118: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8013211C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80132120:
    // 0x80132120: jal         0x80390A04
    // 0x80132124: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80132124: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80132128: beq         $v0, $zero, L_80132144
    if (ctx->r2 == 0) {
        // 0x8013212C: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_80132144;
    }
    // 0x8013212C: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132130: jal         0x80390AC0
    // 0x80132134: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80132134: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80132138: beq         $v0, $zero, L_80132144
    if (ctx->r2 == 0) {
        // 0x8013213C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132144;
    }
    // 0x8013213C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132140: sw          $zero, 0x249C($at)
    MEM_W(0X249C, ctx->r1) = 0;
L_80132144:
    // 0x80132144: jal         0x8039076C
    // 0x80132148: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80132148: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x8013214C: beq         $v0, $zero, L_8013216C
    if (ctx->r2 == 0) {
        // 0x80132150: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8013216C;
    }
    // 0x80132150: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132154: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132158: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8013215C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80132160: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80132164: jal         0x80005C74
    // 0x80132168: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80132168: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
L_8013216C:
    // 0x8013216C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132170: lw          $t2, 0x248C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X248C);
    // 0x80132174: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132178: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x8013217C: bne         $t2, $at, L_80132198
    if (ctx->r10 != ctx->r1) {
        // 0x80132180: addiu       $v0, $v0, 0x4AD0
        ctx->r2 = ADD32(ctx->r2, 0X4AD0);
            goto L_80132198;
    }
    // 0x80132180: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132184: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80132188: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x8013218C: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80132190: jal         0x80005C74
    // 0x80132194: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x80132194: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    after_4:
L_80132198:
    // 0x80132198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013219C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801321A0: jr          $ra
    // 0x801321A4: nop

    return;
    // 0x801321A4: nop

;}
RECOMP_FUNC void func_ovl8_80372DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372DC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80372DCC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80372DD0: jr          $ra
    // 0x80372DD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80372DD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void ftComputerProcDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137778: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013777C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137780: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80137784: jal         0x80136D0C
    // 0x80137788: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    ftComputerGetObjectiveStatus(rdram, ctx);
        goto after_0;
    // 0x80137788: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x8013778C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80137790: beq         $v0, $zero, L_801377A4
    if (ctx->r2 == 0) {
        // 0x80137794: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801377A4;
    }
    // 0x80137794: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80137798: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013779C: bne         $v0, $at, L_801377AC
    if (ctx->r2 != ctx->r1) {
        // 0x801377A0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801377AC;
    }
    // 0x801377A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_801377A4:
    // 0x801377A4: b           L_80137A08
    // 0x801377A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80137A08;
    // 0x801377A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801377AC:
    // 0x801377AC: jal         0x80132BC8
    // 0x801377B0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    ftComputerCheckEvadeDistance(rdram, ctx);
        goto after_1;
    // 0x801377B0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_1:
    // 0x801377B4: beq         $v0, $zero, L_801377CC
    if (ctx->r2 == 0) {
        // 0x801377B8: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_801377CC;
    }
    // 0x801377B8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801377BC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x801377C0: sb          $t6, 0x1CC($a2)
    MEM_B(0X1CC, ctx->r6) = ctx->r14;
    // 0x801377C4: b           L_80137A08
    // 0x801377C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80137A08;
    // 0x801377C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801377CC:
    // 0x801377CC: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x801377D0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801377D4: beq         $v0, $at, L_80137804
    if (ctx->r2 == ctx->r1) {
        // 0x801377D8: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80137804;
    }
    // 0x801377D8: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801377DC: beq         $v0, $at, L_80137804
    if (ctx->r2 == ctx->r1) {
        // 0x801377E0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80137804;
    }
    // 0x801377E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801377E4: jal         0x80135B78
    // 0x801377E8: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_ovl3_80135B78(rdram, ctx);
        goto after_2;
    // 0x801377E8: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_2:
    // 0x801377EC: beq         $v0, $zero, L_80137804
    if (ctx->r2 == 0) {
        // 0x801377F0: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_80137804;
    }
    // 0x801377F0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801377F4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x801377F8: sb          $t7, 0x1CC($a2)
    MEM_B(0X1CC, ctx->r6) = ctx->r15;
    // 0x801377FC: b           L_80137A08
    // 0x80137800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80137A08;
    // 0x80137800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80137804:
    // 0x80137804: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80137808: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013780C: beq         $v0, $at, L_80137834
    if (ctx->r2 == ctx->r1) {
        // 0x80137810: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80137834;
    }
    // 0x80137810: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80137814: beq         $v0, $at, L_8013785C
    if (ctx->r2 == ctx->r1) {
        // 0x80137818: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8013785C;
    }
    // 0x80137818: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8013781C: beq         $v0, $at, L_80137834
    if (ctx->r2 == ctx->r1) {
        // 0x80137820: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80137834;
    }
    // 0x80137820: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80137824: beql        $v0, $at, L_80137860
    if (ctx->r2 == ctx->r1) {
        // 0x80137828: lw          $v0, 0x24($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X24);
            goto L_80137860;
    }
    goto skip_0;
    // 0x80137828: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    skip_0:
    // 0x8013782C: b           L_80137884
    // 0x80137830: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
        goto L_80137884;
    // 0x80137830: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
L_80137834:
    // 0x80137834: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x80137838: slti        $at, $v0, 0xEC
    ctx->r1 = SIGNED(ctx->r2) < 0XEC ? 1 : 0;
    // 0x8013783C: bne         $at, $zero, L_80137884
    if (ctx->r1 != 0) {
        // 0x80137840: slti        $at, $v0, 0xF6
        ctx->r1 = SIGNED(ctx->r2) < 0XF6 ? 1 : 0;
            goto L_80137884;
    }
    // 0x80137840: slti        $at, $v0, 0xF6
    ctx->r1 = SIGNED(ctx->r2) < 0XF6 ? 1 : 0;
    // 0x80137844: beq         $at, $zero, L_80137884
    if (ctx->r1 == 0) {
        // 0x80137848: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80137884;
    }
    // 0x80137848: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8013784C: jal         0x80132564
    // 0x80137850: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_3;
    // 0x80137850: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_3:
    // 0x80137854: b           L_80137A08
    // 0x80137858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137A08;
    // 0x80137858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013785C:
    // 0x8013785C: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
L_80137860:
    // 0x80137860: slti        $at, $v0, 0xED
    ctx->r1 = SIGNED(ctx->r2) < 0XED ? 1 : 0;
    // 0x80137864: bne         $at, $zero, L_80137884
    if (ctx->r1 != 0) {
        // 0x80137868: slti        $at, $v0, 0xF5
        ctx->r1 = SIGNED(ctx->r2) < 0XF5 ? 1 : 0;
            goto L_80137884;
    }
    // 0x80137868: slti        $at, $v0, 0xF5
    ctx->r1 = SIGNED(ctx->r2) < 0XF5 ? 1 : 0;
    // 0x8013786C: beq         $at, $zero, L_80137884
    if (ctx->r1 == 0) {
        // 0x80137870: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80137884;
    }
    // 0x80137870: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137874: jal         0x80132564
    // 0x80137878: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_4;
    // 0x80137878: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_4:
    // 0x8013787C: b           L_80137A08
    // 0x80137880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137A08;
    // 0x80137880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137884:
    // 0x80137884: slti        $at, $v0, 0x98
    ctx->r1 = SIGNED(ctx->r2) < 0X98 ? 1 : 0;
    // 0x80137888: bne         $at, $zero, L_801378AC
    if (ctx->r1 != 0) {
        // 0x8013788C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801378AC;
    }
    // 0x8013788C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137890: slti        $at, $v0, 0x9C
    ctx->r1 = SIGNED(ctx->r2) < 0X9C ? 1 : 0;
    // 0x80137894: beq         $at, $zero, L_801378AC
    if (ctx->r1 == 0) {
        // 0x80137898: addiu       $a1, $zero, 0x24
        ctx->r5 = ADD32(0, 0X24);
            goto L_801378AC;
    }
    // 0x80137898: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8013789C: jal         0x80132564
    // 0x801378A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_5;
    // 0x801378A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x801378A4: b           L_80137A08
    // 0x801378A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137A08;
    // 0x801378A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801378AC:
    // 0x801378AC: jal         0x8013295C
    // 0x801378B0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_6;
    // 0x801378B0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_6:
    // 0x801378B4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801378B8: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x801378BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801378C0: addiu       $a1, $a2, 0x1CC
    ctx->r5 = ADD32(ctx->r6, 0X1CC);
    // 0x801378C4: lwc1        $f4, 0x68($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X68);
    // 0x801378C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801378CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801378D0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801378D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801378D8: bc1fl       L_801378EC
    if (!c1cs) {
        // 0x801378DC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801378EC;
    }
    goto skip_1;
    // 0x801378DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_1:
    // 0x801378E0: b           L_80137A08
    // 0x801378E4: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
        goto L_80137A08;
    // 0x801378E4: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x801378E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_801378EC:
    // 0x801378EC: jal         0x80136310
    // 0x801378F0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    ftComputerCheckFindItem(rdram, ctx);
        goto after_7;
    // 0x801378F0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_7:
    // 0x801378F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801378F8: beq         $v0, $zero, L_801379AC
    if (ctx->r2 == 0) {
        // 0x801378FC: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_801379AC;
    }
    // 0x801378FC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80137900: lbu         $v0, 0x13($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X13);
    // 0x80137904: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80137908: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013790C: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x80137910: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80137914: lwc1        $f8, 0x68($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X68);
    // 0x80137918: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8013791C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80137920: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80137924: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80137928: nop

    // 0x8013792C: bc1fl       L_801379B4
    if (!c1cs) {
        // 0x80137930: lw          $a0, 0x84C($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X84C);
            goto L_801379B4;
    }
    goto skip_2;
    // 0x80137930: lw          $a0, 0x84C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X84C);
    skip_2:
    // 0x80137934: lw          $t0, 0x50E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50E8);
    // 0x80137938: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013793C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80137940: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80137944: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80137948: bnel        $t1, $at, L_80137974
    if (ctx->r9 != ctx->r1) {
        // 0x8013794C: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80137974;
    }
    goto skip_3;
    // 0x8013794C: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    skip_3:
    // 0x80137950: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80137954: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80137958: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8013795C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80137960: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80137964: subu        $v1, $v1, $at
    ctx->r3 = SUB32(ctx->r3, ctx->r1);
    // 0x80137968: b           L_80137988
    // 0x8013796C: addiu       $v1, $v1, 0x13B
    ctx->r3 = ADD32(ctx->r3, 0X13B);
        goto L_80137988;
    // 0x8013796C: addiu       $v1, $v1, 0x13B
    ctx->r3 = ADD32(ctx->r3, 0X13B);
    // 0x80137970: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
L_80137974:
    // 0x80137974: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80137978: subu        $v1, $v1, $at
    ctx->r3 = SUB32(ctx->r3, ctx->r1);
    // 0x8013797C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80137980: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80137984: addiu       $v1, $v1, 0xE1
    ctx->r3 = ADD32(ctx->r3, 0XE1);
L_80137988:
    // 0x80137988: lhu         $t2, 0x12($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X12);
    // 0x8013798C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137990: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80137994: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80137998: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8013799C: beq         $at, $zero, L_801379B0
    if (ctx->r1 == 0) {
        // 0x801379A0: sh          $t3, 0x12($a1)
        MEM_H(0X12, ctx->r5) = ctx->r11;
            goto L_801379B0;
    }
    // 0x801379A0: sh          $t3, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r11;
    // 0x801379A4: b           L_80137A08
    // 0x801379A8: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
        goto L_80137A08;
    // 0x801379A8: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
L_801379AC:
    // 0x801379AC: sh          $zero, 0x12($a1)
    MEM_H(0X12, ctx->r5) = 0;
L_801379B0:
    // 0x801379B0: lw          $a0, 0x84C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X84C);
L_801379B4:
    // 0x801379B4: beql        $a0, $zero, L_80137A00
    if (ctx->r4 == 0) {
        // 0x801379B8: lbu         $t8, 0x1($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X1);
            goto L_80137A00;
    }
    goto skip_4;
    // 0x801379B8: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    skip_4:
    // 0x801379BC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801379C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801379C4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x801379C8: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x801379CC: beql        $v0, $zero, L_801379E8
    if (ctx->r2 == 0) {
        // 0x801379D0: sb          $t6, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r14;
            goto L_801379E8;
    }
    goto skip_5;
    // 0x801379D0: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    skip_5:
    // 0x801379D4: beq         $v0, $at, L_801379E4
    if (ctx->r2 == ctx->r1) {
        // 0x801379D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801379E4;
    }
    // 0x801379D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801379DC: bne         $v0, $at, L_801379F0
    if (ctx->r2 != ctx->r1) {
        // 0x801379E0: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_801379F0;
    }
    // 0x801379E0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_801379E4:
    // 0x801379E4: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
L_801379E8:
    // 0x801379E8: b           L_80137A08
    // 0x801379EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80137A08;
    // 0x801379EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801379F0:
    // 0x801379F0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x801379F4: b           L_80137A08
    // 0x801379F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80137A08;
    // 0x801379F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801379FC: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
L_80137A00:
    // 0x80137A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137A04: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
L_80137A08:
    // 0x80137A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137A0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80137A10: jr          $ra
    // 0x80137A14: nop

    return;
    // 0x80137A14: nop

;}
RECOMP_FUNC void grInishiePowerBlockSetWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010986C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109870: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109874: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80109878: addiu       $t7, $zero, 0x708
    ctx->r15 = ADD32(0, 0X708);
    // 0x8010987C: sb          $t6, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r14;
    // 0x80109880: jr          $ra
    // 0x80109884: sh          $t7, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r15;
    return;
    // 0x80109884: sh          $t7, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void wpSamusBombMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80169328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016932C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80169330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80169334: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80169338: addiu       $a1, $a1, -0x6F90
    ctx->r5 = ADD32(ctx->r5, -0X6F90);
    // 0x8016933C: jal         0x801655C8
    // 0x80169340: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80169340: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80169344: bne         $v0, $zero, L_80169354
    if (ctx->r2 != 0) {
        // 0x80169348: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80169354;
    }
    // 0x80169348: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016934C: b           L_80169378
    // 0x80169350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80169378;
    // 0x80169350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80169354:
    // 0x80169354: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80169358: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8016935C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80169360: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80169364: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80169368: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8016936C: sw          $t6, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r14;
    // 0x80169370: sw          $t7, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r15;
    // 0x80169374: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
L_80169378:
    // 0x80169378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016937C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80169380: jr          $ra
    // 0x80169384: nop

    return;
    // 0x80169384: nop

;}
RECOMP_FUNC void itLGunMakeAmmo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175AD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80175ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175AE0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80175AE4: lw          $t7, 0x84C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84C);
    // 0x80175AE8: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x80175AEC: jal         0x80175A60
    // 0x80175AF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itLGunWeaponAmmoMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80175AF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80175AF4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80175AF8: lhu         $t8, 0x33E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X33E);
    // 0x80175AFC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80175B00: sh          $t9, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r25;
    // 0x80175B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80175B0C: jr          $ra
    // 0x80175B10: nop

    return;
    // 0x80175B10: nop

;}
RECOMP_FUNC void itTaruThrownCheckMapCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179D88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80179D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179D90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80179D94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80179D98: jal         0x801737B8
    // 0x80179D9C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80179D9C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_0:
    // 0x80179DA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80179DA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80179DA8: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80179DAC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80179DB0: jal         0x801737EC
    // 0x80179DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_1;
    // 0x80179DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80179DB8: beql        $v0, $zero, L_80179DCC
    if (ctx->r2 == 0) {
        // 0x80179DBC: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80179DCC;
    }
    goto skip_0;
    // 0x80179DBC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80179DC0: jal         0x80172508
    // 0x80179DC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    itMainSetSpinVelLR(rdram, ctx);
        goto after_2;
    // 0x80179DC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80179DC8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80179DCC:
    // 0x80179DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80179DD4: beq         $t6, $zero, L_80179DE4
    if (ctx->r14 == 0) {
        // 0x80179DD8: nop
    
            goto L_80179DE4;
    }
    // 0x80179DD8: nop

    // 0x80179DDC: b           L_80179DE4
    // 0x80179DE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80179DE4;
    // 0x80179DE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80179DE4:
    // 0x80179DE4: jr          $ra
    // 0x80179DE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80179DE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonAttack13ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E8B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014E8B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E8BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014E8C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8014E8C4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8014E8C8: beq         $v1, $at, L_8014E8D8
    if (ctx->r3 == ctx->r1) {
        // 0x8014E8CC: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8014E8D8;
    }
    // 0x8014E8CC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8014E8D0: bne         $v1, $at, L_8014E904
    if (ctx->r3 != ctx->r1) {
        // 0x8014E8D4: nop
    
            goto L_8014E904;
    }
    // 0x8014E8D4: nop

L_8014E8D8:
    // 0x8014E8D8: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8014E8DC: beq         $t6, $zero, L_8014E904
    if (ctx->r14 == 0) {
        // 0x8014E8E0: nop
    
            goto L_8014E904;
    }
    // 0x8014E8E0: nop

    // 0x8014E8E4: lw          $t7, 0x18C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18C);
    // 0x8014E8E8: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8014E8EC: bgez        $t9, L_8014E904
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014E8F0: nop
    
            goto L_8014E904;
    }
    // 0x8014E8F0: nop

    // 0x8014E8F4: jal         0x8014F0F4
    // 0x8014E8F8: nop

    ftCommonAttack100StartSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014E8F8: nop

    after_0:
    // 0x8014E8FC: b           L_8014E910
    // 0x8014E900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014E910;
    // 0x8014E900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E904:
    // 0x8014E904: jal         0x800D94C4
    // 0x8014E908: nop

    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x8014E908: nop

    after_1:
    // 0x8014E90C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E910:
    // 0x8014E910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E914: jr          $ra
    // 0x8014E918: nop

    return;
    // 0x8014E918: nop

;}
RECOMP_FUNC void ftCommonOttottoProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80142854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142858: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8014285C: jal         0x800D9480
    // 0x80142860: addiu       $a1, $a1, 0x2AC4
    ctx->r5 = ADD32(ctx->r5, 0X2AC4);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80142860: addiu       $a1, $a1, 0x2AC4
    ctx->r5 = ADD32(ctx->r5, 0X2AC4);
    after_0:
    // 0x80142864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80142868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014286C: jr          $ra
    // 0x80142870: nop

    return;
    // 0x80142870: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirHiSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EC00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015EC04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015EC08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015EC0C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015EC10: jal         0x800DEE98
    // 0x8015EC14: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015EC14: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015EC18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015EC1C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8015EC20: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x8015EC24: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015EC28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015EC2C: jal         0x800E6F24
    // 0x8015EC30: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015EC30: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015EC34: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8015EC38: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8015EC3C: addiu       $t8, $t8, -0x1680
    ctx->r24 = ADD32(ctx->r24, -0X1680);
    // 0x8015EC40: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x8015EC44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015EC48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015EC4C: jr          $ra
    // 0x8015EC50: nop

    return;
    // 0x8015EC50: nop

;}
RECOMP_FUNC void itKabigonJumpSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017E64C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E650: jal         0x8017E600
    // 0x8017E654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itKabigonJumpInitVars(rdram, ctx);
        goto after_0;
    // 0x8017E654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017E658: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017E65C: addiu       $a1, $a1, -0x548C
    ctx->r5 = ADD32(ctx->r5, -0X548C);
    // 0x8017E660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017E664: jal         0x80172EC8
    // 0x8017E668: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017E668: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8017E66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017E674: jr          $ra
    // 0x8017E678: nop

    return;
    // 0x8017E678: nop

;}
RECOMP_FUNC void mnOptionMakeMenuGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801321AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801321B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801321B4: addiu       $t7, $t7, 0x3680
    ctx->r15 = ADD32(ctx->r15, 0X3680);
    // 0x801321B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801321BC: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x801321C0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801321C4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801321C8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801321CC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801321D0: addiu       $t1, $t1, 0x368C
    ctx->r9 = ADD32(ctx->r9, 0X368C);
    // 0x801321D4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801321D8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801321DC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801321E0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801321E4: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x801321E8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801321EC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801321F0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801321F4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801321F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801321FC: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80132200: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80132204: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80132208: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8013220C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132210: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80132214: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x80132218: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x8013221C: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80132220: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132224: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132228: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x8013222C: jal         0x80009968
    // 0x80132230: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132230: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    after_0:
    // 0x80132234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132238: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013223C: sw          $v0, 0x37D0($at)
    MEM_W(0X37D0, ctx->r1) = ctx->r2;
    // 0x80132240: jr          $ra
    // 0x80132244: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80132244: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftCommonJumpAerialSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013FD74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013FD78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013FD7C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013FD80: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8013FD84: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013FD88: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8013FD8C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013FD90: lb          $t6, 0x1C2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1C2);
    // 0x8013FD94: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x8013FD98: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013FD9C: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x8013FDA0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013FDA4: lw          $t0, 0x9C8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013FDA8: mflo        $t8
    ctx->r24 = lo;
    // 0x8013FDAC: slti        $at, $t8, -0xA
    ctx->r1 = SIGNED(ctx->r24) < -0XA ? 1 : 0;
    // 0x8013FDB0: bne         $at, $zero, L_8013FDC0
    if (ctx->r1 != 0) {
        // 0x8013FDB4: nop
    
            goto L_8013FDC0;
    }
    // 0x8013FDB4: nop

    // 0x8013FDB8: b           L_8013FDC0
    // 0x8013FDBC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
        goto L_8013FDC0;
    // 0x8013FDBC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
L_8013FDC0:
    // 0x8013FDC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013FDC4: jal         0x800E6F24
    // 0x8013FDC8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013FDC8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x8013FDCC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8013FDD0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8013FDD4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8013FDD8: beq         $a0, $v0, L_8013FDE8
    if (ctx->r4 == ctx->r2) {
        // 0x8013FDDC: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_8013FDE8;
    }
    // 0x8013FDDC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8013FDE0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8013FDE4: bne         $v0, $at, L_8013FE08
    if (ctx->r2 != ctx->r1) {
        // 0x8013FDE8: lui         $at, 0x430C
        ctx->r1 = S32(0X430C << 16);
            goto L_8013FE08;
    }
L_8013FDE8:
    // 0x8013FDE8: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8013FDEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013FDF0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013FDF4: addiu       $t1, $t1, -0x494
    ctx->r9 = ADD32(ctx->r9, -0X494);
    // 0x8013FDF8: sw          $t1, 0x9E0($s0)
    MEM_W(0X9E0, ctx->r16) = ctx->r9;
    // 0x8013FDFC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8013FE00: b           L_8013FE34
    // 0x8013FE04: swc1        $f4, 0x7E8($s0)
    MEM_W(0X7E8, ctx->r16) = ctx->f4.u32l;
        goto L_8013FE34;
    // 0x8013FE04: swc1        $f4, 0x7E8($s0)
    MEM_W(0X7E8, ctx->r16) = ctx->f4.u32l;
L_8013FE08:
    // 0x8013FE08: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8013FE0C: beq         $v0, $at, L_8013FE20
    if (ctx->r2 == ctx->r1) {
        // 0x8013FE10: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_8013FE20;
    }
    // 0x8013FE10: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013FE14: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8013FE18: bnel        $v0, $at, L_8013FE38
    if (ctx->r2 != ctx->r1) {
        // 0x8013FE1C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8013FE38;
    }
    goto skip_0;
    // 0x8013FE1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
L_8013FE20:
    // 0x8013FE20: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8013FE24: addiu       $t2, $t2, -0x43C
    ctx->r10 = ADD32(ctx->r10, -0X43C);
    // 0x8013FE28: sw          $t2, 0x9E0($s0)
    MEM_W(0X9E0, ctx->r16) = ctx->r10;
    // 0x8013FE2C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8013FE30: swc1        $f6, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->f6.u32l;
L_8013FE34:
    // 0x8013FE34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8013FE38:
    // 0x8013FE38: beq         $v1, $at, L_8013FE54
    if (ctx->r3 == ctx->r1) {
        // 0x8013FE3C: addiu       $t3, $zero, 0x50
        ctx->r11 = ADD32(0, 0X50);
            goto L_8013FE54;
    }
    // 0x8013FE3C: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x8013FE40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013FE44: bnel        $v1, $at, L_8013FE58
    if (ctx->r3 != ctx->r1) {
        // 0x8013FE48: lb          $v1, 0x1C2($s0)
        ctx->r3 = MEM_B(ctx->r16, 0X1C2);
            goto L_8013FE58;
    }
    goto skip_1;
    // 0x8013FE48: lb          $v1, 0x1C2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1C2);
    skip_1:
    // 0x8013FE4C: b           L_8013FE58
    // 0x8013FE50: lb          $v1, 0x1C2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1C2);
        goto L_8013FE58;
    // 0x8013FE50: lb          $v1, 0x1C2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1C2);
L_8013FE54:
    // 0x8013FE54: lb          $v1, 0x1C2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1C2);
L_8013FE58:
    // 0x8013FE58: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8013FE5C: lwc1        $f16, 0x3C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x8013FE60: lwc1        $f4, 0x40($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8013FE64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013FE68: lwc1        $f8, 0x48($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8013FE6C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8013FE70: addiu       $t6, $zero, 0xFE
    ctx->r14 = ADD32(0, 0XFE);
    // 0x8013FE74: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8013FE78: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013FE7C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8013FE80: beq         $v0, $at, L_8013FE94
    if (ctx->r2 == ctx->r1) {
        // 0x8013FE84: swc1        $f10, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
            goto L_8013FE94;
    }
    // 0x8013FE84: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x8013FE88: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8013FE8C: bnel        $v0, $at, L_8013FEB0
    if (ctx->r2 != ctx->r1) {
        // 0x8013FE90: mtc1        $v1, $f8
        ctx->f8.u32l = ctx->r3;
            goto L_8013FEB0;
    }
    goto skip_2;
    // 0x8013FE90: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    skip_2:
L_8013FE94:
    // 0x8013FE94: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8013FE98: lwc1        $f4, 0x44($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X44);
    // 0x8013FE9C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013FEA0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8013FEA4: b           L_8013FEC0
    // 0x8013FEA8: swc1        $f6, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f6.u32l;
        goto L_8013FEC0;
    // 0x8013FEA8: swc1        $f6, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f6.u32l;
    // 0x8013FEAC: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_8013FEB0:
    // 0x8013FEB0: lwc1        $f16, 0x44($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X44);
    // 0x8013FEB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013FEB8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8013FEBC: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
L_8013FEC0:
    // 0x8013FEC0: lbu         $t4, 0x148($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X148);
    // 0x8013FEC4: lbu         $t8, 0x192($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X192);
    // 0x8013FEC8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8013FECC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8013FED0: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x8013FED4: sb          $t5, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r13;
    // 0x8013FED8: sb          $t6, 0x269($s0)
    MEM_B(0X269, ctx->r16) = ctx->r14;
    // 0x8013FEDC: beq         $a0, $v0, L_8013FEF0
    if (ctx->r4 == ctx->r2) {
        // 0x8013FEE0: sb          $t9, 0x192($s0)
        MEM_B(0X192, ctx->r16) = ctx->r25;
            goto L_8013FEF0;
    }
    // 0x8013FEE0: sb          $t9, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r25;
    // 0x8013FEE4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8013FEE8: bnel        $v0, $at, L_8013FF1C
    if (ctx->r2 != ctx->r1) {
        // 0x8013FEEC: sw          $zero, 0xB20($s0)
        MEM_W(0XB20, ctx->r16) = 0;
            goto L_8013FF1C;
    }
    goto skip_3;
    // 0x8013FEEC: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
    skip_3:
L_8013FEF0:
    // 0x8013FEF0: lb          $t1, 0x1C2($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1C2);
    // 0x8013FEF4: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x8013FEF8: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8013FEFC: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013FF00: mflo        $t3
    ctx->r11 = lo;
    // 0x8013FF04: slti        $at, $t3, -0x1E
    ctx->r1 = SIGNED(ctx->r11) < -0X1E ? 1 : 0;
    // 0x8013FF08: beql        $at, $zero, L_8013FF1C
    if (ctx->r1 == 0) {
        // 0x8013FF0C: sw          $zero, 0xB20($s0)
        MEM_W(0XB20, ctx->r16) = 0;
            goto L_8013FF1C;
    }
    goto skip_4;
    // 0x8013FF0C: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
    skip_4:
    // 0x8013FF10: b           L_8013FF1C
    // 0x8013FF14: sw          $t4, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r12;
        goto L_8013FF1C;
    // 0x8013FF14: sw          $t4, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r12;
    // 0x8013FF18: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
L_8013FF1C:
    // 0x8013FF1C: jal         0x8013FA90
    // 0x8013FF20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonJumpAerialUpdateModelYaw(rdram, ctx);
        goto after_1;
    // 0x8013FF20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013FF24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013FF28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013FF2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013FF30: jr          $ra
    // 0x8013FF34: nop

    return;
    // 0x8013FF34: nop

;}
RECOMP_FUNC void grJungleTaruCannUpdateRotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109DBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80109DC0: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80109DC4: lhu         $t6, 0xA($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XA);
    // 0x80109DC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109DD0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80109DD4: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80109DD8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80109DDC: bne         $t8, $zero, L_80109E14
    if (ctx->r24 != 0) {
        // 0x80109DE0: sh          $t7, 0xA($v1)
        MEM_H(0XA, ctx->r3) = ctx->r15;
            goto L_80109E14;
    }
    // 0x80109DE0: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x80109DE4: sb          $zero, 0x8($v1)
    MEM_B(0X8, ctx->r3) = 0;
    // 0x80109DE8: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    // 0x80109DEC: jal         0x80018994
    // 0x80109DF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80109DF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80109DF4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80109DF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80109DFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80109E00: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80109E04: addiu       $t9, $v0, 0xB4
    ctx->r25 = ADD32(ctx->r2, 0XB4);
    // 0x80109E08: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
    // 0x80109E0C: b           L_80109E24
    // 0x80109E10: swc1        $f4, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f4.u32l;
        goto L_80109E24;
    // 0x80109E10: swc1        $f4, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f4.u32l;
L_80109E14:
    // 0x80109E14: lwc1        $f6, 0x38($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80109E18: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80109E1C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80109E20: swc1        $f10, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f10.u32l;
L_80109E24:
    // 0x80109E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109E28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80109E2C: jr          $ra
    // 0x80109E30: nop

    return;
    // 0x80109E30: nop

;}
RECOMP_FUNC void mnTitleStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801340B8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801340BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801340C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801340C4: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801340C8: addiu       $a0, $a0, 0x4370
    ctx->r4 = ADD32(ctx->r4, 0X4370);
    // 0x801340CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801340D0: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801340D4: jal         0x80007024
    // 0x801340D8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801340D8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801340DC: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x801340E0: lbu         $t8, 0x4B14($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4B14);
    // 0x801340E4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801340E8: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
    // 0x801340EC: bne         $t8, $zero, L_8013410C
    if (ctx->r24 != 0) {
        // 0x801340F0: nop
    
            goto L_8013410C;
    }
    // 0x801340F0: nop

    // 0x801340F4: lbu         $v0, 0x5E3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5E3);
    // 0x801340F8: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x801340FC: beq         $at, $zero, L_8013410C
    if (ctx->r1 == 0) {
        // 0x80134100: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_8013410C;
    }
    // 0x80134100: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80134104: jal         0x800D45F4
    // 0x80134108: sb          $t9, 0x5E3($v1)
    MEM_B(0X5E3, ctx->r3) = ctx->r25;
    lbBackupWrite(rdram, ctx);
        goto after_1;
    // 0x80134108: sb          $t9, 0x5E3($v1)
    MEM_B(0X5E3, ctx->r3) = ctx->r25;
    after_1:
L_8013410C:
    // 0x8013410C: lui         $t0, 0x8037
    ctx->r8 = S32(0X8037 << 16);
    // 0x80134110: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80134114: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134118: addiu       $t1, $t1, 0x45B0
    ctx->r9 = ADD32(ctx->r9, 0X45B0);
    // 0x8013411C: addiu       $t0, $t0, -0x6DC0
    ctx->r8 = ADD32(ctx->r8, -0X6DC0);
    // 0x80134120: addiu       $a0, $a0, 0x438C
    ctx->r4 = ADD32(ctx->r4, 0X438C);
    // 0x80134124: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80134128: jal         0x8000683C
    // 0x8013412C: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    syTaskmanStartTask(rdram, ctx);
        goto after_2;
    // 0x8013412C: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    after_2:
    // 0x80134130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134138: jr          $ra
    // 0x8013413C: nop

    return;
    // 0x8013413C: nop

;}
RECOMP_FUNC void spShow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025F38: jal         0x80025EF0
    // 0x80025F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    spClearAttribute(rdram, ctx);
        goto after_0;
    // 0x80025F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80025F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025F48: jr          $ra
    // 0x80025F4C: nop

    return;
    // 0x80025F4C: nop

;}
RECOMP_FUNC void func_ovl8_803851E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803851E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x803851E8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x803851EC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x803851F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803851F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803851F8: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x803851FC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80385200: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80385204: bne         $a0, $zero, L_8038521C
    if (ctx->r4 != 0) {
        // 0x80385208: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_8038521C;
    }
    // 0x80385208: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8038520C: jal         0x803717A0
    // 0x80385210: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80385210: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_0:
    // 0x80385214: beq         $v0, $zero, L_80385320
    if (ctx->r2 == 0) {
        // 0x80385218: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80385320;
    }
    // 0x80385218: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8038521C:
    // 0x8038521C: bne         $s2, $zero, L_80385240
    if (ctx->r18 != 0) {
        // 0x80385220: addiu       $a0, $s0, 0x60
        ctx->r4 = ADD32(ctx->r16, 0X60);
            goto L_80385240;
    }
    // 0x80385220: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    // 0x80385224: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    // 0x80385228: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8038522C: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x80385230: jal         0x803717E0
    // 0x80385234: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80385234: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    after_1:
    // 0x80385238: jal         0x8037C2D0
    // 0x8038523C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8038523C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
L_80385240:
    // 0x80385240: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80385244: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80385248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038524C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80385250: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80385254: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80385258: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8038525C: jal         0x803847A0
    // 0x80385260: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_803847A0(rdram, ctx);
        goto after_3;
    // 0x80385260: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x80385264: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x80385268: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8038526C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80385270: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80385274: jal         0x803724B4
    // 0x80385278: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_ovl8_803724B4(rdram, ctx);
        goto after_4;
    // 0x80385278: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8038527C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80385280: addiu       $t8, $t8, -0x29B0
    ctx->r24 = ADD32(ctx->r24, -0X29B0);
    // 0x80385284: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80385288: addiu       $t9, $t9, -0x2888
    ctx->r25 = ADD32(ctx->r25, -0X2888);
    // 0x8038528C: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80385290: sw          $t9, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r25;
    // 0x80385294: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80385298: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8038529C: addiu       $t0, $t0, -0x2730
    ctx->r8 = ADD32(ctx->r8, -0X2730);
    // 0x803852A0: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x803852A4: addiu       $t2, $t2, -0x2708
    ctx->r10 = ADD32(ctx->r10, -0X2708);
    // 0x803852A8: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x803852AC: sw          $t2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r10;
    // 0x803852B0: lhu         $v1, 0x10($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X10);
    // 0x803852B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x803852B8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x803852BC: bne         $v1, $at, L_803852CC
    if (ctx->r3 != ctx->r1) {
        // 0x803852C0: addiu       $a1, $sp, 0x40
        ctx->r5 = ADD32(ctx->r29, 0X40);
            goto L_803852CC;
    }
    // 0x803852C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x803852C4: b           L_803852DC
    // 0x803852C8: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
        goto L_803852DC;
    // 0x803852C8: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
L_803852CC:
    // 0x803852CC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x803852D0: bne         $v1, $at, L_803852DC
    if (ctx->r3 != ctx->r1) {
        // 0x803852D4: addiu       $s2, $zero, 0x3
        ctx->r18 = ADD32(0, 0X3);
            goto L_803852DC;
    }
    // 0x803852D4: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x803852D8: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
L_803852DC:
    // 0x803852DC: lhu         $t3, 0x4($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X4);
    // 0x803852E0: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x803852E4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x803852E8: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x803852EC: lhu         $t4, 0x6($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X6);
    // 0x803852F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x803852F4: jal         0x8037B85C
    // 0x803852F8: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    func_ovl8_8037B85C(rdram, ctx);
        goto after_5;
    // 0x803852F8: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    after_5:
    // 0x803852FC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80385300: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80385304: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x80385308: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8038530C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80385310: jal         0x8037ACAC
    // 0x80385314: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_6;
    // 0x80385314: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_6:
    // 0x80385318: sw          $v0, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r2;
    // 0x8038531C: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
L_80385320:
    // 0x80385320: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80385324: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80385328: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8038532C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80385330: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80385334: jr          $ra
    // 0x80385338: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80385338: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ifCommonPlayerArrowsUpdateFlags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801119AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801119B0: nop

    // 0x801119B4: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x801119B8: nop

    // 0x801119BC: bc1fl       L_801119D0
    if (!c1cs) {
        // 0x801119C0: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_801119D0;
    }
    goto skip_0;
    // 0x801119C0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x801119C4: b           L_801119D0
    // 0x801119C8: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_801119D0;
    // 0x801119C8: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x801119CC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_801119D0:
    // 0x801119D0: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x801119D4: nop

    // 0x801119D8: bc1fl       L_801119EC
    if (!c1cs) {
        // 0x801119DC: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_801119EC;
    }
    goto skip_1;
    // 0x801119DC: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_1:
    // 0x801119E0: b           L_801119EC
    // 0x801119E4: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_801119EC;
    // 0x801119E4: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x801119E8: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_801119EC:
    // 0x801119EC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801119F0: nop

    // 0x801119F4: bc1f        L_80111A34
    if (!c1cs) {
        // 0x801119F8: nop
    
            goto L_80111A34;
    }
    // 0x801119F8: nop

    // 0x801119FC: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80111A00: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80111A04: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, 0X1580);
    // 0x80111A08: bc1fl       L_80111A2C
    if (!c1cs) {
        // 0x80111A0C: lbu         $t8, 0xE($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0XE);
            goto L_80111A2C;
    }
    goto skip_2;
    // 0x80111A0C: lbu         $t8, 0xE($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XE);
    skip_2:
    // 0x80111A10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80111A14: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, 0X1580);
    // 0x80111A18: lbu         $t6, 0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XE);
    // 0x80111A1C: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80111A20: jr          $ra
    // 0x80111A24: sb          $t7, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r15;
    return;
    // 0x80111A24: sb          $t7, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r15;
    // 0x80111A28: lbu         $t8, 0xE($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XE);
L_80111A2C:
    // 0x80111A2C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80111A30: sb          $t9, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r25;
L_80111A34:
    // 0x80111A34: jr          $ra
    // 0x80111A38: nop

    return;
    // 0x80111A38: nop

;}
RECOMP_FUNC void mpCollisionGetEdgeRightDLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAD24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FAD28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FAD2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FAD30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FAD34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAD38: beq         $a0, $at, L_800FAD4C
    if (ctx->r4 == ctx->r1) {
        // 0x800FAD3C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FAD4C;
    }
    // 0x800FAD3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FAD40: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FAD44: bne         $a0, $at, L_800FAD70
    if (ctx->r4 != ctx->r1) {
        // 0x800FAD48: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FAD70;
    }
    // 0x800FAD48: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FAD4C:
    // 0x800FAD4C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAD50: addiu       $s0, $s0, 0x5C0
    ctx->r16 = ADD32(ctx->r16, 0X5C0);
    // 0x800FAD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAD58:
    // 0x800FAD58: jal         0x80023624
    // 0x800FAD5C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FAD5C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FAD60: jal         0x800A3040
    // 0x800FAD64: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FAD64: nop

    after_1:
    // 0x800FAD68: b           L_800FAD58
    // 0x800FAD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FAD58;
    // 0x800FAD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAD70:
    // 0x800FAD70: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FAD74: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FAD78: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FAD7C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FAD80: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FAD84: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FAD88: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FAD8C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FAD90: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FAD94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FAD98: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FAD9C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FADA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FADA4: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FADA8: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FADAC: bnel        $at, $zero, L_800FADD8
    if (ctx->r1 != 0) {
        // 0x800FADB0: lh          $v0, 0x8($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X8);
            goto L_800FADD8;
    }
    goto skip_0;
    // 0x800FADB0: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    skip_0:
    // 0x800FADB4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FADB8: addiu       $s0, $s0, 0x5E0
    ctx->r16 = ADD32(ctx->r16, 0X5E0);
L_800FADBC:
    // 0x800FADBC: jal         0x80023624
    // 0x800FADC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FADC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FADC4: jal         0x800A3040
    // 0x800FADC8: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FADC8: nop

    after_3:
    // 0x800FADCC: b           L_800FADBC
    // 0x800FADD0: nop

        goto L_800FADBC;
    // 0x800FADD0: nop

    // 0x800FADD4: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
L_800FADD8:
    // 0x800FADD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FADDC: jr          $ra
    // 0x800FADE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FADE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonSquatSetStatusNoPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80143028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014302C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80143030: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80143034: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143038: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8014303C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80143040: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80143044: jal         0x800E6F24
    // 0x80143048: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80143048: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8014304C: jal         0x800E0830
    // 0x80143050: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80143050: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80143054: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80143058: lbu         $t7, 0x192($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X192);
    // 0x8014305C: lb          $t9, 0x1C3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1C3);
    // 0x80143060: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    // 0x80143064: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80143068: slti        $at, $t9, -0x34
    ctx->r1 = SIGNED(ctx->r25) < -0X34 ? 1 : 0;
    // 0x8014306C: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    // 0x80143070: beq         $at, $zero, L_80143094
    if (ctx->r1 == 0) {
        // 0x80143074: sw          $zero, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = 0;
            goto L_80143094;
    }
    // 0x80143074: sw          $zero, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = 0;
    // 0x80143078: lbu         $t0, 0x269($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X269);
    // 0x8014307C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80143080: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80143084: beql        $at, $zero, L_80143098
    if (ctx->r1 == 0) {
        // 0x80143088: sw          $zero, 0xB20($v0)
        MEM_W(0XB20, ctx->r2) = 0;
            goto L_80143098;
    }
    goto skip_0;
    // 0x80143088: sw          $zero, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = 0;
    skip_0:
    // 0x8014308C: b           L_80143098
    // 0x80143090: sw          $t1, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r9;
        goto L_80143098;
    // 0x80143090: sw          $t1, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r9;
L_80143094:
    // 0x80143094: sw          $zero, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = 0;
L_80143098:
    // 0x80143098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014309C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801430A0: jr          $ra
    // 0x801430A4: nop

    return;
    // 0x801430A4: nop

;}
RECOMP_FUNC void mnPlayersVSGetPuckFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013782C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80137830: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80137834: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80137838: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013783C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80137840: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137844: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80137848: lw          $t7, -0x4574($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4574);
    // 0x8013784C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80137850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137854: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x80137858: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013785C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80137860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80137864: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80137868: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8013786C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80137870: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80137874: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80137878: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x8013787C: bne         $at, $zero, L_80137898
    if (ctx->r1 != 0) {
        // 0x80137880: addiu       $a1, $a1, 0xD
        ctx->r5 = ADD32(ctx->r5, 0XD);
            goto L_80137898;
    }
    // 0x80137880: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x80137884: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80137888: beq         $at, $zero, L_80137898
    if (ctx->r1 == 0) {
        // 0x8013788C: nop
    
            goto L_80137898;
    }
    // 0x8013788C: nop

    // 0x80137890: b           L_80137898
    // 0x80137894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80137898;
    // 0x80137894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80137898:
    // 0x80137898: beq         $v0, $zero, L_8013790C
    if (ctx->r2 == 0) {
        // 0x8013789C: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_8013790C;
    }
    // 0x8013789C: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x801378A0: bne         $at, $zero, L_801378BC
    if (ctx->r1 != 0) {
        // 0x801378A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801378BC;
    }
    // 0x801378A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801378A8: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x801378AC: beq         $at, $zero, L_801378BC
    if (ctx->r1 == 0) {
        // 0x801378B0: nop
    
            goto L_801378BC;
    }
    // 0x801378B0: nop

    // 0x801378B4: b           L_801378BC
    // 0x801378B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801378BC;
    // 0x801378B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801378BC:
    // 0x801378BC: beq         $v0, $zero, L_8013790C
    if (ctx->r2 == 0) {
        // 0x801378C0: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_8013790C;
    }
    // 0x801378C0: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x801378C4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x801378C8: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x801378CC: mflo        $a0
    ctx->r4 = lo;
    // 0x801378D0: jal         0x80132118
    // 0x801378D4: nop

    mnPlayersVSGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x801378D4: nop

    after_0:
    // 0x801378D8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801378DC: jal         0x80131ED8
    // 0x801378E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayersVSCheckFighterCrossed(rdram, ctx);
        goto after_1;
    // 0x801378E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801378E4: bne         $v0, $zero, L_801378FC
    if (ctx->r2 != 0) {
        // 0x801378E8: nop
    
            goto L_801378FC;
    }
    // 0x801378E8: nop

    // 0x801378EC: jal         0x80132044
    // 0x801378F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayersVSCheckFighterLocked(rdram, ctx);
        goto after_2;
    // 0x801378F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801378F4: beq         $v0, $zero, L_80137904
    if (ctx->r2 == 0) {
        // 0x801378F8: nop
    
            goto L_80137904;
    }
    // 0x801378F8: nop

L_801378FC:
    // 0x801378FC: b           L_801379A8
    // 0x80137900: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_801379A8;
    // 0x80137900: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80137904:
    // 0x80137904: b           L_801379A8
    // 0x80137908: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_801379A8;
    // 0x80137908: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_8013790C:
    // 0x8013790C: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80137910: bne         $at, $zero, L_8013792C
    if (ctx->r1 != 0) {
        // 0x80137914: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013792C;
    }
    // 0x80137914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80137918: slti        $at, $v1, 0x7A
    ctx->r1 = SIGNED(ctx->r3) < 0X7A ? 1 : 0;
    // 0x8013791C: beq         $at, $zero, L_8013792C
    if (ctx->r1 == 0) {
        // 0x80137920: nop
    
            goto L_8013792C;
    }
    // 0x80137920: nop

    // 0x80137924: b           L_8013792C
    // 0x80137928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013792C;
    // 0x80137928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013792C:
    // 0x8013792C: beq         $v0, $zero, L_801379A4
    if (ctx->r2 == 0) {
        // 0x80137930: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_801379A4;
    }
    // 0x80137930: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80137934: bne         $at, $zero, L_80137950
    if (ctx->r1 != 0) {
        // 0x80137938: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80137950;
    }
    // 0x80137938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013793C: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80137940: beq         $at, $zero, L_80137950
    if (ctx->r1 == 0) {
        // 0x80137944: nop
    
            goto L_80137950;
    }
    // 0x80137944: nop

    // 0x80137948: b           L_80137950
    // 0x8013794C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80137950;
    // 0x8013794C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80137950:
    // 0x80137950: beq         $v0, $zero, L_801379A4
    if (ctx->r2 == 0) {
        // 0x80137954: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_801379A4;
    }
    // 0x80137954: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80137958: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8013795C: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80137960: mflo        $a0
    ctx->r4 = lo;
    // 0x80137964: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80137968: jal         0x80132118
    // 0x8013796C: nop

    mnPlayersVSGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x8013796C: nop

    after_3:
    // 0x80137970: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80137974: jal         0x80131ED8
    // 0x80137978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayersVSCheckFighterCrossed(rdram, ctx);
        goto after_4;
    // 0x80137978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8013797C: bne         $v0, $zero, L_80137994
    if (ctx->r2 != 0) {
        // 0x80137980: nop
    
            goto L_80137994;
    }
    // 0x80137980: nop

    // 0x80137984: jal         0x80132044
    // 0x80137988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayersVSCheckFighterLocked(rdram, ctx);
        goto after_5;
    // 0x80137988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x8013798C: beq         $v0, $zero, L_8013799C
    if (ctx->r2 == 0) {
        // 0x80137990: nop
    
            goto L_8013799C;
    }
    // 0x80137990: nop

L_80137994:
    // 0x80137994: b           L_801379A8
    // 0x80137998: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_801379A8;
    // 0x80137998: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_8013799C:
    // 0x8013799C: b           L_801379A8
    // 0x801379A0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_801379A8;
    // 0x801379A0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_801379A4:
    // 0x801379A4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801379A8:
    // 0x801379A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801379AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801379B0: jr          $ra
    // 0x801379B4: nop

    return;
    // 0x801379B4: nop

;}
RECOMP_FUNC void sc1PBonusStageUpdatePlatformInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D890: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018D894: addiu       $a1, $a1, 0x13F0
    ctx->r5 = ADD32(ctx->r5, 0X13F0);
    // 0x8018D898: lbu         $v1, 0x10($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X10);
    // 0x8018D89C: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8018D8A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D8A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D8A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D8AC: blez        $v1, L_8018D8C4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8018D8B0: lw          $a0, 0x74($t6)
        ctx->r4 = MEM_W(ctx->r14, 0X74);
            goto L_8018D8C4;
    }
    // 0x8018D8B0: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
L_8018D8B4:
    // 0x8018D8B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018D8B8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018D8BC: bne         $at, $zero, L_8018D8B4
    if (ctx->r1 != 0) {
        // 0x8018D8C0: lw          $a0, 0x8($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X8);
            goto L_8018D8B4;
    }
    // 0x8018D8C0: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
L_8018D8C4:
    // 0x8018D8C4: jal         0x800096EC
    // 0x8018D8C8: nop

    gcEjectSObj(rdram, ctx);
        goto after_0;
    // 0x8018D8C8: nop

    after_0:
    // 0x8018D8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D8D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D8D4: jr          $ra
    // 0x8018D8D8: nop

    return;
    // 0x8018D8D8: nop

;}
RECOMP_FUNC void mnVSRecordRedrawStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D48: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135D4C: lw          $a1, 0x6C20($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6C20);
    // 0x80135D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135D58: beq         $a1, $zero, L_80135D68
    if (ctx->r5 == 0) {
        // 0x80135D5C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80135D68;
    }
    // 0x80135D5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80135D60: jal         0x80009A84
    // 0x80135D64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80135D64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_80135D68:
    // 0x80135D68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80135D6C: lw          $a0, 0x6C24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C24);
    // 0x80135D70: beq         $a0, $zero, L_80135D80
    if (ctx->r4 == 0) {
        // 0x80135D74: nop
    
            goto L_80135D80;
    }
    // 0x80135D74: nop

    // 0x80135D78: jal         0x80009A84
    // 0x80135D7C: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80135D7C: nop

    after_1:
L_80135D80:
    // 0x80135D80: jal         0x80135934
    // 0x80135D84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnVSRecordMakeStats(rdram, ctx);
        goto after_2;
    // 0x80135D84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80135D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135D90: jr          $ra
    // 0x80135D94: nop

    return;
    // 0x80135D94: nop

;}
RECOMP_FUNC void syDmaSramPiInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002D14: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80002D18: addiu       $a2, $a2, 0x5048
    ctx->r6 = ADD32(ctx->r6, 0X5048);
    // 0x80002D1C: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x80002D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002D24: lui         $v0, 0xA800
    ctx->r2 = S32(0XA800 << 16);
    // 0x80002D28: bne         $v0, $t6, L_80002D38
    if (ctx->r2 != ctx->r14) {
        // 0x80002D2C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80002D38;
    }
    // 0x80002D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002D30: b           L_80002D94
    // 0x80002D34: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_80002D94;
    // 0x80002D34: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80002D38:
    // 0x80002D38: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80002D3C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80002D40: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80002D44: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x80002D48: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80002D4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80002D50: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002D54: sb          $t7, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r15;
    // 0x80002D58: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x80002D5C: sb          $t8, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r24;
    // 0x80002D60: sb          $t9, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r25;
    // 0x80002D64: sb          $t0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r8;
    // 0x80002D68: sb          $t1, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r9;
    // 0x80002D6C: sb          $t2, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r10;
    // 0x80002D70: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80002D74: addiu       $a0, $a0, 0x505C
    ctx->r4 = ADD32(ctx->r4, 0X505C);
    // 0x80002D78: jal         0x800315B0
    // 0x80002D7C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    _bzero(rdram, ctx);
        goto after_0;
    // 0x80002D7C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_0:
    // 0x80002D80: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80002D84: jal         0x80032810
    // 0x80002D88: addiu       $a0, $a2, 0x5048
    ctx->r4 = ADD32(ctx->r6, 0X5048);
    osEPiLinkHandle(rdram, ctx);
        goto after_1;
    // 0x80002D88: addiu       $a0, $a2, 0x5048
    ctx->r4 = ADD32(ctx->r6, 0X5048);
    after_1:
    // 0x80002D8C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80002D90: addiu       $v0, $a2, 0x5048
    ctx->r2 = ADD32(ctx->r6, 0X5048);
L_80002D94:
    // 0x80002D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002D9C: jr          $ra
    // 0x80002DA0: nop

    return;
    // 0x80002DA0: nop

;}
RECOMP_FUNC void ftCommonGuardOnCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80148D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148D14: jal         0x80148CBC
    // 0x80148D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftCommonGuardOnCheckInterruptSuccess(rdram, ctx);
        goto after_0;
    // 0x80148D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80148D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80148D24: jr          $ra
    // 0x80148D28: nop

    return;
    // 0x80148D28: nop

;}
RECOMP_FUNC void func_ovl8_8037BF68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BF68: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8037BF6C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8037BF70: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x8037BF74: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8037BF78: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8037BF7C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8037BF80: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8037BF84: bne         $s0, $zero, L_8037BF94
    if (ctx->r16 != 0) {
        // 0x8037BF88: sw          $a3, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r7;
            goto L_8037BF94;
    }
    // 0x8037BF88: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8037BF8C: b           L_8037BF98
    // 0x8037BF90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8037BF98;
    // 0x8037BF90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8037BF94:
    // 0x8037BF94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037BF98:
    // 0x8037BF98: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8037BF9C: addiu       $t6, $t6, -0x7D00
    ctx->r14 = ADD32(ctx->r14, -0X7D00);
    // 0x8037BFA0: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8037BFA4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8037BFA8: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8037BFAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037BFB0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8037BFB4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8037BFB8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8037BFBC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8037BFC0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8037BFC4: addiu       $a1, $a1, -0x4E3C
    ctx->r5 = ADD32(ctx->r5, -0X4E3C);
    // 0x8037BFC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037BFCC: addiu       $a0, $zero, -0x1FF
    ctx->r4 = ADD32(0, -0X1FF);
    // 0x8037BFD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037BFD4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8037BFD8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8037BFDC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8037BFE0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8037BFE4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8037BFE8: jal         0x8000B93C
    // 0x8037BFEC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8037BFEC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x8037BFF0: bne         $v0, $zero, L_8037C000
    if (ctx->r2 != 0) {
        // 0x8037BFF4: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_8037C000;
    }
    // 0x8037BFF4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8037BFF8: b           L_8037C0B8
    // 0x8037BFFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8037C0B8;
    // 0x8037BFFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8037C000:
    // 0x8037C000: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x8037C004: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8037C008: addiu       $a0, $zero, -0x1FC
    ctx->r4 = ADD32(0, -0X1FC);
    // 0x8037C00C: sw          $t1, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->r9;
    // 0x8037C010: bne         $s0, $zero, L_8037C03C
    if (ctx->r16 != 0) {
        // 0x8037C014: sw          $v0, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->r2;
            goto L_8037C03C;
    }
    // 0x8037C014: sw          $v0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r2;
    // 0x8037C018: addiu       $a0, $zero, -0x1FD
    ctx->r4 = ADD32(0, -0X1FD);
    // 0x8037C01C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C020: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8037C024: jal         0x800099A8
    // 0x8037C028: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeGObjSPBefore(rdram, ctx);
        goto after_1;
    // 0x8037C028: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8037C02C: bne         $v0, $zero, L_8037C05C
    if (ctx->r2 != 0) {
        // 0x8037C030: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037C05C;
    }
    // 0x8037C030: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8037C034: b           L_8037C0B8
    // 0x8037C038: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8037C0B8;
    // 0x8037C038: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8037C03C:
    // 0x8037C03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C040: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8037C044: jal         0x800099A8
    // 0x8037C048: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeGObjSPBefore(rdram, ctx);
        goto after_2;
    // 0x8037C048: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8037C04C: bne         $v0, $zero, L_8037C05C
    if (ctx->r2 != 0) {
        // 0x8037C050: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037C05C;
    }
    // 0x8037C050: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8037C054: b           L_8037C0B8
    // 0x8037C058: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8037C0B8;
    // 0x8037C058: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8037C05C:
    // 0x8037C05C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8037C060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037C064: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8037C068: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x8037C06C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8037C070: jal         0x80009DF4
    // 0x8037C074: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x8037C074: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_3:
    // 0x8037C078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037C07C: jal         0x80009614
    // 0x8037C080: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    gcAddSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8037C080: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_4:
    // 0x8037C084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037C088: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8037C08C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037C090: jal         0x80008188
    // 0x8037C094: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x8037C094: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8037C098: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8037C09C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037C0A0: sw          $t4, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r12;
    // 0x8037C0A4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8037C0A8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8037C0AC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8037C0B0: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8037C0B4: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
L_8037C0B8:
    // 0x8037C0B8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8037C0BC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8037C0C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8037C0C4: jr          $ra
    // 0x8037C0C8: nop

    return;
    // 0x8037C0C8: nop

;}
RECOMP_FUNC void mvOpeningSamusFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DED0: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DED4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DED8: addiu       $v1, $v1, -0x1B68
    ctx->r3 = ADD32(ctx->r3, -0X1B68);
    // 0x8018DEDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DEE0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DEE4: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DEE8: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018DEEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DEF0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018DEF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8018DEF8: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DEFC: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018DF00:
    // 0x8018DF00: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DF04: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DF08: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DF0C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DF10: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DF14: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DF18: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DF1C: bne         $t6, $t0, L_8018DF00
    if (ctx->r14 != ctx->r8) {
        // 0x8018DF20: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DF00;
    }
    // 0x8018DF20: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DF24: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DF28: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DF2C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DF30: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8018DF34: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8018DF38: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
    // 0x8018DF3C: sb          $t3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r11;
    // 0x8018DF40: sb          $a1, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r5;
    // 0x8018DF44: jal         0x8018D0C0
    // 0x8018DF48: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    mvOpeningSamusSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DF48: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    after_0:
    // 0x8018DF4C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DF50: addiu       $a1, $a1, -0x21F8
    ctx->r5 = ADD32(ctx->r5, -0X21F8);
    // 0x8018DF54: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018DF58: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018DF5C: jal         0x80009968
    // 0x8018DF60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018DF60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DF64: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8018DF68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DF6C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DF70: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DF74: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DF78: jal         0x8000B9FC
    // 0x8018DF7C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DF7C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018DF80: jal         0x8018DEC4
    // 0x8018DF84: nop

    mvOpeningSamusInitVars(rdram, ctx);
        goto after_3;
    // 0x8018DF84: nop

    after_3:
    // 0x8018DF88: jal         0x80115890
    // 0x8018DF8C: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018DF8C: nop

    after_4:
    // 0x8018DF90: jal         0x800EC130
    // 0x8018DF94: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018DF94: nop

    after_5:
    // 0x8018DF98: jal         0x800FC284
    // 0x8018DF9C: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018DF9C: nop

    after_6:
    // 0x8018DFA0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DFA4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DFA8: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DFAC: jal         0x8010E598
    // 0x8018DFB0: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018DFB0: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018DFB4: jal         0x8010DB54
    // 0x8018DFB8: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018DFB8: nop

    after_8:
    // 0x8018DFBC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DFC0: jal         0x800D7194
    // 0x8018DFC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8018DFC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018DFC8: jal         0x801654B0
    // 0x8018DFCC: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_10;
    // 0x8018DFCC: nop

    after_10:
    // 0x8018DFD0: jal         0x8016DEA0
    // 0x8018DFD4: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018DFD4: nop

    after_11:
    // 0x8018DFD8: jal         0x800FD300
    // 0x8018DFDC: nop

    efManagerInitEffects(rdram, ctx);
        goto after_12;
    // 0x8018DFDC: nop

    after_12:
    // 0x8018DFE0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018DFE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018DFE8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8018DFEC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018DFF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DFF4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018DFF8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8018DFFC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8018E000: jal         0x803904E0
    // 0x8018E004: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_13;
    // 0x8018E004: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_13:
    // 0x8018E008: jal         0x800D786C
    // 0x8018E00C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_14;
    // 0x8018E00C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x8018E010: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018E014: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8018E018: jal         0x80004980
    // 0x8018E01C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_15;
    // 0x8018E01C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_15:
    // 0x8018E020: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E024: jal         0x8018DBC8
    // 0x8018E028: sw          $v0, -0x1D74($at)
    MEM_W(-0X1D74, ctx->r1) = ctx->r2;
    mvOpeningSamusMakeNameCamera(rdram, ctx);
        goto after_16;
    // 0x8018E028: sw          $v0, -0x1D74($at)
    MEM_W(-0X1D74, ctx->r1) = ctx->r2;
    after_16:
    // 0x8018E02C: jal         0x8018DD58
    // 0x8018E030: nop

    mvOpeningSamusMakePosedWallpaperCamera(rdram, ctx);
        goto after_17;
    // 0x8018E030: nop

    after_17:
    // 0x8018E034: jal         0x8018DC68
    // 0x8018E038: nop

    mvOpeningSamusMakePosedFighterCamera(rdram, ctx);
        goto after_18;
    // 0x8018E038: nop

    after_18:
    // 0x8018E03C: jal         0x8018D194
    // 0x8018E040: nop

    mvOpeningSamusMakeName(rdram, ctx);
        goto after_19;
    // 0x8018E040: nop

    after_19:
    // 0x8018E044: jal         0x8000092C
    // 0x8018E048: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x8018E048: nop

    after_20:
    // 0x8018E04C: sltiu       $at, $v0, 0x6F9
    ctx->r1 = ctx->r2 < 0X6F9 ? 1 : 0;
    // 0x8018E050: beql        $at, $zero, L_8018E070
    if (ctx->r1 == 0) {
        // 0x8018E054: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018E070;
    }
    goto skip_0;
    // 0x8018E054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018E058:
    // 0x8018E058: jal         0x8000092C
    // 0x8018E05C: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_21;
    // 0x8018E05C: nop

    after_21:
    // 0x8018E060: sltiu       $at, $v0, 0x6F9
    ctx->r1 = ctx->r2 < 0X6F9 ? 1 : 0;
    // 0x8018E064: bne         $at, $zero, L_8018E058
    if (ctx->r1 != 0) {
        // 0x8018E068: nop
    
            goto L_8018E058;
    }
    // 0x8018E068: nop

    // 0x8018E06C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018E070:
    // 0x8018E070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E074: jr          $ra
    // 0x8018E078: nop

    return;
    // 0x8018E078: nop

;}
RECOMP_FUNC void itTaruFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179D24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80179D28: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80179D2C: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80179D30: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80179D34: jal         0x80173F78
    // 0x80179D38: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80179D38: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80179D3C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179D40: addiu       $a1, $a1, -0x5B7C
    ctx->r5 = ADD32(ctx->r5, -0X5B7C);
    // 0x80179D44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80179D48: jal         0x80172EC8
    // 0x80179D4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80179D4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80179D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179D58: jr          $ra
    // 0x80179D5C: nop

    return;
    // 0x80179D5C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePortraitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132598: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013259C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801325A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801325A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801325A8: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
L_801325AC:
    // 0x801325AC: jal         0x801323D8
    // 0x801325B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingMakePortrait(rdram, ctx);
        goto after_0;
    // 0x801325B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801325B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801325B8: bne         $s0, $s1, L_801325AC
    if (ctx->r16 != ctx->r17) {
        // 0x801325BC: nop
    
            goto L_801325AC;
    }
    // 0x801325BC: nop

    // 0x801325C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801325C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801325C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801325CC: jr          $ra
    // 0x801325D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801325D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mvOpeningSectorInitTotalTimeTics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132640: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132644: jr          $ra
    // 0x80132648: sw          $zero, 0x2A18($at)
    MEM_W(0X2A18, ctx->r1) = 0;
    return;
    // 0x80132648: sw          $zero, 0x2A18($at)
    MEM_W(0X2A18, ctx->r1) = 0;
;}
RECOMP_FUNC void mnPlayers1PTrainingMakeHandicapLevelCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136128: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013612C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80136130: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80136134: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80136138: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x8013613C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80136140: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80136144: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80136148: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013614C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80136150: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80136154: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80136158: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013615C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80136160: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80136164: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80136168: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013616C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80136170: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80136174: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80136178: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013617C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136180: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80136184: jal         0x8000B93C
    // 0x80136188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80136188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013618C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136190: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80136194: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80136198: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013619C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801361A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801361A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801361A8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801361AC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801361B0: jal         0x80007080
    // 0x801361B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801361B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801361B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801361BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801361C0: jr          $ra
    // 0x801361C4: nop

    return;
    // 0x801361C4: nop

;}
RECOMP_FUNC void mpCollisionSetBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC42C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FC430: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x800FC434: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FC438: addiu       $v0, $v0, 0x13A0
    ctx->r2 = ADD32(ctx->r2, 0X13A0);
    // 0x800FC43C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x800FC440: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC444: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FC448: jr          $ra
    // 0x800FC44C: sw          $t7, 0x139C($at)
    MEM_W(0X139C, ctx->r1) = ctx->r15;
    return;
    // 0x800FC44C: sw          $t7, 0x139C($at)
    MEM_W(0X139C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void ftYoshiSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E598: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015E59C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E5A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015E5A4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015E5A8: jal         0x800DEE98
    // 0x8015E5AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015E5AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015E5B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015E5B4: addiu       $t7, $zero, 0x25
    ctx->r15 = ADD32(0, 0X25);
    // 0x8015E5B8: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015E5BC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E5C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015E5C4: jal         0x800E6F24
    // 0x8015E5C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E5C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015E5CC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E5D0: addiu       $a1, $a1, -0x17C4
    ctx->r5 = ADD32(ctx->r5, -0X17C4);
    // 0x8015E5D4: jal         0x8015E310
    // 0x8015E5D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftYoshiSpecialNSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x8015E5D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015E5DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E5E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015E5E4: jr          $ra
    // 0x8015E5E8: nop

    return;
    // 0x8015E5E8: nop

;}
RECOMP_FUNC void mnVSModeMakeRuleValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132238: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013223C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132240: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132244: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132248: addiu       $t7, $t7, 0x4860
    ctx->r15 = ADD32(ctx->r15, 0X4860);
    // 0x8013224C: lwr         $t9, 0x2($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X2);
    // 0x80132250: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80132254: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013225C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132260: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132264: jal         0x80009968
    // 0x80132268: swr         $t9, 0x2($t6)
    do_swr(rdram, 0X2, ctx->r14, ctx->r25);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132268: swr         $t9, 0x2($t6)
    do_swr(rdram, 0X2, ctx->r14, ctx->r25);
    after_0:
    // 0x8013226C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132270: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132274: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132278: sw          $v0, 0x4958($at)
    MEM_W(0X4958, ctx->r1) = ctx->r2;
    // 0x8013227C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132280: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132284: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013228C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132290: jal         0x80009DF4
    // 0x80132294: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132294: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132298: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013229C: lw          $v0, 0x494C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X494C);
    // 0x801322A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322A4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801322A8: beq         $v0, $zero, L_8013233C
    if (ctx->r2 == 0) {
        // 0x801322AC: lui         $t1, 0x0
        ctx->r9 = S32(0X0 << 16);
            goto L_8013233C;
    }
    // 0x801322AC: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801322B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801322B4: beq         $v0, $at, L_801322DC
    if (ctx->r2 == ctx->r1) {
        // 0x801322B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801322DC;
    }
    // 0x801322B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801322C0: beq         $v0, $at, L_80132454
    if (ctx->r2 == ctx->r1) {
        // 0x801322C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80132454;
    }
    // 0x801322C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801322CC: beq         $v0, $at, L_80132394
    if (ctx->r2 == ctx->r1) {
        // 0x801322D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80132394;
    }
    // 0x801322D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322D4: b           L_80132514
    // 0x801322D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80132514;
    // 0x801322D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801322DC:
    // 0x801322DC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801322E0: lw          $t1, 0x4A4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4A4C);
    // 0x801322E4: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x801322E8: addiu       $t2, $t2, 0x2A80
    ctx->r10 = ADD32(ctx->r10, 0X2A80);
    // 0x801322EC: jal         0x800CCFDC
    // 0x801322F0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801322F0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x801322F4: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x801322F8: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x801322FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132300: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x80132304: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132308: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x8013230C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132310: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80132314: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80132318: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013231C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132320: lbu         $t7, 0x2C($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2C);
    // 0x80132324: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80132328: lbu         $t8, 0x2D($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2D);
    // 0x8013232C: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x80132330: lbu         $t9, 0x2E($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2E);
    // 0x80132334: b           L_80132510
    // 0x80132338: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
        goto L_80132510;
    // 0x80132338: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
L_8013233C:
    // 0x8013233C: lw          $t0, 0x4A4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4A4C);
    // 0x80132340: addiu       $t1, $t1, 0x28E0
    ctx->r9 = ADD32(ctx->r9, 0X28E0);
    // 0x80132344: jal         0x800CCFDC
    // 0x80132348: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132348: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_3:
    // 0x8013234C: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80132350: lui         $at, 0x433B
    ctx->r1 = S32(0X433B << 16);
    // 0x80132354: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132358: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x8013235C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132360: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80132364: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132368: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8013236C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132370: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132374: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132378: lbu         $t6, 0x2C($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2C);
    // 0x8013237C: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80132380: lbu         $t7, 0x2D($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2D);
    // 0x80132384: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80132388: lbu         $t8, 0x2E($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2E);
    // 0x8013238C: b           L_80132510
    // 0x80132390: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
        goto L_80132510;
    // 0x80132390: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
L_80132394:
    // 0x80132394: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132398: lw          $t9, 0x4A4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4A4C);
    // 0x8013239C: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801323A0: addiu       $t0, $t0, 0x2A80
    ctx->r8 = ADD32(ctx->r8, 0X2A80);
    // 0x801323A4: jal         0x800CCFDC
    // 0x801323A8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801323A8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x801323AC: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801323B0: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x801323B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801323B8: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x801323BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801323C0: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x801323C4: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801323C8: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801323CC: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801323D0: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801323D4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801323D8: lbu         $t5, 0x2C($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2C);
    // 0x801323DC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801323E0: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801323E4: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x801323E8: lbu         $t6, 0x2D($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2D);
    // 0x801323EC: addiu       $t9, $t9, 0x2C20
    ctx->r25 = ADD32(ctx->r25, 0X2C20);
    // 0x801323F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801323F4: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x801323F8: lbu         $t7, 0x2E($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2E);
    // 0x801323FC: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x80132400: lw          $t8, 0x4A4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4A4C);
    // 0x80132404: jal         0x800CCFDC
    // 0x80132408: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132408: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_5:
    // 0x8013240C: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132410: lui         $at, 0x4354
    ctx->r1 = S32(0X4354 << 16);
    // 0x80132414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132418: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x8013241C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132420: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132424: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132428: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8013242C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132430: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132434: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132438: lbu         $t4, 0x2C($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2C);
    // 0x8013243C: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80132440: lbu         $t5, 0x2D($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2D);
    // 0x80132444: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80132448: lbu         $t6, 0x2E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2E);
    // 0x8013244C: b           L_80132510
    // 0x80132450: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
        goto L_80132510;
    // 0x80132450: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
L_80132454:
    // 0x80132454: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132458: lw          $t7, 0x4A4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4A4C);
    // 0x8013245C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132460: addiu       $t8, $t8, 0x28E0
    ctx->r24 = ADD32(ctx->r24, 0X28E0);
    // 0x80132464: jal         0x800CCFDC
    // 0x80132468: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132468: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_6:
    // 0x8013246C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132470: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x80132474: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132478: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x8013247C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132480: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132484: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132488: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013248C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132490: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132494: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132498: lbu         $t3, 0x2C($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2C);
    // 0x8013249C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801324A0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801324A4: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x801324A8: lbu         $t4, 0x2D($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2D);
    // 0x801324AC: addiu       $t7, $t7, 0x2C20
    ctx->r15 = ADD32(ctx->r15, 0X2C20);
    // 0x801324B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801324B4: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x801324B8: lbu         $t5, 0x2E($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2E);
    // 0x801324BC: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x801324C0: lw          $t6, 0x4A4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4A4C);
    // 0x801324C4: jal         0x800CCFDC
    // 0x801324C8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x801324C8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_7:
    // 0x801324CC: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801324D0: lui         $at, 0x4354
    ctx->r1 = S32(0X4354 << 16);
    // 0x801324D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801324D8: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x801324DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801324E0: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x801324E4: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801324E8: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801324EC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801324F0: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801324F4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801324F8: lbu         $t2, 0x2C($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2C);
    // 0x801324FC: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80132500: lbu         $t3, 0x2D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2D);
    // 0x80132504: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80132508: lbu         $t4, 0x2E($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2E);
    // 0x8013250C: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
L_80132510:
    // 0x80132510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132514:
    // 0x80132514: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132518: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013251C: jr          $ra
    // 0x80132520: nop

    return;
    // 0x80132520: nop

;}
RECOMP_FUNC void wpPikachuThunderHeadProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016A704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016A708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016A70C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8016A710: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016A714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016A718: lw          $t6, 0x29C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X29C);
    // 0x8016A71C: bne         $t6, $at, L_8016A734
    if (ctx->r14 != ctx->r1) {
        // 0x8016A720: nop
    
            goto L_8016A734;
    }
    // 0x8016A720: nop

    // 0x8016A724: jal         0x8016A680
    // 0x8016A728: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    wpPikachuThunderHeadMakeTrailEffect(rdram, ctx);
        goto after_0;
    // 0x8016A728: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8016A72C: b           L_8016A780
    // 0x8016A730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A780;
    // 0x8016A730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A734:
    // 0x8016A734: jal         0x80167FE8
    // 0x8016A738: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_1;
    // 0x8016A738: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8016A73C: beq         $v0, $zero, L_8016A774
    if (ctx->r2 == 0) {
        // 0x8016A740: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016A774;
    }
    // 0x8016A740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016A744: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016A748: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016A74C: jal         0x800FF648
    // 0x8016A750: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8016A750: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x8016A754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016A758: jal         0x8016A640
    // 0x8016A75C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpPikachuThunderHeadSetDestroy(rdram, ctx);
        goto after_3;
    // 0x8016A75C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8016A760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016A764: jal         0x8016A680
    // 0x8016A768: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    wpPikachuThunderHeadMakeTrailEffect(rdram, ctx);
        goto after_4;
    // 0x8016A768: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x8016A76C: b           L_8016A780
    // 0x8016A770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A780;
    // 0x8016A770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A774:
    // 0x8016A774: jal         0x8016A680
    // 0x8016A778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    wpPikachuThunderHeadMakeTrailEffect(rdram, ctx);
        goto after_5;
    // 0x8016A778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8016A77C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A780:
    // 0x8016A780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016A784: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016A788: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016A78C: jr          $ra
    // 0x8016A790: nop

    return;
    // 0x8016A790: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeStatDisplayText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DF30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DF34: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8018DF38: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018DF3C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DF40: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8018DF44: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8018DF48: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8018DF4C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8018DF50: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8018DF54: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8018DF58: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018DF5C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018DF60: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018DF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DF68: jal         0x80009968
    // 0x8018DF6C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018DF6C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
    // 0x8018DF70: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018DF74: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018DF78: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8018DF7C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DF80: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018DF84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DF88: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018DF8C: jal         0x80009DF4
    // 0x8018DF90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018DF90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018DF94: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018DF98: addiu       $s2, $s2, 0xB58
    ctx->r18 = ADD32(ctx->r18, 0XB58);
    // 0x8018DF9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018DFA0: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
    // 0x8018DFA4: addiu       $s6, $zero, 0x201
    ctx->r22 = ADD32(0, 0X201);
    // 0x8018DFA8: addiu       $s5, $zero, 0xDD
    ctx->r21 = ADD32(0, 0XDD);
    // 0x8018DFAC: addiu       $s4, $zero, 0xAE
    ctx->r20 = ADD32(0, 0XAE);
    // 0x8018DFB0: addiu       $s3, $zero, 0xAF
    ctx->r19 = ADD32(0, 0XAF);
L_8018DFB4:
    // 0x8018DFB4: lw          $t7, 0x24($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X24);
    // 0x8018DFB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018DFBC: jal         0x8018DEDC
    // 0x8018DFC0: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    sc1PTrainingModeMakeStatDisplay(rdram, ctx);
        goto after_2;
    // 0x8018DFC0: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    after_2:
    // 0x8018DFC4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8018DFC8: sb          $s3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r19;
    // 0x8018DFCC: sb          $s4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r20;
    // 0x8018DFD0: sb          $s5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r21;
    // 0x8018DFD4: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x8018DFD8: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x8018DFDC: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x8018DFE0: bne         $s0, $s7, L_8018DFB4
    if (ctx->r16 != ctx->r23) {
        // 0x8018DFE4: sh          $s6, 0x24($v0)
        MEM_H(0X24, ctx->r2) = ctx->r22;
            goto L_8018DFB4;
    }
    // 0x8018DFE4: sh          $s6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r22;
    // 0x8018DFE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DFEC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DFF0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8018DFF4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8018DFF8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8018DFFC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E000: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8018E004: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8018E008: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8018E00C: jr          $ra
    // 0x8018E010: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8018E010: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftNessSpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153E4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80153E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153E54: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80153E58: lw          $v1, 0xB20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB20);
    // 0x80153E5C: beq         $v1, $zero, L_80153E68
    if (ctx->r3 == 0) {
        // 0x80153E60: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80153E68;
    }
    // 0x80153E60: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80153E64: sw          $t6, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r14;
L_80153E68:
    // 0x80153E68: jal         0x800D8BB4
    // 0x80153E6C: nop

    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_0;
    // 0x80153E6C: nop

    after_0:
    // 0x80153E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80153E78: jr          $ra
    // 0x80153E7C: nop

    return;
    // 0x80153E7C: nop

;}
RECOMP_FUNC void ftBossGootsubusuEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159DD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80159DD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159DDC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80159DE0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159DE4: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x80159DE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159DEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80159DF0: jal         0x800E6F24
    // 0x80159DF4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159DF4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80159DF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80159DFC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80159E00: swc1        $f4, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->f4.u32l;
    // 0x80159E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159E08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80159E0C: jr          $ra
    // 0x80159E10: nop

    return;
    // 0x80159E10: nop

;}
RECOMP_FUNC void ftBossOkutsubushiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AB08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015AB0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015AB10: jal         0x800D938C
    // 0x8015AB14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsSetAirVelTransN(rdram, ctx);
        goto after_0;
    // 0x8015AB14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015AB18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8015AB1C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8015AB20: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8015AB24: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015AB28: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8015AB2C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8015AB30: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015AB34: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8015AB38: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8015AB3C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8015AB40: addiu       $t3, $t3, -0x6C74
    ctx->r11 = ADD32(ctx->r11, -0X6C74);
    // 0x8015AB44: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8015AB48: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8015AB4C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8015AB50: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8015AB54: nop

    // 0x8015AB58: bc1fl       L_8015AB6C
    if (!c1cs) {
        // 0x8015AB5C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8015AB6C;
    }
    goto skip_0;
    // 0x8015AB5C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8015AB60: b           L_8015AB6C
    // 0x8015AB64: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8015AB6C;
    // 0x8015AB64: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8015AB68: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8015AB6C:
    // 0x8015AB6C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8015AB70: nop

    // 0x8015AB74: bc1fl       L_8015ABB0
    if (!c1cs) {
        // 0x8015AB78: lwc1        $f16, 0x48($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
            goto L_8015ABB0;
    }
    goto skip_1;
    // 0x8015AB78: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    skip_1:
    // 0x8015AB7C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8015AB80: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8015AB84: bc1fl       L_8015AB98
    if (!c1cs) {
        // 0x8015AB88: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8015AB98;
    }
    goto skip_2;
    // 0x8015AB88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x8015AB8C: b           L_8015AB9C
    // 0x8015AB90: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8015AB9C;
    // 0x8015AB90: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8015AB94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8015AB98:
    // 0x8015AB98: nop

L_8015AB9C:
    // 0x8015AB9C: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8015ABA0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8015ABA4: b           L_8015ABB8
    // 0x8015ABA8: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
        goto L_8015ABB8;
    // 0x8015ABA8: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x8015ABAC: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
L_8015ABB0:
    // 0x8015ABB0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8015ABB4: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
L_8015ABB8:
    // 0x8015ABB8: lhu         $t0, 0xB24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XB24);
    // 0x8015ABBC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8015ABC0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8015ABC4: bne         $t2, $zero, L_8015ABD4
    if (ctx->r10 != 0) {
        // 0x8015ABC8: sh          $t1, 0xB24($v0)
        MEM_H(0XB24, ctx->r2) = ctx->r9;
            goto L_8015ABD4;
    }
    // 0x8015ABC8: sh          $t1, 0xB24($v0)
    MEM_H(0XB24, ctx->r2) = ctx->r9;
    // 0x8015ABCC: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
    // 0x8015ABD0: sw          $t3, 0x9E0($v0)
    MEM_W(0X9E0, ctx->r2) = ctx->r11;
L_8015ABD4:
    // 0x8015ABD4: jal         0x80158528
    // 0x8015ABD8: nop

    ftBossCommonUpdateFogColor(rdram, ctx);
        goto after_1;
    // 0x8015ABD8: nop

    after_1:
    // 0x8015ABDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015ABE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015ABE4: jr          $ra
    // 0x8015ABE8: nop

    return;
    // 0x8015ABE8: nop

;}
RECOMP_FUNC void wpProcessUpdateAttackStatWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80166854: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80166858: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016685C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80166860: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80166864: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80166868: jal         0x80168128
    // 0x8016686C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x8016686C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80166870: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80166874: jal         0x80168128
    // 0x80166878: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    wpMainGetStaledDamage(rdram, ctx);
        goto after_1;
    // 0x80166878: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x8016687C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80166880: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80166884: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80166888: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8016688C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80166890: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80166894: jal         0x800F0C94
    // 0x80166898: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gmCollisionGetWeaponAttacksPosition(rdram, ctx);
        goto after_2;
    // 0x80166898: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x8016689C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x801668A0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x801668A4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x801668A8: lw          $a0, 0x40($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X40);
    // 0x801668AC: lw          $v1, 0x40($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X40);
    // 0x801668B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801668B4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801668B8: bnel        $at, $zero, L_80166904
    if (ctx->r1 != 0) {
        // 0x801668BC: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80166904;
    }
    goto skip_0;
    // 0x801668BC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x801668C0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x801668C4: jal         0x8016679C
    // 0x801668C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_3;
    // 0x801668C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x801668CC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x801668D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x801668D4: lw          $t9, 0x23C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X23C);
    // 0x801668D8: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801668DC: beq         $at, $zero, L_801668E8
    if (ctx->r1 == 0) {
        // 0x801668E0: nop
    
            goto L_801668E8;
    }
    // 0x801668E0: nop

    // 0x801668E4: sw          $a1, 0x23C($t8)
    MEM_W(0X23C, ctx->r24) = ctx->r5;
L_801668E8:
    // 0x801668E8: jal         0x80100BF0
    // 0x801668EC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_4;
    // 0x801668EC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x801668F0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801668F4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x801668F8: lw          $v1, 0x40($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X40);
    // 0x801668FC: lw          $a0, 0x40($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X40);
    // 0x80166900: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_80166904:
    // 0x80166904: bne         $at, $zero, L_80166944
    if (ctx->r1 != 0) {
        // 0x80166908: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80166944;
    }
    // 0x80166908: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8016690C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80166910: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80166914: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80166918: jal         0x8016679C
    // 0x8016691C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_5;
    // 0x8016691C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80166920: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80166924: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80166928: lw          $t3, 0x23C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X23C);
    // 0x8016692C: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80166930: beq         $at, $zero, L_8016693C
    if (ctx->r1 == 0) {
        // 0x80166934: nop
    
            goto L_8016693C;
    }
    // 0x80166934: nop

    // 0x80166938: sw          $a1, 0x23C($t2)
    MEM_W(0X23C, ctx->r10) = ctx->r5;
L_8016693C:
    // 0x8016693C: jal         0x80100BF0
    // 0x80166940: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_6;
    // 0x80166940: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_6:
L_80166944:
    // 0x80166944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80166948: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8016694C: jr          $ra
    // 0x80166950: nop

    return;
    // 0x80166950: nop

;}
RECOMP_FUNC void mnMapsFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B88: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B8C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B90: addiu       $t8, $t8, 0x45A8
    ctx->r24 = ADD32(ctx->r24, 0X45A8);
    // 0x80131B94: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B9C: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131BA0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131BA4: jr          $ra
    // 0x80131BA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131BA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftPhysicsApplyAirVelFriction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D91EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D91F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D91F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D91F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D91FC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800D9200: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x800D9204: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x800D9208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D920C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800D9210: bgez        $t8, L_800D9228
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D9214: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800D9228;
    }
    // 0x800D9214: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D9218: jal         0x800D8DA0
    // 0x800D921C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsApplyFastFall(rdram, ctx);
        goto after_0;
    // 0x800D921C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D9220: b           L_800D9234
    // 0x800D9224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800D9234;
    // 0x800D9224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D9228:
    // 0x800D9228: jal         0x800D8E50
    // 0x800D922C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_1;
    // 0x800D922C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800D9230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D9234:
    // 0x800D9234: jal         0x800D8FA8
    // 0x800D9238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_2;
    // 0x800D9238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800D923C: bne         $v0, $zero, L_800D924C
    if (ctx->r2 != 0) {
        // 0x800D9240: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D924C;
    }
    // 0x800D9240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D9244: jal         0x800D9074
    // 0x800D9248: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_3;
    // 0x800D9248: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_800D924C:
    // 0x800D924C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9250: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D9254: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D9258: jr          $ra
    // 0x800D925C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D925C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mvOpeningStandoffMakeMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013242C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132430: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80132434: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80132438: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8013243C: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80132440: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x80132444: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80132448: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013244C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132450: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132454: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132458: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013245C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80132460: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80132464: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80132468: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8013246C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132470: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132474: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132478: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013247C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132480: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132484: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132488: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013248C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132490: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132494: jal         0x8000B93C
    // 0x80132498: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132498: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013249C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801324A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801324A4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801324A8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801324AC: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x801324B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801324B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801324B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801324BC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801324C0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801324C4: jal         0x80007080
    // 0x801324C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801324C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801324CC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x801324D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801324D4: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x801324D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801324DC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801324E0: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x801324E4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x801324E8: lw          $t4, 0x2B98($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2B98);
    // 0x801324EC: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x801324F0: addiu       $t5, $t5, 0x7250
    ctx->r13 = ADD32(ctx->r13, 0X7250);
    // 0x801324F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801324F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801324FC: jal         0x8000FA3C
    // 0x80132500: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80132500: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x80132504: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132508: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8013250C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80132510: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132514: jal         0x80008188
    // 0x80132518: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80132518: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8013251C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80132520: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80132524: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132528: jr          $ra
    // 0x8013252C: nop

    return;
    // 0x8013252C: nop

;}
RECOMP_FUNC void mnPlayers1PGameInitSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801382C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801382CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801382D0: jal         0x80137448
    // 0x801382D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnPlayers1PGameMakeCursor(rdram, ctx);
        goto after_0;
    // 0x801382D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801382D8: jal         0x80137590
    // 0x801382DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameMakePuck(rdram, ctx);
        goto after_1;
    // 0x801382DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801382E0: jal         0x801331F4
    // 0x801382E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameMakeGate(rdram, ctx);
        goto after_2;
    // 0x801382E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801382E8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801382EC: addiu       $v0, $v0, -0x7118
    ctx->r2 = ADD32(ctx->r2, -0X7118);
    // 0x801382F0: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x801382F4: beql        $t6, $zero, L_80138328
    if (ctx->r14 == 0) {
        // 0x801382F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138328;
    }
    goto skip_0;
    // 0x801382F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801382FC: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x80138300: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80138304: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80138308: beql        $a2, $at, L_80138328
    if (ctx->r6 == ctx->r1) {
        // 0x8013830C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138328;
    }
    goto skip_1;
    // 0x8013830C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80138310: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80138314: jal         0x80135060
    // 0x80138318: lw          $a3, 0x24($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X24);
    mnPlayers1PGameMakeFighter(rdram, ctx);
        goto after_3;
    // 0x80138318: lw          $a3, 0x24($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X24);
    after_3:
    // 0x8013831C: jal         0x80134B3C
    // 0x80138320: nop

    mnPlayers1PGameMakeFighterRecord(rdram, ctx);
        goto after_4;
    // 0x80138320: nop

    after_4:
    // 0x80138324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138328:
    // 0x80138328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013832C: jr          $ra
    // 0x80138330: nop

    return;
    // 0x80138330: nop

;}
RECOMP_FUNC void mnVSRecordMakeRankingTableValues(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134AA8: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80134AAC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134AB0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80134AB4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80134AB8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80134ABC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80134AC0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80134AC4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80134AC8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80134ACC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80134AD0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80134AD4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80134AD8: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x80134ADC: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x80134AE0: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80134AE4: addiu       $t6, $t6, 0x6908
    ctx->r14 = ADD32(ctx->r14, 0X6908);
    // 0x80134AE8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134AEC: addiu       $s5, $sp, 0xDC
    ctx->r21 = ADD32(ctx->r29, 0XDC);
    // 0x80134AF0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134AF4: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80134AF8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80134AFC: addiu       $t9, $t9, 0x6924
    ctx->r25 = ADD32(ctx->r25, 0X6924);
    // 0x80134B00: addiu       $s6, $sp, 0xC0
    ctx->r22 = ADD32(ctx->r29, 0XC0);
    // 0x80134B04: sw          $t7, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r15;
    // 0x80134B08: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80134B0C: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80134B10: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80134B14: sw          $t8, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r24;
    // 0x80134B18: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80134B1C: addiu       $v1, $sp, 0xB8
    ctx->r3 = ADD32(ctx->r29, 0XB8);
    // 0x80134B20: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80134B24: sw          $t7, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r15;
    // 0x80134B28: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80134B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134B30: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80134B34: sw          $t8, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r24;
    // 0x80134B38: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80134B3C: sw          $t7, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r15;
    // 0x80134B40: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x80134B44: sw          $t8, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r24;
    // 0x80134B48: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80134B4C: sw          $t1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r9;
    // 0x80134B50: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80134B54: sw          $t0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r8;
    // 0x80134B58: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80134B5C: sw          $t1, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r9;
    // 0x80134B60: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80134B64: sw          $t0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r8;
    // 0x80134B68: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80134B6C: sw          $t1, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->r9;
    // 0x80134B70: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80134B74: sw          $t0, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r8;
L_80134B78:
    // 0x80134B78: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x80134B7C: bnel        $at, $zero, L_80134B8C
    if (ctx->r1 != 0) {
        // 0x80134B80: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80134B8C;
    }
    goto skip_0;
    // 0x80134B80: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x80134B84: addiu       $a0, $a0, -0x7
    ctx->r4 = ADD32(ctx->r4, -0X7);
    // 0x80134B88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80134B8C:
    // 0x80134B8C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80134B90: sw          $a0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r4;
    // 0x80134B94: bne         $at, $zero, L_80134B78
    if (ctx->r1 != 0) {
        // 0x80134B98: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80134B78;
    }
    // 0x80134B98: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80134B9C: jal         0x80009968
    // 0x80134BA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134BA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80134BA4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134BA8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80134BAC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80134BB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80134BB4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134BB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134BBC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80134BC0: jal         0x80009DF4
    // 0x80134BC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80134BC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80134BC8: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80134BCC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80134BD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80134BD4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80134BD8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80134BDC: addiu       $s3, $s3, 0x6C58
    ctx->r19 = ADD32(ctx->r19, 0X6C58);
    // 0x80134BE0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80134BE4:
    // 0x80134BE4: jal         0x801326EC
    // 0x80134BE8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_2;
    // 0x80134BE8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x80134BEC: beq         $v0, $zero, L_801350B8
    if (ctx->r2 == 0) {
        // 0x80134BF0: addiu       $s2, $zero, 0x30
        ctx->r18 = ADD32(0, 0X30);
            goto L_801350B8;
    }
    // 0x80134BF0: addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
    // 0x80134BF4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80134BF8: addiu       $s0, $sp, 0x9C
    ctx->r16 = ADD32(ctx->r29, 0X9C);
L_80134BFC:
    // 0x80134BFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80134C00: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80134C04: beq         $at, $zero, L_80135094
    if (ctx->r1 == 0) {
        // 0x80134C08: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_80135094;
    }
    // 0x80134C08: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80134C0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134C10: addu        $at, $at, $t3
    gpr jr_addend_80134C18 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80134C14: lw          $t3, 0x6BEC($at)
    ctx->r11 = ADD32(ctx->r1, 0X6BEC);
    // 0x80134C18: jr          $t3
    // 0x80134C1C: nop

    switch (jr_addend_80134C18 >> 2) {
        case 0: goto L_80134C20; break;
        case 1: goto L_80134CA4; break;
        case 2: goto L_80134D1C; break;
        case 3: goto L_80134D94; break;
        case 4: goto L_80134E18; break;
        case 5: goto L_80134F8C; break;
        case 6: goto L_80135010; break;
        default: switch_error(__func__, 0x80134C18, 0x80136BEC);
    }
    // 0x80134C1C: nop

L_80134C20:
    // 0x80134C20: sll         $t4, $s7, 2
    ctx->r12 = S32(ctx->r23 << 2);
    // 0x80134C24: subu        $t4, $t4, $s7
    ctx->r12 = SUB32(ctx->r12, ctx->r23);
    // 0x80134C28: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80134C2C: addu        $t4, $t4, $s7
    ctx->r12 = ADD32(ctx->r12, ctx->r23);
    // 0x80134C30: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80134C34: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80134C38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134C3C: jal         0x80131D38
    // 0x80134C40: add.s       $f20, $f6, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f24.fl;
    mnVSRecordGetWinPercent(rdram, ctx);
        goto after_3;
    // 0x80134C40: add.s       $f20, $f6, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f24.fl;
    after_3:
    // 0x80134C44: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80134C48: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80134C4C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80134C50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80134C54: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x80134C58: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80134C5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134C60: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80134C64: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x80134C68: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80134C6C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80134C70: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80134C74: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80134C78: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80134C7C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80134C80: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80134C84: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80134C88: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80134C8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134C90: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80134C94: jal         0x80131F34
    // 0x80134C98: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_4;
    // 0x80134C98: nop

    after_4:
    // 0x80134C9C: b           L_80135094
    // 0x80134CA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80135094;
    // 0x80134CA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80134CA4:
    // 0x80134CA4: sll         $t3, $s7, 2
    ctx->r11 = S32(ctx->r23 << 2);
    // 0x80134CA8: subu        $t3, $t3, $s7
    ctx->r11 = SUB32(ctx->r11, ctx->r23);
    // 0x80134CAC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80134CB0: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x80134CB4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80134CB8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80134CBC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80134CC0: jal         0x80131B74
    // 0x80134CC4: add.s       $f20, $f4, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f24.fl;
    mnVSRecordGetKOs(rdram, ctx);
        goto after_5;
    // 0x80134CC4: add.s       $f20, $f4, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f24.fl;
    after_5:
    // 0x80134CC8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80134CCC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80134CD0: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80134CD4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80134CD8: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x80134CDC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80134CE0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80134CE4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80134CE8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80134CEC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80134CF0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80134CF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80134CF8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80134CFC: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80134D00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134D04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134D08: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80134D0C: jal         0x80131F34
    // 0x80134D10: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_6;
    // 0x80134D10: nop

    after_6:
    // 0x80134D14: b           L_80135094
    // 0x80134D18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80135094;
    // 0x80134D18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80134D1C:
    // 0x80134D1C: sll         $t0, $s7, 2
    ctx->r8 = S32(ctx->r23 << 2);
    // 0x80134D20: subu        $t0, $t0, $s7
    ctx->r8 = SUB32(ctx->r8, ctx->r23);
    // 0x80134D24: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80134D28: addu        $t0, $t0, $s7
    ctx->r8 = ADD32(ctx->r8, ctx->r23);
    // 0x80134D2C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80134D30: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80134D34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134D38: jal         0x80131C0C
    // 0x80134D3C: add.s       $f20, $f10, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f24.fl;
    mnVSRecordGetTKO(rdram, ctx);
        goto after_7;
    // 0x80134D3C: add.s       $f20, $f10, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f24.fl;
    after_7:
    // 0x80134D40: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80134D44: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80134D48: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80134D4C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80134D50: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x80134D54: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80134D58: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80134D5C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80134D60: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80134D64: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80134D68: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80134D6C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80134D70: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80134D74: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80134D78: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134D7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134D80: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80134D84: jal         0x80131F34
    // 0x80134D88: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_8;
    // 0x80134D88: nop

    after_8:
    // 0x80134D8C: b           L_80135094
    // 0x80134D90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80135094;
    // 0x80134D90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80134D94:
    // 0x80134D94: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x80134D98: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x80134D9C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80134DA0: addu        $t7, $t7, $s7
    ctx->r15 = ADD32(ctx->r15, ctx->r23);
    // 0x80134DA4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80134DA8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80134DAC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80134DB0: jal         0x80134A1C
    // 0x80134DB4: add.s       $f20, $f4, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f24.fl;
    mnVSRecordGetSDPercent(rdram, ctx);
        goto after_9;
    // 0x80134DB4: add.s       $f20, $f4, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f24.fl;
    after_9:
    // 0x80134DB8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80134DBC: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80134DC0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80134DC4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80134DC8: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x80134DCC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80134DD0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80134DD4: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80134DD8: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80134DDC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80134DE0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80134DE4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80134DE8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80134DEC: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80134DF0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80134DF4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80134DF8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80134DFC: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80134E00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134E04: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80134E08: jal         0x80131F34
    // 0x80134E0C: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_10;
    // 0x80134E0C: nop

    after_10:
    // 0x80134E10: b           L_80135094
    // 0x80134E14: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80135094;
    // 0x80134E14: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80134E18:
    // 0x80134E18: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80134E1C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80134E20: addiu       $at, $zero, 0xE10
    ctx->r1 = ADD32(0, 0XE10);
    // 0x80134E24: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80134E28: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80134E2C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80134E30: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80134E34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80134E38: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80134E3C: lw          $a1, 0x44F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X44F8);
    // 0x80134E40: sll         $t2, $s7, 2
    ctx->r10 = S32(ctx->r23 << 2);
    // 0x80134E44: subu        $t2, $t2, $s7
    ctx->r10 = SUB32(ctx->r10, ctx->r23);
    // 0x80134E48: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x80134E4C: mfhi        $a1
    ctx->r5 = hi;
    // 0x80134E50: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80134E54: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80134E58: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x80134E5C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80134E60: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x80134E64: addu        $t2, $t2, $s7
    ctx->r10 = ADD32(ctx->r10, ctx->r23);
    // 0x80134E68: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80134E6C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80134E70: mflo        $a1
    ctx->r5 = lo;
    // 0x80134E74: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80134E78: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x80134E7C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80134E80: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80134E84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80134E88: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80134E8C: lui         $s1, 0x0
    ctx->r17 = S32(0X0 << 16);
    // 0x80134E90: addiu       $s1, $s1, 0x54C0
    ctx->r17 = ADD32(ctx->r17, 0X54C0);
    // 0x80134E94: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80134E98: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80134E9C: add.s       $f20, $f4, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80134EA0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80134EA4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80134EA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80134EAC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80134EB0: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80134EB4: jal         0x80131F34
    // 0x80134EB8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_11;
    // 0x80134EB8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_11:
    // 0x80134EBC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80134EC0: lw          $t5, 0x6D88($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D88);
    // 0x80134EC4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134EC8: jal         0x800CCFDC
    // 0x80134ECC: addu        $a1, $t5, $s1
    ctx->r5 = ADD32(ctx->r13, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_12;
    // 0x80134ECC: addu        $a1, $t5, $s1
    ctx->r5 = ADD32(ctx->r13, ctx->r17);
    after_12:
    // 0x80134ED0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80134ED4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134ED8: jal         0x80131E40
    // 0x80134EDC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mnVSRecordSetSpriteColors(rdram, ctx);
        goto after_13;
    // 0x80134EDC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_13:
    // 0x80134EE0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80134EE4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80134EE8: addiu       $at, $zero, 0xE10
    ctx->r1 = ADD32(0, 0XE10);
    // 0x80134EEC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80134EF0: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x80134EF4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80134EF8: swc1        $f20, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
    // 0x80134EFC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80134F00: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x80134F04: addiu       $t1, $t0, -0xB
    ctx->r9 = ADD32(ctx->r8, -0XB);
    // 0x80134F08: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80134F0C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80134F10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134F14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80134F18: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
    // 0x80134F1C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80134F20: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80134F24: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80134F28: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80134F2C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80134F30: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80134F34: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80134F38: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x80134F3C: lw          $a1, 0x44F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X44F8);
    // 0x80134F40: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80134F44: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x80134F48: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x80134F4C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80134F50: mflo        $a1
    ctx->r5 = lo;
    // 0x80134F54: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80134F58: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80134F5C: addiu       $t9, $t8, -0xD
    ctx->r25 = ADD32(ctx->r24, -0XD);
    // 0x80134F60: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80134F64: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80134F68: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80134F6C: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80134F70: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80134F74: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80134F78: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80134F7C: jal         0x80131F34
    // 0x80134F80: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_14;
    // 0x80134F80: nop

    after_14:
    // 0x80134F84: b           L_80135094
    // 0x80134F88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80135094;
    // 0x80134F88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80134F8C:
    // 0x80134F8C: sll         $t1, $s7, 2
    ctx->r9 = S32(ctx->r23 << 2);
    // 0x80134F90: subu        $t1, $t1, $s7
    ctx->r9 = SUB32(ctx->r9, ctx->r23);
    // 0x80134F94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80134F98: addu        $t1, $t1, $s7
    ctx->r9 = ADD32(ctx->r9, ctx->r23);
    // 0x80134F9C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80134FA0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80134FA4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80134FA8: jal         0x80134978
    // 0x80134FAC: add.s       $f20, $f18, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f24.fl;
    mnVSRecordGetUsePercent(rdram, ctx);
        goto after_15;
    // 0x80134FAC: add.s       $f20, $f18, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f24.fl;
    after_15:
    // 0x80134FB0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80134FB4: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80134FB8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80134FBC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80134FC0: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x80134FC4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80134FC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134FCC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80134FD0: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80134FD4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80134FD8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80134FDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80134FE0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80134FE4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134FE8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80134FEC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80134FF0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80134FF4: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80134FF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134FFC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80135000: jal         0x80131F34
    // 0x80135004: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_16;
    // 0x80135004: nop

    after_16:
    // 0x80135008: b           L_80135094
    // 0x8013500C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80135094;
    // 0x8013500C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80135010:
    // 0x80135010: sll         $t0, $s7, 2
    ctx->r8 = S32(ctx->r23 << 2);
    // 0x80135014: subu        $t0, $t0, $s7
    ctx->r8 = SUB32(ctx->r8, ctx->r23);
    // 0x80135018: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013501C: addu        $t0, $t0, $s7
    ctx->r8 = ADD32(ctx->r8, ctx->r23);
    // 0x80135020: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80135024: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80135028: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013502C: jal         0x801348B4
    // 0x80135030: add.s       $f20, $f16, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f24.fl;
    mnVSRecordGetAvg(rdram, ctx);
        goto after_17;
    // 0x80135030: add.s       $f20, $f16, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f24.fl;
    after_17:
    // 0x80135034: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80135038: mul.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8013503C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80135040: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80135044: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x80135048: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8013504C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80135050: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80135054: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80135058: addiu       $t7, $t6, -0xF
    ctx->r15 = ADD32(ctx->r14, -0XF);
    // 0x8013505C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80135060: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80135064: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135068: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8013506C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80135070: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80135074: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80135078: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8013507C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80135080: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80135084: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80135088: jal         0x80131F34
    // 0x8013508C: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_18;
    // 0x8013508C: nop

    after_18:
    // 0x80135090: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80135094:
    // 0x80135094: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80135098: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013509C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801350A0: lw          $t1, 0x6630($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6630);
    // 0x801350A4: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x801350A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801350AC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801350B0: bne         $fp, $at, L_80134BFC
    if (ctx->r30 != ctx->r1) {
        // 0x801350B4: addu        $s2, $s2, $t1
        ctx->r18 = ADD32(ctx->r18, ctx->r9);
            goto L_80134BFC;
    }
    // 0x801350B4: addu        $s2, $s2, $t1
    ctx->r18 = ADD32(ctx->r18, ctx->r9);
L_801350B8:
    // 0x801350B8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x801350BC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801350C0: bne         $s7, $at, L_80134BE4
    if (ctx->r23 != ctx->r1) {
        // 0x801350C4: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80134BE4;
    }
    // 0x801350C4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x801350C8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801350CC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x801350D0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801350D4: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801350D8: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x801350DC: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x801350E0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801350E4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801350E8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801350EC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801350F0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x801350F4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x801350F8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x801350FC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80135100: jr          $ra
    // 0x80135104: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80135104: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void efGroundUpdateEffectYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80116094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80116098: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8011609C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801160A0: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x801160A4: jal         0x80115F5C
    // 0x801160A8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    efGroundCommonProcUpdate(rdram, ctx);
        goto after_0;
    // 0x801160A8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x801160AC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801160B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801160B4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x801160B8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x801160BC: bnel        $t9, $at, L_801160DC
    if (ctx->r25 != ctx->r1) {
        // 0x801160C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801160DC;
    }
    goto skip_0;
    // 0x801160C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801160C4: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x801160C8: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
    // 0x801160CC: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801160D0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801160D4: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x801160D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801160DC:
    // 0x801160DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801160E0: jr          $ra
    // 0x801160E4: nop

    return;
    // 0x801160E4: nop

;}

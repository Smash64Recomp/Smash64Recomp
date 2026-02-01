#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl8_80382F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382F70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80382F74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80382F78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382F7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382F80: beq         $a0, $zero, L_80382FF8
    if (ctx->r4 == 0) {
        // 0x80382F84: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80382FF8;
    }
    // 0x80382F84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80382F88: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80382F8C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80382F90: addiu       $t6, $t6, -0x3870
    ctx->r14 = ADD32(ctx->r14, -0X3870);
    // 0x80382F94: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80382F98: addiu       $t7, $t7, -0x3770
    ctx->r15 = ADD32(ctx->r15, -0X3770);
    // 0x80382F9C: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80382FA0: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80382FA4: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80382FA8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80382FAC: addiu       $t9, $t9, -0x3618
    ctx->r25 = ADD32(ctx->r25, -0X3618);
    // 0x80382FB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382FB4: jal         0x80373D88
    // 0x80382FB8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_80373D88(rdram, ctx);
        goto after_0;
    // 0x80382FB8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x80382FBC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80382FC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382FC4: beql        $t1, $zero, L_80382FE4
    if (ctx->r9 == 0) {
        // 0x80382FC8: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_80382FE4;
    }
    goto skip_0;
    // 0x80382FC8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80382FCC: jal         0x8037C30C
    // 0x80382FD0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x80382FD0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x80382FD4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80382FD8: jal         0x803718C4
    // 0x80382FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x80382FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80382FE0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_80382FE4:
    // 0x80382FE4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80382FE8: beql        $t3, $zero, L_80382FFC
    if (ctx->r11 == 0) {
        // 0x80382FEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80382FFC;
    }
    goto skip_1;
    // 0x80382FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80382FF0: jal         0x803717C0
    // 0x80382FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x80382FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80382FF8:
    // 0x80382FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80382FFC:
    // 0x80382FFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80383000: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80383004: jr          $ra
    // 0x80383008: nop

    return;
    // 0x80383008: nop

;}
RECOMP_FUNC void ftKirbySpecialHiProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161194: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80161198: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x8016119C: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x801611A0: jr          $ra
    // 0x801611A4: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    return;
    // 0x801611A4: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
;}
RECOMP_FUNC void wpBossBulletExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DC00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016DC04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016DC08: jal         0x80167FE8
    // 0x8016DC0C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8016DC0C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8016DC10: beq         $v0, $zero, L_8016DC20
    if (ctx->r2 == 0) {
        // 0x8016DC14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016DC20;
    }
    // 0x8016DC14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DC18: b           L_8016DC24
    // 0x8016DC1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016DC24;
    // 0x8016DC1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016DC20:
    // 0x8016DC20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016DC24:
    // 0x8016DC24: jr          $ra
    // 0x8016DC28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8016DC28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mpCollisionGetFCCommonCeil(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3E04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F3E08: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800F3E0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F3E10: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800F3E14: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800F3E18: jal         0x800F3A78
    // 0x800F3E1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetFCCommon(rdram, ctx);
        goto after_0;
    // 0x800F3E1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800F3E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F3E28: jr          $ra
    // 0x800F3E2C: nop

    return;
    // 0x800F3E2C: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltAirMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801695E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801695E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801695EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801695F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801695F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801695F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801695FC: addiu       $a1, $a1, -0x6F50
    ctx->r5 = ADD32(ctx->r5, -0X6F50);
    // 0x80169600: jal         0x801655C8
    // 0x80169604: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80169604: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80169608: bne         $v0, $zero, L_80169618
    if (ctx->r2 != 0) {
        // 0x8016960C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80169618;
    }
    // 0x8016960C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80169610: b           L_80169644
    // 0x80169614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80169644;
    // 0x80169614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80169618:
    // 0x80169618: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016961C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80169620: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80169624: sw          $t6, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r14;
    // 0x80169628: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8016962C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80169630: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x80169634: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80169638: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8016963C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80169640: sw          $t9, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r25;
L_80169644:
    // 0x80169644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80169648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016964C: jr          $ra
    // 0x80169650: nop

    return;
    // 0x80169650: nop

;}
RECOMP_FUNC void ifCommonBattlePauseSetGObjFlagsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113F9C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80113FA0: lw          $v0, 0x6728($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6728);
    // 0x80113FA4: beq         $v0, $zero, L_80113FBC
    if (ctx->r2 == 0) {
        // 0x80113FA8: nop
    
            goto L_80113FBC;
    }
    // 0x80113FA8: nop

    // 0x80113FAC: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
L_80113FB0:
    // 0x80113FB0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80113FB4: bnel        $v0, $zero, L_80113FB0
    if (ctx->r2 != 0) {
        // 0x80113FB8: sw          $a0, 0x7C($v0)
        MEM_W(0X7C, ctx->r2) = ctx->r4;
            goto L_80113FB0;
    }
    goto skip_0;
    // 0x80113FB8: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
    skip_0:
L_80113FBC:
    // 0x80113FBC: jr          $ra
    // 0x80113FC0: nop

    return;
    // 0x80113FC0: nop

;}
RECOMP_FUNC void mnVSItemSwitchFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x3270
    ctx->r24 = ADD32(ctx->r24, 0X3270);
    // 0x80131B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B14: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131B18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B1C: jr          $ra
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void lbCommonInitCameraVec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD53C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD540: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CD544: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CD548: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800CD54C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800CD550: jal         0x80008CF0
    // 0x800CD554: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcAddXObjForCamera(rdram, ctx);
        goto after_0;
    // 0x800CD554: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CD558: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CD55C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800CD560: addiu       $t6, $t6, -0x474C
    ctx->r14 = ADD32(ctx->r14, -0X474C);
    // 0x800CD564: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x800CD568: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_800CD56C:
    // 0x800CD56C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800CD570: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800CD574: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800CD578: sw          $t8, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->r24;
    // 0x800CD57C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x800CD580: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x800CD584: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x800CD588: bne         $t6, $t0, L_800CD56C
    if (ctx->r14 != ctx->r8) {
        // 0x800CD58C: sw          $t8, 0x34($t9)
        MEM_W(0X34, ctx->r25) = ctx->r24;
            goto L_800CD56C;
    }
    // 0x800CD58C: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x800CD590: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800CD594: sw          $t8, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r24;
    // 0x800CD598: sw          $v0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r2;
    // 0x800CD59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD5A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD5A4: jr          $ra
    // 0x800CD5A8: nop

    return;
    // 0x800CD5A8: nop

;}
RECOMP_FUNC void ftNessSpecialHiJibakuProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80154824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80154828: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015482C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80154830: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154834: lwc1        $f0, 0x60($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80154838: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8015483C: nop

    // 0x80154840: bc1f        L_80154854
    if (!c1cs) {
        // 0x80154844: nop
    
            goto L_80154854;
    }
    // 0x80154844: nop

    // 0x80154848: lwc1        $f6, -0x3A20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A20);
    // 0x8015484C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80154850: swc1        $f8, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f8.u32l;
L_80154854:
    // 0x80154854: jal         0x800D8B94
    // 0x80154858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsApplyGroundVelTransferAir(rdram, ctx);
        goto after_0;
    // 0x80154858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015485C: jal         0x80154758
    // 0x80154860: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftNessSpecialHiUpdateModelPitch(rdram, ctx);
        goto after_1;
    // 0x80154860: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80154864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80154868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015486C: jr          $ra
    // 0x80154870: nop

    return;
    // 0x80154870: nop

;}
RECOMP_FUNC void itEggWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018161C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181620: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80181624: jal         0x801735A0
    // 0x80181628: addiu       $a1, $a1, 0x171C
    ctx->r5 = ADD32(ctx->r5, 0X171C);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80181628: addiu       $a1, $a1, 0x171C
    ctx->r5 = ADD32(ctx->r5, 0X171C);
    after_0:
    // 0x8018162C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80181638: jr          $ra
    // 0x8018163C: nop

    return;
    // 0x8018163C: nop

;}
RECOMP_FUNC void wpNessPKThunderTrailMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B580: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016B584: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8016B588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B58C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8016B590: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x8016B594: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016B598: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016B59C: addiu       $a1, $a1, -0x6DFC
    ctx->r5 = ADD32(ctx->r5, -0X6DFC);
    // 0x8016B5A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016B5A4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8016B5A8: jal         0x801655C8
    // 0x8016B5AC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016B5AC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8016B5B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8016B5B4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016B5B8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8016B5BC: bne         $v0, $zero, L_8016B5CC
    if (ctx->r2 != 0) {
        // 0x8016B5C0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8016B5CC;
    }
    // 0x8016B5C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8016B5C4: b           L_8016B64C
    // 0x8016B5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016B64C;
    // 0x8016B5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016B5CC:
    // 0x8016B5CC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8016B5D0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8016B5D4: addiu       $t6, $t6, 0x7660
    ctx->r14 = ADD32(ctx->r14, 0X7660);
    // 0x8016B5D8: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x8016B5DC: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8016B5E0: bne         $a2, $zero, L_8016B618
    if (ctx->r6 != 0) {
        // 0x8016B5E4: sw          $t7, 0x268($v1)
        MEM_W(0X268, ctx->r3) = ctx->r15;
            goto L_8016B618;
    }
    // 0x8016B5E4: sw          $t7, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r15;
    // 0x8016B5E8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8016B5EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016B5F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8016B5F4: jal         0x801655A0
    // 0x8016B5F8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    wpManagerGetGroupID(rdram, ctx);
        goto after_1;
    // 0x8016B5F8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x8016B5FC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8016B600: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8016B604: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8016B608: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016B60C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8016B610: b           L_8016B620
    // 0x8016B614: sw          $v0, 0x264($v1)
    MEM_W(0X264, ctx->r3) = ctx->r2;
        goto L_8016B620;
    // 0x8016B614: sw          $v0, 0x264($v1)
    MEM_W(0X264, ctx->r3) = ctx->r2;
L_8016B618:
    // 0x8016B618: lw          $t8, 0x264($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X264);
    // 0x8016B61C: sw          $t8, 0x264($v1)
    MEM_W(0X264, ctx->r3) = ctx->r24;
L_8016B620:
    // 0x8016B620: sw          $zero, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = 0;
    // 0x8016B624: sw          $a2, 0x2A0($v1)
    MEM_W(0X2A0, ctx->r3) = ctx->r6;
    // 0x8016B628: beq         $a2, $zero, L_8016B638
    if (ctx->r6 == 0) {
        // 0x8016B62C: sw          $a0, 0x2A4($v1)
        MEM_W(0X2A4, ctx->r3) = ctx->r4;
            goto L_8016B638;
    }
    // 0x8016B62C: sw          $a0, 0x2A4($v1)
    MEM_W(0X2A4, ctx->r3) = ctx->r4;
    // 0x8016B630: lw          $a0, 0x2A8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X2A8);
    // 0x8016B634: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
L_8016B638:
    // 0x8016B638: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8016B63C: sw          $a0, 0x2A8($v1)
    MEM_W(0X2A8, ctx->r3) = ctx->r4;
    // 0x8016B640: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8016B644: sw          $a1, 0x2A8($t1)
    MEM_W(0X2A8, ctx->r9) = ctx->r5;
    // 0x8016B648: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8016B64C:
    // 0x8016B64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016B654: jr          $ra
    // 0x8016B658: nop

    return;
    // 0x8016B658: nop

;}
RECOMP_FUNC void ftCommonDashCheckTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EDFC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8013EE00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013EE04: lw          $a1, 0xB28($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XB28);
    // 0x8013EE08: lb          $t6, 0x1C2($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1C2);
    // 0x8013EE0C: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013EE10: mflo        $t7
    ctx->r15 = lo;
    // 0x8013EE14: slti        $at, $t7, 0x38
    ctx->r1 = SIGNED(ctx->r15) < 0X38 ? 1 : 0;
    // 0x8013EE18: bne         $at, $zero, L_8013EE40
    if (ctx->r1 != 0) {
        // 0x8013EE1C: nop
    
            goto L_8013EE40;
    }
    // 0x8013EE1C: nop

    // 0x8013EE20: lbu         $t8, 0x268($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X268);
    // 0x8013EE24: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8013EE28: beq         $at, $zero, L_8013EE40
    if (ctx->r1 == 0) {
        // 0x8013EE2C: nop
    
            goto L_8013EE40;
    }
    // 0x8013EE2C: nop

    // 0x8013EE30: sw          $a1, 0xB24($v1)
    MEM_W(0XB24, ctx->r3) = ctx->r5;
    // 0x8013EE34: sw          $zero, 0xB2C($v1)
    MEM_W(0XB2C, ctx->r3) = 0;
    // 0x8013EE38: jr          $ra
    // 0x8013EE3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013EE3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013EE40:
    // 0x8013EE40: jr          $ra
    // 0x8013EE44: nop

    return;
    // 0x8013EE44: nop

;}
RECOMP_FUNC void ftDonkeySpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B6D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B6D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B6D8: jal         0x800D94C4
    // 0x8015B6DC: nop

    ftAnimEndSetWait(rdram, ctx);
        goto after_0;
    // 0x8015B6DC: nop

    after_0:
    // 0x8015B6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B6E8: jr          $ra
    // 0x8015B6EC: nop

    return;
    // 0x8015B6EC: nop

;}
RECOMP_FUNC void ftCommonCaptureYoshiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C778: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014C77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C780: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014C784: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8014C788: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014C78C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8014C790: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8014C794: jal         0x8014A5F0
    // 0x8014C798: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    ftCommonCapturePulledRotateScale(rdram, ctx);
        goto after_0;
    // 0x8014C798: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    after_0:
    // 0x8014C79C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8014C7A0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8014C7A4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8014C7A8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8014C7AC: addiu       $at, $zero, 0xB1
    ctx->r1 = ADD32(0, 0XB1);
    // 0x8014C7B0: swc1        $f4, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f4.u32l;
    // 0x8014C7B4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8014C7B8: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8014C7BC: swc1        $f6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f6.u32l;
    // 0x8014C7C0: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x8014C7C4: bnel        $t8, $at, L_8014C830
    if (ctx->r24 != ctx->r1) {
        // 0x8014C7C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C830;
    }
    goto skip_0;
    // 0x8014C7C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014C7CC: lh          $v1, 0xB1C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XB1C);
    // 0x8014C7D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014C7D4: bnel        $v1, $at, L_8014C7F0
    if (ctx->r3 != ctx->r1) {
        // 0x8014C7D8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8014C7F0;
    }
    goto skip_1;
    // 0x8014C7D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x8014C7DC: jal         0x8014CF20
    // 0x8014C7E0: nop

    ftCommonYoshiEggSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014C7E0: nop

    after_1:
    // 0x8014C7E4: b           L_8014C830
    // 0x8014C7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014C830;
    // 0x8014C7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C7EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8014C7F0:
    // 0x8014C7F0: bne         $v1, $at, L_8014C82C
    if (ctx->r3 != ctx->r1) {
        // 0x8014C7F4: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8014C82C;
    }
    // 0x8014C7F4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8014C7F8: lbu         $t1, 0x18E($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X18E);
    // 0x8014C7FC: lbu         $t6, 0x18D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18D);
    // 0x8014C800: sh          $t9, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r25;
    // 0x8014C804: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x8014C808: sb          $t2, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r10;
    // 0x8014C80C: lhu         $t3, 0x18E($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X18E);
    // 0x8014C810: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8014C814: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8014C818: srl         $t4, $t3, 15
    ctx->r12 = S32(U32(ctx->r11) >> 15);
    // 0x8014C81C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8014C820: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8014C824: jal         0x800E8A24
    // 0x8014C828: sb          $t8, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r24;
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_2;
    // 0x8014C828: sb          $t8, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r24;
    after_2:
L_8014C82C:
    // 0x8014C82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014C830:
    // 0x8014C830: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014C834: jr          $ra
    // 0x8014C838: nop

    return;
    // 0x8014C838: nop

;}
RECOMP_FUNC void syUtilsCsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018858: jal         0x800303F0
    // 0x8001885C: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001885C: nop

    after_0:
    // 0x80018860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001886C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018870: jr          $ra
    // 0x80018874: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    return;
    // 0x80018874: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
;}
RECOMP_FUNC void itNessPKFireWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801855E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801855E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801855EC: jal         0x80185374
    // 0x801855F0: nop

    itNessPKFireCommonUpdateAllCheckDestroy(rdram, ctx);
        goto after_0;
    // 0x801855F0: nop

    after_0:
    // 0x801855F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801855F8: bne         $v0, $at, L_80185608
    if (ctx->r2 != ctx->r1) {
        // 0x801855FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80185608;
    }
    // 0x801855FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185600: b           L_8018560C
    // 0x80185604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018560C;
    // 0x80185604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80185608:
    // 0x80185608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018560C:
    // 0x8018560C: jr          $ra
    // 0x80185610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80185610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void syAudioStopFGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020FAC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80020FB0: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x80020FB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80020FB8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80020FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020FC0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80020FC4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80020FC8: beq         $a1, $zero, L_80020FEC
    if (ctx->r5 == 0) {
        // 0x80020FCC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80020FEC;
    }
    // 0x80020FCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80020FD0: jal         0x80026738
    // 0x80020FD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x80020FD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80020FD8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80020FDC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80020FE0: lw          $t8, -0x26AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26AC);
    // 0x80020FE4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80020FE8: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_80020FEC:
    // 0x80020FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80020FF4: jr          $ra
    // 0x80020FF8: nop

    return;
    // 0x80020FF8: nop

;}
RECOMP_FUNC void func_ovl29_80136B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136B14: jr          $ra
    // 0x80136B18: nop

    return;
    // 0x80136B18: nop

;}
RECOMP_FUNC void gcRunGObjProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A49C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A4A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8000A4A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A4A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A4AC: sw          $t6, -0x478C($at)
    MEM_W(-0X478C, ctx->r1) = ctx->r14;
    // 0x8000A4B0: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8000A4B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A4B8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000A4BC: sw          $t7, 0x6A54($at)
    MEM_W(0X6A54, ctx->r1) = ctx->r15;
    // 0x8000A4C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A4C4: sw          $a0, 0x6A60($at)
    MEM_W(0X6A60, ctx->r1) = ctx->r4;
    // 0x8000A4C8: lbu         $v0, 0x14($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X14);
    // 0x8000A4CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A4D0: beql        $v0, $zero, L_8000A4EC
    if (ctx->r2 == 0) {
        // 0x8000A4D4: lw          $a0, 0x1C($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X1C);
            goto L_8000A4EC;
    }
    goto skip_0;
    // 0x8000A4D4: lw          $a0, 0x1C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1C);
    skip_0:
    // 0x8000A4D8: beql        $v0, $at, L_8000A518
    if (ctx->r2 == ctx->r1) {
        // 0x8000A4DC: lw          $a0, 0x18($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X18);
            goto L_8000A518;
    }
    goto skip_1;
    // 0x8000A4DC: lw          $a0, 0x18($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X18);
    skip_1:
    // 0x8000A4E0: b           L_8000A530
    // 0x8000A4E4: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
        goto L_8000A530;
    // 0x8000A4E4: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x8000A4E8: lw          $a0, 0x1C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1C);
L_8000A4EC:
    // 0x8000A4EC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8000A4F0: jal         0x80039190
    // 0x8000A4F4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A4F4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8000A4F8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A4FC: addiu       $a0, $a0, 0x6A70
    ctx->r4 = ADD32(ctx->r4, 0X6A70);
    // 0x8000A500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A504: jal         0x80030210
    // 0x8000A508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8000A508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8000A50C: b           L_8000A52C
    // 0x8000A510: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
        goto L_8000A52C;
    // 0x8000A510: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8000A514: lw          $a0, 0x18($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X18);
L_8000A518:
    // 0x8000A518: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8000A51C: lw          $t9, 0x1C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1C);
    // 0x8000A520: jalr        $t9
    // 0x8000A524: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8000A524: nop

    after_2:
    // 0x8000A528: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_8000A52C:
    // 0x8000A52C: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
L_8000A530:
    // 0x8000A530: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A534: sw          $zero, 0x6A54($at)
    MEM_W(0X6A54, ctx->r1) = 0;
    // 0x8000A538: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A53C: sw          $zero, 0x6A60($at)
    MEM_W(0X6A60, ctx->r1) = 0;
    // 0x8000A540: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8000A544: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A548: addiu       $a1, $a1, 0x6A64
    ctx->r5 = ADD32(ctx->r5, 0X6A64);
    // 0x8000A54C: sw          $zero, -0x478C($at)
    MEM_W(-0X478C, ctx->r1) = 0;
    // 0x8000A550: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000A554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A558: beql        $v0, $zero, L_8000A5D4
    if (ctx->r2 == 0) {
        // 0x8000A55C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000A5D4;
    }
    goto skip_2;
    // 0x8000A55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8000A560: beq         $v0, $at, L_8000A5C0
    if (ctx->r2 == ctx->r1) {
        // 0x8000A564: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8000A5C0;
    }
    // 0x8000A564: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000A568: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A56C: beq         $v0, $at, L_8000A57C
    if (ctx->r2 == ctx->r1) {
        // 0x8000A570: nop
    
            goto L_8000A57C;
    }
    // 0x8000A570: nop

    // 0x8000A574: b           L_8000A5D0
    // 0x8000A578: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_8000A5D0;
    // 0x8000A578: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8000A57C:
    // 0x8000A57C: beq         $v1, $zero, L_8000A5AC
    if (ctx->r3 == 0) {
        // 0x8000A580: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_8000A5AC;
    }
    // 0x8000A580: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000A584: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
    // 0x8000A588: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8000A58C: bnel        $v0, $t8, L_8000A5B0
    if (ctx->r2 != ctx->r24) {
        // 0x8000A590: lw          $a0, 0x18($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X18);
            goto L_8000A5B0;
    }
    goto skip_3;
    // 0x8000A590: lw          $a0, 0x18($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X18);
    skip_3:
    // 0x8000A594: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
L_8000A598:
    // 0x8000A598: beql        $v1, $zero, L_8000A5B0
    if (ctx->r3 == 0) {
        // 0x8000A59C: lw          $a0, 0x18($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X18);
            goto L_8000A5B0;
    }
    goto skip_4;
    // 0x8000A59C: lw          $a0, 0x18($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X18);
    skip_4:
    // 0x8000A5A0: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x8000A5A4: beql        $v0, $t0, L_8000A598
    if (ctx->r2 == ctx->r8) {
        // 0x8000A5A8: lw          $v1, 0x8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X8);
            goto L_8000A598;
    }
    goto skip_5;
    // 0x8000A5A8: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    skip_5:
L_8000A5AC:
    // 0x8000A5AC: lw          $a0, 0x18($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X18);
L_8000A5B0:
    // 0x8000A5B0: jal         0x80009A84
    // 0x8000A5B4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x8000A5B4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x8000A5B8: b           L_8000A5D0
    // 0x8000A5BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_8000A5D0;
    // 0x8000A5BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8000A5C0:
    // 0x8000A5C0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000A5C4: jal         0x8000848C
    // 0x8000A5C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    gcEndGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8000A5C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8000A5CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8000A5D0:
    // 0x8000A5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000A5D4:
    // 0x8000A5D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A5D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A5DC: jr          $ra
    // 0x8000A5E0: nop

    return;
    // 0x8000A5E0: nop

;}
RECOMP_FUNC void itGShellSpinProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178CF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178D00: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178D04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80178D08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80178D0C: lw          $t6, 0x298($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X298);
    // 0x80178D10: lw          $t7, 0x2A4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2A4);
    // 0x80178D14: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80178D18: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80178D1C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80178D20: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80178D24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80178D28: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80178D2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80178D30: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80178D34: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80178D38: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80178D3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80178D40: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80178D44: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80178D48: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x80178D4C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80178D50: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80178D54: nop

    // 0x80178D58: bc1fl       L_80178D6C
    if (!c1cs) {
        // 0x80178D5C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80178D6C;
    }
    goto skip_0;
    // 0x80178D5C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80178D60: b           L_80178D6C
    // 0x80178D64: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80178D6C;
    // 0x80178D64: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80178D68: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80178D6C:
    // 0x80178D6C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80178D70: nop

    // 0x80178D74: bc1fl       L_80178DCC
    if (!c1cs) {
        // 0x80178D78: lw          $t1, 0x108($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X108);
            goto L_80178DCC;
    }
    goto skip_1;
    // 0x80178D78: lw          $t1, 0x108($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X108);
    skip_1:
    // 0x80178D7C: sw          $t9, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r25;
    // 0x80178D80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80178D84: jal         0x8016F280
    // 0x80178D88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_0;
    // 0x80178D88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80178D8C: jal         0x801727BC
    // 0x80178D90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainCopyDamageStats(rdram, ctx);
        goto after_1;
    // 0x80178D90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80178D94: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80178D98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80178D9C: lw          $t0, 0x108($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X108);
    // 0x80178DA0: beq         $t0, $zero, L_80178DB8
    if (ctx->r8 == 0) {
        // 0x80178DA4: nop
    
            goto L_80178DB8;
    }
    // 0x80178DA4: nop

    // 0x80178DA8: jal         0x80178FA8
    // 0x80178DAC: nop

    itGShellSpinAirSetStatus(rdram, ctx);
        goto after_2;
    // 0x80178DAC: nop

    after_2:
    // 0x80178DB0: b           L_80178DF4
    // 0x80178DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80178DF4;
    // 0x80178DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80178DB8:
    // 0x80178DB8: jal         0x80178EDC
    // 0x80178DBC: nop

    itGShellSpinSetStatus(rdram, ctx);
        goto after_3;
    // 0x80178DBC: nop

    after_3:
    // 0x80178DC0: b           L_80178DF4
    // 0x80178DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80178DF4;
    // 0x80178DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178DC8: lw          $t1, 0x108($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X108);
L_80178DCC:
    // 0x80178DCC: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x80178DD0: beq         $t1, $zero, L_80178DE8
    if (ctx->r9 == 0) {
        // 0x80178DD4: nop
    
            goto L_80178DE8;
    }
    // 0x80178DD4: nop

    // 0x80178DD8: jal         0x80178930
    // 0x80178DDC: nop

    itGShellFallSetStatus(rdram, ctx);
        goto after_4;
    // 0x80178DDC: nop

    after_4:
    // 0x80178DE0: b           L_80178DF4
    // 0x80178DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80178DF4;
    // 0x80178DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80178DE8:
    // 0x80178DE8: jal         0x80178910
    // 0x80178DEC: nop

    itGShellWaitSetStatus(rdram, ctx);
        goto after_5;
    // 0x80178DEC: nop

    after_5:
    // 0x80178DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80178DF4:
    // 0x80178DF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80178DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178DFC: jr          $ra
    // 0x80178E00: nop

    return;
    // 0x80178E00: nop

;}
RECOMP_FUNC void func_ovl8_80375864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375864: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80375868: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8037586C: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x80375870: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80375874: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80375878: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8037587C: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x80375880: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x80375884: jr          $ra
    // 0x80375888: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    return;
    // 0x80375888: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void gmCollisionGetItemAttackShieldPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0EB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0EBC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0EC0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800F0EC4: jal         0x800F095C
    // 0x800F0EC8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetItemAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0EC8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0ECC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0ED0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0ED4: jal         0x800F09F0
    // 0x800F0ED8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    gmCollisionGetShieldPosition(rdram, ctx);
        goto after_1;
    // 0x800F0ED8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800F0EDC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0EE0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0EE4: jal         0x800F0A48
    // 0x800F0EE8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0EE8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0EF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0EF4: jr          $ra
    // 0x800F0EF8: nop

    return;
    // 0x800F0EF8: nop

;}
RECOMP_FUNC void ftBossYubideppou3SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A538: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015A53C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015A540: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015A544: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8015A548: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015A54C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015A550: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    // 0x8015A554: jal         0x800E6F24
    // 0x8015A558: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A558: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015A55C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8015A560: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015A564: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8015A568: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8015A56C: lh          $t7, 0xB1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB1A);
    // 0x8015A570: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8015A574: sh          $t8, 0xB1A($v0)
    MEM_H(0XB1A, ctx->r2) = ctx->r24;
    // 0x8015A578: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8015A57C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8015A580: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8015A584: lw          $a0, 0x924($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X924);
    // 0x8015A588: jal         0x800EDF24
    // 0x8015A58C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_1;
    // 0x8015A58C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8015A590: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8015A594: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8015A598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015A59C: lw          $t9, 0xADC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XADC);
    // 0x8015A5A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8015A5A4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8015A5A8: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8015A5AC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8015A5B0: nop

    // 0x8015A5B4: bc1f        L_8015A5DC
    if (!c1cs) {
        // 0x8015A5B8: nop
    
            goto L_8015A5DC;
    }
    // 0x8015A5B8: nop

    // 0x8015A5BC: lh          $t0, 0xB1A($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XB1A);
    // 0x8015A5C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8015A5C4: beq         $t0, $at, L_8015A5DC
    if (ctx->r8 == ctx->r1) {
        // 0x8015A5C8: nop
    
            goto L_8015A5DC;
    }
    // 0x8015A5C8: nop

    // 0x8015A5CC: jal         0x8016DE28
    // 0x8015A5D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    wpBossBulletHardMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x8015A5D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8015A5D4: b           L_8015A5E8
    // 0x8015A5D8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_8015A5E8;
    // 0x8015A5D8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8015A5DC:
    // 0x8015A5DC: jal         0x8016DDB4
    // 0x8015A5E0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    wpBossBulletNormalMakeWeapon(rdram, ctx);
        goto after_3;
    // 0x8015A5E0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8015A5E4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8015A5E8:
    // 0x8015A5E8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8015A5EC: sb          $t1, 0xB1C($v0)
    MEM_B(0XB1C, ctx->r2) = ctx->r9;
    // 0x8015A5F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015A5F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015A5F8: jr          $ra
    // 0x8015A5FC: nop

    return;
    // 0x8015A5FC: nop

;}
RECOMP_FUNC void func_ovl8_8037B98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B98C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8037B990: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037B994: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037B998: addiu       $t7, $t7, -0x5EE4
    ctx->r15 = ADD32(ctx->r15, -0X5EE4);
    // 0x8037B99C: addiu       $v0, $v0, -0x1040
    ctx->r2 = ADD32(ctx->r2, -0X1040);
    // 0x8037B9A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037B9A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037B9A8: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x8037B9AC: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
L_8037B9B0:
    // 0x8037B9B0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037B9B4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8037B9B8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8037B9BC: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x8037B9C0: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8037B9C4: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8037B9C8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8037B9CC: bne         $t7, $t0, L_8037B9B0
    if (ctx->r15 != ctx->r8) {
        // 0x8037B9D0: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8037B9B0;
    }
    // 0x8037B9D0: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8037B9D4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037B9D8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8037B9DC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8037B9E0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8037B9E4: jal         0x80371638
    // 0x8037B9E8: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    func_ovl8_80371638(rdram, ctx);
        goto after_0;
    // 0x8037B9E8: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    after_0:
    // 0x8037B9EC: jal         0x8037D2F0
    // 0x8037B9F0: nop

    func_ovl8_8037D2F0(rdram, ctx);
        goto after_1;
    // 0x8037B9F0: nop

    after_1:
    // 0x8037B9F4: jal         0x803717A0
    // 0x8037B9F8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_ovl8_803717A0(rdram, ctx);
        goto after_2;
    // 0x8037B9F8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x8037B9FC: beq         $v0, $zero, L_8037BA14
    if (ctx->r2 == 0) {
        // 0x8037BA00: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037BA14;
    }
    // 0x8037BA00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037BA04: jal         0x8037C3C0
    // 0x8037BA08: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_ovl8_8037C3C0(rdram, ctx);
        goto after_3;
    // 0x8037BA08: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_3:
    // 0x8037BA0C: b           L_8037BA18
    // 0x8037BA10: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_8037BA18;
    // 0x8037BA10: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_8037BA14:
    // 0x8037BA14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037BA18:
    // 0x8037BA18: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037BA1C: addiu       $v0, $v0, -0x103C
    ctx->r2 = ADD32(ctx->r2, -0X103C);
    // 0x8037BA20: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8037BA24: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8037BA28: jal         0x8037C498
    // 0x8037BA2C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    func_ovl8_8037C498(rdram, ctx);
        goto after_4;
    // 0x8037BA2C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x8037BA30: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037BA34: jal         0x8037C510
    // 0x8037BA38: lw          $a0, -0x103C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X103C);
    func_ovl8_8037C510(rdram, ctx);
        goto after_5;
    // 0x8037BA38: lw          $a0, -0x103C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X103C);
    after_5:
    // 0x8037BA3C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037BA40: addiu       $a1, $a1, -0x426C
    ctx->r5 = ADD32(ctx->r5, -0X426C);
    // 0x8037BA44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037BA48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037BA4C: jal         0x80008188
    // 0x8037BA50: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x8037BA50: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x8037BA54: jal         0x803717A0
    // 0x8037BA58: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    func_ovl8_803717A0(rdram, ctx);
        goto after_7;
    // 0x8037BA58: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_7:
    // 0x8037BA5C: beq         $v0, $zero, L_8037BA78
    if (ctx->r2 == 0) {
        // 0x8037BA60: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037BA78;
    }
    // 0x8037BA60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037BA64: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8037BA68: jal         0x8037CE90
    // 0x8037BA6C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_ovl8_8037CE90(rdram, ctx);
        goto after_8;
    // 0x8037BA6C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_8:
    // 0x8037BA70: b           L_8037BA7C
    // 0x8037BA74: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
        goto L_8037BA7C;
    // 0x8037BA74: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_8037BA78:
    // 0x8037BA78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037BA7C:
    // 0x8037BA7C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037BA80: addiu       $v0, $v0, -0x1038
    ctx->r2 = ADD32(ctx->r2, -0X1038);
    // 0x8037BA84: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8037BA88: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8037BA8C: jal         0x8037CFD8
    // 0x8037BA90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    func_ovl8_8037CFD8(rdram, ctx);
        goto after_9;
    // 0x8037BA90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_9:
    // 0x8037BA94: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037BA98: lw          $v1, -0x1038($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1038);
    // 0x8037BA9C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037BAA0: addiu       $a1, $a1, -0x420C
    ctx->r5 = ADD32(ctx->r5, -0X420C);
    // 0x8037BAA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037BAA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8037BAAC: jal         0x80008188
    // 0x8037BAB0: lw          $a0, 0x48($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X48);
    gcAddGObjProcess(rdram, ctx);
        goto after_10;
    // 0x8037BAB0: lw          $a0, 0x48($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X48);
    after_10:
    // 0x8037BAB4: jal         0x8037D63C
    // 0x8037BAB8: nop

    func_ovl8_8037D63C(rdram, ctx);
        goto after_11;
    // 0x8037BAB8: nop

    after_11:
    // 0x8037BABC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BAC0: jal         0x80381DC8
    // 0x8037BAC4: sw          $zero, -0x1034($at)
    MEM_W(-0X1034, ctx->r1) = 0;
    dbUiNodeTypeRegisterHandlers(rdram, ctx);
        goto after_12;
    // 0x8037BAC4: sw          $zero, -0x1034($at)
    MEM_W(-0X1034, ctx->r1) = 0;
    after_12:
    // 0x8037BAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037BACC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8037BAD0: jr          $ra
    // 0x8037BAD4: nop

    return;
    // 0x8037BAD4: nop

;}
RECOMP_FUNC void ftYoshiSpecialHiSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EC54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015EC58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015EC5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015EC60: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015EC64: jal         0x800DEEC8
    // 0x8015EC68: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015EC68: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015EC6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015EC70: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8015EC74: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x8015EC78: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015EC7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015EC80: jal         0x800E6F24
    // 0x8015EC84: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015EC84: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015EC88: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8015EC8C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8015EC90: addiu       $t8, $t8, -0x1680
    ctx->r24 = ADD32(ctx->r24, -0X1680);
    // 0x8015EC94: jal         0x800D8EB8
    // 0x8015EC98: sw          $t8, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r24;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015EC98: sw          $t8, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r24;
    after_2:
    // 0x8015EC9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015ECA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015ECA4: jr          $ra
    // 0x8015ECA8: nop

    return;
    // 0x8015ECA8: nop

;}
RECOMP_FUNC void ftCommonAttackLw4CheckInterruptSquat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150838: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015083C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150840: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80150844: jal         0x80150798
    // 0x80150848: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonAttackLw4CheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x80150848: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015084C: beq         $v0, $zero, L_80150870
    if (ctx->r2 == 0) {
        // 0x80150850: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80150870;
    }
    // 0x80150850: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80150854: lw          $t6, 0xB20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB20);
    // 0x80150858: beql        $t6, $zero, L_80150874
    if (ctx->r14 == 0) {
        // 0x8015085C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80150874;
    }
    goto skip_0;
    // 0x8015085C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80150860: jal         0x801507D0
    // 0x80150864: nop

    ftCommonAttackLw4CheckInterruptMain(rdram, ctx);
        goto after_1;
    // 0x80150864: nop

    after_1:
    // 0x80150868: b           L_80150878
    // 0x8015086C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80150878;
    // 0x8015086C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150870:
    // 0x80150870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80150874:
    // 0x80150874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150878:
    // 0x80150878: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015087C: jr          $ra
    // 0x80150880: nop

    return;
    // 0x80150880: nop

;}
RECOMP_FUNC void mnMapsMakeLayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013303C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80133040: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133044: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80133048: addiu       $t7, $t7, 0x4858
    ctx->r15 = ADD32(ctx->r15, 0X4858);
    // 0x8013304C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80133050: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133054: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80133058: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8013305C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80133060: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80133064: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x80133068: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
L_8013306C:
    // 0x8013306C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133070: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133074: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133078: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x8013307C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80133080: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80133084: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133088: bne         $t7, $t0, L_8013306C
    if (ctx->r15 != ctx->r8) {
        // 0x8013308C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8013306C;
    }
    // 0x8013308C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133090: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80133094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013309C: bne         $t1, $zero, L_801330AC
    if (ctx->r9 != 0) {
        // 0x801330A0: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_801330AC;
    }
    // 0x801330A0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x801330A4: b           L_80133198
    // 0x801330A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133198;
    // 0x801330A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801330AC:
    // 0x801330AC: jal         0x80009968
    // 0x801330B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801330B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801330B4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x801330B8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x801330BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801330C0: lbu         $t3, 0x44($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X44);
    // 0x801330C4: sllv        $t0, $t5, $t4
    ctx->r8 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x801330C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801330CC: and         $t7, $t3, $t0
    ctx->r15 = ctx->r11 & ctx->r8;
    // 0x801330D0: beq         $t7, $zero, L_801330E4
    if (ctx->r15 == 0) {
        // 0x801330D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801330E4;
    }
    // 0x801330D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801330D8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801330DC: b           L_801330EC
    // 0x801330E0: addiu       $a1, $a1, 0x2F70
    ctx->r5 = ADD32(ctx->r5, 0X2F70);
        goto L_801330EC;
    // 0x801330E0: addiu       $a1, $a1, 0x2F70
    ctx->r5 = ADD32(ctx->r5, 0X2F70);
L_801330E4:
    // 0x801330E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801330E8: addiu       $a1, $a1, 0x2EF0
    ctx->r5 = ADD32(ctx->r5, 0X2EF0);
L_801330EC:
    // 0x801330EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801330F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801330F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801330F8: jal         0x80009DF4
    // 0x801330FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801330FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133100: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80133104: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80133108: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013310C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133114: jal         0x8000F590
    // 0x80133118: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x80133118: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_2:
    // 0x8013311C: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x80133120: beql        $a1, $zero, L_80133134
    if (ctx->r5 == 0) {
        // 0x80133124: lw          $a1, 0x4($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X4);
            goto L_80133134;
    }
    goto skip_0;
    // 0x80133124: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x80133128: jal         0x8000F8F4
    // 0x8013312C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x8013312C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80133130: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
L_80133134:
    // 0x80133134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133138: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8013313C: bne         $a1, $zero, L_80133150
    if (ctx->r5 != 0) {
        // 0x80133140: nop
    
            goto L_80133150;
    }
    // 0x80133140: nop

    // 0x80133144: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x80133148: beql        $t8, $zero, L_80133164
    if (ctx->r24 == 0) {
        // 0x8013314C: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_80133164;
    }
    goto skip_1;
    // 0x8013314C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    skip_1:
L_80133150:
    // 0x80133150: jal         0x8000BED8
    // 0x80133154: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    gcAddAnimAll(rdram, ctx);
        goto after_4;
    // 0x80133154: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_4:
    // 0x80133158: jal         0x8000DF34
    // 0x8013315C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x8013315C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80133160: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80133164:
    // 0x80133164: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x80133168: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8013316C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80133170: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80133174: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80133178: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8013317C: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x80133180: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80133184: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80133188: swc1        $f6, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f6.u32l;
    // 0x8013318C: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80133190: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80133194: swc1        $f8, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f8.u32l;
L_80133198:
    // 0x80133198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013319C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801331A0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801331A4: jr          $ra
    // 0x801331A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801331A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mnCongraActorFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C04: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131C08: addiu       $v1, $v1, 0x22E4
    ctx->r3 = ADD32(ctx->r3, 0X22E4);
    // 0x80131C0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131C14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131C18: beq         $v0, $zero, L_80131C2C
    if (ctx->r2 == 0) {
        // 0x80131C1C: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80131C2C;
    }
    // 0x80131C1C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80131C20: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80131C24: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131C28: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80131C2C:
    // 0x80131C2C: bne         $v0, $zero, L_80131C94
    if (ctx->r2 != 0) {
        // 0x80131C30: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_80131C94;
    }
    // 0x80131C30: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131C34: lw          $t7, 0x22EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X22EC);
    // 0x80131C38: bnel        $t7, $zero, L_80131C98
    if (ctx->r15 != 0) {
        // 0x80131C3C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80131C98;
    }
    goto skip_0;
    // 0x80131C3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80131C40: jal         0x80131B6C
    // 0x80131C44: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    mnCongraGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x80131C44: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x80131C48: beq         $v0, $zero, L_80131C94
    if (ctx->r2 == 0) {
        // 0x80131C4C: addiu       $a3, $sp, 0x2C
        ctx->r7 = ADD32(ctx->r29, 0X2C);
            goto L_80131C94;
    }
    // 0x80131C4C: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x80131C50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80131C54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C58: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131C5C: sw          $t8, 0x22EC($at)
    MEM_W(0X22EC, ctx->r1) = ctx->r24;
    // 0x80131C60: addiu       $t9, $t9, 0x21C0
    ctx->r25 = ADD32(ctx->r25, 0X21C0);
    // 0x80131C64: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80131C68: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80131C6C: addiu       $t3, $t3, 0x22F0
    ctx->r11 = ADD32(ctx->r11, 0X22F0);
    // 0x80131C70: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80131C74: addiu       $t2, $zero, 0x5A
    ctx->r10 = ADD32(0, 0X5A);
    // 0x80131C78: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80131C7C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80131C80: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80131C84: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x80131C88: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80131C8C: jal         0x800D4060
    // 0x80131C90: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_1;
    // 0x80131C90: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
L_80131C94:
    // 0x80131C94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80131C98:
    // 0x80131C98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80131C9C: jr          $ra
    // 0x80131CA0: nop

    return;
    // 0x80131CA0: nop

;}
RECOMP_FUNC void func_ovl8_80371AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371AC4: jr          $ra
    // 0x80371AC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371AC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void mnPlayersVSGetFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132118: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013211C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132120: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80132124: addiu       $t6, $t6, -0x4B2C
    ctx->r14 = ADD32(ctx->r14, -0X4B2C);
    // 0x80132128: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x8013212C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80132130:
    // 0x80132130: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132134: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132138: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8013213C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132140: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132144: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132148: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013214C: bne         $t6, $t0, L_80132130
    if (ctx->r14 != ctx->r8) {
        // 0x80132150: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132130;
    }
    // 0x80132150: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132154: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80132158: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8013215C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80132160: jr          $ra
    // 0x80132164: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80132164: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void wpKirbyCutterProcSetOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BE14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016BE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016BE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016BE20: jal         0x800269C0
    // 0x8016BE24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8016BE24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8016BE28: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016BE2C: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8016BE30: jal         0x80100480
    // 0x8016BE34: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016BE34: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016BE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016BE3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016BE40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016BE44: jr          $ra
    // 0x8016BE48: nop

    return;
    // 0x8016BE48: nop

;}
RECOMP_FUNC void mnPlayers1PBonusSetDigitColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BF8: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80131BFC: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131C00: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80131C04: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131C08: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80131C0C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80131C10: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x80131C14: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x80131C18: sb          $t1, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r9;
    // 0x80131C1C: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80131C20: sb          $t2, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r10;
    // 0x80131C24: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x80131C28: sb          $t3, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r11;
    // 0x80131C2C: lw          $t4, 0x10($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10);
    // 0x80131C30: sb          $t4, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r12;
    // 0x80131C34: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x80131C38: jr          $ra
    // 0x80131C3C: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
    return;
    // 0x80131C3C: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void func_ovl8_8037BB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BB78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037BB7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_8037BB80:
    // 0x8037BB80: jal         0x8037499C
    // 0x8037BB84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_ovl8_8037499C(rdram, ctx);
        goto after_0;
    // 0x8037BB84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8037BB88: beq         $v0, $zero, L_8037BBA0
    if (ctx->r2 == 0) {
        // 0x8037BB8C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037BBA0;
    }
    // 0x8037BB8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037BB90: jal         0x8037488C
    // 0x8037BB94: nop

    func_ovl8_8037488C(rdram, ctx);
        goto after_1;
    // 0x8037BB94: nop

    after_1:
    // 0x8037BB98: b           L_8037BB80
    // 0x8037BB9C: nop

        goto L_8037BB80;
    // 0x8037BB9C: nop

L_8037BBA0:
    // 0x8037BBA0: jal         0x8037499C
    // 0x8037BBA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_ovl8_8037499C(rdram, ctx);
        goto after_2;
    // 0x8037BBA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8037BBA8: beq         $v0, $zero, L_8037BBC0
    if (ctx->r2 == 0) {
        // 0x8037BBAC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037BBC0;
    }
    // 0x8037BBAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037BBB0: jal         0x8037488C
    // 0x8037BBB4: nop

    func_ovl8_8037488C(rdram, ctx);
        goto after_3;
    // 0x8037BBB4: nop

    after_3:
    // 0x8037BBB8: b           L_8037BBA0
    // 0x8037BBBC: nop

        goto L_8037BBA0;
    // 0x8037BBBC: nop

L_8037BBC0:
    // 0x8037BBC0: jal         0x8037BD44
    // 0x8037BBC4: nop

    func_ovl8_8037BD44(rdram, ctx);
        goto after_4;
    // 0x8037BBC4: nop

    after_4:
    // 0x8037BBC8: jal         0x8037BAD8
    // 0x8037BBCC: nop

    func_ovl8_8037BAD8(rdram, ctx);
        goto after_5;
    // 0x8037BBCC: nop

    after_5:
    // 0x8037BBD0: jal         0x8037BB28
    // 0x8037BBD4: nop

    func_ovl8_8037BB28(rdram, ctx);
        goto after_6;
    // 0x8037BBD4: nop

    after_6:
    // 0x8037BBD8: jal         0x8037D34C
    // 0x8037BBDC: nop

    func_ovl8_8037D34C(rdram, ctx);
        goto after_7;
    // 0x8037BBDC: nop

    after_7:
    // 0x8037BBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037BBE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037BBE8: jr          $ra
    // 0x8037BBEC: nop

    return;
    // 0x8037BBEC: nop

;}
RECOMP_FUNC void wpYoshiEggThrowProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C3B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016C3B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C3BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016C3C0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016C3C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016C3C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016C3CC: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x8016C3D0: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x8016C3D4: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x8016C3D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016C3DC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8016C3E0: jal         0x80019438
    // 0x8016C3E4: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x8016C3E4: nop

    after_0:
    // 0x8016C3E8: jal         0x80167FA0
    // 0x8016C3EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_1;
    // 0x8016C3EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016C3F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C3F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016C3F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C3FC: jr          $ra
    // 0x8016C400: nop

    return;
    // 0x8016C400: nop

;}
RECOMP_FUNC void scSubsysFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390584: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80390588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8039058C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80390590: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80390594: jal         0x800E0830
    // 0x80390598: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_0;
    // 0x80390598: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8039059C: jal         0x800E11C8
    // 0x803905A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainRunUpdateColAnim(rdram, ctx);
        goto after_1;
    // 0x803905A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x803905A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x803905A8: lw          $v0, 0x9D4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X9D4);
    // 0x803905AC: beql        $v0, $zero, L_803905C0
    if (ctx->r2 == 0) {
        // 0x803905B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803905C0;
    }
    goto skip_0;
    // 0x803905B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803905B4: jalr        $v0
    // 0x803905B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x803905B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x803905BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803905C0:
    // 0x803905C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803905C4: jr          $ra
    // 0x803905C8: nop

    return;
    // 0x803905C8: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltGroundCheckDestroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80169BF0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80169BF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80169BF8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80169BFC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80169C00: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80169C04: jal         0x80169654
    // 0x80169C08: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    wpPikachuThunderJoltGroundAddAnim(rdram, ctx);
        goto after_0;
    // 0x80169C08: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80169C0C: lw          $v0, 0x29C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X29C);
    // 0x80169C10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80169C14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80169C18: beq         $v0, $zero, L_80169C40
    if (ctx->r2 == 0) {
        // 0x80169C1C: addiu       $t6, $sp, 0x30
        ctx->r14 = ADD32(ctx->r29, 0X30);
            goto L_80169C40;
    }
    // 0x80169C1C: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80169C20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80169C24: beq         $v0, $at, L_80169C80
    if (ctx->r2 == ctx->r1) {
        // 0x80169C28: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80169C80;
    }
    // 0x80169C28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80169C2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80169C30: beq         $v0, $at, L_80169C5C
    if (ctx->r2 == ctx->r1) {
        // 0x80169C34: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80169C5C;
    }
    // 0x80169C34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80169C38: b           L_80169CA0
    // 0x80169C3C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_80169CA0;
    // 0x80169C3C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_80169C40:
    // 0x80169C40: lw          $a1, 0x74($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X74);
    // 0x80169C44: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    // 0x80169C48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80169C4C: jal         0x800F3DD8
    // 0x80169C50: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_1;
    // 0x80169C50: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x80169C54: b           L_80169CA0
    // 0x80169C58: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_80169CA0;
    // 0x80169C58: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_80169C5C:
    // 0x80169C5C: lw          $a1, 0x74($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X74);
    // 0x80169C60: lw          $a0, 0xCC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XCC);
    // 0x80169C64: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x80169C68: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80169C6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80169C70: jal         0x800F4194
    // 0x80169C74: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_2;
    // 0x80169C74: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_2:
    // 0x80169C78: b           L_80169CA0
    // 0x80169C7C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_80169CA0;
    // 0x80169C7C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_80169C80:
    // 0x80169C80: lw          $a1, 0x74($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X74);
    // 0x80169C84: lw          $a0, 0xE0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XE0);
    // 0x80169C88: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80169C8C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80169C90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80169C94: jal         0x800F41C0
    // 0x80169C98: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_3;
    // 0x80169C98: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_3:
    // 0x80169C9C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_80169CA0:
    // 0x80169CA0: jal         0x800191FC
    // 0x80169CA4: addiu       $a1, $s0, 0x2A0
    ctx->r5 = ADD32(ctx->r16, 0X2A0);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_4;
    // 0x80169CA4: addiu       $a1, $s0, 0x2A0
    ctx->r5 = ADD32(ctx->r16, 0X2A0);
    after_4:
    // 0x80169CA8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80169CAC: lwc1        $f4, -0x3530($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3530);
    // 0x80169CB0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80169CB4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80169CB8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80169CBC: nop

    // 0x80169CC0: bc1f        L_80169CE0
    if (!c1cs) {
        // 0x80169CC4: nop
    
            goto L_80169CE0;
    }
    // 0x80169CC4: nop

    // 0x80169CC8: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x80169CCC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80169CD0: jal         0x800FF648
    // 0x80169CD4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_5;
    // 0x80169CD4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_5:
    // 0x80169CD8: b           L_80169CF4
    // 0x80169CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80169CF4;
    // 0x80169CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80169CE0:
    // 0x80169CE0: jal         0x8001863C
    // 0x80169CE4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_6;
    // 0x80169CE4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_6:
    // 0x80169CE8: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x80169CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80169CF0: swc1        $f0, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f0.u32l;
L_80169CF4:
    // 0x80169CF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80169CF8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80169CFC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80169D00: jr          $ra
    // 0x80169D04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80169D04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gmRumbleInitPlayers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801157EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801157F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801157F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801157F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801157FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80115800: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80115804:
    // 0x80115804: jal         0x800044B4
    // 0x80115808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerInitRumble(rdram, ctx);
        goto after_0;
    // 0x80115808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8011580C: jal         0x80004494
    // 0x80115810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerStopRumble(rdram, ctx);
        goto after_1;
    // 0x80115810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80115814: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80115818: bne         $s0, $s1, L_80115804
    if (ctx->r16 != ctx->r17) {
        // 0x8011581C: nop
    
            goto L_80115804;
    }
    // 0x8011581C: nop

    // 0x80115820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80115824: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80115828: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8011582C: jr          $ra
    // 0x80115830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80115830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void scExplainWindowProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D2D0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8018D2D4: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x8018D2D8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018D2DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D2E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D2E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D2E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D2EC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8018D2F0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8018D2F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018D2F8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D2FC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018D300: lui         $t9, 0xED02
    ctx->r25 = S32(0XED02 << 16);
    // 0x8018D304: lui         $t2, 0x4D
    ctx->r10 = S32(0X4D << 16);
    // 0x8018D308: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D30C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8018D310: ori         $t2, $t2, 0x8398
    ctx->r10 = ctx->r10 | 0X8398;
    // 0x8018D314: ori         $t9, $t9, 0x8280
    ctx->r25 = ctx->r25 | 0X8280;
    // 0x8018D318: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D31C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8018D320: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018D324: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x8018D328: ori         $t4, $t4, 0xA01
    ctx->r12 = ctx->r12 | 0XA01;
    // 0x8018D32C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8018D330: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8018D334: lui         $t5, 0x30
    ctx->r13 = S32(0X30 << 16);
    // 0x8018D338: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8018D33C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D340: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018D344: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x8018D348: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x8018D34C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D350: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8018D354: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018D358: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D35C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018D360: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x8018D364: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018D368: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D36C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8018D370: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D374: jal         0x80006D70
    // 0x8018D378: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x8018D378: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018D37C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D380: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8018D384: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x8018D388: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x8018D38C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018D390: lui         $t3, 0xF64D
    ctx->r11 = S32(0XF64D << 16);
    // 0x8018D394: lui         $t4, 0x2
    ctx->r12 = S32(0X2 << 16);
    // 0x8018D398: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8018D39C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8018D3A0: ori         $t4, $t4, 0x8280
    ctx->r12 = ctx->r12 | 0X8280;
    // 0x8018D3A4: ori         $t3, $t3, 0x8398
    ctx->r11 = ctx->r11 | 0X8398;
    // 0x8018D3A8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8018D3AC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8018D3B0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018D3B4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8018D3B8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8018D3BC: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8018D3C0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D3C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D3C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D3CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018D3D0: jr          $ra
    // 0x8018D3D4: nop

    return;
    // 0x8018D3D4: nop

;}
RECOMP_FUNC void mnCharactersResetFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133840: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133844: lw          $t6, 0x66E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X66E0);
    // 0x80133848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013384C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133850: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80133854: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80133858: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x8013385C: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x80133860: lwc1        $f4, 0x65D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65D4);
    // 0x80133864: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80133868: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013386C: lui         $at, 0x43B9
    ctx->r1 = S32(0X43B9 << 16);
    // 0x80133870: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133874: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80133878: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013387C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133880: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x80133884: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x80133888: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x8013388C: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80133890: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80133894: swc1        $f8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f8.u32l;
    // 0x80133898: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x8013389C: swc1        $f2, 0x66E4($at)
    MEM_W(0X66E4, ctx->r1) = ctx->f2.u32l;
    // 0x801338A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338A4: jr          $ra
    // 0x801338A8: swc1        $f2, 0x66E8($at)
    MEM_W(0X66E8, ctx->r1) = ctx->f2.u32l;
    return;
    // 0x801338A8: swc1        $f2, 0x66E8($at)
    MEM_W(0X66E8, ctx->r1) = ctx->f2.u32l;
;}
RECOMP_FUNC void wpSamusChargeShotProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80168DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168DAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80168DB0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80168DB4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80168DB8: jal         0x801680EC
    // 0x80168DBC: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x80168DBC: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    after_0:
    // 0x80168DC0: jal         0x80167F68
    // 0x80168DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetLR(rdram, ctx);
        goto after_1;
    // 0x80168DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80168DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80168DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80168DD4: jr          $ra
    // 0x80168DD8: nop

    return;
    // 0x80168DD8: nop

;}
RECOMP_FUNC void mnPlayersVSCheckReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A5E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013A5E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013A5EC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8013A5F0: jal         0x8013A30C
    // 0x8013A5F4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    mnPlayersVSGetReadyPlayerCount(rdram, ctx);
        goto after_0;
    // 0x8013A5F4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8013A5F8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8013A5FC: beq         $at, $zero, L_8013A608
    if (ctx->r1 == 0) {
        // 0x8013A600: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8013A608;
    }
    // 0x8013A600: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A604: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8013A608:
    // 0x8013A608: beq         $v1, $zero, L_8013A634
    if (ctx->r3 == 0) {
        // 0x8013A60C: lui         $t6, 0x8014
        ctx->r14 = S32(0X8014 << 16);
            goto L_8013A634;
    }
    // 0x8013A60C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013A610: lw          $t6, -0x4258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4258);
    // 0x8013A614: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013A618: bne         $t6, $at, L_8013A634
    if (ctx->r14 != ctx->r1) {
        // 0x8013A61C: nop
    
            goto L_8013A634;
    }
    // 0x8013A61C: nop

    // 0x8013A620: jal         0x8013A470
    // 0x8013A624: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    mnPlayersVSCheckSingleTeam(rdram, ctx);
        goto after_1;
    // 0x8013A624: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8013A628: beq         $v0, $zero, L_8013A634
    if (ctx->r2 == 0) {
        // 0x8013A62C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8013A634;
    }
    // 0x8013A62C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A630: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8013A634:
    // 0x8013A634: beql        $v1, $zero, L_8013A654
    if (ctx->r3 == 0) {
        // 0x8013A638: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013A654;
    }
    goto skip_0;
    // 0x8013A638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013A63C: jal         0x8013A534
    // 0x8013A640: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    mnPlayersVSCheckNoPuckOnPortraitAll(rdram, ctx);
        goto after_2;
    // 0x8013A640: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_2:
    // 0x8013A644: bne         $v0, $zero, L_8013A650
    if (ctx->r2 != 0) {
        // 0x8013A648: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8013A650;
    }
    // 0x8013A648: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A64C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8013A650:
    // 0x8013A650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A654:
    // 0x8013A654: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013A658: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013A65C: jr          $ra
    // 0x8013A660: nop

    return;
    // 0x8013A660: nop

;}
RECOMP_FUNC void mvUnknownMarioStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D508: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D50C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D510: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D514: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018D518: addiu       $a0, $a0, -0x2A44
    ctx->r4 = ADD32(ctx->r4, -0X2A44);
    // 0x8018D51C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D520: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018D524: jal         0x80007024
    // 0x8018D528: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018D528: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018D52C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018D530: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D534: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D538: addiu       $t9, $t9, -0x26B0
    ctx->r25 = ADD32(ctx->r25, -0X26B0);
    // 0x8018D53C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018D540: addiu       $a0, $a0, -0x2A28
    ctx->r4 = ADD32(ctx->r4, -0X2A28);
    // 0x8018D544: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018D548: jal         0x800A2698
    // 0x8018D54C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x8018D54C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018D550: jal         0x80020A74
    // 0x8018D554: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_2;
    // 0x8018D554: nop

    after_2:
    // 0x8018D558: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D560: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018D564: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8018D568: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D56C: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x8018D570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D574: jr          $ra
    // 0x8018D578: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    return;
    // 0x8018D578: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void sc1PBonusStageMakeTargets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D374: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8018D378: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D37C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018D380: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D384: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8018D388: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8018D38C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8018D390: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8018D394: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018D398: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8018D39C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018D3A0: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8018D3A4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018D3A8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8018D3AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018D3B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018D3B4: lw          $t1, 0x1300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1300);
    // 0x8018D3B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D3BC: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D3C0: addiu       $t0, $t0, -0x113C
    ctx->r8 = ADD32(ctx->r8, -0X113C);
    // 0x8018D3C4: addiu       $t9, $t8, -0xCC
    ctx->r25 = ADD32(ctx->r24, -0XCC);
    // 0x8018D3C8: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x8018D3CC: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x8018D3D0: swc1        $f20, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f20.u32l;
    // 0x8018D3D4: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8018D3D8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8018D3DC: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8018D3E0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8018D3E4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8018D3E8: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x8018D3EC: addiu       $s3, $s3, 0x13F0
    ctx->r19 = ADD32(ctx->r19, 0X13F0);
    // 0x8018D3F0: subu        $v1, $t2, $t3
    ctx->r3 = SUB32(ctx->r10, ctx->r11);
    // 0x8018D3F4: sb          $zero, 0xC($s3)
    MEM_B(0XC, ctx->r19) = 0;
    // 0x8018D3F8: addu        $s1, $v1, $t4
    ctx->r17 = ADD32(ctx->r3, ctx->r12);
    // 0x8018D3FC: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
    // 0x8018D400: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x8018D404: addu        $s2, $v1, $t5
    ctx->r18 = ADD32(ctx->r3, ctx->r13);
    // 0x8018D408: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018D40C: beq         $s4, $t6, L_8018D478
    if (ctx->r20 == ctx->r14) {
        // 0x8018D410: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_8018D478;
    }
    // 0x8018D410: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8018D414: addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // 0x8018D418: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8018D41C:
    // 0x8018D41C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018D420: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D424: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8018D428: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    // 0x8018D42C: jal         0x8016EA78
    // 0x8018D430: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_0;
    // 0x8018D430: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x8018D434: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8018D438: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D43C: beql        $a1, $zero, L_8018D45C
    if (ctx->r5 == 0) {
        // 0x8018D440: lbu         $t8, 0xC($s3)
        ctx->r24 = MEM_BU(ctx->r19, 0XC);
            goto L_8018D45C;
    }
    goto skip_0;
    // 0x8018D440: lbu         $t8, 0xC($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0XC);
    skip_0:
    // 0x8018D444: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018D448: jal         0x8000BD1C
    // 0x8018D44C: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8018D44C: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    after_1:
    // 0x8018D450: jal         0x8000DF34
    // 0x8018D454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x8018D454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8018D458: lbu         $t8, 0xC($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0XC);
L_8018D45C:
    // 0x8018D45C: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8018D460: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018D464: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018D468: sb          $t9, 0xC($s3)
    MEM_B(0XC, ctx->r19) = ctx->r25;
    // 0x8018D46C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8018D470: bnel        $s4, $t0, L_8018D41C
    if (ctx->r20 != ctx->r8) {
        // 0x8018D474: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8018D41C;
    }
    goto skip_1;
    // 0x8018D474: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_1:
L_8018D478:
    // 0x8018D478: lbu         $t1, 0xC($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0XC);
    // 0x8018D47C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018D480: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018D484: beq         $t1, $at, L_8018D4A4
    if (ctx->r9 == ctx->r1) {
        // 0x8018D488: lw          $s0, 0x24($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X24);
            goto L_8018D4A4;
    }
    // 0x8018D488: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018D48C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D490: addiu       $a0, $a0, -0xE90
    ctx->r4 = ADD32(ctx->r4, -0XE90);
    // 0x8018D494: jal         0x80023624
    // 0x8018D498: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D498: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
L_8018D49C:
    // 0x8018D49C: b           L_8018D49C
    pause_self(rdram);
    // 0x8018D4A0: nop

L_8018D4A4:
    // 0x8018D4A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D4A8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018D4AC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D4B0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8018D4B4: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8018D4B8: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8018D4BC: jr          $ra
    // 0x8018D4C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8018D4C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mnPlayers1PTrainingDestroyPortraitFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F68: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80133F6C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80133F70: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80133F74: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80133F78: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133F7C: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80133F80: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80133F84: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80133F88: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    // 0x80133F8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133F94: beq         $a1, $zero, L_80133FA4
    if (ctx->r5 == 0) {
        // 0x80133F98: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80133FA4;
    }
    // 0x80133F98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80133F9C: jal         0x80009A84
    // 0x80133FA0: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80133FA0: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    after_0:
L_80133FA4:
    // 0x80133FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133FA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133FAC: jr          $ra
    // 0x80133FB0: nop

    return;
    // 0x80133FB0: nop

;}
RECOMP_FUNC void mvOpeningRunFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013237C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80132380: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132384: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132388: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013238C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132390: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132394: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132398: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8013239C: addiu       $t8, $t8, 0x2748
    ctx->r24 = ADD32(ctx->r24, 0X2748);
    // 0x801323A0: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801323A4: addiu       $t0, $t0, 0x2A68
    ctx->r8 = ADD32(ctx->r8, 0X2A68);
    // 0x801323A8: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801323AC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801323B0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801323B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801323B8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801323BC: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x801323C0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801323C4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x801323C8: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x801323CC: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x801323D0: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x801323D4: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x801323D8: jal         0x800CDF78
    // 0x801323DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x801323DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x801323E0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801323E4: addiu       $s0, $s0, 0x25D0
    ctx->r16 = ADD32(ctx->r16, 0X25D0);
    // 0x801323E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801323EC: jal         0x800CDEEC
    // 0x801323F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x801323F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x801323F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801323F8: jal         0x80004980
    // 0x801323FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x801323FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132400: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132404: addiu       $a2, $a2, 0x2AA0
    ctx->r6 = ADD32(ctx->r6, 0X2AA0);
    // 0x80132408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013240C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80132410: jal         0x800CDE04
    // 0x80132414: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132414: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132418: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8013241C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132420: addiu       $a1, $a1, 0x2268
    ctx->r5 = ADD32(ctx->r5, 0X2268);
    // 0x80132424: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80132428: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013242C: jal         0x80009968
    // 0x80132430: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132430: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80132434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132438: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013243C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132440: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80132444: jal         0x8000B9FC
    // 0x80132448: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132448: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8013244C: jal         0x80115890
    // 0x80132450: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80132450: nop

    after_6:
    // 0x80132454: jal         0x8013225C
    // 0x80132458: nop

    mvOpeningRunInitVars(rdram, ctx);
        goto after_7;
    // 0x80132458: nop

    after_7:
    // 0x8013245C: jal         0x800FD300
    // 0x80132460: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x80132460: nop

    after_8:
    // 0x80132464: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132468: jal         0x800D7194
    // 0x8013246C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8013246C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x80132470: jal         0x800D786C
    // 0x80132474: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x80132474: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80132478: jal         0x800D786C
    // 0x8013247C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_11;
    // 0x8013247C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80132480: jal         0x800D786C
    // 0x80132484: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_12;
    // 0x80132484: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80132488: jal         0x800D786C
    // 0x8013248C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8013248C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80132490: jal         0x800D786C
    // 0x80132494: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_14;
    // 0x80132494: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_14:
    // 0x80132498: jal         0x800D786C
    // 0x8013249C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_15;
    // 0x8013249C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_15:
    // 0x801324A0: jal         0x800D786C
    // 0x801324A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_16;
    // 0x801324A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_16:
    // 0x801324A8: jal         0x800D786C
    // 0x801324AC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_17;
    // 0x801324AC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_17:
    // 0x801324B0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801324B4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801324B8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801324BC: addiu       $s1, $s1, 0xD9C
    ctx->r17 = ADD32(ctx->r17, 0XD9C);
    // 0x801324C0: addiu       $s2, $s2, 0x2738
    ctx->r18 = ADD32(ctx->r18, 0X2738);
    // 0x801324C4: addiu       $s0, $s0, 0x2718
    ctx->r16 = ADD32(ctx->r16, 0X2718);
L_801324C8:
    // 0x801324C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801324CC: jal         0x80004980
    // 0x801324D0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_18;
    // 0x801324D0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_18:
    // 0x801324D4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801324D8: bne         $s0, $s2, L_801324C8
    if (ctx->r16 != ctx->r18) {
        // 0x801324DC: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_801324C8;
    }
    // 0x801324DC: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x801324E0: jal         0x80132138
    // 0x801324E4: nop

    mvOpeningRunMakeMainCamera(rdram, ctx);
        goto after_19;
    // 0x801324E4: nop

    after_19:
    // 0x801324E8: jal         0x801321BC
    // 0x801324EC: nop

    mvOpeningRunMakeWallpaperCamera(rdram, ctx);
        goto after_20;
    // 0x801324EC: nop

    after_20:
    // 0x801324F0: jal         0x80131E88
    // 0x801324F4: nop

    mvOpeningRunMakeWallpaper(rdram, ctx);
        goto after_21;
    // 0x801324F4: nop

    after_21:
    // 0x801324F8: jal         0x80131BE8
    // 0x801324FC: nop

    mvOpeningRunMakeFighters(rdram, ctx);
        goto after_22;
    // 0x801324FC: nop

    after_22:
    // 0x80132500: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80132504: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132508: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013250C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80132510: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132514: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132518: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8013251C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132520: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80132524: jal         0x803904E0
    // 0x80132528: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_23;
    // 0x80132528: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_23:
    // 0x8013252C: jal         0x8000092C
    // 0x80132530: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_24;
    // 0x80132530: nop

    after_24:
    // 0x80132534: sltiu       $at, $v0, 0x8CA
    ctx->r1 = ctx->r2 < 0X8CA ? 1 : 0;
    // 0x80132538: beql        $at, $zero, L_80132558
    if (ctx->r1 == 0) {
        // 0x8013253C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80132558;
    }
    goto skip_0;
    // 0x8013253C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_80132540:
    // 0x80132540: jal         0x8000092C
    // 0x80132544: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_25;
    // 0x80132544: nop

    after_25:
    // 0x80132548: sltiu       $at, $v0, 0x8CA
    ctx->r1 = ctx->r2 < 0X8CA ? 1 : 0;
    // 0x8013254C: bne         $at, $zero, L_80132540
    if (ctx->r1 != 0) {
        // 0x80132550: nop
    
            goto L_80132540;
    }
    // 0x80132550: nop

    // 0x80132554: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80132558:
    // 0x80132558: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013255C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80132560: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80132564: jr          $ra
    // 0x80132568: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80132568: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void syDebugFillRectangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021A34: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80021A38: addiu       $t0, $t0, 0x667C
    ctx->r8 = ADD32(ctx->r8, 0X667C);
    // 0x80021A3C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80021A40: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80021A44: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x80021A48: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80021A4C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021A50: addiu       $v0, $v0, 0x6678
    ctx->r2 = ADD32(ctx->r2, 0X6678);
    // 0x80021A54: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80021A58: addiu       $v1, $zero, 0x140
    ctx->r3 = ADD32(0, 0X140);
    // 0x80021A5C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80021A60: mflo        $t8
    ctx->r24 = lo;
    // 0x80021A64: nop

    // 0x80021A68: nop

    // 0x80021A6C: divu        $zero, $t8, $t1
    lo = S32(U32(ctx->r24) / U32(ctx->r9)); hi = S32(U32(ctx->r24) % U32(ctx->r9));
    // 0x80021A70: mflo        $t9
    ctx->r25 = lo;
    // 0x80021A74: andi        $t2, $t9, 0x3FF
    ctx->r10 = ctx->r25 & 0X3FF;
    // 0x80021A78: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80021A7C: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021A80: bne         $t1, $zero, L_80021A8C
    if (ctx->r9 != 0) {
        // 0x80021A84: nop
    
            goto L_80021A8C;
    }
    // 0x80021A84: nop

    // 0x80021A88: break       7
    do_break(2147621512);
L_80021A8C:
    // 0x80021A8C: mflo        $t5
    ctx->r13 = lo;
    // 0x80021A90: nop

    // 0x80021A94: nop

    // 0x80021A98: divu        $zero, $t5, $v1
    lo = S32(U32(ctx->r13) / U32(ctx->r3)); hi = S32(U32(ctx->r13) % U32(ctx->r3));
    // 0x80021A9C: mflo        $t6
    ctx->r14 = lo;
    // 0x80021AA0: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x80021AA4: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80021AA8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80021AAC: or          $t2, $t9, $t3
    ctx->r10 = ctx->r25 | ctx->r11;
    // 0x80021AB0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80021AB4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80021AB8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80021ABC: bne         $v1, $zero, L_80021AC8
    if (ctx->r3 != 0) {
        // 0x80021AC0: nop
    
            goto L_80021AC8;
    }
    // 0x80021AC0: nop

    // 0x80021AC4: break       7
    do_break(2147621572);
L_80021AC8:
    // 0x80021AC8: multu       $t4, $a1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021ACC: mflo        $t5
    ctx->r13 = lo;
    // 0x80021AD0: nop

    // 0x80021AD4: nop

    // 0x80021AD8: divu        $zero, $t5, $v1
    lo = S32(U32(ctx->r13) / U32(ctx->r3)); hi = S32(U32(ctx->r13) % U32(ctx->r3));
    // 0x80021ADC: mflo        $t6
    ctx->r14 = lo;
    // 0x80021AE0: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x80021AE4: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80021AE8: multu       $a2, $t9
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021AEC: bne         $v1, $zero, L_80021AF8
    if (ctx->r3 != 0) {
        // 0x80021AF0: nop
    
            goto L_80021AF8;
    }
    // 0x80021AF0: nop

    // 0x80021AF4: break       7
    do_break(2147621620);
L_80021AF8:
    // 0x80021AF8: mflo        $t3
    ctx->r11 = lo;
    // 0x80021AFC: nop

    // 0x80021B00: nop

    // 0x80021B04: divu        $zero, $t3, $t1
    lo = S32(U32(ctx->r11) / U32(ctx->r9)); hi = S32(U32(ctx->r11) % U32(ctx->r9));
    // 0x80021B08: mflo        $t2
    ctx->r10 = lo;
    // 0x80021B0C: andi        $t4, $t2, 0x3FF
    ctx->r12 = ctx->r10 & 0X3FF;
    // 0x80021B10: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80021B14: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80021B18: bne         $t1, $zero, L_80021B24
    if (ctx->r9 != 0) {
        // 0x80021B1C: nop
    
            goto L_80021B24;
    }
    // 0x80021B1C: nop

    // 0x80021B20: break       7
    do_break(2147621664);
L_80021B24:
    // 0x80021B24: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80021B28: jr          $ra
    // 0x80021B2C: nop

    return;
    // 0x80021B2C: nop

;}
RECOMP_FUNC void ifCommonPlayerStockSingleProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FF24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FF28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FF2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8010FF30: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010FF34: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8010FF38: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8010FF3C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8010FF40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010FF44: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8010FF48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010FF4C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8010FF50: lb          $v1, 0x2B($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X2B);
    // 0x8010FF54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010FF58: beql        $v1, $at, L_8010FF6C
    if (ctx->r3 == ctx->r1) {
        // 0x8010FF5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010FF6C;
    }
    goto skip_0;
    // 0x8010FF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010FF60: jal         0x800CCF00
    // 0x8010FF64: nop

    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_0;
    // 0x8010FF64: nop

    after_0:
    // 0x8010FF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010FF6C:
    // 0x8010FF6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FF70: jr          $ra
    // 0x8010FF74: nop

    return;
    // 0x8010FF74: nop

;}
RECOMP_FUNC void ftBossGootsubusuUpProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159B00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159B08: jal         0x800D9414
    // 0x80159B0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_0;
    // 0x80159B0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80159B10: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80159B14: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80159B18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80159B1C: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x80159B20: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80159B24: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80159B28: swc1        $f8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f8.u32l;
    // 0x80159B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159B34: jr          $ra
    // 0x80159B38: nop

    return;
    // 0x80159B38: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiUpdateModelPitchScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152AA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152AA8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152AAC: lwc1        $f12, 0x48($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80152AB0: lwc1        $f14, 0x4C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80152AB4: jal         0x8001863C
    // 0x80152AB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x80152AB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80152ABC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80152AC0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152AC4: lwc1        $f2, -0x3AB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3AB0);
    // 0x80152AC8: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80152ACC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152AD0: lwc1        $f10, -0x3AAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3AAC);
    // 0x80152AD4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80152AD8: lw          $t7, 0x8F8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8F8);
    // 0x80152ADC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152AE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80152AE4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80152AE8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80152AEC: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x80152AF0: lw          $t8, 0x8F8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8F8);
    // 0x80152AF4: swc1        $f2, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f2.u32l;
    // 0x80152AF8: lw          $t9, 0x8F8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8F8);
    // 0x80152AFC: swc1        $f2, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f2.u32l;
    // 0x80152B00: lwc1        $f18, -0x3AA8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3AA8);
    // 0x80152B04: lw          $t0, 0x8F8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8F8);
    // 0x80152B08: swc1        $f18, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f18.u32l;
    // 0x80152B0C: jal         0x800EB528
    // 0x80152B10: lw          $a0, 0x8F8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8F8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_1;
    // 0x80152B10: lw          $a0, 0x8F8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8F8);
    after_1:
    // 0x80152B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152B1C: jr          $ra
    // 0x80152B20: nop

    return;
    // 0x80152B20: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeTimeSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133804: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80133808: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8013380C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80133810: lw          $a0, -0x7090($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7090);
    // 0x80133814: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80133818: beq         $a0, $zero, L_80133828
    if (ctx->r4 == 0) {
        // 0x8013381C: nop
    
            goto L_80133828;
    }
    // 0x8013381C: nop

    // 0x80133820: jal         0x80009A84
    // 0x80133824: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80133824: nop

    after_0:
L_80133828:
    // 0x80133828: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013382C: lw          $t9, -0x6960($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6960);
    // 0x80133830: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80133834: addiu       $t0, $t0, 0x48B0
    ctx->r8 = ADD32(ctx->r8, 0X48B0);
    // 0x80133838: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013383C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133840: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x80133844: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80133848: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8013384C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133850: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133854: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80133858: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8013385C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80133860: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80133864: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80133868: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013386C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133870: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80133874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013387C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80133880: jal         0x800CD050
    // 0x80133884: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_1;
    // 0x80133884: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_1:
    // 0x80133888: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013388C: sw          $v0, -0x7090($at)
    MEM_W(-0X7090, ctx->r1) = ctx->r2;
    // 0x80133890: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80133894: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133898: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x8013389C: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x801338A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801338A4: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x801338A8: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x801338AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801338B0: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
    // 0x801338B4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801338B8: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x801338BC: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x801338C0: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x801338C4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801338C8: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x801338CC: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801338D0: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x801338D4: jal         0x80133680
    // 0x801338D8: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    mnPlayers1PGameMakeTimeSetting(rdram, ctx);
        goto after_2;
    // 0x801338D8: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    after_2:
    // 0x801338DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801338E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801338E4: jr          $ra
    // 0x801338E8: nop

    return;
    // 0x801338E8: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftKirbyCopyLinkSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80164824: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80164828: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016482C: jal         0x800DEEC8
    // 0x80164830: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80164830: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80164834: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80164838: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8016483C: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    // 0x80164840: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80164844: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80164848: jal         0x800E6F24
    // 0x8016484C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8016484C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80164850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80164854: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80164858: jr          $ra
    // 0x8016485C: nop

    return;
    // 0x8016485C: nop

;}
RECOMP_FUNC void syMallocInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006D54: addu        $t6, $a2, $a3
    ctx->r14 = ADD32(ctx->r6, ctx->r7);
    // 0x80006D58: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80006D5C: sw          $a2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r6;
    // 0x80006D60: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80006D64: jr          $ra
    // 0x80006D68: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    return;
    // 0x80006D68: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void ftCommonAttackLw4CheckInterruptMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801507D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801507D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801507D8: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x801507DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801507E0: jal         0x80146A8C
    // 0x801507E4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_0;
    // 0x801507E4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801507E8: beq         $v0, $zero, L_80150804
    if (ctx->r2 == 0) {
        // 0x801507EC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80150804;
    }
    // 0x801507EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801507F0: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x801507F4: jal         0x80146690
    // 0x801507F8: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x801507F8: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    after_1:
    // 0x801507FC: b           L_80150828
    // 0x80150800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150828;
    // 0x80150800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150804:
    // 0x80150804: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80150808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8015080C: lb          $t9, 0x101($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X101);
    // 0x80150810: bgez        $t9, L_80150828
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80150814: nop
    
            goto L_80150828;
    }
    // 0x80150814: nop

    // 0x80150818: jal         0x80150760
    // 0x8015081C: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    ftCommonAttackLw4SetStatus(rdram, ctx);
        goto after_2;
    // 0x8015081C: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    after_2:
    // 0x80150820: b           L_80150828
    // 0x80150824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150828;
    // 0x80150824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150828:
    // 0x80150828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015082C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80150830: jr          $ra
    // 0x80150834: nop

    return;
    // 0x80150834: nop

;}
RECOMP_FUNC void ftCommonTurnRunProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F178: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013F17C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013F180: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8013F184: beq         $t6, $zero, L_8013F1A8
    if (ctx->r14 == 0) {
        // 0x8013F188: nop
    
            goto L_8013F1A8;
    }
    // 0x8013F188: nop

    // 0x8013F18C: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8013F190: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8013F194: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8013F198: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8013F19C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8013F1A0: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x8013F1A4: swc1        $f6, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f6.u32l;
L_8013F1A8:
    // 0x8013F1A8: jal         0x800D9480
    // 0x8013F1AC: addiu       $a1, $a1, -0x1118
    ctx->r5 = ADD32(ctx->r5, -0X1118);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013F1AC: addiu       $a1, $a1, -0x1118
    ctx->r5 = ADD32(ctx->r5, -0X1118);
    after_0:
    // 0x8013F1B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F1B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F1B8: jr          $ra
    // 0x8013F1BC: nop

    return;
    // 0x8013F1BC: nop

;}
RECOMP_FUNC void ftSamusSpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DC40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015DC44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015DC48: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015DC4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015DC50: lui         $a1, 0x3F28
    ctx->r5 = S32(0X3F28 << 16);
    // 0x8015DC54: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x8015DC58: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015DC5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8015DC60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8015DC64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8015DC68: bc1f        L_8015DC84
    if (!c1cs) {
        // 0x8015DC6C: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8015DC84;
    }
    // 0x8015DC6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015DC70: lwc1        $f8, -0x3730($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3730);
    // 0x8015DC74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015DC78: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8015DC7C: jal         0x801438F0
    // 0x8015DC80: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015DC80: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
L_8015DC84:
    // 0x8015DC84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015DC88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015DC8C: jr          $ra
    // 0x8015DC90: nop

    return;
    // 0x8015DC90: nop

;}
RECOMP_FUNC void func_80017D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80017D40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80017D44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017D48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80017D4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80017D50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80017D54: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x80017D58: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80017D5C: jal         0x8001663C
    // 0x80017D60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001663C(rdram, ctx);
        goto after_0;
    // 0x80017D60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80017D64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80017D68: jal         0x80016EDC
    // 0x80017D6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gcPrepCameraMatrix(rdram, ctx);
        goto after_1;
    // 0x80017D6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80017D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80017D74: jal         0x8001783C
    // 0x80017D78: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    gcRunFuncCamera(rdram, ctx);
        goto after_2;
    // 0x80017D78: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80017D7C: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
    // 0x80017D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017D84: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80017D88: beq         $t8, $zero, L_80017D98
    if (ctx->r24 == 0) {
        // 0x80017D8C: nop
    
            goto L_80017D98;
    }
    // 0x80017D8C: nop

    // 0x80017D90: b           L_80017D98
    // 0x80017D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80017D98;
    // 0x80017D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80017D98:
    // 0x80017D98: jal         0x80017B80
    // 0x80017D9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcCaptureCameraGObj(rdram, ctx);
        goto after_3;
    // 0x80017D9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80017DA0: jal         0x80017CC8
    // 0x80017DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80017CC8(rdram, ctx);
        goto after_4;
    // 0x80017DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80017DA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80017DAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017DB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017DB4: jr          $ra
    // 0x80017DB8: nop

    return;
    // 0x80017DB8: nop

;}
RECOMP_FUNC void mnBackupClearFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x2EC8
    ctx->r24 = ADD32(ctx->r24, 0X2EC8);
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
RECOMP_FUNC void func_ovl51_8018D160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D160: jr          $ra
    // 0x8018D164: nop

    return;
    // 0x8018D164: nop

;}
RECOMP_FUNC void ftMarioSpecialAirLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80156784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156788: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8015678C: jal         0x800DE6E4
    // 0x80156790: addiu       $a1, $a1, 0x67B0
    ctx->r5 = ADD32(ctx->r5, 0X67B0);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80156790: addiu       $a1, $a1, 0x67B0
    ctx->r5 = ADD32(ctx->r5, 0X67B0);
    after_0:
    // 0x80156794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80156798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015679C: jr          $ra
    // 0x801567A0: nop

    return;
    // 0x801567A0: nop

;}
RECOMP_FUNC void gcPrepCameraMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016EDC: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80016EE0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80016EE4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80016EE8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80016EEC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80016EF0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80016EF4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80016EF8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80016EFC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80016F00: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80016F04: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80016F08: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80016F0C: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80016F10: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80016F14: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80016F18: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x80016F1C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80016F20: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80016F24: lw          $a2, 0x60($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X60);
    // 0x80016F28: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80016F2C: beql        $a2, $zero, L_800177FC
    if (ctx->r6 == 0) {
        // 0x80016F30: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_800177FC;
    }
    goto skip_0;
    // 0x80016F30: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x80016F34: blez        $a2, L_8001750C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80016F38: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8001750C;
    }
    // 0x80016F38: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80016F3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016F40: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80016F44: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80016F48: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80016F4C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80016F50: addiu       $s5, $s5, 0x65D8
    ctx->r21 = ADD32(ctx->r21, 0X65D8);
    // 0x80016F54: addiu       $s7, $s7, 0x6FA0
    ctx->r23 = ADD32(ctx->r23, 0X6FA0);
    // 0x80016F58: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80016F5C: lw          $s4, 0xC4($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC4);
L_80016F60:
    // 0x80016F60: lw          $s1, 0x64($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X64);
    // 0x80016F64: beql        $s1, $zero, L_800174FC
    if (ctx->r17 == 0) {
        // 0x80016F68: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_800174FC;
    }
    goto skip_1;
    // 0x80016F68: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    skip_1:
    // 0x80016F6C: lbu         $t8, 0x5($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X5);
    // 0x80016F70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80016F74: addiu       $s2, $s1, 0x8
    ctx->r18 = ADD32(ctx->r17, 0X8);
    // 0x80016F78: beq         $t8, $at, L_80017360
    if (ctx->r24 == ctx->r1) {
        // 0x80016F7C: lui         $t9, 0x8004
        ctx->r25 = S32(0X8004 << 16);
            goto L_80017360;
    }
    // 0x80016F7C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80016F80: lw          $t9, 0x6630($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6630);
    // 0x80016F84: blezl       $t9, L_80016F9C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80016F88: lbu         $v1, 0x4($s1)
        ctx->r3 = MEM_BU(ctx->r17, 0X4);
            goto L_80016F9C;
    }
    goto skip_2;
    // 0x80016F88: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
    skip_2:
    // 0x80016F8C: lw          $s2, 0xC($s5)
    ctx->r18 = MEM_W(ctx->r21, 0XC);
    // 0x80016F90: addiu       $t0, $s2, 0x40
    ctx->r8 = ADD32(ctx->r18, 0X40);
    // 0x80016F94: sw          $t0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r8;
    // 0x80016F98: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
L_80016F9C:
    // 0x80016F9C: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80016FA0: sltiu       $at, $t1, 0x11
    ctx->r1 = ctx->r9 < 0X11 ? 1 : 0;
    // 0x80016FA4: beq         $at, $zero, L_8001730C
    if (ctx->r1 == 0) {
        // 0x80016FA8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8001730C;
    }
    // 0x80016FA8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80016FAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80016FB0: addu        $at, $at, $t1
    gpr jr_addend_80016FB8 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80016FB4: lw          $t1, -0x1D60($at)
    ctx->r9 = ADD32(ctx->r1, -0X1D60);
    // 0x80016FB8: jr          $t1
    // 0x80016FBC: nop

    switch (jr_addend_80016FB8 >> 2) {
        case 0: goto L_80016FC0; break;
        case 1: goto L_80016FC8; break;
        case 2: goto L_80016FD0; break;
        case 3: goto L_8001701C; break;
        case 4: goto L_80017068; break;
        case 5: goto L_800170A8; break;
        case 6: goto L_800170A8; break;
        case 7: goto L_80017118; break;
        case 8: goto L_80017118; break;
        case 9: goto L_80017164; break;
        case 10: goto L_80017164; break;
        case 11: goto L_800171B0; break;
        case 12: goto L_800171B0; break;
        case 13: goto L_8001723C; break;
        case 14: goto L_8001723C; break;
        case 15: goto L_800172A4; break;
        case 16: goto L_800172A4; break;
        default: switch_error(__func__, 0x80016FB8, 0x8003E2A0);
    }
    // 0x80016FBC: nop

L_80016FC0:
    // 0x80016FC0: b           L_80017348
    // 0x80016FC4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x80016FC4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_80016FC8:
    // 0x80016FC8: b           L_80017348
    // 0x80016FCC: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x80016FCC: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_80016FD0:
    // 0x80016FD0: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80016FD4: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x80016FD8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x80016FDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80016FE0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80016FE4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80016FE8: addiu       $a0, $a0, 0x6FA8
    ctx->r4 = ADD32(ctx->r4, 0X6FA8);
    // 0x80016FEC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80016FF0: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80016FF4: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x80016FF8: jal         0x8001B248
    // 0x80016FFC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixPerspFastF(rdram, ctx);
        goto after_0;
    // 0x80016FFC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80017000: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80017004: addiu       $a0, $a0, 0x6FA8
    ctx->r4 = ADD32(ctx->r4, 0X6FA8);
    // 0x80017008: jal         0x80019C70
    // 0x8001700C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8001700C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80017010: sw          $s2, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r18;
    // 0x80017014: b           L_80017348
    // 0x80017018: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x80017018: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_8001701C:
    // 0x8001701C: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80017020: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x80017024: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x80017028: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8001702C: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80017030: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80017034: addiu       $a0, $a0, 0x6FA8
    ctx->r4 = ADD32(ctx->r4, 0X6FA8);
    // 0x80017038: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8001703C: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80017040: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x80017044: jal         0x8001B4CC
    // 0x80017048: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    syMatrixPerspF(rdram, ctx);
        goto after_2;
    // 0x80017048: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8001704C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80017050: addiu       $a0, $a0, 0x6FA8
    ctx->r4 = ADD32(ctx->r4, 0X6FA8);
    // 0x80017054: jal         0x80019C70
    // 0x80017058: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    syMatrixF2L(rdram, ctx);
        goto after_3;
    // 0x80017058: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x8001705C: sw          $s2, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r18;
    // 0x80017060: b           L_80017348
    // 0x80017064: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x80017064: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_80017068:
    // 0x80017068: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8001706C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80017070: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x80017074: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x80017078: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001707C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80017080: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80017084: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80017088: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8001708C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80017090: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80017094: jal         0x8001B1E4
    // 0x80017098: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    syMatrixOrtho(rdram, ctx);
        goto after_4;
    // 0x80017098: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8001709C: sw          $s2, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r18;
    // 0x800170A0: b           L_80017348
    // 0x800170A4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x800170A4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_800170A8:
    // 0x800170A8: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800170AC: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x800170B0: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800170B4: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x800170B8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800170BC: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800170C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800170C4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800170C8: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800170CC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800170D0: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800170D4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800170D8: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800170DC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800170E0: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x800170E4: jal         0x8001A37C
    // 0x800170E8: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    syMatrixLookAt(rdram, ctx);
        goto after_5;
    // 0x800170E8: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x800170EC: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x800170F0: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800170F4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800170F8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800170FC: nop

    // 0x80017100: bc1f        L_80017110
    if (!c1cs) {
        // 0x80017104: nop
    
            goto L_80017110;
    }
    // 0x80017104: nop

    // 0x80017108: b           L_80017110
    // 0x8001710C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80017110;
    // 0x8001710C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80017110:
    // 0x80017110: b           L_80017348
    // 0x80017114: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x80017114: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_80017118:
    // 0x80017118: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8001711C: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x80017120: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80017124: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x80017128: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001712C: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80017130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80017134: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80017138: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001713C: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80017140: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80017144: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80017148: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x8001714C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80017150: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x80017154: jal         0x8001A6C8
    // 0x80017158: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    syMatrixModLookAt(rdram, ctx);
        goto after_6;
    // 0x80017158: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8001715C: b           L_80017348
    // 0x80017160: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x80017160: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_80017164:
    // 0x80017164: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80017168: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x8001716C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80017170: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x80017174: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80017178: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8001717C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80017180: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80017184: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80017188: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8001718C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80017190: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80017194: swc1        $f22, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f22.u32l;
    // 0x80017198: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8001719C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800171A0: jal         0x8001A6C8
    // 0x800171A4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    syMatrixModLookAt(rdram, ctx);
        goto after_7;
    // 0x800171A4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x800171A8: b           L_80017348
    // 0x800171AC: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x800171AC: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_800171B0:
    // 0x800171B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800171B4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800171B8: jal         0x80006CEC
    // 0x800171BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    syMallocSet(rdram, ctx);
        goto after_8;
    // 0x800171BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_8:
    // 0x800171C0: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800171C4: lw          $a2, 0x3C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X3C);
    // 0x800171C8: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x800171CC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800171D0: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800171D4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800171D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800171DC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800171E0: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800171E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800171E8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800171EC: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800171F0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800171F4: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800171F8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800171FC: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80017200: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80017204: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80017208: jal         0x8001AB2C
    // 0x8001720C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    syMatrixLookAtReflect(rdram, ctx);
        goto after_9;
    // 0x8001720C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x80017210: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80017214: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80017218: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x8001721C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80017220: nop

    // 0x80017224: bc1f        L_80017234
    if (!c1cs) {
        // 0x80017228: nop
    
            goto L_80017234;
    }
    // 0x80017228: nop

    // 0x8001722C: b           L_80017234
    // 0x80017230: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80017234;
    // 0x80017230: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80017234:
    // 0x80017234: b           L_80017348
    // 0x80017238: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x80017238: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_8001723C:
    // 0x8001723C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80017240: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80017244: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80017248: jal         0x80006CEC
    // 0x8001724C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    syMallocSet(rdram, ctx);
        goto after_10;
    // 0x8001724C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_10:
    // 0x80017250: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80017254: lw          $a2, 0x3C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X3C);
    // 0x80017258: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x8001725C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80017260: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80017264: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80017268: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8001726C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80017270: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80017274: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80017278: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8001727C: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80017280: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80017284: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80017288: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8001728C: swc1        $f22, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f22.u32l;
    // 0x80017290: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80017294: jal         0x8001AFD0
    // 0x80017298: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    syMatrixModLookAtReflect(rdram, ctx);
        goto after_11;
    // 0x80017298: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x8001729C: b           L_80017348
    // 0x800172A0: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x800172A0: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_800172A4:
    // 0x800172A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800172A8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800172AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800172B0: jal         0x80006CEC
    // 0x800172B4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    syMallocSet(rdram, ctx);
        goto after_12;
    // 0x800172B4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    after_12:
    // 0x800172B8: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800172BC: lw          $a2, 0x3C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X3C);
    // 0x800172C0: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x800172C4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800172C8: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800172CC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800172D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800172D4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800172D8: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800172DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800172E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800172E4: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800172E8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800172EC: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800172F0: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800172F4: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x800172F8: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800172FC: jal         0x8001AFD0
    // 0x80017300: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    syMatrixModLookAtReflect(rdram, ctx);
        goto after_13;
    // 0x80017300: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x80017304: b           L_80017348
    // 0x80017308: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
        goto L_80017348;
    // 0x80017308: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_8001730C:
    // 0x8001730C: slti        $at, $v1, 0x42
    ctx->r1 = SIGNED(ctx->r3) < 0X42 ? 1 : 0;
    // 0x80017310: bne         $at, $zero, L_80017344
    if (ctx->r1 != 0) {
        // 0x80017314: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80017344;
    }
    // 0x80017314: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80017318: lw          $v0, 0x70AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X70AC);
    // 0x8001731C: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x80017320: beq         $v0, $zero, L_80017344
    if (ctx->r2 == 0) {
        // 0x80017324: addu        $t3, $v0, $t2
        ctx->r11 = ADD32(ctx->r2, ctx->r10);
            goto L_80017344;
    }
    // 0x80017324: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80017328: lw          $a3, -0x210($t3)
    ctx->r7 = MEM_W(ctx->r11, -0X210);
    // 0x8001732C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80017330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80017334: beql        $a3, $zero, L_80017348
    if (ctx->r7 == 0) {
        // 0x80017338: lbu         $v0, 0x5($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X5);
            goto L_80017348;
    }
    goto skip_3;
    // 0x80017338: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    skip_3:
    // 0x8001733C: jalr        $a3
    // 0x80017340: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    LOOKUP_FUNC(ctx->r7)(rdram, ctx);
        goto after_14;
    // 0x80017340: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    after_14:
L_80017344:
    // 0x80017344: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_80017348:
    // 0x80017348: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001734C: bne         $v0, $at, L_80017360
    if (ctx->r2 != ctx->r1) {
        // 0x80017350: addiu       $t4, $s1, 0x8
        ctx->r12 = ADD32(ctx->r17, 0X8);
            goto L_80017360;
    }
    // 0x80017350: addiu       $t4, $s1, 0x8
    ctx->r12 = ADD32(ctx->r17, 0X8);
    // 0x80017354: bne         $t4, $s2, L_80017360
    if (ctx->r12 != ctx->r18) {
        // 0x80017358: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_80017360;
    }
    // 0x80017358: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8001735C: sb          $t5, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r13;
L_80017360:
    // 0x80017360: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
    // 0x80017364: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80017368: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x8001736C: beq         $at, $zero, L_800174BC
    if (ctx->r1 == 0) {
        // 0x80017370: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800174BC;
    }
    // 0x80017370: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80017374: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017378: addu        $at, $at, $t6
    gpr jr_addend_80017380 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8001737C: lw          $t6, -0x1D1C($at)
    ctx->r14 = ADD32(ctx->r1, -0X1D1C);
    // 0x80017380: jr          $t6
    // 0x80017384: nop

    switch (jr_addend_80017380 >> 2) {
        case 0: goto L_80017388; break;
        case 1: goto L_80017390; break;
        case 2: goto L_80017398; break;
        case 3: goto L_80017398; break;
        case 4: goto L_800173D8; break;
        case 5: goto L_80017438; break;
        case 6: goto L_80017498; break;
        case 7: goto L_80017438; break;
        case 8: goto L_80017498; break;
        case 9: goto L_80017438; break;
        case 10: goto L_80017498; break;
        case 11: goto L_800173FC; break;
        case 12: goto L_8001745C; break;
        case 13: goto L_800173FC; break;
        case 14: goto L_8001745C; break;
        case 15: goto L_800173FC; break;
        case 16: goto L_8001745C; break;
        default: switch_error(__func__, 0x80017380, 0x8003E2E4);
    }
    // 0x80017384: nop

L_80017388:
    // 0x80017388: b           L_800174F8
    // 0x8001738C: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
        goto L_800174F8;
    // 0x8001738C: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
L_80017390:
    // 0x80017390: b           L_800174F8
    // 0x80017394: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
        goto L_800174F8;
    // 0x80017394: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
L_80017398:
    // 0x80017398: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x8001739C: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800173A0: ori         $t9, $t9, 0x7
    ctx->r25 = ctx->r25 | 0X7;
    // 0x800173A4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800173A8: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x800173AC: sw          $s2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r18;
    // 0x800173B0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800173B4: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800173B8: lui         $t2, 0xDB0E
    ctx->r10 = S32(0XDB0E << 16);
    // 0x800173BC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800173C0: sw          $t1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r9;
    // 0x800173C4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800173C8: lhu         $t3, 0x1C($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X1C);
    // 0x800173CC: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x800173D0: b           L_800174F8
    // 0x800173D4: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
        goto L_800174F8;
    // 0x800173D4: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
L_800173D8:
    // 0x800173D8: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x800173DC: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x800173E0: ori         $t6, $t6, 0x7
    ctx->r14 = ctx->r14 | 0X7;
    // 0x800173E4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800173E8: sw          $t5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r13;
    // 0x800173EC: sw          $s2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r18;
    // 0x800173F0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800173F4: b           L_800174F8
    // 0x800173F8: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
        goto L_800174F8;
    // 0x800173F8: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
L_800173FC:
    // 0x800173FC: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80017400: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x80017404: ori         $t9, $t9, 0xA
    ctx->r25 = ctx->r25 | 0XA;
    // 0x80017408: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8001740C: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x80017410: sw          $s4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r20;
    // 0x80017414: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80017418: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x8001741C: lui         $t2, 0xDC08
    ctx->r10 = S32(0XDC08 << 16);
    // 0x80017420: ori         $t2, $t2, 0x30A
    ctx->r10 = ctx->r10 | 0X30A;
    // 0x80017424: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80017428: sw          $t1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r9;
    // 0x8001742C: addiu       $t3, $s4, 0x10
    ctx->r11 = ADD32(ctx->r20, 0X10);
    // 0x80017430: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80017434: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_80017438:
    // 0x80017438: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x8001743C: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x80017440: ori         $t6, $t6, 0x5
    ctx->r14 = ctx->r14 | 0X5;
    // 0x80017444: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80017448: sw          $t5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r13;
    // 0x8001744C: sw          $s2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r18;
    // 0x80017450: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80017454: b           L_800174F8
    // 0x80017458: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
        goto L_800174F8;
    // 0x80017458: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
L_8001745C:
    // 0x8001745C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80017460: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x80017464: ori         $t9, $t9, 0xA
    ctx->r25 = ctx->r25 | 0XA;
    // 0x80017468: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8001746C: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x80017470: sw          $s4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r20;
    // 0x80017474: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80017478: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x8001747C: lui         $t2, 0xDC08
    ctx->r10 = S32(0XDC08 << 16);
    // 0x80017480: ori         $t2, $t2, 0x30A
    ctx->r10 = ctx->r10 | 0X30A;
    // 0x80017484: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80017488: sw          $t1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r9;
    // 0x8001748C: addiu       $t3, $s4, 0x10
    ctx->r11 = ADD32(ctx->r20, 0X10);
    // 0x80017490: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80017494: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_80017498:
    // 0x80017498: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x8001749C: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x800174A0: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x800174A4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800174A8: sw          $t5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r13;
    // 0x800174AC: sw          $s2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r18;
    // 0x800174B0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800174B4: b           L_800174F8
    // 0x800174B8: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
        goto L_800174F8;
    // 0x800174B8: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
L_800174BC:
    // 0x800174BC: slti        $at, $v1, 0x42
    ctx->r1 = SIGNED(ctx->r3) < 0X42 ? 1 : 0;
    // 0x800174C0: bne         $at, $zero, L_800174F4
    if (ctx->r1 != 0) {
        // 0x800174C4: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_800174F4;
    }
    // 0x800174C4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800174C8: lw          $v0, 0x70AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X70AC);
    // 0x800174CC: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x800174D0: beq         $v0, $zero, L_800174F4
    if (ctx->r2 == 0) {
        // 0x800174D4: addu        $t8, $v0, $t7
        ctx->r24 = ADD32(ctx->r2, ctx->r15);
            goto L_800174F4;
    }
    // 0x800174D4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800174D8: lw          $a3, -0x20C($t8)
    ctx->r7 = MEM_W(ctx->r24, -0X20C);
    // 0x800174DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800174E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800174E4: beql        $a3, $zero, L_800174F8
    if (ctx->r7 == 0) {
        // 0x800174E8: lw          $a2, 0x60($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X60);
            goto L_800174F8;
    }
    goto skip_4;
    // 0x800174E8: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    skip_4:
    // 0x800174EC: jalr        $a3
    // 0x800174F0: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    LOOKUP_FUNC(ctx->r7)(rdram, ctx);
        goto after_15;
    // 0x800174F0: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    after_15:
L_800174F4:
    // 0x800174F4: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
L_800174F8:
    // 0x800174F8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_800174FC:
    // 0x800174FC: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80017500: bne         $at, $zero, L_80016F60
    if (ctx->r1 != 0) {
        // 0x80017504: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80016F60;
    }
    // 0x80017504: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80017508: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
L_8001750C:
    // 0x8001750C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80017510: lw          $t9, 0x70A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70A8);
    // 0x80017514: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017518: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8001751C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80017520: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x80017524: beq         $at, $zero, L_8001759C
    if (ctx->r1 == 0) {
        // 0x80017528: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8001759C;
    }
    // 0x80017528: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001752C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017530: addu        $at, $at, $t9
    gpr jr_addend_80017538 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80017534: lw          $t9, -0x1CD8($at)
    ctx->r25 = ADD32(ctx->r1, -0X1CD8);
    // 0x80017538: jr          $t9
    // 0x8001753C: nop

    switch (jr_addend_80017538 >> 2) {
        case 0: goto L_80017540; break;
        case 1: goto L_80017548; break;
        case 2: goto L_80017550; break;
        case 3: goto L_80017560; break;
        case 4: goto L_80017568; break;
        case 5: goto L_80017578; break;
        case 6: goto L_80017588; break;
        case 7: goto L_80017590; break;
        default: switch_error(__func__, 0x80017538, 0x8003E328);
    }
    // 0x8001753C: nop

L_80017540:
    // 0x80017540: b           L_8001759C
    // 0x80017544: sw          $s3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r19;
        goto L_8001759C;
    // 0x80017544: sw          $s3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r19;
L_80017548:
    // 0x80017548: b           L_8001759C
    // 0x8001754C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_8001759C;
    // 0x8001754C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80017550:
    // 0x80017550: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80017554: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x80017558: b           L_8001759C
    // 0x8001755C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_8001759C;
    // 0x8001755C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80017560:
    // 0x80017560: b           L_8001759C
    // 0x80017564: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_8001759C;
    // 0x80017564: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80017568:
    // 0x80017568: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001756C: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x80017570: b           L_8001759C
    // 0x80017574: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_8001759C;
    // 0x80017574: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80017578:
    // 0x80017578: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8001757C: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x80017580: b           L_8001759C
    // 0x80017584: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
        goto L_8001759C;
    // 0x80017584: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80017588:
    // 0x80017588: b           L_8001759C
    // 0x8001758C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
        goto L_8001759C;
    // 0x8001758C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80017590:
    // 0x80017590: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80017594: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x80017598: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8001759C:
    // 0x8001759C: beq         $s3, $zero, L_800176C0
    if (ctx->r19 == 0) {
        // 0x800175A0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800176C0;
    }
    // 0x800175A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800175A4: beq         $s3, $at, L_800175BC
    if (ctx->r19 == ctx->r1) {
        // 0x800175A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800175BC;
    }
    // 0x800175A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800175AC: beql        $s3, $at, L_80017604
    if (ctx->r19 == ctx->r1) {
        // 0x800175B0: lwc1        $f18, 0x4C($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
            goto L_80017604;
    }
    goto skip_5;
    // 0x800175B0: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    skip_5:
    // 0x800175B4: b           L_80017640
    // 0x800175B8: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
        goto L_80017640;
    // 0x800175B8: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
L_800175BC:
    // 0x800175BC: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800175C0: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800175C4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800175C8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800175CC: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800175D0: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800175D4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800175D8: nop

    // 0x800175DC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800175E0: jal         0x80033510
    // 0x800175E4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_16;
    // 0x800175E4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_16:
    // 0x800175E8: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800175EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800175F0: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x800175F4: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800175F8: b           L_80017640
    // 0x800175FC: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
        goto L_80017640;
    // 0x800175FC: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x80017600: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
L_80017604:
    // 0x80017604: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80017608: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8001760C: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80017610: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80017614: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80017618: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001761C: nop

    // 0x80017620: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80017624: jal         0x80033510
    // 0x80017628: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_17;
    // 0x80017628: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_17:
    // 0x8001762C: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80017630: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80017634: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x80017638: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8001763C: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
L_80017640:
    // 0x80017640: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017644: lwc1        $f6, -0x1CB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1CB8);
    // 0x80017648: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8001764C: addiu       $s1, $s1, 0x7028
    ctx->r17 = ADD32(ctx->r17, 0X7028);
    // 0x80017650: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80017654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017658: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x8001765C: bc1fl       L_80017688
    if (!c1cs) {
        // 0x80017660: lwc1        $f8, 0x94($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
            goto L_80017688;
    }
    goto skip_6;
    // 0x80017660: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    skip_6:
    // 0x80017664: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80017668: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8001766C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80017670: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80017674: jal         0x8001B6EC
    // 0x80017678: addiu       $a0, $s1, 0x7028
    ctx->r4 = ADD32(ctx->r17, 0X7028);
    syMatrixScaF(rdram, ctx);
        goto after_18;
    // 0x80017678: addiu       $a0, $s1, 0x7028
    ctx->r4 = ADD32(ctx->r17, 0X7028);
    after_18:
    // 0x8001767C: b           L_800176C4
    // 0x80017680: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
        goto L_800176C4;
    // 0x80017680: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80017684: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
L_80017688:
    // 0x80017688: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8001768C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80017690: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80017694: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80017698: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8001769C: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    // 0x800176A0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800176A4: jal         0x8001A0F0
    // 0x800176A8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    syMatrixLookAtF(rdram, ctx);
        goto after_19;
    // 0x800176A8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_19:
    // 0x800176AC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800176B0: addiu       $a1, $a1, 0x6FA8
    ctx->r5 = ADD32(ctx->r5, 0X6FA8);
    // 0x800176B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800176B8: jal         0x80034980
    // 0x800176BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    guMtxCatF(rdram, ctx);
        goto after_20;
    // 0x800176BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_20:
L_800176C0:
    // 0x800176C0: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
L_800176C4:
    // 0x800176C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800176C8: beql        $t4, $zero, L_800177F0
    if (ctx->r12 == 0) {
        // 0x800176CC: lw          $t5, 0xDC($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XDC);
            goto L_800177F0;
    }
    goto skip_7;
    // 0x800176CC: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    skip_7:
    // 0x800176D0: beq         $t4, $at, L_800176E8
    if (ctx->r12 == ctx->r1) {
        // 0x800176D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800176E8;
    }
    // 0x800176D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800176D8: beql        $t4, $at, L_80017730
    if (ctx->r12 == ctx->r1) {
        // 0x800176DC: lwc1        $f18, 0x50($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
            goto L_80017730;
    }
    goto skip_8;
    // 0x800176DC: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    skip_8:
    // 0x800176E0: b           L_8001776C
    // 0x800176E4: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
        goto L_8001776C;
    // 0x800176E4: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
L_800176E8:
    // 0x800176E8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800176EC: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800176F0: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800176F4: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800176F8: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800176FC: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80017700: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80017704: nop

    // 0x80017708: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001770C: jal         0x80033510
    // 0x80017710: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_21;
    // 0x80017710: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_21:
    // 0x80017714: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80017718: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001771C: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x80017720: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80017724: b           L_8001776C
    // 0x80017728: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
        goto L_8001776C;
    // 0x80017728: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
    // 0x8001772C: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
L_80017730:
    // 0x80017730: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80017734: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80017738: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8001773C: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80017740: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80017744: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80017748: nop

    // 0x8001774C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80017750: jal         0x80033510
    // 0x80017754: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_22;
    // 0x80017754: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_22:
    // 0x80017758: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001775C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80017760: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
    // 0x80017764: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80017768: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
L_8001776C:
    // 0x8001776C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017770: lwc1        $f6, -0x1CB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1CB4);
    // 0x80017774: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80017778: addiu       $s0, $s0, 0x7068
    ctx->r16 = ADD32(ctx->r16, 0X7068);
    // 0x8001777C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80017780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80017784: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80017788: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001778C: bc1fl       L_800177B8
    if (!c1cs) {
        // 0x80017790: mfc1        $a2, $f20
        ctx->r6 = (int32_t)ctx->f20.u32l;
            goto L_800177B8;
    }
    goto skip_9;
    // 0x80017790: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    skip_9:
    // 0x80017794: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80017798: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8001779C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800177A0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800177A4: jal         0x8001B6EC
    // 0x800177A8: addiu       $a0, $s0, 0x7068
    ctx->r4 = ADD32(ctx->r16, 0X7068);
    syMatrixScaF(rdram, ctx);
        goto after_23;
    // 0x800177A8: addiu       $a0, $s0, 0x7068
    ctx->r4 = ADD32(ctx->r16, 0X7068);
    after_23:
    // 0x800177AC: b           L_800177F0
    // 0x800177B0: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
        goto L_800177F0;
    // 0x800177B0: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    // 0x800177B4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_800177B8:
    // 0x800177B8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800177BC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800177C0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800177C4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800177C8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800177CC: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    // 0x800177D0: jal         0x8001A0F0
    // 0x800177D4: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    syMatrixLookAtF(rdram, ctx);
        goto after_24;
    // 0x800177D4: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    after_24:
    // 0x800177D8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800177DC: addiu       $a1, $a1, 0x6FA8
    ctx->r5 = ADD32(ctx->r5, 0X6FA8);
    // 0x800177E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800177E4: jal         0x80034980
    // 0x800177E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    guMtxCatF(rdram, ctx);
        goto after_25;
    // 0x800177E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_25:
    // 0x800177EC: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
L_800177F0:
    // 0x800177F0: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x800177F4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800177F8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_800177FC:
    // 0x800177FC: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80017800: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80017804: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80017808: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8001780C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80017810: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80017814: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80017818: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8001781C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80017820: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80017824: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80017828: jr          $ra
    // 0x8001782C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8001782C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void ftLinkSpecialHiDestroyWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80163B4C: lbu         $t6, 0x260($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X260);
    // 0x80163B50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80163B54: sb          $t8, 0x2B4($a1)
    MEM_B(0X2B4, ctx->r5) = ctx->r24;
    // 0x80163B58: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80163B5C: sb          $t7, 0x260($a1)
    MEM_B(0X260, ctx->r5) = ctx->r15;
    // 0x80163B60: jal         0x8016800C
    // 0x80163B64: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    wpMainDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x80163B64: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    after_0:
    // 0x80163B68: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80163B6C: sw          $zero, 0xB18($t9)
    MEM_W(0XB18, ctx->r25) = 0;
    // 0x80163B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163B78: jr          $ra
    // 0x80163B7C: nop

    return;
    // 0x80163B7C: nop

;}
RECOMP_FUNC void ftCommonHammerTurnProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147AD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80147AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147AD8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80147ADC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80147AE0: jal         0x80147A70
    // 0x80147AE4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonHammerTurnUpdateModelYaw(rdram, ctx);
        goto after_0;
    // 0x80147AE4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80147AE8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80147AEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80147AF0: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x80147AF4: bnel        $t8, $zero, L_80147B08
    if (ctx->r24 != 0) {
        // 0x80147AF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80147B08;
    }
    goto skip_0;
    // 0x80147AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80147AFC: jal         0x800F3938
    // 0x80147B00: nop

    ftHammerSetStatusHammerWait(rdram, ctx);
        goto after_1;
    // 0x80147B00: nop

    after_1:
    // 0x80147B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80147B08:
    // 0x80147B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80147B0C: jr          $ra
    // 0x80147B10: nop

    return;
    // 0x80147B10: nop

;}
RECOMP_FUNC void func_ovl8_8038649C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038649C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803864A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803864A4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803864A8: jal         0x8037B3E4
    // 0x803864AC: lw          $a0, 0x3C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C4);
    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x803864AC: lw          $a0, 0x3C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C4);
    after_0:
    // 0x803864B0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803864B4: jal         0x8037488C
    // 0x803864B8: lw          $a0, 0x3C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C0);
    func_ovl8_8037488C(rdram, ctx);
        goto after_1;
    // 0x803864B8: lw          $a0, 0x3C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C0);
    after_1:
    // 0x803864BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803864C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803864C4: jr          $ra
    // 0x803864C8: nop

    return;
    // 0x803864C8: nop

;}
RECOMP_FUNC void ftPhysicsApplyGroundVelFriction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8BB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D8BC0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x800D8BC4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800D8BC8: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x800D8BCC: lw          $t7, 0xF4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF4);
    // 0x800D8BD0: lw          $v0, 0x9C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C8);
    // 0x800D8BD4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D8BD8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800D8BDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D8BE0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D8BE4: lwc1        $f4, -0x3B20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3B20);
    // 0x800D8BE8: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800D8BEC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800D8BF0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800D8BF4: jal         0x800D8978
    // 0x800D8BF8: nop

    ftPhysicsSetGroundVelFriction(rdram, ctx);
        goto after_0;
    // 0x800D8BF8: nop

    after_0:
    // 0x800D8BFC: jal         0x800D87D0
    // 0x800D8C00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_1;
    // 0x800D8C00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800D8C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8C0C: jr          $ra
    // 0x800D8C10: nop

    return;
    // 0x800D8C10: nop

;}
RECOMP_FUNC void mnVSResultsGetTensDigit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801346C0: bgez        $a0, L_801346F0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801346C4: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_801346F0;
    }
    // 0x801346C4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801346C8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801346CC: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x801346D0: mfhi        $v0
    ctx->r2 = hi;
    // 0x801346D4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801346D8: nop

    // 0x801346DC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x801346E0: mflo        $v0
    ctx->r2 = lo;
    // 0x801346E4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x801346E8: jr          $ra
    // 0x801346EC: nop

    return;
    // 0x801346EC: nop

L_801346F0:
    // 0x801346F0: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x801346F4: mfhi        $v0
    ctx->r2 = hi;
    // 0x801346F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801346FC: nop

    // 0x80134700: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80134704: mflo        $v0
    ctx->r2 = lo;
    // 0x80134708: nop

    // 0x8013470C: nop

    // 0x80134710: jr          $ra
    // 0x80134714: nop

    return;
    // 0x80134714: nop

;}
RECOMP_FUNC void ftKirbySpecialLwUnused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161360: jr          $ra
    // 0x80161364: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80161364: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void ftFoxSpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C1F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C1F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C1FC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015C200: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015C204: addiu       $a1, $a1, -0x3B94
    ctx->r5 = ADD32(ctx->r5, -0X3B94);
    // 0x8015C208: lw          $t6, 0xB2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XB2C);
    // 0x8015C20C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8015C210: sw          $t7, 0xB2C($v1)
    MEM_W(0XB2C, ctx->r3) = ctx->r15;
    // 0x8015C214: jal         0x800DDDDC
    // 0x8015C218: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015C218: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015C21C: beq         $v0, $zero, L_8015C254
    if (ctx->r2 == 0) {
        // 0x8015C220: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8015C254;
    }
    // 0x8015C220: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C224: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    // 0x8015C228: lwc1        $f4, 0xF8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x8015C22C: lwc1        $f14, 0xFC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XFC);
    // 0x8015C230: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8015C234: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8015C238: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8015C23C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8015C240: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8015C244: jal         0x8001863C
    // 0x8015C248: nop

    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8015C248: nop

    after_1:
    // 0x8015C24C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C250: swc1        $f0, 0xB20($v1)
    MEM_W(0XB20, ctx->r3) = ctx->f0.u32l;
L_8015C254:
    // 0x8015C254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015C258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C25C: jr          $ra
    // 0x8015C260: nop

    return;
    // 0x8015C260: nop

;}
RECOMP_FUNC void mnMapsPreviewCameraThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801339C8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x801339CC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801339D0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801339D4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x801339D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801339DC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801339E0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801339E4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801339E8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801339EC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801339F0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801339F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801339F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801339FC: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x80133A00: lwc1        $f26, 0x4BCC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X4BCC);
    // 0x80133A04: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80133A08: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80133A0C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80133A10: lwc1        $f24, 0x4C($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X4C);
L_80133A14:
    // 0x80133A14: mul.s       $f4, $f20, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x80133A18: jal         0x800303F0
    // 0x80133A1C: div.s       $f12, $f4, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f28.fl);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80133A1C: div.s       $f12, $f4, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f28.fl);
    after_0:
    // 0x80133A20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80133A24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133A28: mul.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x80133A2C: add.s       $f2, $f20, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x80133A30: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x80133A34: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x80133A38: bc1f        L_80133A48
    if (!c1cs) {
        // 0x80133A3C: swc1        $f8, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
            goto L_80133A48;
    }
    // 0x80133A3C: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x80133A40: b           L_80133A4C
    // 0x80133A44: sub.s       $f20, $f2, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f22.fl;
        goto L_80133A4C;
    // 0x80133A44: sub.s       $f20, $f2, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f22.fl;
L_80133A48:
    // 0x80133A48: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_80133A4C:
    // 0x80133A4C: jal         0x8000B1E8
    // 0x80133A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x80133A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80133A54: b           L_80133A14
    // 0x80133A58: nop

        goto L_80133A14;
    // 0x80133A58: nop

    // 0x80133A5C: nop

    // 0x80133A60: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80133A64: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80133A68: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80133A6C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80133A70: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80133A74: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80133A78: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80133A7C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80133A80: jr          $ra
    // 0x80133A84: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80133A84: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftCommonRebirthDownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013CF60: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8013CF64: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013CF68: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8013CF6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013CF70: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8013CF74: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x8013CF78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013CF7C: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x8013CF80: addiu       $t1, $t7, 0x3C
    ctx->r9 = ADD32(ctx->r15, 0X3C);
    // 0x8013CF84: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
L_8013CF88:
    // 0x8013CF88: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013CF8C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8013CF90: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013CF94: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x8013CF98: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8013CF9C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8013CFA0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8013CFA4: bne         $t7, $t1, L_8013CF88
    if (ctx->r15 != ctx->r9) {
        // 0x8013CFA8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8013CF88;
    }
    // 0x8013CFA8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8013CFAC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013CFB0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8013CFB4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8013CFB8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013CFBC: lw          $t2, 0x44($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X44);
    // 0x8013CFC0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8013CFC4: jal         0x800FC814
    // 0x8013CFC8: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_0;
    // 0x8013CFC8: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    after_0:
    // 0x8013CFCC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8013CFD0: jal         0x800FC894
    // 0x8013CFD4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_1;
    // 0x8013CFD4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x8013CFD8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8013CFDC: lw          $a1, 0x66FC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X66FC);
    // 0x8013CFE0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8013CFE4: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8013CFE8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8013CFEC:
    // 0x8013CFEC: beql        $a0, $zero, L_8013D040
    if (ctx->r4 == 0) {
        // 0x8013CFF0: sll         $t4, $t0, 2
        ctx->r12 = S32(ctx->r8 << 2);
            goto L_8013D040;
    }
    goto skip_0;
    // 0x8013CFF0: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    skip_0:
L_8013CFF4:
    // 0x8013CFF4: beql        $a0, $s0, L_8013D034
    if (ctx->r4 == ctx->r16) {
        // 0x8013CFF8: lw          $a0, 0x4($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X4);
            goto L_8013D034;
    }
    goto skip_1;
    // 0x8013CFF8: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x8013CFFC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D000: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x8013D004: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8013D008: bne         $at, $zero, L_8013D030
    if (ctx->r1 != 0) {
        // 0x8013D00C: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_8013D030;
    }
    // 0x8013D00C: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x8013D010: beql        $at, $zero, L_8013D034
    if (ctx->r1 == 0) {
        // 0x8013D014: lw          $a0, 0x4($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X4);
            goto L_8013D034;
    }
    goto skip_2;
    // 0x8013D014: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x8013D018: lw          $t3, 0xB34($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XB34);
    // 0x8013D01C: bnel        $t0, $t3, L_8013D034
    if (ctx->r8 != ctx->r11) {
        // 0x8013D020: lw          $a0, 0x4($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X4);
            goto L_8013D034;
    }
    goto skip_3;
    // 0x8013D020: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x8013D024: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8013D028: b           L_8013CFEC
    // 0x8013D02C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_8013CFEC;
    // 0x8013D02C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8013D030:
    // 0x8013D030: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
L_8013D034:
    // 0x8013D034: bne         $a0, $zero, L_8013CFF4
    if (ctx->r4 != 0) {
        // 0x8013D038: nop
    
            goto L_8013CFF4;
    }
    // 0x8013D038: nop

    // 0x8013D03C: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
L_8013D040:
    // 0x8013D040: addiu       $t5, $t5, -0x7B70
    ctx->r13 = ADD32(ctx->r13, -0X7B70);
    // 0x8013D044: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8013D048: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8013D04C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8013D050: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013D054: lw          $t1, 0x1300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1300);
    // 0x8013D058: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013D05C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8013D060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013D064: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8013D068: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8013D06C: lh          $t7, 0x74($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X74);
    // 0x8013D070: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8013D074: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8013D078: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8013D07C: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x8013D080: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013D084: jal         0x800D79F0
    // 0x8013D088: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    ftManagerInitFighter(rdram, ctx);
        goto after_2;
    // 0x8013D088: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8013D08C: jal         0x8010F840
    // 0x8013D090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ifCommonPlayerDamageStopBreakAnim(rdram, ctx);
        goto after_3;
    // 0x8013D090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8013D094: jal         0x800DEE98
    // 0x8013D098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_4;
    // 0x8013D098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8013D09C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013D0A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013D0A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8013D0A8: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x8013D0AC: addiu       $t8, $zero, 0x4000
    ctx->r24 = ADD32(0, 0X4000);
    // 0x8013D0B0: sw          $t6, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->r14;
    // 0x8013D0B4: sw          $t8, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->r24;
    // 0x8013D0B8: swc1        $f0, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f0.u32l;
    // 0x8013D0BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8013D0C0: swc1        $f2, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f2.u32l;
    // 0x8013D0C4: swc1        $f2, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f2.u32l;
    // 0x8013D0C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013D0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013D0D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8013D0D4: jal         0x800E6F24
    // 0x8013D0D8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_5;
    // 0x8013D0D8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_5:
    // 0x8013D0DC: jal         0x800E0830
    // 0x8013D0E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_6;
    // 0x8013D0E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8013D0E4: jal         0x800D9444
    // 0x8013D0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_7;
    // 0x8013D0E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8013D0EC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8013D0F0: addiu       $t9, $zero, 0x5A
    ctx->r25 = ADD32(0, 0X5A);
    // 0x8013D0F4: addiu       $t2, $zero, 0x186
    ctx->r10 = ADD32(0, 0X186);
    // 0x8013D0F8: sw          $t9, 0xB38($s1)
    MEM_W(0XB38, ctx->r17) = ctx->r25;
    // 0x8013D0FC: sw          $t2, 0xB30($s1)
    MEM_W(0XB30, ctx->r17) = ctx->r10;
    // 0x8013D100: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8013D104: lbu         $t6, 0x191($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X191);
    // 0x8013D108: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8013D10C: lw          $t5, 0x1C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C);
    // 0x8013D110: ori         $t2, $t6, 0x10
    ctx->r10 = ctx->r14 | 0X10;
    // 0x8013D114: ori         $t9, $t2, 0x40
    ctx->r25 = ctx->r10 | 0X40;
    // 0x8013D118: sw          $t5, 0xB24($s1)
    MEM_W(0XB24, ctx->r17) = ctx->r13;
    // 0x8013D11C: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x8013D120: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013D124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013D128: sw          $t4, 0xB28($s1)
    MEM_W(0XB28, ctx->r17) = ctx->r12;
    // 0x8013D12C: lw          $t5, 0x24($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X24);
    // 0x8013D130: lw          $t4, 0x9C8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X9C8);
    // 0x8013D134: sw          $t5, 0xB2C($s1)
    MEM_W(0XB2C, ctx->r17) = ctx->r13;
    // 0x8013D138: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8013D13C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8013D140: lbu         $t5, 0x18E($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X18E);
    // 0x8013D144: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8013D148: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x8013D14C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013D150: ori         $t8, $t6, 0x40
    ctx->r24 = ctx->r14 | 0X40;
    // 0x8013D154: swc1        $f8, 0xB18($s1)
    MEM_W(0XB18, ctx->r17) = ctx->f8.u32l;
    // 0x8013D158: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8013D15C: sb          $t2, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r10;
    // 0x8013D160: andi        $t2, $t9, 0xF0
    ctx->r10 = ctx->r25 & 0XF0;
    // 0x8013D164: sb          $t9, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r25;
    // 0x8013D168: sb          $t6, 0x18E($s1)
    MEM_B(0X18E, ctx->r17) = ctx->r14;
    // 0x8013D16C: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8013D170: sb          $t8, 0x18E($s1)
    MEM_B(0X18E, ctx->r17) = ctx->r24;
    // 0x8013D174: sb          $t3, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r11;
    // 0x8013D178: sw          $t0, 0xB34($s1)
    MEM_W(0XB34, ctx->r17) = ctx->r8;
    // 0x8013D17C: swc1        $f16, 0xB20($s1)
    MEM_W(0XB20, ctx->r17) = ctx->f16.u32l;
    // 0x8013D180: swc1        $f10, 0xB1C($s1)
    MEM_W(0XB1C, ctx->r17) = ctx->f10.u32l;
    // 0x8013D184: lwc1        $f18, -0x3FB0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3FB0);
    // 0x8013D188: swc1        $f18, 0x864($s1)
    MEM_W(0X864, ctx->r17) = ctx->f18.u32l;
    // 0x8013D18C: jal         0x80104068
    // 0x8013D190: lw          $a1, 0xEC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XEC);
    efManagerRebirthHaloMakeEffect(rdram, ctx);
        goto after_8;
    // 0x8013D190: lw          $a1, 0xEC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XEC);
    after_8:
    // 0x8013D194: beq         $v0, $zero, L_8013D1A8
    if (ctx->r2 == 0) {
        // 0x8013D198: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8013D1A8;
    }
    // 0x8013D198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013D19C: lbu         $t1, 0x18F($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X18F);
    // 0x8013D1A0: ori         $t7, $t1, 0x10
    ctx->r15 = ctx->r9 | 0X10;
    // 0x8013D1A4: sb          $t7, 0x18F($s1)
    MEM_B(0X18F, ctx->r17) = ctx->r15;
L_8013D1A8:
    // 0x8013D1A8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8013D1AC: jal         0x800E9814
    // 0x8013D1B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_9;
    // 0x8013D1B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8013D1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013D1B8: jal         0x800E7F7C
    // 0x8013D1BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_10;
    // 0x8013D1BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8013D1C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013D1C4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D1C8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8013D1CC: jr          $ra
    // 0x8013D1D0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8013D1D0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void __n_lookupSoundQuick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E41C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8002E420: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8002E424: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002E428: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8002E42C: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8002E430: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8002E434: subu        $t7, $t7, $a3
    ctx->r15 = SUB32(ctx->r15, ctx->r7);
    // 0x8002E438: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002E43C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002E440: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8002E444: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002E448: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x8002E44C: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x8002E450: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002E454: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x8002E458: blez        $t0, L_8002E514
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002E45C: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_8002E514;
    }
    // 0x8002E45C: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_8002E460:
    // 0x8002E460: bgez        $a1, L_8002E46C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8002E464: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_8002E46C;
    }
    // 0x8002E464: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x8002E468: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
L_8002E46C:
    // 0x8002E46C: sra         $a1, $at, 1
    ctx->r5 = S32(SIGNED(ctx->r1) >> 1);
    // 0x8002E470: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8002E474: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x8002E478: lw          $a3, 0xC($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XC);
    // 0x8002E47C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002E480: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x8002E484: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x8002E488: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002E48C: bnel        $at, $zero, L_8002E4D4
    if (ctx->r1 != 0) {
        // 0x8002E490: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8002E4D4;
    }
    goto skip_0;
    // 0x8002E490: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_0:
    // 0x8002E494: lbu         $t5, 0x3($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X3);
    // 0x8002E498: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002E49C: bnel        $at, $zero, L_8002E4D4
    if (ctx->r1 != 0) {
        // 0x8002E4A0: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8002E4D4;
    }
    goto skip_1;
    // 0x8002E4A0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_1:
    // 0x8002E4A4: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8002E4A8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8002E4AC: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002E4B0: bnel        $at, $zero, L_8002E4D4
    if (ctx->r1 != 0) {
        // 0x8002E4B4: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8002E4D4;
    }
    goto skip_2;
    // 0x8002E4B4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_2:
    // 0x8002E4B8: lbu         $t7, 0x1($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1);
    // 0x8002E4BC: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002E4C0: bnel        $at, $zero, L_8002E4D4
    if (ctx->r1 != 0) {
        // 0x8002E4C4: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8002E4D4;
    }
    goto skip_3;
    // 0x8002E4C4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x8002E4C8: jr          $ra
    // 0x8002E4CC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x8002E4CC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8002E4D0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_8002E4D4:
    // 0x8002E4D4: bne         $at, $zero, L_8002E4FC
    if (ctx->r1 != 0) {
        // 0x8002E4D8: nop
    
            goto L_8002E4FC;
    }
    // 0x8002E4D8: nop

    // 0x8002E4DC: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8002E4E0: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002E4E4: beql        $at, $zero, L_8002E508
    if (ctx->r1 == 0) {
        // 0x8002E4E8: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_8002E508;
    }
    goto skip_4;
    // 0x8002E4E8: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x8002E4EC: lbu         $t9, 0x3($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3);
    // 0x8002E4F0: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002E4F4: bnel        $at, $zero, L_8002E508
    if (ctx->r1 != 0) {
        // 0x8002E4F8: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_8002E508;
    }
    goto skip_5;
    // 0x8002E4F8: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_5:
L_8002E4FC:
    // 0x8002E4FC: b           L_8002E508
    // 0x8002E500: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_8002E508;
    // 0x8002E500: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x8002E504: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_8002E508:
    // 0x8002E508: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002E50C: beql        $at, $zero, L_8002E460
    if (ctx->r1 == 0) {
        // 0x8002E510: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_8002E460;
    }
    goto skip_6;
    // 0x8002E510: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    skip_6:
L_8002E514:
    // 0x8002E514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002E518: jr          $ra
    // 0x8002E51C: nop

    return;
    // 0x8002E51C: nop

;}
RECOMP_FUNC void syDmaInitVpk0Stream(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800035E4: sw          $a0, 0x50E0($at)
    MEM_W(0X50E0, ctx->r1) = ctx->r4;
    // 0x800035E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800035EC: sw          $a1, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->r5;
    // 0x800035F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800035F4: jr          $ra
    // 0x800035F8: sw          $a2, 0x50DC($at)
    MEM_W(0X50DC, ctx->r1) = ctx->r6;
    return;
    // 0x800035F8: sw          $a2, 0x50DC($at)
    MEM_W(0X50DC, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void mvOpeningYoshiMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D194: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
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
    // 0x8018D1BC: addiu       $t7, $t7, -0x1EF0
    ctx->r15 = ADD32(ctx->r15, -0X1EF0);
    // 0x8018D1C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018D1C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018D1C8: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8018D1CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D1D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018D1D4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8018D1D8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8018D1DC: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D1E0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8018D1E4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018D1E8: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8018D1EC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8018D1F0: addiu       $t1, $t1, -0x1ED8
    ctx->r9 = ADD32(ctx->r9, -0X1ED8);
    // 0x8018D1F4: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8018D1F8: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8018D1FC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D200: addiu       $t0, $sp, 0x5C
    ctx->r8 = ADD32(ctx->r29, 0X5C);
    // 0x8018D204: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018D208: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8018D20C: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018D210: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8018D214: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8018D218: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8018D21C: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8018D220: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018D224: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018D228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D22C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D230: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8018D234: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8018D238: jal         0x80009968
    // 0x8018D23C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D23C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x8018D240: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D244: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018D248: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8018D24C: sw          $v0, -0x1DD4($at)
    MEM_W(-0X1DD4, ctx->r1) = ctx->r2;
    // 0x8018D250: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018D254: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018D258: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018D25C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D260: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018D264: jal         0x80009DF4
    // 0x8018D268: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D268: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018D26C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8018D270: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x8018D274: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x8018D278: beq         $t5, $zero, L_8018D2EC
    if (ctx->r13 == 0) {
        // 0x8018D27C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018D2EC;
    }
    // 0x8018D27C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D280: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018D284: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8018D288: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018D28C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D290: addiu       $s2, $s2, -0x1BC0
    ctx->r18 = ADD32(ctx->r18, -0X1BC0);
    // 0x8018D294: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D298: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
    // 0x8018D29C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8018D2A0:
    // 0x8018D2A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018D2A4: jal         0x800CCFDC
    // 0x8018D2A8: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018D2A8: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x8018D2AC: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D2B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D2B4: and         $t0, $t8, $s3
    ctx->r8 = ctx->r24 & ctx->r19;
    // 0x8018D2B8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018D2BC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8018D2C0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8018D2C4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D2C8: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x8018D2CC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8018D2D0: jal         0x8018D160
    // 0x8018D2D4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    mvOpeningYoshiInitName(rdram, ctx);
        goto after_3;
    // 0x8018D2D4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x8018D2D8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8018D2DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018D2E0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018D2E4: bnel        $v0, $zero, L_8018D2A0
    if (ctx->r2 != 0) {
        // 0x8018D2E8: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8018D2A0;
    }
    goto skip_0;
    // 0x8018D2E8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8018D2EC:
    // 0x8018D2EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D2F0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018D2F4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018D2F8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D2FC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018D300: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018D304: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D308: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8018D30C: jr          $ra
    // 0x8018D310: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8018D310: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void ftDonkeyThrowFWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D49C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D4A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D4A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014D4A8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8014D4AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014D4B0: lw          $t7, 0x14C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14C);
    // 0x8014D4B4: bnel        $t7, $at, L_8014D4C8
    if (ctx->r15 != ctx->r1) {
        // 0x8014D4B8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8014D4C8;
    }
    goto skip_0;
    // 0x8014D4B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8014D4BC: jal         0x800DEE98
    // 0x8014D4C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8014D4C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8014D4C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8014D4C8:
    // 0x8014D4C8: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x8014D4CC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014D4D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014D4D4: jal         0x800E6F24
    // 0x8014D4D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014D4D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8014D4DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D4E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014D4E4: jr          $ra
    // 0x8014D4E8: nop

    return;
    // 0x8014D4E8: nop

;}
RECOMP_FUNC void mnPlayersVSGetNextPortraitX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DC4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80131DC8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131DCC: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80131DD0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80131DD4: addiu       $t6, $t6, -0x4C10
    ctx->r14 = ADD32(ctx->r14, -0X4C10);
    // 0x80131DD8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80131DDC: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80131DE0: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131DE4:
    // 0x80131DE4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131DE8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131DEC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131DF0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131DF4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131DF8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131DFC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131E00: bne         $t6, $t0, L_80131DE4
    if (ctx->r14 != ctx->r8) {
        // 0x80131E04: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131DE4;
    }
    // 0x80131E04: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131E08: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80131E0C: addiu       $t1, $t1, -0x4BE0
    ctx->r9 = ADD32(ctx->r9, -0X4BE0);
    // 0x80131E10: addiu       $t5, $t1, 0x30
    ctx->r13 = ADD32(ctx->r9, 0X30);
    // 0x80131E14: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_80131E18:
    // 0x80131E18: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131E1C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80131E20: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80131E24: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x80131E28: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x80131E2C: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x80131E30: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x80131E34: bne         $t1, $t5, L_80131E18
    if (ctx->r9 != ctx->r13) {
        // 0x80131E38: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_80131E18;
    }
    // 0x80131E38: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x80131E3C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80131E40: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x80131E44: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80131E48: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80131E4C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80131E50: nop

    // 0x80131E54: bc1fl       L_80131E6C
    if (!c1cs) {
        // 0x80131E58: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80131E6C;
    }
    goto skip_0;
    // 0x80131E58: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x80131E5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131E60: b           L_80131ED0
    // 0x80131E64: nop

        goto L_80131ED0;
    // 0x80131E64: nop

    // 0x80131E68: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80131E6C:
    // 0x80131E6C: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x80131E70: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x80131E74: bc1fl       L_80131EAC
    if (!c1cs) {
        // 0x80131E78: lwc1        $f6, 0x0($t9)
        ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
            goto L_80131EAC;
    }
    goto skip_1;
    // 0x80131E78: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    skip_1:
    // 0x80131E7C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80131E80: add.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80131E84: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80131E88: nop

    // 0x80131E8C: bc1fl       L_80131EA0
    if (!c1cs) {
        // 0x80131E90: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80131EA0;
    }
    goto skip_2;
    // 0x80131E90: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x80131E94: b           L_80131ED0
    // 0x80131E98: nop

        goto L_80131ED0;
    // 0x80131E98: nop

    // 0x80131E9C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80131EA0:
    // 0x80131EA0: b           L_80131ED0
    // 0x80131EA4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80131ED0;
    // 0x80131EA4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80131EA8: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
L_80131EAC:
    // 0x80131EAC: add.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80131EB0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80131EB4: nop

    // 0x80131EB8: bc1fl       L_80131ECC
    if (!c1cs) {
        // 0x80131EBC: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80131ECC;
    }
    goto skip_3;
    // 0x80131EBC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_3:
    // 0x80131EC0: b           L_80131ECC
    // 0x80131EC4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80131ECC;
    // 0x80131EC4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80131EC8: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80131ECC:
    // 0x80131ECC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80131ED0:
    // 0x80131ED0: jr          $ra
    // 0x80131ED4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80131ED4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void grWallpaperMakeDecideKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104BDC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80104BE0: lbu         $t6, 0x4AD0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD0);
    // 0x80104BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104BE8: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80104BEC: bne         $t6, $at, L_80104C0C
    if (ctx->r14 != ctx->r1) {
        // 0x80104BF0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80104C0C;
    }
    // 0x80104BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104BF4: jal         0x8018DDB0
    // 0x80104BF8: nop

    sc1PTrainingModeLoadWallpaper(rdram, ctx);
        goto after_0;
    // 0x80104BF8: nop

    after_0:
    // 0x80104BFC: jal         0x801048F8
    // 0x80104C00: nop

    grWallpaperMakeStatic(rdram, ctx);
        goto after_1;
    // 0x80104C00: nop

    after_1:
    // 0x80104C04: b           L_80104CA8
    // 0x80104C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80104CA8;
    // 0x80104C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104C0C:
    // 0x80104C0C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80104C10: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80104C14: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    // 0x80104C18: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80104C1C: bne         $at, $zero, L_80104C34
    if (ctx->r1 != 0) {
        // 0x80104C20: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80104C34;
    }
    // 0x80104C20: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80104C24: jal         0x801048F8
    // 0x80104C28: nop

    grWallpaperMakeStatic(rdram, ctx);
        goto after_2;
    // 0x80104C28: nop

    after_2:
    // 0x80104C2C: b           L_80104CA8
    // 0x80104C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80104CA8;
    // 0x80104C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104C34:
    // 0x80104C34: sltiu       $at, $t8, 0x10
    ctx->r1 = ctx->r24 < 0X10 ? 1 : 0;
    // 0x80104C38: beq         $at, $zero, L_80104C9C
    if (ctx->r1 == 0) {
        // 0x80104C3C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80104C9C;
    }
    // 0x80104C3C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80104C40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104C44: addu        $at, $at, $t8
    gpr jr_addend_80104C4C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80104C48: lw          $t8, 0xA50($at)
    ctx->r24 = ADD32(ctx->r1, 0XA50);
    // 0x80104C4C: jr          $t8
    // 0x80104C50: nop

    switch (jr_addend_80104C4C >> 2) {
        case 0: goto L_80104C64; break;
        case 1: goto L_80104C9C; break;
        case 2: goto L_80104C9C; break;
        case 3: goto L_80104C9C; break;
        case 4: goto L_80104C54; break;
        case 5: goto L_80104C9C; break;
        case 6: goto L_80104C9C; break;
        case 7: goto L_80104C9C; break;
        case 8: goto L_80104C9C; break;
        case 9: goto L_80104C9C; break;
        case 10: goto L_80104C9C; break;
        case 11: goto L_80104C54; break;
        case 12: goto L_80104C9C; break;
        case 13: goto L_80104C9C; break;
        case 14: goto L_80104C74; break;
        case 15: goto L_80104C84; break;
        default: switch_error(__func__, 0x80104C4C, 0x80130A50);
    }
    // 0x80104C50: nop

L_80104C54:
    // 0x80104C54: jal         0x801048F8
    // 0x80104C58: nop

    grWallpaperMakeStatic(rdram, ctx);
        goto after_3;
    // 0x80104C58: nop

    after_3:
    // 0x80104C5C: b           L_80104CA8
    // 0x80104C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80104CA8;
    // 0x80104C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104C64:
    // 0x80104C64: jal         0x80104ABC
    // 0x80104C68: nop

    grWallpaperMakeSector(rdram, ctx);
        goto after_4;
    // 0x80104C68: nop

    after_4:
    // 0x80104C6C: b           L_80104CA8
    // 0x80104C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80104CA8;
    // 0x80104C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104C74:
    // 0x80104C74: jal         0x80104B88
    // 0x80104C78: nop

    grWallpaperMakeBonus3(rdram, ctx);
        goto after_5;
    // 0x80104C78: nop

    after_5:
    // 0x80104C7C: b           L_80104CA8
    // 0x80104C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80104CA8;
    // 0x80104C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104C84:
    // 0x80104C84: jal         0x80192764
    // 0x80104C88: nop

    sc1PGameBossInitWallpaper(rdram, ctx);
        goto after_6;
    // 0x80104C88: nop

    after_6:
    // 0x80104C8C: jal         0x80104850
    // 0x80104C90: nop

    grWallpaperMakeCommon(rdram, ctx);
        goto after_7;
    // 0x80104C90: nop

    after_7:
    // 0x80104C94: b           L_80104CA8
    // 0x80104C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80104CA8;
    // 0x80104C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104C9C:
    // 0x80104C9C: jal         0x80104850
    // 0x80104CA0: nop

    grWallpaperMakeCommon(rdram, ctx);
        goto after_8;
    // 0x80104CA0: nop

    after_8:
    // 0x80104CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104CA8:
    // 0x80104CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104CAC: jr          $ra
    // 0x80104CB0: nop

    return;
    // 0x80104CB0: nop

;}
RECOMP_FUNC void func_ovl8_803819F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803819F4: bnel        $a1, $zero, L_80381A1C
    if (ctx->r5 != 0) {
        // 0x803819F8: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_80381A1C;
    }
    goto skip_0;
    // 0x803819F8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x803819FC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80381A00: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80381A04: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80381A08: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80381A0C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80381A10: jr          $ra
    // 0x80381A14: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    return;
    // 0x80381A14: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x80381A18: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
L_80381A1C:
    // 0x80381A1C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80381A20: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80381A24: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x80381A28: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80381A2C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80381A30: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x80381A34: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80381A38: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80381A3C: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80381A40: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x80381A44: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80381A48: subu        $t9, $t8, $a1
    ctx->r25 = SUB32(ctx->r24, ctx->r5);
    // 0x80381A4C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80381A50: jr          $ra
    // 0x80381A54: nop

    return;
    // 0x80381A54: nop

;}
RECOMP_FUNC void mnNoControllerMakeImage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6538: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D653C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D6540: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    // 0x800D6544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6548: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D654C: jal         0x80009968
    // 0x800D6550: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800D6550: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800D6554: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D6558: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800D655C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800D6560: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D6564: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x800D6568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D656C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6570: jal         0x80009DF4
    // 0x800D6574: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x800D6574: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800D6578: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800D657C: lw          $t7, 0x67D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X67D0);
    // 0x800D6580: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x800D6584: addiu       $t8, $t8, -0x7BA0
    ctx->r24 = ADD32(ctx->r24, -0X7BA0);
    // 0x800D6588: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D658C: jal         0x800CCFDC
    // 0x800D6590: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x800D6590: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x800D6594: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800D6598: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D659C: nop

    // 0x800D65A0: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x800D65A4: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x800D65A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D65AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D65B0: jr          $ra
    // 0x800D65B4: nop

    return;
    // 0x800D65B4: nop

;}
RECOMP_FUNC void mnPlayersVSFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013494C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134950: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134954: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134958: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013495C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134960: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80134964: lbu         $v1, 0xD($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XD);
    // 0x80134968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013496C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80134970: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80134974: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80134978: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8013497C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80134980: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80134984: lw          $t8, 0x88($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X88);
    // 0x80134988: bnel        $t8, $at, L_80134A3C
    if (ctx->r24 != ctx->r1) {
        // 0x8013498C: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80134A3C;
    }
    goto skip_0;
    // 0x8013498C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x80134990: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134994: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134998: lwc1        $f4, -0x45A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X45A0);
    // 0x8013499C: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801349A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801349A4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801349A8: nop

    // 0x801349AC: bc1f        L_801349E0
    if (!c1cs) {
        // 0x801349B0: nop
    
            goto L_801349E0;
    }
    // 0x801349B0: nop

    // 0x801349B4: lw          $t9, 0x8C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8C);
    // 0x801349B8: bnel        $t9, $zero, L_80134A7C
    if (ctx->r25 != 0) {
        // 0x801349BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134A7C;
    }
    goto skip_1;
    // 0x801349BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801349C0: jal         0x801348EC
    // 0x801349C4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    mnPlayersVSGetStatusSelected(rdram, ctx);
        goto after_0;
    // 0x801349C4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_0:
    // 0x801349C8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801349CC: jal         0x803905CC
    // 0x801349D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_1;
    // 0x801349D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x801349D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801349D8: b           L_80134A78
    // 0x801349DC: sw          $t0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r8;
        goto L_80134A78;
    // 0x801349DC: sw          $t0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r8;
L_801349E0:
    // 0x801349E0: lwc1        $f2, -0x459C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X459C);
    // 0x801349E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801349E8: lwc1        $f6, -0x4598($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4598);
    // 0x801349EC: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801349F0: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x801349F4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801349F8: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801349FC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80134A00: nop

    // 0x80134A04: bc1fl       L_80134A7C
    if (!c1cs) {
        // 0x80134A08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134A7C;
    }
    goto skip_2;
    // 0x80134A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80134A0C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80134A10: nop

    // 0x80134A14: swc1        $f16, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f16.u32l;
    // 0x80134A18: jal         0x801348EC
    // 0x80134A1C: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    mnPlayersVSGetStatusSelected(rdram, ctx);
        goto after_2;
    // 0x80134A1C: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x80134A20: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80134A24: jal         0x803905CC
    // 0x80134A28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_3;
    // 0x80134A28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80134A2C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134A30: b           L_80134A78
    // 0x80134A34: sw          $t1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r9;
        goto L_80134A78;
    // 0x80134A34: sw          $t1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r9;
    // 0x80134A38: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
L_80134A3C:
    // 0x80134A3C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134A40: lwc1        $f2, -0x4594($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4594);
    // 0x80134A44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134A48: lwc1        $f4, -0x4590($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4590);
    // 0x80134A4C: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80134A50: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80134A54: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x80134A58: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134A5C: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80134A60: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80134A64: nop

    // 0x80134A68: bc1fl       L_80134A7C
    if (!c1cs) {
        // 0x80134A6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134A7C;
    }
    goto skip_3;
    // 0x80134A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80134A70: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80134A74: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
L_80134A78:
    // 0x80134A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134A7C:
    // 0x80134A7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134A80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80134A84: jr          $ra
    // 0x80134A88: nop

    return;
    // 0x80134A88: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingCursorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135934: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013593C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80135940: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80135944: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80135948: jal         0x80135074
    // 0x8013594C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PTrainingAdjustCursor(rdram, ctx);
        goto after_0;
    // 0x8013594C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80135950: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135954: lw          $t6, -0x776C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X776C);
    // 0x80135958: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8013595C: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80135960: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80135964: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80135968: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8013596C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80135970: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x80135974: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x80135978: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013597C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80135980: beq         $t9, $zero, L_801359E0
    if (ctx->r25 == 0) {
        // 0x80135984: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_801359E0;
    }
    // 0x80135984: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135988: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8013598C: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x80135990: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80135994: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80135998: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8013599C: lw          $a2, -0x7A2C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7A2C);
    // 0x801359A0: jal         0x80134848
    // 0x801359A4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    mnPlayers1PTrainingSelectFighter(rdram, ctx);
        goto after_1;
    // 0x801359A4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x801359A8: bne         $v0, $zero, L_801359E0
    if (ctx->r2 != 0) {
        // 0x801359AC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_801359E0;
    }
    // 0x801359AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801359B0: jal         0x80134D8C
    // 0x801359B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PTrainingCheckCursorPuckGrab(rdram, ctx);
        goto after_2;
    // 0x801359B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801359B8: bnel        $v0, $zero, L_801359E4
    if (ctx->r2 != 0) {
        // 0x801359BC: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_801359E4;
    }
    goto skip_0;
    // 0x801359BC: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    skip_0:
    // 0x801359C0: jal         0x8013586C
    // 0x801359C4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayers1PTrainingCheckBackInRange(rdram, ctx);
        goto after_3;
    // 0x801359C4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x801359C8: beql        $v0, $zero, L_801359E4
    if (ctx->r2 == 0) {
        // 0x801359CC: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_801359E4;
    }
    goto skip_1;
    // 0x801359CC: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    skip_1:
    // 0x801359D0: jal         0x801357CC
    // 0x801359D4: nop

    mnPlayers1PTrainingBackTo1PMode(rdram, ctx);
        goto after_4;
    // 0x801359D4: nop

    after_4:
    // 0x801359D8: jal         0x800269C0
    // 0x801359DC: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x801359DC: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_5:
L_801359E0:
    // 0x801359E0: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
L_801359E4:
    // 0x801359E4: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x801359E8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801359EC: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x801359F0: lw          $t4, -0x7798($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7798);
    // 0x801359F4: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x801359F8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801359FC: addiu       $t2, $t2, -0x7AA8
    ctx->r10 = ADD32(ctx->r10, -0X7AA8);
    // 0x80135A00: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80135A04: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80135A08: bne         $t4, $zero, L_80135B90
    if (ctx->r12 != 0) {
        // 0x80135A0C: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_80135B90;
    }
    // 0x80135A0C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80135A10: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80135A14: lw          $t5, -0x776C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X776C);
    // 0x80135A18: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80135A1C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135A20: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80135A24: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80135A28: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80135A2C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80135A30: lhu         $t7, 0x522A($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X522A);
    // 0x80135A34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135A38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80135A3C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80135A40: beq         $t8, $zero, L_80135A70
    if (ctx->r24 == 0) {
        // 0x80135A44: nop
    
            goto L_80135A70;
    }
    // 0x80135A44: nop

    // 0x80135A48: jal         0x80134848
    // 0x80135A4C: lw          $a2, 0x7C($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X7C);
    mnPlayers1PTrainingSelectFighter(rdram, ctx);
        goto after_6;
    // 0x80135A4C: lw          $a2, 0x7C($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X7C);
    after_6:
    // 0x80135A50: bne         $v0, $zero, L_80135A70
    if (ctx->r2 != 0) {
        // 0x80135A54: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80135A70;
    }
    // 0x80135A54: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80135A58: lw          $t0, 0x84($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X84);
    // 0x80135A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135A60: beq         $t0, $zero, L_80135A70
    if (ctx->r8 == 0) {
        // 0x80135A64: nop
    
            goto L_80135A70;
    }
    // 0x80135A64: nop

    // 0x80135A68: jal         0x801355E0
    // 0x80135A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnPlayers1PTrainingUpdateCostume(rdram, ctx);
        goto after_7;
    // 0x80135A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_80135A70:
    // 0x80135A70: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80135A74: lw          $t1, -0x776C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X776C);
    // 0x80135A78: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80135A7C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135A80: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80135A84: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80135A88: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80135A8C: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80135A90: lhu         $t4, 0x522A($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X522A);
    // 0x80135A94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135A98: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80135A9C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80135AA0: beq         $t5, $zero, L_80135AD0
    if (ctx->r13 == 0) {
        // 0x80135AA4: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80135AD0;
    }
    // 0x80135AA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80135AA8: jal         0x80134848
    // 0x80135AAC: lw          $a2, 0x7C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X7C);
    mnPlayers1PTrainingSelectFighter(rdram, ctx);
        goto after_8;
    // 0x80135AAC: lw          $a2, 0x7C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X7C);
    after_8:
    // 0x80135AB0: bne         $v0, $zero, L_80135AD0
    if (ctx->r2 != 0) {
        // 0x80135AB4: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80135AD0;
    }
    // 0x80135AB4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80135AB8: lw          $t8, 0x84($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84);
    // 0x80135ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135AC0: beq         $t8, $zero, L_80135AD0
    if (ctx->r24 == 0) {
        // 0x80135AC4: nop
    
            goto L_80135AD0;
    }
    // 0x80135AC4: nop

    // 0x80135AC8: jal         0x801355E0
    // 0x80135ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    mnPlayers1PTrainingUpdateCostume(rdram, ctx);
        goto after_9;
    // 0x80135ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80135AD0:
    // 0x80135AD0: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80135AD4: lw          $t3, -0x776C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X776C);
    // 0x80135AD8: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80135ADC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135AE0: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80135AE4: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80135AE8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80135AEC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80135AF0: lhu         $t0, 0x522A($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X522A);
    // 0x80135AF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135AF8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80135AFC: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80135B00: beq         $t1, $zero, L_80135B30
    if (ctx->r9 == 0) {
        // 0x80135B04: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_80135B30;
    }
    // 0x80135B04: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80135B08: jal         0x80134848
    // 0x80135B0C: lw          $a2, 0x7C($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X7C);
    mnPlayers1PTrainingSelectFighter(rdram, ctx);
        goto after_10;
    // 0x80135B0C: lw          $a2, 0x7C($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X7C);
    after_10:
    // 0x80135B10: bne         $v0, $zero, L_80135B30
    if (ctx->r2 != 0) {
        // 0x80135B14: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_80135B30;
    }
    // 0x80135B14: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80135B18: lw          $t5, 0x84($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X84);
    // 0x80135B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135B20: beq         $t5, $zero, L_80135B30
    if (ctx->r13 == 0) {
        // 0x80135B24: nop
    
            goto L_80135B30;
    }
    // 0x80135B24: nop

    // 0x80135B28: jal         0x801355E0
    // 0x80135B2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    mnPlayers1PTrainingUpdateCostume(rdram, ctx);
        goto after_11;
    // 0x80135B2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
L_80135B30:
    // 0x80135B30: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135B34: lw          $t6, -0x776C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X776C);
    // 0x80135B38: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80135B3C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135B40: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80135B44: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80135B48: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80135B4C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80135B50: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x80135B54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135B58: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80135B5C: andi        $t3, $t8, 0x2
    ctx->r11 = ctx->r24 & 0X2;
    // 0x80135B60: beq         $t3, $zero, L_80135B90
    if (ctx->r11 == 0) {
        // 0x80135B64: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80135B90;
    }
    // 0x80135B64: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80135B68: jal         0x80134848
    // 0x80135B6C: lw          $a2, 0x7C($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X7C);
    mnPlayers1PTrainingSelectFighter(rdram, ctx);
        goto after_12;
    // 0x80135B6C: lw          $a2, 0x7C($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X7C);
    after_12:
    // 0x80135B70: bne         $v0, $zero, L_80135B90
    if (ctx->r2 != 0) {
        // 0x80135B74: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80135B90;
    }
    // 0x80135B74: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80135B78: lw          $t1, 0x84($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X84);
    // 0x80135B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135B80: beq         $t1, $zero, L_80135B90
    if (ctx->r9 == 0) {
        // 0x80135B84: nop
    
            goto L_80135B90;
    }
    // 0x80135B84: nop

    // 0x80135B88: jal         0x801355E0
    // 0x80135B8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    mnPlayers1PTrainingUpdateCostume(rdram, ctx);
        goto after_13;
    // 0x80135B8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
L_80135B90:
    // 0x80135B90: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80135B94: lw          $t2, -0x776C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X776C);
    // 0x80135B98: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80135B9C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80135BA0: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80135BA4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80135BA8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80135BAC: lhu         $t5, 0x522A($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X522A);
    // 0x80135BB0: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x80135BB4: beql        $t6, $zero, L_80135BD8
    if (ctx->r14 == 0) {
        // 0x80135BB8: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80135BD8;
    }
    goto skip_2;
    // 0x80135BB8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80135BBC: jal         0x80135674
    // 0x80135BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingCheckManFighterSelected(rdram, ctx);
        goto after_14;
    // 0x80135BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80135BC4: beql        $v0, $zero, L_80135BD8
    if (ctx->r2 == 0) {
        // 0x80135BC8: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80135BD8;
    }
    goto skip_3;
    // 0x80135BC8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80135BCC: jal         0x801356D0
    // 0x80135BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingRecallPuck(rdram, ctx);
        goto after_15;
    // 0x80135BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80135BD4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80135BD8:
    // 0x80135BD8: lw          $v0, 0x58($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X58);
    // 0x80135BDC: bne         $v0, $zero, L_80135BF4
    if (ctx->r2 != 0) {
        // 0x80135BE0: nop
    
            goto L_80135BF4;
    }
    // 0x80135BE0: nop

    // 0x80135BE4: jal         0x80135818
    // 0x80135BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingDetectBack(rdram, ctx);
        goto after_16;
    // 0x80135BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80135BEC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80135BF0: lw          $v0, 0x58($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X58);
L_80135BF4:
    // 0x80135BF4: bne         $v0, $zero, L_80135C04
    if (ctx->r2 != 0) {
        // 0x80135BF8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80135C04;
    }
    // 0x80135BF8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135BFC: jal         0x80135430
    // 0x80135C00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PTrainingUpdateCursorNoRecall(rdram, ctx);
        goto after_17;
    // 0x80135C00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
L_80135C04:
    // 0x80135C04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135C08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80135C0C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135C10: jr          $ra
    // 0x80135C14: nop

    return;
    // 0x80135C14: nop

;}
RECOMP_FUNC void ftKirbySpecialNTurnProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016284C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162854: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162858: jal         0x800DDDDC
    // 0x8016285C: addiu       $a1, $a1, 0x2E20
    ctx->r5 = ADD32(ctx->r5, 0X2E20);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8016285C: addiu       $a1, $a1, 0x2E20
    ctx->r5 = ADD32(ctx->r5, 0X2E20);
    after_0:
    // 0x80162860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162868: jr          $ra
    // 0x8016286C: nop

    return;
    // 0x8016286C: nop

;}
RECOMP_FUNC void ftNessJumpAerialProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013FBC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013FBC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013FBCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013FBD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013FBD4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013FBD8: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013FBDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FBE0: addiu       $a1, $s0, 0xB18
    ctx->r5 = ADD32(ctx->r16, 0XB18);
    // 0x8013FBE4: addiu       $a2, $s0, 0x4C
    ctx->r6 = ADD32(ctx->r16, 0X4C);
    // 0x8013FBE8: addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
    // 0x8013FBEC: jal         0x800D9260
    // 0x8013FBF0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    ftPhysicsGetAirVelTransN(rdram, ctx);
        goto after_0;
    // 0x8013FBF0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8013FBF4: lwc1        $f4, 0xB1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB1C);
    // 0x8013FBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FBFC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x8013FC00: jal         0x800D8FA8
    // 0x8013FC04: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x8013FC04: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8013FC08: bne         $v0, $zero, L_8013FC24
    if (ctx->r2 != 0) {
        // 0x8013FC0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8013FC24;
    }
    // 0x8013FC0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FC10: jal         0x800D9044
    // 0x8013FC14: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftPhysicsClampAirVelXStickDefault(rdram, ctx);
        goto after_2;
    // 0x8013FC14: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8013FC18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013FC1C: jal         0x800D9074
    // 0x8013FC20: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_3;
    // 0x8013FC20: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
L_8013FC24:
    // 0x8013FC24: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8013FC28: lwc1        $f6, 0xB18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB18);
    // 0x8013FC2C: swc1        $f0, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f0.u32l;
    // 0x8013FC30: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8013FC34: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x8013FC38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013FC3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013FC40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013FC44: jr          $ra
    // 0x8013FC48: nop

    return;
    // 0x8013FC48: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010EEFC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8010EF00: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8010EF04: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8010EF08: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8010EF0C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8010EF10: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8010EF14: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8010EF18: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010EF1C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010EF20: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010EF24: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8010EF28: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x8010EF2C: addiu       $s4, $s4, 0x65B0
    ctx->r20 = ADD32(ctx->r20, 0X65B0);
    // 0x8010EF30: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8010EF34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010EF38: jal         0x800CC118
    // 0x8010EF3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    lbCommonPrepSObjAttr(rdram, ctx);
        goto after_0;
    // 0x8010EF3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8010EF40: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010EF44: jal         0x800CC818
    // 0x8010EF48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    lbCommonPrepSObjDraw(rdram, ctx);
        goto after_1;
    // 0x8010EF48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8010EF4C: jal         0x800CCED8
    // 0x8010EF50: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    lbCommonSetExternSpriteParams(rdram, ctx);
        goto after_2;
    // 0x8010EF50: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x8010EF54: lw          $v0, 0x84($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X84);
    // 0x8010EF58: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010EF5C: addiu       $t7, $t7, 0x1598
    ctx->r15 = ADD32(ctx->r15, 0X1598);
    // 0x8010EF60: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8010EF64: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8010EF68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010EF6C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8010EF70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010EF74: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x8010EF78: lbu         $t8, 0x69($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X69);
    // 0x8010EF7C: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8010EF80: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8010EF84: beq         $t8, $zero, L_8010F308
    if (ctx->r24 == 0) {
        // 0x8010EF88: subu        $t0, $t0, $v0
        ctx->r8 = SUB32(ctx->r8, ctx->r2);
            goto L_8010F308;
    }
    // 0x8010EF88: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8010EF8C: lw          $t9, 0x50E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50E8);
    // 0x8010EF90: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8010EF94: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x8010EF98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8010EF9C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8010EFA0: lb          $t2, 0x2B($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X2B);
    // 0x8010EFA4: bgezl       $t2, L_8010EFBC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8010EFA8: lbu         $v0, 0x64($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X64);
            goto L_8010EFBC;
    }
    goto skip_0;
    // 0x8010EFA8: lbu         $v0, 0x64($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X64);
    skip_0:
    // 0x8010EFAC: lbu         $t3, 0x68($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X68);
    // 0x8010EFB0: beql        $t3, $zero, L_8010F30C
    if (ctx->r11 == 0) {
        // 0x8010EFB4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8010F30C;
    }
    goto skip_1;
    // 0x8010EFB4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x8010EFB8: lbu         $v0, 0x64($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X64);
L_8010EFBC:
    // 0x8010EFBC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8010EFC0: lwc1        $f20, 0xC($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8010EFC4: bne         $v0, $at, L_8010EFFC
    if (ctx->r2 != ctx->r1) {
        // 0x8010EFC8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8010EFFC;
    }
    // 0x8010EFC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010EFCC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8010EFD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010EFD4: addiu       $t4, $t4, -0x13D0
    ctx->r12 = ADD32(ctx->r12, -0X13D0);
    // 0x8010EFD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010EFDC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8010EFE0: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8010EFE4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8010EFE8: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x8010EFEC: lbu         $a0, -0x13E0($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X13E0);
    // 0x8010EFF0: lbu         $a1, -0x13D8($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X13D8);
    // 0x8010EFF4: b           L_8010F0CC
    // 0x8010EFF8: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
        goto L_8010F0CC;
    // 0x8010EFF8: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
L_8010EFFC:
    // 0x8010EFFC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8010F000: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010F004: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8010F008: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8010F00C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8010F010: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010F014: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010F018: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8010F01C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010F020: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8010F024: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010F028: sub.s       $f0, $f24, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x8010F02C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010F030: nop

    // 0x8010F034: bc1f        L_8010F040
    if (!c1cs) {
        // 0x8010F038: nop
    
            goto L_8010F040;
    }
    // 0x8010F038: nop

    // 0x8010F03C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8010F040:
    // 0x8010F040: lbu         $t6, -0x13E0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X13E0);
    // 0x8010F044: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8010F048: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8010F04C: addiu       $t7, $t6, -0x64
    ctx->r15 = ADD32(ctx->r14, -0X64);
    // 0x8010F050: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8010F054: lbu         $t9, -0x13D8($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X13D8);
    // 0x8010F058: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8010F05C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010F060: addiu       $t2, $t2, -0x13D0
    ctx->r10 = ADD32(ctx->r10, -0X13D0);
    // 0x8010F064: addu        $v1, $v0, $t2
    ctx->r3 = ADD32(ctx->r2, ctx->r10);
    // 0x8010F068: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8010F06C: addiu       $t0, $t9, -0x14
    ctx->r8 = ADD32(ctx->r25, -0X14);
    // 0x8010F070: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8010F074: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8010F078: addiu       $t4, $t3, -0x14
    ctx->r12 = ADD32(ctx->r11, -0X14);
    // 0x8010F07C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010F080: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010F084: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8010F088: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010F08C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8010F090: nop

    // 0x8010F094: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    // 0x8010F098: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010F09C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8010F0A0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8010F0A4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010F0A8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8010F0AC: nop

    // 0x8010F0B0: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x8010F0B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8010F0B8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8010F0BC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8010F0C0: nop

    // 0x8010F0C4: addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
    // 0x8010F0C8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_8010F0CC:
    // 0x8010F0CC: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8010F0D0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8010F0D4: addiu       $s2, $s2, -0x119C
    ctx->r18 = ADD32(ctx->r18, -0X119C);
    // 0x8010F0D8: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8010F0DC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8010F0E0: addiu       $s3, $s3, 0xD40
    ctx->r19 = ADD32(ctx->r19, 0XD40);
    // 0x8010F0E4: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x8010F0E8: lw          $t0, 0x8($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X8);
    // 0x8010F0EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010F0F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8010F0F4: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8010F0F8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8010F0FC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8010F100: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x8010F104: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8010F108: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
L_8010F10C:
    // 0x8010F10C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8010F110: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8010F114: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8010F118: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8010F11C: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8010F120: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8010F124: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8010F128: bne         $t1, $t5, L_8010F10C
    if (ctx->r9 != ctx->r13) {
        // 0x8010F12C: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8010F10C;
    }
    // 0x8010F12C: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8010F130: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8010F134: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8010F138: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8010F13C: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    // 0x8010F140: lh          $t6, 0x14($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X14);
    // 0x8010F144: lh          $t7, 0x16($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16);
    // 0x8010F148: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010F14C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8010F150: nop

    // 0x8010F154: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010F158: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8010F15C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010F160: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8010F164: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010F168: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8010F16C: mul.s       $f16, $f6, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8010F170: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x8010F174: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010F178: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    // 0x8010F17C: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x8010F180: mul.s       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8010F184: sb          $a0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r4;
    // 0x8010F188: sb          $a1, 0x29($s0)
    MEM_B(0X29, ctx->r16) = ctx->r5;
    // 0x8010F18C: sb          $a2, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r6;
    // 0x8010F190: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010F194: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010F198: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8010F19C: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
    // 0x8010F1A0: jal         0x800CC118
    // 0x8010F1A4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    lbCommonPrepSObjAttr(rdram, ctx);
        goto after_3;
    // 0x8010F1A4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_3:
    // 0x8010F1A8: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8010F1AC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010F1B0: addiu       $t8, $t8, -0x13CC
    ctx->r24 = ADD32(ctx->r24, -0X13CC);
    // 0x8010F1B4: bne         $v1, $t8, L_8010F1E0
    if (ctx->r3 != ctx->r24) {
        // 0x8010F1B8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8010F1E0;
    }
    // 0x8010F1B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010F1BC: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8010F1C0: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x8010F1C4: lui         $t5, 0xFFFD
    ctx->r13 = S32(0XFFFD << 16);
    // 0x8010F1C8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8010F1CC: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8010F1D0: ori         $t5, $t5, 0xF2F9
    ctx->r13 = ctx->r13 | 0XF2F9;
    // 0x8010F1D4: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8010F1D8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8010F1DC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_8010F1E0:
    // 0x8010F1E0: jal         0x800CC818
    // 0x8010F1E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    lbCommonPrepSObjDraw(rdram, ctx);
        goto after_4;
    // 0x8010F1E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8010F1E8: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8010F1EC: beq         $s0, $zero, L_8010F300
    if (ctx->r16 == 0) {
        // 0x8010F1F0: nop
    
            goto L_8010F300;
    }
    // 0x8010F1F0: nop

    // 0x8010F1F4: lhu         $t1, 0x24($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X24);
L_8010F1F8:
    // 0x8010F1F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010F1FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010F200: andi        $t4, $t1, 0x4
    ctx->r12 = ctx->r9 & 0X4;
    // 0x8010F204: bnel        $t4, $zero, L_8010F2F8
    if (ctx->r12 != 0) {
        // 0x8010F208: lw          $s0, 0x8($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X8);
            goto L_8010F2F8;
    }
    goto skip_2;
    // 0x8010F208: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x8010F20C: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8010F210: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x8010F214: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x8010F218: lbu         $t2, 0x10($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10);
    // 0x8010F21C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8010F220: addu        $t6, $s2, $t3
    ctx->r14 = ADD32(ctx->r18, ctx->r11);
    // 0x8010F224: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8010F228: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8010F22C: addiu       $t4, $t9, 0x3C
    ctx->r12 = ADD32(ctx->r25, 0X3C);
L_8010F230:
    // 0x8010F230: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8010F234: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8010F238: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8010F23C: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8010F240: lw          $t0, -0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X8);
    // 0x8010F244: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x8010F248: lw          $t5, -0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, -0X4);
    // 0x8010F24C: bne         $t9, $t4, L_8010F230
    if (ctx->r25 != ctx->r12) {
        // 0x8010F250: sw          $t5, 0xC($t1)
        MEM_W(0XC, ctx->r9) = ctx->r13;
            goto L_8010F230;
    }
    // 0x8010F250: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x8010F254: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8010F258: c.eq.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl == ctx->f24.fl;
    // 0x8010F25C: sw          $t5, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r13;
    // 0x8010F260: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8010F264: sw          $t0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r8;
    // 0x8010F268: lh          $t2, 0x14($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X14);
    // 0x8010F26C: lh          $t3, 0x16($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X16);
    // 0x8010F270: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010F274: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8010F278: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010F27C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010F280: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8010F284: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8010F288: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010F28C: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8010F290: nop

    // 0x8010F294: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8010F298: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8010F29C: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8010F2A0: bc1f        L_8010F2E0
    if (!c1cs) {
        // 0x8010F2A4: sub.s       $f2, $f10, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
            goto L_8010F2E0;
    }
    // 0x8010F2A4: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8010F2A8: lbu         $t6, 0x65($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X65);
    // 0x8010F2AC: bnel        $t6, $zero, L_8010F2E4
    if (ctx->r14 != 0) {
        // 0x8010F2B0: swc1        $f0, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
            goto L_8010F2E4;
    }
    goto skip_3;
    // 0x8010F2B0: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    skip_3:
    // 0x8010F2B4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8010F2B8: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010F2BC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8010F2C0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8010F2C4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8010F2C8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8010F2CC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010F2D0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010F2D4: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x8010F2D8: b           L_8010F2E8
    // 0x8010F2DC: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
        goto L_8010F2E8;
    // 0x8010F2DC: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
L_8010F2E0:
    // 0x8010F2E0: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_8010F2E4:
    // 0x8010F2E4: swc1        $f2, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f2.u32l;
L_8010F2E8:
    // 0x8010F2E8: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x8010F2EC: jal         0x800CC818
    // 0x8010F2F0: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    lbCommonPrepSObjDraw(rdram, ctx);
        goto after_5;
    // 0x8010F2F0: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    after_5:
    // 0x8010F2F4: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
L_8010F2F8:
    // 0x8010F2F8: bnel        $s0, $zero, L_8010F1F8
    if (ctx->r16 != 0) {
        // 0x8010F2FC: lhu         $t1, 0x24($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X24);
            goto L_8010F1F8;
    }
    goto skip_4;
    // 0x8010F2FC: lhu         $t1, 0x24($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X24);
    skip_4:
L_8010F300:
    // 0x8010F300: jal         0x800CCEAC
    // 0x8010F304: nop

    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_6;
    // 0x8010F304: nop

    after_6:
L_8010F308:
    // 0x8010F308: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8010F30C:
    // 0x8010F30C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010F310: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010F314: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010F318: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8010F31C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8010F320: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8010F324: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8010F328: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8010F32C: jr          $ra
    // 0x8010F330: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8010F330: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ftBossGootsubusuWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159CA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80159CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159CAC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80159CB0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80159CB4: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80159CB8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80159CBC: lwc1        $f0, 0xB20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XB20);
    // 0x80159CC0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80159CC4: nop

    // 0x80159CC8: bc1fl       L_80159CDC
    if (!c1cs) {
        // 0x80159CCC: lwc1        $f0, 0xB1C($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0XB1C);
            goto L_80159CDC;
    }
    goto skip_0;
    // 0x80159CCC: lwc1        $f0, 0xB1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XB1C);
    skip_0:
    // 0x80159CD0: b           L_80159CF0
    // 0x80159CD4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_80159CF0;
    // 0x80159CD4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80159CD8: lwc1        $f0, 0xB1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XB1C);
L_80159CDC:
    // 0x80159CDC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80159CE0: nop

    // 0x80159CE4: bc1fl       L_80159CF4
    if (!c1cs) {
        // 0x80159CE8: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80159CF4;
    }
    goto skip_1;
    // 0x80159CE8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    skip_1:
    // 0x80159CEC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80159CF0:
    // 0x80159CF0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80159CF4:
    // 0x80159CF4: jal         0x800DE348
    // 0x80159CF8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCommonUpdateFighterProjectFloor(rdram, ctx);
        goto after_0;
    // 0x80159CF8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80159CFC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80159D00: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80159D04: lwc1        $f2, -0x3800($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3800);
    // 0x80159D08: lwc1        $f4, 0xF0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x80159D0C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80159D10: add.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80159D14: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80159D18: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80159D1C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80159D20: swc1        $f2, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = ctx->f2.u32l;
    // 0x80159D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159D28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80159D2C: jr          $ra
    // 0x80159D30: nop

    return;
    // 0x80159D30: nop

;}
RECOMP_FUNC void ifCommonPlayerArrowsRightProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111640: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80111644: lbu         $v0, 0x1590($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1590);
    // 0x80111648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011164C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111650: beq         $v0, $zero, L_80111674
    if (ctx->r2 == 0) {
        // 0x80111654: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80111674;
    }
    // 0x80111654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80111658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8011165C: bne         $v0, $at, L_8011166C
    if (ctx->r2 != ctx->r1) {
        // 0x80111660: nop
    
            goto L_8011166C;
    }
    // 0x80111660: nop

    // 0x80111664: jal         0x801115BC
    // 0x80111668: nop

    ifCommonPlayerArrowsAddAnim(rdram, ctx);
        goto after_0;
    // 0x80111668: nop

    after_0:
L_8011166C:
    // 0x8011166C: jal         0x8000DF34
    // 0x80111670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x80111670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80111674:
    // 0x80111674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011167C: jr          $ra
    // 0x80111680: nop

    return;
    // 0x80111680: nop

;}
RECOMP_FUNC void mnPlayersVSUpdatePlayerKindSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013295C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132960: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132968: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8013296C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80132970: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80132974: addiu       $t7, $t7, -0x4A60
    ctx->r15 = ADD32(ctx->r15, -0X4A60);
    // 0x80132978: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013297C: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
    // 0x80132980: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132984: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132988: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013298C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132990: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132994: jal         0x8000B760
    // 0x80132998: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80132998: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x8013299C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801329A0: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801329A4: lw          $t3, -0x3B60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3B60);
    // 0x801329A8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801329AC: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x801329B0: lw          $t2, 0x18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X18);
    // 0x801329B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801329B8: jal         0x800CCFDC
    // 0x801329BC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x801329BC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x801329C0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x801329C4: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801329C8: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x801329CC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x801329D0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801329D4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801329D8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801329DC: addiu       $t6, $t5, 0x40
    ctx->r14 = ADD32(ctx->r13, 0X40);
    // 0x801329E0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801329E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801329E8: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x801329EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801329F0: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801329F4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x801329F8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801329FC: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132A00: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132A08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80132A0C: jr          $ra
    // 0x80132A10: nop

    return;
    // 0x80132A10: nop

;}
RECOMP_FUNC void ftPhysicsApplyAirVelDriftFastFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D9164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D9168: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D916C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D9170: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800D9174: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x800D9178: jal         0x800D8DB0
    // 0x800D917C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsCheckSetFastFall(rdram, ctx);
        goto after_0;
    // 0x800D917C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D9180: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x800D9184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D9188: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D918C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800D9190: bgez        $t8, L_800D91A8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D9194: nop
    
            goto L_800D91A8;
    }
    // 0x800D9194: nop

    // 0x800D9198: jal         0x800D8DA0
    // 0x800D919C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsApplyFastFall(rdram, ctx);
        goto after_1;
    // 0x800D919C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D91A0: b           L_800D91B4
    // 0x800D91A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800D91B4;
    // 0x800D91A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D91A8:
    // 0x800D91A8: jal         0x800D8E50
    // 0x800D91AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_2;
    // 0x800D91AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800D91B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D91B4:
    // 0x800D91B4: jal         0x800D8FA8
    // 0x800D91B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_3;
    // 0x800D91B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800D91BC: bne         $v0, $zero, L_800D91D8
    if (ctx->r2 != 0) {
        // 0x800D91C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D91D8;
    }
    // 0x800D91C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D91C4: jal         0x800D9044
    // 0x800D91C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsClampAirVelXStickDefault(rdram, ctx);
        goto after_4;
    // 0x800D91C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800D91CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D91D0: jal         0x800D9074
    // 0x800D91D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_5;
    // 0x800D91D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
L_800D91D8:
    // 0x800D91D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D91DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D91E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D91E4: jr          $ra
    // 0x800D91E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D91E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonThrownKirbyStarSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C508: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8014C50C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014C510: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014C514: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8014C518: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014C51C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8014C520: lw          $t7, 0x1074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1074);
    // 0x8014C524: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x8014C528: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8014C52C: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x8014C530: bne         $t9, $zero, L_8014C548
    if (ctx->r25 != 0) {
        // 0x8014C534: addu        $t0, $t7, $t8
        ctx->r8 = ADD32(ctx->r15, ctx->r24);
            goto L_8014C548;
    }
    // 0x8014C534: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8014C538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014C53C: jal         0x800DEEC8
    // 0x8014C540: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8014C540: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8014C544: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_8014C548:
    // 0x8014C548: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8014C54C: addiu       $t1, $t1, -0x3B28
    ctx->r9 = ADD32(ctx->r9, -0X3B28);
    // 0x8014C550: sw          $t1, 0xA0C($s0)
    MEM_W(0XA0C, ctx->r16) = ctx->r9;
    // 0x8014C554: addiu       $t2, $zero, 0x200
    ctx->r10 = ADD32(0, 0X200);
    // 0x8014C558: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8014C55C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8014C560: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8014C564: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x8014C568: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014C56C: jal         0x800E6F24
    // 0x8014C570: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014C570: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8014C574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014C578: jal         0x800E8098
    // 0x8014C57C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014C57C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x8014C580: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8014C584: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8014C588: addiu       $t3, $t3, -0x41AC
    ctx->r11 = ADD32(ctx->r11, -0X41AC);
    // 0x8014C58C: sw          $t3, 0x9F8($s0)
    MEM_W(0X9F8, ctx->r16) = ctx->r11;
    // 0x8014C590: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8014C594: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8014C598: addiu       $a2, $zero, 0x310
    ctx->r6 = ADD32(0, 0X310);
    // 0x8014C59C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8014C5A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8014C5A4:
    // 0x8014C5A4: lw          $t4, 0x294($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X294);
    // 0x8014C5A8: addiu       $v1, $v1, 0xC4
    ctx->r3 = ADD32(ctx->r3, 0XC4);
    // 0x8014C5AC: bne         $a0, $t4, L_8014C5CC
    if (ctx->r4 != ctx->r12) {
        // 0x8014C5B0: nop
    
            goto L_8014C5CC;
    }
    // 0x8014C5B0: nop

    // 0x8014C5B4: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8014C5B8: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014C5BC: mflo        $t6
    ctx->r14 = lo;
    // 0x8014C5C0: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8014C5C4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8014C5C8: sw          $t8, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->r24;
L_8014C5CC:
    // 0x8014C5CC: bne         $v1, $a2, L_8014C5A4
    if (ctx->r3 != ctx->r6) {
        // 0x8014C5D0: addiu       $v0, $v0, 0xC4
        ctx->r2 = ADD32(ctx->r2, 0XC4);
            goto L_8014C5A4;
    }
    // 0x8014C5D0: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x8014C5D4: lbu         $t1, 0x18E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X18E);
    // 0x8014C5D8: lbu         $t6, 0x18D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18D);
    // 0x8014C5DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8014C5E0: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x8014C5E4: sb          $t2, 0x18E($s0)
    MEM_B(0X18E, ctx->r16) = ctx->r10;
    // 0x8014C5E8: lhu         $t3, 0x18E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X18E);
    // 0x8014C5EC: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8014C5F0: srl         $t4, $t3, 15
    ctx->r12 = S32(U32(ctx->r11) >> 15);
    // 0x8014C5F4: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8014C5F8: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8014C5FC: sb          $t8, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r24;
    // 0x8014C600: jal         0x800E8A24
    // 0x8014C604: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_3;
    // 0x8014C604: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x8014C608: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8014C60C: jal         0x800E7F7C
    // 0x8014C610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_4;
    // 0x8014C610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8014C614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014C618: jal         0x8014E3EC
    // 0x8014C61C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ftCommonCaptureTrappedInitBreakoutVars(rdram, ctx);
        goto after_5;
    // 0x8014C61C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x8014C620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014C624: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014C628: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014C62C: jr          $ra
    // 0x8014C630: nop

    return;
    // 0x8014C630: nop

;}
RECOMP_FUNC void itStarmieNFollowSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801821E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801821EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801821F0: jal         0x801820CC
    // 0x801821F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itStarmieNFollowInitVars(rdram, ctx);
        goto after_0;
    // 0x801821F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801821F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801821FC: addiu       $a1, $a1, -0x4E5C
    ctx->r5 = ADD32(ctx->r5, -0X4E5C);
    // 0x80182200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80182204: jal         0x80172EC8
    // 0x80182208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80182208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8018220C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80182214: jr          $ra
    // 0x80182218: nop

    return;
    // 0x80182218: nop

;}
RECOMP_FUNC void ftKirbySpecialAirLwHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161C0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161C10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161C14: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80161C18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80161C1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80161C20: addiu       $a1, $zero, 0x109
    ctx->r5 = ADD32(0, 0X109);
    // 0x80161C24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161C28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80161C2C: jal         0x800E6F24
    // 0x80161C30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161C30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80161C34: jal         0x800E0830
    // 0x80161C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80161C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80161C3C: jal         0x80161360
    // 0x80161C40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftKirbySpecialLwUnused(rdram, ctx);
        goto after_2;
    // 0x80161C40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80161C44: jal         0x80161468
    // 0x80161C48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbySpecialLwSetDropFallVel(rdram, ctx);
        goto after_3;
    // 0x80161C48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80161C4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161C50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161C54: jr          $ra
    // 0x80161C58: nop

    return;
    // 0x80161C58: nop

;}
RECOMP_FUNC void func_ovl28_80133CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133CA0: jr          $ra
    // 0x80133CA4: nop

    return;
    // 0x80133CA4: nop

;}
RECOMP_FUNC void sc1PBonusStageFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E5F8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8018E5FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018E600: jal         0x8018D0F0
    // 0x8018E604: nop

    sc1PBonusStageInitVars(rdram, ctx);
        goto after_0;
    // 0x8018E604: nop

    after_0:
    // 0x8018E608: jal         0x8018ED70
    // 0x8018E60C: nop

    sc1PBonusStageSetupFiles(rdram, ctx);
        goto after_1;
    // 0x8018E60C: nop

    after_1:
    // 0x8018E610: jal         0x8018D330
    // 0x8018E614: nop

    sc1PBonusStageBonus1LoadFile(rdram, ctx);
        goto after_2;
    // 0x8018E614: nop

    after_2:
    // 0x8018E618: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8018E61C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018E620: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018E624: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018E628: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018E62C: jal         0x8000B9FC
    // 0x8018E630: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_3;
    // 0x8018E630: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018E634: jal         0x80115890
    // 0x8018E638: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018E638: nop

    after_4:
    // 0x8018E63C: jal         0x800EC130
    // 0x8018E640: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018E640: nop

    after_5:
    // 0x8018E644: jal         0x800FC284
    // 0x8018E648: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018E648: nop

    after_6:
    // 0x8018E64C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018E650: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018E654: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018E658: jal         0x8010E598
    // 0x8018E65C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018E65C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018E660: jal         0x8010DB54
    // 0x8018E664: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018E664: nop

    after_8:
    // 0x8018E668: jal         0x80104BDC
    // 0x8018E66C: nop

    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_9;
    // 0x8018E66C: nop

    after_9:
    // 0x8018E670: jal         0x8010DB00
    // 0x8018E674: nop

    gmCameraMakeBattleCamera(rdram, ctx);
        goto after_10;
    // 0x8018E674: nop

    after_10:
    // 0x8018E678: jal         0x8016DEA0
    // 0x8018E67C: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018E67C: nop

    after_11:
    // 0x8018E680: jal         0x80105600
    // 0x8018E684: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_12;
    // 0x8018E684: nop

    after_12:
    // 0x8018E688: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018E68C: jal         0x800D7194
    // 0x8018E690: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_13;
    // 0x8018E690: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x8018E694: jal         0x801654B0
    // 0x8018E698: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_14;
    // 0x8018E698: nop

    after_14:
    // 0x8018E69C: jal         0x800FD300
    // 0x8018E6A0: nop

    efManagerInitEffects(rdram, ctx);
        goto after_15;
    // 0x8018E6A0: nop

    after_15:
    // 0x8018E6A4: jal         0x80115DE8
    // 0x8018E6A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    ifScreenFlashMakeInterface(rdram, ctx);
        goto after_16;
    // 0x8018E6A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_16:
    // 0x8018E6AC: jal         0x801156E4
    // 0x8018E6B0: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_17;
    // 0x8018E6B0: nop

    after_17:
    // 0x8018E6B4: jal         0x801653E0
    // 0x8018E6B8: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_18;
    // 0x8018E6B8: nop

    after_18:
    // 0x8018E6BC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8018E6C0: addiu       $t8, $t8, 0x6DD0
    ctx->r24 = ADD32(ctx->r24, 0X6DD0);
    // 0x8018E6C4: addiu       $t1, $t8, 0x3C
    ctx->r9 = ADD32(ctx->r24, 0X3C);
    // 0x8018E6C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018E6CC: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
L_8018E6D0:
    // 0x8018E6D0: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8018E6D4: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8018E6D8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018E6DC: sw          $t0, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r8;
    // 0x8018E6E0: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x8018E6E4: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x8018E6E8: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x8018E6EC: bne         $t8, $t1, L_8018E6D0
    if (ctx->r24 != ctx->r9) {
        // 0x8018E6F0: sw          $t0, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r8;
            goto L_8018E6D0;
    }
    // 0x8018E6F0: sw          $t0, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r8;
    // 0x8018E6F4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8018E6F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018E6FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018E700: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8018E704: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x8018E708: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8018E70C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8018E710:
    // 0x8018E710: lbu         $t2, 0x22($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X22);
    // 0x8018E714: beql        $a0, $t2, L_8018E7FC
    if (ctx->r4 == ctx->r10) {
        // 0x8018E718: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8018E7FC;
    }
    goto skip_0;
    // 0x8018E718: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x8018E71C: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    // 0x8018E720: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8018E724: jal         0x800D786C
    // 0x8018E728: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_19;
    // 0x8018E728: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_19:
    // 0x8018E72C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8018E730: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E734: lw          $t3, 0x50E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50E8);
    // 0x8018E738: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8018E73C: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8018E740: lbu         $t5, 0x23($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X23);
    // 0x8018E744: jal         0x8018E0E0
    // 0x8018E748: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    sc1PBonusStageGetPlayerStartPosition(rdram, ctx);
        goto after_20;
    // 0x8018E748: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    after_20:
    // 0x8018E74C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018E750: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018E754: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x8018E758: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E75C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018E760: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8018E764: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018E768: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018E76C: bc1f        L_8018E780
    if (!c1cs) {
        // 0x8018E770: addu        $t2, $t2, $a2
        ctx->r10 = ADD32(ctx->r10, ctx->r6);
            goto L_8018E780;
    }
    // 0x8018E770: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x8018E774: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018E778: b           L_8018E788
    // 0x8018E77C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_8018E788;
    // 0x8018E77C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_8018E780:
    // 0x8018E780: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018E784: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_8018E788:
    // 0x8018E788: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8018E78C: sb          $zero, 0x48($sp)
    MEM_B(0X48, ctx->r29) = 0;
    // 0x8018E790: sb          $a2, 0x49($sp)
    MEM_B(0X49, ctx->r29) = ctx->r6;
    // 0x8018E794: sb          $t8, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = ctx->r24;
    // 0x8018E798: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x8018E79C: lbu         $t9, 0x26($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X26);
    // 0x8018E7A0: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018E7A4: addiu       $t3, $t3, 0x5228
    ctx->r11 = ADD32(ctx->r11, 0X5228);
    // 0x8018E7A8: sb          $t9, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r25;
    // 0x8018E7AC: lbu         $t0, 0x22($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X22);
    // 0x8018E7B0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8018E7B4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8018E7B8: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8018E7BC: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8018E7C0: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    // 0x8018E7C4: jal         0x800D78B4
    // 0x8018E7C8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_21;
    // 0x8018E7C8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    after_21:
    // 0x8018E7CC: lbu         $t6, 0x53($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X53);
    // 0x8018E7D0: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8018E7D4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8018E7D8: ori         $t1, $t6, 0x80
    ctx->r9 = ctx->r14 | 0X80;
    // 0x8018E7DC: jal         0x800D7F3C
    // 0x8018E7E0: sb          $t1, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r9;
    ftManagerMakeFighter(rdram, ctx);
        goto after_22;
    // 0x8018E7E0: sb          $t1, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r9;
    after_22:
    // 0x8018E7E4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8018E7E8: jal         0x800E7C4C
    // 0x8018E7EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_23;
    // 0x8018E7EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_23:
    // 0x8018E7F0: b           L_8018E808
    // 0x8018E7F4: nop

        goto L_8018E808;
    // 0x8018E7F4: nop

    // 0x8018E7F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8018E7FC:
    // 0x8018E7FC: addiu       $v1, $v1, 0x74
    ctx->r3 = ADD32(ctx->r3, 0X74);
    // 0x8018E800: bne         $a2, $a1, L_8018E710
    if (ctx->r6 != ctx->r5) {
        // 0x8018E804: addiu       $v0, $v0, 0x74
        ctx->r2 = ADD32(ctx->r2, 0X74);
            goto L_8018E710;
    }
    // 0x8018E804: addiu       $v0, $v0, 0x74
    ctx->r2 = ADD32(ctx->r2, 0X74);
L_8018E808:
    // 0x8018E808: jal         0x800D782C
    // 0x8018E80C: nop

    ftManagerSetupFilesPlayablesAll(rdram, ctx);
        goto after_24;
    // 0x8018E80C: nop

    after_24:
    // 0x8018E810: jal         0x80114958
    // 0x8018E814: nop

    ifCommonBattleSetGameStatusWait(rdram, ctx);
        goto after_25;
    // 0x8018E814: nop

    after_25:
    // 0x8018E818: jal         0x8010DDC4
    // 0x8018E81C: nop

    gmCameraScreenFlashMakeCamera(rdram, ctx);
        goto after_26;
    // 0x8018E81C: nop

    after_26:
    // 0x8018E820: jal         0x8010E374
    // 0x8018E824: nop

    gmCameraMakeInterfaceCamera(rdram, ctx);
        goto after_27;
    // 0x8018E824: nop

    after_27:
    // 0x8018E828: jal         0x8010E498
    // 0x8018E82C: nop

    gmCameraMakeEffectCamera(rdram, ctx);
        goto after_28;
    // 0x8018E82C: nop

    after_28:
    // 0x8018E830: jal         0x80111BE4
    // 0x8018E834: nop

    ifCommonPlayerTagMakeInterface(rdram, ctx);
        goto after_29;
    // 0x8018E834: nop

    after_29:
    // 0x8018E838: jal         0x8018E5D8
    // 0x8018E83C: nop

    sc1PBonusStageSetPlayerInterfacePositions(rdram, ctx);
        goto after_30;
    // 0x8018E83C: nop

    after_30:
    // 0x8018E840: jal         0x8010F3C0
    // 0x8018E844: nop

    ifCommonPlayerDamageInitInterface(rdram, ctx);
        goto after_31;
    // 0x8018E844: nop

    after_31:
    // 0x8018E848: jal         0x80110514
    // 0x8018E84C: nop

    ifCommonPlayerStockInitInterface(rdram, ctx);
        goto after_32;
    // 0x8018E84C: nop

    after_32:
    // 0x8018E850: jal         0x8018E098
    // 0x8018E854: nop

    sc1PBonusStageMakeTaskSprites(rdram, ctx);
        goto after_33;
    // 0x8018E854: nop

    after_33:
    // 0x8018E858: jal         0x8018DCC4
    // 0x8018E85C: nop

    sc1PBonusStageMakeInterface(rdram, ctx);
        goto after_34;
    // 0x8018E85C: nop

    after_34:
    // 0x8018E860: jal         0x800FC3E8
    // 0x8018E864: nop

    mpCollisionSetPlayBGM(rdram, ctx);
        goto after_35;
    // 0x8018E864: nop

    after_35:
    // 0x8018E868: jal         0x800269C0
    // 0x8018E86C: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    func_800269C0_275C0(rdram, ctx);
        goto after_36;
    // 0x8018E86C: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_36:
    // 0x8018E870: jal         0x8018E344
    // 0x8018E874: nop

    sc1PBonusStageMakeTimer(rdram, ctx);
        goto after_37;
    // 0x8018E874: nop

    after_37:
    // 0x8018E878: jal         0x8018DD14
    // 0x8018E87C: nop

    sc1PBonusStageInitCamera(rdram, ctx);
        goto after_38;
    // 0x8018E87C: nop

    after_38:
    // 0x8018E880: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018E884: addiu       $t8, $t8, -0xFC4
    ctx->r24 = ADD32(ctx->r24, -0XFC4);
    // 0x8018E888: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8018E88C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x8018E890: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8018E894: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8018E898: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018E89C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8018E8A0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018E8A4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018E8A8: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x8018E8AC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8018E8B0: jal         0x800D4060
    // 0x8018E8B4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_39;
    // 0x8018E8B4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_39:
    // 0x8018E8B8: jal         0x8018E2E8
    // 0x8018E8BC: nop

    sc1PBonusStageMakeTimeUp(rdram, ctx);
        goto after_40;
    // 0x8018E8BC: nop

    after_40:
    // 0x8018E8C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018E8C4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8018E8C8: jr          $ra
    // 0x8018E8CC: nop

    return;
    // 0x8018E8CC: nop

;}
RECOMP_FUNC void __n_seqpStopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F39C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002F3A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002F3A4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8002F3A8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8002F3AC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002F3B0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002F3B4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002F3B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002F3BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002F3C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002F3C4: lw          $s0, 0x58($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X58);
    // 0x8002F3C8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8002F3CC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8002F3D0: beq         $s0, $zero, L_8002F474
    if (ctx->r16 == 0) {
        // 0x8002F3D4: addiu       $s7, $zero, 0x17
        ctx->r23 = ADD32(0, 0X17);
            goto L_8002F474;
    }
    // 0x8002F3D4: addiu       $s7, $zero, 0x17
    ctx->r23 = ADD32(0, 0X17);
    // 0x8002F3D8: addiu       $s6, $zero, 0x16
    ctx->r22 = ADD32(0, 0X16);
L_8002F3DC:
    // 0x8002F3DC: lh          $s3, 0xC($s0)
    ctx->r19 = MEM_H(ctx->r16, 0XC);
    // 0x8002F3E0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8002F3E4: beql        $s3, $s6, L_8002F3F8
    if (ctx->r19 == ctx->r22) {
        // 0x8002F3E8: lw          $t6, 0x10($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X10);
            goto L_8002F3F8;
    }
    goto skip_0;
    // 0x8002F3E8: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x8002F3EC: bne         $s3, $s7, L_8002F46C
    if (ctx->r19 != ctx->r23) {
        // 0x8002F3F0: nop
    
            goto L_8002F46C;
    }
    // 0x8002F3F0: nop

    // 0x8002F3F4: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
L_8002F3F8:
    // 0x8002F3F8: bne         $s2, $t6, L_8002F46C
    if (ctx->r18 != ctx->r14) {
        // 0x8002F3FC: nop
    
            goto L_8002F46C;
    }
    // 0x8002F3FC: nop

    // 0x8002F400: lw          $t9, 0x84($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X84);
    // 0x8002F404: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8002F408: addiu       $s4, $s5, 0x50
    ctx->r20 = ADD32(ctx->r21, 0X50);
    // 0x8002F40C: jalr        $t9
    // 0x8002F410: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002F410: nop

    after_0:
    // 0x8002F414: jal         0x80028C84
    // 0x8002F418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x8002F418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002F41C: beq         $s1, $zero, L_8002F434
    if (ctx->r17 == 0) {
        // 0x8002F420: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002F434;
    }
    // 0x8002F420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F424: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8002F428: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8002F42C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8002F430: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_8002F434:
    // 0x8002F434: jal         0x80028C60
    // 0x8002F438: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x8002F438: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x8002F43C: bnel        $s3, $s6, L_8002F458
    if (ctx->r19 != ctx->r22) {
        // 0x8002F440: lbu         $t3, 0x37($s2)
        ctx->r11 = MEM_BU(ctx->r18, 0X37);
            goto L_8002F458;
    }
    goto skip_1;
    // 0x8002F440: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
    skip_1:
    // 0x8002F444: lbu         $t1, 0x37($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X37);
    // 0x8002F448: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x8002F44C: b           L_8002F460
    // 0x8002F450: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
        goto L_8002F460;
    // 0x8002F450: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
    // 0x8002F454: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
L_8002F458:
    // 0x8002F458: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x8002F45C: sb          $t4, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r12;
L_8002F460:
    // 0x8002F460: lbu         $t5, 0x37($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X37);
    // 0x8002F464: beql        $t5, $zero, L_8002F478
    if (ctx->r13 == 0) {
        // 0x8002F468: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8002F478;
    }
    goto skip_2;
    // 0x8002F468: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
L_8002F46C:
    // 0x8002F46C: bne         $s1, $zero, L_8002F3DC
    if (ctx->r17 != 0) {
        // 0x8002F470: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8002F3DC;
    }
    // 0x8002F470: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8002F474:
    // 0x8002F474: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8002F478:
    // 0x8002F478: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002F47C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002F480: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F484: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002F488: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8002F48C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8002F490: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F494: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8002F498: jr          $ra
    // 0x8002F49C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002F49C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnVSRecordSetRowIconPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133740: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80133744: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133748: addiu       $t7, $t7, 0x680C
    ctx->r15 = ADD32(ctx->r15, 0X680C);
    // 0x8013374C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133750: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80133754: addiu       $t0, $t7, 0x60
    ctx->r8 = ADD32(ctx->r15, 0X60);
    // 0x80133758: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
L_8013375C:
    // 0x8013375C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133760: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133764: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133768: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x8013376C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80133770: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80133774: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133778: bne         $t7, $t0, L_8013375C
    if (ctx->r15 != ctx->r8) {
        // 0x8013377C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8013375C;
    }
    // 0x8013377C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133780: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133784: lw          $v0, 0x6C18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C18);
    // 0x80133788: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8013378C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133790: beq         $v0, $zero, L_801337AC
    if (ctx->r2 == 0) {
        // 0x80133794: addu        $t2, $t2, $t1
        ctx->r10 = ADD32(ctx->r10, ctx->r9);
            goto L_801337AC;
    }
    // 0x80133794: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80133798: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013379C: beq         $v0, $at, L_801337B8
    if (ctx->r2 == ctx->r1) {
        // 0x801337A0: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_801337B8;
    }
    // 0x801337A0: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x801337A4: b           L_801337CC
    // 0x801337A8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
        goto L_801337CC;
    // 0x801337A8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
L_801337AC:
    // 0x801337AC: lw          $t2, 0x6C28($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6C28);
    // 0x801337B0: b           L_801337C8
    // 0x801337B4: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
        goto L_801337C8;
    // 0x801337B4: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
L_801337B8:
    // 0x801337B8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801337BC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801337C0: lw          $t4, 0x6C58($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6C58);
    // 0x801337C4: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
L_801337C8:
    // 0x801337C8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
L_801337CC:
    // 0x801337CC: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x801337D0: jal         0x801326EC
    // 0x801337D4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_0;
    // 0x801337D4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    after_0:
    // 0x801337D8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x801337DC: beq         $v0, $zero, L_8013383C
    if (ctx->r2 == 0) {
        // 0x801337E0: lw          $a2, 0x88($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X88);
            goto L_8013383C;
    }
    // 0x801337E0: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x801337E4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801337E8: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x801337EC: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x801337F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801337F4: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x801337F8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x801337FC: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x80133800: sll         $t0, $t5, 3
    ctx->r8 = S32(ctx->r13 << 3);
    // 0x80133804: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x80133808: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8013380C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133810: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133814: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80133818: lui         $at, 0x4278
    ctx->r1 = S32(0X4278 << 16);
    // 0x8013381C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133820: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80133824: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80133828: swc1        $f8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f8.u32l;
    // 0x8013382C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80133830: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80133834: b           L_8013387C
    // 0x80133838: swc1        $f8, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f8.u32l;
        goto L_8013387C;
    // 0x80133838: swc1        $f8, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f8.u32l;
L_8013383C:
    // 0x8013383C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80133840: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80133844: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80133848: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x8013384C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80133850: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80133854: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133858: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013385C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80133860: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133864: lui         $at, 0x4278
    ctx->r1 = S32(0X4278 << 16);
    // 0x80133868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013386C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80133870: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80133874: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
    // 0x80133878: swc1        $f16, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f16.u32l;
L_8013387C:
    // 0x8013387C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133880: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80133884: jr          $ra
    // 0x80133888: nop

    return;
    // 0x80133888: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AFB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015AFBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015AFC0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015AFC4: jal         0x800DE6E4
    // 0x8015AFC8: addiu       $a1, $a1, -0x5024
    ctx->r5 = ADD32(ctx->r5, -0X5024);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015AFC8: addiu       $a1, $a1, -0x5024
    ctx->r5 = ADD32(ctx->r5, -0X5024);
    after_0:
    // 0x8015AFCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015AFD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015AFD4: jr          $ra
    // 0x8015AFD8: nop

    return;
    // 0x8015AFD8: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DE80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014DE84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014DE88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014DE8C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8014DE90: jal         0x800DEEC8
    // 0x8014DE94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8014DE94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014DE98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014DE9C: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
    // 0x8014DEA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014DEA4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8014DEA8: jal         0x800E6F24
    // 0x8014DEAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014DEAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8014DEB0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8014DEB4: jal         0x800E8098
    // 0x8014DEB8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014DEB8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x8014DEBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014DEC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014DEC4: jr          $ra
    // 0x8014DEC8: nop

    return;
    // 0x8014DEC8: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137CAC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80137CB0: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80137CB4: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80137CB8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137CBC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80137CC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80137CC4: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80137CC8: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80137CCC: addiu       $t8, $t8, -0x7728
    ctx->r24 = ADD32(ctx->r24, -0X7728);
    // 0x80137CD0: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80137CD4: addiu       $t0, $t0, -0x7760
    ctx->r8 = ADD32(ctx->r8, -0X7760);
    // 0x80137CD8: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80137CDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80137CE0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80137CE4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80137CE8: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80137CEC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80137CF0: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80137CF4: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80137CF8: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80137CFC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80137D00: jal         0x800CDF78
    // 0x80137D04: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80137D04: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80137D08: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80137D0C: addiu       $s0, $s0, 0x7F60
    ctx->r16 = ADD32(ctx->r16, 0X7F60);
    // 0x80137D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137D14: jal         0x800CDEEC
    // 0x80137D18: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80137D18: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80137D1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137D20: jal         0x80004980
    // 0x80137D24: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80137D24: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80137D28: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80137D2C: addiu       $a2, $a2, -0x7368
    ctx->r6 = ADD32(ctx->r6, -0X7368);
    // 0x80137D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137D34: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80137D38: jal         0x800CDE04
    // 0x80137D3C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80137D3C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80137D40: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80137D44: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137D48: addiu       $a1, $a1, 0x7700
    ctx->r5 = ADD32(ctx->r5, 0X7700);
    // 0x80137D4C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80137D50: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80137D54: jal         0x80009968
    // 0x80137D58: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80137D58: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_4:
    // 0x80137D5C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80137D60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80137D64: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80137D68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80137D6C: jal         0x8000B9FC
    // 0x80137D70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80137D70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80137D74: jal         0x80115890
    // 0x80137D78: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80137D78: nop

    after_6:
    // 0x80137D7C: jal         0x800FD300
    // 0x80137D80: nop

    efManagerInitEffects(rdram, ctx);
        goto after_7;
    // 0x80137D80: nop

    after_7:
    // 0x80137D84: jal         0x801379CC
    // 0x80137D88: nop

    mnPlayers1PTrainingInitVars(rdram, ctx);
        goto after_8;
    // 0x80137D88: nop

    after_8:
    // 0x80137D8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80137D90: jal         0x800D7194
    // 0x80137D94: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x80137D94: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80137D98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80137D9C:
    // 0x80137D9C: jal         0x800D786C
    // 0x80137DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x80137DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80137DA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80137DA8: slti        $at, $s0, 0xC
    ctx->r1 = SIGNED(ctx->r16) < 0XC ? 1 : 0;
    // 0x80137DAC: bne         $at, $zero, L_80137D9C
    if (ctx->r1 != 0) {
        // 0x80137DB0: nop
    
            goto L_80137D9C;
    }
    // 0x80137DB0: nop

    // 0x80137DB4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137DB8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80137DBC: addiu       $s0, $s0, 0xD9C
    ctx->r16 = ADD32(ctx->r16, 0XD9C);
    // 0x80137DC0: addiu       $v1, $v1, -0x7AA8
    ctx->r3 = ADD32(ctx->r3, -0X7AA8);
L_80137DC4:
    // 0x80137DC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80137DC8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80137DCC: jal         0x80004980
    // 0x80137DD0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x80137DD0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_11:
    // 0x80137DD4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80137DD8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80137DDC: addiu       $t2, $t2, -0x77C8
    ctx->r10 = ADD32(ctx->r10, -0X77C8);
    // 0x80137DE0: addiu       $v1, $v1, 0xB8
    ctx->r3 = ADD32(ctx->r3, 0XB8);
    // 0x80137DE4: bne         $v1, $t2, L_80137DC4
    if (ctx->r3 != ctx->r10) {
        // 0x80137DE8: sw          $v0, -0x84($v1)
        MEM_W(-0X84, ctx->r3) = ctx->r2;
            goto L_80137DC4;
    }
    // 0x80137DE8: sw          $v0, -0x84($v1)
    MEM_W(-0X84, ctx->r3) = ctx->r2;
    // 0x80137DEC: jal         0x801327C4
    // 0x80137DF0: nop

    mnPlayers1PTrainingMakePortraitCamera(rdram, ctx);
        goto after_12;
    // 0x80137DF0: nop

    after_12:
    // 0x80137DF4: jal         0x80135FE8
    // 0x80137DF8: nop

    mnPlayers1PTrainingMakeCursorCamera(rdram, ctx);
        goto after_13;
    // 0x80137DF8: nop

    after_13:
    // 0x80137DFC: jal         0x80136088
    // 0x80137E00: nop

    mnPlayers1PTrainingMakePuckCamera(rdram, ctx);
        goto after_14;
    // 0x80137E00: nop

    after_14:
    // 0x80137E04: jal         0x80132AE4
    // 0x80137E08: nop

    mnPlayers1PTrainingMakePlayerKindCamera(rdram, ctx);
        goto after_15;
    // 0x80137E08: nop

    after_15:
    // 0x80137E0C: jal         0x801329A4
    // 0x80137E10: nop

    mnPlayers1PTrainingMakeGateCamera(rdram, ctx);
        goto after_16;
    // 0x80137E10: nop

    after_16:
    // 0x80137E14: jal         0x80132A44
    // 0x80137E18: nop

    mnPlayers1PTrainingMakePlayerKindSelectCamera(rdram, ctx);
        goto after_17;
    // 0x80137E18: nop

    after_17:
    // 0x80137E1C: jal         0x801339A0
    // 0x80137E20: nop

    mnPlayers1PTrainingMakeFighterCamera(rdram, ctx);
        goto after_18;
    // 0x80137E20: nop

    after_18:
    // 0x80137E24: jal         0x80132B84
    // 0x80137E28: nop

    mnPlayers1PTrainingMakeTeamSelectCamera(rdram, ctx);
        goto after_19;
    // 0x80137E28: nop

    after_19:
    // 0x80137E2C: jal         0x80136128
    // 0x80137E30: nop

    mnPlayers1PTrainingMakeHandicapLevelCamera(rdram, ctx);
        goto after_20;
    // 0x80137E30: nop

    after_20:
    // 0x80137E34: jal         0x80132864
    // 0x80137E38: nop

    mnPlayers1PTrainingMakePortraitWallpaperCamera(rdram, ctx);
        goto after_21;
    // 0x80137E38: nop

    after_21:
    // 0x80137E3C: jal         0x80132904
    // 0x80137E40: nop

    mnPlayers1PTrainingMakePortraitFlashCamera(rdram, ctx);
        goto after_22;
    // 0x80137E40: nop

    after_22:
    // 0x80137E44: jal         0x801361C8
    // 0x80137E48: nop

    mnPlayers1PTrainingMakeReadyCamera(rdram, ctx);
        goto after_23;
    // 0x80137E48: nop

    after_23:
    // 0x80137E4C: jal         0x80133014
    // 0x80137E50: nop

    mnPlayers1PTrainingMakeWallpaper(rdram, ctx);
        goto after_24;
    // 0x80137E50: nop

    after_24:
    // 0x80137E54: jal         0x80132594
    // 0x80137E58: nop

    mnPlayers1PTrainingMakePortraitAll(rdram, ctx);
        goto after_25;
    // 0x80137E58: nop

    after_25:
    // 0x80137E5C: jal         0x80137C74
    // 0x80137E60: nop

    mnPlayers1PTrainingInitSlotAll(rdram, ctx);
        goto after_26;
    // 0x80137E60: nop

    after_26:
    // 0x80137E64: jal         0x80133140
    // 0x80137E68: nop

    mnPlayers1PTrainingMakeLabels(rdram, ctx);
        goto after_27;
    // 0x80137E68: nop

    after_27:
    // 0x80137E6C: jal         0x80136DD8
    // 0x80137E70: nop

    mnPlayers1PTrainingMakePuckAdjust(rdram, ctx);
        goto after_28;
    // 0x80137E70: nop

    after_28:
    // 0x80137E74: jal         0x80136E94
    // 0x80137E78: nop

    mnPlayers1PTrainingMakePuckGlow(rdram, ctx);
        goto after_29;
    // 0x80137E78: nop

    after_29:
    // 0x80137E7C: jal         0x80136F84
    // 0x80137E80: nop

    mnPlayers1PTrainingMakeCostumeSync(rdram, ctx);
        goto after_30;
    // 0x80137E80: nop

    after_30:
    // 0x80137E84: jal         0x801370BC
    // 0x80137E88: nop

    mnPlayers1PTrainingMakeSpotlight(rdram, ctx);
        goto after_31;
    // 0x80137E88: nop

    after_31:
    // 0x80137E8C: jal         0x80137354
    // 0x80137E90: nop

    mnPlayers1PTrainingMakeReady(rdram, ctx);
        goto after_32;
    // 0x80137E90: nop

    after_32:
    // 0x80137E94: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80137E98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80137E9C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80137EA0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80137EA4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80137EA8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80137EAC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80137EB0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80137EB4: jal         0x803904E0
    // 0x80137EB8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_33;
    // 0x80137EB8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_33:
    // 0x80137EBC: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80137EC0: lbu         $t5, 0x4AD1($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4AD1);
    // 0x80137EC4: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80137EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137ECC: beq         $t5, $at, L_80137EDC
    if (ctx->r13 == ctx->r1) {
        // 0x80137ED0: nop
    
            goto L_80137EDC;
    }
    // 0x80137ED0: nop

    // 0x80137ED4: jal         0x80020AB4
    // 0x80137ED8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    syAudioPlayBGM(rdram, ctx);
        goto after_34;
    // 0x80137ED8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_34:
L_80137EDC:
    // 0x80137EDC: jal         0x800266A0
    // 0x80137EE0: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_35;
    // 0x80137EE0: nop

    after_35:
    // 0x80137EE4: jal         0x800269C0
    // 0x80137EE8: addiu       $a0, $zero, 0x212
    ctx->r4 = ADD32(0, 0X212);
    func_800269C0_275C0(rdram, ctx);
        goto after_36;
    // 0x80137EE8: addiu       $a0, $zero, 0x212
    ctx->r4 = ADD32(0, 0X212);
    after_36:
    // 0x80137EEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80137EF0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80137EF4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80137EF8: jr          $ra
    // 0x80137EFC: nop

    return;
    // 0x80137EFC: nop

;}
RECOMP_FUNC void func_ovl27_80134EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134EB0: jr          $ra
    // 0x80134EB4: nop

    return;
    // 0x80134EB4: nop

;}
RECOMP_FUNC void ftCaptainSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FB40: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015FB44: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x8015FB48: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8015FB4C: jr          $ra
    // 0x8015FB50: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    return;
    // 0x8015FB50: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
;}
RECOMP_FUNC void efManagerItemGetSwirlProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010445C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80104460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104464: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104468: jal         0x800FDAFC
    // 0x8010446C: addiu       $a0, $a0, -0x1868
    ctx->r4 = ADD32(ctx->r4, -0X1868);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x8010446C: addiu       $a0, $a0, -0x1868
    ctx->r4 = ADD32(ctx->r4, -0X1868);
    after_0:
    // 0x80104470: bne         $v0, $zero, L_80104480
    if (ctx->r2 != 0) {
        // 0x80104474: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80104480;
    }
    // 0x80104474: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104478: b           L_801044A4
    // 0x8010447C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801044A4;
    // 0x8010447C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80104480:
    // 0x80104480: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80104484: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80104488: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8010448C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80104490: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80104494: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80104498: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x8010449C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801044A0: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_801044A4:
    // 0x801044A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801044A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801044AC: jr          $ra
    // 0x801044B0: nop

    return;
    // 0x801044B0: nop

;}
RECOMP_FUNC void ftComputerFollowObjectiveAlly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139A60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80139A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80139A68: jal         0x8013837C
    // 0x80139A6C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_ovl3_8013837C(rdram, ctx);
        goto after_0;
    // 0x80139A6C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80139A70: beq         $v0, $zero, L_80139D54
    if (ctx->r2 == 0) {
        // 0x80139A74: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80139D54;
    }
    // 0x80139A74: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139A78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80139A7C: beql        $v0, $at, L_80139D60
    if (ctx->r2 == ctx->r1) {
        // 0x80139A80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80139D60;
    }
    goto skip_0;
    // 0x80139A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80139A84: jal         0x80018948
    // 0x80139A88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80139A88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_1:
    // 0x80139A8C: jal         0x80018948
    // 0x80139A90: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x80139A90: nop

    after_2:
    // 0x80139A94: jal         0x80018948
    // 0x80139A98: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x80139A98: nop

    after_3:
    // 0x80139A9C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139AA0: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x80139AA4: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x80139AA8: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80139AAC: lwc1        $f2, 0x1C($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80139AB0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80139AB4: nop

    // 0x80139AB8: bc1fl       L_80139AD4
    if (!c1cs) {
        // 0x80139ABC: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80139AD4;
    }
    goto skip_1;
    // 0x80139ABC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_1:
    // 0x80139AC0: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x80139AC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80139AC8: beq         $t7, $at, L_80139AF0
    if (ctx->r15 == ctx->r1) {
        // 0x80139ACC: nop
    
            goto L_80139AF0;
    }
    // 0x80139ACC: nop

    // 0x80139AD0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80139AD4:
    // 0x80139AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80139AD8: bc1f        L_80139AF8
    if (!c1cs) {
        // 0x80139ADC: nop
    
            goto L_80139AF8;
    }
    // 0x80139ADC: nop

    // 0x80139AE0: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x80139AE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80139AE8: bne         $t8, $at, L_80139AF8
    if (ctx->r24 != ctx->r1) {
        // 0x80139AEC: nop
    
            goto L_80139AF8;
    }
    // 0x80139AEC: nop

L_80139AF0:
    // 0x80139AF0: b           L_80139AF8
    // 0x80139AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80139AF8;
    // 0x80139AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80139AF8:
    // 0x80139AF8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80139AFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80139B00: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80139B04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80139B08: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80139B0C: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80139B10: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80139B14: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80139B18: nop

    // 0x80139B1C: bc1fl       L_80139B7C
    if (!c1cs) {
        // 0x80139B20: sb          $zero, 0x34($v1)
        MEM_B(0X34, ctx->r3) = 0;
            goto L_80139B7C;
    }
    goto skip_2;
    // 0x80139B20: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
    skip_2:
    // 0x80139B24: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139B28: jal         0x80138EE4
    // 0x80139B2C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_ovl3_80138EE4(rdram, ctx);
        goto after_4;
    // 0x80139B2C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_4:
    // 0x80139B30: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139B34: beq         $v0, $zero, L_80139B44
    if (ctx->r2 == 0) {
        // 0x80139B38: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80139B44;
    }
    // 0x80139B38: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139B3C: b           L_80139D5C
    // 0x80139B40: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
        goto L_80139D5C;
    // 0x80139B40: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_80139B44:
    // 0x80139B44: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    // 0x80139B48: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139B4C: jal         0x80132EC8
    // 0x80139B50: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    ftComputerCheckDetectTarget(rdram, ctx);
        goto after_5;
    // 0x80139B50: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_5:
    // 0x80139B54: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139B58: beq         $v0, $zero, L_80139B68
    if (ctx->r2 == 0) {
        // 0x80139B5C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80139B68;
    }
    // 0x80139B5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139B60: b           L_80139D5C
    // 0x80139B64: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
        goto L_80139D5C;
    // 0x80139B64: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_80139B68:
    // 0x80139B68: jal         0x8013877C
    // 0x80139B6C: nop

    func_ovl3_8013877C(rdram, ctx);
        goto after_6;
    // 0x80139B6C: nop

    after_6:
    // 0x80139B70: b           L_80139D60
    // 0x80139B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80139D60;
    // 0x80139B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139B78: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
L_80139B7C:
    // 0x80139B7C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80139B80: jal         0x80138AA8
    // 0x80139B84: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_ovl3_80138AA8(rdram, ctx);
        goto after_7;
    // 0x80139B84: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_7:
    // 0x80139B88: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139B8C: beq         $v0, $zero, L_80139B9C
    if (ctx->r2 == 0) {
        // 0x80139B90: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80139B9C;
    }
    // 0x80139B90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139B94: b           L_80139D5C
    // 0x80139B98: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80139D5C;
    // 0x80139B98: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_80139B9C:
    // 0x80139B9C: lw          $t9, 0x5B4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X5B4);
    // 0x80139BA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80139BA4: beq         $t9, $at, L_80139BCC
    if (ctx->r25 == ctx->r1) {
        // 0x80139BA8: nop
    
            goto L_80139BCC;
    }
    // 0x80139BA8: nop

    // 0x80139BAC: lw          $v0, 0x84C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84C);
    // 0x80139BB0: beql        $v0, $zero, L_80139BE4
    if (ctx->r2 == 0) {
        // 0x80139BB4: lw          $t2, 0x8E8($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X8E8);
            goto L_80139BE4;
    }
    goto skip_3;
    // 0x80139BB4: lw          $t2, 0x8E8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8E8);
    skip_3:
    // 0x80139BB8: lw          $t0, 0x84($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X84);
    // 0x80139BBC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80139BC0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80139BC4: bnel        $t1, $at, L_80139BE4
    if (ctx->r9 != ctx->r1) {
        // 0x80139BC8: lw          $t2, 0x8E8($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X8E8);
            goto L_80139BE4;
    }
    goto skip_4;
    // 0x80139BC8: lw          $t2, 0x8E8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8E8);
    skip_4:
L_80139BCC:
    // 0x80139BCC: jal         0x80134E98
    // 0x80139BD0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_8;
    // 0x80139BD0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_8:
    // 0x80139BD4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139BD8: b           L_80139D5C
    // 0x80139BDC: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80139D5C;
    // 0x80139BDC: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x80139BE0: lw          $t2, 0x8E8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8E8);
L_80139BE4:
    // 0x80139BE4: lwc1        $f2, 0x64($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80139BE8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139BEC: lwc1        $f0, 0x20($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80139BF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80139BF4: nop

    // 0x80139BF8: bc1fl       L_80139C10
    if (!c1cs) {
        // 0x80139BFC: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80139C10;
    }
    goto skip_5;
    // 0x80139BFC: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_5:
    // 0x80139C00: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80139C04: b           L_80139C10
    // 0x80139C08: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80139C10;
    // 0x80139C08: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80139C0C: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_80139C10:
    // 0x80139C10: lwc1        $f18, -0x409C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X409C);
    // 0x80139C14: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80139C18: nop

    // 0x80139C1C: bc1t        L_80139C30
    if (c1cs) {
        // 0x80139C20: nop
    
            goto L_80139C30;
    }
    // 0x80139C20: nop

    // 0x80139C24: lhu         $t3, 0x20($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X20);
    // 0x80139C28: beql        $t3, $zero, L_80139C58
    if (ctx->r11 == 0) {
        // 0x80139C2C: sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
            goto L_80139C58;
    }
    goto skip_6;
    // 0x80139C2C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    skip_6:
L_80139C30:
    // 0x80139C30: jal         0x80134E98
    // 0x80139C34: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_9;
    // 0x80139C34: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_9:
    // 0x80139C38: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139C3C: lhu         $v0, 0x20($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X20);
    // 0x80139C40: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x80139C44: beq         $v0, $zero, L_80139D5C
    if (ctx->r2 == 0) {
        // 0x80139C48: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80139D5C;
    }
    // 0x80139C48: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80139C4C: b           L_80139D5C
    // 0x80139C50: sh          $t4, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r12;
        goto L_80139D5C;
    // 0x80139C50: sh          $t4, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r12;
    // 0x80139C54: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_80139C58:
    // 0x80139C58: jal         0x80018948
    // 0x80139C5C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_10;
    // 0x80139C5C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_10:
    // 0x80139C60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139C64: lwc1        $f6, -0x4098($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4098);
    // 0x80139C68: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139C6C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139C70: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80139C74: nop

    // 0x80139C78: bc1f        L_80139D44
    if (!c1cs) {
        // 0x80139C7C: nop
    
            goto L_80139D44;
    }
    // 0x80139C7C: nop

    // 0x80139C80: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139C84: jal         0x80018948
    // 0x80139C88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_11;
    // 0x80139C88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_11:
    // 0x80139C8C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80139C90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80139C94: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80139C98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139C9C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80139CA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80139CA4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80139CA8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139CAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139CB0: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80139CB4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80139CB8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80139CBC: nop

    // 0x80139CC0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80139CC4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80139CC8: nop

    // 0x80139CCC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80139CD0: beql        $t6, $zero, L_80139D20
    if (ctx->r14 == 0) {
        // 0x80139CD4: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_80139D20;
    }
    goto skip_7;
    // 0x80139CD4: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_7:
    // 0x80139CD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80139CDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80139CE0: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80139CE4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80139CE8: nop

    // 0x80139CEC: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80139CF0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80139CF4: nop

    // 0x80139CF8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80139CFC: bne         $t6, $zero, L_80139D14
    if (ctx->r14 != 0) {
        // 0x80139D00: nop
    
            goto L_80139D14;
    }
    // 0x80139D00: nop

    // 0x80139D04: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80139D08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80139D0C: b           L_80139D2C
    // 0x80139D10: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80139D2C;
    // 0x80139D10: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80139D14:
    // 0x80139D14: b           L_80139D2C
    // 0x80139D18: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80139D2C;
    // 0x80139D18: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80139D1C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_80139D20:
    // 0x80139D20: nop

    // 0x80139D24: bltz        $t6, L_80139D14
    if (SIGNED(ctx->r14) < 0) {
        // 0x80139D28: nop
    
            goto L_80139D14;
    }
    // 0x80139D28: nop

L_80139D2C:
    // 0x80139D2C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80139D30: jal         0x80134E98
    // 0x80139D34: sh          $t6, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r14;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_12;
    // 0x80139D34: sh          $t6, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r14;
    after_12:
    // 0x80139D38: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139D3C: b           L_80139D5C
    // 0x80139D40: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80139D5C;
    // 0x80139D40: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_80139D44:
    // 0x80139D44: jal         0x8013877C
    // 0x80139D48: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
    func_ovl3_8013877C(rdram, ctx);
        goto after_13;
    // 0x80139D48: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
    after_13:
    // 0x80139D4C: b           L_80139D60
    // 0x80139D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80139D60;
    // 0x80139D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80139D54:
    // 0x80139D54: jal         0x8013877C
    // 0x80139D58: nop

    func_ovl3_8013877C(rdram, ctx);
        goto after_14;
    // 0x80139D58: nop

    after_14:
L_80139D5C:
    // 0x80139D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80139D60:
    // 0x80139D60: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80139D64: jr          $ra
    // 0x80139D68: nop

    return;
    // 0x80139D68: nop

;}

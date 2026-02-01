#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sc1PGameInitTimeUpMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F1F8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018F1FC: lbu         $t6, 0x4AE7($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE7);
    // 0x8018F200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018F204: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8018F208: beq         $t6, $at, L_8018F224
    if (ctx->r14 == ctx->r1) {
        // 0x8018F20C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8018F224;
    }
    // 0x8018F20C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F210: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018F214: jal         0x80113398
    // 0x8018F218: addiu       $a0, $a0, 0x4D98
    ctx->r4 = ADD32(ctx->r4, 0X4D98);
    ifCommonTimerMakeInterface(rdram, ctx);
        goto after_0;
    // 0x8018F218: addiu       $a0, $a0, 0x4D98
    ctx->r4 = ADD32(ctx->r4, 0X4D98);
    after_0:
    // 0x8018F21C: b           L_8018F234
    // 0x8018F220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018F234;
    // 0x8018F220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018F224:
    // 0x8018F224: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018F228: jal         0x80113398
    // 0x8018F22C: addiu       $a0, $a0, 0x4DD4
    ctx->r4 = ADD32(ctx->r4, 0X4DD4);
    ifCommonTimerMakeInterface(rdram, ctx);
        goto after_1;
    // 0x8018F22C: addiu       $a0, $a0, 0x4DD4
    ctx->r4 = ADD32(ctx->r4, 0X4DD4);
    after_1:
    // 0x8018F230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018F234:
    // 0x8018F234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018F238: jr          $ra
    // 0x8018F23C: nop

    return;
    // 0x8018F23C: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015B784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B788: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015B78C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015B790: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015B794: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x8015B798: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
    // 0x8015B79C: beq         $t6, $zero, L_8015B7B4
    if (ctx->r14 == 0) {
        // 0x8015B7A0: nop
    
            goto L_8015B7B4;
    }
    // 0x8015B7A0: nop

    // 0x8015B7A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8015B7A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8015B7AC: b           L_8015B7BC
    // 0x8015B7B0: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
        goto L_8015B7BC;
    // 0x8015B7B0: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
L_8015B7B4:
    // 0x8015B7B4: lwc1        $f0, -0x378C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X378C);
    // 0x8015B7B8: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
L_8015B7BC:
    // 0x8015B7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015B7C0: lw          $a2, 0x5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5C);
    // 0x8015B7C4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8015B7C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8015B7CC: jal         0x800D8D68
    // 0x8015B7D0: nop

    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8015B7D0: nop

    after_0:
    // 0x8015B7D4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8015B7D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8015B7DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015B7E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8015B7E4: jal         0x800D8FC8
    // 0x8015B7E8: lui         $a3, 0x4218
    ctx->r7 = S32(0X4218 << 16);
    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_1;
    // 0x8015B7E8: lui         $a3, 0x4218
    ctx->r7 = S32(0X4218 << 16);
    after_1:
    // 0x8015B7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B7F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015B7F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015B7F8: jr          $ra
    // 0x8015B7FC: nop

    return;
    // 0x8015B7FC: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateItemOptionSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F040: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018F044: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018F048: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8018F04C: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x8018F050: lw          $t6, 0x5C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X5C);
    // 0x8018F054: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018F058: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018F05C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8018F060: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8018F064: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
    // 0x8018F068: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8018F06C:
    // 0x8018F06C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F070: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018F074: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018F078: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018F07C: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018F080: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8018F084: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018F088: bne         $t1, $t5, L_8018F06C
    if (ctx->r9 != ctx->r13) {
        // 0x8018F08C: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8018F06C;
    }
    // 0x8018F08C: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8018F090: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F094: addiu       $t7, $zero, 0xBF
    ctx->r15 = ADD32(0, 0XBF);
    // 0x8018F098: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8018F09C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018F0A0: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    // 0x8018F0A4: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8018F0A8: bgez        $t6, L_8018F0B8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018F0AC: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8018F0B8;
    }
    // 0x8018F0AC: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8018F0B0: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8018F0B4: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8018F0B8:
    // 0x8018F0B8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8018F0BC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8018F0C0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8018F0C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F0C8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018F0CC: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x8018F0D0: bne         $t0, $at, L_8018F0E4
    if (ctx->r8 != ctx->r1) {
        // 0x8018F0D4: lui         $at, 0x42A6
        ctx->r1 = S32(0X42A6 << 16);
            goto L_8018F0E4;
    }
    // 0x8018F0D4: lui         $at, 0x42A6
    ctx->r1 = S32(0X42A6 << 16);
    // 0x8018F0D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F0DC: jr          $ra
    // 0x8018F0E0: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8018F0E0: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
L_8018F0E4:
    // 0x8018F0E4: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x8018F0E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F0EC: nop

    // 0x8018F0F0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x8018F0F4: jr          $ra
    // 0x8018F0F8: nop

    return;
    // 0x8018F0F8: nop

;}
RECOMP_FUNC void syControllerDispatchEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004284: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000428C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80004290: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80004294: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80004298: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8000429C: jal         0x80034480
    // 0x800042A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800042A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800042A4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800042A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800042AC: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x800042B0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800042B4: addiu       $a0, $a0, 0x5138
    ctx->r4 = ADD32(ctx->r4, 0X5138);
    // 0x800042B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800042BC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800042C0: jal         0x80030000
    // 0x800042C4: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800042C4: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    after_1:
    // 0x800042C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800042CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800042D0: jal         0x80030210
    // 0x800042D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800042D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800042D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800042DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800042E0: jr          $ra
    // 0x800042E4: nop

    return;
    // 0x800042E4: nop

;}
RECOMP_FUNC void gcGetGObjByID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B14C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000B150: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000B154: bne         $a1, $t6, L_8000B164
    if (ctx->r5 != ctx->r14) {
        // 0x8000B158: nop
    
            goto L_8000B164;
    }
    // 0x8000B158: nop

    // 0x8000B15C: jr          $ra
    // 0x8000B160: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000B160: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000B164:
    // 0x8000B164: jr          $ra
    // 0x8000B168: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000B168: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void grSectorArwingWeaponLaserExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010751C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107520: jal         0x80167FE8
    // 0x80107524: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80107524: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80107528: beq         $v0, $zero, L_80107538
    if (ctx->r2 == 0) {
        // 0x8010752C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80107538;
    }
    // 0x8010752C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107530: b           L_8010753C
    // 0x80107534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010753C;
    // 0x80107534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80107538:
    // 0x80107538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010753C:
    // 0x8010753C: jr          $ra
    // 0x80107540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itNessPKFireMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185824: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80185828: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018582C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80185830: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80185834: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80185838: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8018583C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80185840: ori         $t6, $t6, 0x2
    ctx->r14 = ctx->r14 | 0X2;
    // 0x80185844: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80185848: addiu       $a1, $a1, -0x49C0
    ctx->r5 = ADD32(ctx->r5, -0X49C0);
    // 0x8018584C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80185850: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80185854: jal         0x8016E174
    // 0x80185858: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80185858: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018585C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80185860: bne         $v0, $zero, L_80185870
    if (ctx->r2 != 0) {
        // 0x80185864: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_80185870;
    }
    // 0x80185864: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80185868: b           L_801859A0
    // 0x8018586C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801859A0;
    // 0x8018586C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80185870:
    // 0x80185870: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x80185874: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80185878: lbu         $t8, 0x2CE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2CE);
    // 0x8018587C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x80185880: lbu         $t7, 0x158($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X158);
    // 0x80185884: andi        $t0, $t8, 0xFF7F
    ctx->r8 = ctx->r24 & 0XFF7F;
    // 0x80185888: andi        $t1, $t0, 0xBF
    ctx->r9 = ctx->r8 & 0XBF;
    // 0x8018588C: sb          $t0, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r8;
    // 0x80185890: sb          $t1, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r9;
    // 0x80185894: lbu         $t2, 0x10($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X10);
    // 0x80185898: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8018589C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801858A0: sb          $t2, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r10;
    // 0x801858A4: lbu         $t3, 0x11($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X11);
    // 0x801858A8: sb          $t3, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r11;
    // 0x801858AC: lbu         $t4, 0x12($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X12);
    // 0x801858B0: sb          $t4, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r12;
    // 0x801858B4: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x801858B8: sb          $t8, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r24;
    // 0x801858BC: lhu         $t4, 0x158($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X158);
    // 0x801858C0: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
    // 0x801858C4: lwc1        $f4, 0x108($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X108);
    // 0x801858C8: andi        $t5, $t4, 0xFE07
    ctx->r13 = ctx->r12 & 0XFE07;
    // 0x801858CC: swc1        $f4, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f4.u32l;
    // 0x801858D0: lw          $t9, 0x148($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X148);
    // 0x801858D4: sll         $t0, $t9, 9
    ctx->r8 = S32(ctx->r25 << 9);
    // 0x801858D8: srl         $t1, $t0, 26
    ctx->r9 = S32(U32(ctx->r8) >> 26);
    // 0x801858DC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x801858E0: andi        $t3, $t2, 0x1F8
    ctx->r11 = ctx->r10 & 0X1F8;
    // 0x801858E4: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x801858E8: sh          $t6, 0x158($s0)
    MEM_H(0X158, ctx->r16) = ctx->r14;
    // 0x801858EC: lhu         $t7, 0x14A($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X14A);
    // 0x801858F0: sh          $t7, 0x15A($s0)
    MEM_H(0X15A, ctx->r16) = ctx->r15;
    // 0x801858F4: lhu         $t9, 0x14C($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X14C);
    // 0x801858F8: sh          $t9, 0x15C($s0)
    MEM_H(0X15C, ctx->r16) = ctx->r25;
    // 0x801858FC: lhu         $t0, 0x14E($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X14E);
    // 0x80185900: jal         0x80173F78
    // 0x80185904: sh          $t0, 0x15E($s0)
    MEM_H(0X15E, ctx->r16) = ctx->r8;
    itMapSetAir(rdram, ctx);
        goto after_1;
    // 0x80185904: sh          $t0, 0x15E($s0)
    MEM_H(0X15E, ctx->r16) = ctx->r8;
    after_1:
    // 0x80185908: jal         0x8016F280
    // 0x8018590C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_2;
    // 0x8018590C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x80185910: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80185914: sw          $t1, 0x2C0($s0)
    MEM_W(0X2C0, ctx->r16) = ctx->r9;
    // 0x80185918: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018591C: lw          $a0, 0x1148($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1148);
    // 0x80185920: jal         0x800CE9E8
    // 0x80185924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x80185924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80185928: beq         $v0, $zero, L_80185998
    if (ctx->r2 == 0) {
        // 0x8018592C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80185998;
    }
    // 0x8018592C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80185930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80185934: jal         0x800CE1DC
    // 0x80185938: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x80185938: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_4:
    // 0x8018593C: beq         $v0, $zero, L_80185988
    if (ctx->r2 == 0) {
        // 0x80185940: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80185988;
    }
    // 0x80185940: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80185944: sw          $v0, 0x350($s0)
    MEM_W(0X350, ctx->r16) = ctx->r2;
    // 0x80185948: jal         0x800CEA14
    // 0x8018594C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x8018594C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_5:
    // 0x80185950: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80185954: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80185958: lhu         $t2, 0x2A($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X2A);
    // 0x8018595C: bnel        $t2, $zero, L_80185970
    if (ctx->r10 != 0) {
        // 0x80185960: lw          $t5, 0x0($t4)
        ctx->r13 = MEM_W(ctx->r12, 0X0);
            goto L_80185970;
    }
    goto skip_0;
    // 0x80185960: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    skip_0:
    // 0x80185964: b           L_8018599C
    // 0x80185968: sw          $zero, 0x350($s0)
    MEM_W(0X350, ctx->r16) = 0;
        goto L_8018599C;
    // 0x80185968: sw          $zero, 0x350($s0)
    MEM_W(0X350, ctx->r16) = 0;
    // 0x8018596C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
L_80185970:
    // 0x80185970: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80185974: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x80185978: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x8018597C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80185980: b           L_8018599C
    // 0x80185984: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
        goto L_8018599C;
    // 0x80185984: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
L_80185988:
    // 0x80185988: jal         0x800CEA40
    // 0x8018598C: nop

    lbParticleEjectStruct(rdram, ctx);
        goto after_6;
    // 0x8018598C: nop

    after_6:
    // 0x80185990: b           L_8018599C
    // 0x80185994: sw          $zero, 0x350($s0)
    MEM_W(0X350, ctx->r16) = 0;
        goto L_8018599C;
    // 0x80185994: sw          $zero, 0x350($s0)
    MEM_W(0X350, ctx->r16) = 0;
L_80185998:
    // 0x80185998: sw          $zero, 0x350($s0)
    MEM_W(0X350, ctx->r16) = 0;
L_8018599C:
    // 0x8018599C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_801859A0:
    // 0x801859A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801859A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801859A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801859AC: jr          $ra
    // 0x801859B0: nop

    return;
    // 0x801859B0: nop

;}
RECOMP_FUNC void ftComputerWaitGetTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D18: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80132D1C: lw          $a1, 0x66FC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X66FC);
    // 0x80132D20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132D28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80132D2C: addiu       $a3, $zero, 0x270F
    ctx->r7 = ADD32(0, 0X270F);
    // 0x80132D30: beq         $a1, $zero, L_80132DE8
    if (ctx->r5 == 0) {
        // 0x80132D34: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80132DE8;
    }
    // 0x80132D34: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80132D38: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
L_80132D3C:
    // 0x80132D3C: beql        $a1, $t6, L_80132DE0
    if (ctx->r5 == ctx->r14) {
        // 0x80132D40: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80132DE0;
    }
    goto skip_0;
    // 0x80132D40: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x80132D44: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x80132D48: lbu         $t8, 0xC($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XC);
    // 0x80132D4C: lbu         $t7, 0xC($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XC);
    // 0x80132D50: beql        $t7, $t8, L_80132DE0
    if (ctx->r15 == ctx->r24) {
        // 0x80132D54: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80132DE0;
    }
    goto skip_1;
    // 0x80132D54: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x80132D58: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x80132D5C: addiu       $v0, $a2, 0x1CC
    ctx->r2 = ADD32(ctx->r6, 0X1CC);
    // 0x80132D60: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80132D64: bnel        $at, $zero, L_80132DE0
    if (ctx->r1 != 0) {
        // 0x80132D68: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80132DE0;
    }
    goto skip_2;
    // 0x80132D68: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_2:
    // 0x80132D6C: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    // 0x80132D70: beql        $a0, $zero, L_80132DC8
    if (ctx->r4 == 0) {
        // 0x80132D74: lw          $v0, 0x2C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X2C);
            goto L_80132DC8;
    }
    goto skip_3;
    // 0x80132D74: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    skip_3:
    // 0x80132D78: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80132D7C: bnel        $a0, $t1, L_80132DC8
    if (ctx->r4 != ctx->r9) {
        // 0x80132D80: lw          $v0, 0x2C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X2C);
            goto L_80132DC8;
    }
    goto skip_4;
    // 0x80132D80: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    skip_4:
    // 0x80132D84: lhu         $t2, 0x26($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X26);
    // 0x80132D88: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x80132D8C: bnel        $t2, $t3, L_80132DC4
    if (ctx->r10 != ctx->r11) {
        // 0x80132D90: sw          $zero, 0x30($v0)
        MEM_W(0X30, ctx->r2) = 0;
            goto L_80132DC4;
    }
    goto skip_5;
    // 0x80132D90: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    skip_5:
    // 0x80132D94: lhu         $a0, 0x24($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X24);
    // 0x80132D98: beq         $a0, $zero, L_80132DA8
    if (ctx->r4 == 0) {
        // 0x80132D9C: addiu       $t4, $a0, -0x1
        ctx->r12 = ADD32(ctx->r4, -0X1);
            goto L_80132DA8;
    }
    // 0x80132D9C: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x80132DA0: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132DA4: andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
L_80132DA8:
    // 0x80132DA8: bne         $a0, $zero, L_80132DB8
    if (ctx->r4 != 0) {
        // 0x80132DAC: nop
    
            goto L_80132DB8;
    }
    // 0x80132DAC: nop

    // 0x80132DB0: b           L_80132EB0
    // 0x80132DB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80132EB0;
    // 0x80132DB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132DB8:
    // 0x80132DB8: b           L_80132EB0
    // 0x80132DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80132EB0;
    // 0x80132DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132DC0: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
L_80132DC4:
    // 0x80132DC4: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
L_80132DC8:
    // 0x80132DC8: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80132DCC: beql        $at, $zero, L_80132DE0
    if (ctx->r1 == 0) {
        // 0x80132DD0: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80132DE0;
    }
    goto skip_6;
    // 0x80132DD0: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_6:
    // 0x80132DD4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80132DD8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80132DDC: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
L_80132DE0:
    // 0x80132DE0: bnel        $a1, $zero, L_80132D3C
    if (ctx->r5 != 0) {
        // 0x80132DE4: lw          $t6, 0x4($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X4);
            goto L_80132D3C;
    }
    goto skip_7;
    // 0x80132DE4: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    skip_7:
L_80132DE8:
    // 0x80132DE8: beq         $t0, $zero, L_80132EAC
    if (ctx->r8 == 0) {
        // 0x80132DEC: addiu       $v0, $a2, 0x1CC
        ctx->r2 = ADD32(ctx->r6, 0X1CC);
            goto L_80132EAC;
    }
    // 0x80132DEC: addiu       $v0, $a2, 0x1CC
    ctx->r2 = ADD32(ctx->r6, 0X1CC);
    // 0x80132DF0: sh          $a3, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r7;
    // 0x80132DF4: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80132DF8: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    // 0x80132DFC: jal         0x80018948
    // 0x80132E00: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80132E00: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80132E04: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80132E08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132E0C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80132E10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132E14: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80132E18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132E1C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132E20: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80132E24: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80132E28: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80132E2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80132E30: nop

    // 0x80132E34: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80132E38: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80132E3C: nop

    // 0x80132E40: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80132E44: beql        $t7, $zero, L_80132E94
    if (ctx->r15 == 0) {
        // 0x80132E48: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_80132E94;
    }
    goto skip_8;
    // 0x80132E48: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_8:
    // 0x80132E4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132E50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132E54: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80132E58: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80132E5C: nop

    // 0x80132E60: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80132E64: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80132E68: nop

    // 0x80132E6C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80132E70: bne         $t7, $zero, L_80132E88
    if (ctx->r15 != 0) {
        // 0x80132E74: nop
    
            goto L_80132E88;
    }
    // 0x80132E74: nop

    // 0x80132E78: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80132E7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132E80: b           L_80132EA0
    // 0x80132E84: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80132EA0;
    // 0x80132E84: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80132E88:
    // 0x80132E88: b           L_80132EA0
    // 0x80132E8C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80132EA0;
    // 0x80132E8C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132E90: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_80132E94:
    // 0x80132E94: nop

    // 0x80132E98: bltz        $t7, L_80132E88
    if (SIGNED(ctx->r15) < 0) {
        // 0x80132E9C: nop
    
            goto L_80132E88;
    }
    // 0x80132E9C: nop

L_80132EA0:
    // 0x80132EA0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80132EA4: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132EA8: nop

L_80132EAC:
    // 0x80132EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132EB0:
    // 0x80132EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132EB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80132EB8: jr          $ra
    // 0x80132EBC: nop

    return;
    // 0x80132EBC: nop

;}
RECOMP_FUNC void ftDonkeySpecialNEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B39C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B3A0: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015B3A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015B3A8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8015B3AC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015B3B0: nop

    // 0x8015B3B4: bc1fl       L_8015B3D0
    if (!c1cs) {
        // 0x8015B3B8: lw          $v0, 0x24($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X24);
            goto L_8015B3D0;
    }
    goto skip_0;
    // 0x8015B3B8: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    skip_0:
    // 0x8015B3BC: jal         0x800DEE54
    // 0x8015B3C0: nop

    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_0;
    // 0x8015B3C0: nop

    after_0:
    // 0x8015B3C4: b           L_8015B47C
    // 0x8015B3C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015B47C;
    // 0x8015B3C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B3CC: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
L_8015B3D0:
    // 0x8015B3D0: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x8015B3D4: beq         $v0, $at, L_8015B3E4
    if (ctx->r2 == ctx->r1) {
        // 0x8015B3D8: addiu       $at, $zero, 0xE3
        ctx->r1 = ADD32(0, 0XE3);
            goto L_8015B3E4;
    }
    // 0x8015B3D8: addiu       $at, $zero, 0xE3
    ctx->r1 = ADD32(0, 0XE3);
    // 0x8015B3DC: bnel        $v0, $at, L_8015B47C
    if (ctx->r2 != ctx->r1) {
        // 0x8015B3E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015B47C;
    }
    goto skip_1;
    // 0x8015B3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8015B3E4:
    // 0x8015B3E4: lw          $t6, 0x294($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X294);
    // 0x8015B3E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8015B3EC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8015B3F0: bne         $a0, $t6, L_8015B40C
    if (ctx->r4 != ctx->r14) {
        // 0x8015B3F4: addiu       $v1, $v0, 0x294
        ctx->r3 = ADD32(ctx->r2, 0X294);
            goto L_8015B40C;
    }
    // 0x8015B3F4: addiu       $v1, $v0, 0x294
    ctx->r3 = ADD32(ctx->r2, 0X294);
    // 0x8015B3F8: lw          $t8, 0xB1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XB1C);
    // 0x8015B3FC: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8015B400: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8015B404: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8015B408: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
L_8015B40C:
    // 0x8015B40C: lw          $t1, 0x358($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X358);
    // 0x8015B410: addiu       $v1, $v0, 0x358
    ctx->r3 = ADD32(ctx->r2, 0X358);
    // 0x8015B414: bnel        $a0, $t1, L_8015B434
    if (ctx->r4 != ctx->r9) {
        // 0x8015B418: lw          $t6, 0x41C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X41C);
            goto L_8015B434;
    }
    goto skip_2;
    // 0x8015B418: lw          $t6, 0x41C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X41C);
    skip_2:
    // 0x8015B41C: lw          $t3, 0xB1C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XB1C);
    // 0x8015B420: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8015B424: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8015B428: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8015B42C: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x8015B430: lw          $t6, 0x41C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X41C);
L_8015B434:
    // 0x8015B434: addiu       $v1, $v0, 0x41C
    ctx->r3 = ADD32(ctx->r2, 0X41C);
    // 0x8015B438: bnel        $a0, $t6, L_8015B458
    if (ctx->r4 != ctx->r14) {
        // 0x8015B43C: lw          $t1, 0x4E0($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X4E0);
            goto L_8015B458;
    }
    goto skip_3;
    // 0x8015B43C: lw          $t1, 0x4E0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4E0);
    skip_3:
    // 0x8015B440: lw          $t7, 0xB1C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XB1C);
    // 0x8015B444: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8015B448: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8015B44C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8015B450: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x8015B454: lw          $t1, 0x4E0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4E0);
L_8015B458:
    // 0x8015B458: addiu       $v1, $v0, 0x4E0
    ctx->r3 = ADD32(ctx->r2, 0X4E0);
    // 0x8015B45C: bnel        $a0, $t1, L_8015B47C
    if (ctx->r4 != ctx->r9) {
        // 0x8015B460: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015B47C;
    }
    goto skip_4;
    // 0x8015B460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8015B464: lw          $t2, 0xB1C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XB1C);
    // 0x8015B468: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x8015B46C: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8015B470: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8015B474: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x8015B478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015B47C:
    // 0x8015B47C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B480: jr          $ra
    // 0x8015B484: nop

    return;
    // 0x8015B484: nop

;}
RECOMP_FUNC void mvOpeningRunMakeCrash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131F84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131F88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131F8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131F90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F94: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131F98: jal         0x80009968
    // 0x80131F9C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131F9C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FA0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131FA4: lw          $t6, 0x2AA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2AA8);
    // 0x80131FA8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131FAC: addiu       $t7, $t7, 0x35F8
    ctx->r15 = ADD32(ctx->r15, 0X35F8);
    // 0x80131FB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131FB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131FB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131FBC: jal         0x8000F120
    // 0x80131FC0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131FC0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131FC4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131FC8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131FCC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131FD0: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FD8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131FDC: jal         0x80009DF4
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131FE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131FE8: lwc1        $f0, 0x2700($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2700);
    // 0x80131FEC: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x80131FF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131FF4: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131FF8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80131FFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132000: swc1        $f4, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f4.u32l;
    // 0x80132004: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80132008: lui         $at, 0xC158
    ctx->r1 = S32(0XC158 << 16);
    // 0x8013200C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132010: swc1        $f6, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f6.u32l;
    // 0x80132014: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80132018: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013201C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132020: swc1        $f8, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f8.u32l;
    // 0x80132024: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80132028: lwc1        $f10, 0x2704($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2704);
    // 0x8013202C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132030: addiu       $t7, $t7, 0x2AA8
    ctx->r15 = ADD32(ctx->r15, 0X2AA8);
    // 0x80132034: swc1        $f10, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f10.u32l;
    // 0x80132038: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8013203C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132040: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x80132044: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80132048: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x8013204C: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80132050: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x80132054: lw          $t6, 0x2AA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2AA8);
    // 0x80132058: jal         0x8000F8F4
    // 0x8013205C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x8013205C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x80132060: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132064: lw          $t8, 0x2AA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2AA8);
    // 0x80132068: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8013206C: addiu       $t9, $t9, 0x3700
    ctx->r25 = ADD32(ctx->r25, 0X3700);
    // 0x80132070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132074: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132078: jal         0x8000BE28
    // 0x8013207C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x8013207C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x80132080: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132084: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80132088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013208C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132090: jal         0x80008188
    // 0x80132094: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132094: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80132098: jal         0x8000DF34
    // 0x8013209C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x8013209C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801320A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801320A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801320A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801320AC: jr          $ra
    // 0x801320B0: nop

    return;
    // 0x801320B0: nop

;}
RECOMP_FUNC void ftKirbySpecialNTurnCheckGotoTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801625B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801625B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801625B8: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x801625BC: lb          $v0, 0x1C2($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X1C2);
    // 0x801625C0: bgez        $v0, L_801625D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801625C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801625D0;
    }
    // 0x801625C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801625C8: b           L_801625D0
    // 0x801625CC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_801625D0;
    // 0x801625CC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_801625D0:
    // 0x801625D0: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x801625D4: beq         $at, $zero, L_801625E0
    if (ctx->r1 == 0) {
        // 0x801625D8: nop
    
            goto L_801625E0;
    }
    // 0x801625D8: nop

    // 0x801625DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801625E0:
    // 0x801625E0: bgez        $v0, L_801625F8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801625E4: nop
    
            goto L_801625F8;
    }
    // 0x801625E4: nop

    // 0x801625E8: lw          $t6, 0x44($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X44);
    // 0x801625EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801625F0: beq         $t6, $at, L_80162610
    if (ctx->r14 == ctx->r1) {
        // 0x801625F4: nop
    
            goto L_80162610;
    }
    // 0x801625F4: nop

L_801625F8:
    // 0x801625F8: blezl       $v0, L_80162624
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801625FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80162624;
    }
    goto skip_0;
    // 0x801625FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80162600: lw          $t7, 0x44($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X44);
    // 0x80162604: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80162608: bnel        $t7, $at, L_80162624
    if (ctx->r15 != ctx->r1) {
        // 0x8016260C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80162624;
    }
    goto skip_1;
    // 0x8016260C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_80162610:
    // 0x80162610: jalr        $a1
    // 0x80162614: nop

    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x80162614: nop

    after_0:
    // 0x80162618: b           L_80162624
    // 0x8016261C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80162624;
    // 0x8016261C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80162620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80162624:
    // 0x80162624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016262C: jr          $ra
    // 0x80162630: nop

    return;
    // 0x80162630: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateUnderline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FE40: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018FE44: addiu       $a2, $a2, 0xB58
    ctx->r6 = ADD32(ctx->r6, 0XB58);
    // 0x8018FE48: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8018FE4C: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x8018FE50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FE54: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8018FE58: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x8018FE5C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8018FE60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018FE64: lw          $a1, 0x88($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X88);
    // 0x8018FE68: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8018FE6C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8018FE70: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018FE74: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8018FE78: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8018FE7C: nop

    // 0x8018FE80: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8018FE84: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8018FE88: nop

    // 0x8018FE8C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8018FE90: beql        $t8, $zero, L_8018FEE0
    if (ctx->r24 == 0) {
        // 0x8018FE94: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_8018FEE0;
    }
    goto skip_0;
    // 0x8018FE94: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8018FE98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018FE9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018FEA0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018FEA4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8018FEA8: nop

    // 0x8018FEAC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8018FEB0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8018FEB4: nop

    // 0x8018FEB8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8018FEBC: bne         $t8, $zero, L_8018FED4
    if (ctx->r24 != 0) {
        // 0x8018FEC0: nop
    
            goto L_8018FED4;
    }
    // 0x8018FEC0: nop

    // 0x8018FEC4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8018FEC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018FECC: b           L_8018FEEC
    // 0x8018FED0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8018FEEC;
    // 0x8018FED0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8018FED4:
    // 0x8018FED4: b           L_8018FEEC
    // 0x8018FED8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8018FEEC;
    // 0x8018FED8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018FEDC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_8018FEE0:
    // 0x8018FEE0: nop

    // 0x8018FEE4: bltz        $t8, L_8018FED4
    if (SIGNED(ctx->r24) < 0) {
        // 0x8018FEE8: nop
    
            goto L_8018FED4;
    }
    // 0x8018FEE8: nop

L_8018FEEC:
    // 0x8018FEEC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8018FEF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018FEF4: beq         $v1, $at, L_8018FF08
    if (ctx->r3 == ctx->r1) {
        // 0x8018FEF8: sw          $t8, 0xB4($a2)
        MEM_W(0XB4, ctx->r6) = ctx->r24;
            goto L_8018FF08;
    }
    // 0x8018FEF8: sw          $t8, 0xB4($a2)
    MEM_W(0XB4, ctx->r6) = ctx->r24;
    // 0x8018FEFC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8018FF00: bnel        $v1, $at, L_8018FF14
    if (ctx->r3 != ctx->r1) {
        // 0x8018FF04: addiu       $v1, $zero, -0x2
        ctx->r3 = ADD32(0, -0X2);
            goto L_8018FF14;
    }
    goto skip_1;
    // 0x8018FF04: addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    skip_1:
L_8018FF08:
    // 0x8018FF08: b           L_8018FF14
    // 0x8018FF0C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8018FF14;
    // 0x8018FF0C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8018FF10: addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
L_8018FF14:
    // 0x8018FF14: lh          $t9, 0x14($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X14);
    // 0x8018FF18: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8018FF1C: lwc1        $f16, 0x58($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X58);
    // 0x8018FF20: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8018FF24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018FF28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018FF2C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8018FF30: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018FF34: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8018FF38: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018FF3C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8018FF40: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8018FF44: nop

    // 0x8018FF48: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8018FF4C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8018FF50: nop

    // 0x8018FF54: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8018FF58: beql        $t1, $zero, L_8018FFA8
    if (ctx->r9 == 0) {
        // 0x8018FF5C: mfc1        $t1, $f16
        ctx->r9 = (int32_t)ctx->f16.u32l;
            goto L_8018FFA8;
    }
    goto skip_2;
    // 0x8018FF5C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x8018FF60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018FF64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018FF68: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8018FF6C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8018FF70: nop

    // 0x8018FF74: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8018FF78: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8018FF7C: nop

    // 0x8018FF80: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8018FF84: bne         $t1, $zero, L_8018FF9C
    if (ctx->r9 != 0) {
        // 0x8018FF88: nop
    
            goto L_8018FF9C;
    }
    // 0x8018FF88: nop

    // 0x8018FF8C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8018FF90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018FF94: b           L_8018FFB4
    // 0x8018FF98: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_8018FFB4;
    // 0x8018FF98: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8018FF9C:
    // 0x8018FF9C: b           L_8018FFB4
    // 0x8018FFA0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_8018FFB4;
    // 0x8018FFA0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8018FFA4: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
L_8018FFA8:
    // 0x8018FFA8: nop

    // 0x8018FFAC: bltz        $t1, L_8018FF9C
    if (SIGNED(ctx->r9) < 0) {
        // 0x8018FFB0: nop
    
            goto L_8018FF9C;
    }
    // 0x8018FFB0: nop

L_8018FFB4:
    // 0x8018FFB4: sw          $t1, 0xBC($a2)
    MEM_W(0XBC, ctx->r6) = ctx->r9;
    // 0x8018FFB8: lh          $t2, 0x16($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X16);
    // 0x8018FFBC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8018FFC0: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8018FFC4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8018FFC8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018FFCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018FFD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018FFD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018FFD8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8018FFDC: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018FFE0: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8018FFE4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8018FFE8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8018FFEC: nop

    // 0x8018FFF0: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8018FFF4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8018FFF8: nop

    // 0x8018FFFC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80190000: beql        $t4, $zero, L_80190050
    if (ctx->r12 == 0) {
        // 0x80190004: mfc1        $t4, $f8
        ctx->r12 = (int32_t)ctx->f8.u32l;
            goto L_80190050;
    }
    goto skip_3;
    // 0x80190004: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x80190008: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019000C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80190010: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80190014: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80190018: nop

    // 0x8019001C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80190020: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80190024: nop

    // 0x80190028: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8019002C: bne         $t4, $zero, L_80190044
    if (ctx->r12 != 0) {
        // 0x80190030: nop
    
            goto L_80190044;
    }
    // 0x80190030: nop

    // 0x80190034: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80190038: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019003C: b           L_8019005C
    // 0x80190040: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8019005C;
    // 0x80190040: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80190044:
    // 0x80190044: b           L_8019005C
    // 0x80190048: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8019005C;
    // 0x80190048: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8019004C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
L_80190050:
    // 0x80190050: nop

    // 0x80190054: bltz        $t4, L_80190044
    if (SIGNED(ctx->r12) < 0) {
        // 0x80190058: nop
    
            goto L_80190044;
    }
    // 0x80190058: nop

L_8019005C:
    // 0x8019005C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80190060: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80190064: sw          $t4, 0xB8($a2)
    MEM_W(0XB8, ctx->r6) = ctx->r12;
    // 0x80190068: jr          $ra
    // 0x8019006C: sw          $t6, 0xC0($a2)
    MEM_W(0XC0, ctx->r6) = ctx->r14;
    return;
    // 0x8019006C: sw          $t6, 0xC0($a2)
    MEM_W(0XC0, ctx->r6) = ctx->r14;
;}
RECOMP_FUNC void ftCommonCatchPullProcCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149F04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80149F08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80149F0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80149F10: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80149F14: addiu       $t6, $zero, 0x44
    ctx->r14 = ADD32(0, 0X44);
    // 0x80149F18: addiu       $a1, $zero, 0xA7
    ctx->r5 = ADD32(0, 0XA7);
    // 0x80149F1C: lw          $a2, 0xB18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XB18);
    // 0x80149F20: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80149F24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80149F28: jal         0x800E6F24
    // 0x80149F2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149F2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80149F30: lbu         $t8, 0x192($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X192);
    // 0x80149F34: lw          $t7, 0x830($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X830);
    // 0x80149F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149F3C: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80149F40: sb          $t9, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r25;
    // 0x80149F44: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80149F48: jal         0x800E8098
    // 0x80149F4C: sw          $t7, 0x840($s0)
    MEM_W(0X840, ctx->r16) = ctx->r15;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x80149F4C: sw          $t7, 0x840($s0)
    MEM_W(0X840, ctx->r16) = ctx->r15;
    after_1:
    // 0x80149F50: lw          $v0, 0x9E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9E8);
    // 0x80149F54: beq         $v0, $zero, L_80149F64
    if (ctx->r2 == 0) {
        // 0x80149F58: nop
    
            goto L_80149F64;
    }
    // 0x80149F58: nop

    // 0x80149F5C: jalr        $v0
    // 0x80149F60: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80149F60: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
L_80149F64:
    // 0x80149F64: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80149F68: addiu       $t0, $t0, -0x7930
    ctx->r8 = ADD32(ctx->r8, -0X7930);
    // 0x80149F6C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80149F70: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80149F74: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80149F78: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80149F7C: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80149F80: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80149F84: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
    // 0x80149F88: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x80149F8C: lw          $t4, 0x334($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X334);
    // 0x80149F90: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80149F94: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80149F98: jal         0x800EDF24
    // 0x80149F9C: lw          $a0, 0x8E8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_3;
    // 0x80149F9C: lw          $a0, 0x8E8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8E8);
    after_3:
    // 0x80149FA0: jal         0x80101500
    // 0x80149FA4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    efManagerCatchSwirlMakeEffect(rdram, ctx);
        goto after_4;
    // 0x80149FA4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80149FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149FAC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80149FB0: jal         0x800E806C
    // 0x80149FB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_5;
    // 0x80149FB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80149FB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80149FBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80149FC0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80149FC4: jr          $ra
    // 0x80149FC8: nop

    return;
    // 0x80149FC8: nop

;}
RECOMP_FUNC void __setUsptFromTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029170: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80029174: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80029178: beql        $v0, $zero, L_8002919C
    if (ctx->r2 == 0) {
        // 0x8002917C: sw          $t8, 0x2C($a0)
        MEM_W(0X2C, ctx->r4) = ctx->r24;
            goto L_8002919C;
    }
    goto skip_0;
    // 0x8002917C: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    skip_0:
    // 0x80029180: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80029184: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80029188: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8002918C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80029190: jr          $ra
    // 0x80029194: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    return;
    // 0x80029194: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x80029198: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
L_8002919C:
    // 0x8002919C: jr          $ra
    // 0x800291A0: nop

    return;
    // 0x800291A0: nop

    // 0x800291A4: jr          $ra
    // 0x800291A8: nop

    return;
    // 0x800291A8: nop

;}
RECOMP_FUNC void ftPurinSpecialAirLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015181C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151820: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151824: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151828: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015182C: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80151830: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80151834: jal         0x800E6F24
    // 0x80151838: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80151838: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015183C: jal         0x800E0830
    // 0x80151840: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80151840: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80151844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151848: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015184C: jr          $ra
    // 0x80151850: nop

    return;
    // 0x80151850: nop

;}
RECOMP_FUNC void ftCommonCatchPullProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149EC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80149EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149EC8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80149ECC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80149ED0: addiu       $a1, $a1, -0x6000
    ctx->r5 = ADD32(ctx->r5, -0X6000);
    // 0x80149ED4: jal         0x800D9480
    // 0x80149ED8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149ED8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80149EDC: beq         $v0, $zero, L_80149EF4
    if (ctx->r2 == 0) {
        // 0x80149EE0: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80149EF4;
    }
    // 0x80149EE0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80149EE4: lw          $t8, 0x840($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X840);
    // 0x80149EE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80149EEC: lw          $v0, 0x84($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X84);
    // 0x80149EF0: sw          $t9, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r25;
L_80149EF4:
    // 0x80149EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149EF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80149EFC: jr          $ra
    // 0x80149F00: nop

    return;
    // 0x80149F00: nop

;}
RECOMP_FUNC void mvOpeningYamabukiMakeMBall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131E58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131E5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131E60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E68: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131E6C: jal         0x80009968
    // 0x80131E70: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E70: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131E74: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131E78: lw          $t6, 0x2658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2658);
    // 0x80131E7C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131E80: addiu       $t7, $t7, -0x3620
    ctx->r15 = ADD32(ctx->r15, -0X3620);
    // 0x80131E84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131E88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131E90: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80131E94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80131E98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80131E9C: jal         0x8000F590
    // 0x80131EA0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_1;
    // 0x80131EA0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131EA4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131EA8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131EAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131EB0: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80131EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EB8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131EBC: jal         0x80009DF4
    // 0x80131EC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131EC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131EC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131EC8: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131ECC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131ED0: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80131ED4: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80131ED8: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80131EDC: addiu       $t3, $t3, -0x3540
    ctx->r11 = ADD32(ctx->r11, -0X3540);
    // 0x80131EE0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131EE4: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80131EE8: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80131EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EF0: swc1        $f0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f0.u32l;
    // 0x80131EF4: lw          $t2, 0x2658($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2658);
    // 0x80131EF8: jal         0x8000BD8C
    // 0x80131EFC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80131EFC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x80131F00: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131F04: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F10: jal         0x80008188
    // 0x80131F14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80131F14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80131F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131F1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131F24: jr          $ra
    // 0x80131F28: nop

    return;
    // 0x80131F28: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingGetPuckDistance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801366D0: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    // 0x801366D4: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801366D8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x801366DC: addiu       $a2, $a2, -0x7AA8
    ctx->r6 = ADD32(ctx->r6, -0X7AA8);
    // 0x801366E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801366E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801366E8: mflo        $t6
    ctx->r14 = lo;
    // 0x801366EC: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x801366F0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801366F4: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801366F8: lw          $v0, 0x74($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X74);
    // 0x801366FC: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80136700: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80136704: mflo        $t9
    ctx->r25 = lo;
    // 0x80136708: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x8013670C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80136710: lw          $v1, 0x74($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X74);
    // 0x80136714: lwc1        $f6, 0x5C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80136718: lwc1        $f10, 0x58($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X58);
    // 0x8013671C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80136720: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80136724: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80136728: nop

    // 0x8013672C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80136730: jal         0x80033510
    // 0x80136734: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80136734: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x80136738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013673C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136740: jr          $ra
    // 0x80136744: nop

    return;
    // 0x80136744: nop

;}
RECOMP_FUNC void grSectorArwingUpdateCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107BA0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80107BA4: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80107BA8: lb          $t6, 0x53($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X53);
    // 0x80107BAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80107BB0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80107BB4: beq         $t6, $at, L_80107C90
    if (ctx->r14 == ctx->r1) {
        // 0x80107BB8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80107C90;
    }
    // 0x80107BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107BBC: lbu         $v0, 0x58($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X58);
    // 0x80107BC0: beq         $v0, $zero, L_80107C44
    if (ctx->r2 == 0) {
        // 0x80107BC4: nop
    
            goto L_80107C44;
    }
    // 0x80107BC4: nop

    // 0x80107BC8: lbu         $t7, 0x56($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X56);
    // 0x80107BCC: beq         $t7, $zero, L_80107C44
    if (ctx->r15 == 0) {
        // 0x80107BD0: nop
    
            goto L_80107C44;
    }
    // 0x80107BD0: nop

    // 0x80107BD4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80107BD8: lwc1        $f6, 0x40($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80107BDC: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x80107BE0: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80107BE4: lbu         $t9, 0x57($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X57);
    // 0x80107BE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80107BEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80107BF0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80107BF4: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80107BF8: lwc1        $f10, 0x20($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80107BFC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80107C00: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80107C04: beq         $t9, $zero, L_80107C18
    if (ctx->r25 == 0) {
        // 0x80107C08: swc1        $f18, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
            goto L_80107C18;
    }
    // 0x80107C08: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80107C0C: lbu         $t0, 0x59($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X59);
    // 0x80107C10: bnel        $t0, $zero, L_80107C30
    if (ctx->r8 != 0) {
        // 0x80107C14: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80107C30;
    }
    goto skip_0;
    // 0x80107C14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
L_80107C18:
    // 0x80107C18: jal         0x800FC58C
    // 0x80107C1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mpCollisionSetYakumonoOnID(rdram, ctx);
        goto after_0;
    // 0x80107C1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80107C20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80107C24: jal         0x800FC4A8
    // 0x80107C28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    mpCollisionSetYakumonoPosID(rdram, ctx);
        goto after_1;
    // 0x80107C28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80107C2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80107C30:
    // 0x80107C30: jal         0x800FC4A8
    // 0x80107C34: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    mpCollisionSetYakumonoPosID(rdram, ctx);
        goto after_2;
    // 0x80107C34: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80107C38: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80107C3C: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80107C40: lbu         $v0, 0x58($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X58);
L_80107C44:
    // 0x80107C44: beql        $v0, $zero, L_80107C5C
    if (ctx->r2 == 0) {
        // 0x80107C48: lbu         $t2, 0x57($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X57);
            goto L_80107C5C;
    }
    goto skip_1;
    // 0x80107C48: lbu         $t2, 0x57($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X57);
    skip_1:
    // 0x80107C4C: lbu         $t1, 0x56($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X56);
    // 0x80107C50: bnel        $t1, $zero, L_80107C88
    if (ctx->r9 != 0) {
        // 0x80107C54: lbu         $t4, 0x56($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X56);
            goto L_80107C88;
    }
    goto skip_2;
    // 0x80107C54: lbu         $t4, 0x56($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X56);
    skip_2:
    // 0x80107C58: lbu         $t2, 0x57($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X57);
L_80107C5C:
    // 0x80107C5C: beql        $t2, $zero, L_80107C88
    if (ctx->r10 == 0) {
        // 0x80107C60: lbu         $t4, 0x56($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X56);
            goto L_80107C88;
    }
    goto skip_3;
    // 0x80107C60: lbu         $t4, 0x56($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X56);
    skip_3:
    // 0x80107C64: lbu         $t3, 0x59($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X59);
    // 0x80107C68: beql        $t3, $zero, L_80107C88
    if (ctx->r11 == 0) {
        // 0x80107C6C: lbu         $t4, 0x56($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X56);
            goto L_80107C88;
    }
    goto skip_4;
    // 0x80107C6C: lbu         $t4, 0x56($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X56);
    skip_4:
    // 0x80107C70: jal         0x800FC604
    // 0x80107C74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mpCollisionSetYakumonoOffID(rdram, ctx);
        goto after_3;
    // 0x80107C74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80107C78: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80107C7C: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80107C80: lbu         $v0, 0x58($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X58);
    // 0x80107C84: lbu         $t4, 0x56($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X56);
L_80107C88:
    // 0x80107C88: sb          $v0, 0x59($v1)
    MEM_B(0X59, ctx->r3) = ctx->r2;
    // 0x80107C8C: sb          $t4, 0x57($v1)
    MEM_B(0X57, ctx->r3) = ctx->r12;
L_80107C90:
    // 0x80107C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107C94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80107C98: jr          $ra
    // 0x80107C9C: nop

    return;
    // 0x80107C9C: nop

;}
RECOMP_FUNC void ftParamSetCaptureImmuneMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8098: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E809C: jr          $ra
    // 0x800E80A0: sb          $a1, 0x193($a0)
    MEM_B(0X193, ctx->r4) = ctx->r5;
    return;
    // 0x800E80A0: sb          $a1, 0x193($a0)
    MEM_B(0X193, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void itGShellFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017877C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178780: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80178784: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80178788: lbu         $t6, 0x352($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X352);
    // 0x8017878C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80178790: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80178794: bne         $t6, $zero, L_801787B0
    if (ctx->r14 != 0) {
        // 0x80178798: nop
    
            goto L_801787B0;
    }
    // 0x80178798: nop

    // 0x8017879C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801787A0: jal         0x80173DF4
    // 0x801787A4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyLanding(rdram, ctx);
        goto after_0;
    // 0x801787A4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x801787A8: b           L_801787C0
    // 0x801787AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801787C0;
    // 0x801787AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801787B0:
    // 0x801787B0: jal         0x80173B24
    // 0x801787B4: addiu       $a3, $a3, -0x76F0
    ctx->r7 = ADD32(ctx->r7, -0X76F0);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_1;
    // 0x801787B4: addiu       $a3, $a3, -0x76F0
    ctx->r7 = ADD32(ctx->r7, -0X76F0);
    after_1:
    // 0x801787B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801787BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801787C0:
    // 0x801787C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801787C4: jr          $ra
    // 0x801787C8: nop

    return;
    // 0x801787C8: nop

;}
RECOMP_FUNC void func_ovl8_80371C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371C2C: lwl         $t7, 0x2($a0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r4, 0X2);
    // 0x80371C30: lwr         $t7, 0x5($a0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r4, 0X5);
    // 0x80371C34: swl         $t7, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r15);
    // 0x80371C38: swr         $t7, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r15);
    // 0x80371C3C: lwl         $t6, 0x6($a0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r4, 0X6);
    // 0x80371C40: lwr         $t6, 0x9($a0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r4, 0X9);
    // 0x80371C44: swl         $t6, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r14);
    // 0x80371C48: jr          $ra
    // 0x80371C4C: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
    return;
    // 0x80371C4C: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
;}
RECOMP_FUNC void scVSBattleStartSuddenDeath(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE20: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8018DE24: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DE28: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8018DE2C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8018DE30: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8018DE34: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8018DE38: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8018DE3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018DE40: jal         0x8018E330
    // 0x8018DE44: sb          $zero, 0x4AE2($at)
    MEM_B(0X4AE2, ctx->r1) = 0;
    scVSBattleSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DE44: sb          $zero, 0x4AE2($at)
    MEM_B(0X4AE2, ctx->r1) = 0;
    after_0:
    // 0x8018DE48: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8018DE4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DE50: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DE54: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DE58: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DE5C: jal         0x8000B9FC
    // 0x8018DE60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_1;
    // 0x8018DE60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8018DE64: jal         0x80115890
    // 0x8018DE68: nop

    efParticleInitAll(rdram, ctx);
        goto after_2;
    // 0x8018DE68: nop

    after_2:
    // 0x8018DE6C: jal         0x800EC130
    // 0x8018DE70: nop

    ftParamInitGame(rdram, ctx);
        goto after_3;
    // 0x8018DE70: nop

    after_3:
    // 0x8018DE74: jal         0x800FC284
    // 0x8018DE78: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_4;
    // 0x8018DE78: nop

    after_4:
    // 0x8018DE7C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DE80: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DE84: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DE88: jal         0x8010E598
    // 0x8018DE8C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_5;
    // 0x8018DE8C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_5:
    // 0x8018DE90: jal         0x8010DB54
    // 0x8018DE94: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_6;
    // 0x8018DE94: nop

    after_6:
    // 0x8018DE98: jal         0x80104BDC
    // 0x8018DE9C: nop

    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_7;
    // 0x8018DE9C: nop

    after_7:
    // 0x8018DEA0: jal         0x8010DB00
    // 0x8018DEA4: nop

    gmCameraMakeBattleCamera(rdram, ctx);
        goto after_8;
    // 0x8018DEA4: nop

    after_8:
    // 0x8018DEA8: jal         0x8016DEA0
    // 0x8018DEAC: nop

    itManagerInitItems(rdram, ctx);
        goto after_9;
    // 0x8018DEAC: nop

    after_9:
    // 0x8018DEB0: jal         0x80105600
    // 0x8018DEB4: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_10;
    // 0x8018DEB4: nop

    after_10:
    // 0x8018DEB8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018DEBC: jal         0x800D7194
    // 0x8018DEC0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_11;
    // 0x8018DEC0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x8018DEC4: jal         0x801654B0
    // 0x8018DEC8: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_12;
    // 0x8018DEC8: nop

    after_12:
    // 0x8018DECC: jal         0x800FD300
    // 0x8018DED0: nop

    efManagerInitEffects(rdram, ctx);
        goto after_13;
    // 0x8018DED0: nop

    after_13:
    // 0x8018DED4: jal         0x80115DE8
    // 0x8018DED8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    ifScreenFlashMakeInterface(rdram, ctx);
        goto after_14;
    // 0x8018DED8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_14:
    // 0x8018DEDC: jal         0x801156E4
    // 0x8018DEE0: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_15;
    // 0x8018DEE0: nop

    after_15:
    // 0x8018DEE4: jal         0x801653E0
    // 0x8018DEE8: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_16;
    // 0x8018DEE8: nop

    after_16:
    // 0x8018DEEC: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8018DEF0: addiu       $s2, $s2, 0x50E8
    ctx->r18 = ADD32(ctx->r18, 0X50E8);
    // 0x8018DEF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018DEF8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018DEFC: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
L_8018DF00:
    // 0x8018DF00: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8018DF04: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x8018DF08: addiu       $t1, $t7, 0x3C
    ctx->r9 = ADD32(ctx->r15, 0X3C);
    // 0x8018DF0C: or          $t0, $s4, $zero
    ctx->r8 = ctx->r20 | 0;
L_8018DF10:
    // 0x8018DF10: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018DF14: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018DF18: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018DF1C: sw          $t9, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r25;
    // 0x8018DF20: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8018DF24: sw          $t8, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r24;
    // 0x8018DF28: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8018DF2C: bne         $t7, $t1, L_8018DF10
    if (ctx->r15 != ctx->r9) {
        // 0x8018DF30: sw          $t9, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r25;
            goto L_8018DF10;
    }
    // 0x8018DF30: sw          $t9, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r25;
    // 0x8018DF34: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018DF38: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8018DF3C: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x8018DF40: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8018DF44: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8018DF48: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8018DF4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018DF50: addu        $a1, $t2, $s1
    ctx->r5 = ADD32(ctx->r10, ctx->r17);
    // 0x8018DF54: lbu         $t3, 0x22($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X22);
    // 0x8018DF58: addiu       $t5, $t5, 0x5228
    ctx->r13 = ADD32(ctx->r13, 0X5228);
    // 0x8018DF5C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8018DF60: beq         $t3, $at, L_8018E048
    if (ctx->r11 == ctx->r1) {
        // 0x8018DF64: addu        $s3, $t4, $t5
        ctx->r19 = ADD32(ctx->r12, ctx->r13);
            goto L_8018E048;
    }
    // 0x8018DF64: addu        $s3, $t4, $t5
    ctx->r19 = ADD32(ctx->r12, ctx->r13);
    // 0x8018DF68: jal         0x800D786C
    // 0x8018DF6C: lbu         $a0, 0x23($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_17;
    // 0x8018DF6C: lbu         $a0, 0x23($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X23);
    after_17:
    // 0x8018DF70: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8018DF74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DF78: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8018DF7C: addu        $t1, $t6, $s1
    ctx->r9 = ADD32(ctx->r14, ctx->r17);
    // 0x8018DF80: lbu         $t7, 0x23($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X23);
    // 0x8018DF84: jal         0x800FAF64
    // 0x8018DF88: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    mpCollisionGetPlayerMapObjPosition(rdram, ctx);
        goto after_18;
    // 0x8018DF88: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    after_18:
    // 0x8018DF8C: jal         0x8018D0E0
    // 0x8018DF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scVSBattleGetStartPlayerLR(rdram, ctx);
        goto after_19;
    // 0x8018DF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8018DF94: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018DF98: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8018DF9C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8018DFA0: addu        $a1, $v1, $s1
    ctx->r5 = ADD32(ctx->r3, ctx->r17);
    // 0x8018DFA4: lbu         $t0, 0x25($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X25);
    // 0x8018DFA8: sb          $s0, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r16;
    // 0x8018DFAC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DFB0: sb          $t0, 0x68($sp)
    MEM_B(0X68, ctx->r29) = ctx->r8;
    // 0x8018DFB4: lbu         $t9, 0x5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5);
    // 0x8018DFB8: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x8018DFBC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8018DFC0: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8018DFC4: beql        $at, $zero, L_8018DFD8
    if (ctx->r1 == 0) {
        // 0x8018DFC8: sb          $t4, 0x6A($sp)
        MEM_B(0X6A, ctx->r29) = ctx->r12;
            goto L_8018DFD8;
    }
    goto skip_0;
    // 0x8018DFC8: sb          $t4, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r12;
    skip_0:
    // 0x8018DFCC: b           L_8018DFD8
    // 0x8018DFD0: sb          $t3, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r11;
        goto L_8018DFD8;
    // 0x8018DFD0: sb          $t3, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r11;
    // 0x8018DFD4: sb          $t4, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r12;
L_8018DFD8:
    // 0x8018DFD8: lbu         $t5, 0x26($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X26);
    // 0x8018DFDC: lbu         $t9, 0x73($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X73);
    // 0x8018DFE0: addiu       $t0, $zero, 0x12C
    ctx->r8 = ADD32(0, 0X12C);
    // 0x8018DFE4: sb          $t5, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r13;
    // 0x8018DFE8: lbu         $t6, 0x27($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X27);
    // 0x8018DFEC: ori         $t2, $t9, 0x80
    ctx->r10 = ctx->r25 | 0X80;
    // 0x8018DFF0: sb          $t6, 0x6C($sp)
    MEM_B(0X6C, ctx->r29) = ctx->r14;
    // 0x8018DFF4: lbu         $t1, 0x21($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X21);
    // 0x8018DFF8: sb          $t1, 0x6D($sp)
    MEM_B(0X6D, ctx->r29) = ctx->r9;
    // 0x8018DFFC: lbu         $t7, 0x20($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X20);
    // 0x8018E000: sb          $zero, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = 0;
    // 0x8018E004: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // 0x8018E008: sb          $t2, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r10;
    // 0x8018E00C: sb          $t7, 0x6E($sp)
    MEM_B(0X6E, ctx->r29) = ctx->r15;
    // 0x8018E010: lbu         $t3, 0x22($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X22);
    // 0x8018E014: sw          $s3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r19;
    // 0x8018E018: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x8018E01C: jal         0x800D78B4
    // 0x8018E020: lbu         $a0, 0x23($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_20;
    // 0x8018E020: lbu         $a0, 0x23($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X23);
    after_20:
    // 0x8018E024: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x8018E028: jal         0x800D7F3C
    // 0x8018E02C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_21;
    // 0x8018E02C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_21:
    // 0x8018E030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018E034: jal         0x800E7C4C
    // 0x8018E038: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_22;
    // 0x8018E038: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_22:
    // 0x8018E03C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8018E040: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8018E044: sb          $zero, 0x29($t5)
    MEM_B(0X29, ctx->r13) = 0;
L_8018E048:
    // 0x8018E048: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018E04C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018E050: bne         $s0, $at, L_8018DF00
    if (ctx->r16 != ctx->r1) {
        // 0x8018E054: addiu       $s1, $s1, 0x74
        ctx->r17 = ADD32(ctx->r17, 0X74);
            goto L_8018DF00;
    }
    // 0x8018E054: addiu       $s1, $s1, 0x74
    ctx->r17 = ADD32(ctx->r17, 0X74);
    // 0x8018E058: jal         0x800D782C
    // 0x8018E05C: nop

    ftManagerSetupFilesPlayablesAll(rdram, ctx);
        goto after_23;
    // 0x8018E05C: nop

    after_23:
    // 0x8018E060: jal         0x80114958
    // 0x8018E064: nop

    ifCommonBattleSetGameStatusWait(rdram, ctx);
        goto after_24;
    // 0x8018E064: nop

    after_24:
    // 0x8018E068: jal         0x8010E2D4
    // 0x8018E06C: nop

    gmCameraMakePlayerArrowsCamera(rdram, ctx);
        goto after_25;
    // 0x8018E06C: nop

    after_25:
    // 0x8018E070: jal         0x801118E4
    // 0x8018E074: nop

    ifCommonPlayerArrowsInitInterface(rdram, ctx);
        goto after_26;
    // 0x8018E074: nop

    after_26:
    // 0x8018E078: jal         0x8010E1A4
    // 0x8018E07C: nop

    gmCameraMakePlayerMagnifyCamera(rdram, ctx);
        goto after_27;
    // 0x8018E07C: nop

    after_27:
    // 0x8018E080: jal         0x80111440
    // 0x8018E084: nop

    ifCommonPlayerMagnifyMakeInterface(rdram, ctx);
        goto after_28;
    // 0x8018E084: nop

    after_28:
    // 0x8018E088: jal         0x8010DDC4
    // 0x8018E08C: nop

    gmCameraScreenFlashMakeCamera(rdram, ctx);
        goto after_29;
    // 0x8018E08C: nop

    after_29:
    // 0x8018E090: jal         0x8010E374
    // 0x8018E094: nop

    gmCameraMakeInterfaceCamera(rdram, ctx);
        goto after_30;
    // 0x8018E094: nop

    after_30:
    // 0x8018E098: jal         0x8010E498
    // 0x8018E09C: nop

    gmCameraMakeEffectCamera(rdram, ctx);
        goto after_31;
    // 0x8018E09C: nop

    after_31:
    // 0x8018E0A0: jal         0x80111BE4
    // 0x8018E0A4: nop

    ifCommonPlayerTagMakeInterface(rdram, ctx);
        goto after_32;
    // 0x8018E0A4: nop

    after_32:
    // 0x8018E0A8: jal         0x8010F3A0
    // 0x8018E0AC: nop

    ifCommonPlayerDamageSetDigitPositions(rdram, ctx);
        goto after_33;
    // 0x8018E0AC: nop

    after_33:
    // 0x8018E0B0: jal         0x8010F3C0
    // 0x8018E0B4: nop

    ifCommonPlayerDamageInitInterface(rdram, ctx);
        goto after_34;
    // 0x8018E0B4: nop

    after_34:
    // 0x8018E0B8: jal         0x80110514
    // 0x8018E0BC: nop

    ifCommonPlayerStockInitInterface(rdram, ctx);
        goto after_35;
    // 0x8018E0BC: nop

    after_35:
    // 0x8018E0C0: jal         0x80112B74
    // 0x8018E0C4: nop

    ifCommonSuddenDeathMakeInterface(rdram, ctx);
        goto after_36;
    // 0x8018E0C4: nop

    after_36:
    // 0x8018E0C8: jal         0x800FC3E8
    // 0x8018E0CC: nop

    mpCollisionSetPlayBGM(rdram, ctx);
        goto after_37;
    // 0x8018E0CC: nop

    after_37:
    // 0x8018E0D0: jal         0x800269C0
    // 0x8018E0D4: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    func_800269C0_275C0(rdram, ctx);
        goto after_38;
    // 0x8018E0D4: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_38:
    // 0x8018E0D8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018E0DC: jal         0x80113398
    // 0x8018E0E0: addiu       $a0, $a0, 0x4D98
    ctx->r4 = ADD32(ctx->r4, 0X4D98);
    ifCommonTimerMakeInterface(rdram, ctx);
        goto after_39;
    // 0x8018E0E0: addiu       $a0, $a0, 0x4D98
    ctx->r4 = ADD32(ctx->r4, 0X4D98);
    after_39:
    // 0x8018E0E4: jal         0x80112F68
    // 0x8018E0E8: nop

    ifCommonTimerMakeDigits(rdram, ctx);
        goto after_40;
    // 0x8018E0E8: nop

    after_40:
    // 0x8018E0EC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018E0F0: addiu       $t6, $t6, -0x1C2C
    ctx->r14 = ADD32(ctx->r14, -0X1C2C);
    // 0x8018E0F4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8018E0F8: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x8018E0FC: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8018E100: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8018E104: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018E108: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018E10C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018E110: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018E114: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x8018E118: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8018E11C: jal         0x800D4060
    // 0x8018E120: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_41;
    // 0x8018E120: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_41:
    // 0x8018E124: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E128: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018E12C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E130: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018E134: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8018E138: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8018E13C: jr          $ra
    // 0x8018E140: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8018E140: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void ftCommonHammerTurnProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147B14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147B1C: jal         0x8014800C
    // 0x80147B20: nop

    ftCommonHammerKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x80147B20: nop

    after_0:
    // 0x80147B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147B2C: jr          $ra
    // 0x80147B30: nop

    return;
    // 0x80147B30: nop

;}
RECOMP_FUNC void grHyruleTwisterUpdateTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A7CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A7D4: jal         0x8010A4F4
    // 0x8010A7D8: nop

    grHyruleTwisterDecLifetimeCheckStop(rdram, ctx);
        goto after_0;
    // 0x8010A7D8: nop

    after_0:
    // 0x8010A7DC: bne         $v0, $zero, L_8010A814
    if (ctx->r2 != 0) {
        // 0x8010A7E0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8010A814;
    }
    // 0x8010A7E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010A7E4: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010A7E8: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x8010A7EC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8010A7F0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8010A7F4: bne         $t8, $zero, L_8010A814
    if (ctx->r24 != 0) {
        // 0x8010A7F8: sh          $t7, 0x24($v0)
        MEM_H(0X24, ctx->r2) = ctx->r15;
            goto L_8010A814;
    }
    // 0x8010A7F8: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x8010A7FC: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8010A800: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8010A804: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x8010A808: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8010A80C: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x8010A810: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
L_8010A814:
    // 0x8010A814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A81C: jr          $ra
    // 0x8010A820: nop

    return;
    // 0x8010A820: nop

;}
RECOMP_FUNC void itMSBombWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017650C: jal         0x80172E74
    // 0x80176510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80176510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80176514: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80176518: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x8017651C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80176520: jal         0x80172EC8
    // 0x80176524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80176524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80176528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017652C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176530: jr          $ra
    // 0x80176534: nop

    return;
    // 0x80176534: nop

;}
RECOMP_FUNC void func_ovl8_80381B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381B04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80381B08: jr          $ra
    // 0x80381B0C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80381B0C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void ftCommonYoshiEggSetDamageCollCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CDFC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014CE00: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8014CE04: addiu       $t8, $t8, -0x78E0
    ctx->r24 = ADD32(ctx->r24, -0X78E0);
    // 0x8014CE08: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8014CE0C: lw          $t9, 0x8E8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8E8);
    // 0x8014CE10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014CE14: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8014CE18: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8014CE1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014CE20: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8014CE24: sw          $zero, 0x5C0($v0)
    MEM_W(0X5C0, ctx->r2) = 0;
    // 0x8014CE28: sw          $t0, 0x5C8($v0)
    MEM_W(0X5C8, ctx->r2) = ctx->r8;
    // 0x8014CE2C: sw          $zero, 0x5CC($v0)
    MEM_W(0X5CC, ctx->r2) = 0;
    // 0x8014CE30: sw          $t9, 0x5C4($v0)
    MEM_W(0X5C4, ctx->r2) = ctx->r25;
    // 0x8014CE34: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8014CE38: addiu       $a2, $v0, 0x5E8
    ctx->r6 = ADD32(ctx->r2, 0X5E8);
    // 0x8014CE3C: addiu       $a1, $a2, 0x2C
    ctx->r5 = ADD32(ctx->r6, 0X2C);
    // 0x8014CE40: sw          $t2, 0x5D0($v0)
    MEM_W(0X5D0, ctx->r2) = ctx->r10;
    // 0x8014CE44: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x8014CE48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8014CE4C: sw          $t1, 0x5D4($v0)
    MEM_W(0X5D4, ctx->r2) = ctx->r9;
    // 0x8014CE50: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8014CE54: sw          $t2, 0x5D8($v0)
    MEM_W(0X5D8, ctx->r2) = ctx->r10;
    // 0x8014CE58: lw          $t4, 0x10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X10);
    // 0x8014CE5C: sw          $t4, 0x5DC($v0)
    MEM_W(0X5DC, ctx->r2) = ctx->r12;
    // 0x8014CE60: lw          $t3, 0x14($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X14);
    // 0x8014CE64: sw          $t3, 0x5E0($v0)
    MEM_W(0X5E0, ctx->r2) = ctx->r11;
    // 0x8014CE68: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
    // 0x8014CE6C: sw          $t4, 0x5E4($v0)
    MEM_W(0X5E4, ctx->r2) = ctx->r12;
    // 0x8014CE70: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8014CE74: beql        $t5, $zero, L_8014CE84
    if (ctx->r13 == 0) {
        // 0x8014CE78: lw          $t6, 0x0($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X0);
            goto L_8014CE84;
    }
    goto skip_0;
    // 0x8014CE78: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8014CE7C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x8014CE80: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
L_8014CE84:
    // 0x8014CE84: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8014CE88: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8014CE8C: beq         $t6, $zero, L_8014CE98
    if (ctx->r14 == 0) {
        // 0x8014CE90: addiu       $a2, $zero, 0xB
        ctx->r6 = ADD32(0, 0XB);
            goto L_8014CE98;
    }
    // 0x8014CE90: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8014CE94: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
L_8014CE98:
    // 0x8014CE98: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
L_8014CE9C:
    // 0x8014CE9C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8014CEA0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8014CEA4: beql        $t7, $zero, L_8014CEB4
    if (ctx->r15 == 0) {
        // 0x8014CEA8: lw          $t8, 0x2C($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X2C);
            goto L_8014CEB4;
    }
    goto skip_1;
    // 0x8014CEA8: lw          $t8, 0x2C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2C);
    skip_1:
    // 0x8014CEAC: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8014CEB0: lw          $t8, 0x2C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2C);
L_8014CEB4:
    // 0x8014CEB4: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    // 0x8014CEB8: beql        $t8, $zero, L_8014CEC8
    if (ctx->r24 == 0) {
        // 0x8014CEBC: lw          $t9, 0x2C($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X2C);
            goto L_8014CEC8;
    }
    goto skip_2;
    // 0x8014CEBC: lw          $t9, 0x2C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2C);
    skip_2:
    // 0x8014CEC0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8014CEC4: lw          $t9, 0x2C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2C);
L_8014CEC8:
    // 0x8014CEC8: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    // 0x8014CECC: beql        $t9, $zero, L_8014CEDC
    if (ctx->r25 == 0) {
        // 0x8014CED0: lw          $t0, 0x2C($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X2C);
            goto L_8014CEDC;
    }
    goto skip_3;
    // 0x8014CED0: lw          $t0, 0x2C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X2C);
    skip_3:
    // 0x8014CED4: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8014CED8: lw          $t0, 0x2C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X2C);
L_8014CEDC:
    // 0x8014CEDC: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    // 0x8014CEE0: beq         $t0, $zero, L_8014CEEC
    if (ctx->r8 == 0) {
        // 0x8014CEE4: nop
    
            goto L_8014CEEC;
    }
    // 0x8014CEE4: nop

    // 0x8014CEE8: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
L_8014CEEC:
    // 0x8014CEEC: bne         $v1, $a2, L_8014CE9C
    if (ctx->r3 != ctx->r6) {
        // 0x8014CEF0: addiu       $a1, $a1, 0x2C
        ctx->r5 = ADD32(ctx->r5, 0X2C);
            goto L_8014CE9C;
    }
    // 0x8014CEF0: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    // 0x8014CEF4: lbu         $t2, 0x18C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X18C);
    // 0x8014CEF8: ori         $t5, $t2, 0x40
    ctx->r13 = ctx->r10 | 0X40;
    // 0x8014CEFC: sb          $t5, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r13;
    // 0x8014CF00: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x8014CF04: jr          $ra
    // 0x8014CF08: sb          $t6, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r14;
    return;
    // 0x8014CF08: sb          $t6, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80026A10_27610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A10: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80026A14: addiu       $v0, $v0, -0x1230
    ctx->r2 = ADD32(ctx->r2, -0X1230);
    // 0x80026A18: lhu         $t6, 0x28($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X28);
    // 0x80026A1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026A20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026A24: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026A28: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026A2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026A30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80026A34: bne         $at, $zero, L_80026A44
    if (ctx->r1 != 0) {
        // 0x80026A38: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80026A44;
    }
    // 0x80026A38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80026A3C: b           L_80026A58
    // 0x80026A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80026A58;
    // 0x80026A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80026A44:
    // 0x80026A44: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x80026A48: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80026A4C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80026A50: jal         0x80026844
    // 0x80026A54: lw          $s1, 0x0($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X0);
    func_80026844_27444(rdram, ctx);
        goto after_0;
    // 0x80026A54: lw          $s1, 0x0($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X0);
    after_0:
L_80026A58:
    // 0x80026A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026A5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80026A60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80026A64: jr          $ra
    // 0x80026A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void syVectorDirection3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019914: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019918: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001991C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019920: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019924: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80019928: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001992C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80019930: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80019934: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001993C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80019940: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80019944: add.s       $f0, $f4, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80019948: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8001994C: nop

    // 0x80019950: bc1t        L_80019978
    if (c1cs) {
        // 0x80019954: nop
    
            goto L_80019978;
    }
    // 0x80019954: nop

    // 0x80019958: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001995C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80019960: bc1f        L_80019970
    if (!c1cs) {
        // 0x80019964: nop
    
            goto L_80019970;
    }
    // 0x80019964: nop

    // 0x80019968: jr          $ra
    // 0x8001996C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8001996C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80019970:
    // 0x80019970: jr          $ra
    // 0x80019974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80019974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80019978:
    // 0x80019978: jr          $ra
    // 0x8001997C: nop

    return;
    // 0x8001997C: nop

;}
RECOMP_FUNC void mnPlayersVSGetShade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B78: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80131B7C: lw          $v0, -0x4258($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4258);
    // 0x80131B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131B84: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80131B88: bne         $v0, $zero, L_80131B98
    if (ctx->r2 != 0) {
        // 0x80131B8C: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80131B98;
    }
    // 0x80131B8C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80131B90: b           L_80131C6C
    // 0x80131B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80131C6C;
    // 0x80131B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131B98:
    // 0x80131B98: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
L_80131B9C:
    // 0x80131B9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80131BA0: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80131BA4: bne         $at, $zero, L_80131B9C
    if (ctx->r1 != 0) {
        // 0x80131BA8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80131B9C;
    }
    // 0x80131BA8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x80131BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131BB0: bne         $a2, $v0, L_80131C6C
    if (ctx->r6 != ctx->r2) {
        // 0x80131BB4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131C6C;
    }
    // 0x80131BB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131BB8: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80131BBC: addiu       $a3, $a3, -0x4578
    ctx->r7 = ADD32(ctx->r7, -0X4578);
    // 0x80131BC0: addiu       $t1, $sp, 0x10
    ctx->r9 = ADD32(ctx->r29, 0X10);
    // 0x80131BC4: addiu       $t0, $zero, 0xBC
    ctx->r8 = ADD32(0, 0XBC);
L_80131BC8:
    // 0x80131BC8: beql        $a1, $v1, L_80131C1C
    if (ctx->r5 == ctx->r3) {
        // 0x80131BCC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80131C1C;
    }
    goto skip_0;
    // 0x80131BCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80131BD0: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BD4: mflo        $t6
    ctx->r14 = lo;
    // 0x80131BD8: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
    // 0x80131BDC: lw          $t8, 0x48($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X48);
    // 0x80131BE0: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BE4: mflo        $t7
    ctx->r15 = lo;
    // 0x80131BE8: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
    // 0x80131BEC: lw          $t9, 0x48($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X48);
    // 0x80131BF0: bnel        $t8, $t9, L_80131C1C
    if (ctx->r24 != ctx->r25) {
        // 0x80131BF4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80131C1C;
    }
    goto skip_1;
    // 0x80131BF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80131BF8: lw          $t2, 0x40($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X40);
    // 0x80131BFC: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80131C00: bnel        $t2, $t3, L_80131C1C
    if (ctx->r10 != ctx->r11) {
        // 0x80131C04: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80131C1C;
    }
    goto skip_2;
    // 0x80131C04: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80131C08: lw          $t4, 0x50($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X50);
    // 0x80131C0C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80131C10: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x80131C14: sw          $a2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r6;
    // 0x80131C18: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131C1C:
    // 0x80131C1C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80131C20: bne         $at, $zero, L_80131BC8
    if (ctx->r1 != 0) {
        // 0x80131C24: nop
    
            goto L_80131BC8;
    }
    // 0x80131C24: nop

    // 0x80131C28: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x80131C2C: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80131C30: bne         $t7, $zero, L_80131C40
    if (ctx->r15 != 0) {
        // 0x80131C34: nop
    
            goto L_80131C40;
    }
    // 0x80131C34: nop

    // 0x80131C38: b           L_80131C6C
    // 0x80131C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80131C6C;
    // 0x80131C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131C40:
    // 0x80131C40: bne         $t8, $zero, L_80131C50
    if (ctx->r24 != 0) {
        // 0x80131C44: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80131C50;
    }
    // 0x80131C44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80131C48: b           L_80131C6C
    // 0x80131C4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80131C6C;
    // 0x80131C4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131C50:
    // 0x80131C50: bne         $t9, $zero, L_80131C60
    if (ctx->r25 != 0) {
        // 0x80131C54: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_80131C60;
    }
    // 0x80131C54: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C58: b           L_80131C6C
    // 0x80131C5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80131C6C;
    // 0x80131C5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80131C60:
    // 0x80131C60: bne         $t2, $zero, L_80131C6C
    if (ctx->r10 != 0) {
        // 0x80131C64: nop
    
            goto L_80131C6C;
    }
    // 0x80131C64: nop

    // 0x80131C68: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80131C6C:
    // 0x80131C6C: jr          $ra
    // 0x80131C70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80131C70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnPlayersVSCheckPuckInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135B98: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80135B9C: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80135BA0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80135BA4: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80135BA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80135BAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80135BB0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135BB4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135BB8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80135BBC: lw          $t7, -0x4574($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4574);
    // 0x80135BC0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80135BC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135BC8: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135BCC: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x80135BD0: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80135BD4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135BD8: lwc1        $f2, 0x58($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80135BDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135BE0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80135BE4: nop

    // 0x80135BE8: bc1f        L_80135C14
    if (!c1cs) {
        // 0x80135BEC: nop
    
            goto L_80135C14;
    }
    // 0x80135BEC: nop

    // 0x80135BF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135BF4: nop

    // 0x80135BF8: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80135BFC: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80135C00: nop

    // 0x80135C04: bc1f        L_80135C14
    if (!c1cs) {
        // 0x80135C08: nop
    
            goto L_80135C14;
    }
    // 0x80135C08: nop

    // 0x80135C0C: b           L_80135C14
    // 0x80135C10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80135C14;
    // 0x80135C10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80135C14:
    // 0x80135C14: beq         $a0, $zero, L_80135C78
    if (ctx->r4 == 0) {
        // 0x80135C18: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80135C78;
    }
    // 0x80135C18: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80135C1C: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135C20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80135C24: lwc1        $f2, 0x5C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80135C28: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80135C2C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80135C30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135C34: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80135C38: nop

    // 0x80135C3C: bc1f        L_80135C68
    if (!c1cs) {
        // 0x80135C40: nop
    
            goto L_80135C68;
    }
    // 0x80135C40: nop

    // 0x80135C44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135C48: nop

    // 0x80135C4C: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80135C50: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80135C54: nop

    // 0x80135C58: bc1f        L_80135C68
    if (!c1cs) {
        // 0x80135C5C: nop
    
            goto L_80135C68;
    }
    // 0x80135C5C: nop

    // 0x80135C60: b           L_80135C68
    // 0x80135C64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80135C68;
    // 0x80135C64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80135C68:
    // 0x80135C68: beql        $a0, $zero, L_80135C7C
    if (ctx->r4 == 0) {
        // 0x80135C6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135C7C;
    }
    goto skip_0;
    // 0x80135C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80135C70: jr          $ra
    // 0x80135C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135C78:
    // 0x80135C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135C7C:
    // 0x80135C7C: jr          $ra
    // 0x80135C80: nop

    return;
    // 0x80135C80: nop

;}
RECOMP_FUNC void mvOpeningRoomDeskGroundProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132AB0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132AB4: lw          $t6, 0x4CE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4CE4);
    // 0x80132AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132AC0: slti        $at, $t6, 0x425
    ctx->r1 = SIGNED(ctx->r14) < 0X425 ? 1 : 0;
    // 0x80132AC4: bnel        $at, $zero, L_80132AD8
    if (ctx->r1 != 0) {
        // 0x80132AC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132AD8;
    }
    goto skip_0;
    // 0x80132AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132ACC: jal         0x8000DF34
    // 0x80132AD0: nop

    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x80132AD0: nop

    after_0:
    // 0x80132AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132AD8:
    // 0x80132AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132ADC: jr          $ra
    // 0x80132AE0: nop

    return;
    // 0x80132AE0: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153E80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80153E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153E88: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80153E8C: lw          $t6, 0x9C8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X9C8);
    // 0x80153E90: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80153E94: lw          $v0, 0xB20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB20);
    // 0x80153E98: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80153E9C: beq         $v0, $zero, L_80153EAC
    if (ctx->r2 == 0) {
        // 0x80153EA0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80153EAC;
    }
    // 0x80153EA0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80153EA4: b           L_80153EC4
    // 0x80153EA8: sw          $t7, 0xB20($a3)
    MEM_W(0XB20, ctx->r7) = ctx->r15;
        goto L_80153EC4;
    // 0x80153EA8: sw          $t7, 0xB20($a3)
    MEM_W(0XB20, ctx->r7) = ctx->r15;
L_80153EAC:
    // 0x80153EAC: lw          $a2, 0x5C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X5C);
    // 0x80153EB0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80153EB4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80153EB8: jal         0x800D8D68
    // 0x80153EBC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80153EBC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x80153EC0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80153EC4:
    // 0x80153EC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80153EC8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80153ECC: jal         0x800D8FA8
    // 0x80153ED0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x80153ED0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80153ED4: bne         $v0, $zero, L_80153EE8
    if (ctx->r2 != 0) {
        // 0x80153ED8: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80153EE8;
    }
    // 0x80153ED8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80153EDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80153EE0: jal         0x800D9074
    // 0x80153EE4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x80153EE4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80153EE8:
    // 0x80153EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80153EF0: jr          $ra
    // 0x80153EF4: nop

    return;
    // 0x80153EF4: nop

;}
RECOMP_FUNC void itSpearCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80180198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018019C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801801A0: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x801801A4: bnel        $a1, $zero, L_801801C0
    if (ctx->r5 != 0) {
        // 0x801801A8: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_801801C0;
    }
    goto skip_0;
    // 0x801801A8: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x801801AC: jal         0x8017FF74
    // 0x801801B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itSpearAppearSetStatus(rdram, ctx);
        goto after_0;
    // 0x801801B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801801B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801801B8: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x801801BC: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_801801C0:
    // 0x801801C0: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x801801C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801801C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801801CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801801D0: jr          $ra
    // 0x801801D4: nop

    return;
    // 0x801801D4: nop

;}
RECOMP_FUNC void itHammerDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017637C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176380: jal         0x80172FBC
    // 0x80176384: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainClearColAnim(rdram, ctx);
        goto after_0;
    // 0x80176384: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80176388: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017638C: addiu       $a1, $a1, -0x625C
    ctx->r5 = ADD32(ctx->r5, -0X625C);
    // 0x80176390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80176394: jal         0x80172EC8
    // 0x80176398: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80176398: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8017639C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801763A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801763A4: lwc1        $f4, -0x32EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32EC);
    // 0x801763A8: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x801763AC: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801763B0: jal         0x800E7B54
    // 0x801763B4: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    ftParamTryUpdateItemMusic(rdram, ctx);
        goto after_2;
    // 0x801763B4: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    after_2:
    // 0x801763B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801763BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801763C0: jr          $ra
    // 0x801763C4: nop

    return;
    // 0x801763C4: nop

;}
RECOMP_FUNC void mnVSResultsGetNumberColorID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801353F4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801353F8: addiu       $t6, $t6, -0x6964
    ctx->r14 = ADD32(ctx->r14, -0X6964);
    // 0x801353FC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80135400: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80135404: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x80135408: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8013540C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80135410: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80135414: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x80135418: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8013541C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80135420: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80135424: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80135428: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8013542C: lbu         $t9, -0x63EC($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X63EC);
    // 0x80135430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135434: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80135438: beq         $t9, $at, L_80135448
    if (ctx->r25 == ctx->r1) {
        // 0x8013543C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80135448;
    }
    // 0x8013543C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80135440: b           L_80135460
    // 0x80135444: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80135460;
    // 0x80135444: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80135448:
    // 0x80135448: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8013544C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80135450: lbu         $t1, 0x4D2C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4D2C);
    // 0x80135454: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80135458: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x8013545C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
L_80135460:
    // 0x80135460: jr          $ra
    // 0x80135464: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80135464: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void syControllerUpdateGlobalData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003F9C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80003FA0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80003FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003FA8: addiu       $a3, $a3, 0x5228
    ctx->r7 = ADD32(ctx->r7, 0X5228);
    // 0x80003FAC: addiu       $v1, $v1, 0x51A8
    ctx->r3 = ADD32(ctx->r3, 0X51A8);
    // 0x80003FB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003FB4: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80003FB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_80003FBC:
    // 0x80003FBC: lbu         $t6, 0x1C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1C);
    // 0x80003FC0: bnel        $t6, $zero, L_80004014
    if (ctx->r14 != 0) {
        // 0x80003FC4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80004014;
    }
    goto skip_0;
    // 0x80003FC4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80003FC8: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003FCC: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x80003FD0: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x80003FD4: lhu         $t1, 0xC($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0XC);
    // 0x80003FD8: lhu         $t2, 0x8($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X8);
    // 0x80003FDC: lb          $t3, 0xE($v1)
    ctx->r11 = MEM_B(ctx->r3, 0XE);
    // 0x80003FE0: lb          $t4, 0xF($v1)
    ctx->r12 = MEM_B(ctx->r3, 0XF);
    // 0x80003FE4: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x80003FE8: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x80003FEC: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80003FF0: mflo        $t7
    ctx->r15 = lo;
    // 0x80003FF4: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x80003FF8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80003FFC: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80004000: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
    // 0x80004004: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    // 0x80004008: sb          $t3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r11;
    // 0x8000400C: sb          $t4, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r12;
    // 0x80004010: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80004014:
    // 0x80004014: bne         $a1, $a2, L_80003FBC
    if (ctx->r5 != ctx->r6) {
        // 0x80004018: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_80003FBC;
    }
    // 0x80004018: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8000401C: jal         0x80003C00
    // 0x80004020: nop

    syControllerUpdateDeviceIndexes(rdram, ctx);
        goto after_0;
    // 0x80004020: nop

    after_0:
    // 0x80004024: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80004028: lb          $t5, 0x51A4($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X51A4);
    // 0x8000402C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80004030: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80004034: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80004038: addiu       $a3, $a3, 0x5228
    ctx->r7 = ADD32(ctx->r7, 0X5228);
    // 0x8000403C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004044: mflo        $t6
    ctx->r14 = lo;
    // 0x80004048: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
    // 0x8000404C: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x80004050: sh          $t7, 0x5472($at)
    MEM_H(0X5472, ctx->r1) = ctx->r15;
    // 0x80004054: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80004058: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000405C: sh          $t8, 0x5470($at)
    MEM_H(0X5470, ctx->r1) = ctx->r24;
    // 0x80004060: lhu         $t9, 0x4($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4);
    // 0x80004064: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004068: sh          $t9, 0x5474($at)
    MEM_H(0X5474, ctx->r1) = ctx->r25;
    // 0x8000406C: lhu         $t1, 0x6($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X6);
    // 0x80004070: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004074: sh          $t1, 0x5476($at)
    MEM_H(0X5476, ctx->r1) = ctx->r9;
    // 0x80004078: lb          $t2, 0x8($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X8);
    // 0x8000407C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004080: sb          $t2, 0x5478($at)
    MEM_B(0X5478, ctx->r1) = ctx->r10;
    // 0x80004084: lb          $t3, 0x9($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X9);
    // 0x80004088: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000408C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004090: sb          $t3, 0x5479($at)
    MEM_B(0X5479, ctx->r1) = ctx->r11;
    // 0x80004094: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004098: jr          $ra
    // 0x8000409C: sw          $zero, 0x5250($at)
    MEM_W(0X5250, ctx->r1) = 0;
    return;
    // 0x8000409C: sw          $zero, 0x5250($at)
    MEM_W(0X5250, ctx->r1) = 0;
;}
RECOMP_FUNC void itLinkBombHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018611C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80186120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80186124: jal         0x80185CE4
    // 0x80186128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itLinkBombCommonSetHitStatusNone(rdram, ctx);
        goto after_0;
    // 0x80186128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018612C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80186130: addiu       $a1, $a1, -0x490C
    ctx->r5 = ADD32(ctx->r5, -0X490C);
    // 0x80186134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80186138: jal         0x80172EC8
    // 0x8018613C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8018613C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80186140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80186144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80186148: jr          $ra
    // 0x8018614C: nop

    return;
    // 0x8018614C: nop

;}
RECOMP_FUNC void func_ovl8_80381130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80381134: bne         $a0, $zero, L_8038114C
    if (ctx->r4 != 0) {
        // 0x80381138: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8038114C;
    }
    // 0x80381138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038113C: jal         0x803717A0
    // 0x80381140: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80381140: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x80381144: beq         $v0, $zero, L_80381158
    if (ctx->r2 == 0) {
        // 0x80381148: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80381158;
    }
    // 0x80381148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8038114C:
    // 0x8038114C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80381150: addiu       $t6, $t6, -0x43CC
    ctx->r14 = ADD32(ctx->r14, -0X43CC);
    // 0x80381154: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
L_80381158:
    // 0x80381158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038115C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80381160: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80381164: jr          $ra
    // 0x80381168: nop

    return;
    // 0x80381168: nop

;}
RECOMP_FUNC void syControllerSetAutoRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004368: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000436C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004370: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80004374: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80004378: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8000437C: jal         0x80004284
    // 0x80004380: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syControllerDispatchEvent(rdram, ctx);
        goto after_0;
    // 0x80004380: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80004384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000438C: jr          $ra
    // 0x80004390: nop

    return;
    // 0x80004390: nop

;}
RECOMP_FUNC void itMarumineMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183A74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80183A78: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80183A7C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80183A80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80183A84: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80183A88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80183A8C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80183A90: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80183A94: addiu       $a1, $a1, -0x4C00
    ctx->r5 = ADD32(ctx->r5, -0X4C00);
    // 0x80183A98: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80183A9C: jal         0x8016E174
    // 0x80183AA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80183AA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80183AA4: beq         $v0, $zero, L_80183AF8
    if (ctx->r2 == 0) {
        // 0x80183AA8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80183AF8;
    }
    // 0x80183AA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80183AAC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80183AB0: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x80183AB4: lw          $a0, 0x74($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X74);
    // 0x80183AB8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80183ABC: lbu         $t1, 0x2D3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2D3);
    // 0x80183AC0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80183AC4: sw          $t9, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->r25;
    // 0x80183AC8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80183ACC: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80183AD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80183AD4: sw          $t8, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r24;
    // 0x80183AD8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80183ADC: sb          $t2, 0x2D3($v0)
    MEM_B(0X2D3, ctx->r2) = ctx->r10;
    // 0x80183AE0: sw          $t9, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->r25;
    // 0x80183AE4: jal         0x80008CC0
    // 0x80183AE8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80183AE8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80183AEC: jal         0x800269C0
    // 0x80183AF0: addiu       $a0, $zero, 0x22B
    ctx->r4 = ADD32(0, 0X22B);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80183AF0: addiu       $a0, $zero, 0x22B
    ctx->r4 = ADD32(0, 0X22B);
    after_2:
    // 0x80183AF4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80183AF8:
    // 0x80183AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80183AFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80183B00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80183B04: jr          $ra
    // 0x80183B08: nop

    return;
    // 0x80183B08: nop

;}
RECOMP_FUNC void ftCommonReboundWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144A98: jal         0x80144A60
    // 0x80144A9C: nop

    ftCommonReboundSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144A9C: nop

    after_0:
    // 0x80144AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144AA8: jr          $ra
    // 0x80144AAC: nop

    return;
    // 0x80144AAC: nop

;}
RECOMP_FUNC void efManagerMakeEffectNoForce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDAFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FDB00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FDB04: jal         0x800FD778
    // 0x800FDB08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    efManagerMakeEffect(rdram, ctx);
        goto after_0;
    // 0x800FDB08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800FDB0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FDB10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FDB14: jr          $ra
    // 0x800FDB18: nop

    return;
    // 0x800FDB18: nop

;}
RECOMP_FUNC void ftCommonRebirthWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D3A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013D3A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013D3AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013D3B0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013D3B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013D3B8: jal         0x80151098
    // 0x8013D3BC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013D3BC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013D3C0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D3C4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_0;
    // 0x8013D3C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8013D3C8: jal         0x80151160
    // 0x8013D3CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013D3CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013D3D0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D3D4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_1;
    // 0x8013D3D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8013D3D8: jal         0x801511E0
    // 0x8013D3DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8013D3DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013D3E0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D3E4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_2;
    // 0x8013D3E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8013D3E8: jal         0x80149CE0
    // 0x8013D3EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x8013D3EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013D3F0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D3F4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_3;
    // 0x8013D3F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8013D3F8: jal         0x80150470
    // 0x8013D3FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x8013D3FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013D400: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D404: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_4;
    // 0x8013D404: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8013D408: jal         0x8015070C
    // 0x8013D40C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x8013D40C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013D410: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D414: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_5;
    // 0x8013D414: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8013D418: jal         0x80150884
    // 0x8013D41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw4CheckInterruptCommon(rdram, ctx);
        goto after_6;
    // 0x8013D41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8013D420: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D424: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_6;
    // 0x8013D424: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x8013D428: jal         0x8014F8C0
    // 0x8013D42C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x8013D42C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8013D430: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D434: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_7;
    // 0x8013D434: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x8013D438: jal         0x8014FB1C
    // 0x8013D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x8013D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8013D440: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D444: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_8;
    // 0x8013D444: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x8013D448: jal         0x8014FD70
    // 0x8013D44C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x8013D44C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8013D450: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D454: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_9;
    // 0x8013D454: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x8013D458: jal         0x8014EC78
    // 0x8013D45C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x8013D45C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8013D460: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D464: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_10;
    // 0x8013D464: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x8013D468: jal         0x80148D0C
    // 0x8013D46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x8013D46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8013D470: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D474: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_11;
    // 0x8013D474: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x8013D478: jal         0x8014E764
    // 0x8013D47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x8013D47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8013D480: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D484: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_12;
    // 0x8013D484: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x8013D488: jal         0x8013F4D0
    // 0x8013D48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x8013D48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8013D490: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D494: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_13;
    // 0x8013D494: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x8013D498: jal         0x8013ED64
    // 0x8013D49C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_14;
    // 0x8013D49C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8013D4A0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D4A4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_14;
    // 0x8013D4A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_14:
    // 0x8013D4A8: jal         0x80141EA4
    // 0x8013D4AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassCheckInterruptCommon(rdram, ctx);
        goto after_15;
    // 0x8013D4AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8013D4B0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D4B4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_15;
    // 0x8013D4B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x8013D4B8: jal         0x80142258
    // 0x8013D4BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_16;
    // 0x8013D4BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8013D4C0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D4C4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_16;
    // 0x8013D4C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_16:
    // 0x8013D4C8: jal         0x8014310C
    // 0x8013D4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatCheckInterruptCommon(rdram, ctx);
        goto after_17;
    // 0x8013D4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8013D4D0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D4D4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_17;
    // 0x8013D4D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_17:
    // 0x8013D4D8: jal         0x8013EA04
    // 0x8013D4DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonTurnCheckInterruptCommon(rdram, ctx);
        goto after_18;
    // 0x8013D4DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8013D4E0: bnel        $v0, $zero, L_8013D4FC
    if (ctx->r2 != 0) {
        // 0x8013D4E4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8013D4FC;
    }
    goto skip_18;
    // 0x8013D4E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_18:
    // 0x8013D4E8: jal         0x8013E648
    // 0x8013D4EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonWalkCheckInterruptCommon(rdram, ctx);
        goto after_19;
    // 0x8013D4EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8013D4F0: beql        $v0, $zero, L_8013D508
    if (ctx->r2 == 0) {
        // 0x8013D4F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013D508;
    }
    goto skip_19;
    // 0x8013D4F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x8013D4F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_8013D4FC:
    // 0x8013D4FC: jal         0x800EA8EC
    // 0x8013D500: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    ftParamSetTimedHitStatusInvincible(rdram, ctx);
        goto after_20;
    // 0x8013D500: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_20:
    // 0x8013D504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013D508:
    // 0x8013D508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013D50C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013D510: jr          $ra
    // 0x8013D514: nop

    return;
    // 0x8013D514: nop

;}
RECOMP_FUNC void ftBossHarauProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015946C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159474: jal         0x800D93E4
    // 0x80159478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_0;
    // 0x80159478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015947C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80159480: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80159484: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80159488: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8015948C: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x80159490: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80159494: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80159498: nop

    // 0x8015949C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801594A0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801594A4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801594A8: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x801594AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801594B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801594B4: jr          $ra
    // 0x801594B8: nop

    return;
    // 0x801594B8: nop

;}
RECOMP_FUNC void func_ovl8_80385024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385024: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80385028: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8038502C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80385030: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80385034: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80385038: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8038503C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80385040: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80385044: beq         $a0, $zero, L_80385050
    if (ctx->r4 == 0) {
        // 0x80385048: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80385050;
    }
    // 0x80385048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038504C: lw          $s0, 0x38($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X38);
L_80385050:
    // 0x80385050: jal         0x80377244
    // 0x80385054: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_0;
    // 0x80385054: nop

    after_0:
    // 0x80385058: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x8038505C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80385060: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x80385064: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x80385068: beq         $t7, $zero, L_80385128
    if (ctx->r15 == 0) {
        // 0x8038506C: nop
    
            goto L_80385128;
    }
    // 0x8038506C: nop

L_80385070:
    // 0x80385070: jal         0x8037726C
    // 0x80385074: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_ovl8_8037726C(rdram, ctx);
        goto after_1;
    // 0x80385074: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80385078: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8038507C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80385080: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x80385084: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80385088: lh          $t8, 0x50($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X50);
    // 0x8038508C: jalr        $t9
    // 0x80385090: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80385090: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    after_2:
    // 0x80385094: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x80385098: lwl         $t2, 0x0($s2)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r18, 0X0);
    // 0x8038509C: lwr         $t2, 0x3($s2)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r18, 0X3);
    // 0x803850A0: lh          $t0, 0xA0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XA0);
    // 0x803850A4: swl         $t2, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r10);
    // 0x803850A8: swr         $t2, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r10);
    // 0x803850AC: lw          $t9, 0xA4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XA4);
    // 0x803850B0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x803850B4: addu        $a0, $t0, $s1
    ctx->r4 = ADD32(ctx->r8, ctx->r17);
    // 0x803850B8: jalr        $t9
    // 0x803850BC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x803850BC: nop

    after_3:
    // 0x803850C0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x803850C4: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x803850C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x803850CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x803850D0: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x803850D4: nop

    // 0x803850D8: bc1t        L_803850FC
    if (c1cs) {
        // 0x803850DC: nop
    
            goto L_803850FC;
    }
    // 0x803850DC: nop

    // 0x803850E0: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x803850E4: sw          $s3, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r19;
    // 0x803850E8: lw          $t9, 0xF4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XF4);
    // 0x803850EC: lh          $t3, 0xF0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XF0);
    // 0x803850F0: jalr        $t9
    // 0x803850F4: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x803850F4: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    after_4:
    // 0x803850F8: sw          $zero, 0x48($s1)
    MEM_W(0X48, ctx->r17) = 0;
L_803850FC:
    // 0x803850FC: jal         0x8000B1E8
    // 0x80385100: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_5;
    // 0x80385100: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80385104: beq         $s1, $zero, L_80385110
    if (ctx->r17 == 0) {
        // 0x80385108: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80385110;
    }
    // 0x80385108: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8038510C: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_80385110:
    // 0x80385110: jal         0x80377244
    // 0x80385114: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_6;
    // 0x80385114: nop

    after_6:
    // 0x80385118: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x8038511C: and         $t5, $v0, $t4
    ctx->r13 = ctx->r2 & ctx->r12;
    // 0x80385120: bne         $t5, $zero, L_80385070
    if (ctx->r13 != 0) {
        // 0x80385124: nop
    
            goto L_80385070;
    }
    // 0x80385124: nop

L_80385128:
    // 0x80385128: beq         $s1, $zero, L_80385134
    if (ctx->r17 == 0) {
        // 0x8038512C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80385134;
    }
    // 0x8038512C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80385130: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_80385134:
    // 0x80385134: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x80385138: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8038513C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80385140: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80385144: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80385148: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x8038514C: jalr        $t9
    // 0x80385150: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80385150: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_7:
    // 0x80385154: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80385158: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8038515C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80385160: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80385164: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80385168: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8038516C: jr          $ra
    // 0x80385170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80385170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80385174: nop

    // 0x80385178: nop

    // 0x8038517C: nop

;}
RECOMP_FUNC void mpProcessCheckTestFloorCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB474: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800DB478: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DB47C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DB480: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800DB484: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800DB488: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x800DB48C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800DB490: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800DB494: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800DB498: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DB49C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DB4A0: lhu         $t6, 0x1398($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1398);
    // 0x800DB4A4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DB4A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DB4AC: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DB4B0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DB4B4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800DB4B8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DB4BC: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DB4C0: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x800DB4C4: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800DB4C8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800DB4CC: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DB4D0: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x800DB4D4: addiu       $t8, $sp, 0x38
    ctx->r24 = ADD32(ctx->r29, 0X38);
    // 0x800DB4D8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DB4DC: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x800DB4E0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800DB4E4: lhu         $t7, 0x5C($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X5C);
    // 0x800DB4E8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DB4EC: beql        $t6, $t7, L_800DB51C
    if (ctx->r14 == ctx->r15) {
        // 0x800DB4F0: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_800DB51C;
    }
    goto skip_0;
    // 0x800DB4F0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    skip_0:
    // 0x800DB4F4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DB4F8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DB4FC: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DB500: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DB504: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800DB508: jal         0x800F521C
    // 0x800DB50C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_0;
    // 0x800DB50C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x800DB510: b           L_800DB524
    // 0x800DB514: nop

        goto L_800DB524;
    // 0x800DB514: nop

    // 0x800DB518: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_800DB51C:
    // 0x800DB51C: jal         0x800F4BD8
    // 0x800DB520: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800DB520: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
L_800DB524:
    // 0x800DB524: beq         $v0, $zero, L_800DB578
    if (ctx->r2 == 0) {
        // 0x800DB528: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_800DB578;
    }
    // 0x800DB528: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800DB52C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800DB530: beql        $t2, $t3, L_800DB57C
    if (ctx->r10 == ctx->r11) {
        // 0x800DB534: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DB57C;
    }
    goto skip_1;
    // 0x800DB534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800DB538: lhu         $t4, 0x56($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X56);
    // 0x800DB53C: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x800DB540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DB544: ori         $t5, $t4, 0x800
    ctx->r13 = ctx->r12 | 0X800;
    // 0x800DB548: sh          $t5, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r13;
    // 0x800DB54C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800DB550: sw          $t6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r14;
    // 0x800DB554: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800DB558: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
    // 0x800DB55C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800DB560: sw          $t0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r8;
    // 0x800DB564: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800DB568: sw          $t9, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r25;
    // 0x800DB56C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x800DB570: b           L_800DB57C
    // 0x800DB574: sw          $t0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r8;
        goto L_800DB57C;
    // 0x800DB574: sw          $t0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r8;
L_800DB578:
    // 0x800DB578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DB57C:
    // 0x800DB57C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DB580: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DB584: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800DB588: jr          $ra
    // 0x800DB58C: nop

    return;
    // 0x800DB58C: nop

;}
RECOMP_FUNC void mnCharactersGetFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131B5C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B60: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80131B64: addiu       $t6, $t6, 0x6250
    ctx->r14 = ADD32(ctx->r14, 0X6250);
    // 0x80131B68: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80131B6C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131B70:
    // 0x80131B70: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131B74: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131B78: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131B7C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131B80: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131B84: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131B88: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131B8C: bne         $t6, $t0, L_80131B70
    if (ctx->r14 != ctx->r8) {
        // 0x80131B90: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131B70;
    }
    // 0x80131B90: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131B94: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80131B98: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80131B9C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80131BA0: jr          $ra
    // 0x80131BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayers1PGameSetPortraitWallpaperPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325D8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801325DC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801325E0: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x801325E4: addiu       $t6, $t6, -0x7800
    ctx->r14 = ADD32(ctx->r14, -0X7800);
    // 0x801325E8: addiu       $t0, $t6, 0x60
    ctx->r8 = ADD32(ctx->r14, 0X60);
    // 0x801325EC: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_801325F0:
    // 0x801325F0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801325F4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801325F8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801325FC: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132600: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132604: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132608: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013260C: bne         $t6, $t0, L_801325F0
    if (ctx->r14 != ctx->r8) {
        // 0x80132610: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801325F0;
    }
    // 0x80132610: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132614: sll         $t1, $a1, 3
    ctx->r9 = S32(ctx->r5 << 3);
    // 0x80132618: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x8013261C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80132620: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80132624: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80132628: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8013262C: jr          $ra
    // 0x80132630: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80132630: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
;}

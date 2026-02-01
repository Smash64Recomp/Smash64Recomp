#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itMSBombDetachedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176E70: jal         0x80176D00
    // 0x80176E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMSBombDetachedInitVars(rdram, ctx);
        goto after_0;
    // 0x80176E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80176E78: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80176E7C: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x80176E80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80176E84: jal         0x80172EC8
    // 0x80176E88: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80176E88: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80176E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176E90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176E94: jr          $ra
    // 0x80176E98: nop

    return;
    // 0x80176E98: nop

;}
RECOMP_FUNC void ftMarioSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155FA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80155FA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155FA8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80155FAC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80155FB0: jal         0x800DEEC8
    // 0x80155FB4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80155FB4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80155FB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80155FBC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80155FC0: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80155FC4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155FC8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155FCC: jal         0x800E6F24
    // 0x80155FD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155FD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80155FD4: jal         0x800D8EB8
    // 0x80155FD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80155FD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80155FDC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80155FE0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80155FE4: addiu       $t8, $t8, 0x5E64
    ctx->r24 = ADD32(ctx->r24, 0X5E64);
    // 0x80155FE8: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80155FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155FF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80155FF4: jr          $ra
    // 0x80155FF8: nop

    return;
    // 0x80155FF8: nop

;}
RECOMP_FUNC void unref_80006B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006B28: beq         $a0, $at, L_80006B34
    if (ctx->r4 == ctx->r1) {
        // 0x80006B2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80006B34;
    }
    // 0x80006B2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80006B30: bne         $a0, $at, L_80006B3C
    if (ctx->r4 != ctx->r1) {
        // 0x80006B34: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80006B3C;
    }
L_80006B34:
    // 0x80006B34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006B38: sw          $a0, 0x6640($at)
    MEM_W(0X6640, ctx->r1) = ctx->r4;
L_80006B3C:
    // 0x80006B3C: jr          $ra
    // 0x80006B40: nop

    return;
    // 0x80006B40: nop

;}
RECOMP_FUNC void mvOpeningDonkeyMotionCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D2FC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D300: lw          $t6, -0x1E38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1E38);
    // 0x8018D304: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D308: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018D30C: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8018D310: bne         $at, $zero, L_8018D3EC
    if (ctx->r1 != 0) {
        // 0x8018D314: addiu       $v1, $v1, -0x1DF8
        ctx->r3 = ADD32(ctx->r3, -0X1DF8);
            goto L_8018D3EC;
    }
    // 0x8018D314: addiu       $v1, $v1, -0x1DF8
    ctx->r3 = ADD32(ctx->r3, -0X1DF8);
    // 0x8018D318: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D31C: addiu       $a0, $a0, -0x1E18
    ctx->r4 = ADD32(ctx->r4, -0X1E18);
    // 0x8018D320: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018D324: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D328: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018D32C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D330: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D334: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018D338: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D33C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D340: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018D344: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D348: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018D34C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D350: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D354: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D358: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D35C: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018D360: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8018D364: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018D368: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018D36C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D370: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D374: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D378: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018D37C: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x8018D380: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018D384: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8018D388: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D38C: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D390: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D394: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8018D398: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x8018D39C: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018D3A0: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8018D3A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3A8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3AC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3B0: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8018D3B4: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3B8: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8018D3BC: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8018D3C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3C4: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3CC: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8018D3D0: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3D4: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8018D3D8: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8018D3DC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3E0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3E4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3E8: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_8018D3EC:
    // 0x8018D3EC: jr          $ra
    // 0x8018D3F0: nop

    return;
    // 0x8018D3F0: nop

;}
RECOMP_FUNC void mnCharactersChangeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013369C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801336A0: lw          $a1, 0x65FC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X65FC);
    // 0x801336A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801336A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801336AC: beq         $a1, $zero, L_801336C4
    if (ctx->r5 == 0) {
        // 0x801336B0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801336C4;
    }
    // 0x801336B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801336B4: jal         0x80009A84
    // 0x801336B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801336B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801336BC: jal         0x80131F28
    // 0x801336C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnCharactersMakeEmblem(rdram, ctx);
        goto after_1;
    // 0x801336C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_801336C4:
    // 0x801336C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801336C8: lw          $a0, 0x6600($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6600);
    // 0x801336CC: beq         $a0, $zero, L_801336E4
    if (ctx->r4 == 0) {
        // 0x801336D0: nop
    
            goto L_801336E4;
    }
    // 0x801336D0: nop

    // 0x801336D4: jal         0x80009A84
    // 0x801336D8: nop

    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x801336D8: nop

    after_2:
    // 0x801336DC: jal         0x801320E4
    // 0x801336E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnCharactersMakeName(rdram, ctx);
        goto after_3;
    // 0x801336E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_801336E4:
    // 0x801336E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801336E8: lw          $a0, 0x6604($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6604);
    // 0x801336EC: beq         $a0, $zero, L_80133704
    if (ctx->r4 == 0) {
        // 0x801336F0: nop
    
            goto L_80133704;
    }
    // 0x801336F0: nop

    // 0x801336F4: jal         0x80009A84
    // 0x801336F8: nop

    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x801336F8: nop

    after_4:
    // 0x801336FC: jal         0x80131C00
    // 0x80133700: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnCharactersMakeStory(rdram, ctx);
        goto after_5;
    // 0x80133700: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
L_80133704:
    // 0x80133704: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133708: lw          $a0, 0x6608($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6608);
    // 0x8013370C: beq         $a0, $zero, L_80133724
    if (ctx->r4 == 0) {
        // 0x80133710: nop
    
            goto L_80133724;
    }
    // 0x80133710: nop

    // 0x80133714: jal         0x80009A84
    // 0x80133718: nop

    gcEjectGObj(rdram, ctx);
        goto after_6;
    // 0x80133718: nop

    after_6:
    // 0x8013371C: jal         0x8013239C
    // 0x80133720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnCharactersMakeWorks(rdram, ctx);
        goto after_7;
    // 0x80133720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_7:
L_80133724:
    // 0x80133724: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133728: lw          $a0, 0x660C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X660C);
    // 0x8013372C: beql        $a0, $zero, L_80133748
    if (ctx->r4 == 0) {
        // 0x80133730: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133748;
    }
    goto skip_0;
    // 0x80133730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80133734: jal         0x800D78E8
    // 0x80133738: nop

    ftManagerDestroyFighter(rdram, ctx);
        goto after_8;
    // 0x80133738: nop

    after_8:
    // 0x8013373C: jal         0x80132C40
    // 0x80133740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnCharactersMakeFighter(rdram, ctx);
        goto after_9;
    // 0x80133740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_9:
    // 0x80133744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133748:
    // 0x80133748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013374C: jr          $ra
    // 0x80133750: nop

    return;
    // 0x80133750: nop

;}
RECOMP_FUNC void ftParamMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EABDC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800EABE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EABE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EABE8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800EABEC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800EABF0: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x800EABF4: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x800EABF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800EABFC: bne         $a1, $at, L_800EACC8
    if (ctx->r5 != ctx->r1) {
        // 0x800EAC00: sw          $t7, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r15;
            goto L_800EACC8;
    }
    // 0x800EAC00: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800EAC04: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x800EAC08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EAC0C: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800EAC10: beq         $v0, $at, L_800EAC64
    if (ctx->r2 == ctx->r1) {
        // 0x800EAC14: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800EAC64;
    }
    // 0x800EAC14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EAC18: beq         $v0, $at, L_800EAC44
    if (ctx->r2 == ctx->r1) {
        // 0x800EAC1C: addiu       $a3, $sp, 0x3C
        ctx->r7 = ADD32(ctx->r29, 0X3C);
            goto L_800EAC44;
    }
    // 0x800EAC1C: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800EAC20: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800EAC24: beq         $v0, $at, L_800EAC84
    if (ctx->r2 == ctx->r1) {
        // 0x800EAC28: addiu       $a3, $sp, 0x3C
        ctx->r7 = ADD32(ctx->r29, 0X3C);
            goto L_800EAC84;
    }
    // 0x800EAC28: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800EAC2C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x800EAC30: beql        $v0, $at, L_800EACA8
    if (ctx->r2 == ctx->r1) {
        // 0x800EAC34: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800EACA8;
    }
    goto skip_0;
    // 0x800EAC34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x800EAC38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EAC3C: b           L_800EACD0
    // 0x800EAC40: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
        goto L_800EACD0;
    // 0x800EAC40: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
L_800EAC44:
    // 0x800EAC44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EAC48: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800EAC4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EAC50: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800EAC54: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800EAC58: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800EAC5C: b           L_800EACD0
    // 0x800EAC60: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
        goto L_800EACD0;
    // 0x800EAC60: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_800EAC64:
    // 0x800EAC64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EAC68: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800EAC6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800EAC70: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800EAC74: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800EAC78: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800EAC7C: b           L_800EACD0
    // 0x800EAC80: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
        goto L_800EACD0;
    // 0x800EAC80: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
L_800EAC84:
    // 0x800EAC84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EAC88: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800EAC8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EAC90: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800EAC94: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800EAC98: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800EAC9C: b           L_800EACD0
    // 0x800EACA0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
        goto L_800EACD0;
    // 0x800EACA0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800EACA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800EACA8:
    // 0x800EACA8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800EACAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EACB0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800EACB4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800EACB8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800EACBC: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800EACC0: b           L_800EACD0
    // 0x800EACC4: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
        goto L_800EACD0;
    // 0x800EACC4: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
L_800EACC8:
    // 0x800EACC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EACCC: nop

L_800EACD0:
    // 0x800EACD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800EACD4: beql        $a2, $at, L_800EAE90
    if (ctx->r6 == ctx->r1) {
        // 0x800EACD8: lw          $t8, 0x5C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X5C);
            goto L_800EAE90;
    }
    goto skip_1;
    // 0x800EACD8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x800EACDC: beql        $a3, $zero, L_800EAD08
    if (ctx->r7 == 0) {
        // 0x800EACE0: swc1        $f0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
            goto L_800EAD08;
    }
    goto skip_2;
    // 0x800EACE0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    skip_2:
    // 0x800EACE4: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800EACE8: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800EACEC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800EACF0: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x800EACF4: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x800EACF8: lw          $t1, 0x8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X8);
    // 0x800EACFC: b           L_800EAD14
    // 0x800EAD00: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
        goto L_800EAD14;
    // 0x800EAD00: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x800EAD04: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_800EAD08:
    // 0x800EAD08: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800EAD0C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800EAD10: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
L_800EAD14:
    // 0x800EAD14: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800EAD18: beql        $v0, $zero, L_800EAE20
    if (ctx->r2 == 0) {
        // 0x800EAD1C: lw          $t2, 0x70($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X70);
            goto L_800EAE20;
    }
    goto skip_3;
    // 0x800EAD1C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    skip_3:
    // 0x800EAD20: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EAD24: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EAD28: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800EAD2C: nop

    // 0x800EAD30: bc1tl       L_800EAD78
    if (c1cs) {
        // 0x800EAD34: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800EAD78;
    }
    goto skip_4;
    // 0x800EAD34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_4:
    // 0x800EAD38: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800EAD3C: jal         0x80018948
    // 0x800EAD40: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x800EAD40: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EAD44: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800EAD48: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EAD4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EAD50: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EAD54: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EAD58: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800EAD5C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800EAD60: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800EAD64: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800EAD68: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EAD6C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800EAD70: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x800EAD74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800EAD78:
    // 0x800EAD78: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EAD7C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800EAD80: nop

    // 0x800EAD84: bc1tl       L_800EADCC
    if (c1cs) {
        // 0x800EAD88: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_800EADCC;
    }
    goto skip_5;
    // 0x800EAD88: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_5:
    // 0x800EAD8C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800EAD90: jal         0x80018948
    // 0x800EAD94: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x800EAD94: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_1:
    // 0x800EAD98: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800EAD9C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EADA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EADA4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EADA8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800EADAC: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800EADB0: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800EADB4: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800EADB8: add.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800EADBC: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800EADC0: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800EADC4: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800EADC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_800EADCC:
    // 0x800EADCC: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EADD0: c.eq.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl == ctx->f16.fl;
    // 0x800EADD4: nop

    // 0x800EADD8: bc1tl       L_800EAE20
    if (c1cs) {
        // 0x800EADDC: lw          $t2, 0x70($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X70);
            goto L_800EAE20;
    }
    goto skip_6;
    // 0x800EADDC: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    skip_6:
    // 0x800EADE0: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800EADE4: jal         0x80018948
    // 0x800EADE8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x800EADE8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_2:
    // 0x800EADEC: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800EADF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EADF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EADF8: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EADFC: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EAE00: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800EAE04: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800EAE08: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800EAE0C: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800EAE10: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800EAE14: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800EAE18: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x800EAE1C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
L_800EAE20:
    // 0x800EAE20: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800EAE24: beql        $t2, $zero, L_800EAE70
    if (ctx->r10 == 0) {
        // 0x800EAE28: lw          $t5, 0x54($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X54);
            goto L_800EAE70;
    }
    goto skip_7;
    // 0x800EAE28: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    skip_7:
    // 0x800EAE2C: lw          $t4, 0x9C8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X9C8);
    // 0x800EAE30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EAE34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800EAE38: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800EAE3C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EAE40: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800EAE44: div.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800EAE48: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EAE4C: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EAE50: nop

    // 0x800EAE54: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800EAE58: nop

    // 0x800EAE5C: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800EAE60: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x800EAE64: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800EAE68: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800EAE6C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
L_800EAE70:
    // 0x800EAE70: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800EAE74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EAE78: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800EAE7C: lw          $a0, 0x8E8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8E8);
    // 0x800EAE80: jal         0x800EDF24
    // 0x800EAE84: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_3;
    // 0x800EAE84: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_3:
    // 0x800EAE88: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800EAE8C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
L_800EAE90:
    // 0x800EAE90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EAE94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800EAE98: sltiu       $at, $t8, 0x5C
    ctx->r1 = ctx->r24 < 0X5C ? 1 : 0;
    // 0x800EAE9C: beq         $at, $zero, L_800EB388
    if (ctx->r1 == 0) {
        // 0x800EAEA0: addiu       $s0, $sp, 0x48
        ctx->r16 = ADD32(ctx->r29, 0X48);
            goto L_800EB388;
    }
    // 0x800EAEA0: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800EAEA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800EAEA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EAEAC: addu        $at, $at, $t8
    gpr jr_addend_800EAEB4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800EAEB0: lw          $t8, -0x9C($at)
    ctx->r24 = ADD32(ctx->r1, -0X9C);
    // 0x800EAEB4: jr          $t8
    // 0x800EAEB8: nop

    switch (jr_addend_800EAEB4 >> 2) {
        case 0: goto L_800EAEBC; break;
        case 1: goto L_800EB388; break;
        case 2: goto L_800EB388; break;
        case 3: goto L_800EB388; break;
        case 4: goto L_800EB388; break;
        case 5: goto L_800EB388; break;
        case 6: goto L_800EAEE8; break;
        case 7: goto L_800EAF08; break;
        case 8: goto L_800EAF24; break;
        case 9: goto L_800EB388; break;
        case 10: goto L_800EAF40; break;
        case 11: goto L_800EAF5C; break;
        case 12: goto L_800EAF74; break;
        case 13: goto L_800EAF8C; break;
        case 14: goto L_800EAFA4; break;
        case 15: goto L_800EAFC0; break;
        case 16: goto L_800EAFD4; break;
        case 17: goto L_800EAFEC; break;
        case 18: goto L_800EB050; break;
        case 19: goto L_800EB064; break;
        case 20: goto L_800EB07C; break;
        case 21: goto L_800EB094; break;
        case 22: goto L_800EB0A4; break;
        case 23: goto L_800EB108; break;
        case 24: goto L_800EB120; break;
        case 25: goto L_800EB134; break;
        case 26: goto L_800EB14C; break;
        case 27: goto L_800EB160; break;
        case 28: goto L_800EB178; break;
        case 29: goto L_800EB188; break;
        case 30: goto L_800EB198; break;
        case 31: goto L_800EB1A8; break;
        case 32: goto L_800EB1BC; break;
        case 33: goto L_800EB1E0; break;
        case 34: goto L_800EB204; break;
        case 35: goto L_800EB388; break;
        case 36: goto L_800EB388; break;
        case 37: goto L_800EB378; break;
        case 38: goto L_800EB388; break;
        case 39: goto L_800EB388; break;
        case 40: goto L_800EB268; break;
        case 41: goto L_800EB228; break;
        case 42: goto L_800EB238; break;
        case 43: goto L_800EB248; break;
        case 44: goto L_800EB258; break;
        case 45: goto L_800EB388; break;
        case 46: goto L_800EB314; break;
        case 47: goto L_800EB288; break;
        case 48: goto L_800EB388; break;
        case 49: goto L_800EB388; break;
        case 50: goto L_800EB388; break;
        case 51: goto L_800EB388; break;
        case 52: goto L_800EB388; break;
        case 53: goto L_800EB388; break;
        case 54: goto L_800EB278; break;
        case 55: goto L_800EB388; break;
        case 56: goto L_800EB388; break;
        case 57: goto L_800EB388; break;
        case 58: goto L_800EB388; break;
        case 59: goto L_800EB388; break;
        case 60: goto L_800EB388; break;
        case 61: goto L_800EB388; break;
        case 62: goto L_800EB388; break;
        case 63: goto L_800EB388; break;
        case 64: goto L_800EB388; break;
        case 65: goto L_800EB388; break;
        case 66: goto L_800EB388; break;
        case 67: goto L_800EB388; break;
        case 68: goto L_800EB388; break;
        case 69: goto L_800EB388; break;
        case 70: goto L_800EB2C4; break;
        case 71: goto L_800EB2D4; break;
        case 72: goto L_800EB388; break;
        case 73: goto L_800EB29C; break;
        case 74: goto L_800EB304; break;
        case 75: goto L_800EB388; break;
        case 76: goto L_800EB2E4; break;
        case 77: goto L_800EB2F4; break;
        case 78: goto L_800EB388; break;
        case 79: goto L_800EB388; break;
        case 80: goto L_800EB388; break;
        case 81: goto L_800EB388; break;
        case 82: goto L_800EB388; break;
        case 83: goto L_800EB388; break;
        case 84: goto L_800EB388; break;
        case 85: goto L_800EB388; break;
        case 86: goto L_800EB388; break;
        case 87: goto L_800EB350; break;
        case 88: goto L_800EB388; break;
        case 89: goto L_800EB388; break;
        case 90: goto L_800EB328; break;
        case 91: goto L_800EB33C; break;
        default: switch_error(__func__, 0x800EAEB4, 0x8012FF64);
    }
    // 0x800EAEB8: nop

L_800EAEBC:
    // 0x800EAEBC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800EAEC0: jal         0x800EAB40
    // 0x800EAEC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetEffectJointPosition(rdram, ctx);
        goto after_4;
    // 0x800EAEC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800EAEC8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800EAECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAED0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800EAED4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800EAED8: jal         0x800FDC04
    // 0x800EAEDC: lbu         $a1, 0xD($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0XD);
    efManagerDamageNormalLightMakeEffect(rdram, ctx);
        goto after_5;
    // 0x800EAEDC: lbu         $a1, 0xD($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0XD);
    after_5:
    // 0x800EAEE0: b           L_800EB388
    // 0x800EAEE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAEE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAEE8:
    // 0x800EAEE8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800EAEEC: jal         0x800EAB40
    // 0x800EAEF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetEffectJointPosition(rdram, ctx);
        goto after_6;
    // 0x800EAEF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800EAEF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAEF8: jal         0x800FE7B4
    // 0x800EAEFC: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    efManagerFlameLRMakeEffect(rdram, ctx);
        goto after_7;
    // 0x800EAEFC: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_7:
    // 0x800EAF00: b           L_800EB388
    // 0x800EAF04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAF04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAF08:
    // 0x800EAF08: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800EAF0C: jal         0x800EAB40
    // 0x800EAF10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetEffectJointPosition(rdram, ctx);
        goto after_8;
    // 0x800EAF10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800EAF14: jal         0x800FE9B4
    // 0x800EAF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerFlameRandgcMakeEffect(rdram, ctx);
        goto after_9;
    // 0x800EAF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800EAF1C: b           L_800EB388
    // 0x800EAF20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAF20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAF24:
    // 0x800EAF24: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800EAF28: jal         0x800EAB40
    // 0x800EAF2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetEffectJointPosition(rdram, ctx);
        goto after_10;
    // 0x800EAF2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800EAF30: jal         0x800FEB58
    // 0x800EAF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerFlameStaticMakeEffect(rdram, ctx);
        goto after_11;
    // 0x800EAF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800EAF38: b           L_800EB388
    // 0x800EAF3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAF3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAF40:
    // 0x800EAF40: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800EAF44: jal         0x800EAB40
    // 0x800EAF48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetEffectJointPosition(rdram, ctx);
        goto after_12;
    // 0x800EAF48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x800EAF4C: jal         0x800FEEB0
    // 0x800EAF50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerShockSmallMakeEffect(rdram, ctx);
        goto after_13;
    // 0x800EAF50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800EAF54: b           L_800EB388
    // 0x800EAF58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAF58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAF5C:
    // 0x800EAF5C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800EAF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAF64: jal         0x800FF048
    // 0x800EAF68: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_14;
    // 0x800EAF68: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_14:
    // 0x800EAF6C: b           L_800EB388
    // 0x800EAF70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAF70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAF74:
    // 0x800EAF74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAF78: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800EAF7C: jal         0x800FF048
    // 0x800EAF80: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_15;
    // 0x800EAF80: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_15:
    // 0x800EAF84: b           L_800EB388
    // 0x800EAF88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAF88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAF8C:
    // 0x800EAF8C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800EAF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAF94: jal         0x800FF3F4
    // 0x800EAF98: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    efManagerDustHeavyDoubleMakeEffect(rdram, ctx);
        goto after_16;
    // 0x800EAF98: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_16:
    // 0x800EAF9C: b           L_800EB388
    // 0x800EAFA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAFA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAFA4:
    // 0x800EAFA4: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x800EAFA8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800EAFAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAFB0: jal         0x800FF3F4
    // 0x800EAFB4: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    efManagerDustHeavyDoubleMakeEffect(rdram, ctx);
        goto after_17;
    // 0x800EAFB4: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_17:
    // 0x800EAFB8: b           L_800EB388
    // 0x800EAFBC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAFBC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAFC0:
    // 0x800EAFC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAFC4: jal         0x800FF278
    // 0x800EAFC8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    efManagerDustHeavyMakeEffect(rdram, ctx);
        goto after_18;
    // 0x800EAFC8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_18:
    // 0x800EAFCC: b           L_800EB388
    // 0x800EAFD0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAFD0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAFD4:
    // 0x800EAFD4: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800EAFD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAFDC: jal         0x800FF278
    // 0x800EAFE0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    efManagerDustHeavyMakeEffect(rdram, ctx);
        goto after_19;
    // 0x800EAFE0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_19:
    // 0x800EAFE4: b           L_800EB388
    // 0x800EAFE8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EAFE8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EAFEC:
    // 0x800EAFEC: jal         0x80018948
    // 0x800EAFF0: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_20;
    // 0x800EAFF0: nop

    after_20:
    // 0x800EAFF4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800EAFF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EAFFC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800EB000: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EB004: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800EB008: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EB00C: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800EB010: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800EB014: jal         0x80018948
    // 0x800EB018: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_21;
    // 0x800EB018: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x800EB01C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800EB020: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EB024: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800EB028: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EB02C: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800EB030: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800EB034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB038: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800EB03C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800EB040: jal         0x800FF590
    // 0x800EB044: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    efManagerDustExpandLargeMakeEffect(rdram, ctx);
        goto after_22;
    // 0x800EB044: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x800EB048: b           L_800EB388
    // 0x800EB04C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB04C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB050:
    // 0x800EB050: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800EB054: jal         0x800FF648
    // 0x800EB058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_23;
    // 0x800EB058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800EB05C: b           L_800EB388
    // 0x800EB060: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB060: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB064:
    // 0x800EB064: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800EB068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB06C: jal         0x800FF7D8
    // 0x800EB070: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    efManagerDustDashMakeEffect(rdram, ctx);
        goto after_24;
    // 0x800EB070: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_24:
    // 0x800EB074: b           L_800EB388
    // 0x800EB078: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB078: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB07C:
    // 0x800EB07C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB080: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800EB084: jal         0x800FF7D8
    // 0x800EB088: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    efManagerDustDashMakeEffect(rdram, ctx);
        goto after_25;
    // 0x800EB088: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_25:
    // 0x800EB08C: b           L_800EB388
    // 0x800EB090: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB090: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB094:
    // 0x800EB094: jal         0x800FFAB8
    // 0x800EB098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerDamageSpawnOrbsMakeEffect(rdram, ctx);
        goto after_26;
    // 0x800EB098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x800EB09C: b           L_800EB388
    // 0x800EB0A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB0A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB0A4:
    // 0x800EB0A4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800EB0A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB0AC: lw          $t1, 0x14C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14C);
    // 0x800EB0B0: bne         $t1, $zero, L_800EB0F8
    if (ctx->r9 != 0) {
        // 0x800EB0B4: nop
    
            goto L_800EB0F8;
    }
    // 0x800EB0B4: nop

    // 0x800EB0B8: lw          $v0, 0xEC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XEC);
    // 0x800EB0BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800EB0C0: beq         $v0, $at, L_800EB0F8
    if (ctx->r2 == ctx->r1) {
        // 0x800EB0C4: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_800EB0F8;
    }
    // 0x800EB0C4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800EB0C8: beq         $v0, $at, L_800EB0F8
    if (ctx->r2 == ctx->r1) {
        // 0x800EB0CC: nop
    
            goto L_800EB0F8;
    }
    // 0x800EB0CC: nop

    // 0x800EB0D0: lwc1        $f12, 0xF8($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x800EB0D4: lwc1        $f14, 0xFC($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0XFC);
    // 0x800EB0D8: jal         0x8001863C
    // 0x800EB0DC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_27;
    // 0x800EB0DC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_27:
    // 0x800EB0E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800EB0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB0E8: jal         0x800FFD58
    // 0x800EB0EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    efManagerImpactWaveMakeEffect(rdram, ctx);
        goto after_28;
    // 0x800EB0EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_28:
    // 0x800EB0F0: b           L_800EB388
    // 0x800EB0F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB0F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB0F8:
    // 0x800EB0F8: jal         0x800FFDE8
    // 0x800EB0FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    efManagerImpactAirWaveMakeEffect(rdram, ctx);
        goto after_29;
    // 0x800EB0FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_29:
    // 0x800EB100: b           L_800EB388
    // 0x800EB104: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB104: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB108:
    // 0x800EB108: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800EB10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB110: jal         0x800FFEA4
    // 0x800EB114: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    efManagerStarRodSparkMakeEffect(rdram, ctx);
        goto after_30;
    // 0x800EB114: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_30:
    // 0x800EB118: b           L_800EB388
    // 0x800EB11C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB11C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB120:
    // 0x800EB120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB124: jal         0x801001A8
    // 0x800EB128: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    efManagerDamageSpawnSparksMakeEffect(rdram, ctx);
        goto after_31;
    // 0x800EB128: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_31:
    // 0x800EB12C: b           L_800EB388
    // 0x800EB130: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB130: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB134:
    // 0x800EB134: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800EB138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB13C: jal         0x801001A8
    // 0x800EB140: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    efManagerDamageSpawnSparksMakeEffect(rdram, ctx);
        goto after_32;
    // 0x800EB140: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_32:
    // 0x800EB144: b           L_800EB388
    // 0x800EB148: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB148: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB14C:
    // 0x800EB14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB150: jal         0x801003D0
    // 0x800EB154: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    efManagerDamageSpawnMDustMakeEffect(rdram, ctx);
        goto after_33;
    // 0x800EB154: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_33:
    // 0x800EB158: b           L_800EB388
    // 0x800EB15C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB15C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB160:
    // 0x800EB160: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800EB164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB168: jal         0x801003D0
    // 0x800EB16C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    efManagerDamageSpawnMDustMakeEffect(rdram, ctx);
        goto after_34;
    // 0x800EB16C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_34:
    // 0x800EB170: b           L_800EB388
    // 0x800EB174: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB174: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB178:
    // 0x800EB178: jal         0x80100480
    // 0x800EB17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_35;
    // 0x800EB17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x800EB180: b           L_800EB388
    // 0x800EB184: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB184: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB188:
    // 0x800EB188: jal         0x801005C8
    // 0x800EB18C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_36;
    // 0x800EB18C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x800EB190: b           L_800EB388
    // 0x800EB194: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB194: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB198:
    // 0x800EB198: jal         0x80100524
    // 0x800EB19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerSparkleWhiteMultiMakeEffect(rdram, ctx);
        goto after_37;
    // 0x800EB19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x800EB1A0: b           L_800EB388
    // 0x800EB1A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB1A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB1A8:
    // 0x800EB1A8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800EB1AC: jal         0x8010066C
    // 0x800EB1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_38;
    // 0x800EB1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x800EB1B4: b           L_800EB388
    // 0x800EB1B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB1B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB1BC:
    // 0x800EB1BC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800EB1C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EB1C4: lw          $t3, 0x20($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20);
    // 0x800EB1C8: beql        $t3, $at, L_800EB38C
    if (ctx->r11 == ctx->r1) {
        // 0x800EB1CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EB38C;
    }
    goto skip_8;
    // 0x800EB1CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x800EB1D0: jal         0x801008F4
    // 0x800EB1D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_39;
    // 0x800EB1D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_39:
    // 0x800EB1D8: b           L_800EB388
    // 0x800EB1DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB1DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB1E0:
    // 0x800EB1E0: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800EB1E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EB1E8: lw          $t5, 0x20($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20);
    // 0x800EB1EC: beql        $t5, $at, L_800EB38C
    if (ctx->r13 == ctx->r1) {
        // 0x800EB1F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EB38C;
    }
    goto skip_9;
    // 0x800EB1F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x800EB1F4: jal         0x801008F4
    // 0x800EB1F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_40;
    // 0x800EB1F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_40:
    // 0x800EB1FC: b           L_800EB388
    // 0x800EB200: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB200: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB204:
    // 0x800EB204: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800EB208: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EB20C: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x800EB210: beql        $t7, $at, L_800EB38C
    if (ctx->r15 == ctx->r1) {
        // 0x800EB214: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EB38C;
    }
    goto skip_10;
    // 0x800EB214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x800EB218: jal         0x801008F4
    // 0x800EB21C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_41;
    // 0x800EB21C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_41:
    // 0x800EB220: b           L_800EB388
    // 0x800EB224: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB224: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB228:
    // 0x800EB228: jal         0x80101630
    // 0x800EB22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerPsionicMakeEffect(rdram, ctx);
        goto after_42;
    // 0x800EB22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x800EB230: b           L_800EB388
    // 0x800EB234: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB234: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB238:
    // 0x800EB238: jal         0x80101688
    // 0x800EB23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerFlashSmallMakeEffect(rdram, ctx);
        goto after_43;
    // 0x800EB23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x800EB240: b           L_800EB388
    // 0x800EB244: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB244: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB248:
    // 0x800EB248: jal         0x801016E0
    // 0x800EB24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerFlashMiddleMakeEffect(rdram, ctx);
        goto after_44;
    // 0x800EB24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x800EB250: b           L_800EB388
    // 0x800EB254: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB254: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB258:
    // 0x800EB258: jal         0x80101738
    // 0x800EB25C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerFlashLargeMakeEffect(rdram, ctx);
        goto after_45;
    // 0x800EB25C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x800EB260: b           L_800EB388
    // 0x800EB264: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB264: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB268:
    // 0x800EB268: jal         0x801015D4
    // 0x800EB26C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerFuraSparkleMakeEffect(rdram, ctx);
        goto after_46;
    // 0x800EB26C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x800EB270: b           L_800EB388
    // 0x800EB274: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB274: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB278:
    // 0x800EB278: jal         0x80102018
    // 0x800EB27C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerKirbyStarMakeEffect(rdram, ctx);
        goto after_47;
    // 0x800EB27C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x800EB280: b           L_800EB388
    // 0x800EB284: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB284: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB288:
    // 0x800EB288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB28C: jal         0x8010183C
    // 0x800EB290: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_ovl2_8010183C(rdram, ctx);
        goto after_48;
    // 0x800EB290: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_48:
    // 0x800EB294: b           L_800EB388
    // 0x800EB298: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB298: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB29C:
    // 0x800EB29C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x800EB2A0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x800EB2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB2A8: jal         0x8010066C
    // 0x800EB2AC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_49;
    // 0x800EB2AC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_49:
    // 0x800EB2B0: beq         $v0, $zero, L_800EB388
    if (ctx->r2 == 0) {
        // 0x800EB2B4: lw          $v1, 0x38($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X38);
            goto L_800EB388;
    }
    // 0x800EB2B4: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800EB2B8: addiu       $t8, $zero, 0xC0
    ctx->r24 = ADD32(0, 0XC0);
    // 0x800EB2BC: b           L_800EB388
    // 0x800EB2C0: sb          $t8, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r24;
        goto L_800EB388;
    // 0x800EB2C0: sb          $t8, 0x4B($v0)
    MEM_B(0X4B, ctx->r2) = ctx->r24;
L_800EB2C4:
    // 0x800EB2C4: jal         0x80101408
    // 0x800EB2C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerThunderAmpMakeEffect(rdram, ctx);
        goto after_50;
    // 0x800EB2C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x800EB2CC: b           L_800EB388
    // 0x800EB2D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB2D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB2D4:
    // 0x800EB2D4: jal         0x801014A8
    // 0x800EB2D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerRippleMakeEffect(rdram, ctx);
        goto after_51;
    // 0x800EB2D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x800EB2DC: b           L_800EB388
    // 0x800EB2E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB2E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB2E4:
    // 0x800EB2E4: jal         0x801031E0
    // 0x800EB2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl2_801031E0(rdram, ctx);
        goto after_52;
    // 0x800EB2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x800EB2EC: b           L_800EB388
    // 0x800EB2F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB2F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB2F4:
    // 0x800EB2F4: jal         0x80103280
    // 0x800EB2F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl2_80103280(rdram, ctx);
        goto after_53;
    // 0x800EB2F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x800EB2FC: b           L_800EB388
    // 0x800EB300: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB300: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB304:
    // 0x800EB304: jal         0x80102E90
    // 0x800EB308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerHealSparklesMakeEffect(rdram, ctx);
        goto after_54;
    // 0x800EB308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x800EB30C: b           L_800EB388
    // 0x800EB310: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EB388;
    // 0x800EB310: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800EB314:
    // 0x800EB314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB318: jal         0x801791F4
    // 0x800EB31C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    itBoxContainerSmashMakeEffect(rdram, ctx);
        goto after_55;
    // 0x800EB31C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_55:
    // 0x800EB320: b           L_800EB388
    // 0x800EB324: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
        goto L_800EB388;
    // 0x800EB324: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_800EB328:
    // 0x800EB328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB32C: jal         0x801039D4
    // 0x800EB330: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    efManagerMusicNoteMakeEffect(rdram, ctx);
        goto after_56;
    // 0x800EB330: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_56:
    // 0x800EB334: b           L_800EB388
    // 0x800EB338: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
        goto L_800EB388;
    // 0x800EB338: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_800EB33C:
    // 0x800EB33C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EB340: jal         0x801041A0
    // 0x800EB344: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_57;
    // 0x800EB344: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_57:
    // 0x800EB348: b           L_800EB388
    // 0x800EB34C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
        goto L_800EB388;
    // 0x800EB34C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_800EB350:
    // 0x800EB350: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800EB354: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800EB358: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800EB35C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x800EB360: bnel        $t1, $at, L_800EB38C
    if (ctx->r9 != ctx->r1) {
        // 0x800EB364: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EB38C;
    }
    goto skip_11;
    // 0x800EB364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x800EB368: jal         0x80103150
    // 0x800EB36C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    efManagerYoshiEggEscapeMakeEffect(rdram, ctx);
        goto after_58;
    // 0x800EB36C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_58:
    // 0x800EB370: b           L_800EB388
    // 0x800EB374: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
        goto L_800EB388;
    // 0x800EB374: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_800EB378:
    // 0x800EB378: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800EB37C: jal         0x80100DEC
    // 0x800EB380: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    efManagerFireSparkMakeEffect(rdram, ctx);
        goto after_59;
    // 0x800EB380: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_59:
    // 0x800EB384: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_800EB388:
    // 0x800EB388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EB38C:
    // 0x800EB38C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EB390: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800EB394: jr          $ra
    // 0x800EB398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800EB398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void syVideoSetResHeight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006E80: sw          $a0, 0x667C($at)
    MEM_W(0X667C, ctx->r1) = ctx->r4;
    // 0x80006E84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006E88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80006E8C: jr          $ra
    // 0x80006E90: sw          $t6, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = ctx->r14;
    return;
    // 0x80006E90: sw          $t6, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void ftFoxSpecialLwUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CBA4: lw          $v0, 0x184($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X184);
    // 0x8015CBA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8015CBAC: beq         $a2, $v0, L_8015CBCC
    if (ctx->r6 == ctx->r2) {
        // 0x8015CBB0: nop
    
            goto L_8015CBCC;
    }
    // 0x8015CBB0: nop

    // 0x8015CBB4: lw          $v1, 0xB24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB24);
    // 0x8015CBB8: beql        $v1, $zero, L_8015CBCC
    if (ctx->r3 == 0) {
        // 0x8015CBBC: sw          $a2, 0x184($a0)
        MEM_W(0X184, ctx->r4) = ctx->r6;
            goto L_8015CBCC;
    }
    goto skip_0;
    // 0x8015CBBC: sw          $a2, 0x184($a0)
    MEM_W(0X184, ctx->r4) = ctx->r6;
    skip_0:
    // 0x8015CBC0: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x8015CBC4: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x8015CBC8: sw          $a2, 0x184($a0)
    MEM_W(0X184, ctx->r4) = ctx->r6;
L_8015CBCC:
    // 0x8015CBCC: jr          $ra
    // 0x8015CBD0: nop

    return;
    // 0x8015CBD0: nop

;}
RECOMP_FUNC void itMainGetDamageOutput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801727F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801727F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801727FC: lw          $t6, 0x2CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2CC);
    // 0x80172800: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80172804: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80172808: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x8017280C: bgezl       $t8, L_8017285C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80172810: lw          $v1, 0x110($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X110);
            goto L_8017285C;
    }
    goto skip_0;
    // 0x80172810: lw          $v1, 0x110($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X110);
    skip_0:
    // 0x80172814: jal         0x80018F7C
    // 0x80172818: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    syVectorMag3D(rdram, ctx);
        goto after_0;
    // 0x80172818: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8017281C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80172820: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172824: lwc1        $f8, -0x336C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X336C);
    // 0x80172828: lw          $t9, 0x110($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X110);
    // 0x8017282C: lwc1        $f18, 0x114($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X114);
    // 0x80172830: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80172834: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80172838: nop

    // 0x8017283C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80172840: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80172844: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80172848: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8017284C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80172850: b           L_80172860
    // 0x80172854: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
        goto L_80172860;
    // 0x80172854: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80172858: lw          $v1, 0x110($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X110);
L_8017285C:
    // 0x8017285C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
L_80172860:
    // 0x80172860: lwc1        $f16, 0x118($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X118);
    // 0x80172864: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172868: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017286C: lwc1        $f4, -0x3368($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3368);
    // 0x80172870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80172874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80172878: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017287C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80172880: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80172884: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80172888: jr          $ra
    // 0x8017288C: nop

    return;
    // 0x8017288C: nop

;}
RECOMP_FUNC void __setInstChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DD4C: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8002DD50: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8002DD54: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8002DD58: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002DD5C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8002DD60: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x8002DD64: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x8002DD68: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x8002DD6C: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x8002DD70: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8002DD74: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x8002DD78: lw          $t2, 0x68($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X68);
    // 0x8002DD7C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8002DD80: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x8002DD84: lw          $t5, 0x68($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X68);
    // 0x8002DD88: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x8002DD8C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8002DD90: sb          $t4, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r12;
    // 0x8002DD94: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x8002DD98: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x8002DD9C: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x8002DDA0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x8002DDA4: lw          $t2, 0x68($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X68);
    // 0x8002DDA8: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x8002DDAC: addu        $t1, $t2, $v0
    ctx->r9 = ADD32(ctx->r10, ctx->r2);
    // 0x8002DDB0: jr          $ra
    // 0x8002DDB4: sb          $t0, 0x11($t1)
    MEM_B(0X11, ctx->r9) = ctx->r8;
    return;
    // 0x8002DDB4: sb          $t0, 0x11($t1)
    MEM_B(0X11, ctx->r9) = ctx->r8;
;}
RECOMP_FUNC void ftFoxSpecialHiDecideSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C4DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8015C4E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015C4E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015C4E8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8015C4EC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015C4F0: lb          $v1, 0x1C2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1C2);
    // 0x8015C4F4: bgez        $v1, L_8015C504
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8015C4F8: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_8015C504;
    }
    // 0x8015C4F8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8015C4FC: b           L_8015C504
    // 0x8015C500: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
        goto L_8015C504;
    // 0x8015C500: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
L_8015C504:
    // 0x8015C504: lb          $v0, 0x1C3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C3);
    // 0x8015C508: bgez        $v0, L_8015C518
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8015C50C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8015C518;
    }
    // 0x8015C50C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8015C510: b           L_8015C518
    // 0x8015C514: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
        goto L_8015C518;
    // 0x8015C514: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_8015C518:
    // 0x8015C518: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x8015C51C: slti        $at, $t7, 0x2D
    ctx->r1 = SIGNED(ctx->r15) < 0X2D ? 1 : 0;
    // 0x8015C520: bne         $at, $zero, L_8015C5E8
    if (ctx->r1 != 0) {
        // 0x8015C524: nop
    
            goto L_8015C5E8;
    }
    // 0x8015C524: nop

    // 0x8015C528: lw          $t8, 0xF4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XF4);
    // 0x8015C52C: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x8015C530: bne         $t9, $zero, L_8015C5E8
    if (ctx->r25 != 0) {
        // 0x8015C534: nop
    
            goto L_8015C5E8;
    }
    // 0x8015C534: nop

    // 0x8015C538: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8015C53C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8015C540: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8015C544: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015C548: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8015C54C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8015C550: lb          $t0, 0x1C3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1C3);
    // 0x8015C554: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x8015C558: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8015C55C: nop

    // 0x8015C560: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8015C564: jal         0x800191FC
    // 0x8015C568: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_0;
    // 0x8015C568: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8015C56C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C570: lwc1        $f18, -0x376C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X376C);
    // 0x8015C574: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8015C578: nop

    // 0x8015C57C: bc1t        L_8015C5E8
    if (c1cs) {
        // 0x8015C580: nop
    
            goto L_8015C5E8;
    }
    // 0x8015C580: nop

    // 0x8015C584: jal         0x800E8044
    // 0x8015C588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetStickLR(rdram, ctx);
        goto after_1;
    // 0x8015C588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8015C58C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8015C590: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8015C594: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8015C598: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x8015C59C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015C5A0: jal         0x800E6F24
    // 0x8015C5A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015C5A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8015C5A8: jal         0x8015C4C8
    // 0x8015C5AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialHiInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8015C5AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8015C5B0: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x8015C5B4: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8015C5B8: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x8015C5BC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8015C5C0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8015C5C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015C5C8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8015C5CC: lwc1        $f14, 0xFC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8015C5D0: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x8015C5D4: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8015C5D8: jal         0x8001863C
    // 0x8015C5DC: nop

    syUtilsArcTan2(rdram, ctx);
        goto after_4;
    // 0x8015C5DC: nop

    after_4:
    // 0x8015C5E0: b           L_8015C5F8
    // 0x8015C5E4: swc1        $f0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f0.u32l;
        goto L_8015C5F8;
    // 0x8015C5E4: swc1        $f0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f0.u32l;
L_8015C5E8:
    // 0x8015C5E8: jal         0x800DEEC8
    // 0x8015C5EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_5;
    // 0x8015C5EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8015C5F0: jal         0x8015C60C
    // 0x8015C5F4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    ftFoxSpecialAirHiSetStatusFromGround(rdram, ctx);
        goto after_6;
    // 0x8015C5F4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_6:
L_8015C5F8:
    // 0x8015C5F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015C5FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015C600: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8015C604: jr          $ra
    // 0x8015C608: nop

    return;
    // 0x8015C608: nop

;}
RECOMP_FUNC void grInishiePowerBlockUpdateMake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109888: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010988C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80109890: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80109894: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x80109898: lhu         $t6, 0x44($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X44);
    // 0x8010989C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801098A0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801098A4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801098A8: bne         $t8, $zero, L_80109918
    if (ctx->r24 != 0) {
        // 0x801098AC: sh          $t7, 0x44($s0)
        MEM_H(0X44, ctx->r16) = ctx->r15;
            goto L_80109918;
    }
    // 0x801098AC: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x801098B0: jal         0x80018994
    // 0x801098B4: lbu         $a0, 0x46($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X46);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x801098B4: lbu         $a0, 0x46($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X46);
    after_0:
    // 0x801098B8: lw          $t9, 0x48($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X48);
    // 0x801098BC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x801098C0: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x801098C4: jal         0x800FC894
    // 0x801098C8: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_1;
    // 0x801098C8: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_1:
    // 0x801098CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801098D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801098D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801098D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801098DC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x801098E0: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x801098E4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x801098E8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801098EC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801098F0: jal         0x8016EA78
    // 0x801098F4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_2;
    // 0x801098F4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x801098F8: beq         $v0, $zero, L_80109910
    if (ctx->r2 == 0) {
        // 0x801098FC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80109910;
    }
    // 0x801098FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109900: sw          $v0, 0x142C($at)
    MEM_W(0X142C, ctx->r1) = ctx->r2;
    // 0x80109904: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80109908: b           L_80109918
    // 0x8010990C: sb          $t2, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r10;
        goto L_80109918;
    // 0x8010990C: sb          $t2, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r10;
L_80109910:
    // 0x80109910: jal         0x8010986C
    // 0x80109914: nop

    grInishiePowerBlockSetWait(rdram, ctx);
        goto after_3;
    // 0x80109914: nop

    after_3:
L_80109918:
    // 0x80109918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010991C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80109920: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80109924: jr          $ra
    // 0x80109928: nop

    return;
    // 0x80109928: nop

;}
RECOMP_FUNC void grYamabukiGateUpdateYakumonoPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B10C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B110: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010B114: addiu       $a1, $a1, 0x1400
    ctx->r5 = ADD32(ctx->r5, 0X1400);
    // 0x8010B118: jal         0x800FC4A8
    // 0x8010B11C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mpCollisionSetYakumonoPosID(rdram, ctx);
        goto after_0;
    // 0x8010B11C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8010B120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B128: jr          $ra
    // 0x8010B12C: nop

    return;
    // 0x8010B12C: nop

;}
RECOMP_FUNC void grInishieScaleUpdateStep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109220: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109224: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109228: lhu         $t6, 0x30($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X30);
    // 0x8010922C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109234: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80109238: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8010923C: bne         $t8, $zero, L_8010928C
    if (ctx->r24 != 0) {
        // 0x80109240: sh          $t7, 0x30($v0)
        MEM_H(0X30, ctx->r2) = ctx->r15;
            goto L_8010928C;
    }
    // 0x80109240: sh          $t7, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r15;
    // 0x80109244: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80109248: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x8010924C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80109250: addiu       $v1, $v1, 0x734
    ctx->r3 = ADD32(ctx->r3, 0X734);
    // 0x80109254: sb          $t9, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r25;
    // 0x80109258: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8010925C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80109260: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80109264: jal         0x8000BD1C
    // 0x80109268: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x80109268: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    after_0:
    // 0x8010926C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109270: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109274: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80109278: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8010927C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80109280: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80109284: jal         0x8000BD1C
    // 0x80109288: addu        $a1, $v1, $t1
    ctx->r5 = ADD32(ctx->r3, ctx->r9);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x80109288: addu        $a1, $v1, $t1
    ctx->r5 = ADD32(ctx->r3, ctx->r9);
    after_1:
L_8010928C:
    // 0x8010928C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80109294: jr          $ra
    // 0x80109298: nop

    return;
    // 0x80109298: nop

;}
RECOMP_FUNC void itTaruBombCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184E04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80184E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184E0C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80184E10: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80184E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80184E18: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80184E1C: bne         $at, $zero, L_80184E34
    if (ctx->r1 != 0) {
        // 0x80184E20: nop
    
            goto L_80184E34;
    }
    // 0x80184E20: nop

    // 0x80184E24: jal         0x80184DC4
    // 0x80184E28: nop

    itTaruBombCommonProcHit(rdram, ctx);
        goto after_0;
    // 0x80184E28: nop

    after_0:
    // 0x80184E2C: b           L_80184E38
    // 0x80184E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80184E38;
    // 0x80184E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80184E34:
    // 0x80184E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80184E38:
    // 0x80184E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80184E3C: jr          $ra
    // 0x80184E40: nop

    return;
    // 0x80184E40: nop

;}
RECOMP_FUNC void itHarisenFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801751C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801751C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801751C8: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x801751CC: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801751D0: addiu       $a3, $a3, 0x51F4
    ctx->r7 = ADD32(ctx->r7, 0X51F4);
    // 0x801751D4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801751D8: jal         0x80173B24
    // 0x801751DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801751DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x801751E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801751E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801751E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801751EC: jr          $ra
    // 0x801751F0: nop

    return;
    // 0x801751F0: nop

;}
RECOMP_FUNC void func_ovl8_80387AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387AF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80387AFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80387B00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80387B04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80387B08: beq         $a0, $zero, L_80387BBC
    if (ctx->r4 == 0) {
        // 0x80387B0C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80387BBC;
    }
    // 0x80387B0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80387B10: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80387B14: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80387B18: addiu       $t6, $t6, -0x1520
    ctx->r14 = ADD32(ctx->r14, -0X1520);
    // 0x80387B1C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80387B20: addiu       $t7, $t7, -0x1440
    ctx->r15 = ADD32(ctx->r15, -0X1440);
    // 0x80387B24: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80387B28: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80387B2C: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80387B30: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80387B34: addiu       $t9, $t9, -0x12E8
    ctx->r25 = ADD32(ctx->r25, -0X12E8);
    // 0x80387B38: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80387B3C: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80387B40: addiu       $at, $zero, -0xB8
    ctx->r1 = ADD32(0, -0XB8);
    // 0x80387B44: addiu       $t2, $t2, -0x1258
    ctx->r10 = ADD32(ctx->r10, -0X1258);
    // 0x80387B48: addiu       $t1, $t1, -0x12C0
    ctx->r9 = ADD32(ctx->r9, -0X12C0);
    // 0x80387B4C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80387B50: sw          $t2, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->r10;
    // 0x80387B54: beq         $a0, $at, L_80387B74
    if (ctx->r4 == ctx->r1) {
        // 0x80387B58: sw          $t1, 0x4C($a0)
        MEM_W(0X4C, ctx->r4) = ctx->r9;
            goto L_80387B74;
    }
    // 0x80387B58: sw          $t1, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r9;
    // 0x80387B5C: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80387B60: addiu       $t3, $t3, -0x4374
    ctx->r11 = ADD32(ctx->r11, -0X4374);
    // 0x80387B64: sw          $t3, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->r11;
    // 0x80387B68: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    // 0x80387B6C: jal         0x8038120C
    // 0x80387B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8038120C(rdram, ctx);
        goto after_0;
    // 0x80387B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_80387B74:
    // 0x80387B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80387B78: jal         0x8037C92C
    // 0x80387B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037C92C(rdram, ctx);
        goto after_1;
    // 0x80387B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80387B80: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80387B84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80387B88: beql        $t4, $zero, L_80387BA8
    if (ctx->r12 == 0) {
        // 0x80387B8C: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80387BA8;
    }
    goto skip_0;
    // 0x80387B8C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80387B90: jal         0x8037C30C
    // 0x80387B94: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x80387B94: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x80387B98: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80387B9C: jal         0x803718C4
    // 0x80387BA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x80387BA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80387BA4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_80387BA8:
    // 0x80387BA8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80387BAC: beql        $t6, $zero, L_80387BC0
    if (ctx->r14 == 0) {
        // 0x80387BB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80387BC0;
    }
    goto skip_1;
    // 0x80387BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80387BB4: jal         0x803717C0
    // 0x80387BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x80387BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80387BBC:
    // 0x80387BBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80387BC0:
    // 0x80387BC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80387BC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80387BC8: jr          $ra
    // 0x80387BCC: nop

    return;
    // 0x80387BCC: nop

;}
RECOMP_FUNC void grDisplayLayer2PriProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105154: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80105158: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8010515C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105168: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010516C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105170: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80105174: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105178: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010517C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105180: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x80105184: ori         $t9, $t9, 0xFFFE
    ctx->r25 = ctx->r25 | 0XFFFE;
    // 0x80105188: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010518C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105190: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105194: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105198: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010519C: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x801051A0: lui         $t2, 0x55
    ctx->r10 = S32(0X55 << 16);
    // 0x801051A4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801051A8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801051AC: ori         $t2, $t2, 0x2048
    ctx->r10 = ctx->r10 | 0X2048;
    // 0x801051B0: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x801051B4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801051B8: jal         0x80014038
    // 0x801051BC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x801051BC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_0:
    // 0x801051C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801051C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801051C8: jr          $ra
    // 0x801051CC: nop

    return;
    // 0x801051CC: nop

;}
RECOMP_FUNC void itKabigonFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017E354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E358: jal         0x8017E25C
    // 0x8017E35C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itKabigonFallInitVars(rdram, ctx);
        goto after_0;
    // 0x8017E35C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017E360: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017E364: addiu       $a1, $a1, -0x548C
    ctx->r5 = ADD32(ctx->r5, -0X548C);
    // 0x8017E368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017E36C: jal         0x80172EC8
    // 0x8017E370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017E370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017E374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017E37C: jr          $ra
    // 0x8017E380: nop

    return;
    // 0x8017E380: nop

;}
RECOMP_FUNC void ftKirbySpecialNThrowCheckGotoThrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801624C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801624CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801624D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801624D4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801624D8: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x801624DC: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x801624E0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x801624E4: beql        $t8, $zero, L_80162524
    if (ctx->r24 == 0) {
        // 0x801624E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80162524;
    }
    goto skip_0;
    // 0x801624E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801624EC: lw          $a1, 0x840($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X840);
    // 0x801624F0: beql        $a1, $zero, L_80162524
    if (ctx->r5 == 0) {
        // 0x801624F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80162524;
    }
    goto skip_1;
    // 0x801624F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801624F8: beq         $a1, $zero, L_8016250C
    if (ctx->r5 == 0) {
        // 0x801624FC: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8016250C;
    }
    // 0x801624FC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80162500: jal         0x80161CA0
    // 0x80162504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbySpecialNApplyCaptureDamage(rdram, ctx);
        goto after_0;
    // 0x80162504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8016250C:
    // 0x8016250C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80162510: jalr        $t9
    // 0x80162514: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80162514: nop

    after_1:
    // 0x80162518: b           L_80162524
    // 0x8016251C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80162524;
    // 0x8016251C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80162520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80162524:
    // 0x80162524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016252C: jr          $ra
    // 0x80162530: nop

    return;
    // 0x80162530: nop

;}
RECOMP_FUNC void ftBossWaitSetVelStickRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801587B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801587B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801587B8: lb          $v1, 0x1C2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C2);
    // 0x801587BC: bgez        $v1, L_801587CC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801587C0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_801587CC;
    }
    // 0x801587C0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801587C4: b           L_801587CC
    // 0x801587C8: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
        goto L_801587CC;
    // 0x801587C8: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
L_801587CC:
    // 0x801587CC: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x801587D0: bne         $at, $zero, L_801587E0
    if (ctx->r1 != 0) {
        // 0x801587D4: nop
    
            goto L_801587E0;
    }
    // 0x801587D4: nop

    // 0x801587D8: b           L_801587E0
    // 0x801587DC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_801587E0;
    // 0x801587DC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_801587E0:
    // 0x801587E0: lb          $v1, 0x1C3($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C3);
    // 0x801587E4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x801587E8: bgez        $v1, L_801587F8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801587EC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801587F8;
    }
    // 0x801587EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801587F0: b           L_801587FC
    // 0x801587F4: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
        goto L_801587FC;
    // 0x801587F4: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
L_801587F8:
    // 0x801587F8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_801587FC:
    // 0x801587FC: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80158800: bne         $at, $zero, L_80158810
    if (ctx->r1 != 0) {
        // 0x80158804: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80158810;
    }
    // 0x80158804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80158808: b           L_80158810
    // 0x8015880C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80158810;
    // 0x8015880C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80158810:
    // 0x80158810: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80158814: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80158818: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8015881C: jr          $ra
    // 0x80158820: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x80158820: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void efManagerDamageSpawnOrbsMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFAB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FFABC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FFAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFAC4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FFAC8: jal         0x800FDAFC
    // 0x800FFACC: addiu       $a0, $a0, -0x2064
    ctx->r4 = ADD32(ctx->r4, -0X2064);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FFACC: addiu       $a0, $a0, -0x2064
    ctx->r4 = ADD32(ctx->r4, -0X2064);
    after_0:
    // 0x800FFAD0: bne         $v0, $zero, L_800FFAE0
    if (ctx->r2 != 0) {
        // 0x800FFAD4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FFAE0;
    }
    // 0x800FFAD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FFAD8: b           L_800FFB28
    // 0x800FFADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FFB28;
    // 0x800FFADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FFAE0:
    // 0x800FFAE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800FFAE4: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x800FFAE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800FFAEC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800FFAF0: sw          $t8, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r24;
    // 0x800FFAF4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800FFAF8: sw          $t7, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r15;
    // 0x800FFAFC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800FFB00: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
    // 0x800FFB04: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800FFB08: jal         0x80018994
    // 0x800FFB0C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x800FFB0C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800FFB10: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFB14: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800FFB18: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800FFB1C: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800FFB20: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800FFB24: sw          $t0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r8;
L_800FFB28:
    // 0x800FFB28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFB2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FFB30: jr          $ra
    // 0x800FFB34: nop

    return;
    // 0x800FFB34: nop

;}
RECOMP_FUNC void ftPikachuSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151D24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151D28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151D2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151D30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80151D34: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x80151D38: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80151D3C: jal         0x800E6F24
    // 0x80151D40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80151D40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80151D44: jal         0x800E0830
    // 0x80151D48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80151D48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80151D4C: jal         0x80151D0C
    // 0x80151D50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPikachuSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80151D50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80151D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151D58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151D5C: jr          $ra
    // 0x80151D60: nop

    return;
    // 0x80151D60: nop

;}
RECOMP_FUNC void func_ovl3_8016830C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016830C: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80168310: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80168314: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80168318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016831C: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x80168320: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80168324: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80168328: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8016832C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80168330: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80168334: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80168338: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8016833C: sw          $a1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r5;
    // 0x80168340: jal         0x80032A40
    // 0x80168344: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80168344: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80168348: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8016834C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80168350: addiu       $s7, $zero, 0x12
    ctx->r23 = ADD32(0, 0X12);
    // 0x80168354: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80168358: addiu       $s2, $sp, 0x9C
    ctx->r18 = ADD32(ctx->r29, 0X9C);
L_8016835C:
    // 0x8016835C: lbu         $t6, 0x56($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X56);
    // 0x80168360: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80168364: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80168368: blezl       $t6, L_801683B8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8016836C: lw          $v0, 0x14($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X14);
            goto L_801683B8;
    }
    goto skip_0;
    // 0x8016836C: lw          $v0, 0x14($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X14);
    skip_0:
    // 0x80168370: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
L_80168374:
    // 0x80168374: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80168378: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x8016837C: beql        $t7, $zero, L_801683B8
    if (ctx->r15 == 0) {
        // 0x80168380: lw          $v0, 0x14($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X14);
            goto L_801683B8;
    }
    goto skip_1;
    // 0x80168380: lw          $v0, 0x14($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X14);
    skip_1:
    // 0x80168384: jal         0x80032AF8
    // 0x80168388: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    guMtxL2F(rdram, ctx);
        goto after_1;
    // 0x80168388: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    after_1:
    // 0x8016838C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80168390: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80168394: jal         0x80034980
    // 0x80168398: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    guMtxCatF(rdram, ctx);
        goto after_2;
    // 0x80168398: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x8016839C: lbu         $t8, 0x56($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X56);
    // 0x801683A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801683A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801683A8: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801683AC: bnel        $at, $zero, L_80168374
    if (ctx->r1 != 0) {
        // 0x801683B0: lw          $v0, 0x58($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X58);
            goto L_80168374;
    }
    goto skip_2;
    // 0x801683B0: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    skip_2:
    // 0x801683B4: lw          $v0, 0x14($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X14);
L_801683B8:
    // 0x801683B8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x801683BC: beql        $s6, $v0, L_801683D0
    if (ctx->r22 == ctx->r2) {
        // 0x801683C0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_801683D0;
    }
    goto skip_3;
    // 0x801683C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x801683C4: bne         $s5, $s7, L_8016835C
    if (ctx->r21 != ctx->r23) {
        // 0x801683C8: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8016835C;
    }
    // 0x801683C8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x801683CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_801683D0:
    // 0x801683D0: lw          $v0, 0xF4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XF4);
    // 0x801683D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801683D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801683DC: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
    // 0x801683E0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801683E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801683E8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801683EC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801683F0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801683F4: jal         0x800348E0
    // 0x801683F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    guMtxXFMF(rdram, ctx);
        goto after_3;
    // 0x801683F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x801683FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80168400: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80168404: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80168408: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8016840C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80168410: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80168414: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80168418: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8016841C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80168420: jr          $ra
    // 0x80168424: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x80168424: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void mnStartupFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131ECC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131ED0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131ED4: addiu       $t8, $t8, 0x1F70
    ctx->r24 = ADD32(ctx->r24, 0X1F70);
    // 0x80131ED8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131EDC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131EE0: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131EE4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131EE8: jr          $ra
    // 0x80131EEC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131EEC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void mnPlayers1PTrainingStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137F00: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80137F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137F08: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80137F0C: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80137F10: addiu       $a0, $a0, -0x7BD4
    ctx->r4 = ADD32(ctx->r4, -0X7BD4);
    // 0x80137F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137F18: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80137F1C: jal         0x80007024
    // 0x80137F20: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80137F20: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80137F24: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80137F28: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137F2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80137F30: addiu       $t9, $t9, -0x7340
    ctx->r25 = ADD32(ctx->r25, -0X7340);
    // 0x80137F34: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80137F38: addiu       $a0, $a0, -0x7BB8
    ctx->r4 = ADD32(ctx->r4, -0X7BB8);
    // 0x80137F3C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80137F40: jal         0x800A2698
    // 0x80137F44: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x80137F44: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80137F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137F50: jr          $ra
    // 0x80137F54: nop

    return;
    // 0x80137F54: nop

;}
RECOMP_FUNC void itIwarkWeaponRockProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DE10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017DE14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DE18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017DE1C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017DE20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017DE24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017DE28: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x8017DE2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017DE30: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x8017DE34: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017DE38: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x8017DE3C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8017DE40: jal         0x80019438
    // 0x8017DE44: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x8017DE44: nop

    after_0:
    // 0x8017DE48: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DE4C: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8017DE50: jal         0x8001863C
    // 0x8017DE54: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8017DE54: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x8017DE58: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8017DE5C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DE60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017DE64: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x8017DE68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017DE6C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017DE70: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    // 0x8017DE74: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x8017DE78: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017DE7C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8017DE80: swc1        $f10, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
    // 0x8017DE84: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8017DE88: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8017DE8C: nop

    // 0x8017DE90: bc1fl       L_8017DEA4
    if (!c1cs) {
        // 0x8017DE94: sw          $t0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r8;
            goto L_8017DEA4;
    }
    goto skip_0;
    // 0x8017DE94: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    skip_0:
    // 0x8017DE98: b           L_8017DEA4
    // 0x8017DE9C: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
        goto L_8017DEA4;
    // 0x8017DE9C: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x8017DEA0: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_8017DEA4:
    // 0x8017DEA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DEA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017DEAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017DEB0: jr          $ra
    // 0x8017DEB4: nop

    return;
    // 0x8017DEB4: nop

;}
RECOMP_FUNC void func_ovl8_803762AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803762AC: jr          $ra
    // 0x803762B0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    return;
    // 0x803762B0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
;}
RECOMP_FUNC void syTaskmanSetDLBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004A0C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80004A10: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80004A14: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80004A18: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80004A1C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80004A20: addiu       $v0, $v0, 0x65C8
    ctx->r2 = ADD32(ctx->r2, 0X65C8);
    // 0x80004A24: addiu       $t2, $t2, 0x6588
    ctx->r10 = ADD32(ctx->r10, 0X6588);
    // 0x80004A28: addiu       $t0, $t0, 0x6580
    ctx->r8 = ADD32(ctx->r8, 0X6580);
    // 0x80004A2C: addiu       $a2, $a2, 0x6578
    ctx->r6 = ADD32(ctx->r6, 0X6578);
    // 0x80004A30: addiu       $v1, $v1, 0x6570
    ctx->r3 = ADD32(ctx->r3, 0X6570);
    // 0x80004A34: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80004A38: addiu       $a3, $a0, 0x8
    ctx->r7 = ADD32(ctx->r4, 0X8);
    // 0x80004A3C: addiu       $t1, $a0, 0x10
    ctx->r9 = ADD32(ctx->r4, 0X10);
    // 0x80004A40: addiu       $t3, $a0, 0x18
    ctx->r11 = ADD32(ctx->r4, 0X18);
L_80004A44:
    // 0x80004A44: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80004A48: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80004A4C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80004A50: sw          $t7, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r15;
    // 0x80004A54: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80004A58: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80004A5C: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80004A60: sw          $t6, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r14;
    // 0x80004A64: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80004A68: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x80004A6C: addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
    // 0x80004A70: sw          $t9, -0x20($a2)
    MEM_W(-0X20, ctx->r6) = ctx->r25;
    // 0x80004A74: lw          $t8, -0x1C($a3)
    ctx->r24 = MEM_W(ctx->r7, -0X1C);
    // 0x80004A78: addiu       $t1, $t1, 0x20
    ctx->r9 = ADD32(ctx->r9, 0X20);
    // 0x80004A7C: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x80004A80: sw          $t8, -0x1C($a2)
    MEM_W(-0X1C, ctx->r6) = ctx->r24;
    // 0x80004A84: lw          $t5, -0x20($t1)
    ctx->r13 = MEM_W(ctx->r9, -0X20);
    // 0x80004A88: sw          $t5, -0x20($t0)
    MEM_W(-0X20, ctx->r8) = ctx->r13;
    // 0x80004A8C: lw          $t4, -0x1C($t1)
    ctx->r12 = MEM_W(ctx->r9, -0X1C);
    // 0x80004A90: sw          $t4, -0x1C($t0)
    MEM_W(-0X1C, ctx->r8) = ctx->r12;
    // 0x80004A94: lw          $t7, -0x20($t3)
    ctx->r15 = MEM_W(ctx->r11, -0X20);
    // 0x80004A98: sw          $t7, -0x20($t2)
    MEM_W(-0X20, ctx->r10) = ctx->r15;
    // 0x80004A9C: lw          $t6, -0x1C($t3)
    ctx->r14 = MEM_W(ctx->r11, -0X1C);
    // 0x80004AA0: bne         $t2, $v0, L_80004A44
    if (ctx->r10 != ctx->r2) {
        // 0x80004AA4: sw          $t6, -0x1C($t2)
        MEM_W(-0X1C, ctx->r10) = ctx->r14;
            goto L_80004A44;
    }
    // 0x80004AA4: sw          $t6, -0x1C($t2)
    MEM_W(-0X1C, ctx->r10) = ctx->r14;
    // 0x80004AA8: jr          $ra
    // 0x80004AAC: nop

    return;
    // 0x80004AAC: nop

;}
RECOMP_FUNC void n_alSynSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FAB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002FAB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FAB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002FABC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8002FAC0: beql        $t6, $zero, L_8002FB1C
    if (ctx->r14 == 0) {
        // 0x8002FAC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FB1C;
    }
    goto skip_0;
    // 0x8002FAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002FAC8: jal         0x8002C618
    // 0x8002FACC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002FACC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FAD0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002FAD4: beq         $v0, $zero, L_8002FB18
    if (ctx->r2 == 0) {
        // 0x8002FAD8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002FB18;
    }
    // 0x8002FAD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002FADC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002FAE0: lw          $t7, -0x2CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CEC);
    // 0x8002FAE4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x8002FAE8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8002FAEC: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8002FAF0: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x8002FAF4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8002FAF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FAFC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002FB00: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002FB04: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002FB08: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002FB0C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8002FB10: jal         0x8002A230
    // 0x8002FB14: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    n_alEnvmixerParam(rdram, ctx);
        goto after_1;
    // 0x8002FB14: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    after_1:
L_8002FB18:
    // 0x8002FB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FB1C:
    // 0x8002FB1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002FB20: jr          $ra
    // 0x8002FB24: nop

    return;
    // 0x8002FB24: nop

;}
RECOMP_FUNC void lbTransitionMakeTransition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D430C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D4310: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800D4314: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D4318: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D431C: addiu       $t7, $t7, 0x5D60
    ctx->r15 = ADD32(ctx->r15, 0X5D60);
    // 0x800D4320: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800D4324: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D4328: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800D432C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D4330: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D4334: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D4338: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D433C: lw          $a1, 0x6484($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6484);
    // 0x800D4340: jal         0x800CDC88
    // 0x800D4344: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_0;
    // 0x800D4344: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800D4348: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800D434C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D4350: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x800D4354: jal         0x80009968
    // 0x800D4358: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800D4358: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800D435C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D4360: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800D4364: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D4368: sw          $t8, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r24;
    // 0x800D436C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D4370: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D4374: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800D4378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D437C: jal         0x80009DF4
    // 0x800D4380: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x800D4380: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x800D4384: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800D4388: lw          $t1, 0x6484($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6484);
    // 0x800D438C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800D4390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D4394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D4398: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x800D439C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D43A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D43A4: jal         0x8000F590
    // 0x800D43A8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_3;
    // 0x800D43A8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_3:
    // 0x800D43AC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800D43B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D43B4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800D43B8: beql        $v0, $zero, L_800D43DC
    if (ctx->r2 == 0) {
        // 0x800D43BC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D43DC;
    }
    goto skip_0;
    // 0x800D43BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x800D43C0: lw          $t2, 0x6484($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6484);
    // 0x800D43C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800D43C8: jal         0x8000BD8C
    // 0x800D43CC: addu        $a1, $v0, $t2
    ctx->r5 = ADD32(ctx->r2, ctx->r10);
    gcAddAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x800D43CC: addu        $a1, $v0, $t2
    ctx->r5 = ADD32(ctx->r2, ctx->r10);
    after_4:
    // 0x800D43D0: jal         0x8000DF34
    // 0x800D43D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x800D43D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800D43D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D43DC:
    // 0x800D43DC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800D43E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D43E4: jal         0x80008188
    // 0x800D43E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800D43E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x800D43EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D43F0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800D43F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D43F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D43FC: jr          $ra
    // 0x800D4400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D4400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftBossCommonSetUseFogColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158604: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80158608: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8015860C: lbu         $t7, 0x192($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X192);
    // 0x80158610: sb          $t9, 0xA8F($v0)
    MEM_B(0XA8F, ctx->r2) = ctx->r25;
    // 0x80158614: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80158618: jr          $ra
    // 0x8015861C: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    return;
    // 0x8015861C: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void mvOpeningYosterMainProc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013203C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132040: addiu       $v1, $v1, 0x2438
    ctx->r3 = ADD32(ctx->r3, 0X2438);
    // 0x80132044: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80132048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013204C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132050: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132054: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80132058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013205C: bne         $at, $zero, L_801320F8
    if (ctx->r1 != 0) {
        // 0x80132060: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_801320F8;
    }
    // 0x80132060: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132064: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132068: addiu       $a2, $a2, 0x243C
    ctx->r6 = ADD32(ctx->r6, 0X243C);
    // 0x8013206C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80132070: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132074: beq         $v0, $zero, L_80132080
    if (ctx->r2 == 0) {
        // 0x80132078: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132080;
    }
    // 0x80132078: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8013207C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80132080:
    // 0x80132080: jal         0x80390A04
    // 0x80132084: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80132084: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80132088: beq         $v0, $zero, L_801320A4
    if (ctx->r2 == 0) {
        // 0x8013208C: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_801320A4;
    }
    // 0x8013208C: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132090: jal         0x80390AC0
    // 0x80132094: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80132094: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80132098: beq         $v0, $zero, L_801320A4
    if (ctx->r2 == 0) {
        // 0x8013209C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801320A4;
    }
    // 0x8013209C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320A0: sw          $zero, 0x243C($at)
    MEM_W(0X243C, ctx->r1) = 0;
L_801320A4:
    // 0x801320A4: jal         0x8039076C
    // 0x801320A8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x801320A8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x801320AC: beq         $v0, $zero, L_801320CC
    if (ctx->r2 == 0) {
        // 0x801320B0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_801320CC;
    }
    // 0x801320B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801320B4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801320B8: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801320BC: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x801320C0: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x801320C4: jal         0x80005C74
    // 0x801320C8: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x801320C8: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
L_801320CC:
    // 0x801320CC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801320D0: lw          $t2, 0x2438($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2438);
    // 0x801320D4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801320D8: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x801320DC: bne         $t2, $at, L_801320F8
    if (ctx->r10 != ctx->r1) {
        // 0x801320E0: addiu       $v0, $v0, 0x4AD0
        ctx->r2 = ADD32(ctx->r2, 0X4AD0);
            goto L_801320F8;
    }
    // 0x801320E0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801320E4: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x801320E8: addiu       $t4, $zero, 0x2C
    ctx->r12 = ADD32(0, 0X2C);
    // 0x801320EC: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x801320F0: jal         0x80005C74
    // 0x801320F4: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x801320F4: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    after_4:
L_801320F8:
    // 0x801320F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801320FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132100: jr          $ra
    // 0x80132104: nop

    return;
    // 0x80132104: nop

;}
RECOMP_FUNC void gcAddDObjMatrixSetsRpyD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B3EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B3F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000B3F8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8000B3FC: jal         0x80008CC0
    // 0x8000B400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_0;
    // 0x8000B400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000B404: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000B408: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x8000B40C: jal         0x80008CC0
    // 0x8000B410: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8000B410: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8000B414: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000B418: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8000B41C: jal         0x80008CC0
    // 0x8000B420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8000B420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8000B424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B42C: jr          $ra
    // 0x8000B430: nop

    return;
    // 0x8000B430: nop

;}
RECOMP_FUNC void syMatrixRotPyrR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CAB4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001CAB8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001CABC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001CAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CAC4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001CAC8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001CACC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001CAD0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8001CAD4: jal         0x8001C97C
    // 0x8001CAD8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syMatrixRotPyrRF(rdram, ctx);
        goto after_0;
    // 0x8001CAD8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8001CADC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8001CAE0: jal         0x80019EA0
    // 0x8001CAE4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001CAE4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8001CAE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CAEC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001CAF0: jr          $ra
    // 0x8001CAF4: nop

    return;
    // 0x8001CAF4: nop

;}
RECOMP_FUNC void dbMenuInitMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80369EE0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80369EE4: lui         $t6, 0x8037
    ctx->r14 = S32(0X8037 << 16);
    // 0x80369EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80369EEC: addiu       $t6, $t6, -0x5C00
    ctx->r14 = ADD32(ctx->r14, -0X5C00);
    // 0x80369EF0: addiu       $t7, $zero, 0x7000
    ctx->r15 = ADD32(0, 0X7000);
    // 0x80369EF4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80369EF8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80369EFC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80369F00: jal         0x8037B98C
    // 0x80369F04: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_ovl8_8037B98C(rdram, ctx);
        goto after_0;
    // 0x80369F04: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80369F08: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369F0C: jal         0x8037D6D4
    // 0x80369F10: addiu       $a0, $a0, -0x5C68
    ctx->r4 = ADD32(ctx->r4, -0X5C68);
    func_ovl8_8037D6D4(rdram, ctx);
        goto after_1;
    // 0x80369F10: addiu       $a0, $a0, -0x5C68
    ctx->r4 = ADD32(ctx->r4, -0X5C68);
    after_1:
    // 0x80369F14: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369F18: jal         0x8037D9D0
    // 0x80369F1C: addiu       $a0, $a0, -0x6094
    ctx->r4 = ADD32(ctx->r4, -0X6094);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_2;
    // 0x80369F1C: addiu       $a0, $a0, -0x6094
    ctx->r4 = ADD32(ctx->r4, -0X6094);
    after_2:
    // 0x80369F20: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369F24: jal         0x8037D9B4
    // 0x80369F28: addiu       $a0, $a0, -0x6090
    ctx->r4 = ADD32(ctx->r4, -0X6090);
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_3;
    // 0x80369F28: addiu       $a0, $a0, -0x6090
    ctx->r4 = ADD32(ctx->r4, -0X6090);
    after_3:
    // 0x80369F2C: jal         0x8037D95C
    // 0x80369F30: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_ovl8_8037D95C(rdram, ctx);
        goto after_4;
    // 0x80369F30: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x80369F34: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80369F38: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80369F3C: jal         0x8037D908
    // 0x80369F40: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_ovl8_8037D908(rdram, ctx);
        goto after_5;
    // 0x80369F40: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_5:
    // 0x80369F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80369F48: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369F4C: sw          $zero, 0x1420($at)
    MEM_W(0X1420, ctx->r1) = 0;
    // 0x80369F50: jr          $ra
    // 0x80369F54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80369F54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftPublicPlayCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164C44: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80164C48: lw          $a1, -0x3064($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3064);
    // 0x80164C4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164C54: beq         $a1, $zero, L_80164C80
    if (ctx->r5 == 0) {
        // 0x80164C58: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80164C80;
    }
    // 0x80164C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80164C5C: lhu         $v0, 0x26($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X26);
    // 0x80164C60: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80164C64: beq         $v0, $zero, L_80164C80
    if (ctx->r2 == 0) {
        // 0x80164C68: nop
    
            goto L_80164C80;
    }
    // 0x80164C68: nop

    // 0x80164C6C: lhu         $t6, -0x3060($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3060);
    // 0x80164C70: bne         $t6, $v0, L_80164C80
    if (ctx->r14 != ctx->r2) {
        // 0x80164C74: nop
    
            goto L_80164C80;
    }
    // 0x80164C74: nop

    // 0x80164C78: jal         0x80026738
    // 0x80164C7C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x80164C7C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_80164C80:
    // 0x80164C80: jal         0x800269C0
    // 0x80164C84: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80164C84: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x80164C88: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164C8C: sw          $v0, -0x3064($at)
    MEM_W(-0X3064, ctx->r1) = ctx->r2;
    // 0x80164C90: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80164C94: lw          $a1, -0x3064($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3064);
    // 0x80164C98: beql        $a1, $zero, L_80164CB0
    if (ctx->r5 == 0) {
        // 0x80164C9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80164CB0;
    }
    goto skip_0;
    // 0x80164C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80164CA0: lhu         $t7, 0x26($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X26);
    // 0x80164CA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164CA8: sh          $t7, -0x3060($at)
    MEM_H(-0X3060, ctx->r1) = ctx->r15;
    // 0x80164CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80164CB0:
    // 0x80164CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164CB4: jr          $ra
    // 0x80164CB8: nop

    return;
    // 0x80164CB8: nop

;}
RECOMP_FUNC void ftSamusSpecialNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DB64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015DB68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015DB6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015DB70: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015DB74: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015DB78: jal         0x8015DB14
    // 0x8015DB7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftSamusSpecialNStartGetAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x8015DB7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015DB80: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8015DB84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015DB88: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x8015DB8C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015DB90: jal         0x800E6F24
    // 0x8015DB94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015DB94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015DB98: jal         0x800E0830
    // 0x8015DB9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015DB9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015DBA0: jal         0x8015DB4C
    // 0x8015DBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftSamusSpecialNStartInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8015DBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8015DBA8: lw          $t7, 0xADC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XADC);
    // 0x8015DBAC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8015DBB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8015DBB4: bnel        $t7, $at, L_8015DBC8
    if (ctx->r15 != ctx->r1) {
        // 0x8015DBB8: sw          $zero, 0xB18($s0)
        MEM_W(0XB18, ctx->r16) = 0;
            goto L_8015DBC8;
    }
    goto skip_0;
    // 0x8015DBB8: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    skip_0:
    // 0x8015DBBC: b           L_8015DBC8
    // 0x8015DBC0: sw          $t8, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r24;
        goto L_8015DBC8;
    // 0x8015DBC0: sw          $t8, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r24;
    // 0x8015DBC4: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
L_8015DBC8:
    // 0x8015DBC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015DBCC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015DBD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015DBD4: jr          $ra
    // 0x8015DBD8: nop

    return;
    // 0x8015DBD8: nop

;}
RECOMP_FUNC void func_ovl8_80371DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371DE4: jr          $ra
    // 0x80371DE8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x80371DE8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void itHammerCommonSetColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176118: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x8017611C: jal         0x80172F98
    // 0x80176120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainCheckSetColAnimID(rdram, ctx);
        goto after_0;
    // 0x80176120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80176124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017612C: jr          $ra
    // 0x80176130: nop

    return;
    // 0x80176130: nop

;}
RECOMP_FUNC void itMapCheckDestroyLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173DF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80173DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173DFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80173E00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80173E04: jal         0x801737B8
    // 0x80173E08: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80173E08: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_0:
    // 0x80173E0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80173E10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80173E14: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80173E18: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80173E1C: jal         0x801737EC
    // 0x80173E20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_1;
    // 0x80173E20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80173E24: beql        $v0, $zero, L_80173E38
    if (ctx->r2 == 0) {
        // 0x80173E28: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80173E38;
    }
    goto skip_0;
    // 0x80173E28: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80173E2C: jal         0x80172508
    // 0x80173E30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainSetSpinVelLR(rdram, ctx);
        goto after_2;
    // 0x80173E30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80173E34: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80173E38:
    // 0x80173E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80173E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173E40: beq         $t6, $zero, L_80173E50
    if (ctx->r14 == 0) {
        // 0x80173E44: nop
    
            goto L_80173E50;
    }
    // 0x80173E44: nop

    // 0x80173E48: b           L_80173E50
    // 0x80173E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80173E50;
    // 0x80173E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80173E50:
    // 0x80173E50: jr          $ra
    // 0x80173E54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80173E54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_803735E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803735E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803735E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803735EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x803735F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x803735F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x803735F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803735FC: sb          $zero, 0xC($a0)
    MEM_B(0XC, ctx->r4) = 0;
    // 0x80373600: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80373604: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80373608: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8037360C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80373610: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80373614: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80373618: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8037361C: beq         $a0, $zero, L_80373628
    if (ctx->r4 == 0) {
        // 0x80373620: swc1        $f4, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
            goto L_80373628;
    }
    // 0x80373620: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80373624: lw          $a1, 0x38($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X38);
L_80373628:
    // 0x80373628: jal         0x8037C3AC
    // 0x8037362C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    func_ovl8_8037C3AC(rdram, ctx);
        goto after_0;
    // 0x8037362C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    after_0:
    // 0x80373630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373638: jr          $ra
    // 0x8037363C: nop

    return;
    // 0x8037363C: nop

;}
RECOMP_FUNC void unref_8000A280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A288: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A28C: jal         0x80007CF4
    // 0x8000A290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_0;
    // 0x8000A290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000A294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000A298: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A29C: jal         0x80007C6C
    // 0x8000A2A0: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    gcDLLinkGObjHead(rdram, ctx);
        goto after_1;
    // 0x8000A2A0: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    after_1:
    // 0x8000A2A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A2A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A2AC: jr          $ra
    // 0x8000A2B0: nop

    return;
    // 0x8000A2B0: nop

;}
RECOMP_FUNC void ftCommonHammerWalkProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801479A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801479A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801479A8: jal         0x8014800C
    // 0x801479AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonHammerKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x801479AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801479B0: bnel        $v0, $zero, L_801479D4
    if (ctx->r2 != 0) {
        // 0x801479B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801479D4;
    }
    goto skip_0;
    // 0x801479B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801479B8: jal         0x80147E7C
    // 0x801479BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerFallCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x801479BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801479C0: bnel        $v0, $zero, L_801479D4
    if (ctx->r2 != 0) {
        // 0x801479C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801479D4;
    }
    goto skip_1;
    // 0x801479C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801479C8: jal         0x800F39AC
    // 0x801479CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftHammerCheckGotoHammerWait(rdram, ctx);
        goto after_2;
    // 0x801479CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801479D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801479D4:
    // 0x801479D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801479D8: jr          $ra
    // 0x801479DC: nop

    return;
    // 0x801479DC: nop

;}
RECOMP_FUNC void dbMenuDrawString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80369310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80369314: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80369318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8036931C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80369320: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369324: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80369328: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8036932C: addiu       $a0, $a0, 0x1428
    ctx->r4 = ADD32(ctx->r4, 0X1428);
    // 0x80369330: jal         0x80386BE0
    // 0x80369334: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_ovl8_80386BE0(rdram, ctx);
        goto after_0;
    // 0x80369334: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80369338: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x8036933C: addiu       $a1, $a1, 0x1428
    ctx->r5 = ADD32(ctx->r5, 0X1428);
    // 0x80369340: jal         0x8037DD60
    // 0x80369344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_1;
    // 0x80369344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80369348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8036934C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80369350: jr          $ra
    // 0x80369354: nop

    return;
    // 0x80369354: nop

;}
RECOMP_FUNC void ftKirbySpecialNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162758: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8016275C: jal         0x800DDDDC
    // 0x80162760: addiu       $a1, $a1, 0x2ABC
    ctx->r5 = ADD32(ctx->r5, 0X2ABC);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80162760: addiu       $a1, $a1, 0x2ABC
    ctx->r5 = ADD32(ctx->r5, 0X2ABC);
    after_0:
    // 0x80162764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016276C: jr          $ra
    // 0x80162770: nop

    return;
    // 0x80162770: nop

;}
RECOMP_FUNC void mnCharactersGetMotion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132500: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132504: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80132508: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013250C: addiu       $a3, $sp, 0x0
    ctx->r7 = ADD32(ctx->r29, 0X0);
    // 0x80132510: addiu       $t6, $t6, 0x6430
    ctx->r14 = ADD32(ctx->r14, 0X6430);
    // 0x80132514: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80132518: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
L_8013251C:
    // 0x8013251C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132520: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132524: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132528: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8013252C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132530: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132534: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132538: bne         $t6, $t0, L_8013251C
    if (ctx->r14 != ctx->r8) {
        // 0x8013253C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8013251C;
    }
    // 0x8013253C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132540: beq         $a2, $zero, L_80132558
    if (ctx->r6 == 0) {
        // 0x80132544: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80132558;
    }
    // 0x80132544: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80132548: beq         $a2, $v0, L_80132558
    if (ctx->r6 == ctx->r2) {
        // 0x8013254C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132558;
    }
    // 0x8013254C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132550: bnel        $a2, $at, L_801325AC
    if (ctx->r6 != ctx->r1) {
        // 0x80132554: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_801325AC;
    }
    goto skip_0;
    // 0x80132554: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_0:
L_80132558:
    // 0x80132558: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8013255C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80132560: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x80132564: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80132568: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x8013256C: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x80132570: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80132574: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80132578: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x8013257C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80132580: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80132584: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x80132588: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8013258C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80132590: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132594: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80132598: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8013259C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801325A0: b           L_80132760
    // 0x801325A4: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
        goto L_80132760;
    // 0x801325A4: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x801325A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_801325AC:
    // 0x801325AC: bne         $a1, $at, L_8013263C
    if (ctx->r5 != ctx->r1) {
        // 0x801325B0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8013263C;
    }
    // 0x801325B0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801325B4: beq         $a2, $at, L_801325C4
    if (ctx->r6 == ctx->r1) {
        // 0x801325B8: addiu       $a3, $zero, 0xA
        ctx->r7 = ADD32(0, 0XA);
            goto L_801325C4;
    }
    // 0x801325B8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x801325BC: bne         $a2, $a3, L_80132600
    if (ctx->r6 != ctx->r7) {
        // 0x801325C0: slti        $at, $a2, 0x1A
        ctx->r1 = SIGNED(ctx->r6) < 0X1A ? 1 : 0;
            goto L_80132600;
    }
    // 0x801325C0: slti        $at, $a2, 0x1A
    ctx->r1 = SIGNED(ctx->r6) < 0X1A ? 1 : 0;
L_801325C4:
    // 0x801325C4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x801325C8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801325CC: addiu       $t1, $t1, 0x5CD0
    ctx->r9 = ADD32(ctx->r9, 0X5CD0);
    // 0x801325D0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x801325D4: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x801325D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801325DC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x801325E0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801325E4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801325E8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x801325EC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801325F0: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x801325F4: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801325F8: b           L_80132760
    // 0x801325FC: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
        goto L_80132760;
    // 0x801325FC: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
L_80132600:
    // 0x80132600: bne         $at, $zero, L_8013263C
    if (ctx->r1 != 0) {
        // 0x80132604: slti        $at, $a2, 0x1F
        ctx->r1 = SIGNED(ctx->r6) < 0X1F ? 1 : 0;
            goto L_8013263C;
    }
    // 0x80132604: slti        $at, $a2, 0x1F
    ctx->r1 = SIGNED(ctx->r6) < 0X1F ? 1 : 0;
    // 0x80132608: beq         $at, $zero, L_8013263C
    if (ctx->r1 == 0) {
        // 0x8013260C: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_8013263C;
    }
    // 0x8013260C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80132610: bne         $v1, $v0, L_8013263C
    if (ctx->r3 != ctx->r2) {
        // 0x80132614: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_8013263C;
    }
    // 0x80132614: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132618: addiu       $t5, $t5, 0x5D30
    ctx->r13 = ADD32(ctx->r13, 0X5D30);
    // 0x8013261C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80132620: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80132624: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80132628: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x8013262C: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80132630: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80132634: b           L_80132760
    // 0x80132638: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
        goto L_80132760;
    // 0x80132638: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
L_8013263C:
    // 0x8013263C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80132640: bne         $a1, $a3, L_801326CC
    if (ctx->r5 != ctx->r7) {
        // 0x80132644: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_801326CC;
    }
    // 0x80132644: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80132648: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8013264C: beq         $a2, $at, L_8013265C
    if (ctx->r6 == ctx->r1) {
        // 0x80132650: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8013265C;
    }
    // 0x80132650: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80132654: bne         $a2, $a3, L_80132690
    if (ctx->r6 != ctx->r7) {
        // 0x80132658: slti        $at, $a2, 0x1A
        ctx->r1 = SIGNED(ctx->r6) < 0X1A ? 1 : 0;
            goto L_80132690;
    }
    // 0x80132658: slti        $at, $a2, 0x1A
    ctx->r1 = SIGNED(ctx->r6) < 0X1A ? 1 : 0;
L_8013265C:
    // 0x8013265C: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80132660: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132664: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80132668: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013266C: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80132670: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x80132674: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80132678: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8013267C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80132680: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80132684: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x80132688: b           L_80132760
    // 0x8013268C: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
        goto L_80132760;
    // 0x8013268C: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
L_80132690:
    // 0x80132690: bne         $at, $zero, L_801326CC
    if (ctx->r1 != 0) {
        // 0x80132694: slti        $at, $a2, 0x1F
        ctx->r1 = SIGNED(ctx->r6) < 0X1F ? 1 : 0;
            goto L_801326CC;
    }
    // 0x80132694: slti        $at, $a2, 0x1F
    ctx->r1 = SIGNED(ctx->r6) < 0X1F ? 1 : 0;
    // 0x80132698: beql        $at, $zero, L_801326D0
    if (ctx->r1 == 0) {
        // 0x8013269C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_801326D0;
    }
    goto skip_1;
    // 0x8013269C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_1:
    // 0x801326A0: bne         $v1, $v0, L_801326CC
    if (ctx->r3 != ctx->r2) {
        // 0x801326A4: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_801326CC;
    }
    // 0x801326A4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801326A8: addiu       $t3, $t3, 0x5D9C
    ctx->r11 = ADD32(ctx->r11, 0X5D9C);
    // 0x801326AC: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801326B0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801326B4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801326B8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801326BC: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x801326C0: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x801326C4: b           L_80132760
    // 0x801326C8: sw          $t5, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r13;
        goto L_80132760;
    // 0x801326C8: sw          $t5, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r13;
L_801326CC:
    // 0x801326CC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
L_801326D0:
    // 0x801326D0: bne         $a2, $at, L_80132720
    if (ctx->r6 != ctx->r1) {
        // 0x801326D4: sll         $t3, $a2, 2
        ctx->r11 = S32(ctx->r6 << 2);
            goto L_80132720;
    }
    // 0x801326D4: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x801326D8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x801326DC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801326E0: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801326E4: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x801326E8: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x801326EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801326F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801326F4: addiu       $t7, $t7, 0x5DA8
    ctx->r15 = ADD32(ctx->r15, 0X5DA8);
    // 0x801326F8: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x801326FC: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80132700: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x80132704: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80132708: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8013270C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80132710: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80132714: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x80132718: b           L_80132760
    // 0x8013271C: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
        goto L_80132760;
    // 0x8013271C: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
L_80132720:
    // 0x80132720: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80132724: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80132728: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x8013272C: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80132730: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80132734: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132738: addiu       $t0, $t0, 0x4E30
    ctx->r8 = ADD32(ctx->r8, 0X4E30);
    // 0x8013273C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80132740: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x80132744: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80132748: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8013274C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132750: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80132754: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80132758: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8013275C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
L_80132760:
    // 0x80132760: jr          $ra
    // 0x80132764: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80132764: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftFoxSpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C0B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015C0B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C0BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015C0C0: lw          $t6, 0xB24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB24);
    // 0x8015C0C4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8015C0C8: bne         $t7, $zero, L_8015C0F8
    if (ctx->r15 != 0) {
        // 0x8015C0CC: sw          $t7, 0xB24($v0)
        MEM_W(0XB24, ctx->r2) = ctx->r15;
            goto L_8015C0F8;
    }
    // 0x8015C0CC: sw          $t7, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = ctx->r15;
    // 0x8015C0D0: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x8015C0D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015C0D8: bne         $t9, $at, L_8015C0F0
    if (ctx->r25 != ctx->r1) {
        // 0x8015C0DC: nop
    
            goto L_8015C0F0;
    }
    // 0x8015C0DC: nop

    // 0x8015C0E0: jal         0x8015C88C
    // 0x8015C0E4: nop

    ftFoxSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015C0E4: nop

    after_0:
    // 0x8015C0E8: b           L_8015C0FC
    // 0x8015C0EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015C0FC;
    // 0x8015C0EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015C0F0:
    // 0x8015C0F0: jal         0x8015C838
    // 0x8015C0F4: nop

    ftFoxSpecialHiEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015C0F4: nop

    after_1:
L_8015C0F8:
    // 0x8015C0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015C0FC:
    // 0x8015C0FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015C100: jr          $ra
    // 0x8015C104: nop

    return;
    // 0x8015C104: nop

;}
RECOMP_FUNC void ftBossGootsubusuUpProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159B44: jal         0x800DE324
    // 0x80159B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonSetFighterProjectFloor(rdram, ctx);
        goto after_0;
    // 0x80159B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80159B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80159B50: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80159B54: lwc1        $f2, -0x3810($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3810);
    // 0x80159B58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80159B5C: lwc1        $f0, 0xF0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x80159B60: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80159B64: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x80159B68: nop

    // 0x80159B6C: bc1fl       L_80159B90
    if (!c1cs) {
        // 0x80159B70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80159B90;
    }
    goto skip_0;
    // 0x80159B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80159B74: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80159B78: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80159B7C: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80159B80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80159B84: jal         0x80159D34
    // 0x80159B88: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    ftBossGootsubusuWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x80159B88: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    after_1:
    // 0x80159B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80159B90:
    // 0x80159B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159B94: jr          $ra
    // 0x80159B98: nop

    return;
    // 0x80159B98: nop

;}
RECOMP_FUNC void func_ovl8_80386FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386FE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80386FE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80386FE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80386FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80386FF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80386FF4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80386FF8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80386FFC: jal         0x80376FBC
    // 0x80387000: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    stringLength(rdram, ctx);
        goto after_0;
    // 0x80387000: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80387004: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80387008: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8038700C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80387010: beq         $v1, $zero, L_80387028
    if (ctx->r3 == 0) {
        // 0x80387014: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_80387028;
    }
    // 0x80387014: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80387018: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8038701C: beq         $at, $zero, L_80387028
    if (ctx->r1 == 0) {
        // 0x80387020: nop
    
            goto L_80387028;
    }
    // 0x80387020: nop

    // 0x80387024: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80387028:
    // 0x80387028: bne         $t6, $zero, L_8038709C
    if (ctx->r14 != 0) {
        // 0x8038702C: subu        $a1, $t0, $a2
        ctx->r5 = SUB32(ctx->r8, ctx->r6);
            goto L_8038709C;
    }
    // 0x8038702C: subu        $a1, $t0, $a2
    ctx->r5 = SUB32(ctx->r8, ctx->r6);
    // 0x80387030: blez        $a1, L_8038709C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80387034: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8038709C;
    }
    // 0x80387034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80387038: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8038703C: beq         $v1, $zero, L_80387060
    if (ctx->r3 == 0) {
        // 0x80387040: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80387060;
    }
    // 0x80387040: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80387044: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
L_80387048:
    // 0x80387048: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8038704C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80387050: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80387054: bne         $a0, $v0, L_80387048
    if (ctx->r4 != ctx->r2) {
        // 0x80387058: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80387048;
    }
    // 0x80387058: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8038705C: beq         $v0, $a1, L_8038709C
    if (ctx->r2 == ctx->r5) {
        // 0x80387060: addiu       $a3, $zero, 0x20
        ctx->r7 = ADD32(0, 0X20);
            goto L_8038709C;
    }
L_80387060:
    // 0x80387060: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
L_80387064:
    // 0x80387064: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387068: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x8038706C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387070: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387074: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80387078: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8038707C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387080: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80387084: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387088: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8038708C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80387090: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80387094: bne         $v0, $a1, L_80387064
    if (ctx->r2 != ctx->r5) {
        // 0x80387098: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80387064;
    }
    // 0x80387098: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8038709C:
    // 0x8038709C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803870A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x803870A4: jal         0x80387420
    // 0x803870A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    stringCopyPartial(rdram, ctx);
        goto after_1;
    // 0x803870A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x803870AC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x803870B0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x803870B4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x803870B8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x803870BC: beq         $t7, $zero, L_8038712C
    if (ctx->r15 == 0) {
        // 0x803870C0: addu        $s0, $s0, $a2
        ctx->r16 = ADD32(ctx->r16, ctx->r6);
            goto L_8038712C;
    }
    // 0x803870C0: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x803870C4: subu        $a1, $t0, $a2
    ctx->r5 = SUB32(ctx->r8, ctx->r6);
    // 0x803870C8: blez        $a1, L_8038712C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x803870CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8038712C;
    }
    // 0x803870CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x803870D0: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x803870D4: beq         $v1, $zero, L_803870F4
    if (ctx->r3 == 0) {
        // 0x803870D8: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_803870F4;
    }
    // 0x803870D8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_803870DC:
    // 0x803870DC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803870E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x803870E4: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x803870E8: bne         $a0, $v0, L_803870DC
    if (ctx->r4 != ctx->r2) {
        // 0x803870EC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803870DC;
    }
    // 0x803870EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x803870F0: beq         $v0, $a1, L_8038712C
    if (ctx->r2 == ctx->r5) {
        // 0x803870F4: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8038712C;
    }
L_803870F4:
    // 0x803870F4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803870F8: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x803870FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387100: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387104: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80387108: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8038710C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387110: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80387114: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387118: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8038711C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80387120: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80387124: bne         $v0, $a1, L_803870F4
    if (ctx->r2 != ctx->r5) {
        // 0x80387128: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803870F4;
    }
    // 0x80387128: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8038712C:
    // 0x8038712C: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80387130: beq         $at, $zero, L_80387140
    if (ctx->r1 == 0) {
        // 0x80387134: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80387140;
    }
    // 0x80387134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80387138: b           L_80387144
    // 0x8038713C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
        goto L_80387144;
    // 0x8038713C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80387140:
    // 0x80387140: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80387144:
    // 0x80387144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80387148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8038714C: jr          $ra
    // 0x80387150: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80387150: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}

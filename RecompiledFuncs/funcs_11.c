#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lbBackupClearNewcomers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D48E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D48E4: addiu       $v0, $v0, 0x44E0
    ctx->r2 = ADD32(ctx->r2, 0X44E0);
    // 0x800D48E8: lbu         $t6, 0x457($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X457);
    // 0x800D48EC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D48F0: addiu       $v1, $v1, 0x3994
    ctx->r3 = ADD32(ctx->r3, 0X3994);
    // 0x800D48F4: lbu         $t9, 0x457($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X457);
    // 0x800D48F8: andi        $t8, $t6, 0xFFF0
    ctx->r24 = ctx->r14 & 0XFFF0;
    // 0x800D48FC: lhu         $t1, 0x458($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X458);
    // 0x800D4900: sb          $t8, 0x457($v0)
    MEM_B(0X457, ctx->r2) = ctx->r24;
    // 0x800D4904: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800D4908: sb          $t0, 0x457($v0)
    MEM_B(0X457, ctx->r2) = ctx->r8;
    // 0x800D490C: jr          $ra
    // 0x800D4910: sh          $t1, 0x458($v0)
    MEM_H(0X458, ctx->r2) = ctx->r9;
    return;
    // 0x800D4910: sh          $t1, 0x458($v0)
    MEM_H(0X458, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void mnCharactersFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133E28: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80133E2C: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80133E30: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80133E34: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133E38: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133E3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133E40: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80133E44: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80133E48: addiu       $t8, $t8, 0x6720
    ctx->r24 = ADD32(ctx->r24, 0X6720);
    // 0x80133E4C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80133E50: addiu       $t0, $t0, 0x6A40
    ctx->r8 = ADD32(ctx->r8, 0X6A40);
    // 0x80133E54: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80133E58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80133E5C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80133E60: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80133E64: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80133E68: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80133E6C: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80133E70: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80133E74: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80133E78: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80133E7C: jal         0x800CDF78
    // 0x80133E80: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80133E80: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80133E84: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133E88: addiu       $s0, $s0, 0x6228
    ctx->r16 = ADD32(ctx->r16, 0X6228);
    // 0x80133E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133E90: jal         0x800CDEEC
    // 0x80133E94: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80133E94: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80133E98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133E9C: jal         0x80004980
    // 0x80133EA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80133EA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80133EA4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80133EA8: addiu       $a2, $a2, 0x6A78
    ctx->r6 = ADD32(ctx->r6, 0X6A78);
    // 0x80133EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133EB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80133EB4: jal         0x800CDE04
    // 0x80133EB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80133EB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80133EBC: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80133EC0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133EC4: addiu       $a1, $a1, 0x3D68
    ctx->r5 = ADD32(ctx->r5, 0X3D68);
    // 0x80133EC8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80133ECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133ED0: jal         0x80009968
    // 0x80133ED4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80133ED4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80133ED8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80133EDC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80133EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133EE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80133EE8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80133EEC: jal         0x8000B9FC
    // 0x80133EF0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80133EF0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80133EF4: jal         0x80115890
    // 0x80133EF8: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80133EF8: nop

    after_6:
    // 0x80133EFC: jal         0x80133568
    // 0x80133F00: nop

    mnCharactersInitVars(rdram, ctx);
        goto after_7;
    // 0x80133F00: nop

    after_7:
    // 0x80133F04: jal         0x800FD300
    // 0x80133F08: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x80133F08: nop

    after_8:
    // 0x80133F0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80133F10: jal         0x800D7194
    // 0x80133F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x80133F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80133F18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80133F1C:
    // 0x80133F1C: jal         0x800D786C
    // 0x80133F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x80133F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80133F24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80133F28: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80133F2C: bne         $s0, $at, L_80133F1C
    if (ctx->r16 != ctx->r1) {
        // 0x80133F30: nop
    
            goto L_80133F1C;
    }
    // 0x80133F30: nop

    // 0x80133F34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133F38: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x80133F3C: jal         0x80004980
    // 0x80133F40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x80133F40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x80133F44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F48: jal         0x80133000
    // 0x80133F4C: sw          $v0, 0x66EC($at)
    MEM_W(0X66EC, ctx->r1) = ctx->r2;
    mnCharactersMakeStoryCamera(rdram, ctx);
        goto after_12;
    // 0x80133F4C: sw          $v0, 0x66EC($at)
    MEM_W(0X66EC, ctx->r1) = ctx->r2;
    after_12:
    // 0x80133F50: jal         0x801330A0
    // 0x80133F54: nop

    mnCharactersMakeDecalsCamera(rdram, ctx);
        goto after_13;
    // 0x80133F54: nop

    after_13:
    // 0x80133F58: jal         0x80133140
    // 0x80133F5C: nop

    mnCharactersMakeEmblemCamera(rdram, ctx);
        goto after_14;
    // 0x80133F5C: nop

    after_14:
    // 0x80133F60: jal         0x80133224
    // 0x80133F64: nop

    mnCharactersMakeNameCamera(rdram, ctx);
        goto after_15;
    // 0x80133F64: nop

    after_15:
    // 0x80133F68: jal         0x801332C4
    // 0x80133F6C: nop

    mnCharactersMakeWorksWallpaperCamera(rdram, ctx);
        goto after_16;
    // 0x80133F6C: nop

    after_16:
    // 0x80133F70: jal         0x80133364
    // 0x80133F74: nop

    mnCharactersMakeWorksCamera(rdram, ctx);
        goto after_17;
    // 0x80133F74: nop

    after_17:
    // 0x80133F78: jal         0x80133404
    // 0x80133F7C: nop

    mnCharactersMakeFighterCamera(rdram, ctx);
        goto after_18;
    // 0x80133F7C: nop

    after_18:
    // 0x80133F80: jal         0x80131D44
    // 0x80133F84: nop

    mnCharactersMakeDecals(rdram, ctx);
        goto after_19;
    // 0x80133F84: nop

    after_19:
    // 0x80133F88: jal         0x801322F0
    // 0x80133F8C: nop

    mnCharactersMakeWorksWallpaper(rdram, ctx);
        goto after_20;
    // 0x80133F8C: nop

    after_20:
    // 0x80133F90: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133F94: addiu       $s0, $s0, 0x65F8
    ctx->r16 = ADD32(ctx->r16, 0X65F8);
    // 0x80133F98: jal         0x80131B58
    // 0x80133F9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_21;
    // 0x80133F9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_21:
    // 0x80133FA0: jal         0x8013239C
    // 0x80133FA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersMakeWorks(rdram, ctx);
        goto after_22;
    // 0x80133FA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x80133FA8: jal         0x80131B58
    // 0x80133FAC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_23;
    // 0x80133FAC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_23:
    // 0x80133FB0: jal         0x80131C00
    // 0x80133FB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersMakeStory(rdram, ctx);
        goto after_24;
    // 0x80133FB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x80133FB8: jal         0x80131B58
    // 0x80133FBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_25;
    // 0x80133FBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_25:
    // 0x80133FC0: jal         0x80131F28
    // 0x80133FC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersMakeEmblem(rdram, ctx);
        goto after_26;
    // 0x80133FC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x80133FC8: jal         0x80131B58
    // 0x80133FCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_27;
    // 0x80133FCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_27:
    // 0x80133FD0: jal         0x801320E4
    // 0x80133FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersMakeName(rdram, ctx);
        goto after_28;
    // 0x80133FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_28:
    // 0x80133FD8: jal         0x80132FA0
    // 0x80133FDC: nop

    mnCharactersMakeMotionName(rdram, ctx);
        goto after_29;
    // 0x80133FDC: nop

    after_29:
    // 0x80133FE0: jal         0x80131B58
    // 0x80133FE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_30;
    // 0x80133FE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_30:
    // 0x80133FE8: jal         0x80132C40
    // 0x80133FEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersMakeFighter(rdram, ctx);
        goto after_31;
    // 0x80133FEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_31:
    // 0x80133FF0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80133FF4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80133FF8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133FFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80134000: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80134004: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80134008: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8013400C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80134010: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80134014: jal         0x803904E0
    // 0x80134018: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_32;
    // 0x80134018: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_32:
    // 0x8013401C: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80134020: lbu         $t5, 0x4AD1($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4AD1);
    // 0x80134024: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x80134028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013402C: bnel        $t5, $at, L_80134040
    if (ctx->r13 != ctx->r1) {
        // 0x80134030: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80134040;
    }
    goto skip_0;
    // 0x80134030: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80134034: jal         0x80020AB4
    // 0x80134038: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    syAudioPlayBGM(rdram, ctx);
        goto after_33;
    // 0x80134038: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_33:
    // 0x8013403C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134040:
    // 0x80134040: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80134044: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80134048: jr          $ra
    // 0x8013404C: nop

    return;
    // 0x8013404C: nop

;}
RECOMP_FUNC void mnDataMakeMenuGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801320D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801320DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801320E0: addiu       $t7, $t7, 0x2F80
    ctx->r15 = ADD32(ctx->r15, 0X2F80);
    // 0x801320E4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801320E8: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x801320EC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801320F0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801320F4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801320F8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801320FC: addiu       $t1, $t1, 0x2F8C
    ctx->r9 = ADD32(ctx->r9, 0X2F8C);
    // 0x80132100: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132104: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132108: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8013210C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80132110: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x80132114: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80132118: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8013211C: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80132120: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80132124: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132128: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8013212C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80132130: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80132134: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80132138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013213C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132140: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132144: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80132148: jal         0x80009968
    // 0x8013214C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013214C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x80132150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132154: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132158: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x8013215C: jr          $ra
    // 0x80132160: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80132160: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void lbParticleAllocGenerators(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2758: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D275C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D2760: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800D2764: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D2768: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D276C: addiu       $v1, $v1, 0x639C
    ctx->r3 = ADD32(ctx->r3, 0X639C);
    // 0x800D2770: addiu       $s1, $s1, 0x6398
    ctx->r17 = ADD32(ctx->r17, 0X6398);
    // 0x800D2774: addiu       $s0, $a0, -0x1
    ctx->r16 = ADD32(ctx->r4, -0X1);
    // 0x800D2778: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D277C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800D2780: bltz        $s0, L_800D27BC
    if (SIGNED(ctx->r16) < 0) {
        // 0x800D2784: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_800D27BC;
    }
    // 0x800D2784: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800D2788:
    // 0x800D2788: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x800D278C: jal         0x80004980
    // 0x800D2790: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800D2790: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800D2794: bnel        $v0, $zero, L_800D27A8
    if (ctx->r2 != 0) {
        // 0x800D2798: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_800D27A8;
    }
    goto skip_0;
    // 0x800D2798: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x800D279C: b           L_800D27E4
    // 0x800D27A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D27E4;
    // 0x800D27A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D27A4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_800D27A8:
    // 0x800D27A8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D27AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D27B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D27B4: bgez        $s0, L_800D2788
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D27B8: sw          $v0, 0x6398($at)
        MEM_W(0X6398, ctx->r1) = ctx->r2;
            goto L_800D2788;
    }
    // 0x800D27B8: sw          $v0, 0x6398($at)
    MEM_W(0X6398, ctx->r1) = ctx->r2;
L_800D27BC:
    // 0x800D27BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D27C0: sh          $zero, 0x644A($at)
    MEM_H(0X644A, ctx->r1) = 0;
    // 0x800D27C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D27C8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D27CC: sh          $zero, 0x6450($at)
    MEM_H(0X6450, ctx->r1) = 0;
    // 0x800D27D0: addiu       $a1, $a1, 0x2C4C
    ctx->r5 = ADD32(ctx->r5, 0X2C4C);
    // 0x800D27D4: addiu       $a0, $zero, -0x7
    ctx->r4 = ADD32(0, -0X7);
    // 0x800D27D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D27DC: jal         0x80009968
    // 0x800D27E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800D27E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
L_800D27E4:
    // 0x800D27E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D27E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D27EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D27F0: jr          $ra
    // 0x800D27F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D27F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnSoundTestMakeHeaderSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013234C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132350: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013235C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132360: jal         0x80009968
    // 0x80132364: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132364: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132368: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013236C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132370: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132374: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132378: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013237C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132380: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132384: jal         0x80009DF4
    // 0x80132388: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132388: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013238C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132390: lw          $t7, 0x4470($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4470);
    // 0x80132394: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132398: addiu       $t8, $t8, 0xB40
    ctx->r24 = ADD32(ctx->r24, 0XB40);
    // 0x8013239C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801323A0: jal         0x800CCFDC
    // 0x801323A4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801323A4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801323A8: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x801323AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801323B0: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x801323B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801323B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801323BC: addiu       $t0, $zero, 0x5F
    ctx->r8 = ADD32(0, 0X5F);
    // 0x801323C0: addiu       $t1, $zero, 0x58
    ctx->r9 = ADD32(0, 0X58);
    // 0x801323C4: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x801323C8: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801323CC: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x801323D0: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x801323D4: sb          $t2, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r10;
    // 0x801323D8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801323DC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801323E0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801323E4: lw          $t3, 0x4478($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4478);
    // 0x801323E8: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801323EC: addiu       $t4, $t4, 0x1BB8
    ctx->r12 = ADD32(ctx->r12, 0X1BB8);
    // 0x801323F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801323F4: jal         0x800CCFDC
    // 0x801323F8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801323F8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x801323FC: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80132400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132404: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80132408: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013240C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132410: addiu       $t6, $zero, 0xF2
    ctx->r14 = ADD32(0, 0XF2);
    // 0x80132414: addiu       $t7, $zero, 0xC7
    ctx->r15 = ADD32(0, 0XC7);
    // 0x80132418: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x8013241C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132420: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80132424: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80132428: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x8013242C: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132430: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132434: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132438: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8013243C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132444: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132448: jr          $ra
    // 0x8013244C: nop

    return;
    // 0x8013244C: nop

;}
RECOMP_FUNC void sc1PBonusStageInitBonus2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DC40: jal         0x8018DB24
    // 0x8018DC44: nop

    sc1PBonusStageMakeBumpers(rdram, ctx);
        goto after_0;
    // 0x8018DC44: nop

    after_0:
    // 0x8018DC48: jal         0x8018D5E8
    // 0x8018DC4C: nop

    sc1PBonusStageBonus2LoadFile(rdram, ctx);
        goto after_1;
    // 0x8018DC4C: nop

    after_1:
    // 0x8018DC50: jal         0x8018D794
    // 0x8018DC54: nop

    sc1PBonusStageMakePlatforms(rdram, ctx);
        goto after_2;
    // 0x8018DC54: nop

    after_2:
    // 0x8018DC58: jal         0x8018DAE0
    // 0x8018DC5C: nop

    sc1PBonusStageMakeBonus2Ground(rdram, ctx);
        goto after_3;
    // 0x8018DC5C: nop

    after_3:
    // 0x8018DC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DC64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DC68: jr          $ra
    // 0x8018DC6C: nop

    return;
    // 0x8018DC6C: nop

;}
RECOMP_FUNC void wpMapTestAllCheckFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167B58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80167B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80167B60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80167B64: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80167B68: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80167B6C: addiu       $a1, $a1, 0x7A8C
    ctx->r5 = ADD32(ctx->r5, 0X7A8C);
    // 0x80167B70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80167B74: jal         0x800DA034
    // 0x80167B78: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x80167B78: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_0:
    // 0x80167B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80167B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167B84: jr          $ra
    // 0x80167B88: nop

    return;
    // 0x80167B88: nop

;}
RECOMP_FUNC void func_ovl8_8038374C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038374C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383754: lh          $t7, 0x44($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X44);
    // 0x80383758: lh          $t6, 0x42($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X42);
    // 0x8038375C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80383760: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80383764: beql        $at, $zero, L_803837E4
    if (ctx->r1 == 0) {
        // 0x80383768: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803837E4;
    }
    goto skip_0;
    // 0x80383768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8038376C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80383770: lh          $t8, 0x138($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X138);
    // 0x80383774: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80383778: lw          $t9, 0x13C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X13C);
    // 0x8038377C: addu        $a0, $t8, $a0
    ctx->r4 = ADD32(ctx->r24, ctx->r4);
    // 0x80383780: jalr        $t9
    // 0x80383784: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383784: nop

    after_0:
    // 0x80383788: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8038378C: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80383790: lw          $t9, 0xFC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XFC);
    // 0x80383794: lh          $t0, 0xF8($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XF8);
    // 0x80383798: jalr        $t9
    // 0x8038379C: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8038379C: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    after_1:
    // 0x803837A0: beq         $v0, $zero, L_803837B8
    if (ctx->r2 == 0) {
        // 0x803837A4: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_803837B8;
    }
    // 0x803837A4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x803837A8: lh          $t1, 0x42($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X42);
    // 0x803837AC: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x803837B0: b           L_803837C4
    // 0x803837B4: sh          $t2, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r10;
        goto L_803837C4;
    // 0x803837B4: sh          $t2, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r10;
L_803837B8:
    // 0x803837B8: lh          $t3, 0x42($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X42);
    // 0x803837BC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x803837C0: sh          $t4, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r12;
L_803837C4:
    // 0x803837C4: lw          $v1, 0x38($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X38);
    // 0x803837C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x803837CC: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803837D0: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x803837D4: lh          $t5, 0x118($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X118);
    // 0x803837D8: jalr        $t9
    // 0x803837DC: addu        $a0, $t5, $v1
    ctx->r4 = ADD32(ctx->r13, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x803837DC: addu        $a0, $t5, $v1
    ctx->r4 = ADD32(ctx->r13, ctx->r3);
    after_2:
    // 0x803837E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803837E4:
    // 0x803837E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803837E8: jr          $ra
    // 0x803837EC: nop

    return;
    // 0x803837EC: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePuckAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136DE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136DE8: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80136DEC: jal         0x80009968
    // 0x80136DF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80136DF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80136DF4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136DF8: addiu       $a1, $a1, 0x6CCC
    ctx->r5 = ADD32(ctx->r5, 0X6CCC);
    // 0x80136DFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80136E04: jal         0x80008188
    // 0x80136E08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80136E08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80136E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136E10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136E14: jr          $ra
    // 0x80136E18: nop

    return;
    // 0x80136E18: nop

;}
RECOMP_FUNC void efParticleGObjSetSkipID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801158D8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801158DC: addiu       $v1, $v1, 0x1A10
    ctx->r3 = ADD32(ctx->r3, 0X1A10);
    // 0x801158E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801158E4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x801158E8: sllv        $t8, $t7, $a0
    ctx->r24 = S32(ctx->r15 << (ctx->r4 & 31));
    // 0x801158EC: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x801158F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801158F4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x801158F8: sw          $t9, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r25;
    // 0x801158FC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80115900: lw          $t2, 0x1A14($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1A14);
    // 0x80115904: lw          $t1, 0x7C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X7C);
    // 0x80115908: jr          $ra
    // 0x8011590C: sw          $t1, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->r9;
    return;
    // 0x8011590C: sw          $t1, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->r9;
;}
RECOMP_FUNC void mnPlayersVSShutter1PProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013317C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133188: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8013318C: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x80133190: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    // 0x80133194: jal         0x800CD1F0
    // 0x80133198: addiu       $a3, $zero, 0xD9
    ctx->r7 = ADD32(0, 0XD9);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_0;
    // 0x80133198: addiu       $a3, $zero, 0xD9
    ctx->r7 = ADD32(0, 0XD9);
    after_0:
    // 0x8013319C: jal         0x800CCF00
    // 0x801331A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x801331A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801331A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801331A8: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    // 0x801331AC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x801331B0: jal         0x800CD1F0
    // 0x801331B4: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_2;
    // 0x801331B4: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_2:
    // 0x801331B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801331BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801331C0: jr          $ra
    // 0x801331C4: nop

    return;
    // 0x801331C4: nop

;}
RECOMP_FUNC void ftSamusSpecialLwSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E1DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E1E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E1E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E1E8: jal         0x800DEEC8
    // 0x8015E1EC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015E1EC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015E1F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015E1F4: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8015E1F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015E1FC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E200: jal         0x800E6F24
    // 0x8015E204: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E204: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015E208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E20C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E210: jr          $ra
    // 0x8015E214: nop

    return;
    // 0x8015E214: nop

;}
RECOMP_FUNC void func_ovl8_80371DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371DEC: jr          $ra
    // 0x80371DF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371DF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void mnCharactersUpdateScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801338AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801338B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801338B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801338B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801338BC: jal         0x8039076C
    // 0x801338C0: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x801338C0: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_0:
    // 0x801338C4: jal         0x8039076C
    // 0x801338C8: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_1;
    // 0x801338C8: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_1:
    // 0x801338CC: beq         $v0, $zero, L_801338F4
    if (ctx->r2 == 0) {
        // 0x801338D0: addiu       $t7, $zero, 0x3A
        ctx->r15 = ADD32(0, 0X3A);
            goto L_801338F4;
    }
    // 0x801338D0: addiu       $t7, $zero, 0x3A
    ctx->r15 = ADD32(0, 0X3A);
    // 0x801338D4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801338D8: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801338DC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x801338E0: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x801338E4: jal         0x8013366C
    // 0x801338E8: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    mnCharactersBackupFighterKind(rdram, ctx);
        goto after_2;
    // 0x801338E8: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    after_2:
    // 0x801338EC: jal         0x80005C74
    // 0x801338F0: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x801338F0: nop

    after_3:
L_801338F4:
    // 0x801338F4: jal         0x80390804
    // 0x801338F8: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_4;
    // 0x801338F8: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_4:
    // 0x801338FC: beq         $v0, $zero, L_80133B14
    if (ctx->r2 == 0) {
        // 0x80133900: addiu       $a0, $v0, -0x1
        ctx->r4 = ADD32(ctx->r2, -0X1);
            goto L_80133B14;
    }
    // 0x80133900: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80133904: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80133908: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8013390C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80133910: addiu       $t9, $t9, 0x5228
    ctx->r25 = ADD32(ctx->r25, 0X5228);
    // 0x80133914: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80133918: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8013391C: lb          $v1, 0x8($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X8);
    // 0x80133920: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133924: addiu       $s1, $s1, 0x66E4
    ctx->r17 = ADD32(ctx->r17, 0X66E4);
    // 0x80133928: slti        $at, $v1, -0x14
    ctx->r1 = SIGNED(ctx->r3) < -0X14 ? 1 : 0;
    // 0x8013392C: beq         $at, $zero, L_801339B4
    if (ctx->r1 == 0) {
        // 0x80133930: nop
    
            goto L_801339B4;
    }
    // 0x80133930: nop

    // 0x80133934: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80133938: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013393C: lwc1        $f2, 0x65D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X65D8);
    // 0x80133940: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133944: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80133948: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013394C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133950: lwc1        $f10, 0x65DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65DC);
    // 0x80133954: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80133958: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8013395C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133960: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133964: addiu       $a0, $a0, 0x660C
    ctx->r4 = ADD32(ctx->r4, 0X660C);
    // 0x80133968: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8013396C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133970: lw          $v0, 0x74($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X74);
    // 0x80133974: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80133978: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8013397C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80133980: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80133984: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80133988: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8013398C: lw          $v0, 0x74($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X74);
    // 0x80133990: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80133994: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80133998: nop

    // 0x8013399C: bc1f        L_801339AC
    if (!c1cs) {
        // 0x801339A0: nop
    
            goto L_801339AC;
    }
    // 0x801339A0: nop

    // 0x801339A4: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801339A8: swc1        $f10, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f10.u32l;
L_801339AC:
    // 0x801339AC: sw          $zero, 0x66D0($at)
    MEM_W(0X66D0, ctx->r1) = 0;
    // 0x801339B0: lb          $v1, 0x8($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X8);
L_801339B4:
    // 0x801339B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801339B8: lwc1        $f2, 0x65E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X65E0);
    // 0x801339BC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801339C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801339C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801339C8: slti        $at, $v1, 0x15
    ctx->r1 = SIGNED(ctx->r3) < 0X15 ? 1 : 0;
    // 0x801339CC: bne         $at, $zero, L_80133A38
    if (ctx->r1 != 0) {
        // 0x801339D0: addiu       $a0, $a0, 0x660C
        ctx->r4 = ADD32(ctx->r4, 0X660C);
            goto L_80133A38;
    }
    // 0x801339D0: addiu       $a0, $a0, 0x660C
    ctx->r4 = ADD32(ctx->r4, 0X660C);
    // 0x801339D4: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x801339D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801339DC: lwc1        $f4, 0x65E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65E4);
    // 0x801339E0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801339E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801339E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801339EC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x801339F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801339F4: div.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801339F8: lw          $v0, 0x74($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X74);
    // 0x801339FC: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80133A00: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80133A04: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80133A08: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80133A0C: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x80133A10: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80133A14: lw          $v0, 0x74($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X74);
    // 0x80133A18: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80133A1C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80133A20: nop

    // 0x80133A24: bc1f        L_80133A34
    if (!c1cs) {
        // 0x80133A28: nop
    
            goto L_80133A34;
    }
    // 0x80133A28: nop

    // 0x80133A2C: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80133A30: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
L_80133A34:
    // 0x80133A34: sw          $zero, 0x66D0($at)
    MEM_W(0X66D0, ctx->r1) = 0;
L_80133A38:
    // 0x80133A38: lb          $s0, 0x9($a3)
    ctx->r16 = MEM_B(ctx->r7, 0X9);
    // 0x80133A3C: slti        $at, $s0, 0x15
    ctx->r1 = SIGNED(ctx->r16) < 0X15 ? 1 : 0;
    // 0x80133A40: bne         $at, $zero, L_80133AAC
    if (ctx->r1 != 0) {
        // 0x80133A44: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_80133AAC;
    }
    // 0x80133A44: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80133A48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133A4C: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80133A50: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80133A54: nop

    // 0x80133A58: bc1f        L_80133AAC
    if (!c1cs) {
        // 0x80133A5C: nop
    
            goto L_80133AAC;
    }
    // 0x80133A5C: nop

    // 0x80133A60: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x80133A64: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133A68: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80133A6C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80133A70: div.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80133A74: add.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80133A78: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x80133A7C: lw          $t4, 0x66E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X66E0);
    // 0x80133A80: lw          $a2, 0x66E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X66E8);
    // 0x80133A84: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80133A88: lw          $a0, 0x74($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X74);
    // 0x80133A8C: jal         0x80133754
    // 0x80133A90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    mnCharactersMoveFighterCamera(rdram, ctx);
        goto after_5;
    // 0x80133A90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_5:
    // 0x80133A94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133A98: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80133A9C: sw          $zero, 0x66D0($at)
    MEM_W(0X66D0, ctx->r1) = 0;
    // 0x80133AA0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80133AA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80133AA8: lb          $s0, 0x9($a3)
    ctx->r16 = MEM_B(ctx->r7, 0X9);
L_80133AAC:
    // 0x80133AAC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133AB0: slti        $at, $s0, -0x14
    ctx->r1 = SIGNED(ctx->r16) < -0X14 ? 1 : 0;
    // 0x80133AB4: beq         $at, $zero, L_80133CA4
    if (ctx->r1 == 0) {
        // 0x80133AB8: addiu       $s1, $s1, 0x66E4
        ctx->r17 = ADD32(ctx->r17, 0X66E4);
            goto L_80133CA4;
    }
    // 0x80133AB8: addiu       $s1, $s1, 0x66E4
    ctx->r17 = ADD32(ctx->r17, 0X66E4);
    // 0x80133ABC: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80133AC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133AC4: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80133AC8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80133ACC: nop

    // 0x80133AD0: bc1fl       L_80133CA8
    if (!c1cs) {
        // 0x80133AD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80133CA8;
    }
    goto skip_0;
    // 0x80133AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80133AD8: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80133ADC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133AE0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80133AE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80133AE8: div.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80133AEC: add.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80133AF0: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x80133AF4: lw          $t5, 0x66E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X66E0);
    // 0x80133AF8: lw          $a2, 0x66E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X66E8);
    // 0x80133AFC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80133B00: jal         0x80133754
    // 0x80133B04: lw          $a0, 0x74($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X74);
    mnCharactersMoveFighterCamera(rdram, ctx);
        goto after_6;
    // 0x80133B04: lw          $a0, 0x74($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X74);
    after_6:
    // 0x80133B08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133B0C: b           L_80133CA4
    // 0x80133B10: sw          $zero, 0x66D0($at)
    MEM_W(0X66D0, ctx->r1) = 0;
        goto L_80133CA4;
    // 0x80133B10: sw          $zero, 0x66D0($at)
    MEM_W(0X66D0, ctx->r1) = 0;
L_80133B14:
    // 0x80133B14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133B18: lw          $v0, 0x6718($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6718);
    // 0x80133B1C: bne         $v0, $zero, L_80133B3C
    if (ctx->r2 != 0) {
        // 0x80133B20: nop
    
            goto L_80133B3C;
    }
    // 0x80133B20: nop

    // 0x80133B24: jal         0x80390804
    // 0x80133B28: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_7;
    // 0x80133B28: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_7:
    // 0x80133B2C: bne         $v0, $zero, L_80133B54
    if (ctx->r2 != 0) {
        // 0x80133B30: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80133B54;
    }
    // 0x80133B30: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80133B34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133B38: lw          $v0, 0x6718($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6718);
L_80133B3C:
    // 0x80133B3C: bne         $v0, $zero, L_80133BDC
    if (ctx->r2 != 0) {
        // 0x80133B40: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80133BDC;
    }
    // 0x80133B40: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133B44: jal         0x8039089C
    // 0x80133B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_8;
    // 0x80133B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80133B4C: beq         $v0, $zero, L_80133BDC
    if (ctx->r2 == 0) {
        // 0x80133B50: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80133BDC;
    }
    // 0x80133B50: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_80133B54:
    // 0x80133B54: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133B58: addiu       $s0, $s0, 0x65F8
    ctx->r16 = ADD32(ctx->r16, 0X65F8);
    // 0x80133B5C: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
    // 0x80133B60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80133B64:
    // 0x80133B64: bne         $v0, $zero, L_80133B74
    if (ctx->r2 != 0) {
        // 0x80133B68: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80133B74;
    }
    // 0x80133B68: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80133B6C: b           L_80133B78
    // 0x80133B70: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_80133B78;
    // 0x80133B70: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_80133B74:
    // 0x80133B74: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
L_80133B78:
    // 0x80133B78: jal         0x80131B58
    // 0x80133B7C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_9;
    // 0x80133B7C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x80133B80: jal         0x80133510
    // 0x80133B84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersCheckHaveFighterKind(rdram, ctx);
        goto after_10;
    // 0x80133B84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x80133B88: beql        $v0, $zero, L_80133B64
    if (ctx->r2 == 0) {
        // 0x80133B8C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80133B64;
    }
    goto skip_1;
    // 0x80133B8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80133B90: jal         0x80131B58
    // 0x80133B94: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_11;
    // 0x80133B94: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x80133B98: jal         0x8013369C
    // 0x80133B9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersChangeFighter(rdram, ctx);
        goto after_12;
    // 0x80133B9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80133BA0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80133BA4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80133BA8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133BAC: beq         $t7, $zero, L_80133BC4
    if (ctx->r15 == 0) {
        // 0x80133BB0: addiu       $t0, $t9, 0xA0
        ctx->r8 = ADD32(ctx->r25, 0XA0);
            goto L_80133BC4;
    }
    // 0x80133BB0: addiu       $t0, $t9, 0xA0
    ctx->r8 = ADD32(ctx->r25, 0XA0);
    // 0x80133BB4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80133BB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133BBC: b           L_80133BD4
    // 0x80133BC0: sw          $t8, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->r24;
        goto L_80133BD4;
    // 0x80133BC0: sw          $t8, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->r24;
L_80133BC4:
    // 0x80133BC4: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80133BC8: mflo        $t1
    ctx->r9 = lo;
    // 0x80133BCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133BD0: sw          $t1, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->r9;
L_80133BD4:
    // 0x80133BD4: jal         0x80133840
    // 0x80133BD8: nop

    mnCharactersResetFighterCamera(rdram, ctx);
        goto after_13;
    // 0x80133BD8: nop

    after_13:
L_80133BDC:
    // 0x80133BDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133BE0: lw          $v0, 0x6718($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6718);
    // 0x80133BE4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133BE8: addiu       $s0, $s0, 0x65F8
    ctx->r16 = ADD32(ctx->r16, 0X65F8);
    // 0x80133BEC: bne         $v0, $zero, L_80133C0C
    if (ctx->r2 != 0) {
        // 0x80133BF0: addiu       $s1, $zero, 0xB
        ctx->r17 = ADD32(0, 0XB);
            goto L_80133C0C;
    }
    // 0x80133BF0: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
    // 0x80133BF4: jal         0x80390804
    // 0x80133BF8: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_14;
    // 0x80133BF8: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_14:
    // 0x80133BFC: bne         $v0, $zero, L_80133C24
    if (ctx->r2 != 0) {
        // 0x80133C00: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80133C24;
    }
    // 0x80133C00: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80133C04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133C08: lw          $v0, 0x6718($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6718);
L_80133C0C:
    // 0x80133C0C: bne         $v0, $zero, L_80133CA4
    if (ctx->r2 != 0) {
        // 0x80133C10: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80133CA4;
    }
    // 0x80133C10: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80133C14: jal         0x8039089C
    // 0x80133C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_15;
    // 0x80133C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80133C1C: beq         $v0, $zero, L_80133CA4
    if (ctx->r2 == 0) {
        // 0x80133C20: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80133CA4;
    }
    // 0x80133C20: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_80133C24:
    // 0x80133C24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80133C28:
    // 0x80133C28: bne         $s1, $v0, L_80133C38
    if (ctx->r17 != ctx->r2) {
        // 0x80133C2C: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80133C38;
    }
    // 0x80133C2C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80133C30: b           L_80133C3C
    // 0x80133C34: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
        goto L_80133C3C;
    // 0x80133C34: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80133C38:
    // 0x80133C38: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
L_80133C3C:
    // 0x80133C3C: jal         0x80131B58
    // 0x80133C40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_16;
    // 0x80133C40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_16:
    // 0x80133C44: jal         0x80133510
    // 0x80133C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersCheckHaveFighterKind(rdram, ctx);
        goto after_17;
    // 0x80133C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x80133C4C: beql        $v0, $zero, L_80133C28
    if (ctx->r2 == 0) {
        // 0x80133C50: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80133C28;
    }
    goto skip_2;
    // 0x80133C50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80133C54: jal         0x80131B58
    // 0x80133C58: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_18;
    // 0x80133C58: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_18:
    // 0x80133C5C: jal         0x8013369C
    // 0x80133C60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersChangeFighter(rdram, ctx);
        goto after_19;
    // 0x80133C60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x80133C64: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80133C68: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80133C6C: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x80133C70: beq         $t3, $zero, L_80133C88
    if (ctx->r11 == 0) {
        // 0x80133C74: subu        $t7, $t6, $t5
        ctx->r15 = SUB32(ctx->r14, ctx->r13);
            goto L_80133C88;
    }
    // 0x80133C74: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80133C78: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80133C7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C80: b           L_80133C9C
    // 0x80133C84: sw          $t4, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->r12;
        goto L_80133C9C;
    // 0x80133C84: sw          $t4, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->r12;
L_80133C88:
    // 0x80133C88: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133C8C: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80133C90: mflo        $t8
    ctx->r24 = lo;
    // 0x80133C94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C98: sw          $t8, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = ctx->r24;
L_80133C9C:
    // 0x80133C9C: jal         0x80133840
    // 0x80133CA0: nop

    mnCharactersResetFighterCamera(rdram, ctx);
        goto after_20;
    // 0x80133CA0: nop

    after_20:
L_80133CA4:
    // 0x80133CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80133CA8:
    // 0x80133CA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80133CAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80133CB0: jr          $ra
    // 0x80133CB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80133CB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mpCollisionCheckRWallSurfaceTilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7270: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800F7274: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F7278: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F727C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800F7280: subu        $v0, $a2, $a0
    ctx->r2 = SUB32(ctx->r6, ctx->r4);
    // 0x800F7284: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F7288: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F728C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F7290: bgez        $v0, L_800F72A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F7294: swc1        $f0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
            goto L_800F72A4;
    }
    // 0x800F7294: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800F7298: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800F729C: b           L_800F72A8
    // 0x800F72A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
        goto L_800F72A8;
    // 0x800F72A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_800F72A4:
    // 0x800F72A4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800F72A8:
    // 0x800F72A8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F72AC: nop

    // 0x800F72B0: bc1fl       L_800F730C
    if (!c1cs) {
        // 0x800F72B4: mtc1        $a1, $f6
        ctx->f6.u32l = ctx->r5;
            goto L_800F730C;
    }
    goto skip_0;
    // 0x800F72B4: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    skip_0:
    // 0x800F72B8: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800F72BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F72C0: lwc1        $f10, 0x848($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X848);
    // 0x800F72C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F72C8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F72CC: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800F72D0: nop

    // 0x800F72D4: bc1t        L_800F7300
    if (c1cs) {
        // 0x800F72D8: nop
    
            goto L_800F7300;
    }
    // 0x800F72D8: nop

    // 0x800F72DC: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F72E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F72E4: lwc1        $f10, 0x84C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X84C);
    // 0x800F72E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F72EC: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F72F0: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800F72F4: nop

    // 0x800F72F8: bc1fl       L_800F735C
    if (!c1cs) {
        // 0x800F72FC: lwc1        $f16, 0x7C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
            goto L_800F735C;
    }
    goto skip_1;
    // 0x800F72FC: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    skip_1:
L_800F7300:
    // 0x800F7300: b           L_800F7694
    // 0x800F7304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7694;
    // 0x800F7304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7308: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
L_800F730C:
    // 0x800F730C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7310: lwc1        $f10, 0x850($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X850);
    // 0x800F7314: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F7318: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F731C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800F7320: nop

    // 0x800F7324: bc1t        L_800F7350
    if (c1cs) {
        // 0x800F7328: nop
    
            goto L_800F7350;
    }
    // 0x800F7328: nop

    // 0x800F732C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F7330: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7334: lwc1        $f10, 0x854($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X854);
    // 0x800F7338: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F733C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F7340: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F7344: nop

    // 0x800F7348: bc1fl       L_800F735C
    if (!c1cs) {
        // 0x800F734C: lwc1        $f16, 0x7C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
            goto L_800F735C;
    }
    goto skip_2;
    // 0x800F734C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    skip_2:
L_800F7350:
    // 0x800F7350: b           L_800F7694
    // 0x800F7354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7694;
    // 0x800F7354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7358: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
L_800F735C:
    // 0x800F735C: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800F7360: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800F7364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800F7368: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800F736C: subu        $v1, $a3, $t6
    ctx->r3 = SUB32(ctx->r7, ctx->r14);
    // 0x800F7370: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800F7374: bgez        $v1, L_800F7388
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800F7378: swc1        $f0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
            goto L_800F7388;
    }
    // 0x800F7378: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800F737C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800F7380: b           L_800F738C
    // 0x800F7384: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
        goto L_800F738C;
    // 0x800F7384: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_800F7388:
    // 0x800F7388: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
L_800F738C:
    // 0x800F738C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800F7390: nop

    // 0x800F7394: bc1fl       L_800F73E0
    if (!c1cs) {
        // 0x800F7398: mtc1        $a2, $f4
        ctx->f4.u32l = ctx->r6;
            goto L_800F73E0;
    }
    goto skip_3;
    // 0x800F7398: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    skip_3:
    // 0x800F739C: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800F73A0: nop

    // 0x800F73A4: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F73A8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800F73AC: nop

    // 0x800F73B0: bc1t        L_800F73D4
    if (c1cs) {
        // 0x800F73B4: nop
    
            goto L_800F73D4;
    }
    // 0x800F73B4: nop

    // 0x800F73B8: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x800F73BC: nop

    // 0x800F73C0: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F73C4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800F73C8: nop

    // 0x800F73CC: bc1fl       L_800F7420
    if (!c1cs) {
        // 0x800F73D0: lw          $t7, 0x6C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X6C);
            goto L_800F7420;
    }
    goto skip_4;
    // 0x800F73D0: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    skip_4:
L_800F73D4:
    // 0x800F73D4: b           L_800F7694
    // 0x800F73D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7694;
    // 0x800F73D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F73DC: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
L_800F73E0:
    // 0x800F73E0: nop

    // 0x800F73E4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F73E8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800F73EC: nop

    // 0x800F73F0: bc1t        L_800F7414
    if (c1cs) {
        // 0x800F73F4: nop
    
            goto L_800F7414;
    }
    // 0x800F73F4: nop

    // 0x800F73F8: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800F73FC: nop

    // 0x800F7400: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F7404: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800F7408: nop

    // 0x800F740C: bc1fl       L_800F7420
    if (!c1cs) {
        // 0x800F7410: lw          $t7, 0x6C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X6C);
            goto L_800F7420;
    }
    goto skip_5;
    // 0x800F7410: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    skip_5:
L_800F7414:
    // 0x800F7414: b           L_800F7694
    // 0x800F7418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7694;
    // 0x800F7418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F741C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_800F7420:
    // 0x800F7420: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800F7424: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800F7428: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800F742C: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F7430: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800F7434: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800F7438: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F743C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7440: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F7444: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F7448: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F744C: swc1        $f14, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f14.u32l;
    // 0x800F7450: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800F7454: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x800F7458: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F745C: lwc1        $f8, 0x858($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X858);
    // 0x800F7460: div.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800F7464: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800F7468: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800F746C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F7470: add.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x800F7474: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800F7478: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F747C: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x800F7480: nop

    // 0x800F7484: bc1f        L_800F7694
    if (!c1cs) {
        // 0x800F7488: nop
    
            goto L_800F7694;
    }
    // 0x800F7488: nop

    // 0x800F748C: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800F7490: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F7494: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7498: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
    // 0x800F749C: div.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800F74A0: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F74A4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800F74A8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F74AC: lwc1        $f6, 0x85C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X85C);
    // 0x800F74B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F74B4: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800F74B8: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F74BC: sub.s       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800F74C0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F74C4: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x800F74C8: nop

    // 0x800F74CC: bc1fl       L_800F7520
    if (!c1cs) {
        // 0x800F74D0: sub.s       $f0, $f10, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
            goto L_800F7520;
    }
    goto skip_6;
    // 0x800F74D0: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    skip_6:
    // 0x800F74D4: lwc1        $f4, 0x860($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X860);
    // 0x800F74D8: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800F74DC: nop

    // 0x800F74E0: bc1f        L_800F7694
    if (!c1cs) {
        // 0x800F74E4: nop
    
            goto L_800F7694;
    }
    // 0x800F74E4: nop

    // 0x800F74E8: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x800F74EC: nop

    // 0x800F74F0: bc1f        L_800F7694
    if (!c1cs) {
        // 0x800F74F4: nop
    
            goto L_800F7694;
    }
    // 0x800F74F4: nop

    // 0x800F74F8: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x800F74FC: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800F7500: bc1f        L_800F7694
    if (!c1cs) {
        // 0x800F7504: nop
    
            goto L_800F7694;
    }
    // 0x800F7504: nop

    // 0x800F7508: swc1        $f12, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f12.u32l;
    // 0x800F750C: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800F7510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F7514: b           L_800F7694
    // 0x800F7518: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
        goto L_800F7694;
    // 0x800F7518: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
    // 0x800F751C: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
L_800F7520:
    // 0x800F7520: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F7524: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F7528: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800F752C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800F7530: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800F7534: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800F7538: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800F753C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F7540: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800F7544: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800F7548: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800F754C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F7550: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800F7554: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F7558: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F755C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800F7560: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F7564: div.s       $f14, $f18, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800F7568: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800F756C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x800F7570: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    // 0x800F7574: bc1fl       L_800F75B0
    if (!c1cs) {
        // 0x800F7578: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800F75B0;
    }
    goto skip_7;
    // 0x800F7578: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_7:
    // 0x800F757C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7580: lwc1        $f4, 0x864($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X864);
    // 0x800F7584: mov.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = ctx->f8.fl;
    // 0x800F7588: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F758C: nop

    // 0x800F7590: bc1fl       L_800F75A4
    if (!c1cs) {
        // 0x800F7594: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_800F75A4;
    }
    goto skip_8;
    // 0x800F7594: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_8:
    // 0x800F7598: b           L_800F7694
    // 0x800F759C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7694;
    // 0x800F759C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F75A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800F75A4:
    // 0x800F75A4: b           L_800F75EC
    // 0x800F75A8: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
        goto L_800F75EC;
    // 0x800F75A8: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F75AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800F75B0:
    // 0x800F75B0: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F75B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F75B8: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800F75BC: nop

    // 0x800F75C0: bc1fl       L_800F75EC
    if (!c1cs) {
        // 0x800F75C4: lwc1        $f8, 0x4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
            goto L_800F75EC;
    }
    goto skip_9;
    // 0x800F75C4: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    skip_9:
    // 0x800F75C8: lwc1        $f10, 0x868($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X868);
    // 0x800F75CC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800F75D0: nop

    // 0x800F75D4: bc1fl       L_800F75E8
    if (!c1cs) {
        // 0x800F75D8: mov.s       $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
            goto L_800F75E8;
    }
    goto skip_10;
    // 0x800F75D8: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    skip_10:
    // 0x800F75DC: b           L_800F7694
    // 0x800F75E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7694;
    // 0x800F75E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F75E4: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_800F75E8:
    // 0x800F75E8: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
L_800F75EC:
    // 0x800F75EC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F75F0: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F75F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F75F8: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800F75FC: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F7600: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800F7604: lwc1        $f8, 0x86C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X86C);
    // 0x800F7608: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F760C: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800F7610: div.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800F7614: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800F7618: nop

    // 0x800F761C: bc1t        L_800F763C
    if (c1cs) {
        // 0x800F7620: nop
    
            goto L_800F763C;
    }
    // 0x800F7620: nop

    // 0x800F7624: lwc1        $f6, 0x870($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X870);
    // 0x800F7628: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F762C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800F7630: nop

    // 0x800F7634: bc1fl       L_800F7648
    if (!c1cs) {
        // 0x800F7638: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800F7648;
    }
    goto skip_11;
    // 0x800F7638: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_11:
L_800F763C:
    // 0x800F763C: b           L_800F7694
    // 0x800F7640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7694;
    // 0x800F7640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F7644: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800F7648:
    // 0x800F7648: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F764C: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F7650: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F7654: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x800F7658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F765C: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800F7660: nop

    // 0x800F7664: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800F7668: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800F766C: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x800F7670: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F7674: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F7678: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800F767C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800F7680: nop

    // 0x800F7684: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F7688: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800F768C: b           L_800F7694
    // 0x800F7690: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
        goto L_800F7694;
    // 0x800F7690: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
L_800F7694:
    // 0x800F7694: jr          $ra
    // 0x800F7698: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800F7698: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void gmCameraUpdateAnimVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CBE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CBE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CBEC: jal         0x80010580
    // 0x8010CBF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcPlayCamAnim(rdram, ctx);
        goto after_0;
    // 0x8010CBF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010CBF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8010CBF8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010CBFC: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8010CC00: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8010CC04: lwc1        $f6, 0x8C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x8010CC08: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8010CC0C: lwc1        $f10, 0x4C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8010CC10: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010CC14: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8010CC18: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x8010CC1C: lwc1        $f16, 0x90($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X90);
    // 0x8010CC20: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8010CC24: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8010CC28: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    // 0x8010CC2C: lwc1        $f6, 0x94($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X94);
    // 0x8010CC30: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010CC34: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8010CC38: swc1        $f8, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f8.u32l;
    // 0x8010CC3C: lwc1        $f16, 0x8C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x8010CC40: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8010CC44: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8010CC48: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8010CC4C: lwc1        $f6, 0x90($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X90);
    // 0x8010CC50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010CC54: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x8010CC58: lwc1        $f16, 0x94($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X94);
    // 0x8010CC5C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8010CC60: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x8010CC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CC6C: jr          $ra
    // 0x8010CC70: nop

    return;
    // 0x8010CC70: nop

;}
RECOMP_FUNC void ftCommonFireFlowerShootProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801472B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801472B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801472B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x801472BC: jal         0x800D9480
    // 0x801472C0: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801472C0: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    after_0:
    // 0x801472C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801472C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801472CC: jr          $ra
    // 0x801472D0: nop

    return;
    // 0x801472D0: nop

;}
RECOMP_FUNC void func_ovl3_80175408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017540C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175410: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175414: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80175418: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8017541C: lw          $t8, 0x2D4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2D4);
    // 0x80175420: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80175424: lw          $t7, -0x6590($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6590);
    // 0x80175428: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8017542C: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80175430: addiu       $t1, $t1, 0x2198
    ctx->r9 = ADD32(ctx->r9, 0X2198);
    // 0x80175434: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80175438: subu        $a1, $t0, $t1
    ctx->r5 = SUB32(ctx->r8, ctx->r9);
    // 0x8017543C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80175440: jal         0x8000BD8C
    // 0x80175444: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    gcAddAnimJointAll(rdram, ctx);
        goto after_0;
    // 0x80175444: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x80175448: jal         0x8000DF34
    // 0x8017544C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8017544C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80175450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175458: jr          $ra
    // 0x8017545C: nop

    return;
    // 0x8017545C: nop

;}
RECOMP_FUNC void ftYoshiSpecialLwLandingProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EDE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015EDE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015EDEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015EDF0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015EDF4: lw          $t7, 0x17C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X17C);
    // 0x8015EDF8: beq         $t7, $zero, L_8015EE2C
    if (ctx->r15 == 0) {
        // 0x8015EDFC: nop
    
            goto L_8015EE2C;
    }
    // 0x8015EDFC: nop

    // 0x8015EE00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015EE04: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x8015EE08: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8015EE0C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8015EE10: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8015EE14: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8015EE18: jal         0x800EDF24
    // 0x8015EE1C: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8015EE1C: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    after_0:
    // 0x8015EE20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015EE24: jal         0x8016C954
    // 0x8015EE28: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    wpYoshiStarMakeStars(rdram, ctx);
        goto after_1;
    // 0x8015EE28: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
L_8015EE2C:
    // 0x8015EE2C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8015EE30: addiu       $a1, $a1, -0x1E38
    ctx->r5 = ADD32(ctx->r5, -0X1E38);
    // 0x8015EE34: jal         0x800D9480
    // 0x8015EE38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015EE38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015EE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015EE40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015EE44: jr          $ra
    // 0x8015EE48: nop

    return;
    // 0x8015EE48: nop

;}
RECOMP_FUNC void itBombHeiThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177598: jal         0x80177208
    // 0x8017759C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBombHeiCommonSetHitStatusNormal(rdram, ctx);
        goto after_0;
    // 0x8017759C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801775A0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801775A4: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x801775A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801775AC: jal         0x80172EC8
    // 0x801775B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801775B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x801775B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801775B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801775BC: jr          $ra
    // 0x801775C0: nop

    return;
    // 0x801775C0: nop

;}
RECOMP_FUNC void mvOpeningSamusMakePosedWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D9AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D9B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D9B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D9B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D9BC: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8018D9C0: jal         0x80009968
    // 0x8018D9C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D9C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D9C8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9CC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D9D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D9D4: addiu       $a1, $a1, -0x2750
    ctx->r5 = ADD32(ctx->r5, -0X2750);
    // 0x8018D9D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D9DC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8018D9E0: jal         0x80009DF4
    // 0x8018D9E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D9E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D9EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D9F0: jr          $ra
    // 0x8018D9F4: nop

    return;
    // 0x8018D9F4: nop

;}
RECOMP_FUNC void efManagerPikachuThunderShockMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801018A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801018AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801018B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801018B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801018B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801018BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801018C0: addiu       $a0, $a0, -0x1E04
    ctx->r4 = ADD32(ctx->r4, -0X1E04);
    // 0x801018C4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x801018C8: jal         0x800FDAFC
    // 0x801018CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x801018CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801018D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801018D4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801018D8: bne         $v0, $zero, L_801018E8
    if (ctx->r2 != 0) {
        // 0x801018DC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801018E8;
    }
    // 0x801018DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801018E0: b           L_801019F4
    // 0x801018E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801019F4;
    // 0x801018E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801018E8:
    // 0x801018E8: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x801018EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801018F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801018F4: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x801018F8: lw          $t6, 0x84($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X84);
    // 0x801018FC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80101900: lw          $t7, 0x8E8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8E8);
    // 0x80101904: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x80101908: sw          $t7, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r15;
    // 0x8010190C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80101910: sw          $t0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r8;
    // 0x80101914: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80101918: sw          $t9, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r25;
    // 0x8010191C: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x80101920: sw          $t0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r8;
    // 0x80101924: lw          $t1, 0x84($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X84);
    // 0x80101928: lw          $t2, 0x44($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X44);
    // 0x8010192C: bnel        $t2, $at, L_8010194C
    if (ctx->r10 != ctx->r1) {
        // 0x80101930: lwc1        $f8, 0x0($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
            goto L_8010194C;
    }
    goto skip_0;
    // 0x80101930: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80101934: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80101938: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x8010193C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80101940: b           L_80101954
    // 0x80101944: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
        goto L_80101954;
    // 0x80101944: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
    // 0x80101948: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
L_8010194C:
    // 0x8010194C: lw          $t4, 0x10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X10);
    // 0x80101950: swc1        $f8, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f8.u32l;
L_80101954:
    // 0x80101954: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x80101958: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8010195C: jal         0x80008CC0
    // 0x80101960: lw          $a0, 0x10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X10);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80101960: lw          $a0, 0x10($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X10);
    after_1:
    // 0x80101964: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80101968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010196C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101970: beq         $v1, $at, L_8010198C
    if (ctx->r3 == ctx->r1) {
        // 0x80101974: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8010198C;
    }
    // 0x80101974: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80101978: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010197C: beq         $v1, $at, L_801019C0
    if (ctx->r3 == ctx->r1) {
        // 0x80101980: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801019C0;
    }
    // 0x80101980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101984: b           L_801019F4
    // 0x80101988: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_801019F4;
    // 0x80101988: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8010198C:
    // 0x8010198C: lw          $v0, 0x10C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10C0);
    // 0x80101990: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80101994: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80101998: addiu       $t7, $t7, 0x1AC0
    ctx->r15 = ADD32(ctx->r15, 0X1AC0);
    // 0x8010199C: addiu       $t6, $t6, 0x1850
    ctx->r14 = ADD32(ctx->r14, 0X1850);
    // 0x801019A0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801019A4: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x801019A8: jal         0x8000BED8
    // 0x801019AC: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    gcAddAnimAll(rdram, ctx);
        goto after_2;
    // 0x801019AC: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x801019B0: jal         0x8000DF34
    // 0x801019B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x801019B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801019B8: b           L_801019F4
    // 0x801019BC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_801019F4;
    // 0x801019BC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_801019C0:
    // 0x801019C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801019C4: lw          $v0, 0x10C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10C0);
    // 0x801019C8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801019CC: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801019D0: addiu       $t9, $t9, 0x1B10
    ctx->r25 = ADD32(ctx->r25, 0X1B10);
    // 0x801019D4: addiu       $t8, $t8, 0x1970
    ctx->r24 = ADD32(ctx->r24, 0X1970);
    // 0x801019D8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801019DC: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x801019E0: jal         0x8000BED8
    // 0x801019E4: addu        $a2, $v0, $t9
    ctx->r6 = ADD32(ctx->r2, ctx->r25);
    gcAddAnimAll(rdram, ctx);
        goto after_4;
    // 0x801019E4: addu        $a2, $v0, $t9
    ctx->r6 = ADD32(ctx->r2, ctx->r25);
    after_4:
    // 0x801019E8: jal         0x8000DF34
    // 0x801019EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x801019EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801019F0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_801019F4:
    // 0x801019F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801019F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801019FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80101A00: jr          $ra
    // 0x80101A04: nop

    return;
    // 0x80101A04: nop

;}
RECOMP_FUNC void mvOpeningSectorMakeGreatFox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131F50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131F54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131F58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131F5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F60: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131F64: jal         0x80009968
    // 0x80131F68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131F68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F6C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131F70: lw          $t6, 0x2C00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C00);
    // 0x80131F74: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131F78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131F7C: addiu       $t7, $t7, -0x27E0
    ctx->r15 = ADD32(ctx->r15, -0X27E0);
    // 0x80131F80: sw          $v0, 0x2A1C($at)
    MEM_W(0X2A1C, ctx->r1) = ctx->r2;
    // 0x80131F84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131F88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131F8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131F90: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80131F94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80131F98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80131F9C: jal         0x8000F590
    // 0x80131FA0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_1;
    // 0x80131FA0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131FA4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131FA8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131FAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131FB0: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80131FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FB8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131FBC: jal         0x80009DF4
    // 0x80131FC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131FC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131FC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131FC8: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131FCC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131FD0: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80131FD4: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80131FD8: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80131FDC: addiu       $t3, $t3, -0x25F0
    ctx->r11 = ADD32(ctx->r11, -0X25F0);
    // 0x80131FE0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131FE4: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80131FE8: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80131FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FF0: swc1        $f0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f0.u32l;
    // 0x80131FF4: lw          $t2, 0x2C00($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2C00);
    // 0x80131FF8: jal         0x8000BD8C
    // 0x80131FFC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80131FFC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x80132000: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132004: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80132008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013200C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132010: jal         0x80008188
    // 0x80132014: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80132014: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80132018: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013201C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132024: jr          $ra
    // 0x80132028: nop

    return;
    // 0x80132028: nop

;}
RECOMP_FUNC void func_ovl8_80381908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038190C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80381910: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x80381914: beql        $a1, $zero, L_80381928
    if (ctx->r5 == 0) {
        // 0x80381918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80381928;
    }
    goto skip_0;
    // 0x80381918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8038191C: jal         0x80371764
    // 0x80381920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_ovl8_80371764(rdram, ctx);
        goto after_0;
    // 0x80381920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80381924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80381928:
    // 0x80381928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038192C: jr          $ra
    // 0x80381930: nop

    return;
    // 0x80381930: nop

;}
RECOMP_FUNC void ftFoxSpecialLwLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CD90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015CD94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015CD98: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8015CD9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015CDA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015CDA4: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x8015CDA8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015CDAC: jal         0x800E6F24
    // 0x8015CDB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015CDB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015CDB4: jal         0x8015CD7C
    // 0x8015CDB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialLwLoopSetReflectFlag(rdram, ctx);
        goto after_1;
    // 0x8015CDB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015CDBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015CDC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015CDC4: jr          $ra
    // 0x8015CDC8: nop

    return;
    // 0x8015CDC8: nop

;}
RECOMP_FUNC void func_ovl2_800EBC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBC0C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800EBC10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EBC14: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800EBC18: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800EBC1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EBC20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EBC24: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800EBC28: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800EBC2C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800EBC30: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800EBC34: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800EBC38: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x800EBC3C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800EBC40: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x800EBC44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EBC48: jal         0x800EDF24
    // 0x800EBC4C: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x800EBC4C: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    after_0:
    // 0x800EBC50: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800EBC54: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800EBC58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EBC5C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800EBC60: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800EBC64: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800EBC68: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x800EBC6C: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x800EBC70: jal         0x800EE018
    // 0x800EBC74: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_ovl2_800EE018(rdram, ctx);
        goto after_1;
    // 0x800EBC74: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_1:
    // 0x800EBC78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EBC7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EBC80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EBC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EBC88: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800EBC8C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x800EBC90: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800EBC94: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800EBC98: jal         0x80019980
    // 0x800EBC9C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    syVectorNormCross3D(rdram, ctx);
        goto after_2;
    // 0x800EBC9C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800EBCA0: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800EBCA4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800EBCA8: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x800EBCAC: lw          $v0, 0x84($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X84);
    // 0x800EBCB0: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800EBCB4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800EBCB8: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800EBCBC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800EBCC0: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800EBCC4: jal         0x80018EE0
    // 0x800EBCC8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_3;
    // 0x800EBCC8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x800EBCCC: jal         0x80018EE0
    // 0x800EBCD0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    syVectorNorm3D(rdram, ctx);
        goto after_4;
    // 0x800EBCD0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x800EBCD4: jal         0x80018EE0
    // 0x800EBCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syVectorNorm3D(rdram, ctx);
        goto after_5;
    // 0x800EBCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800EBCDC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800EBCE0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800EBCE4: jal         0x800EBB3C
    // 0x800EBCE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_ovl2_800EBB3C(rdram, ctx);
        goto after_6;
    // 0x800EBCE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x800EBCEC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800EBCF0: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
    // 0x800EBCF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EBCF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EBCFC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800EBD00: jr          $ra
    // 0x800EBD04: nop

    return;
    // 0x800EBD04: nop

;}
RECOMP_FUNC void ifCommonBattleGoUpdateInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011403C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80114040: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80114044: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80114048: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8011404C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80114050: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80114054: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80114058: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8011405C: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80114060: lui         $s6, 0x800A
    ctx->r22 = S32(0X800A << 16);
    // 0x80114064: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80114068: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8011406C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80114070: addiu       $s6, $s6, 0x50E8
    ctx->r22 = ADD32(ctx->r22, 0X50E8);
    // 0x80114074: addiu       $s1, $s1, 0x5228
    ctx->r17 = ADD32(ctx->r17, 0X5228);
    // 0x80114078: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8011407C: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80114080: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80114084: addiu       $s7, $zero, 0x74
    ctx->r23 = ADD32(0, 0X74);
    // 0x80114088: addiu       $fp, $zero, 0xF
    ctx->r30 = ADD32(0, 0XF);
L_8011408C:
    // 0x8011408C: lhu         $t6, 0x2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X2);
    // 0x80114090: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x80114094: beql        $t7, $zero, L_80114274
    if (ctx->r15 == 0) {
        // 0x80114098: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80114274;
    }
    goto skip_0;
    // 0x80114098: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x8011409C: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801140A0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x801140A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801140A8: mflo        $t8
    ctx->r24 = lo;
    // 0x801140AC: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x801140B0: lbu         $a0, 0x22($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X22);
    // 0x801140B4: beq         $s5, $a0, L_80114258
    if (ctx->r21 == ctx->r4) {
        // 0x801140B8: nop
    
            goto L_80114258;
    }
    // 0x801140B8: nop

    // 0x801140BC: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x801140C0: bnel        $fp, $t9, L_801140D4
    if (ctx->r30 != ctx->r25) {
        // 0x801140C4: lw          $s0, 0x78($v1)
        ctx->r16 = MEM_W(ctx->r3, 0X78);
            goto L_801140D4;
    }
    goto skip_1;
    // 0x801140C4: lw          $s0, 0x78($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X78);
    skip_1:
    // 0x801140C8: beq         $a0, $at, L_80114258
    if (ctx->r4 == ctx->r1) {
        // 0x801140CC: nop
    
            goto L_80114258;
    }
    // 0x801140CC: nop

    // 0x801140D0: lw          $s0, 0x78($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X78);
L_801140D4:
    // 0x801140D4: lw          $s2, 0x84($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X84);
    // 0x801140D8: lw          $t0, 0x24($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X24);
    // 0x801140DC: bnel        $s4, $t0, L_801140F8
    if (ctx->r20 != ctx->r8) {
        // 0x801140E0: lw          $t1, 0x190($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X190);
            goto L_801140F8;
    }
    goto skip_2;
    // 0x801140E0: lw          $t1, 0x190($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X190);
    skip_2:
    // 0x801140E4: jal         0x8013D580
    // 0x801140E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSleepCheckIgnorePauseMenu(rdram, ctx);
        goto after_0;
    // 0x801140E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801140EC: bnel        $v0, $zero, L_80114274
    if (ctx->r2 != 0) {
        // 0x801140F0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80114274;
    }
    goto skip_3;
    // 0x801140F0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_3:
    // 0x801140F4: lw          $t1, 0x190($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X190);
L_801140F8:
    // 0x801140F8: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x801140FC: bltz        $t3, L_80114258
    if (SIGNED(ctx->r11) < 0) {
        // 0x80114100: nop
    
            goto L_80114258;
    }
    // 0x80114100: nop

    // 0x80114104: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x80114108: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8011410C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80114110: bnel        $s5, $t5, L_801141B4
    if (ctx->r21 != ctx->r13) {
        // 0x80114114: lw          $a0, 0x74($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X74);
            goto L_801141B4;
    }
    goto skip_4;
    // 0x80114114: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    skip_4:
    // 0x80114118: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8011411C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80114120: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80114124: lh          $t6, 0x9A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X9A);
    // 0x80114128: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8011412C: nop

    // 0x80114130: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80114134: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x80114138: lh          $t7, 0x9C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X9C);
    // 0x8011413C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80114140: nop

    // 0x80114144: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80114148: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x8011414C: lh          $t8, 0x9E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X9E);
    // 0x80114150: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80114154: nop

    // 0x80114158: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8011415C: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x80114160: lh          $t9, 0xA0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA0);
    // 0x80114164: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80114168: nop

    // 0x8011416C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80114170: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80114174: lh          $t0, 0xA2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA2);
    // 0x80114178: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8011417C: nop

    // 0x80114180: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80114184: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80114188: lh          $t1, 0xA4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XA4);
    // 0x8011418C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80114190: nop

    // 0x80114194: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80114198: jal         0x8010D0A4
    // 0x8011419C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    gmCameraSetStatusMapZoom(rdram, ctx);
        goto after_1;
    // 0x8011419C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801141A0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801141A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801141A8: b           L_80114248
    // 0x801141AC: sb          $t2, 0x1828($at)
    MEM_B(0X1828, ctx->r1) = ctx->r10;
        goto L_80114248;
    // 0x801141AC: sb          $t2, 0x1828($at)
    MEM_B(0X1828, ctx->r1) = ctx->r10;
    // 0x801141B0: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
L_801141B4:
    // 0x801141B4: jal         0x8010CA7C
    // 0x801141B8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    gmCameraCheckPausePlayerOutBounds(rdram, ctx);
        goto after_2;
    // 0x801141B8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x801141BC: beq         $v0, $zero, L_801141D0
    if (ctx->r2 == 0) {
        // 0x801141C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801141D0;
    }
    // 0x801141C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801141C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801141C8: b           L_80114248
    // 0x801141CC: sb          $zero, 0x1828($at)
    MEM_B(0X1828, ctx->r1) = 0;
        goto L_80114248;
    // 0x801141CC: sb          $zero, 0x1828($at)
    MEM_B(0X1828, ctx->r1) = 0;
L_801141D0:
    // 0x801141D0: lw          $t3, 0x84($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X84);
    // 0x801141D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801141D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801141DC: lwc1        $f4, 0xC90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC90);
    // 0x801141E0: lw          $t4, 0x9C8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X9C8);
    // 0x801141E4: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x801141E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801141EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801141F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801141F4: lw          $a3, 0x90($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X90);
    // 0x801141F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801141FC: jal         0x8010CF44
    // 0x80114200: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    gmCameraSetStatusPlayerZoom(rdram, ctx);
        goto after_3;
    // 0x80114200: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80114204: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114208: lwc1        $f8, 0x1468($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1468);
    // 0x8011420C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114210: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80114214: swc1        $f8, 0x17E8($at)
    MEM_W(0X17E8, ctx->r1) = ctx->f8.u32l;
    // 0x80114218: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011421C: lwc1        $f10, 0x1464($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1464);
    // 0x80114220: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80114228: swc1        $f10, 0x17EC($at)
    MEM_W(0X17EC, ctx->r1) = ctx->f10.u32l;
    // 0x8011422C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114230: sb          $t5, 0x1828($at)
    MEM_B(0X1828, ctx->r1) = ctx->r13;
    // 0x80114234: lbu         $t6, 0xE($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0XE);
    // 0x80114238: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011423C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80114240: jal         0x800E9198
    // 0x80114244: sb          $t6, 0x17E5($at)
    MEM_B(0X17E5, ctx->r1) = ctx->r14;
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_4;
    // 0x80114244: sb          $t6, 0x17E5($at)
    MEM_B(0X17E5, ctx->r1) = ctx->r14;
    after_4:
L_80114248:
    // 0x80114248: jal         0x80113FC4
    // 0x8011424C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    ifCommonBattlePauseInitInterface(rdram, ctx);
        goto after_5;
    // 0x8011424C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80114250: b           L_80114288
    // 0x80114254: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80114288;
    // 0x80114254: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80114258:
    // 0x80114258: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011425C: sb          $zero, 0x1828($at)
    MEM_B(0X1828, ctx->r1) = 0;
    // 0x80114260: jal         0x80113FC4
    // 0x80114264: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    ifCommonBattlePauseInitInterface(rdram, ctx);
        goto after_6;
    // 0x80114264: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x80114268: b           L_80114288
    // 0x8011426C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80114288;
    // 0x8011426C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80114270: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80114274:
    // 0x80114274: bne         $s3, $s4, L_8011408C
    if (ctx->r19 != ctx->r20) {
        // 0x80114278: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_8011408C;
    }
    // 0x80114278: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x8011427C: jal         0x8000A5E4
    // 0x80114280: nop

    gcRunAll(rdram, ctx);
        goto after_7;
    // 0x80114280: nop

    after_7:
    // 0x80114284: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80114288:
    // 0x80114288: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8011428C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80114290: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80114294: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80114298: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8011429C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x801142A0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x801142A4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x801142A8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x801142AC: jr          $ra
    // 0x801142B0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801142B0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_ovl2_800EDA0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDA0C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800EDA10: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800EDA14: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800EDA18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EDA1C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800EDA20: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800EDA24: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800EDA28: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800EDA2C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800EDA30: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800EDA34: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800EDA38: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800EDA3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EDA40: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x800EDA44: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_800EDA48:
    // 0x800EDA48: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EDA4C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EDA50: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800EDA54: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EDA58: nop

    // 0x800EDA5C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EDA60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EDA64: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EDA68: jal         0x80033510
    // 0x800EDA6C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EDA6C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x800EDA70: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800EDA74: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800EDA78: bc1tl       L_800EDA88
    if (c1cs) {
        // 0x800EDA7C: lwc1        $f16, 0x0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
            goto L_800EDA88;
    }
    goto skip_0;
    // 0x800EDA7C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800EDA80: div.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800EDA84: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
L_800EDA88:
    // 0x800EDA88: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800EDA8C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800EDA90: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800EDA94: swc1        $f18, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->f18.u32l;
    // 0x800EDA98: lwc1        $f4, -0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0XC);
    // 0x800EDA9C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800EDAA0: swc1        $f6, -0xC($s1)
    MEM_W(-0XC, ctx->r17) = ctx->f6.u32l;
    // 0x800EDAA4: lwc1        $f10, -0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, -0X8);
    // 0x800EDAA8: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800EDAAC: bne         $s1, $s2, L_800EDA48
    if (ctx->r17 != ctx->r18) {
        // 0x800EDAB0: swc1        $f8, -0x8($s1)
        MEM_W(-0X8, ctx->r17) = ctx->f8.u32l;
            goto L_800EDA48;
    }
    // 0x800EDAB0: swc1        $f8, -0x8($s1)
    MEM_W(-0X8, ctx->r17) = ctx->f8.u32l;
    // 0x800EDAB4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800EDAB8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800EDABC: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EDAC0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800EDAC4: nop

    // 0x800EDAC8: bc1tl       L_800EDAE4
    if (c1cs) {
        // 0x800EDACC: c.eq.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
            goto L_800EDAE4;
    }
    goto skip_1;
    // 0x800EDACC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    skip_1:
    // 0x800EDAD0: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x800EDAD4: nop

    // 0x800EDAD8: bc1f        L_800EDB38
    if (!c1cs) {
        // 0x800EDADC: nop
    
            goto L_800EDB38;
    }
    // 0x800EDADC: nop

    // 0x800EDAE0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
L_800EDAE4:
    // 0x800EDAE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EDAE8: bc1f        L_800EDB10
    if (!c1cs) {
        // 0x800EDAEC: nop
    
            goto L_800EDB10;
    }
    // 0x800EDAEC: nop

    // 0x800EDAF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EDAF4: lwc1        $f16, 0x240($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X240);
    // 0x800EDAF8: swc1        $f16, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f16.u32l;
    // 0x800EDAFC: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800EDB00: jal         0x8001863C
    // 0x800EDB04: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x800EDB04: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x800EDB08: b           L_800EDB2C
    // 0x800EDB0C: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
        goto L_800EDB2C;
    // 0x800EDB0C: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
L_800EDB10:
    // 0x800EDB10: lwc1        $f18, 0x244($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X244);
    // 0x800EDB14: swc1        $f18, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f18.u32l;
    // 0x800EDB18: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800EDB1C: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800EDB20: jal         0x8001863C
    // 0x800EDB24: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_2;
    // 0x800EDB24: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x800EDB28: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
L_800EDB2C:
    // 0x800EDB2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EDB30: b           L_800EDB64
    // 0x800EDB34: swc1        $f4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f4.u32l;
        goto L_800EDB64;
    // 0x800EDB34: swc1        $f4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f4.u32l;
L_800EDB38:
    // 0x800EDB38: jal         0x8001873C
    // 0x800EDB3C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    syUtilsArcSin(rdram, ctx);
        goto after_3;
    // 0x800EDB3C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_3:
    // 0x800EDB40: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x800EDB44: lwc1        $f14, 0x70($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EDB48: jal         0x8001863C
    // 0x800EDB4C: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    syUtilsArcTan2(rdram, ctx);
        goto after_4;
    // 0x800EDB4C: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    after_4:
    // 0x800EDB50: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x800EDB54: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EDB58: jal         0x8001863C
    // 0x800EDB5C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    syUtilsArcTan2(rdram, ctx);
        goto after_5;
    // 0x800EDB5C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_5:
    // 0x800EDB60: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
L_800EDB64:
    // 0x800EDB64: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800EDB68: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800EDB6C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800EDB70: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800EDB74: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800EDB78: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800EDB7C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800EDB80: jr          $ra
    // 0x800EDB84: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800EDB84: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156ABC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80156AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156AC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80156AC8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80156ACC: jal         0x800DEE98
    // 0x80156AD0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80156AD0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80156AD4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80156AD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80156ADC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80156AE0: lw          $v0, 0xADC($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XADC);
    // 0x80156AE4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80156AE8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80156AEC: beq         $v0, $zero, L_80156B04
    if (ctx->r2 == 0) {
        // 0x80156AF0: nop
    
            goto L_80156B04;
    }
    // 0x80156AF0: nop

    // 0x80156AF4: beq         $v0, $at, L_80156B04
    if (ctx->r2 == ctx->r1) {
        // 0x80156AF8: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80156B04;
    }
    // 0x80156AF8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80156AFC: bne         $v0, $at, L_80156B0C
    if (ctx->r2 != ctx->r1) {
        // 0x80156B00: addiu       $a1, $zero, 0xE9
        ctx->r5 = ADD32(0, 0XE9);
            goto L_80156B0C;
    }
    // 0x80156B00: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
L_80156B04:
    // 0x80156B04: b           L_80156B0C
    // 0x80156B08: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
        goto L_80156B0C;
    // 0x80156B08: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
L_80156B0C:
    // 0x80156B0C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80156B10: jal         0x800E6F24
    // 0x80156B14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80156B14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x80156B18: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80156B1C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80156B20: addiu       $t9, $t9, 0x69D4
    ctx->r25 = ADD32(ctx->r25, 0X69D4);
    // 0x80156B24: sw          $t9, 0x9D8($t0)
    MEM_W(0X9D8, ctx->r8) = ctx->r25;
    // 0x80156B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80156B2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156B30: jr          $ra
    // 0x80156B34: nop

    return;
    // 0x80156B34: nop

;}
RECOMP_FUNC void ftMarioSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80155F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155F30: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155F34: jal         0x800DE6E4
    // 0x80155F38: addiu       $a1, $a1, 0x5F4C
    ctx->r5 = ADD32(ctx->r5, 0X5F4C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80155F38: addiu       $a1, $a1, 0x5F4C
    ctx->r5 = ADD32(ctx->r5, 0X5F4C);
    after_0:
    // 0x80155F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155F44: jr          $ra
    // 0x80155F48: nop

    return;
    // 0x80155F48: nop

;}
RECOMP_FUNC void ftCommonPassSetStatusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141DA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80141DA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80141DA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80141DAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80141DB0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80141DB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80141DB8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80141DBC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80141DC0: jal         0x800DEEC8
    // 0x80141DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80141DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80141DC8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80141DCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80141DD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80141DD4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80141DD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80141DDC: jal         0x800E6F24
    // 0x80141DE0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80141DE0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x80141DE4: jal         0x800D8EB8
    // 0x80141DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80141DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80141DEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80141DF0: lw          $t8, 0xEC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XEC);
    // 0x80141DF4: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x80141DF8: sb          $t9, 0x269($s0)
    MEM_B(0X269, ctx->r16) = ctx->r25;
    // 0x80141DFC: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x80141E00: sw          $t8, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->r24;
    // 0x80141E04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80141E08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80141E0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80141E10: jr          $ra
    // 0x80141E14: nop

    return;
    // 0x80141E14: nop

;}
RECOMP_FUNC void itMapCheckDestroyDropped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173B24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80173B28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80173B2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80173B30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80173B34: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80173B38: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80173B3C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80173B40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80173B44: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80173B48: jal         0x801737B8
    // 0x80173B4C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80173B4C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_0:
    // 0x80173B50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80173B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80173B58: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80173B5C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80173B60: jal         0x801737EC
    // 0x80173B64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_1;
    // 0x80173B64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80173B68: beql        $v0, $zero, L_80173B7C
    if (ctx->r2 == 0) {
        // 0x80173B6C: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_80173B7C;
    }
    goto skip_0;
    // 0x80173B6C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80173B70: jal         0x80172508
    // 0x80173B74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_2;
    // 0x80173B74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80173B78: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80173B7C:
    // 0x80173B7C: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x80173B80: addiu       $a1, $s0, 0xB8
    ctx->r5 = ADD32(ctx->r16, 0XB8);
    // 0x80173B84: beql        $t6, $zero, L_80173C54
    if (ctx->r14 == 0) {
        // 0x80173B88: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80173C54;
    }
    goto skip_1;
    // 0x80173B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80173B8C: jal         0x80173A48
    // 0x80173B90: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    itMapSetGroundRebound(rdram, ctx);
        goto after_3;
    // 0x80173B90: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80173B94: jal         0x80172508
    // 0x80173B98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_4;
    // 0x80173B98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80173B9C: lw          $t7, 0x2CC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2CC);
    // 0x80173BA0: lbu         $t3, 0x2CE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2CE);
    // 0x80173BA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80173BA8: sll         $t8, $t7, 18
    ctx->r24 = S32(ctx->r15 << 18);
    // 0x80173BAC: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80173BB0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80173BB4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80173BB8: andi        $t2, $t1, 0x30
    ctx->r10 = ctx->r9 & 0X30;
    // 0x80173BBC: andi        $t4, $t3, 0xFFCF
    ctx->r12 = ctx->r11 & 0XFFCF;
    // 0x80173BC0: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80173BC4: sb          $t5, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r13;
    // 0x80173BC8: lw          $v0, 0x2CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2CC);
    // 0x80173BCC: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80173BD0: sll         $t6, $v0, 18
    ctx->r14 = S32(ctx->r2 << 18);
    // 0x80173BD4: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x80173BD8: bnel        $t7, $at, L_80173C28
    if (ctx->r15 != ctx->r1) {
        // 0x80173BDC: lw          $t0, 0x2CC($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X2CC);
            goto L_80173C28;
    }
    goto skip_2;
    // 0x80173BDC: lw          $t0, 0x2CC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2CC);
    skip_2:
    // 0x80173BE0: lw          $t8, 0x50E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50E8);
    // 0x80173BE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80173BE8: sll         $v1, $v0, 20
    ctx->r3 = S32(ctx->r2 << 20);
    // 0x80173BEC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80173BF0: srl         $v1, $v1, 29
    ctx->r3 = S32(U32(ctx->r3) >> 29);
    // 0x80173BF4: beql        $t9, $at, L_80173C28
    if (ctx->r25 == ctx->r1) {
        // 0x80173BF8: lw          $t0, 0x2CC($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X2CC);
            goto L_80173C28;
    }
    goto skip_3;
    // 0x80173BF8: lw          $t0, 0x2CC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2CC);
    skip_3:
    // 0x80173BFC: beq         $v1, $zero, L_80173C24
    if (ctx->r3 == 0) {
        // 0x80173C00: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80173C24;
    }
    // 0x80173C00: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80173C04: beq         $v1, $at, L_80173C1C
    if (ctx->r3 == ctx->r1) {
        // 0x80173C08: nop
    
            goto L_80173C1C;
    }
    // 0x80173C08: nop

    // 0x80173C0C: jal         0x80018994
    // 0x80173C10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_5;
    // 0x80173C10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x80173C14: bnel        $v0, $zero, L_80173C28
    if (ctx->r2 != 0) {
        // 0x80173C18: lw          $t0, 0x2CC($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X2CC);
            goto L_80173C28;
    }
    goto skip_4;
    // 0x80173C18: lw          $t0, 0x2CC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2CC);
    skip_4:
L_80173C1C:
    // 0x80173C1C: b           L_80173C54
    // 0x80173C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80173C54;
    // 0x80173C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80173C24:
    // 0x80173C24: lw          $t0, 0x2CC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2CC);
L_80173C28:
    // 0x80173C28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80173C2C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80173C30: sll         $t1, $t0, 18
    ctx->r9 = S32(ctx->r8 << 18);
    // 0x80173C34: srl         $t3, $t1, 30
    ctx->r11 = S32(U32(ctx->r9) >> 30);
    // 0x80173C38: bnel        $t3, $at, L_80173C54
    if (ctx->r11 != ctx->r1) {
        // 0x80173C3C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80173C54;
    }
    goto skip_5;
    // 0x80173C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80173C40: beql        $v0, $zero, L_80173C54
    if (ctx->r2 == 0) {
        // 0x80173C44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80173C54;
    }
    goto skip_6;
    // 0x80173C44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x80173C48: jalr        $v0
    // 0x80173C4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80173C4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80173C50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173C54:
    // 0x80173C54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80173C58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80173C5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80173C60: jr          $ra
    // 0x80173C64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80173C64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnVSResultsMakePointsRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135DCC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80135DD0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80135DD4: lw          $t9, -0x5FB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5FB8);
    // 0x80135DD8: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80135DDC: addiu       $t0, $t0, 0x10D8
    ctx->r8 = ADD32(ctx->r8, 0X10D8);
    // 0x80135DE0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135DE4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80135DE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80135DEC: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x80135DF0: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x80135DF4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80135DF8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135DFC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80135E00: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80135E04: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80135E08: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80135E0C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80135E10: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80135E14: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80135E18: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80135E1C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135E20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135E24: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80135E28: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80135E2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135E34: jal         0x800CD050
    // 0x80135E38: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80135E38: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x80135E3C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80135E40: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80135E44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135E48: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80135E4C: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x80135E50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135E54: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x80135E58: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80135E5C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80135E60: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
    // 0x80135E64: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135E68: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80135E6C: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80135E70: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x80135E74: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135E78: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135E7C: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80135E80: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80135E84: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80135E88: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x80135E8C: sb          $zero, 0x28($t0)
    MEM_B(0X28, ctx->r8) = 0;
    // 0x80135E90: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x80135E94: sb          $zero, 0x29($t1)
    MEM_B(0X29, ctx->r9) = 0;
    // 0x80135E98: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x80135E9C: sb          $zero, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = 0;
    // 0x80135EA0: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x80135EA4: sb          $a0, 0x28($t3)
    MEM_B(0X28, ctx->r11) = ctx->r4;
    // 0x80135EA8: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80135EAC: sb          $a0, 0x29($t4)
    MEM_B(0X29, ctx->r12) = ctx->r4;
    // 0x80135EB0: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80135EB4: sb          $a0, 0x2A($t5)
    MEM_B(0X2A, ctx->r13) = ctx->r4;
    // 0x80135EB8: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80135EBC: beq         $t6, $zero, L_80135EFC
    if (ctx->r14 == 0) {
        // 0x80135EC0: nop
    
            goto L_80135EFC;
    }
    // 0x80135EC0: nop

    // 0x80135EC4: jal         0x801352FC
    // 0x80135EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_1;
    // 0x80135EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80135ECC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135ED0: jal         0x80135DB8
    // 0x80135ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetPoints(rdram, ctx);
        goto after_2;
    // 0x80135ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80135ED8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135EDC: jal         0x801353F4
    // 0x80135EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_3;
    // 0x80135EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80135EE4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135EE8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80135EEC: lui         $a2, 0x42D0
    ctx->r6 = S32(0X42D0 << 16);
    // 0x80135EF0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135EF4: jal         0x80134AC4
    // 0x80135EF8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_4;
    // 0x80135EF8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
L_80135EFC:
    // 0x80135EFC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135F00: lw          $t7, -0x642C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X642C);
    // 0x80135F04: beq         $t7, $zero, L_80135F44
    if (ctx->r15 == 0) {
        // 0x80135F08: nop
    
            goto L_80135F44;
    }
    // 0x80135F08: nop

    // 0x80135F0C: jal         0x801352FC
    // 0x80135F10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_5;
    // 0x80135F10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80135F14: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135F18: jal         0x80135DB8
    // 0x80135F1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetPoints(rdram, ctx);
        goto after_6;
    // 0x80135F1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80135F20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135F24: jal         0x801353F4
    // 0x80135F28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_7;
    // 0x80135F28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80135F2C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135F30: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80135F34: lui         $a2, 0x42D0
    ctx->r6 = S32(0X42D0 << 16);
    // 0x80135F38: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135F3C: jal         0x80134AC4
    // 0x80135F40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_8;
    // 0x80135F40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
L_80135F44:
    // 0x80135F44: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80135F48: lw          $t8, -0x6428($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6428);
    // 0x80135F4C: beq         $t8, $zero, L_80135F8C
    if (ctx->r24 == 0) {
        // 0x80135F50: nop
    
            goto L_80135F8C;
    }
    // 0x80135F50: nop

    // 0x80135F54: jal         0x801352FC
    // 0x80135F58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_9;
    // 0x80135F58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x80135F5C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135F60: jal         0x80135DB8
    // 0x80135F64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetPoints(rdram, ctx);
        goto after_10;
    // 0x80135F64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80135F68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135F6C: jal         0x801353F4
    // 0x80135F70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_11;
    // 0x80135F70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80135F74: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135F78: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80135F7C: lui         $a2, 0x42D0
    ctx->r6 = S32(0X42D0 << 16);
    // 0x80135F80: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135F84: jal         0x80134AC4
    // 0x80135F88: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_12;
    // 0x80135F88: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_12:
L_80135F8C:
    // 0x80135F8C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80135F90: lw          $t9, -0x6424($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6424);
    // 0x80135F94: beql        $t9, $zero, L_80135FD8
    if (ctx->r25 == 0) {
        // 0x80135F98: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80135FD8;
    }
    goto skip_0;
    // 0x80135F98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80135F9C: jal         0x801352FC
    // 0x80135FA0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_13;
    // 0x80135FA0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80135FA4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135FA8: jal         0x80135DB8
    // 0x80135FAC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetPoints(rdram, ctx);
        goto after_14;
    // 0x80135FAC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x80135FB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135FB4: jal         0x801353F4
    // 0x80135FB8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_15;
    // 0x80135FB8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_15:
    // 0x80135FBC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135FC0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80135FC4: lui         $a2, 0x42D0
    ctx->r6 = S32(0X42D0 << 16);
    // 0x80135FC8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135FCC: jal         0x80134AC4
    // 0x80135FD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_16;
    // 0x80135FD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_16:
    // 0x80135FD4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80135FD8:
    // 0x80135FD8: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80135FDC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80135FE0: jr          $ra
    // 0x80135FE4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80135FE4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void sc1PIntroFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134B38: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80134B3C: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80134B40: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80134B44: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134B48: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80134B4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80134B50: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80134B54: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80134B58: addiu       $t8, $t8, 0x5D38
    ctx->r24 = ADD32(ctx->r24, 0X5D38);
    // 0x80134B5C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80134B60: addiu       $t0, $t0, 0x5D00
    ctx->r8 = ADD32(ctx->r8, 0X5D00);
    // 0x80134B64: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80134B68: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80134B6C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80134B70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80134B74: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80134B78: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80134B7C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80134B80: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80134B84: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80134B88: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80134B8C: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80134B90: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80134B94: jal         0x800CDF78
    // 0x80134B98: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80134B98: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80134B9C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80134BA0: addiu       $s0, $s0, 0x4DF0
    ctx->r16 = ADD32(ctx->r16, 0X4DF0);
    // 0x80134BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134BA8: jal         0x800CDEEC
    // 0x80134BAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80134BAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80134BB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134BB4: jal         0x80004980
    // 0x80134BB8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80134BB8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80134BBC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80134BC0: addiu       $a2, $a2, 0x6058
    ctx->r6 = ADD32(ctx->r6, 0X6058);
    // 0x80134BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134BC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80134BCC: jal         0x800CDE04
    // 0x80134BD0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80134BD0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80134BD4: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80134BD8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134BDC: addiu       $a1, $a1, 0x48F4
    ctx->r5 = ADD32(ctx->r5, 0X48F4);
    // 0x80134BE0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80134BE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134BE8: jal         0x80009968
    // 0x80134BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80134BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80134BF0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80134BF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80134BF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134BFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80134C00: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80134C04: jal         0x8000B9FC
    // 0x80134C08: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80134C08: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80134C0C: jal         0x80134810
    // 0x80134C10: nop

    sc1PIntroInitVars(rdram, ctx);
        goto after_6;
    // 0x80134C10: nop

    after_6:
    // 0x80134C14: jal         0x80115890
    // 0x80134C18: nop

    efParticleInitAll(rdram, ctx);
        goto after_7;
    // 0x80134C18: nop

    after_7:
    // 0x80134C1C: jal         0x800FD300
    // 0x80134C20: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x80134C20: nop

    after_8:
    // 0x80134C24: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80134C28: addiu       $s2, $s2, 0x5C28
    ctx->r18 = ADD32(ctx->r18, 0X5C28);
    // 0x80134C2C: jal         0x8013456C
    // 0x80134C30: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroGetFighterAllocsNum(rdram, ctx);
        goto after_9;
    // 0x80134C30: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x80134C34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80134C38: jal         0x800D7194
    // 0x80134C3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftManagerAllocFighter(rdram, ctx);
        goto after_10;
    // 0x80134C3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80134C40: jal         0x801349F8
    // 0x80134C44: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroSetupFighterFiles(rdram, ctx);
        goto after_11;
    // 0x80134C44: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_11:
    // 0x80134C48: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80134C4C: jal         0x8013456C
    // 0x80134C50: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroGetFighterAllocsNum(rdram, ctx);
        goto after_12;
    // 0x80134C50: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_12:
    // 0x80134C54: blez        $v0, L_80134C98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80134C58: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80134C98;
    }
    // 0x80134C58: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80134C5C: addiu       $t4, $t4, 0x5C38
    ctx->r12 = ADD32(ctx->r12, 0X5C38);
    // 0x80134C60: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80134C64: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
L_80134C68:
    // 0x80134C68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134C6C: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x80134C70: jal         0x80004980
    // 0x80134C74: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_13;
    // 0x80134C74: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_13:
    // 0x80134C78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80134C7C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80134C80: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80134C84: jal         0x8013456C
    // 0x80134C88: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    sc1PIntroGetFighterAllocsNum(rdram, ctx);
        goto after_14;
    // 0x80134C88: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    after_14:
    // 0x80134C8C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80134C90: bne         $at, $zero, L_80134C68
    if (ctx->r1 != 0) {
        // 0x80134C94: nop
    
            goto L_80134C68;
    }
    // 0x80134C94: nop

L_80134C98:
    // 0x80134C98: jal         0x801344CC
    // 0x80134C9C: nop

    sc1PIntroMakePicturesCamera(rdram, ctx);
        goto after_15;
    // 0x80134C9C: nop

    after_15:
    // 0x80134CA0: jal         0x8013442C
    // 0x80134CA4: nop

    sc1PIntroMakeDecalsCamera(rdram, ctx);
        goto after_16;
    // 0x80134CA4: nop

    after_16:
    // 0x80134CA8: jal         0x8013438C
    // 0x80134CAC: nop

    sc1PIntroMakeBannersCamera(rdram, ctx);
        goto after_17;
    // 0x80134CAC: nop

    after_17:
    // 0x80134CB0: jal         0x80131B24
    // 0x80134CB4: nop

    sc1PIntroMakeSky(rdram, ctx);
        goto after_18;
    // 0x80134CB4: nop

    after_18:
    // 0x80134CB8: jal         0x80131BA8
    // 0x80134CBC: nop

    sc1PIntroMakeBanners(rdram, ctx);
        goto after_19;
    // 0x80134CBC: nop

    after_19:
    // 0x80134CC0: jal         0x80131F6C
    // 0x80134CC4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroCheckNotBonusStage(rdram, ctx);
        goto after_20;
    // 0x80134CC4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_20:
    // 0x80134CC8: beq         $v0, $zero, L_80134CE0
    if (ctx->r2 == 0) {
        // 0x80134CCC: nop
    
            goto L_80134CE0;
    }
    // 0x80134CCC: nop

    // 0x80134CD0: jal         0x80131ED4
    // 0x80134CD4: nop

    sc1PIntroMakeVSDecal(rdram, ctx);
        goto after_21;
    // 0x80134CD4: nop

    after_21:
    // 0x80134CD8: b           L_80134CE8
    // 0x80134CDC: nop

        goto L_80134CE8;
    // 0x80134CDC: nop

L_80134CE0:
    // 0x80134CE0: jal         0x8013357C
    // 0x80134CE4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroMakeBonusPicture(rdram, ctx);
        goto after_22;
    // 0x80134CE4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_22:
L_80134CE8:
    // 0x80134CE8: jal         0x80131F98
    // 0x80134CEC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroMakeLabels(rdram, ctx);
        goto after_23;
    // 0x80134CEC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_23:
    // 0x80134CF0: jal         0x801321C0
    // 0x80134CF4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroMakeFigures(rdram, ctx);
        goto after_24;
    // 0x80134CF4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_24:
    // 0x80134CF8: jal         0x80132B40
    // 0x80134CFC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroMakeStageInfo(rdram, ctx);
        goto after_25;
    // 0x80134CFC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_25:
    // 0x80134D00: jal         0x80131F6C
    // 0x80134D04: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroCheckNotBonusStage(rdram, ctx);
        goto after_26;
    // 0x80134D04: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_26:
    // 0x80134D08: beql        $v0, $zero, L_80134D24
    if (ctx->r2 == 0) {
        // 0x80134D0C: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_80134D24;
    }
    goto skip_0;
    // 0x80134D0C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    skip_0:
    // 0x80134D10: jal         0x80134190
    // 0x80134D14: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroInitFighters(rdram, ctx);
        goto after_27;
    // 0x80134D14: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_27:
    // 0x80134D18: jal         0x80133AC8
    // 0x80134D1C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    sc1PIntroInitVSFighters(rdram, ctx);
        goto after_28;
    // 0x80134D1C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_28:
    // 0x80134D20: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
L_80134D24:
    // 0x80134D24: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80134D28: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80134D2C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80134D30: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80134D34: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80134D38: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80134D3C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80134D40: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80134D44: jal         0x803904E0
    // 0x80134D48: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_29;
    // 0x80134D48: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_29:
    // 0x80134D4C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80134D50: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80134D54: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80134D58: bne         $t7, $at, L_80134D70
    if (ctx->r15 != ctx->r1) {
        // 0x80134D5C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80134D70;
    }
    // 0x80134D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134D60: jal         0x80020AB4
    // 0x80134D64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioPlayBGM(rdram, ctx);
        goto after_30;
    // 0x80134D64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_30:
    // 0x80134D68: b           L_80134D78
    // 0x80134D6C: nop

        goto L_80134D78;
    // 0x80134D6C: nop

L_80134D70:
    // 0x80134D70: jal         0x80020AB4
    // 0x80134D74: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    syAudioPlayBGM(rdram, ctx);
        goto after_31;
    // 0x80134D74: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_31:
L_80134D78:
    // 0x80134D78: jal         0x80000920
    // 0x80134D7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sySchedulerSetTicCount(rdram, ctx);
        goto after_32;
    // 0x80134D7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_32:
    // 0x80134D80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80134D84: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80134D88: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80134D8C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80134D90: jr          $ra
    // 0x80134D94: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80134D94: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftCommonSquatWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014329C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801432A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801432A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801432A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801432AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801432B0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x801432B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801432B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801432BC: jal         0x800E6F24
    // 0x801432C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801432C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801432C4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801432C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801432CC: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801432D0: lbu         $t7, 0x192($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X192);
    // 0x801432D4: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x801432D8: jal         0x800E7F7C
    // 0x801432DC: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_1;
    // 0x801432DC: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    after_1:
    // 0x801432E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801432E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801432E8: jr          $ra
    // 0x801432EC: nop

    return;
    // 0x801432EC: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNSetStatusSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80150ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150ED8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80150EDC: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80150EE0: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x80150EE4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80150EE8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80150EEC: lw          $t9, -0x75B0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X75B0);
    // 0x80150EF0: jalr        $t9
    // 0x80150EF4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80150EF4: nop

    after_0:
    // 0x80150EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80150F00: jr          $ra
    // 0x80150F04: nop

    return;
    // 0x80150F04: nop

;}
RECOMP_FUNC void mnVSRecordMakeRankingHighlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013486C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134870: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134878: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8013487C: jal         0x80009968
    // 0x80134880: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134880: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134884: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134888: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013488C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134890: addiu       $a1, $a1, 0x46D8
    ctx->r5 = ADD32(ctx->r5, 0X46D8);
    // 0x80134894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134898: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013489C: jal         0x80009DF4
    // 0x801348A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801348A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801348A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801348A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801348AC: jr          $ra
    // 0x801348B0: nop

    return;
    // 0x801348B0: nop

;}
RECOMP_FUNC void ftCommonThrownCopyStarProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C65C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C660: lui         $a1, 0x40A6
    ctx->r5 = S32(0X40A6 << 16);
    // 0x8014C664: jal         0x8014BF04
    // 0x8014C668: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    ftCommonThrownCommonStarUpdatePhysics(rdram, ctx);
        goto after_0;
    // 0x8014C668: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_0:
    // 0x8014C66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C674: jr          $ra
    // 0x8014C678: nop

    return;
    // 0x8014C678: nop

;}
RECOMP_FUNC void func_ovl8_80371ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371ABC: jr          $ra
    // 0x80371AC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371AC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void ftParamInitAllParts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9248: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800E924C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800E9250: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800E9254: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800E9258: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800E925C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800E9260: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800E9264: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800E9268: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800E926C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800E9270: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E9274: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800E9278: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800E927C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800E9280: lw          $s5, 0x84($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X84);
    // 0x800E9284: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800E9288: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800E928C: lw          $t8, 0x9C8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X9C8);
    // 0x800E9290: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E9294: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E9298: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800E929C: or          $s6, $s5, $zero
    ctx->r22 = ctx->r21 | 0;
    // 0x800E92A0: lw          $fp, 0x2D4($t8)
    ctx->r30 = MEM_W(ctx->r24, 0X2D4);
    // 0x800E92A4: lw          $s3, 0x32C($t8)
    ctx->r19 = MEM_W(ctx->r24, 0X32C);
L_800E92A8:
    // 0x800E92A8: lw          $s1, 0x8F8($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X8F8);
    // 0x800E92AC: beql        $s1, $zero, L_800E9450
    if (ctx->r17 == 0) {
        // 0x800E92B0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E9450;
    }
    goto skip_0;
    // 0x800E92B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800E92B4: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    // 0x800E92B8: addu        $s0, $s5, $t9
    ctx->r16 = ADD32(ctx->r21, ctx->r25);
    // 0x800E92BC: jal         0x800091F4
    // 0x800E92C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcRemoveMObjAll(rdram, ctx);
        goto after_0;
    // 0x800E92C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800E92C4: lb          $t0, 0x97D($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X97D);
    // 0x800E92C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E92CC: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800E92D0: beq         $t0, $at, L_800E93C8
    if (ctx->r8 == ctx->r1) {
        // 0x800E92D4: nop
    
            goto L_800E93C8;
    }
    // 0x800E92D4: nop

    // 0x800E92D8: lw          $t2, 0x328($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X328);
    // 0x800E92DC: mtc1        $s7, $f4
    ctx->f4.u32l = ctx->r23;
    // 0x800E92E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E92E4: addu        $t3, $t2, $s4
    ctx->r11 = ADD32(ctx->r10, ctx->r20);
    // 0x800E92E8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800E92EC: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E92F0: beql        $v1, $zero, L_800E9348
    if (ctx->r3 == 0) {
        // 0x800E92F4: lbu         $t9, 0xE($s5)
        ctx->r25 = MEM_BU(ctx->r21, 0XE);
            goto L_800E9348;
    }
    goto skip_1;
    // 0x800E92F4: lbu         $t9, 0xE($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0XE);
    skip_1:
    // 0x800E92F8: lb          $t4, 0x97D($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X97D);
    // 0x800E92FC: lbu         $t7, 0xE($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0XE);
    // 0x800E9300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E9304: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800E9308: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800E930C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800E9310: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800E9314: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800E9318: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E931C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x800E9320: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x800E9324: lw          $a3, -0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, -0X8);
    // 0x800E9328: lw          $a2, -0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, -0XC);
    // 0x800E932C: lw          $a1, -0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X10);
    // 0x800E9330: addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // 0x800E9334: jal         0x800C8CB8
    // 0x800E9338: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_1;
    // 0x800E9338: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x800E933C: b           L_800E93C8
    // 0x800E9340: nop

        goto L_800E93C8;
    // 0x800E9340: nop

    // 0x800E9344: lbu         $t9, 0xE($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0XE);
L_800E9348:
    // 0x800E9348: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E934C: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x800E9350: beq         $t9, $at, L_800E937C
    if (ctx->r25 == ctx->r1) {
        // 0x800E9354: subu        $t1, $t1, $s2
        ctx->r9 = SUB32(ctx->r9, ctx->r18);
            goto L_800E937C;
    }
    // 0x800E9354: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x800E9358: lw          $t0, 0x10($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X10);
    // 0x800E935C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800E9360: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x800E9364: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800E9368: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800E936C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800E9370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E9374: bne         $t3, $zero, L_800E9384
    if (ctx->r11 != 0) {
        // 0x800E9378: nop
    
            goto L_800E9384;
    }
    // 0x800E9378: nop

L_800E937C:
    // 0x800E937C: b           L_800E9384
    // 0x800E9380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E9384;
    // 0x800E9380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E9384:
    // 0x800E9384: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x800E9388: addu        $v1, $fp, $t4
    ctx->r3 = ADD32(ctx->r30, ctx->r12);
    // 0x800E938C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x800E9390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E9394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9398: beq         $a0, $zero, L_800E93A8
    if (ctx->r4 == 0) {
        // 0x800E939C: addu        $t5, $a0, $s4
        ctx->r13 = ADD32(ctx->r4, ctx->r20);
            goto L_800E93A8;
    }
    // 0x800E939C: addu        $t5, $a0, $s4
    ctx->r13 = ADD32(ctx->r4, ctx->r20);
    // 0x800E93A0: b           L_800E93A8
    // 0x800E93A4: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
        goto L_800E93A8;
    // 0x800E93A4: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
L_800E93A8:
    // 0x800E93A8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800E93AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E93B0: beq         $v0, $zero, L_800E93C0
    if (ctx->r2 == 0) {
        // 0x800E93B4: addu        $t7, $v0, $s4
        ctx->r15 = ADD32(ctx->r2, ctx->r20);
            goto L_800E93C0;
    }
    // 0x800E93B4: addu        $t7, $v0, $s4
    ctx->r15 = ADD32(ctx->r2, ctx->r20);
    // 0x800E93B8: b           L_800E93C0
    // 0x800E93BC: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
        goto L_800E93C0;
    // 0x800E93BC: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
L_800E93C0:
    // 0x800E93C0: jal         0x800C8CB8
    // 0x800E93C4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_2;
    // 0x800E93C4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
L_800E93C8:
    // 0x800E93C8: beql        $s3, $zero, L_800E9450
    if (ctx->r19 == 0) {
        // 0x800E93CC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E9450;
    }
    goto skip_2;
    // 0x800E93CC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x800E93D0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800E93D4: addiu       $t6, $s2, 0x4
    ctx->r14 = ADD32(ctx->r18, 0X4);
    // 0x800E93D8: bnel        $t6, $t8, L_800E9450
    if (ctx->r14 != ctx->r24) {
        // 0x800E93DC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E9450;
    }
    goto skip_3;
    // 0x800E93DC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x800E93E0: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
    // 0x800E93E4: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    // 0x800E93E8: beq         $a0, $zero, L_800E93FC
    if (ctx->r4 == 0) {
        // 0x800E93EC: nop
    
            goto L_800E93FC;
    }
    // 0x800E93EC: nop

    // 0x800E93F0: jal         0x80009A84
    // 0x800E93F4: nop

    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x800E93F4: nop

    after_3:
    // 0x800E93F8: sw          $zero, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = 0;
L_800E93FC:
    // 0x800E93FC: beql        $s7, $zero, L_800E9450
    if (ctx->r23 == 0) {
        // 0x800E9400: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E9450;
    }
    goto skip_4;
    // 0x800E9400: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x800E9404: mtc1        $s7, $f6
    ctx->f6.u32l = ctx->r23;
    // 0x800E9408: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    // 0x800E940C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E9410: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x800E9414: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800E9418: jal         0x80009968
    // 0x800E941C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x800E941C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    after_4:
    // 0x800E9420: sw          $v0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->r2;
    // 0x800E9424: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x800E9428: jal         0x800092D0
    // 0x800E942C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_5;
    // 0x800E942C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800E9430: lw          $t9, 0xDC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XDC);
    // 0x800E9434: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x800E9438: lw          $a2, 0xC($s3)
    ctx->r6 = MEM_W(ctx->r19, 0XC);
    // 0x800E943C: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x800E9440: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800E9444: jal         0x800C8CB8
    // 0x800E9448: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_6;
    // 0x800E9448: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x800E944C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800E9450:
    // 0x800E9450: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x800E9454: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800E9458: bne         $s2, $at, L_800E92A8
    if (ctx->r18 != ctx->r1) {
        // 0x800E945C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800E92A8;
    }
    // 0x800E945C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800E9460: sb          $s7, 0x10($s5)
    MEM_B(0X10, ctx->r21) = ctx->r23;
    // 0x800E9464: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800E9468: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800E946C: sb          $t0, 0x11($s5)
    MEM_B(0X11, ctx->r21) = ctx->r8;
    // 0x800E9470: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800E9474: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x800E9478: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E947C: addu        $v0, $t1, $t3
    ctx->r2 = ADD32(ctx->r9, ctx->r11);
    // 0x800E9480: lbu         $t4, 0xEF($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XEF);
    // 0x800E9484: lbu         $t5, 0xEC($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XEC);
    // 0x800E9488: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E948C: mflo        $t7
    ctx->r15 = lo;
    // 0x800E9490: nop

    // 0x800E9494: nop

    // 0x800E9498: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x800E949C: mflo        $t6
    ctx->r14 = lo;
    // 0x800E94A0: sb          $t6, 0xA90($s5)
    MEM_B(0XA90, ctx->r21) = ctx->r14;
    // 0x800E94A4: lbu         $t8, 0xEF($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XEF);
    // 0x800E94A8: lbu         $t9, 0xED($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XED);
    // 0x800E94AC: bne         $v1, $zero, L_800E94B8
    if (ctx->r3 != 0) {
        // 0x800E94B0: nop
    
            goto L_800E94B8;
    }
    // 0x800E94B0: nop

    // 0x800E94B4: break       7
    do_break(2148439220);
L_800E94B8:
    // 0x800E94B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E94BC: bne         $v1, $at, L_800E94D0
    if (ctx->r3 != ctx->r1) {
        // 0x800E94C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E94D0;
    }
    // 0x800E94C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E94C4: bne         $t7, $at, L_800E94D0
    if (ctx->r15 != ctx->r1) {
        // 0x800E94C8: nop
    
            goto L_800E94D0;
    }
    // 0x800E94C8: nop

    // 0x800E94CC: break       6
    do_break(2148439244);
L_800E94D0:
    // 0x800E94D0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E94D4: mflo        $t0
    ctx->r8 = lo;
    // 0x800E94D8: nop

    // 0x800E94DC: nop

    // 0x800E94E0: div         $zero, $t0, $v1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r3)));
    // 0x800E94E4: mflo        $t2
    ctx->r10 = lo;
    // 0x800E94E8: sb          $t2, 0xA91($s5)
    MEM_B(0XA91, ctx->r21) = ctx->r10;
    // 0x800E94EC: lbu         $t3, 0xEE($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XEE);
    // 0x800E94F0: lbu         $t1, 0xEF($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XEF);
    // 0x800E94F4: bne         $v1, $zero, L_800E9500
    if (ctx->r3 != 0) {
        // 0x800E94F8: nop
    
            goto L_800E9500;
    }
    // 0x800E94F8: nop

    // 0x800E94FC: break       7
    do_break(2148439292);
L_800E9500:
    // 0x800E9500: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E9504: bne         $v1, $at, L_800E9518
    if (ctx->r3 != ctx->r1) {
        // 0x800E9508: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E9518;
    }
    // 0x800E9508: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E950C: bne         $t0, $at, L_800E9518
    if (ctx->r8 != ctx->r1) {
        // 0x800E9510: nop
    
            goto L_800E9518;
    }
    // 0x800E9510: nop

    // 0x800E9514: break       6
    do_break(2148439316);
L_800E9518:
    // 0x800E9518: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E951C: mflo        $t4
    ctx->r12 = lo;
    // 0x800E9520: nop

    // 0x800E9524: nop

    // 0x800E9528: div         $zero, $t4, $v1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r3)));
    // 0x800E952C: mflo        $t5
    ctx->r13 = lo;
    // 0x800E9530: sb          $t5, 0xA92($s5)
    MEM_B(0XA92, ctx->r21) = ctx->r13;
    // 0x800E9534: bne         $v1, $zero, L_800E9540
    if (ctx->r3 != 0) {
        // 0x800E9538: nop
    
            goto L_800E9540;
    }
    // 0x800E9538: nop

    // 0x800E953C: break       7
    do_break(2148439356);
L_800E9540:
    // 0x800E9540: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E9544: bne         $v1, $at, L_800E9558
    if (ctx->r3 != ctx->r1) {
        // 0x800E9548: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E9558;
    }
    // 0x800E9548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E954C: bne         $t4, $at, L_800E9558
    if (ctx->r12 != ctx->r1) {
        // 0x800E9550: nop
    
            goto L_800E9558;
    }
    // 0x800E9550: nop

    // 0x800E9554: break       6
    do_break(2148439380);
L_800E9558:
    // 0x800E9558: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800E955C: jal         0x800E9598
    // 0x800E9560: nop

    ftParamInitTexturePartAll(rdram, ctx);
        goto after_7;
    // 0x800E9560: nop

    after_7:
    // 0x800E9564: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800E9568: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800E956C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E9570: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800E9574: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800E9578: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800E957C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800E9580: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800E9584: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800E9588: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800E958C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800E9590: jr          $ra
    // 0x800E9594: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800E9594: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ftCommonHammerKneeBendSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147F88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80147F8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80147F90: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80147F94: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80147F98: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80147F9C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80147FA0: jal         0x800F3828
    // 0x80147FA4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftHammerGetAnimFrame(rdram, ctx);
        goto after_0;
    // 0x80147FA4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80147FA8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80147FAC: jal         0x800F385C
    // 0x80147FB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftHammerGetStatUpdateFlags(rdram, ctx);
        goto after_1;
    // 0x80147FB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80147FB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80147FB8: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x80147FBC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80147FC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80147FC4: jal         0x800E6F24
    // 0x80147FC8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80147FC8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80147FCC: jal         0x800F388C
    // 0x80147FD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftHammerSetColAnim(rdram, ctx);
        goto after_3;
    // 0x80147FD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80147FD4: lb          $t6, 0x1C3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1C3);
    // 0x80147FD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80147FDC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80147FE0: swc1        $f8, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f8.u32l;
    // 0x80147FE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80147FE8: swc1        $f6, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->f6.u32l;
    // 0x80147FEC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80147FF0: sw          $zero, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = 0;
    // 0x80147FF4: sw          $t7, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r15;
    // 0x80147FF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80147FFC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80148000: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80148004: jr          $ra
    // 0x80148008: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80148008: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_ovl2_80106730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106730: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80106734: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80106738: lw          $t6, 0x1424($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1424);
    // 0x8010673C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80106740: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80106744: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80106748: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8010674C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80106750: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80106754: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80106758: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010675C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80106760: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80106764: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80106768: lw          $s0, 0x6C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X6C);
    // 0x8010676C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80106770: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80106774: beq         $s0, $zero, L_80106810
    if (ctx->r16 == 0) {
        // 0x80106778: or          $s4, $a1, $zero
        ctx->r20 = ctx->r5 | 0;
            goto L_80106810;
    }
    // 0x80106778: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8010677C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80106780: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80106784: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80106788: lwc1        $f20, 0x4C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8010678C: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80106790: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
L_80106794:
    // 0x80106794: beql        $t7, $zero, L_80106804
    if (ctx->r15 == 0) {
        // 0x80106798: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80106804;
    }
    goto skip_0;
    // 0x80106798: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8010679C: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x801067A0: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x801067A4: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x801067A8: bnel        $t0, $zero, L_80106804
    if (ctx->r8 != 0) {
        // 0x801067AC: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80106804;
    }
    goto skip_1;
    // 0x801067AC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x801067B0: lbu         $t1, 0x4($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X4);
    // 0x801067B4: bnel        $s2, $t1, L_80106804
    if (ctx->r18 != ctx->r9) {
        // 0x801067B8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80106804;
    }
    goto skip_2;
    // 0x801067B8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x801067BC: jal         0x8000CB94
    // 0x801067C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_0;
    // 0x801067C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801067C4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x801067C8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801067CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801067D0: bc1fl       L_801067E4
    if (!c1cs) {
        // 0x801067D4: c.lt.s      $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
            goto L_801067E4;
    }
    goto skip_3;
    // 0x801067D4: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    skip_3:
    // 0x801067D8: b           L_801067F4
    // 0x801067DC: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
        goto L_801067F4;
    // 0x801067DC: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x801067E0: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
L_801067E4:
    // 0x801067E4: nop

    // 0x801067E8: bc1fl       L_801067F8
    if (!c1cs) {
        // 0x801067EC: mfc1        $a2, $f20
        ctx->r6 = (int32_t)ctx->f20.u32l;
            goto L_801067F8;
    }
    goto skip_4;
    // 0x801067EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    skip_4:
    // 0x801067F0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_801067F4:
    // 0x801067F4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_801067F8:
    // 0x801067F8: jal         0x8001E574
    // 0x801067FC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    syInterpQuad(rdram, ctx);
        goto after_1;
    // 0x801067FC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_1:
    // 0x80106800: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80106804:
    // 0x80106804: bnel        $s0, $zero, L_80106794
    if (ctx->r16 != 0) {
        // 0x80106808: lbu         $t7, 0x5($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X5);
            goto L_80106794;
    }
    goto skip_5;
    // 0x80106808: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
    skip_5:
    // 0x8010680C: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
L_80106810:
    // 0x80106810: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80106814: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106818: lwc1        $f4, 0xAC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XAC0);
    // 0x8010681C: lwc1        $f6, 0x74($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X74);
    // 0x80106820: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80106824: lwc1        $f20, 0x4C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80106828: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8010682C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80106830: bc1tl       L_801068A4
    if (c1cs) {
        // 0x80106834: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801068A4;
    }
    goto skip_6;
    // 0x80106834: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_6:
    // 0x80106838: lbu         $t3, 0x1445($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X1445);
    // 0x8010683C: bnel        $t3, $zero, L_801068A4
    if (ctx->r11 != 0) {
        // 0x80106840: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801068A4;
    }
    goto skip_7;
    // 0x80106840: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_7:
    // 0x80106844: lw          $s0, 0x6C($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X6C);
    // 0x80106848: beq         $s0, $zero, L_80106898
    if (ctx->r16 == 0) {
        // 0x8010684C: nop
    
            goto L_80106898;
    }
    // 0x8010684C: nop

    // 0x80106850: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
L_80106854:
    // 0x80106854: beql        $t4, $zero, L_80106890
    if (ctx->r12 == 0) {
        // 0x80106858: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80106890;
    }
    goto skip_8;
    // 0x80106858: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x8010685C: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80106860: lw          $t6, 0x7C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X7C);
    // 0x80106864: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80106868: bnel        $t7, $zero, L_80106890
    if (ctx->r15 != 0) {
        // 0x8010686C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80106890;
    }
    goto skip_9;
    // 0x8010686C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x80106870: lbu         $t8, 0x4($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X4);
    // 0x80106874: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80106878: bnel        $s2, $t8, L_80106890
    if (ctx->r18 != ctx->r24) {
        // 0x8010687C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80106890;
    }
    goto skip_10;
    // 0x8010687C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_10:
    // 0x80106880: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80106884: jal         0x8001E530
    // 0x80106888: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    syInterpCubic(rdram, ctx);
        goto after_2;
    // 0x80106888: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_2:
    // 0x8010688C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80106890:
    // 0x80106890: bnel        $s0, $zero, L_80106854
    if (ctx->r16 != 0) {
        // 0x80106894: lbu         $t4, 0x5($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X5);
            goto L_80106854;
    }
    goto skip_11;
    // 0x80106894: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
    skip_11:
L_80106898:
    // 0x80106898: jal         0x80018EE0
    // 0x8010689C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    syVectorNorm3D(rdram, ctx);
        goto after_3;
    // 0x8010689C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x801068A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_801068A4:
    // 0x801068A4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801068A8: jal         0x800CD5AC
    // 0x801068AC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    lbCommonCross3D(rdram, ctx);
        goto after_4;
    // 0x801068AC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_4:
    // 0x801068B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801068B4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x801068B8: jal         0x800CD5AC
    // 0x801068BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    lbCommonCross3D(rdram, ctx);
        goto after_5;
    // 0x801068BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
    // 0x801068C0: jal         0x80018EE0
    // 0x801068C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    syVectorNorm3D(rdram, ctx);
        goto after_6;
    // 0x801068C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x801068C8: jal         0x80018EE0
    // 0x801068CC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    syVectorNorm3D(rdram, ctx);
        goto after_7;
    // 0x801068CC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_7:
    // 0x801068D0: jal         0x80018EE0
    // 0x801068D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    syVectorNorm3D(rdram, ctx);
        goto after_8;
    // 0x801068D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x801068D8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801068DC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801068E0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801068E4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801068E8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801068EC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801068F0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801068F4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801068F8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801068FC: jr          $ra
    // 0x80106900: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80106900: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void sc1PGameSetGameEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D1A8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8018D1AC: lbu         $t8, 0x4AE3($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4AE3);
    // 0x8018D1B0: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018D1B4: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8018D1B8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8018D1BC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018D1C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D1C4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018D1C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D1CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D1D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D1D4: sw          $t6, 0x33C0($at)
    MEM_W(0X33C0, ctx->r1) = ctx->r14;
    // 0x8018D1D8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018D1DC: lw          $v0, 0x78($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X78);
    // 0x8018D1E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D1E4: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8018D1E8: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x8018D1EC: sw          $t1, 0x33C8($at)
    MEM_W(0X33C8, ctx->r1) = ctx->r9;
    // 0x8018D1F0: lw          $t2, 0x5B0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X5B0);
    // 0x8018D1F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D1F8: jr          $ra
    // 0x8018D1FC: sw          $t2, 0x33CC($at)
    MEM_W(0X33CC, ctx->r1) = ctx->r10;
    return;
    // 0x8018D1FC: sw          $t2, 0x33CC($at)
    MEM_W(0X33CC, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157BEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80157BF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157BF4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80157BF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80157BFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80157C00: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
    // 0x80157C04: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80157C08: jal         0x800E6F24
    // 0x80157C0C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80157C0C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80157C10: jal         0x80157AD4
    // 0x80157C14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyDonkeySpecialNLoopSetProcDamageAnimSpeed(rdram, ctx);
        goto after_1;
    // 0x80157C14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80157C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157C1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80157C20: jr          $ra
    // 0x80157C24: nop

    return;
    // 0x80157C24: nop

;}
RECOMP_FUNC void mnPlayersVSDestroyPortraitFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136388: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8013638C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136390: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80136394: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136398: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013639C: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x801363A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801363A4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801363A8: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    // 0x801363AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801363B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801363B4: beq         $a1, $zero, L_801363CC
    if (ctx->r5 == 0) {
        // 0x801363B8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_801363CC;
    }
    // 0x801363B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801363BC: jal         0x80009A84
    // 0x801363C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801363C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x801363C4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x801363C8: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
L_801363CC:
    // 0x801363CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801363D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801363D4: jr          $ra
    // 0x801363D8: nop

    return;
    // 0x801363D8: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialNEmptySwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801648A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801648A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801648A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801648AC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801648B0: jal         0x800DEEC8
    // 0x801648B4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801648B4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801648B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801648BC: addiu       $a1, $zero, 0x124
    ctx->r5 = ADD32(0, 0X124);
    // 0x801648C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801648C4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801648C8: jal         0x800E6F24
    // 0x801648CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801648CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801648D0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801648D4: lbu         $t8, 0x192($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X192);
    // 0x801648D8: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x801648DC: sb          $t9, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r25;
    // 0x801648E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801648E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801648E8: jr          $ra
    // 0x801648EC: nop

    return;
    // 0x801648EC: nop

;}
RECOMP_FUNC void func_ovl8_80379D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379D74: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80379D78: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x80379D7C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80379D80: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80379D84: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80379D88: sltiu       $at, $a3, 0x4
    ctx->r1 = ctx->r7 < 0X4 ? 1 : 0;
    // 0x80379D8C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80379D90: beq         $at, $zero, L_8037A0F0
    if (ctx->r1 == 0) {
        // 0x80379D94: lh          $v0, 0x2($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X2);
            goto L_8037A0F0;
    }
    // 0x80379D94: lh          $v0, 0x2($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X2);
    // 0x80379D98: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80379D9C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80379DA0: addu        $at, $at, $t6
    gpr jr_addend_80379DA8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80379DA4: lw          $t6, -0x11C8($at)
    ctx->r14 = ADD32(ctx->r1, -0X11C8);
    // 0x80379DA8: jr          $t6
    // 0x80379DAC: nop

    switch (jr_addend_80379DA8 >> 2) {
        case 0: goto L_8037A0F0; break;
        case 1: goto L_80379DB0; break;
        case 2: goto L_80379EAC; break;
        case 3: goto L_80379FD0; break;
        default: switch_error(__func__, 0x80379DA8, 0x8038EE38);
    }
    // 0x80379DAC: nop

L_80379DB0:
    // 0x80379DB0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80379DB4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80379DB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80379DBC: lhu         $t0, 0x6($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X6);
    // 0x80379DC0: blezl       $t0, L_8037A0F4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80379DC4: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_8037A0F4;
    }
    goto skip_0;
    // 0x80379DC4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_0:
    // 0x80379DC8: lhu         $t1, 0x4($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X4);
L_80379DCC:
    // 0x80379DCC: blez        $t1, L_80379E88
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80379DD0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80379E88;
    }
    // 0x80379DD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80379DD4:
    // 0x80379DD4: lh          $t7, 0x2($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X2);
    // 0x80379DD8: addu        $t0, $t7, $a1
    ctx->r8 = ADD32(ctx->r15, ctx->r5);
    // 0x80379DDC: andi        $t8, $t0, 0x1
    ctx->r24 = ctx->r8 & 0X1;
    // 0x80379DE0: beq         $t8, $zero, L_80379E40
    if (ctx->r24 == 0) {
        // 0x80379DE4: nop
    
            goto L_80379E40;
    }
    // 0x80379DE4: nop

    // 0x80379DE8: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x80379DEC: addu        $t9, $t1, $a0
    ctx->r25 = ADD32(ctx->r9, ctx->r4);
    // 0x80379DF0: andi        $t4, $t9, 0x4
    ctx->r12 = ctx->r25 & 0X4;
    // 0x80379DF4: beq         $t4, $zero, L_80379E1C
    if (ctx->r12 == 0) {
        // 0x80379DF8: nop
    
            goto L_80379E1C;
    }
    // 0x80379DF8: nop

    // 0x80379DFC: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379E00: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x80379E04: mflo        $t6
    ctx->r14 = lo;
    // 0x80379E08: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80379E0C: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x80379E10: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80379E14: b           L_80379E60
    // 0x80379E18: lbu         $t3, -0x4($t9)
    ctx->r11 = MEM_BU(ctx->r25, -0X4);
        goto L_80379E60;
    // 0x80379E18: lbu         $t3, -0x4($t9)
    ctx->r11 = MEM_BU(ctx->r25, -0X4);
L_80379E1C:
    // 0x80379E1C: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379E20: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    // 0x80379E24: mflo        $t5
    ctx->r13 = lo;
    // 0x80379E28: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80379E2C: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x80379E30: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80379E34: lbu         $t2, 0x4($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X4);
    // 0x80379E38: b           L_80379E60
    // 0x80379E3C: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
        goto L_80379E60;
    // 0x80379E3C: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
L_80379E40:
    // 0x80379E40: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379E44: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80379E48: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80379E4C: mflo        $t4
    ctx->r12 = lo;
    // 0x80379E50: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x80379E54: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80379E58: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80379E5C: lbu         $t3, 0x0($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X0);
L_80379E60:
    // 0x80379E60: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80379E64: sb          $t3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r11;
    // 0x80379E68: lhu         $t1, 0x4($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X4);
    // 0x80379E6C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80379E70: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80379E74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80379E78: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80379E7C: bne         $at, $zero, L_80379DD4
    if (ctx->r1 != 0) {
        // 0x80379E80: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80379DD4;
    }
    // 0x80379E80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80379E84: lhu         $t0, 0x6($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X6);
L_80379E88:
    // 0x80379E88: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80379E8C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80379E90: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80379E94: subu        $t9, $s0, $t1
    ctx->r25 = SUB32(ctx->r16, ctx->r9);
    // 0x80379E98: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80379E9C: bne         $at, $zero, L_80379DCC
    if (ctx->r1 != 0) {
        // 0x80379EA0: addu        $v1, $v1, $t9
        ctx->r3 = ADD32(ctx->r3, ctx->r25);
            goto L_80379DCC;
    }
    // 0x80379EA0: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80379EA4: b           L_8037A0F4
    // 0x80379EA8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
        goto L_8037A0F4;
    // 0x80379EA8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_80379EAC:
    // 0x80379EAC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80379EB0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80379EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80379EB8: lhu         $t0, 0x6($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X6);
    // 0x80379EBC: blezl       $t0, L_8037A0F4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80379EC0: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_8037A0F4;
    }
    goto skip_1;
    // 0x80379EC0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_1:
    // 0x80379EC4: lhu         $t1, 0x4($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X4);
L_80379EC8:
    // 0x80379EC8: blez        $t1, L_80379FA8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80379ECC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80379FA8;
    }
    // 0x80379ECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80379ED0:
    // 0x80379ED0: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x80379ED4: addu        $t0, $t4, $a1
    ctx->r8 = ADD32(ctx->r12, ctx->r5);
    // 0x80379ED8: andi        $t5, $t0, 0x1
    ctx->r13 = ctx->r8 & 0X1;
    // 0x80379EDC: beq         $t5, $zero, L_80379F54
    if (ctx->r13 == 0) {
        // 0x80379EE0: nop
    
            goto L_80379F54;
    }
    // 0x80379EE0: nop

    // 0x80379EE4: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x80379EE8: addu        $t6, $t1, $a0
    ctx->r14 = ADD32(ctx->r9, ctx->r4);
    // 0x80379EEC: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80379EF0: beq         $t7, $zero, L_80379F24
    if (ctx->r15 == 0) {
        // 0x80379EF4: nop
    
            goto L_80379F24;
    }
    // 0x80379EF4: nop

    // 0x80379EF8: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379EFC: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x80379F00: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x80379F04: mflo        $t9
    ctx->r25 = lo;
    // 0x80379F08: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x80379F0C: addu        $t5, $t8, $t4
    ctx->r13 = ADD32(ctx->r24, ctx->r12);
    // 0x80379F10: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80379F14: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80379F18: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80379F1C: b           L_80379F80
    // 0x80379F20: lhu         $t3, -0x4($t8)
    ctx->r11 = MEM_HU(ctx->r24, -0X4);
        goto L_80379F80;
    // 0x80379F20: lhu         $t3, -0x4($t8)
    ctx->r11 = MEM_HU(ctx->r24, -0X4);
L_80379F24:
    // 0x80379F24: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379F28: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    // 0x80379F2C: sll         $t9, $t1, 1
    ctx->r25 = S32(ctx->r9 << 1);
    // 0x80379F30: mflo        $t5
    ctx->r13 = lo;
    // 0x80379F34: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80379F38: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80379F3C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80379F40: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x80379F44: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x80379F48: lhu         $t2, 0x4($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X4);
    // 0x80379F4C: b           L_80379F80
    // 0x80379F50: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
        goto L_80379F80;
    // 0x80379F50: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
L_80379F54:
    // 0x80379F54: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379F58: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x80379F5C: lh          $t5, 0x0($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X0);
    // 0x80379F60: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x80379F64: mflo        $t7
    ctx->r15 = lo;
    // 0x80379F68: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80379F6C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80379F70: addu        $t7, $t8, $t4
    ctx->r15 = ADD32(ctx->r24, ctx->r12);
    // 0x80379F74: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80379F78: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80379F7C: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
L_80379F80:
    // 0x80379F80: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80379F84: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x80379F88: lhu         $t1, 0x4($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X4);
    // 0x80379F8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80379F90: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80379F94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80379F98: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80379F9C: bne         $at, $zero, L_80379ED0
    if (ctx->r1 != 0) {
        // 0x80379FA0: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80379ED0;
    }
    // 0x80379FA0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80379FA4: lhu         $t0, 0x6($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X6);
L_80379FA8:
    // 0x80379FA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80379FAC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80379FB0: subu        $t5, $s0, $t1
    ctx->r13 = SUB32(ctx->r16, ctx->r9);
    // 0x80379FB4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80379FB8: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x80379FBC: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80379FC0: bne         $at, $zero, L_80379EC8
    if (ctx->r1 != 0) {
        // 0x80379FC4: addu        $v1, $v1, $t8
        ctx->r3 = ADD32(ctx->r3, ctx->r24);
            goto L_80379EC8;
    }
    // 0x80379FC4: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80379FC8: b           L_8037A0F4
    // 0x80379FCC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
        goto L_8037A0F4;
    // 0x80379FCC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_80379FD0:
    // 0x80379FD0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80379FD4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80379FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80379FDC: lhu         $t0, 0x6($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X6);
    // 0x80379FE0: blezl       $t0, L_8037A0F4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80379FE4: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_8037A0F4;
    }
    goto skip_2;
    // 0x80379FE4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_2:
    // 0x80379FE8: lhu         $t1, 0x4($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X4);
L_80379FEC:
    // 0x80379FEC: blez        $t1, L_8037A0D0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80379FF0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8037A0D0;
    }
    // 0x80379FF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80379FF4:
    // 0x80379FF4: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x80379FF8: addu        $t0, $t4, $a1
    ctx->r8 = ADD32(ctx->r12, ctx->r5);
    // 0x80379FFC: andi        $t7, $t0, 0x1
    ctx->r15 = ctx->r8 & 0X1;
    // 0x8037A000: beq         $t7, $zero, L_8037A078
    if (ctx->r15 == 0) {
        // 0x8037A004: nop
    
            goto L_8037A078;
    }
    // 0x8037A004: nop

    // 0x8037A008: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x8037A00C: addu        $t6, $t1, $a0
    ctx->r14 = ADD32(ctx->r9, ctx->r4);
    // 0x8037A010: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x8037A014: beq         $t9, $zero, L_8037A048
    if (ctx->r25 == 0) {
        // 0x8037A018: nop
    
            goto L_8037A048;
    }
    // 0x8037A018: nop

    // 0x8037A01C: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A020: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x8037A024: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8037A028: mflo        $t8
    ctx->r24 = lo;
    // 0x8037A02C: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8037A030: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x8037A034: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8037A038: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8037A03C: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x8037A040: b           L_8037A0A4
    // 0x8037A044: lw          $t2, -0x8($t5)
    ctx->r10 = MEM_W(ctx->r13, -0X8);
        goto L_8037A0A4;
    // 0x8037A044: lw          $t2, -0x8($t5)
    ctx->r10 = MEM_W(ctx->r13, -0X8);
L_8037A048:
    // 0x8037A048: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A04C: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    // 0x8037A050: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8037A054: mflo        $t7
    ctx->r15 = lo;
    // 0x8037A058: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8037A05C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x8037A060: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x8037A064: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8037A068: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x8037A06C: lw          $t3, 0x8($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X8);
    // 0x8037A070: b           L_8037A0A4
    // 0x8037A074: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
        goto L_8037A0A4;
    // 0x8037A074: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
L_8037A078:
    // 0x8037A078: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A07C: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x8037A080: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x8037A084: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x8037A088: mflo        $t9
    ctx->r25 = lo;
    // 0x8037A08C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8037A090: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x8037A094: addu        $t9, $t5, $t4
    ctx->r25 = ADD32(ctx->r13, ctx->r12);
    // 0x8037A098: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8037A09C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8037A0A0: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
L_8037A0A4:
    // 0x8037A0A4: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x8037A0A8: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x8037A0AC: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x8037A0B0: lhu         $t1, 0x4($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X4);
    // 0x8037A0B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8037A0B8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037A0BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8037A0C0: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8037A0C4: bne         $at, $zero, L_80379FF4
    if (ctx->r1 != 0) {
        // 0x8037A0C8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80379FF4;
    }
    // 0x8037A0C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8037A0CC: lhu         $t0, 0x6($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X6);
L_8037A0D0:
    // 0x8037A0D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8037A0D4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037A0D8: subu        $t7, $s0, $t1
    ctx->r15 = SUB32(ctx->r16, ctx->r9);
    // 0x8037A0DC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8037A0E0: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8037A0E4: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8037A0E8: bne         $at, $zero, L_80379FEC
    if (ctx->r1 != 0) {
        // 0x8037A0EC: addu        $v1, $v1, $t5
        ctx->r3 = ADD32(ctx->r3, ctx->r13);
            goto L_80379FEC;
    }
    // 0x8037A0EC: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
L_8037A0F0:
    // 0x8037A0F0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_8037A0F4:
    // 0x8037A0F4: jr          $ra
    // 0x8037A0F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8037A0F8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void ftCommonThrownKirbyStarProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C268: jal         0x8014BF04
    // 0x8014C26C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    ftCommonThrownCommonStarUpdatePhysics(rdram, ctx);
        goto after_0;
    // 0x8014C26C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_0:
    // 0x8014C270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C278: jr          $ra
    // 0x8014C27C: nop

    return;
    // 0x8014C27C: nop

;}
RECOMP_FUNC void sc1PStageClearMakeTimerTextSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132504: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80132508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013250C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132510: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132514: jal         0x80009968
    // 0x80132518: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132518: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013251C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132520: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132524: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132528: sw          $v0, 0x52F8($at)
    MEM_W(0X52F8, ctx->r1) = ctx->r2;
    // 0x8013252C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132530: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132534: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132538: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013253C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132540: jal         0x80009DF4
    // 0x80132544: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132544: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132548: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013254C: lw          $t7, 0x5588($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5588);
    // 0x80132550: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132554: addiu       $t8, $t8, 0x25E8
    ctx->r24 = ADD32(ctx->r24, 0X25E8);
    // 0x80132558: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013255C: jal         0x800CCFDC
    // 0x80132560: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132560: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132564: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132568: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x8013256C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132570: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132574: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132578: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013257C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132580: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132584: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80132588: addiu       $t3, $zero, 0xB7
    ctx->r11 = ADD32(0, 0XB7);
    // 0x8013258C: addiu       $t4, $zero, 0xE4
    ctx->r12 = ADD32(0, 0XE4);
    // 0x80132590: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80132594: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132598: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x8013259C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x801325A0: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x801325A4: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x801325A8: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x801325AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801325B0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801325B4: lw          $t6, 0x5588($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5588);
    // 0x801325B8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801325BC: addiu       $t7, $t7, 0x2120
    ctx->r15 = ADD32(ctx->r15, 0X2120);
    // 0x801325C0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801325C4: jal         0x800CCFDC
    // 0x801325C8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801325C8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x801325CC: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801325D0: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x801325D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801325D8: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x801325DC: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801325E0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801325E4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801325E8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801325EC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801325F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801325F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801325F8: addiu       $t2, $zero, 0xB7
    ctx->r10 = ADD32(0, 0XB7);
    // 0x801325FC: addiu       $t3, $zero, 0xE4
    ctx->r11 = ADD32(0, 0XE4);
    // 0x80132600: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80132604: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80132608: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x8013260C: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132610: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132614: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132618: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x8013261C: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80132620: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x80132624: jal         0x800269C0
    // 0x80132628: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80132628: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    after_4:
    // 0x8013262C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132630: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132634: jr          $ra
    // 0x80132638: nop

    return;
    // 0x80132638: nop

;}
RECOMP_FUNC void func_ovl8_8037368C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037368C: jr          $ra
    // 0x80373690: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    return;
    // 0x80373690: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
;}

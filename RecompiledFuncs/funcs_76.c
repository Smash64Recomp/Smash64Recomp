#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSItemSwitchMakeCursorCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132468: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013246C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132470: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132474: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132478: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8013247C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132480: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80132484: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132488: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013248C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132490: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132494: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132498: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013249C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801324A0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801324A4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801324A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801324AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801324B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801324B4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801324B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801324BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801324C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801324C4: jal         0x8000B93C
    // 0x801324C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801324C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801324CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801324D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801324D4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801324D8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801324DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801324E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801324E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801324E8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801324EC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801324F0: jal         0x80007080
    // 0x801324F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801324F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801324F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801324FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132500: jr          $ra
    // 0x80132504: nop

    return;
    // 0x80132504: nop

;}
RECOMP_FUNC void gcFindGObjByID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B19C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000B1A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B1A4: lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // 0x8000B1A8: addiu       $a0, $a0, -0x4EB4
    ctx->r4 = ADD32(ctx->r4, -0X4EB4);
    // 0x8000B1AC: jal         0x8000B08C
    // 0x8000B1B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcFuncGObjAllEx(rdram, ctx);
        goto after_0;
    // 0x8000B1B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8000B1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B1B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B1BC: jr          $ra
    // 0x8000B1C0: nop

    return;
    // 0x8000B1C0: nop

;}
RECOMP_FUNC void gcPlayCamAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010588: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8001058C: jal         0x8000FA74
    // 0x80010590: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    gcParseCObjCamAnimJoint(rdram, ctx);
        goto after_0;
    // 0x80010590: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80010594: jal         0x80010344
    // 0x80010598: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    gcPlayCObjCamAnim(rdram, ctx);
        goto after_1;
    // 0x80010598: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8001059C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800105A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800105A4: jr          $ra
    // 0x800105A8: nop

    return;
    // 0x800105A8: nop

;}
RECOMP_FUNC void ftCommonWaitCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E2A8: jal         0x8013E258
    // 0x8013E2AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonWaitCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8013E2AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013E2B0: beql        $v0, $zero, L_8013E2CC
    if (ctx->r2 == 0) {
        // 0x8013E2B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013E2CC;
    }
    goto skip_0;
    // 0x8013E2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013E2B8: jal         0x8013E1C8
    // 0x8013E2BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013E2BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013E2C0: b           L_8013E2CC
    // 0x8013E2C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013E2CC;
    // 0x8013E2C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013E2C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013E2CC:
    // 0x8013E2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E2D4: jr          $ra
    // 0x8013E2D8: nop

    return;
    // 0x8013E2D8: nop

;}
RECOMP_FUNC void syControllerScheduleRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800042EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800042F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800042F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800042F8: jal         0x80004284
    // 0x800042FC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    syControllerDispatchEvent(rdram, ctx);
        goto after_0;
    // 0x800042FC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80004300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004304: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80004308: jr          $ra
    // 0x8000430C: nop

    return;
    // 0x8000430C: nop

;}
RECOMP_FUNC void grSectorArwingLaser3DFuncMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106904: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80106908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010690C: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80106910: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80106914: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80106918: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010691C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80106920: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80106924: lwc1        $f12, 0x1C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80106928: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8010692C: lwc1        $f16, 0x24($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80106930: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80106934: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80106938: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010693C: lbu         $t7, 0x1445($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1445);
    // 0x80106940: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80106944: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x80106948: swc1        $f2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f2.u32l;
    // 0x8010694C: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80106950: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x80106954: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x80106958: bne         $t7, $at, L_80106978
    if (ctx->r15 != ctx->r1) {
        // 0x8010695C: swc1        $f6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
            goto L_80106978;
    }
    // 0x8010695C: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x80106960: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80106964: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80106968: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x8010696C: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x80106970: b           L_801069A8
    // 0x80106974: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
        goto L_801069A8;
    // 0x80106974: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
L_80106978:
    // 0x80106978: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x8010697C: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x80106980: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x80106984: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    // 0x80106988: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x8010698C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x80106990: jal         0x80106730
    // 0x80106994: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_ovl2_80106730(rdram, ctx);
        goto after_0;
    // 0x80106994: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80106998: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8010699C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801069A0: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801069A4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
L_801069A8:
    // 0x801069A8: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801069AC: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801069B0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801069B4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801069B8: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801069BC: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801069C0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801069C4: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801069C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801069CC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801069D0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801069D4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x801069D8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801069DC: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801069E0: lwc1        $f4, 0x1430($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1430);
    // 0x801069E4: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x801069E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801069EC: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x801069F0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x801069F4: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x801069F8: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801069FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80106A00: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x80106A04: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80106A08: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80106A0C: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x80106A10: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x80106A14: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80106A18: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x80106A1C: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x80106A20: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80106A24: jal         0x80032940
    // 0x80106A28: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80106A28: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80106A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106A30: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80106A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80106A38: jr          $ra
    // 0x80106A3C: nop

    return;
    // 0x80106A3C: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157BB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80157BB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157BB8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80157BBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80157BC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80157BC4: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x80157BC8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80157BCC: jal         0x800E6F24
    // 0x80157BD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80157BD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80157BD4: jal         0x80157AD4
    // 0x80157BD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyDonkeySpecialNLoopSetProcDamageAnimSpeed(rdram, ctx);
        goto after_1;
    // 0x80157BD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80157BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157BE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80157BE4: jr          $ra
    // 0x80157BE8: nop

    return;
    // 0x80157BE8: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageSetDigitPositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F3A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010F3A4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010F3A8: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, 0X1580);
    // 0x8010F3AC: addiu       $t6, $t6, -0x13C8
    ctx->r14 = ADD32(ctx->r14, -0X13C8);
    // 0x8010F3B0: addiu       $t7, $zero, 0xD2
    ctx->r15 = ADD32(0, 0XD2);
    // 0x8010F3B4: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8010F3B8: jr          $ra
    // 0x8010F3BC: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    return;
    // 0x8010F3BC: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void ftCommonCapturePulledProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A72C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8014A730: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014A734: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014A738: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8014A73C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8014A740: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014A744: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8014A748: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8014A74C: lw          $v0, 0x844($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X844);
    // 0x8014A750: addiu       $t7, $s0, 0xF8
    ctx->r15 = ADD32(ctx->r16, 0XF8);
    // 0x8014A754: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x8014A758: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8014A75C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8014A760: addiu       $a3, $s0, 0xF4
    ctx->r7 = ADD32(ctx->r16, 0XF4);
    // 0x8014A764: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    // 0x8014A768: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8014A76C: jal         0x800F3DD8
    // 0x8014A770: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_0;
    // 0x8014A770: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014A774: beq         $v0, $zero, L_8014A7E4
    if (ctx->r2 == 0) {
        // 0x8014A778: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_8014A7E4;
    }
    // 0x8014A778: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8014A77C: lw          $t8, 0xEC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XEC);
    // 0x8014A780: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014A784: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8014A788: sw          $t8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->r24;
    // 0x8014A78C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8014A790: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8014A794: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8014A798: nop

    // 0x8014A79C: bc1fl       L_8014A7C0
    if (!c1cs) {
        // 0x8014A7A0: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8014A7C0;
    }
    goto skip_0;
    // 0x8014A7A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x8014A7A4: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8014A7A8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8014A7AC: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8014A7B0: sw          $zero, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = 0;
    // 0x8014A7B4: b           L_8014A84C
    // 0x8014A7B8: sb          $zero, 0x148($s0)
    MEM_B(0X148, ctx->r16) = 0;
        goto L_8014A84C;
    // 0x8014A7B8: sb          $zero, 0x148($s0)
    MEM_B(0X148, ctx->r16) = 0;
    // 0x8014A7BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8014A7C0:
    // 0x8014A7C0: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8014A7C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014A7C8: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8014A7CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014A7D0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8014A7D4: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x8014A7D8: sw          $t9, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r25;
    // 0x8014A7DC: b           L_8014A84C
    // 0x8014A7E0: sb          $t0, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r8;
        goto L_8014A84C;
    // 0x8014A7E0: sb          $t0, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r8;
L_8014A7E4:
    // 0x8014A7E4: lw          $t1, 0x44($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X44);
    // 0x8014A7E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014A7EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8014A7F0: bne         $t1, $at, L_8014A80C
    if (ctx->r9 != ctx->r1) {
        // 0x8014A7F4: nop
    
            goto L_8014A80C;
    }
    // 0x8014A7F4: nop

    // 0x8014A7F8: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    // 0x8014A7FC: jal         0x800F4408
    // 0x8014A800: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x8014A800: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8014A804: b           L_8014A818
    // 0x8014A808: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
        goto L_8014A818;
    // 0x8014A808: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
L_8014A80C:
    // 0x8014A80C: jal         0x800F4428
    // 0x8014A810: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_2;
    // 0x8014A810: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    after_2:
    // 0x8014A814: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
L_8014A818:
    // 0x8014A818: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8014A81C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8014A820: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014A824: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8014A828: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8014A82C: add.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8014A830: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x8014A834: jal         0x800DE324
    // 0x8014A838: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    mpCommonSetFighterProjectFloor(rdram, ctx);
        goto after_3;
    // 0x8014A838: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x8014A83C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8014A840: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8014A844: sw          $t2, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r10;
    // 0x8014A848: sb          $t3, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r11;
L_8014A84C:
    // 0x8014A84C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014A850: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014A854: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8014A858: jr          $ra
    // 0x8014A85C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8014A85C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void itKamexCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180B1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80180B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180B24: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80180B28: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80180B2C: bnel        $a1, $zero, L_80180B54
    if (ctx->r5 != 0) {
        // 0x80180B30: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80180B54;
    }
    goto skip_0;
    // 0x80180B30: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x80180B34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80180B38: nop

    // 0x80180B3C: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80180B40: jal         0x80180964
    // 0x80180B44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itKamexAppearSetStatus(rdram, ctx);
        goto after_0;
    // 0x80180B44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80180B48: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80180B4C: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80180B50: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_80180B54:
    // 0x80180B54: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x80180B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180B5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80180B60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80180B64: jr          $ra
    // 0x80180B68: nop

    return;
    // 0x80180B68: nop

;}
RECOMP_FUNC void ifCommonBattlePausePlayerNumMakeSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113CF8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80113CFC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80113D00: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80113D04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80113D08: lw          $t8, 0xD54($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD54);
    // 0x80113D0C: lw          $t7, -0x10AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X10AC);
    // 0x80113D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80113D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113D18: jal         0x800CCFDC
    // 0x80113D1C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80113D1C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80113D20: lui         $at, 0x4355
    ctx->r1 = S32(0X4355 << 16);
    // 0x80113D24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80113D28: lui         $at, 0x433F
    ctx->r1 = S32(0X433F << 16);
    // 0x80113D2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80113D30: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80113D34: addiu       $t9, $zero, 0x201
    ctx->r25 = ADD32(0, 0X201);
    // 0x80113D38: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80113D3C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80113D40: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80113D44: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80113D48: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80113D4C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80113D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80113D58: jr          $ra
    // 0x80113D5C: nop

    return;
    // 0x80113D5C: nop

;}
RECOMP_FUNC void func_ovl8_80375E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375E00: jr          $ra
    // 0x80375E04: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    return;
    // 0x80375E04: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void SC1PGameBossWallpaper0ProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019136C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80191370: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80191374: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80191378: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8019137C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80191380: lw          $t3, 0x84($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X84);
    // 0x80191384: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80191388: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8019138C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80191390: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80191394: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80191398: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8019139C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801913A0: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x801913A4: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x801913A8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801913AC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801913B0: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x801913B4: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x801913B8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801913BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801913C0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801913C4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801913C8: andi        $t1, $t3, 0xFF
    ctx->r9 = ctx->r11 & 0XFF;
    // 0x801913CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801913D0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801913D4: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x801913D8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801913DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801913E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801913E4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801913E8: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x801913EC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x801913F0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801913F4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801913F8: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x801913FC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80191400: lbu         $t6, 0x2BD0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2BD0);
    // 0x80191404: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80191408: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x8019140C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80191410: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80191414: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80191418: lbu         $t4, 0x2BC0($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X2BC0);
    // 0x8019141C: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80191420: lbu         $t7, 0x2BC8($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2BC8);
    // 0x80191424: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x80191428: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8019142C: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80191430: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x80191434: or          $t8, $t6, $t4
    ctx->r24 = ctx->r14 | ctx->r12;
    // 0x80191438: or          $t5, $t8, $t1
    ctx->r13 = ctx->r24 | ctx->r9;
    // 0x8019143C: jal         0x80014768
    // 0x80191440: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x80191440: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    after_0:
    // 0x80191444: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80191448: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8019144C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191450: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80191454: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80191458: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019145C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80191460: ori         $t6, $t6, 0x49D8
    ctx->r14 = ctx->r14 | 0X49D8;
    // 0x80191464: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80191468: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8019146C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80191470: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191474: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80191478: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019147C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80191480: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191484: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80191488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019148C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191490: jr          $ra
    // 0x80191494: nop

    return;
    // 0x80191494: nop

;}
RECOMP_FUNC void func_ovl28_80134838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134838: jr          $ra
    // 0x8013483C: nop

    return;
    // 0x8013483C: nop

;}
RECOMP_FUNC void syAudioBnkfPatchSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E85C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E860: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
    // 0x8001E864: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E868: bnel        $t6, $zero, L_8001E8A4
    if (ctx->r14 != 0) {
        // 0x8001E86C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E8A4;
    }
    goto skip_0;
    // 0x8001E86C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001E870: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8001E874: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8001E878: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x8001E87C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x8001E880: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x8001E884: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x8001E888: sb          $t7, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r15;
    // 0x8001E88C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001E890: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8001E894: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    // 0x8001E898: jal         0x8001E8B0
    // 0x8001E89C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    syAudioBnkfPatchWaveTable(rdram, ctx);
        goto after_0;
    // 0x8001E89C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_0:
    // 0x8001E8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E8A4:
    // 0x8001E8A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E8A8: jr          $ra
    // 0x8001E8AC: nop

    return;
    // 0x8001E8AC: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwLandingSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801600EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801600F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801600F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801600F8: jal         0x800DEE98
    // 0x801600FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801600FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80160100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80160104: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80160108: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8016010C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80160110: jal         0x800E6F24
    // 0x80160114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80160114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80160118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016011C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80160120: jr          $ra
    // 0x80160124: nop

    return;
    // 0x80160124: nop

;}
RECOMP_FUNC void scStaffrollScrollThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134854: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80134858: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8013485C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134860: addiu       $a0, $a0, 0x679C
    ctx->r4 = ADD32(ctx->r4, 0X679C);
    // 0x80134864: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80134868: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8013486C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80134870: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80134874: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80134878: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8013487C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80134880: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80134884: jal         0x80133E68
    // 0x80134888: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    scStaffrollMakeJobGObj(rdram, ctx);
        goto after_0;
    // 0x80134888: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    after_0:
    // 0x8013488C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80134890: addiu       $s3, $s3, -0x5748
    ctx->r19 = ADD32(ctx->r19, -0X5748);
    // 0x80134894: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80134898: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x8013489C: slti        $at, $t6, 0x54
    ctx->r1 = SIGNED(ctx->r14) < 0X54 ? 1 : 0;
    // 0x801348A0: beq         $at, $zero, L_80134940
    if (ctx->r1 == 0) {
        // 0x801348A4: lui         $at, 0x8014
        ctx->r1 = S32(0X8014 << 16);
            goto L_80134940;
    }
    // 0x801348A4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801348A8: lwc1        $f22, -0x5840($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5840);
    // 0x801348AC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801348B0: lwc1        $f20, -0x583C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X583C);
L_801348B4:
    // 0x801348B4: beql        $s1, $zero, L_801348C8
    if (ctx->r17 == 0) {
        // 0x801348B8: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_801348C8;
    }
    goto skip_0;
    // 0x801348B8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_0:
    // 0x801348BC: b           L_801348C8
    // 0x801348C0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_801348C8;
    // 0x801348C0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x801348C4: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_801348C8:
    // 0x801348C8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801348CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801348D0: nop

    // 0x801348D4: bc1f        L_80134928
    if (!c1cs) {
        // 0x801348D8: nop
    
            goto L_80134928;
    }
    // 0x801348D8: nop

    // 0x801348DC: beql        $s1, $zero, L_80134918
    if (ctx->r17 == 0) {
        // 0x801348E0: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80134918;
    }
    goto skip_1;
    // 0x801348E0: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    skip_1:
    // 0x801348E4: jal         0x80133F68
    // 0x801348E8: nop

    scStaffrollMakeNameGObjAndDObjs(rdram, ctx);
        goto after_1;
    // 0x801348E8: nop

    after_1:
    // 0x801348EC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x801348F0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x801348F4: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x801348F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801348FC: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80134900: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x80134904: bne         $t9, $t8, L_80134928
    if (ctx->r25 != ctx->r24) {
        // 0x80134908: nop
    
            goto L_80134928;
    }
    // 0x80134908: nop

    // 0x8013490C: b           L_80134928
    // 0x80134910: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80134928;
    // 0x80134910: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80134914: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
L_80134918:
    // 0x80134918: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8013491C: jal         0x80133E68
    // 0x80134920: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    scStaffrollMakeJobGObj(rdram, ctx);
        goto after_2;
    // 0x80134920: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    after_2:
    // 0x80134924: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
L_80134928:
    // 0x80134928: jal         0x8000B1E8
    // 0x8013492C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_3;
    // 0x8013492C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80134930: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x80134934: slti        $at, $t1, 0x54
    ctx->r1 = SIGNED(ctx->r9) < 0X54 ? 1 : 0;
    // 0x80134938: bne         $at, $zero, L_801348B4
    if (ctx->r1 != 0) {
        // 0x8013493C: nop
    
            goto L_801348B4;
    }
    // 0x8013493C: nop

L_80134940:
    // 0x80134940: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80134944: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80134948: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013494C: lw          $s0, 0x84($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X84);
    // 0x80134950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134954: sw          $t3, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r11;
    // 0x80134958: jal         0x80009A84
    // 0x8013495C: sw          $zero, -0x5738($at)
    MEM_W(-0X5738, ctx->r1) = 0;
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x8013495C: sw          $zero, -0x5738($at)
    MEM_W(-0X5738, ctx->r1) = 0;
    after_4:
    // 0x80134960: jal         0x8000B1E8
    // 0x80134964: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_5;
    // 0x80134964: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80134968: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8013496C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80134970: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80134974: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80134978: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8013497C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80134980: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80134984: jr          $ra
    // 0x80134988: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80134988: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNReleaseSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F570: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F578: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F57C: jal         0x800DEEC8
    // 0x8015F580: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015F580: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015F584: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015F588: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8015F58C: addiu       $a1, $zero, 0x12E
    ctx->r5 = ADD32(0, 0X12E);
    // 0x8015F590: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F594: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015F598: jal         0x800E6F24
    // 0x8015F59C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015F59C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015F5A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F5A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F5A8: jr          $ra
    // 0x8015F5AC: nop

    return;
    // 0x8015F5AC: nop

;}
RECOMP_FUNC void ftCommonAttackLw3SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FD14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014FD18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014FD1C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8014FD20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014FD24: jal         0x80146064
    // 0x8014FD28: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftCommonGetCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014FD28: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014FD2C: bne         $v0, $zero, L_8014FD60
    if (ctx->r2 != 0) {
        // 0x8014FD30: lui         $t7, 0x8015
        ctx->r15 = S32(0X8015 << 16);
            goto L_8014FD60;
    }
    // 0x8014FD30: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8014FD34: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8014FD38: addiu       $t7, $t7, -0x334
    ctx->r15 = ADD32(ctx->r15, -0X334);
    // 0x8014FD3C: addiu       $a1, $zero, 0xC9
    ctx->r5 = ADD32(0, 0XC9);
    // 0x8014FD40: sw          $t7, 0xA0C($t8)
    MEM_W(0XA0C, ctx->r24) = ctx->r15;
    // 0x8014FD44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014FD48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014FD4C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014FD50: jal         0x800E6F24
    // 0x8014FD54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014FD54: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8014FD58: jal         0x800E0830
    // 0x8014FD5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014FD5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_8014FD60:
    // 0x8014FD60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014FD64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014FD68: jr          $ra
    // 0x8014FD6C: nop

    return;
    // 0x8014FD6C: nop

;}
RECOMP_FUNC void mpCollisionSetYakumonoOffID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC604: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC608: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC60C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FC610: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FC614: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC618: beq         $a0, $at, L_800FC62C
    if (ctx->r4 == ctx->r1) {
        // 0x800FC61C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FC62C;
    }
    // 0x800FC61C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC620: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FC624: bne         $a0, $at, L_800FC650
    if (ctx->r4 != ctx->r1) {
        // 0x800FC628: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800FC650;
    }
    // 0x800FC628: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
L_800FC62C:
    // 0x800FC62C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC630: addiu       $s0, $s0, 0x6DC
    ctx->r16 = ADD32(ctx->r16, 0X6DC);
    // 0x800FC634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC638:
    // 0x800FC638: jal         0x80023624
    // 0x800FC63C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FC63C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FC640: jal         0x800A3040
    // 0x800FC644: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FC644: nop

    after_1:
    // 0x800FC648: b           L_800FC638
    // 0x800FC64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FC638;
    // 0x800FC64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC650:
    // 0x800FC650: lw          $t7, 0x1304($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1304);
    // 0x800FC654: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800FC658: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800FC65C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800FC660: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800FC664: sw          $t6, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r14;
    // 0x800FC668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC66C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC670: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC674: jr          $ra
    // 0x800FC678: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FC678: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mpCollisionGetFCAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F46D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F46D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F46D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F46DC: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x800F46E0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800F46E4: subu        $t9, $a3, $a1
    ctx->r25 = SUB32(ctx->r7, ctx->r5);
    // 0x800F46E8: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x800F46EC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800F46F0: nop

    // 0x800F46F4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F46F8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F46FC: nop

    // 0x800F4700: bc1fl       L_800F4728
    if (!c1cs) {
        // 0x800F4704: mtc1        $t9, $f10
        ctx->f10.u32l = ctx->r25;
            goto L_800F4728;
    }
    goto skip_0;
    // 0x800F4704: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    skip_0:
    // 0x800F4708: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x800F470C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800F4710: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800F4714: nop

    // 0x800F4718: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F471C: b           L_800F479C
    // 0x800F4720: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
        goto L_800F479C;
    // 0x800F4720: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800F4724: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
L_800F4728:
    // 0x800F4728: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F472C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F4730: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F4734: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F4738: div.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800F473C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800F4740: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F4744: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800F4748: jal         0x80033510
    // 0x800F474C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F474C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x800F4750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F4754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F4758: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800F475C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F4760: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800F4764: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F4768: bgez        $t0, L_800F4788
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800F476C: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_800F4788;
    }
    // 0x800F476C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x800F4770: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x800F4774: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    // 0x800F4778: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800F477C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800F4780: b           L_800F4794
    // 0x800F4784: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
        goto L_800F4794;
    // 0x800F4784: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
L_800F4788:
    // 0x800F4788: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800F478C: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x800F4790: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_800F4794:
    // 0x800F4794: jal         0x80018EE0
    // 0x800F4798: nop

    syVectorNorm3D(rdram, ctx);
        goto after_1;
    // 0x800F4798: nop

    after_1:
L_800F479C:
    // 0x800F479C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F47A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F47A4: jr          $ra
    // 0x800F47A8: nop

    return;
    // 0x800F47A8: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNReleaseProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F2BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F2C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F2C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015F2C8: jal         0x8015F248
    // 0x8015F2CC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftKirbyCopyYoshiSpecialAirNCatchUpdateCaptureVars(rdram, ctx);
        goto after_0;
    // 0x8015F2CC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015F2D0: jal         0x800D94C4
    // 0x8015F2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x8015F2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015F2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F2DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F2E0: jr          $ra
    // 0x8015F2E4: nop

    return;
    // 0x8015F2E4: nop

;}
RECOMP_FUNC void func_ovl8_8037BBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BBF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037BBF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037BBF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037BBFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037BC00: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037BC04: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8037BC08: jal         0x803717A0
    // 0x8037BC0C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037BC0C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_0:
    // 0x8037BC10: beq         $v0, $zero, L_8037BC34
    if (ctx->r2 == 0) {
        // 0x8037BC14: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037BC34;
    }
    // 0x8037BC14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037BC18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037BC1C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8037BC20: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8037BC24: jal         0x803759F0
    // 0x8037BC28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_ovl8_803759F0(rdram, ctx);
        goto after_1;
    // 0x8037BC28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8037BC2C: b           L_8037BC38
    // 0x8037BC30: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8037BC38;
    // 0x8037BC30: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8037BC34:
    // 0x8037BC34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037BC38:
    // 0x8037BC38: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037BC3C: lui         $t6, 0x8038
    ctx->r14 = S32(0X8038 << 16);
    // 0x8037BC40: addiu       $v0, $v0, -0x1034
    ctx->r2 = ADD32(ctx->r2, -0X1034);
    // 0x8037BC44: addiu       $t6, $t6, -0x40CC
    ctx->r14 = ADD32(ctx->r14, -0X40CC);
    // 0x8037BC48: lui         $a3, 0x8038
    ctx->r7 = S32(0X8038 << 16);
    // 0x8037BC4C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8037BC50: addiu       $a3, $a3, -0x4138
    ctx->r7 = ADD32(ctx->r7, -0X4138);
    // 0x8037BC54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037BC58: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8037BC5C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8037BC60: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8037BC64: jal         0x803723AC
    // 0x8037BC68: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_ovl8_803723AC(rdram, ctx);
        goto after_2;
    // 0x8037BC68: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8037BC6C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037BC70: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
    // 0x8037BC74: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8037BC78: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x8037BC7C: jal         0x80375B8C
    // 0x8037BC80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_ovl8_80375B8C(rdram, ctx);
        goto after_3;
    // 0x8037BC80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x8037BC84: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8037BC88: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037BC8C: beq         $v1, $zero, L_8037BC9C
    if (ctx->r3 == 0) {
        // 0x8037BC90: nop
    
            goto L_8037BC9C;
    }
    // 0x8037BC90: nop

    // 0x8037BC94: b           L_8037BCA8
    // 0x8037BC98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8037BCA8;
    // 0x8037BC98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8037BC9C:
    // 0x8037BC9C: jal         0x80375C54
    // 0x8037BCA0: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
    func_ovl8_80375C54(rdram, ctx);
        goto after_4;
    // 0x8037BCA0: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
    after_4:
    // 0x8037BCA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037BCA8:
    // 0x8037BCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037BCAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037BCB0: jr          $ra
    // 0x8037BCB4: nop

    return;
    // 0x8037BCB4: nop

;}
RECOMP_FUNC void wpLinkBoomerangUpdateVelLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CF48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016CF4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016CF50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016CF54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8016CF58: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8016CF5C: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8016CF60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016CF64: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8016CF68: nop

    // 0x8016CF6C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8016CF70: jal         0x80033510
    // 0x8016CF74: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8016CF74: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8016CF78: jal         0x80035CD0
    // 0x8016CF7C: lwc1        $f12, 0x2A4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A4);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8016CF7C: lwc1        $f12, 0x2A4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A4);
    after_1:
    // 0x8016CF80: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8016CF84: lwc1        $f12, 0x2A4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A4);
    // 0x8016CF88: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8016CF8C: jal         0x800303F0
    // 0x8016CF90: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8016CF90: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8016CF94: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8016CF98: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CF9C: lwc1        $f2, 0x2A4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2A4);
    // 0x8016CFA0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8016CFA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8016CFA8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8016CFAC: lwc1        $f4, -0x3478($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3478);
    // 0x8016CFB0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CFB4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8016CFB8: nop

    // 0x8016CFBC: bc1fl       L_8016CFE8
    if (!c1cs) {
        // 0x8016CFC0: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_8016CFE8;
    }
    goto skip_0;
    // 0x8016CFC0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    skip_0:
    // 0x8016CFC4: lwc1        $f6, -0x3474($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3474);
    // 0x8016CFC8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8016CFCC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8016CFD0: nop

    // 0x8016CFD4: bc1fl       L_8016CFE8
    if (!c1cs) {
        // 0x8016CFD8: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_8016CFE8;
    }
    goto skip_1;
    // 0x8016CFD8: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    skip_1:
    // 0x8016CFDC: b           L_8016CFE8
    // 0x8016CFE0: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
        goto L_8016CFE8;
    // 0x8016CFE0: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x8016CFE4: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
L_8016CFE8:
    // 0x8016CFE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016CFEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016CFF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016CFF4: jr          $ra
    // 0x8016CFF8: nop

    return;
    // 0x8016CFF8: nop

;}
RECOMP_FUNC void itHammerFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801761F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801761FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80176204: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80176208: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017620C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80176210: jal         0x80173F78
    // 0x80176214: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80176214: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80176218: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017621C: addiu       $a1, $a1, -0x625C
    ctx->r5 = ADD32(ctx->r5, -0X625C);
    // 0x80176220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80176224: jal         0x80172EC8
    // 0x80176228: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80176228: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017622C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176234: jr          $ra
    // 0x80176238: nop

    return;
    // 0x80176238: nop

;}
RECOMP_FUNC void ftLinkSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801638EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801638F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801638F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801638F8: jal         0x800DEE98
    // 0x801638FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801638FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80163900: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80163904: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80163908: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8016390C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80163910: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80163914: jal         0x800E6F24
    // 0x80163918: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80163918: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8016391C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163920: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163924: jr          $ra
    // 0x80163928: nop

    return;
    // 0x80163928: nop

;}
RECOMP_FUNC void mpProcessSetCollProjectFloorID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9FCC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D9FD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D9FD4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D9FD8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800D9FDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D9FE0: addiu       $t6, $s0, 0x80
    ctx->r14 = ADD32(ctx->r16, 0X80);
    // 0x800D9FE4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800D9FE8: addiu       $a1, $s0, 0x74
    ctx->r5 = ADD32(ctx->r16, 0X74);
    // 0x800D9FEC: addiu       $a2, $s0, 0x78
    ctx->r6 = ADD32(ctx->r16, 0X78);
    // 0x800D9FF0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9FF4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800D9FF8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800D9FFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800DA000: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800DA004: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DA008: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    // 0x800DA00C: jal         0x800F9348
    // 0x800DA010: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckProjectFloor(rdram, ctx);
        goto after_0;
    // 0x800DA010: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800DA014: bne         $v0, $zero, L_800DA020
    if (ctx->r2 != 0) {
        // 0x800DA018: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_800DA020;
    }
    // 0x800DA018: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800DA01C: sw          $t7, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r15;
L_800DA020:
    // 0x800DA020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DA024: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DA028: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800DA02C: jr          $ra
    // 0x800DA030: nop

    return;
    // 0x800DA030: nop

;}
RECOMP_FUNC void itPakkunAppearUpdateDamageColl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D1DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017D1E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D1E4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017D1E8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017D1EC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8017D1F0: lwc1        $f6, 0x354($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X354);
    // 0x8017D1F4: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8017D1F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8017D1FC: lui         $at, 0x4375
    ctx->r1 = S32(0X4375 << 16);
    // 0x8017D200: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017D204: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D208: nop

    // 0x8017D20C: add.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8017D210: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    // 0x8017D214: nop

    // 0x8017D218: bc1fl       L_8017D230
    if (!c1cs) {
        // 0x8017D21C: lw          $t7, 0x248($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X248);
            goto L_8017D230;
    }
    goto skip_0;
    // 0x8017D21C: lw          $t7, 0x248($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X248);
    skip_0:
    // 0x8017D220: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x8017D224: b           L_8017D288
    // 0x8017D228: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
        goto L_8017D288;
    // 0x8017D228: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x8017D22C: lw          $t7, 0x248($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X248);
L_8017D230:
    // 0x8017D230: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017D234: bnel        $t7, $zero, L_8017D268
    if (ctx->r15 != 0) {
        // 0x8017D238: sub.s       $f10, $f12, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_8017D268;
    }
    goto skip_1;
    // 0x8017D238: sub.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f14.fl;
    skip_1:
    // 0x8017D23C: sw          $t8, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r24;
    // 0x8017D240: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8017D244: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x8017D248: jal         0x8017275C
    // 0x8017D24C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_0;
    // 0x8017D24C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017D250: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8017D254: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8017D258: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8017D25C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017D260: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8017D264: sub.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f14.fl;
L_8017D268:
    // 0x8017D268: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D26C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D270: nop

    // 0x8017D274: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017D278: add.s       $f18, $f0, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8017D27C: swc1        $f0, 0x25C($v0)
    MEM_W(0X25C, ctx->r2) = ctx->f0.u32l;
    // 0x8017D280: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8017D284: swc1        $f4, 0x250($v0)
    MEM_W(0X250, ctx->r2) = ctx->f4.u32l;
L_8017D288:
    // 0x8017D288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D28C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D290: jr          $ra
    // 0x8017D294: nop

    return;
    // 0x8017D294: nop

;}
RECOMP_FUNC void ftKirbyCopyNessSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155CAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80155CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155CB4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155CB8: jal         0x800DDDDC
    // 0x80155CBC: addiu       $a1, $a1, 0x5D48
    ctx->r5 = ADD32(ctx->r5, 0X5D48);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80155CBC: addiu       $a1, $a1, 0x5D48
    ctx->r5 = ADD32(ctx->r5, 0X5D48);
    after_0:
    // 0x80155CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155CC8: jr          $ra
    // 0x80155CCC: nop

    return;
    // 0x80155CCC: nop

;}
RECOMP_FUNC void ftSamusSpecialLwInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E218: jr          $ra
    // 0x8015E21C: sw          $zero, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = 0;
    return;
    // 0x8015E21C: sw          $zero, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = 0;
;}
RECOMP_FUNC void ftNessSpecialAirLwProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015530C: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80155310: lw          $t6, 0x9C8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X9C8);
    // 0x80155314: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80155318: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8015531C: lw          $v0, 0xB20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB20);
    // 0x80155320: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80155324: beq         $v0, $zero, L_80155334
    if (ctx->r2 == 0) {
        // 0x80155328: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80155334;
    }
    // 0x80155328: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8015532C: b           L_8015534C
    // 0x80155330: sw          $t7, 0xB20($a3)
    MEM_W(0XB20, ctx->r7) = ctx->r15;
        goto L_8015534C;
    // 0x80155330: sw          $t7, 0xB20($a3)
    MEM_W(0XB20, ctx->r7) = ctx->r15;
L_80155334:
    // 0x80155334: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80155338: lw          $a2, 0x5C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X5C);
    // 0x8015533C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80155340: jal         0x800D8D68
    // 0x80155344: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80155344: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80155348: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8015534C:
    // 0x8015534C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80155350: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80155354: jal         0x800D8FA8
    // 0x80155358: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x80155358: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8015535C: bne         $v0, $zero, L_80155370
    if (ctx->r2 != 0) {
        // 0x80155360: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80155370;
    }
    // 0x80155360: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80155364: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80155368: jal         0x800D9074
    // 0x8015536C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x8015536C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80155370:
    // 0x80155370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155378: jr          $ra
    // 0x8015537C: nop

    return;
    // 0x8015537C: nop

;}
RECOMP_FUNC void itIwarkCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DB18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017DB1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DB20: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017DB24: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017DB28: bnel        $a1, $zero, L_8017DB44
    if (ctx->r5 != 0) {
        // 0x8017DB2C: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8017DB44;
    }
    goto skip_0;
    // 0x8017DB2C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x8017DB30: jal         0x8017DAD8
    // 0x8017DB34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itIwarkFlySetStatus(rdram, ctx);
        goto after_0;
    // 0x8017DB34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017DB38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DB3C: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017DB40: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_8017DB44:
    // 0x8017DB44: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8017DB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DB4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017DB50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017DB54: jr          $ra
    // 0x8017DB58: nop

    return;
    // 0x8017DB58: nop

;}
RECOMP_FUNC void lbCommonDrawSObjBitmap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB7D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CB7D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CB7DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CB7E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CB7E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800CB7E8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800CB7EC: lw          $t0, 0x8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X8);
    // 0x800CB7F0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CB7F4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800CB7F8: bne         $t0, $zero, L_800CB81C
    if (ctx->r8 != 0) {
        // 0x800CB7FC: lw          $a2, 0x54($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X54);
            goto L_800CB81C;
    }
    // 0x800CB7FC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
L_800CB800:
    // 0x800CB800: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800CB804: jal         0x80023624
    // 0x800CB808: addiu       $a0, $a0, 0x5E40
    ctx->r4 = ADD32(ctx->r4, 0X5E40);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800CB808: addiu       $a0, $a0, 0x5E40
    ctx->r4 = ADD32(ctx->r4, 0X5E40);
    after_0:
    // 0x800CB80C: jal         0x800A3040
    // 0x800CB810: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800CB810: nop

    after_1:
    // 0x800CB814: b           L_800CB800
    // 0x800CB818: nop

        goto L_800CB800;
    // 0x800CB818: nop

L_800CB81C:
    // 0x800CB81C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800CB820: lw          $a0, 0x62C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X62C8);
    // 0x800CB824: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800CB828: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800CB82C: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CB830: bnel        $at, $zero, L_800CC108
    if (ctx->r1 != 0) {
        // 0x800CB834: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CC108;
    }
    goto skip_0;
    // 0x800CB834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800CB838: lhu         $v1, 0x14($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X14);
    // 0x800CB83C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800CB840: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB844: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x800CB848: beq         $t7, $zero, L_800CB854
    if (ctx->r15 == 0) {
        // 0x800CB84C: andi        $t9, $v1, 0x80
        ctx->r25 = ctx->r3 & 0X80;
            goto L_800CB854;
    }
    // 0x800CB84C: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x800CB850: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800CB854:
    // 0x800CB854: beq         $t9, $zero, L_800CB86C
    if (ctx->r25 == 0) {
        // 0x800CB858: lw          $v0, 0x0($t8)
        ctx->r2 = MEM_W(ctx->r24, 0X0);
            goto L_800CB86C;
    }
    // 0x800CB858: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800CB85C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800CB860: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x800CB864: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CB868: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
L_800CB86C:
    // 0x800CB86C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CB870: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800CB874: lw          $v1, 0x62C4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X62C4);
    // 0x800CB878: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800CB87C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB880: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800CB884: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x800CB888: beq         $at, $zero, L_800CB8B8
    if (ctx->r1 == 0) {
        // 0x800CB88C: lh          $t3, 0xC($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XC);
            goto L_800CB8B8;
    }
    // 0x800CB88C: lh          $t3, 0xC($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XC);
    // 0x800CB890: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800CB894: subu        $t7, $v1, $a1
    ctx->r15 = SUB32(ctx->r3, ctx->r5);
    // 0x800CB898: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800CB89C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB8A0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800CB8A4: mflo        $t9
    ctx->r25 = lo;
    // 0x800CB8A8: sra         $t6, $t9, 5
    ctx->r14 = S32(SIGNED(ctx->r25) >> 5);
    // 0x800CB8AC: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800CB8B0: b           L_800CB8C4
    // 0x800CB8B4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_800CB8C4;
    // 0x800CB8B4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_800CB8B8:
    // 0x800CB8B8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800CB8BC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800CB8C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
L_800CB8C4:
    // 0x800CB8C4: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB8C8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CB8CC: beq         $at, $zero, L_800CB8FC
    if (ctx->r1 == 0) {
        // 0x800CB8D0: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800CB8FC;
    }
    // 0x800CB8D0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800CB8D4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800CB8D8: subu        $t6, $a0, $v1
    ctx->r14 = SUB32(ctx->r4, ctx->r3);
    // 0x800CB8DC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800CB8E0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB8E4: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800CB8E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800CB8EC: sra         $t9, $t8, 5
    ctx->r25 = S32(SIGNED(ctx->r24) >> 5);
    // 0x800CB8F0: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x800CB8F4: b           L_800CB904
    // 0x800CB8F8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_800CB904;
    // 0x800CB8F8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_800CB8FC:
    // 0x800CB8FC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800CB900: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_800CB904:
    // 0x800CB904: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CB908: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800CB90C: lw          $v1, 0x62BC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X62BC);
    // 0x800CB910: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800CB914: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CB918: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800CB91C: bne         $at, $zero, L_800CB92C
    if (ctx->r1 != 0) {
        // 0x800CB920: sll         $ra, $a0, 2
        ctx->r31 = S32(ctx->r4 << 2);
            goto L_800CB92C;
    }
    // 0x800CB920: sll         $ra, $a0, 2
    ctx->r31 = S32(ctx->r4 << 2);
    // 0x800CB924: b           L_800CB92C
    // 0x800CB928: sll         $ra, $v1, 2
    ctx->r31 = S32(ctx->r3 << 2);
        goto L_800CB92C;
    // 0x800CB928: sll         $ra, $v1, 2
    ctx->r31 = S32(ctx->r3 << 2);
L_800CB92C:
    // 0x800CB92C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CB930: lw          $v1, 0x62C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X62C0);
    // 0x800CB934: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800CB938: bne         $at, $zero, L_800CB948
    if (ctx->r1 != 0) {
        // 0x800CB93C: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800CB948;
    }
    // 0x800CB93C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800CB940: b           L_800CB94C
    // 0x800CB944: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_800CB94C;
    // 0x800CB944: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_800CB948:
    // 0x800CB948: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_800CB94C:
    // 0x800CB94C: lw          $t6, 0x62B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X62B4);
    // 0x800CB950: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800CB954: beql        $t6, $t0, L_800CC068
    if (ctx->r14 == ctx->r8) {
        // 0x800CB958: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_800CC068;
    }
    goto skip_1;
    // 0x800CB958: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x800CB95C: lbu         $v1, 0x31($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X31);
    // 0x800CB960: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CB964: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800CB968: beql        $v1, $zero, L_800CB9A0
    if (ctx->r3 == 0) {
        // 0x800CB96C: lbu         $t8, 0x30($t1)
        ctx->r24 = MEM_BU(ctx->r9, 0X30);
            goto L_800CB9A0;
    }
    goto skip_2;
    // 0x800CB96C: lbu         $t8, 0x30($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X30);
    skip_2:
    // 0x800CB970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CB974: beq         $v1, $at, L_800CBB5C
    if (ctx->r3 == ctx->r1) {
        // 0x800CB978: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_800CBB5C;
    }
    // 0x800CB978: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CB97C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CB980: beq         $v1, $at, L_800CBD24
    if (ctx->r3 == ctx->r1) {
        // 0x800CB984: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_800CBD24;
    }
    // 0x800CB984: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CB988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CB98C: beq         $v1, $at, L_800CBEE4
    if (ctx->r3 == ctx->r1) {
        // 0x800CB990: lui         $t4, 0x700
        ctx->r12 = S32(0X700 << 16);
            goto L_800CBEE4;
    }
    // 0x800CB990: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x800CB994: b           L_800CC05C
    // 0x800CB998: nop

        goto L_800CC05C;
    // 0x800CB998: nop

    // 0x800CB99C: lbu         $t8, 0x30($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X30);
L_800CB9A0:
    // 0x800CB9A0: lui         $t0, 0x10
    ctx->r8 = S32(0X10 << 16);
    // 0x800CB9A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CB9A8: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x800CB9AC: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800CB9B0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CB9B4: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x800CB9B8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CB9BC: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800CB9C0: lui         $t5, 0xF500
    ctx->r13 = S32(0XF500 << 16);
    // 0x800CB9C4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CB9C8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CB9CC: lbu         $t6, 0x30($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X30);
    // 0x800CB9D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CB9D4: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x800CB9D8: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800CB9DC: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x800CB9E0: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x800CB9E4: or          $t6, $t9, $t0
    ctx->r14 = ctx->r25 | ctx->r8;
    // 0x800CB9E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CB9EC: lbu         $t7, 0x64($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X64);
    // 0x800CB9F0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CB9F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CB9F8: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800CB9FC: lbu         $t7, 0x66($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X66);
    // 0x800CBA00: sll         $t9, $t8, 18
    ctx->r25 = S32(ctx->r24 << 18);
    // 0x800CBA04: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x800CBA08: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x800CBA0C: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x800CBA10: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x800CBA14: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800CBA18: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBA1C: andi        $t6, $t8, 0x3
    ctx->r14 = ctx->r24 & 0X3;
    // 0x800CBA20: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x800CBA24: lbu         $t6, 0x67($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X67);
    // 0x800CBA28: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800CBA2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800CBA30: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800CBA34: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800CBA38: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800CBA3C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CBA40: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800CBA44: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CBA48: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800CBA4C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800CBA50: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800CBA54: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x800CBA58: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBA5C: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
    // 0x800CBA60: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBA64: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800CBA68: mflo        $a0
    ctx->r4 = lo;
    // 0x800CBA6C: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800CBA70: sra         $a0, $a0, 2
    ctx->r4 = S32(SIGNED(ctx->r4) >> 2);
    // 0x800CBA74: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CBA78: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x800CBA7C: beq         $at, $zero, L_800CBA8C
    if (ctx->r1 == 0) {
        // 0x800CBA80: nop
    
            goto L_800CBA8C;
    }
    // 0x800CBA80: nop

    // 0x800CBA84: b           L_800CBA8C
    // 0x800CBA88: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_800CBA8C;
    // 0x800CBA88: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800CBA8C:
    // 0x800CBA8C: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x800CBA90: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800CBA94: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x800CBA98: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800CBA9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CBAA0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800CBAA4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CBAA8: lbu         $t6, 0x30($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X30);
    // 0x800CBAAC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBAB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CBAB4: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800CBAB8: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x800CBABC: sra         $t6, $t2, 1
    ctx->r14 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800CBAC0: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800CBAC4: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x800CBAC8: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800CBACC: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x800CBAD0: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800CBAD4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800CBAD8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CBADC: lbu         $t6, 0x64($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X64);
    // 0x800CBAE0: lbu         $t8, 0x66($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X66);
    // 0x800CBAE4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBAE8: andi        $t9, $t6, 0x3
    ctx->r25 = ctx->r14 & 0X3;
    // 0x800CBAEC: sll         $t7, $t9, 18
    ctx->r15 = S32(ctx->r25 << 18);
    // 0x800CBAF0: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800CBAF4: sll         $t9, $t6, 14
    ctx->r25 = S32(ctx->r14 << 14);
    // 0x800CBAF8: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x800CBAFC: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800CBB00: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CBB04: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x800CBB08: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800CBB0C: lbu         $t7, 0x67($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X67);
    // 0x800CBB10: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800CBB14: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBB18: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x800CBB1C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800CBB20: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800CBB24: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x800CBB28: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800CBB2C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800CBB30: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800CBB34: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800CBB38: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800CBB3C: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x800CBB40: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800CBB44: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800CBB48: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800CBB4C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800CBB50: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800CBB54: b           L_800CC05C
    // 0x800CBB58: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
        goto L_800CC05C;
    // 0x800CBB58: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
L_800CBB5C:
    // 0x800CBB5C: lbu         $t9, 0x30($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X30);
    // 0x800CBB60: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800CBB64: lui         $t0, 0x10
    ctx->r8 = S32(0X10 << 16);
    // 0x800CBB68: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800CBB6C: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800CBB70: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800CBB74: or          $t9, $t6, $t0
    ctx->r25 = ctx->r14 | ctx->r8;
    // 0x800CBB78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CBB7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800CBB80: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800CBB84: lui         $t5, 0xF500
    ctx->r13 = S32(0XF500 << 16);
    // 0x800CBB88: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBB8C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800CBB90: lbu         $t7, 0x30($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X30);
    // 0x800CBB94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CBB98: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x800CBB9C: andi        $t6, $t7, 0x7
    ctx->r14 = ctx->r15 & 0X7;
    // 0x800CBBA0: sll         $t9, $t6, 21
    ctx->r25 = S32(ctx->r14 << 21);
    // 0x800CBBA4: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800CBBA8: or          $t7, $t8, $t0
    ctx->r15 = ctx->r24 | ctx->r8;
    // 0x800CBBAC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CBBB0: lbu         $t6, 0x64($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X64);
    // 0x800CBBB4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBBB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CBBBC: andi        $t9, $t6, 0x3
    ctx->r25 = ctx->r14 & 0X3;
    // 0x800CBBC0: lbu         $t6, 0x66($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X66);
    // 0x800CBBC4: sll         $t8, $t9, 18
    ctx->r24 = S32(ctx->r25 << 18);
    // 0x800CBBC8: or          $t7, $t8, $t4
    ctx->r15 = ctx->r24 | ctx->r12;
    // 0x800CBBCC: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x800CBBD0: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x800CBBD4: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x800CBBD8: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800CBBDC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBBE0: andi        $t7, $t9, 0x3
    ctx->r15 = ctx->r25 & 0X3;
    // 0x800CBBE4: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800CBBE8: lbu         $t7, 0x67($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X67);
    // 0x800CBBEC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800CBBF0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800CBBF4: andi        $t6, $t7, 0xF
    ctx->r14 = ctx->r15 & 0XF;
    // 0x800CBBF8: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800CBBFC: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800CBC00: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CBC04: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800CBC08: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800CBC0C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800CBC10: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800CBC14: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800CBC18: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x800CBC1C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBC20: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
    // 0x800CBC24: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBC28: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800CBC2C: mflo        $a0
    ctx->r4 = lo;
    // 0x800CBC30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CBC34: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800CBC38: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CBC3C: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x800CBC40: beq         $at, $zero, L_800CBC50
    if (ctx->r1 == 0) {
        // 0x800CBC44: nop
    
            goto L_800CBC50;
    }
    // 0x800CBC44: nop

    // 0x800CBC48: b           L_800CBC50
    // 0x800CBC4C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_800CBC50;
    // 0x800CBC4C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800CBC50:
    // 0x800CBC50: andi        $t7, $v1, 0xFFF
    ctx->r15 = ctx->r3 & 0XFFF;
    // 0x800CBC54: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800CBC58: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x800CBC5C: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800CBC60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CBC64: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CBC68: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CBC6C: lbu         $t7, 0x30($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X30);
    // 0x800CBC70: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800CBC74: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBC78: andi        $t6, $t7, 0x7
    ctx->r14 = ctx->r15 & 0X7;
    // 0x800CBC7C: sll         $t9, $t6, 21
    ctx->r25 = S32(ctx->r14 << 21);
    // 0x800CBC80: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800CBC84: addiu       $t6, $t2, 0x7
    ctx->r14 = ADD32(ctx->r10, 0X7);
    // 0x800CBC88: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800CBC8C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800CBC90: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x800CBC94: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x800CBC98: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800CBC9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CBCA0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800CBCA4: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x800CBCA8: lbu         $t9, 0x66($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X66);
    // 0x800CBCAC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBCB0: andi        $t7, $t8, 0x3
    ctx->r15 = ctx->r24 & 0X3;
    // 0x800CBCB4: sll         $t6, $t7, 18
    ctx->r14 = S32(ctx->r15 << 18);
    // 0x800CBCB8: andi        $t8, $t9, 0xF
    ctx->r24 = ctx->r25 & 0XF;
    // 0x800CBCBC: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x800CBCC0: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x800CBCC4: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800CBCC8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CBCCC: andi        $t6, $t8, 0x3
    ctx->r14 = ctx->r24 & 0X3;
    // 0x800CBCD0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800CBCD4: lbu         $t6, 0x67($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X67);
    // 0x800CBCD8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800CBCDC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBCE0: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x800CBCE4: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x800CBCE8: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800CBCEC: addiu       $t8, $t2, -0x1
    ctx->r24 = ADD32(ctx->r10, -0X1);
    // 0x800CBCF0: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800CBCF4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800CBCF8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x800CBCFC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800CBD00: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CBD04: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x800CBD08: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800CBD0C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x800CBD10: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x800CBD14: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800CBD18: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800CBD1C: b           L_800CC05C
    // 0x800CBD20: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
        goto L_800CC05C;
    // 0x800CBD20: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
L_800CBD24:
    // 0x800CBD24: lbu         $t7, 0x30($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X30);
    // 0x800CBD28: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800CBD2C: lui         $t0, 0x10
    ctx->r8 = S32(0X10 << 16);
    // 0x800CBD30: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800CBD34: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800CBD38: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800CBD3C: or          $t7, $t8, $t0
    ctx->r15 = ctx->r24 | ctx->r8;
    // 0x800CBD40: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CBD44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800CBD48: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800CBD4C: lui         $t5, 0xF500
    ctx->r13 = S32(0XF500 << 16);
    // 0x800CBD50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBD54: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CBD58: lbu         $t6, 0x30($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X30);
    // 0x800CBD5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CBD60: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x800CBD64: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800CBD68: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800CBD6C: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800CBD70: or          $t6, $t9, $t0
    ctx->r14 = ctx->r25 | ctx->r8;
    // 0x800CBD74: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CBD78: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x800CBD7C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBD80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CBD84: andi        $t7, $t8, 0x3
    ctx->r15 = ctx->r24 & 0X3;
    // 0x800CBD88: lbu         $t8, 0x66($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X66);
    // 0x800CBD8C: sll         $t9, $t7, 18
    ctx->r25 = S32(ctx->r15 << 18);
    // 0x800CBD90: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x800CBD94: andi        $t7, $t8, 0xF
    ctx->r15 = ctx->r24 & 0XF;
    // 0x800CBD98: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x800CBD9C: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x800CBDA0: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800CBDA4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBDA8: andi        $t6, $t7, 0x3
    ctx->r14 = ctx->r15 & 0X3;
    // 0x800CBDAC: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x800CBDB0: lbu         $t6, 0x67($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X67);
    // 0x800CBDB4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x800CBDB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800CBDBC: andi        $t8, $t6, 0xF
    ctx->r24 = ctx->r14 & 0XF;
    // 0x800CBDC0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800CBDC4: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800CBDC8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CBDCC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800CBDD0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CBDD4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800CBDD8: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800CBDDC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800CBDE0: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x800CBDE4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBDE8: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
    // 0x800CBDEC: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBDF0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800CBDF4: mflo        $a0
    ctx->r4 = lo;
    // 0x800CBDF8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CBDFC: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x800CBE00: beq         $at, $zero, L_800CBE10
    if (ctx->r1 == 0) {
        // 0x800CBE04: nop
    
            goto L_800CBE10;
    }
    // 0x800CBE04: nop

    // 0x800CBE08: b           L_800CBE10
    // 0x800CBE0C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_800CBE10;
    // 0x800CBE0C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800CBE10:
    // 0x800CBE10: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x800CBE14: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800CBE18: or          $t7, $t8, $t4
    ctx->r15 = ctx->r24 | ctx->r12;
    // 0x800CBE1C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800CBE20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CBE24: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800CBE28: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CBE2C: lbu         $t6, 0x30($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X30);
    // 0x800CBE30: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBE34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CBE38: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800CBE3C: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800CBE40: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800CBE44: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800CBE48: addiu       $t7, $t8, 0x7
    ctx->r15 = ADD32(ctx->r24, 0X7);
    // 0x800CBE4C: or          $t6, $t9, $t0
    ctx->r14 = ctx->r25 | ctx->r8;
    // 0x800CBE50: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800CBE54: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x800CBE58: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x800CBE5C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800CBE60: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800CBE64: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x800CBE68: lbu         $t9, 0x66($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X66);
    // 0x800CBE6C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBE70: andi        $t6, $t8, 0x3
    ctx->r14 = ctx->r24 & 0X3;
    // 0x800CBE74: sll         $t7, $t6, 18
    ctx->r15 = S32(ctx->r14 << 18);
    // 0x800CBE78: andi        $t8, $t9, 0xF
    ctx->r24 = ctx->r25 & 0XF;
    // 0x800CBE7C: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x800CBE80: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x800CBE84: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800CBE88: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CBE8C: andi        $t7, $t8, 0x3
    ctx->r15 = ctx->r24 & 0X3;
    // 0x800CBE90: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800CBE94: lbu         $t7, 0x67($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X67);
    // 0x800CBE98: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800CBE9C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBEA0: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x800CBEA4: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x800CBEA8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800CBEAC: addiu       $t8, $t2, -0x1
    ctx->r24 = ADD32(ctx->r10, -0X1);
    // 0x800CBEB0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800CBEB4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800CBEB8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800CBEBC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800CBEC0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CBEC4: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x800CBEC8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800CBECC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800CBED0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800CBED4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800CBED8: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800CBEDC: b           L_800CC05C
    // 0x800CBEE0: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
        goto L_800CC05C;
    // 0x800CBEE0: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
L_800CBEE4:
    // 0x800CBEE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CBEE8: lui         $t6, 0xFD18
    ctx->r14 = S32(0XFD18 << 16);
    // 0x800CBEEC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800CBEF0: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800CBEF4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBEF8: lui         $t0, 0xF518
    ctx->r8 = S32(0XF518 << 16);
    // 0x800CBEFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CBF00: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CBF04: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800CBF08: lbu         $t7, 0x64($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X64);
    // 0x800CBF0C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBF10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CBF14: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800CBF18: lbu         $t7, 0x66($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X66);
    // 0x800CBF1C: sll         $t6, $t8, 18
    ctx->r14 = S32(ctx->r24 << 18);
    // 0x800CBF20: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x800CBF24: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x800CBF28: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x800CBF2C: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x800CBF30: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800CBF34: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBF38: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x800CBF3C: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x800CBF40: lbu         $t9, 0x67($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X67);
    // 0x800CBF44: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800CBF48: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800CBF4C: andi        $t7, $t9, 0xF
    ctx->r15 = ctx->r25 & 0XF;
    // 0x800CBF50: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x800CBF54: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800CBF58: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800CBF5C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800CBF60: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CBF64: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800CBF68: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800CBF6C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800CBF70: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x800CBF74: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBF78: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
    // 0x800CBF7C: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBF80: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800CBF84: mflo        $a0
    ctx->r4 = lo;
    // 0x800CBF88: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CBF8C: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x800CBF90: beq         $at, $zero, L_800CBFA0
    if (ctx->r1 == 0) {
        // 0x800CBF94: nop
    
            goto L_800CBFA0;
    }
    // 0x800CBF94: nop

    // 0x800CBF98: b           L_800CBFA0
    // 0x800CBF9C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_800CBFA0;
    // 0x800CBF9C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800CBFA0:
    // 0x800CBFA0: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x800CBFA4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800CBFA8: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x800CBFAC: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800CBFB0: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x800CBFB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CBFB8: addiu       $t7, $t9, 0x7
    ctx->r15 = ADD32(ctx->r25, 0X7);
    // 0x800CBFBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CBFC0: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800CBFC4: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x800CBFC8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBFCC: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x800CBFD0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CBFD4: or          $t7, $t9, $t0
    ctx->r15 = ctx->r25 | ctx->r8;
    // 0x800CBFD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CBFDC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CBFE0: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x800CBFE4: lbu         $t7, 0x66($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X66);
    // 0x800CBFE8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CBFEC: andi        $t6, $t8, 0x3
    ctx->r14 = ctx->r24 & 0X3;
    // 0x800CBFF0: sll         $t9, $t6, 18
    ctx->r25 = S32(ctx->r14 << 18);
    // 0x800CBFF4: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x800CBFF8: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x800CBFFC: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x800CC000: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800CC004: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CC008: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x800CC00C: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x800CC010: lbu         $t9, 0x67($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X67);
    // 0x800CC014: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800CC018: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC01C: andi        $t7, $t9, 0xF
    ctx->r15 = ctx->r25 & 0XF;
    // 0x800CC020: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x800CC024: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800CC028: addiu       $t8, $t2, -0x1
    ctx->r24 = ADD32(ctx->r10, -0X1);
    // 0x800CC02C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800CC030: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800CC034: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800CC038: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800CC03C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800CC040: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x800CC044: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800CC048: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800CC04C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800CC050: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800CC054: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800CC058: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
L_800CC05C:
    // 0x800CC05C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CC060: sw          $t0, 0x62B4($at)
    MEM_W(0X62B4, ctx->r1) = ctx->r8;
    // 0x800CC064: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_800CC068:
    // 0x800CC068: andi        $t6, $ra, 0xFFF
    ctx->r14 = ctx->r31 & 0XFFF;
    // 0x800CC06C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800CC070: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800CC074: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800CC078: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800CC07C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800CC080: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC084: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC088: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800CC08C: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x800CC090: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800CC094: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800CC098: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800CC09C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800CC0A0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CC0A4: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x800CC0A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CC0AC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CC0B0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800CC0B4: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x800CC0B8: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800CC0BC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800CC0C0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800CC0C4: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CC0C8: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x800CC0CC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CC0D0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800CC0D4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800CC0D8: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x800CC0DC: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800CC0E0: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800CC0E4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800CC0E8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800CC0EC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800CC0F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800CC0F4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800CC0F8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800CC0FC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800CC100: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x800CC104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CC108:
    // 0x800CC108: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CC10C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CC110: jr          $ra
    // 0x800CC114: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800CC114: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void itMSBombDetachedInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176D08: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80176D0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80176D10: sw          $t6, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r14;
    // 0x80176D14: jal         0x8017279C
    // 0x80176D18: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    itMainClearOwnerStats(rdram, ctx);
        goto after_0;
    // 0x80176D18: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    after_0:
    // 0x80176D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176D24: jr          $ra
    // 0x80176D28: nop

    return;
    // 0x80176D28: nop

;}
RECOMP_FUNC void ftCommonDamageCheckCatchResist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140D38: lw          $t6, 0x7F8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7F8);
    // 0x80140D3C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80140D40: bnel        $t6, $at, L_80140D54
    if (ctx->r14 != ctx->r1) {
        // 0x80140D44: lwc1        $f12, 0x7E0($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X7E0);
            goto L_80140D54;
    }
    goto skip_0;
    // 0x80140D44: lwc1        $f12, 0x7E0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7E0);
    skip_0:
    // 0x80140D48: b           L_80140E1C
    // 0x80140D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140E1C;
    // 0x80140D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80140D50: lwc1        $f12, 0x7E0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7E0);
L_80140D54:
    // 0x80140D54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80140D58: nop

    // 0x80140D5C: c.eq.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl == ctx->f12.fl;
    // 0x80140D60: nop

    // 0x80140D64: bc1fl       L_80140D78
    if (!c1cs) {
        // 0x80140D68: lw          $t7, 0x40($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X40);
            goto L_80140D78;
    }
    goto skip_1;
    // 0x80140D68: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    skip_1:
    // 0x80140D6C: b           L_80140E1C
    // 0x80140D70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140E1C;
    // 0x80140D70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80140D74: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
L_80140D78:
    // 0x80140D78: beql        $t7, $zero, L_80140DC0
    if (ctx->r15 == 0) {
        // 0x80140D7C: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_80140DC0;
    }
    goto skip_2;
    // 0x80140D7C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_2:
    // 0x80140D80: lw          $t8, 0x190($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X190);
    // 0x80140D84: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80140D88: sll         $t0, $t8, 22
    ctx->r8 = S32(ctx->r24 << 22);
    // 0x80140D8C: bgezl       $t0, L_80140DC0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80140D90: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_80140DC0;
    }
    goto skip_3;
    // 0x80140D90: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_3:
    // 0x80140D94: lwc1        $f6, 0x7EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7EC);
    // 0x80140D98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80140D9C: nop

    // 0x80140DA0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80140DA4: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80140DA8: nop

    // 0x80140DAC: bc1fl       L_80140DC0
    if (!c1cs) {
        // 0x80140DB0: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_80140DC0;
    }
    goto skip_4;
    // 0x80140DB0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_4:
    // 0x80140DB4: b           L_80140E1C
    // 0x80140DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140E1C;
    // 0x80140DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80140DBC: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_80140DC0:
    // 0x80140DC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80140DC4: beq         $v0, $at, L_80140DDC
    if (ctx->r2 == ctx->r1) {
        // 0x80140DC8: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80140DDC;
    }
    // 0x80140DC8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80140DCC: beq         $v0, $at, L_80140DDC
    if (ctx->r2 == ctx->r1) {
        // 0x80140DD0: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80140DDC;
    }
    // 0x80140DD0: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80140DD4: bnel        $v0, $at, L_80140E1C
    if (ctx->r2 != ctx->r1) {
        // 0x80140DD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80140E1C;
    }
    goto skip_5;
    // 0x80140DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
L_80140DDC:
    // 0x80140DDC: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80140DE0: slti        $at, $v0, 0xEB
    ctx->r1 = SIGNED(ctx->r2) < 0XEB ? 1 : 0;
    // 0x80140DE4: bne         $at, $zero, L_80140E18
    if (ctx->r1 != 0) {
        // 0x80140DE8: slti        $at, $v0, 0xF4
        ctx->r1 = SIGNED(ctx->r2) < 0XF4 ? 1 : 0;
            goto L_80140E18;
    }
    // 0x80140DE8: slti        $at, $v0, 0xF4
    ctx->r1 = SIGNED(ctx->r2) < 0XF4 ? 1 : 0;
    // 0x80140DEC: beql        $at, $zero, L_80140E1C
    if (ctx->r1 == 0) {
        // 0x80140DF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80140E1C;
    }
    goto skip_6;
    // 0x80140DF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x80140DF4: jal         0x800EA1B0
    // 0x80140DF8: nop

    ftParamGetHitStun(rdram, ctx);
        goto after_0;
    // 0x80140DF8: nop

    after_0:
    // 0x80140DFC: jal         0x80140A94
    // 0x80140E00: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    ftCommonDamageGetDamageLevel(rdram, ctx);
        goto after_1;
    // 0x80140E00: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80140E04: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80140E08: beql        $at, $zero, L_80140E1C
    if (ctx->r1 == 0) {
        // 0x80140E0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80140E1C;
    }
    goto skip_7;
    // 0x80140E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x80140E10: b           L_80140E1C
    // 0x80140E14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140E1C;
    // 0x80140E14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140E18:
    // 0x80140E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140E1C:
    // 0x80140E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80140E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80140E24: jr          $ra
    // 0x80140E28: nop

    return;
    // 0x80140E28: nop

;}
RECOMP_FUNC void func_ovl8_80376A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80376A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376A50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80376A54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80376A58: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80376A5C: beq         $a0, $zero, L_80376A68
    if (ctx->r4 == 0) {
        // 0x80376A60: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80376A68;
    }
    // 0x80376A60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80376A64: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80376A68:
    // 0x80376A68: beq         $a3, $zero, L_80376A74
    if (ctx->r7 == 0) {
        // 0x80376A6C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_80376A74;
    }
    // 0x80376A6C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80376A70: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
L_80376A74:
    // 0x80376A74: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80376A78: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x80376A7C: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x80376A80: lh          $t9, 0x22($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X22);
    // 0x80376A84: lw          $a0, 0x40($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X40);
    // 0x80376A88: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80376A8C: jal         0x80023888
    // 0x80376A90: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    spMove(rdram, ctx);
        goto after_0;
    // 0x80376A90: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80376A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80376A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80376A9C: jr          $ra
    // 0x80376AA0: nop

    return;
    // 0x80376AA0: nop

;}
RECOMP_FUNC void ftParamGetJointID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E86D4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800E86D8: bne         $a1, $at, L_800E86E8
    if (ctx->r5 != ctx->r1) {
        // 0x800E86DC: nop
    
            goto L_800E86E8;
    }
    // 0x800E86DC: nop

    // 0x800E86E0: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x800E86E4: lw          $a1, 0x33C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X33C);
L_800E86E8:
    // 0x800E86E8: jr          $ra
    // 0x800E86EC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800E86EC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void mnVSModeMakeRuleArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132818: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013281C: lw          $a0, 0x4964($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4964);
    // 0x80132820: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132824: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132828: beql        $a0, $zero, L_80132844
    if (ctx->r4 == 0) {
        // 0x8013282C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80132844;
    }
    goto skip_0;
    // 0x8013282C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x80132830: jal         0x80009A84
    // 0x80132834: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80132834: nop

    after_0:
    // 0x80132838: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013283C: sw          $zero, 0x4964($at)
    MEM_W(0X4964, ctx->r1) = 0;
    // 0x80132840: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80132844:
    // 0x80132844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132848: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8013284C: jal         0x80009968
    // 0x80132850: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80132850: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132854: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132858: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013285C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132860: sw          $v0, 0x4964($at)
    MEM_W(0X4964, ctx->r1) = ctx->r2;
    // 0x80132864: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132868: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013286C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132870: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132874: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132878: jal         0x80009DF4
    // 0x8013287C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x8013287C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80132880: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132884: addiu       $a1, $a1, 0x265C
    ctx->r5 = ADD32(ctx->r5, 0X265C);
    // 0x80132888: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013288C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132890: jal         0x80008188
    // 0x80132894: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80132894: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80132898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013289C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801328A0: jr          $ra
    // 0x801328A4: nop

    return;
    // 0x801328A4: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNLoopSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162A20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162A28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162A2C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162A30: jal         0x800DEE98
    // 0x80162A34: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80162A34: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162A38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162A3C: addiu       $t7, $zero, 0x4825
    ctx->r15 = ADD32(0, 0X4825);
    // 0x80162A40: addiu       $a1, $zero, 0x10E
    ctx->r5 = ADD32(0, 0X10E);
    // 0x80162A44: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162A48: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162A4C: jal         0x800E6F24
    // 0x80162A50: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162A50: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162A54: jal         0x80161E3C
    // 0x80162A58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbySpecialNSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x80162A58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80162A5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162A60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162A64: jr          $ra
    // 0x80162A68: nop

    return;
    // 0x80162A68: nop

;}
RECOMP_FUNC void itMBallThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C880: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017C884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C888: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017C88C: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x8017C890: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017C894: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8017C898: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8017C89C: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x8017C8A0: jal         0x80172558
    // 0x8017C8A4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017C8A4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017C8A8: jal         0x801713F4
    // 0x8017C8AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x8017C8AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017C8B0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8017C8B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C8B8: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8017C8BC: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8017C8C0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8017C8C4: swc1        $f4, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f4.u32l;
    // 0x8017C8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C8CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017C8D0: jr          $ra
    // 0x8017C8D4: nop

    return;
    // 0x8017C8D4: nop

;}
RECOMP_FUNC void mpCommonProcFighterCliffWaitOrLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE97C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE980: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE984: jal         0x800DE80C
    // 0x800DE988: addiu       $a1, $a1, -0x171C
    ctx->r5 = ADD32(ctx->r5, -0X171C);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x800DE988: addiu       $a1, $a1, -0x171C
    ctx->r5 = ADD32(ctx->r5, -0X171C);
    after_0:
    // 0x800DE98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE994: jr          $ra
    // 0x800DE998: nop

    return;
    // 0x800DE998: nop

;}
RECOMP_FUNC void itPippiWeaponSwarmProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180488: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018048C: jal         0x80167520
    // 0x80180490: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    wpDisplayMain(rdram, ctx);
        goto after_0;
    // 0x80180490: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    after_0:
    // 0x80180494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018049C: jr          $ra
    // 0x801804A0: nop

    return;
    // 0x801804A0: nop

;}
RECOMP_FUNC void unref_80009D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009D40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80009D44: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80009D48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009D4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009D50: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80009D54: lw          $a3, 0x10($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X10);
    // 0x80009D58: lbu         $a2, 0xC($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0XC);
    // 0x80009D5C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80009D60: jal         0x80009B48
    // 0x80009D64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gcMoveGObjCommon(rdram, ctx);
        goto after_0;
    // 0x80009D64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80009D68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009D6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009D70: jr          $ra
    // 0x80009D74: nop

    return;
    // 0x80009D74: nop

;}
RECOMP_FUNC void func_ovl8_8037BF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BF34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037BF38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037BF3C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8037BF40: lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X10);
    // 0x8037BF44: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037BF48: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x8037BF4C: lh          $t6, 0x58($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X58);
    // 0x8037BF50: jalr        $t9
    // 0x8037BF54: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037BF54: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x8037BF58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037BF5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037BF60: jr          $ra
    // 0x8037BF64: nop

    return;
    // 0x8037BF64: nop

;}
RECOMP_FUNC void syMatrixLookAtReflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AB2C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001AB30: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001AB34: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001AB38: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8001AB3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001AB40: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001AB44: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001AB48: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001AB4C: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001AB50: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8001AB54: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8001AB58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001AB5C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001AB60: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8001AB64: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8001AB68: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001AB6C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8001AB70: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001AB74: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001AB78: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8001AB7C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8001AB80: jal         0x8001A744
    // 0x8001AB84: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syMatrixLookAtReflectF(rdram, ctx);
        goto after_0;
    // 0x8001AB84: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001AB88: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001AB8C: jal         0x80019C70
    // 0x8001AB90: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8001AB90: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_1:
    // 0x8001AB94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001AB98: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8001AB9C: jr          $ra
    // 0x8001ABA0: nop

    return;
    // 0x8001ABA0: nop

;}
RECOMP_FUNC void ftCommonRebirthDownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013D204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013D208: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D20C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013D210: jal         0x8013D1D4
    // 0x8013D214: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftCommonRebirthCommonUpdateHaloWait(rdram, ctx);
        goto after_0;
    // 0x8013D214: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013D218: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D21C: addiu       $at, $zero, 0x159
    ctx->r1 = ADD32(0, 0X159);
    // 0x8013D220: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013D224: lw          $v1, 0xB30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB30);
    // 0x8013D228: bnel        $v1, $at, L_8013D244
    if (ctx->r3 != ctx->r1) {
        // 0x8013D22C: addiu       $at, $zero, 0x13B
        ctx->r1 = ADD32(0, 0X13B);
            goto L_8013D244;
    }
    goto skip_0;
    // 0x8013D22C: addiu       $at, $zero, 0x13B
    ctx->r1 = ADD32(0, 0X13B);
    skip_0:
    // 0x8013D230: lbu         $t6, 0x191($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X191);
    // 0x8013D234: lw          $v1, 0xB30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB30);
    // 0x8013D238: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x8013D23C: sb          $t7, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r15;
    // 0x8013D240: addiu       $at, $zero, 0x13B
    ctx->r1 = ADD32(0, 0X13B);
L_8013D244:
    // 0x8013D244: bnel        $v1, $at, L_8013D258
    if (ctx->r3 != ctx->r1) {
        // 0x8013D248: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013D258;
    }
    goto skip_1;
    // 0x8013D248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013D24C: jal         0x8013D2DC
    // 0x8013D250: nop

    ftCommonRebirthStandSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013D250: nop

    after_1:
    // 0x8013D254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013D258:
    // 0x8013D258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013D25C: jr          $ra
    // 0x8013D260: nop

    return;
    // 0x8013D260: nop

;}
RECOMP_FUNC void mnModeSelectMakeLabelsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132398: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013239C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801323A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801323A4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801323A8: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801323AC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801323B0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801323B4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801323B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801323BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801323C0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801323C4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801323C8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801323CC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801323D0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801323D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801323D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801323DC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801323E0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801323E4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801323E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801323EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801323F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801323F4: jal         0x8000B93C
    // 0x801323F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801323F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801323FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132400: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132404: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132408: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013240C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132410: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132414: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132418: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013241C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132420: jal         0x80007080
    // 0x80132424: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132424: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132428: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013242C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132430: jr          $ra
    // 0x80132434: nop

    return;
    // 0x80132434: nop

;}
RECOMP_FUNC void ftYoshiSpecialNCatchUpdateProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E33C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E344: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015E348: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8015E34C: beql        $t6, $zero, L_8015E364
    if (ctx->r14 == 0) {
        // 0x8015E350: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8015E364;
    }
    goto skip_0;
    // 0x8015E350: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x8015E354: lw          $t7, 0x840($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X840);
    // 0x8015E358: bne         $t7, $zero, L_8015E378
    if (ctx->r15 != 0) {
        // 0x8015E35C: nop
    
            goto L_8015E378;
    }
    // 0x8015E35C: nop

    // 0x8015E360: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8015E364:
    // 0x8015E364: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015E368: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015E36C: nop

    // 0x8015E370: bc1fl       L_8015E384
    if (!c1cs) {
        // 0x8015E374: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015E384;
    }
    goto skip_1;
    // 0x8015E374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8015E378:
    // 0x8015E378: jalr        $a1
    // 0x8015E37C: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x8015E37C: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    after_0:
    // 0x8015E380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015E384:
    // 0x8015E384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E388: jr          $ra
    // 0x8015E38C: nop

    return;
    // 0x8015E38C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetMins(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133488: addiu       $at, $zero, 0xE10
    ctx->r1 = ADD32(0, 0XE10);
    // 0x8013348C: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80133490: mflo        $v0
    ctx->r2 = lo;
    // 0x80133494: jr          $ra
    // 0x80133498: nop

    return;
    // 0x80133498: nop

;}
RECOMP_FUNC void ftParamProcResumeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9CCC: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800E9CD0: jal         0x800E9B64
    // 0x800E9CD4: addiu       $a1, $a1, -0x6350
    ctx->r5 = ADD32(ctx->r5, -0X6350);
    ftParamRunProcEffect(rdram, ctx);
        goto after_0;
    // 0x800E9CD4: addiu       $a1, $a1, -0x6350
    ctx->r5 = ADD32(ctx->r5, -0X6350);
    after_0:
    // 0x800E9CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9CE0: jr          $ra
    // 0x800E9CE4: nop

    return;
    // 0x800E9CE4: nop

;}

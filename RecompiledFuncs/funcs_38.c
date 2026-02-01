#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void grBonus3MakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B7C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B7D0: jal         0x8010B4D0
    // 0x8010B7D4: nop

    grBonus3InitHeaders(rdram, ctx);
        goto after_0;
    // 0x8010B7D4: nop

    after_0:
    // 0x8010B7D8: jal         0x8010B508
    // 0x8010B7DC: nop

    grBonus3MakeBumpers(rdram, ctx);
        goto after_1;
    // 0x8010B7DC: nop

    after_1:
    // 0x8010B7E0: jal         0x8010B660
    // 0x8010B7E4: nop

    grBonus3TaruBombMakeActor(rdram, ctx);
        goto after_2;
    // 0x8010B7E4: nop

    after_2:
    // 0x8010B7E8: jal         0x8010B784
    // 0x8010B7EC: nop

    grBonus3FinishMakeActor(rdram, ctx);
        goto after_3;
    // 0x8010B7EC: nop

    after_3:
    // 0x8010B7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B7F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B7FC: jr          $ra
    // 0x8010B800: nop

    return;
    // 0x8010B800: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiJibakuBoundProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155058: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015505C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80155060: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80155064: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80155068: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8015506C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80155070: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80155074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80155078: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8015507C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80155080: bc1f        L_8015509C
    if (!c1cs) {
        // 0x80155084: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8015509C;
    }
    // 0x80155084: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80155088: lwc1        $f8, -0x39FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X39FC);
    // 0x8015508C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80155090: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80155094: jal         0x801438F0
    // 0x80155098: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155098: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
L_8015509C:
    // 0x8015509C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801550A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801550A4: jr          $ra
    // 0x801550A8: nop

    return;
    // 0x801550A8: nop

;}
RECOMP_FUNC void ftNessSpecialLw_UpdateReleaseLag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015551C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155520: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80155524: jal         0x801551E0
    // 0x80155528: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftNessSpecialLwCheckRelease(rdram, ctx);
        goto after_0;
    // 0x80155528: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015552C: jal         0x80155204
    // 0x80155530: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ftNessSpecialLwDecReleaseLag(rdram, ctx);
        goto after_1;
    // 0x80155530: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80155534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015553C: jr          $ra
    // 0x80155540: nop

    return;
    // 0x80155540: nop

;}
RECOMP_FUNC void syAudioLoadAssets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F4C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001F4C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001F4C8: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8001F4CC: addiu       $s1, $s1, -0x2678
    ctx->r17 = ADD32(ctx->r17, -0X2678);
    // 0x8001F4D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001F4D4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001F4D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001F4DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8001F4E0: jal         0x800315B0
    // 0x8001F4E4: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    _bzero(rdram, ctx);
        goto after_0;
    // 0x8001F4E4: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_0:
    // 0x8001F4E8: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8001F4EC: addiu       $s2, $s2, -0x2D28
    ctx->r18 = ADD32(ctx->r18, -0X2D28);
    // 0x8001F4F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8001F4F4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8001F4F8: jal         0x8001E5C0
    // 0x8001F4FC: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    alHeapInit(rdram, ctx);
        goto after_1;
    // 0x8001F4FC: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_1:
    // 0x8001F500: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x8001F504: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001F508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F50C: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x8001F510: bne         $at, $zero, L_8001F524
    if (ctx->r1 != 0) {
        // 0x8001F514: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001F524;
    }
    // 0x8001F514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F518: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001F51C: b           L_8001F56C
    // 0x8001F520: sw          $v0, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r2;
        goto L_8001F56C;
    // 0x8001F520: sw          $v0, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r2;
L_8001F524:
    // 0x8001F524: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x8001F528: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F52C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001F530: subu        $s0, $t6, $v0
    ctx->r16 = SUB32(ctx->r14, ctx->r2);
    // 0x8001F534: jal         0x8001E5F4
    // 0x8001F538: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8001F538: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x8001F53C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8001F540: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x8001F544: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001F548: jal         0x8001E91C
    // 0x8001F54C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    syAudioReadRom(rdram, ctx);
        goto after_3;
    // 0x8001F54C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x8001F550: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8001F554: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    // 0x8001F558: jal         0x8001E688
    // 0x8001F55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alBnkfNew(rdram, ctx);
        goto after_4;
    // 0x8001F55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8001F560: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8001F564: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001F568: sw          $t7, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r15;
L_8001F56C:
    // 0x8001F56C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8001F570: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001F574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F578: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x8001F57C: bne         $at, $zero, L_8001F590
    if (ctx->r1 != 0) {
        // 0x8001F580: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001F590;
    }
    // 0x8001F580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F584: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001F588: b           L_8001F5D8
    // 0x8001F58C: sw          $v0, -0x26B0($at)
    MEM_W(-0X26B0, ctx->r1) = ctx->r2;
        goto L_8001F5D8;
    // 0x8001F58C: sw          $v0, -0x26B0($at)
    MEM_W(-0X26B0, ctx->r1) = ctx->r2;
L_8001F590:
    // 0x8001F590: lw          $t8, 0x18($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X18);
    // 0x8001F594: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F598: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001F59C: subu        $s0, $t8, $v0
    ctx->r16 = SUB32(ctx->r24, ctx->r2);
    // 0x8001F5A0: jal         0x8001E5F4
    // 0x8001F5A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x8001F5A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // 0x8001F5A8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8001F5AC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8001F5B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001F5B4: jal         0x8001E91C
    // 0x8001F5B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    syAudioReadRom(rdram, ctx);
        goto after_6;
    // 0x8001F5B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x8001F5BC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8001F5C0: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8001F5C4: jal         0x8001E688
    // 0x8001F5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alBnkfNew(rdram, ctx);
        goto after_7;
    // 0x8001F5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8001F5CC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8001F5D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001F5D4: sw          $t9, -0x26B0($at)
    MEM_W(-0X26B0, ctx->r1) = ctx->r25;
L_8001F5D8:
    // 0x8001F5D8: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x8001F5DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001F5E0: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8001F5E4: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x8001F5E8: bne         $at, $zero, L_8001F5F8
    if (ctx->r1 != 0) {
        // 0x8001F5EC: addiu       $t1, $t1, -0x26A4
        ctx->r9 = ADD32(ctx->r9, -0X26A4);
            goto L_8001F5F8;
    }
    // 0x8001F5EC: addiu       $t1, $t1, -0x26A4
    ctx->r9 = ADD32(ctx->r9, -0X26A4);
    // 0x8001F5F0: b           L_8001F69C
    // 0x8001F5F4: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
        goto L_8001F69C;
    // 0x8001F5F4: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_8001F5F8:
    // 0x8001F5F8: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8001F5FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001F600: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F608: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F60C: jal         0x8001E5F4
    // 0x8001F610: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x8001F610: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8001F614: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8001F618: addiu       $t1, $t1, -0x26A4
    ctx->r9 = ADD32(ctx->r9, -0X26A4);
    // 0x8001F61C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8001F620: lw          $a0, 0x2C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X2C);
    // 0x8001F624: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001F628: jal         0x8001E91C
    // 0x8001F62C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    syAudioReadRom(rdram, ctx);
        goto after_9;
    // 0x8001F62C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x8001F630: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8001F634: addiu       $t1, $t1, -0x26A4
    ctx->r9 = ADD32(ctx->r9, -0X26A4);
    // 0x8001F638: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8001F63C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F644: lh          $v0, 0x2($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X2);
    // 0x8001F648: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F64C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001F650: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8001F654: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F658: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001F65C: jal         0x8001E5F4
    // 0x8001F660: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x8001F660: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
    // 0x8001F664: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8001F668: addiu       $t1, $t1, -0x26A4
    ctx->r9 = ADD32(ctx->r9, -0X26A4);
    // 0x8001F66C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8001F670: lw          $a0, 0x2C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X2C);
    // 0x8001F674: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001F678: jal         0x8001E91C
    // 0x8001F67C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    syAudioReadRom(rdram, ctx);
        goto after_11;
    // 0x8001F67C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x8001F680: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8001F684: addiu       $t1, $t1, -0x26A4
    ctx->r9 = ADD32(ctx->r9, -0X26A4);
    // 0x8001F688: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001F68C: jal         0x8001E648
    // 0x8001F690: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    alSeqFileNew(rdram, ctx);
        goto after_12;
    // 0x8001F690: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    after_12:
    // 0x8001F694: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8001F698: addiu       $t1, $t1, -0x26A4
    ctx->r9 = ADD32(ctx->r9, -0X26A4);
L_8001F69C:
    // 0x8001F69C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001F6A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F6A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F6A8: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x8001F6AC: blez        $t4, L_8001F6FC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8001F6B0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001F6FC;
    }
    // 0x8001F6B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F6B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001F6B8:
    // 0x8001F6B8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8001F6BC: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x8001F6C0: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8001F6C4: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8001F6C8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001F6CC: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x8001F6D0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8001F6D4: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F6D8: beql        $at, $zero, L_8001F6E8
    if (ctx->r1 == 0) {
        // 0x8001F6DC: lh          $t7, 0x2($a0)
        ctx->r15 = MEM_H(ctx->r4, 0X2);
            goto L_8001F6E8;
    }
    goto skip_0;
    // 0x8001F6DC: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    skip_0:
    // 0x8001F6E0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8001F6E4: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
L_8001F6E8:
    // 0x8001F6E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F6EC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8001F6F0: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001F6F4: bne         $at, $zero, L_8001F6B8
    if (ctx->r1 != 0) {
        // 0x8001F6F8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_8001F6B8;
    }
    // 0x8001F6F8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_8001F6FC:
    // 0x8001F6FC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8001F700: addiu       $v1, $v1, -0x2694
    ctx->r3 = ADD32(ctx->r3, -0X2694);
L_8001F704:
    // 0x8001F704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F70C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F710: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001F714: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001F718: jal         0x8001E5F4
    // 0x8001F71C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    alHeapDBAlloc(rdram, ctx);
        goto after_13;
    // 0x8001F71C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_13:
    // 0x8001F720: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8001F724: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8001F728: addiu       $t8, $t8, -0x2690
    ctx->r24 = ADD32(ctx->r24, -0X2690);
    // 0x8001F72C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001F730: sltu        $at, $v1, $t8
    ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x8001F734: bne         $at, $zero, L_8001F704
    if (ctx->r1 != 0) {
        // 0x8001F738: sw          $v0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r2;
            goto L_8001F704;
    }
    // 0x8001F738: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x8001F73C: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x8001F740: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001F744: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F74C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F750: jal         0x8001E5F4
    // 0x8001F754: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_14;
    // 0x8001F754: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x8001F758: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8001F75C: addiu       $s0, $s0, -0x26C8
    ctx->r16 = ADD32(ctx->r16, -0X26C8);
    // 0x8001F760: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x8001F764: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001F768: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001F76C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F774: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F778: jal         0x8001E5F4
    // 0x8001F77C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_15;
    // 0x8001F77C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x8001F780: addiu       $t3, $zero, 0x68
    ctx->r11 = ADD32(0, 0X68);
    // 0x8001F784: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8001F788: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8001F78C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F794: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F798: jal         0x8001E5F4
    // 0x8001F79C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_16;
    // 0x8001F79C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_16:
    // 0x8001F7A0: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8001F7A4: addiu       $s0, $s0, -0x26B8
    ctx->r16 = ADD32(ctx->r16, -0X26B8);
    // 0x8001F7A8: addiu       $t4, $zero, 0x68
    ctx->r12 = ADD32(0, 0X68);
    // 0x8001F7AC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001F7B0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8001F7B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F7B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F7BC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F7C0: jal         0x8001E5F4
    // 0x8001F7C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_17;
    // 0x8001F7C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_17:
    // 0x8001F7C8: addiu       $t5, $zero, 0xE60
    ctx->r13 = ADD32(0, 0XE60);
    // 0x8001F7CC: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8001F7D0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8001F7D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F7D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F7DC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F7E0: jal         0x8001E5F4
    // 0x8001F7E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_18;
    // 0x8001F7E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_18:
    // 0x8001F7E8: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8001F7EC: addiu       $s0, $s0, -0x26D8
    ctx->r16 = ADD32(ctx->r16, -0X26D8);
    // 0x8001F7F0: addiu       $t6, $zero, 0xE60
    ctx->r14 = ADD32(0, 0XE60);
    // 0x8001F7F4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8001F7F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001F7FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F804: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F808: jal         0x8001E5F4
    // 0x8001F80C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_19;
    // 0x8001F80C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_19:
    // 0x8001F810: addiu       $t7, $zero, 0xE60
    ctx->r15 = ADD32(0, 0XE60);
    // 0x8001F814: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8001F818: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001F81C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F824: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F828: jal         0x8001E5F4
    // 0x8001F82C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_20;
    // 0x8001F82C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_20:
    // 0x8001F830: lw          $v1, 0x50($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X50);
    // 0x8001F834: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001F838: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8001F83C: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x8001F840: beq         $at, $zero, L_8001F898
    if (ctx->r1 == 0) {
        // 0x8001F844: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001F898;
    }
    // 0x8001F844: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F848: lw          $t8, 0x54($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X54);
    // 0x8001F84C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F850: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F854: subu        $s0, $t8, $v1
    ctx->r16 = SUB32(ctx->r24, ctx->r3);
    // 0x8001F858: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001F85C: jal         0x8001E5F4
    // 0x8001F860: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_21;
    // 0x8001F860: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_21:
    // 0x8001F864: lw          $a0, 0x50($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X50);
    // 0x8001F868: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001F86C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8001F870: jal         0x8001E91C
    // 0x8001F874: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    syAudioReadRom(rdram, ctx);
        goto after_22;
    // 0x8001F874: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_22:
    // 0x8001F878: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8001F87C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F880: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001F884: addiu       $t3, $v1, 0x4
    ctx->r11 = ADD32(ctx->r3, 0X4);
    // 0x8001F888: sh          $t2, 0x4C($s1)
    MEM_H(0X4C, ctx->r17) = ctx->r10;
    // 0x8001F88C: sh          $t2, -0x3478($at)
    MEM_H(-0X3478, ctx->r1) = ctx->r10;
    // 0x8001F890: sw          $t3, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r11;
    // 0x8001F894: sw          $t3, -0x3480($at)
    MEM_W(-0X3480, ctx->r1) = ctx->r11;
L_8001F898:
    // 0x8001F898: lw          $v0, 0x58($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X58);
    // 0x8001F89C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001F8A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F8A4: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x8001F8A8: beq         $at, $zero, L_8001F93C
    if (ctx->r1 == 0) {
        // 0x8001F8AC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001F93C;
    }
    // 0x8001F8AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F8B0: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x8001F8B4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F8B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001F8BC: subu        $s0, $t5, $v0
    ctx->r16 = SUB32(ctx->r13, ctx->r2);
    // 0x8001F8C0: jal         0x8001E5F4
    // 0x8001F8C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    alHeapDBAlloc(rdram, ctx);
        goto after_23;
    // 0x8001F8C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_23:
    // 0x8001F8C8: lw          $a0, 0x58($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X58);
    // 0x8001F8CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001F8D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8001F8D4: jal         0x8001E91C
    // 0x8001F8D8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    syAudioReadRom(rdram, ctx);
        goto after_24;
    // 0x8001F8D8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_24:
    // 0x8001F8DC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001F8E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F8E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F8E8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8001F8EC: addiu       $t7, $a3, 0x4
    ctx->r15 = ADD32(ctx->r7, 0X4);
    // 0x8001F8F0: sh          $t6, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = ctx->r14;
    // 0x8001F8F4: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x8001F8F8: sh          $v0, -0x347A($at)
    MEM_H(-0X347A, ctx->r1) = ctx->r2;
    // 0x8001F8FC: sw          $t7, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r15;
    // 0x8001F900: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F904: blez        $v0, L_8001F93C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F908: sw          $t7, -0x3484($at)
        MEM_W(-0X3484, ctx->r1) = ctx->r15;
            goto L_8001F93C;
    }
    // 0x8001F908: sw          $t7, -0x3484($at)
    MEM_W(-0X3484, ctx->r1) = ctx->r15;
    // 0x8001F90C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F910: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
L_8001F914:
    // 0x8001F914: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F918: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8001F91C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001F920: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F924: addu        $t3, $t2, $a3
    ctx->r11 = ADD32(ctx->r10, ctx->r7);
    // 0x8001F928: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8001F92C: lhu         $t4, 0x4A($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X4A);
    // 0x8001F930: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F934: bnel        $at, $zero, L_8001F914
    if (ctx->r1 != 0) {
        // 0x8001F938: lw          $t9, 0x40($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X40);
            goto L_8001F914;
    }
    goto skip_1;
    // 0x8001F938: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    skip_1:
L_8001F93C:
    // 0x8001F93C: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8001F940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001F944: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F948: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x8001F94C: beq         $at, $zero, L_8001F9E8
    if (ctx->r1 == 0) {
        // 0x8001F950: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001F9E8;
    }
    // 0x8001F950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F954: lw          $t5, 0x64($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X64);
    // 0x8001F958: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001F95C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001F960: subu        $s0, $t5, $v0
    ctx->r16 = SUB32(ctx->r13, ctx->r2);
    // 0x8001F964: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001F968: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F96C: jal         0x8001E5F4
    // 0x8001F970: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_25;
    // 0x8001F970: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_25:
    // 0x8001F974: lw          $a0, 0x60($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X60);
    // 0x8001F978: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001F97C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8001F980: jal         0x8001E91C
    // 0x8001F984: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    syAudioReadRom(rdram, ctx);
        goto after_26;
    // 0x8001F984: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_26:
    // 0x8001F988: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8001F98C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001F990: addiu       $v1, $v1, -0x34C4
    ctx->r3 = ADD32(ctx->r3, -0X34C4);
    // 0x8001F994: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8001F998: addiu       $t7, $a3, 0x4
    ctx->r15 = ADD32(ctx->r7, 0X4);
    // 0x8001F99C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8001F9A0: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x8001F9A4: sh          $v0, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r2;
    // 0x8001F9A8: sw          $t7, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r15;
    // 0x8001F9AC: sw          $t7, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r15;
    // 0x8001F9B0: blez        $v0, L_8001F9E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F9B4: sh          $t6, 0x48($s1)
        MEM_H(0X48, ctx->r17) = ctx->r14;
            goto L_8001F9E8;
    }
    // 0x8001F9B4: sh          $t6, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r14;
    // 0x8001F9B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F9BC: lw          $t9, 0x3C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X3C);
L_8001F9C0:
    // 0x8001F9C0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001F9C4: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8001F9C8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8001F9CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001F9D0: addu        $t3, $t2, $a3
    ctx->r11 = ADD32(ctx->r10, ctx->r7);
    // 0x8001F9D4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8001F9D8: lhu         $t4, 0x48($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X48);
    // 0x8001F9DC: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001F9E0: bnel        $at, $zero, L_8001F9C0
    if (ctx->r1 != 0) {
        // 0x8001F9E4: lw          $t9, 0x3C($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X3C);
            goto L_8001F9C0;
    }
    goto skip_2;
    // 0x8001F9E4: lw          $t9, 0x3C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X3C);
    skip_2:
L_8001F9E8:
    // 0x8001F9E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F9EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001F9F0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001F9F4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001F9F8: jr          $ra
    // 0x8001F9FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8001F9FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftNessSpecialHiStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80153EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153F00: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80153F04: jal         0x800DDE84
    // 0x80153F08: addiu       $a1, $a1, 0x3F80
    ctx->r5 = ADD32(ctx->r5, 0X3F80);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80153F08: addiu       $a1, $a1, 0x3F80
    ctx->r5 = ADD32(ctx->r5, 0X3F80);
    after_0:
    // 0x80153F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80153F14: jr          $ra
    // 0x80153F18: nop

    return;
    // 0x80153F18: nop

;}
RECOMP_FUNC void scVSBattleStartBattle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D228: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8018D22C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D230: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018D234: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D238: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8018D23C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8018D240: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8018D244: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8018D248: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018D24C: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x8018D250: jal         0x8018E330
    // 0x8018D254: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    scVSBattleSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018D254: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    after_0:
    // 0x8018D258: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8018D25C: addiu       $s3, $s3, 0x44E0
    ctx->r19 = ADD32(ctx->r19, 0X44E0);
    // 0x8018D260: lbu         $t6, 0x5E2($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X5E2);
    // 0x8018D264: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8018D268: bnel        $t7, $zero, L_8018D300
    if (ctx->r15 != 0) {
        // 0x8018D26C: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_8018D300;
    }
    goto skip_0;
    // 0x8018D26C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    skip_0:
    // 0x8018D270: lbu         $t8, 0x5E3($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X5E3);
    // 0x8018D274: lui         $s0, 0x0
    ctx->r16 = S32(0X0 << 16);
    // 0x8018D278: addiu       $s0, $s0, 0xC7
    ctx->r16 = ADD32(ctx->r16, 0XC7);
    // 0x8018D27C: slti        $at, $t8, 0x45
    ctx->r1 = SIGNED(ctx->r24) < 0X45 ? 1 : 0;
    // 0x8018D280: bnel        $at, $zero, L_8018D300
    if (ctx->r1 != 0) {
        // 0x8018D284: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_8018D300;
    }
    goto skip_1;
    // 0x8018D284: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    skip_1:
    // 0x8018D288: jal         0x800CDBD0
    // 0x8018D28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbRelocGetFileSize(rdram, ctx);
        goto after_1;
    // 0x8018D28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8018D290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D294: jal         0x80004980
    // 0x8018D298: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018D298: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018D29C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D2A0: jal         0x800CDC88
    // 0x8018D2A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_3;
    // 0x8018D2A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8018D2A8: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8018D2AC: lui         $s1, 0x0
    ctx->r17 = S32(0X0 << 16);
    // 0x8018D2B0: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x8018D2B4: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x8018D2B8: addu        $a0, $v0, $t9
    ctx->r4 = ADD32(ctx->r2, ctx->r25);
    // 0x8018D2BC: addu        $t0, $v0, $s1
    ctx->r8 = ADD32(ctx->r2, ctx->r17);
    // 0x8018D2C0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8018D2C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018D2C8: jal         0x800321D0
    // 0x8018D2CC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_4;
    // 0x8018D2CC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8018D2D0: addu        $t1, $s2, $s1
    ctx->r9 = ADD32(ctx->r18, ctx->r17);
    // 0x8018D2D4: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8018D2D8: jal         0x800344B0
    // 0x8018D2DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osInvalICache_recomp(rdram, ctx);
        goto after_5;
    // 0x8018D2DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8018D2E0: jalr        $s0
    // 0x8018D2E4: nop

    LOOKUP_FUNC(ctx->r16)(rdram, ctx);
        goto after_6;
    // 0x8018D2E4: nop

    after_6:
    // 0x8018D2E8: bnel        $v0, $zero, L_8018D300
    if (ctx->r2 != 0) {
        // 0x8018D2EC: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_8018D300;
    }
    goto skip_2;
    // 0x8018D2EC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    skip_2:
    // 0x8018D2F0: lbu         $t2, 0x5E2($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X5E2);
    // 0x8018D2F4: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8018D2F8: sb          $t3, 0x5E2($s3)
    MEM_B(0X5E2, ctx->r19) = ctx->r11;
    // 0x8018D2FC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_8018D300:
    // 0x8018D300: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018D304: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018D308: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018D30C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018D310: jal         0x8000B9FC
    // 0x8018D314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_7;
    // 0x8018D314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x8018D318: jal         0x80115890
    // 0x8018D31C: nop

    efParticleInitAll(rdram, ctx);
        goto after_8;
    // 0x8018D31C: nop

    after_8:
    // 0x8018D320: jal         0x800EC130
    // 0x8018D324: nop

    ftParamInitGame(rdram, ctx);
        goto after_9;
    // 0x8018D324: nop

    after_9:
    // 0x8018D328: jal         0x800FC284
    // 0x8018D32C: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_10;
    // 0x8018D32C: nop

    after_10:
    // 0x8018D330: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018D334: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018D338: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018D33C: jal         0x8010E598
    // 0x8018D340: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_11;
    // 0x8018D340: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_11:
    // 0x8018D344: jal         0x8010DB54
    // 0x8018D348: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_12;
    // 0x8018D348: nop

    after_12:
    // 0x8018D34C: jal         0x80104BDC
    // 0x8018D350: nop

    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_13;
    // 0x8018D350: nop

    after_13:
    // 0x8018D354: jal         0x8010DB00
    // 0x8018D358: nop

    gmCameraMakeBattleCamera(rdram, ctx);
        goto after_14;
    // 0x8018D358: nop

    after_14:
    // 0x8018D35C: jal         0x8016DEA0
    // 0x8018D360: nop

    itManagerInitItems(rdram, ctx);
        goto after_15;
    // 0x8018D360: nop

    after_15:
    // 0x8018D364: jal         0x80105600
    // 0x8018D368: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_16;
    // 0x8018D368: nop

    after_16:
    // 0x8018D36C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018D370: jal         0x800D7194
    // 0x8018D374: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_17;
    // 0x8018D374: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x8018D378: jal         0x801654B0
    // 0x8018D37C: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_18;
    // 0x8018D37C: nop

    after_18:
    // 0x8018D380: jal         0x800FD300
    // 0x8018D384: nop

    efManagerInitEffects(rdram, ctx);
        goto after_19;
    // 0x8018D384: nop

    after_19:
    // 0x8018D388: jal         0x80115DE8
    // 0x8018D38C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    ifScreenFlashMakeInterface(rdram, ctx);
        goto after_20;
    // 0x8018D38C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_20:
    // 0x8018D390: jal         0x801156E4
    // 0x8018D394: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_21;
    // 0x8018D394: nop

    after_21:
    // 0x8018D398: jal         0x801653E0
    // 0x8018D39C: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_22;
    // 0x8018D39C: nop

    after_22:
    // 0x8018D3A0: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8018D3A4: addiu       $s2, $s2, 0x50E8
    ctx->r18 = ADD32(ctx->r18, 0X50E8);
    // 0x8018D3A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018D3AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D3B0: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
L_8018D3B4:
    // 0x8018D3B4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x8018D3B8: addiu       $t5, $t5, 0x6DD0
    ctx->r13 = ADD32(ctx->r13, 0X6DD0);
    // 0x8018D3BC: addiu       $t9, $t5, 0x3C
    ctx->r25 = ADD32(ctx->r13, 0X3C);
    // 0x8018D3C0: or          $t8, $s4, $zero
    ctx->r24 = ctx->r20 | 0;
L_8018D3C4:
    // 0x8018D3C4: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8018D3C8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8018D3CC: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8018D3D0: sw          $t7, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r15;
    // 0x8018D3D4: lw          $t6, -0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X8);
    // 0x8018D3D8: sw          $t6, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r14;
    // 0x8018D3DC: lw          $t7, -0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, -0X4);
    // 0x8018D3E0: bne         $t5, $t9, L_8018D3C4
    if (ctx->r13 != ctx->r25) {
        // 0x8018D3E4: sw          $t7, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r15;
            goto L_8018D3C4;
    }
    // 0x8018D3E4: sw          $t7, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r15;
    // 0x8018D3E8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8018D3EC: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8018D3F0: addu        $t2, $t2, $s0
    ctx->r10 = ADD32(ctx->r10, ctx->r16);
    // 0x8018D3F4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8018D3F8: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8018D3FC: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D400: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018D404: addu        $v1, $t0, $s1
    ctx->r3 = ADD32(ctx->r8, ctx->r17);
    // 0x8018D408: lbu         $t1, 0x22($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X22);
    // 0x8018D40C: addiu       $t3, $t3, 0x5228
    ctx->r11 = ADD32(ctx->r11, 0X5228);
    // 0x8018D410: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8018D414: beq         $t1, $at, L_8018D4E4
    if (ctx->r9 == ctx->r1) {
        // 0x8018D418: addu        $s3, $t2, $t3
        ctx->r19 = ADD32(ctx->r10, ctx->r11);
            goto L_8018D4E4;
    }
    // 0x8018D418: addu        $s3, $t2, $t3
    ctx->r19 = ADD32(ctx->r10, ctx->r11);
    // 0x8018D41C: jal         0x800D786C
    // 0x8018D420: lbu         $a0, 0x23($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_23;
    // 0x8018D420: lbu         $a0, 0x23($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X23);
    after_23:
    // 0x8018D424: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8018D428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D42C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8018D430: addu        $t9, $t4, $s1
    ctx->r25 = ADD32(ctx->r12, ctx->r17);
    // 0x8018D434: lbu         $t5, 0x23($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X23);
    // 0x8018D438: jal         0x800FAF64
    // 0x8018D43C: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    mpCollisionGetPlayerMapObjPosition(rdram, ctx);
        goto after_24;
    // 0x8018D43C: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    after_24:
    // 0x8018D440: jal         0x8018D0E0
    // 0x8018D444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scVSBattleGetStartPlayerLR(rdram, ctx);
        goto after_25;
    // 0x8018D444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8018D448: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8018D44C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8018D450: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8018D454: addu        $v1, $a1, $s1
    ctx->r3 = ADD32(ctx->r5, ctx->r17);
    // 0x8018D458: lbu         $t8, 0x25($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X25);
    // 0x8018D45C: sb          $s0, 0x71($sp)
    MEM_B(0X71, ctx->r29) = ctx->r16;
    // 0x8018D460: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D464: sb          $t8, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r24;
    // 0x8018D468: lbu         $t7, 0x5($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X5);
    // 0x8018D46C: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x8018D470: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D474: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x8018D478: beql        $at, $zero, L_8018D48C
    if (ctx->r1 == 0) {
        // 0x8018D47C: sb          $t2, 0x72($sp)
        MEM_B(0X72, ctx->r29) = ctx->r10;
            goto L_8018D48C;
    }
    goto skip_3;
    // 0x8018D47C: sb          $t2, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r10;
    skip_3:
    // 0x8018D480: b           L_8018D48C
    // 0x8018D484: sb          $t1, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r9;
        goto L_8018D48C;
    // 0x8018D484: sb          $t1, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r9;
    // 0x8018D488: sb          $t2, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r10;
L_8018D48C:
    // 0x8018D48C: lbu         $t3, 0x26($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X26);
    // 0x8018D490: sb          $t3, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r11;
    // 0x8018D494: lbu         $t4, 0x27($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X27);
    // 0x8018D498: sb          $t4, 0x74($sp)
    MEM_B(0X74, ctx->r29) = ctx->r12;
    // 0x8018D49C: lbu         $t9, 0x21($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X21);
    // 0x8018D4A0: sb          $t9, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r25;
    // 0x8018D4A4: lbu         $t5, 0x20($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X20);
    // 0x8018D4A8: sb          $t5, 0x76($sp)
    MEM_B(0X76, ctx->r29) = ctx->r13;
    // 0x8018D4AC: lbu         $t8, 0x7($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X7);
    // 0x8018D4B0: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8018D4B4: sb          $t8, 0x77($sp)
    MEM_B(0X77, ctx->r29) = ctx->r24;
    // 0x8018D4B8: lbu         $t6, 0x22($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X22);
    // 0x8018D4BC: sw          $s3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r19;
    // 0x8018D4C0: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
    // 0x8018D4C4: jal         0x800D78B4
    // 0x8018D4C8: lbu         $a0, 0x23($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_26;
    // 0x8018D4C8: lbu         $a0, 0x23($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X23);
    after_26:
    // 0x8018D4CC: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x8018D4D0: jal         0x800D7F3C
    // 0x8018D4D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_27;
    // 0x8018D4D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_27:
    // 0x8018D4D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D4DC: jal         0x800E7C4C
    // 0x8018D4E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_28;
    // 0x8018D4E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_28:
L_8018D4E4:
    // 0x8018D4E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018D4E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018D4EC: bne         $s0, $at, L_8018D3B4
    if (ctx->r16 != ctx->r1) {
        // 0x8018D4F0: addiu       $s1, $s1, 0x74
        ctx->r17 = ADD32(ctx->r17, 0X74);
            goto L_8018D3B4;
    }
    // 0x8018D4F0: addiu       $s1, $s1, 0x74
    ctx->r17 = ADD32(ctx->r17, 0X74);
    // 0x8018D4F4: jal         0x800D782C
    // 0x8018D4F8: nop

    ftManagerSetupFilesPlayablesAll(rdram, ctx);
        goto after_29;
    // 0x8018D4F8: nop

    after_29:
    // 0x8018D4FC: jal         0x80114958
    // 0x8018D500: nop

    ifCommonBattleSetGameStatusWait(rdram, ctx);
        goto after_30;
    // 0x8018D500: nop

    after_30:
    // 0x8018D504: jal         0x8010E2D4
    // 0x8018D508: nop

    gmCameraMakePlayerArrowsCamera(rdram, ctx);
        goto after_31;
    // 0x8018D508: nop

    after_31:
    // 0x8018D50C: jal         0x801118E4
    // 0x8018D510: nop

    ifCommonPlayerArrowsInitInterface(rdram, ctx);
        goto after_32;
    // 0x8018D510: nop

    after_32:
    // 0x8018D514: jal         0x8010E1A4
    // 0x8018D518: nop

    gmCameraMakePlayerMagnifyCamera(rdram, ctx);
        goto after_33;
    // 0x8018D518: nop

    after_33:
    // 0x8018D51C: jal         0x80111440
    // 0x8018D520: nop

    ifCommonPlayerMagnifyMakeInterface(rdram, ctx);
        goto after_34;
    // 0x8018D520: nop

    after_34:
    // 0x8018D524: jal         0x8010DDC4
    // 0x8018D528: nop

    gmCameraScreenFlashMakeCamera(rdram, ctx);
        goto after_35;
    // 0x8018D528: nop

    after_35:
    // 0x8018D52C: jal         0x8010E374
    // 0x8018D530: nop

    gmCameraMakeInterfaceCamera(rdram, ctx);
        goto after_36;
    // 0x8018D530: nop

    after_36:
    // 0x8018D534: jal         0x8010E498
    // 0x8018D538: nop

    gmCameraMakeEffectCamera(rdram, ctx);
        goto after_37;
    // 0x8018D538: nop

    after_37:
    // 0x8018D53C: jal         0x80111BE4
    // 0x8018D540: nop

    ifCommonPlayerTagMakeInterface(rdram, ctx);
        goto after_38;
    // 0x8018D540: nop

    after_38:
    // 0x8018D544: jal         0x8010F3A0
    // 0x8018D548: nop

    ifCommonPlayerDamageSetDigitPositions(rdram, ctx);
        goto after_39;
    // 0x8018D548: nop

    after_39:
    // 0x8018D54C: jal         0x8010F3C0
    // 0x8018D550: nop

    ifCommonPlayerDamageInitInterface(rdram, ctx);
        goto after_40;
    // 0x8018D550: nop

    after_40:
    // 0x8018D554: jal         0x80110514
    // 0x8018D558: nop

    ifCommonPlayerStockInitInterface(rdram, ctx);
        goto after_41;
    // 0x8018D558: nop

    after_41:
    // 0x8018D55C: jal         0x80112A80
    // 0x8018D560: nop

    ifCommonEntryAllMakeInterface(rdram, ctx);
        goto after_42;
    // 0x8018D560: nop

    after_42:
    // 0x8018D564: jal         0x800FC3E8
    // 0x8018D568: nop

    mpCollisionSetPlayBGM(rdram, ctx);
        goto after_43;
    // 0x8018D568: nop

    after_43:
    // 0x8018D56C: jal         0x800269C0
    // 0x8018D570: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    func_800269C0_275C0(rdram, ctx);
        goto after_44;
    // 0x8018D570: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_44:
    // 0x8018D574: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018D578: jal         0x80113398
    // 0x8018D57C: addiu       $a0, $a0, 0x4D98
    ctx->r4 = ADD32(ctx->r4, 0X4D98);
    ifCommonTimerMakeInterface(rdram, ctx);
        goto after_45;
    // 0x8018D57C: addiu       $a0, $a0, 0x4D98
    ctx->r4 = ADD32(ctx->r4, 0X4D98);
    after_45:
    // 0x8018D580: jal         0x80112F68
    // 0x8018D584: nop

    ifCommonTimerMakeDigits(rdram, ctx);
        goto after_46;
    // 0x8018D584: nop

    after_46:
    // 0x8018D588: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D58C: addiu       $t7, $t7, -0x1C30
    ctx->r15 = ADD32(ctx->r15, -0X1C30);
    // 0x8018D590: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x8018D594: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x8018D598: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8018D59C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8018D5A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D5A4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8018D5A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018D5AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018D5B0: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x8018D5B4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8018D5B8: jal         0x800D4060
    // 0x8018D5BC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_47;
    // 0x8018D5BC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_47:
    // 0x8018D5C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D5C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018D5C8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D5CC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018D5D0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8018D5D4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8018D5D8: jr          $ra
    // 0x8018D5DC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8018D5DC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void gcGetGObjStackOfSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007488: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000748C: lw          $v1, 0x66C4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X66C4);
    // 0x80007490: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80007494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007498: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000749C: beq         $v1, $zero, L_800074C0
    if (ctx->r3 == 0) {
        // 0x800074A0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800074C0;
    }
    // 0x800074A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800074A4: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
L_800074A8:
    // 0x800074A8: beq         $a3, $t6, L_800074C0
    if (ctx->r7 == ctx->r14) {
        // 0x800074AC: nop
    
            goto L_800074C0;
    }
    // 0x800074AC: nop

    // 0x800074B0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800074B4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800074B8: bnel        $v1, $zero, L_800074A8
    if (ctx->r3 != 0) {
        // 0x800074BC: lw          $t6, 0x8($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X8);
            goto L_800074A8;
    }
    goto skip_0;
    // 0x800074BC: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    skip_0:
L_800074C0:
    // 0x800074C0: bne         $v1, $zero, L_80007504
    if (ctx->r3 != 0) {
        // 0x800074C4: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80007504;
    }
    // 0x800074C4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800074C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800074CC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800074D0: jal         0x80004980
    // 0x800074D4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800074D4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800074D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800074DC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800074E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800074E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800074E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800074EC: beq         $a2, $zero, L_800074FC
    if (ctx->r6 == 0) {
        // 0x800074F0: sw          $a3, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r7;
            goto L_800074FC;
    }
    // 0x800074F0: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x800074F4: b           L_80007504
    // 0x800074F8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80007504;
    // 0x800074F8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800074FC:
    // 0x800074FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80007500: sw          $v0, 0x66C4($at)
    MEM_W(0X66C4, ctx->r1) = ctx->r2;
L_80007504:
    // 0x80007504: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80007508: addiu       $a0, $a3, 0x8
    ctx->r4 = ADD32(ctx->r7, 0X8);
    // 0x8000750C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80007510: beq         $v0, $zero, L_80007528
    if (ctx->r2 == 0) {
        // 0x80007514: nop
    
            goto L_80007528;
    }
    // 0x80007514: nop

    // 0x80007518: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000751C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80007520: b           L_8000753C
    // 0x80007524: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_8000753C;
    // 0x80007524: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80007528:
    // 0x80007528: jal         0x80004980
    // 0x8000752C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8000752C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80007530: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80007534: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80007538: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
L_8000753C:
    // 0x8000753C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80007540: addiu       $v1, $v1, 0x66B8
    ctx->r3 = ADD32(ctx->r3, 0X66B8);
    // 0x80007544: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80007548: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000754C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007550: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80007554: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80007558: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000755C: jr          $ra
    // 0x80007560: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80007560: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void itManagerSetupContainerDrops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016EF40: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8016EF44: lw          $t2, 0x50E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E8);
    // 0x8016EF48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8016EF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016EF50: lbu         $t6, 0x1C($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X1C);
    // 0x8016EF54: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016EF58: addiu       $t0, $t0, -0x2FB8
    ctx->r8 = ADD32(ctx->r8, -0X2FB8);
    // 0x8016EF5C: beql        $t6, $zero, L_8016F208
    if (ctx->r14 == 0) {
        // 0x8016EF60: sh          $zero, 0x10($t0)
        MEM_H(0X10, ctx->r8) = 0;
            goto L_8016F208;
    }
    goto skip_0;
    // 0x8016EF60: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    skip_0:
    // 0x8016EF64: lw          $a2, 0xC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0XC);
    // 0x8016EF68: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8016EF6C: beql        $a2, $zero, L_8016F208
    if (ctx->r6 == 0) {
        // 0x8016EF70: sh          $zero, 0x10($t0)
        MEM_H(0X10, ctx->r8) = 0;
            goto L_8016F208;
    }
    goto skip_1;
    // 0x8016EF70: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    skip_1:
    // 0x8016EF74: lw          $t3, 0x1300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1300);
    // 0x8016EF78: srl         $v0, $a2, 4
    ctx->r2 = S32(U32(ctx->r6) >> 4);
    // 0x8016EF7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8016EF80: lw          $a3, 0x84($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X84);
    // 0x8016EF84: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8016EF88: beq         $a3, $zero, L_8016F204
    if (ctx->r7 == 0) {
        // 0x8016EF8C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_8016F204;
    }
    // 0x8016EF8C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_8016EF90:
    // 0x8016EF90: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8016EF94: beq         $t7, $zero, L_8016EFA4
    if (ctx->r15 == 0) {
        // 0x8016EF98: addu        $t8, $a1, $v1
        ctx->r24 = ADD32(ctx->r5, ctx->r3);
            goto L_8016EFA4;
    }
    // 0x8016EF98: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
    // 0x8016EF9C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8016EFA0: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
L_8016EFA4:
    // 0x8016EFA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8016EFA8: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8016EFAC: bne         $at, $zero, L_8016EF90
    if (ctx->r1 != 0) {
        // 0x8016EFB0: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_8016EF90;
    }
    // 0x8016EFB0: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8016EFB4: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016EFB8: addiu       $t0, $t0, -0x2FB8
    ctx->r8 = ADD32(ctx->r8, -0X2FB8);
    // 0x8016EFBC: beq         $a0, $zero, L_8016F208
    if (ctx->r4 == 0) {
        // 0x8016EFC0: sh          $a0, 0x10($t0)
        MEM_H(0X10, ctx->r8) = ctx->r4;
            goto L_8016F208;
    }
    // 0x8016EFC0: sh          $a0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r4;
    // 0x8016EFC4: lw          $a0, 0xC($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XC);
    // 0x8016EFC8: lw          $t1, 0x84($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X84);
    // 0x8016EFCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016EFD0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8016EFD4: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
L_8016EFD8:
    // 0x8016EFD8: andi        $t4, $a0, 0x1
    ctx->r12 = ctx->r4 & 0X1;
    // 0x8016EFDC: beq         $t4, $zero, L_8016EFF4
    if (ctx->r12 == 0) {
        // 0x8016EFE0: addu        $t5, $t1, $v1
        ctx->r13 = ADD32(ctx->r9, ctx->r3);
            goto L_8016EFF4;
    }
    // 0x8016EFE0: addu        $t5, $t1, $v1
    ctx->r13 = ADD32(ctx->r9, ctx->r3);
    // 0x8016EFE4: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8016EFE8: beql        $t6, $zero, L_8016EFF8
    if (ctx->r14 == 0) {
        // 0x8016EFEC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8016EFF8;
    }
    goto skip_2;
    // 0x8016EFEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x8016EFF0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8016EFF4:
    // 0x8016EFF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8016EFF8:
    // 0x8016EFF8: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8016EFFC: bne         $at, $zero, L_8016EFD8
    if (ctx->r1 != 0) {
        // 0x8016F000: srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
            goto L_8016EFD8;
    }
    // 0x8016F000: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8016F004: addiu       $a0, $a3, 0x1
    ctx->r4 = ADD32(ctx->r7, 0X1);
    // 0x8016F008: sb          $a0, 0x8($t0)
    MEM_B(0X8, ctx->r8) = ctx->r4;
    // 0x8016F00C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016F010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016F014: jal         0x80004980
    // 0x8016F018: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x8016F018: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_0:
    // 0x8016F01C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8016F020: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016F024: addiu       $t0, $t0, -0x2FB8
    ctx->r8 = ADD32(ctx->r8, -0X2FB8);
    // 0x8016F028: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8016F02C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8016F030: jal         0x80004980
    // 0x8016F034: sll         $a0, $a3, 1
    ctx->r4 = S32(ctx->r7 << 1);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8016F034: sll         $a0, $a3, 1
    ctx->r4 = S32(ctx->r7 << 1);
    after_1:
    // 0x8016F038: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016F03C: addiu       $t0, $t0, -0x2FB8
    ctx->r8 = ADD32(ctx->r8, -0X2FB8);
    // 0x8016F040: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x8016F044: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8016F048: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8016F04C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8016F054: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x8016F058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016F05C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8016F060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016F064: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8016F068: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
L_8016F06C:
    // 0x8016F06C: andi        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 & 0X1;
    // 0x8016F070: beq         $t8, $zero, L_8016F0B0
    if (ctx->r24 == 0) {
        // 0x8016F074: srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
            goto L_8016F0B0;
    }
    // 0x8016F074: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8016F078: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x8016F07C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8016F080: beql        $t9, $zero, L_8016F0B4
    if (ctx->r25 == 0) {
        // 0x8016F084: andi        $t9, $a0, 0x1
        ctx->r25 = ctx->r4 & 0X1;
            goto L_8016F0B4;
    }
    goto skip_3;
    // 0x8016F084: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    skip_3:
    // 0x8016F088: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x8016F08C: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x8016F090: sb          $v1, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r3;
    // 0x8016F094: lw          $t6, 0x14($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X14);
    // 0x8016F098: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8016F09C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8016F0A0: sh          $a2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r6;
    // 0x8016F0A4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8016F0A8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8016F0AC: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
L_8016F0B0:
    // 0x8016F0B0: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
L_8016F0B4:
    // 0x8016F0B4: beq         $t9, $zero, L_8016F0F8
    if (ctx->r25 == 0) {
        // 0x8016F0B8: srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
            goto L_8016F0F8;
    }
    // 0x8016F0B8: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8016F0BC: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x8016F0C0: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x8016F0C4: beql        $t4, $zero, L_8016F0FC
    if (ctx->r12 == 0) {
        // 0x8016F0C8: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_8016F0FC;
    }
    goto skip_4;
    // 0x8016F0C8: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    skip_4:
    // 0x8016F0CC: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8016F0D0: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8016F0D4: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x8016F0D8: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x8016F0DC: lw          $t8, 0x14($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X14);
    // 0x8016F0E0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8016F0E4: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x8016F0E8: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
    // 0x8016F0EC: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x8016F0F0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8016F0F4: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
L_8016F0F8:
    // 0x8016F0F8: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
L_8016F0FC:
    // 0x8016F0FC: beq         $t6, $zero, L_8016F140
    if (ctx->r14 == 0) {
        // 0x8016F100: srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
            goto L_8016F140;
    }
    // 0x8016F100: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8016F104: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x8016F108: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x8016F10C: beql        $t5, $zero, L_8016F144
    if (ctx->r13 == 0) {
        // 0x8016F110: andi        $t8, $a0, 0x1
        ctx->r24 = ctx->r4 & 0X1;
            goto L_8016F144;
    }
    goto skip_5;
    // 0x8016F110: andi        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 & 0X1;
    skip_5:
    // 0x8016F114: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    // 0x8016F118: addiu       $t7, $v1, 0x2
    ctx->r15 = ADD32(ctx->r3, 0X2);
    // 0x8016F11C: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x8016F120: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x8016F124: lw          $t4, 0x14($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X14);
    // 0x8016F128: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8016F12C: addu        $t6, $t4, $a1
    ctx->r14 = ADD32(ctx->r12, ctx->r5);
    // 0x8016F130: sh          $a2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r6;
    // 0x8016F134: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x8016F138: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8016F13C: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
L_8016F140:
    // 0x8016F140: andi        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 & 0X1;
L_8016F144:
    // 0x8016F144: beq         $t8, $zero, L_8016F184
    if (ctx->r24 == 0) {
        // 0x8016F148: addu        $v0, $t1, $v1
        ctx->r2 = ADD32(ctx->r9, ctx->r3);
            goto L_8016F184;
    }
    // 0x8016F148: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x8016F14C: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x8016F150: beql        $t7, $zero, L_8016F188
    if (ctx->r15 == 0) {
        // 0x8016F154: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8016F188;
    }
    goto skip_6;
    // 0x8016F154: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_6:
    // 0x8016F158: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x8016F15C: addiu       $t9, $v1, 0x3
    ctx->r25 = ADD32(ctx->r3, 0X3);
    // 0x8016F160: addu        $t6, $t4, $a3
    ctx->r14 = ADD32(ctx->r12, ctx->r7);
    // 0x8016F164: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8016F168: lw          $t5, 0x14($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X14);
    // 0x8016F16C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8016F170: addu        $t8, $t5, $a1
    ctx->r24 = ADD32(ctx->r13, ctx->r5);
    // 0x8016F174: sh          $a2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r6;
    // 0x8016F178: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x8016F17C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8016F180: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
L_8016F184:
    // 0x8016F184: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8016F188:
    // 0x8016F188: bne         $v1, $t2, L_8016F06C
    if (ctx->r3 != ctx->r10) {
        // 0x8016F18C: srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
            goto L_8016F06C;
    }
    // 0x8016F18C: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8016F190: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x8016F194: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x8016F198: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016F19C: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x8016F1A0: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x8016F1A4: lw          $t5, 0x14($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X14);
    // 0x8016F1A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8016F1AC: addu        $t8, $t5, $a1
    ctx->r24 = ADD32(ctx->r13, ctx->r5);
    // 0x8016F1B0: sh          $a2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r6;
    // 0x8016F1B4: lhu         $v1, 0x10($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X10);
    // 0x8016F1B8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8016F1BC: bgez        $v1, L_8016F1D0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8016F1C0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8016F1D0;
    }
    // 0x8016F1C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016F1C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016F1C8: nop

    // 0x8016F1CC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8016F1D0:
    // 0x8016F1D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016F1D4: lwc1        $f10, -0x33E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X33E8);
    // 0x8016F1D8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8016F1DC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8016F1E0: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8016F1E4: nop

    // 0x8016F1E8: beq         $v0, $zero, L_8016F1F8
    if (ctx->r2 == 0) {
        // 0x8016F1EC: nop
    
            goto L_8016F1F8;
    }
    // 0x8016F1EC: nop

    // 0x8016F1F0: b           L_8016F1F8
    // 0x8016F1F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8016F1F8;
    // 0x8016F1F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8016F1F8:
    // 0x8016F1F8: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x8016F1FC: b           L_8016F208
    // 0x8016F200: sh          $t9, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r25;
        goto L_8016F208;
    // 0x8016F200: sh          $t9, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r25;
L_8016F204:
    // 0x8016F204: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
L_8016F208:
    // 0x8016F208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016F20C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8016F210: jr          $ra
    // 0x8016F214: nop

    return;
    // 0x8016F214: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwHitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801523F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801523F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801523FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152400: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x80152404: beql        $t6, $zero, L_80152418
    if (ctx->r14 == 0) {
        // 0x80152408: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80152418;
    }
    goto skip_0;
    // 0x80152408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015240C: jal         0x80152724
    // 0x80152410: nop

    ftPikachuSpecialLwEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x80152410: nop

    after_0:
    // 0x80152414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80152418:
    // 0x80152418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015241C: jr          $ra
    // 0x80152420: nop

    return;
    // 0x80152420: nop

;}
RECOMP_FUNC void itLinkBombExplodeUpdateAttackEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801863AC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801863B0: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x801863B4: lw          $t6, -0x493C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X493C);
    // 0x801863B8: lw          $a1, 0x340($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X340);
    // 0x801863BC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801863C0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801863C4: addiu       $t8, $t8, 0x88
    ctx->r24 = ADD32(ctx->r24, 0X88);
    // 0x801863C8: srl         $a1, $a1, 28
    ctx->r5 = S32(U32(ctx->r5) >> 28);
    // 0x801863CC: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x801863D0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801863D4: addu        $a2, $v1, $t9
    ctx->r6 = ADD32(ctx->r3, ctx->r25);
    // 0x801863D8: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x801863DC: lhu         $t0, 0x33E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X33E);
    // 0x801863E0: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x801863E4: bne         $t0, $t1, L_80186490
    if (ctx->r8 != ctx->r9) {
        // 0x801863E8: nop
    
            goto L_80186490;
    }
    // 0x801863E8: nop

    // 0x801863EC: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x801863F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801863F4: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x801863F8: sra         $t4, $t3, 22
    ctx->r12 = S32(SIGNED(ctx->r11) >> 22);
    // 0x801863FC: sw          $t4, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r12;
    // 0x80186400: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80186404: sll         $t6, $t5, 18
    ctx->r14 = S32(ctx->r13 << 18);
    // 0x80186408: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x8018640C: sw          $t7, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r15;
    // 0x80186410: lhu         $t8, 0x4($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X4);
    // 0x80186414: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80186418: bgez        $t8, L_8018642C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018641C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018642C;
    }
    // 0x8018641C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80186420: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80186424: nop

    // 0x80186428: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8018642C:
    // 0x8018642C: lbu         $t0, 0x158($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X158);
    // 0x80186430: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80186434: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80186438: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x8018643C: sb          $t2, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r10;
    // 0x80186440: andi        $t4, $t2, 0xF7
    ctx->r12 = ctx->r10 & 0XF7;
    // 0x80186444: lbu         $t2, 0x340($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X340);
    // 0x80186448: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8018644C: sb          $t4, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r12;
    // 0x80186450: andi        $t6, $t4, 0xFB
    ctx->r14 = ctx->r12 & 0XFB;
    // 0x80186454: andi        $t1, $t0, 0xF0
    ctx->r9 = ctx->r8 & 0XF0;
    // 0x80186458: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x8018645C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80186460: sb          $t4, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r12;
    // 0x80186464: lw          $t5, 0x340($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X340);
    // 0x80186468: sb          $t6, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r14;
    // 0x8018646C: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80186470: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x80186474: swc1        $f6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f6.u32l;
    // 0x80186478: sb          $t7, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r15;
    // 0x8018647C: bne         $t6, $at, L_80186490
    if (ctx->r14 != ctx->r1) {
        // 0x80186480: sw          $t8, 0x11C($v0)
        MEM_W(0X11C, ctx->r2) = ctx->r24;
            goto L_80186490;
    }
    // 0x80186480: sw          $t8, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r24;
    // 0x80186484: andi        $t8, $t4, 0xF
    ctx->r24 = ctx->r12 & 0XF;
    // 0x80186488: ori         $t9, $t8, 0x30
    ctx->r25 = ctx->r24 | 0X30;
    // 0x8018648C: sb          $t9, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r25;
L_80186490:
    // 0x80186490: jr          $ra
    // 0x80186494: nop

    return;
    // 0x80186494: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageGetDigitOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E83C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010E840: blez        $a0, L_8010E8EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8010E844: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010E8EC;
    }
    // 0x8010E844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010E848: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x8010E84C: beq         $t0, $zero, L_8010E884
    if (ctx->r8 == 0) {
        // 0x8010E850: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_8010E884;
    }
    // 0x8010E850: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8010E854: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010E858: addiu       $t0, $t0, -0x1410
    ctx->r8 = ADD32(ctx->r8, -0X1410);
    // 0x8010E85C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8010E860:
    // 0x8010E860: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8010E864: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010E868: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8010E86C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8010E870: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8010E874: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8010E878: bne         $a3, $v0, L_8010E860
    if (ctx->r7 != ctx->r2) {
        // 0x8010E87C: addu        $v1, $v1, $t9
        ctx->r3 = ADD32(ctx->r3, ctx->r25);
            goto L_8010E860;
    }
    // 0x8010E87C: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x8010E880: beq         $v0, $a0, L_8010E8EC
    if (ctx->r2 == ctx->r4) {
        // 0x8010E884: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_8010E8EC;
    }
L_8010E884:
    // 0x8010E884: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010E888: addiu       $t0, $t0, -0x1410
    ctx->r8 = ADD32(ctx->r8, -0X1410);
    // 0x8010E88C: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
L_8010E890:
    // 0x8010E890: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x8010E894: lbu         $t5, 0x1($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1);
    // 0x8010E898: lbu         $t9, 0x2($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X2);
    // 0x8010E89C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8010E8A0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8010E8A4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8010E8A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8010E8AC: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8010E8B0: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8010E8B4: lbu         $t4, 0x3($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X3);
    // 0x8010E8B8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8010E8BC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8010E8C0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8010E8C4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8010E8C8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8010E8CC: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x8010E8D0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8010E8D4: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8010E8D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8010E8DC: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x8010E8E0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8010E8E4: bne         $v0, $a0, L_8010E890
    if (ctx->r2 != ctx->r4) {
        // 0x8010E8E8: addu        $v1, $v1, $t7
        ctx->r3 = ADD32(ctx->r3, ctx->r15);
            goto L_8010E890;
    }
    // 0x8010E8E8: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
L_8010E8EC:
    // 0x8010E8EC: jr          $ra
    // 0x8010E8F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010E8F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnPlayers1PTrainingMakeTeamSelectCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B84: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132B88: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132B8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132B90: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132B94: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x80132B98: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80132B9C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80132BA0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132BA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132BA8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132BAC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132BB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132BB4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132BB8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132BBC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132BC0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132BC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132BC8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132BCC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132BD0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132BD4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132BDC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132BE0: jal         0x8000B93C
    // 0x80132BE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132BE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132BE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132BEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132BF0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132BF4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132BF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132BFC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132C00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132C04: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132C08: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132C0C: jal         0x80007080
    // 0x80132C10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132C10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132C14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132C18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132C1C: jr          $ra
    // 0x80132C20: nop

    return;
    // 0x80132C20: nop

;}
RECOMP_FUNC void ftKirbyCopyPurinSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151B04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151B08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151B0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151B10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80151B14: addiu       $a1, $zero, 0x126
    ctx->r5 = ADD32(0, 0X126);
    // 0x80151B18: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80151B1C: jal         0x800E6F24
    // 0x80151B20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80151B20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80151B24: jal         0x80151860
    // 0x80151B28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyPurinSpecialNInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x80151B28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80151B2C: jal         0x800E0830
    // 0x80151B30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80151B30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80151B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151B38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151B3C: jr          $ra
    // 0x80151B40: nop

    return;
    // 0x80151B40: nop

;}
RECOMP_FUNC void itTaruBombExplodeMakeEffectGotoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801852B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801852BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801852C0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801852C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801852C8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x801852CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801852D0: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x801852D4: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x801852D8: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x801852DC: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x801852E0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x801852E4: jal         0x801005C8
    // 0x801852E8: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801852E8: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    after_0:
    // 0x801852EC: beq         $v0, $zero, L_80185318
    if (ctx->r2 == 0) {
        // 0x801852F0: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80185318;
    }
    // 0x801852F0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801852F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801852F8: lwc1        $f4, -0x30A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30A0);
    // 0x801852FC: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x80185300: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    // 0x80185304: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80185308: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8018530C: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80185310: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x80185314: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
L_80185318:
    // 0x80185318: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018531C: jal         0x801008F4
    // 0x80185320: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80185320: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80185324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80185328: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8018532C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80185330: jal         0x80185284
    // 0x80185334: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    itTaruBombExplodeSetStatus(rdram, ctx);
        goto after_2;
    // 0x80185334: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    after_2:
    // 0x80185338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018533C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80185340: jr          $ra
    // 0x80185344: nop

    return;
    // 0x80185344: nop

;}
RECOMP_FUNC void ftCommonGetCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014606C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80146070: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80146074: lw          $t6, 0x84C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84C);
    // 0x80146078: bnel        $t6, $zero, L_801460A8
    if (ctx->r14 != 0) {
        // 0x8014607C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801460A8;
    }
    goto skip_0;
    // 0x8014607C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80146080: jal         0x80145990
    // 0x80146084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonGetFindItem(rdram, ctx);
        goto after_0;
    // 0x80146084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80146088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8014608C: beq         $v0, $zero, L_801460A4
    if (ctx->r2 == 0) {
        // 0x80146090: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_801460A4;
    }
    // 0x80146090: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80146094: jal         0x80145FD8
    // 0x80146098: nop

    ftCommonGetSetStatus(rdram, ctx);
        goto after_1;
    // 0x80146098: nop

    after_1:
    // 0x8014609C: b           L_801460A8
    // 0x801460A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801460A8;
    // 0x801460A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801460A4:
    // 0x801460A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801460A8:
    // 0x801460A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801460AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801460B0: jr          $ra
    // 0x801460B4: nop

    return;
    // 0x801460B4: nop

;}
RECOMP_FUNC void itMBallCommonProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C97C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017C980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C984: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8017C988: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017C98C: sw          $zero, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = 0;
    // 0x8017C990: sh          $t6, 0x350($a1)
    MEM_H(0X350, ctx->r5) = ctx->r14;
    // 0x8017C994: jal         0x80172FE0
    // 0x8017C998: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x8017C998: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8017C99C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C9A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C9A4: lw          $a0, 0x354($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X354);
    // 0x8017C9A8: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // 0x8017C9AC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017C9B0: lbu         $t7, 0xC($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XC);
    // 0x8017C9B4: sb          $t7, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r15;
    // 0x8017C9B8: lbu         $t8, 0xD($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XD);
    // 0x8017C9BC: sb          $t8, 0x15($a1)
    MEM_B(0X15, ctx->r5) = ctx->r24;
    // 0x8017C9C0: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x8017C9C4: sw          $t9, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r25;
    // 0x8017C9C8: lbu         $t0, 0x12($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X12);
    // 0x8017C9CC: sb          $t0, 0x16($a1)
    MEM_B(0X16, ctx->r5) = ctx->r8;
    // 0x8017C9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C9D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017C9D8: jr          $ra
    // 0x8017C9DC: nop

    return;
    // 0x8017C9DC: nop

;}
RECOMP_FUNC void func_ovl8_80382224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80382228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8038222C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382234: beq         $a0, $zero, L_803822C4
    if (ctx->r4 == 0) {
        // 0x80382238: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_803822C4;
    }
    // 0x80382238: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8038223C: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80382240: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80382244: addiu       $t6, $t6, -0x42E0
    ctx->r14 = ADD32(ctx->r14, -0X42E0);
    // 0x80382248: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038224C: addiu       $t7, $t7, -0x4210
    ctx->r15 = ADD32(ctx->r15, -0X4210);
    // 0x80382250: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80382254: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80382258: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8038225C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80382260: addiu       $t9, $t9, -0x40B8
    ctx->r25 = ADD32(ctx->r25, -0X40B8);
    // 0x80382264: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80382268: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x8038226C: beql        $a0, $zero, L_80382280
    if (ctx->r4 == 0) {
        // 0x80382270: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80382280;
    }
    goto skip_0;
    // 0x80382270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80382274: jal         0x80371764
    // 0x80382278: nop

    func_ovl8_80371764(rdram, ctx);
        goto after_0;
    // 0x80382278: nop

    after_0:
    // 0x8038227C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80382280:
    // 0x80382280: jal         0x8037354C
    // 0x80382284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037354C(rdram, ctx);
        goto after_1;
    // 0x80382284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80382288: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8038228C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382290: beql        $t1, $zero, L_803822B0
    if (ctx->r9 == 0) {
        // 0x80382294: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_803822B0;
    }
    goto skip_1;
    // 0x80382294: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80382298: jal         0x8037C30C
    // 0x8038229C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x8038229C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x803822A0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x803822A4: jal         0x803718C4
    // 0x803822A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x803822A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x803822AC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_803822B0:
    // 0x803822B0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x803822B4: beql        $t3, $zero, L_803822C8
    if (ctx->r11 == 0) {
        // 0x803822B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803822C8;
    }
    goto skip_2;
    // 0x803822B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x803822BC: jal         0x803717C0
    // 0x803822C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x803822C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_803822C4:
    // 0x803822C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803822C8:
    // 0x803822C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803822CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803822D0: jr          $ra
    // 0x803822D4: nop

    return;
    // 0x803822D4: nop

;}
RECOMP_FUNC void ifCommonBattleEndInitSoundNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113790: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80113794: jr          $ra
    // 0x80113798: sb          $zero, 0x1829($at)
    MEM_B(0X1829, ctx->r1) = 0;
    return;
    // 0x80113798: sb          $zero, 0x1829($at)
    MEM_B(0X1829, ctx->r1) = 0;
;}
RECOMP_FUNC void ftManagerSetupFilesKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D7714: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D7718: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800D771C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D7720: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800D7724: lw          $s0, 0x6E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6E10);
    // 0x800D7728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D772C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800D7730: beql        $a1, $zero, L_800D774C
    if (ctx->r5 == 0) {
        // 0x800D7734: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_800D774C;
    }
    goto skip_0;
    // 0x800D7734: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x800D7738: jal         0x800CD678
    // 0x800D773C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    lbRelocGetStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x800D773C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800D7740: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D7744: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800D7748: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
L_800D774C:
    // 0x800D774C: beq         $a0, $zero, L_800D7764
    if (ctx->r4 == 0) {
        // 0x800D7750: nop
    
            goto L_800D7764;
    }
    // 0x800D7750: nop

    // 0x800D7754: jal         0x800CD678
    // 0x800D7758: nop

    lbRelocGetStatusBufferFile(rdram, ctx);
        goto after_1;
    // 0x800D7758: nop

    after_1:
    // 0x800D775C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x800D7760: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
L_800D7764:
    // 0x800D7764: jal         0x800CD678
    // 0x800D7768: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    lbRelocGetStatusBufferFile(rdram, ctx);
        goto after_2;
    // 0x800D7768: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_2:
    // 0x800D776C: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800D7770: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x800D7774: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x800D7778: beql        $a0, $zero, L_800D7790
    if (ctx->r4 == 0) {
        // 0x800D777C: lw          $a0, 0x14($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X14);
            goto L_800D7790;
    }
    goto skip_1;
    // 0x800D777C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    skip_1:
    // 0x800D7780: jal         0x800CD678
    // 0x800D7784: nop

    lbRelocGetStatusBufferFile(rdram, ctx);
        goto after_3;
    // 0x800D7784: nop

    after_3:
    // 0x800D7788: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800D778C: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
L_800D7790:
    // 0x800D7790: beql        $a0, $zero, L_800D77AC
    if (ctx->r4 == 0) {
        // 0x800D7794: lw          $a0, 0x18($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X18);
            goto L_800D77AC;
    }
    goto skip_2;
    // 0x800D7794: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    skip_2:
    // 0x800D7798: jal         0x800CD678
    // 0x800D779C: nop

    lbRelocGetStatusBufferFile(rdram, ctx);
        goto after_4;
    // 0x800D779C: nop

    after_4:
    // 0x800D77A0: lw          $t0, 0x3C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X3C);
    // 0x800D77A4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800D77A8: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
L_800D77AC:
    // 0x800D77AC: beql        $a0, $zero, L_800D77C8
    if (ctx->r4 == 0) {
        // 0x800D77B0: lw          $a0, 0x1C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X1C);
            goto L_800D77C8;
    }
    goto skip_3;
    // 0x800D77B0: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    skip_3:
    // 0x800D77B4: jal         0x800CD678
    // 0x800D77B8: nop

    lbRelocGetStatusBufferFile(rdram, ctx);
        goto after_5;
    // 0x800D77B8: nop

    after_5:
    // 0x800D77BC: lw          $t1, 0x40($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X40);
    // 0x800D77C0: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x800D77C4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
L_800D77C8:
    // 0x800D77C8: beql        $a0, $zero, L_800D77E4
    if (ctx->r4 == 0) {
        // 0x800D77CC: lw          $a0, 0x20($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X20);
            goto L_800D77E4;
    }
    goto skip_4;
    // 0x800D77CC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    skip_4:
    // 0x800D77D0: jal         0x800CD678
    // 0x800D77D4: nop

    lbRelocGetStatusBufferFile(rdram, ctx);
        goto after_6;
    // 0x800D77D4: nop

    after_6:
    // 0x800D77D8: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x800D77DC: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x800D77E0: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
L_800D77E4:
    // 0x800D77E4: beql        $a0, $zero, L_800D7800
    if (ctx->r4 == 0) {
        // 0x800D77E8: lw          $a0, 0x50($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X50);
            goto L_800D7800;
    }
    goto skip_5;
    // 0x800D77E8: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    skip_5:
    // 0x800D77EC: jal         0x800CD678
    // 0x800D77F0: nop

    lbRelocGetStatusBufferFile(rdram, ctx);
        goto after_7;
    // 0x800D77F0: nop

    after_7:
    // 0x800D77F4: lw          $t3, 0x48($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X48);
    // 0x800D77F8: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x800D77FC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
L_800D7800:
    // 0x800D7800: beql        $a0, $zero, L_800D781C
    if (ctx->r4 == 0) {
        // 0x800D7804: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D781C;
    }
    goto skip_6;
    // 0x800D7804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800D7808: jal         0x801159B0
    // 0x800D780C: nop

    efParticleGetBankID(rdram, ctx);
        goto after_8;
    // 0x800D780C: nop

    after_8:
    // 0x800D7810: lw          $t4, 0x4C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4C);
    // 0x800D7814: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x800D7818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D781C:
    // 0x800D781C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D7820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D7824: jr          $ra
    // 0x800D7828: nop

    return;
    // 0x800D7828: nop

;}
RECOMP_FUNC void sc1PGameBossProcDisplayFadeColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191908: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8019190C: addiu       $v0, $v0, 0x38F0
    ctx->r2 = ADD32(ctx->r2, 0X38F0);
    // 0x80191910: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191914: lwc1        $f6, 0x2F70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2F70);
    // 0x80191918: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019191C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80191920: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80191924: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80191928: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8019192C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80191930: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80191934: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80191938: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019193C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80191940: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80191944: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80191948: nop

    // 0x8019194C: bc1fl       L_80191960
    if (!c1cs) {
        // 0x80191950: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80191960;
    }
    goto skip_0;
    // 0x80191950: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80191954: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80191958: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019195C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80191960:
    // 0x80191960: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80191964: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80191968: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019196C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80191970: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80191974: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191978: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019197C: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x80191980: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80191984: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80191988: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8019198C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80191990: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191994: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191998: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x8019199C: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x801919A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801919A4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801919A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801919AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801919B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801919B4: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x801919B8: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801919BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801919C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801919C4: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x801919C8: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x801919CC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801919D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801919D4: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x801919D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801919DC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801919E0: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    // 0x801919E4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801919E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801919EC: sll         $t7, $a0, 24
    ctx->r15 = S32(ctx->r4 << 24);
    // 0x801919F0: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x801919F4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801919F8: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x801919FC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80191A00: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80191A04: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x80191A08: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80191A0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191A10: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80191A14: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x80191A18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80191A1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80191A20: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x80191A24: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x80191A28: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80191A2C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80191A30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191A34: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80191A38: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80191A3C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80191A40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80191A44: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80191A48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191A4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191A50: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80191A54: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80191A58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80191A5C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80191A60: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80191A64: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80191A68: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80191A6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191A70: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80191A74: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80191A78: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80191A7C: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x80191A80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80191A84: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80191A88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80191A8C: jr          $ra
    // 0x80191A90: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    return;
    // 0x80191A90: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
;}
RECOMP_FUNC void sc1PBonusStageSetBonusStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E8D0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8018E8D4: addiu       $a1, $a1, 0x4AD0
    ctx->r5 = ADD32(ctx->r5, 0X4AD0);
    // 0x8018E8D8: lbu         $t7, 0x13($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X13);
    // 0x8018E8DC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018E8E0: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x8018E8E4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018E8E8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018E8EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E8F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018E8F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8018E8F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E8FC: addiu       $v1, $v1, 0xD6C
    ctx->r3 = ADD32(ctx->r3, 0XD6C);
    // 0x8018E900: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8018E904: lw          $t0, 0x58($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X58);
    // 0x8018E908: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018E90C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018E910: lui         $t5, 0x4
    ctx->r13 = S32(0X4 << 16);
    // 0x8018E914: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x8018E918: beq         $a0, $zero, L_8018E934
    if (ctx->r4 == 0) {
        // 0x8018E91C: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8018E934;
    }
    // 0x8018E91C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8018E920: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
    // 0x8018E924: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
    // 0x8018E928: sw          $zero, 0x30($a1)
    MEM_W(0X30, ctx->r5) = 0;
    // 0x8018E92C: jr          $ra
    // 0x8018E930: sw          $zero, 0x34($a1)
    MEM_W(0X34, ctx->r5) = 0;
    return;
    // 0x8018E930: sw          $zero, 0x34($a1)
    MEM_W(0X34, ctx->r5) = 0;
L_8018E934:
    // 0x8018E934: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x8018E938: sw          $t5, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r13;
    // 0x8018E93C: sw          $zero, 0x30($a1)
    MEM_W(0X30, ctx->r5) = 0;
    // 0x8018E940: addiu       $t3, $t2, 0x3B
    ctx->r11 = ADD32(ctx->r10, 0X3B);
    // 0x8018E944: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x8018E948: mflo        $t4
    ctx->r12 = lo;
    // 0x8018E94C: sw          $t4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r12;
    // 0x8018E950: sw          $zero, 0x34($a1)
    MEM_W(0X34, ctx->r5) = 0;
    // 0x8018E954: jr          $ra
    // 0x8018E958: nop

    return;
    // 0x8018E958: nop

;}
RECOMP_FUNC void wpFoxBlasterProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168A14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80168A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168A1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80168A20: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80168A24: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80168A28: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x80168A2C: jal         0x801680EC
    // 0x80168A30: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x80168A30: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80168A34: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80168A38: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80168A3C: jal         0x8001863C
    // 0x80168A40: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80168A40: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x80168A44: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80168A48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80168A4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80168A50: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x80168A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80168A58: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x80168A5C: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80168A60: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x80168A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80168A6C: jr          $ra
    // 0x80168A70: nop

    return;
    // 0x80168A70: nop

;}
RECOMP_FUNC void gcPauseGObjProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B2EC: bne         $a0, $zero, L_8000B2FC
    if (ctx->r4 != 0) {
        // 0x8000B2F0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8000B2FC;
    }
    // 0x8000B2F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000B2F4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000B2F8: lw          $a0, 0x6A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A60);
L_8000B2FC:
    // 0x8000B2FC: jr          $ra
    // 0x8000B300: sb          $t6, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r14;
    return;
    // 0x8000B300: sb          $t6, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void mnPlayers1PBonusFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B0C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B10: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B1C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B28: jal         0x8039051C
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B30: jal         0x80390528
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B40: jal         0x800FCB70
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B50: jr          $ra
    // 0x80131B54: nop

    return;
    // 0x80131B54: nop

;}
RECOMP_FUNC void scStaffrollMakeScrollGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013498C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013499C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801349A0: jal         0x80009968
    // 0x801349A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801349A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801349A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801349AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801349B0: addiu       $a1, $a1, 0x4854
    ctx->r5 = ADD32(ctx->r5, 0X4854);
    // 0x801349B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801349B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801349BC: jal         0x80008188
    // 0x801349C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x801349C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x801349C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801349C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801349CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801349D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801349D4: jr          $ra
    // 0x801349D8: sw          $t6, -0x5738($at)
    MEM_W(-0X5738, ctx->r1) = ctx->r14;
    return;
    // 0x801349D8: sw          $t6, -0x5738($at)
    MEM_W(-0X5738, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void grCommonSetupInitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105608: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010560C: lw          $a0, 0x1300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1300);
    // 0x80105610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80105614: jal         0x8010547C
    // 0x80105618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    grDisplayMakeGeometryLayer(rdram, ctx);
        goto after_0;
    // 0x80105618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8010561C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80105620: lw          $a0, 0x1300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1300);
    // 0x80105624: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105628: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010562C: sw          $v0, 0x13E0($at)
    MEM_W(0X13E0, ctx->r1) = ctx->r2;
    // 0x80105630: lw          $a2, 0x1304($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1304);
    // 0x80105634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80105638: jal         0x8010547C
    // 0x8010563C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    grDisplayMakeGeometryLayer(rdram, ctx);
        goto after_1;
    // 0x8010563C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x80105640: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80105644: lw          $a0, 0x1300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1300);
    // 0x80105648: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010564C: sw          $v0, 0x13E4($at)
    MEM_W(0X13E4, ctx->r1) = ctx->r2;
    // 0x80105650: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80105654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80105658: jal         0x8010547C
    // 0x8010565C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    grDisplayMakeGeometryLayer(rdram, ctx);
        goto after_2;
    // 0x8010565C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
    // 0x80105660: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80105664: lw          $a0, 0x1300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1300);
    // 0x80105668: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010566C: sw          $v0, 0x13E8($at)
    MEM_W(0X13E8, ctx->r1) = ctx->r2;
    // 0x80105670: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80105674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80105678: jal         0x8010547C
    // 0x8010567C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    grDisplayMakeGeometryLayer(rdram, ctx);
        goto after_3;
    // 0x8010567C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_3:
    // 0x80105680: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105684: jal         0x800FC450
    // 0x80105688: sw          $v0, 0x13EC($at)
    MEM_W(0X13EC, ctx->r1) = ctx->r2;
    mpCollisionClearYakumonoAll(rdram, ctx);
        goto after_4;
    // 0x80105688: sw          $v0, 0x13EC($at)
    MEM_W(0X13EC, ctx->r1) = ctx->r2;
    after_4:
    // 0x8010568C: jal         0x801056C0
    // 0x80105690: nop

    grMainSetupMakeGround(rdram, ctx);
        goto after_5;
    // 0x80105690: nop

    after_5:
    // 0x80105694: jal         0x800FBD14
    // 0x80105698: nop

    mpCollisionInitYakumonoAll(rdram, ctx);
        goto after_6;
    // 0x80105698: nop

    after_6:
    // 0x8010569C: jal         0x8016EC40
    // 0x801056A0: nop

    itManagerMakeAppearActor(rdram, ctx);
        goto after_7;
    // 0x801056A0: nop

    after_7:
    // 0x801056A4: jal         0x80116AD0
    // 0x801056A8: nop

    efGroundMakeAppearActor(rdram, ctx);
        goto after_8;
    // 0x801056A8: nop

    after_8:
    // 0x801056AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801056B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801056B4: jr          $ra
    // 0x801056B8: nop

    return;
    // 0x801056B8: nop

;}
RECOMP_FUNC void ftCommonShieldBreakFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149744: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80149748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014974C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80149750: addiu       $t7, $zero, 0x10B2
    ctx->r15 = ADD32(0, 0X10B2);
    // 0x80149754: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80149758: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    // 0x8014975C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80149760: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80149764: jal         0x800E6F24
    // 0x80149768: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149768: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014976C: jal         0x800D8EB8
    // 0x80149770: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_1;
    // 0x80149770: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80149774: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80149778: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8014977C: jal         0x800E806C
    // 0x80149780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_2;
    // 0x80149780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80149784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80149788: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014978C: jr          $ra
    // 0x80149790: nop

    return;
    // 0x80149790: nop

;}
RECOMP_FUNC void ftMainProcSearchCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E6104: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E6108: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E610C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E6110: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E6114: jal         0x800E1EE8
    // 0x800E6118: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftMainSearchHitHazard(rdram, ctx);
        goto after_0;
    // 0x800E6118: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x800E611C: lw          $t6, 0x190($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X190);
    // 0x800E6120: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x800E6124: bgezl       $t8, L_800E6168
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E6128: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E6168;
    }
    goto skip_0;
    // 0x800E6128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800E612C: jal         0x800E5E58
    // 0x800E6130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainSearchFighterCatch(rdram, ctx);
        goto after_1;
    // 0x800E6130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800E6134: lw          $t9, 0x830($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X830);
    // 0x800E6138: beql        $t9, $zero, L_800E6168
    if (ctx->r25 == 0) {
        // 0x800E613C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E6168;
    }
    goto skip_1;
    // 0x800E613C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800E6140: lw          $t9, 0x838($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X838);
    // 0x800E6144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E6148: jalr        $t9
    // 0x800E614C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800E614C: nop

    after_2:
    // 0x800E6150: lw          $t9, 0x83C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X83C);
    // 0x800E6154: lw          $a0, 0x830($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X830);
    // 0x800E6158: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E615C: jalr        $t9
    // 0x800E6160: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800E6160: nop

    after_3:
    // 0x800E6164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E6168:
    // 0x800E6168: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E616C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E6170: jr          $ra
    // 0x800E6174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800E6174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void n_alFxNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D218: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002D21C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8002D220: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D224: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8002D228: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8002D22C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8002D230: addiu       $t6, $zero, 0x2C
    ctx->r14 = ADD32(0, 0X2C);
    // 0x8002D234: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8002D238: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8002D23C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8002D240: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8002D244: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8002D248: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8002D24C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8002D250: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8002D254: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8002D258: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8002D25C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8002D260: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8002D264: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002D268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D26C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D270: jal         0x8001E5F4
    // 0x8002D274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x8002D274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8002D278: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8002D27C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8002D280: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8002D284: lbu         $t7, 0x1C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1C);
    // 0x8002D288: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002D28C: addiu       $s3, $s3, -0x2E18
    ctx->r19 = ADD32(ctx->r19, -0X2E18);
    // 0x8002D290: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8002D294: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x8002D298: beq         $at, $zero, L_8002D2F8
    if (ctx->r1 == 0) {
        // 0x8002D29C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8002D2F8;
    }
    // 0x8002D29C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002D2A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002D2A4: addu        $at, $at, $t8
    gpr jr_addend_8002D2AC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8002D2A8: lw          $t8, -0x1184($at)
    ctx->r24 = ADD32(ctx->r1, -0X1184);
    // 0x8002D2AC: jr          $t8
    // 0x8002D2B0: nop

    switch (jr_addend_8002D2AC >> 2) {
        case 0: goto L_8002D2B4; break;
        case 1: goto L_8002D2C0; break;
        case 2: goto L_8002D2D8; break;
        case 3: goto L_8002D2E4; break;
        case 4: goto L_8002D2CC; break;
        case 5: goto L_8002D2F0; break;
        default: switch_error(__func__, 0x8002D2AC, 0x8003EE7C);
    }
    // 0x8002D2B0: nop

L_8002D2B4:
    // 0x8002D2B4: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8002D2B8: b           L_8002D2F8
    // 0x8002D2BC: addiu       $s3, $s3, -0x2F80
    ctx->r19 = ADD32(ctx->r19, -0X2F80);
        goto L_8002D2F8;
    // 0x8002D2BC: addiu       $s3, $s3, -0x2F80
    ctx->r19 = ADD32(ctx->r19, -0X2F80);
L_8002D2C0:
    // 0x8002D2C0: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8002D2C4: b           L_8002D2F8
    // 0x8002D2C8: addiu       $s3, $s3, -0x2F18
    ctx->r19 = ADD32(ctx->r19, -0X2F18);
        goto L_8002D2F8;
    // 0x8002D2C8: addiu       $s3, $s3, -0x2F18
    ctx->r19 = ADD32(ctx->r19, -0X2F18);
L_8002D2CC:
    // 0x8002D2CC: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8002D2D0: b           L_8002D2F8
    // 0x8002D2D4: addiu       $s3, $s3, -0x2E90
    ctx->r19 = ADD32(ctx->r19, -0X2E90);
        goto L_8002D2F8;
    // 0x8002D2D4: addiu       $s3, $s3, -0x2E90
    ctx->r19 = ADD32(ctx->r19, -0X2E90);
L_8002D2D8:
    // 0x8002D2D8: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8002D2DC: b           L_8002D2F8
    // 0x8002D2E0: addiu       $s3, $s3, -0x2E68
    ctx->r19 = ADD32(ctx->r19, -0X2E68);
        goto L_8002D2F8;
    // 0x8002D2E0: addiu       $s3, $s3, -0x2E68
    ctx->r19 = ADD32(ctx->r19, -0X2E68);
L_8002D2E4:
    // 0x8002D2E4: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8002D2E8: b           L_8002D2F8
    // 0x8002D2EC: addiu       $s3, $s3, -0x2E40
    ctx->r19 = ADD32(ctx->r19, -0X2E40);
        goto L_8002D2F8;
    // 0x8002D2EC: addiu       $s3, $s3, -0x2E40
    ctx->r19 = ADD32(ctx->r19, -0X2E40);
L_8002D2F0:
    // 0x8002D2F0: b           L_8002D2F8
    // 0x8002D2F4: lw          $s3, 0x20($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X20);
        goto L_8002D2F8;
    // 0x8002D2F4: lw          $s3, 0x20($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X20);
L_8002D2F8:
    // 0x8002D2F8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8002D2FC: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8002D300: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8002D304: sb          $t9, 0x24($s5)
    MEM_B(0X24, ctx->r21) = ctx->r25;
    // 0x8002D308: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    // 0x8002D30C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D314: sw          $t0, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r8;
    // 0x8002D318: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002D31C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002D320: jal         0x8001E5F4
    // 0x8002D324: andi        $a3, $t9, 0xFF
    ctx->r7 = ctx->r25 & 0XFF;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x8002D324: andi        $a3, $t9, 0xFF
    ctx->r7 = ctx->r25 & 0XFF;
    after_1:
    // 0x8002D328: sw          $v0, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r2;
    // 0x8002D32C: lw          $a3, 0x1C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X1C);
    // 0x8002D330: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8002D334: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002D338: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D33C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D340: jal         0x8001E5F4
    // 0x8002D344: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8002D344: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x8002D348: lw          $t3, 0x1C($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X1C);
    // 0x8002D34C: sw          $v0, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r2;
    // 0x8002D350: sw          $v0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r2;
    // 0x8002D354: beq         $t3, $zero, L_8002D384
    if (ctx->r11 == 0) {
        // 0x8002D358: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002D384;
    }
    // 0x8002D358: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002D35C: lw          $t4, 0x14($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X14);
L_8002D360:
    // 0x8002D360: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x8002D364: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002D368: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8002D36C: sh          $zero, 0x0($t6)
    MEM_H(0X0, ctx->r14) = 0;
    // 0x8002D370: lw          $t7, 0x1C($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X1C);
    // 0x8002D374: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8002D378: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x8002D37C: bnel        $at, $zero, L_8002D360
    if (ctx->r1 != 0) {
        // 0x8002D380: lw          $t4, 0x14($s5)
        ctx->r12 = MEM_W(ctx->r21, 0X14);
            goto L_8002D360;
    }
    goto skip_0;
    // 0x8002D380: lw          $t4, 0x14($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X14);
    skip_0:
L_8002D384:
    // 0x8002D384: lbu         $t8, 0x24($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X24);
    // 0x8002D388: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002D38C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002D390: blez        $t8, L_8002D5D8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8002D394: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_8002D5D8;
    }
    // 0x8002D394: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8002D398: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8002D39C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002D3A0: lwc1        $f22, -0x116C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X116C);
    // 0x8002D3A4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8002D3A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8002D3AC: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8002D3B0: addiu       $s7, $zero, 0x28
    ctx->r23 = ADD32(0, 0X28);
L_8002D3B4:
    // 0x8002D3B4: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D3B8: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8002D3BC: lw          $t9, 0x20($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X20);
    // 0x8002D3C0: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8002D3C4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8002D3C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D3CC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D3D0: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8002D3D4: addu        $t5, $s3, $t4
    ctx->r13 = ADD32(ctx->r19, ctx->r12);
    // 0x8002D3D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D3DC: mflo        $t0
    ctx->r8 = lo;
    // 0x8002D3E0: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x8002D3E4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8002D3E8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8002D3EC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D3F0: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8002D3F4: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8002D3F8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8002D3FC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002D400: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D404: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D408: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8002D40C: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x8002D410: sh          $t9, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r25;
    // 0x8002D414: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8002D418: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D41C: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D420: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8002D424: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x8002D428: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
    // 0x8002D42C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8002D430: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D434: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D438: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8002D43C: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x8002D440: sh          $t5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r13;
    // 0x8002D444: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8002D448: beql        $v0, $zero, L_8002D534
    if (ctx->r2 == 0) {
        // 0x8002D44C: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8002D534;
    }
    goto skip_1;
    // 0x8002D44C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    skip_1:
    // 0x8002D450: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002D454: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8002D458: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8002D45C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002D460: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8002D464: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8002D468: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D46C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8002D470: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8002D474: div.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8002D478: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8002D47C: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D480: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8002D484: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002D488: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x8002D48C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002D490: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002D494: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8002D498: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8002D49C: bgez        $t2, L_8002D4B0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8002D4A0: swc1        $f18, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
            goto L_8002D4B0;
    }
    // 0x8002D4A0: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8002D4A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002D4A8: nop

    // 0x8002D4AC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8002D4B0:
    // 0x8002D4B0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8002D4B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D4B8: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x8002D4BC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8002D4C0: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8002D4C4: addiu       $t6, $zero, 0x34
    ctx->r14 = ADD32(0, 0X34);
    // 0x8002D4C8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D4CC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D4D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D4D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D4D8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002D4DC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8002D4E0: div.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8002D4E4: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002D4E8: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x8002D4EC: jal         0x8001E5F4
    // 0x8002D4F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x8002D4F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8002D4F4: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8002D4F8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8002D4FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002D500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D508: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002D50C: jal         0x8001E5F4
    // 0x8002D510: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x8002D510: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_4:
    // 0x8002D514: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8002D518: sw          $v0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r2;
    // 0x8002D51C: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8002D520: swc1        $f26, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f26.u32l;
    // 0x8002D524: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8002D528: b           L_8002D53C
    // 0x8002D52C: sw          $fp, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r30;
        goto L_8002D53C;
    // 0x8002D52C: sw          $fp, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r30;
    // 0x8002D530: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_8002D534:
    // 0x8002D534: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8002D538: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
L_8002D53C:
    // 0x8002D53C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8002D540: addu        $s2, $s3, $t1
    ctx->r18 = ADD32(ctx->r19, ctx->r9);
    // 0x8002D544: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8002D548: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D54C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D550: beq         $t2, $zero, L_8002D5B4
    if (ctx->r10 == 0) {
        // 0x8002D554: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_8002D5B4;
    }
    // 0x8002D554: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002D558: addiu       $t3, $zero, 0x30
    ctx->r11 = ADD32(0, 0X30);
    // 0x8002D55C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002D560: jal         0x8001E5F4
    // 0x8002D564: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x8002D564: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_5:
    // 0x8002D568: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8002D56C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8002D570: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002D574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D57C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002D580: jal         0x8001E5F4
    // 0x8002D584: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x8002D584: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_6:
    // 0x8002D588: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x8002D58C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D590: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D594: sw          $v0, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r2;
    // 0x8002D598: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x8002D59C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8002D5A0: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8002D5A4: jal         0x8002CED4
    // 0x8002D5A8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _init_lpfilter(rdram, ctx);
        goto after_7;
    // 0x8002D5A8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x8002D5AC: b           L_8002D5C4
    // 0x8002D5B0: lbu         $t8, 0x24($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X24);
        goto L_8002D5C4;
    // 0x8002D5B0: lbu         $t8, 0x24($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X24);
L_8002D5B4:
    // 0x8002D5B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D5B8: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8002D5BC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8002D5C0: lbu         $t8, 0x24($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X24);
L_8002D5C4:
    // 0x8002D5C4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002D5C8: andi        $s4, $s4, 0xFFFF
    ctx->r20 = ctx->r20 & 0XFFFF;
    // 0x8002D5CC: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002D5D0: bne         $at, $zero, L_8002D3B4
    if (ctx->r1 != 0) {
        // 0x8002D5D4: nop
    
            goto L_8002D3B4;
    }
    // 0x8002D5D4: nop

L_8002D5D8:
    // 0x8002D5D8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8002D5DC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8002D5E0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8002D5E4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8002D5E8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8002D5EC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8002D5F0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8002D5F4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8002D5F8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8002D5FC: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8002D600: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8002D604: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8002D608: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8002D60C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8002D610: jr          $ra
    // 0x8002D614: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002D614: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void sc1PGameSetGameStatusWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EB68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018EB6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018EB70: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018EB74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EB78: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8018EB7C: jal         0x80009968
    // 0x8018EB80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018EB80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018EB84: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018EB88: addiu       $a1, $a1, -0x1524
    ctx->r5 = ADD32(ctx->r5, -0X1524);
    // 0x8018EB8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EB90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018EB94: jal         0x80008188
    // 0x8018EB98: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8018EB98: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x8018EB9C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018EBA0: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018EBA4: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    // 0x8018EBA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018EBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018EBB0: jr          $ra
    // 0x8018EBB4: nop

    return;
    // 0x8018EBB4: nop

;}
RECOMP_FUNC void wpFoxBlasterProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80168928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016892C: jal         0x80167C04
    // 0x80168930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x80168930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80168934: beq         $v0, $zero, L_80168950
    if (ctx->r2 == 0) {
        // 0x80168938: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80168950;
    }
    // 0x80168938: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016893C: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80168940: jal         0x80103320
    // 0x80168944: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerFoxBlasterGlowMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80168944: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80168948: b           L_80168954
    // 0x8016894C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80168954;
    // 0x8016894C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80168950:
    // 0x80168950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80168954:
    // 0x80168954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016895C: jr          $ra
    // 0x80168960: nop

    return;
    // 0x80168960: nop

;}
RECOMP_FUNC void syTaskmanSetFuncSwapBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800048D0: beq         $a0, $zero, L_800048E4
    if (ctx->r4 == 0) {
        // 0x800048D4: lui         $t6, 0x8000
        ctx->r14 = S32(0X8000 << 16);
            goto L_800048E4;
    }
    // 0x800048D4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800048D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800048DC: jr          $ra
    // 0x800048E0: sw          $a0, 0x666C($at)
    MEM_W(0X666C, ctx->r1) = ctx->r4;
    return;
    // 0x800048E0: sw          $a0, 0x666C($at)
    MEM_W(0X666C, ctx->r1) = ctx->r4;
L_800048E4:
    // 0x800048E4: addiu       $t6, $t6, 0xA34
    ctx->r14 = ADD32(ctx->r14, 0XA34);
    // 0x800048E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800048EC: sw          $t6, 0x666C($at)
    MEM_W(0X666C, ctx->r1) = ctx->r14;
    // 0x800048F0: jr          $ra
    // 0x800048F4: nop

    return;
    // 0x800048F4: nop

;}
RECOMP_FUNC void mnPlayers1PGamePuckProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013712C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137130: lw          $t7, -0x708C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X708C);
    // 0x80137134: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80137138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013713C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80137140: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x80137144: beq         $at, $zero, L_80137160
    if (ctx->r1 == 0) {
        // 0x80137148: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_80137160;
    }
    // 0x80137148: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8013714C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80137150: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137154: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80137158: b           L_801371A0
    // 0x8013715C: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
        goto L_801371A0;
    // 0x8013715C: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
L_80137160:
    // 0x80137160: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137164: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80137168: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x8013716C: bne         $t9, $zero, L_80137194
    if (ctx->r25 != 0) {
        // 0x80137170: nop
    
            goto L_80137194;
    }
    // 0x80137170: nop

    // 0x80137174: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
    // 0x80137178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013717C: beq         $v0, $t0, L_80137194
    if (ctx->r2 == ctx->r8) {
        // 0x80137180: nop
    
            goto L_80137194;
    }
    // 0x80137180: nop

    // 0x80137184: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x80137188: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013718C: bnel        $v0, $t1, L_801371A0
    if (ctx->r2 != ctx->r9) {
        // 0x80137190: sw          $t2, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r10;
            goto L_801371A0;
    }
    goto skip_0;
    // 0x80137190: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    skip_0:
L_80137194:
    // 0x80137194: b           L_801371A0
    // 0x80137198: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_801371A0;
    // 0x80137198: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8013719C: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
L_801371A0:
    // 0x801371A0: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x801371A4: bne         $t3, $zero, L_8013720C
    if (ctx->r11 != 0) {
        // 0x801371A8: nop
    
            goto L_8013720C;
    }
    // 0x801371A8: nop

    // 0x801371AC: lw          $t4, 0x50($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X50);
    // 0x801371B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801371B4: beq         $t4, $at, L_8013720C
    if (ctx->r12 == ctx->r1) {
        // 0x801371B8: nop
    
            goto L_8013720C;
    }
    // 0x801371B8: nop

    // 0x801371BC: lw          $t5, 0x70($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X70);
    // 0x801371C0: bne         $t5, $zero, L_80137214
    if (ctx->r13 != 0) {
        // 0x801371C4: nop
    
            goto L_80137214;
    }
    // 0x801371C4: nop

    // 0x801371C8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801371CC: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x801371D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801371D4: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x801371D8: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x801371DC: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x801371E0: lwc1        $f4, 0x58($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X58);
    // 0x801371E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801371E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801371EC: swc1        $f8, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f8.u32l;
    // 0x801371F0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801371F4: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x801371F8: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x801371FC: lwc1        $f10, 0x5C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x80137200: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80137204: b           L_80137214
    // 0x80137208: swc1        $f18, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f18.u32l;
        goto L_80137214;
    // 0x80137208: swc1        $f18, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f18.u32l;
L_8013720C:
    // 0x8013720C: jal         0x801370EC
    // 0x80137210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameMovePuck(rdram, ctx);
        goto after_0;
    // 0x80137210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
L_80137214:
    // 0x80137214: jal         0x80136050
    // 0x80137218: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameGetPuckFighterKind(rdram, ctx);
        goto after_1;
    // 0x80137218: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013721C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137220: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80137224: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x80137228: bne         $t2, $zero, L_80137250
    if (ctx->r10 != 0) {
        // 0x8013722C: nop
    
            goto L_80137250;
    }
    // 0x8013722C: nop

    // 0x80137230: lw          $t3, 0x20($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X20);
    // 0x80137234: beq         $v0, $t3, L_80137250
    if (ctx->r2 == ctx->r11) {
        // 0x80137238: nop
    
            goto L_80137250;
    }
    // 0x80137238: nop

    // 0x8013723C: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x80137240: jal         0x80135804
    // 0x80137244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameUpdateFighter(rdram, ctx);
        goto after_2;
    // 0x80137244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80137248: jal         0x801358C4
    // 0x8013724C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameUpdateNameAndEmblem(rdram, ctx);
        goto after_3;
    // 0x8013724C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_80137250:
    // 0x80137250: jal         0x80134B3C
    // 0x80137254: nop

    mnPlayers1PGameMakeFighterRecord(rdram, ctx);
        goto after_4;
    // 0x80137254: nop

    after_4:
    // 0x80137258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013725C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80137260: jr          $ra
    // 0x80137264: nop

    return;
    // 0x80137264: nop

;}
RECOMP_FUNC void itBoxExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017994C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179950: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80179954: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80179958: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8017995C: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80179960: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80179964: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80179968: bne         $t8, $at, L_80179978
    if (ctx->r24 != ctx->r1) {
        // 0x8017996C: sh          $t7, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r15;
            goto L_80179978;
    }
    // 0x8017996C: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x80179970: b           L_80179994
    // 0x80179974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80179994;
    // 0x80179974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80179978:
    // 0x80179978: lw          $t9, -0x5CAC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5CAC);
    // 0x8017997C: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80179980: addiu       $t1, $t1, 0x614
    ctx->r9 = ADD32(ctx->r9, 0X614);
    // 0x80179984: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80179988: jal         0x80173180
    // 0x8017998C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x8017998C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x80179990: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80179994:
    // 0x80179994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017999C: jr          $ra
    // 0x801799A0: nop

    return;
    // 0x801799A0: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133694: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133698: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8013369C: lui         $t9, 0x804
    ctx->r25 = S32(0X804 << 16);
    // 0x801336A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801336A4: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x801336A8: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x801336AC: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x801336B0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801336B4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801336B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801336BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801336C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801336C4: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801336C8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801336CC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801336D0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801336D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801336D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801336DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801336E0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801336E4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801336E8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801336EC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801336F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801336F4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801336F8: jal         0x8000B93C
    // 0x801336FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801336FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133700: jal         0x801335D4
    // 0x80133704: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    mnPlayers1PGameContinueSetupCamera(rdram, ctx);
        goto after_1;
    // 0x80133704: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    after_1:
    // 0x80133708: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013370C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133710: jr          $ra
    // 0x80133714: nop

    return;
    // 0x80133714: nop

;}
RECOMP_FUNC void mvOpeningJungleSetupFiles(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8018D0E0: addiu       $t8, $t8, -0x2558
    ctx->r24 = ADD32(ctx->r24, -0X2558);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x23D8
    ctx->r8 = ADD32(ctx->r8, -0X23D8);
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
    // 0x8018D118: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D11C: addiu       $a0, $a0, -0x26CC
    ctx->r4 = ADD32(ctx->r4, -0X26CC);
    // 0x8018D120: jal         0x800CDEEC
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
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
    // 0x8018D134: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D138: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018D13C: addiu       $a2, $a2, -0x23A0
    ctx->r6 = ADD32(ctx->r6, -0X23A0);
    // 0x8018D140: addiu       $a0, $a0, -0x26CC
    ctx->r4 = ADD32(ctx->r4, -0X26CC);
    // 0x8018D144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
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
RECOMP_FUNC void mnBackupClearMakeMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132430: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132434: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132438: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013243C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132440: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80132444: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132448: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8013244C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132450: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132454: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132458: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013245C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132460: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132464: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132468: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013246C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132470: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132474: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132478: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013247C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132480: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132488: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013248C: jal         0x8000B93C
    // 0x80132490: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132490: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132494: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132498: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013249C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801324A0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801324A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801324A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801324AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801324B0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801324B4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801324B8: jal         0x80007080
    // 0x801324BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801324BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801324C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801324C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801324C8: jr          $ra
    // 0x801324CC: nop

    return;
    // 0x801324CC: nop

;}
RECOMP_FUNC void ftFoxSpecialLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CBEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015CBF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015CBF4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8015CBF8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015CBFC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8015CC00: jal         0x8015CBA4
    // 0x8015CC04: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftFoxSpecialLwUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x8015CC04: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015CC08: jal         0x8015CB80
    // 0x8015CC0C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ftFoxSpecialLwCheckSetRelease(rdram, ctx);
        goto after_1;
    // 0x8015CC0C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8015CC10: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8015CC14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015CC18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8015CC1C: lwc1        $f6, 0x78($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X78);
    // 0x8015CC20: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015CC24: nop

    // 0x8015CC28: bc1fl       L_8015CC58
    if (!c1cs) {
        // 0x8015CC2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015CC58;
    }
    goto skip_0;
    // 0x8015CC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015CC30: lw          $t7, 0x14C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14C);
    // 0x8015CC34: bne         $t7, $zero, L_8015CC4C
    if (ctx->r15 != 0) {
        // 0x8015CC38: nop
    
            goto L_8015CC4C;
    }
    // 0x8015CC38: nop

    // 0x8015CC3C: jal         0x8015CD90
    // 0x8015CC40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftFoxSpecialLwLoopSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015CC40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8015CC44: b           L_8015CC58
    // 0x8015CC48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015CC58;
    // 0x8015CC48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CC4C:
    // 0x8015CC4C: jal         0x8015CDCC
    // 0x8015CC50: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftFoxSpecialAirLwLoopSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015CC50: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x8015CC54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CC58:
    // 0x8015CC58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015CC5C: jr          $ra
    // 0x8015CC60: nop

    return;
    // 0x8015CC60: nop

;}
RECOMP_FUNC void itHitokageWeaponFlameMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801842C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801842CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801842D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801842D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801842D8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801842DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801842E0: addiu       $a1, $a1, -0x4B0C
    ctx->r5 = ADD32(ctx->r5, -0X4B0C);
    // 0x801842E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801842E8: jal         0x801655C8
    // 0x801842EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x801842EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x801842F0: bne         $v0, $zero, L_80184300
    if (ctx->r2 != 0) {
        // 0x801842F4: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80184300;
    }
    // 0x801842F4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x801842F8: b           L_801843B0
    // 0x801842FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801843B0;
    // 0x801842FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80184300:
    // 0x80184300: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80184304: lw          $v1, 0x84($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X84);
    // 0x80184308: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8018430C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80184310: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80184314: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80184318: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x8018431C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80184320: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80184324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80184328: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    // 0x8018432C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80184330: sw          $t9, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r25;
    // 0x80184334: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x80184338: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x8018433C: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80184340: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80184344: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80184348: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8018434C: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x80184350: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80184354: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80184358: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8018435C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80184360: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80184364: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x80184368: jal         0x800CE8C0
    // 0x8018436C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_1;
    // 0x8018436C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80184370: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80184374: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80184378: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8018437C: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80184380: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80184384: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80184388: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018438C: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x80184390: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80184394: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80184398: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018439C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801843A0: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x801843A4: jal         0x800CE8C0
    // 0x801843A8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_2;
    // 0x801843A8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801843AC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_801843B0:
    // 0x801843B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801843B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801843B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801843BC: jr          $ra
    // 0x801843C0: nop

    return;
    // 0x801843C0: nop

;}
RECOMP_FUNC void itNBumperAttachedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BBFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017BC00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BC04: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017BC08: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8017BC0C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BC10: addiu       $a1, $a1, -0x47D8
    ctx->r5 = ADD32(ctx->r5, -0X47D8);
    // 0x8017BC14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017BC18: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8017BC1C: jal         0x801735A0
    // 0x8017BC20: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017BC20: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8017BC24: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BC28: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8017BC2C: beq         $v0, $zero, L_8017BCAC
    if (ctx->r2 == 0) {
        // 0x8017BC30: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8017BCAC;
    }
    // 0x8017BC30: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8017BC34: lhu         $a0, 0x2D0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2D0);
    // 0x8017BC38: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8017BC3C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8017BC40: jal         0x800FC67C
    // 0x8017BC44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_1;
    // 0x8017BC44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8017BC48: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BC4C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8017BC50: bne         $v0, $zero, L_8017BC98
    if (ctx->r2 != 0) {
        // 0x8017BC54: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8017BC98;
    }
    // 0x8017BC54: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8017BC58: lbu         $t6, 0x2CF($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2CF);
    // 0x8017BC5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8017BC60: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x8017BC64: sb          $t7, 0x2CF($v1)
    MEM_B(0X2CF, ctx->r3) = ctx->r15;
    // 0x8017BC68: jal         0x8017B828
    // 0x8017BC6C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    itNBumperDroppedSetStatus(rdram, ctx);
        goto after_2;
    // 0x8017BC6C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x8017BC70: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8017BC74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BC78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017BC7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BC80: lw          $t8, 0x80($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X80);
    // 0x8017BC84: swc1        $f0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->f0.u32l;
    // 0x8017BC88: swc1        $f0, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->f0.u32l;
    // 0x8017BC8C: swc1        $f0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f0.u32l;
    // 0x8017BC90: b           L_8017BCAC
    // 0x8017BC94: swc1        $f4, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->f4.u32l;
        goto L_8017BCAC;
    // 0x8017BC94: swc1        $f4, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->f4.u32l;
L_8017BC98:
    // 0x8017BC98: lhu         $t9, 0x33E($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017BC9C: bnel        $t9, $zero, L_8017BCB0
    if (ctx->r25 != 0) {
        // 0x8017BCA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017BCB0;
    }
    goto skip_0;
    // 0x8017BCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017BCA4: jal         0x8017B874
    // 0x8017BCA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    itNBumperAttachedSetModelPitch(rdram, ctx);
        goto after_3;
    // 0x8017BCA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
L_8017BCAC:
    // 0x8017BCAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017BCB0:
    // 0x8017BCB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017BCB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017BCB8: jr          $ra
    // 0x8017BCBC: nop

    return;
    // 0x8017BCBC: nop

;}
RECOMP_FUNC void ftBossAppearProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AEE0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015AEE4: lw          $a1, 0x8EC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8EC);
    // 0x8015AEE8: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    // 0x8015AEEC: lw          $t7, 0x1C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1C);
    // 0x8015AEF0: sw          $t7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r15;
    // 0x8015AEF4: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // 0x8015AEF8: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x8015AEFC: lw          $t7, 0x24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X24);
    // 0x8015AF00: jr          $ra
    // 0x8015AF04: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    return;
    // 0x8015AF04: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
;}
RECOMP_FUNC void itBombHeiCommonSetExplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177060: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80177064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80177068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017706C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80177070: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80177074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80177078: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8017707C: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80177080: jal         0x80177218
    // 0x80177084: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    itBombHeiCommonSetHitStatusNone(rdram, ctx);
        goto after_0;
    // 0x80177084: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80177088: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8017708C: jal         0x801005C8
    // 0x80177090: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80177090: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80177094: beq         $v0, $zero, L_801770B8
    if (ctx->r2 == 0) {
        // 0x80177098: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801770B8;
    }
    // 0x80177098: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017709C: lwc1        $f0, -0x32D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X32D0);
    // 0x801770A0: lw          $t8, 0x5C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5C);
    // 0x801770A4: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x801770A8: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x801770AC: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x801770B0: lw          $t0, 0x5C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X5C);
    // 0x801770B4: swc1        $f0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f0.u32l;
L_801770B8:
    // 0x801770B8: jal         0x801008F4
    // 0x801770BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x801770BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x801770C0: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x801770C4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801770C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801770CC: sb          $t1, 0x54($t2)
    MEM_B(0X54, ctx->r10) = ctx->r9;
    // 0x801770D0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x801770D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801770D8: jal         0x8017275C
    // 0x801770DC: sh          $t3, 0x156($t4)
    MEM_H(0X156, ctx->r12) = ctx->r11;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_3;
    // 0x801770DC: sh          $t3, 0x156($t4)
    MEM_H(0X156, ctx->r12) = ctx->r11;
    after_3:
    // 0x801770E0: jal         0x8017279C
    // 0x801770E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainClearOwnerStats(rdram, ctx);
        goto after_4;
    // 0x801770E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801770E8: jal         0x80177C30
    // 0x801770EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itBombHeiExplodeSetStatus(rdram, ctx);
        goto after_5;
    // 0x801770EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801770F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801770F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801770F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801770FC: jr          $ra
    // 0x80177100: nop

    return;
    // 0x80177100: nop

;}
RECOMP_FUNC void ftCommonShieldBreakFlyReflectorSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149608: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014960C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149610: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80149614: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80149618: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8014961C: lw          $v0, 0x850($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X850);
    // 0x80149620: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80149624: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80149628: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8014962C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80149630: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80149634: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80149638: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8014963C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80149640: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80149644: lw          $a0, 0x8E8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8E8);
    // 0x80149648: jal         0x800EDF24
    // 0x8014964C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8014964C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80149650: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80149654: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80149658: lw          $a1, 0x18C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X18C);
    // 0x8014965C: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    // 0x80149660: jal         0x8010155C
    // 0x80149664: sra         $a1, $a1, 30
    ctx->r5 = S32(SIGNED(ctx->r5) >> 30);
    efManagerReflectBreakMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80149664: sra         $a1, $a1, 30
    ctx->r5 = S32(SIGNED(ctx->r5) >> 30);
    after_1:
    // 0x80149668: jal         0x80149488
    // 0x8014966C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftCommonShieldBreakFlySetStatus(rdram, ctx);
        goto after_2;
    // 0x8014966C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80149670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149674: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80149678: jr          $ra
    // 0x8014967C: nop

    return;
    // 0x8014967C: nop

;}
RECOMP_FUNC void itCapsuleThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174168: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017416C: jal         0x801737B8
    // 0x80174170: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80174170: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    after_0:
    // 0x80174174: beql        $v0, $zero, L_801741A0
    if (ctx->r2 == 0) {
        // 0x80174178: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801741A0;
    }
    goto skip_0;
    // 0x80174178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8017417C: jal         0x801730D4
    // 0x80174180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainMakeContainerItem(rdram, ctx);
        goto after_1;
    // 0x80174180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80174184: beq         $v0, $zero, L_80174194
    if (ctx->r2 == 0) {
        // 0x80174188: nop
    
            goto L_80174194;
    }
    // 0x80174188: nop

    // 0x8017418C: b           L_801741A0
    // 0x80174190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801741A0;
    // 0x80174190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80174194:
    // 0x80174194: jal         0x80174428
    // 0x80174198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itCapsuleExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_2;
    // 0x80174198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8017419C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801741A0:
    // 0x801741A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801741A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801741A8: jr          $ra
    // 0x801741AC: nop

    return;
    // 0x801741AC: nop

;}
RECOMP_FUNC void itNessPKFireCommonUpdateAllCheckDestroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185374: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80185378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018537C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80185380: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80185384: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80185388: lw          $t6, 0x2C0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C0);
    // 0x8018538C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80185390: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80185394: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80185398: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8018539C: lw          $a3, 0x350($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X350);
    // 0x801853A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801853A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801853A8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801853AC: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801853B0: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801853B4: add.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x801853B8: swc1        $f0, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f0.u32l;
    // 0x801853BC: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x801853C0: lwc1        $f2, 0x48($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X48);
    // 0x801853C4: swc1        $f2, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f2.u32l;
    // 0x801853C8: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x801853CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801853D0: swc1        $f2, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f2.u32l;
    // 0x801853D4: lw          $v1, 0x2D4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2D4);
    // 0x801853D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801853DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801853E0: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x801853E4: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x801853E8: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x801853EC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x801853F0: nop

    // 0x801853F4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801853F8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801853FC: swc1        $f6, 0x120($v0)
    MEM_W(0X120, ctx->r2) = ctx->f6.u32l;
    // 0x80185400: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x80185404: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80185408: nop

    // 0x8018540C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80185410: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80185414: swc1        $f16, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f16.u32l;
    // 0x80185418: lh          $t3, 0x16($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X16);
    // 0x8018541C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80185420: nop

    // 0x80185424: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80185428: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8018542C: swc1        $f6, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f6.u32l;
    // 0x80185430: lh          $t4, 0x18($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X18);
    // 0x80185434: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80185438: nop

    // 0x8018543C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80185440: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80185444: swc1        $f16, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f16.u32l;
    // 0x80185448: lh          $t5, 0x1A($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1A);
    // 0x8018544C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80185450: nop

    // 0x80185454: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80185458: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8018545C: swc1        $f6, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f6.u32l;
    // 0x80185460: lh          $t6, 0x1C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1C);
    // 0x80185464: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80185468: nop

    // 0x8018546C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80185470: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80185474: swc1        $f16, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->f16.u32l;
    // 0x80185478: lhu         $t7, 0x32($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X32);
    // 0x8018547C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80185480: bgez        $t7, L_80185494
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80185484: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80185494;
    }
    // 0x80185484: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80185488: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018548C: nop

    // 0x80185490: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80185494:
    // 0x80185494: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80185498: nop

    // 0x8018549C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801854A0: swc1        $f10, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f10.u32l;
    // 0x801854A4: lh          $t8, 0x1E($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1E);
    // 0x801854A8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801854AC: nop

    // 0x801854B0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801854B4: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801854B8: swc1        $f6, 0x24C($v0)
    MEM_W(0X24C, ctx->r2) = ctx->f6.u32l;
    // 0x801854BC: lh          $t9, 0x20($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X20);
    // 0x801854C0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801854C4: nop

    // 0x801854C8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801854CC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801854D0: swc1        $f10, 0x250($v0)
    MEM_W(0X250, ctx->r2) = ctx->f10.u32l;
    // 0x801854D4: lh          $t0, 0x22($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X22);
    // 0x801854D8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801854DC: nop

    // 0x801854E0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801854E4: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801854E8: swc1        $f6, 0x254($v0)
    MEM_W(0X254, ctx->r2) = ctx->f6.u32l;
    // 0x801854EC: lh          $t1, 0x24($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X24);
    // 0x801854F0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801854F4: nop

    // 0x801854F8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801854FC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80185500: nop

    // 0x80185504: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80185508: swc1        $f16, 0x258($v0)
    MEM_W(0X258, ctx->r2) = ctx->f16.u32l;
    // 0x8018550C: lh          $t2, 0x26($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X26);
    // 0x80185510: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80185514: nop

    // 0x80185518: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018551C: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80185520: nop

    // 0x80185524: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80185528: swc1        $f8, 0x25C($v0)
    MEM_W(0X25C, ctx->r2) = ctx->f8.u32l;
    // 0x8018552C: lh          $t3, 0x28($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X28);
    // 0x80185530: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80185534: nop

    // 0x80185538: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018553C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80185540: nop

    // 0x80185544: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80185548: beq         $a3, $zero, L_80185590
    if (ctx->r7 == 0) {
        // 0x8018554C: swc1        $f6, 0x260($v0)
        MEM_W(0X260, ctx->r2) = ctx->f6.u32l;
            goto L_80185590;
    }
    // 0x8018554C: swc1        $f6, 0x260($v0)
    MEM_W(0X260, ctx->r2) = ctx->f6.u32l;
    // 0x80185550: lw          $t4, 0x74($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X74);
    // 0x80185554: lwc1        $f4, 0x40($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X40);
    // 0x80185558: swc1        $f4, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f4.u32l;
    // 0x8018555C: lw          $t5, 0x74($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X74);
    // 0x80185560: lwc1        $f8, 0x44($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X44);
    // 0x80185564: swc1        $f8, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f8.u32l;
    // 0x80185568: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x8018556C: lwc1        $f10, 0x48($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80185570: swc1        $f10, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f10.u32l;
    // 0x80185574: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x80185578: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8018557C: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x80185580: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x80185584: sw          $t8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r24;
    // 0x80185588: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8018558C: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
L_80185590:
    // 0x80185590: lw          $t0, 0x2C0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C0);
    // 0x80185594: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80185598: bgez        $t1, L_801855D0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018559C: sw          $t1, 0x2C0($v0)
        MEM_W(0X2C0, ctx->r2) = ctx->r9;
            goto L_801855D0;
    }
    // 0x8018559C: sw          $t1, 0x2C0($v0)
    MEM_W(0X2C0, ctx->r2) = ctx->r9;
    // 0x801855A0: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
    // 0x801855A4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801855A8: jal         0x800FF648
    // 0x801855AC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801855AC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x801855B0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801855B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801855B8: beq         $a3, $zero, L_801855C8
    if (ctx->r7 == 0) {
        // 0x801855BC: nop
    
            goto L_801855C8;
    }
    // 0x801855BC: nop

    // 0x801855C0: jal         0x800D39D4
    // 0x801855C4: lhu         $a0, 0xB8($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0XB8);
    lbParticleEjectStructID(rdram, ctx);
        goto after_1;
    // 0x801855C4: lhu         $a0, 0xB8($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0XB8);
    after_1:
L_801855C8:
    // 0x801855C8: b           L_801855D4
    // 0x801855CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801855D4;
    // 0x801855CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801855D0:
    // 0x801855D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801855D4:
    // 0x801855D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801855D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801855DC: jr          $ra
    // 0x801855E0: nop

    return;
    // 0x801855E0: nop

;}
RECOMP_FUNC void ftCommonWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E1C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013E1CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013E1D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8013E1D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013E1D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013E1DC: jal         0x800F3794
    // 0x8013E1E0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x8013E1E0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8013E1E4: beql        $v0, $zero, L_8013E200
    if (ctx->r2 == 0) {
        // 0x8013E1E8: lw          $t6, 0x14C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X14C);
            goto L_8013E200;
    }
    goto skip_0;
    // 0x8013E1E8: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    skip_0:
    // 0x8013E1EC: jal         0x800F3938
    // 0x8013E1F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftHammerSetStatusHammerWait(rdram, ctx);
        goto after_1;
    // 0x8013E1F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8013E1F4: b           L_8013E248
    // 0x8013E1F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8013E248;
    // 0x8013E1F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013E1FC: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
L_8013E200:
    // 0x8013E200: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013E204: bnel        $t6, $at, L_8013E218
    if (ctx->r14 != ctx->r1) {
        // 0x8013E208: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013E218;
    }
    goto skip_1;
    // 0x8013E208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x8013E20C: jal         0x800DEE98
    // 0x8013E210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_2;
    // 0x8013E210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013E214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8013E218:
    // 0x8013E218: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8013E21C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013E220: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013E224: jal         0x800E6F24
    // 0x8013E228: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_3;
    // 0x8013E228: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8013E22C: lbu         $t8, 0x192($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X192);
    // 0x8013E230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013E234: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8013E238: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x8013E23C: jal         0x800E7F7C
    // 0x8013E240: sb          $t9, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r25;
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_4;
    // 0x8013E240: sb          $t9, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r25;
    after_4:
    // 0x8013E244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8013E248:
    // 0x8013E248: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013E24C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8013E250: jr          $ra
    // 0x8013E254: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8013E254: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sc1PGameWaitStageCommonUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E670: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8018E674: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8018E678: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8018E67C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8018E680: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8018E684: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8018E688: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8018E68C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8018E690: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8018E694: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8018E698: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8018E69C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018E6A0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018E6A4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018E6A8: jal         0x80018994
    // 0x8018E6AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8018E6AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8018E6B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018E6B4: jal         0x8000B1E8
    // 0x8018E6B8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x8018E6B8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_1:
    // 0x8018E6BC: jal         0x80112668
    // 0x8018E6C0: nop

    ifCommonCountdownMakeInterface(rdram, ctx);
        goto after_2;
    // 0x8018E6C0: nop

    after_2:
    // 0x8018E6C4: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018E6C8: addiu       $t7, $t7, 0x2B0C
    ctx->r15 = ADD32(ctx->r15, 0X2B0C);
    // 0x8018E6CC: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x8018E6D0: addu        $fp, $t6, $t7
    ctx->r30 = ADD32(ctx->r14, ctx->r15);
    // 0x8018E6D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E6D8: bne         $s0, $at, L_8018E6E8
    if (ctx->r16 != ctx->r1) {
        // 0x8018E6DC: lhu         $s4, 0x0($fp)
        ctx->r20 = MEM_HU(ctx->r30, 0X0);
            goto L_8018E6E8;
    }
    // 0x8018E6DC: lhu         $s4, 0x0($fp)
    ctx->r20 = MEM_HU(ctx->r30, 0X0);
    // 0x8018E6E0: jal         0x8000B1E8
    // 0x8018E6E4: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_3;
    // 0x8018E6E4: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_3:
L_8018E6E8:
    // 0x8018E6E8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8018E6EC: addiu       $v1, $v1, 0x50E8
    ctx->r3 = ADD32(ctx->r3, 0X50E8);
    // 0x8018E6F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8018E6F4: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x8018E6F8: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
    // 0x8018E6FC: addu        $s5, $t8, $t9
    ctx->r21 = ADD32(ctx->r24, ctx->r25);
    // 0x8018E700: slti        $at, $s5, 0x3
    ctx->r1 = SIGNED(ctx->r21) < 0X3 ? 1 : 0;
    // 0x8018E704: beq         $at, $zero, L_8018E714
    if (ctx->r1 == 0) {
        // 0x8018E708: nop
    
            goto L_8018E714;
    }
    // 0x8018E708: nop

    // 0x8018E70C: jal         0x8000B1E8
    // 0x8018E710: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_4;
    // 0x8018E710: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
L_8018E714:
    // 0x8018E714: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8018E718: lbu         $s2, 0x4AE3($s2)
    ctx->r18 = MEM_BU(ctx->r18, 0X4AE3);
    // 0x8018E71C: blez        $s5, L_8018E7C8
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8018E720: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8018E7C8;
    }
    // 0x8018E720: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8018E724: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8018E728: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018E72C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E730: lui         $s7, 0x8019
    ctx->r23 = S32(0X8019 << 16);
    // 0x8018E734: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018E738: addiu       $s7, $s7, 0x2B10
    ctx->r23 = ADD32(ctx->r23, 0X2B10);
    // 0x8018E73C: lwc1        $f22, 0x2ED8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X2ED8);
    // 0x8018E740: addiu       $s6, $zero, 0x74
    ctx->r22 = ADD32(0, 0X74);
L_8018E744:
    // 0x8018E744: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018E748: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8018E74C: addiu       $v1, $v1, 0x50E8
    ctx->r3 = ADD32(ctx->r3, 0X50E8);
    // 0x8018E750: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8018E754: mflo        $t1
    ctx->r9 = lo;
    // 0x8018E758: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8018E75C: lw          $s0, 0x78($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X78);
    // 0x8018E760: jal         0x8013DBE0
    // 0x8018E764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppearSetStatus(rdram, ctx);
        goto after_5;
    // 0x8018E764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8018E768: bne         $fp, $s7, L_8018E7AC
    if (ctx->r30 != ctx->r23) {
        // 0x8018E76C: addiu       $a0, $zero, 0x1E
        ctx->r4 = ADD32(0, 0X1E);
            goto L_8018E7AC;
    }
    // 0x8018E76C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8018E770: jal         0x8000B1E8
    // 0x8018E774: addiu       $s1, $s4, -0x1E
    ctx->r17 = ADD32(ctx->r20, -0X1E);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_6;
    // 0x8018E774: addiu       $s1, $s4, -0x1E
    ctx->r17 = ADD32(ctx->r20, -0X1E);
    after_6:
    // 0x8018E778: lw          $t3, 0x84($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X84);
    // 0x8018E77C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018E780: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018E784: lw          $t4, 0x9C8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X9C8);
    // 0x8018E788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018E78C: lw          $a3, 0x90($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X90);
    // 0x8018E790: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x8018E794: jal         0x8010CF44
    // 0x8018E798: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    gmCameraSetStatusPlayerZoom(rdram, ctx);
        goto after_7;
    // 0x8018E798: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_7:
    // 0x8018E79C: jal         0x8000B1E8
    // 0x8018E7A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_8;
    // 0x8018E7A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8018E7A4: b           L_8018E7B4
    // 0x8018E7A8: nop

        goto L_8018E7B4;
    // 0x8018E7A8: nop

L_8018E7AC:
    // 0x8018E7AC: jal         0x8000B1E8
    // 0x8018E7B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_9;
    // 0x8018E7B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
L_8018E7B4:
    // 0x8018E7B4: jal         0x8018D280
    // 0x8018E7B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    sc1PGameGetNextFreePlayerPort(rdram, ctx);
        goto after_10;
    // 0x8018E7B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x8018E7BC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018E7C0: bne         $s3, $s5, L_8018E744
    if (ctx->r19 != ctx->r21) {
        // 0x8018E7C4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8018E744;
    }
    // 0x8018E7C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8018E7C8:
    // 0x8018E7C8: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8018E7CC: addiu       $t5, $t5, 0x2B10
    ctx->r13 = ADD32(ctx->r13, 0X2B10);
    // 0x8018E7D0: bnel        $fp, $t5, L_8018E7EC
    if (ctx->r30 != ctx->r13) {
        // 0x8018E7D4: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_8018E7EC;
    }
    goto skip_0;
    // 0x8018E7D4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x8018E7D8: jal         0x8000B1E8
    // 0x8018E7DC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_11;
    // 0x8018E7DC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_11:
    // 0x8018E7E0: jal         0x8010CF20
    // 0x8018E7E4: nop

    gmCameraSetStatusDefault(rdram, ctx);
        goto after_12;
    // 0x8018E7E4: nop

    after_12:
    // 0x8018E7E8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8018E7EC:
    // 0x8018E7EC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018E7F0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018E7F4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018E7F8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8018E7FC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E800: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8018E804: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8018E808: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8018E80C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8018E810: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8018E814: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8018E818: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8018E81C: jr          $ra
    // 0x8018E820: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8018E820: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void scExplainLoadExplainFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D0C4: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x8018D0C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0CC: addiu       $a0, $a0, 0xC6
    ctx->r4 = ADD32(ctx->r4, 0XC6);
    // 0x8018D0D0: jal         0x800CDBD0
    // 0x8018D0D4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x8018D0D4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D0D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D0DC: jal         0x80004980
    // 0x8018D0E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8018D0E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8018D0E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D0E8: jal         0x800CDC88
    // 0x8018D0EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x8018D0EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8018D0F0: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x8018D0F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D0F8: addiu       $a0, $a0, 0xFC
    ctx->r4 = ADD32(ctx->r4, 0XFC);
    // 0x8018D0FC: sw          $v0, -0x1620($at)
    MEM_W(-0X1620, ctx->r1) = ctx->r2;
    // 0x8018D100: jal         0x800CDBD0
    // 0x8018D104: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_3;
    // 0x8018D104: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x8018D108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D10C: jal         0x80004980
    // 0x8018D110: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_4;
    // 0x8018D110: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x8018D114: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D118: jal         0x800CDC88
    // 0x8018D11C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_5;
    // 0x8018D11C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8018D120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D124: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D128: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018D12C: addiu       $v1, $v1, -0x161C
    ctx->r3 = ADD32(ctx->r3, -0X161C);
    // 0x8018D130: addiu       $t7, $t7, 0x1404
    ctx->r15 = ADD32(ctx->r15, 0X1404);
    // 0x8018D134: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D138: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8018D13C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D140: sw          $t8, -0x1618($at)
    MEM_W(-0X1618, ctx->r1) = ctx->r24;
    // 0x8018D144: jr          $ra
    // 0x8018D148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018D148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itLinkBombHoldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80186024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80186028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018602C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80186030: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80186034: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80186038: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x8018603C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80186040: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80186044: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x80186048: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x8018604C: bnel        $t7, $at, L_80186060
    if (ctx->r15 != ctx->r1) {
        // 0x80186050: lw          $v1, 0x2C0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X2C0);
            goto L_80186060;
    }
    goto skip_0;
    // 0x80186050: lw          $v1, 0x2C0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C0);
    skip_0:
    // 0x80186054: b           L_80186108
    // 0x80186058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80186108;
    // 0x80186058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018605C: lw          $v1, 0x2C0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C0);
L_80186060:
    // 0x80186060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80186064: addiu       $a1, $s0, 0x2C
    ctx->r5 = ADD32(ctx->r16, 0X2C);
    // 0x80186068: bnel        $v1, $zero, L_80186090
    if (ctx->r3 != 0) {
        // 0x8018606C: mtc1        $v1, $f4
        ctx->f4.u32l = ctx->r3;
            goto L_80186090;
    }
    goto skip_1;
    // 0x8018606C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    skip_1:
    // 0x80186070: jal         0x80172984
    // 0x80186074: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    itMainSetFighterRelease(rdram, ctx);
        goto after_0;
    // 0x80186074: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x80186078: jal         0x8017279C
    // 0x8018607C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8018607C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80186080: jal         0x80186368
    // 0x80186084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itLinkBombExplodeInitVars(rdram, ctx);
        goto after_2;
    // 0x80186084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80186088: lw          $v1, 0x2C0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C0);
    // 0x8018608C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
L_80186090:
    // 0x80186090: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x80186094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80186098: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018609C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801860A0: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x801860A4: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x801860A8: nop

    // 0x801860AC: bc1fl       L_801860D8
    if (!c1cs) {
        // 0x801860B0: lui         $at, 0x42C0
        ctx->r1 = S32(0X42C0 << 16);
            goto L_801860D8;
    }
    goto skip_2;
    // 0x801860B0: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    skip_2:
    // 0x801860B4: jal         0x80172F98
    // 0x801860B8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    itMainCheckSetColAnimID(rdram, ctx);
        goto after_3;
    // 0x801860B8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_3:
    // 0x801860BC: lw          $v1, 0x2C0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C0);
    // 0x801860C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801860C4: sh          $t8, 0x354($s0)
    MEM_H(0X354, ctx->r16) = ctx->r24;
    // 0x801860C8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x801860CC: nop

    // 0x801860D0: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801860D4: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
L_801860D8:
    // 0x801860D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801860DC: nop

    // 0x801860E0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801860E4: nop

    // 0x801860E8: bc1fl       L_80186100
    if (!c1cs) {
        // 0x801860EC: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_80186100;
    }
    goto skip_3;
    // 0x801860EC: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    skip_3:
    // 0x801860F0: jal         0x801859C0
    // 0x801860F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itLinkBombExplodeWaitUpdateScale(rdram, ctx);
        goto after_4;
    // 0x801860F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801860F8: lw          $v1, 0x2C0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C0);
    // 0x801860FC: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
L_80186100:
    // 0x80186100: sw          $t9, 0x2C0($s0)
    MEM_W(0X2C0, ctx->r16) = ctx->r25;
    // 0x80186104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80186108:
    // 0x80186108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018610C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80186110: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80186114: jr          $ra
    // 0x80186118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80186118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void sc1PBonusStageSetTimeUp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E298: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018E29C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E2A0: jr          $ra
    // 0x8018E2A4: sw          $t6, -0xC58($at)
    MEM_W(-0XC58, ctx->r1) = ctx->r14;
    return;
    // 0x8018E2A4: sw          $t6, -0xC58($at)
    MEM_W(-0XC58, ctx->r1) = ctx->r14;
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itBombHeiWalkSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801779A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801779AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801779B0: jal         0x80177208
    // 0x801779B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBombHeiCommonSetHitStatusNormal(rdram, ctx);
        goto after_0;
    // 0x801779B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801779B8: jal         0x80177848
    // 0x801779BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itBombHeiWalkInitVars(rdram, ctx);
        goto after_1;
    // 0x801779BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801779C0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801779C4: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x801779C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801779CC: jal         0x80172EC8
    // 0x801779D0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x801779D0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // 0x801779D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801779D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801779DC: jr          $ra
    // 0x801779E0: nop

    return;
    // 0x801779E0: nop

;}
RECOMP_FUNC void gmRumbleGetMotorUpdateStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801151F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801151F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801151FC: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80115200: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80115204: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80115208: bnel        $t6, $zero, L_80115244
    if (ctx->r14 != 0) {
        // 0x8011520C: lbu         $v0, 0x0($a3)
        ctx->r2 = MEM_BU(ctx->r7, 0X0);
            goto L_80115244;
    }
    goto skip_0;
    // 0x8011520C: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    skip_0:
    // 0x80115210: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80115214: jal         0x800044B4
    // 0x80115218: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    syControllerInitRumble(rdram, ctx);
        goto after_0;
    // 0x80115218: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8011521C: jal         0x80004494
    // 0x80115220: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    syControllerStopRumble(rdram, ctx);
        goto after_1;
    // 0x80115220: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80115224: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80115228: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x8011522C: beq         $t7, $zero, L_80115238
    if (ctx->r15 == 0) {
        // 0x80115230: nop
    
            goto L_80115238;
    }
    // 0x80115230: nop

    // 0x80115234: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
L_80115238:
    // 0x80115238: b           L_80115288
    // 0x8011523C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80115288;
    // 0x8011523C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80115240: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
L_80115244:
    // 0x80115244: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x80115248: beql        $t8, $v0, L_80115288
    if (ctx->r24 == ctx->r2) {
        // 0x8011524C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80115288;
    }
    goto skip_1;
    // 0x8011524C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80115250: beq         $v0, $zero, L_80115270
    if (ctx->r2 == 0) {
        // 0x80115254: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80115270;
    }
    // 0x80115254: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80115258: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8011525C: jal         0x80004494
    // 0x80115260: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    syControllerStopRumble(rdram, ctx);
        goto after_2;
    // 0x80115260: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80115264: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80115268: b           L_80115284
    // 0x8011526C: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
        goto L_80115284;
    // 0x8011526C: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
L_80115270:
    // 0x80115270: jal         0x80004474
    // 0x80115274: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    syControllerStartRumble(rdram, ctx);
        goto after_3;
    // 0x80115274: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x80115278: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8011527C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80115280: sb          $t9, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r25;
L_80115284:
    // 0x80115284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80115288:
    // 0x80115288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011528C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80115290: jr          $ra
    // 0x80115294: nop

    return;
    // 0x80115294: nop

;}
RECOMP_FUNC void mnOptionStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335C0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801335C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801335C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801335CC: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801335D0: addiu       $a0, $a0, 0x36F8
    ctx->r4 = ADD32(ctx->r4, 0X36F8);
    // 0x801335D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801335D8: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801335DC: jal         0x80007024
    // 0x801335E0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801335E0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801335E4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801335E8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801335EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801335F0: addiu       $t9, $t9, 0x38C0
    ctx->r25 = ADD32(ctx->r25, 0X38C0);
    // 0x801335F4: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801335F8: addiu       $a0, $a0, 0x3714
    ctx->r4 = ADD32(ctx->r4, 0X3714);
    // 0x801335FC: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80133600: jal         0x8000683C
    // 0x80133604: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80133604: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80133608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013360C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133610: jr          $ra
    // 0x80133614: nop

    return;
    // 0x80133614: nop

;}
RECOMP_FUNC void itMSBombExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176F34: jal         0x80176E9C
    // 0x80176F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMSBombExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80176F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80176F3C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80176F40: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x80176F44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80176F48: jal         0x80172EC8
    // 0x80176F4C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80176F4C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_1:
    // 0x80176F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176F58: jr          $ra
    // 0x80176F5C: nop

    return;
    // 0x80176F5C: nop

;}
RECOMP_FUNC void ftBossTsutsuku3SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159F14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80159F18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159F1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159F20: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x80159F24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159F28: jal         0x800E6F24
    // 0x80159F2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159F2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80159F30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80159F38: jr          $ra
    // 0x80159F3C: nop

    return;
    // 0x80159F3C: nop

;}
RECOMP_FUNC void efManagerPurinSingMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801020F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801020F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801020FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80102100: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102104: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80102108: jal         0x800FDB1C
    // 0x8010210C: addiu       $a0, $a0, -0x1CEC
    ctx->r4 = ADD32(ctx->r4, -0X1CEC);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x8010210C: addiu       $a0, $a0, -0x1CEC
    ctx->r4 = ADD32(ctx->r4, -0X1CEC);
    after_0:
    // 0x80102110: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80102114: bne         $v0, $zero, L_80102124
    if (ctx->r2 != 0) {
        // 0x80102118: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80102124;
    }
    // 0x80102118: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8010211C: b           L_801021AC
    // 0x80102120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801021AC;
    // 0x80102120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102124:
    // 0x80102124: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x80102128: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x8010212C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80102130: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80102134: lw          $t6, 0x84($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X84);
    // 0x80102138: lw          $v1, 0x74($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X74);
    // 0x8010213C: lw          $t7, 0x8E8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8E8);
    // 0x80102140: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80102144: sw          $t7, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r15;
    // 0x80102148: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010214C: jal         0x80008CC0
    // 0x80102150: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80102150: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80102154: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80102158: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8010215C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80102160: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x80102164: lw          $s0, 0x8($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X8);
    // 0x80102168: jal         0x80008CC0
    // 0x8010216C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8010216C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80102170: lw          $s0, 0x10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X10);
    // 0x80102174: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80102178: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8010217C: jal         0x80008CC0
    // 0x80102180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x80102180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80102184: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80102188: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8010218C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80102190: jal         0x80008CC0
    // 0x80102194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80102194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80102198: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8010219C: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x801021A0: jal         0x80008CC0
    // 0x801021A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_5;
    // 0x801021A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x801021A8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_801021AC:
    // 0x801021AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801021B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801021B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801021B8: jr          $ra
    // 0x801021BC: nop

    return;
    // 0x801021BC: nop

;}
RECOMP_FUNC void ftCommonLandingSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142D9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80142DA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142DA4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80142DA8: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80142DAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80142DB0: lw          $t6, 0x18C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18C);
    // 0x80142DB4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80142DB8: bgez        $t8, L_80142DF8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80142DBC: nop
    
            goto L_80142DF8;
    }
    // 0x80142DBC: nop

    // 0x80142DC0: lw          $t9, 0x9C8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X9C8);
    // 0x80142DC4: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80142DC8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80142DCC: lwc1        $f4, 0x60($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X60);
    // 0x80142DD0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80142DD4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80142DD8: nop

    // 0x80142DDC: bc1f        L_80142DF8
    if (!c1cs) {
        // 0x80142DE0: nop
    
            goto L_80142DF8;
    }
    // 0x80142DE0: nop

    // 0x80142DE4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80142DE8: jal         0x80142D44
    // 0x80142DEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    ftCommonLandingSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x80142DEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80142DF0: b           L_80142E04
    // 0x80142DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80142E04;
    // 0x80142DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80142DF8:
    // 0x80142DF8: jal         0x80142D44
    // 0x80142DFC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftCommonLandingSetStatusParam(rdram, ctx);
        goto after_1;
    // 0x80142DFC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80142E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80142E04:
    // 0x80142E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142E08: jr          $ra
    // 0x80142E0C: nop

    return;
    // 0x80142E0C: nop

;}
RECOMP_FUNC void mpCommonProcFighterLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE6E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE6E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE6EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DE6F0: jal         0x800DE6B0
    // 0x800DE6F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x800DE6F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DE6F8: beq         $v0, $zero, L_800DE710
    if (ctx->r2 == 0) {
        // 0x800DE6FC: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_800DE710;
    }
    // 0x800DE6FC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE700: jalr        $t9
    // 0x800DE704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800DE704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800DE708: b           L_800DE714
    // 0x800DE70C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DE714;
    // 0x800DE70C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DE710:
    // 0x800DE710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DE714:
    // 0x800DE714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE71C: jr          $ra
    // 0x800DE720: nop

    return;
    // 0x800DE720: nop

;}
RECOMP_FUNC void ftCommonThrownCopyStarSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C6AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014C6B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014C6B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014C6B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014C6BC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014C6C0: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x8014C6C4: bne         $t7, $zero, L_8014C6D4
    if (ctx->r15 != 0) {
        // 0x8014C6C8: nop
    
            goto L_8014C6D4;
    }
    // 0x8014C6C8: nop

    // 0x8014C6CC: jal         0x800DEEC8
    // 0x8014C6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8014C6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_8014C6D4:
    // 0x8014C6D4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8014C6D8: addiu       $t8, $t8, -0x3984
    ctx->r24 = ADD32(ctx->r24, -0X3984);
    // 0x8014C6DC: sw          $t8, 0xA0C($s0)
    MEM_W(0XA0C, ctx->r16) = ctx->r24;
    // 0x8014C6E0: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x8014C6E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8014C6E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014C6EC: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    // 0x8014C6F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014C6F4: jal         0x800E6F24
    // 0x8014C6F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014C6F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8014C6FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014C700: jal         0x800E8098
    // 0x8014C704: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014C704: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x8014C708: lbu         $t2, 0x18E($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X18E);
    // 0x8014C70C: lbu         $t7, 0x18D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18D);
    // 0x8014C710: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8014C714: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x8014C718: sb          $t3, 0x18E($s0)
    MEM_B(0X18E, ctx->r16) = ctx->r11;
    // 0x8014C71C: lhu         $t4, 0x18E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X18E);
    // 0x8014C720: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8014C724: addiu       $t0, $t0, -0x41AC
    ctx->r8 = ADD32(ctx->r8, -0X41AC);
    // 0x8014C728: srl         $t5, $t4, 15
    ctx->r13 = S32(U32(ctx->r12) >> 15);
    // 0x8014C72C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8014C730: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8014C734: sw          $t0, 0x9F8($s0)
    MEM_W(0X9F8, ctx->r16) = ctx->r8;
    // 0x8014C738: sb          $t9, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r25;
    // 0x8014C73C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014C740: jal         0x800E8A24
    // 0x8014C744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_3;
    // 0x8014C744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8014C748: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014C74C: jal         0x800E7F7C
    // 0x8014C750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_4;
    // 0x8014C750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8014C754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014C758: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014C75C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014C760: jr          $ra
    // 0x8014C764: nop

    return;
    // 0x8014C764: nop

;}
RECOMP_FUNC void ftCommonCliffAttackEscape2ProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80145444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145448: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8014544C: lw          $t6, 0x14C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14C);
    // 0x80145450: bne         $t6, $zero, L_80145468
    if (ctx->r14 != 0) {
        // 0x80145454: nop
    
            goto L_80145468;
    }
    // 0x80145454: nop

    // 0x80145458: jal         0x800DDF44
    // 0x8014545C: nop

    mpCommonSetFighterFallOnEdgeBreak(rdram, ctx);
        goto after_0;
    // 0x8014545C: nop

    after_0:
    // 0x80145460: b           L_80145484
    // 0x80145464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80145484;
    // 0x80145464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145468:
    // 0x80145468: jal         0x800DE6B0
    // 0x8014546C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_1;
    // 0x8014546C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80145470: beq         $v0, $zero, L_80145480
    if (ctx->r2 == 0) {
        // 0x80145474: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80145480;
    }
    // 0x80145474: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80145478: jal         0x800DEE98
    // 0x8014547C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_2;
    // 0x8014547C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_80145480:
    // 0x80145480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145484:
    // 0x80145484: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80145488: jr          $ra
    // 0x8014548C: nop

    return;
    // 0x8014548C: nop

;}
RECOMP_FUNC void mnPlayersVSAdjustCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801379B8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801379BC: addiu       $t6, $t6, -0x4790
    ctx->r14 = ADD32(ctx->r14, -0X4790);
    // 0x801379C0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801379C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801379C8: addiu       $t1, $sp, 0x1C
    ctx->r9 = ADD32(ctx->r29, 0X1C);
    // 0x801379CC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801379D0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801379D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x801379D8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x801379DC: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x801379E0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801379E4: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x801379E8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x801379EC: sw          $t8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r24;
    // 0x801379F0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801379F4: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801379F8: addiu       $t2, $t2, -0x4578
    ctx->r10 = ADD32(ctx->r10, -0X4578);
    // 0x801379FC: sw          $t7, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r15;
    // 0x80137A00: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80137A04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80137A08: addu        $v0, $t9, $t2
    ctx->r2 = ADD32(ctx->r25, ctx->r10);
    // 0x80137A0C: lw          $t3, 0xA0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XA0);
    // 0x80137A10: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
    // 0x80137A14: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80137A18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80137A1C: beq         $t3, $zero, L_80137BA0
    if (ctx->r11 == 0) {
        // 0x80137A20: sw          $t7, 0x14($t1)
        MEM_W(0X14, ctx->r9) = ctx->r15;
            goto L_80137BA0;
    }
    // 0x80137A20: sw          $t7, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r15;
    // 0x80137A24: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80137A28: lwc1        $f2, 0x98($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X98);
    // 0x80137A2C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80137A30: lw          $v1, 0x74($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X74);
    // 0x80137A34: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80137A38: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80137A3C: lwc1        $f12, 0x58($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80137A40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80137A44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80137A48: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80137A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137A50: div.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80137A54: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80137A58: nop

    // 0x80137A5C: bc1f        L_80137A84
    if (!c1cs) {
        // 0x80137A60: nop
    
            goto L_80137A84;
    }
    // 0x80137A60: nop

    // 0x80137A64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80137A68: nop

    // 0x80137A6C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80137A70: nop

    // 0x80137A74: bc1f        L_80137A84
    if (!c1cs) {
        // 0x80137A78: nop
    
            goto L_80137A84;
    }
    // 0x80137A78: nop

    // 0x80137A7C: b           L_80137A84
    // 0x80137A80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80137A84;
    // 0x80137A80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80137A84:
    // 0x80137A84: beq         $a0, $zero, L_80137A94
    if (ctx->r4 == 0) {
        // 0x80137A88: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80137A94;
    }
    // 0x80137A88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80137A8C: b           L_80137A9C
    // 0x80137A90: swc1        $f2, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f2.u32l;
        goto L_80137A9C;
    // 0x80137A90: swc1        $f2, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f2.u32l;
L_80137A94:
    // 0x80137A94: add.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80137A98: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
L_80137A9C:
    // 0x80137A9C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80137AA0: lwc1        $f2, 0x9C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x80137AA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137AA8: lw          $v1, 0x74($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X74);
    // 0x80137AAC: lwc1        $f12, 0x5C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80137AB0: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80137AB4: div.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80137AB8: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80137ABC: nop

    // 0x80137AC0: bc1f        L_80137AE8
    if (!c1cs) {
        // 0x80137AC4: nop
    
            goto L_80137AE8;
    }
    // 0x80137AC4: nop

    // 0x80137AC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80137ACC: nop

    // 0x80137AD0: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80137AD4: nop

    // 0x80137AD8: bc1f        L_80137AE8
    if (!c1cs) {
        // 0x80137ADC: nop
    
            goto L_80137AE8;
    }
    // 0x80137ADC: nop

    // 0x80137AE0: b           L_80137AE8
    // 0x80137AE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80137AE8;
    // 0x80137AE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80137AE8:
    // 0x80137AE8: beql        $a0, $zero, L_80137AFC
    if (ctx->r4 == 0) {
        // 0x80137AEC: add.s       $f4, $f12, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_80137AFC;
    }
    goto skip_0;
    // 0x80137AEC: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    skip_0:
    // 0x80137AF0: b           L_80137B00
    // 0x80137AF4: swc1        $f2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f2.u32l;
        goto L_80137B00;
    // 0x80137AF4: swc1        $f2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f2.u32l;
    // 0x80137AF8: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
L_80137AFC:
    // 0x80137AFC: swc1        $f4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f4.u32l;
L_80137B00:
    // 0x80137B00: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80137B04: lwc1        $f8, 0x98($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X98);
    // 0x80137B08: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x80137B0C: lwc1        $f6, 0x58($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80137B10: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80137B14: nop

    // 0x80137B18: bc1fl       L_80137B40
    if (!c1cs) {
        // 0x80137B1C: lw          $t7, 0x54($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X54);
            goto L_80137B40;
    }
    goto skip_1;
    // 0x80137B1C: lw          $t7, 0x54($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X54);
    skip_1:
    // 0x80137B20: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80137B24: lwc1        $f18, 0x9C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x80137B28: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x80137B2C: nop

    // 0x80137B30: bc1fl       L_80137B40
    if (!c1cs) {
        // 0x80137B34: lw          $t7, 0x54($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X54);
            goto L_80137B40;
    }
    goto skip_2;
    // 0x80137B34: lw          $t7, 0x54($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X54);
    skip_2:
    // 0x80137B38: sw          $zero, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = 0;
    // 0x80137B3C: lw          $t7, 0x54($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X54);
L_80137B40:
    // 0x80137B40: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80137B44: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80137B48: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80137B4C: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80137B50: lwc1        $f8, 0x58($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80137B54: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x80137B58: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80137B5C: nop

    // 0x80137B60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137B64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80137B68: swc1        $f10, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f10.u32l;
    // 0x80137B6C: lw          $t4, 0x54($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X54);
    // 0x80137B70: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80137B74: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80137B78: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x80137B7C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80137B80: lwc1        $f6, 0x5C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80137B84: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80137B88: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80137B8C: nop

    // 0x80137B90: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80137B94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80137B98: b           L_80137D44
    // 0x80137B9C: swc1        $f8, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f8.u32l;
        goto L_80137D44;
    // 0x80137B9C: swc1        $f8, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f8.u32l;
L_80137BA0:
    // 0x80137BA0: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x80137BA4: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x80137BA8: addu        $t2, $t2, $a1
    ctx->r10 = ADD32(ctx->r10, ctx->r5);
    // 0x80137BAC: bne         $t9, $zero, L_80137D44
    if (ctx->r25 != 0) {
        // 0x80137BB0: sll         $t2, $t2, 1
        ctx->r10 = S32(ctx->r10 << 1);
            goto L_80137D44;
    }
    // 0x80137BB0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80137BB4: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80137BB8: addiu       $t3, $t3, 0x5228
    ctx->r11 = ADD32(ctx->r11, 0X5228);
    // 0x80137BBC: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x80137BC0: lb          $t0, 0x8($a3)
    ctx->r8 = MEM_B(ctx->r7, 0X8);
    // 0x80137BC4: slti        $at, $t0, -0x8
    ctx->r1 = SIGNED(ctx->r8) < -0X8 ? 1 : 0;
    // 0x80137BC8: bne         $at, $zero, L_80137BD8
    if (ctx->r1 != 0) {
        // 0x80137BCC: slti        $at, $t0, 0x9
        ctx->r1 = SIGNED(ctx->r8) < 0X9 ? 1 : 0;
            goto L_80137BD8;
    }
    // 0x80137BCC: slti        $at, $t0, 0x9
    ctx->r1 = SIGNED(ctx->r8) < 0X9 ? 1 : 0;
    // 0x80137BD0: bne         $at, $zero, L_80137BE0
    if (ctx->r1 != 0) {
        // 0x80137BD4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80137BE0;
    }
    // 0x80137BD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80137BD8:
    // 0x80137BD8: b           L_80137BE0
    // 0x80137BDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80137BE0;
    // 0x80137BDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80137BE0:
    // 0x80137BE0: beql        $a0, $zero, L_80137C84
    if (ctx->r4 == 0) {
        // 0x80137BE4: lb          $a1, 0x9($a3)
        ctx->r5 = MEM_B(ctx->r7, 0X9);
            goto L_80137C84;
    }
    goto skip_3;
    // 0x80137BE4: lb          $a1, 0x9($a3)
    ctx->r5 = MEM_B(ctx->r7, 0X9);
    skip_3:
    // 0x80137BE8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80137BEC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80137BF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137BF4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80137BF8: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80137BFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80137C00: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x80137C04: lwc1        $f8, 0x58($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80137C08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137C0C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80137C10: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80137C14: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80137C18: nop

    // 0x80137C1C: bc1f        L_80137C44
    if (!c1cs) {
        // 0x80137C20: nop
    
            goto L_80137C44;
    }
    // 0x80137C20: nop

    // 0x80137C24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80137C28: nop

    // 0x80137C2C: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80137C30: nop

    // 0x80137C34: bc1f        L_80137C44
    if (!c1cs) {
        // 0x80137C38: nop
    
            goto L_80137C44;
    }
    // 0x80137C38: nop

    // 0x80137C3C: b           L_80137C44
    // 0x80137C40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80137C44;
    // 0x80137C40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80137C44:
    // 0x80137C44: beql        $a0, $zero, L_80137C84
    if (ctx->r4 == 0) {
        // 0x80137C48: lb          $a1, 0x9($a3)
        ctx->r5 = MEM_B(ctx->r7, 0X9);
            goto L_80137C84;
    }
    goto skip_4;
    // 0x80137C48: lb          $a1, 0x9($a3)
    ctx->r5 = MEM_B(ctx->r7, 0X9);
    skip_4:
    // 0x80137C4C: swc1        $f0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f0.u32l;
    // 0x80137C50: lw          $t4, 0x54($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X54);
    // 0x80137C54: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80137C58: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80137C5C: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x80137C60: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80137C64: lwc1        $f8, 0x58($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80137C68: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80137C6C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80137C70: nop

    // 0x80137C74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137C78: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80137C7C: swc1        $f10, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f10.u32l;
    // 0x80137C80: lb          $a1, 0x9($a3)
    ctx->r5 = MEM_B(ctx->r7, 0X9);
L_80137C84:
    // 0x80137C84: slti        $at, $a1, -0x8
    ctx->r1 = SIGNED(ctx->r5) < -0X8 ? 1 : 0;
    // 0x80137C88: bne         $at, $zero, L_80137C98
    if (ctx->r1 != 0) {
        // 0x80137C8C: slti        $at, $a1, 0x9
        ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
            goto L_80137C98;
    }
    // 0x80137C8C: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x80137C90: bne         $at, $zero, L_80137CA0
    if (ctx->r1 != 0) {
        // 0x80137C94: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80137CA0;
    }
    // 0x80137C94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80137C98:
    // 0x80137C98: b           L_80137CA0
    // 0x80137C9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80137CA0;
    // 0x80137C9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80137CA0:
    // 0x80137CA0: beq         $a0, $zero, L_80137D44
    if (ctx->r4 == 0) {
        // 0x80137CA4: nop
    
            goto L_80137D44;
    }
    // 0x80137CA4: nop

    // 0x80137CA8: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80137CAC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80137CB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80137CB4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80137CB8: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80137CBC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80137CC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80137CC4: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80137CC8: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x80137CCC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80137CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137CD4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80137CD8: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80137CDC: nop

    // 0x80137CE0: bc1f        L_80137D08
    if (!c1cs) {
        // 0x80137CE4: nop
    
            goto L_80137D08;
    }
    // 0x80137CE4: nop

    // 0x80137CE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137CEC: nop

    // 0x80137CF0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80137CF4: nop

    // 0x80137CF8: bc1f        L_80137D08
    if (!c1cs) {
        // 0x80137CFC: nop
    
            goto L_80137D08;
    }
    // 0x80137CFC: nop

    // 0x80137D00: b           L_80137D08
    // 0x80137D04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80137D08;
    // 0x80137D04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80137D08:
    // 0x80137D08: beq         $a0, $zero, L_80137D44
    if (ctx->r4 == 0) {
        // 0x80137D0C: nop
    
            goto L_80137D44;
    }
    // 0x80137D0C: nop

    // 0x80137D10: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x80137D14: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80137D18: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80137D1C: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x80137D20: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80137D24: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80137D28: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80137D2C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80137D30: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80137D34: nop

    // 0x80137D38: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137D3C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80137D40: swc1        $f18, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f18.u32l;
L_80137D44:
    // 0x80137D44: jr          $ra
    // 0x80137D48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80137D48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void wpProcessUpdateHitInteractStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016679C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801667A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801667A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801667A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801667AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801667B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801667B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801667B8: lw          $t6, 0x264($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X264);
    // 0x801667BC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801667C0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801667C4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x801667C8: beq         $t6, $zero, L_80166820
    if (ctx->r14 == 0) {
        // 0x801667CC: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_80166820;
    }
    // 0x801667CC: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x801667D0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801667D4: lw          $s0, 0x6704($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6704);
    // 0x801667D8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x801667DC: beql        $s0, $zero, L_80166838
    if (ctx->r16 == 0) {
        // 0x801667E0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80166838;
    }
    goto skip_0;
    // 0x801667E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801667E4: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_801667E8:
    // 0x801667E8: lw          $t7, 0x264($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X264);
    // 0x801667EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801667F0: lw          $t8, 0x264($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X264);
    // 0x801667F4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x801667F8: addiu       $a0, $v0, 0x100
    ctx->r4 = ADD32(ctx->r2, 0X100);
    // 0x801667FC: bnel        $t7, $t8, L_80166810
    if (ctx->r15 != ctx->r24) {
        // 0x80166800: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80166810;
    }
    goto skip_1;
    // 0x80166800: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80166804: jal         0x80166594
    // 0x80166808: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    wpProcessSetHitInteractStats(rdram, ctx);
        goto after_0;
    // 0x80166808: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
    // 0x8016680C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80166810:
    // 0x80166810: bnel        $s0, $zero, L_801667E8
    if (ctx->r16 != 0) {
        // 0x80166814: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_801667E8;
    }
    goto skip_2;
    // 0x80166814: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_2:
    // 0x80166818: b           L_80166838
    // 0x8016681C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80166838;
    // 0x8016681C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80166820:
    // 0x80166820: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80166824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80166828: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8016682C: jal         0x80166594
    // 0x80166830: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    wpProcessSetHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x80166830: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_1:
    // 0x80166834: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80166838:
    // 0x80166838: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016683C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80166840: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80166844: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80166848: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8016684C: jr          $ra
    // 0x80166850: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80166850: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftSamusSpecialNEndSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DA04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015DA08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015DA0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015DA10: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015DA14: jal         0x800DEEC8
    // 0x8015DA18: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015DA18: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015DA1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015DA20: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015DA24: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x8015DA28: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015DA2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015DA30: jal         0x800E6F24
    // 0x8015DA34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015DA34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015DA38: jal         0x800D8EB8
    // 0x8015DA3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015DA3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015DA40: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8015DA44: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8015DA48: addiu       $t8, $t8, -0x2CC8
    ctx->r24 = ADD32(ctx->r24, -0X2CC8);
    // 0x8015DA4C: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x8015DA50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015DA54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015DA58: jr          $ra
    // 0x8015DA5C: nop

    return;
    // 0x8015DA5C: nop

;}
RECOMP_FUNC void itBoxCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017969C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801796A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801796A4: jal         0x80179424
    // 0x801796A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBoxCommonCheckSpawnItems(rdram, ctx);
        goto after_0;
    // 0x801796A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801796AC: beq         $v0, $zero, L_801796BC
    if (ctx->r2 == 0) {
        // 0x801796B0: nop
    
            goto L_801796BC;
    }
    // 0x801796B0: nop

    // 0x801796B4: b           L_801796C8
    // 0x801796B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801796C8;
    // 0x801796B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801796BC:
    // 0x801796BC: jal         0x80179B08
    // 0x801796C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itBoxExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_1;
    // 0x801796C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801796C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801796C8:
    // 0x801796C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801796CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801796D0: jr          $ra
    // 0x801796D4: nop

    return;
    // 0x801796D4: nop

;}
RECOMP_FUNC void mnPlayers1PGameReadyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137BEC: jal         0x80137EF0
    // 0x80137BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnPlayers1PGameCheckReady(rdram, ctx);
        goto after_0;
    // 0x80137BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80137BF4: beq         $v0, $zero, L_80137C40
    if (ctx->r2 == 0) {
        // 0x80137BF8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80137C40;
    }
    // 0x80137BF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80137BFC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137C00: addiu       $v1, $v1, -0x7084
    ctx->r3 = ADD32(ctx->r3, -0X7084);
    // 0x80137C04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80137C08: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80137C0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80137C10: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80137C14: bne         $v0, $at, L_80137C24
    if (ctx->r2 != ctx->r1) {
        // 0x80137C18: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80137C24;
    }
    // 0x80137C18: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80137C1C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80137C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137C24:
    // 0x80137C24: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80137C28: beq         $at, $zero, L_80137C38
    if (ctx->r1 == 0) {
        // 0x80137C2C: nop
    
            goto L_80137C38;
    }
    // 0x80137C2C: nop

    // 0x80137C30: b           L_80137C54
    // 0x80137C34: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80137C54;
    // 0x80137C34: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_80137C38:
    // 0x80137C38: b           L_80137C54
    // 0x80137C3C: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
        goto L_80137C54;
    // 0x80137C3C: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
L_80137C40:
    // 0x80137C40: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137C44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80137C48: addiu       $v1, $v1, -0x7084
    ctx->r3 = ADD32(ctx->r3, -0X7084);
    // 0x80137C4C: sw          $t9, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r25;
    // 0x80137C50: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80137C54:
    // 0x80137C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137C5C: jr          $ra
    // 0x80137C60: nop

    return;
    // 0x80137C60: nop

;}
RECOMP_FUNC void grYamabukiGateSetPositionFar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AE3C: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x8010AE40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010AE44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010AE48: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010AE4C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010AE50: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8010AE54: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x8010AE58: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8010AE5C: lwc1        $f6, 0x20($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8010AE60: jr          $ra
    // 0x8010AE64: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8010AE64: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void ftCommonGuardOnCheckInterruptSuccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80148CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148CC4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80148CC8: lhu         $t6, 0x1BC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BC);
    // 0x80148CCC: lhu         $t7, 0x1B8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B8);
    // 0x80148CD0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80148CD4: beql        $t8, $zero, L_80148CFC
    if (ctx->r24 == 0) {
        // 0x80148CD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80148CFC;
    }
    goto skip_0;
    // 0x80148CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80148CDC: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80148CE0: beql        $t9, $zero, L_80148CFC
    if (ctx->r25 == 0) {
        // 0x80148CE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80148CFC;
    }
    goto skip_1;
    // 0x80148CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80148CE8: jal         0x80148BFC
    // 0x80148CEC: nop

    ftCommonGuardOnSetStatus(rdram, ctx);
        goto after_0;
    // 0x80148CEC: nop

    after_0:
    // 0x80148CF0: b           L_80148CFC
    // 0x80148CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80148CFC;
    // 0x80148CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80148CF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80148CFC:
    // 0x80148CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80148D04: jr          $ra
    // 0x80148D08: nop

    return;
    // 0x80148D08: nop

;}
RECOMP_FUNC void ftCommonRunBrakeCheckInterruptRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F0A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F0A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F0A8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013F0AC: lb          $t6, 0x1C2($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C2);
    // 0x8013F0B0: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8013F0B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013F0B8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013F0BC: mflo        $t8
    ctx->r24 = lo;
    // 0x8013F0C0: slti        $at, $t8, 0x32
    ctx->r1 = SIGNED(ctx->r24) < 0X32 ? 1 : 0;
    // 0x8013F0C4: beq         $at, $zero, L_8013F0DC
    if (ctx->r1 == 0) {
        // 0x8013F0C8: nop
    
            goto L_8013F0DC;
    }
    // 0x8013F0C8: nop

    // 0x8013F0CC: jal         0x8013F05C
    // 0x8013F0D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftCommonRunBrakeSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013F0D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8013F0D4: b           L_8013F0DC
    // 0x8013F0D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013F0DC;
    // 0x8013F0D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F0DC:
    // 0x8013F0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F0E4: jr          $ra
    // 0x8013F0E8: nop

    return;
    // 0x8013F0E8: nop

;}
RECOMP_FUNC void itMBallDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CA14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CA18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CA1C: jal         0x8017C690
    // 0x8017CA20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMBallOpenAddAnim(rdram, ctx);
        goto after_0;
    // 0x8017CA20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017CA24: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017CA28: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x8017CA2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017CA30: jal         0x80172EC8
    // 0x8017CA34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017CA34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8017CA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CA3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CA40: jr          $ra
    // 0x8017CA44: nop

    return;
    // 0x8017CA44: nop

;}
RECOMP_FUNC void gcAddDObjMatrixSetsRpyR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B43C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000B440: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8000B444: jal         0x80008CC0
    // 0x8000B448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_0;
    // 0x8000B448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000B44C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000B450: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8000B454: jal         0x80008CC0
    // 0x8000B458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8000B458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8000B45C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000B460: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8000B464: jal         0x80008CC0
    // 0x8000B468: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8000B468: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8000B46C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B474: jr          $ra
    // 0x8000B478: nop

    return;
    // 0x8000B478: nop

;}
RECOMP_FUNC void func_ovl8_80371A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371A2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80371A30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80371A34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80371A38: jal         0x80371E58
    // 0x80371A3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_ovl8_80371E58(rdram, ctx);
        goto after_0;
    // 0x80371A3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80371A40: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x80371A44: lw          $t9, 0x124($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X124);
    // 0x80371A48: lh          $t6, 0x120($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X120);
    // 0x80371A4C: jalr        $t9
    // 0x80371A50: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80371A50: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    after_1:
    // 0x80371A54: beql        $v0, $zero, L_80371A74
    if (ctx->r2 == 0) {
        // 0x80371A58: lw          $t8, 0x1C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X1C);
            goto L_80371A74;
    }
    goto skip_0;
    // 0x80371A58: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x80371A5C: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x80371A60: lw          $t9, 0xC4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC4);
    // 0x80371A64: lh          $t7, 0xC0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC0);
    // 0x80371A68: jalr        $t9
    // 0x80371A6C: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80371A6C: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    after_2:
    // 0x80371A70: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
L_80371A74:
    // 0x80371A74: beql        $t8, $zero, L_80371A94
    if (ctx->r24 == 0) {
        // 0x80371A78: lw          $v0, 0x58($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X58);
            goto L_80371A94;
    }
    goto skip_1;
    // 0x80371A78: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    skip_1:
    // 0x80371A7C: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x80371A80: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x80371A84: lh          $t0, 0x60($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X60);
    // 0x80371A88: jalr        $t9
    // 0x80371A8C: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80371A8C: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    after_3:
    // 0x80371A90: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
L_80371A94:
    // 0x80371A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80371A98: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x80371A9C: lh          $t1, 0x118($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X118);
    // 0x80371AA0: jalr        $t9
    // 0x80371AA4: addu        $a0, $t1, $s0
    ctx->r4 = ADD32(ctx->r9, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80371AA4: addu        $a0, $t1, $s0
    ctx->r4 = ADD32(ctx->r9, ctx->r16);
    after_4:
    // 0x80371AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80371AAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80371AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80371AB4: jr          $ra
    // 0x80371AB8: nop

    return;
    // 0x80371AB8: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingHandicapLevelProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801345B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801345BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801345C0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801345C4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801345C8: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x801345CC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801345D0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x801345D4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801345D8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x801345DC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801345E0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801345E4: lw          $t8, 0x84($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X84);
    // 0x801345E8: bnel        $t8, $zero, L_80134604
    if (ctx->r24 != 0) {
        // 0x801345EC: lw          $t9, 0x74($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X74);
            goto L_80134604;
    }
    goto skip_0;
    // 0x801345EC: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x801345F0: jal         0x801342B8
    // 0x801345F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayers1PTrainingDestroyHandicapLevel(rdram, ctx);
        goto after_0;
    // 0x801345F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801345F8: b           L_80134620
    // 0x801345FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134620;
    // 0x801345FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134600: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
L_80134604:
    // 0x80134604: lw          $t1, 0x80($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X80);
    // 0x80134608: lw          $t0, 0x54($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X54);
    // 0x8013460C: beql        $t0, $t1, L_80134620
    if (ctx->r8 == ctx->r9) {
        // 0x80134610: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80134620;
    }
    goto skip_1;
    // 0x80134610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80134614: jal         0x8013462C
    // 0x80134618: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayers1PTrainingMakeHandicapLevel(rdram, ctx);
        goto after_1;
    // 0x80134618: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8013461C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134620:
    // 0x80134620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134624: jr          $ra
    // 0x80134628: nop

    return;
    // 0x80134628: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetTotalHiScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134B64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134B68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80134B6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80134B70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134B74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134B78: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80134B7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80134B80: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_80134B84:
    // 0x80134B84: jal         0x80134758
    // 0x80134B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameGetHiScore(rdram, ctx);
        goto after_0;
    // 0x80134B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80134B8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80134B90: bne         $s0, $s2, L_80134B84
    if (ctx->r16 != ctx->r18) {
        // 0x80134B94: addu        $s1, $s1, $v0
        ctx->r17 = ADD32(ctx->r17, ctx->r2);
            goto L_80134B84;
    }
    // 0x80134B94: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80134B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134B9C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80134BA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80134BA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134BA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80134BAC: jr          $ra
    // 0x80134BB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80134BB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonTurnCheckInputSuccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E9D0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013E9D4: lb          $t6, 0x1C2($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C2);
    // 0x8013E9D8: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8013E9DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013E9E0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013E9E4: mflo        $t8
    ctx->r24 = lo;
    // 0x8013E9E8: slti        $at, $t8, -0x13
    ctx->r1 = SIGNED(ctx->r24) < -0X13 ? 1 : 0;
    // 0x8013E9EC: beq         $at, $zero, L_8013E9FC
    if (ctx->r1 == 0) {
        // 0x8013E9F0: nop
    
            goto L_8013E9FC;
    }
    // 0x8013E9F0: nop

    // 0x8013E9F4: jr          $ra
    // 0x8013E9F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013E9F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013E9FC:
    // 0x8013E9FC: jr          $ra
    // 0x8013EA00: nop

    return;
    // 0x8013EA00: nop

;}
RECOMP_FUNC void ftCommonDownBounceProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014430C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144310: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144314: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80144318: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8014431C: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x80144320: beq         $v1, $zero, L_8014432C
    if (ctx->r3 == 0) {
        // 0x80144324: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8014432C;
    }
    // 0x80144324: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80144328: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
L_8014432C:
    // 0x8014432C: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x80144330: lhu         $t8, 0x1B6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B6);
    // 0x80144334: lhu         $t0, 0x1BE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80144338: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8014433C: and         $t1, $t0, $t9
    ctx->r9 = ctx->r8 & ctx->r25;
    // 0x80144340: beql        $t1, $zero, L_80144350
    if (ctx->r9 == 0) {
        // 0x80144344: lwc1        $f6, 0x78($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
            goto L_80144350;
    }
    goto skip_0;
    // 0x80144344: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    skip_0:
    // 0x80144348: sw          $t2, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r10;
    // 0x8014434C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
L_80144350:
    // 0x80144350: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80144354: nop

    // 0x80144358: bc1fl       L_8014438C
    if (!c1cs) {
        // 0x8014435C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014438C;
    }
    goto skip_1;
    // 0x8014435C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80144360: jal         0x80144944
    // 0x80144364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonDownAttackCheckInterruptDownBounce(rdram, ctx);
        goto after_0;
    // 0x80144364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80144368: bne         $v0, $zero, L_80144388
    if (ctx->r2 != 0) {
        // 0x8014436C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80144388;
    }
    // 0x8014436C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80144370: jal         0x8014482C
    // 0x80144374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonDownForwardOrBackCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80144374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80144378: bne         $v0, $zero, L_80144388
    if (ctx->r2 != 0) {
        // 0x8014437C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80144388;
    }
    // 0x8014437C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80144380: jal         0x80144294
    // 0x80144384: nop

    ftCommonDownWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x80144384: nop

    after_2:
L_80144388:
    // 0x80144388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014438C:
    // 0x8014438C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144390: jr          $ra
    // 0x80144394: nop

    return;
    // 0x80144394: nop

;}
RECOMP_FUNC void mvEndingMakeRoomBackground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131B60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131B68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131B6C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131B70: jal         0x80009968
    // 0x80131B74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131B74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131B78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B7C: lw          $t6, 0x2F70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2F70);
    // 0x80131B80: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131B84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131B88: addiu       $t7, $t7, 0x7E98
    ctx->r15 = ADD32(ctx->r15, 0X7E98);
    // 0x80131B8C: sw          $v0, 0x2BE0($at)
    MEM_W(0X2BE0, ctx->r1) = ctx->r2;
    // 0x80131B90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131B94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131B98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131B9C: jal         0x8000F120
    // 0x80131BA0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131BA0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131BA4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131BA8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131BAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131BB0: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80131BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131BB8: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80131BBC: jal         0x80009DF4
    // 0x80131BC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131BC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131BC4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131BC8: lw          $t9, 0x2F70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2F70);
    // 0x80131BCC: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80131BD0: addiu       $t0, $t0, 0x42F8
    ctx->r8 = ADD32(ctx->r8, 0X42F8);
    // 0x80131BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131BD8: jal         0x8000F8F4
    // 0x80131BDC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x80131BDC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80131BE0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131BE4: lw          $t1, 0x2F70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2F70);
    // 0x80131BE8: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80131BEC: addiu       $t2, $t2, -0x7878
    ctx->r10 = ADD32(ctx->r10, -0X7878);
    // 0x80131BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131BF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131BF8: jal         0x8000BE28
    // 0x80131BFC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80131BFC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x80131C00: jal         0x8000DF34
    // 0x80131C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80131C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80131C08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131C0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131C10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131C14: jr          $ra
    // 0x80131C18: nop

    return;
    // 0x80131C18: nop

;}
RECOMP_FUNC void wpYoshiStarMakeStars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C954: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C95C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8016C960: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016C964: lw          $a2, 0x44($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X44);
    // 0x8016C968: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016C96C: jal         0x8016C834
    // 0x8016C970: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    wpYoshiStarMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016C970: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8016C974: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8016C97C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8016C980: lw          $a2, 0x44($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X44);
    // 0x8016C984: jal         0x8016C834
    // 0x8016C988: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    wpYoshiStarMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x8016C988: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    after_1:
    // 0x8016C98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C990: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016C994: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C998: jr          $ra
    // 0x8016C99C: nop

    return;
    // 0x8016C99C: nop

;}
RECOMP_FUNC void mnSoundTestUpdateControllerInputs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B80: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131B84: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131B88: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80131B8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B94: beq         $v0, $zero, L_80131BA4
    if (ctx->r2 == 0) {
        // 0x80131B98: addiu       $a0, $zero, -0x20
        ctx->r4 = ADD32(0, -0X20);
            goto L_80131BA4;
    }
    // 0x80131B98: addiu       $a0, $zero, -0x20
    ctx->r4 = ADD32(0, -0X20);
    // 0x80131B9C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80131BA0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_80131BA4:
    // 0x80131BA4: jal         0x80390A04
    // 0x80131BA8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80131BA8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x80131BAC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131BB0: beq         $v0, $zero, L_80131C04
    if (ctx->r2 == 0) {
        // 0x80131BB4: addiu       $a2, $a2, 0x433C
        ctx->r6 = ADD32(ctx->r6, 0X433C);
            goto L_80131C04;
    }
    // 0x80131BB4: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131BB8: addiu       $a0, $zero, -0x20
    ctx->r4 = ADD32(0, -0X20);
    // 0x80131BBC: jal         0x80390AC0
    // 0x80131BC0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80131BC0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x80131BC4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131BC8: beq         $v0, $zero, L_80131C04
    if (ctx->r2 == 0) {
        // 0x80131BCC: addiu       $a2, $a2, 0x433C
        ctx->r6 = ADD32(ctx->r6, 0X433C);
            goto L_80131C04;
    }
    // 0x80131BCC: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131BD0: jal         0x80390804
    // 0x80131BD4: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_2;
    // 0x80131BD4: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    after_2:
    // 0x80131BD8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131BDC: bne         $v0, $zero, L_80131C04
    if (ctx->r2 != 0) {
        // 0x80131BE0: addiu       $a2, $a2, 0x433C
        ctx->r6 = ADD32(ctx->r6, 0X433C);
            goto L_80131C04;
    }
    // 0x80131BE0: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131BE4: jal         0x80390804
    // 0x80131BE8: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_3;
    // 0x80131BE8: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    after_3:
    // 0x80131BEC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131BF0: bne         $v0, $zero, L_80131C04
    if (ctx->r2 != 0) {
        // 0x80131BF4: addiu       $a2, $a2, 0x433C
        ctx->r6 = ADD32(ctx->r6, 0X433C);
            goto L_80131C04;
    }
    // 0x80131BF4: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131BF8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80131BFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C00: sw          $zero, 0x4340($at)
    MEM_W(0X4340, ctx->r1) = 0;
L_80131C04:
    // 0x80131C04: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80131C08: bne         $v0, $zero, L_80131C2C
    if (ctx->r2 != 0) {
        // 0x80131C0C: nop
    
            goto L_80131C2C;
    }
    // 0x80131C0C: nop

    // 0x80131C10: jal         0x80390804
    // 0x80131C14: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_4;
    // 0x80131C14: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_4:
    // 0x80131C18: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131C1C: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131C20: bne         $v0, $zero, L_80131C4C
    if (ctx->r2 != 0) {
        // 0x80131C24: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80131C4C;
    }
    // 0x80131C24: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80131C28: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80131C2C:
    // 0x80131C2C: bne         $v0, $zero, L_80131CD0
    if (ctx->r2 != 0) {
        // 0x80131C30: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_80131CD0;
    }
    // 0x80131C30: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80131C34: jal         0x80390950
    // 0x80131C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_5;
    // 0x80131C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80131C3C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131C40: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131C44: beq         $v0, $zero, L_80131CD0
    if (ctx->r2 == 0) {
        // 0x80131C48: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80131CD0;
    }
    // 0x80131C48: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80131C4C:
    // 0x80131C4C: jal         0x800269C0
    // 0x80131C50: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x80131C50: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_6:
    // 0x80131C54: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80131C58: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131C5C: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131C60: beq         $t7, $zero, L_80131C74
    if (ctx->r15 == 0) {
        // 0x80131C64: lui         $a3, 0x8013
        ctx->r7 = S32(0X8013 << 16);
            goto L_80131C74;
    }
    // 0x80131C64: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80131C68: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80131C6C: b           L_80131C94
    // 0x80131C70: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_80131C94;
    // 0x80131C70: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_80131C74:
    // 0x80131C74: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C78: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80131C7C: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x80131C80: bgez        $t1, L_80131C90
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80131C84: sra         $t2, $t1, 3
        ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
            goto L_80131C90;
    }
    // 0x80131C84: sra         $t2, $t1, 3
    ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80131C88: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x80131C8C: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_80131C90:
    // 0x80131C90: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_80131C94:
    // 0x80131C94: addiu       $a3, $a3, 0x4308
    ctx->r7 = ADD32(ctx->r7, 0X4308);
    // 0x80131C98: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80131C9C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80131CA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CA4: addiu       $v0, $t3, -0x1
    ctx->r2 = ADD32(ctx->r11, -0X1);
    // 0x80131CA8: bgez        $v0, L_80131CB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80131CAC: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80131CB8;
    }
    // 0x80131CAC: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80131CB0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80131CB4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_80131CB8:
    // 0x80131CB8: bne         $v0, $zero, L_80131CCC
    if (ctx->r2 != 0) {
        // 0x80131CBC: nop
    
            goto L_80131CCC;
    }
    // 0x80131CBC: nop

    // 0x80131CC0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80131CC4: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x80131CC8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_80131CCC:
    // 0x80131CCC: sw          $t8, 0x4340($at)
    MEM_W(0X4340, ctx->r1) = ctx->r24;
L_80131CD0:
    // 0x80131CD0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80131CD4: bne         $v0, $zero, L_80131CF8
    if (ctx->r2 != 0) {
        // 0x80131CD8: nop
    
            goto L_80131CF8;
    }
    // 0x80131CD8: nop

    // 0x80131CDC: jal         0x80390804
    // 0x80131CE0: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_7;
    // 0x80131CE0: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_7:
    // 0x80131CE4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131CE8: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131CEC: bne         $v0, $zero, L_80131D18
    if (ctx->r2 != 0) {
        // 0x80131CF0: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80131D18;
    }
    // 0x80131CF0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80131CF4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80131CF8:
    // 0x80131CF8: bne         $v0, $zero, L_80131DA0
    if (ctx->r2 != 0) {
        // 0x80131CFC: addiu       $a0, $zero, -0x20
        ctx->r4 = ADD32(0, -0X20);
            goto L_80131DA0;
    }
    // 0x80131CFC: addiu       $a0, $zero, -0x20
    ctx->r4 = ADD32(0, -0X20);
    // 0x80131D00: jal         0x80390950
    // 0x80131D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_8;
    // 0x80131D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80131D08: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131D0C: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131D10: beq         $v0, $zero, L_80131DA0
    if (ctx->r2 == 0) {
        // 0x80131D14: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80131DA0;
    }
    // 0x80131D14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80131D18:
    // 0x80131D18: jal         0x800269C0
    // 0x80131D1C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80131D1C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_9:
    // 0x80131D20: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80131D24: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131D28: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80131D2C: addiu       $a3, $a3, 0x4308
    ctx->r7 = ADD32(ctx->r7, 0X4308);
    // 0x80131D30: beq         $t0, $zero, L_80131D44
    if (ctx->r8 == 0) {
        // 0x80131D34: addiu       $a2, $a2, 0x433C
        ctx->r6 = ADD32(ctx->r6, 0X433C);
            goto L_80131D44;
    }
    // 0x80131D34: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131D38: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80131D3C: b           L_80131D60
    // 0x80131D40: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
        goto L_80131D60;
    // 0x80131D40: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80131D44:
    // 0x80131D44: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D48: addiu       $t2, $t1, 0xA0
    ctx->r10 = ADD32(ctx->r9, 0XA0);
    // 0x80131D4C: bgez        $t2, L_80131D5C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80131D50: sra         $t3, $t2, 3
        ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
            goto L_80131D5C;
    }
    // 0x80131D50: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x80131D54: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x80131D58: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_80131D5C:
    // 0x80131D5C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_80131D60:
    // 0x80131D60: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80131D64: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80131D68: addiu       $v0, $t4, 0x1
    ctx->r2 = ADD32(ctx->r12, 0X1);
    // 0x80131D6C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80131D70: bne         $at, $zero, L_80131D80
    if (ctx->r1 != 0) {
        // 0x80131D74: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80131D80;
    }
    // 0x80131D74: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80131D78: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80131D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131D80:
    // 0x80131D80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131D84: bne         $v0, $at, L_80131D98
    if (ctx->r2 != ctx->r1) {
        // 0x80131D88: nop
    
            goto L_80131D98;
    }
    // 0x80131D88: nop

    // 0x80131D8C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80131D90: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x80131D94: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_80131D98:
    // 0x80131D98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D9C: sw          $t8, 0x4340($at)
    MEM_W(0X4340, ctx->r1) = ctx->r24;
L_80131DA0:
    // 0x80131DA0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80131DA4: bne         $v0, $zero, L_80131DD0
    if (ctx->r2 != 0) {
        // 0x80131DA8: nop
    
            goto L_80131DD0;
    }
    // 0x80131DA8: nop

    // 0x80131DAC: jal         0x80390804
    // 0x80131DB0: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_10;
    // 0x80131DB0: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_10:
    // 0x80131DB4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131DB8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80131DBC: addiu       $a3, $a3, 0x4308
    ctx->r7 = ADD32(ctx->r7, 0X4308);
    // 0x80131DC0: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131DC4: bne         $v0, $zero, L_80131DF8
    if (ctx->r2 != 0) {
        // 0x80131DC8: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80131DF8;
    }
    // 0x80131DC8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80131DCC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80131DD0:
    // 0x80131DD0: bne         $v0, $zero, L_80131F14
    if (ctx->r2 != 0) {
        // 0x80131DD4: addiu       $a0, $zero, -0x20
        ctx->r4 = ADD32(0, -0X20);
            goto L_80131F14;
    }
    // 0x80131DD4: addiu       $a0, $zero, -0x20
    ctx->r4 = ADD32(0, -0X20);
    // 0x80131DD8: jal         0x8039089C
    // 0x80131DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_11;
    // 0x80131DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80131DE0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131DE4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80131DE8: addiu       $a3, $a3, 0x4308
    ctx->r7 = ADD32(ctx->r7, 0X4308);
    // 0x80131DEC: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131DF0: beq         $v0, $zero, L_80131F14
    if (ctx->r2 == 0) {
        // 0x80131DF4: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80131F14;
    }
    // 0x80131DF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80131DF8:
    // 0x80131DF8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80131DFC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80131E00: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80131E04: beq         $t0, $zero, L_80131E14
    if (ctx->r8 == 0) {
        // 0x80131E08: addiu       $t2, $t1, 0xA0
        ctx->r10 = ADD32(ctx->r9, 0XA0);
            goto L_80131E14;
    }
    // 0x80131E08: addiu       $t2, $t1, 0xA0
    ctx->r10 = ADD32(ctx->r9, 0XA0);
    // 0x80131E0C: b           L_80131E28
    // 0x80131E10: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
        goto L_80131E28;
    // 0x80131E10: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80131E14:
    // 0x80131E14: bgez        $t2, L_80131E24
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80131E18: sra         $t3, $t2, 4
        ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
            goto L_80131E24;
    }
    // 0x80131E18: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x80131E1C: addiu       $at, $t2, 0xF
    ctx->r1 = ADD32(ctx->r10, 0XF);
    // 0x80131E20: sra         $t3, $at, 4
    ctx->r11 = S32(SIGNED(ctx->r1) >> 4);
L_80131E24:
    // 0x80131E24: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_80131E28:
    // 0x80131E28: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80131E2C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80131E30: addiu       $t5, $t5, 0x4348
    ctx->r13 = ADD32(ctx->r13, 0X4348);
    // 0x80131E34: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80131E38: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80131E3C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80131E40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131E44: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80131E48: beq         $v0, $zero, L_80131E68
    if (ctx->r2 == 0) {
        // 0x80131E4C: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80131E68;
    }
    // 0x80131E4C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131E50: beq         $v0, $at, L_80131E94
    if (ctx->r2 == ctx->r1) {
        // 0x80131E54: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80131E94;
    }
    // 0x80131E54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131E58: beql        $v0, $at, L_80131EC4
    if (ctx->r2 == ctx->r1) {
        // 0x80131E5C: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80131EC4;
    }
    goto skip_0;
    // 0x80131E5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80131E60: b           L_80131EE8
    // 0x80131E64: nop

        goto L_80131EE8;
    // 0x80131E64: nop

L_80131E68:
    // 0x80131E68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131E6C: bgez        $v0, L_80131E7C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80131E70: nop
    
            goto L_80131E7C;
    }
    // 0x80131E70: nop

    // 0x80131E74: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x80131E78: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80131E7C:
    // 0x80131E7C: bne         $v0, $zero, L_80131EE8
    if (ctx->r2 != 0) {
        // 0x80131E80: nop
    
            goto L_80131EE8;
    }
    // 0x80131E80: nop

    // 0x80131E84: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80131E88: addiu       $t9, $t0, 0x14
    ctx->r25 = ADD32(ctx->r8, 0X14);
    // 0x80131E8C: b           L_80131EE8
    // 0x80131E90: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
        goto L_80131EE8;
    // 0x80131E90: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80131E94:
    // 0x80131E94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131E98: bgez        $v0, L_80131EA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80131E9C: nop
    
            goto L_80131EA8;
    }
    // 0x80131E9C: nop

    // 0x80131EA0: addiu       $v0, $zero, 0xC1
    ctx->r2 = ADD32(0, 0XC1);
    // 0x80131EA4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80131EA8:
    // 0x80131EA8: bne         $v0, $zero, L_80131EE8
    if (ctx->r2 != 0) {
        // 0x80131EAC: nop
    
            goto L_80131EE8;
    }
    // 0x80131EAC: nop

    // 0x80131EB0: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80131EB4: addiu       $t3, $t2, 0x14
    ctx->r11 = ADD32(ctx->r10, 0X14);
    // 0x80131EB8: b           L_80131EE8
    // 0x80131EBC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_80131EE8;
    // 0x80131EBC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80131EC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80131EC4:
    // 0x80131EC4: bgez        $v0, L_80131ED4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80131EC8: nop
    
            goto L_80131ED4;
    }
    // 0x80131EC8: nop

    // 0x80131ECC: addiu       $v0, $zero, 0xF3
    ctx->r2 = ADD32(0, 0XF3);
    // 0x80131ED0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80131ED4:
    // 0x80131ED4: bne         $v0, $zero, L_80131EE8
    if (ctx->r2 != 0) {
        // 0x80131ED8: nop
    
            goto L_80131EE8;
    }
    // 0x80131ED8: nop

    // 0x80131EDC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80131EE0: addiu       $t6, $t5, 0x14
    ctx->r14 = ADD32(ctx->r13, 0X14);
    // 0x80131EE4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_80131EE8:
    // 0x80131EE8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131EEC: lw          $t7, 0x4340($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4340);
    // 0x80131EF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131EF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80131EF8: beq         $t7, $at, L_80131F0C
    if (ctx->r15 == ctx->r1) {
        // 0x80131EFC: nop
    
            goto L_80131F0C;
    }
    // 0x80131EFC: nop

    // 0x80131F00: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80131F04: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80131F08: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_80131F0C:
    // 0x80131F0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131F10: sw          $t9, 0x4340($at)
    MEM_W(0X4340, ctx->r1) = ctx->r25;
L_80131F14:
    // 0x80131F14: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80131F18: bne         $v0, $zero, L_80131F44
    if (ctx->r2 != 0) {
        // 0x80131F1C: nop
    
            goto L_80131F44;
    }
    // 0x80131F1C: nop

    // 0x80131F20: jal         0x80390804
    // 0x80131F24: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_12;
    // 0x80131F24: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_12:
    // 0x80131F28: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131F2C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80131F30: addiu       $a3, $a3, 0x4308
    ctx->r7 = ADD32(ctx->r7, 0X4308);
    // 0x80131F34: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131F38: bne         $v0, $zero, L_80131F6C
    if (ctx->r2 != 0) {
        // 0x80131F3C: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80131F6C;
    }
    // 0x80131F3C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80131F40: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80131F44:
    // 0x80131F44: bne         $v0, $zero, L_801320A4
    if (ctx->r2 != 0) {
        // 0x80131F48: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_801320A4;
    }
    // 0x80131F48: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80131F4C: jal         0x8039089C
    // 0x80131F50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_13;
    // 0x80131F50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80131F54: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131F58: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80131F5C: addiu       $a3, $a3, 0x4308
    ctx->r7 = ADD32(ctx->r7, 0X4308);
    // 0x80131F60: addiu       $a2, $a2, 0x433C
    ctx->r6 = ADD32(ctx->r6, 0X433C);
    // 0x80131F64: beq         $v0, $zero, L_801320A4
    if (ctx->r2 == 0) {
        // 0x80131F68: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_801320A4;
    }
    // 0x80131F68: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80131F6C:
    // 0x80131F6C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80131F70: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F74: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80131F78: beq         $t1, $zero, L_80131F8C
    if (ctx->r9 == 0) {
        // 0x80131F7C: subu        $t5, $t4, $t3
        ctx->r13 = SUB32(ctx->r12, ctx->r11);
            goto L_80131F8C;
    }
    // 0x80131F7C: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x80131F80: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80131F84: b           L_80131FA0
    // 0x80131F88: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
        goto L_80131FA0;
    // 0x80131F88: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_80131F8C:
    // 0x80131F8C: bgez        $t5, L_80131F9C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80131F90: sra         $t6, $t5, 4
        ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
            goto L_80131F9C;
    }
    // 0x80131F90: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80131F94: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x80131F98: sra         $t6, $at, 4
    ctx->r14 = S32(SIGNED(ctx->r1) >> 4);
L_80131F9C:
    // 0x80131F9C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_80131FA0:
    // 0x80131FA0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80131FA4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131FA8: addiu       $t8, $t8, 0x4348
    ctx->r24 = ADD32(ctx->r24, 0X4348);
    // 0x80131FAC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80131FB0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80131FB4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80131FB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131FBC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131FC0: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x80131FC4: beq         $v0, $zero, L_80131FE4
    if (ctx->r2 == 0) {
        // 0x80131FC8: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_80131FE4;
    }
    // 0x80131FC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131FCC: beq         $v0, $at, L_80132018
    if (ctx->r2 == ctx->r1) {
        // 0x80131FD0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132018;
    }
    // 0x80131FD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131FD4: beql        $v0, $at, L_80132050
    if (ctx->r2 == ctx->r1) {
        // 0x80131FD8: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80132050;
    }
    goto skip_1;
    // 0x80131FD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80131FDC: b           L_8013207C
    // 0x80131FE0: nop

        goto L_8013207C;
    // 0x80131FE0: nop

L_80131FE4:
    // 0x80131FE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131FE8: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x80131FEC: bnel        $at, $zero, L_80132000
    if (ctx->r1 != 0) {
        // 0x80131FF0: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_80132000;
    }
    goto skip_2;
    // 0x80131FF0: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    skip_2:
    // 0x80131FF4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80131FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131FFC: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
L_80132000:
    // 0x80132000: bne         $v0, $at, L_8013207C
    if (ctx->r2 != ctx->r1) {
        // 0x80132004: nop
    
            goto L_8013207C;
    }
    // 0x80132004: nop

    // 0x80132008: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8013200C: addiu       $t2, $t1, 0x14
    ctx->r10 = ADD32(ctx->r9, 0X14);
    // 0x80132010: b           L_8013207C
    // 0x80132014: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
        goto L_8013207C;
    // 0x80132014: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_80132018:
    // 0x80132018: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013201C: slti        $at, $v0, 0xC2
    ctx->r1 = SIGNED(ctx->r2) < 0XC2 ? 1 : 0;
    // 0x80132020: bnel        $at, $zero, L_80132034
    if (ctx->r1 != 0) {
        // 0x80132024: addiu       $at, $zero, 0xC1
        ctx->r1 = ADD32(0, 0XC1);
            goto L_80132034;
    }
    goto skip_3;
    // 0x80132024: addiu       $at, $zero, 0xC1
    ctx->r1 = ADD32(0, 0XC1);
    skip_3:
    // 0x80132028: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8013202C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132030: addiu       $at, $zero, 0xC1
    ctx->r1 = ADD32(0, 0XC1);
L_80132034:
    // 0x80132034: bne         $v0, $at, L_8013207C
    if (ctx->r2 != ctx->r1) {
        // 0x80132038: nop
    
            goto L_8013207C;
    }
    // 0x80132038: nop

    // 0x8013203C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80132040: addiu       $t3, $t4, 0x14
    ctx->r11 = ADD32(ctx->r12, 0X14);
    // 0x80132044: b           L_8013207C
    // 0x80132048: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_8013207C;
    // 0x80132048: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8013204C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80132050:
    // 0x80132050: slti        $at, $v0, 0xF4
    ctx->r1 = SIGNED(ctx->r2) < 0XF4 ? 1 : 0;
    // 0x80132054: bnel        $at, $zero, L_80132068
    if (ctx->r1 != 0) {
        // 0x80132058: addiu       $at, $zero, 0xF3
        ctx->r1 = ADD32(0, 0XF3);
            goto L_80132068;
    }
    goto skip_4;
    // 0x80132058: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    skip_4:
    // 0x8013205C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80132060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132064: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
L_80132068:
    // 0x80132068: bne         $v0, $at, L_8013207C
    if (ctx->r2 != ctx->r1) {
        // 0x8013206C: nop
    
            goto L_8013207C;
    }
    // 0x8013206C: nop

    // 0x80132070: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80132074: addiu       $t6, $t5, 0x14
    ctx->r14 = ADD32(ctx->r13, 0X14);
    // 0x80132078: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_8013207C:
    // 0x8013207C: lw          $t7, 0x4340($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4340);
    // 0x80132080: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132084: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80132088: beq         $t7, $at, L_8013209C
    if (ctx->r15 == ctx->r1) {
        // 0x8013208C: nop
    
            goto L_8013209C;
    }
    // 0x8013208C: nop

    // 0x80132090: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80132094: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80132098: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_8013209C:
    // 0x8013209C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320A0: sw          $t9, 0x4340($at)
    MEM_W(0X4340, ctx->r1) = ctx->r25;
L_801320A4:
    // 0x801320A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801320A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801320AC: jr          $ra
    // 0x801320B0: nop

    return;
    // 0x801320B0: nop

;}
RECOMP_FUNC void syUtilsRandTimeFloat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800189F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800189FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018A00: jal         0x80034D50
    // 0x80018A04: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80018A04: nop

    after_0:
    // 0x80018A08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018A0C: jal         0x80039518
    // 0x80018A10: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    __ull_to_f_recomp(rdram, ctx);
        goto after_1;
    // 0x80018A10: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    after_1:
    // 0x80018A14: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80018A18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018A24: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80018A28: jr          $ra
    // 0x80018A2C: nop

    return;
    // 0x80018A2C: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80154034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80154038: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015403C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80154040: jal         0x80153FCC
    // 0x80154044: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftNessSpecialHiInitStatusVars(rdram, ctx);
        goto after_0;
    // 0x80154044: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80154048: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015404C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80154050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80154054: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80154058: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015405C: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80154060: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80154064: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80154068: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8015406C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80154070: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x80154074: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80154078: jal         0x800E6F24
    // 0x8015407C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015407C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80154080: jal         0x800E0830
    // 0x80154084: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80154084: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80154088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015408C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80154090: jr          $ra
    // 0x80154094: nop

    return;
    // 0x80154094: nop

;}
RECOMP_FUNC void itPakkunWaitInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017D194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D198: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017D19C: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x8017D1A0: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    // 0x8017D1A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017D1A8: jal         0x8017CF20
    // 0x8017D1AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itPakkunWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017D1AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017D1B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D1B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017D1B8: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x8017D1BC: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x8017D1C0: lwc1        $f4, 0x354($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X354);
    // 0x8017D1C4: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8017D1C8: swc1        $f4, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f4.u32l;
    // 0x8017D1CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D1D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017D1D4: jr          $ra
    // 0x8017D1D8: nop

    return;
    // 0x8017D1D8: nop

;}
RECOMP_FUNC void efManagerVelAddDestroyAnimEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FE264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FE268: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800FE26C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x800FE270: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FE274: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800FE278: jal         0x8000DF34
    // 0x800FE27C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800FE27C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800FE280: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800FE284: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FE288: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE28C: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    // 0x800FE290: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800FE294: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800FE298: lwc1        $f6, 0xA0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XA0);
    // 0x800FE29C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800FE2A0: nop

    // 0x800FE2A4: bc1fl       L_800FE2C8
    if (!c1cs) {
        // 0x800FE2A8: lwc1        $f8, 0x1C($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_800FE2C8;
    }
    goto skip_0;
    // 0x800FE2A8: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x800FE2AC: jal         0x800FD4F8
    // 0x800FE2B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800FE2B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x800FE2B4: jal         0x80009A84
    // 0x800FE2B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800FE2B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800FE2BC: b           L_800FE2E8
    // 0x800FE2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FE2E8;
    // 0x800FE2C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FE2C4: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
L_800FE2C8:
    // 0x800FE2C8: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800FE2CC: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FE2D0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FE2D4: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x800FE2D8: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800FE2DC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800FE2E0: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x800FE2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FE2E8:
    // 0x800FE2E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FE2EC: jr          $ra
    // 0x800FE2F0: nop

    return;
    // 0x800FE2F0: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetFreeCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134EC8: jal         0x800EC0EC
    // 0x80134ECC: nop

    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80134ECC: nop

    after_0:
    // 0x80134ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134ED8: jr          $ra
    // 0x80134EDC: nop

    return;
    // 0x80134EDC: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltAirProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80169390: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80169394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80169398: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016939C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801693A0: jal         0x80167FE8
    // 0x801693A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x801693A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x801693A8: beq         $v0, $zero, L_801693CC
    if (ctx->r2 == 0) {
        // 0x801693AC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_801693CC;
    }
    // 0x801693AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801693B0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801693B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801693B8: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x801693BC: jal         0x800FF648
    // 0x801693C0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801693C0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x801693C4: b           L_801693DC
    // 0x801693C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801693DC;
    // 0x801693C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801693CC:
    // 0x801693CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801693D0: jal         0x80168088
    // 0x801693D4: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    wpMainApplyGravityClampTVel(rdram, ctx);
        goto after_2;
    // 0x801693D4: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_2:
    // 0x801693D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801693DC:
    // 0x801693DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801693E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801693E4: jr          $ra
    // 0x801693E8: nop

    return;
    // 0x801693E8: nop

;}
RECOMP_FUNC void func_ovl2_80107D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107D50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80107D54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80107D58: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80107D5C: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x80107D60: lb          $v0, 0x49($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X49);
    // 0x80107D64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80107D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80107D6C: beq         $v0, $at, L_80107DF4
    if (ctx->r2 == ctx->r1) {
        // 0x80107D70: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80107DF4;
    }
    // 0x80107D70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80107D74: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80107D78: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80107D7C: lbu         $t7, -0x1680($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1680);
    // 0x80107D80: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80107D84: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80107D88: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80107D8C: sb          $t7, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r15;
    // 0x80107D90: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80107D94: lw          $t9, -0x16C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X16C0);
    // 0x80107D98: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80107D9C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80107DA0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80107DA4: addu        $s1, $t9, $t0
    ctx->r17 = ADD32(ctx->r25, ctx->r8);
    // 0x80107DA8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80107DAC: jal         0x80106A40
    // 0x80107DB0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_0;
    // 0x80107DB0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x80107DB4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80107DB8: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80107DBC: jal         0x80106A40
    // 0x80107DC0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_1;
    // 0x80107DC0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x80107DC4: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80107DC8: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    // 0x80107DCC: jal         0x80106A40
    // 0x80107DD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_2;
    // 0x80107DD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x80107DD4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80107DD8: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    // 0x80107DDC: jal         0x80106A40
    // 0x80107DE0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_3;
    // 0x80107DE0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
    // 0x80107DE4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80107DE8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80107DEC: sb          $t1, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r9;
    // 0x80107DF0: sw          $zero, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = 0;
L_80107DF4:
    // 0x80107DF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80107DF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80107DFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80107E00: jr          $ra
    // 0x80107E04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80107E04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftBossYubideppou1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A358: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015A35C: jal         0x800D9480
    // 0x8015A360: addiu       $a1, $a1, -0x58B8
    ctx->r5 = ADD32(ctx->r5, -0X58B8);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A360: addiu       $a1, $a1, -0x58B8
    ctx->r5 = ADD32(ctx->r5, -0X58B8);
    after_0:
    // 0x8015A364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015A368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A36C: jr          $ra
    // 0x8015A370: nop

    return;
    // 0x8015A370: nop

;}
RECOMP_FUNC void mnBackupClearMakeOptionConfirm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132148: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013214C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80132150: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80132154: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132158: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013215C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80132160: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80132164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132168: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013216C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80132170: jal         0x80009968
    // 0x80132174: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132174: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80132178: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013217C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132180: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132184: sw          $v0, 0x30C8($at)
    MEM_W(0X30C8, ctx->r1) = ctx->r2;
    // 0x80132188: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8013218C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132190: addiu       $a1, $a1, 0x1F98
    ctx->r5 = ADD32(ctx->r5, 0X1F98);
    // 0x80132194: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132198: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013219C: jal         0x80009DF4
    // 0x801321A0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801321A0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x801321A4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801321A8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801321AC: addiu       $s0, $s0, 0x31B0
    ctx->r16 = ADD32(ctx->r16, 0X31B0);
    // 0x801321B0: bne         $t7, $zero, L_801321F0
    if (ctx->r15 != 0) {
        // 0x801321B4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801321F0;
    }
    // 0x801321B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801321B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801321BC: addiu       $s0, $s0, 0x31B0
    ctx->r16 = ADD32(ctx->r16, 0X31B0);
    // 0x801321C0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x801321C4: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801321C8: addiu       $t9, $t9, 0x7580
    ctx->r25 = ADD32(ctx->r25, 0X7580);
    // 0x801321CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801321D0: jal         0x800CCFDC
    // 0x801321D4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801321D4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x801321D8: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x801321DC: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801321E0: addiu       $t1, $t1, 0x7500
    ctx->r9 = ADD32(ctx->r9, 0X7500);
    // 0x801321E4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801321E8: b           L_80132218
    // 0x801321EC: sw          $t2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r10;
        goto L_80132218;
    // 0x801321EC: sw          $t2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r10;
L_801321F0:
    // 0x801321F0: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x801321F4: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801321F8: addiu       $t4, $t4, 0x7580
    ctx->r12 = ADD32(ctx->r12, 0X7580);
    // 0x801321FC: jal         0x800CCFDC
    // 0x80132200: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132200: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80132204: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80132208: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x8013220C: addiu       $t6, $t6, 0x7528
    ctx->r14 = ADD32(ctx->r14, 0X7528);
    // 0x80132210: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80132214: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
L_80132218:
    // 0x80132218: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8013221C: lui         $at, 0x433D
    ctx->r1 = S32(0X433D << 16);
    // 0x80132220: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132224: lui         $at, 0x42D4
    ctx->r1 = S32(0X42D4 << 16);
    // 0x80132228: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013222C: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80132230: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132234: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80132238: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013223C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132240: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132244: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80132248: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x8013224C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132250: bne         $t2, $zero, L_80132288
    if (ctx->r10 != 0) {
        // 0x80132254: lui         $t9, 0x0
        ctx->r25 = S32(0X0 << 16);
            goto L_80132288;
    }
    // 0x80132254: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80132258: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8013225C: addiu       $t4, $t4, 0x7AB8
    ctx->r12 = ADD32(ctx->r12, 0X7AB8);
    // 0x80132260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132264: jal         0x800CCFDC
    // 0x80132268: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132268: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x8013226C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80132270: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80132274: addiu       $t6, $t6, 0x7A88
    ctx->r14 = ADD32(ctx->r14, 0X7A88);
    // 0x80132278: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8013227C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80132280: b           L_801322B0
    // 0x80132284: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
        goto L_801322B0;
    // 0x80132284: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
L_80132288:
    // 0x80132288: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8013228C: addiu       $t9, $t9, 0x7AB8
    ctx->r25 = ADD32(ctx->r25, 0X7AB8);
    // 0x80132290: jal         0x800CCFDC
    // 0x80132294: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132294: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_5:
    // 0x80132298: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8013229C: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801322A0: addiu       $t1, $t1, 0x7A60
    ctx->r9 = ADD32(ctx->r9, 0X7A60);
    // 0x801322A4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801322A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801322AC: sw          $t2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r10;
L_801322B0:
    // 0x801322B0: lhu         $t3, 0x24($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X24);
    // 0x801322B4: lui         $at, 0x42A6
    ctx->r1 = S32(0X42A6 << 16);
    // 0x801322B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801322BC: lui         $at, 0x42D4
    ctx->r1 = S32(0X42D4 << 16);
    // 0x801322C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801322C4: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x801322C8: sh          $t5, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r13;
    // 0x801322CC: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x801322D0: sh          $t6, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r14;
    // 0x801322D4: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x801322D8: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
    // 0x801322DC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x801322E0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801322E4: addiu       $t8, $t8, 0x5DB8
    ctx->r24 = ADD32(ctx->r24, 0X5DB8);
    // 0x801322E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801322EC: jal         0x800CCFDC
    // 0x801322F0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x801322F0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_6:
    // 0x801322F4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801322F8: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x801322FC: addiu       $t4, $zero, 0xEF
    ctx->r12 = ADD32(0, 0XEF);
    // 0x80132300: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132304: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132308: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013230C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132310: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80132314: addiu       $t5, $zero, 0x9D
    ctx->r13 = ADD32(0, 0X9D);
    // 0x80132318: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8013231C: bne         $t3, $zero, L_80132340
    if (ctx->r11 != 0) {
        // 0x80132320: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80132340;
    }
    // 0x80132320: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132324: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x80132328: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013232C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80132330: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132334: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132338: b           L_80132354
    // 0x8013233C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
        goto L_80132354;
    // 0x8013233C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
L_80132340:
    // 0x80132340: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132344: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80132348: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013234C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132350: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80132354:
    // 0x80132354: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80132358: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x8013235C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132360: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80132364: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132368: addiu       $t8, $t8, 0x63C8
    ctx->r24 = ADD32(ctx->r24, 0X63C8);
    // 0x8013236C: bnel        $t6, $at, L_801323CC
    if (ctx->r14 != ctx->r1) {
        // 0x80132370: lw          $t5, 0x4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X4);
            goto L_801323CC;
    }
    goto skip_0;
    // 0x80132370: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80132374: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80132378: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013237C: jal         0x800CCFDC
    // 0x80132380: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80132380: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_7:
    // 0x80132384: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132388: lui         $at, 0x426C
    ctx->r1 = S32(0X426C << 16);
    // 0x8013238C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132390: lui         $at, 0x42A6
    ctx->r1 = S32(0X42A6 << 16);
    // 0x80132394: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132398: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013239C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801323A0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801323A4: addiu       $t3, $zero, 0xEF
    ctx->r11 = ADD32(0, 0XEF);
    // 0x801323A8: addiu       $t4, $zero, 0x9D
    ctx->r12 = ADD32(0, 0X9D);
    // 0x801323AC: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801323B0: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x801323B4: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x801323B8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801323BC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801323C0: b           L_8013241C
    // 0x801323C4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
        goto L_8013241C;
    // 0x801323C4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801323C8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
L_801323CC:
    // 0x801323CC: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801323D0: addiu       $t6, $t6, 0x69D8
    ctx->r14 = ADD32(ctx->r14, 0X69D8);
    // 0x801323D4: jal         0x800CCFDC
    // 0x801323D8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x801323D8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_8:
    // 0x801323DC: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801323E0: lui         $at, 0x426C
    ctx->r1 = S32(0X426C << 16);
    // 0x801323E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801323E8: lui         $at, 0x42A6
    ctx->r1 = S32(0X42A6 << 16);
    // 0x801323EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801323F0: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x801323F4: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801323F8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x801323FC: addiu       $t1, $zero, 0xEF
    ctx->r9 = ADD32(0, 0XEF);
    // 0x80132400: addiu       $t2, $zero, 0x9D
    ctx->r10 = ADD32(0, 0X9D);
    // 0x80132404: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132408: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x8013240C: sb          $t2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r10;
    // 0x80132410: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132414: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132418: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
L_8013241C:
    // 0x8013241C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132420: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80132424: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132428: jr          $ra
    // 0x8013242C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8013242C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void lbCommonSim2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7C14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C7C18: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7C1C: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7C20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C7C24: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C7C28: nop

    // 0x800C7C2C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C7C30: jal         0x80033510
    // 0x800C7C34: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7C34: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800C7C38: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800C7C3C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800C7C40: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C7C44: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C7C48: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C7C4C: nop

    // 0x800C7C50: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C7C54: jal         0x80033510
    // 0x800C7C58: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C7C58: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x800C7C5C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800C7C60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C7C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7C68: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C7C6C: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7C70: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C7C74: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7C78: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C7C7C: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C7C80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7C84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C7C88: add.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800C7C8C: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800C7C90: jr          $ra
    // 0x800C7C94: div.s       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    return;
    // 0x800C7C94: div.s       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
;}
RECOMP_FUNC void mvEndingFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void ftParamInitGame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC138: jal         0x800E1CF0
    // 0x800EC13C: nop

    ftMainClearGroundElementsAll(rdram, ctx);
        goto after_0;
    // 0x800EC13C: nop

    after_0:
    // 0x800EC140: jal         0x80113488
    // 0x800EC144: nop

    ifCommonBattleInitPlacement(rdram, ctx);
        goto after_1;
    // 0x800EC144: nop

    after_1:
    // 0x800EC148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC14C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC150: jr          $ra
    // 0x800EC154: nop

    return;
    // 0x800EC154: nop

;}
RECOMP_FUNC void ftPhysicsApplyGravityDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8E50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8E58: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D8E5C: lw          $a2, 0x5C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X5C);
    // 0x800D8E60: jal         0x800D8D68
    // 0x800D8E64: lw          $a1, 0x58($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X58);
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x800D8E64: lw          $a1, 0x58($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X58);
    after_0:
    // 0x800D8E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8E6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8E70: jr          $ra
    // 0x800D8E74: nop

    return;
    // 0x800D8E74: nop

;}
RECOMP_FUNC void func_ovl8_80385180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80385184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80385188: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8038518C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80385190: jal         0x803717A0
    // 0x80385194: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80385194: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_0:
    // 0x80385198: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8038519C: beq         $v0, $zero, L_803851CC
    if (ctx->r2 == 0) {
        // 0x803851A0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803851CC;
    }
    // 0x803851A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803851A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x803851A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803851AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803851B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803851B4: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x803851B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x803851BC: jal         0x803851E4
    // 0x803851C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_803851E4(rdram, ctx);
        goto after_1;
    // 0x803851C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x803851C4: b           L_803851D0
    // 0x803851C8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803851D0;
    // 0x803851C8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803851CC:
    // 0x803851CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803851D0:
    // 0x803851D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803851D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803851D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803851DC: jr          $ra
    // 0x803851E0: nop

    return;
    // 0x803851E0: nop

;}
RECOMP_FUNC void itMarumineExplodeUpdateAttackEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183830: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80183834: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80183838: lw          $t6, -0x4BFC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BFC);
    // 0x8018383C: lw          $a1, 0x340($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X340);
    // 0x80183840: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80183844: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80183848: addiu       $t8, $t8, 0x14C
    ctx->r24 = ADD32(ctx->r24, 0X14C);
    // 0x8018384C: srl         $a1, $a1, 28
    ctx->r5 = S32(U32(ctx->r5) >> 28);
    // 0x80183850: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80183854: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80183858: addu        $a2, $v1, $t9
    ctx->r6 = ADD32(ctx->r3, ctx->r25);
    // 0x8018385C: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x80183860: lhu         $t0, 0x33E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X33E);
    // 0x80183864: bne         $t0, $t1, L_8018390C
    if (ctx->r8 != ctx->r9) {
        // 0x80183868: nop
    
            goto L_8018390C;
    }
    // 0x80183868: nop

    // 0x8018386C: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80183870: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80183874: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80183878: sra         $t4, $t3, 22
    ctx->r12 = S32(SIGNED(ctx->r11) >> 22);
    // 0x8018387C: sw          $t4, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r12;
    // 0x80183880: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80183884: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80183888: sll         $t6, $t5, 18
    ctx->r14 = S32(ctx->r13 << 18);
    // 0x8018388C: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x80183890: sw          $t7, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r15;
    // 0x80183894: lhu         $t8, 0x4($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X4);
    // 0x80183898: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x8018389C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x801838A0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801838A4: bgez        $t8, L_801838B8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801838A8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801838B8;
    }
    // 0x801838A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801838AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801838B0: nop

    // 0x801838B4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801838B8:
    // 0x801838B8: lbu         $t9, 0x158($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X158);
    // 0x801838BC: andi        $t8, $t7, 0xF0
    ctx->r24 = ctx->r15 & 0XF0;
    // 0x801838C0: sw          $t3, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r11;
    // 0x801838C4: andi        $t1, $t9, 0xFFFB
    ctx->r9 = ctx->r25 & 0XFFFB;
    // 0x801838C8: lbu         $t9, 0x340($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X340);
    // 0x801838CC: sb          $t1, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r9;
    // 0x801838D0: andi        $t4, $t1, 0xFD
    ctx->r12 = ctx->r9 & 0XFD;
    // 0x801838D4: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x801838D8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x801838DC: sb          $t1, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r9;
    // 0x801838E0: lw          $t2, 0x340($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X340);
    // 0x801838E4: sb          $t4, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r12;
    // 0x801838E8: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x801838EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801838F0: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x801838F4: swc1        $f6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f6.u32l;
    // 0x801838F8: bne         $t3, $at, L_8018390C
    if (ctx->r11 != ctx->r1) {
        // 0x801838FC: sb          $t5, 0x158($v0)
        MEM_B(0X158, ctx->r2) = ctx->r13;
            goto L_8018390C;
    }
    // 0x801838FC: sb          $t5, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r13;
    // 0x80183900: andi        $t5, $t1, 0xF
    ctx->r13 = ctx->r9 & 0XF;
    // 0x80183904: ori         $t6, $t5, 0x30
    ctx->r14 = ctx->r13 | 0X30;
    // 0x80183908: sb          $t6, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r14;
L_8018390C:
    // 0x8018390C: jr          $ra
    // 0x80183910: nop

    return;
    // 0x80183910: nop

;}
RECOMP_FUNC void mnMapsMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132738: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013273C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132740: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80132744: addiu       $t6, $t6, 0x46DC
    ctx->r14 = ADD32(ctx->r14, 0X46DC);
    // 0x80132748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013274C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80132750: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80132754: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80132758:
    // 0x80132758: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013275C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132760: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132764: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132768: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8013276C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132770: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132774: bne         $t6, $t0, L_80132758
    if (ctx->r14 != ctx->r8) {
        // 0x80132778: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132758;
    }
    // 0x80132778: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8013277C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80132780: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132784: lw          $t5, 0x4E18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4E18);
    // 0x80132788: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8013278C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80132790: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80132794: jal         0x800CCFDC
    // 0x80132798: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132798: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_0:
    // 0x8013279C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801327A0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801327A4: jal         0x801326DC
    // 0x801327A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    mnMapsSetNamePosition(rdram, ctx);
        goto after_1;
    // 0x801327A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x801327AC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x801327B0: lhu         $t0, 0x24($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X24);
    // 0x801327B4: sb          $zero, 0x28($v1)
    MEM_B(0X28, ctx->r3) = 0;
    // 0x801327B8: sb          $zero, 0x29($v1)
    MEM_B(0X29, ctx->r3) = 0;
    // 0x801327BC: andi        $t9, $t0, 0xFFDF
    ctx->r25 = ctx->r8 & 0XFFDF;
    // 0x801327C0: ori         $t7, $t9, 0x1
    ctx->r15 = ctx->r25 | 0X1;
    // 0x801327C4: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x801327C8: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x801327CC: sb          $zero, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = 0;
    // 0x801327D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801327D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801327D8: jr          $ra
    // 0x801327DC: nop

    return;
    // 0x801327DC: nop

;}
RECOMP_FUNC void func_800077D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800077D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800077D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800077D8: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800077DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800077E0: jal         0x80007784
    // 0x800077E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80007784(rdram, ctx);
        goto after_0;
    // 0x800077E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800077E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800077EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800077F0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800077F4: beql        $v0, $zero, L_8000780C
    if (ctx->r2 == 0) {
        // 0x800077F8: lw          $t7, 0x0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X0);
            goto L_8000780C;
    }
    goto skip_0;
    // 0x800077F8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800077FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80007800: b           L_80007810
    // 0x80007804: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80007810;
    // 0x80007804: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80007808: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_8000780C:
    // 0x8000780C: sw          $t7, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r15;
L_80007810:
    // 0x80007810: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80007814: beql        $v0, $zero, L_8000782C
    if (ctx->r2 == 0) {
        // 0x80007818: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_8000782C;
    }
    goto skip_1;
    // 0x80007818: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x8000781C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80007820: b           L_80007830
    // 0x80007824: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80007830;
    // 0x80007824: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80007828: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
L_8000782C:
    // 0x8000782C: sw          $t9, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r25;
L_80007830:
    // 0x80007830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007834: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80007838: jr          $ra
    // 0x8000783C: nop

    return;
    // 0x8000783C: nop

;}
RECOMP_FUNC void efManagerQuakeMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801008F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801008F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801008FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100900: jal         0x800FD4B8
    // 0x80100904: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80100904: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80100908: bne         $v0, $zero, L_80100918
    if (ctx->r2 != 0) {
        // 0x8010090C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80100918;
    }
    // 0x8010090C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80100910: b           L_80100A44
    // 0x80100914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100A44;
    // 0x80100914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100918:
    // 0x80100918: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8010091C: addiu       $a1, $a1, 0x8B8
    ctx->r5 = ADD32(ctx->r5, 0X8B8);
    // 0x80100920: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x80100924: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80100928: jal         0x80009968
    // 0x8010092C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8010092C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80100930: bne         $v0, $zero, L_80100940
    if (ctx->r2 != 0) {
        // 0x80100934: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80100940;
    }
    // 0x80100934: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80100938: b           L_80100A44
    // 0x8010093C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100A44;
    // 0x8010093C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100940:
    // 0x80100940: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80100944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010094C: jal         0x800092D0
    // 0x80100950: sw          $t6, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r14;
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80100950: sw          $t6, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r14;
    after_2:
    // 0x80100954: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100958: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8010095C: jal         0x80008CC0
    // 0x80100960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x80100960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80100964: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80100968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010096C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80100970: beq         $v1, $zero, L_801009A4
    if (ctx->r3 == 0) {
        // 0x80100974: lui         $t8, 0x1
        ctx->r24 = S32(0X1 << 16);
            goto L_801009A4;
    }
    // 0x80100974: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80100978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010097C: beq         $v1, $at, L_801009C0
    if (ctx->r3 == ctx->r1) {
        // 0x80100980: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801009C0;
    }
    // 0x80100980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100984: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80100988: beq         $v1, $at, L_801009E4
    if (ctx->r3 == ctx->r1) {
        // 0x8010098C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801009E4;
    }
    // 0x8010098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100990: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80100994: beq         $v1, $at, L_80100A08
    if (ctx->r3 == ctx->r1) {
        // 0x80100998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80100A08;
    }
    // 0x80100998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010099C: b           L_80100A24
    // 0x801009A0: nop

        goto L_80100A24;
    // 0x801009A0: nop

L_801009A4:
    // 0x801009A4: lw          $t7, 0x13B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X13B0);
    // 0x801009A8: addiu       $t8, $t8, -0x3440
    ctx->r24 = ADD32(ctx->r24, -0X3440);
    // 0x801009AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801009B0: jal         0x8000BD8C
    // 0x801009B4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x801009B4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x801009B8: b           L_80100A24
    // 0x801009BC: nop

        goto L_80100A24;
    // 0x801009BC: nop

L_801009C0:
    // 0x801009C0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801009C4: lw          $t9, 0x13B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X13B0);
    // 0x801009C8: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x801009CC: addiu       $t0, $t0, -0x33E0
    ctx->r8 = ADD32(ctx->r8, -0X33E0);
    // 0x801009D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801009D4: jal         0x8000BD8C
    // 0x801009D8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_5;
    // 0x801009D8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_5:
    // 0x801009DC: b           L_80100A24
    // 0x801009E0: nop

        goto L_80100A24;
    // 0x801009E0: nop

L_801009E4:
    // 0x801009E4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801009E8: lw          $t1, 0x13B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X13B0);
    // 0x801009EC: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x801009F0: addiu       $t2, $t2, -0x3310
    ctx->r10 = ADD32(ctx->r10, -0X3310);
    // 0x801009F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801009F8: jal         0x8000BD8C
    // 0x801009FC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddAnimJointAll(rdram, ctx);
        goto after_6;
    // 0x801009FC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_6:
    // 0x80100A00: b           L_80100A24
    // 0x80100A04: nop

        goto L_80100A24;
    // 0x80100A04: nop

L_80100A08:
    // 0x80100A08: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80100A0C: lw          $t3, 0x13B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X13B0);
    // 0x80100A10: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80100A14: addiu       $t4, $t4, -0x3240
    ctx->r12 = ADD32(ctx->r12, -0X3240);
    // 0x80100A18: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80100A1C: jal         0x8000BD8C
    // 0x80100A20: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddAnimJointAll(rdram, ctx);
        goto after_7;
    // 0x80100A20: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_7:
L_80100A24:
    // 0x80100A24: jal         0x8000DF34
    // 0x80100A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_8;
    // 0x80100A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80100A2C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80100A30: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80100A34: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80100A38: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80100A3C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80100A40: sb          $t7, 0x18($t8)
    MEM_B(0X18, ctx->r24) = ctx->r15;
L_80100A44:
    // 0x80100A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100A48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100A4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80100A50: jr          $ra
    // 0x80100A54: nop

    return;
    // 0x80100A54: nop

;}
RECOMP_FUNC void dbFallsFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6490: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D6494: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800D6498: addiu       $t8, $t8, 0x66F8
    ctx->r24 = ADD32(ctx->r24, 0X66F8);
    // 0x800D649C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800D64A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D64A4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800D64A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D64AC: jr          $ra
    // 0x800D64B0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x800D64B0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void func_ovl8_8037EE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EE64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037EE68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037EE6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037EE70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037EE74: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037EE78: bne         $a0, $zero, L_8037EE90
    if (ctx->r4 != 0) {
        // 0x8037EE7C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8037EE90;
    }
    // 0x8037EE7C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037EE80: jal         0x803717A0
    // 0x8037EE84: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037EE84: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x8037EE88: beq         $v0, $zero, L_8037EEF8
    if (ctx->r2 == 0) {
        // 0x8037EE8C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037EEF8;
    }
    // 0x8037EE8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037EE90:
    // 0x8037EE90: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8037EE94: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8037EE98: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x8037EE9C: bnel        $t6, $zero, L_8037EEC0
    if (ctx->r14 != 0) {
        // 0x8037EEA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037EEC0;
    }
    goto skip_0;
    // 0x8037EEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8037EEA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037EEA8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8037EEAC: jal         0x803717E0
    // 0x8037EEB0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037EEB0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037EEB4: jal         0x8037C2D0
    // 0x8037EEB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037EEB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8037EEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8037EEC0:
    // 0x8037EEC0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037EEC4: jal         0x80373C10
    // 0x8037EEC8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_80373C10(rdram, ctx);
        goto after_3;
    // 0x8037EEC8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8037EECC: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037EED0: addiu       $t7, $t7, -0x5490
    ctx->r15 = ADD32(ctx->r15, -0X5490);
    // 0x8037EED4: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x8037EED8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8037EEDC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037EEE0: addiu       $t8, $t8, -0x53B8
    ctx->r24 = ADD32(ctx->r24, -0X53B8);
    // 0x8037EEE4: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x8037EEE8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8037EEEC: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037EEF0: addiu       $t0, $t0, -0x5260
    ctx->r8 = ADD32(ctx->r8, -0X5260);
    // 0x8037EEF4: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_8037EEF8:
    // 0x8037EEF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037EEFC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037EF00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037EF04: jr          $ra
    // 0x8037EF08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037EF08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayers1PTrainingReadyProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013725C: jal         0x800CCF00
    // 0x80137260: nop

    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_0;
    // 0x80137260: nop

    after_0:
    // 0x80137264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013726C: jr          $ra
    // 0x80137270: nop

    return;
    // 0x80137270: nop

;}
RECOMP_FUNC void mnPlayersVSMakeGateCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132F00: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132F04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132F08: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132F0C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80132F10: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132F14: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x80132F18: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132F1C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132F20: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132F24: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132F28: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132F2C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132F30: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132F34: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132F38: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132F3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132F40: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132F44: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132F48: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132F4C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132F54: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132F58: jal         0x8000B93C
    // 0x80132F5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132F5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132F60: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132F64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132F68: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132F6C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132F70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132F74: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132F78: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132F7C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132F80: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132F84: jal         0x80007080
    // 0x80132F88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132F88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132F8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132F90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132F94: jr          $ra
    // 0x80132F98: nop

    return;
    // 0x80132F98: nop

;}

	.syntax unified
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x50]
	ldrb r0, [r0, #0xd]
	cmp r0, #0xc
	bls _080272E2
	b _08027532
_080272E2:
	lsls r0, r0, #2
	ldr r1, _080272EC @ =_080272F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080272EC: .4byte _080272F0
_080272F0: @ jump table
	.4byte _08027508 @ case 0
	.4byte _08027324 @ case 1
	.4byte _08027324 @ case 2
	.4byte _08027332 @ case 3
	.4byte _0802733E @ case 4
	.4byte _08027332 @ case 5
	.4byte _08027368 @ case 6
	.4byte _08027532 @ case 7
	.4byte _08027346 @ case 8
	.4byte _08027454 @ case 9
	.4byte _0802748C @ case 10
	.4byte _08027532 @ case 11
	.4byte _08027324 @ case 12
_08027324:
	adds r1, r6, #0
	adds r1, #0x7a
	movs r0, #0xa0
	strh r0, [r1]
	subs r1, #4
	strh r0, [r1]
	b _0802733E
_08027332:
	adds r0, r6, #0
	adds r0, #0x83
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802733E
	b _08027532
_0802733E:
	adds r0, r6, #0
	bl sub_0802757C
	b _08027532
_08027346:
	ldrb r0, [r6, #0xf]
	cmp r0, #2
	bls _0802734E
	b _08027532
_0802734E:
	adds r0, r6, #0
	bl sub_0802757C
	adds r0, r6, #0
	adds r0, #0x83
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027360
	b _08027532
_08027360:
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
	b _08027532
_08027368:
	ldr r5, [r6, #0x48]
	adds r0, r6, #0
	adds r0, #0x7a
	ldrh r1, [r0]
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r4, #0
	bl __divsi3
	lsls r1, r0, #3
	adds r1, r1, r0
	lsrs r1, r1, #7
	strb r1, [r5, #6]
	ldr r5, [r6, #0x48]
	adds r0, r6, #0
	adds r0, #0x76
	ldrh r1, [r0]
	adds r0, r4, #0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsrs r1, r1, #6
	strb r1, [r5, #7]
	adds r0, r6, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0
	bne _080273A4
	b _08027532
_080273A4:
	adds r0, r6, #0
	adds r0, #0x41
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08027444
	adds r2, r6, #0
	adds r2, #0x3d
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08027444
	ldr r0, [r6, #0x54]
	ldr r0, [r0, #0x68]
	adds r0, #0x3d
	strb r1, [r0]
	ldr r0, [r6, #0x54]
	ldr r0, [r0, #0x50]
	ldrb r1, [r2]
	adds r0, #0x3d
	strb r1, [r0]
	ldr r0, [r6, #0x54]
	ldrb r1, [r2]
	adds r0, #0x3d
	strb r1, [r0]
	ldr r0, [r6, #0x54]
	bl sub_08027D20
	adds r2, r0, #0
	cmp r2, #0
	beq _08027406
	ldrh r0, [r6, #0x2e]
	adds r0, #1
	strh r0, [r2, #0x2e]
	adds r0, r6, #0
	adds r0, #0x63
	ldrb r0, [r0]
	adds r0, #0x20
	adds r1, r2, #0
	adds r1, #0x63
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x62
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x62
	strb r1, [r0]
_08027406:
	ldr r0, [r6, #0x54]
	bl sub_08027C54
	cmp r0, #0
	beq _0802741C
	ldr r0, [r6, #0x54]
	adds r0, #0x84
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #2
	beq _08027428
_0802741C:
	ldr r0, _08027424 @ =0x00000127
	bl SoundReq
	b _08027444
	.align 2, 0
_08027424: .4byte 0x00000127
_08027428:
	bl sub_08078B48
	ldr r0, _0802744C @ =gRoomControls
	ldr r2, [r6, #0x54]
	str r2, [r0, #0x30]
	ldr r1, _08027450 @ =gPauseMenuOptions
	movs r0, #1
	strb r0, [r1]
	movs r0, #9
	strb r0, [r2, #0xd]
	movs r0, #0x94
	lsls r0, r0, #1
	bl SoundReq
_08027444:
	adds r0, r6, #0
	bl sub_08027A60
	b _08027484
	.align 2, 0
_0802744C: .4byte gRoomControls
_08027450: .4byte gPauseMenuOptions
_08027454:
	ldr r5, [r6, #0x48]
	adds r0, r6, #0
	adds r0, #0x7a
	ldrh r1, [r0]
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r4, #0
	bl __divsi3
	lsls r1, r0, #3
	adds r1, r1, r0
	lsrs r1, r1, #7
	strb r1, [r5, #6]
	ldr r5, [r6, #0x48]
	adds r0, r6, #0
	adds r0, #0x76
	ldrh r1, [r0]
	adds r0, r4, #0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsrs r1, r1, #6
	strb r1, [r5, #7]
_08027484:
	adds r0, r6, #0
	bl sub_0800445C
	b _08027532
_0802748C:
	adds r2, r6, #0
	adds r2, #0x7d
	ldrb r0, [r2]
	cmp r0, #0
	bne _0802749E
	adds r0, r6, #0
	bl sub_0802757C
	b _080274AE
_0802749E:
	adds r1, r6, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #0
	beq _080274AE
	movs r0, #0
	strb r0, [r2]
	strb r0, [r1]
_080274AE:
	adds r2, r6, #0
	adds r2, #0x83
	adds r0, r6, #0
	adds r0, #0x81
	ldrb r1, [r0]
	lsrs r0, r1, #1
	ldrb r2, [r2]
	adds r0, r2, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r1
	bls _080274F4
	lsls r0, r2, #0x18
	cmp r0, #0
	ble _080274E0
	adds r0, r6, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _08027532
	adds r0, r6, #0
	movs r1, #0xc
	bl InitAnimationForceUpdate
	b _08027532
_080274E0:
	adds r0, r6, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _08027532
	adds r0, r6, #0
	movs r1, #0xb
	bl InitAnimationForceUpdate
	b _08027532
_080274F4:
	adds r0, r6, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _08027532
	adds r0, r6, #0
	movs r1, #0xa
	bl InitAnimationForceUpdate
	b _08027532
_08027508:
	ldr r0, [r6, #0x54]
	adds r0, #0x84
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #8
	bne _08027532
	adds r0, r6, #0
	bl sub_0802757C
	adds r0, r6, #0
	adds r0, #0x7d
	ldrb r0, [r0]
	cmp r0, #1
	bne _08027532
	adds r1, r6, #0
	adds r1, #0x81
	ldrb r0, [r1]
	cmp r0, #0
	beq _08027532
	subs r0, #4
	strb r0, [r1]
_08027532:
	ldr r0, [r6, #0x50]
	ldr r0, [r0, #0x34]
	str r0, [r6, #0x34]
	adds r1, r6, #0
	adds r1, #0x41
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	bl UpdateAnimationSingleFrame
	pop {r4, r5, r6, pc}
	.syntax divided

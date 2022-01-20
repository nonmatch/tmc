	.syntax unified
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r4, [r7, #0x54]
	ldr r5, [r7, #0x68]
	ldr r6, [r7, #0x50]
	ldr r0, [r4, #0x74]
	str r0, [r6, #0x74]
	ldr r0, [r4, #0x78]
	str r0, [r6, #0x78]
	ldr r0, [r4, #0x74]
	str r0, [r5, #0x74]
	ldr r0, [r4, #0x78]
	str r0, [r5, #0x78]
	adds r0, r4, #0
	adds r0, #0x83
	ldrb r0, [r0]
	rsbs r0, r0, #0
	adds r1, r4, #0
	adds r1, #0x7f
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x83
	ldrb r0, [r0]
	rsbs r0, r0, #0
	adds r1, r5, #0
	adds r1, #0x7f
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x83
	ldrb r0, [r0]
	rsbs r0, r0, #0
	adds r1, r6, #0
	adds r1, #0x7f
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x7a
	ldrh r0, [r1]
	cmp r0, #0xa0
	bls _080278C2
	movs r0, #0xe
	b _080278CC
_080278C2:
	ldrh r1, [r1]
	movs r0, #0xa0
	subs r0, r0, r1
	asrs r0, r0, #3
	adds r0, #0xe
_080278CC:
	strb r0, [r5, #0xe]
	adds r1, r6, #0
	adds r1, #0x7a
	ldrh r0, [r1]
	cmp r0, #0xa0
	bls _080278EA
	adds r2, r4, #0
	adds r2, #0x7a
	ldrh r1, [r2]
	subs r1, #0xa0
	asrs r1, r1, #4
	movs r0, #0x12
	subs r0, r0, r1
	strb r0, [r6, #0xe]
	b _080278FA
_080278EA:
	ldrh r1, [r1]
	movs r0, #0xa0
	subs r0, r0, r1
	asrs r0, r0, #2
	adds r0, #0x12
	strb r0, [r6, #0xe]
	adds r2, r4, #0
	adds r2, #0x7a
_080278FA:
	adds r0, r2, #0
	ldrh r1, [r0]
	cmp r1, #0xa0
	bls _0802791A
	adds r0, r1, #0
	subs r0, #0xa0
	asrs r0, r0, #2
	movs r1, #0xe
	subs r1, r1, r0
	strb r1, [r4, #0xe]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08027934
	movs r0, #0
	b _08027932
_0802791A:
	cmp r1, #0x7f
	bhi _08027928
	ldrh r1, [r0]
	movs r0, #0xa0
	subs r0, r0, r1
	asrs r0, r0, #2
	b _08027930
_08027928:
	ldrh r1, [r2]
	movs r0, #0xa0
	subs r0, r0, r1
	asrs r0, r0, #1
_08027930:
	adds r0, #0xe
_08027932:
	strb r0, [r4, #0xe]
_08027934:
	ldr r0, [r7, #0x2c]
	str r0, [r5, #0x2c]
	ldr r0, [r7, #0x30]
	str r0, [r5, #0x30]
	ldrb r1, [r5, #0xe]
	lsls r1, r1, #8
	adds r0, r5, #0
	adds r0, #0x83
	ldrb r2, [r0]
	adds r0, r5, #0
	bl LinearMoveAngle
	ldr r0, [r5, #0x2c]
	str r0, [r6, #0x2c]
	ldr r0, [r5, #0x30]
	str r0, [r6, #0x30]
	ldrb r1, [r6, #0xe]
	lsls r1, r1, #8
	adds r0, r6, #0
	adds r0, #0x83
	ldrb r2, [r0]
	adds r0, r6, #0
	bl LinearMoveAngle
	ldr r0, [r6, #0x2c]
	str r0, [r4, #0x2c]
	ldr r0, [r6, #0x30]
	str r0, [r4, #0x30]
	ldrb r1, [r4, #0xe]
	lsls r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x83
	ldrb r2, [r0]
	adds r0, r4, #0
	bl LinearMoveAngle
	adds r0, r7, #0
	bl sub_08027984
	pop {r4, r5, r6, r7, pc}
	.syntax divided

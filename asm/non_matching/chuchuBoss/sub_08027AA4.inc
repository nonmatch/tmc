	.syntax unified
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x41
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08027B94
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x13
	beq _08027AC2
	cmp r0, #0x1b
	beq _08027B44
	b _08027B94
_08027AC2:
	movs r0, #0x84
	bl SoundReq
	ldrb r3, [r5, #0xb]
	adds r0, r5, #0
	movs r1, #0x49
	movs r2, #9
	bl CreateObjectWithParent
	ldr r0, _08027B3C @ =0x00000155
	bl SoundReq
	adds r0, r5, #0
	adds r0, #0x84
	ldr r4, [r0]
	adds r1, r5, #0
	adds r1, #0x3d
	movs r0, #3
	strb r0, [r1]
	ldrb r0, [r4, #6]
	adds r0, #1
	strb r0, [r4, #6]
	ldrb r0, [r4, #6]
	movs r1, #3
	bl __divsi3
	adds r1, r0, #0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x15
	ldrb r2, [r4, #5]
	cmp r0, r2
	beq _08027B06
	lsls r0, r1, #3
	strb r0, [r4, #5]
_08027B06:
	movs r0, #0xb4
	str r0, [r4, #8]
	movs r0, #5
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _08027B94
	movs r0, #0x40
	strb r0, [r4, #1]
	adds r1, r5, #0
	adds r1, #0x3f
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r5, #0xd]
	cmp r0, #2
	bne _08027B2A
	adds r0, r5, #0
	bl sub_08027BBC
_08027B2A:
	adds r0, r5, #0
	bl sub_08027D20
	ldr r0, _08027B40 @ =0x00000127
	bl SoundReq
_08027B36:
	movs r0, #1
	b _08027B96
	.align 2, 0
_08027B3C: .4byte 0x00000155
_08027B40: .4byte 0x00000127
_08027B44:
	adds r1, r5, #0
	adds r1, #0x3d
	movs r0, #0xe2
	strb r0, [r1]
	ldr r0, [r5, #0x4c]
	ldrb r0, [r0, #0xa]
	adds r0, #1
	cmp r0, #2
	beq _08027B74
	cmp r0, #2
	bgt _08027B60
	cmp r0, #1
	beq _08027B84
	b _08027B36
_08027B60:
	cmp r0, #3
	bne _08027B36
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xe0
	lsls r0, r0, #1
	b _08027B90
_08027B74:
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0x14
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xc0
	lsls r0, r0, #1
	b _08027B90
_08027B84:
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #4
	adds r0, #0xf0
_08027B90:
	strh r0, [r1]
	b _08027B36
_08027B94:
	movs r0, #0
_08027B96:
	pop {r4, r5, pc}
	.syntax divided

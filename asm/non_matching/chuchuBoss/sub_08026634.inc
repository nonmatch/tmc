	.syntax unified
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl sub_08027AA4
	cmp r0, #0
	beq _08026644
	b _08026748
_08026644:
	adds r0, r4, #0
	adds r0, #0x7d
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080266D6
	adds r1, r4, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08026748
	adds r1, #8
	ldr r2, [r1]
	ldrb r3, [r2, #1]
	movs r0, #0x40
	ands r0, r3
	adds r5, r1, #0
	cmp r0, #0
	bne _080266B0
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _0802668C
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	ldr r1, [r5]
	ldrb r0, [r1]
	cmp r0, #0
	bne _080266B0
	movs r0, #1
	b _080266AE
_0802668C:
	movs r0, #1
	strb r0, [r2, #1]
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	cmp r0, #2
	bne _080266B0
	bl Random
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	beq _080266B0
	ldr r1, [r5]
	movs r0, #4
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, #0x81
_080266AE:
	strb r0, [r1, #1]
_080266B0:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	ldr r0, [r5]
	strb r1, [r0, #3]
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #0x90
	movs r2, #0x90
	movs r3, #0xc
	bl sub_08027B98
	movs r0, #0xe0
	lsls r0, r0, #0xb
	str r0, [r4, #0x20]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r4, #0x24]
	b _08026742
_080266D6:
	ldr r0, _08026700 @ =gRoomTransition
	ldr r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	cmp r0, #0
	bne _080266EC
	ldr r1, _08026704 @ =gPlayerEntity
	adds r0, r4, #0
	bl GetFacingDirection
	strb r0, [r4, #0x15]
_080266EC:
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #2
	bne _08026708
	movs r0, #0x80
	lsls r0, r0, #1
	b _0802670A
	.align 2, 0
_08026700: .4byte gRoomTransition
_08026704: .4byte gPlayerEntity
_08026708:
	movs r0, #0xc0
_0802670A:
	strh r0, [r4, #0x24]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0802672C
	ldr r0, _0802674C @ =gRoomTransition
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08026726
	movs r0, #0xcf
	lsls r0, r0, #1
	bl SoundReq
_08026726:
	adds r0, r4, #0
	bl ProcessMovement0
_0802672C:
	adds r0, r4, #0
	adds r0, #0x76
	adds r1, r4, #0
	adds r1, #0x81
	ldrh r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08026742
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
_08026742:
	adds r0, r4, #0
	bl sub_08027870
_08026748:
	add sp, #4
	pop {r4, r5, pc}
	.align 2, 0
_0802674C: .4byte gRoomTransition
	.syntax divided

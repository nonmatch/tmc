	.syntax unified
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _08026398 @ =gPlayerEntity
	ldrb r0, [r4, #0xc]
	cmp r0, #0xf
	beq _080263B0
	adds r1, r3, #0
	adds r1, #0x7d
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080263A0
	adds r0, r3, #0
	adds r0, #0x7c
	strb r2, [r0]
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	strb r2, [r4, #0x14]
	ldr r1, _0802639C @ =gRoomControls
	str r3, [r1, #0x30]
	movs r0, #1
	strb r0, [r1, #0xe]
	b _080263B0
	.align 2, 0
_08026398: .4byte gPlayerEntity
_0802639C: .4byte gRoomControls
_080263A0:
	cmp r2, #0x60
	bhi _080263B0
	cmp r2, #0x5b
	bhi _080263AC
	movs r0, #4
	b _080263AE
_080263AC:
	movs r0, #2
_080263AE:
	strb r0, [r4, #0x14]
_080263B0:
	pop {r4, pc}
	.align 2, 0
	.syntax divided

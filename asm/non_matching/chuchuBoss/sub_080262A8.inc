	.syntax unified
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x82
	movs r6, #0
	movs r0, #0x90
	strb r0, [r1]
	subs r1, #1
	movs r0, #0xb0
	strb r0, [r1]
	subs r1, #1
	movs r0, #8
	strb r0, [r1]
	movs r5, #1
	strb r5, [r4, #0xe]
	adds r0, r4, #0
	movs r1, #6
	movs r2, #1
	bl sub_080276F4
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne _080262EC
	ldr r1, _080262E8 @ =gPlayerState
	movs r0, #0x82
	lsls r0, r0, #1
	strh r0, [r1, #8]
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	strb r5, [r0, #3]
	b _0802631A
	.align 2, 0
_080262E8: .4byte gPlayerState
_080262EC:
	adds r0, r4, #0
	adds r0, #0x7c
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0x7d
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #3
	strb r0, [r1, #3]
	ldr r0, _0802631C @ =gPlayerEntity
	strb r6, [r0, #0x14]
	ldr r0, _08026320 @ =gRoomControls
	str r4, [r0, #0x30]
	strb r5, [r0, #0xe]
	ldr r0, _08026324 @ =0x00004022
	movs r1, #0xb2
	lsls r1, r1, #2
	movs r2, #1
	bl SetTile
_0802631A:
	pop {r4, r5, r6, pc}
	.align 2, 0
_0802631C: .4byte gPlayerEntity
_08026320: .4byte gRoomControls
_08026324: .4byte 0x00004022
	.syntax divided

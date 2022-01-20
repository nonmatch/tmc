	.syntax unified
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	adds r0, #0x81
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802652C
	adds r0, r2, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	ldr r1, _08026534 @ =gRoomControls
	ldr r0, _08026538 @ =gPlayerEntity
	str r0, [r1, #0x30]
_0802652C:
	adds r0, r2, #0
	bl sub_08027870
	pop {pc}
	.align 2, 0
_08026534: .4byte gRoomControls
_08026538: .4byte gPlayerEntity
	.syntax divided

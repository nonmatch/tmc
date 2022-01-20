	.syntax unified
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08026578 @ =gRoomControls
	ldrh r5, [r1]
	cmp r5, #0
	bne _08026572
	movs r0, #4
	strb r0, [r1, #0xe]
	movs r0, #0xff
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0x90
	movs r2, #0xb0
	movs r3, #4
	bl sub_08027B98
	adds r0, r4, #0
	movs r1, #0
	bl sub_08027548
	ldr r0, [r4, #0x54]
	movs r1, #0
	bl InitAnimationForceUpdate
	ldr r0, _0802657C @ =gPauseMenuOptions
	strb r5, [r0]
_08026572:
	add sp, #4
	pop {r4, r5, pc}
	.align 2, 0
_08026578: .4byte gRoomControls
_0802657C: .4byte gPauseMenuOptions
	.syntax divided

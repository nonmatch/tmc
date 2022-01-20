	.syntax unified
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080279E8
	cmp r0, #0
	beq _08026504
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	adds r1, r4, #0
	adds r1, #0x7d
	movs r0, #0x3c
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0
	bl sub_080276F4
	movs r0, #0x2e
	bl SoundReq
_08026504:
	adds r0, r4, #0
	bl sub_080277F8
	pop {r4, pc}
	.syntax divided

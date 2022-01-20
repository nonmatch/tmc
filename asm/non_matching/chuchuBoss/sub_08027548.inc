	.syntax unified
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	movs r5, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0xff
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0x90
	movs r2, #0xb0
	movs r3, #8
	bl sub_08027B98
	adds r0, r4, #0
	adds r0, #0x7d
	strb r5, [r0]
	adds r0, r4, #0
	movs r1, #0
	adds r2, r6, #0
	bl sub_080276F4
	add sp, #4
	pop {r4, r5, r6, pc}
	.align 2, 0
	.syntax divided

	.syntax unified
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #0x54]
	bl sub_08027C9C
	ldr r0, [r4, #0x68]
	adds r1, r5, #0
	bl sub_08027C9C
	ldr r0, [r4, #0x50]
	adds r1, r5, #0
	bl sub_08027C9C
	pop {r4, r5, pc}
	.align 2, 0
	.syntax divided

	.syntax unified
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x54]
	ldr r5, [r4, #0x68]
	ldr r6, [r4, #0x50]
	ldrb r2, [r1, #0xa]
	bl sub_080279AC
	ldrb r2, [r5, #0xa]
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080279AC
	ldrb r2, [r6, #0xa]
	adds r0, r4, #0
	adds r1, r6, #0
	bl sub_080279AC
	pop {r4, r5, r6, pc}
	.align 2, 0
	.syntax divided

	.syntax unified
	push {lr}
	ldr r2, _08026964 @ =gUnk_080CC26C
	adds r1, r0, #0
	adds r1, #0x84
	ldr r1, [r1]
	ldrb r1, [r1, #3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {pc}
	.align 2, 0
_08026964: .4byte gUnk_080CC26C
	.syntax divided

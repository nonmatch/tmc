	.syntax unified
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xf0
	movs r2, #8
	bl sub_080277B8
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #1
	beq _08026802
	movs r0, #0xff
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0xe0
	movs r2, #0xc0
	movs r3, #0x20
	bl sub_08027B98
	ldr r0, [r4, #0x54]
	movs r1, #2
	bl InitAnimationForceUpdate
_08026802:
	add sp, #4
	pop {r4, pc}
	.align 2, 0
	.syntax divided

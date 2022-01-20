	.syntax unified
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl sub_080279E8
	cmp r0, #0
	beq _08026942
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
_08026942:
	adds r0, r4, #0
	bl sub_080277F8
	add sp, #4
	pop {r4, pc}
	.syntax divided

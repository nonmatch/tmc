	.syntax unified
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xd0
	movs r2, #8
	bl sub_080277B8
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #6
	beq _080264D2
	ldr r0, [r4, #0x54]
	movs r1, #4
	bl InitAnimationForceUpdate
	adds r0, r4, #0
	bl sub_08027D20
_080264D2:
	pop {r4, pc}
	.syntax divided

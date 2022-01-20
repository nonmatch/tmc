	.syntax unified
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x54]
	adds r1, #0x83
	ldr r0, [r4, #0x50]
	adds r0, #0x83
	ldrb r1, [r1]
	ldrb r0, [r0]
	orrs r1, r0
	ldr r0, [r4, #0x68]
	adds r0, #0x83
	ldrb r0, [r0]
	orrs r1, r0
	cmp r1, #0
	bne _080267C6
	adds r2, r4, #0
	adds r2, #0x7d
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080267CC
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x80
	movs r3, #0x40
	bl sub_08027B98
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #3]
	ldr r0, [r4, #0x54]
	movs r1, #1
	bl InitAnimationForceUpdate
_080267C6:
	adds r0, r4, #0
	bl sub_080277F8
_080267CC:
	add sp, #4
	pop {r4, pc}
	.syntax divided

	.syntax unified
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x7c
	ldrb r1, [r5]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08026F70
	adds r0, r4, #0
	bl sub_080279E8
	cmp r0, #0
	beq _08026F68
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	movs r2, #0
	strb r2, [r0, #3]
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5]
	str r2, [sp]
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x80
	movs r3, #0x80
	bl sub_08027B98
	ldrb r0, [r5]
	cmp r0, #2
	bne _08026F68
	adds r0, r4, #0
	movs r1, #0
	bl sub_08027548
_08026F68:
	adds r0, r4, #0
	bl sub_080277F8
	b _08026FA0
_08026F70:
	adds r0, r4, #0
	movs r1, #0xf0
	movs r2, #0x10
	bl sub_080277B8
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #0
	beq _08026FA0
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r5]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0xc0
	movs r2, #0xc0
	movs r3, #0x20
	bl sub_08027B98
_08026FA0:
	add sp, #4
	pop {r4, r5, pc}
	.syntax divided

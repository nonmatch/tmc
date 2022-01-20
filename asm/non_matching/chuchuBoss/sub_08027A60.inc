	.syntax unified
	push {lr}
	adds r2, r0, #0
	adds r0, #0x7c
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08027A78
	ldr r0, [r2, #0x74]
	movs r1, #0x80
	lsls r1, r1, #7
	b _08027A7C
_08027A78:
	ldr r0, [r2, #0x74]
	ldr r1, _08027AA0 @ =0xFFFFC000
_08027A7C:
	adds r0, r0, r1
	str r0, [r2, #0x74]
	adds r3, r2, #0
	adds r3, #0x7c
	ldrb r0, [r3]
	adds r2, r0, #1
	strb r2, [r3]
	movs r0, #0x7f
	ands r0, r2
	cmp r0, #0x28
	bne _08027A9C
	movs r1, #0x80
	movs r0, #0x80
	ands r2, r0
	eors r2, r1
	strb r2, [r3]
_08027A9C:
	pop {pc}
	.align 2, 0
_08027AA0: .4byte 0xFFFFC000
	.syntax divided

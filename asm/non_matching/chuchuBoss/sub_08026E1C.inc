	.syntax unified
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	adds r6, r0, #0
	cmp r6, #0
	bne _08026EE0
	ldr r0, [r4, #0x54]
	ldrb r0, [r0, #0xf]
	ldr r1, [r4, #0x50]
	ldrb r1, [r1, #0xf]
	ldr r2, [r4, #0x68]
	adds r0, r0, r1
	ldrb r2, [r2, #0xf]
	adds r0, r0, r2
	cmp r0, #0xa
	ble _08026EF2
	ldrb r0, [r4, #0x10]
	movs r1, #0x80
	mov r8, r1
	movs r7, #0
	mov r1, r8
	orrs r0, r1
	strb r0, [r4, #0x10]
	adds r0, r4, #0
	bl sub_08027C54
	adds r5, r4, #0
	adds r5, #0x84
	cmp r0, #0
	beq _08026E72
	ldr r1, [r5]
	ldrb r0, [r1, #4]
	adds r0, #1
	strb r0, [r1, #4]
	ldr r0, [r4, #0x54]
	adds r0, #0x45
	movs r1, #0xff
	strb r1, [r0]
_08026E72:
	ldr r1, [r5]
	ldrb r0, [r1, #4]
	cmp r0, #3
	bne _08026EA0
	adds r0, r4, #0
	adds r0, #0x45
	strb r6, [r0]
	ldrb r0, [r4, #0x10]
	movs r1, #0x7f
	ands r1, r0
	strb r1, [r4, #0x10]
	ldr r3, [r4, #0x54]
	ldr r2, [r4, #0x50]
	ldr r0, [r4, #0x68]
	strb r1, [r0, #0x10]
	ldrb r0, [r4, #0x10]
	strb r0, [r2, #0x10]
	strb r0, [r3, #0x10]
	adds r1, r4, #0
	adds r1, #0x3d
	movs r0, #0xc4
	strb r0, [r1]
	b _08026F14
_08026EA0:
	movs r0, #4
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, #0x81
	strb r0, [r1, #1]
	ldrb r0, [r4, #0x10]
	mov r1, r8
	orrs r0, r1
	strb r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0x3f
	movs r0, #0x7d
	strb r0, [r1]
	movs r0, #0xb
	strb r0, [r4, #0xd]
	ldr r0, [r5]
	strb r6, [r0, #3]
	ldr r0, [r4, #0x54]
	movs r1, #0
	bl InitAnimationForceUpdate
	str r6, [sp]
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x80
	movs r3, #0x80
	bl sub_08027B98
	ldr r1, [r5]
	movs r0, #0x21
	strb r0, [r1, #1]
	b _08026EF2
_08026EE0:
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x84
	ldr r0, [r1]
	str r2, [r0, #8]
	ldr r0, [r1]
	strb r2, [r0, #6]
_08026EF2:
	adds r0, r4, #0
	bl sub_08027C54
	cmp r0, #0
	beq _08026F14
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #2
	bne _08026F14
	adds r0, r4, #0
	movs r1, #0x3f
	bl sub_08027C7C
	bl sub_08078B48
_08026F14:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.syntax divided

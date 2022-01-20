	.syntax unified
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08026474
	ldr r0, _08026478 @ =0x0000FF40
	strh r0, [r7, #0x36]
	ldr r6, [r7, #0x54]
	ldr r5, [r7, #0x50]
	ldr r4, [r7, #0x68]
	ldrb r2, [r4, #0x18]
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	movs r3, #1
	orrs r0, r3
	strb r0, [r4, #0x18]
	ldrb r2, [r5, #0x18]
	adds r0, r1, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5, #0x18]
	ldrb r2, [r6, #0x18]
	adds r0, r1, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r6, #0x18]
	ldrb r0, [r7, #0x18]
	ands r1, r0
	orrs r1, r3
	strb r1, [r7, #0x18]
	adds r0, r7, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	movs r0, #0xd1
	lsls r0, r0, #1
	bl SoundReq
_08026474:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08026478: .4byte 0x0000FF40
	.syntax divided

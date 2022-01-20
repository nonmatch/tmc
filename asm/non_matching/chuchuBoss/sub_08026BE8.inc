	.syntax unified
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x54]
	adds r3, r5, #0
	adds r3, #0x3b
	ldrb r1, [r3]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	adds r2, r0, #0
	cmp r2, #0
	bne _08026C34
	movs r0, #7
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	strb r2, [r0, #3]
	adds r1, #1
	movs r0, #0x2d
	strb r0, [r1]
	ldrb r1, [r5, #0x10]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r5, #0x10]
	ldrb r0, [r3]
	movs r1, #1
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _08026C30 @ =0x00000155
	bl SoundReq
	b _08026C38
	.align 2, 0
_08026C30: .4byte 0x00000155
_08026C34:
	subs r0, #1
	strb r0, [r1]
_08026C38:
	adds r0, r4, #0
	bl sub_08027870
	pop {r4, r5, pc}
	.syntax divided

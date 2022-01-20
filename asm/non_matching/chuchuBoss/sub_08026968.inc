	.syntax unified
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x7d
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0802698C
	adds r0, r2, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	b _080269C0
_0802698C:
	ldr r6, [r2, #0x54]
	ldr r4, [r2, #0x68]
	ldr r5, [r2, #0x50]
	ldrb r1, [r2, #0x15]
	movs r0, #0x10
	ands r0, r1
	ldr r3, _080269C8 @ =0xFFFFFF00
	cmp r0, #0
	beq _080269A2
	movs r3, #0x80
	lsls r3, r3, #1
_080269A2:
	adds r1, r4, #0
	adds r1, #0x82
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0x82
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, r6, #0
	adds r1, #0x82
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
_080269C0:
	adds r0, r2, #0
	bl sub_08027870
	pop {r4, r5, r6, pc}
	.align 2, 0
_080269C8: .4byte 0xFFFFFF00
	.syntax divided

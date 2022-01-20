	.syntax unified
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x7d
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xff
	bne _08026410
	ldr r2, _08026400 @ =gUnk_080CC234
	adds r3, r4, #0
	adds r3, #0x7c
	ldrb r0, [r3]
	adds r1, r0, #1
	strb r1, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r2
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0xff
	bne _08026404
	movs r0, #0x78
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	b _08026410
	.align 2, 0
_08026400: .4byte gUnk_080CC234
_08026404:
	ldrb r2, [r4, #0xb]
	adds r0, r4, #0
	movs r1, #0x49
	movs r3, #0
	bl CreateObjectWithParent
_08026410:
	pop {r4, r5, pc}
	.align 2, 0
	.syntax divided

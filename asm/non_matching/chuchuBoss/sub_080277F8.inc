	.syntax unified
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r3, [r6, #0x54]
	ldr r5, [r6, #0x68]
	ldr r4, [r6, #0x50]
	ldrh r2, [r6, #0x2e]
	strh r2, [r5, #0x2e]
	movs r7, #0xe
	strb r7, [r5, #0xe]
	ldrh r0, [r6, #0x32]
	subs r0, #0xe
	strh r0, [r5, #0x32]
	strh r2, [r4, #0x2e]
	movs r0, #0x7a
	adds r0, r0, r3
	mov ip, r0
	ldrh r1, [r0]
	subs r1, #0xa0
	asrs r1, r1, #4
	movs r0, #0x12
	subs r0, r0, r1
	strb r0, [r4, #0xe]
	ldrb r1, [r4, #0xe]
	ldrh r0, [r5, #0x32]
	subs r0, r0, r1
	strh r0, [r4, #0x32]
	strh r2, [r3, #0x2e]
	mov r1, ip
	ldrh r0, [r1]
	cmp r0, #0xa0
	bls _0802784E
	subs r0, #0xa0
	asrs r0, r0, #2
	movs r1, #0xe
	subs r1, r1, r0
	strb r1, [r3, #0xe]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08027850
	movs r0, #0
	strb r0, [r3, #0xe]
	b _08027850
_0802784E:
	strb r7, [r3, #0xe]
_08027850:
	ldrb r1, [r3, #0xe]
	ldrh r0, [r4, #0x32]
	subs r0, r0, r1
	strh r0, [r3, #0x32]
	ldr r0, [r3, #0x74]
	str r0, [r4, #0x74]
	ldr r0, [r3, #0x78]
	str r0, [r4, #0x78]
	ldr r0, [r3, #0x74]
	str r0, [r5, #0x74]
	ldr r0, [r3, #0x78]
	str r0, [r5, #0x78]
	adds r0, r6, #0
	bl sub_08027984
	pop {r4, r5, r6, r7, pc}
	.syntax divided

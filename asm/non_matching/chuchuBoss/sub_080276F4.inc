	.syntax unified
	push {r4, r5, r6, r7, lr}
	adds r6, r2, #0
	ldr r5, [r0, #0x54]
	ldr r4, [r0, #0x68]
	ldr r0, [r0, #0x50]
	mov ip, r0
	adds r0, #0x84
	movs r2, #0
	strb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x84
	strb r2, [r0]
	adds r0, r5, #0
	adds r0, #0x84
	strb r2, [r0]
	mov r0, ip
	adds r0, #0x7e
	movs r7, #0
	strh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x7e
	strh r2, [r0]
	adds r0, r5, #0
	adds r0, #0x7e
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x7d
	strb r7, [r0]
	adds r0, r4, #0
	adds r0, #0x7d
	strb r7, [r0]
	ldr r0, _080277AC @ =gUnk_080CC27C
	lsls r1, r1, #2
	adds r0, r1, r0
	ldrh r2, [r0]
	adds r3, r5, #0
	adds r3, #0x86
	strh r2, [r3]
	ldrb r0, [r0, #2]
	adds r2, r5, #0
	adds r2, #0x81
	strb r0, [r2]
	ldr r0, _080277B0 @ =gUnk_080CC2BC
	adds r0, r1, r0
	ldrh r2, [r0]
	adds r3, r4, #0
	adds r3, #0x86
	strh r2, [r3]
	ldrb r0, [r0, #2]
	adds r2, r4, #0
	adds r2, #0x81
	strb r0, [r2]
	ldr r0, _080277B4 @ =gUnk_080CC29C
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r2, ip
	adds r2, #0x86
	strh r0, [r2]
	ldrb r0, [r1, #2]
	mov r1, ip
	adds r1, #0x81
	strb r0, [r1]
	cmp r6, #0
	bne _080277AA
	mov r0, ip
	adds r0, #0x85
	strb r7, [r0]
	adds r0, r4, #0
	adds r0, #0x85
	strb r7, [r0]
	adds r0, r5, #0
	adds r0, #0x85
	strb r7, [r0]
	mov r0, ip
	adds r0, #0x82
	strh r6, [r0]
	adds r0, r4, #0
	adds r0, #0x82
	strh r6, [r0]
	adds r0, r5, #0
	adds r0, #0x82
	strh r6, [r0]
	ldrb r0, [r1]
	lsls r0, r0, #7
	ldrh r1, [r2]
	bl __divsi3
	adds r0, #1
	adds r1, r5, #0
	adds r1, #0x7d
	strb r0, [r1]
_080277AA:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_080277AC: .4byte gUnk_080CC27C
_080277B0: .4byte gUnk_080CC2BC
_080277B4: .4byte gUnk_080CC29C
	.syntax divided

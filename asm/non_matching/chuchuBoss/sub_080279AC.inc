	.syntax unified
	push {r4, r5, r6, lr}
	mov ip, r1
	movs r3, #4
	subs r3, r3, r2
	ldrh r1, [r1, #0x2e]
	ldrh r4, [r0, #0x2e]
	subs r1, r1, r4
	mov r6, ip
	adds r6, #0x62
	strb r1, [r6]
	mov r2, ip
	ldrh r1, [r2, #0x32]
	ldrh r2, [r0, #0x32]
	adds r0, r2, r3
	subs r1, r1, r0
	mov r5, ip
	adds r5, #0x63
	strb r1, [r5]
	mov r0, ip
	strh r4, [r0, #0x2e]
	adds r2, r2, r3
	strh r2, [r0, #0x32]
	ldr r1, [r0, #0x48]
	ldrb r0, [r6]
	strb r0, [r1]
	mov r2, ip
	ldr r1, [r2, #0x48]
	ldrb r0, [r5]
	strb r0, [r1, #1]
	pop {r4, r5, r6, pc}
	.syntax divided

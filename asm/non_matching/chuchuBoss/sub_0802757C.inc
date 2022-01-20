	.syntax unified
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x7d
	ldrb r1, [r6]
	cmp r1, #0
	beq _080275BA
	ldrb r0, [r5, #0xa]
	cmp r0, #1
	beq _080275AE
	ldr r0, [r5, #0x54]
	adds r0, #0x7d
	ldrb r0, [r0]
	movs r1, #0x83
	adds r1, r1, r5
	mov sl, r1
	cmp r0, #0
	beq _08027676
	movs r0, #0
	strb r0, [r6]
	b _08027676
_080275AE:
	subs r0, r1, #1
	strb r0, [r6]
	movs r2, #0x83
	adds r2, r2, r5
	mov sl, r2
	b _08027676
_080275BA:
	movs r0, #0x85
	adds r0, r0, r5
	mov ip, r0
	ldrb r1, [r0]
	mov sb, r1
	cmp r1, #1
	bne _0802761E
	adds r1, r5, #0
	adds r1, #0x82
	adds r0, r5, #0
	adds r0, #0x86
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x83
	adds r2, r5, #0
	adds r2, #0x81
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r3, #0
	ldrsb r3, [r2, r3]
	mov r8, r1
	mov sl, r0
	adds r7, r2, #0
	cmp r4, r3
	blt _08027676
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	ldrb r0, [r5, #0xa]
	cmp r0, #1
	bne _08027616
	ldr r1, [r5, #0x50]
	adds r0, r1, #0
	adds r0, #0x81
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, #0x86
	ldrh r1, [r1]
	bl __divsi3
	adds r0, #1
	strb r0, [r6]
	b _0802761A
_08027616:
	mov r2, sb
	strb r2, [r6]
_0802761A:
	ldrb r0, [r7]
	b _08027670
_0802761E:
	adds r2, r5, #0
	adds r2, #0x82
	adds r1, r5, #0
	adds r1, #0x86
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	adds r1, r5, #0
	adds r1, #0x83
	movs r4, #0
	ldrsb r4, [r1, r4]
	adds r0, r5, #0
	adds r0, #0x81
	ldrb r3, [r0]
	mov r8, r2
	mov sl, r1
	adds r7, r0, #0
	cmn r4, r3
	bgt _08027676
	movs r1, #1
	mov r2, ip
	strb r1, [r2]
	ldrb r0, [r5, #0xa]
	cmp r0, #1
	bne _0802766A
	ldr r1, [r5, #0x50]
	adds r0, r1, #0
	adds r0, #0x81
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, #0x86
	ldrh r1, [r1]
	bl __divsi3
	adds r0, #1
	strb r0, [r6]
	b _0802766C
_0802766A:
	strb r1, [r6]
_0802766C:
	ldrb r0, [r7]
	rsbs r0, r0, #0
_08027670:
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1]
_08027676:
	ldr r2, [r5, #0x50]
	adds r0, r2, #0
	adds r0, #0x63
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	ldr r0, [r2, #0x30]
	adds r0, r0, r1
	str r0, [r5, #0x30]
	adds r0, r2, #0
	adds r0, #0x62
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0x10
	ldr r0, [r2, #0x2c]
	adds r0, r0, r1
	str r0, [r5, #0x2c]
	ldrb r1, [r5, #0xe]
	lsls r1, r1, #8
	mov r0, sl
	ldrb r2, [r0]
	adds r0, r5, #0
	bl LinearMoveAngle
	ldrb r0, [r5, #0xa]
	cmp r0, #1
	beq _080276D2
	ldr r1, [r5, #0x54]
	ldr r0, [r5, #0x30]
	str r0, [r1, #0x30]
	ldr r1, [r5, #0x54]
	ldr r0, [r5, #0x2c]
	str r0, [r1, #0x2c]
	ldr r0, [r5, #0x54]
	ldrb r1, [r0, #0xe]
	lsls r1, r1, #8
	adds r2, r0, #0
	adds r2, #0x83
	ldrb r2, [r2]
	bl LinearMoveAngle
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x54]
	ldrb r2, [r1, #0xa]
	bl sub_080279AC
_080276D2:
	ldr r0, [r5, #0x68]
	ldrb r2, [r5, #0xa]
	adds r1, r5, #0
	bl sub_080279AC
	mov r1, sl
	ldrb r0, [r1]
	rsbs r0, r0, #0
	adds r1, r5, #0
	adds r1, #0x7f
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	.syntax divided

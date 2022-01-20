	.syntax unified
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x54]
	ldr r7, [r5, #0x68]
	ldr r6, [r5, #0x50]
	adds r2, r5, #0
	adds r2, #0x7d
	ldrb r0, [r2]
	cmp r0, #0
	beq _08026CCC
	subs r1, r0, #1
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _08026C9C
	movs r0, #8
	ands r1, r0
	cmp r1, #0
	beq _08026C82
	ldr r0, [r4, #0x74]
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r0, r1
	str r0, [r4, #0x74]
	ldr r0, [r4, #0x78]
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	str r0, [r4, #0x78]
	b _08026E12
_08026C82:
	ldr r0, [r4, #0x74]
	ldr r3, _08026C94 @ =0xFFFE0000
	adds r0, r0, r3
	str r0, [r4, #0x74]
	ldr r0, [r4, #0x78]
	ldr r1, _08026C98 @ =0xFFFF0000
	adds r0, r0, r1
	str r0, [r4, #0x78]
	b _08026E12
	.align 2, 0
_08026C94: .4byte 0xFFFE0000
_08026C98: .4byte 0xFFFF0000
_08026C9C:
	ldrb r1, [r5, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026CBA
	adds r0, r4, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #8
	beq _08026CCC
	adds r0, r4, #0
	movs r1, #8
	bl InitAnimationForceUpdate
	b _08026CCC
_08026CBA:
	adds r0, r4, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #7
	beq _08026CCC
	adds r0, r4, #0
	movs r1, #7
	bl InitAnimationForceUpdate
_08026CCC:
	adds r0, r5, #0
	adds r0, #0x7c
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _08026CF0
	ldrb r1, [r5, #0x15]
	movs r0, #0x10
	ands r0, r1
	ldr r2, _08026CEC @ =0xFFFFFD00
	cmp r0, #0
	beq _08026D00
	movs r2, #0xc0
	lsls r2, r2, #2
	b _08026D00
	.align 2, 0
_08026CEC: .4byte 0xFFFFFD00
_08026CF0:
	ldrb r1, [r5, #0x15]
	movs r0, #0x10
	ands r0, r1
	ldr r2, _08026D30 @ =0xFFFFFB80
	cmp r0, #0
	beq _08026D00
	movs r2, #0x90
	lsls r2, r2, #3
_08026D00:
	adds r0, r7, #0
	adds r0, #0x83
	ldrb r0, [r0]
	adds r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _08026D34
	adds r1, r7, #0
	adds r1, #0x82
	lsls r0, r2, #1
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, r6, #0
	adds r1, #0x82
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x82
	ldrh r0, [r1]
	b _08026D7E
	.align 2, 0
_08026D30: .4byte 0xFFFFFB80
_08026D34:
	adds r0, r7, #0
	adds r0, #0x82
	movs r1, #0
	strh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x83
	ldrb r0, [r0]
	adds r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _08026D60
	adds r1, r6, #0
	adds r1, #0x82
	lsls r0, r2, #1
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x82
	ldrh r0, [r1]
	b _08026D7E
_08026D60:
	adds r0, r6, #0
	adds r0, #0x82
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x83
	ldrb r0, [r0]
	adds r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _08026D84
	adds r1, r4, #0
	adds r1, #0x82
	lsls r0, r2, #1
	ldrh r2, [r1]
_08026D7E:
	adds r0, r0, r2
	strh r0, [r1]
	b _08026D8A
_08026D84:
	adds r0, r4, #0
	adds r0, #0x82
	strh r1, [r0]
_08026D8A:
	adds r1, r4, #0
	adds r1, #0x76
	ldrh r0, [r1]
	cmp r0, #0xa0
	bls _08026DA4
	ldr r0, [r4, #0x74]
	ldr r3, _08026DA0 @ =0xFFFC0000
	adds r0, r0, r3
	str r0, [r4, #0x74]
	b _08026DA8
	.align 2, 0
_08026DA0: .4byte 0xFFFC0000
_08026DA4:
	movs r0, #0xa0
	strh r0, [r1]
_08026DA8:
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	cmp r0, #0x9f
	bhi _08026DBE
	ldr r0, [r4, #0x78]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x78]
	b _08026E0C
_08026DBE:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0
	bl sub_080276F4
	adds r0, r4, #0
	adds r0, #0x7d
	movs r2, #0
	strb r2, [r0]
	ldrb r1, [r5, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026DEE
	adds r1, r6, #0
	adds r1, #0x85
	movs r0, #1
	strb r0, [r1]
	adds r1, r7, #0
	adds r1, #0x85
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x85
	strb r0, [r1]
_08026DEE:
	movs r0, #8
	strb r0, [r5, #0xd]
	movs r0, #4
	mov r3, r8
	strb r0, [r3]
	strb r2, [r6, #0xf]
	strb r2, [r7, #0xf]
	strb r2, [r4, #0xf]
	str r2, [sp]
	adds r0, r5, #0
	movs r1, #0x90
	movs r2, #0xb0
	movs r3, #0x10
	bl sub_08027B98
_08026E0C:
	adds r0, r5, #0
	bl sub_08027870
_08026E12:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	.syntax divided

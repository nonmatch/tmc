	.syntax unified
.ifdef EU
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r5, [r6, #0x54]
	ldr r0, [r6, #0x68]
	mov sl, r0
	ldr r1, [r6, #0x50]
	mov sb, r1
	ldrb r1, [r6, #0x15]
	movs r0, #0x10
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #2
	mov r8, r1
	cmp r0, #0
	beq _080269DC
	ldr r0, _080269FC @ =0xFFFFFD00
	mov r8, r0
_080269DC:
	mov r0, sl
	adds r0, #0x83
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x20
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bhi _08026A00
	mov r1, sl
	adds r1, #0x82
	ldrh r0, [r1]
	add r0, r8
	strh r0, [r1]
	b _08026A02
	.align 2, 0
_080269FC: .4byte 0xFFFFFD00
_08026A00:
	movs r7, #1
_08026A02:
	mov r0, sb
	adds r0, #0x83
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x44
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x87
	bhi _08026A20
	mov r1, sb
	adds r1, #0x82
	ldrh r0, [r1]
	add r0, r8
	strh r0, [r1]
	b _08026A22
_08026A20:
	adds r7, #1
_08026A22:
	adds r0, r5, #0
	adds r0, #0x83
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x40
	adds r0, #0x20
	cmp r0, #0x40
	bls _08026A62
	ldrb r1, [r6, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026A50
	adds r0, r5, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #6
	beq _08026A62
	adds r0, r5, #0
	movs r1, #6
	bl InitAnimationForceUpdate
	b _08026A62
_08026A50:
	adds r0, r5, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #5
	beq _08026A62
	adds r0, r5, #0
	movs r1, #5
	bl InitAnimationForceUpdate
_08026A62:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08026A74
	adds r1, r5, #0
	adds r1, #0x82
	ldrh r0, [r1]
	add r0, r8
	strh r0, [r1]
	b _08026A76
_08026A74:
	adds r7, #1
_08026A76:
	cmp r7, #3
	beq _08026A7C
	b _08026B98
_08026A7C:
	ldrb r1, [r6, #0x10]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r6, #0x10]
	ldrb r1, [r5, #0x10]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r5, #0x10]
	adds r1, r5, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	movs r0, #0x20
	movs r1, #0
	bl InitScreenShake
	ldr r0, _08026B24 @ =0x0000010B
	bl SoundReq
	adds r0, r6, #0
	movs r1, #0x15
	movs r2, #0
	movs r3, #0
	bl CreateObjectWithParent
	adds r4, r0, #0
	cmp r4, #0
	beq _08026B2E
	movs r0, #0xc9
	strh r0, [r4, #0x12]
	adds r0, r6, #0
	adds r0, #0x60
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x60
	strh r1, [r0]
	ldrb r1, [r6, #0x1a]
	lsls r1, r1, #0x1c
	lsrs r1, r1, #0x1c
	ldrb r2, [r4, #0x1a]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #0x1a]
	adds r1, r4, #0
	adds r1, #0x58
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #0x32]
	adds r0, #0x10
	strh r0, [r4, #0x32]
	adds r2, r4, #0
	adds r2, #0x29
	ldrb r1, [r2]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r2, [r5, #0x19]
	lsrs r2, r2, #6
	lsls r2, r2, #6
	ldrb r3, [r4, #0x19]
	movs r1, #0x3f
	adds r0, r1, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r4, #0x19]
	ldrb r0, [r5, #0x1b]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	ldrb r2, [r4, #0x1b]
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, #0x1b]
	ldrb r1, [r6, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026B28
	ldrh r0, [r4, #0x2e]
	subs r0, #0x38
	b _08026B2C
	.align 2, 0
_08026B24: .4byte 0x0000010B
_08026B28:
	ldrh r0, [r4, #0x2e]
	adds r0, #0x38
_08026B2C:
	strh r0, [r4, #0x2e]
_08026B2E:
	ldr r3, [r6, #0x50]
	ldr r2, [r6, #0x54]
	ldr r0, [r6, #0x68]
	adds r0, #0x84
	movs r1, #1
	strb r1, [r0]
	adds r2, #0x84
	strb r1, [r2]
	adds r3, #0x84
	strb r1, [r3]
	mov r0, sb
	adds r0, #0x7a
	movs r1, #0x98
	strh r1, [r0]
	mov r0, sl
	adds r0, #0x7a
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x7a
	strh r1, [r0]
	bl Random
	ldr r2, _08026B94 @ =gUnk_080CC278
	movs r1, #3
	ands r1, r0
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r7, r6, #0
	adds r7, #0x7c
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	adds r0, r5, #0
	movs r1, #0x49
	movs r2, #0xa
	movs r3, #0
	bl CreateObjectWithParent
	adds r4, r0, #0
	cmp r4, #0
	beq _08026BB4
	adds r1, r4, #0
	adds r1, #0x84
	ldrb r0, [r7]
	str r0, [r1]
	b _08026BB4
	.align 2, 0
_08026B94: .4byte gUnk_080CC278
_08026B98:
	adds r0, r5, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, #0xef
	bhi _08026BB4
	ldr r0, [r5, #0x74]
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r0, r1
	str r0, [r5, #0x74]
	ldr r0, [r5, #0x78]
	ldr r1, _08026BC4 @ =0xFFFF8000
	adds r0, r0, r1
	str r0, [r5, #0x78]
_08026BB4:
	adds r0, r6, #0
	bl sub_08027870
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08026BC4: .4byte 0xFFFF8000
.else
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r5, [r6, #0x54]
	ldr r0, [r6, #0x68]
	mov sl, r0
	ldr r1, [r6, #0x50]
	mov sb, r1
	ldrb r1, [r6, #0x15]
	movs r0, #0x10
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #2
	mov r8, r1
	cmp r0, #0
	beq _080269F8
	ldr r0, _08026A18 @ =0xFFFFFD00
	mov r8, r0
_080269F8:
	mov r0, sl
	adds r0, #0x83
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x20
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bhi _08026A1C
	mov r1, sl
	adds r1, #0x82
	ldrh r0, [r1]
	add r0, r8
	strh r0, [r1]
	b _08026A1E
	.align 2, 0
_08026A18: .4byte 0xFFFFFD00
_08026A1C:
	movs r7, #1
_08026A1E:
	mov r0, sb
	adds r0, #0x83
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x44
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x87
	bhi _08026A3C
	mov r1, sb
	adds r1, #0x82
	ldrh r0, [r1]
	add r0, r8
	strh r0, [r1]
	b _08026A3E
_08026A3C:
	adds r7, #1
_08026A3E:
	adds r0, r5, #0
	adds r0, #0x83
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x40
	adds r0, #0x20
	cmp r0, #0x40
	bls _08026A7E
	ldrb r1, [r6, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026A6C
	adds r0, r5, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #6
	beq _08026A7E
	adds r0, r5, #0
	movs r1, #6
	bl InitAnimationForceUpdate
	b _08026A7E
_08026A6C:
	adds r0, r5, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #5
	beq _08026A7E
	adds r0, r5, #0
	movs r1, #5
	bl InitAnimationForceUpdate
_08026A7E:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08026A90
	adds r1, r5, #0
	adds r1, #0x82
	ldrh r0, [r1]
	add r0, r8
	strh r0, [r1]
	b _08026A92
_08026A90:
	adds r7, #1
_08026A92:
	cmp r7, #3
	beq _08026A98
	b _08026BB8
_08026A98:
	ldrb r1, [r6, #0x10]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r6, #0x10]
	ldrb r1, [r5, #0x10]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r5, #0x10]
	adds r1, r5, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	movs r0, #0x20
	movs r1, #0
	bl InitScreenShake
	ldr r0, _08026B24 @ =0x0000010B
	bl SoundReq
	adds r0, r6, #0
	movs r1, #0x15
	movs r2, #0
	movs r3, #0
	bl CreateObjectWithParent
	adds r4, r0, #0
	cmp r4, #0
	beq _08026B4E
	movs r0, #0xc9
	strh r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0x58
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #0x32]
	adds r0, #0x10
	strh r0, [r4, #0x32]
	adds r2, r4, #0
	adds r2, #0x29
	ldrb r1, [r2]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r2, [r5, #0x19]
	lsrs r2, r2, #6
	lsls r2, r2, #6
	ldrb r3, [r4, #0x19]
	movs r1, #0x3f
	adds r0, r1, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r4, #0x19]
	ldrb r0, [r5, #0x1b]
	lsrs r0, r0, #6
	lsls r0, r0, #6
	ldrb r2, [r4, #0x1b]
	ands r1, r2
	orrs r1, r0
	strb r1, [r4, #0x1b]
	ldrb r1, [r6, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026B28
	ldrh r0, [r4, #0x2e]
	subs r0, #0x38
	b _08026B2C
	.align 2, 0
_08026B24: .4byte 0x0000010B
_08026B28:
	ldrh r0, [r4, #0x2e]
	adds r0, #0x38
_08026B2C:
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	movs r1, #0x3e
	bl LoadFixedGFX
	ldrb r0, [r6, #0xb]
	cmp r0, #0
	bne _08026B46
	adds r0, r4, #0
	movs r1, #0x2b
	bl LoadObjPalette
	b _08026B4E
_08026B46:
	adds r0, r4, #0
	movs r1, #0x2c
	bl LoadObjPalette
_08026B4E:
	ldr r3, [r6, #0x50]
	ldr r2, [r6, #0x54]
	ldr r0, [r6, #0x68]
	adds r0, #0x84
	movs r1, #1
	strb r1, [r0]
	adds r2, #0x84
	strb r1, [r2]
	adds r3, #0x84
	strb r1, [r3]
	mov r0, sb
	adds r0, #0x7a
	movs r1, #0x98
	strh r1, [r0]
	mov r0, sl
	adds r0, #0x7a
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x7a
	strh r1, [r0]
	bl Random
	ldr r2, _08026BB4 @ =gUnk_080CC278
	movs r1, #3
	ands r1, r0
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r7, r6, #0
	adds r7, #0x7c
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	adds r0, r5, #0
	movs r1, #0x49
	movs r2, #0xa
	movs r3, #0
	bl CreateObjectWithParent
	adds r4, r0, #0
	cmp r4, #0
	beq _08026BD4
	adds r1, r4, #0
	adds r1, #0x84
	ldrb r0, [r7]
	str r0, [r1]
	b _08026BD4
	.align 2, 0
_08026BB4: .4byte gUnk_080CC278
_08026BB8:
	adds r0, r5, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, #0xef
	bhi _08026BD4
	ldr r0, [r5, #0x74]
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r0, r1
	str r0, [r5, #0x74]
	ldr r0, [r5, #0x78]
	ldr r1, _08026BE4 @ =0xFFFF8000
	adds r0, r0, r1
	str r0, [r5, #0x78]
_08026BD4:
	adds r0, r6, #0
	bl sub_08027870
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08026BE4: .4byte 0xFFFF8000
.endif
	.syntax divided

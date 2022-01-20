	.syntax unified
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_08078B48
	ldrb r0, [r4, #0x10]
	movs r5, #0x7f
	adds r1, r5, #0
	ands r1, r0
	strb r1, [r4, #0x10]
	ldr r3, [r4, #0x54]
	ldr r2, [r4, #0x50]
	ldr r0, [r4, #0x68]
	strb r1, [r0, #0x10]
	ldrb r0, [r4, #0x10]
	strb r0, [r2, #0x10]
	strb r0, [r3, #0x10]
	adds r3, r4, #0
	adds r3, #0x7c
	ldrb r0, [r3]
	cmp r0, #0
	beq _08026FD2
	movs r0, #1
	strb r0, [r3]
_08026FD2:
	ldr r2, [r4, #0x54]
	adds r0, r2, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	cmp r0, #0x97
	bhi _08026FFE
	movs r1, #0x80
	lsls r1, r1, #9
	ldrb r0, [r3]
	lsls r1, r0
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
	ldr r2, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldrb r3, [r3]
	lsls r1, r3
	ldr r0, [r2, #0x74]
	subs r0, r0, r1
	str r0, [r2, #0x74]
	b _0802705C
_08026FFE:
	movs r0, #7
	strb r0, [r4, #0xd]
	ldrb r1, [r2, #0x10]
	adds r0, r5, #0
	ands r0, r1
	strb r0, [r2, #0x10]
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1, #3]
	adds r1, r4, #0
	adds r1, #0x7d
	movs r0, #0x2d
	strb r0, [r1]
	ldr r0, _08027044 @ =0x00000155
	bl SoundReq
	ldrb r1, [r4, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08027048
	ldr r1, [r4, #0x54]
	adds r0, r1, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #8
	beq _0802705C
	adds r0, r1, #0
	movs r1, #8
	bl InitAnimationForceUpdate
	b _0802705C
	.align 2, 0
_08027044: .4byte 0x00000155
_08027048:
	ldr r1, [r4, #0x54]
	adds r0, r1, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #7
	beq _0802705C
	adds r0, r1, #0
	movs r1, #7
	bl InitAnimationForceUpdate
_0802705C:
	adds r0, r4, #0
	bl sub_08027870
	pop {r4, r5, pc}
	.syntax divided

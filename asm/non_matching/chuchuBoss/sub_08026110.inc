	.syntax unified
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _08026144 @ =gUnk_080CC1DC
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r0, r6, #0
	adds r0, #0x84
	ldr r2, [r0]
	ldr r0, [r2, #8]
	cmp r0, #0
	bne _08026160
	ldrb r1, [r2, #5]
	cmp r1, #0
	beq _08026160
	ldrb r0, [r6, #0xd]
	cmp r0, #8
	bne _08026148
	adds r0, r1, #0
	subs r0, #0x40
	b _0802614C
	.align 2, 0
_08026144: .4byte gUnk_080CC1DC
_08026148:
	adds r0, r1, #0
	subs r0, #0x20
_0802614C:
	strb r0, [r2, #5]
	adds r0, r6, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #5
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08026160
	movs r0, #0
	strb r0, [r1, #5]
_08026160:
	adds r2, r6, #0
	adds r2, #0x80
	ldrb r0, [r2]
	movs r1, #0x76
	adds r1, r1, r6
	mov ip, r1
	adds r7, r6, #0
	adds r7, #0x7a
	cmp r0, #0
	beq _08026230
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _080261D2
	ldrb r1, [r2]
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x74]
	subs r0, r0, r1
	str r0, [r6, #0x74]
	ldrb r1, [r2]
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x78]
	subs r0, r0, r1
	str r0, [r6, #0x78]
	mov r0, ip
	ldrh r2, [r0]
	adds r4, r6, #0
	adds r4, #0x82
	ldrb r1, [r4]
	adds r3, r6, #0
	adds r3, #0x84
	ldr r0, [r3]
	ldrb r0, [r0, #5]
	adds r1, r1, r0
	cmp r2, r1
	bgt _080261AA
	mov r0, ip
	strh r1, [r0]
_080261AA:
	ldrh r2, [r7]
	ldrb r1, [r4]
	ldr r0, [r3]
	ldrb r0, [r0, #5]
	adds r1, r1, r0
	cmp r2, r1
	bgt _080261BA
	strh r1, [r7]
_080261BA:
	mov r1, ip
	ldrh r2, [r1]
	ldrb r1, [r4]
	ldr r0, [r3]
	ldrb r0, [r0, #5]
	adds r1, r1, r0
	cmp r2, r1
	bgt _08026230
	ldrh r0, [r7]
	cmp r0, r1
	bgt _08026230
	b _08026228
_080261D2:
	ldrb r1, [r2]
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x74]
	adds r0, r0, r1
	str r0, [r6, #0x74]
	ldrb r1, [r2]
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x78]
	adds r0, r0, r1
	str r0, [r6, #0x78]
	mov r0, ip
	ldrh r2, [r0]
	adds r4, r6, #0
	adds r4, #0x81
	ldrb r1, [r4]
	adds r3, r6, #0
	adds r3, #0x84
	ldr r0, [r3]
	ldrb r0, [r0, #5]
	adds r1, r1, r0
	cmp r2, r1
	blt _08026202
	mov r0, ip
	strh r1, [r0]
_08026202:
	ldrh r2, [r7]
	ldrb r1, [r4]
	ldr r0, [r3]
	ldrb r0, [r0, #5]
	adds r1, r1, r0
	cmp r2, r1
	blt _08026212
	strh r1, [r7]
_08026212:
	mov r1, ip
	ldrh r2, [r1]
	ldrb r1, [r4]
	ldr r0, [r3]
	ldrb r0, [r0, #5]
	adds r1, r1, r0
	cmp r2, r1
	blt _08026230
	ldrh r0, [r7]
	cmp r0, r1
	blt _08026230
_08026228:
	ldrb r0, [r6, #0xe]
	movs r1, #1
	eors r0, r1
	strb r0, [r6, #0xe]
_08026230:
	ldr r5, [r6, #0x48]
	mov r0, ip
	ldrh r1, [r0]
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r4, #0
	bl __divsi3
	lsls r1, r0, #3
	subs r1, r1, r0
	lsrs r1, r1, #7
	strb r1, [r5, #6]
	ldr r5, [r6, #0x48]
	ldrh r1, [r7]
	adds r0, r4, #0
	bl __divsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsrs r1, r1, #7
	strb r1, [r5, #7]
	movs r1, #0x36
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _08026268
	adds r0, r6, #0
	bl sub_0800445C
_08026268:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	.syntax divided

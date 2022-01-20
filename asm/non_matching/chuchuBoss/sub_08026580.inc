	.syntax unified
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl sub_08027AA4
	adds r7, r5, #0
	adds r7, #0x84
	ldr r0, [r7]
	ldrb r0, [r0, #1]
	cmp r0, #0x40
	bne _0802659C
	adds r0, r5, #0
	bl sub_08027BBC
	b _0802662C
_0802659C:
	adds r1, r5, #0
	adds r1, #0x7d
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r1, #0
	cmp r0, #0xff
	bne _08026626
	movs r0, #0
	strh r0, [r5, #0x24]
	movs r0, #2
	strb r0, [r5, #0xd]
	adds r4, r5, #0
	adds r4, #0x7c
	movs r0, #0x3c
	strb r0, [r4]
	ldr r1, _080265E4 @ =gPlayerEntity
	adds r0, r5, #0
	bl GetFacingDirection
	strb r0, [r5, #0x15]
	ldr r0, [r7]
	ldrb r0, [r0, #4]
	adds r2, r4, #0
	cmp r0, #2
	bne _080265E8
	adds r1, r5, #0
	adds r1, #0x80
	movs r0, #0x48
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #0x10
	b _080265EE
	.align 2, 0
_080265E4: .4byte gPlayerEntity
_080265E8:
	adds r1, r5, #0
	adds r1, #0x80
	movs r0, #0x10
_080265EE:
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x84
	ldr r0, [r4]
	ldrb r1, [r0, #1]
	movs r0, #0xa0
	ands r0, r1
	cmp r0, #0
	beq _08026608
	movs r0, #0
	strb r0, [r6]
	strb r0, [r2]
	b _08026626
_08026608:
	bl Random
	ldr r2, _08026630 @ =gUnk_080CC24F
	movs r1, #7
	ands r1, r0
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r1, r0, #1
	strb r1, [r6]
	ldr r0, [r4]
	ldrb r0, [r0, #4]
	cmp r0, #2
	bne _08026626
	lsls r0, r1, #1
	strb r0, [r6]
_08026626:
	adds r0, r5, #0
	bl sub_08027870
_0802662C:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08026630: .4byte gUnk_080CC24F
	.syntax divided

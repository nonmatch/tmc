	.syntax unified
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	ldrb r0, [r0, #0xd]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xd]
	cmp r0, #0xc
	bhi _080272CA
	lsls r0, r0, #2
	ldr r1, _08027228 @ =_0802722C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027228: .4byte _0802722C
_0802722C: @ jump table
	.4byte _080272C4 @ case 0
	.4byte _08027260 @ case 1
	.4byte _08027260 @ case 2
	.4byte _0802726E @ case 3
	.4byte _080272AA @ case 4
	.4byte _0802726E @ case 5
	.4byte _080272CA @ case 6
	.4byte _080272CA @ case 7
	.4byte _08027282 @ case 8
	.4byte _080272CA @ case 9
	.4byte _080272A0 @ case 10
	.4byte _080272CA @ case 11
	.4byte _08027260 @ case 12
_08027260:
	adds r1, r4, #0
	adds r1, #0x7a
	movs r0, #0xa0
	strh r0, [r1]
	subs r1, #4
	strh r0, [r1]
	b _080272AA
_0802726E:
	adds r0, r4, #0
	adds r0, #0x83
	ldrb r0, [r0]
	cmp r0, #0
	beq _080272CA
	adds r1, r4, #0
	adds r1, #0x7d
	movs r0, #0
	strb r0, [r1]
	b _080272AA
_08027282:
	ldrb r0, [r4, #0xf]
	cmp r0, #3
	bhi _080272CA
	adds r0, r4, #0
	bl sub_0802757C
	adds r0, r4, #0
	adds r0, #0x83
	ldrb r0, [r0]
	cmp r0, #0
	bne _080272CA
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _080272CA
_080272A0:
	adds r2, r4, #0
	adds r2, #0x7d
	ldrb r0, [r2]
	cmp r0, #0
	bne _080272B2
_080272AA:
	adds r0, r4, #0
	bl sub_0802757C
	b _080272CA
_080272B2:
	adds r1, r4, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #0
	beq _080272CA
	movs r0, #0
	strb r0, [r2]
	strb r0, [r1]
	b _080272CA
_080272C4:
	adds r0, r4, #0
	bl sub_0802757C
_080272CA:
	ldr r0, [r4, #0x50]
	ldr r0, [r0, #0x34]
	str r0, [r4, #0x34]
	pop {r4, pc}
	.align 2, 0
	.syntax divided

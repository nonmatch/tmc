	.syntax unified
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x54]
	ldr r7, [r4, #0x68]
	ldr r6, [r4, #0x50]
	adds r1, r2, #0
	adds r1, #0x76
	ldrh r0, [r1]
	cmp r0, #0xbf
	bhi _08026820
	adds r0, #4
	strh r0, [r1]
_08026820:
	adds r5, r2, #0
	adds r5, #0x7a
	ldrh r0, [r5]
	cmp r0, #0xb0
	bls _08026830
	subs r0, #8
	strh r0, [r5]
	b _08026860
_08026830:
	ldr r1, _08026868 @ =gPlayerEntity
	adds r0, r4, #0
	bl GetFacingDirection
	strb r0, [r4, #0x15]
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r1, #0xa0
	strh r1, [r5]
	adds r0, r6, #0
	adds r0, #0x7a
	strh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x7a
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl sub_080276F4
	movs r0, #0xd1
	lsls r0, r0, #1
	bl SoundReq
_08026860:
	adds r0, r4, #0
	bl sub_080277F8
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08026868: .4byte gPlayerEntity
	.syntax divided

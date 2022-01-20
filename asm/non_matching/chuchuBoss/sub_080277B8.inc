	.syntax unified
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, [r5, #0x54]
	adds r3, r1, #0
	adds r3, #0x7a
	ldrh r0, [r3]
	cmp r4, r0
	bls _080277DC
	adds r0, r0, r2
	strh r0, [r3]
	ldr r0, [r1, #0x74]
	ldr r2, _080277D8 @ =0xFFFE8000
	adds r0, r0, r2
	str r0, [r1, #0x74]
	b _080277F0
	.align 2, 0
_080277D8: .4byte 0xFFFE8000
_080277DC:
	strh r4, [r3]
	adds r1, #0x7c
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
_080277F0:
	adds r0, r5, #0
	bl sub_080277F8
	pop {r4, r5, pc}
	.syntax divided

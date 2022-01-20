	.syntax unified
	push {r4, lr}
	adds r4, r0, #0
	bl sub_08027AA4
	ldr r1, _080268E8 @ =gUnk_080CC264
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4, pc}
	.align 2, 0
_080268E8: .4byte gUnk_080CC264
	.syntax divided

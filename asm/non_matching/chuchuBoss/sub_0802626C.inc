	.syntax unified
	push {lr}
	ldr r2, _0802629C @ =gPauseMenuOptions
	movs r1, #1
	strb r1, [r2]
	ldr r2, _080262A0 @ =gUnk_080CC20C
	adds r1, r0, #0
	adds r1, #0x84
	ldr r1, [r1]
	ldrb r1, [r1, #3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	ldr r0, _080262A4 @ =gPlayerEntity
	ldrb r0, [r0, #0xc]
	cmp r0, #0x17
	beq _08026298
	cmp r0, #0xf
	beq _08026298
	bl sub_08078B48
_08026298:
	pop {pc}
	.align 2, 0
_0802629C: .4byte gPauseMenuOptions
_080262A0: .4byte gUnk_080CC20C
_080262A4: .4byte gPlayerEntity
	.syntax divided

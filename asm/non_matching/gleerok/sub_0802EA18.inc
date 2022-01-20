	.syntax unified
	push {lr}
	adds r3, r2, #0
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	subs r1, r1, r0
	ldr r0, _0802EA40 @ =0x00001FFF
	ands r1, r0
	lsls r3, r3, #8
	subs r2, r2, r3
	cmp r1, r2
	blo _0802EA44
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r3, r2
	cmp r1, r0
	bhi _0802EA44
	movs r0, #0
	b _0802EA46
	.align 2, 0
_0802EA40: .4byte 0x00001FFF
_0802EA44:
	movs r0, #1
_0802EA46:
	pop {pc}
	.syntax divided

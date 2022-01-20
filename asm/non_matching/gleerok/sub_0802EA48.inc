	.syntax unified
	push {r4, lr}
	adds r4, r0, #0
	cmp r3, #1
	bne _0802EA52
	rsbs r2, r2, #0
_0802EA52:
	lsls r0, r1, #2
	adds r0, r4, r0
	ldrh r1, [r0]
	adds r1, r1, r2
	ldr r3, _0802EA64 @ =0x00001FFF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0]
	pop {r4, pc}
	.align 2, 0
_0802EA64: .4byte 0x00001FFF
	.syntax divided

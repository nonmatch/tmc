	.syntax unified
	push {lr}
	adds r2, r0, #0
	ldr r0, _08026354 @ =gPlayerEntity
	ldrb r0, [r0, #0xc]
	cmp r0, #0x17
	beq _08026352
	adds r1, r2, #0
	adds r1, #0x7d
	movs r0, #0x78
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	movs r0, #0xa
	movs r1, #0
	movs r2, #0
	bl sub_08078AC0
_08026352:
	pop {pc}
	.align 2, 0
_08026354: .4byte gPlayerEntity
	.syntax divided

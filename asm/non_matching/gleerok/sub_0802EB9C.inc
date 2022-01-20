	.syntax unified
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0802EBBC @ =gUnk_080CD850
	bl GetRandomByWeight
	ldr r1, _0802EBC0 @ =gUnk_080CD854
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x74
	strb r1, [r0]
	adds r4, #0x75
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, pc}
	.align 2, 0
_0802EBBC: .4byte gUnk_080CD850
_0802EBC0: .4byte gUnk_080CD854
	.syntax divided

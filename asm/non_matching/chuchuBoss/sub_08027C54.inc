	.syntax unified
	push {lr}
	ldr r2, _08027C74 @ =gUnk_080CC2DC
	adds r1, r0, #0
	adds r1, #0x84
	ldr r1, [r1]
	ldrb r1, [r1, #4]
	adds r1, r1, r2
	ldr r0, [r0, #0x54]
	adds r0, #0x45
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhi _08027C78
	movs r0, #0
	b _08027C7A
	.align 2, 0
_08027C74: .4byte gUnk_080CC2DC
_08027C78:
	movs r0, #1
_08027C7A:
	pop {pc}
	.syntax divided

	.syntax unified
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	bl GravityUpdate
	cmp r0, #0
	bne _080264A6
	movs r0, #0x10
	movs r1, #0
	bl InitScreenShake
	ldr r0, _080264A8 @ =0x000001A1
	bl SoundReq
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
_080264A6:
	pop {r4, pc}
	.align 2, 0
_080264A8: .4byte 0x000001A1
	.syntax divided

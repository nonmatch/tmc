	.syntax unified
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	bl GravityUpdate
	adds r5, r0, #0
	cmp r5, #0
	beq _08026888
	adds r0, r4, #0
	bl ProcessMovement0
	b _080268BE
_08026888:
	movs r0, #0x10
	movs r1, #0
	bl InitScreenShake
	movs r0, #5
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0x84
	ldr r0, [r0]
	strb r5, [r0, #3]
	str r5, [sp]
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x80
	movs r3, #0x80
	bl sub_08027B98
	adds r0, r4, #0
	bl sub_08027870
	ldr r0, [r4, #0x54]
	movs r1, #3
	bl InitAnimationForceUpdate
	ldr r0, _080268C4 @ =0x000001A1
	bl SoundReq
_080268BE:
	add sp, #4
	pop {r4, r5, pc}
	.align 2, 0
_080268C4: .4byte 0x000001A1
	.syntax divided

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_0800857C
sub_0800857C: @ 0x0800857C
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	ldrb r1, [r0, #0xb]
	lsrs r1, r1, #8
	bhs _0800859C
	ldr r1, _08008888 @ =gPlayerState
	ldrb r1, [r1, #2]
	movs r2, #0x80
	ands r1, r2
	bne _0800859C
	bl sub_080085CC
_0800859C:
	ldrh r1, [r0, #0x24]
	ldrb r2, [r0, #0x15]
	bl sub_080027EA
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov sb, r5
	mov sl, r6
	mov fp, r7
	pop {r4, r5, r6, r7, pc}

	thumb_func_start sub_080085B0
sub_080085B0: @ 0x080085B0
	push {r3, r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	bl sub_080085CC
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov sb, r5
	mov sl, r6
	mov fp, r7
	pop {r3, r4, r5, r6, r7, pc}

	thumb_func_start sub_080085CC
sub_080085CC: @ 0x080085CC
	push {lr}
	ldr r2, _0800888C @ =gPlayerState
	ldr r1, _08008890 @ =gUnk_080083FC
	movs r3, #0x26
	ldrb r3, [r2, r3]
	orrs r3, r3
	beq _080085E6
	ldr r2, [r2, #0x30]
	movs r3, #0x80
	ands r2, r3
	beq _0800861A
	ldr r1, _08008894 @ =gUnk_0800839C
	b _0800861A
_080085E6:
	ldr r1, _08008898 @ =gUnk_0800845C
	ldrb r3, [r2, #2]
	orrs r3, r3
	bne _0800861A
	ldr r2, [r2, #0x30]
	ldr r3, _0800889C @ =0x01000000
	tst r2, r3
	bne _0800861A
	movs r3, #0x80
	ldr r1, _080088A0 @ =gUnk_0800833C
	ands r2, r3
	bne _0800861A
	ldr r1, _080088A4 @ =gUnk_080084BC
	ldr r3, _080088A8 @ =gPlayerState
	ldrb r2, [r3, #0x1c]
	orrs r2, r2
	bne _0800861A
	ldrb r2, [r3, #5]
	orrs r2, r2
	bne _0800861A
	ldr r1, _080088AC @ =gUnk_0800851C
	movs r2, #0xaa
	ldrb r2, [r3, r2]
	orrs r2, r2
	bne _0800861A
	ldr r1, _080088B0 @ =gUnk_080082DC
_0800861A:
	mov fp, r1
	movs r7, #0
	mov r8, r0
	movs r2, #0x2e
	ldrh r3, [r0, r2]
	movs r2, #0x32
	ldrh r4, [r0, r2]
	movs r2, #0x48
	ldr r5, [r0, r2]
	ldr r1, _080088B4 @ =gRoomControls + 6
	ldrh r1, [r1]
	subs r3, r3, r1
	ldr r1, _080088B8 @ =gRoomControls + 8
	ldrh r1, [r1]
	subs r4, r4, r1
	eors r2, r2
	ldrsb r0, [r5, r2]
	adds r0, r0, r3
	movs r2, #1
	ldrsb r1, [r5, r2]
	adds r1, r1, r4
	push {r0, r1}
	ldrb r2, [r5, #2]
	adds r0, r0, r2
	ldrb r4, [r5, #3]
	movs r6, #2
	mov sl, r1
_08008650:
	lsls r7, r7, #1
	lsls r7, r7, #1
	adds r1, r1, r4
	bl sub_080086D8
	orrs r7, r2
	lsls r7, r7, #1
	mov r1, sl
	subs r1, r1, r4
	bl sub_080086D8
	orrs r7, r2
	lsls r7, r7, #1
	subs r6, #1
	beq _08008678
	mov r1, sl
	ldrb r3, [r5, #2]
	subs r0, r0, r3
	subs r0, r0, r3
	b _08008650
_08008678:
	pop {r0, r1}
	ldrb r2, [r5, #5]
	adds r1, r1, r2
	ldrb r4, [r5, #4]
	movs r6, #2
	mov sb, r0
_08008684:
	lsls r7, r7, #1
	lsls r7, r7, #1
	adds r0, r0, r4
	bl sub_080086D8
	orrs r7, r2
	lsls r7, r7, #1
	mov r0, sb
	subs r0, r0, r4
	bl sub_080086D8
	orrs r7, r2
	lsls r7, r7, #1
	subs r6, #1
	beq _080086AC
	mov r0, sb
	ldrb r3, [r5, #5]
	subs r1, r1, r3
	subs r1, r1, r3
	b _08008684
_080086AC:
	mov r0, r8
	movs r2, #0x2a
	strh r7, [r0, r2]
	pop {pc}

	thumb_func_start sub_080086B4
sub_080086B4: @ 0x080086B4
	push {r3, r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	mov fp, r2
	ldr r2, _080088BC @ =gPlayerEntity
	mov r8, r2
	bl sub_080086D8
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov sb, r5
	mov sl, r6
	mov fp, r7
	adds r0, r2, #0
	pop {r3, r4, r5, r6, r7, pc}

	thumb_func_start sub_080086D8
sub_080086D8: @ 0x080086D8
	push {r0, r1, lr}
	ldr r2, _080088C0 @ =0x000003F0
	ands r0, r2
	ands r1, r2
	lsrs r0, r0, #4
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, r8
	movs r3, #0x38
	ldrb r3, [r2, r3]
	lsls r3, r3, #2
	ldr r1, _080088C4 @ =gUnk_08000248
	ldr r1, [r1, r3]
	ldrb r2, [r0, r1]
	push {r2}
	mov r0, r8
	ldr r1, _080088C8 @ =gPlayerState
	movs r2, #0x26
	ldrb r2, [r1, r2]
	cmp r2, #0
	beq _08008716
	movs r2, #0x12
	ldrb r2, [r1, r2]
	cmp r2, #0x18
	beq _08008716
	pop {r2}
	pop {r0, r1}
	cmp r2, #0x10
	bhs _0800872E
	movs r2, #0xf
	b _0800871E
_08008716:
	pop {r2}
	pop {r0, r1}
	cmp r2, #0x10
	bhs _0800872E
_0800871E:
	movs r3, #8
	tst r1, r3
	bne _08008726
	lsrs r2, r2, #2
_08008726:
	tst r0, r3
	bne _08008754
	lsrs r2, r2, #1
	b _08008754
_0800872E:
	cmp r2, #0xff
	beq _08008754
	push {r4}
	subs r2, #0x10
	mov r3, fp
	ldrb r2, [r2, r3]
	lsls r2, r2, #2
	ldr r3, _080088CC @ =gUnk_0800823C
	ldr r3, [r3, r2]
	movs r4, #0xf
	ands r4, r1
	lsls r4, r4, #1
	ldrh r2, [r3, r4]
	movs r3, #0xf
	adds r4, r3, #0
	ands r3, r0
	eors r4, r3
	lsrs r2, r4
	pop {r4}
_08008754:
	movs r3, #1
	ands r2, r3
	pop {pc}

	non_word_aligned_thumb_func_start sub_0800875A
sub_0800875A: @ 0x0800875A
	push {r2, r4, lr}
	ldrb r3, [r0, #0x14]
	movs r2, #6
	ands r3, r2
	ldr r4, _080088D0 @ =gUnk_08007DF4
	ldrsb r2, [r4, r3]
	adds r3, #1
	ldrsb r3, [r4, r3]
	bl sub_08008782
	pop {r2, r4}
	cmp r0, #0
	beq _08008780
	ldrb r1, [r0, #2]
	strb r1, [r2, #3]
	ldrb r1, [r0, #3]
	strb r1, [r2, #7]
	ldrb r1, [r0, #5]
	strb r1, [r2, #8]
_08008780:
	pop {pc}

	non_word_aligned_thumb_func_start sub_08008782
sub_08008782: @ 0x08008782
	push {r4}
	ldrh r4, [r0, #0x2e]
	adds r2, r2, r4
	ldrh r4, [r0, #0x32]
	adds r3, r3, r4
	pop {r4}
	b sub_08008796

	thumb_func_start sub_08008790
sub_08008790: @ 0x08008790
	ldrh r2, [r0, #0x2e]
	ldrh r3, [r0, #0x32]
	b sub_08008796

	non_word_aligned_thumb_func_start sub_08008796
sub_08008796: @ 0x08008796
	push {r4, r5, r6, r7, lr}
	push {r2, r3}
	ldr r2, _080088D4 @ =gRoomControls
	ldrh r3, [r2]
	movs r2, #1
	cmp r2, r3
	pop {r2, r3}
	beq _080087CE
	push {r0, r1, r2, r3}
	pop {r4, r5, r6, r7}
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	ldrb r2, [r4, r2]
	bl GetTileTypeByPos
	ldr r1, _080088D8 @ =gUnk_080046A4
	bl sub_08007DE0
	beq _080087CE
	lsls r1, r3, #3
	adds r3, r5, #0
	ldr r0, _080088DC @ =gUnk_080047F6
	adds r5, r0, r1
	ldrh r0, [r5]
	lsrs r0, r3
	lsrs r0, r0, #1
	bhs _080087D2
_080087CE:
	movs r0, #0
	pop {r4, r5, r6, r7, pc}
_080087D2:
	ldrb r0, [r5, #2]
	ldrb r1, [r5, #3]
	cmp r0, #0xff
	beq _0800883A
	cmp r3, #6
	beq _0800883A
	cmp r3, #0xe
	beq _0800883A
	cmp r3, #0xa
	beq _0800883A
	cmp r3, #0xb
	beq _0800883A
	cmp r3, #0xd
	bne _080087F6
	cmp r0, #0xf
	bne _0800883A
	cmp r1, #0x17
	bne _0800883A
_080087F6:
	movs r2, #0
	cmp r0, #0xf
	bne _080087FE
	movs r2, #0x80
_080087FE:
	bl CreateObject
	cmp r0, #0
	beq _0800883A
	ldrb r1, [r5, #2]
	cmp r1, #0
	beq _08008820
	movs r2, #0xf
	adds r1, r6, #0
	bics r1, r2
	adds r1, #8
	strh r1, [r0, #0x2e]
	adds r1, r7, #0
	bics r1, r2
	adds r1, #8
	strh r1, [r0, #0x32]
	b _0800882C
_08008820:
	ldrh r1, [r4, #0x2e]
	strh r1, [r0, #0x2e]
	ldrh r1, [r4, #0x32]
	strh r1, [r0, #0x32]
	ldrh r1, [r4, #0x36]
	strh r1, [r1, #0x36]
_0800882C:
	movs r3, #0x50
	str r4, [r1, r3]
	movs r3, #0x38
	ldrb r1, [r4, r3]
	strb r1, [r0, r3]
	bl UpdateSpriteForCollisionLayer
_0800883A:
	ldr r1, _080088E0 @ =gRoomControls
	ldrh r0, [r1, #6]
	subs r2, r6, r0
	lsrs r2, r2, #4
	ldrh r0, [r1, #8]
	subs r3, r7, r0
	lsrs r3, r3, #4
	lsls r3, r3, #6
	adds r1, r2, r3
	movs r3, #0x38
	ldrb r2, [r4, r3]
	ldrh r0, [r5, #6]
	ldr r3, _080088E4 @ =0x00004000
	tst r0, r3
	beq _08008870
	ldr r3, _080088E8 @ =0x0000FFFF
	cmp r0, r3
	beq _08008876
	push {r0, r1}
	adds r0, r2, #0
	bl GetLayerByIndex
	adds r3, r0, #4
	pop {r0, r1}
	lsls r1, r1, #1
	strh r0, [r3, r1]
	b _0800887E
_08008870:
	bl sub_0807B7D8
	b _0800887E
_08008876:
	adds r0, r1, #0
	adds r1, r2, #0
	bl sub_0807BA8C
_0800887E:
	ldrb r1, [r5, #2]
	ldrb r2, [r5, #3]
	adds r0, r5, #0
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08008888: .4byte gPlayerState
_0800888C: .4byte gPlayerState
_08008890: .4byte gUnk_080083FC
_08008894: .4byte gUnk_0800839C
_08008898: .4byte gUnk_0800845C
_0800889C: .4byte 0x01000000
_080088A0: .4byte gUnk_0800833C
_080088A4: .4byte gUnk_080084BC
_080088A8: .4byte gPlayerState
_080088AC: .4byte gUnk_0800851C
_080088B0: .4byte gUnk_080082DC
_080088B4: .4byte gRoomControls + 6
_080088B8: .4byte gRoomControls + 8
_080088BC: .4byte gPlayerEntity
_080088C0: .4byte 0x000003F0
_080088C4: .4byte gUnk_08000248
_080088C8: .4byte gPlayerState
_080088CC: .4byte gUnk_0800823C
_080088D0: .4byte gUnk_08007DF4
_080088D4: .4byte gRoomControls
_080088D8: .4byte gUnk_080046A4
_080088DC: .4byte gUnk_080047F6
_080088E0: .4byte gRoomControls
_080088E4: .4byte 0x00004000
_080088E8: .4byte 0x0000FFFF
_080088EC:
	.byte 0x00, 0xFD, 0x03, 0xFD
	.byte 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0xFD, 0x03, 0xFD, 0x00, 0xFD, 0xFD
_080088FC:
	.byte 0x00, 0xF6, 0x0A, 0xF6
	.byte 0x0A, 0x00, 0x0A, 0x0A, 0x00, 0x0A, 0xF6, 0x0A, 0xF6, 0x00, 0xF6, 0xF6
_0800890C:
	.byte 0x00, 0x06, 0xFA, 0x00
	.byte 0x00, 0xFA, 0x06, 0x00, 0x13, 0x12, 0x12, 0x10, 0x10, 0x11, 0x11, 0x13
_0800891C:
	push {r0}
	bl ResetPlayerVelocity
	pop {r0}
_08008924:
	pop {pc}

	non_word_aligned_thumb_func_start sub_08008926
sub_08008926: @ 0x08008926
	push {r4, r5, r6, lr}
	bl sub_08008942
	pop {r4, r5, r6, pc}

	non_word_aligned_thumb_func_start sub_0800892E
sub_0800892E: @ 0x0800892E
	push {r4, r5, r6, lr}
	bl sub_08008936
	pop {r4, r5, r6, pc}

	non_word_aligned_thumb_func_start sub_08008936
sub_08008936: @ 0x08008936
	push {lr}
	ldrb r2, [r0, #0x14]
	lsrs r2, r2, #1
	lsls r2, r2, #3
	ldr r1, _08008A68 @ =gPlayerState
	b _08008960

	non_word_aligned_thumb_func_start sub_08008942
sub_08008942: @ 0x08008942
	push {lr}
	ldr r1, _08008A6C @ =gPlayerState
	ldrb r2, [r1, #7]
	ldrb r3, [r1, #0xa]
	orrs r2, r3
	bne _08008924
	ldrb r2, [r1, #0xd]
	b _08008956
_08008952:
	push {lr}
	ldr r1, _08008A70 @ =gPlayerState
_08008956:
	movs r3, #0x15
	strb r2, [r0, r3]
	movs r3, #0x80
	tst r2, r3
	bne _080089C0
_08008960:
	ldrb r3, [r1, #5]
	cmp r3, #2
	beq _0800891C
	cmp r3, #1
	beq _0800891C
	ldr r4, _08008A74 @ =_080088FC
	ldrb r3, [r1, #2]
	adds r1, r2, #0
	orrs r3, r3
	beq _08008992
	push {r2}
	movs r3, #0x14
	ldrb r1, [r0, r3]
	lsrs r1, r1, #1
	lsls r1, r1, #1
	lsrs r2, r2, #2
	subs r2, r2, r1
	pop {r1}
	adds r2, #2
	movs r4, #7
	ands r2, r4
	ldr r4, _08008A78 @ =_080088EC
	cmp r2, #4
	beq _08008992
	bhs _080089A8
_08008992:
	adds r3, r1, #0
	lsrs r3, r3, #2
	lsls r3, r3, #1
	adds r4, r4, r3
	movs r3, #0
	ldrsb r2, [r4, r3]
	adds r3, #1
	ldrsb r3, [r4, r3]
	bl sub_08008A46
	b _080089C0
_080089A8:
	movs r3, #0x14
	ldrb r3, [r0, r3]
	lsrs r3, r3, #1
	lsls r3, r3, #1
	ldr r4, _08008A7C @ =_0800890C
	adds r4, r4, r3
	movs r3, #0
	ldrsb r2, [r4, r3]
	adds r3, #1
	ldrsb r3, [r4, r3]
	bl sub_08008A46
_080089C0:
	ldr r1, _08008A80 @ =gPlayerState
	movs r4, #0x8c
	movs r2, #8
	ldrsh r3, [r1, r4]
	orrs r3, r3
	beq _080089E4
	bpl _080089D2
	movs r2, #0x18
	rsbs r3, r3, #0
_080089D2:
	push {r0, r1}
	adds r1, r3, #0
	push {r2}
	bl sub_080027EA
	pop {r0}
	bl sub_0807A5B8
	pop {r0, r1}
_080089E4:
	movs r4, #0x8e
	movs r2, #0x10
	ldrsh r3, [r1, r4]
	orrs r3, r3
	beq _08008A06
	bpl _080089F4
	movs r2, #0
	rsbs r3, r3, #0
_080089F4:
	push {r0, r1}
	adds r1, r3, #0
	push {r2}
	bl sub_080027EA
	pop {r0}
	bl sub_0807A5B8
	pop {r0, r1}
_08008A06:
	ldrb r2, [r1, #2]
	orrs r2, r2
	bne _08008A18
	movs r2, #0x8c
	bl sub_08008A1A
	movs r2, #0x8e
	bl sub_08008A1A
_08008A18:
	pop {pc}

	non_word_aligned_thumb_func_start sub_08008A1A
sub_08008A1A: @ 0x08008A1A
	ldrb r3, [r1, #2]
	movs r4, #3
	orrs r3, r3
	bne _08008A2C
	movs r3, #0x26
	ldrb r3, [r1, r3]
	orrs r3, r3
	bne _08008A2C
	movs r4, #3
_08008A2C:
	ldrsh r3, [r1, r2]
	orrs r3, r3
	bmi _08008A3E
	subs r3, r3, r4
	bpl _08008A3A
	beq _08008A3A
_08008A38:
	eors r3, r3
_08008A3A:
	strh r3, [r1, r2]
	mov pc, lr
_08008A3E:
	adds r3, r3, r4
	bmi _08008A3A
	beq _08008A3A
	b _08008A38

	non_word_aligned_thumb_func_start sub_08008A46
sub_08008A46: @ 0x08008A46
	push {lr}
	ldr r1, _08008A84 @ =gPlayerState
	movs r4, #0x8c
	ldrsh r5, [r1, r4]
	adds r5, r5, r2
	bl sub_08008A88
	movs r4, #0x8e
	ldrsh r5, [r1, r4]
	adds r5, r5, r3
	bl sub_08008A88
	pop {pc}
_08008A60:
	eors r3, r3
	strh r3, [r1]
	pop {pc}
	.align 2, 0
_08008A68: .4byte gPlayerState
_08008A6C: .4byte gPlayerState
_08008A70: .4byte gPlayerState
_08008A74: .4byte _080088FC
_08008A78: .4byte _080088EC
_08008A7C: .4byte _0800890C
_08008A80: .4byte gPlayerState
_08008A84: .4byte gPlayerState

	thumb_func_start sub_08008A88
sub_08008A88: @ 0x08008A88
	orrs r5, r5
	bmi _08008A94
	ldr r6, _08008B38 @ =0x00000180
	cmp r5, r6
	blo _08008A9C
	b _08008A9A
_08008A94:
	ldr r6, _08008B3C @ =0xFFFFFE80
	cmp r5, r6
	bhs _08008A9C
_08008A9A:
	adds r5, r6, #0
_08008A9C:
	strh r5, [r1, r4]
	mov pc, lr

	thumb_func_start sub_08008AA0
sub_08008AA0: @ 0x08008AA0
	push {r4, r5, lr}
	ldr r1, _08008B40 @ =gPlayerState
	ldrb r2, [r1, #0x12]
	cmp r2, #1
	beq _08008AC4
	ldrb r2, [r1, #0xd]
	cmp r2, #0xff
	beq _08008AC4
	lsls r2, r2, #4
	ldr r3, _08008B44 @ =gSineTable
	ldrsh r4, [r3, r2]
	adds r3, #0x80
	ldrsh r5, [r3, r2]
	rsbs r5, r5, #0
	movs r2, #0x8c
	strh r4, [r1, r2]
	movs r2, #0x8e
	strh r5, [r1, r2]
_08008AC4:
	pop {r4, r5, pc}

	non_word_aligned_thumb_func_start sub_08008AC6
sub_08008AC6: @ 0x08008AC6
	push {r0, lr}
	ldr r1, _08008B48 @ =gPlayerState
	movs r3, #0x26
	ldrb r2, [r1, r3]
	movs r3, #0xf
	ands r2, r3
	bne _08008AEC
	ldr r2, [r1, #0x30]
	ldr r3, _08008B4C @ =gUnk_02000020
	ands r2, r3
	bne _08008AEC
	bl sub_08008AEE
	beq _08008AEC
	movs r3, #0xe2
	movs r2, #0x3d
	strb r3, [r0, r2]
	bl RespawnPlayer
_08008AEC:
	pop {r0, pc}

	non_word_aligned_thumb_func_start sub_08008AEE
sub_08008AEE: @ 0x08008AEE
	ldrh r2, [r0, #0x2a]
	movs r3, #0xe
	movs r1, #4
_08008AF4:
	tst r2, r3
	beq _08008B00
	lsrs r2, r2, #4
	subs r1, #1
	bne _08008AF4
	movs r2, #1
_08008B00:
	bx lr

	non_word_aligned_thumb_func_start sub_08008B02
sub_08008B02: @ 0x08008B02
	push {r0, r1, lr}
	movs r1, #0
	movs r2, #0
	bl sub_080002B4
	ldr r1, _08008B50 @ =0x00004000
	tst r0, r1
	bne _08008B1E
	ldr r1, _08008B54 @ =gUnk_08007CAC
	bl sub_08007DE0
	movs r2, #1
	cmp r3, #1
	beq _08008B20
_08008B1E:
	movs r2, #0
_08008B20:
	pop {r0, r1, pc}

	non_word_aligned_thumb_func_start sub_08008B22
sub_08008B22: @ 0x08008B22
	push {lr}
	ldr r0, _08008B58 @ =gPlayerEntity
	bl sub_08008B02
	adds r0, r2, #0
	pop {pc}

	non_word_aligned_thumb_func_start sub_08008B2E
sub_08008B2E: @ 0x08008B2E
	push {r0, lr}
	adds r0, r2, #0
	bl EnqueueSFX
	pop {r0, pc}
	.align 2, 0
_08008B38: .4byte 0x00000180
_08008B3C: .4byte 0xFFFFFE80
_08008B40: .4byte gPlayerState
_08008B44: .4byte gSineTable
_08008B48: .4byte gPlayerState
_08008B4C: .4byte gUnk_02000020
_08008B50: .4byte 0x00004000
_08008B54: .4byte gUnk_08007CAC
_08008B58: .4byte gPlayerEntity




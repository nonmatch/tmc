	.syntax unified
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r6, [r5, #0x54]
	ldr r0, [r5, #0x68]
	mov sb, r0
	ldr r1, [r5, #0x50]
	mov r8, r1
	movs r0, #0x60
	strh r0, [r5, #0x24]
	adds r0, r6, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _08027098
	ldr r0, _080270C8 @ =gRoomTransition
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08027098
	movs r0, #0x7c
	bl SoundReq
_08027098:
	adds r0, r5, #0
	adds r0, #0x84
	ldr r3, [r0]
	ldrb r1, [r3, #3]
	adds r7, r0, #0
	cmp r1, #0
	beq _080270E0
	ldr r0, _080270CC @ =gPlayerEntity
	movs r2, #0x32
	ldrsh r4, [r5, r2]
	movs r1, #0x32
	ldrsh r2, [r0, r1]
	cmp r4, r2
	beq _080270E0
	ldr r0, _080270C8 @ =gRoomTransition
	ldr r1, [r0]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	bne _080270D4
	cmp r4, r2
	ble _080270D0
	strb r1, [r3, #0xc]
	b _080270D4
	.align 2, 0
_080270C8: .4byte gRoomTransition
_080270CC: .4byte gPlayerEntity
_080270D0:
	movs r0, #0x10
	strb r0, [r3, #0xc]
_080270D4:
	ldr r0, [r7]
	ldrb r0, [r0, #0xc]
	strb r0, [r5, #0x15]
	adds r0, r5, #0
	bl ProcessMovement0
_080270E0:
	adds r0, r6, #0
	adds r0, #0x85
	ldrb r0, [r0]
	cmp r0, #1
	bne _080270FC
	adds r0, r6, #0
	adds r0, #0x83
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0802710E
	movs r0, #0x18
	b _08027110
_080270FC:
	adds r0, r6, #0
	adds r0, #0x83
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0802710E
	movs r0, #0x18
	b _08027110
_0802710E:
	movs r0, #8
_08027110:
	strb r0, [r5, #0x15]
	ldr r1, [r7]
	ldrb r0, [r1, #3]
	cmp r0, #0
	bne _08027152
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	ldrh r1, [r1, #0xe]
	cmp r0, r1
	bne _0802714A
	mov r0, r8
	adds r0, #0x84
	movs r1, #1
	strb r1, [r0]
	mov r0, sb
	adds r0, #0x84
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x84
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x7c
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, [r7]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	b _080271FE
_0802714A:
	adds r0, r5, #0
	bl ProcessMovement0
	b _080271FE
_08027152:
	adds r0, r6, #0
	adds r0, #0x7d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080271E6
	mov r0, sb
	adds r0, #0x7d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080271E6
	mov r0, r8
	adds r0, #0x7d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080271E6
	adds r1, r5, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080271FE
	mov r0, r8
	adds r0, #0x84
	movs r1, #1
	strb r1, [r0]
	mov r0, sb
	adds r0, #0x84
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x84
	strb r1, [r0]
	movs r3, #0
	ldr r0, [r7]
	ldrb r0, [r0, #3]
	cmp r0, #1
	bls _080271B2
	ldr r0, _080271DC @ =gPlayerEntity
	movs r2, #0x2e
	ldrsh r1, [r5, r2]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	movs r3, #8
	cmp r1, r0
	ble _080271B2
	movs r3, #0x18
_080271B2:
	ldr r2, [r7]
	ldrb r1, [r2, #3]
	cmp r1, #5
	beq _080271C0
	ldrb r0, [r5, #0x15]
	cmp r0, r3
	bne _080271E0
_080271C0:
	movs r4, #0
	movs r0, #6
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #1
	bl sub_080276F4
	ldr r0, [r7]
	strb r4, [r0, #3]
	adds r1, r5, #0
	adds r1, #0x7d
	movs r0, #0xf
	b _080271FC
	.align 2, 0
_080271DC: .4byte gPlayerEntity
_080271E0:
	adds r0, r1, #1
	strb r0, [r2, #3]
	b _080271FE
_080271E6:
	ldr r0, [r7]
	ldrb r0, [r0, #3]
	cmp r0, #4
	beq _080271F6
	adds r1, r5, #0
	adds r1, #0x7c
	movs r0, #0x1e
	b _080271FC
_080271F6:
	adds r1, r5, #0
	adds r1, #0x7c
	movs r0, #0x3c
_080271FC:
	strb r0, [r1]
_080271FE:
	adds r0, r5, #0
	bl sub_08027870
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
	.syntax divided

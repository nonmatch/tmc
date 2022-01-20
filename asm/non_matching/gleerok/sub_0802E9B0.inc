	.syntax unified
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0802E9D0 @ =gPlayerEntity
	movs r2, #0x2e
	ldrsh r1, [r0, r2]
	movs r3, #0x32
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl sub_080041DC
	lsrs r2, r0, #4
	cmp r2, #0x5f
	bgt _0802E9D4
	movs r2, #0xa
	b _0802E9EA
	.align 2, 0
_0802E9D0: .4byte gPlayerEntity
_0802E9D4:
	adds r1, r2, #0
	subs r1, #0x60
	cmp r1, #0
	bge _0802E9DE
	adds r1, #3
_0802E9DE:
	asrs r1, r1, #2
	movs r0, #0xa
	subs r2, r0, r1
	cmp r2, #3
	bgt _0802E9EA
	movs r2, #4
_0802E9EA:
	adds r0, r4, #0
	adds r0, #0x84
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r2, r0
	beq _0802EA10
	cmp r2, r0
	ble _0802EA04
	ldrh r0, [r3, #0x2c]
	adds r0, #0x20
	b _0802EA08
_0802EA04:
	ldrh r0, [r3, #0x2c]
	subs r0, #0x20
_0802EA08:
	ldr r2, _0802EA14 @ =0x00001FFF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r3, #0x2c]
_0802EA10:
	pop {r4, pc}
	.align 2, 0
_0802EA14: .4byte 0x00001FFF
	.syntax divided

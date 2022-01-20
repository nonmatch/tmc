	.syntax unified
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r4, #0
	movs r0, #0xa
	strb r0, [r6, #0xd]
	adds r5, r6, #0
	adds r5, #0x84
	ldr r0, [r5]
	strb r4, [r0, #1]
	adds r0, r6, #0
	movs r1, #7
	movs r2, #1
	bl sub_080276F4
	ldr r0, [r6, #0x54]
	adds r0, #0x7d
	strb r4, [r0]
	movs r3, #0
	strh r4, [r6, #0x24]
	ldr r0, [r5]
	strb r3, [r0, #3]
	movs r0, #0x2e
	ldrsh r1, [r6, r0]
	ldr r0, [r5]
	ldrh r0, [r0, #0xe]
	cmp r1, r0
	ble _08027C0A
	movs r0, #0x18
	strb r0, [r6, #0x15]
	ldr r2, [r6, #0x54]
	ldr r1, [r6, #0x50]
	ldr r0, [r6, #0x68]
	adds r0, #0x85
	strb r3, [r0]
	adds r1, #0x85
	strb r3, [r1]
	adds r2, #0x85
	strb r3, [r2]
	b _08027C22
_08027C0A:
	movs r0, #8
	strb r0, [r6, #0x15]
	ldr r3, [r6, #0x54]
	ldr r2, [r6, #0x50]
	ldr r0, [r6, #0x68]
	adds r0, #0x85
	movs r1, #1
	strb r1, [r0]
	adds r2, #0x85
	strb r1, [r2]
	adds r3, #0x85
	strb r1, [r3]
_08027C22:
	ldrb r0, [r6, #0x15]
	lsrs r0, r0, #2
	strb r0, [r6, #0x14]
	ldr r0, _08027C44 @ =gPlayerEntity
	movs r2, #0x32
	ldrsh r1, [r6, r2]
	movs r2, #0x32
	ldrsh r0, [r0, r2]
	cmp r1, r0
	beq _08027C52
	cmp r1, r0
	ble _08027C48
	adds r0, r6, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #0
	b _08027C50
	.align 2, 0
_08027C44: .4byte gPlayerEntity
_08027C48:
	adds r0, r6, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #0x10
_08027C50:
	strb r0, [r1, #0xc]
_08027C52:
	pop {r4, r5, r6, pc}
	.syntax divided

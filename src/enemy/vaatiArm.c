/**
 * @file vaatiArm.c
 * @ingroup Enemies
 *
 * @brief Vaati Arm enemy
 */

#include "area.h"
#include "enemy.h"
#include "functions.h"
#include "hitbox.h"
#include "object.h"
#include "roomid.h"

typedef struct VaatiArm_HeapStruct1 {
    union SplitHWord unk00;
    u16 unk02;
    union SplitHWord unk04;
    u16 unk06;
    s16 unk08;
    s16 unk0a;
    u8 unk0c;
    u8 unk0d;
    u8 unk0e;
    u8 unk0f;
} VaatiArm_HeapStruct1;

typedef struct VaatiArm_HeapStruct {
    Entity* entities[5];
    Entity* parent;
    VaatiArm_HeapStruct1 s1[5];
} VaatiArm_HeapStruct;

static u32 sub_080437DC(Entity*);
static u32 sub_08043C98(Entity*);
static void VaatiArm_OnTick(Entity*);
static void VaatiArm_OnCollision(Entity*);
static void sub_080425B4(Entity*);
static void sub_08042818(Entity*);
static void sub_08042870(Entity*);
static void sub_08042A3C(Entity*);
static void sub_08042C14(Entity*);
static void sub_0804325C(Entity*);
static void sub_08043420(Entity*);
static void sub_08043680(Entity*);
static void VaatiArm_OnGrabbed(Entity*);
static void sub_08042654(Entity*);
static void sub_0804259C(Entity*);
static void sub_08043A10(Entity*);
static void sub_08043ABC(Entity*);
static void sub_08043BC8(Entity*);
static void sub_08043EB8(Entity*);
static void sub_08044000(Entity*);
static void sub_08044078(Entity*);
static void sub_080440CC(Entity*);
static void sub_08043CD4(Entity*);
static void sub_08042894(Entity*);
static void sub_080428AC(Entity*);
static void sub_080428FC(Entity*);
static void sub_08042944(Entity*);
static void sub_08042970(Entity*);
static void sub_080429D4(Entity*);
static void sub_080429FC(Entity*);
static void sub_08043BF0(Entity*);
static void sub_08042A6C(Entity*);
static void sub_08042A88(Entity*);
static void sub_08042AEC(Entity*);
static void sub_08042B20(Entity*);
static void sub_08043C40(Entity*, VaatiArm_HeapStruct1*);
static void sub_08043A78(Entity*);
static void sub_08042C34(Entity*);
static void sub_08042D24(Entity*);
static void sub_08042D6C(Entity*);
static void sub_08042E30(Entity*);
static void sub_08042EF4(Entity*);
static void sub_08042FD8(Entity*);
static void sub_08043048(Entity*);
static void sub_080430D0(Entity*);
static void sub_08043130(Entity*);
static void sub_080431E8(Entity*);
static void sub_08043B9C(Entity*);
static void sub_08043DB0(Entity*);
static void sub_08043B7C(Entity*);
static void sub_08043D08(Entity*);
void sub_080432A8(Entity*);
void sub_0804334C(Entity*);
static void sub_08043440(Entity*);
static void sub_08043490(Entity*);
static void sub_08043520(Entity*);
static void sub_0804355C(Entity*);
static void sub_08043580(Entity*);
static void sub_080435F4(Entity*);
static void sub_08043698(Entity*);
static void sub_080436C0(Entity*);
static void sub_08043700(Entity*);
static void sub_08043738(Entity*);
static void sub_08043770(Entity*);

void sub_0804AA1C(Entity*);

void (*const VaatiArm_Functions[])(Entity*) = {
    VaatiArm_OnTick, VaatiArm_OnCollision, GenericKnockback, GenericDeath, GenericConfused, VaatiArm_OnGrabbed,
};
void (*const gUnk_080D1248[])(Entity*) = {
    sub_0804259C, sub_08044078, sub_08044078, sub_08044078, sub_080440CC,
};
void (*const gUnk_080D125C[])(Entity*) = {
    sub_080425B4, sub_08042654, sub_08042818, sub_08042870, sub_08042A3C,
    sub_08042C14, sub_0804325C, sub_08043420, sub_08043680,
};

const s16 gUnk_080D1280[] = { 0x140, -0x140 };
const s8 gUnk_080D1284[] = { 0x40, -0x40 };
const u8 gUnk_080D1286[] = { 2, 3, 5, 6, 0xc, 0xb, 9, 8, 0, 0 };

void (*const gUnk_080D1290[])(Entity*) = {
    sub_08042894, sub_080428AC, sub_080428FC, sub_08042944, sub_08042970, sub_080429D4, sub_080429FC,
};

const s16 gUnk_080D12AC[] = { -0x200, 0x200 };
const u8 gUnk_080D12B0[] = { 8, -8 };
const u8 gUnk_080D12B2[] = { -0x50, 0x50 };
const s8 gUnk_080D12B4[] = { -0x20, 0x20 };
const u8 gUnk_080D12B6[] = { 0x70, -0x70 };

void (*const gUnk_080D12B8[])(Entity*) = {
    sub_08042A6C,
    sub_08042A88,
    sub_08042AEC,
    sub_08042B20,
};

const u8 gUnk_080D12C8[] = { 0x60, -0x60 };
const u16 gUnk_080D12CA[] = { 0x280, -0x280 };

void (*const gUnk_080D12D0[])(Entity*) = {
    sub_08042C34, sub_08042D24, sub_08042D6C, sub_08042E30, sub_08042EF4,
    sub_08042FD8, sub_08043048, sub_080430D0, sub_08043130, sub_080431E8,
};

const s8 gUnk_080D12F8[] = { -0x10, 0, 0, -0x10, 0x10, 0, 0, 0x10 };
const s16 gUnk_080D1300[] = { 0xC0, -0xC0 };
const u8 gUnk_080D1304[] = { 0, -1, -2, -3, 0, 1, 2, 3 };
const s16 gUnk_080D130C[] = { 0x5000, -0x5000 };
const s16 gUnk_080D1310[] = { 0xA0, -0xA0 };
void (*const gUnk_080D1314[])(Entity*) = { sub_080432A8, sub_0804334C };
const u8 gUnk_080D131C[] = { 0x70, -0x70 };
void (*const gUnk_080D1320[])(Entity*) = {
    sub_08043440, sub_08043490, sub_08043520, sub_0804355C, sub_08043580, sub_080435F4,
};
const s16 gUnk_080D1338[] = { 0x4000, -0x4000 };
const s16 gUnk_080D133C[] = { 0xA0, -0xA0 };
const u8 gUnk_080D1340[] = { 0, 0x12, 0x12, 0x11, 0x11, 0, 0, 0 };
void (*const gUnk_080D1348[])(Entity*) = {
    sub_08043698, sub_080436C0, sub_08043700, sub_08043738, sub_08043770,
};
const u16 gUnk_080D135C[] = { 0x4000, -0x4000, 0x8000 };
const u8 gUnk_080D1362[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2,
    3, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 1, 2, 3,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
};
const u8 gUnk_080D13B2[] = { 0, 12, 9, 6, 3 };
const u8 gUnk_080D13B7[] = {
    1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 10, 10, 10, 11, 11, 11, 12, 12, 1, 0,
};
const Coords gUnk_080D13D8[] = { { .HALF = { -0x60, 0x80 } }, { .HALF = { 0x60, -0x80 } } };
const u8 gUnk_080D13E0[] = { 0xc, 0xe, 0x10 };
const u8 gUnk_080D13E3[] = { 8, 9, 10, 4, 4, 5 };
const s8 gUnk_080D13E9[] = { -8, 8 };
const ScreenTransitionData gUnk_080D13EC = {
    1, { 0, 0, 0, 0 }, 0x98, 0xb8, 0, AREA_VAATIS_ARMS, ROOM_VAATIS_ARMS_FIRST, 1, 0, 0, 0
};
const u16 gUnk_080D1400[][5] = {
    { 0x8000, 0x7000, 0x6000, 0x5000, 0x4000 },
    { 0x8000, -0x7000, -0x6000, -0x5000, -0x4000 },
};
const u8 gUnk_080D1414[] = { 0, 0xc, 0xe, 0x10, 0x1c };
const u8 gUnk_080D1419[] = { 0, 0xa, 0xa, 0xa, 0x1c };

void VaatiArm(Entity* this) {
    VaatiArm_Functions[GetNextFunction(this)](this);
}

static void VaatiArm_OnTick(Entity* this) {
    gUnk_080D1248[this->type](this);
}

static void VaatiArm_OnCollision(Entity* this) {
    EnemyFunctionHandlerAfterCollision(this, VaatiArm_Functions);
}

static void VaatiArm_OnGrabbed(Entity* this) {
}

static void sub_0804259C(Entity* this) {
    gUnk_080D125C[this->action](this);
}

static void sub_080425B4(Entity* this) {
    if (sub_080437DC(this)) {
        this->field_0x7c.BYTES.byte0 = 0;
        this->field_0x7c.BYTES.byte1 = 0;
        if ((gRoomTransition.field_0x38 & 1) != 0) {
            if (gRoomTransition.field_0x3c == this->type2) {
                sub_08043EB8(this);
                sub_08043ABC(this);
                if ((gRoomTransition.field_0x39 >> (this->type2 + 2) & 1U) != 0) {
                    this->action = 7;
                    this->subAction = 4;
                } else {
                    this->action = 8;
                    this->subAction = 0;
                }
            } else {
                sub_08044000(this);
                sub_08043BC8(this);
                sub_08043A10(this);
            }
        } else {
            this->action = 1;
            this->subAction = gRoomTransition.field_0x38 & 1;
            ((VaatiArm_HeapStruct*)this->myHeap)->s1[0].unk08 = gUnk_080D1280[this->type2];
            sub_08042654(this);
        }
    }
}

static void sub_08042654(Entity* this) {
    u32 uVar8;
    int index;
    VaatiArm_HeapStruct1* ptr;

    index = this->type2 * 4;
    ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    switch (this->subAction) {
        case 0:
            this->subAction = 1;
            ptr->unk00.HALF.HI = gUnk_080D1284[this->type2];
            uVar8 = gUnk_080D1286[this->type2 * 4];
            InitAnimationForceUpdate(this, uVar8);
            SoundReq(SFX_15E);
            break;
        case 1:
            ptr->unk00.HWORD += ptr->unk08;
            if ((((VaatiArm_HeapStruct*)this->myHeap)->s1[1].unk0c += 2) < 0xc)
                break;
            this->subAction = 2;
            uVar8 = gUnk_080D1286[index + 1];
            InitAnimationForceUpdate(this, uVar8);
            SoundReq(SFX_15E);
            break;
        case 2:
            ptr->unk00.HWORD += ptr->unk08;
            if ((((VaatiArm_HeapStruct*)this->myHeap)->s1[2].unk0c += 2) < 0xe)
                break;
            this->subAction = 3;
            uVar8 = gUnk_080D1286[index + 2];
            InitAnimationForceUpdate(this, uVar8);
            SoundReq(SFX_15E);
            break;
        case 3:
            ptr->unk00.HWORD += ptr->unk08;
            if ((((VaatiArm_HeapStruct*)this->myHeap)->s1[3].unk0c += 2) < 0x10)
                break;
            this->subAction = 4;
            uVar8 = gUnk_080D1286[index + 3];
            InitAnimationForceUpdate(this, uVar8);
            SoundReq(SFX_15E);
            break;
        case 4:
            ptr->unk00.HWORD += ptr->unk08;
            if ((((VaatiArm_HeapStruct*)this->myHeap)->s1[4].unk0c += 2) < 0x1c)
                break;
            this->subAction = 5;
            this->timer = 90;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->flags |= ENT_COLLIDE;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->spritePriority.b0 = 4;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[1]->flags |= ENT_COLLIDE;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[1]->spritePriority.b0 = 4;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[2]->flags |= ENT_COLLIDE;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[2]->spritePriority.b0 = 4;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[3]->flags |= ENT_COLLIDE;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[3]->spritePriority.b0 = 4;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[4]->flags |= ENT_COLLIDE;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[4]->spritePriority.b0 = 4;
            InitAnimationForceUpdate(this, 7);
            SoundReq(SFX_15E);
            break;
        default:
            if (--this->timer == 0) {
                sub_08043BC8(this);
            }
            break;
    }
    sub_08043A10(this);
}

static void sub_08042818(Entity* this) {
    VaatiArm_HeapStruct1* ptr;

    sub_08043CD4(this);
    ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    ptr->unk00.HWORD += ptr->unk08;
    if (--ptr->unk0d == 0) {
        ptr->unk0d = 0x78;
        ptr->unk08 *= -1;
    }
    ptr->unk04.HWORD += ptr->unk0a;
    if (--ptr->unk0e == 0) {
        ptr->unk0e = 0x50;
        ptr->unk0a *= -1;
    }
    sub_08043A10(this);
}

static void sub_08042870(Entity* this) {
    sub_08043CD4(this);
    gUnk_080D1290[this->subAction](this);
    sub_08043A10(this);
}

static void sub_08042894(Entity* this) {
    this->subAction = 1;
    ((VaatiArm_HeapStruct*)this->myHeap)->s1[0].unk08 = gUnk_080D12AC[this->type2];
}

static void sub_080428AC(Entity* this) {
    u8 bVar1;
    VaatiArm_HeapStruct1* pVVar3;

    pVVar3 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    bVar1 = pVVar3->unk04.HALF.HI;
    if (bVar1 != 0x40) {
        if (bVar1 >= 0x41) {
            pVVar3->unk04.HWORD -= 0x80;
        } else {
            pVVar3->unk04.HWORD += 0x80;
        }
    }
    if ((u32)(pVVar3->unk00.HALF.HI - gUnk_080D12B0[this->type2] + 1) > 2) {
        pVVar3->unk00.HWORD += pVVar3->unk08;
    } else {
        this->subAction = 2;
        this->timer = 30;
    }
    sub_08043BF0(this);
}

static void sub_080428FC(Entity* this) {
    u32 uVar2;
    VaatiArm_HeapStruct1* ptr;

    if (--this->timer == 0) {
        this->subAction = 3;
        ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
        ptr->unk08 *= -3;
        SoundReq(SFX_153);
        uVar2 = 0;
        do {
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[uVar2]->hitType = 0x3b;
            uVar2 = uVar2 + 1;
        } while (uVar2 < 5);
    }
}

static void sub_08042944(Entity* this) {
    VaatiArm_HeapStruct1* pVVar1;

    pVVar1 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    if ((u32)(pVVar1->unk00.HALF.HI - 0x7c) >= 9) {
        pVVar1->unk00.HWORD += pVVar1->unk08;
    } else {
        this->subAction = 4;
        this->speed = pVVar1->unk08;
    }
    sub_08043BF0(this);
}

static void sub_08042970(Entity* this) {
    u32 uVar2;
    VaatiArm_HeapStruct1* pVVar3;

    pVVar3 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    if ((u32)(pVVar3->unk00.HALF.HI - gUnk_080D12B2[this->type2] + 2) >= 5) {
        pVVar3->unk08 += gUnk_080D12B4[this->type2];
        pVVar3->unk00.HWORD += pVVar3->unk08;
    } else {
        this->subAction = 5;
        this->timer = 60;
        uVar2 = 0;
        do {
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[uVar2]->hitType = 0x39;
            uVar2 = uVar2 + 1;
        } while (uVar2 < 5);
    }
    sub_08043BF0(this);
}

static void sub_080429D4(Entity* this) {
    s16 sVar2;
    VaatiArm_HeapStruct1* pVVar3;

    if (--this->timer == 0) {
        this->subAction = 6;
        pVVar3 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
        sVar2 = -this->speed / 6;
        pVVar3->unk08 = sVar2;
    }
}

static void sub_080429FC(Entity* this) {
    VaatiArm_HeapStruct1* pVVar1;

    pVVar1 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    if ((u32)(pVVar1->unk00.HALF.HI - gUnk_080D12B6[this->type2]) + 1 >= 3) {
        pVVar1->unk00.HWORD += pVVar1->unk08;
        sub_08043BF0(this);
    } else {
        sub_08043BC8(this);
        InitAnimationForceUpdate(this, 7);
    }
}

static void sub_08042A3C(Entity* this) {
    Entity* entity;

    gUnk_080D12B8[this->subAction](this);
    sub_08043A10(this);
    entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
    entity->z.HALF.HI += this->field_0x78.HALF.LO;
}

static void sub_08042A6C(Entity* this) {
    this->subAction = 1;
    this->field_0x78.HALF.LO = 0;
    this->field_0x7c.BYTES.byte2 = 1;
    ((VaatiArm_HeapStruct*)this->myHeap)->s1[0].unk0a = 0x200;
}

static void sub_08042A88(Entity* this) {
    VaatiArm_HeapStruct1* pVVar4;

    pVVar4 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    if (gUnk_080D12C8[this->type2] != pVVar4->unk00.HALF.HI) {
        if (gUnk_080D12C8[this->type2] < pVVar4->unk00.HALF.HI) {
            pVVar4->unk00.HWORD -= 0x100;
        } else {
            pVVar4->unk00.HWORD += 0x100;
        }
    }
    if (pVVar4->unk0a < pVVar4->unk04.HWORD) {
        pVVar4->unk04.HWORD -= pVVar4->unk0a;
    } else {
        pVVar4->unk04.HWORD = 0;
        pVVar4->unk08 = gUnk_080D12CA[this->type2];
        this->subAction = 2;
        this->timer = 30;
    }
}

static void sub_08042AEC(Entity* this) {
    if (--this->timer == 0) {
        this->subAction = 3;
        this->timer = 4;
        this->hitType = 0x3d;
        InitAnimationForceUpdate(this, 0xe);
        ((VaatiArm_HeapStruct*)this->myHeap)->entities[1]->hitType = 0x3d;
    }
}

static void sub_08042B20(Entity* this) {
    VaatiArm_HeapStruct1* ptr;
    Entity* object;
    Entity* entity;
    u32 i;

    ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    if (ptr->unk04.HALF.HI < 0x7b) {
        ptr->unk04.HWORD += 0x500;
    } else {
        ptr->unk04.HALF.HI = 0x80;
    }
    if (0x30 < ptr->unk04.HALF.HI) {
        ptr->unk00.HWORD += ptr->unk08;
    }
    if (((VaatiArm_HeapStruct*)this->myHeap)->entities[3]->spriteSettings.draw) {
        sub_08043C40(this, ptr);
        for (i = 0; i < 4; i++) {
            entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
            if ((-0xa <= entity->z.HALF.HI) && ((entity->spriteSettings.draw) == 1)) {
                if (i == 0) {
                    object = CreateObject(VAATI3_ARM, 0, 0);
                    if (object != NULL) {
                        object->parent = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
                    }
                    *(Entity**)&((VaatiArm_HeapStruct*)this->myHeap)->entities[4]->field_0x68 = object;
                    object = CreateObject(VAATI3_ARM, 2, 0);
                    if (object != NULL) {
                        CopyPosition(((VaatiArm_HeapStruct*)this->myHeap)->entities[4], object);
                    }
                }
                entity->flags &= ~ENT_COLLIDE;
                entity->spriteSettings.draw = 0;
                SoundReq(SFX_161);
            }
        }
    } else {
        this->field_0x78.HALF.LO += 2;
        if (--this->timer == 0) {
            this->action = 5;
            this->subAction = 0;
            this->timer = 30;
            this->hitType = 0x39;
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[1]->hitType = 0x39;
        }
    }
}

static void sub_08042C14(Entity* this) {
    gUnk_080D12D0[this->subAction](this);
    sub_08043A78(this);
}

static void sub_08042C34(Entity* this) {
    u32 random;
    int y;
    u32 i;
    Entity* entity;
    int x;
    const s8* temp;

    VaatiArm_HeapStruct1* ptr;

    if (--this->timer == 0) {
        this->timer = 60;
        this->subtimer = 3;
        this->subAction = 1;
        random = Random() & 6;
        temp = &gUnk_080D12F8[random];
        x = gPlayerEntity.x.HALF.HI + *temp;
        y = gPlayerEntity.y.HALF.HI + *(temp + 1);
        if ((gRoomControls.origin_x + 0x20) > x) {
            x = gRoomControls.origin_x + 0x20;
        }
        if (gRoomControls.origin_x + gRoomControls.width + -0x20 < x) {
            x = gRoomControls.origin_x + gRoomControls.width + -0x20;
        }
        if ((gRoomControls.origin_y + 0x20) > y) {
            y = gRoomControls.origin_y + 0x20;
        }
#if defined EU || defined JP || defined DEMO_JP
        if (gRoomControls.origin_y + gRoomControls.height + -0x20 < y) {
            y = gRoomControls.origin_y + gRoomControls.height + -0x20;
        }
#else
        if (gRoomControls.origin_y + gRoomControls.height + -0x40 < y) {
            y = gRoomControls.origin_y + gRoomControls.height + -0x40;
        }
#endif
        if (((u32)((x - gRoomControls.origin_x) - 0x90) < 0x41) && ((u32)((y - gRoomControls.origin_y) - 8) < 0x41)) {
            x = gRoomControls.origin_x + 0xb0;
            y = gRoomControls.origin_y + 0x40;
        }
        for (i = 0; i < 4; i++) {
            entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
            entity->x.HALF.HI = x;
            entity->y.HALF.HI = y;
            entity->z.HALF.HI = 0x32;
            entity->hitType = 0x39;
            ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[i];
            ptr->unk00.HWORD = 0x80;
            ptr->unk04.HWORD = 0;
            ptr->unk0c = gUnk_080D1419[i];
            if (i != 0) {
                InitializeAnimation(entity, 0x12);
            }
        }
    }
}

static void sub_08042D24(Entity* this) {
    Entity* entity;

    if (--this->timer == 0) {
        this->subAction = 2;
        this->hitType = 0x3d;
        ((VaatiArm_HeapStruct*)this->myHeap)->entities[1]->hitType = 0x3d;
        entity = CreateObject(VAATI3_ARM, 1, 0);
        if (entity != NULL) {
            entity->parent = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
        }
        *(Entity**)&this->field_0x68 = entity;
        InitAnimationForceUpdate(this, 0xd);
    }
}

static void sub_08042D6C(Entity* this) {
    Entity* object;
    Entity* entity;
    u32 i;

    for (i = 0; i < 4; i++) {
        entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
        if (entity->z.HALF.HI < 4) {
            if (i != 2) {
                entity->flags = entity->flags | ENT_COLLIDE;
            }
            if ((entity->spriteSettings.draw == 0u) && (object = CreateObject(VAATI3_ARM, 2, 0), object != NULL)) {
                CopyPosition(entity, object);
                SoundReq(SFX_166);
            }
            entity->spriteSettings.draw = 1;
        }
    }
    entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
    if (entity->z.HALF.HI <= -3) {
        entity->z.HALF.HI = -5;
        ((VaatiArm_HeapStruct*)this->myHeap)->s1[0].unk08 = gUnk_080D1300[this->type2];
        ((VaatiArm_HeapStruct*)this->myHeap)->s1[0].unk0a = 0xc0;
        this->subAction = 3;
        this->timer = 30;
        this->hitType = 0x39;
        this->field_0x7c.BYTES.byte3 = 0x2d;
        InitAnimationForceUpdate(this, 0);
        ((VaatiArm_HeapStruct*)this->myHeap)->entities[1]->hitType = 0x39;
    } else {
        entity->z.HALF.HI -= 2;
    }
}

static void sub_08042E30(Entity* this) {
    short sVar3;
    u32 uVar6;
    VaatiArm_HeapStruct1* pVVar9;

    if (this->field_0x7c.BYTES.byte3 == 0) {
        if (sub_08043C98(this) != 0) {
            return;
        }
    } else {
        this->field_0x7c.BYTES.byte3--;
    }
    pVVar9 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    if (--this->timer == 0) {
        this->subAction = 4;
        this->timer = (Random() & 0x38) + 40;
        this->speed = 0x200;
        this->direction = pVVar9->unk00.HALF.HI >> 3;
        uVar6 = CalculateDirectionTo(this->x.HALF.HI, this->y.HALF.HI, gRoomControls.origin_x + 0x110,
                                     gRoomControls.origin_y + 0x60);
        this->field_0x78.HALF.HI = (gUnk_080D1304[Random() & 7] + uVar6) & 0x1f;
    }
    pVVar9->unk00.HWORD += pVVar9->unk08;
    pVVar9->unk04.HWORD += pVVar9->unk0a;
    if (pVVar9->unk0a >= 1) {
        if (pVVar9->unk04.HALF.HI >= 0x19) {
            sVar3 = pVVar9->unk0a;
            pVVar9->unk0a = -sVar3;
        }
    } else {
        if (3 >= pVVar9->unk04.HALF.HI) {
            sVar3 = pVVar9->unk0a;
            pVVar9->unk0a = -sVar3;
        }
    }
    UpdateAnimationSingleFrame(this);
}

static void sub_08042EF4(Entity* this) {
    VaatiArm_HeapStruct1* ptr;
    Entity* entity;
    u32 temp;
    u32 x, y;

    UpdateAnimationSingleFrame(this);
    if (sub_08043C98(this) == 0) {
        if (--this->timer == 0) {
            if (EntityWithinDistance(this, gPlayerEntity.x.HALF.HI, gPlayerEntity.y.HALF.HI, 0x50)) {
                this->subAction = 6;
                this->timer = 40;
            } else {
                this->subAction = 5;
                InitAnimationForceUpdate(this, 0xf);
                SoundReq(SFX_19B);
            }
        }
        ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
        if (ptr->unk04.HALF.HI < 0x20) {
            ptr->unk04.HWORD += 0x100;
        }
        x = this->parent->x.HALF.HI;
        y = this->parent->y.HALF.HI - 0x10;
        if (EntityWithinDistance(this, x, y, 0x30)) {
            temp = CalculateDirectionTo(this->x.HALF.HI, this->y.HALF.HI, x, y);
            if ((this->field_0x78.HALF.HI - temp) + 4 < 9) {
                this->field_0x78.HALF.HI = temp ^ 0x10;
            }
        }
        if (this->field_0x78.HALF.HI != this->direction) {
            sub_08004596(this, this->field_0x78.HALF.HI);
            ptr->unk00.HALF.HI = this->direction << 3;
        }
        entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
        entity->direction = this->direction;
        ProcessMovement0(entity);
    }
}

static void sub_08042FD8(Entity* this) {
    Entity* entity;

    UpdateAnimationSingleFrame(this);
    if (!sub_08043C98(this)) {
        if ((this->frame & 1) != 0) {
            entity = CreateProjectile(V3_HAND_PROJECTILE);
            if (entity != NULL) {
                CopyPosition(this, entity);
                entity->z.HALF.HI -= 0x18;
                this->frame = 0;
            }
        } else {
            if (this->frame & ANIM_DONE) {
                if (--this->subtimer == 0) {
                    this->subAction = 8;
                    this->timer = 60;
                } else {
                    this->subAction = 3;
                    this->timer = 60;
                    InitAnimationForceUpdate(this, 0);
                }
            }
        }
    }
}

static void sub_08043048(Entity* this) {
    VaatiArm_HeapStruct1* ptr;
    u32 i;

    if (sub_08043C98(this) == 0) {
        ptr = ((VaatiArm_HeapStruct*)this->myHeap)->s1;
        if (ptr[0].unk04.HALF.HI < 0x50) {
            ptr[0].unk04.HWORD += 0x200;
            if (0x4f < ptr[0].unk04.HALF.HI) {
                for (i = 0; i < 5; i++) {
                    ((VaatiArm_HeapStruct*)this->myHeap)->entities[i]->hitType = 0x3b;
                }
                SoundReq(SFX_153);
            }
        } else {
            ptr[0].unk00.HWORD += ptr[0].unk08 * 8;
            if (--this->timer == 0) {
                this->subAction = 7;
                for (i = 0; i < 5; i++) {
                    ((VaatiArm_HeapStruct*)this->myHeap)->entities[i]->hitType = 0x39;
                }
            }
        }
        sub_08043B9C(this);
    }
}

static void sub_080430D0(Entity* this) {
    VaatiArm_HeapStruct1* ptr;

    if (sub_08043C98(this) == 0) {
        ptr = ((VaatiArm_HeapStruct*)this->myHeap)->s1;
        ptr[0].unk00.HWORD += ptr[0].unk08;
        ptr[0].unk04.HWORD -= 0x100;
        if (ptr[0].unk04.HALF.HI < 0x18) {
            if (--this->subtimer == 0) {
                this->subAction = 8;
                this->timer = 60;
            } else {
                this->subAction = 3;
                this->timer = 60;
                ptr[0].unk0a = -0xc0;
                InitAnimationForceUpdate(this, 0);
            }
        }
    }
}

static void sub_08043130(Entity* this) {
    VaatiArm_HeapStruct1* ptr;
    Entity* entity;
    u32 i;

    ptr = ((VaatiArm_HeapStruct*)this->myHeap)->s1;
    if (ptr[0].unk04.HALF.HI != 0) {
        if (sub_08043C98(this) == 0) {
            if (--ptr[0].unk04.HALF.HI == 0) {
                InitAnimationForceUpdate(this, 0xd);
            }
        }
    } else {
        if (this->timer != 0) {
            this->timer--;
            for (i = 1; i < 4; i++) {
                ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[i];
                if (ptr->unk04.HALF.HI != 0) {
                    ptr->unk04.HALF.HI--;
                }
            }
        } else {
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[3]->z.HALF.HI += 3;
            for (i = 0; i < 4; i++) {
                entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
                if (entity->z.HALF.HI > -4) {
                    entity->flags = entity->flags & ~ENT_COLLIDE;
                    if (entity->spriteSettings.draw == 1) {
                        SoundReq(SFX_161);
                    }
                    entity->spriteSettings.draw = 0;
                }
            }
            if (this->spriteSettings.draw == 0) {
                this->subAction = 9;
                this->timer = 60;
                sub_0804AA1C(this);
            }
        }
    }
}

static void sub_080431E8(Entity* this) {
    u32 i;
    VaatiArm_HeapStruct1* ptr;

    if (--this->timer == 0) {
        this->action = 6;
        this->subAction = 0;
        for (i = 0; i < 4; i++) {
            ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[i];
            ptr->unk00.HWORD = gUnk_080D130C[this->type2];
            ptr->unk04.HWORD = 0x8000;
            ptr->unk0c = gUnk_080D1414[i];
            if (i == 3) {
                InitializeAnimation(((VaatiArm_HeapStruct*)this->myHeap)->entities[3], 0x11);
            }
        }
        ((VaatiArm_HeapStruct*)this->myHeap)->s1[0].unk08 = gUnk_080D1310[this->type2];
        InitAnimationForceUpdate(this, 0xe);
    }
}

static void sub_0804325C(Entity* this) {
    Entity* entity;

    sub_08043CD4(this);
    gUnk_080D1314[this->subAction](this);
    sub_08043A10(this);
    if (this->field_0x78.HALF.LO != 0) {
        if (this->field_0x78.HALF.LO >= 3) {
            this->field_0x78.HALF.LO -= 2;
            entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
            entity->z.HALF.HI += this->field_0x78.HALF.LO;
        } else {
            this->field_0x78.HALF.LO = 0;
        }
    }
}

void sub_080432A8(Entity* this) {
    s32 iVar3;
    s32 i;
    VaatiArm_HeapStruct1* hs;
    Entity* ent;
    i = 3;
    iVar3 = 0;

    for (; i >= 0; i--) {
        hs = &((VaatiArm_HeapStruct*)this->myHeap)->s1[i];
        if (hs->unk0c > 2) {
            hs->unk0c--;
            if (++iVar3 > 1) {
                break;
            }
        }
    }

    hs = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    hs->unk04.HALF.HI -= 2;

    for (i = 0; i < 4; i++) {
        ent = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
        if (ent->z.HALF.HI < 4) {
            COLLISION_ON(ent);
            ent->spriteSettings.draw = 1;
        }
    }

    if ((((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->spriteSettings.draw == 1) &&
        (((VaatiArm_HeapStruct*)this->myHeap)->s1[1].unk0c < 3)) {
        this->subAction = 1;
        this->timer = 0x1e;
        ((VaatiArm_HeapStruct*)this->myHeap)->s1[0].unk04.HWORD = 0x4000;
        sub_0804AA1C(((VaatiArm_HeapStruct*)this->myHeap)->entities[4]);
    }
}

void sub_0804334C(Entity* this) {
    u32 bVar1;
    Entity* entity;
    u32 i;
    VaatiArm_HeapStruct1* ptr;

    if (this->timer != 0) {
        if (--this->timer != 0) {
            return;
        }
        for (i = 0; i < 5; i++) {
            entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
            COLLISION_ON(entity);
            entity->spriteSettings.draw = 1;
        }
    }
    ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    if (gUnk_080D131C[this->type2] - ptr->unk00.HALF.HI + 1 > 2u) {
        ptr->unk00.HWORD += ptr->unk08;
        bVar1 = 0;
    } else {
        bVar1 = 1;
    }
    sub_08043B9C(this);
    for (i = 0; i < 5; i++) {
        ptr = &(((VaatiArm_HeapStruct*)this->myHeap)->s1)[i];

        if (gUnk_080D1414[i] > ptr->unk0c) {
            if (gUnk_080D1414[i] == ++ptr->unk0c) {
                SoundReq(SFX_15E);
            }
            return;
        }
        if ((bVar1) && (i == 4)) {
            sub_08043BC8(this);
            InitAnimationForceUpdate(this, 7);
            if (this->field_0x7c.BYTES.byte2 != 0) {
                this->field_0x7c.BYTES.byte2 = 0;
                ((VaatiArm_HeapStruct*)this->myHeap)->parent->subAction = 2;
            }
        }
    }
}

static void sub_08043420(Entity* this) {
    gUnk_080D1320[this->subAction](this);
    sub_08043ABC(this);
}

static void sub_08043440(Entity* this) {
    u32 i;
    int iVar4;
    u8* ptr;
    int offset;
    int zero;

    i = 0;
    iVar4 = 0;
    zero = 0;
    offset = 0x18;
    do {
        ptr = ((u8*)this->myHeap) + offset;
        if (ptr[5] >= 0x11) {
            ptr[5] -= 0x10;
            iVar4++;
        } else {
            ((u16*)ptr)[2] = zero;
        }
        offset += 0x10;
        i++;
    } while (i < 5);
    if (iVar4 == 0) {
        i = 0;
        do {
            ((VaatiArm_HeapStruct*)this->myHeap)->s1[i].unk00.HWORD = 0x8000;
            i++;
        } while (i < 5);
        this->subAction = 1;
        InitAnimationForceUpdate(this, 0x10);
    }
}

static void sub_08043490(Entity* this) {
    Entity* entity;
    Entity* entity2;
    Entity* entity3;

    entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
    if (entity->z.HALF.HI < -4) {
        entity->zVelocity = Q_16_16(1.5);
        this->subAction = 2;
        this->field_0x7c.BYTES.byte2 = 0;
        ((VaatiArm_HeapStruct*)this->myHeap)->parent->subAction = 2;
    } else {
        entity->z.HALF.HI -= 2;
        if (entity->z.HALF.HI < 0) {
            entity->flags = entity->flags | ENT_COLLIDE;
            entity->spriteSettings.draw = 1;
            entity->collisionFlags = entity->collisionFlags & 0xef;
            entity->hitType = 0x3a;
            entity->hitbox = (Hitbox*)&gUnk_080FD450;
            entity2 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[2];
            entity2->flags = entity2->flags | ENT_COLLIDE;
            entity3 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
            entity3->flags = entity3->flags & ~ENT_COLLIDE;
        }
    }
    UpdateAnimationSingleFrame(this);
}

static void sub_08043520(Entity* this) {
    Entity* entity;

    entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
    GravityUpdate(entity, Q_8_8(26.0));
    if ((entity->zVelocity < 0) && (-6 < entity->z.HALF.HI)) {
        entity->z.HALF.HI = -6;
        this->subAction = 3;
        this->field_0x7a.HWORD = 900;
    }
}

static void sub_0804355C(Entity* this) {
    sub_08043DB0(this);
    if (--this->field_0x7a.HWORD == 0) {
        this->subAction = 4;
    }
    UpdateAnimationSingleFrame(this);
}

static void sub_08043580(Entity* this) {
    Entity* entity;
    u32 i;

    ((VaatiArm_HeapStruct*)this->myHeap)->entities[4]->z.HALF.HI += 3;
    for (i = 0; i < 5; i++) {
        entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
        if (-4 < entity->z.HALF.HI) {
            entity->flags = entity->flags & ~ENT_COLLIDE;
            entity->spriteSettings.draw = 0;
        }
    }
    if ((this->spriteSettings.draw & 3) == 0) {
        this->subAction = 5;
        this->timer = 60;
        entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
        entity->collisionFlags = entity->collisionFlags | 0x10;
        entity->hitType = 0x39;
        entity->hitbox = (Hitbox*)&gUnk_080FD538;
        sub_0804AA1C(this);
    }
}

static void sub_080435F4(Entity* this) {
    Entity* entity;
    u32 i;
    VaatiArm_HeapStruct1* ptr;

    if (--this->timer == 0) {
        this->action = 6;
        this->subAction = 1;
        this->timer = 1;
        for (i = 0; i < 5; i++) {
            ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[i];
            ptr->unk00.HWORD = gUnk_080D1338[this->type2];
            ptr->unk04.HWORD = 0x4000;
            ptr->unk0c = 0;
            ptr->unk08 = gUnk_080D133C[this->type2];
            entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
            if (i == 0) {
                sub_08043B9C(entity);
            } else {
                InitializeAnimation(entity, gUnk_080D1340[i]);
            }
        }
    }
}

static void sub_08043680(Entity* this) {
    gUnk_080D1348[this->subAction](this);
}

static void sub_08043698(Entity* this) {
    Entity* entity;
    u32 i;

    this->subAction = 1;
    this->timer = 60;
    for (i = 0; i < 5; i++) {
        entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
        entity->flags = entity->flags & ~ENT_COLLIDE;
    }
}

static inline void deleteThing(Entity* this, const u32 index) {
    if (--this->timer == 0) {
        this->timer = 20;
        this->subAction = index + 1;
        if (index == 1) {
            this->spriteSettings.draw = 0;
        }
        CreateFx(((VaatiArm_HeapStruct*)this->myHeap)->entities[index], FX_GIANT_EXPLOSION4, 0);
        ((VaatiArm_HeapStruct*)this->myHeap)->entities[index]->myHeap = NULL;
        DeleteEntity(((VaatiArm_HeapStruct*)this->myHeap)->entities[index]);
    }
}

static void sub_080436C0(Entity* this) {
    deleteThing(this, 1);
}

static void sub_08043700(Entity* this) {
    deleteThing(this, 2);
}

static void sub_08043738(Entity* this) {
    deleteThing(this, 3);
}

static void sub_08043770(Entity* this) {
    Entity* entity;

    if (--this->timer == 0) {
        entity = ((VaatiArm_HeapStruct*)this->myHeap)->parent;
        if ((gRoomTransition.field_0x39 & 0xc) == 0) {
            entity->subAction = 2;
        }
        if (this->type2 == 0) {
            ((VaatiArm_HeapStruct*)entity->myHeap)->parent = NULL;
            gRoomTransition.field_0x39 &= 0xfe;
        } else {
            *(u32*)((VaatiArm_HeapStruct*)entity->myHeap)->s1 = 0;
            gRoomTransition.field_0x39 &= 0xfd;
        }
        ((VaatiArm_HeapStruct*)this->myHeap)->entities[4]->myHeap = NULL;
        ((VaatiArm_HeapStruct*)this->myHeap)->entities[4]->health = 0;
        (*(Entity**)&this->field_0x68)->parent = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
        DeleteThisEntity();
    }
}

static u32 sub_080437DC(Entity* this) {
    u16 temp;
    VaatiArm_HeapStruct* heapStruct;
    Entity* entity;

    if (gEntCount >= 0x44)
        return 0;
    heapStruct = zMalloc(sizeof(VaatiArm_HeapStruct));
    if (heapStruct == NULL)
        return 0;
    this->spritePriority.b0 = 5;
    this->collisionFlags = this->collisionFlags | 0x10;
    this->myHeap = (u32*)heapStruct;
    heapStruct->entities[0] = this;
    entity = CreateEnemy(VAATI_ARM, 1);
    entity->spritePriority.b0 = 5;
    entity->collisionFlags = entity->collisionFlags | 0x10;
    entity->myHeap = (u32*)heapStruct;
    heapStruct->entities[1] = entity;
    CopyPosition(this, entity);
    entity = CreateEnemy(VAATI_ARM, 2);
    entity->spritePriority.b0 = 5;
    entity->collisionFlags = entity->collisionFlags | 0x10;
    entity->myHeap = (u32*)heapStruct;
    heapStruct->entities[2] = entity;
    CopyPosition(this, entity);
    entity = CreateEnemy(VAATI_ARM, 3);
    entity->spritePriority.b0 = 5;
    entity->collisionFlags = entity->collisionFlags | 0x10;
    entity->myHeap = (u32*)heapStruct;
    heapStruct->entities[3] = entity;
    CopyPosition(this, entity);
    entity = CreateEnemy(VAATI_ARM, 4);
    entity->spritePriority.b0 = 5;
    entity->collisionFlags = entity->collisionFlags | 0x10;
    entity->myHeap = (u32*)heapStruct;
    heapStruct->entities[4] = entity;
    CopyPosition(this, entity);
    heapStruct->parent = this->parent;
    temp = gUnk_080D135C[this->type2];
    heapStruct->s1[0].unk00.HWORD = temp;
    heapStruct->s1[0].unk04.HWORD = 0x4000;
    heapStruct->s1[0].unk0c = 0;
    heapStruct->s1[1].unk00.HWORD = temp;
    heapStruct->s1[1].unk04.HWORD = 0x4000;
    heapStruct->s1[1].unk0c = 0;
    heapStruct->s1[2].unk00.HWORD = temp;
    heapStruct->s1[2].unk04.HWORD = 0x4000;
    heapStruct->s1[2].unk0c = 0;
    heapStruct->s1[3].unk00.HWORD = temp;
    heapStruct->s1[3].unk04.HWORD = 0x4000;
    heapStruct->s1[3].unk0c = 0;
    heapStruct->s1[4].unk00.HWORD = temp;
    heapStruct->s1[4].unk04.HWORD = 0x4000;
    heapStruct->s1[4].unk0c = 0;
    return 1;
}

void sub_0804393C(Entity* this) {
    s32 uVar1;
    s32 uVar2;
    s32 uVar6;
    s32 iVar7;
    VaatiArm_HeapStruct1* hs;
    Entity* ent;

    ent = ((VaatiArm_HeapStruct*)this->myHeap)->entities[0];
    if (ent->field_0x7c.BYTES.byte0 != 0 && ent->field_0x7c.BYTES.byte1 <= this->type) {
        uVar2 = gUnk_080D1362[this->type * 16 + ((ent->field_0x7c.BYTES.byte0 >> 3) & 0xf)];
    } else {
        uVar2 = 0;
    }
    hs = &((VaatiArm_HeapStruct*)this->myHeap)->s1[this->type];
    uVar2 = (uVar2 + hs->unk0c) << 8;
    uVar1 = -gSineTable[hs->unk04.HALF.HI + 0x40] * uVar2;
    uVar2 = (gSineTable[hs->unk04.HALF.HI & 0x7f] * uVar2) / 0x100;
    uVar6 = gSineTable[hs->unk00.HALF.HI] * uVar2;
    iVar7 = -gSineTable[hs->unk00.HALF.HI + 0x40] * uVar2;
    PositionRelative(((VaatiArm_HeapStruct*)this->myHeap)->entities[this->type + 1], this, uVar6, iVar7);
    this->z.WORD += uVar1;
    this->spriteOffsetY = ((VaatiArm_HeapStruct*)this->myHeap)->entities[this->type + 1]->spriteOffsetY;
}

static void sub_08043A10(Entity* this) {
    sub_08043B7C(this);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[4]);
    ((VaatiArm_HeapStruct*)this->myHeap)->entities[4]->y.HALF.HI -= 8;
    ((VaatiArm_HeapStruct*)this->myHeap)->entities[4]->z.HALF.HI -= 8;
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[3]);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[2]);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[1]);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[0]);
    ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->y.HALF.HI++;
    ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->spriteOffsetY--;
    if (this->field_0x7c.BYTES.byte0 != 0) {
        this->field_0x7c.BYTES.byte0--;
    }
}

static void sub_08043A78(Entity* this) {
    this->field_0x7c.BYTES.byte0 = 0;
    sub_08043B7C(this);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[2]);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[1]);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[0]);
    ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->y.HALF.HI++;
    ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->spriteOffsetY--;
}

static void sub_08043ABC(Entity* this) {
    this->field_0x7c.BYTES.byte0 = 0;
    sub_08043B7C(this);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[3]);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[2]);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[1]);
    sub_0804393C(((VaatiArm_HeapStruct*)this->myHeap)->entities[0]);
    ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->y.HALF.HI++;
    ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->spriteOffsetY--;
}

void sub_08043B08(Entity* this) {
    VaatiArm_HeapStruct1* hs1;
    VaatiArm_HeapStruct1* hs2;
    u32 bVar1;
    s32 uVar6;

    hs1 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[this->type - 1];
    hs2 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[this->type];
    bVar1 = gUnk_080D13B2[this->type];
    if (((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->type2 == 0) {
        uVar6 = (s8)((hs1->unk00.HALF.HI - hs2->unk00.HALF.HI));
        if (bVar1 < uVar6) {
            if (uVar6 <= 0) {
                hs2->unk00.HALF.HI = hs1->unk00.HALF.HI;
            } else {
                hs2->unk00.HALF.HI = hs1->unk00.HALF.HI - bVar1;
            }
        }
    } else {
        uVar6 = (s8)(hs2->unk00.HALF.HI - hs1->unk00.HALF.HI);
        if (bVar1 < uVar6) {
            if (uVar6 < 0) {
                hs2->unk00.HALF.HI = hs1->unk00.HALF.HI;
            } else {
                hs2->unk00.HALF.HI = hs1->unk00.HALF.HI + bVar1;
            }
        }
    }

    uVar6 = hs1->unk04.HALF.HI - hs2->unk04.HALF.HI;
    if ((bVar1 << 1) < uVar6 + bVar1) {
        if (uVar6 > 0) {
            hs2->unk04.HALF.HI = hs1->unk04.HALF.HI - bVar1;
        } else {
            hs2->unk04.HALF.HI = hs1->unk04.HALF.HI + bVar1;
        }
    }
}

static void sub_08043B7C(Entity* this) {
    sub_08043B08(((VaatiArm_HeapStruct*)this->myHeap)->entities[1]);
    sub_08043B08(((VaatiArm_HeapStruct*)this->myHeap)->entities[2]);
    sub_08043B08(((VaatiArm_HeapStruct*)this->myHeap)->entities[3]);
}

static void sub_08043B9C(Entity* this) {
    u32 index = ((((VaatiArm_HeapStruct*)this->myHeap)->s1[0].unk00.HALF.HI + 4) & 0xff) >> 3;
    if (gUnk_080D13B7[index] != this->frameIndex - 1) {
        InitAnimationForceUpdate(this, gUnk_080D13B7[index]);
    }
}

static void sub_08043BC8(Entity* this) {
    VaatiArm_HeapStruct1* pVVar2;
    const Coords* ptr;

    this->action = 2;
    ptr = &gUnk_080D13D8[this->type2];
    pVVar2 = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    pVVar2->unk08 = ptr->HALF.x;
    pVVar2->unk0a = ptr->HALF.y;
    pVVar2->unk0d = 0x5a;
    pVVar2->unk0e = 0x28;
}

static void sub_08043BF0(Entity* this) {
    u8 bVar1;
    u32 uVar2;
    VaatiArm_HeapStruct1* ptr;

    ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[0];
    if (this->type2 == 0) {
        bVar1 = ptr->unk00.HALF.HI;
        uVar2 = 6;
        if (((0x2f < bVar1) && (uVar2 = 7, 0x5f < bVar1)) && (uVar2 = 9, bVar1 < 0x90)) {
            uVar2 = 8;
        }
    } else {
        bVar1 = ptr->unk00.HALF.HI;
        uVar2 = 8;
        if (((bVar1 < 0xd1) && (uVar2 = 7, bVar1 < 0xa1)) && (uVar2 = 5, 0x70 < bVar1)) {
            uVar2 = 6;
        }
    }
    if (this->animIndex != uVar2) {
        InitAnimationForceUpdate(this, uVar2);
    }
}

static void sub_08043C40(Entity* this, VaatiArm_HeapStruct1* heapStruct) {
    u8* iVar3;
    int offset;
    const u8* puVar6;
    u32 i;

    if (heapStruct->unk04.HALF.HI < 0x20) {
        puVar6 = gUnk_080D13E0;
    } else {
        if (heapStruct->unk04.HALF.HI < 0x30) {
            puVar6 = gUnk_080D13E3;
        } else {
            if (heapStruct->unk04.HALF.HI < 0x78) {
                puVar6 = &gUnk_080D13E0[6];
            } else {
                puVar6 = gUnk_080D13E0;
            }
        }
    }
    for (i = 0, offset = 0x28; i < 3; offset += 0x10, i++) {
        iVar3 = (u8*)(int)((VaatiArm_HeapStruct*)this->myHeap) + offset;
        if (puVar6[i] != iVar3[0xc]) {
            if (puVar6[i] < iVar3[0xc]) {
                iVar3[0xc]--;
            } else {
                iVar3[0xc]++;
            }
        }
    }
}

static u32 sub_08043C98(Entity* this) {
#if defined EU || defined JP
    Entity* e1 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
    if ((e1->contactFlags == 0x9d)) {
        sub_08043D08(this);
        return 1;
    } else {
        return 0;
    }
#else
    Entity* e1 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[2];
    Entity* e2 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
    if ((e1->contactFlags == 0x9d) || (e2->contactFlags == 0x9d)) {
        sub_08043D08(this);
        gRoomTransition.field_0x38 |= 2;
        return 1;
    } else {
        return 0;
    }
#endif
}

static void sub_08043CD4(Entity* this) {
    u32 i;
    for (i = 0; i < 5; i++) {
        if (((VaatiArm_HeapStruct*)this->myHeap)->entities[i]->contactFlags == 0x9d) {
            this->field_0x7c.BYTES.byte0 = 0x78;
            this->field_0x7c.BYTES.byte1 = i;
            return;
        }
    }
}

static void sub_08043D08(Entity* this) {
    Entity* entity;
    Entity* fx;
    u32 i;

    this->action = 7;
    this->subAction = 0;
    InitAnimationForceUpdate(this, 0xd);
    entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
    entity->flags &= ~ENT_COLLIDE;
    entity->spriteSettings.draw = 0;
    InitializeAnimation(entity, 0x13);
    sub_0804AA1C(entity);
    fx = CreateFx(entity, FX_GIANT_EXPLOSION4, 0);
    if (fx != NULL) {
        fx->x.HALF.HI += gUnk_080D13E9[this->type2];
        fx->y.HALF.HI -= 6;
        fx->spritePriority.b0 = 3;
    }
    CopyPosition(((VaatiArm_HeapStruct*)this->myHeap)->entities[3], entity);
    entity->z.HALF.HI += ((VaatiArm_HeapStruct*)this->myHeap)->s1[3].unk0c;
    for (i = 0; i < 5; i++) {
        ((VaatiArm_HeapStruct*)this->myHeap)->entities[i]->hitType = 0x39;
    }
    EnqueueSFX(SFX_HIT);
}

static void sub_08043DB0(Entity* this) {
    s32 cVar1;
    Entity* pEVar2;
    Entity* pEVar3;
    Entity* pEVar4;

    if (((gPlayerState.flags & PL_MINISH) != 0)) {
        pEVar3 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
        if (CheckPlayerInRegion(pEVar3->x.HALF.HI - gRoomControls.origin_x,
                                pEVar3->y.HALF.HI - gRoomControls.origin_y + 2, 3, 3)) {
            DoExitTransition(&gUnk_080D13EC);
            if ((gRoomTransition.field_0x39 & 3) != 3) {
                gRoomTransition.player_status.room_next = 1;
            }
            cVar1 = this->field_0x7a.HWORD;
            gRoomTransition.field_0x3d = 0x1e - (cVar1 / 0x3c);
            gRoomTransition.field_0x3c = this->type2;
            pEVar2 = ((VaatiArm_HeapStruct*)this->myHeap)->parent;
            gRoomTransition.field_0x40 = pEVar2->x.HALF.HI;
            gRoomTransition.field_0x42 = pEVar2->y.HALF.HI;
            pEVar4 = ((VaatiArm_HeapStruct*)pEVar2->myHeap)->parent;
            if (pEVar4 != NULL) {
                gRoomTransition.field_0x44 = pEVar4->x.HALF.HI;
                gRoomTransition.field_0x46 = pEVar4->y.HALF.HI;
            } else {
                gRoomTransition.field_0x44 = gRoomControls.origin_x + 0x110;
                gRoomTransition.field_0x46 = gRoomControls.origin_y + 0x60;
            }
            pEVar4 = (Entity*)(*(int*)((VaatiArm_HeapStruct*)pEVar2->myHeap)->s1);
            if (pEVar4 != NULL) {
                gRoomTransition.field_0x48 = pEVar4->x.HALF.HI;
                gRoomTransition.field_0x4a = pEVar4->y.HALF.HI;
            } else {
                gRoomTransition.field_0x48 = gRoomControls.origin_x + 0x110;
                gRoomTransition.field_0x4a = gRoomControls.origin_y + 0x60;
            }
        }
    }
}

static void sub_08043EB8(Entity* this) {
    u32 i;
    Entity* pEVar4;
    VaatiArm_HeapStruct1* ptr;

    COLLISION_ON(this);
    this->spritePriority.b0 = 4;
    InitAnimationForceUpdate(this, 0xd);
    pEVar4 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[1];
    pEVar4->flags = pEVar4->flags | ENT_COLLIDE;
    pEVar4->spritePriority.b0 = 4;
    pEVar4 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[2];
    pEVar4->flags = pEVar4->flags | ENT_COLLIDE;
    pEVar4->spritePriority.b0 = 4;
    pEVar4 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
    pEVar4->flags = pEVar4->flags & ~ENT_COLLIDE;
    pEVar4->spriteSettings.draw = 1;
    pEVar4->spritePriority.b0 = 4;
    pEVar4 = ((VaatiArm_HeapStruct*)this->myHeap)->entities[4];
    pEVar4->flags = pEVar4->flags | ENT_COLLIDE;
    pEVar4->spriteSettings.draw = 1;
    pEVar4->spritePriority.b0 = 4;
    pEVar4->x.HALF.HI = (this->type2 == 0) ? gRoomTransition.field_0x44 : gRoomTransition.field_0x48;
    pEVar4->y.HALF.HI = (this->type2 == 0) ? gRoomTransition.field_0x46 : gRoomTransition.field_0x4a;
    pEVar4->z.HALF.HI = 0;
    pEVar4->collisionFlags = pEVar4->collisionFlags & 0xef;
    pEVar4->hitType = 0x3a;
    pEVar4->hitbox = (Hitbox*)&gUnk_080FD450;
    pEVar4 = CreateObject(VAATI3_ARM, 0, 0);
    if (pEVar4 != NULL) {
        pEVar4->parent = ((VaatiArm_HeapStruct*)this->myHeap)->entities[3];
    }
    *(Entity**)&((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->field_0x68 = pEVar4;
    for (i = 0; i < 5; i++) {
        ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[i];
        ptr->unk00.HWORD = 0x8000;
        ptr->unk04.HWORD = 0;
        ptr->unk0c = gUnk_080D1419[i];
    }
}

void sub_08044000(Entity* this) {
    Entity* entity;
    u32 i;
    VaatiArm_HeapStruct1* ptr;
    const u16* ptr2;

    ptr2 = gUnk_080D1400[this->type2];
    for (i = 0; i < 5; i++) {
        entity = ((VaatiArm_HeapStruct*)this->myHeap)->entities[i];
        entity->flags = entity->flags | 0x80;
        entity->spritePriority.b0 = 4;
        ptr = &((VaatiArm_HeapStruct*)this->myHeap)->s1[i];
        ptr->unk00.HWORD = ptr2[i];
        ptr->unk04.HWORD = 0x4000;
        ptr->unk0c = gUnk_080D1414[i];
    }
    InitAnimationForceUpdate(this, 7);
    CopyPosition(((VaatiArm_HeapStruct*)this->myHeap)->parent, ((VaatiArm_HeapStruct*)this->myHeap)->entities[4]);
}

static void sub_08044078(Entity* this) {
    if (this->action == 0) {
        this->action = 1;
        if (this->type != 3 ||
            !(((gRoomTransition.field_0x38 & 1) == 0 ||
               (((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->type2 != gRoomTransition.field_0x3c)))) {
            InitializeAnimation(this, 0x12);
        } else {
            InitializeAnimation(this, 0x11);
        }
    }
    GetNextFrame(this);
}

static void sub_080440CC(Entity* this) {
    if (this->action == 0) {
        this->action = 1;
        if ((gRoomTransition.field_0x38 & 1) != 0 &&
            ((VaatiArm_HeapStruct*)this->myHeap)->entities[0]->type2 == gRoomTransition.field_0x3c) {
            InitializeAnimation(this, 0x13);
        } else {
            InitializeAnimation(this, 0x11);
        }
    }
    GetNextFrame(this);
}

#include "enemy.h"
#include "entity.h"

void (*const gUnk_080D1CC8[])(Entity*);
void (*const gUnk_080D1CE0[])(Entity*);

void Curtain(Entity* this) {
    EnemyFunctionHandler(this, gUnk_080D1CC8);
}

void sub_080481D0(Entity* this) {
    gUnk_080D1CE0[this->action](this);
}

void sub_080481E8(Entity* this) {
    if (this->field_0x46) {
        this->action = 2;
        this->flags &= ~ENT_COLLIDE;
        this->spritePriority.b0 = 7;
        this->actionDelay = 3;
    } else {
        this->actionDelay = 2;
    }

    InitializeAnimation(this, this->actionDelay);
}

void nullsub_26() {
}

void sub_08048224(Entity* this) {
    this->spritePriority.b0 = 4;

    if (CheckLocalFlag(0x72) == 0) {
        this->action = 1;
        this->actionDelay = 0;
    } else {
        this->action = 3;
        this->flags &= ~ENT_COLLIDE;
        this->actionDelay = 1;
    }

    InitializeAnimation(this, this->actionDelay);
}

void sub_08048268(Entity* this) {
    if (this->actionDelay == 0) {
        return;
    }

    GetNextFrame(this);
    if (this->frame & 0x80) {
        this->actionDelay = 0;
        InitializeAnimation(this, 0);
    }
}

void sub_08048294(Entity* this) {
    GetNextFrame(this);

    if (this->frame & 0x80) {
        this->action = 3;
        SetLocalFlag(0x72);
        InitializeAnimation(this, 1);
    }
}

void nullsub_27() {
}

void (*const gUnk_080D1CC8[])(Entity*) = {
    sub_080481D0, sub_080481E8, sub_08001324, sub_0804A7D4, sub_08001242, nullsub_26,
};

void (*const gUnk_080D1CE0[])(Entity*) = {
    sub_08048224,
    sub_08048268,
    sub_08048294,
    nullsub_27,
};

#define NENT_DEPRECATED
#include "global.h"
#include "entity.h"
#include "enemy.h"
#include "player.h"
#include "functions.h"
#include "enemy/gyorg.h"

void sub_080489B4(GyorgFemaleEyeEntity*);
void sub_080489CC(GyorgFemaleEyeEntity*);

void sub_08048AF0(GyorgFemaleEyeEntity*);
void sub_08048B2C(GyorgFemaleEyeEntity*);
void sub_08048B84(GyorgFemaleEyeEntity*);
void sub_08048BB0(GyorgFemaleEyeEntity*);
void sub_08048CEC(GyorgFemaleEyeEntity*);

void sub_08048D20(GyorgFemaleEyeEntity*);
u32 sub_08048D70(GyorgFemaleEntity*);

void (*const gUnk_080D1F64[])(GyorgFemaleEyeEntity*) = {
    sub_080489B4,
    sub_080489CC,
    (void (*)(GyorgFemaleEyeEntity*))sub_08001324,
    (void (*)(GyorgFemaleEyeEntity*))sub_0804A7D4,
    (void (*)(GyorgFemaleEyeEntity*))sub_08001242,
    sub_080489B4,
};

void GyorgFemaleEye(Entity* this) {
    if (this->parent->next == NULL) {
        DeleteThisEntity();
    }
    gUnk_080D1F64[GetNextFunction(this)]((GyorgFemaleEyeEntity*)this);
}

void sub_080489B4(GyorgFemaleEyeEntity* this) {
    static void (*const gUnk_080D1F7C[])(GyorgFemaleEyeEntity*) = {
        sub_08048AF0, sub_08048B2C, sub_08048B84, sub_08048BB0, sub_08048CEC,
    };
    gUnk_080D1F7C[super->action](this);
}

typedef struct {
    u16 x, y;
} xy;

const xy gUnk_080D1F90[] = {
    { 0x1e8, 0x1d8 }, { 0x1f8, 0x1d8 }, { 0x208, 0x1d8 }, { 0x218, 0x1d8 }, { 0x1e8, 0x1e8 }, { 0x1f8, 0x1e8 },
    { 0x208, 0x1e8 }, { 0x218, 0x1e8 }, { 0x238, 0x1f8 }, { 0x238, 0x208 }, { 0x238, 0x218 }, { 0x238, 0x228 },
    { 0x228, 0x1f8 }, { 0x228, 0x208 }, { 0x228, 0x218 }, { 0x228, 0x228 }, { 0x218, 0x248 }, { 0x208, 0x248 },
    { 0x1f8, 0x248 }, { 0x1e8, 0x248 }, { 0x218, 0x238 }, { 0x208, 0x238 }, { 0x1f8, 0x238 }, { 0x1e8, 0x238 },
    { 0x1c8, 0x228 }, { 0x1c8, 0x218 }, { 0x1c8, 0x208 }, { 0x1c8, 0x1f8 }, { 0x1d8, 0x228 }, { 0x1d8, 0x218 },
    { 0x1d8, 0x208 }, { 0x1d8, 0x1f8 },
};

const u8 gUnk_080D2010[] = {
    0, 0, 1, 1, 0, 0, 1, 1, 4, 4, 5, 5, 4, 4, 5, 5, 9, 9, 8, 8, 9, 9, 8, 8, 13, 13, 12, 12, 13, 13, 12, 12,
};

const u8 gUnk_080D2030[] = {
    2, 2, 3, 3, 2, 2, 3, 3, 6, 6, 7, 7, 6, 6, 7, 7, 11, 11, 10, 10, 11, 11, 10, 10, 15, 15, 14, 14, 15, 15, 14, 14,
};

void sub_080489CC(GyorgFemaleEyeEntity* this) {
    GyorgFemaleEntity* parent;
    if (super->health != 0xFF) {
        parent = (GyorgFemaleEntity*)super->parent;
#ifndef EU
        if ((parent->unk_78 >> super->type) & 1) {
#endif
            parent->unk_7c |= (1 << super->type);
#ifndef EU
            switch (super->bitfield & 0x7F) {
                case 4 ... 6:
                case 8 ... 13:
                case 16 ... 18:
                case 24 ... 26:
#endif
                    (*(((GyorgFemaleHeap**)&parent->base.myHeap)))->unk_18[super->type] = super->field_0x4c;
                    (*(((GyorgFemaleHeap**)&parent->base.myHeap)))->unk_38 =
                        (gPlayerEntity.x.HALF.HI + super->x.HALF.HI) / 2;
                    (*(((GyorgFemaleHeap**)&parent->base.myHeap)))->unk_3a =
                        (gPlayerEntity.y.HALF.HI + super->y.HALF.HI) / 2;
                    (*(((GyorgFemaleHeap**)&parent->base.myHeap)))->unk_3c = (super->knockbackDirection ^= 0x10);
#ifndef EU
                    break;
                default:
                    ((GyorgFemaleHeap*)parent->base.myHeap)->unk_3c = 0xFF;
                    break;
            }
        }
#endif
    }
    super->health = 0xFF;
    sub_0804AA30(super, (void (*const*)(Entity*))gUnk_080D1F64);
}

void sub_08048AF0(GyorgFemaleEyeEntity* this) {
    super->action = 1;
    super->animationState = 0xFF;
    super->spriteOrientation.flipY = 2;
    super->spriteRendering.b3 = 2;
    super->spritePriority.b0 = 7;
    super->collisionLayer = 2;
    sub_08048D20(this);
}

void sub_08048B2C(GyorgFemaleEyeEntity* this) {
    GyorgFemaleEntity* parent;
    sub_08048D20(this);
    parent = (GyorgFemaleEntity*)super->parent;
    if (sub_08048D70(parent)) {
        if (!super->spriteSettings.draw) {
            CreateFx(super, 2, 0x40);
        }
        super->spriteSettings.draw = 1;
    } else {
        super->spriteSettings.draw = 0;
    }
    if ((parent->unk_78 >> super->type) & 1) {
        super->action = 2;
    }
}

void sub_08048B84(GyorgFemaleEyeEntity* this) {
    GetNextFrame(super);
    if (super->frame & 0x80) {
        super->action = 3;
        super->flags |= 0x80;
        super->hitType = 0x1E;
    }
}

void sub_08048BB0(GyorgFemaleEyeEntity* this) {
    GyorgFemaleEntity* parent = (GyorgFemaleEntity*)super->parent;
    if (!((parent->unk_78 >> super->type) & 1)) {
        if (parent->base.health != 0) {
            super->action = 4;
            super->flags &= ~0x80;
            InitializeAnimation(super, gUnk_080D2030[(super->animationState << 3) + super->type]);
        } else {
            super->action = 1;
            super->flags &= ~0x80;
            super->spriteSettings.draw = 0;
            InitializeAnimation(super, gUnk_080D2010[(super->animationState << 3) + super->type]);
            CreateFx(super, 2, 0x40);
        }
    } else {
        if ((parent->unk_80 >> super->type) & 1) {
            if (super->animIndex <= 0x13) {
                super->iframes = 0xF4;
                super->hitType = 0x89;
                InitializeAnimation(super, (parent->base.animationState >> 6) + 0x14);
                SoundReq(0x119);
            }
            GetNextFrame(super);
            if (super->frame & 0x80) {
                super->hitType = 0x1E;
                InitializeAnimation(super, gUnk_080D2010[(super->animationState << 3) + super->type]);
                UpdateAnimationVariableFrames(super, 7);
                parent->unk_80 &= ~(1 << super->type);
            }
        } else {
            if (parent->unk_78 == 0xFF) {
                u32 tmp = super->animIndex;
                if (tmp < 0x10 || tmp > 0x13) {
                    InitializeAnimation(super, super->animationState + 0x10);
                    UpdateAnimationVariableFrames(super, Random() & 0x1C);
                }
                GetNextFrame(super);
            }
        }
    }
}

void sub_08048CEC(GyorgFemaleEyeEntity* this) {
    GetNextFrame(super);
    if (super->frame & 0x80) {
        super->action = 1;
        InitializeAnimation(super, gUnk_080D2010[(super->animationState << 3) + super->type]);
    }
}
void sub_08048D20(GyorgFemaleEyeEntity* this) {
    GyorgFemaleEntity* parent = (GyorgFemaleEntity*)super->parent;
    const xy* tmp;
    u32 tmp2 = (parent->base.animationState >> 6);
    if (tmp2 != super->animationState) {
        super->animationState = tmp2;
        tmp = &gUnk_080D1F90[super->type + (tmp2 << 3)];
        super->x.HALF.HI = tmp->x + gRoomControls.roomOriginX;
        super->y.HALF.HI = tmp->y + gRoomControls.roomOriginY;
        InitializeAnimation(super, gUnk_080D2010[super->type + (tmp2 << 3)]);
    }
}

u32 sub_08048D70(GyorgFemaleEntity* parent) {
    GenericEntity* tmp;
    if (parent->base.health != 0) {
        return 1;
    }
    tmp = ((GyorgFemaleHeap*)parent->base.myHeap)->male1;
    if (!tmp) {
        tmp = ((GyorgFemaleHeap*)parent->base.myHeap)->male2;
    }
    if (tmp->base.health != 0) {
        return 0;
    }
    return 1;
}

/**
 * @file itemOnGround.c
 * @ingroup Objects
 *
 * @brief Item On Ground object
 */
#define NENT_DEPRECATED
#include "collision.h"
#include "entity.h"
#include "flags.h"
#include "functions.h"
#include "global.h"
#include "hitbox.h"
#include "item.h"
#include "itemMetaData.h"
#include "object.h"
#include "player.h"
#include "sound.h"
#include "playeritem.h"

typedef struct {
    Entity base;
    u8 unk68;
    u8 unk69;
    u8 unused6a;
    u16 despawnTimer;
    u16 tileType;
    u16 filler[11];
    u16 flag;
} ItemOnGroundEntity;

void sub_08081150(ItemOnGroundEntity*);
u8 GetGustJarFlagsForItem(Item);
void ItemOnGround_InitDespawnTimer(ItemOnGroundEntity*);
u32 ItemOnGround_DespawnTimerTick(ItemOnGroundEntity*);
void ItemOnGround_GravityUpdateWithBounce(ItemOnGroundEntity*);
void ItemOnGround_GravityUpdate(ItemOnGroundEntity*);
void ItemOnGround_PickUp1(ItemOnGroundEntity*);
void ItemOnGround_GustJarAction(ItemOnGroundEntity* this);
void ItemOnGround_PickUp2(ItemOnGroundEntity*);
void sub_080810A8(ItemOnGroundEntity*);
void sub_08081188(ItemOnGroundEntity*);
void ItemOnGround_Action2_Default(ItemOnGroundEntity* this);
void ItemOnGround_Action2_2(ItemOnGroundEntity* this);
void ItemOnGround_Action2_3(ItemOnGroundEntity* this);
void ItemOnGround_Action2_Nop1(ItemOnGroundEntity* this);
void ItemOnGround_Action2_Bounce(ItemOnGroundEntity* this);
void ItemOnGround_Action2_7(ItemOnGroundEntity* this);
void ItemOnGround_UnderWater(ItemOnGroundEntity* this);
void ItemOnGround_Action2_Nop2(ItemOnGroundEntity* this);
void ItemOnGround_GustJarAction0(ItemOnGroundEntity* this);
void ItemOnGround_GustJarAction1(ItemOnGroundEntity* this);
void ItemOnGround_GustJarAction2(ItemOnGroundEntity* this);
bool32 CheckShouldPlayItemGetCutscene(ItemOnGroundEntity*);

void ItemOnGround_Init(ItemOnGroundEntity*);
void ItemOnGround_Action1(ItemOnGroundEntity*);
void ItemOnGround_Action2(ItemOnGroundEntity*);
void ItemOnGround_OnBoomerang(ItemOnGroundEntity*);
void ItemOnGround_Collected(ItemOnGroundEntity*);
void ItemOnGround(Entity* this) {
    static void (*const ItemOnGround_Actions[])(ItemOnGroundEntity*) = {
        ItemOnGround_Init, ItemOnGround_Action1, ItemOnGround_Action2, ItemOnGround_OnBoomerang, ItemOnGround_Collected,
    };
    if (this->contactFlags & 0x80) {
        switch (this->contactFlags & 0x7F) {
            case 20:
                // boomerang
                this->action = 3;
                COLLISION_OFF(this);
                this->spriteSettings.draw = 1;
                this->collisionFlags |= 0x10;
                this->child = this->contactedEntity;
                break;
            case 0:
            case 1:
            case 4:
            case 5:
            case 6:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 30:
                ItemOnGround_PickUp1((ItemOnGroundEntity*)this);
                break;
        }
    }

    if (sub_0806F520(this)) {
        ItemOnGround_GustJarAction((ItemOnGroundEntity*)this);
    } else {
        ItemOnGround_Actions[this->action]((ItemOnGroundEntity*)this);
    }

    if (this->type == ITEM_KINSTONE) {
        gRoomVars.field_0x4++;
    }

    sub_08080CB4(this);
}

void ItemOnGround_Init3(ItemOnGroundEntity* this);
void ItemOnGround_Init7(ItemOnGroundEntity* this);
void ItemOnGround_Init8(ItemOnGroundEntity* this);
void ItemOnGround_Init9(ItemOnGroundEntity* this);
void ItemOnGround_Init(ItemOnGroundEntity* this) {
    static void (*const sSubactions[])(ItemOnGroundEntity*) = {
        sub_080810A8, ItemOnGround_PickUp2,       sub_08081150,       ItemOnGround_Init3, sub_08081188, sub_080810A8,
        sub_080810A8, ItemOnGround_Init7, ItemOnGround_Init8, ItemOnGround_Init9, sub_080810A8,
    };
    if (this->flag && CheckFlags(this->flag)) {
        DeleteThisEntity();
    }

    if (super->type != ITEM_FAIRY) {
        super->spriteSettings.draw = 1;
        super->spritePriority.b1 = 3;
        super->spriteSettings.shadow = 0;
        super->hitType = 7;
        super->collisionFlags = 0x47;
        super->hurtType = 0x44;
        super->health = 0xFF;
        super->hitbox = (Hitbox*)&gUnk_080FD1A8;
        switch (super->type) {
            case ITEM_SHELLS:
            case ITEM_RUPEE1:
            case ITEM_RUPEE5:
            case ITEM_RUPEE20:
            case ITEM_RUPEE50:
            case ITEM_RUPEE100:
            case ITEM_KINSTONE:
            case ITEM_BOMBS5:
            case ITEM_ARROWS5:
            case ITEM_HEART:
                super->flags2 = 0x17;
                break;
            default:
                super->flags2 = 0x11;
                break;
        }

        this->unk69 = super->timer;
        this->unused6a = 0;
        this->despawnTimer = 0;
        this->unk68 = 0;
        super->timer = 0;
        SetDefaultPriority(super, PRIO_NO_BLOCK);
        super->gustJarFlags = GetGustJarFlagsForItem(super->type);
        sSubactions[this->unk69](this);
    } else {
        Entity* entity = CreateObject(FAIRY, 0x60, 0);
        if (entity != NULL) {
            entity->timer = 0;
            if (super->timer == 1) {
                entity->type2 = 2;
            }
            CopyPosition(super, entity);
            DeleteThisEntity();
        }
    }
}

void sub_080810A8(ItemOnGroundEntity* this) {
    super->action = 1;
    ItemOnGround_InitDespawnTimer(this);
    if (super->direction & 0x80) {
        super->direction &= 0x1F;
        if (super->speed == 0) {
            super->speed = 0x100;
        }
    } else {
        super->direction |= 0xFF;
    }

    if (super->zVelocity == 0) {
        super->zVelocity = Q_16_16(1.875);
    }

    if (super->collisionLayer == 2) {
        ResolveCollisionLayer(super);
    }
}

void ItemOnGround_PickUp2(ItemOnGroundEntity* this) {
    if (super->type != ITEM_HEART) {
        ItemOnGround_PickUp1(this);
    } else {
        super->action = 2;
        super->subAction = 0;
        COLLISION_ON(super);
        super->flags2 = 0x11;
        CopyPosition(&gPlayerEntity, super);
    }
}

void ItemOnGround_Init3(ItemOnGroundEntity* this) {
    ItemOnGround_InitDespawnTimer(this);
    this->despawnTimer += 80;
    sub_08081150(this);
}

void sub_08081150(ItemOnGroundEntity* this) {
    super->action = 2;
    COLLISION_ON(super);
    super->z.HALF.HI = -0x80;
    super->spriteOrientation.flipY = 1;
    super->spriteRendering.b3 = 1;
    SoundReq(SFX_12D);
}

void sub_08081188(ItemOnGroundEntity* this) {
    super->action = 2;
    COLLISION_ON(super);
    if (super->collisionLayer == 2) {
        ResolveCollisionLayer(super);
    }
}

void ItemOnGround_Init7(ItemOnGroundEntity* this) {
    super->action = 2;
    super->spriteSettings.draw = 0;
    this->tileType = GetTileTypeByEntity(super);
}

void ItemOnGround_Init8(ItemOnGroundEntity* this) {
    super->action = 2;
    super->spriteSettings.draw = 0;
}

void ItemOnGround_Init9(ItemOnGroundEntity* this) {
    sub_08081188(this);
    SoundReq(SFX_215);
}

void ItemOnGround_Action1(ItemOnGroundEntity* this) {
    if (this->unk69 != 6) {
        ProcessMovement2(super);
    } else {
        LinearMoveUpdate(super);
    }

    GravityUpdate(super, Q_16_16(0.15625));
    if (super->zVelocity <= 0) {
        super->action = 2;
        COLLISION_ON(super);
        ItemOnGround_InitDespawnTimer(this);
    }
}

void ItemOnGround_Action2(ItemOnGroundEntity* this) {
    static void (*const sSubactions[])(ItemOnGroundEntity*) = {
        ItemOnGround_Action2_Default, ItemOnGround_Action2_Default, ItemOnGround_Action2_2,
        ItemOnGround_Action2_3,       ItemOnGround_Action2_Nop1,    ItemOnGround_Action2_Bounce,
        ItemOnGround_Action2_Default, ItemOnGround_Action2_7,       ItemOnGround_UnderWater,
        ItemOnGround_Action2_Nop2,    ItemOnGround_Action2_Default,
    };
    sSubactions[this->unk69](this);
}

void ItemOnGround_Action2_Default(ItemOnGroundEntity* this) {
    ItemOnGround_GravityUpdateWithBounce(this);
    if (ItemOnGround_DespawnTimerTick(this)) {
        DeleteThisEntityWithFlag(super, FALSE);
    } else {
        sub_0800442E(super);
    }
}

void ItemOnGround_Action2_2(ItemOnGroundEntity* this) {
    UpdateAnimationSingleFrame(super);
    ItemOnGround_GravityUpdate(this);
}

void ItemOnGround_Action2_3(ItemOnGroundEntity* this) {
    if (ItemOnGround_DespawnTimerTick(this)) {
        DeleteThisEntityWithFlag(super, FALSE);
    } else {
        ItemOnGround_GravityUpdate(this);
    }
}

void ItemOnGround_Action2_Nop1(ItemOnGroundEntity* this) {
}

void ItemOnGround_Action2_Bounce(ItemOnGroundEntity* this) {
    ItemOnGround_GravityUpdateWithBounce(this);
}

void ItemOnGround_Action2_7(ItemOnGroundEntity* this) {
    if (sub_080B1B0C(super) != 0xF && this->tileType != GetTileTypeByEntity(super)) {
        super->direction = 0;
        super->speed = 0;
        super->spriteSettings.draw = 1;
        this->unk69 = 0;
        sub_080810A8(this);
    }
}

void ItemOnGround_UnderWater(ItemOnGroundEntity* this) {
    PlayerState* playerState = &gPlayerState;
#ifdef EU
    if ((playerState->swim_state & 0x80) && IsColliding(super, &gPlayerEntity)) {
#else
    if ((playerState->swim_state & 0x80) && (playerState->flags & PL_MINISH) == 0 &&
        IsColliding(super, &gPlayerEntity)) {
#endif
        ItemOnGround_PickUp2(this);
    }
}

void ItemOnGround_Action2_Nop2(ItemOnGroundEntity* this) {
}

void ItemOnGround_OnBoomerang(ItemOnGroundEntity* this) {
    Entity* other = super->child;
    if (!(other->kind == PLAYER_ITEM && other->id == PLAYER_ITEM_BOOMERANG)) {
        DeleteThisEntityWithFlag(super, FALSE);
    } else {
        CopyPosition(other, super);
        super->z.HALF.HI--;
        other = &gPlayerEntity;
        if (IsColliding(super, other)) {
            ItemOnGround_PickUp2(this);
        }
    }
}

void ItemOnGround_Collected(ItemOnGroundEntity* this) {
    if (--super->timer) {
        Entity* other = super->child;
        super->x.WORD = other->x.WORD;
        super->y.WORD = other->y.WORD;
        super->spriteOrientation.flipY = other->spriteOrientation.flipY;
        super->spriteRendering.b3 = other->spriteRendering.b3;
        GravityUpdate(super, Q_16_16(0.15625));
    } else {
        DeleteThisEntityWithFlag(super, TRUE);
    }
}

void ItemOnGround_GustJarAction(ItemOnGroundEntity* this) {
    static void (*const subActionFuncs[])(ItemOnGroundEntity*) = {
        ItemOnGround_GustJarAction0,
        ItemOnGround_GustJarAction1,
        ItemOnGround_GustJarAction2,
    };
    subActionFuncs[super->subAction](this);
}

void ItemOnGround_GustJarAction0(ItemOnGroundEntity* this) {
    super->subAction = 1;
    super->gustJarTolerance = 1;
    super->spriteSettings.draw = 1;
}

void ItemOnGround_GustJarAction1(ItemOnGroundEntity* this) {
    sub_0806F4E8(super);
}

void ItemOnGround_GustJarAction2(ItemOnGroundEntity* this) {
    if (sub_0806F3E4(super)) {
        ItemOnGround_PickUp2(this);
    }
}

/**
 * deletes current entity (DeleteThisEntity)
 * if setFlag is given and the given entity has an associated flag (at 0x86), it will be set
 * @param this
 * @param setFlag
 */
void DeleteThisEntityWithFlag(Entity* this, u32 setFlag) {
    // could be a different entity, but doesn't matter in this
    ItemOnGroundEntity* this2 = (ItemOnGroundEntity*)this;
    if (setFlag && this2->flag) {
        SetFlag(this2->flag);
    }

    DeleteThisEntity();
}

bool32 ItemOnGround_PickUp(ItemOnGroundEntity* this) {
    if (CheckShouldPlayItemGetCutscene(this)) {
        SetDefaultPriority(super, PRIO_PLAYER_EVENT);
        CreateItemEntity(super->type, super->type2, 0);
        return TRUE;
    } else {
        GiveItem(super->type, super->type2);
        return FALSE;
    }
}

bool32 CheckShouldPlayItemGetCutscene(ItemOnGroundEntity* this) {
    return ((gItemMetaData[super->type].unk3 & 0x2) || !GetInventoryValue(super->type));
}

typedef struct {
    u8 unk0[2];
    u16 sfx;
    u8 gustJarFlags;
    u8 unk5[3];
} Unk_0811E84C;

static const Unk_0811E84C gUnk_0811E84C[118] = {
    [ITEM_SHELLS] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_DUNGEON_MAP] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_COMPASS] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_BIG_KEY] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_SMALL_KEY] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE1] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE5] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE20] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE50] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE100] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE200] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_KINSTONE] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_BOMBS5] = { { 0x0, 0x0 }, SFX_HEART_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_ARROWS5] = { { 0x0, 0x0 }, SFX_HEART_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_HEART] = { { 0x0, 0x0 }, SFX_HEART_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
};

u8 GetGustJarFlagsForItem(Item item) {
    const Unk_0811E84C* entry = &gUnk_0811E84C[item];
    return entry->gustJarFlags;
}

void PlayItemSfx(Item item) {
    const Unk_0811E84C* entry = &gUnk_0811E84C[item];
    if (entry->sfx) {
        SoundReq(entry->sfx);
    }
}

void ItemOnGround_InitDespawnTimer(ItemOnGroundEntity* this) {
    if (this->unk69 == 10) {
        this->despawnTimer = 120;
    } else {
        this->despawnTimer = 600;
    }
}

/**
 * ticks the item's despawn timer
 * @param this
 * @return true if timer reached 0, false otherwise
 */
u32 ItemOnGround_DespawnTimerTick(ItemOnGroundEntity* this) {
    if (!AnyPrioritySet()) {
        if (--this->despawnTimer == 0) {
            return TRUE;
        }

        if (this->despawnTimer < 90) {
            super->spriteSettings.draw ^= 1;
        }
    }

    return FALSE;
}

void ItemOnGround_GravityUpdateWithBounce(ItemOnGroundEntity* this) {
    if (this->unk68 == 0) {
        u32 var0 = GravityUpdateWithBounce(super, Q_16_16(0.15625));
        if (var0 == 0) {
            this->unk68 = 1;
        } else {
            if (var0 == 1) {
                PlayItemSfx(super->type);
                UpdateSpriteForCollisionLayer(super);
            }

            ProcessMovement2(super);
        }
    }
}

// has a manual bounce
// FoW?
void ItemOnGround_GravityUpdate(ItemOnGroundEntity* this) {
    if (this->unk68 > 1)
        return;

    if (this->unk68 == 0) {
        if (!GravityUpdate(super, Q_16_16(0.0625)) && !sub_0800442E(super)) {
            this->unk68 = 1;
            super->zVelocity = Q_16_16(1.875);
            PlayItemSfx(super->type);
            UpdateSpriteForCollisionLayer(super);
        }
    } else {
        if (!GravityUpdate(super, Q_16_16(0.15625))) {
            this->unk68 = 2;
            PlayItemSfx(super->type);
        }
    }
}

void ItemOnGround_PickUp1(ItemOnGroundEntity* this) {
    if (super->health == 0) {
        DeleteThisEntityWithFlag(super, TRUE);
    }

    COLLISION_OFF(super);
    super->action = 4;
    super->timer = 14;
    super->zVelocity = Q_16_16(2.0);
    super->spriteSettings.draw = 1;
    super->spritePriority.b1 = 2;
    super->spritePriority.b0 = 3;
    super->child = &gPlayerEntity;
    CopyPosition(super->child, super);
    super->z.HALF.HI -= 4;
    if (super->type != ITEM_HEART && ItemOnGround_PickUp(this)) {
        DeleteThisEntityWithFlag(super, TRUE);
    }
}

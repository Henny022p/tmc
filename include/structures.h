#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "global.h"
#include "entity.h"

typedef struct {
    s32 signature;
    u8 field_0x4;
    u8 listenForKeyPresses;
    u8 field_0x6;
    u8 field_0x7;
    u8 pad[24];
} struct_02000010;
static_assert(sizeof(struct_02000010) == 0x20);

extern struct_02000010 gUnk_02000010;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
} struct_020354C0;
extern struct_020354C0 gUnk_020354C0[0x20];

typedef struct {
    u16 unk_00;
    u8 unk_02[0xE];
} struct_02034480;
extern struct_02034480 gUnk_02034480;

typedef struct {
    u8 numTiles;
    u8 unk_1;
    u16 firstTileIndex;
} SpriteFrame;

typedef struct {
    void* animations;
    SpriteFrame* frames;
    void* ptr;
    u32 pad;
} SpritePtr;

extern const SpritePtr gSpritePtrs[];

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2[2];
    u16 unk_4;
    u8 filler[12];
    Entity* unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
} struct_02018EB0;

extern struct_02018EB0 gUnk_02018EB0;

typedef struct {
    u8 frame;
    u8 frameIndex;
} PACKED FrameStruct;

#endif // STRUCTURES_H

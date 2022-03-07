#include "global.h"
#include "entity.h"
#include "room.h"
#include "area.h"
#include "game.h"
#include "asm.h"
#include "item.h"
#include "coord.h"
#include "functions.h"

/** Collisions. */
typedef enum {
    COL_NONE = 0x0,
    COL_NORTH_WEST = 0x2,
    COL_NORTH_EAST = 0x4,
    COL_NORTH_FULL = 0x6,
    COL_NORTH_ANY = 0xe,
    COL_SOUTH_WEST = 0x20,
    COL_SOUTH_EAST = 0x40,
    COL_SOUTH_FULL = 0x60,
    COL_SOUTH_ANY = 0xe0,
    COL_WEST_SOUTH = 0x200,
    COL_WEST_NORTH = 0x400,
    COL_WEST_FULL = 0x600,
    COL_WEST_ANY = 0xe00,
    COL_EAST_SOUTH = 0x2000,
    COL_EAST_NORTH = 0x4000,
    COL_EAST_FULL = 0x6000,
    COL_EAST_ANY = 0xe000,
} Collisions;

extern u8 gExitList_RoyalValley_ForestMaze[];
extern u8 gUnk_08135190[];
extern u8 gUnk_08134FBC[];
extern u8 gUnk_08135048[];
extern u8 gUnk_0813A76C[];

bool32 IsTileCollision(const u8*, s32, s32, u32);
void CalculateEntityTileCollisions(Entity*, u32, u32);
bool32 ProcessMovementInternal(Entity*, s32, s32, u32);
bool32 sub_080AF0C8(Entity*);

/** The type of the movement/collision? that is done. */
typedef enum {
    CollisionType0,  // Normal/common? Used by most enemies and NPCs.
    CollisionType1,  // chaser, enemy50, fallingBoulder, ghini, keese, pesto, sensorBladeTrap, vaatiRebornEnemy,
                     // playerItem10, playerItem13
    CollisionType2,  // acroBandits, beetle, chuchu, fireballGuy, flyingSkull, helmasaur, keaton, lakitu,
                     // miniFireballGuy, peahat, rollobite, spikedBeetle, spinyChuchu, stalfos, itemOnGround,
                     // smallIceBlock, flyingPot, object1F
    CollisionType3,  // arrowProjectile, boneProjectile, cannonballProjectile, deekuSeedProjectile, fireProjectile,
                     // gyorgMaleEnergyProjectile, iceProjectile, lakituLightning, mandiblesProjectile, rockProjectile,
                     // spikedRollers, torchTrapProjectile, v2Projectile, v3ElectricProjectile, v3HandProjectile,
                     // v3TennisBallProjectile, windProjectile
    CollisionType4,  // lilypadLarge
    CollisionType5,  // chuchu
    CollisionType6,  // npc5
    CollisionType7,  // not used?
    CollisionType8,  // not used?
    CollisionType9,  // not used?
    CollisionType10, // playerItem13, rollobite
    CollisionType11, // not used?
    CollisionType12, // chaser, sensorBladeTrap
} CollisionType;

/** The collision function that is evaluated for a tile depending on the x/y position of the entity in the tile. */
typedef enum {
    FilledNone = 0,
    FilledAll = 1,
    FilledNorthWest = 2,
    FilledNorthEast = 3,
    FilledSouthWest = 4,
    FilledSouthEast = 5,
    FilledSouth = 6,
    FilledNorth = 7,
    FilledWest = 8,
    FilledEast = 9
} TileFilled;

bool32 MoveNorth(Entity*, s32, s32, u32);
bool32 MoveNorthEast(Entity*, s32, s32, u32);
bool32 MoveEast(Entity*, s32, s32, u32);
bool32 MoveSouthEast(Entity*, s32, s32, u32);
bool32 MoveSouth(Entity*, s32, s32, u32);
bool32 MoveSouthWest(Entity*, s32, s32, u32);
bool32 MoveWest(Entity*, s32, s32, u32);
bool32 MoveNorthWest(Entity*, s32, s32, u32);

/** Empty */
bool32 TileCollisionFunction0(s32 x, s32 y) {
    return FALSE;
}

/** Fully filled */
bool32 TileCollisionFunction1(s32 x, s32 y) {
    return TRUE;
}

/** Diagonal North West filled*/
bool32 TileCollisionFunction2(s32 x, s32 y) {
    static const u16 gUnk_08133918[] = {
        /*
        0b1000000000000000,
        0b1100000000000000,
        0b1110000000000000,
        0b1111000000000000,
        0b1111100000000000,
        0b1111110000000000,
        0b1111111000000000,
        0b1111111100000000,
        0b1111111110000000,
        0b1111111111000000,
        0b1111111111100000,
        0b1111111111110000,
        0b1111111111111000,
        0b1111111111111100,
        0b1111111111111110,
        0b1111111111111111,
        */
        32768, 49152, 57344, 61440, 63488, 64512, 65024, 65280, 65408, 65472, 65504, 65520, 65528, 65532, 65534, 65535,
    };

    return gUnk_08133918[y & 0xf] >> (x & 0xf) & 1;
}

/** Diagonal North East filled*/
bool32 TileCollisionFunction3(s32 x, s32 y) {
    static const u16 gUnk_08133938[] = {
        /*
        0b1,
        0b11,
        0b111,
        0b1111,
        0b11111,
        0b111111,
        0b1111111,
        0b11111111,
        0b111111111,
        0b1111111111,
        0b11111111111,
        0b111111111111,
        0b1111111111111,
        0b11111111111111,
        0b111111111111111,
        0b1111111111111111,
        */
        1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535,
    };
    return gUnk_08133938[y & 0xf] >> (x & 0xf) & 1;
}

/** Diagonal South West filled*/
bool32 TileCollisionFunction4(s32 x, s32 y) {
    static const u16 gUnk_08133958[] = {
        /*
        0b1111111111111111,
        0b1111111111111110,
        0b1111111111111100,
        0b1111111111111000,
        0b1111111111110000,
        0b1111111111100000,
        0b1111111111000000,
        0b1111111110000000,
        0b1111111100000000,
        0b1111111000000000,
        0b1111110000000000,
        0b1111100000000000,
        0b1111000000000000,
        0b1110000000000000,
        0b1100000000000000,
        0b1000000000000000,
        */
        65535, 65534, 65532, 65528, 65520, 65504, 65472, 65408, 65280, 65024, 64512, 63488, 61440, 57344, 49152, 32768,
    };
    return gUnk_08133958[y & 0xf] >> (x & 0xf) & 1;
}

/** Diagonal South East filled*/
bool32 TileCollisionFunction5(s32 x, s32 y) {
    static const u16 gUnk_08133978[] = {
        /*
        0b1111111111111111,
        0b111111111111111,
        0b11111111111111,
        0b1111111111111,
        0b111111111111,
        0b11111111111,
        0b1111111111,
        0b111111111,
        0b11111111,
        0b1111111,
        0b111111,
        0b11111,
        0b1111,
        0b111,
        0b11,
        0b1,
        */
        65535, 32767, 16383, 8191, 4095, 2047, 1023, 511, 255, 127, 63, 31, 15, 7, 3, 1,
    };
    return gUnk_08133978[y & 0xf] >> (x & 0xf) & 1;
}

/** 3/8 South filled */
bool32 TileCollisionFunction6(s32 x, s32 y) {
    static const u16 gUnk_08133998[] = {
        /*
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b0,
        0b0,
        0b0,
        0b0,
        0b0,
        0b0,
        */
        65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 0, 0, 0, 0, 0, 0,
    };

    return gUnk_08133998[y & 0xf] >> (x & 0xf) & 1;
}

/** 3/8 North filled */
bool32 TileCollisionFunction7(s32 x, s32 y) {
    static const u16 gUnk_081339B8[] = {
        /*
        0b0,
        0b0,
        0b0,
        0b0,
        0b0,
        0b0,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        0b1111111111111111,
        */
        0, 0, 0, 0, 0, 0, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
    };
    return gUnk_081339B8[y & 0xf] >> (x & 0xf) & 1;
}

/** 3/8 West filled */
bool32 TileCollisionFunction8(s32 x, s32 y) {
    static const u16 gUnk_081339D8[] = {
        /*
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        */
        65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472, 65472,
    };
    return gUnk_081339D8[y & 0xf] >> (x & 0xf) & 1;
}

/** 3/8 East filled */
bool32 TileCollisionFunction9(s32 x, s32 y) {
    static const u16 gUnk_081339F8[] = {
        /*
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        0b1111111111,
        */
        1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023,
    };
    return gUnk_081339F8[y & 0xf] >> (x & 0xf) & 1;
}

bool32 IsTileCollision(const u8* layer, s32 x, s32 y, u32 collisionType) {
    static bool32 (*const tileCollisionFunctions[])(s32, s32) = {
        TileCollisionFunction0, TileCollisionFunction1, TileCollisionFunction2, TileCollisionFunction3,
        TileCollisionFunction4, TileCollisionFunction5, TileCollisionFunction6, TileCollisionFunction7,
        TileCollisionFunction8, TileCollisionFunction9,
    };

    u32 tileType = layer[TILE(x, y)];
    if (tileType == 0) {
        if (collisionType == 4) {
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        if (tileType < 0x10) {
            static const u8 collisionLookup[] = {
                0xff,       FilledAll, FilledNone, FilledNone, 0xff,      FilledAll, FilledNone, FilledAll, FilledAll,
                FilledAll,  0xff,      FilledAll,  0xff,       FilledAll, FilledAll, FilledAll,  FilledAll, FilledAll,
                FilledNone, FilledAll, 0xff,       FilledAll,  FilledAll, FilledAll, 0xff,       FilledAll,
            };

            if (collisionLookup[collisionType * 2 + ((tileType + 1) >> 4)] == FilledNone) {
                return FALSE;
            }
            if (collisionLookup[collisionType * 2 + ((tileType + 1) >> 4)] == FilledAll) {
                return TRUE;
            }
            // Calculation for 0xff in previous lookup.
            if ((y & 8) == 0) {
                tileType = layer[TILE(x, y)];
                tileType >>= 2;
            }
            if ((x & 8) == 0) {
                tileType >>= 1;
            }
            return tileType & 1;
        } else {
            if (tileType == 0xff) {
                static const u8 collisionFunctionLookup[] = {
                    FilledAll, FilledAll, FilledAll, FilledNone, FilledAll, FilledAll, FilledAll,
                    FilledAll, FilledAll, FilledAll, FilledAll,  FilledAll, FilledAll,
                };
                return tileCollisionFunctions[collisionFunctionLookup[collisionType]](x, y);
            } else {
                static const u8 collisionFunctionLookup[] = {
                    /* collisionType: 0 */
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 1 */
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 2 */
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 3 */
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 4 */
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 5 */
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 6 */
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledSouth,
                    FilledNorth,
                    FilledWest,
                    FilledEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 7 */
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 8 */
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 9 */
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 10 */
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 11 */
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /* collisionType: 12 */
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNorthWest,
                    FilledNorthEast,
                    FilledSouthWest,
                    FilledSouthEast,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledNone,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    FilledAll,
                    /**/
                    FilledNone,
                };
                if (tileType > 0x6f) {
                    return TRUE;
                }

                return tileCollisionFunctions[collisionFunctionLookup[collisionType * 0x60 + tileType - 0x10]](x, y);
                // return tileCollisionFunctions[collisionFunctionLookup[collisionType][tileType - 0x10]](x, y);
            }
        }
    }
    return FALSE;
}

ASM_FUNC("asm/non_matching/movement/CalculateEntityTileCollisions.inc",
         void CalculateEntityTileCollisions(Entity* this, u32 direction, u32 collisionType))
/*NONMATCH("asm/non_matching/movement/CalculateEntityTileCollisions.inc",
         void CalculateEntityTileCollisions(Entity* this, u32 direction, u32 collisionType)) {
    u8* layer;

    u32 colResult;

    s32 xMin;
    s32 xVar1;
    s32 xVar2;

    s32 yMin;
    s32 yVar1;
    s32 yVar2;

    bool32 col1;
    bool32 col2;
    bool32 col3;
    bool32 col4;
    bool32 col5;
    bool32 col6;

    u32 hitboxUnkX;
    u32 hitboxUnkY;

    layer = GetLayerByIndex(this->collisionLayer)->_2004;
    xMin = this->x.HALF.HI + this->hitbox->offset_x;
    yMin = this->y.HALF.HI + this->hitbox->offset_y;
    hitboxUnkX = this->hitbox->unk2[0];
    hitboxUnkY = this->hitbox->unk2[1];
    if ((direction & 0xf) != 0) {
        if (0xf >= direction) {
            col1 = IsTileCollision(layer, xMin + hitboxUnkX, yMin, collisionType);
            col2 = IsTileCollision(layer, xMin + hitboxUnkX, yMin + hitboxUnkY, collisionType);
            col3 = IsTileCollision(layer, xMin + hitboxUnkX, yMin - hitboxUnkY, collisionType);
            colResult = ((col1 << 1 | col2) << 1 | col3) << 6;
        } else {
            col1 = IsTileCollision(layer, xMin - hitboxUnkX, yMin, collisionType);
            col2 = IsTileCollision(layer, xMin - hitboxUnkX, yMin + hitboxUnkY, collisionType);
            colResult = col1 << 1 | col2;
            col3 = IsTileCollision(layer, xMin - hitboxUnkX, yMin - hitboxUnkY, collisionType);
            colResult = (colResult << 1 | col3) << 2;
        }
    } else {
        col1 = IsTileCollision(layer, xMin + hitboxUnkX, yMin, collisionType);
        col2 = IsTileCollision(layer, xMin + hitboxUnkX, yMin + hitboxUnkY, collisionType);
        col3 = IsTileCollision(layer, xMin + hitboxUnkX, yMin - hitboxUnkY, collisionType);
        col4 = IsTileCollision(layer, xMin - hitboxUnkX, yMin, collisionType);
        col5 = IsTileCollision(layer, xMin - hitboxUnkX, yMin + hitboxUnkY, collisionType);
        colResult = (((col1 << 1 | col2) << 1 | col3) << 2 | col4) << 1 | col5;
        col6 = IsTileCollision(layer, xMin - hitboxUnkX, yMin - hitboxUnkY, collisionType);
        colResult = (colResult << 1 | col6) << 2;
    }

    hitboxUnkX = this->hitbox->unk2[2];
    hitboxUnkY = this->hitbox->unk2[3];

    if (((direction - 8) & 0xf) == 0) {
        col1 = IsTileCollision(layer, xMin, yMin + hitboxUnkY, collisionType);
        col2 = IsTileCollision(layer, xMin + hitboxUnkX, yMin + hitboxUnkY, collisionType);
        col3 = IsTileCollision(layer, xMin - hitboxUnkX, yMin + hitboxUnkY, collisionType);
        yMin -= hitboxUnkY;
        col4 = IsTileCollision(layer, xMin, yMin, collisionType);
        col5 = IsTileCollision(layer, xMin + hitboxUnkX, yMin, collisionType);
        colResult = ((((colResult | col1) << 1 | col2) << 1 | col3) << 2 | col4) << 1 | col5;
        col6 = IsTileCollision(layer, xMin - hitboxUnkX, yMin, collisionType);
        this->collisions = ((colResult << 1 | col6) << 1);
    } else {
        if (direction - 8 < 0x10) {
            yMin += hitboxUnkY;
            col1 = IsTileCollision(layer, xMin, yMin, collisionType);
            col2 = IsTileCollision(layer, xMin + hitboxUnkX, yMin, collisionType);
            col3 = IsTileCollision(layer, xMin - hitboxUnkX, yMin, collisionType);
            this->collisions = ((((colResult | col1) << 1 | col2) << 1 | col3) << 5);
        } else {
            yMin -= hitboxUnkY;
            col1 = IsTileCollision(layer, xMin, yMin, collisionType);
            col2 = IsTileCollision(layer, xMin + hitboxUnkX, yMin, collisionType);
            col6 = (colResult << 4 | col1) << 1 | col2;
            colResult = IsTileCollision(layer, xMin - hitboxUnkX, yMin, collisionType);
            this->collisions = ((col6 << 1 | colResult) << 1);
        }
    }
}
END_NONMATCH*/

bool32 ProcessMovementInternal(Entity* this, s32 radius, s32 direction, u32 collisionType) {
    static bool32 (*const gDirectionalMovementFunctions[])(Entity*, s32, s32, u32) = {
        MoveNorth,
        /**/
        MoveNorthEast,
        MoveNorthEast,
        MoveNorthEast,
        MoveNorthEast,
        MoveNorthEast,
        MoveNorthEast,
        MoveNorthEast,
        /**/
        MoveEast,
        /**/
        MoveSouthEast,
        MoveSouthEast,
        MoveSouthEast,
        MoveSouthEast,
        MoveSouthEast,
        MoveSouthEast,
        MoveSouthEast,
        /**/
        MoveSouth,
        /**/
        MoveSouthWest,
        MoveSouthWest,
        MoveSouthWest,
        MoveSouthWest,
        MoveSouthWest,
        MoveSouthWest,
        MoveSouthWest,
        /**/
        MoveWest,
        /**/
        MoveNorthWest,
        MoveNorthWest,
        MoveNorthWest,
        MoveNorthWest,
        MoveNorthWest,
        MoveNorthWest,
        MoveNorthWest,
    };
    return gDirectionalMovementFunctions[direction](this, radius, direction << 3, collisionType);
}

bool32 MoveNorth(Entity* this, s32 radius, s32 angle, u32 collisionType) {
    s32 moveA = 0;
    s32 moveB = 0;
    if ((this->collisions & COL_NORTH_ANY) != COL_NONE) {
        if ((this->collisions & COL_NORTH_ANY) == COL_NORTH_WEST) {
            if ((this->collisions & COL_EAST_ANY) == COL_NONE) {
                moveA = radius * 0x100;
                this->x.WORD += moveA;
                CalculateEntityTileCollisions(this, DirectionNorthEast, collisionType);
                if ((this->collisions & COL_NORTH_ANY) == COL_NONE) {
                    moveB = gSineTable[0x40] * radius;
                    moveA = radius * 0x100;
                    this->y.WORD -= moveB;
                }
            }
        } else {
            if ((this->collisions & COL_NORTH_ANY) == COL_NORTH_EAST) {
                if ((this->collisions & COL_WEST_ANY) == COL_NONE) {
                    moveA = radius * 0x100;
                    this->x.WORD -= moveA;
                    CalculateEntityTileCollisions(this, DirectionNorthWest, collisionType);
                    if ((this->collisions & COL_NORTH_ANY) == COL_NONE) {
                        moveB = gSineTable[0x40] * radius;
                        moveA = radius * 0x100;
                        this->y.WORD -= moveB;
                    }
                }
            }
        }
    } else {
        moveA = gSineTable[0x40] * radius;
        this->y.WORD -= moveA;
    }
    if (((moveA >= -0x3333) && (moveA < 0x3333)) && ((moveB >= -0x3333) && (moveB < 0x3333))) {
        return FALSE;
    } else {
        return TRUE;
    }
}

ASM_FUNC("asm/non_matching/movement/MoveNorthEast.inc",
         bool32 MoveNorthEast(Entity* this, s32 radius, s32 angle, u32 collisionType))
/*NONMATCH("asm/non_matching/movement/MoveNorthEast.inc",
         bool32 MoveNorthEast(Entity* this, s32 radius, s32 angle, u32 collisionType)) {
    s32 moveA = 0;
    s32 moveB = 0;
    if (((this->collisions & COL_NORTH_ANY) == COL_NONE) || ((this->collisions & COL_EAST_ANY) == COL_NONE)) {
        if ((this->collisions & (COL_NORTH_ANY | COL_EAST_ANY)) == COL_NONE) {
            moveA = radius * gSineTable[angle + 0x40];
            this->y.WORD -= moveA;
            moveB = radius * gSineTable[angle];
            this->x.WORD += moveB;
        } else {
            if ((this->collisions & COL_NORTH_ANY) == COL_NORTH_WEST) {
                moveA = radius * 0x100;
                this->x.WORD += moveA;
                CalculateEntityTileCollisions(this, DirectionNorthEast, collisionType);
            } else {
                if ((this->collisions & COL_EAST_ANY) == COL_EAST_NORTH) {
                    moveA = radius * 0x100;
                    this->y.WORD -= moveA;
                    CalculateEntityTileCollisions(this, DirectionNorthEast, collisionType);
                }
            }
            if ((this->collisions & COL_NORTH_ANY) == COL_NONE) {
                moveB = gSineTable[angle + 0x40] * radius;
                this->y.WORD -= moveB;
            }
            if ((this->collisions & COL_EAST_ANY) == COL_NONE) {
                moveB = gSineTable[angle] * radius;
                this->x.WORD += moveB;
            }
        }
    }
    if (((moveA >= -0x3333) && (moveA < 0x3333)) && ((moveB >= -0x3333) && (moveB < 0x3333))) {
        return FALSE;
    } else {
        return TRUE;
    }
}
END_NONMATCH*/

bool32 MoveEast(Entity* this, s32 radius, s32 angle, u32 collisionType) {
    s32 moveA = 0;
    s32 moveB = 0;
    if ((this->collisions & COL_EAST_ANY) != COL_NONE) {
        if ((this->collisions & COL_EAST_ANY) == COL_EAST_SOUTH) {
            if ((this->collisions & COL_SOUTH_ANY) == COL_NONE) {
                moveA = radius * 0x100;
                this->y.WORD += moveA;
                CalculateEntityTileCollisions(this, DirectionSouthEast, collisionType);
                if ((this->collisions & COL_EAST_ANY) == COL_NONE) {
                    moveB = gSineTable[angle] * radius;
                    this->x.WORD += moveB;
                }
            }
        } else {
            if ((this->collisions & COL_EAST_ANY) == COL_EAST_NORTH) {
                if ((this->collisions & COL_NORTH_ANY) == COL_NONE) {
                    moveA = radius * 0x100;
                    this->y.WORD -= moveA;
                    CalculateEntityTileCollisions(this, DirectionNorthEast, collisionType);
                    if ((this->collisions & COL_EAST_ANY) == COL_NONE) {
                        moveB = gSineTable[angle] * radius;
                        this->x.WORD += moveB;
                    }
                }
            }
        }
    } else {
        moveA = gSineTable[angle] * radius;
        this->x.WORD += moveA;
    }
    if (((moveA >= -0x3333) && (moveA < 0x3333)) && ((moveB >= -0x3333) && (moveB < 0x3333))) {
        return FALSE;
    } else {
        return TRUE;
    }
}

ASM_FUNC("asm/non_matching/movement/MoveSouthEast.inc",
         bool32 MoveSouthEast(Entity* this, s32 radius, s32 angle, u32 collisionType))
/*NONMATCH("asm/non_matching/movement/MoveSouthEast.inc",
         bool32 MoveSouthEast(Entity* this, s32 radius, s32 angle, u32 collisionType)) {
    s32 moveA = 0;
    s32 moveB = 0;
    if (((this->collisions & COL_SOUTH_ANY) == COL_NONE) || ((this->collisions & COL_EAST_ANY) == COL_NONE)) {
        if ((this->collisions & (COL_SOUTH_ANY | COL_EAST_ANY)) == COL_NONE) {
            moveA = gSineTable[angle + 0x40] * radius;
            this->y.WORD -= moveA;
            moveB = gSineTable[angle] * radius;
            this->x.WORD += moveB;
        } else {
            if ((this->collisions & COL_SOUTH_ANY) == COL_SOUTH_WEST) {
                moveA = radius * 0x100;
                this->x.WORD += moveA;
                CalculateEntityTileCollisions(this, DirectionSouthEast, collisionType);
            } else if ((this->collisions & COL_EAST_ANY) == COL_EAST_SOUTH) {
                moveA = radius * 0x100;
                this->y.WORD += moveA;
                CalculateEntityTileCollisions(this, DirectionSouthEast, collisionType);
            }
            if ((this->collisions & COL_SOUTH_ANY) == COL_NONE) {
                moveB = gSineTable[angle + 0x40] * radius;
                this->y.WORD -= moveB;
            }
            if ((this->collisions & COL_EAST_ANY) == COL_NONE) {
                moveB = gSineTable[angle] * radius;
                this->x.WORD += moveB;
            }
        }
    }
    if (((moveA >= -0x3333) && (moveA < 0x3333)) && ((moveB >= -0x3333) && (moveB < 0x3333))) {
        return FALSE;
    } else {
        return TRUE;
    }
}
END_NONMATCH*/

bool32 MoveSouth(Entity* this, s32 radius, s32 angle, u32 collisionType) {
    s32 moveA = 0;
    s32 moveB = 0;

    if ((this->collisions & COL_SOUTH_ANY) != COL_NONE) {
        if ((this->collisions & COL_SOUTH_ANY) == COL_SOUTH_WEST) {
            if ((this->collisions & COL_EAST_ANY) == COL_NONE) {
                moveA = radius * 0x100;
                this->x.WORD += moveA;
                CalculateEntityTileCollisions(this, DirectionSouthEast, collisionType);
                if ((this->collisions & COL_SOUTH_ANY) == COL_NONE) {
                    moveB = gSineTable[angle + 0x40] * radius;
                    this->y.WORD -= moveB;
                }
            }
        } else {
            if ((this->collisions & COL_SOUTH_ANY) == COL_SOUTH_EAST) {
                if ((this->collisions & COL_WEST_ANY) == COL_NONE) {
                    moveA = radius * 0x100;
                    this->x.WORD -= moveA;
                    CalculateEntityTileCollisions(this, DirectionSouthWest, collisionType);
                    if ((this->collisions & COL_SOUTH_ANY) == COL_NONE) {
                        moveB = gSineTable[angle + 0x40] * radius;
                        this->y.WORD -= moveB;
                    }
                }
            }
        }
    } else {
        moveA = gSineTable[angle + 0x40] * radius;
        this->y.WORD -= moveA;
    }
    if (((moveA >= -0x3333) && (moveA < 0x3333)) && ((moveB >= -0x3333) && (moveB < 0x3333))) {
        return FALSE;
    } else {
        return TRUE;
    }
}

ASM_FUNC("asm/non_matching/movement/MoveSouthWest.inc",
         bool32 MoveSouthWest(Entity* this, s32 radius, s32 angle, u32 collisionType))
/*NONMATCH("asm/non_matching/movement/MoveSouthWest.inc",
         bool32 MoveSouthWest(Entity* this, s32 radius, s32 angle, u32 collisionType)) {
    s32 moveA = 0;
    s32 moveB = 0;
    if (((this->collisions & COL_SOUTH_ANY) == COL_NONE) || ((this->collisions & COL_WEST_ANY) == COL_NONE)) {
        if ((this->collisions & (COL_SOUTH_ANY | COL_WEST_ANY)) == COL_NONE) {
            moveB = gSineTable[angle + 0x40] * radius;
            this->y.WORD -= moveB;
            moveA = gSineTable[angle] * radius;
            this->x.WORD += moveA;
        } else {
            if ((this->collisions & COL_SOUTH_ANY) == COL_SOUTH_EAST) {
                moveB = radius * 0x100;
                this->x.WORD -= moveB;
                CalculateEntityTileCollisions(this, DirectionSouthWest, collisionType);
            } else {
                if ((this->collisions & COL_WEST_ANY) == COL_WEST_SOUTH) {
                    moveB = radius * 0x100;
                    this->y.WORD += moveB;
                    CalculateEntityTileCollisions(this, DirectionSouthWest, collisionType);
                }
            }
            if ((this->collisions & COL_SOUTH_ANY) == COL_NONE) {
                moveA = gSineTable[angle + 0x40] * radius;
                this->y.WORD -= moveA;
            }
            if ((this->collisions & COL_WEST_ANY) == COL_NONE) {
                moveA = gSineTable[angle] * radius;
                this->x.WORD += moveA;
            }
        }
    }
    if (((moveA >= -0x3333) && (moveA < 0x3333)) && ((moveB >= -0x3333) && (moveB < 0x3333))) {
        return FALSE;
    } else {
        return TRUE;
    }
}
END_NONMATCH*/

bool32 MoveWest(Entity* this, s32 radius, s32 angle, u32 collisionType) {
    s32 moveA = 0;
    s32 moveB = 0;

    if ((this->collisions & COL_WEST_ANY) != COL_NONE) {

        if ((this->collisions & COL_WEST_ANY) == COL_WEST_SOUTH) {
            if ((this->collisions & COL_SOUTH_ANY) == COL_NONE) {
                moveA = radius * 0x100;
                this->y.WORD += moveA;
                CalculateEntityTileCollisions(this, DirectionNorthWest,
                                              collisionType); // @bug? Should this calculate for DirectionSouthWest?
                if ((this->collisions & COL_WEST_ANY) == COL_NONE) {
                    moveB = gSineTable[angle] * radius;
                    this->x.WORD += moveB;
                }
            }
        } else {
            if ((this->collisions & COL_WEST_ANY) == COL_WEST_NORTH) {
                if ((this->collisions & COL_NORTH_ANY) == COL_NONE) {
                    moveA = radius * 0x100;
                    this->y.WORD -= moveA;
                    CalculateEntityTileCollisions(this, DirectionNorthWest, collisionType);
                    if ((this->collisions & COL_WEST_ANY) == COL_NONE) {
                        moveB = gSineTable[angle] * radius;
                        this->x.WORD += moveB;
                    }
                }
            }
        }
    } else {
        moveA = gSineTable[angle] * radius;
        this->x.WORD += moveA;
    }

    if (((moveA >= -0x3333) && (moveA < 0x3333)) && ((moveB >= -0x3333) && (moveB < 0x3333))) {
        return FALSE;
    } else {
        return TRUE;
    }
}

ASM_FUNC("asm/non_matching/movement/MoveNorthWest.inc",
         bool32 MoveNorthWest(Entity* this, s32 radius, s32 angle, u32 collisionType))
/*NONMATCH("asm/non_matching/movement/MoveNorthWest.inc",
         bool32 MoveNorthWest(Entity* this, s32 radius, s32 angle, u32 collisionType)) {
    s32 moveA = 0;
    s32 moveB = 0;
    u32 colNorthAny = (this->collisions & COL_NORTH_ANY);
    u32 colWestAny = (this->collisions & COL_WEST_ANY);
    if ((colNorthAny == COL_NONE) || (colWestAny == COL_NONE)) {
        if ((colNorthAny | colWestAny) == COL_NONE) {
            moveA = gSineTable[angle + 0x40] * radius;
            this->y.WORD -= moveA;
            moveB = gSineTable[angle] * radius;
            this->x.WORD += moveB;
        } else {
            if (colNorthAny == COL_NORTH_EAST) {
                moveA = radius * 0x100;
                this->x.WORD -= moveA;
                CalculateEntityTileCollisions(this, DirectionNorthWest, collisionType);
            } else {
                if (colWestAny == COL_WEST_NORTH) {
                    moveA = radius * 0x100;
                    this->y.WORD -= moveA;
                    CalculateEntityTileCollisions(this, DirectionNorthWest, collisionType);
                }
            }
            if ((this->collisions & COL_NORTH_ANY) == COL_NONE) {
                moveB = gSineTable[angle + 0x40] * radius;
                this->y.WORD -= moveB;
            }
            if ((this->collisions & COL_WEST_ANY) == COL_NONE) {
                moveB = gSineTable[angle] * radius;
                this->x.WORD += moveB;
            }
        }
    }
    if (((moveA >= -0x3333) && (moveA < 0x3333)) && ((moveB >= -0x3333) && (moveB < 0x3333))) {
        return FALSE;
    } else {
        return TRUE;
    }
}
END_NONMATCH*/

bool32 ProcessMovement0(Entity* this) {
    bool32 result;

    if ((this->direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, this->direction, 0);
        result = ProcessMovementInternal(this, this->speed, this->direction, 0);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 ProcessMovement1(Entity* this) {
    bool32 result;

    if ((this->direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, this->direction, 1);
        result = ProcessMovementInternal(this, this->speed, this->direction, 1);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 ProcessMovement2(Entity* this) {
    bool32 result;

    if ((this->direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, this->direction, 2);
        result = ProcessMovementInternal(this, this->speed, this->direction, 2);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 ProcessMovement10(Entity* this) {
    bool32 result;

    if ((this->direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, this->direction, 10);
        result = ProcessMovementInternal(this, this->speed, this->direction, 10);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 ProcessMovement12(Entity* this) {
    bool32 result;

    if ((this->direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, this->direction, 12);
        result = ProcessMovementInternal(this, this->speed, this->direction, 12);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 ProcessMovement0_custom(Entity* this, u32 direction, u32 speed) {
    bool32 result;

    if ((direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, direction, 0);
        result = ProcessMovementInternal(this, speed, direction, 0);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 ProcessMovement3(Entity* this) {
    bool32 result;

    if (((this->direction & 0x80) == 0) && (sub_080AF0C8(this) == 0)) {
        CalculateEntityTileCollisions(this, this->direction, 3);
        result = ProcessMovementInternal(this, this->speed, this->direction, 3);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 sub_080AF0C8(Entity* this) {
    u32 tileType = GetTileTypeByEntity(this);
    switch (tileType) {
        case 0x87:
            if (((this->direction + 7) & 0x1f) < 0x10) {
                this->collisions = COL_NORTH_ANY;
                return TRUE;
            }
            break;
        case 0x8a:
            if (((this->direction - 1) & 0x1f) < 0x10) {
                this->collisions = COL_EAST_ANY;
                return TRUE;
            }
            break;
        case 0x88:
            if (((this->direction - 9) & 0x1f) < 0x10) {
                this->collisions = COL_SOUTH_ANY;
                return TRUE;
            }
            break;
        case 0x89:
            if (((this->direction - 0x11) & 0x1f) < 0x10) {
                this->collisions = COL_WEST_ANY;
                return TRUE;
            }
            break;
    }
    return FALSE;
}

bool32 ProcessMovement4(Entity* this) {
    bool32 result;

    if ((this->direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, this->direction, 4);
        result = ProcessMovementInternal(this, this->speed, this->direction, 4);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 ProcessMovement5(Entity* this) {
    bool32 result;

    if ((this->direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, this->direction, 5);
        result = ProcessMovementInternal(this, this->speed, this->direction, 5);
    } else {
        result = FALSE;
    }
    return result;
}

void Knockback1(Entity* this) {
    this->knockbackDuration--;
    CalculateEntityTileCollisions(this, this->knockbackDirection, 2);
    ProcessMovementInternal(this, this->knockbackSpeed, this->knockbackDirection, 2);
}

void Knockback2(Entity* this) {
    this->knockbackDuration--;
    CalculateEntityTileCollisions(this, this->knockbackDirection, 1);
    ProcessMovementInternal(this, this->knockbackSpeed, this->knockbackDirection, 1);
}

bool32 ProcessMovement6(Entity* this) {
    bool32 result;

    if ((this->direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, this->direction, 6);
        result = ProcessMovementInternal(this, this->speed, this->direction, 6);
    } else {
        result = FALSE;
    }
    return result;
}

bool32 ProcessMovement6_custom(Entity* this, u32 direction, u32 speed) {
    bool32 result;

    if ((direction & 0x80) == 0) {
        CalculateEntityTileCollisions(this, direction, 6);
        result = ProcessMovementInternal(this, speed, direction, 6);
    } else {
        result = FALSE;
    }
    return result;
}

void ProcessMovementInternal2(Entity* this, u32 direction, u32 speed) {
    ProcessMovementInternal(this, direction, speed, 2);
}

void sub_080AF250(s32 param_1) {
    gArea.pCurrentRoomInfo = GetCurrentRoomInfo();
    if (param_1 != 0) {
        (gArea.pCurrentRoomInfo)->exits = gUnk_08135190;
    } else {
        (gArea.pCurrentRoomInfo)->exits = gExitList_RoyalValley_ForestMaze;
    }
}

void sub_080AF284(void) {
    if (CheckPlayerInRegion(0x78, gRoomControls.height - 0x50, 0x78, 0x50)) {
        gArea.pCurrentRoomInfo = GetCurrentRoomInfo();
        (gArea.pCurrentRoomInfo)->exits = gUnk_08135048;
    } else {
        if (GetInventoryValue(ITEM_FOURSWORD) == 0) {
            return;
        }
        gArea.pCurrentRoomInfo = GetCurrentRoomInfo();
        (gArea.pCurrentRoomInfo)->exits = gUnk_08134FBC;
    }
}

void sub_080AF2E4(void) {
    if (GetInventoryValue(ITEM_FOURSWORD)) {
        gArea.pCurrentRoomInfo = GetCurrentRoomInfo();
        (gArea.pCurrentRoomInfo)->exits = gUnk_0813A76C;
    }
}

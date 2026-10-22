/* sn-2.95.3-136 */
/*
 * NON_MATCHING: same length as retail; retail keeps no in s0 and self in s1,
 * here they are the other way round. Everything else matches.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cScenario.h"
#include "godhand/cEmManage.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

/* cScenario as the room jump sees it: the player pose saved when a jump
 * starts. A view of the record's first 0x18 bytes. */
typedef struct cScenarioJump {
    cVec pos;                           /* 0x00 player position */
    float angle;                        /* 0x10 player heading */
    unsigned char jumping;              /* 0x14 a room jump is under way */
    char unk15;
    unsigned short fromRoom;            /* 0x16 room the jump left */
} cScenarioJump;

/* View of cGameObjVt with the position and rotation getters at 0x80..0x8F. */
typedef struct cGameObjPoseVt {
    char unk00[0x80];
    short posDelta;                     /* 0x80 */
    short pad82;
    cVec *(*getPos)(void *self);        /* 0x84 */
    short rotDelta;                     /* 0x88 */
    short pad8A;
    cVec *(*getRot)(void *self);        /* 0x8C */
} cGameObjPoseVt;

/* View of cGameObj down to its method table. */
typedef struct cGameObjPose {
    char unk000[0x214];
    cGameObjPoseVt *vt;                 /* 0x214 */
} cGameObjPose;

/* The player's position and rotation, through its method table. */
static inline cVec *playerPos(void)
{
    cGameObjPose *pl = (cGameObjPose *)Getplayer();

    return pl->vt->getPos((char *)pl + pl->vt->posDelta);
}

static inline cVec *playerRot(void)
{
    cGameObjPose *pl = (cGameObjPose *)Getplayer();

    return pl->vt->getRot((char *)pl + pl->vt->rotDelta);
}

extern void *D_003C264C;
extern void cSaveManager_setCheckPoint(void *self, int a1, int a2, int a3);
extern void cScenario_beginRoomJump_2C4548(cScenario *self, int room, float angle, void *pos, int a3, unsigned int t0, int t1);

#define GAMEWORK_ROOM_JUMP 0x8000000

/* Start a room jump to room no: drop the room's enemies, note where the player
 * stood, set the checkpoint, and use the fixed landing point and heading of
 * the few rooms that have one. */
__attribute__((section(".text.func_002C45A8")))
void func_002C45A8(cScenarioJump *self, unsigned short no, cVec *pos, float angle)
{
    cVec ofs;

    if (self->jumping) {
        return;
    }
    cEmManage_ReleaseEmAll(&D_005864F0);
    self->jumping = 1;
    self->fromRoom = D_007474A0.room;
    cVec_copy3(&self->pos, playerPos());
    self->angle = playerRot()->y;
    cScenario_runRoomExitFunc((cScenario *)self);
    cSaveManager_setCheckPoint(D_003C264C, 0, 0, 0);
    D_007474A0.flags |= GAMEWORK_ROOM_JUMP;
    VU0_LQC2_SQC2_MEM(4, &ofs, pos);
    switch (D_007474A0.room) {
    case 0x105:
        ofs.x = 0.0f;
        ofs.y = 1.05f;
        ofs.z = 5.5f;
        no = 0x42;
        angle = 3.14159265f;
        break;
    case 0x102:
        ofs.x = 4.8f;
        ofs.y = 1.6f;
        ofs.z = 0.0f;
        no = 0x44;
        angle = -1.57079633f;
        break;
    case 0x300:
        ofs.x = 0.0f;
        ofs.y = 0.0f;
        ofs.z = 2.0f;
        no = 0x41;
        angle = 3.14159265f;
        break;
    case 0x404:
        ofs.x = 4.8f;
        ofs.y = 1.6f;
        ofs.z = 0.0f;
        no = 0x4C;
        angle = -1.57079633f;
        break;
    case 0x503:
        ofs.x = 0.0f;
        ofs.y = 1.6f;
        ofs.z = 5.5f;
        no = 0x43;
        angle = 3.14159265f;
        break;
    case 0x607:
        ofs.x = 0.0f;
        ofs.y = 1.05f;
        ofs.z = 5.5f;
        no = 0x40;
        angle = 3.14159265f;
        break;
    case 0x701:
        ofs.x = 4.8f;
        ofs.y = 1.6f;
        ofs.z = 0.0f;
        no = 0x4D;
        angle = -1.57079633f;
        break;
    case 0x204:
    case 0x802:
        ofs.x = 0.0f;
        ofs.y = 41.66f;
        ofs.z = 5.0f;
        no = 0x45;
        angle = 3.14159265f;
        break;
    }
    cScenario_beginRoomJump_2C4548((cScenario *)self, no, angle, &ofs, 0, 0, 1);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C45A8);
#endif

/* NON_MATCHING func_002000F8 (sn-2.95.3-136):
 * Retail keeps &D_007474A0.flags5D8 (the address D_00747A78) in s4 and reaches every other world field
 * from it (s4 - 0x5D8, s4 + 0xC); this build keeps &D_007474A0 in s4. Retail also masks flags5E4 as a
 * signed int (addiu -0x21). The callees func_00200638 and InitSlotParams_200658 are defined (void) but
 * are passed the door; func_002006B8 is defined on SavePointWork, a view of cDoor. */
#include "include_asm.h"
#include "godhand/cDoor.h"
#include "godhand/cGameObj.h"
#include "godhand/cScenario.h"
#include "godhand/classFADE.h"
#include "godhand/player.h"

#ifdef NON_MATCHING
#define CDOOR_SAME_ROOM        0xFFFF   /* point id of a jump inside the current room */
#define CDOOR_WAIT             5
#define GAME_MODE_ROOM_JUMP    5
#define FADE_WHITE_FROM        0x80A0A0A0
#define FADE_WHITE_TO          0x00A0A0A0
#define FADE_BLACK             0xFF000000
#define FADE_TIME              15
#define WORLD_F_PLAYER_READY   0x00010000
#define WORLD_F_PAD_LOCK       0x02000000
#define SCENARIO_F_RUN         1
#define GAMEOBJ_OFFSET_ROT_ORDER 0x140  /* rotation order byte; cGameObj.h does not name it */
#define GAMEOBJ_ROT_ORDER(obj) (*((unsigned char *)(obj) + GAMEOBJ_OFFSET_ROT_ORDER))

extern cDoorWorld D_007474A0;
extern unsigned char D_005CAC90[];
extern int D_0061A990[];
extern int func_002006B8(cDoor *self);
extern void func_00200638(cDoor *self);
extern void InitSlotParams_200658(cDoor *self);
extern int Obj0000_Get_Low16_2006B0(int id);
extern void MtxInitTransVec(float *mtx, float *trans);
extern void MtxMulRotVec(float *dst, float *src, float *rot, int order);
extern void pl00_reset(void *pl);
extern void func_002D9D48(int *a0, int a1);

/* Start the fade the jump point asks for: bit 0 a white flash, bit 1 a fade from black, a negative value none. */
static inline void cDoor_startFade(cDoor *self)
{
    int fade;

    if (D_00747470.state == 0) {
        return;
    }
    fade = self->point[0].arg2;
    if (fade < 0) {
        return;
    }
    if (fade & 1) {
        classFADE_start(&D_00747470, 0, 8, 0, FADE_WHITE_FROM, FADE_WHITE_TO, FADE_TIME);
    } else if (fade & 2) {
        classFADE_start(&D_00747470, 0, 8, 0, FADE_BLACK, 0, FADE_TIME);
    }
}

/* Run a door jump once any fade has finished: inside the room, move the player to the point; otherwise set up the jump to the next room. */
__attribute__((section(".text.func_002000F8")))
void func_002000F8(cDoor *self)
{
    cGameObj *pl;

    if (D_00747470.state != 0 && ((D_00747470.state >> FADE_STATE_DONE_BIT) & 1) == 0) {
        return;
    }
    D_007474A0.flags5D8 |= WORLD_F_PLAYER_READY;
    if (func_002006B8(self) == 0) {
        return;
    }
    D_007474A0.flags5E4 &= ~0x20;
    func_00200638(self);
    if (self->point[0].id == CDOOR_SAME_ROOM) {
        pl = Getplayer();
        switch (self->step) {
        case 0:
            cScenario_moveObjPos(D_003C2F84, (char *)pl, self->point[0].pos[0], self->point[0].pos[1],
                                 self->point[0].pos[2], self->point[0].angle);
            MtxInitTransVec(pl->mtx, &pl->pos->x);
            MtxMulRotVec(pl->mtx, pl->mtx, pl->rot, GAMEOBJ_ROT_ORDER(pl));
            pl00_reset(Getplayer());
            cScenario_resetCam(D_003C2F84);
            self->wait = CDOOR_WAIT;
            D_007474A0.kindC = D_007474A0.kindA;
            D_007474A0.kindA = self->point[0].kind;
            D_007474A0.kindB = self->point[0].kind;
            cScenario_runExitFunc(D_003C2F84);
            cDoor_startFade(self);
            self->step++;
            break;
        case 1:
            D_007474A0.flags5E4 &= ~WORLD_F_PAD_LOCK;
            D_003C2F84->task.flags &= ~SCENARIO_F_RUN;
            InitSlotParams_200658(self);
            break;
        }
        return;
    }
    D_005CAC90[0] = GAME_MODE_ROOM_JUMP;
    D_005CAC90[3] = 0;
    D_005CAC90[1] = 0;
    D_005CAC90[2] = 0;
    D_007474A0.nextRoom = Obj0000_Get_Low16_2006B0(self->point[0].id);
    D_007474A0.nextArg = self->point[0].arg;
    D_007474A0.flags5D8 &= ~0x00400000;
    D_007474A0.flags5D8 &= ~0x00100000;
    D_007474A0.flags5E4 |= 0x8000;
    D_007474A0.flags5E0 &= ~0x00100000;
    D_007474A0.pos[0] = self->point[0].pos[0];
    D_007474A0.pos[2] = self->point[0].pos[2];
    D_007474A0.pos[1] = self->point[0].pos[1];
    D_007474A0.angle = self->point[0].angle;
    D_007474A0.kindB = self->point[0].kind;
    switch (D_007474A0.nextRoom) {
    case 0x100:
    case 0x200:
    case 0x300:
    case 0x400:
    case 0x500:
    case 0x600:
    case 0x700:
    case 0x802:
    case 0x806:
        func_002D9D48(D_0061A990, 0);
        break;
    }
    cDoor_startFade(self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002000F8);
#endif

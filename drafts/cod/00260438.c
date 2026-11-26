/* sn-2.95.3-136 */
/* NON_MATCHING func_00260438 (sn-2.95.3-136): 2 instructions off. Before the subtraction retail loads
 * self->pos (lw v1) and then forms &tmp_ (addiu a0); this C forms them the other way round. The
 * subtraction binds &tmp_ like func_00274D18's (decisions_needed, batch 240): CVEC_SUB as it is
 * gives 9 off. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cVec.h"
#include "godhand/capVu0.h"
#include "godhand/cCamera.h"
#include "godhand/mtx.h"
#include "godhand/rand.h"
#include "godhand/sceVu0.h"
#include "godhand/globals.h"

/* the room word, as 00133408.c reads it: the high byte is the stage (001633a0.c, 0028fb88.c) */
extern unsigned char D_00747A50[];

#define SPAWN_EM_NO      0x278
#define SPAWN_BLOCK_EM   0x20F          /* no copy while an enemy with this number is listed */
#define SPAWN_FLAGS      0x4000000
#define SPAWN_APP        0xD
#define ROOM_RAND        0x40           /* D_00747A50: room where the copy appears at a random offset */
#define ROOM_FIXED       0x303          /* D_00747A50: room where it appears at a fixed point */

/* SET_EM_DATA's constructor: pos zero, no entry number. */
static __inline__ void SET_EM_DATA_init(SET_EM_DATA *d)
{
    CVEC_ZERO(d->pos);
    d->entryNo = EM_ENTRY_NONE;
}

/* Enemy 0x278: unless an enemy 0x20F is listed, enter another of its actor 5 above a point (10
 * ahead and 5 up in its own frame, or a random or fixed point in two rooms), heading along the line
 * from that point to it. */
__attribute__((section(".text.func_00260438")))
void func_00260438(cEm00 *self)
{
    float mtx[16] __attribute__((aligned(16)));
    cVec pos;
    cVec dir;
    CVEC_TEMPS;
    SET_EM_DATA data;
    float ang;

    if ((self->emNo ^ SPAWN_EM_NO) != 0) {
        return;
    }
    self->unk1728 = 1800.0f;
    if (func_002919C0(&D_005864F0, self->actorId, SPAWN_BLOCK_EM) != 0) {
        return;
    }
    CVEC_ZERO(pos);
    switch (*(unsigned short *)D_00747A50) {
    default:
        MtxInitRotY(mtx, self->rot.y);
        pos.x = 0.0f;
        pos.y = 5.0f;
        pos.z = 10.0f;
        cVec_applyMatrix(&pos, mtx);
        CVEC_ADD_TO(pos, self->pos);
        break;
    case ROOM_RAND:
        pos.x = fRand1_1() * 5.0f;
        pos.y = 6.0f;
        pos.z = fRand1_1() * 5.0f;
        break;
    case ROOM_FIXED:
        pos.x = 90.0f;
        pos.y = 10.0f;
        pos.z = -21.0f;
        break;
    }
    CVEC_ZERO(dir);
    {
        cVec *a_ = self->pos;
        cVec *t_ = &tmp_;
        cVec *b_ = &pos;

        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);
        VU0_LQC2(4, t_, 0);
        VU0_SQC2_MEM(4, &ret_, 0);
    }
    dir.x = ret_.x;
    dir.y = ret_.y;
    dir.z = ret_.z;
    ang = capVu0Atan2(dir.x, dir.z);
    SET_EM_DATA_init(&data);
    data.objId = self->actorId;
    data.pos.x = pos.x;
    data.pos.z = pos.z;
    data.pos.y = pos.y + 5.0f;
    data.rot = ang;
    data.rot = Adjust_theta(data.rot);
    data.flags = SPAWN_FLAGS;
    data.appPattern = SPAWN_APP;
    data.seBank = SPAWN_BLOCK_EM;
    data.seNo = 0;
    data.entryNo = EM_ENTRY_NONE;
    cEmManage_EntryEm(&D_005864F0, &data, 0, self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00260438);
#endif

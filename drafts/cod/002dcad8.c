/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/pl00.h"
#include "godhand/player.h"
#include "godhand/cEmManage.h"
#include "godhand/cActionButton.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/capVu0.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

#ifdef NON_MATCHING
/* The face a line check hit. */
typedef struct LineHitFace {
    char unk0[4];
    int flags;                          /* 0x4 */
} LineHitFace;

extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *p);
extern void cActionButton_set(cActionButton *self, int priority, int life, int a3, int a4, int a5, int kind);
extern cActionButton D_00568288;
extern void func_002DCCD0(void);

/* Offer the jump-down button: while the player is alive, free and not held,
 * look 1.0 ahead and down from waist height for a ledge face (bit 0x20); on
 * one, store the start point half a unit out from it at the player's height
 * and the facing, and set the button. Same length as retail, 7 instructions
 * differ: retail forms &pos in $v1 before the vadd (the C++ operator+= binds
 * its this pointer first) and still addresses the vadd's lqc2/sqc2 from $sp. */
__attribute__((section(".text.SetActionJumpDown")))
void SetActionJumpDown(void)
{
    pl00 *pl = (pl00 *)Getplayer();
    cVec from;
    cVec to;
    cVec hit;
    cVec nrm;
    float m[16];
    cVec pos;
    LineHitFace *face;
    float ang;

    if (pl->base.hp <= 0 || Obj0000_IsSet_Field_15F4_Bit_400000_10B698(pl)
        || D_005864F0.slotWait > 0 || cEmManage_CkPlCatched(&D_005864F0)) {
        return;
    }
    cVec_zero(&from);
    cVec_zero(&to);
    cVec_zero(&hit);
    cVec_zero(&nrm);
    from.x = 0.0f;
    from.y = 0.5f;
    from.z = -0.5f;
    to.x = 0.0f;
    to.y = 0.5f;
    to.z = 1.0f;
    cVec_applyMatrix(&from, pl->base.mtx);
    cVec_applyMatrix(&to, pl->base.mtx);
    if (ChkLine(&from, &to, &hit, (int)&nrm, 1, 0, &face, 1, 0, 0, 0, 0, 1) == 0) {
        return;
    }
    if ((face->flags & 0x20) == 0) {
        return;
    }
    cVec_zero(&pos);
    ang = capVu0Atan2(-nrm.x, -nrm.z);
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = -0.5f;
    MtxInitRotY(m, ang);
    cVec_applyMatrix(&pos, m);
    CVEC_ADD_TO(pos, &hit);
    pos.y = pl->base.pos->y;
    CVEC_ASSIGN_VEC(pl->jumpPos, pos);
    pl->jumpAngle = ang;
    cActionButton_set(&D_00568288, 4, 9, 0, (int)func_002DCCD0, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", SetActionJumpDown);
#endif

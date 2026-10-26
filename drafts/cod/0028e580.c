/* NON_MATCHING func_0028E580 (sn-2.95.3-136): 144 words vs 145. Retail loads the 2.0 bound after
 * the abs.s (lui/mtc1 then a hazard nop before c.lt.s); here the scheduler hoists the constant above
 * the sub.s, so the nop and one word go missing and everything after shifts. The byte at
 * cScenario+0x14 is read through a raw offset until cScenario.h names it. */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/cOmBase.h"
#include "godhand/cScenario.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
extern int cEmBase_checkDeadFlag(void *em);
extern float capVu0LengthSq(void *v);
extern int Dest_ck(void *a0, void *a1, float f12, float f13);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void cActionButton_set(void *a0, int a1, int a2, int a3, void *t0, void *t1, int t2);
extern void cScenario_startSoftTask(void *self);
extern char D_00568288[];

/* The g++ method table of a game object: getPos at 0x80/0x84, getRot at 0x88/0x8C. */
typedef struct ObjPosVt {
    char unk00[0x80];
    short getPosDelta;                  /* 0x80 */
    short pad82;
    cVec *(*getPos)(void *self);        /* 0x84 */
    short getRotDelta;                  /* 0x88 */
    short pad8A;
    cVec *(*getRot)(void *self);        /* 0x8C */
} ObjPosVt;

typedef struct ObjPos {
    char unk000[0x214];
    ObjPosVt *vt;                       /* 0x214 */
} ObjPos;

static __inline__ cVec *ObjPos_getPos(void *obj)
{
    ObjPos *o = obj;

    return o->vt->getPos((char *)o + o->vt->getPosDelta);
}

static __inline__ cVec *ObjPos_getRot(void *obj)
{
    ObjPos *o = obj;

    return o->vt->getRot((char *)o + o->vt->getRotDelta);
}

#define OBJ_GETPOS(o) ObjPos_getPos(o)
#define OBJ_GETROT(o) ObjPos_getRot(o)

/* Offer the action button that starts the soft event when the player stands close, level with and facing the object, with a clear line between them. */
__attribute__((section(".text.func_0028E580")))
void func_0028E580(ObjPos *self)
{
    cVec d;
    cVec tmp;
    cVec *pp;
    cVec *rot;

    if (*(unsigned char *)((char *)D_003C2F84 + 0x14) == 1) {
        return;
    }
    if (cEmBase_checkDeadFlag(self) == 1) {
        return;
    }
    VU0_ZERO_VSUB_XYZ_TO(&tmp, 0, OBJ_GETPOS(Getplayer()), OBJ_GETPOS(self));
    VU0_LQC2_SQC2_MEM(4, &d, &tmp);
    if (__builtin_fabsf(OBJ_GETPOS(Getplayer())->y - OBJ_GETPOS(self)->y) < 2.0f && capVu0LengthSq(&d) < 9.0f) {
        pp = OBJ_GETPOS(Getplayer());
        rot = OBJ_GETROT(Getplayer());
        if (Dest_ck(pp, OBJ_GETPOS(self), rot->y, 1.9198622f)
            && ChkLine(OBJ_GETPOS(Getplayer()), OBJ_GETPOS(self), 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 0) {
            cActionButton_set(D_00568288, 4, 14, 0, cScenario_startSoftTask, self, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0028E580);
#endif

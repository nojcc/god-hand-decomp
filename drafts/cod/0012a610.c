/* NON_MATCHING func_0012A610 (sn-2.95.3-136, extern_jtbl D_0041CEC0): the frame is 0x10 smaller than retail's, which shifts every stack offset. Retail computes the address of the reach-centre vector once, before the matrix call, and keeps it in $s4 for the distance test inside the loop; ours recomputes sp+0x30 at each use and saves one register less. Holding that address in a pointer local reproduces the frame, but that is register steering. Past that, the facing test loads Turn_dest's arguments in a different order and builds the absolute value with bc1tl/neg instead of retail's bc1f/mov/neg. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cMc.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define GAMEOBJ_F_SUSPEND   0x8000
#define ITEM_ID_FIRST       0x300       /* actor ids of items: 0x300..0x4FF */
#define ITEM_ID_END         0x500
#define PICKUP_RANGE_SQ     4.0f        /* squared XZ distance (2 units) */
#define PICKUP_ABOVE        1.7f
#define PICKUP_BELOW        -0.5f
#define PICKUP_ARC          0.52359879f /* 30 degrees either side */
#define PICKUP_EYE          0.5f

extern cMcObjList *D_00754C58;
extern int cOmWeapon_ckGetEnable(cOmWeapon *self);
extern int Obj1D00_GetField_665(cOmWeapon *self);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);
extern float Turn_dest(float *from, float *to, float cur, float max);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* Finds a weapon the player can pick up: in reach, at about the same height, in front for the wall-mounted ones, and with a clear line to it. */
__attribute__((section(".text.func_0012A610")))
cOmWeapon *func_0012A610(cGameObj *self)
{
    cVec at;
    cVec from;
    cVec to;
    cMcObj **it;
    cMcObj **cur;
    cMcObj **end;
    cOmWeapon *w;
    float dy;
    float d;

    VU0_SQC2_VF0(&at, 0);
    end = D_00754C58->end;
    it = D_00754C58->begin;
    at.x = 0.0f;
    at.y = 0.0f;
    at.z = 0.0f;
    sceVu0ApplyMatrix(&at, self->mtx, &at);
    while (it != end) {
        cur = it++;
        if (((cGameObj *)*cur)->objFlags & GAMEOBJ_F_SUSPEND)
            continue;
        if (((cGameObj *)*cur)->objFlags < 0)
            continue;
        if ((cGameObj_idInRange((cGameObj *)*cur, ITEM_ID_FIRST, ITEM_ID_END) & 0xFF) == 0)
            continue;
        switch (((cGameObj *)*cur)->actorId) {
        case 0x361: case 0x362: case 0x363: case 0x368: case 0x36D:
        case 0x375: case 0x377: case 0x378: case 0x379: case 0x37B:
        case 0x380: case 0x390:
        case 0x3A8: case 0x3A9: case 0x3AA: case 0x3AB: case 0x3AD:
        case 0x3AE: case 0x3AF: case 0x3B4: case 0x3B7:
            w = (cOmWeapon *)*cur;
            if (cOmWeapon_ckGetEnable(w) == 0)
                break;
            if (PICKUP_RANGE_SQ < capVu0MagnitudeSqXZ(&at, w->base.pos))
                break;
            dy = w->base.pos->y - self->pos->y;
            if (Obj1D00_GetField_665(w) != 0)
                dy -= 1.0f;
            if (PICKUP_ABOVE < dy)
                break;
            if (dy < PICKUP_BELOW)
                break;
            if (Obj1D00_GetField_665(w) != 0) {
                d = Turn_dest((float *)self->pos, (float *)w->base.pos, self->rot[1], 3.1415927f);
                if (PICKUP_ARC < (d < 0.0f ? -d : d))
                    break;
            }
            VU0_SQC2_VF0(&from, 0);
            VU0_SQC2_VF0(&to, 0);
            cVec_copy3(&from, self->pos);
            cVec_copy3(&to, w->base.pos);
            from.y += PICKUP_EYE;
            to.y += PICKUP_EYE;
            if (ChkLine(&from, &to, 0, 0, 7, 0x18, 0, 0, 0, 0, 0, 0, 1) == 0)
                return w;
            break;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012A610);
#endif

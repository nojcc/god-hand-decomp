/* NON_MATCHING func_0012A3C0 (sn-2.95.3-136): 101 differing words. Retail hoists all
 * four box limits other than 3.0 into f20-f23 before the loop; here 0.5 is reloaded in
 * the loop, which shifts the float registers and the prologue. Belongs after
 * cGameObj_findBurningPos in src/cod/0012a2e0.c. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* sn-2.95.3-136 */
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"
#include "godhand/sceVu0.h"

#define FIRE_ACTOR_NUM    2

extern unsigned char cOmbb_ckFire(void *actor);
extern cVec *func_001B8720(cEmActor *actor);
extern void cOmbb__clearFire(void *arg);
extern void MtxInverse(void *dst, void *src);

/* The fire box in this object's local space: x from -32 to 3, y within 0.5, z within 3. */
#define FIRE_BOX_X_MIN   -32.0f
#define FIRE_BOX_X_MAX   3.0f
#define FIRE_BOX_Z_HALF  3.0f
#define FIRE_BOX_Y_HALF  0.5f

/* The frame: the actor's point in local space, the inverse matrix, the transform's result and work copy. */
typedef struct FireBoxFrame {
    cVec local;
    float inv[16];
    cVec out;
    cVec work;
} FireBoxFrame;

#define FIREBOXFRAME_OFFSET(field) ((int)&((FireBoxFrame *)0)->field)

/* Put out the first burning actor inside the fire box in front of this object. */
__attribute__((section(".text.func_0012A3C0")))
void func_0012A3C0(cGameObj *self) {
    FireBoxFrame f;
    cEmActor *actor;
    unsigned int i;

    for (i = 0; i < FIRE_ACTOR_NUM; i++) {
        actor = func_002948C8(&D_005864F0, i);
        if (actor == 0) {
            continue;
        }
        if (cOmbb_ckFire(actor) == 0) {
            continue;
        }
        VU0_SQC2_VF0_MEM(&f.local, 0);
        MtxInverse(f.inv, self->mtx);
        VU0_LQC2(4, func_001B8720(actor), 0);
        VU0_SQC2(4, &f, FIREBOXFRAME_OFFSET(work));
        sceVu0ApplyMatrix(&f.work, f.inv, &f.work);
        VU0_LQC2(4, &f.work, 0);
        VU0_SQC2(4, &f, FIREBOXFRAME_OFFSET(out));
        cVec_copy3(&f.local, &f.out);
        if (f.local.x < FIRE_BOX_X_MIN || FIRE_BOX_X_MAX < f.local.x
            || f.local.z < -FIRE_BOX_Z_HALF || FIRE_BOX_Z_HALF < f.local.z
            || f.local.y < -FIRE_BOX_Y_HALF || FIRE_BOX_Y_HALF < f.local.y) {
            continue;
        }
        cOmbb__clearFire(actor);
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012A3C0);
#endif

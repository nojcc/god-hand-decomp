/* NON_MATCHING func_001EBA20 (sn-2.95.3-136): start motions below a height. Retail stores $vf0 at
 * 0x30($sp) and builds &pos later, in the delay slot of the obj test; ours builds &pos at the loop
 * top, so the skip branch is not a likely branch and the zero-vector store moves into a delay slot. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

#define MOTENT_NUM       5
#define MOTENT_F_DONE    2               /* flags bit: the motion step was set */
#define MOTENT_HEIGHT    -30.0f          /* margin under the trigger height */

/* When and how fast an entry's motion starts. */
typedef struct MotParam {
    int unk0;
    int timer;
    float unk8;
    float height;                       /* 0x0C */
    float step;                         /* 0x10 */
    int unk14[4];
} MotParam;

/* One object whose motion starts when it drops below a height. */
typedef struct MotEnt {
    cGameObj *obj;                      /* 0x00 */
    int unk04;
    MotParam p;                         /* 0x08 */
    int unk2C;
    unsigned int flags;                 /* 0x30 */
    char unk34[0xC];
} MotEnt;

/* The owner of the motion entries. */
typedef struct MotOwner {
    char unk00[0x5C];
    MotEnt ent[MOTENT_NUM];             /* 0x5C */
} MotOwner;

extern void SetMotionStep(void *obj, float step);

/* Set a point: x, y, z and w = 1. */
static __inline__ void vecSet(cVec *d, float x, float y, float z)
{
    d->x = x;
    d->y = y;
    d->z = z;
    d->w = 1.0f;
}

/* Start the motion of every entry whose object has dropped below its trigger height. */
void func_001EBA20(MotOwner *o)
{
    MotEnt *e = o->ent;
    int i = MOTENT_NUM - 1;
    long flags;
    MotParam p;
    float h;
    cVec pos;
    cVec zero;

    do {
        flags = e->flags;
        if (((flags >> MOTENT_F_DONE) & 1) == 0) {
            p = e->p;
            h = p.height + MOTENT_HEIGHT;
            VU0_SQC2_VF0(&pos, 0);
            if (e->obj != 0) {
                cVec_copy3(&pos, e->obj->pos);
            } else {
                vecSet(&zero, 0.0f, 0.0f, 0.0f);
                cVec_copy3(&pos, &zero);
            }
            if (pos.z <= h) {
                SetMotionStep(e->obj, p.step);
                e->flags |= 1 << MOTENT_F_DONE;
            }
        }
        e++;
        i--;
    } while (i >= 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EBA20);
#endif

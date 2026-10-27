/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

/* One tracked point: its offset in the part and its world position. */
typedef struct cPtRec {
    cVec local;                         /* 0x00 point in the part's space */
    char unk10[0x30 - 0x10];
    cVec vel;                           /* 0x30 */
    cVec pos;                           /* 0x40 world point */
    cVec prev;                          /* 0x50 world point last frame */
    char unk60[0xA0 - 0x60];
} cPtRec;

/* The points of an object and the part each one rides on. */
typedef struct cPtList {
    unsigned int num;                   /* 0x00 */
    unsigned char *part;                /* 0x04 part index of each point */
    char unk08[0x54 - 0x08];
    cOmBase **parts;                    /* 0x54 part list, or 0 for the object's children */
} cPtList;

#ifdef NON_MATCHING
/* Snap every tracked point to its part: the world position is the part's
 * matrix times the point's offset, the previous position is set to it and the
 * velocity cleared.
 * Still differs from retail: the 0xA0 record stride stays in the loop where
 * retail keeps it in $fp (the vector operator's asm stops the hoist). */
__attribute__((section(".text.func_00107C68")))
void func_00107C68(cOmBase *self, cPtList *list, cPtRec *rec)
{
    int frame[3];
    CVEC_TEMPS;
    unsigned int i;
    unsigned char *idx = list->part;

    for (i = 0; i < list->num; i++, idx++) {
        cOmBase *part;
        cPtRec *p;

        if (list->parts != 0) {
            part = list->parts[*idx];
        } else {
            part = cOmBase_childAtIdx(self, frame, *idx);
        }
        p = &rec[*idx];
        CVEC_SET_APPLY(p->pos, part->mtx, &p->local);
        CVEC_ASSIGN(p->prev, &p->pos);
        p->vel.x = 0.0f;
        p->vel.y = 0.0f;
        p->vel.z = 0.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00107C68);
#endif

/* NON_MATCHING func_00137BB8: sn only s1..s6 assignment differs; tried all decl orders, offset loop, do-while, hit temp, C++ */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cArea.h"

typedef struct AreaEnt137BB8 {
    cArea area;                 /* 0x00 */
    float range;                /* 0x30 */
    char unk34[0xA];
    unsigned char prio;         /* 0x3E */
    char unk3F[0x2D];
} AreaEnt137BB8;                /* 0x6C */

typedef struct AreaList137BB8 {
    AreaEnt137BB8 *ent;         /* 0x00 */
    int unk04[2];
    unsigned int num;           /* 0x0C */
    int unk10[8];
    AreaEnt137BB8 *cur;         /* 0x30 */
} AreaList137BB8;

extern int cArea_HitCheck(AreaEnt137BB8 *self, float range, float *pt);
extern int cArea_HitCheck_1F83E8(cArea *self, float *pt);

int func_00137BB8(AreaList137BB8 *list, float *pt)
{
    unsigned char best;
    unsigned int i;
    AreaEnt137BB8 *found;
    AreaEnt137BB8 *e;

    if (list->ent == 0)
        return 0;
    best = 0xFF;
    found = 0;
    for (i = 0; i < list->num; i++) {
        e = &list->ent[i];
        if (e == list->cur) {
            if (!(unsigned char)cArea_HitCheck(e, e->range, pt))
                continue;
        } else {
            if (!(unsigned char)cArea_HitCheck_1F83E8(&e->area, pt))
                continue;
        }
        if (e->prio < best) {
            found = e;
            best = e->prio;
        }
    }
    if (found != 0) {
        list->cur = found;
        return 1;
    }
    list->cur = 0;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00137BB8);
#endif

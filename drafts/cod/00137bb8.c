/* NON_MATCHING cAreaCamManager_selectArea: sn only s1..s6 assignment differs */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/pathRec.h"

/* cArea::HitCheck with the margin the active record is tested with. */
extern int cArea_HitCheck(cArea *self, float margin, float *pt);

int cAreaCamManager_selectArea(cAreaCamManager *self, cVec *pos)
{
    unsigned char best;
    unsigned int i;
    AreaCamRec *found;
    AreaCamRec *e;

    if (self->recs == 0)
        return 0;
    best = 0xFF;
    found = 0;
    for (i = 0; i < self->recNum; i++) {
        e = &self->recs[i];
        if (e == self->rec) {
            if (!(unsigned char)cArea_HitCheck(&e->area, e->margin, &pos->x))
                continue;
        } else {
            if (!(unsigned char)cArea_HitCheck_1F83E8(&e->area, &pos->x))
                continue;
        }
        if (e->priority < best) {
            found = e;
            best = e->priority;
        }
    }
    if (found != 0) {
        self->rec = found;
        return 1;
    }
    self->rec = 0;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", cAreaCamManager_selectArea);
#endif

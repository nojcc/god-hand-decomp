/* sn-2.95.3-136 */
#include "godhand/idPair.h"

extern int cSceAtManager_getUnit(int a0, int a1);
extern void func_002C1D68(int a0, int a1, int a2);
extern int cArea_HitCheck_1F83E8(int a0, int a1);

/* Sets up the banner's two parts (display ids 0x1D and 0x1E), points work at
 * the first part's entries, empties the queue and resets it. */
__attribute__((section(".text.func_001467E8")))
void func_001467E8(IdPair *self)
{
    unsigned short i;

    cIDBase_initialize(&self->base, 1, 0x1D);
    cIDBase_initialize(&self->part2, 1, 0x1E);
    i = 0;
    do {
        self->work[i] = cIDBase_getIDWork(&self->base, i);
        i = i + 1;
    } while (i < IDPAIR_WORK_NUM);
    self->count = 0;
    IdPair_init(self);
}

/* SN ProDG ee-gcc 2.95.3. House style inherited from the matched
   src/cod/002c2138.c, which calls all three of these callees. */





__attribute__((section(".text.cSceAtManager_AtHitCheckNo")))
int cSceAtManager_AtHitCheckNo(int a0, float *a1, int a2) {
    float pos[4];
    int buf[12];
    int u;

    u = cSceAtManager_getUnit(a0, a2);
    pos[0] = a1[0];
    pos[1] = a1[1];
    pos[2] = a1[2];
    pos[3] = 1.0f;
    if (u == 0) return 0;
    func_002C1D68(a0, buf, u);
    return cArea_HitCheck_1F83E8(buf, pos);
}

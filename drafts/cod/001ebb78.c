/* NON_MATCHING func_001EBB78 (sn-2.95.3-136): 2 differing. Retail loads the copied speed into f12 before the object into a0 for SetMotionStep; ours loads them the other way round. */
/* sn-2.95.3-136: func_001EBB78, start the dogs: each one not yet running counts its start delay down
 * (stats.grade), and when it runs out the dog is marked running and its object runs at the dog's speed. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/DogRace.h"
#include "godhand/cOm71.h"

#define DOGRACE_DOG_F_RUNNING 0x2       /* DogRaceDog.unk30: the dog has started running */

extern void SetMotionStep(void *a0, float f12);

/* Count the start delay down; nonzero once it has run out. */
static __inline__ unsigned char DogRaceDog_startWait(DogRaceDog *dog)
{
    if (dog->stats.grade != 0) {
        dog->stats.grade--;
        return 0;
    }
    return 1;
}

__attribute__((section(".text.func_001EBB78")))
void func_001EBB78(DogRace *self)
{
    int i;

    for (i = 0; i < DOGRACE_DOG_NUM; i++) {
        DogRaceDog *dog = &self->dog[i];
        long flags = (unsigned int)dog->unk30;

        if ((flags >> 1 & 1) == 0 && DogRaceDog_startWait(dog)) {
            DogRaceStats stats = dog->stats;

            dog->unk30 |= DOGRACE_DOG_F_RUNNING;
            cOm71_SetMotionRun(dog->obj);
            SetMotionStep(dog->obj, stats.speed);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EBB78);
#endif

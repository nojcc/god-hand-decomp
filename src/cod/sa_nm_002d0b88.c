/* func_002D0B88: 22 insns, register naming only - retail keeps found in a0 and
 * the table end in a1 (ours a2/a0), which also reorders the fallback stores.
 * cSnd_IsEnemyAlive: 36 insns - our kind range tests fold into one unsigned
 * compare (or a movz); retail keeps two slti tests with a branch. */
#include "include_asm.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cSnd.h"

#ifdef NON_MATCHING

extern cSndKindEnt D_003C3120;           /* fallback entry, just before the table */
extern cSndKindEnt D_003C3138[44];

static inline unsigned char SndIsEnemyKind(int kind)
{
    return kind >= COLISEUM_EM_KIND_FIRST && kind < COLISEUM_EM_KIND_END;
}

static inline unsigned char SndIsBossKind(int kind)
{
    return kind >= COLISEUM_EM_KIND_BOSS && kind < COLISEUM_EM_KIND_END;
}

int cSnd_IsEnemyAlive(void *snd, int kind)
{
    ColiseumEmNode *node;
    ColiseumEm *em;

    for (node = D_005869F0; node != 0; node = node->next) {
        em = node->em;
        if (em != 0 && SndIsEnemyKind(em->kind)) {
            if (!SndIsBossKind(em->kind) && !cEmBase_checkDeadFlag(em) && em->kind == kind) {
                return 1;
            }
        }
    }
    return 0;
}

#else

INCLUDE_ASM("asm/nonmatching", cSnd_IsEnemyAlive);

#endif

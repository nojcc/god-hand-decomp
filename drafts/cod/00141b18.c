/* NON_MATCHING func_00141B18 (sn-2.95.3-136): retail keeps the loop-3 base as a copy (daddu s2,s4) of the hoisted p+0x190; ours copy-propagates it, which flips the s3/s4 picks and the addu operand order. */
#include "include_asm.h"
#include "godhand/cIDBase.h"

#ifdef NON_MATCHING
/* func_00141B18: HUD panel init: set up the four ID bases, cache every ID work
 * pointer, restart the anims and pick up the game level. */
extern char D_00569B70[];
extern int cCoreSave_getGameLevel(void *self);

__attribute__((section(".text.func_00141B18")))
void func_00141B18(char *p)
{
    unsigned short i;
    void **w;

    cIDBase_initialize(p, 1, 0);
    cIDBase_initialize(p + 0xE0, 1, 0xC);
    cIDBase_initialize(p + 0x190, 1, 1);
    cIDBase_initialize(p + 0x210, 1, 0x14);
    w = (void **)(p + 0x98);
    for (i = 0; i < 0x12; i++) {
        cIDBase_initIDWork(p, i);
        *(void **)((int)w + i * 4) = cIDBase_getIDWork(p, i);
    }
    {
        char *b2;
        char *b3;
        void **w1;
        void **w2;
        char *b;

        i = 0;
        b2 = p + 0x190;
        b3 = p + 0x210;
        w1 = (void **)(p + 0x130);
        w2 = (void **)(p + 0x1E0);
        b = p + 0xE0;
        for (; i < 0x13; i++) {
            cIDBase_initIDWork(b, i);
            *(void **)((int)w1 + i * 4) = cIDBase_getIDWork(b, i);
        }
        b = b2;
        for (i = 0; i < 0xC; i++) {
            cIDBase_initIDWork(b, i);
            *(void **)((int)w2 + i * 4) = cIDBase_getIDWork(b, i);
        }
        cIDBase_restartAnim(p);
        *(unsigned char *)(p + 0x1C) = 1;
        cIDBase_restartAnim(b3);
        *(unsigned char *)(b3 + 0x1C) = 1;
    }
    *(int *)(*(char **)(p + 0xC8) + 0x2C) |= 0x400;
    *(int *)(*(char **)(p + 0xCC) + 0x2C) |= 0x400;
    *(int *)(*(char **)(p + 0xD0) + 0x2C) |= 0x400;
    *(int *)(*(char **)(p + 0xD4) + 0x2C) |= 0x400;
    *(short *)(p + 0x17C) = cCoreSave_getGameLevel(D_00569B70);
    *(unsigned char *)(p + 0x26D) = 1;
    *(unsigned char *)(p + 0x26C) = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00141B18);
#endif

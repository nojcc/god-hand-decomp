/* NON_MATCHING func_00300458: pool allocator.
 * Control flow and switch compare tree match retail; retail hoists kind<2 and the case constants 1/2/3 into s2-s5 before the loop (frame 0x70), this hoists only 1 (frame 0x40) and fills the switch delay slots instead. */
#include "include_asm.h"

#ifdef NON_MATCHING
#define POOL_NUM   0x100
#define POOL_SIZE  0x260

typedef struct PoolObj300458 {
    char pad000[0x190];
    unsigned char kind;                 /* 0x190 */
} PoolObj300458;

extern unsigned int D_00741940[POOL_NUM / 32];  /* slot in use */
extern unsigned int D_00741960[POOL_NUM / 32];
extern unsigned int D_00741980[POOL_NUM / 32];
extern char D_0071B940[POOL_NUM][POOL_SIZE];

extern void func_003A52F0(void *dst, int c, int n);
extern PoolObj300458 *func_00304D48(void *mem);
extern PoolObj300458 *InitObjectSetVtable_4FCF8_304D70(void *mem);
extern PoolObj300458 *InitObjectSetVtable_4FC98_304DB0(void *mem);
extern PoolObj300458 *InitObjectSetVtable_4FC38_304DF0(void *mem);

__attribute__((section(".text.func_00300458")))
PoolObj300458 *func_00300458(unsigned char kind)
{
    PoolObj300458 *o;
    int i;
    unsigned int bit;

    for (i = 0; i < POOL_NUM; i++) {
        bit = 0x80000000 >> (i & 31);
        if (!(D_00741940[(unsigned int)i >> 5] & bit)) {
            D_00741940[(unsigned int)i >> 5] |= bit;
            D_00741960[(unsigned int)i >> 5] &= ~bit;
            D_00741980[(unsigned int)i >> 5] &= ~bit;
            func_003A52F0(D_0071B940[i], 0, POOL_SIZE);
            switch (kind) {
            case 0:
                o = func_00304D48(D_0071B940[i]);
                break;
            case 1:
                o = InitObjectSetVtable_4FCF8_304D70(D_0071B940[i]);
                break;
            case 2:
                o = InitObjectSetVtable_4FC98_304DB0(D_0071B940[i]);
                break;
            case 3:
                o = InitObjectSetVtable_4FC38_304DF0(D_0071B940[i]);
                break;
            default:
                o = func_00304D48(D_0071B940[i]);
                break;
            }
            o->kind = kind;
            return o;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00300458);
#endif

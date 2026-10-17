/* halt demote func_001C2408 */
#ifdef NON_MATCHING
#include "godhand/vu0.h"
extern int cCoreSave_getClearNum(void *save);
extern void cCoreSave_addGold(void *save, int amount, int unk);
extern void cCockGetPoint_setData(void *cock, void *pos, int amount, int id);
extern char D_00569B70[];
extern void *D_003BD6E8;

__attribute__((section(".text.func_001C2408")))
void func_001C2408(void *self, int amount)
{
    int clear;
    char pos[16] __attribute__((aligned(16)));
    void *src;

    if (amount <= 0) {
        return;
    }
    clear = cCoreSave_getClearNum(D_00569B70);
    if (clear != 0) {
        amount <<= 1;
    }
    cCoreSave_addGold(D_00569B70, amount, 0);
    src = *(void **)((char *)self + 0xF0);
    VU0_LQC2(4, src, 0);
    VU0_SQC2(4, pos, 0);
    cCockGetPoint_setData((char *)D_003BD6E8 + 0x15C0, pos, amount & 0xFFFF,
                          *(short *)((char *)self + 0x2AC));
}

#else
INCLUDE_ASM("nonmatching", func_001C2408);
#endif

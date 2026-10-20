/* NON_MATCHING func_00148D30 (sn-2.95.3-136; PARK, 41 diffs): the &D_007474A0 base stays in a saved reg instead of a2 with a branch-2 copy into s7, and that shifts every saved reg. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_00148D30: rebind every model part's texture word from the room resource,
 * either by name lookup (flag 0x2000000) or by slot index. */
extern char D_007474A0[];
extern char D_004664A0[];
extern int D_0041EA50[];
extern int D_0041EA58[];
extern int *func_0031CDC0(int *base, int *key, int *alt, int nth);
extern char *cIDBase_getSlotPtr(void *unused, void *pack, unsigned char idx);
extern int func_00151398(char *w, void *name, int type);
extern long func_00151368(char *w, int h);

__attribute__((section(".text.func_00148D30")))
void func_00148D30(char *a0, int a1)
{
    char *g = D_007474A0;
    char *L[2];
    int n;
    int i;
    int flag;

    if (*(int *)(g + 0x5FC) == 0)
        return;
    i = 0;
    if (*(int *)(a0 + 0x380) & 0x2000000) {
        L[0] = *(char **)(a0 + 0x388);
        n = *(unsigned short *)(L[0] + 0xA);
        flag = *(int *)(g + 0x210) & 1;
        if (n == 0)
            return;
        do {
            int id;

            L[1] = (char *)(*(int *)((int)L[0] + i * 4 + 0x20) + (int)L[0]);
            id = *(unsigned char *)(L[1] + 0x16);
            if (id != 0xFF) {
                char *gg = D_007474A0;
                int *t = func_0031CDC0(*(int **)(gg + 0x5FC), D_0041EA50, D_0041EA58, id);
                int h = func_00151398(D_004664A0, t, a1);
                char *o = *(char **)((flag << 6) + (int)(a0 + 0x300) + i * 4);

                *(long *)(o + 0x20) = func_00151368(D_004664A0, h);
            }
            i++;
        } while (i < n);
    } else {
        char *g2 = D_007474A0;

        L[1] = *(char **)(a0 + 0x388);
        n = *(unsigned short *)(L[1] + 0xA);
        flag = *(int *)(g2 + 0x210) & 1;
        if (n == 0)
            return;
        do {
            int id;

            L[0] = (char *)(*(int *)((int)L[1] + i * 4 + 0x20) + (int)L[1]);
            id = *(unsigned char *)(L[0] + 0x16);
            if (id != 0xFF) {
                char *t = cIDBase_getSlotPtr(D_004664A0, *(void **)(g2 + 0x5FC), id);
                int h = func_00151398(D_004664A0, t, a1);
                char *o = *(char **)((flag << 6) + (int)(a0 + 0x300) + i * 4);

                *(long *)(o + 0x20) = func_00151368(D_004664A0, h);
            }
            i++;
        } while (i < n);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00148D30);
#endif

/* NON_MATCHING func_00351A08 (cygnus dr, s0/s1 swap): best 14 with -freorder-blocks dropped: retail keeps hn in s0 and the +0xD30 time block in s1 (ours the reverse), and loads total before t[0]. Reading total into a local fixes the load order (24) but not the saved-register swap; all-through-hn and positive-test forms worse. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0xC];
    void *vtbl;      /* 0x0C */
} SfDev;

typedef struct {
    char pad0[0x164];
    int start;       /* 0x164 (0xE94 in the handle) */
    char pad168[0x1F0 - 0x168];
    int total;       /* 0x1F0 (0xF20 in the handle) */
} SfTime;

typedef struct {
    SfDev *dev;      /* 0x000 */
    char pad4[0xD30 - 4];
    SfTime tm;       /* 0xD30 */
} SfHn;

extern char D_004593D8[];
extern int func_0034CF38(SfHn *hn, int *pos, int *rate);
extern int func_0036C920(int pos, int a, int rate);

int func_00351A08(SfHn *hn)
{
    SfTime *tm = &hn->tm;
    int t[2];
    int r;

    if (hn->dev->vtbl != D_004593D8) {
        t[0] = 0;
        t[1] = 44100;
    } else if (func_0034CF38(hn, &t[0], &t[1]) == 0) {
        return -1;
    }
    tm->total += t[0];
    r = func_0036C920(tm->total, *(int *)((char *)hn + 0xD94), t[1]) - tm->start;
    return r < 0 ? 0 : r;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00351A08);
#endif

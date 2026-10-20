/* NON_MATCHING func_00353550: 45: retail shares hdr (o+0x90C) in a0 from the bne delay slot while keeping o in s0 and st in s2, and returns 0 straight from the GetArrayElem test; ours either ties st to o's register (shared hdr) or recomputes hdr per branch */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[8];
    int w;
    int h;
} Hdr353550;

typedef struct {
    char pad0[0x10];
    int cnt10;
    int cnt14;
} Stat353550;

typedef struct {
    int p0;
    int p4;
} Arg353550;

extern int GetArrayElemA0C_35A1C8(void *, int);
extern int func_00369478(int, int, int);
extern int func_00369920(int, int, int);

int func_00353550(char *o, int mode, Arg353550 *a)
{
    int r;
    Stat353550 *st;
    Hdr353550 *hdr;

    if (GetArrayElemA0C_35A1C8(o, 7) == 0) {
        st = (Stat353550 *)(o + 0x950);
        if (mode == 3) {
            hdr = (Hdr353550 *)(o + 0x90C);
            r = func_00369478(a->p0, a->p4, hdr->w * hdr->h);
            if (r == 0) {
                return r;
            }
            st->cnt10++;
        } else {
            r = 0;
            if (mode == 2) {
                hdr = (Hdr353550 *)(o + 0x90C);
                r = func_00369920(a->p0, a->p4, hdr->w * hdr->h);
                if (r == 0) {
                    return r;
                }
                st->cnt14++;
            }
        }
        return r;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00353550);
#endif

/* NON_MATCHING func_00353550: 45: retail shares hdr (o+0x90C) in a0 from the bne delay slot while keeping o in s0 and st in s2, and returns 0 straight from the GetArrayElem test; ours either ties st to o's register (shared hdr) or recomputes hdr per branch */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[8];
    int w;
    int h;
} FrmHdr;

typedef struct {
    char pad0[0x10];
    int cnt10;
    int cnt14;
} FrmStat;

typedef struct {
    int p0;
    int p4;
} FrmArg;

extern int GetArrayElemA0C_35A1C8(void *, int);
extern int func_00369478(int, int, int);
extern int func_00369920(int, int, int);

int func_00353550(char *o, int mode, FrmArg *a)
{
    int r;
    FrmStat *st;
    FrmHdr *hdr;

    if (GetArrayElemA0C_35A1C8(o, 7) == 0) {
        st = (FrmStat *)(o + 0x950);
        if (mode == 3) {
            hdr = (FrmHdr *)(o + 0x90C);
            r = func_00369478(a->p0, a->p4, hdr->w * hdr->h);
            if (r == 0) {
                return r;
            }
            st->cnt10++;
        } else {
            r = 0;
            if (mode == 2) {
                hdr = (FrmHdr *)(o + 0x90C);
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

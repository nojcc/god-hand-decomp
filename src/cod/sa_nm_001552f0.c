/* 13 differing insns: retail keeps base/quotient in v0->v1 and reloads 0x18
 * into v0 for the second divide check; ours swaps v0/v1.
 * Tried pointer
 * forms, MdlPack struct, cnt/base/rec locals, a second divisor variable. */
#include "include_asm.h"
#include "godhand/mdlPkt.h"

#ifdef NON_MATCHING
int func_001552F0(MdlObj *self, int idx)
{
    PackRef r;
    int d = 0x18;
    int n;
    MdlPack *base;
    char *rec;
    int cnt;

    base = self->pack;
    r.base = base;
    rec = base->ofs[idx] + (char *)base;
    r.rec = (MdlRec *)rec;
    cnt = *(unsigned short *)(rec + 0x14);
    n = cnt / d;
    if (cnt % d != 0) {
        n = cnt / d + 1;
    }
    return n * 0x70 + 0x10;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001552F0);
#endif

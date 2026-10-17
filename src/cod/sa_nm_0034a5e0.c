/* NON_MATCHING func_0034A5E0 (cygnus-2.96 dr): 19 diffs: i=0 / s-reg save order and loop entry layout differ */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Hdr34A5E0 {
    char pad0[0x38];
    int total;
    void *cb;
} Hdr34A5E0;

typedef struct Obj34A5E0 {
    char pad0[0x9C8];
    long long pos;
    char pad9D0[0x2004 - 0x9D0];
    Hdr34A5E0 *hdr;
} Obj34A5E0;

extern char D_00459410[];
extern void func_0034A400(void);
extern int Obj34D8_GetTri78_Times100(Obj34A5E0 *o);
extern int func_003A50B4(const char *a, const char *b, int n);
extern int func_0034A6F8(Obj34A5E0 *o, int *a, int *b);

void func_0034A5E0(Obj34A5E0 *o, char *p, int len, int *out)
{
    int a, b;
    int i;
    Hdr34A5E0 *h;

    *out = 0;
    h = o->hdr;
    i = 0;
    if (Obj34D8_GetTri78_Times100(o) >= 0x6C) {
        h->cb = func_0034A400;
        return;
    }
    for (; i < len - 0x12; i += 0x12) {
        int r = func_003A50B4(p, D_00459410, 0x12);
        p += 0x12;
        if (r == 0)
            continue;
        h->cb = func_0034A400;
        break;
    }
    *out = i;
    o->pos += i;
    if (func_0034A6F8(o, &a, &b) == 0)
        h->total += (i / (a * 0x12)) << 5;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034A5E0);
#endif

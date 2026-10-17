/* NON_MATCHING func_003BA3D8 (cygnus-2.96 dr): 2 diffs: dbr likely/non-likely choice inverted on fs<3 and frm<38 branches (same insns) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Ac3BA3D8 {
    char pad0[0x28];
    int order;
    int rate;
    int bitrate;
    int size;
} Ac3BA3D8;

extern char D_00460978[];
extern char D_004609A8[];
extern char D_004609D8[];
extern int D_003FC518[];
extern int D_003FC528[];
extern int D_003FC5C8[][40];
extern void func_003B9DE0(char *msg);

int func_003BA3D8(Ac3BA3D8 *a, unsigned char *p)
{
    unsigned int fs;
    unsigned int frm;
    int off;

    if (p[0] == 0x0B && p[1] == 0x77) {
        a->order = 1;
        off = 4;
    } else if (p[0] == 0x77 && p[1] == 0x0B) {
        a->order = 2;
        off = 5;
    } else {
        func_003B9DE0(D_00460978);
        return -1;
    }
    p += off;
    fs = *p >> 6;
    if (fs >= 3) {
        func_003B9DE0(D_004609A8);
        return -1;
    }
    a->rate = D_003FC518[fs];
    frm = *p & 0x3F;
    if (frm >= 38) {
        func_003B9DE0(D_004609D8);
        return -1;
    }
    a->bitrate = D_003FC528[frm];
    a->size = D_003FC5C8[fs][frm] * 2;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003BA3D8);
#endif

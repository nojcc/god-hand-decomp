#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x10];
    int busy;      /* 0x10 */
    int put;       /* 0x14 */
    int end;       /* 0x18 */
} ViBuf;

typedef struct {
    char pad0[0x14];
    int eos;       /* 0x14 */
    int term;      /* 0x18 */
    char pad1C[0x28 - 0x1C];
    char dec[0x48];/* 0x28 (0x1150 in the work) */
    ViBuf vb;      /* 0x70 (0x1198 in the work) */
} MpvTerm;

typedef struct {
    char pad0[0x1128];
    MpvTerm t;     /* 0x1128 */
} MpvWork;

typedef struct {
    char pad0[0x1FC0];
    MpvWork *w;    /* 0x1FC0 */
} SfMpv;

extern char D_00459748[];
extern int func_0039AA38(void *dec);
extern int viBufAddDMA(ViBuf *vb);
extern int sfmpvp_PutVibuf(ViBuf *vb, void *data, int n);

int func_003566E8(int a0, int a1, SfMpv *sf)
{
    MpvWork *w = sf->w;
    MpvTerm *t = &w->t;
    ViBuf *vb = &w->t.vb;

    if (t->term == 1) {
        func_0039AA38(w->t.dec);
        return 1;
    }
    viBufAddDMA(vb);
    if (t->eos != 0 && vb->busy == 0) {
        t->term = 1;
        sfmpvp_PutVibuf(vb, D_00459748, 0x10);
        vb->put = vb->end;
        viBufAddDMA(vb);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003566E8);
#endif

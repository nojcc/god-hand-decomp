/* NON_MATCHING func_003454F0: then-path matches via explicit locals; else-path store order (retail C,0,8,4) cannot be steered, so cross-jumping merges sw v0,8(a1) tails; */
#include "include_asm.h"
#include "godhand/criStm.h"

#ifdef NON_MATCHING
typedef struct {
    float vhz;    /* 0x0 */
    int disp;     /* 0x4 */
    int max;      /* 0x8 */
    int mode;     /* 0xC */
} MwsfdIprm;

typedef struct {
    int pad0;
    MwsfdIprm iprm;     /* 0x04 */
    char pad14[0x38 - 0x14];
    int f38;            /* 0x38 */
    int f3C;            /* 0x3C */
    char pad40[0x5C - 0x40];
    int f5C;            /* 0x5C */
    char pad60[0x188C - 0x60];
    int f188C;          /* 0x188C */
} MwsfdWork;

extern MwsfdWork *GetD003EC7E0_3452B0(void);
extern void MWSFSVR_SetMwsfdSvrFlg(int f);

void func_003454F0(MwsfdIprm *iprm)
{
    MwsfdWork *w = GetD003EC7E0_3452B0();
    MwsfdIprm *dst;

    func_003A52F0(w, 0, 0x1890);
    MWSFSVR_SetMwsfdSvrFlg(0);
    w->f5C = 0;
    dst = &w->iprm;
    if (iprm != 0) {
        int disp = iprm->disp;
        int mode = iprm->mode;
        float vhz;
        int max;

        dst->disp = disp;
        vhz = iprm->vhz;
        max = iprm->max;
        dst->mode = mode;
        dst->vhz = vhz;
        dst->max = max;
    } else {
        dst->mode = 0;
        dst->vhz = 59.94f;
        dst->max = 1;
        dst->disp = dst->max;
    }
    w->f3C = 0;
    w->f38 = 1;
    w->f188C = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003454F0);
#endif

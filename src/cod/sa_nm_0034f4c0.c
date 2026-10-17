/* NON_MATCHING func_0034F4C0 (NEAR-MISS): cygnus dr; 6 diffs, same size: retail allocates the len<0x40 test and the 0x40000 constant to v1 (v0 already holding the return 1 in-block), ours v0; ret-variable, switch, negated-bool, comma-guard forms and -fno-gcse no fix */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x3C];
    int ended;            /* 0x3C */
} Ctx34F4C0;

typedef struct {
    char pad0[0x8];
    Ctx34F4C0 *ctx;       /* 0x8 */
    char padC[0x4];
    int arg;              /* 0x10 */
    char pad14[0xC];
    int ofs;              /* 0x20 */
} Sub34F4C0;

typedef struct {
    char pad0[0x1F74];
    Sub34F4C0 sub;        /* 0x1F74 */
} Sfd34F4C0;

extern int func_00368A28(unsigned char *buf);
extern int func_0034C7D0(Sfd34F4C0 *w, int arg);
extern int sfmps_IsEffectiveEndcode(Sfd34F4C0 *w, int code);
extern void func_0034F390(Sfd34F4C0 *w, int flag);
extern void func_0034F658(Sfd34F4C0 *w, int *out);

int func_0034F4C0(Sfd34F4C0 *w, unsigned char *buf, int len, int len2)
{
    Sub34F4C0 *s = &w->sub;
    Ctx34F4C0 *c = s->ctx;
    int arg = s->arg;
    int code;
    int r;

    if (len >= 4) {
        code = func_00368A28(buf);
        if (code == 0x80000) {
            if (s->ofs < 0)
                s->ofs = func_0034C7D0(w, arg) + 4;
            c->ended = 1;
        } else if (code != 0) {
            c->ended = 0;
        }
    } else {
        code = 0;
    }
    if (sfmps_IsEffectiveEndcode(w, code)) {
        func_0034F390(w, 1);
        return 0;
    }
    if (len2 < 4) {
        func_0034F658(w, &r);
        if (r != 0)
            return 0;
    }
    if (len < 0x40 && (code == 0x10000 || code == 0x40000)) {
        func_0034F658(w, 0);
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034F4C0);
#endif

/* NON_MATCHING func_00383F50 (sn-2.95.3-136; PARK, 56 diffs): two-mixer sibling of func_00382660 (also NM). Control flow
 * matches; retail puts sel/mix/mute in s0/s1/s2 (ours s1/s2/s0) and the last loop is one word off. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Sel383F50 {
    char pad00[4];
    unsigned char cur;                  /* 0x04 0 = all channels */
    char pad05[3];
    short vol[5];                       /* 0x08 [0] = all, [1..] channels */
} Sel383F50;

typedef struct Mix383F50 {
    char pad00[8];
    int nch;                            /* 0x08 */
    char pad0C[0x0C];
    unsigned char mute[8];              /* 0x18 */
    void *h;                            /* 0x20 */
} Mix383F50;

extern int func_00384138(char *o, Sel383F50 *s);
extern void func_0032EC78(void *h, int ch, int vol);

__attribute__((section(".text.func_00383F50")))
void func_00383F50(char *o, char *ev)
{
    Mix383F50 *c;
    Mix383F50 *c2;
    Sel383F50 *s;
    int i;
    int j;

    s = (Sel383F50 *)(o + 0x370);
    c = (Mix383F50 *)(o + 0x414);
    c2 = (Mix383F50 *)(o + 0x43C);
    if ((*(int *)(ev + 0x34) & 0xA000) == 0)
        return;
    c->mute[s->cur] ^= 1;
    c2->mute[s->cur] ^= 1;
    if (s->cur == 0) {
        for (j = 0; j < 4; j++) {
            c->mute[j + 1] = c->mute[s->cur];
            c2->mute[j + 1] = c2->mute[s->cur];
        }
    } else if (func_00384138(o, s) != 0) {
        c->mute[0] = c->mute[s->cur];
        c2->mute[0] = c2->mute[s->cur];
    }
    if (c->h == 0)
        return;
    if (s->cur != 0) {
        if (c->mute[s->cur] != 0)
            func_0032EC78(c->h, s->cur - 1, -0x3C0);
        else
            func_0032EC78(c->h, s->cur - 1, s->vol[s->cur]);
    } else if (c->mute[s->cur] != 0) {
        for (i = 0; i < c->nch; i++)
            func_0032EC78(c->h, i, -0x3C0);
    } else {
        for (i = 1; i <= c->nch; i++)
            func_0032EC78(c->h, i - 1, s->vol[i]);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00383F50);
#endif

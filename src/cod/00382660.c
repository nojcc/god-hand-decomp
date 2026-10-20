/* NON_MATCHING func_00382660: channel mute toggle and volume push.
* The control flow and the first copy loop (through c->mute) match.
* Retail puts sel/mix/mute in s0/s1/s2 (mine s1/s2/s0) and keeps i+1 in s0 in the last loop. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct MuteSel {
    char pad00[2];
    unsigned char cur;                  /* 0x02 0 = all channels */
    char pad03;
    short vol[5];                       /* 0x04 [0] = all, [1..] channels */
} MuteSel;

typedef struct MuteMix {
    char pad00[8];
    int nch;                            /* 0x08 */
    char pad0C[0x0C];
    unsigned char mute[8];              /* 0x18 */
    void *h;                            /* 0x20 */
} MuteMix;

extern int func_003827F0(char *o, MuteSel *s);
extern void func_0032EC78(void *h, int ch, int vol);

__attribute__((section(".text.func_00382660")))
void func_00382660(char *o, char *ev)
{
    MuteMix *c;
    unsigned char *f;
    MuteSel *s;
    int i;
    int j;

    f = (unsigned char *)(o + 0x360);
    s = (MuteSel *)(o + 0x318);
    c = (MuteMix *)(o + 0x348);
    if ((*(int *)(ev + 0x34) & 0xA000) == 0)
        return;
    f[s->cur] ^= 1;
    if (s->cur == 0) {
        for (j = 0; j < 4; j++)
            c->mute[j + 1] = c->mute[s->cur];
    } else if (func_003827F0(o, s) != 0) {
        c->mute[0] = f[s->cur];
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
        for (i = 0; i < c->nch; i++)
            func_0032EC78(c->h, i, s->vol[i + 1]);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00382660);
#endif

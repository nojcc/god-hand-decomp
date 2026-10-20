/* NON_MATCHING func_003520D8: SFD audio time: latch the stream base time, then turn a time stamp into a play position, counting samples on while the stamp repeats.
 * Logic matches; retail keeps tc/s/ts/info/unit/rate in s0/s1/s2/s3/s5/s6, base in v1 and computes &tc->last late (s4), reusing s1 for t; this hoists &tc->last to entry and shifts every pointer one register.
 * Dropping the base local spills out (90). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Ts3520D8 {
    long time;                          /* 0x00 */
    long unk08;                         /* 0x08 */
} Ts3520D8;

typedef struct Info3520D8 {
    char pad00[0x10];
    int rateNo;                         /* 0x10 index into D_00459920 */
    int unit;                           /* 0x14 samples per stamp */
    int kind;                           /* 0x18 */
} Info3520D8;

typedef struct Tc3520D8 {
    int unit;                           /* 0x00 */
    int base;                           /* 0x04 */
    int run;                            /* 0x08 */
    char pad0C[4];
    long last;                          /* 0x10 */
    long lastUnk;                       /* 0x18 */
} Tc3520D8;

typedef struct Sfd3520D8 {
    char pad000[0x150];
    long base;                          /* 0x150 */
} Sfd3520D8;

extern int D_00459920[];

extern long func_00352258(int n, int rate);
extern int func_003A50B4(const void *a, const void *b, int n);

__attribute__((section(".text.func_003520D8")))
long func_003520D8(Sfd3520D8 *s, Tc3520D8 *tc, Info3520D8 *info, Ts3520D8 *ts, int cont, long *out)
{
    int rate;
    int unit;
    long base;
    long t;
    int n;

    rate = D_00459920[info->rateNo];
    unit = info->unit;
    base = s->base;
    if (base < 0) {
        base = ts->time - func_00352258(unit, rate);
        if (base < 0)
            base = 0;
        s->base = base;
    }
    t = ts->time - base;
    if (t < 0)
        t = 0;
    if (func_003A50B4(&tc->last, ts, 4) != 0) {
        tc->last = ts->time;
        tc->lastUnk = ts->unk08;
        tc->unit = unit;
        tc->base = 0;
        tc->run = (info->kind == 3) ? 1 : 0;
        *out = ts->time;
        return t;
    }
    if (cont != 0) {
        tc->base = tc->base + tc->run + 1;
        tc->unit = 0;
        tc->run = 0;
    }
    n = unit - tc->unit;
    tc->run = (n < tc->run) ? tc->run : n;
    t += func_00352258(tc->base + n, rate);
    if (t < 0)
        t = 0;
    return t;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003520D8);
#endif

/* NON_MATCHING func_00353630: decide whether the next SFD frame is due: hand off to the time callback when set, else correct the time and test it against the frame clock.
* Control flow and loads match; retail holds t/rate/cnt in s4/s3/s5 (here s3/s5/s4) and uses a0 as the base temp, so it re-copies s and mode before the callback (3 words).
* Declaration order changes nothing; direct s->tmr access loses the two clock base registers (91). */
#include "include_asm.h"

#ifdef NON_MATCHING
#define SFD_FRAME_LIMIT  1000

typedef struct FrmClock {
    int on;                             /* 0x00 */
    char pad04[0x20];
    int time;                           /* 0x24 */
    int rate;                           /* 0x28 */
} FrmClock;

typedef struct FrmTimer {
    char pad000[0x18];
    int (*func)(void *s, int mode, int t, int rate);    /* 0x18 */
    char pad01C[0xC0 - 0x1C];
    FrmClock clk;                      /* 0x0C0 the decoder clock */
    char pad0EC[0x118 - 0xEC];
    FrmClock sync;                     /* 0x118 the clock it syncs to */
    char pad144[0x164 - 0x144];
    int base;                           /* 0x164 */
} FrmTimer;

typedef struct FrmCount {
    char pad00[0x84];
    int frames;                         /* 0x84 */
} FrmCount;

typedef struct FrmDueHn {
    char pad0000[0xAA4];
    int frameMax;                       /* 0xAA4 */
    char pad0AA8[0xD30 - 0xAA8];
    FrmTimer tmr;                      /* 0xD30 */
    char pad0E98[0x1FC0 - 0xD30 - sizeof(FrmTimer)];
    FrmCount *cnt;                     /* 0x1FC0 */
} FrmDueHn;

extern void func_0035A540(FrmTimer *t, int time);
extern int func_0035A5E0(FrmTimer *t, int time);
extern int func_0035BA50(FrmDueHn *s);
extern void func_0035AB98(FrmDueHn *s, int *a, int *b);
extern void func_003537A8(FrmDueHn *s, int mode, int *num, int *den);
extern int func_00366918(int a, int b, int time, int a3);

__attribute__((section(".text.func_00353630")))
int func_00353630(FrmDueHn *s, int mode)
{
    FrmTimer *tm;
    int rate;
    int t;
    FrmCount *cnt;
    FrmClock *clk;
    FrmClock *sync;
    int a;
    int b;
    int num;
    int den;

    tm = &s->tmr;
    t = 0;
    sync = &tm->sync;
    clk = &tm->clk;
    cnt = s->cnt;
    if (sync->on != 0)
        t = clk->time - sync->time + tm->base;
    rate = clk->rate;
    if (tm->func != 0)
        return tm->func(s, mode, t, rate);
    if (mode == 1)
        func_0035A540(tm, t);
    if ((unsigned int)(mode - 1) < 2)
        t = func_0035A5E0(tm, t);
    if (func_0035BA50(s) <= SFD_FRAME_LIMIT) {
        if (cnt->frames >= s->frameMax)
            return 0;
    }
    func_0035AB98(s, &a, &b);
    if (a < 0)
        return 0;
    func_003537A8(s, mode, &num, &den);
    if (func_00366918(a, b, t - rate * num / den) != 0)
        return 0;
    cnt->frames++;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00353630);
#endif

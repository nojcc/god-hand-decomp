#include "include_asm.h"
#include "godhand/sftim.h"

int func_003526D0(SftimHn *hn, SftimInfo *info);
void Sftim_setTimecode(SftimHn *hn, SftimInfo *info, int time, int update);

#ifdef NON_MATCHING
extern void func_00352888(int time, int rate, int drop, int ofs, SftimTc *tc);
extern void func_00352AA0(SftimTc *src, SftimTc *dst);
/* Register allocation: retail builds the result in v0 directly; ours uses a3 plus a move. */
#else
#endif

#ifdef NON_MATCHING
/* Register allocation: retail loads rate straight into a1; ours goes through v1 (8 insns). */
__attribute__((section(".text.Sftim_setTimecode")))
void Sftim_setTimecode(SftimHn *hn, SftimInfo *info, int time, int update)
{
    SftimWork *w = &hn->tim;
    int rate = info->rate;
    int drop = info->drop;
    int ofs = info->ofs;

    if (update != 0 && time >= 0) {
        func_00352888(time, rate, drop, ofs, &hn->tim.tc);
        return;
    }
    if (w->rec[1].valid == 0) {
        if (hn->f36B0 == 0) {
            w->tc.rate = rate;
            w->tc.drop = 0;
            w->tc.hour = 0;
            w->tc.min = 0;
            w->tc.sec = 0;
            w->tc.frame = 0;
        }
    } else if (update != 0) {
        func_00352AA0(&w->rec[1].tc, &w->tc);
        w->fld[0].fieldB = w->tc.fieldB;
        w->fld[ofs].fieldB = w->tc.fieldB;
    } else {
        w->tc.rate = w->rec[1].tc.rate;
        w->tc.drop = w->rec[1].tc.drop;
        w->tc.hour = w->rec[1].tc.hour;
        w->tc.min = w->rec[1].tc.min;
        w->tc.sec = w->rec[1].tc.sec;
        w->tc.frame = w->rec[1].tc.frame;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", Sftim_setTimecode);
#endif

#ifdef NON_MATCHING
/* Retail computes the field parity before the shift, and allocates the non-drop h/m/s chain differently (12 insns). */
#else
#endif

#ifdef NON_MATCHING
/* Scheduling and register allocation of the div/mod chain differ (39 insns). */
__attribute__((section(".text.func_00352AA0")))
void func_00352AA0(SftimTc *src, SftimTc *dst)
{
    int fields = src->fieldA + src->fieldB;
    int rate = src->rate;
    int fps = D_004596C8[rate];
    int half = fields / 2;
    int f = src->frame + src->frameAdd + 1 + half;
    int frame = f % fps;
    int s = src->sec + f / fps;
    int sec = s % 60;
    int m = src->min + s / 60;
    int min = m % 60;
    int hour = src->hour + m / 60;

    if (src->drop != 0 && sec == 0 && min % 10 != 0) {
        if ((unsigned int)frame < 2) {
            frame = 2;
        }
    }
    dst->rate = rate;
    dst->fieldB = fields - half * 2;
    dst->hour = hour;
    dst->drop = src->drop;
    dst->min = min;
    dst->sec = sec;
    dst->frame = frame;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00352AA0);
#endif

#ifdef NON_MATCHING
/* Retail keeps &rec[0] in a register and does not write the difference back to the stack. */
__attribute__((section(".text.SftimHn_recordLastFrame")))
void SftimHn_recordLastFrame(SftimHn *hn, int *hdr)
{
    SftimTc tc = hn->tim.tc;
    int time;
    int unit;
    SftimRec *last;
    SftimRec *top;

    SFTIM_Tc2Time(&tc, &time, &unit);
    hn->tim.rec[3].tc = tc;
    last = &hn->tim.rec[3];
    top = &hn->tim.rec[1];
    time -= hn->tim.rec[0].time;
    last->valid = 1;
    last->time = time;
    last->unit = unit;
    if (time >= top->time) {
        *top = *last;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", SftimHn_recordLastFrame);
#endif

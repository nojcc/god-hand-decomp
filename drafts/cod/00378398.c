/* sn-2.95.3-136 */
/* func_00378398 (fp_hazard_rules mtc1), the sibling of func_003781F8 that
 * reads the second curve table. Same difference: retail places the
 * interpolation and exact-point bodies after the loop's out-of-range exit,
 * and shares the exact-point store with the last-point test. */
#include "include_asm.h"
#include "godhand/sndBank.h"
#include "godhand/seqNode.h"

#ifdef NON_MATCHING
/* A sound entry as the curve lookup reads it. */
typedef struct SndCurveUser {
    short bank;                 /* 0x00 index into D_0076DF10 */
    char unk02[0x1E - 0x02];
    signed char curveSet;       /* 0x1E */
} SndCurveUser;

/* One point of a volume curve. */
typedef struct SndCurvePt {
    short x;
    unsigned short y;
} SndCurvePt;

/* A curve: its points, and how many. */
typedef struct SndCurve {
    int ptOfs;                  /* 0x00 from the bank table */
    short unk04;
    unsigned short num;         /* 0x06 */
} SndCurve;

/* The bank table header the offsets are taken from. */
typedef struct SndCurveTbl {
    int unk00;
    int setOfs;                 /* 0x04 curve sets: four curve numbers each */
    int curveOfs;               /* 0x08 */
    int curveOfs2;              /* 0x0C */
} SndCurveTbl;

/* Looks up the bank's volume curve for the current output mode at `x`,
 * interpolating between points. Writes the level to *out; returns 0, 1 when
 * the mode has no curve, or -1 when x is out of range. */
__attribute__((section(".text.func_00378398")))
int func_00378398(short x, SndCurveUser *user, unsigned short *out)
{
    SndCurveTbl *tbl;
    signed char *set;
    int curveNo;
    SndCurve *curve;
    SndCurvePt *pts;
    SndCurvePt *pt;
    short i;
    int num;

    if (x < 0) {
        *out = 0;
        return -1;
    }
    tbl = (SndCurveTbl *)D_0076DF10[user->bank].tbl;
    set = (signed char *)tbl + tbl->setOfs + user->curveSet * 4;
    if (Obj0000_Get_D_0076A7A4_3756F0() == 2) {
        curveNo = set[3];
    } else {
        curveNo = set[1];
    }
    if (curveNo < 0) {
        *out = 0;
        return 1;
    }
    curve = (SndCurve *)((char *)tbl + tbl->curveOfs2) + curveNo;
    num = curve->num;
    pts = (SndCurvePt *)((char *)tbl + curve->ptOfs);
    pt = &pts[num - 1];
    if (x >= pt->x) {
        *out = pt->y;
        return 0;
    }
    for (i = 0; i < num; i++) {
        pt = &pts[i];
        if (x == pt->x) {
            *out = pt->y;
            return 0;
        }
        if (x < pt->x) {
            *out = pt[-1].y - (int)((float)(short)(pt[-1].y - pt->y) / (float)(short)(pt->x - pt[-1].x)
                                   * (float)(x - pt[-1].x));
            return 0;
        }
    }
    *out = 0;
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00378398);
#endif

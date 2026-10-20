/* NON_MATCHING func_00359848 (cygnus-2.96, -freorder-blocks dropped; PARK 20 at attempt 4): once audio and video analysis are finished, take the stream rate/channel info from the MPS header (rate adjusted by the audio clock or scaled by 2048/2018 for old streams), the video info or the ADX info, store it in the work area and call func_00359DF0. Control flow and loads match; retail allocates rate to a1 and ch to v1 (ours swaps them) and shares one rate copy after the audio-clock branch. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int set;
    int rate;
    int ch;
} Info359848;

typedef struct {
    int on;
    char pad4[8];
    int rate;
    char pad10[0x24];
    int scale;
} Aud359848;

typedef struct {
    int done;
    int rate;
    int ch;
    Aud359848 aud;
    char pad44[0x8A0 - 0x44];
    Info359848 mps;
    char pad8AC[0xAD0 - 0x8AC];
    Info359848 vid;
    char padADC[0xD0C - 0xADC];
    Info359848 adx;
    char padD18[0xDC4 - 0xD18];
    int num;
} Work359848;

typedef struct {
    char pad0[0x36B0];
    Work359848 *work;
} Sfd359848;

extern int sfsee_IsAudioAnalyzing(Sfd359848 *sfd, Info359848 *info, int *found);
extern int sfsee_IsVideoAnalyzing(Sfd359848 *sfd, Info359848 *info, int *found);
extern int sfsee_IsMpsStream(Sfd359848 *sfd);
extern int func_0036C920(int a, int b, int c);
extern int Obj34D8_GetTri78_Times100(Sfd359848 *sfd);
extern void func_00359DF0(Sfd359848 *sfd);

void func_00359848(Sfd359848 *sfd)
{
    Work359848 *w = sfd->work;
    Aud359848 *aud = &w->aud;
    Info359848 *mps = &w->mps;
    Info359848 *vid = &w->vid;
    Info359848 *adx = &w->adx;
    int afound;
    int vfound;
    int ch;
    int rate;

    if (w->done != 0) {
        return;
    }
    if (sfsee_IsAudioAnalyzing(sfd, adx, &afound) != 0) {
        return;
    }
    if (sfsee_IsVideoAnalyzing(sfd, vid, &vfound) != 0) {
        return;
    }
    if (sfsee_IsMpsStream(sfd) != 0) {
        mps->set = 1;
        if (aud->on == 0) {
            rate = mps->rate;
        } else if (aud->rate > 0) {
            int v = aud->rate;
            if (w->num > 0 && aud->scale > 0) {
                v = func_0036C920(w->num, 1000, aud->scale);
            }
            rate = v;
        } else if (Obj34D8_GetTri78_Times100(sfd) < 108) {
            rate = (mps->rate << 11) / 2018;
        } else {
            rate = mps->rate;
        }
        ch = mps->ch;
    } else if (vfound != 0) {
        ch = vid->ch;
        rate = vid->rate;
    } else if (afound != 0) {
        ch = adx->ch;
        rate = adx->rate;
    } else {
        return;
    }
    w->rate = rate;
    w->done = 1;
    w->ch = ch;
    func_00359DF0(sfd);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00359848);
#endif

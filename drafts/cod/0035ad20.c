/* NON_MATCHING sftim_GetTimeExtClock: cygnus-2.96: retail reloads t->last after the -5 test and hoists the cnt load; prologue order differs */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SfdTimeRec {
    char unk0[0x2D4];
    int (*get)(int, int *, int *);  /* 0x2D4 */
    int last;                       /* 0x2D8 */
    int total;                      /* 0x2DC */
    int flag;                       /* 0x2E0 */
    int mod;                        /* 0x2E4 */
    int arg;                        /* 0x2E8 */
} SfdTimeRec;

extern int SFTIM_ChkRegularTime(char *sfd, int *time, int *flag);
extern int sftim_IsTimeIncre(char *sfd);

int sftim_GetTimeExtClock(char *sfd, int *time, int *flag)
{
    int cnt;
    int fl;
    int ret;
    int d;
    int f;
    int r2;
    SfdTimeRec *t;

    ret = SFTIM_ChkRegularTime(sfd, time, flag);
    t = (SfdTimeRec *)(sfd + 0xD30);
    if (ret == 0)
        return ret;
    if (t->get == 0) {
        f = 1;
        *time = -2;
        ret = 0;
    } else {
            r2 = t->get(t->arg, &cnt, &fl);
            if (sftim_IsTimeIncre(sfd) != 0) {
                if (t->last != -5) {
                    d = cnt - t->last;
                    if (d < 0)
                        d += t->mod + 1;
                    t->total += d;
                }
            }
            ret = r2;
            t->last = cnt;
            t->flag = fl;
            *time = t->total;
            f = t->flag;
    }
    *flag = f;
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatching", sftim_GetTimeExtClock);
#endif

/* NON_MATCHING func_0035AD20 (sched): cygnus dr retail reloads t->last after the -5 test and hoists the cnt load; prologue order differs */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Tim35AD20 {
    char unk0[0x2D4];
    int (*get)(int, int *, int *);  /* 0x2D4 */
    int last;                       /* 0x2D8 */
    int total;                      /* 0x2DC */
    int flag;                       /* 0x2E0 */
    int mod;                        /* 0x2E4 */
    int arg;                        /* 0x2E8 */
} Tim35AD20;

extern int func_0035AE18(char *sfd, int *time, int *flag);
extern int func_0035A768(char *sfd);

int func_0035AD20(char *sfd, int *time, int *flag)
{
    int cnt;
    int fl;
    int ret;
    int d;
    int f;
    int r2;
    Tim35AD20 *t;

    ret = func_0035AE18(sfd, time, flag);
    t = (Tim35AD20 *)(sfd + 0xD30);
    if (ret == 0)
        return ret;
    if (t->get == 0) {
        f = 1;
        *time = -2;
        ret = 0;
    } else {
            r2 = t->get(t->arg, &cnt, &fl);
            if (func_0035A768(sfd) != 0) {
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
INCLUDE_ASM("asm/nonmatching", func_0035AD20);
#endif

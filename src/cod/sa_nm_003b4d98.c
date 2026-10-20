/* NON_MATCHING func_003B4D98 (ee-2.9-991111; PARK, 46 diffs): sceIoctl-style request; retail holds the case-1 compare constant in s5 from the prologue (beql s1,s5), which shifts the s-reg assignment and the switch delay slots; if-chain and explicit locals are worse */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int fd;
    int mode;
} Iob4D98;

typedef struct {
    int sema;
    void *dst;
    int size;
    int fd;
    int cmd;
    char data[0x400];
    int f414;
    int f418;
    int len;
} Pkt4D98;

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern Iob4D98 *get_iob(int fd);
extern void func_003B3EC8(int cmd);
extern void func_003B3F50(void);
extern int SignalSema_3B3EF8(void);
extern int CreateSema(struct SemaParam *p);
extern int DeleteSema(int id);
extern int WaitSema(int id);
extern int SignalSema(int id);
extern void func_003B2850(void *p, int n);
extern int func_003B3958(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, int a, int b, int c);
extern void *memcpy(void *d, const void *s, unsigned int n);

extern int D_003FAEDC;
extern int D_003FAED8;
extern int D_003FAEEC;
extern int D_003FAE58[];
extern int *D_0077FF88;
extern Pkt4D98 D_0077FFC0;
extern char D_00460198[];
extern char D_00780C00[];
extern char D_00780C50[];
extern char D_007816C0[];

int func_003B4D98(int fd, int cmd, void *arg)
{
    struct SemaParam sp;
    int result;
    int sid;
    int flag;
    int i;
    Iob4D98 *f;
    Pkt4D98 *q = &D_0077FFC0;

    f = get_iob(fd);
    func_003B3EC8(5);
    D_0077FF88 = arg;
    if (D_003FAEDC == 0)
        func_003B3F50();
    if (f == 0 || f->mode == 0) {
        SignalSema_3B3EF8();
        return -9;
    }
    q->f414 = 0;
    q->f418 = 0;
    switch (cmd) {
    case 1:
        WaitSema(D_003FAEEC);
        for (i = 0; i < 32; i++) {
            if (D_003FAE58[i] != -1)
                break;
        }
        if (i == 32)
            *D_0077FF88 = 0;
        else
            *D_0077FF88 = 1;
        SignalSema(D_003FAEEC);
        SignalSema_3B3EF8();
        return 0;
    case 2:
        *(int *)arg = *(int *)((unsigned int)(D_00780C50 + D_003FAED8 * 0x440) | 0x20000000);
        SignalSema_3B3EF8();
        return 0;
    case 3:
        *(long *)arg = *(long *)((unsigned int)(D_00780C50 + D_003FAED8 * 0x440) | 0x20000000);
        SignalSema_3B3EF8();
        return 0;
    }
    q->fd = f->fd;
    q->cmd = cmd;
    if (arg == 0) {
        q->len = 0;
    } else {
        q->len = 0x400;
        memcpy(q->data, arg, 0x400);
    }
    sp.maxCount = 1;
    sp.initCount = 0;
    sp.option = (unsigned int)D_00460198;
    sid = CreateSema(&sp);
    q->size = 4;
    q->dst = &result;
    q->sema = sid;
    func_003B2850(&D_0077FFC0, 0x420);
    if (func_003B3958(D_007816C0, 5, 0, &D_0077FFC0, 0x420, D_00780C00, 4, 0, 0, 0) < 0) {
        DeleteSema(sid);
        SignalSema_3B3EF8();
        return -11;
    }
    flag = *(int *)((unsigned int)D_00780C00 | 0x20000000);
    SignalSema_3B3EF8();
    if (flag == 0) {
        DeleteSema(sid);
        return -11;
    }
    WaitSema(sid);
    DeleteSema(sid);
    return result;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003B4D98);
#endif

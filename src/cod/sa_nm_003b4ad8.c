/* NON_MATCHING func_003B4AD8 (ee-2.9-991111;
 * PARK, 27 diffs): sceWrite-style write; code and layout match, only the
 * s4-s7 assignment is rotated (retail: async s4, sid s5, size s6, mode s7). */
#include "include_asm.h"

#ifdef NON_MATCHING
/* ee-2.9-991111 */

typedef struct { int f0; int f4; int f8; int fC; } Iob;
typedef struct {
    int sema;
    void *dst;
    int size;
    int fd;
    unsigned int buf;
    int len;
    int head;
    unsigned char data[16];
    int unit;
} WritePkt;

struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern Iob *get_iob(int fd);
extern void func_003B2850(unsigned int, int);
extern int func_003B3958(void *, int, int, void *, int, void *, int, int, int, int);

extern int SignalSema_3B3EF8(void);
extern int CreateSema(struct SemaParam *p);
extern int DeleteSema(int id);
extern int WaitSema(int id);
extern int SignalSema(int id);

extern int D_003FAEDC;
extern int D_003FAEEC;
extern int D_003FAE58[32];
extern Iob D_007814C0[32];
extern WritePkt D_0077FFC0;
extern char D_00460180[];
extern char D_00780C00[];
extern char D_007816C0[];

__attribute__((section(".text.func_003B4AD8")))
int func_003B4AD8(int fd, unsigned int buf, int size)
{
    struct SemaParam sp;
    int result;
    Iob *p;
    int sid;
    int r;
    int mode;
    int nowait;
    int async;
    int head;
    int i;
    int j;

    WritePkt *q = &D_0077FFC0;

    p = get_iob(fd);
    func_003B3EC8(3);
    if (!D_003FAEDC || !p || !(mode = p->f4)) {
        SignalSema_3B3EF8();
        return -9;
    }
    q->fd = p->f0;
    q->unit = p - D_007814C0;
    sp.maxCount = 1;
    sp.option = (unsigned int)D_00460180;
    nowait = mode & 0x8000;
    q->len = size;
    q->buf = buf;
    sp.initCount = 0;
    sid = CreateSema(&sp);
    q->dst = &result;
    q->size = 4;
    D_0077FFC0.sema = sid;
    if (nowait) {
        WaitSema(D_003FAEEC);
        async = nowait;
        for (i = 0; i < 32; i++) {
            if (D_003FAE58[i] == -1) {
                D_003FAE58[i] = q->sema;
                q->sema = -q->sema;
                break;
            }
        }
        SignalSema(D_003FAEEC);
    } else {
        async = 0;
    }
    if (!(buf & 0xF))
        head = 0;
    else
        head = (((buf >> 4) << 4) + 16) - buf;
    if (size < head)
        head = size;
    if (!(mode & 0x20000000))
        func_003B2850(buf, size);
    buf |= 0x20000000;
    q->head = head;
    for (j = 0; j < head; j++)
        q->data[j] = *(unsigned char *)(buf + j);
    r = func_003B3958(D_007816C0, 3, 0, &D_0077FFC0, 0x30, D_00780C00, 4, 0, 0, async);
    if (r < 0) {
        DeleteSema(sid);
        SignalSema_3B3EF8();
        return -11;
    }
    r = *(int *)((unsigned int)D_00780C00 | 0x20000000);
    SignalSema_3B3EF8();
    if (r == 0) {
        DeleteSema(sid);
        return -11;
    }
    if (async) {
        DeleteSema(sid);
        return 0;
    }
    WaitSema(sid);
    DeleteSema(sid);
    return result;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003B4AD8);
#endif

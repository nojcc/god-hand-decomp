/* NON_MATCHING func_00374210: sn: retail saves an unused s0 (ret var eliminated after alloc) and schedules the size math differently */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SndStrm {
    void *handle;   /* 0x00 */
    void *buf;      /* 0x04 */
    int size;       /* 0x08 */
    int unkC;
    int nch;        /* 0x10 */
} SndStrm;

extern char D_00754210[];
extern void *func_0031C8E0(int size, int align, void *heap);
extern void func_0031C928(void *p, void *heap);
extern void *func_0032D340(int n, int nch, void *buf, int size);

int func_00374210(SndStrm *s, int rate, int sec, int n)
{
    int ret;
    int sz;

    sz = s->nch * (rate / 1000 * 25000) / 44 * (sec + 1);
    sz = (sz + 0x800) / 0x800 * 0x800;
    s->size = (sz + (s->nch * 0x40C0 + 0x24)) * n + 0x40;
    ret = 0;
    s->buf = func_0031C8E0(s->size, 0x40, D_00754210);
    if (s->buf != 0) {
        s->handle = func_0032D340(n, s->nch, s->buf, s->size);
        if (s->handle != 0) {
            ret = 1;
        } else {
            func_0031C928(s->buf, D_00754210);
            s->buf = 0;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00374210);
#endif

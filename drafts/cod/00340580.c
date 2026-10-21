/* NON_MATCHING func_00340580: cygnus-2.96: prologue param-copy order plus 3 beql (retail) vs beq with the same delay insn */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_003EC420[];
extern char D_00456F18[];
extern char D_00456F40[];
extern char D_00456F68[];
extern int func_003A50B4(void *d, const void *s, int n);
extern void func_003A52F0(void *p, int c, int n);
extern void func_00340700(void *w);
extern void func_00340450(const char *msg);

typedef struct SifWork {
    char *buf;                  /* 0x00 */
    int size;                   /* 0x04 */
    char *tab0;                 /* 0x08 */
    char *tab1;                 /* 0x0C */
    char unk10[0x1C];
} SifWork;                   /* 0x2C */

SifWork *func_00340580(char *buf, int size)
{
    SifWork *w;
    char *p;
    unsigned int r;

    func_003A50B4(D_003EC420, D_003EC420, 0x168);
    if (buf == 0) {
        func_00340450(D_00456F18);
        return 0;
    }
    if (size < 0x400) {
        func_00340450(D_00456F40);
        return 0;
    }
    {
        r = (unsigned int)buf & 3;
        p = buf;
        if (r != 0)
            p = buf - r + 4;
        w = (SifWork *)p;
        func_003A52F0(w, 0, sizeof(SifWork));
        p = (char *)w + sizeof(SifWork);
        w->buf = buf;
        w->size = size;
        r = (unsigned int)p & 3;
        if (r != 0)
            p = p - r + 4;
        w->tab0 = p;
        w->tab1 = p + 0x180;
        func_00340700(w);
        if ((unsigned int)(p + 0x300) > (unsigned int)(buf + size)) {
            func_00340450(D_00456F68);
            return 0;
        }
        return w;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00340580);
#endif

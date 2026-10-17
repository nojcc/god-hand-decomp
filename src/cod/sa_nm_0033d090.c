/* NON_MATCHING func_0033D090 (regalloc): cygnus dr: 7 diffs, v0/v1 swap in the default-code copy block only; tried short/char-array/temp forms */
#include "include_asm.h"

#ifdef NON_MATCHING
extern unsigned short D_003E9D54;
extern unsigned short D_003E9D56;
extern unsigned short D_003E9D58;
extern char D_004568F8[];
extern int func_003A6C58(char *buf, const char *fmt, ...);
extern int func_0033C548(char *s, int len, unsigned short *a, unsigned short *b, unsigned short *c);

typedef struct Key33D090 {
    char unk0[0xA0];
    union {
        struct {
            unsigned short a;   /* 0xA0 */
            unsigned short b;   /* 0xA2 */
        } s;
        int ab;
    } k;
    short c;                    /* 0xA4 */
} Key33D090;

int func_0033D090(Key33D090 *o, unsigned int kind, unsigned int ch, int name, unsigned short *a, unsigned short *b,
                  unsigned short *c)
{
    char buf[16];

    if ((kind & 0xFF) < 4)
        goto zero;
    ch &= 0xFF;
    if (ch >= 0x10) {
        func_003A6C58(buf, D_004568F8, name);
        func_0033C548(buf, 8, a, b, c);
    } else if (ch >= 8) {
            if (o->k.ab == 0 && o->c == 0) {
                o->k.s.a = D_003E9D54;
                o->k.s.b = D_003E9D56;
                o->c = (short)D_003E9D58;
            }
            *a = o->k.s.a;
            *b = o->k.s.b;
            *c = o->c;
    } else {
zero:
        *a = 0;
        *b = 0;
        *c = 0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033D090);
#endif

/* NON_MATCHING func_001034E0 (sn-2.95.3-136;
 * PARK, 141 diffs): 150 vs 159 words; retail keeps
 * every branch body separate (no cross-jump of the d/b stores or the 5.0f loads) and lays
 * the 0x621..0x623 tests out as fallthrough chains.
 * The 0x2F4/0x2F5 pair test is a 64-bit
 * masked ld compare (MREQ_AB), which this reproduces. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct MotReq {
    int pad;
    unsigned char a;            /* 0x2F4 */
    unsigned char b;            /* 0x2F5 */
    unsigned char c;            /* 0x2F6 */
    unsigned char d;            /* 0x2F7 */
} MotReq;

#define MREQ_AB(o) (*(unsigned long *)&(o)->m & 0xFFFF00000000UL)

typedef struct Obj {
    char pad000[0x2F0];
    MotReq m;                   /* 0x2F0 */
    char pad2F8[0x54C - 0x2F8];
    float f54C;                 /* 0x54C */
} Obj;

extern char D_007474A0[];
extern char *Getplayer(void);

#define GW_FLAGS8   (*(int *)(D_007474A0 + 8))
#define GW_FLAGS5D8 (*(int *)(D_007474A0 + 0x5D8))

__attribute__((section(".text.func_001034E0")))
int func_001034E0(Obj *self)
{
    char *pl = Getplayer();

    if (!(GW_FLAGS5D8 & 0x2000000)) {
        if (*(signed char *)(pl + 0x621)) {
            self->m.d = 0;
            self->m.b = 5;
            self->m.a = 0;
            self->m.c = 0;
            return 1;
        }
        if (*(signed char *)(pl + 0x622)) {
            self->m.d = 1;
            self->m.b = 5;
            self->m.a = 0;
            self->m.c = 0;
            return 1;
        }
        if (*(signed char *)(pl + 0x623)) {
            self->m.d = 2;
            self->m.b = 5;
            self->m.a = 0;
            self->m.c = 0;
            return 1;
        }
        if (*(unsigned char *)(pl + 0x61E)) {
            float ang = *(float *)(pl + 0x614);
            if (ang < 0.7853982f) {
                self->m.b = 4;
                self->f54C = 5.0f;
                self->m.d = 0;
            } else if (2.3561945f < ang) {
                self->m.b = 4;
                self->m.d = 1;
                self->f54C = 5.0f;
            } else if (0.0f < *(float *)(pl + 0x610)) {
                self->m.b = 4;
                self->m.d = 2;
                self->f54C = 5.0f;
            } else {
                self->m.b = 4;
                self->m.d = 3;
                self->f54C = 5.0f;
            }
            self->m.a = 0;
            self->m.c = 0;
            return 1;
        }
        if (GW_FLAGS8 & 4) {
            if (MREQ_AB(self) == 0x30000000000UL)
                return 0;
            self->m.d = 0;
            self->m.b = 3;
            self->m.a = 0;
            self->m.c = 0;
            return 1;
        }
        if (*(unsigned char *)(pl + 0x61F)) {
            float ang = *(float *)(pl + 0x608);
            if (ang < 1.2217305f) {
                if (MREQ_AB(self) == 0x10000000000UL)
                    return 0;
                self->m.d = 0;
                self->m.b = 1;
                self->m.a = 0;
                self->m.c = 0;
                return 1;
            }
            if (2.0943952f < ang) {
                if (MREQ_AB(self) == 0x20000000000UL)
                    return 0;
                self->m.d = 0;
                self->m.b = 2;
                self->m.a = 0;
                self->m.c = 0;
                return 1;
            }
        }
    }
    if (MREQ_AB(self) == 0x0UL)
        return 0;
    self->m.d = 0;
    self->m.a = 0;
    self->m.b = 0;
    self->m.c = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001034E0);
#endif

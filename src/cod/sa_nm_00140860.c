/* NON_MATCHING func_00140860 (sn-2.95.3-136;
 * PARK, 134 diffs): drop dead/flagged enemies from the 5-slot list and
 * compact the parallel arrays.
 * Retail keeps the 0x200..0x2FF type test as two branches (no bool), reuses obj for the
 * dead check but re-reads it in the flag arm, and duplicates the D_00747A84 test per arm. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x2FE];
    short type;
    char pad300[0x5B0 - 0x300];
    unsigned int f5B0;
} Em140;

typedef struct {
    char b[16];
} Rec140;

typedef struct {
    char pad0[0xA8];
    int f[5];
    char padBC[4];
    char anim[5][0x50];
    Em140 *obj[5];
    char pad264[0x270 - 0x264];
    float v[5][4];
    float a[5];
    float b[5];
    float c[5];
    unsigned short d[5];
    char pad306[2];
    Rec140 rec[5];
    unsigned char n;
    char pad359[0x370 - 0x359];
    int e[5];
} Mgr140;

extern int D_00747A84;
extern int cEmBase_checkDeadFlag(Em140 *o);
extern void cIDBase_resetAnim(void *a);
extern void func_00140718(Mgr140 *self, int a, int b);

static __inline__ void cpy3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

static __inline__ int isEmType(Em140 *o)
{
    if (o->type < 0x200)
        return 0;
    if (o->type >= 0x300)
        return 0;
    return 1;
}

static __inline__ int isGone(Mgr140 *self, int i)
{
    long t;

    if (isEmType(self->obj[i])) {
        if (cEmBase_checkDeadFlag(self->obj[i]))
            return 1;
    } else {
        t = self->obj[i]->f5B0;
        if (((t >> 1) & 1) == 1)
            return 1;
    }
    if (D_00747A84 & 0x20000000)
        return 1;
    return 0;
}

__attribute__((section(".text.func_00140860")))
void func_00140860(Mgr140 *self)
{
    unsigned short i;
    unsigned short j;

    for (i = 0; i < self->n; i++) {
        if (isGone(self, i) == 1) {
            cIDBase_resetAnim(self->anim[i]);
            self->obj[i] = 0;
            self->a[i] = 1.0f;
            self->b[i] = 1.0f;
            self->c[i] = 1.0f;
            self->d[i] = 0;
            self->e[i] = 0;
            self->f[i] = 0;
            for (j = i; j < self->n; j++) {
                if (j == self->n - 1) {
                    func_00140718(self, 0, 1);
                } else {
                    self->obj[j] = self->obj[j + 1];
                    self->a[j] = self->a[j + 1];
                    self->b[j] = self->b[j + 1];
                    self->c[j] = self->c[j + 1];
                    self->d[j] = self->d[j + 1];
                    self->e[j] = self->e[j + 1];
                    self->rec[j] = self->rec[j + 1];
                    self->f[j] = self->f[j + 1];
                    cpy3(self->v[j], self->v[j + 1]);
                }
            }
            self->n--;
            i--;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00140860);
#endif

/* sn-2.95.3-136: func_001C0450, re-register the object's collision / lock-on entry with D_00569B70 when its state
 * word, its state bits or its position quaternion changed since the last call (or, when only bit 1 of the state bits
 * is set, when the secondary vector changed), then latch the current state. */
typedef struct VtEnt {
    short delta;
    short pad;
    int (*fn)();
} VtEnt;

extern char D_00569B70[];
extern void func_001FB1C0(void *a0, int a1, int a2, int a3, int a4, void *a5);

#include "godhand/vecInline.h"

static inline void regist(char *p)
{
    func_001FB1C0(D_00569B70, *(unsigned short *)(p + 0x662),
                  (*(VtEnt **)(p + 0x214))[16].fn(p + (*(VtEnt **)(p + 0x214))[16].delta),
                  (*(VtEnt **)(p + 0x214))[17].fn(p + (*(VtEnt **)(p + 0x214))[17].delta),
                  *(int *)(p + 0x560), p + 0x676);
}

__attribute__((section(".text.func_001C0450")))
void func_001C0450(char *p)
{
    long tmp;
    long t2;

    tmp = *(unsigned int *)(p + 0x5B0);
    tmp = tmp >> 5;
    tmp = tmp & 1;
    if (tmp == 1)
        return;
    if (*(int *)(p + 0x560) != *(int *)(p + 0x67C)
        || *(unsigned char *)(p + 0x676) != *(unsigned char *)(p + 0x677)
        || vec4_ne((float *)(p + 0x490), *(float **)(p + 0xF0))) {
        regist(p);
    } else {
        t2 = *(unsigned char *)(p + 0x676);
        t2 = t2 >> 1;
        t2 = t2 & 1;
        if (t2 == 1) {
            if (vec4_ne((float *)(p + 0x5D0), (float *)(p + 0x100)))
                regist(p);
        }
    }
    *(int *)(p + 0x67C) = *(int *)(p + 0x560);
    *(unsigned char *)(p + 0x677) = *(unsigned char *)(p + 0x676);
}

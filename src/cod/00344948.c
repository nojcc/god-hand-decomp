/* NON_MATCHING func_00344948 (cygnus-2.96): values and call order are right.
* Retail copies prm[0..3] into the stack info block, and the info block into the work area, one word at a time through v0, as if every load and store could alias; ours batches the loads (struct copies give ldl/sdl instead). t (prm+0x20) and c (prm+0x2C) also swap s7/fp. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_00344948: MWSFSVM setup: build a stream-info block from the create parameters, check it,
 * convert the two time bases and fill the handle's work area from it. */
typedef struct {
    int rate;                           /* 0x00 */
    int f4;                             /* 0x04 */
    int f8[4];                          /* 0x08 */
    int f18;                            /* 0x18 */
    int f1C;                            /* 0x1C */
    int f20;                            /* 0x20 */
} SvmInfo;

typedef struct {
    long w[7];
} SvmTail;

extern char D_00457870[];
extern int func_00344BF0(int a0);
extern int func_00344C30(int a0);
extern int func_0035B5F8(int a0, SvmInfo *info);
extern void MWSFSVM_Error(char *msg);
extern int Forward36C920_344BC0(int a0, int a1, int a2);
extern void func_00344B28(char *svm, char *prm, char *work);
extern void func_00344D98(char *svm, char *prm, char *work);
extern int func_00344C98(char *svm, char *prm, int a2, int a3);

__attribute__((section(".text.func_00344948")))
void func_00344948(char *svm, char *prm, char *work)
{
    SvmInfo info;
    int h;
    int unit;
    int t0;
    int t1;
    int a;
    int b;
    int c;
    int t;

    h = *(int *)(svm + 0x3C);
    t = *(int *)(prm + 0x20);
    info.f4 = func_00344BF0(*(int *)(prm + 0x1C));
    info.f8[0] = *(int *)(prm + 0x0);
    info.f8[1] = *(int *)(prm + 0x4);
    info.f8[2] = *(int *)(prm + 0x8);
    info.f8[3] = *(int *)(prm + 0xC);
    info.f18 = func_00344C30(*(int *)(prm + 0x10));
    unit = *(int *)(prm + 0x18);
    a = *(int *)(prm + 0x34);
    b = *(int *)(prm + 0x30);
    c = *(int *)(prm + 0x2C);
    info.f1C = *(int *)(prm + 0x24);
    info.f20 = *(int *)(prm + 0x28);
    if (func_0035B5F8(h, &info) != 0)
        MWSFSVM_Error(D_00457870);
    t0 = Forward36C920_344BC0(a, info.rate, unit);
    t1 = Forward36C920_344BC0(b, info.rate, unit);
    *(int *)(work + 0x0) = t;
    *(int *)(work + 0x34) = t1;
    *(int *)(work + 0x8) = info.f4;
    *(int *)(work + 0xC) = info.f8[0];
    *(int *)(work + 0x10) = info.f8[1];
    *(int *)(work + 0x14) = info.f8[2];
    *(int *)(work + 0x18) = info.f8[3];
    *(int *)(work + 0x20) = info.rate;
    *(int *)(work + 0x24) = t0;
    *(int *)(work + 0x28) = a;
    *(int *)(work + 0x2C) = unit;
    *(int *)(work + 0x30) = c;
    *(int *)(work + 0x38) = b;
    *(int *)(work + 0x1C) = info.f18;
    *(int *)(work + 0x3C) = info.f1C;
    *(int *)(work + 0x40) = info.f20;
    func_00344B28(svm, prm, work);
    func_00344D98(svm, prm, work);
    *(int *)(work + 0x4C) = func_00344C98(svm, prm, *(int *)(work + 0x88), *(int *)(work + 0x8C));
    *(SvmTail *)(work + 0x50) = *(SvmTail *)(prm + 0x48);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00344948);
#endif

/* NON_MATCHING func_00140E58 (sn-2.95.3-136): retail tests the 0x40000 pause bit as lui/and/sltu and keeps the bool in v0 for a second test, ours folds it to sra/andi; retail also passes p + 0x1DC0 through v0 before s3 in the update path.
* The if/return bool helpers and the SetA/SetB setters already line up the flag-set tail; stage object per-frame update */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int D_00747A2C[];
extern unsigned int D_00747A24;
extern int D_003C2FB0;
extern void NoOp_1415E0(void);
extern void func_0013C950(void *a0);
extern void func_0013F5D0(void *a0);
extern void func_0013E970(void *a0);
extern void func_001471F0(void *a0);
extern void UpdateLinkedFieldsAndMove_13F1C0(void *a0);
extern void Gp_drawGreyScreenQuad(int a0, int a1, int a2);

typedef struct {
    short delta;
    short pad;
    void (*fn)(void *);
} StageVtEnt;

static inline unsigned char Paused140E58(void)
{
    return (D_00747A2C[0x13] & 0x40000) != 0;
}

static inline unsigned char TestA140E58(char *p, char *sub)
{
    if (*(int *)(sub + 0x9C) != 0 && (*(unsigned int *)(p + 0x1E60) & 0x20000000) != 0)
        return 1;
    return 0;
}

static inline unsigned char TestB140E58(char *p)
{
    if (*(unsigned char *)(p + 0x21E8) != 0 && *(int *)(p + 0x1F20) < 0)
        return 1;
    return 0;
}

static inline unsigned char TestC140E58(char *p)
{
    if (*(int *)(p + 0x22BC) != 0 && (*(unsigned int *)(p + 0x22C0) & 0x20000000) != 0)
        return 1;
    return 0;
}

static inline void SetA140E58(char *o, int m)
{
    *(unsigned char *)(o + 0x1C0) |= m;
}

static inline void SetB140E58(char *o, int m)
{
    *(unsigned char *)(o + 0x104) |= m;
}

__attribute__((section(".text.func_00140E58")))
void func_00140E58(char *p)
{
    int paused;
    int i;
    char *sub;

    if (D_00747A2C[0] < 0)
        return;
    paused = Paused140E58();
    sub = p + 0x1DC0;
    if (!paused) {
        if (!(D_00747A2C[0x16] & 0x4000))
            NoOp_1415E0(p);
        func_0013C950(sub);
        func_0013F5D0(p + 0x1E90);
        func_0013E970(p + 0x2220);
        func_001471F0(p + 0x1A20);
        {
            int q;
            int end = (int)(p + 0x23C0);
            for (q = (int)(p + 0x22F4); q < end; q += 0xC) {
                char *e = *(char **)q;
                if (e != 0 && *(unsigned char *)(e + 0x77) == 0) {
                    StageVtEnt *v = (StageVtEnt *)(*(char **)(e + 0x80) + 0x20);
                    v->fn(e + v->delta);
                }
            }
        }
    }
    else if (paused)
        UpdateLinkedFieldsAndMove_13F1C0(p + 0x1520);
    if (TestA140E58(p, sub) || TestB140E58(p) || TestC140E58(p))
        SetA140E58(p + 0x1AE0, 2);
    if (TestA140E58(p, sub) || TestB140E58(p))
        SetB140E58(p + 0x1CB0, 1);
    else if (TestC140E58(p))
        SetB140E58(p + 0x1CB0, 2);
    if (D_00747A24 & 0x20000)
        Gp_drawGreyScreenQuad(D_003C2FB0, 6, 5);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00140E58);
#endif

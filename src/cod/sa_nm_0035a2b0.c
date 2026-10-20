/* NON_MATCHING func_0035A2B0 (cygnus-2.96 --drop-reorder;
 * PARK, 46 diffs): matches through both table-clear loops (the
 * second table is addressed from sub = t + 0xC set before the first loop); the final block of constant stores is
 * scheduled differently and retail reloads 0x2A8 for the 0x2D0 copy.
 * Sofdec timer init: six time callbacks,
 * sub-timer resets, two 32-entry tables cleared, default timing parameters. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_0035B0D8(void *obj, void *fn, int n);
extern void sftim_GetTimeNone(void);
extern void func_0035ACA0(void);
extern void func_0035AD00(void);
extern void func_0035AD20(void);
extern void func_0035A518(void *p);
extern void func_0035A4D0(void *p, int v);

__attribute__((section(".text.func_0035A2B0")))
void func_0035A2B0(void *obj, char *t)
{
    int i;
    char *sub;

    func_0035B0D8(obj, sftim_GetTimeNone, 0);
    func_0035B0D8(obj, func_0035ACA0, 1);
    func_0035B0D8(obj, 0, 2);
    func_0035B0D8(obj, func_0035AD00, 3);
    func_0035B0D8(obj, 0, 4);
    func_0035B0D8(obj, func_0035AD20, 5);
    *(int *)(t + 0x18) = 0;
    func_0035A518(t + 0x1C);
    func_0035A4D0(t + 0xC0, 0);
    func_0035A4D0(t + 0x3C, 0x7FFFFFFF);
    func_0035A4D0(t + 0x68, -1);
    func_0035A4D0(t + 0x94, -1);
    func_0035A4D0(t + 0xEC, -1);
    func_0035A4D0(t + 0x118, 0x7FFFFFFF);
    *(int *)(t + 0x144) = 0;
    *(int *)(t + 0x148) = 0;
    *(long *)(t + 0x150) = -1;
    *(long *)(t + 0x158) = -1;
    *(int *)(t + 0x160) = 0;
    *(int *)(t + 0x164) = 0;
    *(int *)(t + 0x168) = 0;
    sub = t + 0xC;
    for (i = 31; i >= 0; i--)
        ((int *)(t + 0x16C))[i] = 0;
    *(int *)(t + 0x1EC) = 1;
    *(int *)(t + 0x1F0) = 0;
    *(int *)(t + 0x1F4) = 0;
    *(int *)(t + 0x1F8) = 0;
    for (i = 31; i >= 0; i--)
        ((int *)(sub + 0x1F0))[i] = 0;
    *(int *)(t + 0x27C) = -5;
    *(int *)(t + 0x280) = 1;
    *(int *)(t + 0x284) = -5;
    *(int *)(t + 0x288) = 1;
    *(int *)(t + 0x28C) = -1;
    *(int *)(t + 0x290) = 1;
    *(int *)(t + 0x294) = -5;
    *(int *)(t + 0x298) = 0x7FFFFFFF;
    *(int *)(t + 0x29C) = 0;
    *(int *)(t + 0x2A0) = 0x7FFFFFFF;
    *(int *)(t + 0x2A4) = 0;
    *(int *)(t + 0x2A8) = 0;
    *(int *)(t + 0x2AC) = 1000;
    *(int *)(t + 0x2B0) = 0;
    *(int *)(t + 0x2B4) = 0;
    *(int *)(t + 0x2B8) = 1;
    *(int *)(t + 0x2BC) = 100;
    *(float *)(t + 0x2C0) = -1.0f;
    *(int *)(t + 0x2C4) = 0;
    *(float *)(t + 0x2C8) = -1.0f;
    *(int *)(t + 0x2CC) = -1;
    *(int *)(t + 0x2D0) = *(int *)(t + 0x2A8);
    *(int *)(t + 0x2D4) = 0;
    *(int *)(t + 0x2D8) = -5;
    *(int *)(t + 0x2DC) = 0;
    *(int *)(t + 0x2E0) = 1;
    *(int *)(t + 0x2E4) = -1;
    *(int *)(t + 0x2E8) = 0;
    *(int *)(t + 0x5B0) = 0;
    *(int *)(t + 0x5B4) = 0;
    *(int *)(t + 0x5B8) = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0035A2B0);
#endif

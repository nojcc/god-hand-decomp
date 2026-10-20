/* NON_MATCHING classCFILTER_TAG_Filter_main (sn-2.95.3-136;
 * PARK, 182 diffs): retail keeps the 0xE00 width constant in s2 across all calls (4 s-regs, 0x50 frame); ours rematerializes it at the use, so the frame is 0x40 and every slot shifts */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_00747A80[];
extern int D_00747A24;
extern int D_003C1180;
extern int D_003C118C;
extern void func_002998D8(char *p, int a, int b);
extern void PushEntryAtField10000_299868(char *p, int reg, long val);
extern void func_00299DE0(char *p);
extern void func_0029F7D8(char *p);
extern void func_0029AC10(char *p);
extern void func_0029BAB8(char *p);
extern void func_0029CE70(char *p);
extern void func_0029DA70(char *p);
extern void func_0029E8E0(char *p);
extern void func_002A39A8(char *p);
extern void func_0029E2C0(char *p);
extern void func_002A0C60(char *p);
extern void func_002A10E8(char *p);
extern void func_002A1640(char *p);
extern void func_002A1BF8(char *p);
extern void func_00299908(char *p);
extern void GifPacket_closeAndQueue(char *p);

#define FLT_F(p) (*(unsigned long *)((p) + 0x140C8))
#define FLT_G(p) (*(unsigned long *)((p) + 0x14098))

void classCFILTER_TAG_Filter_main(char *p)
{
    char *g;
    unsigned int sz;
    unsigned long f;
    long t;
    char *a;

    a = D_00747A80;
    if (*(int *)a & 0x4000000)
        return;
    g = a - 0x5E0;
    func_002998D8(p, 0, 14);
    sz = 0xE00;
    PushEntryAtField10000_299868(p, 0x3B, 0x8000000000L);
    f = FLT_F(p);
    if (!(f & 0x1000) && ((f & 0x80) || (FLT_G(p) & 2) || (f & 0x4018)))
        func_00299DE0(p);
    if (FLT_F(p) & 0x100)
        func_0029F7D8(p);
    if (FLT_F(p) & 2)
        func_0029AC10(p);
    if (FLT_F(p) & 0x20)
        func_0029BAB8(p);
    if ((FLT_F(p) & 0x1040) == 0x40)
        func_0029CE70(p);
    if ((FLT_F(p) & 0x1080) == 0x80)
        func_0029DA70(p);
    if ((FLT_F(p) & 0x1008) == 8)
        func_0029E8E0(p);
    if ((FLT_F(p) & 0x5000) == 0x4000)
        func_002A39A8(p);
    if ((FLT_F(p) & 0x1010) == 0x10)
        func_0029E2C0(p);
    if (FLT_G(p) & 1)
        func_002A0C60(p);
    if (FLT_G(p) & 2)
        func_002A10E8(p);
    t = D_00747A24;
    if ((FLT_G(p) & 4) || (((unsigned long)t >> 5) & 1))
        func_002A1640(p);
    f = FLT_F(p);
    if ((f & 0x400) || (D_00747A24 & 0x20000) || (f & 0x1000)) {
        func_002A1BF8(p);
    } else {
        *(short *)(p + 0x19ADA) = 0;
        *(char *)(p + 0x19AD8) = 0;
    }
    func_00299908(p);
    func_002998D8(p, 1, 14);
    PushEntryAtField10000_299868(p, 0x3F, 0xFF);
    PushEntryAtField10000_299868(p, 0x19, *(long *)(g + 0x490));
    PushEntryAtField10000_299868(p, 0x4F, 0xA0000F8);
    PushEntryAtField10000_299868(p, 0x48, 0x50000);
    PushEntryAtField10000_299868(p, 0x41, ((long)(D_003C1180 - 1) << 16) | ((long)(D_003C118C - 1) << 48));
    PushEntryAtField10000_299868(p, 0x4D, (sz >> 5) | ((long)(D_003C1180 / 64) << 16));
    func_00299908(p);
    GifPacket_closeAndQueue(p);
}
#else
INCLUDE_ASM("asm/nonmatching", classCFILTER_TAG_Filter_main);
#endif

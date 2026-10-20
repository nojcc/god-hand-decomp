/* NON_MATCHING func_002A6DA8 (sn-2.95.3-136; PARK, 10 diffs): retail schedules the sd of attr+0x30 after the poly4 arg setup and loads %hi(D_003C1190) before %hi(D_003C1184); the vertex store order is solved (the scheduler emits each float's last store first, then the rest in source order); pause-screen wait loop */
#include "include_asm.h"

#ifdef NON_MATCHING
extern unsigned int D_00747A24[];
extern unsigned char D_007474A0[];
extern unsigned char D_005CAC90;
extern char *D_003BD6E8;
extern int D_00752C00[];
extern int D_00747A80;
extern float D_003C1184;
extern float D_003C1190;
extern void cCockMess_SetMessNo(void *a0, int a1, int a2, float f12, float f13);
extern void func_00140E58(void *a0);
extern void func_001410A8(void *a0);
extern void *func_003A52F0(void *a0, int a1, int a2);
extern void Gp_draw_poly4(float *v, unsigned int col, int a2, void *attr, int a4, int a5);
extern void cTaskWork_sleep(int task, int n);

static inline unsigned char *game(void)
{
    return D_007474A0;
}

static inline int *task(void)
{
    return D_00752C00;
}

__attribute__((section(".text.func_002A6DA8")))
void func_002A6DA8(void)
{
    float v[16];
    unsigned char attr[0x48];
    unsigned int *gw = D_00747A24;
    unsigned char *g;
    unsigned long t;
    unsigned int f;
    int saved;
    float w;
    float h;
    float z;
    float far;
    float one;

    t = gw[0];
    t = t >> 3;
    t = t & 1;
    if (t)
        return;
    f = gw[0x18];
    if (f & 0x8000000)
        return;
    if (f & 0x20000000)
        return;
    if (f & 0x40000000)
        return;
    if (f & 0x2000000)
        return;
    if (gw[0x19] & 0x40000000)
        return;
    g = (unsigned char *)gw - 0x584;
    if (*(unsigned short *)(g + 0x5B0) == 0x20)
        return;
    if (D_005CAC90 != 4)
        return;
    if (g[0x14] != 0)
        return;
    saved = *(int *)(g + 0x5E0);
    cCockMess_SetMessNo(D_003BD6E8 + 0x1520, 0x3007, 0, 256.0f, 220.0f);
    *(int *)(g + 0x5E0) |= 0x2000000;
    *(int *)(g + 0x5E0) |= 0x20000;
    while (*(int *)(game() + 0x56C) == 0 ? !(*(int *)(game() + 8) & 0x20) : !(*(int *)(game() + 8) & 0x40)) {
        func_00140E58(D_003BD6E8);
        func_001410A8(D_003BD6E8);
        *(int *)attr = 0;
        func_003A52F0(attr, 0, 0x48);
        *(int *)attr |= 0x20;
        *(long *)(attr + 0x30) = 0x30000;
        w = D_003C1184;
        h = D_003C1190;
        z = 0.0f;
        far = 65535.0f;
        one = 1.0f;
        v[4] = z;
        v[0] = z;
        v[9] = z;
        v[12] = w;
        v[13] = h;
        v[14] = far;
        v[10] = far;
        v[6] = far;
        v[15] = one;
        v[11] = one;
        v[7] = one;
        v[1] = z;
        v[8] = w;
        v[5] = h;
        v[2] = far;
        v[3] = one;
        Gp_draw_poly4(v, 0x80000000, 1, attr, 6, 5);
        cTaskWork_sleep(task()[1], 1);
    }
    D_00747A80 = saved;
    *(int *)(D_003BD6E8 + 0x15BC) = 0xFFFF;
    cTaskWork_sleep(task()[1], 1);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002A6DA8);
#endif

/* NON_MATCHING func_00291D48 (sn-2.95.3-136;
 * PARK, 147 diffs): retail assembler short-loop-padded the
 * multi-block list-scan loop (nop after lw 8(a0)); ee-as/call-loop-pad do not pad multi-block
 * loops, shifting everything by one word.
 * Frame/regalloc otherwise right (wlSet inline breaks
 * the cross-call const-1 CSE);
 * WL store order inside wlSet still unverified. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_007474A0[];
extern char *D_00569B70;
struct WL { int pad; unsigned char on; char p5[3]; int t8; int tC; };
extern struct WL D_00754C38;
extern char D_00604700[];
extern unsigned int D_00747A84;
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void KillEffect(void *a0, int a1, int a2);
extern void cWorldLight_loadPreset(void *wl, int on);
extern void cWorldLight_startFade(void *wl, int a1, int frames);
extern void cWorldLight_Light_curent_set(void *wl, int a1);

static inline void wlSet(int on, int t)
{
    D_00754C38.on = on;
    D_00754C38.tC = t;
    D_00754C38.t8 = t;
}

static inline char *game(void)
{
    return D_007474A0;
}

__attribute__((section(".text.func_00291D48")))
void func_00291D48(char *self)
{
    char *n;
    int found = 0;
    int v;
    int stage;

    for (n = *(char **)(self + 0x500); n != 0; n = *(char **)(n + 4)) {
        char *o = *(char **)(n + 8);
        int id;
        if (o == 0)
            continue;
        id = *(int *)(o + 0x564);
        if ((unsigned int)(id - 0x220) < 4 || id == 0x209 || id == 0x260 || id == 0x263 || id == 0x266) {
            found = 1;
            break;
        }
    }
    stage = *(unsigned short *)(game() + 0x5B0);
    switch (stage) {
    case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45:
    case 0x4C: case 0x4D: case 0x4E: case 0x4F:
        found = 0;
        break;
    }
    v = *(int *)(D_00569B70 + 0x14);
    if (v < 0) {
        if (*(unsigned char *)(self + 0x518) == 0) {
            SetEffect(0, 9, 0, 0, 1, 0xFFFFFFFF);
            wlSet(1, 0);
            cWorldLight_loadPreset(D_00604700, 1);
            *(unsigned char *)(self + 0x518) = 1;
        }
    } else if (v & 0x40000000) {
        if (*(unsigned char *)(self + 0x518)) {
            SetEffect(0, 10, 0, 0, -1, 0xFFFFFFFF);
            D_00754C38.tC = 0;
            D_00754C38.on = 0;
            D_00754C38.t8 = 0;
            cWorldLight_loadPreset(D_00604700, 0);
            *(unsigned char *)(self + 0x518) = 0;
        }
    } else if (D_00747A84 & 0x20000000) {
        *(unsigned char *)(self + 0x518) = 0;
    } else if (*(unsigned char *)(self + 0x518)) {
        if (found == 0) {
            *(unsigned char *)(self + 0x518) = 0;
            KillEffect(0, 1, 2);
            SetEffect(0, 10, 0, 0, -1, 0xFFFFFFFF);
            D_00754C38.tC = 60;
            D_00754C38.on = 0;
            D_00754C38.t8 = 60;
            cWorldLight_startFade(D_00604700, 0, 60);
        }
    } else if (found) {
        *(unsigned char *)(self + 0x518) = 1;
        SetEffect(0, 9, 0, 0, 1, 0xFFFFFFFF);
        wlSet(1, 0);
        cWorldLight_Light_curent_set(D_00604700, 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00291D48);
#endif

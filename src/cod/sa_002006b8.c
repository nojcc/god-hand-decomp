/* sn-2.95.3-136: per-frame check of a saved camera/position point: unless the game is paused or the point
 * is locked, the first pass saves the current point, sets the BGM state, opens the sub screen and releases
 * the scenario; then the point is reloaded from the stage start table or restored from the save. */
#include "godhand/vec.h"
typedef struct SavePoint {
    float x;                            /* 0x00 */
    float y;                            /* 0x04 */
    float z;                            /* 0x08 */
    float w;                            /* 0x0C */
    unsigned short kind;                /* 0x10 */
    unsigned char f12;                  /* 0x12 */
    unsigned char lock;                 /* 0x13 */
    int f14;                            /* 0x14 */
} SavePoint;

typedef struct SavePointWork {
    char unk00[4];
    SavePoint cur;                       /* 0x04 */
    SavePoint save;                      /* 0x1C */
    char unk34[5];
    signed char step;                   /* 0x39 */
    unsigned char busy;                 /* 0x3A */
} SavePointWork;

extern int D_00747A2C[];
extern int D_00747A24;
extern unsigned int D_00747A84;
extern char *D_003BD930;
extern int D_003C2F84;
extern char D_005FEE00[];
extern Vec4f D_00583F00[];
extern float D_003BF198[];
extern void cSnd_SetBgmState(void *snd, int state);
extern void cSubScr_SubScrOn(void *scr, int a, int b, int c);
extern void cScenario_release(int scn);

__attribute__((section(".text.func_002006B8")))
int func_002006B8(SavePointWork *self)
{
    unsigned long t;
    unsigned short v;
    char *w;
    int idx;
    Vec4f *sp;

    t = (unsigned int)D_00747A2C[3];
    if (((t >> 6) & 1) == 1)
        return 1;
    if (self->busy != 0)
        return 1;
    if (self->cur.kind == 0xFFFF)
        return 1;
    if (self->cur.lock == 1)
        return 1;
    switch (self->step) {
    case 0:
        t = D_00747A2C[-2];
        if (((t >> 6) & 1) != 1) {
            v = *(unsigned short *)((char *)D_00747A2C + 0x24);
            if (v != 0 && v != 0x20)
                self->save = self->cur;
        }
        cSnd_SetBgmState(D_005FEE00, 0);
        cSubScr_SubScrOn(D_003BD930, 3, 2, 0x11);
        cScenario_release(D_003C2F84);
        self->step++;
    case 1:
        if (D_00747A84 & 0x8000000)
            return 0;
    }
    w = D_003BD930 + 0x730;
    idx = *(unsigned short *)(w + 0x136);
    if (*(unsigned short *)(w + 0x134) == 0) {
        sp = &D_00583F00[idx];
        self->cur.x = sp->x;
        self->cur.y = sp->y;
        self->cur.z = sp->z;
        self->cur.w = D_003BF198[idx];
        self->cur.f12 = 0xFF;
        self->cur.kind = 0;
    } else {
        t = D_00747A24;
        if (((t >> 6) & 1) == 1)
            return 1;
        if (*(unsigned short *)((char *)&D_00747A24 + 0x2C) != 0)
            return 1;
        if (self->cur.kind != 0x100)
            return 1;
        self->cur = self->save;
    }
    return 1;
}

#include "godhand/classFADE.h"
#include "godhand/cScenario.h"

#define EVENT_FADE_TIME  15

typedef struct EvVtEntry28E858 {
    short delta;                        /* 0x00 */
    short pad;
    void (*fn)(void *self, int arg);    /* 0x04 */
} EvVtEntry28E858;

typedef struct EvVt28E858 {
    char unk00[0x60];
    EvVtEntry28E858 reset;              /* 0x60 */
} EvVt28E858;

typedef struct EvObj28E858 {
    char unk000[0x214];
    EvVt28E858 *vt;                     /* 0x214 */
} EvObj28E858;

typedef struct Vec4_28E858 {
    float x, y, z, w;
} Vec4_28E858;

extern unsigned char D_005FEE00[];
extern char *D_003C23A4;

extern EvObj28E858 *Getplayer(void);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int cSnd_SeFadeOut(void *a0, int a1, short a2);
extern void cTaskWork_sleep(struct cTaskWork *task, int frames);
extern void cTaskWork_exit(struct cTaskWork *task);
extern void func_002C45A8(cScenario *self, int no, Vec4_28E858 *pos, float arg);

__attribute__((section(".text.func_0028E858")))
void func_0028E858(EvObj28E858 *self)
{
    EvObj28E858 *pl;
    int se;
    Vec4_28E858 v;

    self->vt->reset.fn((char *)self + self->vt->reset.delta, 0);
    pl = Getplayer();
    pl->vt->reset.fn((char *)pl + pl->vt->reset.delta, 0);
    se = cSnd_SeCall_2CBA48(D_005FEE00, 1, 0, self, 0, 0, 0, 0);
    cScenario_execUpCut(D_003C2F84, 0x3004, 0, 0, 0, 1);
    cSnd_SeFadeOut(D_005FEE00, se, EVENT_FADE_TIME);
    if (*(short *)(D_003C23A4 + 0xBEC) == 0) {
        classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, EVENT_FADE_TIME);
        cTaskWork_sleep(D_003C2F84->task.cur, EVENT_FADE_TIME);
        cScenario__endSoftEvent(D_003C2F84);
        v.x = 2.0f;
        v.y = 1.61f;
        v.z = 0.0f;
        v.w = 1.0f;
        /* the heading is passed as an int */
        func_002C45A8(D_003C2F84, 0x43, &v, (int)v.z);
    } else {
        cScenario__endSoftEvent(D_003C2F84);
    }
    cTaskWork_exit(D_003C2F84->task.cur);
}

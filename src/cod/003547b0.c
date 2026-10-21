/* cygnus-2.96: MWSFD handle init: copy the default parameter blocks and reset
 * the work fields and the 16 decode slots. */
#include "godhand/sftim.h"
typedef struct Def24 { int w[9]; } Def24;
typedef struct Def8 { int w[2]; } Def8;
typedef struct Def40 { int w[16]; } Def40;

typedef struct MwsfdDecSlot {
    char pad00[0x54];
    void *buf;                          /* 0x54 */
    char pad58[0xF0 - 0x58];
} MwsfdDecSlot;

typedef struct MwsfdInitView {
    int f0;
    Def24 prm;                          /* 0x004 */
    Def8 prm2;                          /* 0x028 */
    Def40 prm3;                         /* 0x030 */
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    char f8C[0x10C - 0x8C];
    int f10C;
    int f110;
    int f114;
    char f118[0x138 - 0x118];
    int f138;
    int f13C;
    char pad140[0x160 - 0x140];
    int f160[6];
    char pad178[0x180 - 0x178];
    MwsfdDecSlot slot[16];                /* 0x180 */
    char f1080[0x109C - 0x1080];
    char ent[16][8];                    /* 0x109C */
} MwsfdInitView;

extern Def24 D_00766BA8;
extern Def8 D_00766BD0;
extern Def40 D_00766BD8;
extern int func_003549A8(void *a0, MwsfdInitView *hn);
extern void func_00354A70(void *a0, void *a1, int a2);
extern void func_00354B20(void *a0);
extern void func_003520B0(void *a0);
extern void func_00354B40(void *a0);

__attribute__((section(".text.func_003547B0")))
int func_003547B0(void *a0, MwsfdInitView *hn)
{
    int i;

    if (func_003549A8(a0, hn))
        return func_0034DD70(0, 0xFF000F15);
    hn->prm = D_00766BA8;
    hn->prm2 = D_00766BD0;
    hn->prm3 = D_00766BD8;
    hn->f74 = 5;
    hn->f78 = 0xC0;
    hn->f13C = 1;
    hn->f0 = 0;
    hn->f70 = 0;
    hn->f138 = 0;
    hn->f7C = 0;
    hn->f80 = 0;
    hn->f160[0] = 0;
    hn->f160[1] = 0;
    hn->f160[2] = 0;
    hn->f160[3] = 0;
    hn->f160[4] = 0;
    hn->f160[5] = 0;
    func_00354A70(hn->slot, &hn->prm3, 0x10);
    hn->f84 = 0;
    hn->f88 = 0;
    func_00354B20(hn->f8C);
    hn->f10C = -1;
    hn->f110 = 0;
    hn->f114 = 0x7FFFFFFF;
    func_003520B0(hn->f118);
    func_00354B40(hn->f1080);
    for (i = 15; i >= 0; i--)
        hn->slot[i].buf = hn->ent[i];
    return 0;
}

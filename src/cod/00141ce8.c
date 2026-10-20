/* func_00141CE8: HUD panel reset: restart anims, show/hide parts by game level and god-item count (sn-2.95.3-136) */
#include "godhand/player.h"
#include "godhand/cCoreSave.h"
extern void cIDBase_restartAnim(void *p);
extern float cHeatSys_GetHeatRatio(void *self);
extern void func_002AC9B8(void *p, void *ent, int arg);

#define WK(o) (*(char **)(p + (o)))
#define FL(o) (*(int *)(WK(o) + 0x2C))

__attribute__((section(".text.func_00141CE8")))
void func_00141CE8(char *p)
{
    char **w;
    int i;
    int n;
    char *b3 = p + 0x210;
    char *b1 = p + 0xE0;
    char *b2 = p + 0x190;

    *(int *)(p + 0x90) = 0;
    cIDBase_restartAnim(p);
    *(unsigned char *)(p + 0x1C) = 1;
    cIDBase_restartAnim(b3);
    *(unsigned char *)(b3 + 0x1C) = 1;
    FL(0xC8) |= 0x8000000;
    FL(0xCC) |= 0x8000000;
    FL(0xD0) |= 0x8000000;
    FL(0xD4) |= 0x8000000;
    cIDBase_restartAnim(b1);
    *(unsigned char *)(b1 + 0x1C) = 1;
    cIDBase_restartAnim(b2);
    *(unsigned char *)(b2 + 0x1C) = 0;
    *(int *)(p + 0x180) = 0;
    *(unsigned short *)(p + 0x17C) = cCoreSave_getGameLevel(&D_00569B70);
    if (*(unsigned short *)(p + 0x17C) == 4)
        *(unsigned short *)(p + 0x17C) = 3;
    else if (*(unsigned short *)(p + 0x17C) == 5)
        *(unsigned short *)(p + 0x17C) = 4;
    (*(unsigned short *)(p + 0x17C))--;
    w = (char **)(p + 0x98);
    *(int *)(*(char **)((int)w + ((*(unsigned short *)(p + 0x17C) + 12) << 2)) + 0x2C) &= ~0x8000000;
    func_002AC9B8(p, *(char **)((int)w + ((*(unsigned short *)(p + 0x17C) + 12) << 2)), 0);
    FL(0x1FC) |= 0x8000000;
    FL(0x200) |= 0x8000000;
    FL(0x204) |= 0x8000000;
    FL(0xC8) |= 0x400;
    FL(0xCC) |= 0x400;
    FL(0xD0) |= 0x400;
    FL(0xD4) |= 0x400;
    FL(0x1F8) |= 0x1000;
    *(float *)(WK(0x1F8) + 0x40) = 0.75f;
    *(float *)(WK(0x1F8) + 0x44) = 0.75f;
    *(unsigned char *)(p + 0x260) = cCoreSave_getGodItemNum(&D_00569B70);
    n = cCoreSave_getGodItemNum(&D_00569B70);
    w = (char **)(p + 0x130);
    for (i = 0; i < 6; i++) {
        if (i < n)
            *(int *)(w[i] + 0x2C) &= ~0x8000000;
        else
            *(int *)(w[i] + 0x2C) |= 0x8000000;
    }
    *(float *)(p + 0x264) = cHeatSys_GetHeatRatio(&D_005CB000);
    *(float *)(p + 0x268) = cHeatSys_GetHeatRatio(&D_005CB000);
    FL(0x164) |= 0x8000000;
    FL(0x168) |= 0x8000000;
    FL(0x16C) |= 0x8000000;
    FL(0x170) |= 0x8000000;
    FL(0x174) |= 0x8000000;
    FL(0x178) |= 0x8000000;
    FL(0xDC) |= 0x8000000;
    FL(0xB0) |= 0x8000000;
    {
    char *b = p + 0x190;
    func_002AC9B8(p, WK(0xC4), 1);
    *(unsigned char *)(WK(0xC4) + 0x4F) = 0;
    func_002AC9B8(b, WK(0x1E8), 1);
    *(unsigned char *)(WK(0x1E8) + 0x4F) = 0;
    func_002AC9B8(b, WK(0x208), 1);
    *(unsigned char *)(WK(0x208) + 0x4F) = 0;
    func_002AC9B8(b, WK(0x20C), 1);
    *(unsigned char *)(WK(0x20C) + 0x4F) = 0x80;
    }
    *(unsigned char *)(p + 0x26F) = 0;
}

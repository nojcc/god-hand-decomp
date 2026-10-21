/* sn-2.95.3-136 */
/* func_002B1890: draws a message window as a nine-slice frame plus its pointer tail (sn-2.95.3-136) */
#include "godhand/cMessDrawFont.h"

extern cMessDrawFont D_005E7510;
extern char D_005E75A0[];
extern char D_003C2478[];
extern void *D_003C254C;
extern void func_002B2058(void *spr, int idx, void *tex, float x, float y, float w, float h);

__attribute__((section(".text.func_002B1890")))
void func_002B1890(char *self)
{
    long t;
    float x0, y0, w, h;
    float xe, x1, x2, wm, y1, hm, y2;
    cMessDrawFont *font;
    char *spr;

    t = *(int *)(self + 0x14);
    if ((((unsigned long)t >> 3) & 1UL) == 0)
        return;
    font = &D_005E7510;
    spr = D_005E75A0;
    w = font->sizeW + *(float *)(self + 0x98) * 24.0f;
    x0 = (float)*(short *)(self + 0xA6) - 12.0f;
    y0 = (float)*(short *)(self + 0xA8) - 12.0f;
    h = font->sizeH + *(float *)(self + 0x9C) * 24.0f;
    *(void **)(spr + 4) = D_003C2478;
    x1 = x0 + 21.0f;
    wm = w - 42.0f;
    func_002B2058(spr, 0, D_003C254C, x0, y0, 21.0f, 21.0f);
    xe = x0 + w;
    x2 = xe - 21.0f;
    func_002B2058(spr, 1, D_003C254C, x1, y0, wm, 21.0f);
    y1 = y0 + 21.0f;
    hm = h - 42.0f;
    func_002B2058(spr, 2, D_003C254C, x2, y0, 21.0f, 21.0f);
    func_002B2058(spr, 3, D_003C254C, x0, y1, 21.0f, hm);
    func_002B2058(spr, 4, D_003C254C, x1, y1, wm, hm);
    func_002B2058(spr, 5, D_003C254C, x2, y1, 21.0f, hm);
    y2 = y0 + h - 21.0f;
    func_002B2058(spr, 6, D_003C254C, x0, y2, 21.0f, 21.0f);
    func_002B2058(spr, 7, D_003C254C, x1, y2, wm, 21.0f);
    func_002B2058(spr, 8, D_003C254C, x2, y2, 21.0f, 21.0f);
    switch (*(unsigned short *)(self + 0x62)) {
    case 1:
        func_002B2058(spr, 9, D_003C254C, x0 - 42.0f, y1, *(float *)(self + 0x98) * 42.0f, *(float *)(self + 0x9C) * 42.0f);
        break;
    case 2:
        func_002B2058(spr, 9, D_003C254C, xe + 42.0f, y1, *(float *)(self + 0x98) * -42.0f, *(float *)(self + 0x9C) * 42.0f);
        break;
    case 3:
        func_002B2058(spr, 9, D_003C254C, x0 - 42.0f, y2, *(float *)(self + 0x98) * 42.0f, *(float *)(self + 0x9C) * -42.0f);
        break;
    case 4:
        func_002B2058(spr, 9, D_003C254C, xe + 42.0f, y2, *(float *)(self + 0x98) * -42.0f, *(float *)(self + 0x9C) * -42.0f);
        break;
    }
}

/* NON_MATCHING func_00150C10: draw one glyph at the cursor (mode 0 direct, mode 1 through the font lookup, which can resolve it outright) and advance the cursor from the glyph table; returns the old glyph index, or -1.
 * Structure matches; retail allocates the result to t0 (the lookup result goes v0 -> a0 -> t0) where ours uses a3, which also shifts the glyph-info load. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct GlyphInfo150C10 {
    char pad0[0x12];
    unsigned short height;              /* 0x12 */
} GlyphInfo150C10;

typedef struct Glyph150C10 {
    char pad0[2];
    unsigned char width;                /* 0x02 */
    char pad3[0xD];
    unsigned short step;                /* 0x10 */
    unsigned short adv;                 /* 0x12 */
    GlyphInfo150C10 *info;              /* 0x14 */
    char pad18[0xB0 - 0x18];
} Glyph150C10;

typedef struct Cursor150C10 {
    int count;                          /* 0x00 */
    int idx;                            /* 0x04 */
    int x;                              /* 0x08 */
    int y;                              /* 0x0C */
} Cursor150C10;

extern Glyph150C10 D_00747BA0[];

extern int func_0030A298(int y);
extern void func_003090F8(int idx, char *str, int x, int y);
extern int func_00150D78(Cursor150C10 *c, char *str);
extern void func_00309D88(int idx, char *str, int x, int y, int flag);
extern void func_0030A200(int idx);

int func_00150C10(Cursor150C10 *c, char *str, int mode)
{
    int r = -1;
    Glyph150C10 *g;

    if (str != 0) {
        if (mode == 0) {
            func_003090F8(*(unsigned char *)&c->idx, str, c->x, func_0030A298(c->y));
            r = c->idx;
            g = &D_00747BA0[r];
            c->count++;
            c->idx = r + g->step;
            c->y += g->width;
            c->x += g->adv;
        }
        if (mode == 1) {
            r = func_00150D78(c, str);
            if (r == -1) {
                func_00309D88(c->idx, str, c->x, c->y, 1);
                func_0030A200(c->idx);
                r = c->idx;
                g = &D_00747BA0[r];
                c->count++;
                c->idx = r + g->step;
                c->y += g->info->height;
                c->x += g->adv;
            }
        }
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00150C10);
#endif

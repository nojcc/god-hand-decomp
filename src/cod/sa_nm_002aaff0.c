/* NON_MATCHING cIDBase_transSprite (sn,as-sn,abi-stack-args): best 35 (--as sn): retail passes 8 words on the stack (w,h,0,1.0,w,h,0,1.0 stored directly with swc1/sw) after f12-f16, leaving f17-f19 unused, so they are not plain float params; a 16-byte struct by value goes by reference (35), 8-byte structs are copied with ldl/ldr (51). Also retail keeps ent in t3 and reads the flag byte at 0x2D. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    float x, y;
} SprVec2;
typedef struct {
    char pad0[0x46];
    unsigned char mode; /* 0x46 */
} IDBase;
typedef struct {
    char pad0[0x28];
    int colorNo; /* 0x28 */
    int fontNo; /* 0x2C */
} IDDraw;
typedef struct {
    char pad0[0x2C];
    unsigned char flags0; /* 0x2C */
    unsigned char flags1; /* 0x2D */
    char pad2E[2];
    char pad30[0x50 - 0x30];
    float drawX; /* 0x50 */
    float drawY; /* 0x54 */
    float drawSclX; /* 0x58 */
    float drawSclY; /* 0x5C */
    float drawRot; /* 0x60 */
    unsigned int color; /* 0x64 */
    float w; /* 0x68 */
    float h; /* 0x6C */
    float rot; /* 0x70 */
    char pad74[0x84 - 0x74];
    unsigned int seed; /* 0x84 */
    unsigned char kind; /* 0x88 */
    unsigned char b89; /* 0x89 */
    unsigned char b8A; /* 0x8A */
    unsigned char b8B; /* 0x8B */
    signed char cells; /* 0x8C */
    unsigned char colorNo; /* 0x8D */
    short fontNo; /* 0x8E */
} IDEnt;
extern void func_002C70A8(IDDraw *draw, int cells, unsigned int seed, unsigned int color, int flag,
                          int b89, int b8B, int b8A, float x, float y, float cw, float h, float rot,
                          SprVec2 scl0, SprVec2 ofs0, SprVec2 scl1, SprVec2 ofs1);

void cIDBase_transSprite(IDBase *self, IDDraw *draw, IDEnt *ent)
{
    SprVec2 scl, ofs;
    float w, h;
    int cells;

    if (self->mode == 6)
        draw->colorNo = ent->colorNo;
    else
        draw->colorNo = self->mode;
    draw->fontNo = ent->fontNo;
    cells = ent->cells;
    w = ent->w * ent->drawSclX;
    h = ent->h * ent->drawSclY;
    scl.x = w;
    scl.y = h;
    ofs.x = 0.0f;
    ofs.y = 1.0f;
    func_002C70A8(draw, cells, ent->seed, ent->color, ent->flags1 & 1, ent->b89, ent->b8B, ent->b8A,
                  ent->drawX, ent->drawY, w / (float)cells, h, ent->rot, scl, ofs, scl, ofs);
}
#else
INCLUDE_ASM("asm/nonmatching", cIDBase_transSprite);
#endif

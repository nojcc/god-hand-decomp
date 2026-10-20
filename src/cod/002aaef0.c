/* NON_MATCHING cIDBase_transTex: sn: same ABI wall as cIDBase_transSprite: retail stores w,h,0,1.0 x2 straight into the outgoing stack area;
* 16-byte aligned structs go by reference, aligned(8) pairs go through 64-bit regs */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    float w, h;
    int flag;
    float a;
} __attribute__((aligned(16))) TexQuad2AAEF0;
typedef struct {
    char pad0[0x46];
    unsigned char mode; /* 0x46 */
} IdBaseView;
typedef struct {
    char pad0[0x28];
    int colorNo; /* 0x28 */
    int fontNo; /* 0x2C */
} IdDraw;
typedef struct {
    char pad0[0x24];
    void *tex;          /* 0x24 */
    char pad28[0x50 - 0x28];
    float drawX;        /* 0x50 */
    float drawY;        /* 0x54 */
    float drawSclX;     /* 0x58 */
    float drawSclY;     /* 0x5C */
    float drawRot;      /* 0x60 */
    unsigned int color; /* 0x64 */
    float w;            /* 0x68 */
    float h;            /* 0x6C */
    float f70[4];       /* 0x70 */
    float f80;          /* 0x80 */
    char pad84[5];
    unsigned char b89;  /* 0x89 */
    unsigned char b8A;  /* 0x8A */
    unsigned char b8B;  /* 0x8B */
    char pad8C;
    unsigned char colorNo; /* 0x8D */
    short fontNo;       /* 0x8E */
} IdEnt;

extern int *D_003C2384;
extern void *cIDManager_getTexAddr(int mgr, int res, int id);
extern void func_002C5EA8(IdDraw *draw, void *tex, unsigned int color, int b89,
                          float x, float y, float w, float h, float rot,
                          float u0, float v0, float u1, float v1, float f80,
                          TexQuad2AAEF0 q0, TexQuad2AAEF0 q1);

void cIDBase_transTex(IdBaseView *self, IdDraw *draw, IdEnt *ent)
{
    void *tex;
    TexQuad2AAEF0 q;
    float w, h;

    tex = ent->tex;
    if (tex == 0)
        tex = cIDManager_getTexAddr(*D_003C2384, ent->b8A, ent->b8B + 1);
    if (self->mode == 6)
        draw->colorNo = ent->colorNo;
    else
        draw->colorNo = self->mode;
    draw->fontNo = ent->fontNo;
    w = ent->w * ent->drawSclX;
    h = ent->h * ent->drawSclY;
    q.w = w;
    q.h = h;
    q.flag = 0;
    q.a = 1.0f;
    func_002C5EA8(draw, tex, ent->color, ent->b89, ent->drawX, ent->drawY, w, h, ent->drawRot,
                  ent->f70[0], ent->f70[1], ent->f70[2], ent->f70[3], ent->f80, q, q);
}
#else
INCLUDE_ASM("asm/nonmatching", cIDBase_transTex);
#endif

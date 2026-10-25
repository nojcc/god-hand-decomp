/* include/godhand/cScrSpriteDraw.h - the screen sprite draw state.
 *
 * cScrSpriteDraw is not a long-lived object. Callers keep one 0x34-byte
 * record on the stack, reset it with cScrSpriteDraw_drawInit (every scale
 * 1.0, colour table 6, font 5, no clip) and hand it to the draw methods as
 * `this`. The methods read the record to move, scale and tint what they
 * draw, then queue one packet each.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read the record.
 * Offsets are exact; a field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CSCRSPRITEDRAW_H
#define GODHAND_CSCRSPRITEDRAW_H

typedef struct cScrSpriteDraw {
    char *sprites;                      /* 0x00 sprite records, 0x1C bytes each */
    char *texBase;                      /* 0x04 texture offset table; the textures follow it */
    float shiftX;                       /* 0x08 added to x before the screen scale */
    float shiftY;                       /* 0x0C added to y */
    float scaleX;                       /* 0x10 multiplies the width */
    float scaleY;                       /* 0x14 multiplies the height */
    float alphaScale;                   /* 0x18 multiplies bits 24..31 of the packed colour */
    float redScale;                     /* 0x1C bits 0..7 */
    float greenScale;                   /* 0x20 bits 8..15 */
    float blueScale;                    /* 0x24 bits 16..23 */
    int colorNo;                        /* 0x28 colour table index */
    int fontNo;                         /* 0x2C */
    unsigned short clip;                /* 0x30 0xFFFF = no clip */
    char unk32[2];
} cScrSpriteDraw;                       /* 0x34 */

/* The draw methods build their packets in this shape: a screen vertex is
 * (x, y, depth, 1.0), where the depth is the draw state's clip value. */
#define SCR_BASE_HEIGHT  448.0f         /* layout height the draw coordinates assume */
#define SCR_PKT_TAG      0x3001D        /* tag word written into the packet that comes back */

/* One sprite record: which texture, its texel window, and its size. */
typedef struct cScrSprite {
    unsigned char tex;                  /* 0x00 index into the texture offset table */
    char unk01[3];
    float u0;                           /* 0x04 */
    float v0;                           /* 0x08 */
    float u1;                           /* 0x0C */
    float v1;                           /* 0x10 */
    float w;                            /* 0x14 width, before the draw state's scale */
    float h;                            /* 0x18 */
} cScrSprite;                           /* 0x1C */

/* The texture draw config the packet builders take: a mode word, then the
 * texel window. The callers keep the whole 0x50 bytes on the stack. */
typedef struct cScrTexCfg {
    int mode;                           /* 0x00 SCR_TEX_* bits */
    float u0;                           /* 0x04 */
    float v0;                           /* 0x08 */
    float u1;                           /* 0x0C */
    float v1;                           /* 0x10 */
    float u2;                           /* 0x14 SCR_TEX_CORNERS: (u0,v0) (u1,v1) (u2,v2) (u3,v3) */
    float v2;                           /* 0x18 */
    float u3;                           /* 0x1C */
    float v3;                           /* 0x20 */
    float cutX;                         /* 0x24 SCR_TEX_CUT0/1: fraction of the top edge kept */
    float cutY;                         /* 0x28 */
    char unk2C[4];
    unsigned long alpha;                /* 0x30 SCR_TEX_ALPHA: ALPHA_1 register */
    char unk38[8];
    unsigned long clamp;                /* 0x40 SCR_TEX_CLAMP: CLAMP_1 register */
    char unk48[8];
} cScrTexCfg;                           /* 0x50 */

#define SCR_TEX_RECT     0x01           /* texel rectangle (u0,v0)-(u1,v1) */
#define SCR_TEX_CUT1     0x04           /* pull vertex 1 toward vertex 0 by cutX, cutY */
#define SCR_TEX_CUT0     0x08           /* pull vertex 0 toward vertex 1 by cutX, cutY */
#define SCR_TEX_CORNERS  0x10           /* one texel position per corner */
#define SCR_TEX_ALPHA    0x20
#define SCR_TEX_CLAMP    0x80

typedef struct cScrVtx {
    float x;
    float y;
    float z;
    float w;
} cScrVtx;

static __inline__ void cScrVtx_set(cScrVtx *v, float x, float y, int z) {
    v->x = x;
    v->y = y;
    v->z = (float)z;
    v->w = 1.0f;
}

extern float D_003C1184;                /* screen width (512.0) */
extern int D_003C11B0;                  /* draw mode word passed to the packet builders */

/* Float to unsigned int (definition in 001c8f30.c). */
unsigned int func_0031ED08(float f12);

/* Draw glyph digit (0-9, -1 the minus sign) of the digit sheet texNo in bank
 * slot, centred on (x, y) (definition in 002c6d48.c). */
void func_002C6D48(cScrSpriteDraw *self, int digit, float x, float y, float w, float h,
                   unsigned int color, short texNo, unsigned short slot);

/* One colour channel of the packed colour, scaled and clamped back to a byte
 * (func_0031ED08 does the clamp). */
#define SCR_CHAN(color, shift, scale) \
    func_0031ED08((float)(unsigned int)(((color) >> (shift)) & 0xFF) * (scale))

typedef char cScrSpriteDraw_size_check[(sizeof(cScrSpriteDraw) == 0x34) ? 1 : -1];

extern void cScrSpriteDraw_drawTex(cScrSpriteDraw *self, unsigned int tex,
                                   float x, float y, float w, float h,
                                   float u0, float v0, float u1, float v1, unsigned int color);
void cScrSpriteDraw_drawTexCentered(cScrSpriteDraw *self, unsigned int tex,
                                    float x, float y, float w, float h,
                                    float u0, float v0, float u1, float v1, unsigned int color);

#endif

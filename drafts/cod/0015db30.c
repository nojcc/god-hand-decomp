/* sn-2.95.3-136 */
/* NON_MATCHING func_0015DB30: same length and frame; retail runs the vertex loop as a
 * count-down from 2 and orders the packet stores differently, which moves
 * 64 instructions. */
#include "include_asm.h"
#include "godhand/cScrSpriteDraw.h"
#include "godhand/drawQueue.h"
#include "godhand/sceVu0.h"

extern int D_003C1180;                  /* screen width */
extern int D_00586B80;                  /* screen top in GS coordinates */

/* One A+D entry of a GIF packet: register data, then the register. */
typedef struct GsAd {
    unsigned long data;
    unsigned long addr;
} GsAd;

/* An A+D entry for the ST register, its data written as two floats. */
typedef struct GsAdSt {
    float s;
    float t;
    unsigned long addr;
} GsAdSt;

/* The flat sprite packet: TEST_1, then one GIF list of the colour and the
 * two corners with their texel positions. */
typedef struct GpSpritePkt {
    unsigned long dmaTag;               /* 0x00 cnt, 8 qwords */
    unsigned int vifFlush;              /* 0x08 */
    unsigned int vifDirect;             /* 0x0C DIRECT 8 */
    unsigned long envTag[2];            /* 0x10 A+D, 1 register */
    GsAd test;                          /* 0x20 */
    unsigned long primTag[2];           /* 0x30 sprite, 5 A+D entries */
    GsAd rgbaq;                         /* 0x40 */
    GsAdSt st0;                         /* 0x50 */
    GsAd xyz0;                          /* 0x60 XYZ3: no kick */
    GsAdSt st1;                         /* 0x70 */
    GsAd xyz1;                          /* 0x80 XYZ2 */
    unsigned long endTag;               /* 0x90 end */
    unsigned int endVifFlush;           /* 0x98 */
    unsigned int endVifNop;             /* 0x9C */
} GpSpritePkt;

#ifdef NON_MATCHING
/* Queue a sprite from the corners v[0] and v[1] in the packed colour color,
 * with cfg's texel rectangle and alpha settings when given; returns the
 * packet, or 0 when the packet buffer is full. tex is not read. */
__attribute__((section(".text.func_0015DB30")))
GpSpritePkt *func_0015DB30(cScrVtx *v, unsigned int color, void *tex, cScrTexCfg *cfg, int kind, int prio)
{
    GpSpritePkt *pkt;
    sceVu0IVECTOR xy[2];
    union { float f; unsigned int i; } q;
    int i;

    pkt = PostInc_D_00566E10_0015B0F0_15B0F0(sizeof(GpSpritePkt));
    if (pkt == 0) {
        return 0;
    }
    pkt->dmaTag = 0x10000008;
    pkt->envTag[0] = 0x1000000000000001;
    pkt->vifFlush = 0x11000000;
    pkt->vifDirect = 0x50000008;
    pkt->envTag[1] = 0xE;
    pkt->test.data = 0x5080B;
    pkt->test.addr = 0x47;
    for (i = 1; i >= 0; i--) {
        sceVu0FTOI4Vector(xy[i], &v[i]);
        xy[i][1] += D_00586B80 * 16;
        xy[i][0] += (0x800 - D_003C1180 / 2) * 16;
    }
    pkt->rgbaq.addr = 1;
    pkt->primTag[0] = 0x100B400000008005;
    pkt->primTag[1] = 0xE;
    q.f = 1.0f;
    pkt->rgbaq.data = (unsigned long)(color & 0xFF) | (unsigned long)((color >> 8) & 0xFF) << 8
                    | (unsigned long)((color >> 16) & 0xFF) << 16 | (unsigned long)((color >> 24) & 0xFF) << 24
                    | (unsigned long)q.i << 32;
    pkt->xyz0.addr = 0xD;
    pkt->xyz0.data = xy[0][0] | (unsigned long)xy[0][1] << 16 | (unsigned long)(xy[0][2] >> 4) << 32;
    pkt->xyz1.addr = 5;
    pkt->st1.t = 1.0f;
    pkt->xyz1.data = xy[1][0] | (unsigned long)xy[1][1] << 16 | (unsigned long)(xy[1][2] >> 4) << 32;
    pkt->st1.addr = 2;
    pkt->endTag = 0x70000000;
    pkt->endVifFlush = 0x11000000;
    pkt->st0.s = 0.0f;
    pkt->st0.t = 0.0f;
    pkt->st0.addr = 2;
    pkt->st1.s = 1.0f;
    pkt->endVifNop = 0;
    if (cfg != 0) {
        if (cfg->mode & SCR_TEX_ALPHA) {
            pkt->test.data = cfg->alpha;
        }
        if (cfg->mode & SCR_TEX_RECT) {
            pkt->st0.s = cfg->u0;
            pkt->st0.t = cfg->v0;
            pkt->st1.s = cfg->u1;
            pkt->st1.t = cfg->v1;
        }
    }
    func_0031A650(D_00754C80, kind, prio, pkt, &pkt->endTag);
    return pkt;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0015DB30);
#endif

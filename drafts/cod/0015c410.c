/* sn-2.95.3-136 */
/* NON_MATCHING func_0015C410: same length (322 words). Retail adds tbp to
 * TEX0.TBP0 in 64 bits with tbp zero-extended, where C promotes the 14-bit
 * field to int; the end tag stores and the cfg reloads also take other
 * registers and order. Needs as=sn. */
#include "include_asm.h"
#include "godhand/cCamManager.h"
#include "godhand/cScrSpriteDraw.h"
#include "godhand/drawQueue.h"
#include "godhand/pack.h"
#include "godhand/sceVu0.h"
#include "godhand/tim2.h"

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

/* One vertex of the strip: its texel position, then its screen position. */
typedef struct GpStripVtx {
    GsAdSt st;                          /* 0x00 */
    GsAd xyz;                           /* 0x10 XYZ3 for the first vertex, XYZ2 after */
} GpStripVtx;

/* The end of a DMA chain: an end tag and two VIF words. */
typedef struct GpEndTag {
    unsigned long tag;                  /* 0x00 */
    unsigned int vifFlush;              /* 0x08 */
    unsigned int vifNop;                /* 0x0C */
} GpEndTag;

/* The textured strip packet: the texture upload the TIM2 builders write,
 * the texture and blend registers, then one GIF list of the colour and the
 * vertices, closed by a GpEndTag after the last vertex. */
typedef struct GpStripPkt {
    char upload[0x160];                 /* 0x000 */
    unsigned long dmaTag;               /* 0x160 cnt */
    unsigned int vifFlush;              /* 0x168 */
    unsigned int vifDirect;             /* 0x16C */
    unsigned long envTag[2];            /* 0x170 A+D, 6 registers */
    GsAd texflush;                      /* 0x180 */
    GsAd alpha;                         /* 0x190 */
    GsAd test;                          /* 0x1A0 */
    GsAd clamp;                         /* 0x1B0 */
    GsAd tex0;                          /* 0x1C0 */
    GsAd tex1;                          /* 0x1D0 */
    unsigned long primTag[2];           /* 0x1E0 triangle strip */
    GsAd rgbaq;                         /* 0x1F0 */
    GpStripVtx vtx[1];                  /* 0x200 one per vertex */
} GpStripPkt;

#ifdef NON_MATCHING
/* Queue a textured triangle strip of n vertices (at least 3) with texel
 * positions (s[i], t[i]) in the packed colour color. The texture file tex
 * is uploaded at tbp (CLUT at cbp) by the builder for its kind. With screen
 * == 0 the vertices are projected through the current camera and a strip of
 * kind 2 is queued at a depth from the projected z; otherwise they are
 * screen positions and the strip is queued at prio. Returns the packet, or
 * 0 when the packet buffer is full or the file kind is 3. */
__attribute__((section(".text.func_0015C410")))
GpStripPkt *func_0015C410(cVec *verts, float *s, float *t, unsigned int n, unsigned int color,
                          int screen, void *tex, unsigned int tbp, int cbp, cScrTexCfg *cfg,
                          int kind, int prio)
{
    float mtx[4][4];
    sceVu0IVECTOR xy;
    GsTex0 tex0;
    GpStripPkt *pkt;
    GpStripVtx *vtx;
    GpEndTag *end;
    unsigned int size;
    unsigned int i;
    int depth;
    union { float f; unsigned int i; } q;

    if (n < 3) {
        return 0;
    }
    size = n * sizeof(GpStripVtx);
    pkt = PostInc_D_00566E10_0015B0F0_15B0F0(size + 0x210);
    if (pkt == 0) {
        return 0;
    }
    vtx = pkt->vtx;
    end = (GpEndTag *)&vtx[n];
    switch (func_00151630(tex)) {
    case 0:
        func_0015E0A0(pkt, tex, tbp, cbp, &tex0);
        break;
    case 1:
        func_0015E2E0(pkt, tex, tbp, cbp, &tex0);
        break;
    case 2:
        func_0015DDF8((struct TexUpPacket *)pkt, tex, tbp, cbp, &tex0);
        tex0.TBP0 += tbp;
        tex0.CBP = cbp;
        tex0.TCC = 1;
        break;
    case 3:
        return 0;
    }
    pkt->dmaTag = (size / 16 + 9) | 0x10000000;
    pkt->vifFlush = 0x11000000;
    pkt->vifDirect = (size / 16 + 9) | 0x50000000;
    pkt->envTag[0] = 0x1000000000000006;
    pkt->envTag[1] = 0xE;
    pkt->texflush.data = 0xFF;
    pkt->texflush.addr = 0x3F;
    pkt->alpha.data = 0x8000000044;
    pkt->alpha.addr = 0x42;
    pkt->test.data = 0x50000;
    pkt->test.addr = 0x47;
    pkt->clamp.data = 0;
    pkt->clamp.addr = 8;
    pkt->tex0.data = *(unsigned long *)&tex0;
    pkt->tex0.addr = 6;
    pkt->tex1.data = 0x60;
    pkt->tex1.addr = 0x14;
    pkt->primTag[0] = (size / 16 | 0x8001) | 0x102AC00000000000;
    pkt->primTag[1] = 0xE;
    q.f = 1.0f;
    pkt->rgbaq.data = (unsigned long)(color & 0xFF) | (unsigned long)((color >> 8) & 0xFF) << 8
                    | (unsigned long)((color >> 16) & 0xFF) << 16 | (unsigned long)((color >> 24) & 0xFF) << 24
                    | (unsigned long)q.i << 32;
    pkt->rgbaq.addr = 1;
    /* retail takes the depth from xy before any vertex is projected into it */
    depth = ((0x400 - (xy[2] >> 8)) & 0xFFF) + 0x32;
    if (depth >= 0x400) {
        depth = 0x3FF;
    }
    for (i = 0; i < n; i++) {
        if (screen == 0) {
            func_0030A548(mtx, D_005CAFF0);
            sceVu0RotTransPers(xy, mtx, &verts[i], 0);
        } else {
            sceVu0FTOI4Vector(xy, &verts[i]);
            xy[0] += (0x800 - D_003C1180 / 2) * 16;
            xy[1] += D_00586B80 * 16;
        }
        if (i != 0) {
            vtx[i].xyz.data = xy[0] | (unsigned long)xy[1] << 16 | (unsigned long)(xy[2] >> 4) << 32;
            vtx[i].xyz.addr = 5;
        } else {
            vtx[i].xyz.data = xy[0] | (unsigned long)xy[1] << 16 | (unsigned long)(xy[2] >> 4) << 32;
            vtx[i].xyz.addr = 0xD;
        }
        vtx[i].st.s = s[i];
        vtx[i].st.t = t[i];
        vtx[i].st.addr = 2;
    }
    end->tag = 0x70000000;
    end->vifFlush = 0x11000000;
    end->vifNop = 0;
    if (cfg != 0) {
        if (cfg->mode & SCR_TEX_ALPHA) {
            pkt->test.data = cfg->alpha;
        }
        if (cfg->mode & SCR_TEX_CLAMP) {
            pkt->clamp.data = cfg->clamp;
            pkt->clamp.addr = 8;
        }
    }
    if (screen == 0) {
        if (depth > 0) {
            if (kind == 2) {
                func_0031A650(D_00754C80, 2, depth, pkt, end);
            } else {
                func_0031A650(D_00754C80, kind, prio, pkt, end);
            }
        }
    } else {
        func_0031A650(D_00754C80, kind, prio, pkt, end);
    }
    return pkt;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0015C410);
#endif

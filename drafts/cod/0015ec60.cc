/* sn-2.95.3-136 (C++ unit, -fno-exceptions). NON_MATCHING func_0015EC60: 163 words vs retail 159, slots exact (the clip matrix and its output share 0x50/0x90 with the screen coordinates and the corner copy). The build keeps &out (0x90) in a seventh saved register for the projection loop and counts the loop down; retail rebuilds sp+0x90 each pass and counts up with slti, and takes Q's 1.0 from $f20 where the build reloads it. A struct copy for the corner: 169 words; a walking corner pointer: 163. */
extern "C" {

#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/cVec.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/gsPacket.h"
#include "godhand/shadowPacket.h"


extern cVec D_004A6DC0[4];             /* the quad's corners, (+-1, 0, +-1), set on first use */
extern int D_004A6E00;                 /* nonzero once D_004A6DC0 is set */

/* Fill the shadow quad for a size x size square at pos, turned by q, with the given
 * alpha: if any corner falls outside the clip volume, the empty quad instead. */

__attribute__((section(".text.func_0015EC60")))
void func_0015EC60(ShadowPacket *p, cVec *pos, float *q, unsigned char alpha, float size)
{
    float m[4][4];
    cVec scale;
    int clip;

    cVec_set4(&scale, size, 1.0f, size, 1.0f);
    MtxBuildTransRotScale(&m[0][0], pos, q, &scale);
    if (D_004A6E00 == 0) {
        cVec *c = D_004A6DC0;

        c->x = 1.0f;
        c->y = 0.0f;
        c->z = 1.0f;
        c->w = 1.0f;
        c++;
        c->x = 1.0f;
        c->y = 0.0f;
        c->z = -1.0f;
        c->w = 1.0f;
        D_004A6E00 = 1;
        c++;
        c->x = -1.0f;
        c->y = 0.0f;
        c->z = 1.0f;
        c->w = 1.0f;
        c++;
        c->x = -1.0f;
        c->y = 0.0f;
        c->z = -1.0f;
        c->w = 1.0f;
    }
    {
        float clipM[4][4];
        cVec out;

        MtxMultiply(clipM, D_005CAFF0->mtx[3], m);
        clip = katVu0ViewVolumeClip(&out, clipM, &D_004A6DC0[0]) << 6;
        clip |= katVu0ViewVolumeClip(&out, clipM, &D_004A6DC0[1]);
        clip <<= 6;
        clip |= katVu0ViewVolumeClip(&out, clipM, &D_004A6DC0[2]);
        clip <<= 6;
        clip |= katVu0ViewVolumeClip(&out, clipM, &D_004A6DC0[3]);
    }
    if ((clip & 0xFFFFFF) == 0) {
        int scr[4][4];
        FloatBits bits;
        int i;

        MtxMultiply(m, D_005CAFF0->mtx[0], m);
        for (i = 0; i < 4; i++) {
            cVec v;

            CVEC_COPY(v, &D_004A6DC0[i]);
            sceVu0RotTransPers(scr[i], m, &v, 1);
        }
        bits.f = 1.0f;
        p->rgbaq = (long)alpha << 24 | 0xFFFFFF | (long)bits.u << 32;
        p->vtx[0].xyz = GS_SET_XYZ(scr[0][0], scr[0][1], scr[0][2]);
        p->vtx[1].xyz = GS_SET_XYZ(scr[1][0], scr[1][1], scr[1][2]);
        p->vtx[2].xyz = GS_SET_XYZ(scr[2][0], scr[2][1], scr[2][2]);
        p->vtx[3].xyz = GS_SET_XYZ(scr[3][0], scr[3][1], scr[3][2]);
    } else {
        func_0015EEE0(p);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0015EC60);
#endif

}

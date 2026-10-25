/* sn-2.95.3-136 */
/* NON_MATCHING EmClothInit: 873 vs 951 words; needs extern_jtbl D_0044DDE0.
 * Retail builds every case's cVec(0, dy, dz) in one stack slot, as C++
 * temporaries share one; the block-local temporaries here take a slot each,
 * so the frame is 0x90 larger. With one function-level temporary the
 * registers match, but retail still reloads z from the temporary after the
 * x and y copies and this code does not. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cloth.h"
#include "godhand/cVec.h"

extern unsigned char D_003C35A0[];
extern unsigned char D_003C35A8[];
extern unsigned char D_003C35B0[];
extern float D_003C35B8[];
extern float D_003C35C8[];
extern float D_003C35D8[];
extern unsigned char D_003C35E8[];
extern unsigned char D_003C35F0[];
extern unsigned char D_003C35F8[];
extern float D_003C3600[];
extern float D_003C3618[];
extern float D_003C3630[];
extern unsigned char D_003C3648[];
extern unsigned char D_003C3658[];
extern unsigned char D_003C3668[];
extern float D_003C3678[];
extern float D_003C36A0[];
extern float D_003C36C8[];
extern unsigned char D_003C36F0[];
extern unsigned char D_003C36F8[];
extern unsigned char D_003C3700[];
extern float D_003C3708[];
extern float D_003C3720[];
extern float D_003C3738[];
extern unsigned char D_003C3750[];
extern unsigned char D_003C3758[];
extern unsigned char D_003C3760[];
extern float D_003C3768[];
extern float D_003C3788[];
extern float D_003C37A8[];
extern unsigned char D_003C3840[];
extern unsigned char D_003C3848[];
extern unsigned char D_003C3850[];
extern float D_003C3858[];
extern unsigned char D_003C3868[];
extern unsigned char D_003C3870[];
extern unsigned char D_003C3878[];
extern float D_003C3880[];
extern unsigned char D_003C3890[];
extern unsigned char D_003C38A0[];
extern unsigned char D_003C38B0[];
extern float D_003C38C0[];
extern float D_003C38E8[];
extern float D_003C3910[];
extern unsigned char D_003C3938[];
extern unsigned char D_003C3948[];
extern unsigned char D_003C3958[];
extern float D_003C3968[];
extern float D_003C3990[];
extern float D_003C39B8[];
extern unsigned char D_003C39E0[];
extern unsigned char D_003C39E8[];
extern unsigned char D_003C39F0[];
extern float D_003C39F8[];
extern float D_003C3A10[];
extern float D_003C3A28[];
extern unsigned char D_003C3A40[];
extern unsigned char D_003C3A50[];
extern unsigned char D_003C3A60[];
extern float D_003C3A70[];
extern float D_003C3A98[];
extern float D_003C3AC0[];
extern unsigned char D_003C3AE8[];
extern unsigned char D_003C3AF0[];
extern unsigned char D_003C3AF8[];
extern float D_003C3B00[];
extern float D_003C3B20[];
extern float D_003C3B40[];

/* One enemy cloth: the joint chain and its tables, the spheres, the push
 * and the two values func_001038E0 takes, then the start call. A macro
 * because each case repeats the whole block. */
#define EM_CLOTH_SET(c, n, jnt, par, chd, t28, t2C, t30, sph, nsph,      \
                     f3C, f40, own, fl, dy, dz, a3, a4)                  \
    {                                                                   \
        (c)->numJoints = (n);                                           \
        (c)->joint = (jnt);                                             \
        (c)->unk08 = 0;                                                 \
        (c)->unk0C = 0;                                                 \
        (c)->unk10 = 0;                                                 \
        (c)->unk14 = 0;                                                 \
        (c)->parent = (par);                                            \
        (c)->child = (chd);                                             \
        (c)->unk20 = 0;                                                 \
        (c)->unk24 = 0;                                                 \
        (c)->unk28 = (t28);                                             \
        (c)->unk2C = (t2C);                                             \
        (c)->unk30 = (t30);                                             \
        (c)->spheres = (sph);                                           \
        (c)->unk38 = (nsph);                                            \
        (c)->owner = (own);                                             \
        (c)->unk3C = (f3C);                                             \
        (c)->unk40 = (f40);                                             \
        (c)->unk44 = 1;                                                 \
        (c)->unk48 = 0.0f;                                              \
        (c)->unk4C = 0.1f;                                              \
        (c)->unk50 = 0.5f;                                              \
        (c)->unk54 = 0;                                                 \
        (c)->unk5C = (fl);                                              \
        CVEC_SET_XYZ(&(c)->drift.x, 0.0f, (dy), (dz))                   \
        (c)->unk70 = 1.0471976f;                                        \
        func_001038E0(self, (c), model, (a3), (a4));                    \
    }

/* Sets up an enemy's cloth from its enemy number and starts it. */
__attribute__((section(".text.EmClothInit")))
void EmClothInit(int emNo, cEm00 *self, void *model, EmCloth *cloth)
{
    if (self == 0 || model == 0 || cloth == 0) {
        return;
    }
    switch (emNo) {
    case 0x250:
    case 0x251:
        EM_CLOTH_SET(cloth, 4, D_003C35A0, D_003C35A8, D_003C35B0,
                     D_003C35B8, D_003C35C8, D_003C35D8, D_0061A9A0, 2,
                     0.015f, 0.8f, self, 0x100, 0.0f, 0.0f, 0.1f, 0.0f)
        break;
    case 0x214:
    case 0x215:
        EM_CLOTH_SET(cloth, 5, D_003C35E8, D_003C35F0, D_003C35F8,
                     D_003C3600, D_003C3618, D_003C3630, D_0061AA00, 4,
                     0.015f, 0.8f, self, 0x100, 0.0f, 0.0f, 0.1f, 0.0f)
        break;
    case 0x21C:
        EM_CLOTH_SET(cloth, 10, D_003C3648, D_003C3658, D_003C3668,
                     D_003C3678, D_003C36A0, D_003C36C8, D_0061AAC0, 5,
                     0.015f, 0.8f, self, 0x100, 0.0f, 0.0f, 0.1f, 0.0f)
        break;
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274:
        EM_CLOTH_SET(cloth, 6, D_003C36F0, D_003C36F8, D_003C3700,
                     D_003C3708, D_003C3720, D_003C3738, D_0061ABB0, 2,
                     0.015f, 0.8f, self, 0x500, 0.02f, -0.02f, 0.1f, 0.0f)
        break;
    case 0x256:
        EM_CLOTH_SET(cloth, 8, D_003C3750, D_003C3758, D_003C3760,
                     D_003C3768, D_003C3788, D_003C37A8, D_0061AC10, 4,
                     0.015f, 0.8f, self, 0x100, 0.0f, 0.0f, 0.1f, 0.0f)
        break;
    case 0x223:
        EM_CLOTH_SET(cloth, 4, D_003C3840, D_003C3848, D_003C3850,
                     D_003C3858, 0, 0, 0, 0,
                     0.015f, 0.8f, 0, 0, 0.0f, 0.0f, 0.1f, 0.1f)
        break;
    case 0x242:
    case 0x243:
        EM_CLOTH_SET(cloth, 10, D_003C3890, D_003C38A0, D_003C38B0,
                     D_003C38C0, D_003C38E8, D_003C3910, D_0061AD90, 8,
                     0.005f, 0.5f, self, 0x100, 0.0f, 0.0f, 0.1f, 0.0f)
        break;
    case 0x2A0:
        EM_CLOTH_SET(cloth, 10, D_003C3938, D_003C3948, D_003C3958,
                     D_003C3968, D_003C3990, D_003C39B8, D_0061AF10, 6,
                     0.005f, 0.5f, self, 0x100, 0.0f, 0.0f, 0.06f, 0.0f)
        break;
    case 0x252:
        if (self->actorId == 0x252 || self->actorId == 0x2A6) {
            EM_CLOTH_SET(cloth, 6, D_003C39E0, D_003C39E8, D_003C39F0,
                         D_003C39F8, D_003C3A10, D_003C3A28, D_0061B030, 6,
                         0.005f, 0.5f, self, 0x100, 0.0f, 0.0f, 0.06f, 0.0f)
        } else {
            EM_CLOTH_SET(cloth, 10, D_003C3A40, D_003C3A50, D_003C3A60,
                         D_003C3A70, D_003C3A98, D_003C3AC0, D_0061B150, 6,
                         0.005f, 0.5f, self, 0x100, 0.0f, 0.0f, 0.06f, 0.0f)
        }
        break;
    case 0x266:
        EM_CLOTH_SET(cloth, 3, D_003C3868, D_003C3870, D_003C3878,
                     D_003C3880, 0, 0, 0, 0,
                     0.015f, 0.8f, 0, 0, 0.0f, 0.0f, 0.1f, 0.3f)
        break;
    case 0x244:
        EM_CLOTH_SET(cloth, 8, D_003C3AE8, D_003C3AF0, D_003C3AF8,
                     D_003C3B00, D_003C3B20, D_003C3B40, 0, 0,
                     0.015f, 0.8f, self, 0x100, 0.0f, 0.0f, 0.1f, 0.0f)
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", EmClothInit);
#endif

/* sn-2.95.3-136 */
/* NON_MATCHING func_001C3090: 297 vs 299 words. The code matches up to
 * register choice. Retail puts the (1, 1, 1) scale and the lock-on copy in one
 * stack slot, as C++ temporaries freed after their statement; the block
 * locals here take a slot each, so the frame is 0x10 larger. Retail also keeps
 * self in s3 and loads the -0.02 piece constant into f20 before the record
 * calls. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/mtx.h"
#include "godhand/objField.h"
#include "godhand/rand.h"
#include "godhand/vecInline.h"

#define PIECE_SIZE      0x60                    /* one objField record per child */
#define VT_LOCKON_POS   16                      /* vtable slot of the lock-on position */

/* An object that breaks into its child parts; each part flies off through
 * its own objField record. */
typedef struct cOmShatter {
    cOmBase base;
    char unk5E0[0x608 - 0x5E0];
    char *piece;                                /* 0x608 PIECE_SIZE bytes per child */
    signed char shattered;                      /* 0x60C */
} cOmShatter;

/* Throw child part no off as a piece: stop the part's own matrix update,
 * jitter its start position and velocity, and fill its piece record. The
 * 0x403..0x405 objects scale the position jitter down with the part's height
 * above their lock-on point. */
__attribute__((section(".text.func_001C3090")))
void func_001C3090(cOmShatter *self, unsigned int no, cVec *pos, cVec *vel)
{
    int frame[3];
    cVec p;
    cVec v;
    cParts *part;
    float *mtx;
    char *rec;

    if (no >= self->base.childNum)
        return;
    if (cOmBase_childAtIdx(&self->base, frame, no) == 0)
        return;
    ((cParts *)cOmBase_childAtIdx(&self->base, frame, no))->partFlags |= CPARTS_NO_LOCAL;
    ((cParts *)cOmBase_childAtIdx(&self->base, frame, no))->partFlags |= CPARTS_NO_PARENT;
    CVEC_COPY(p, pos);
    CVEC_COPY(v, vel);
    switch (self->base.actorId) {
    case 800:
        p.x += fRand1_1() * 0.05f;
        p.y += 0.0f;
        p.z += fRand1_1() * 0.05f;
        break;
    case 0x403:
    case 0x404:
    case 0x405:
        if (cOmBase_childAtIdx(&self->base, frame, no) != 0) {
            cVec lock;
            cVec at;
            float d;
            float s;

            CVEC_COPY(lock, CVCALL_FN(&self->base, VT_LOCKON_POS, cVec *(*)(void *))(
                                CVCALL_THIS(&self->base, VT_LOCKON_POS)));
            part = (cParts *)cOmBase_childAtIdx(&self->base, frame, no);
            vec4_set_point(&at.x, part->mtx[12], part->mtx[13], part->mtx[14]);
            d = at.y - lock.y - 2.0f;
            if (d < 0.0f)
                s = 1.0f;
            else if (d >= 0.0f && d < 2.0f)
                s = (2.0f - d) * 0.5f;
            else
                s = 0.0f;
            p.x += fRand1_1() * 0.2f;
            p.y += fRand0_1() * 0.4f;
            p.z += fRand1_1() * 0.2f;
            CVEC_MUL_SCALAR(p, s);
        }
        break;
    default:
        p.x += fRand1_1() * 0.2f;
        p.y += fRand0_1() * 0.4f;
        p.z += fRand1_1() * 0.2f;
        break;
    }
    v.x += fRand1_1() * 0.1f;
    v.y += fRand1_1() * 0.1f;
    v.z += fRand1_1() * 0.1f;
    if (cOmBase_childAtIdx(&self->base, frame, no) == 0)
        return;
    mtx = ((cParts *)cOmBase_childAtIdx(&self->base, frame, no))->mtx;
    rec = self->piece + no * PIECE_SIZE;
    Obj0000_Set_Byte_54(rec, 1);
    Obj0000_Set_Field_50_173998(rec, mtx);
    ForwardVec3At30_147C60(rec, mtx);
    func_00147C88(rec + 0x10, mtx, 0);
    CopyVec3ToField20_173908(rec, &p.x);
    CopyVec3ToField30_173938(rec, &v.x);
    {
        cVec one;

        vec4_set_point(&one.x, 1.0f, 1.0f, 1.0f);
        CopyVec3ToField40_173968(rec, &one.x);
    }
    *(float *)(rec + 0x58) = -0.02f;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C3090);
#endif

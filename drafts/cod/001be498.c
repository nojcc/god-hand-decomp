/* NON_MATCHING func_001BE498 (sn-2.95.3-136): 177 differing words. Retail keeps the
 * child bounds check as a byte (andi 0xFF before the branch) in all three child
 * lookups, has a 0x10 larger frame, and multiplies the piece index by 0x60 with mult
 * from a saved register; cOmBase_childAt and the piece indexing here compile to
 * neither. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

#define PIECE_NUM          8
#define PIECE_FLAG_LOOSE   0x08
#define PIECE_FLAG_FLYING  0x10
#define PIECE_JITTER_XZ    0.05f
#define PIECE_JITTER_Y     0.2f
#define PIECE_JITTER_SPIN  0.1f
#define PIECE_GRAVITY      -0.02f
#define PIECE_SCALE_END    3.0f

/* One flying piece: a child body thrown off with its own motion. */
typedef struct cOmPiece {
    cVec pos;                   /* 0x00 */
    cVec rot;                   /* 0x10 */
    cVec vel;                   /* 0x20 */
    cVec spin;                  /* 0x30 */
    cVec scale;                 /* 0x40 */
    float *mtx;                 /* 0x50 the child body's matrix */
    unsigned char active;       /* 0x54 */
    char unk55[3];
    float gravity;              /* 0x58 */
    char unk5C[4];
} cOmPiece;

/* An object that breaks into pieces. */
typedef struct cOmPieces {
    cOmBase base;
    char unk5E0[0x600 - 0x5E0];
    cOmPiece piece[PIECE_NUM];  /* 0x600 */
} cOmPieces;

/* The child body's flags word. */
#define COMBASE_CHILD_FLAGS(b) (*(int *)((char *)(b) + 0x154))

typedef struct PieceFrame {
    int childNum;
    char unk04[0xC];
    cVec vel;
    cVec spin;
    cVec scale;
    cVec work;
} PieceFrame;

#define PIECEFRAME_OFFSET(field) ((int)&((PieceFrame *)0)->field)

extern float fRand1_1(void);
extern float fRand0_1(void);
extern void Obj0000_Set_Byte_54(char *arg0, int arg1);
extern void Obj0000_Set_Field_50_173998(int *a0, int a1);
extern void ForwardVec3At30_147C60(void *a0, float *a1);
extern void func_00147C88(void *a0, void *a1, int a2);
extern void CopyVec3ToField20_173908(char *a0, float *a1);
extern void CopyVec3ToField30_173938(char *a0, float *a1);
extern void CopyVec3ToField40_173968(char *a0, float *a1);

/* Throws child idx off as piece idx with a jittered velocity and spin. */
__attribute__((section(".text.func_001BE498")))
void func_001BE498(cOmPieces *self, int idx, cVec *vel, cVec *spin)
{
    PieceFrame f;
    cOmBase *child;
    cOmPiece *piece;

    COMBASE_CHILD_FLAGS(cOmBase_childAt(&self->base, &f.childNum, idx)) |= PIECE_FLAG_LOOSE;
    COMBASE_CHILD_FLAGS(cOmBase_childAt(&self->base, &f.childNum, idx)) |= PIECE_FLAG_FLYING;
    VU0_LQC2(4, vel, 0);
    VU0_SQC2(4, &f, PIECEFRAME_OFFSET(vel));
    VU0_LQC2(4, spin, 0);
    VU0_SQC2(4, &f, PIECEFRAME_OFFSET(spin));
    f.vel.x += fRand1_1() * PIECE_JITTER_XZ;
    f.vel.y += fRand0_1() * PIECE_JITTER_Y;
    f.vel.z += fRand1_1() * PIECE_JITTER_XZ;
    f.spin.x += fRand1_1() * PIECE_JITTER_SPIN;
    f.spin.y += fRand1_1() * PIECE_JITTER_SPIN;
    f.spin.z += fRand1_1() * PIECE_JITTER_SPIN;
    child = cOmBase_childAt(&self->base, &f.childNum, idx);
    piece = &self->piece[idx];
    Obj0000_Set_Byte_54((char *)piece, 1);
    Obj0000_Set_Field_50_173998((int *)piece, (int)child->mtx);
    ForwardVec3At30_147C60(piece, child->mtx);
    func_00147C88(&piece->rot, child->mtx, 0);
    CopyVec3ToField20_173908((char *)piece, &f.vel.x);
    CopyVec3ToField30_173938((char *)piece, &f.spin.x);
    cVec_set4(&f.scale, 1.0f, 1.0f, 1.0f, 1.0f);
    CopyVec3ToField40_173968((char *)piece, &f.scale.x);
    piece->gravity = PIECE_GRAVITY;
    cVec_set4(&f.scale, PIECE_SCALE_END, PIECE_SCALE_END, PIECE_SCALE_END, 1.0f);
    VU0_LQC2(4, &f.scale, 0);
    VU0_SQC2(4, &f, PIECEFRAME_OFFSET(work));
    cVec_copy3(&self->piece[idx].scale, &f.work);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001BE498);
#endif

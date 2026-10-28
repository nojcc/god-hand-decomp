#include "include_asm.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"
#include "godhand/cModel.h"

typedef struct cVecQ {
    float x, y, z, w;
} __attribute__((aligned(16))) cVecQ;

extern char D_00463050[];

int ChkLine(void *a0, void *a1, void *a2, void *a3, int a4, int a5, int a6,
            int a7, int a8, int a9, int a10, int a11, int a12);
void MtxInitTransVec(float *mtx, cVec *pos);
void MtxMulRotVec(float *dst, float *src, float *rot, unsigned char order);
void cPlCamera_SetNormalZoomOutMode(void *cam, void *pose, int snap);

#ifdef NON_MATCHING
/* The pos -> to copy is the VU0 lqc2/sqc2 vector-copy macro (inline asm) in retail. */
static inline void cVecQ_init(cVecQ *v)
{
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
    v->w = 1.0f;
}

__attribute__((section(".text.func_0031C5C0")))
void func_0031C5C0(void)
{
    cGameObj *pl = Getplayer();
    cVecQ pos;
    cVecQ to;
    float angle;

    cVecQ_init(&pos);
    D_007474A0.flags5E4 &= ~0x8000;
    pos.x = D_007474A0.startPos[0];
    pos.y = D_007474A0.startPos[1] + 0.2f;
    pos.z = D_007474A0.startPos[2];
    angle = D_007474A0.startAngle;
    D_007474A0.flags598 &= ~0x40;
    if (angle < -3.1415927f && angle > 3.1415927f) {
        angle = 0.0f;
    }
    if (D_007474A0.stage != GAMEWORK_STAGE_NOPLAYER) {
        to = pos;
        to.y -= 5.0f;
        if (ChkLine(&pos, &to, &to, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
            pos.y = to.y;
        }
    }
    pl->pos->x = pos.x;
    pl->pos->y = pos.y;
    pl->pos->z = pos.z;
    pl->rot[1] = angle;
    pl->rot[0] = 0.0f;
    pl->rot[2] = 0.0f;
    pl->posA.x = pos.x;
    pl->posA.y = pos.y;
    pl->posA.z = pos.z;
    pl->mtx[12] = pos.x;
    pl->mtx[13] = pos.y;
    pl->mtx[14] = pos.z;
    ((cVec *)pl->unk000)[3].x = pos.x;
    ((cVec *)pl->unk000)[3].y = pos.y;
    ((cVec *)pl->unk000)[3].z = pos.z;
    MtxInitTransVec(pl->mtx, pl->pos);
    MtxMulRotVec(pl->mtx, pl->mtx, pl->rot, *((unsigned char *)pl + 0x140));
    cModel_calcParts(pl);
    cPlCamera_SetNormalZoomOutMode(D_00463050, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0031C5C0);
#endif

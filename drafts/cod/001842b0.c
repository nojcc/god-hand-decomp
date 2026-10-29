/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/cOl40.h"
#include "godhand/cGameObj.h"
#include "godhand/cModel.h"
#include "godhand/cCamera.h"
#include "godhand/cEmManage.h"
#include "godhand/player.h"
#include "godhand/objField.h"
#include "godhand/mtx.h"
#include "godhand/cVec.h"

extern unsigned char cOl40_isDead(unsigned char *a0);
extern void func_001846D8(void *self);
extern int Dest_ck(float *from, float *to, float cur, float max);
extern void func_001B7EE0(void *a0, float fp12);
extern void func_00184A40(void *a0);
extern void func_00184B60(void *a0);
extern void func_00184CE0(void *a0);
extern void func_00184E60(void *a0);
extern void func_00184FE0(void *a0);
extern void func_001850B0(void *a0);
extern void func_00185180(unsigned char *self);
extern int GetField_54_173900(void *a0);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);
extern void MtxInitRotVec(void *a0, float *a1, unsigned char order);
extern void MtxMulScaleVec(int a0, int a1, int a2);

#define OL40_GETPOS(o)  CVCALL_FN(o, 16, cVec *(*)(char *))(CVCALL_THIS(o, 16))
#define OL40_GETROT(o)  CVCALL_FN(o, 17, cVec *(*)(char *))(CVCALL_THIS(o, 17))

/* Per-frame update: while standing, the side facing the player (within 45
 * degrees of front, back or either flank) that isn't broken yet plays
 * func_001B7EE0; then the break steps run, or the final break once all six
 * sides are down, and every loose piece moves, spins and falls until it
 * drops below -1000.
 * Still differs from retail: the player's lock-on call keeps the player in
 * a1 instead of v0, and the piece loop holds the matrix address in a saved
 * register where retail holds the constants 1 and -1000. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_001842B0")))
void func_001842B0(cOl40 *self)
{
    CVEC_TEMPS;
    float m[16];
    unsigned int i;

    if (cOl40_isDead((unsigned char *)self) == 0) {
        float front;
        float right;
        float left;
        cGameObj *pl;
        float *from;

        func_001846D8(self);
        func_00186398(self);
        front = Adjust_theta(OL40_GETROT(&self->base)->y + 0.0f);
        right = Adjust_theta(OL40_GETROT(&self->base)->y + 1.5707964f);
        left = Adjust_theta(OL40_GETROT(&self->base)->y + -1.5707964f);
        from = &OL40_GETPOS(&self->base)->x;
        pl = Getplayer();
        if (Dest_ck(from, &((cVec *(*)(void *))cGameObj_vt(pl)->lockOn)((char *)pl + cGameObj_vt(pl)->lockOnDelta)->x, front, 0.7853982f) != 0) {
            if (self->broken[0] == 0) {
                func_001B7EE0(self, 3.5f);
            }
        } else {
            from = &OL40_GETPOS(&self->base)->x;
            pl = Getplayer();
            if (Dest_ck(from, &((cVec *(*)(void *))cGameObj_vt(pl)->lockOn)((char *)pl + cGameObj_vt(pl)->lockOnDelta)->x, right, 0.7853982f) != 0) {
                if (self->broken[3] == 0) {
                    func_001B7EE0(self, 3.5f);
                }
            } else {
                from = &OL40_GETPOS(&self->base)->x;
                pl = Getplayer();
                    if (Dest_ck(from, &((cVec *(*)(void *))cGameObj_vt(pl)->lockOn)((char *)pl + cGameObj_vt(pl)->lockOnDelta)->x, left, 0.7853982f) != 0) {
                    if (self->broken[2] == 0) {
                        func_001B7EE0(self, 3.5f);
                    }
                } else if (self->broken[1] == 0) {
                    func_001B7EE0(self, 3.5f);
                }
            }
        }
    }
    if (self->broken[0] == 0 || self->broken[1] == 0 || self->broken[2] == 0 ||
        self->broken[3] == 0 || self->broken[4] == 0 || self->broken[5] == 0) {
        func_00184A40(self);
        func_00184B60(self);
        func_00184CE0(self);
        func_00184E60(self);
        func_00184FE0(self);
        func_001850B0(self);
    } else {
        func_00185180((unsigned char *)self);
    }
    for (i = 0; i < 20; i++) {
        cOl40Piece *p = &self->piece[i];

        if (GetField_54_173900(p) == 1) {
            float rate = cEmManage_GetSpeedRate(&D_005864F0);

            CVEC_INIT_MUL(ret_, &p->vel, rate);
            CVEC_ADD_TO(p->pos, &ret_);
            CVEC_INIT_MUL(ret_, &p->rotVel, rate);
            CVEC_ADD_TO(p->rot, &ret_);
            Adjust_theta_vec(&p->rot);
            MtxInitRotVec(m, &p->rot.x, 0);
            CopyVec3ToField30_147C40(m, &p->pos.x);
            MtxMulScaleVec((int)m, (int)m, (int)&p->scale);
            MtxCopy(p->mtx, m);
            p->vel.y += p->gravity * rate;
            if (p->vel.y < -1000.0f) {
                Obj0000_Set_Byte_54(p, 0);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001842B0);
#endif

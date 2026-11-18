/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"

/* sn-2.95.3-136 */

extern void SetMotionStep(void *a0, float f12);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void ForwardAnimParamPairByIndex_27EA50(void *a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern float fRand1_1(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern char D_00462FC0[];

#include "godhand/vu0.h"
#include "godhand/motion.h"
#include "godhand/player.h"

/* Held-by-player phase of an enemy, stepped on its 0x2F6 sub-phase (0 to 5).
 * The enemy copies the player's motion step, plays three motion pairs from
 * its motion table (0x39A0, 0x39A8, 0x39B0) and rides the player's position
 * delta at 0x550; the last phase spawns effect 0x4F on a part, fires the
 * vtable hit at 0xA8 with damage 20 * the charge at 0x600, adds heat and
 * hands control back with phase 1/4/2. */
__attribute__((section(".text.cEm_heldByPlayerPhase")))
void cEm_heldByPlayerPhase(cEm00 *self)
{
    char *s2;
    unsigned char frame[0x10];
    float buf[4];
    void *m1;
    unsigned char *m2;

    s2 = (char *)Getplayer();
    {
        float v = *(float *)(s2 + 0x5A8);

        self->speedRate = v;
        SetMotionStep(self, v);
    }
    self->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
    switch (self->step) {
    case 0:
    {
        char *p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x39A0), EM_RES_REC(p, 0x39A4),
                      0, 0.0f, 0, 0);
        if (self->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x19);
        }
        self->unk16EC = 0;
        self->unk56A = 0;
        (self->step)++;
    }
        /* fallthrough */
    case 1:
    {
        char *q;
        cVec *p;

        q = s2 + 0x550;
        p = self->pos;
        VU0_LQC2(4, p, 0);
        VU0_LQC2(5, q, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, p, 0);
    }
        if (moveMotion(self) != 0) {
            (self->step)++;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
    {
        char *p;
        float z = 0.0f;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x39A8), EM_RES_REC(p, 0x39AC),
                      0, z, 0, 0);
        if (self->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x1A);
        }
        self->timerA = 1;
        self->timer = z;
        (self->step)++;
    }
        /* fallthrough */
    case 3:
    {
        cVec *p;
        char *q;

        p = self->pos;
        q = s2 + 0x550;
        VU0_VADD_XYZ_IP(p, 0, q);
    }
        if (moveMotion(self) != 0) {
            self->timer = self->timer + 1.0f;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        self->step = *(unsigned char *)(s2 + 0x2F6);
        break;
    case 4:
    {
        char *p;

        ReleaseField6ECByTag564_26B1E8(self);
        p = self->pack;
        func_002A8578(self, EM_RES_REC(p, 0x39B0), EM_RES_REC(p, 0x39B4),
                      0, 0.0f, 0, 0);
        if (self->unk744 != 0) {
            ForwardAnimParamPairByIndex_27EA50(self->unk744, 0x1B);
        }
        self->timerA = 1;
        self->unk56E = 0xF;
        (self->step)++;
    }
        /* fallthrough */
    case 5:
        if (self->unk56E != 0) {
            cVec *p;
            char *q;

            (self->unk56E)--;
            p = self->pos;
            q = s2 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(self) != 0) {
            cOmBase *s1 = cOmBase_childAt((cOmBase *)self, (int *)frame, 4);
            cGameObjVt *vt;

            if (s1 != 0) {
                VU0_SQC2_VF0(frame, 0x10);
                buf[0] = fRand1_1() * 0.1f;
                buf[1] = fRand1_1() * 0.1f + 0.1f;
                buf[2] = fRand0_1() * 0.1f + 0.2f;
                /* One pointer local per call, cleared after it: retail recomputes
                 * $sp+0x10 at each call instead of holding it in a saved register. */
                m1 = (void *)buf;
                sceVu0ApplyMatrix(m1, s1->mtx, m1);
                m1 = 0;
                m2 = frame + 0x10;
                SetEffectPos(0, 0x4F, 0, m2, -1, 1.0f);
                m2 = 0;
            }
            vt = cGameObj_vt((cGameObj *)self);
            vt->unkAC((char *)self + vt->unkA8Delta,
               (int)(self->timer * 20.0f), s2, 0, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, self->timer);
            self->mode = 1;
            self->phase = 4;
            self->stepArg = 2;
            self->step = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    default:
        break;
    }
}

#include "godhand/cCollisionSolid.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_00262750(void *a0, int a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */










#include "godhand/vu0.h"

#define FRAME ((char *)va - 0x30)

/* Phase machine on the step byte, 53 case labels. Calls VU0_SQC2_VF0,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, cCollisionSolidManage_SetPriority, func_002A8578,
 * func_00262750, VU0_LQC2 and 9 more. */
__attribute__((section(".text.func_0025ADC0"))) void func_0025ADC0(cEm00 *self)
{
    float va[4], vb[4], vc[4], vd[4];
    VU0_SQC2_VF0(FRAME, 0x30);
    self->unk617 = 1;
    switch (self->step) {
        case 0: {
            int gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int s2v, s0v;

            switch (self->emNo) {
                default: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x124);
                    s0v = EM_RES_REC(b, 0x128);
                } break;
                case 0x20a:
                case 0x20b:
                case 0x20c:
                case 0x20d:
                case 0x20e:
                case 0x218:
                case 0x245:
                case 0x246:
                case 0x247:
                case 0x24f:
                case 0x278:
                case 0x279: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x89c);
                    s0v = EM_RES_REC(b, 0x8a0);
                } break;
                case 0x250:
                case 0x251: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x89c);
                    s0v = EM_RES_REC(b, 0x8a0);
                } break;
                case 0x260: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x89c);
                    s0v = EM_RES_REC(b, 0x8a0);
                } break;
                case 0x214:
                case 0x215:
                case 0x21a:
                case 0x21b:
                case 0x21c:
                case 0x21d:
                case 0x21e:
                case 0x225:
                case 0x22c:
                case 0x22d:
                case 0x22e:
                case 0x22f:
                case 0x248:
                case 0x249:
                case 0x24c:
                case 0x24d:
                case 0x24e:
                case 0x252:
                case 0x25a: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x112c);
                    s0v = EM_RES_REC(b, 0x1130);
                } break;
                case 0x20f:
                case 0x210:
                case 0x211:
                case 0x226:
                case 0x270:
                case 0x271:
                case 0x272:
                case 0x273:
                case 0x274: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x124);
                    s0v = EM_RES_REC(b, 0x128);
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x209:
                case 0x21f:
                case 0x224:
                case 0x241: {
                    char *b = self->pack;
                    s2v = EM_RES_REC(b, 0x15d4);
                    s0v = EM_RES_REC(b, 0x15d8);
                } break;
            }
            cCollisionSolidManage_SetPriority(&D_00462FC0, (struct cGameObj *)self, 5);
            func_002A8578(self, s2v, s0v, 3, 0.0f, gb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 1: {
            cVec *p;
            float *dp;
            float *pd;
            float k;
            int f;

            self->hitFlash = 3.0f;
            self->emFlags |= 0x1000;
            func_00262750(self, 4);
            f = self->emFlags;
            f |= 0x10000;
            f |= 0x20000;
            self->emFlags = f;
            pd = vd;
            k = 0.1f;

            VU0_LQC2(4, &self->unk580, 0);
            VU0_SQC2(4, FRAME, 0x60);
            VU0_LQC2(4, FRAME, 0x60);
            VU0_LOAD_SCALAR(5, k);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, FRAME, 0x60);

            VU0_LQC2(4, pd, 0);
            VU0_SQC2(4, FRAME, 0x50);
            k = self->speedRate;
            VU0_LQC2(4, vc, 0);
            VU0_SQC2(4, FRAME, 0x60);
            VU0_LQC2(4, FRAME, 0x60);
            VU0_LOAD_SCALAR(5, k);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, FRAME, 0x60);
            VU0_LQC2(4, pd, 0);
            VU0_SQC2(4, FRAME, 0x40);

            dp = va;
            if (dp != vb) {
                float t0, t1, t2;
                t0 = vb[0];
                t1 = vb[1];
                dp[0] = t0;
                *(float *)&dp[1] = t1;
                t2 = *(float *)&vb[2];
                dp[2] = t2;
            }
            p = self->pos;
            VU0_VADD_XYZ_IP(p, 0, dp);
            VU0_LQC2(4, self, 0x580);
            VU0_LQC2(5, dp, 0);
            VU0_VSUB_XYZ(4, 4, 5);
            VU0_SQC2(4, self, 0x580);

            if (moveMotion(self) != 0) {
                self->hp = 0;
                self->mode = 2;
                self->phase = 2;
                self->stepArg = 1;
                self->step = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->seqFlags & 0x10) {
                float *q;
                int r;

                VU0_SQC2_VF0(FRAME, 0x40);
                VU0_SQC2_VF0(FRAME, 0x50);
                VU0_SQC2_VF0(FRAME, 0x60);
                q = &self->posA.x;
                if (vb != q) {
                    vb[0] = q[0];
                    vb[1] = q[1];
                    vb[2] = q[2];
                }
                q = &self->pos->x;
                if (vc != q) {
                    vc[0] = q[0];
                    vc[1] = q[1];
                    vc[2] = q[2];
                }
                vb[1] = vb[1] + 0.5f;
                r = ChkLine(vb, vc, pd, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1);
                if (r == 1) {
                    cVec *fp = self->pos;
                    cGameObjVt *vt;
                    short ofs;

                    fp->y = vd[1];
                    vt = cGameObj_vt((cGameObj *)self);
                    ofs = vt->unkA8Delta;
                    vt->unkAC((char *)self + ofs, 0x32, 0, 0, 0);
                    self->mode = r;
                    self->phase = 8;
                    self->step = 2;
                    self->stepArg = 0;
                }
            }
            break;
        }
    }
}

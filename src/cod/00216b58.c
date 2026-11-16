/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"
#include "godhand/angle.h"
#include "godhand/cCamera.h"
#include "godhand/motion.h"
#include "godhand/cOmWeapon.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern unsigned int irand(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_0026B4E8(void *a0);

/* sn-2.95.3-136 matched TU. */


















/* Phase machine on the step byte, 11 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cCoreSave_getGameLevel, func_002A8578, Getplayer, Turn_dest, Adjust_theta and 9 more. */
__attribute__((section(".text.func_00216B58"))) void func_00216B58(cEm00 *self)
{
    int gb;
    int s2v, s0v;
    int t;

    switch (self->step) {
        case 0: {
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            t = self->emNo;
            if (t == 0x21E)
                goto a0_hit;
            if (t <= 0x21E)
                goto a0_def;
            if (t == 0x22F)
                goto a0_hit;
        a0_def:
            {
                char *v0 = self->pack;
                s2v = EM_RES_REC((int)v0, 0x1E68);
                s0v = EM_RES_REC((int)v0, 0x1E6C);
            }
            goto a0_end;
        a0_hit:
            {
                char *v1 = self->pack;
                s2v = EM_RES_REC((int)v1, 0x1518);
                s0v = EM_RES_REC((int)v1, 0x151C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    char *w = self->pack;
                    s0v = EM_RES_REC((int)w, 0x1520);
                }
            }
        a0_end:
            func_002A8578(self, s2v, s0v, 3, 0.0f, gb, 0);
            self->timerA = 0xA;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    self->timerA = (int)((float)self->timerA * 0.75f);
                    break;
                case 2:
                    self->timerA = (int)((float)self->timerA * 0.8f);
                    break;
                case 3:
                case 4:
                    self->timerA = (int)((float)self->timerA * 0.9f);
                    break;
                case 5:
                    break;
            }
            self->timerB = 1;
            self->timer = self->rot.y;
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            if ((self->seqFlags & 0x10) != 0) {
                self->emFlags = self->emFlags | 0x80000000;
            }
            if (self->timerA != 0) {
                cVec *pos;
                cGameObj *pl;
                float th;

                self->timerA -= 1;
                pos = self->pos;
                pl = Getplayer();
                th = Turn_dest(&pos->x, &pl->pos->x, self->timer,
                               self->speedRate * 0.3926991f);
                self->timer += th;
                self->timer = Adjust_theta(self->timer);
                self->rot.y += th;
                self->rot.y = Adjust_theta(self->rot.y);
            }
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            self->unk17D0 = irand() % 5;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            t = self->emNo;
            if (t == 0x21E)
                goto a2_hit;
            if (t <= 0x21E)
                goto a2_def;
            if (t == 0x22F)
                goto a2_hit;
        a2_def:
            {
                char *v0 = self->pack;
                s2v = EM_RES_REC((int)v0, 0x1560);
                s0v = EM_RES_REC((int)v0, 0x1564);
            }
            goto a2_end;
        a2_hit:
            {
                char *v0 = self->pack;
                s2v = EM_RES_REC((int)v0, 0x10A8);
                s0v = EM_RES_REC((int)v0, 0x10AC);
            }
        a2_end:
            func_002A8578(self, s2v, s0v, 3, 0.0f, gb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 3: {
            cOmWeapon *p;

            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            p = self->fx4;
            if (p != 0 &&
                capVu0MagnitudeSqXZ(p->base.pos, self->pos) < 2.25f) {
                self->step += 1;
            } else {
                func_00262AA8(self);
            }
            break;
        }
        case 4: {
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            t = self->emNo;
            if (t == 0x21E)
                goto a4_hit;
            if (t <= 0x21E)
                goto a4_def;
            if (t == 0x22F)
                goto a4_hit;
        a4_def:
            {
                char *v0;
                self->hitFlash = 10.0f;
                v0 = self->pack;
                s2v = EM_RES_REC((int)v0, 0x15A4);
                s0v = EM_RES_REC((int)v0, 0x15A8);
                SetOrientByType_26AF20((cOmBase *)self, self->fx4, 1);
            }
            goto a4_end;
        a4_hit:
            {
                char *v0 = self->pack;
                s2v = EM_RES_REC((int)v0, 0x1524);
                s0v = EM_RES_REC((int)v0, 0x1528);
                SetOrientByType_26AF20((cOmBase *)self, self->fx4, 3);
            }
        a4_end:
            self->emFlags = self->emFlags | 0x80000000;
            func_002A8578(self, s2v, s0v, 3, 0.0f, gb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 5: {
            t = self->emNo;
            if (t == 0x21E)
                goto a5_ck;
            if (t <= 0x21E)
                goto a5_set;
            if (t != 0x22F)
                goto a5_set;
        a5_ck:
            if ((self->seqFlags & 0x10) == 0)
                goto a5_done;
        a5_set:
            self->emFlags = self->emFlags | 0x80000000;
        a5_done:
            if (moveMotion(self) != 0) {
                t = self->emNo;
                if (t == 0x21E)
                    goto a6_hit;
                if (t <= 0x21E)
                    goto a6_def;
                if (t == 0x22F)
                    goto a6_hit;
            a6_def:
                SetOrientByType_26AF20((cOmBase *)self, self->fx4, 0);
                goto a6_end;
            a6_hit:
                SetOrientByType_26AF20((cOmBase *)self, self->fx4, 2);
            a6_end:
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
    }
    if ((self->seqFlags & 1) != 0) {
        if (self->timerB != 0) {
            self->timerB = 0;
            func_0026B4E8(self);
        }
    }
}

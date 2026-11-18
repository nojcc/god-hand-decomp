#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/player.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002495E0(void *a0, float f);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern float Adjust_theta(float f12);
extern int cEmManage_CkPlCatched(void *a0);
extern char D_005864F0[];

/* Phase machine on the step byte, 4 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, cGameObj_startPhase3, func_002831C8, moveMotion, cObjBase_addNullSpeed_Rotation and 3
 * more. */
__attribute__((section(".text.func_0024A518"))) void func_0024A518(cEm00 *self)
{
    int t0, b;
    float one;
    float f;

    self->emFlags = self->emFlags | 0x30400;
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x3D7C), EM_RES_REC(b, 0x3D80), 10, 0.0f, t0, 0);
            if (self->sub0 != 0) {
                cGameObj_startPhase3(self->sub0, 1, 0);
            }
            if (self->sub1 != 0) {
                func_002831C8(self->sub1, 1, 0);
            }
            self->step++;
        case 1:
            one = 1.0f;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (*(float *)((char *)self + 0x176C) <= 0.0f) {
                self->step++;
            }
            break;
        case 2:
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x3D84), EM_RES_REC(b, 0x3D88), 10, 0.0f, t0, 0);
            if (self->sub0 != 0) {
                cGameObj_startPhase3(self->sub0, 2, 0);
            }
            if (self->sub1 != 0) {
                func_002831C8(self->sub1, 2, 0);
            }
            self->timer = 30.0f;
            self->step++;
        case 3:
            f = self->timer;
            if (0.0f < f) {
                self->timer = f - self->speedRate;
            } else {
                self->emFlags = self->emFlags & 0xFEFFFFFF;
            }
            func_002495E0(self, 0.0f);
            self->emFlags = self->emFlags | 0x800000;
            if (moveMotion(self) != 0) {
                self->emFlags = self->emFlags & 0xFEFFFFFF;
                func_002705D8(self);
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
}

/* Phase machine on the step byte, 4 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, Getplayer, Turn_dest, Turn_dest_dir, Adjust_theta and 7 more. */
__attribute__((section(".text.func_0022AF90"))) void func_0022AF90(cEm00 *self)
{
    char *v0;
    cVec *pos;
    cVec *s2;
    int gb, b;
    float one;
    float th, d, ad, f, g;

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->step) {
        case 0:
            self->emFlags = (self->emFlags | 2) & 0xFFFF7FFF;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0xCF8), EM_RES_REC(b, 0xCFC), 10, 0.0f, gb, 0);
            self->timerC = 0;
            self->step = self->step + 1;
        case 1:
            pos = self->pos;
            v0 = (char *)Getplayer();
            one = 1.0f;
            th = Turn_dest(pos, *(void **)(v0 + 0xF0), *(float *)((char *)self + 0x1670), 0.5235988f);
            d = Turn_dest_dir(self->rot.y, Adjust_theta(th + *(float *)((char *)self + 0x1670)),
                              self->speedRate * 0.19634955f);
            self->rot.y = self->rot.y + d;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (*(short *)((char *)Getplayer() + 0x54A) <= 0) {
                return;
            }
            if (cEmManage_CkPlCatched(D_005864F0) != 0) {
                return;
            }
            f = self->playerDist;
            if (9.0f < f && f < 400.0f && *(float *)((char *)self + 0x1714) <= 0.0f) {
                s2 = self->pos;
                v0 = (char *)Getplayer();
                d = Turn_dest(s2, *(void **)(v0 + 0xF0), self->rot.y, 3.14159274f);
                if (d < 0.0f) {
                    f = -d;
                    ad = f;
                } else {
                    ad = d;
                }
                if (ad < 0.26179940f) {
                    self->step = self->step + 1;
                }
            }
            if (self->playerDist < 25.0f) {
                v0 = (char *)Getplayer();
                d = self->pos->y - *(float *)(*(char **)(v0 + 0xF0) + 4);
                if (d < 0.0f) {
                    f = -d;
                    ad = f;
                } else {
                    ad = d;
                }
                if (ad < 0.5f) {
                    func_002705D8(self);
                }
            }
            break;
        case 2:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0xDBC), EM_RES_REC(b, 0xDC0), 10, 0.0f, gb, 0);
            self->timerA = 0x64;
            self->step = self->step + 1;
        case 3:
            if (moveMotion(self) != 0) {
                self->step = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (self->seqFlags & 1) {
                if (self->unk17C3 != 0) {
                    func_0026A638(self, 1);
                } else {
                    func_0026A638(self, 0);
                }
            }
            if (self->seqFlags & 2) {
                func_0026A838(self, 0);
                func_0026A838(self, 1);
            }
            break;
    }
    if (self->seqFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 = self->emFlags2 & 0xFFFFFBFF;
    }
}

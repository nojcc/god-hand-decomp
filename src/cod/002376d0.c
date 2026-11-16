/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"

extern int Getplayer(void);
extern unsigned int irand(void);
extern void func_00274FE8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002376C0(void);
extern char D_00568288[];
extern int D_007474A8;

extern void cActionButton_set(void *a0, int a1, int a2,
                                                       int a3, void *t0, void *t1,
                                                       int t2);






__attribute__((section(".text.func_002376D0")))
void func_002376D0(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->emFlags |= 0x21000;
    self->hitFlash = 3.0f;
    switch (self->step) {
    case 0: {
        int w = (int)self->pack;
        self->unk1864 = 0;
        func_002A8578(self, *(int *)(w + 0x20FC) + w, *(int *)(w + 0x2100) + w,
                      0, 0.0f, 0, 0);
        self->unk568 = 0;
        self->unk56E = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            self->unk56A = 0x39;
            break;
        case 2:
            self->unk56A = 0x3E;
            break;
        case 3:
            self->unk56A = 0x43;
            break;
        case 4:
            self->unk56A = 0x43;
            break;
        case 5:
            self->unk56A = 0x48;
            break;
        }
        self->unk56C = irand() & 3;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 1:
        if (moveMotion(self)) {
            func_00274FE8(self);
            return;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->unk56A != 0) {
            self->unk56A = self->unk56A - 1;
        } else if (*(short *)(s1 + 0x54A) > 0 && self->unk568 == 0) {
            switch (self->unk56C) {
            default:
            case 0:
                if ((D_007474A8 & 0xD0) != 0)
                    self->unk56A = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           0, func_002376C0, self, 0);
                break;
            case 1:
                if ((D_007474A8 & 0xE0) != 0)
                    self->unk56A = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           1, func_002376C0, self, 0);
                break;
            case 2:
                if ((D_007474A8 & 0xB0) != 0)
                    self->unk56A = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           2, func_002376C0, self, 0);
                break;
            case 3:
                if ((D_007474A8 & 0x70) != 0)
                    self->unk56A = 0;
                cActionButton_set(D_00568288, 0xB, 0x25,
                                                           3, func_002376C0, self, 0);
                break;
            }
        }
        if (self->seqFlags & 0x10) {
            self->unk56A = 0x3E7;
            if (self->unk568 == 0 || *(short *)(s1 + 0x54A) <= 0) {
                *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
                self->step = self->step + 1;
            }
        }
        if (self->seqFlags & 1) {
            cGameObjVt *vt = cGameObj_vt((cGameObj *)self);
            short off = vt->unkA8Delta;
            vt->unkAC((char *)self + off, 0x32, 0, 0, 0);
            if (self->hp <= 0)
                self->hp = 1;
        }
        break;
    case 2: {
        int w = (int)self->pack;
        self->unk1864 = 0;
        func_002A8578(self, *(int *)(w + 0x2104) + w, *(int *)(w + 0x2108) + w,
                      0, 0.0f, 0, 0);
        self->unk56E = 0x3C;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(self)) {
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    default:
        break;
    }
}

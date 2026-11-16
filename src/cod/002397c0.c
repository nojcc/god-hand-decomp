/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"

extern int Getplayer(void);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
extern void func_002DB770(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_007474A0[];

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"














__attribute__((section(".text.func_002397C0")))
void func_002397C0(cEm00 *self)
{
    char *s1 = (char *)Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
    case 0: {
        char *w = self->pack;
        self->unk1864 = 0;
        func_002A8578(self, EM_RES_REC(w, 0x3C44), EM_RES_REC(w, 0x3C48),
                      0, 0.0f, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            self->unk568 = 0xF;
            break;
        case 2:
            self->unk568 = 0x14;
            break;
        case 3:
        case 4:
            self->unk568 = 0x19;
            break;
        case 5:
            self->unk568 = 0x1E;
            break;
        }
        self->unk56A = 4;
        self->unk56E = 0xF;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 1:
        if (self->unk56E != 0) {
            char *q = s1 + 0x550;
            cVec *p;
            self->unk56E = self->unk56E - 1;
            p = self->pos;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        self->hitFlash = 3.0f;
        if (moveMotion(self))
            self->step = self->step + 1;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2: {
        char *w = self->pack;
        self->unk1864 = 0;
        func_002A8578(self, EM_RES_REC(w, 0x3C4C), EM_RES_REC(w, 0x3C50),
                      0, 0.0f, 0, 0);
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 3:
    {
        char *g;
        func_002DB770();
        g = D_007474A0;
        if (*(int *)(g + 8) & 0xF0)
            self->unk568 = self->unk568 - 1;
        if (*(int *)(g + 8) & 0xF00000)
            self->unk568 = self->unk568 - 4;
    }
        self->hitFlash = 3.0f;
        if (moveMotion(self)) {
            if (self->unk568 <= 0) {
                self->step = 6;
                *(unsigned char *)(s1 + 0x2F6) = 6;
            }
            if (--self->unk56A <= 0) {
                self->step = 4;
                *(unsigned char *)(s1 + 0x2F6) = 4;
            }
            if (*(short *)(s1 + 0x54A) <= 0) {
                self->step = 4;
                *(unsigned char *)(s1 + 0x2F6) = 4;
            }
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 4: {
        char *w = self->pack;
        self->unk1864 = 0;
        func_002A8578(self, EM_RES_REC(w, 0x3C54), EM_RES_REC(w, 0x3C58),
                      3, 0.0f, 0, 0);
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 5:
        self->hitFlash = 3.0f;
        if (moveMotion(self)) {
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 6: {
        char *w = self->pack;
        func_002A8578(self, EM_RES_REC(w, 0x3C5C), EM_RES_REC(w, 0x3C60),
                      3, 0.0f, 0, 0);
        self->timerA = 1;
        self->hitFlash = 5.0f;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 7:
        if (moveMotion(self))
            func_002705D8(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->seqFlags & 1) {
            if (self->timerA != 0) {
                cGameObjVt *vt = cGameObj_vt((cGameObj *)self);
                short off;
                self->timerA = 0;
                off = vt->unkA8Delta;
                vt->unkAC((char *)self + off, 0xA, s1, 1, 0);
                if (self->hp <= 0)
                    self->hp = 1;
            }
        }
        break;
    default:
        break;
    }
}

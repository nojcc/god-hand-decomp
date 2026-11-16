/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/motion.h"

extern char *Getplayer(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_002DB770(void);
extern void KillEffect(void *a0, int a1, int a2);
extern char D_007474A0[];

__attribute__((section(".text.func_00238F10")))
void func_00238F10(cEm00 *self)
{
    int one = 1;
    char *s2 = Getplayer();

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
    case 0: {
        char *p = self->pack;

        self->unk1864 = 0;
        func_002A8578(self, EM_RES_REC(p, 0x39DC), EM_RES_REC(p, 0x39E0),
                      0, 0.0f, 0, 0);
        self->unk56E = 0xF;
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
        self->unk56A = 0;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 1:
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0x6C;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->unk56A != 0) {
            (self->unk56A)--;
        } else {
            char *g;

            func_002DB770();
            g = D_007474A0;
            if (*(int *)(g + 8) & 0xF0)
                (self->unk568)--;
            if (*(int *)(g + 8) & 0xF00000)
                self->unk568 -= 4;
        }
        if (self->seqFlags & 0x10) {
            if (self->unk568 <= 0) {
                *(unsigned char *)(s2 + 0x2F6) = 2;
                self->step = 2;
            }
            self->unk56A = 0x3E7;
        }
        break;
    case 2: {
        char *p = self->pack;

        self->unk1864 = 0;
        func_002A8578(self, EM_RES_REC(p, 0x39E4), EM_RES_REC(p, 0x39E8),
                      0, 0.0f, 0, 0);
        self->emFlags2 &= 0xDFFFFFFFU;
        KillEffect(self, 1, 2);
        self->unk568 = one;
        self->unk56E = 0xF;
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(self) != 0) {
            if (self->hp < 2) {
                self->mode = 2;
                self->hp = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
                return;
            }
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->seqFlags & 1) {
            if (self->unk568 != 0) {
                cGameObjVt *vt = cGameObj_vt((cGameObj *)self);

                vt->unkAC((char *)self + vt->unkA8Delta, 0x32, 0, 0, 0);
                if (self->hp <= 0)
                    self->hp = 1;
                self->unk568 = 0;
            }
        } else {
            self->unk568 = 1;
        }
        break;
    default:
        break;
    }
}

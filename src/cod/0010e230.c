/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00.h"
#include "godhand/capVu0.h"
#include "godhand/motion.h"

/* L1 w34 parked: 216/225 EXACT, insn delta -1, needs --assembler sn (ps2eeas supplies the mtc1 nop at .L0010E2EC). Residue: flag copy daddu $a0,$v0 (R allocated $v0 here), beqzl for beqz at 0x0010E334 (follows the flag register), mov.s $f12 placement before the func_002A8578 call. Edits this wave: int one = 1 hoisted, extern int func_00124540, stores 15C4/15B0 first. */
/* func_0010E230 — 0x0010E230, 900 B — sn-2.95.3-136. */

extern float capVu0MagnitudeXZ(void *a0, void *a1);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0010A438(void *a0);


static __inline__ long InMidRange(unsigned short k, int lo, int hi)
{
    long c;
    int t;
    c = 0;
    if (k >= lo) {
        t = (k < hi);
        c = t;
    }
    return c;
}

__attribute__((section(".text.func_0010E230")))
void func_0010E230(pl00 *self)
{
    int one = 1;

    self->flags15F4 |= 0x40000;
    if (self->base.hp <= 0)
        self->base.hp = one;
    switch (self->base.step) {
    case 0: {
        cGameObj *o;
        char *w;


        o = self->held;
        self->unk1588 = 0.0f;
        if (o != 0) {
            cGameObjVt *vt;
            cVec *(*fp)(void *self);
            cVec *p;
            float d;
            float lim;

            vt = cGameObj_vt(o);
            p = self->base.pos;
            fp = vt->getPos;
            d = capVu0MagnitudeXZ(p, fp((char *)o + vt->getPosDelta));
            d = d - 1.2f;
            lim = 0.5f;
            if (self->comboSlot == 0
                && self->unk61F != 0)
                lim = 1.0f;
            if (lim < d)
                d = lim;
            if (0.0f < d)
                self->unk1588 = d * 0.2f;
        if (self->held != 0) {
            unsigned short k = self->held->actorId;
            if (InMidRange(k, 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(&D_00569B70, 0x14);
        }
        }
        func_00124540(self, 0);
        self->comboSlot = 0;
        self->comboSet = 0;
        if (self->unk648 > 0)
            self->unk648 = 0x2D;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self,
            (int)(self->unk600 * 8.0f), 2, 0x18, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self,
            (int)(self->unk600 * 8.0f), 2, 0x18, 0, 0xA);
        w = self->base.pack;
        func_002A8578(self, EM_RES_REC(w, 0x1AC), EM_RES_REC(w, 0x1B4),
                      3, 0.0f, 0, 0);
        self->unk15C4 = 0.0f;
        self->unk15B0 = 1;
        self->stepScale = 1.0f;
        self->unk15B8 = 1;
        self->unk1588 = 0.0f;
        self->base.unk568 = 0x32;
        self->unk1603 = 2;
        self->base.step = self->base.step + 1;
        self->stepCount = 0;
    }
    /* fallthrough */
    case 1: {
        cGameObj *o;
        float acc;

        if (self->base.unk568 != 0) {
            self->base.unk568 = self->base.unk568 - 1;
            InvokeVirtualAtField214AndForward_124E68(self, 0.19634954f);
        }
        if ((self->base.seqFlags & 0x10) == 0)
            self->unk1603 = 2;
        if (self->held != 0)
            self->unk648 = 0x14;
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        o = self->held;
        if (o != 0) {
            cGameObjVt *vt;
            cVec *(*fp)(void *self);
            cVec *p;

            vt = cGameObj_vt(o);
            p = self->base.pos;
            fp = vt->getPos;
            if (capVu0MagnitudeSqXZ(p, fp((char *)o + vt->getPosDelta)) < 1.21f) {
                self->base.nullSpeed.x = 0.0f;
                self->base.nullSpeed.z = 0.0f;
            }
        }
        acc = self->unk1588;
        self->base.nullSpeed.z = self->base.nullSpeed.z + acc;
        self->unk1588 = acc * 0.9f;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    default:
        break;
    }
    func_0010A438(self);
    if (func_00123938(self, 1) != 0)
        pl00_clearMotionCam(self, 1, 0);
}

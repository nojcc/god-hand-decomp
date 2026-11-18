#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* sn-2.95.3-136 candidate. */











/* Phase machine on the step byte, 31 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, cSnd_SeCall_2CBA48, GetSeqSEBase, moveMotion, func_002705D8 and 2 more. */
__attribute__((section(".text.func_002311A8"))) void func_002311A8(cEm00 *self)
{

    switch (self->step) {
        case 0: {
            int t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int o1;
            int o2;

            switch (self->emNo) {
                default: {
                    int b = EM_RES(self);

                    o1 = EM_RES_REC(b, 0x1C0);
                    o2 = EM_RES_REC(b, 0x1C4);
                } break;
                case 0x20A:
                case 0x20B:
                case 0x20C:
                case 0x20D:
                case 0x20E:
                case 0x218:
                case 0x245:
                case 0x246:
                case 0x247:
                case 0x24F:
                case 0x278:
                case 0x279: {
                    int b = EM_RES(self);

                    o1 = EM_RES_REC(b, 0x948);
                    o2 = EM_RES_REC(b, 0x94C);
                } break;
                case 0x21A:
                case 0x21B:
                case 0x21C:
                case 0x21D:
                case 0x21E:
                case 0x225:
                case 0x22C:
                case 0x22D:
                case 0x22E:
                case 0x22F:
                case 0x248:
                case 0x249:
                case 0x24C:
                case 0x24D:
                case 0x24E:
                case 0x252:
                case 0x25A: {
                    int b = EM_RES(self);

                    o1 = EM_RES_REC(b, 0x11A0);
                    o2 = EM_RES_REC(b, 0x11A4);
                } break;
            }
            func_002A8578(self, o1, o2, 0xA, 0.0f, t0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            self->hitFlash = 2.0f;
            self->step = self->step + 1;
        }
        case 1:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}

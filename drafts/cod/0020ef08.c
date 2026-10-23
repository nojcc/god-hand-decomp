/* sn-2.95.3-136 */
/* NON_MATCHING func_0020EF08 (extern_jtbl D_00432AC0 D_00432C10): retail keeps
 * the three Obj2810_ClearState_B calls (hit kind 35, the default and kind 44 of
 * the last switch) as separate blocks; here they are merged into one, and the
 * hit pointer and flag word get an extra register copy in retail. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/player.h"

#define EM_FLAG_HOLD   0x1000000

extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern void Obj2810_ClearState_B(int obj);
extern void Obj2810_ClearState_C(int obj);
extern int func_002815D0(int obj);
extern int func_0026F1D8(void *self);
extern void func_0026F120(void *self);
extern void func_00270C78(void *self);
extern unsigned char D_005CB010;

static __inline__ void cEm00_setState(cEm00 *self, unsigned char mode, unsigned char phase,
                                      unsigned char step, unsigned char arg)
{
    self->mode = mode;
    self->phase = phase;
    self->step = step;
    self->stepArg = arg;
}

/* Knocked down, or a held reaction when the hold flag is set. */
static __inline__ void knockDown(cEm00 *self)
{
    if (!(self->emFlags & EM_FLAG_HOLD))
        cEm00_setState(self, 1, 0x1A, 0, 0);
    else
        cEm00_setState(self, 1, 0x1B, 0, 2);
}

__attribute__((section(".text.func_0020EF08")))
int func_0020EF08(cEm00 *self)
{
    cDamageTake *hit;
    int flags;
    int kind;
    cVec *pos;

    pos = self->pos;
    Turn_dest(pos, Getplayer()->pos, self->rot.y, 3.1415927f);
    hit = self->unk698;
    if (hit->kind == 30) {
        knockDown(self);
    } else if (hit->kind == 31) {
        knockDown(self);
    } else if (hit->kind == 33) {
        knockDown(self);
    } else if (hit->kind == 32) {
        knockDown(self);
    } else if (hit->kind == 34) {
        knockDown(self);
    } else if (hit->kind == 35) {
        if (self->emFlags & EM_FLAG_HOLD)
            cEm00_setState(self, 1, 0x1B, 0, 0);
        else if (self->sub0 != 0)
            Obj2810_ClearState_B(self->sub0);
    } else if (hit->kind == 37) {
        knockDown(self);
    } else if (hit->kind == 38) {
        knockDown(self);
    } else if (hit->kind == 40) {
        knockDown(self);
    } else if (hit->kind == 28) {
        knockDown(self);
    } else if (hit->kind == 29) {
        knockDown(self);
    } else if (hit->kind == 39) {
        knockDown(self);
    } else if (hit->kind == 44) {
    } else if (hit->kind == 36) {
    } else {
        flags = self->emFlags;
        if ((flags & 0x800000) && self->vital > 0 && D_005CB010 == 0)
            return 1;
        if (!(flags & EM_FLAG_HOLD) && self->sub0 != 0 && func_002815D0(self->sub0) != 0)
            return 1;
        if (self->moveFlags & 8)
            return 1;
        if (self->vital <= 0) {
            cEm00_setState(self, 1, 0x1A, 0, 0);
        } else if (self->emFlags & EM_FLAG_HOLD) {
            kind = ((cDamageTake *)self->unk698)->kind;
            switch (kind) {
            case 2: case 3: case 4: case 5: case 7:
            case 21: case 22: case 23: case 24: case 27: case 44:
                cEm00_setState(self, 1, 0x1B, 0, 0);
                break;
            case 13:
                cEm00_setState(self, 1, 0x1B, 0, 2);
                break;
            case 1: case 84:
            default:
                cEm00_setState(self, 1, 0x1B, 0, 1);
                break;
            }
        } else if (func_0026F1D8(self) == 0 && (func_0026F120(self), func_0026F1D8(self) != 0)) {
            func_00270C78(self);
        } else {
            kind = ((cDamageTake *)self->unk698)->kind;
            switch (kind) {
            default:
                if (self->sub0 != 0)
                    Obj2810_ClearState_B(self->sub0);
                break;
            case 44:
                if (self->sub0 != 0)
                    Obj2810_ClearState_B(self->sub0);
                break;
            case 1: case 6: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
            case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23:
            case 24: case 25: case 26: case 27: case 28: case 42:
            case 46: case 47: case 48: case 49: case 50: case 51: case 52: case 53: case 54:
            case 82: case 83: case 84:
                if (self->sub0 != 0)
                    Obj2810_ClearState_C(self->sub0);
                break;
            }
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0020EF08);
#endif

#include "include_asm.h"
/* NON_MATCHING func_0020CD00 (sn-2.95.3-136, extern_jtbl D_00431EB0 D_00432010): same shape and
 * length within 4 words; retail dispatches counterReady with slti 2 / slti 4 (ours tests == 0) and
 * keeps the constant 1 of the case-1 compare in a saved register that the roll results copy. */
#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cHeatSys.h"
#include "godhand/player.h"
#include "godhand/rand.h"

#ifdef NON_MATCHING

#define EMFLAG2_ALWAYS_COUNTER  0x4000000   /* counters whenever it can, heat mode or not */
#define EMMOVE_NO_COUNTER       0x100
#define EMMOVE_BLOCKED          (0x8 | 0x20 | 0x4)
#define COUNTER_TURN_MAX        2.3561945f  /* 135 degrees */
#define EM_NO_TWIN_A            0x220       /* these three counter on their own roll */
#define EM_NO_TWIN_B            0x221
#define EM_NO_TWIN_C            0x222
#define PHASE_COUNTER           0x0A
#define PHASE_TWIN_COUNTER      0x12

/* The roll for a counter after a hit of the given kind, by counterReady. */
static __inline__ int Em_rollCounter(cEm00 *self, int kind)
{
    int ok = 1;

    switch (kind) {
    default:
        switch (self->counterReady) {
        case 1:
            if (cCoreSave_getGameLevel(&D_00569B70) < 2) {
                return 0;
            }
            if ((irand() & 0x1F) != 3) {
                ok = 0;
            }
            break;
        case 2:
        case 3:
            if (cCoreSave_getGameLevel(&D_00569B70) < 2) {
                if ((irand() & 0x1F) != 3) {
                    ok = 0;
                }
            } else if ((irand() & 0xF) != 3) {
                ok = 0;
            }
            break;
        default:
            return 0;
        }
        return ok;
    case 0x0C:
    case 0x0D:
    case 0x0F:
        switch (self->counterReady) {
        case 1:
            if (cCoreSave_getGameLevel(&D_00569B70) < 2) {
                ok = 0;
            } else if ((irand() & 0x1F) != 3) {
                ok = 0;
            }
            break;
        case 2:
            if (cCoreSave_getGameLevel(&D_00569B70) < 2) {
                if ((irand() & 0x1F) != 3) {
                    ok = 0;
                }
            } else if ((irand() & 0xF) != 3) {
                ok = 0;
            }
            break;
        case 3:
            if (cCoreSave_getGameLevel(&D_00569B70) < 2) {
                if ((irand() & 7) != 3) {
                    ok = 0;
                }
            } else if ((unsigned int)irand() % 3 != 2) {
                ok = 0;
            }
            break;
        default:
            ok = 0;
            break;
        }
        break;
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x1B:
        switch (self->counterReady) {
        case 1:
            if (cCoreSave_getGameLevel(&D_00569B70) < 2) {
                ok = 0;
            } else if ((irand() & 7) != 3) {
                ok = 0;
            }
            break;
        case 2:
        case 3:
            if ((irand() & 3) != 3) {
                ok = 0;
            }
            break;
        default:
            ok = 0;
            break;
        }
        break;
    case 0x1C:
    case 0x2C:
    case 0x30:
    case 0x36:
    case 0x52:
    case 0x55:
        return 0;
    }
    if (self->emFlags2 & EMFLAG2_ALWAYS_COUNTER) {
        ok = 1;
    }
    return ok;
}

/* Restores the counter's hit points, capped at the maximum. */
static __inline__ void Em_restoreCounterVital(cEm00 *self)
{
    if (self->counterVital >= self->vitalMax) {
        self->vital = self->vitalMax;
    } else {
        self->vital = self->counterVital;
    }
}

/* Decides whether the enemy answers the hit it just took with a counter
 * attack; if so, starts the counter phase and returns 1. */
__attribute__((section(".text.func_0020CD00")))
int func_0020CD00(cEm00 *self)
{
    cGameObj *player = Getplayer();
    cDamageTake *hit;
    unsigned short move;

    if (!(self->emFlags2 & EMFLAG2_ALWAYS_COUNTER)) {
        if (D_005CB000.mode != 0) {
            return 0;
        }
        if (Obj0000_Get_Field_5FC_NE_Zero_12C748((char *)player) != 0) {
            return 0;
        }
    }
    if (func_0026F1D8(self) != 0) {
        return 0;
    }
    move = self->moveFlags;
    if (move & EMMOVE_NO_COUNTER) {
        return 0;
    }
    if (self->counterVital <= 0) {
        return 0;
    }
    if (self->unk760 > COUNTER_TURN_MAX) {
        return 0;
    }
    if (self->speedRate < 1.0f) {
        return 0;
    }
    if (self->unk1740 > 0.0f) {
        return 0;
    }
    if (move & 0x8) {
        return 0;
    }
    if (move & 0x20) {
        return 0;
    }
    if (move & 0x4) {
        return 0;
    }
    hit = (cDamageTake *)self->unk698;
    switch (hit->kind) {
    case 0x01: case 0x02: case 0x03: case 0x04:
    case 0x07: case 0x08: case 0x09:
    case 0x0C: case 0x0D: case 0x0E: case 0x0F:
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16:
    case 0x17: case 0x18: case 0x19: case 0x1A: case 0x1B:
    case 0x2B: case 0x2D:
        switch (self->emNo) {
        default:
            if (!Em_rollCounter(self, hit->kind)) {
                return 0;
            }
            Em_restoreCounterVital(self);
            self->unk17C4 = -1;
            self->phase = PHASE_COUNTER;
            self->stepArg = 0;
            break;
        case EM_NO_TWIN_A:
        case EM_NO_TWIN_B:
        case EM_NO_TWIN_C:
            if ((irand() & 7) != 3) {
                return 0;
            }
            Em_restoreCounterVital(self);
            self->unk17C4 = -1;
            self->stepArg = 1;
            self->phase = PHASE_TWIN_COUNTER;
            break;
        }
        self->unk17C8 = 0;
        self->mode = 0;
        self->step = 0;
        return 1;
    case 0x55:
    default:
        return 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0020CD00);
#endif

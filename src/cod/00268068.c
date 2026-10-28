/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"
#include "godhand/rand.h"

/* Picks a reaction for an alerted enemy (emFlags 0x200000 and emFlags2
 * 0x8000000 set; unless forced, only once unk760 exceeds 75 degrees). Below
 * level 5, with unk760 over 75 degrees, phase 8 may start: on a coin flip, or
 * for enemy 0x264 when playerDist is over 49; enemy 0x265 gives up while
 * emFlags2 bit 0x20000000 is set, and 0x220..0x222 give up on a coin flip.
 * With counterReady 2 or 3 and playerDist under 6.25 a counter attack
 * (phase 0xA) is tried on one roll in four, two rolls for enemies 0x252,
 * 0x256 and 0x27E. Otherwise, with playerDist at most 4 (49 for 0x264) and
 * none of the emFlags2 bits 0x10380 set, the listed enemies start phase 0x45
 * and enemy 0x20E phase 0x27. Returns 1 when a phase starts. */
__attribute__((section(".text.func_00268068")))
int func_00268068(cEm00 *self, int force)
{
    int counter;

    if (self->emNo == 0x26A) {
        return 0;
    }
    if (force == 0 && self->unk760 < 1.3089969f) {
        return 0;
    }
    if (!(self->emFlags & 0x200000)) {
        return 0;
    }
    if (!(self->emFlags2 & 0x8000000)) {
        return 0;
    }
    if (cCoreSave_getGameLevel(&D_00569B70) < 5) {
        switch (self->emNo) {
        default:
            if (1.3089969f < self->unk760 && (irand() & 1)) {
                self->emFlags2 |= 1;
                cEm00_setState(self, 0, 8, 1);
                return 1;
            }
            break;
        case 0x220:
        case 0x221:
        case 0x222:
            if (irand() & 1) {
                return 0;
            }
            break;
        case 0x264:
            if (1.3089969f < self->unk760 && 49.0f < self->playerDist) {
                self->emFlags2 |= 1;
                cEm00_setState(self, 0, 8, 1);
                return 1;
            }
            break;
        case 0x265:
            if (self->emFlags2 & 0x20000000) {
                return 0;
            }
            if (1.3089969f < self->unk760 && (irand() & 1)) {
                self->emFlags2 |= 1;
                cEm00_setState(self, 0, 8, 1);
                return 1;
            }
            break;
        }
    }
    switch (self->counterReady) {
    case 2:
    case 3:
        if (self->playerDist < 6.25f) {
            counter = 0;
            if ((irand() & 3) == 1) {
                counter = 1;
            }
            switch (self->emNo) {
            case 0x252:
            case 0x256:
            case 0x27E:
                if ((irand() & 3) == 1) {
                    counter = 1;
                }
                break;
            }
            if (counter && func_00273C38((cGameObj *)self) != 0) {
                cEm00_setState(self, 0, 0xA, 1);
                return 1;
            }
        }
        break;
    }
    if (self->emNo != 0x264) {
        if (4.0f < self->playerDist) {
            return 0;
        }
    } else if (49.0f < self->playerDist) {
        return 0;
    }
    if (self->emFlags2 & 0x10380) {
        return 0;
    }
    switch (self->emNo) {
    case 0x209:
    case 0x20A:
    case 0x20B:
    case 0x20C:
    case 0x20D:
    case 0x218:
    case 0x222:
    case 0x223:
    case 0x245:
    case 0x246:
    case 0x247:
    case 0x24F:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x256:
    case 0x260:
    case 0x275:
    case 0x276:
    case 0x278:
    case 0x279:
    case 0x27E:
        cEm00_setState(self, 0, 0x45, 0);
        return 1;
    case 0x20E:
        D_005864F0.unk541 = 150;
        cEm00_setState(self, 0, 0x27, 0);
        return 1;
    }
    return 0;
}

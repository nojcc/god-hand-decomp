/* NON_MATCHING func_002CEA00 (sn-2.95.3-136): same length as retail; 4 instructions differ. In the left-volume easing step retail computes the difference into a new register ($v1) and keeps the loaded volume in $a0; ours computes it in place in $a0. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cSnd.h"
#include "godhand/SndEntry.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/vu0.h"

extern char D_00747B20[];               /* the hidden-model list */
extern void func_0030A538(cVec *dst, cVec *src);
extern int func_00308DA8(int self, int a1, int a2);

/* The sound system object. */
static __inline__ cSnd *sndSys(void)
{
    return &D_005FEE00;
}

/* Turns the voice's state into driver parameters for this frame: follows its
 * object, sets volume and pan from the listener, applies the quiet and
 * occlusion scales, then eases the values towards the ones last sent and
 * queues the entry. Returns 0 when the driver refuses a value, else 1 (also
 * when nothing changed). */
__attribute__((section(".text.func_002CEA00")))
int func_002CEA00(cSndSeVoice *v, SndEntryParam *e)
{
    short dist;
    short pan;

    if (v->obj != 0) {
        if (v->part == 0) {
            func_0030A538((cVec *)v->pos, ((cOmBase *)v->obj)->pos);
        } else {
            func_0030A538((cVec *)v->pos, ((cParts *)v->part)->pos);
        }
        v->pos[1] += 1.3f;
    }
    e->dirty = 0;
    switch (v->kind) {
    case 0:
        if (v->idA >= 0) {
            e->volL = e->volR = v->idA;
        }
        if (v->idB >= 0) {
            e->pitch = v->idB;
        }
        break;
    case 1:
        cSnd_CalcListenerPanDist(v, (cVec *)v->pos, &dist, 0);
        if (UpdateEntryVolume_3751B8(e, dist) == -1) {
            return 0;
        }
        break;
    case 2:
        cSnd_CalcListenerPanDist(v, (cVec *)v->pos, &dist, &pan);
        if (UpdateEntryVolume_3751B8(e, dist) == -1) {
            return 0;
        }
        if (UpdateEntryParams_3752A0(e, pan) == -1) {
            return 0;
        }
        v->flags |= 2;
        e->dirty = 0xF;
        break;
    case 3:
        cSnd_CalcListenerPanDist(v, (cVec *)v->pos, 0, &pan);
        if (UpdateEntryVolume_3751B8(e, v->dist) == -1) {
            return 0;
        }
        if (UpdateEntryParams_3752A0(e, pan) == -1) {
            return 0;
        }
        v->flags |= 2;
        e->dirty = 0xF;
        break;
    }
    if ((v->stateFlags & 4) && !(v->stateFlags & 0x80000)) {
        e->volL = (int)(e->volL * D_005FEE00.f64);
        e->volR = (int)(e->volR * D_005FEE00.f64);
        e->dirty |= 0xB;
        v->flags |= 2;
    }
    if (v->stateFlags & 0x20) {
        e->volL = (int)(e->volL * D_005FEE00.f70);
        e->volR = (int)(e->volR * D_005FEE00.f70);
        e->dirty |= 0xB;
        v->flags |= 2;
    }
    if (v->stateFlags & 0x10000) {
        e->unk1C -= 0xF00;
        if (v->optFlags & 2) {
            e->volL = (int)(e->volL * 1.4f);
            e->volR = (int)(e->volR * 1.4f);
        }
        if (v->optFlags & 4) {
            e->volL = 0;
            v->curVolL = 0;
            e->volR = 0;
            v->curVolR = 0;
        }
        e->dirty |= 0xB;
        v->flags |= 2;
    } else if ((v->optFlags & 2) || (v->optFlags & 4)) {
        if (v->curVolL != e->volL || v->curVolR != e->volR) {
            e->dirty |= 0xB;
            v->flags |= 2;
        }
    }
    if (v->stateFlags & 0x200) {
        cVec from;
        cVec to;

        if (func_00308DA8((int)D_00747B20,
                          (int)CVEC_ARG_COPY(from, v->pos),
                          (int)CVEC_ARG_COPY(to, &sndSys()->listenPos)) != 0) {
            e->volL = (int)(e->volL * 0.3f);
            v->curVolL = e->volL;
            e->volR = (int)(e->volR * 0.3f);
            v->curVolR = e->volR;
            e->dirty |= 0xB;
            v->flags |= 2;
        } else if (v->curVolL != e->volL || v->curVolR != e->volR) {
            e->dirty |= 0xB;
            v->flags |= 2;
        }
    }
    if (!(v->flags & 2)) {
        return 1;
    }
    v->flags ^= 2;
    if (e->volL > 0x80) {
        e->volL = 0x80;
    }
    if (e->volR > 0x80) {
        e->volR = 0x80;
    }
    {
        int d = e->volL - v->curVolL;
        if ((d < 0 ? -d : d) >= 7) {
            e->volL = d < 0 ? v->curVolL - 6 : v->curVolL + 6;
        }
    }
    v->curVolL = e->volL;
    {
        int d = e->volR - v->curVolR;
        if ((d < 0 ? -d : d) >= 7) {
            e->volR = d < 0 ? v->curVolR - 6 : v->curVolR + 6;
        }
    }
    v->curVolR = e->volR;
    {
        int d = e->pitch - v->curPitch;
        if ((d < 0 ? -d : d) >= 4) {
            e->pitch = d >= 0 ? v->curPitch + 3 : v->curPitch - 3;
        }
    }
    v->curPitch = e->pitch;
    while (e->pan - v->curPan >= 180) {
        e->pan -= 360;
    }
    while (e->pan - v->curPan < -179) {
        e->pan += 360;
    }
    {
        int d = e->pan - v->curPan;
        if ((d < 0 ? -d : d) >= 13) {
            e->pan = d < 0 ? v->curPan - 12 : v->curPan + 12;
        }
    }
    v->curPan = e->pan % 720;
    return AddSoundEntry_374F30(v->handle, e) != -1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002CEA00);
#endif

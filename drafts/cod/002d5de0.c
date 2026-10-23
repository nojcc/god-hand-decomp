/* NON_MATCHING CustomIDWork_Main (sn-2.95.3-136, as sn): 4 words short. Retail pads the colour and scale
 * divides with two nops but not the position and offset ones, which no hazard rule reproduces; re-read flag
 * words also land in v1 where retail uses a fresh v0, and t sits in $f3 instead of $f2. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/CustomIDWork.h"

extern float capVu0Sin(float x);

/* Advance the element's position, offset, colour and scale animations by one frame. */
__attribute__((section(".text.CustomIDWork_Main")))
void CustomIDWork_Main(CustomIDWork *self)
{
    CustomIDObj *obj;
    long f;
    float t;

    obj = self->obj;
    if (obj == 0)
        return;

    f = (unsigned int)self->localFlags;
    if ((f & CIDW_ANIM_ON) == 1) {
        self->localCount++;
        t = (float)self->localCount / (float)self->localTotal;
        if ((f >> 1 & 1) == 1)
            obj->localPos[0] = self->localFrom[0] + (self->localTo[0] - self->localFrom[0]) * t;
        f = (unsigned int)self->localFlags;
        if ((f >> 2 & 1) == 1)
            self->obj->localPos[1] = self->localFrom[1] + (self->localTo[1] - self->localFrom[1]) * t;
        if (self->localCount >= self->localTotal)
            self->localFlags = 0;
    }

    f = (unsigned int)self->offsFlags;
    if ((f & CIDW_ANIM_ON) == 1) {
        if ((f >> 1 & 1) == 1 || (f >> 3 & 1) == 1) {
            self->offsCount++;
            t = (float)self->offsCount / (float)self->offsTotal;
            if ((f >> 1 & 1) == 1)
                self->obj->offsetPos[0] = self->offsFrom[0] + (self->offsTo[0] - self->offsFrom[0]) * t;
            f = (unsigned int)self->offsFlags;
            if ((f >> 3 & 1) == 1)
                self->obj->offsetPos[1] = self->offsFrom[1] + (self->offsTo[1] - self->offsFrom[1]) * t;
            if (self->offsCount >= self->offsTotal)
                self->offsFlags = 0;
        } else if ((f >> 2 & 1) == 1 || (f >> 4 & 1) == 1) {
            self->offsCount += self->offsTotal;
            if (self->offsCount >= CIDW_SINE_PERIOD)
                self->offsCount -= CIDW_SINE_PERIOD;
            f = (unsigned int)self->offsFlags;
            if ((f >> 2 & 1) == 1)
                self->obj->offsetPos[0] = capVu0Sin(self->offsCount * CIDW_DEG_TO_RAD) * self->offsAmp[0];
            f = (unsigned int)self->offsFlags;
            if ((f >> 4 & 1) == 1)
                self->obj->offsetPos[1] = capVu0Sin(self->offsCount * CIDW_DEG_TO_RAD) * self->offsAmp[1];
        }
    }

    f = (unsigned int)self->colorFlags;
    if ((f & CIDW_ANIM_ON) == 1) {
        if ((f >> 1 & 1) == 1) {
            self->colorCount++;
            t = (float)self->colorCount / (float)self->colorTotal;
            self->obj->color[0] = (int)(self->colorFrom[0] + (self->colorTo[0] - self->colorFrom[0]) * t);
            self->obj->color[1] = (int)(self->colorFrom[1] + (self->colorTo[1] - self->colorFrom[1]) * t);
            self->obj->color[2] = (int)(self->colorFrom[2] + (self->colorTo[2] - self->colorFrom[2]) * t);
            self->obj->color[3] = (int)(self->colorFrom[3] + (self->colorTo[3] - self->colorFrom[3]) * t);
            if (self->colorCount >= self->colorTotal)
                self->colorFlags = 0;
        } else if ((f >> 2 & 1) == 1) {
            self->colorCount += self->colorTotal;
            if (self->colorCount >= CIDW_SINE_PERIOD)
                self->colorCount -= CIDW_SINE_PERIOD;
            self->obj->color[0] = (int)(capVu0Sin(self->colorCount * CIDW_DEG_TO_RAD)
                                        * (self->colorTo[0] - self->colorFrom[0]) + self->colorFrom[0]);
            self->obj->color[1] = (int)(capVu0Sin(self->colorCount * CIDW_DEG_TO_RAD)
                                        * (self->colorTo[1] - self->colorFrom[1]) + self->colorFrom[1]);
            self->obj->color[2] = (int)(capVu0Sin(self->colorCount * CIDW_DEG_TO_RAD)
                                        * (self->colorTo[2] - self->colorFrom[2]) + self->colorFrom[2]);
            self->obj->color[3] = (int)(capVu0Sin(self->colorCount * CIDW_DEG_TO_RAD)
                                        * (self->colorTo[3] - self->colorFrom[3]) + self->colorFrom[3]);
        }
    }

    f = (unsigned int)self->scaleFlags;
    if ((f & CIDW_ANIM_ON) == 1) {
        if ((f >> 1 & 1) == 1) {
            self->scaleCount++;
            t = (float)self->scaleCount / (float)self->scaleTotal;
            self->obj->scale[0] = self->scaleX[0] + (self->scaleX[1] - self->scaleX[0]) * t;
            self->obj->scale[1] = self->scaleY[0] + (self->scaleY[1] - self->scaleY[0]) * t;
            if (self->scaleCount >= self->scaleTotal)
                self->scaleFlags = 0;
        } else if ((f >> 2 & 1) == 1) {
            self->scaleCount += self->scaleTotal;
            if (self->scaleCount >= CIDW_SINE_PERIOD)
                self->scaleCount -= CIDW_SINE_PERIOD;
            self->obj->scale[0] = capVu0Sin(self->scaleCount * CIDW_DEG_TO_RAD)
                                  * (self->scaleX[1] - self->scaleX[0]) + self->scaleX[0];
            self->obj->scale[1] = capVu0Sin(self->scaleCount * CIDW_DEG_TO_RAD)
                                  * (self->scaleY[1] - self->scaleY[0]) + self->scaleY[0];
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", CustomIDWork_Main);
#endif

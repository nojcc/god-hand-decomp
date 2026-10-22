/* sn-2.95.3-136 */
/*
 * NON_MATCHING: 137 vs 139 words (47 instructions differ under mtc1,div1).
 * Retail pads the first div.s with no nops and the second with two, which
 * no fp_hazard_rules set models; it also tests flag bit 3 with dsrl where
 * this gives srl, and keeps the level in $f4 rather than $f3.
 */
#include "include_asm.h"
#include "godhand/cIDBase.h"
#include "godhand/cOmBase.h"

/* View of GameWork from 0x584 (D_00747A24). */
typedef struct GameFlags {
    unsigned int flags;                 /* 0x00 GameWork 0x584 */
    char unk04[4];
    int sys;                            /* 0x08 GameSys.unk00 */
    char unk0C[0x60 - 0x0C];
    int flags5E4;                       /* 0x60 */
} GameFlags;

extern GameFlags D_00747A24;

#ifdef NON_MATCHING
extern void cIDBase_move(cIDBaseObj *self);

#define VITALGAUGE_INIT     0x40000000  /* flags: bars set to full */
#define VITALGAUGE_HOLD     40          /* frames the lost part stays before draining */

/* The vital gauge: two stacked bars, each with a drain marker behind it. */
typedef struct cVitalGauge {
    cIDBaseObj base;
    char unk48[0x94 - 0x48];
    int active;                         /* 0x94 */
    char unk98[4];
    cOmBase *target;                    /* 0x9C */
    unsigned int flags;                 /* 0xA0 */
    char unkA4[4];
    float drain;                        /* 0xA8 marker level, 0..2 */
    float last;                         /* 0xAC level last frame */
    float drainFrom;                    /* 0xB0 marker level when the hold ended */
    float level;                        /* 0xB4 0..2 */
    float drainPrev;                    /* 0xB8 */
    unsigned char drainAlpha;           /* 0xBC */
    char unkBD;
    unsigned short hold;                /* 0xBE */
    cIDBaseEnt *ent[4];                 /* 0xC0 upper bar, lower drain, lower bar, upper drain */
} cVitalGauge;

/* Track the target's vital: the bars follow it at once, the drain marker
 * holds for a while after a hit and then eases down to it. */
__attribute__((section(".text.func_0013E970")))
void func_0013E970(cVitalGauge *self)
{
    float level, lower, upper, drainLower, drainUpper;

    if (self->active == 0 || self->target == 0) {
        return;
    }
    if ((D_00747A24.flags >> 3) & 1) {
        return;
    }
    if (D_00747A24.sys < 0 || self->target->hpMax == 0) {
        return;
    }
    if (D_00747A24.flags5E4 & 0x80000) {
        return;
    }
    if (!(self->flags & VITALGAUGE_INIT)) {
        self->drain = 1.0f;
        self->last = 1.0f;
        self->ent[0]->sclY = 1.0f;
        self->ent[2]->sclY = self->drain;
        self->ent[1]->sclY = self->drain;
        self->ent[3]->sclY = self->drain;
        self->flags |= VITALGAUGE_INIT;
    }
    level = (float)self->target->hp / (float)self->target->hpMax * 2.0f;
    if (self->last != level) {
        self->hold = VITALGAUGE_HOLD;
    }
    self->level = level;
    if (self->hold == 0) {
        self->drainPrev = self->drain;
        self->drain = self->drain - (self->drain - level) * 0.07f;
    } else {
        self->hold--;
    }
    self->drainAlpha = (self->drain - level) / (self->drainFrom - level) * 128.0f;
    self->last = level;
    lower = self->level;
    if (1.0f < lower) {
        upper = lower - 1.0f;
        lower = 1.0f;
    } else {
        upper = 0.0f;
    }
    drainLower = self->drainPrev;
    if (1.0f < drainLower) {
        drainUpper = drainLower - 1.0f;
        drainLower = 1.0f;
    } else {
        drainUpper = 0.0f;
    }
    self->ent[0]->sclY = upper;
    self->ent[2]->sclY = lower;
    self->ent[1]->sclY = drainUpper;
    self->ent[3]->sclY = drainLower;
    self->ent[1]->colorBase.c[3] = self->drainAlpha;
    self->ent[3]->colorBase.c[3] = self->drainAlpha;
    if (self->hold == VITALGAUGE_HOLD - 1) {
        self->drainFrom = self->drain;
    }
    cIDBase_move(&self->base);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0013E970);
#endif

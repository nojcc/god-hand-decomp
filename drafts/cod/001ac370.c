/* sn-2.95.3-136 */
/* func_001AC370 (breakable guard shells): the switch and the shell display match; the colour
 * tail differs in which FP registers hold c, 1 - c and 0.2, and retail pads the second and third
 * div.s with two nops but leaves the first bare, which no fp hazard rule reproduces. */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"

#ifdef NON_MATCHING

/* A breakable gimmick: a guard that regenerates and changes colour with it. */
typedef struct cGmGuard {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x24];
    float fade;                         /* 0x604 cross-fade between the two shells, 0 to 1 */
    int fadeMode;                       /* 0x608 0 none, 1 to the broken shell, 2 back */
    unsigned char broken;               /* 0x60C */
    char unk60D[0xB];
    int damage;                         /* 0x618 damage taken so far */
    char unk61C[0x8];
    void *unit;                         /* 0x624 damage unit */
} cGmGuard;

extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern void cOmBase_setMeshColorFromLayer(void *self, int layer, float r, float g, float b);
extern void cOmBase_setMeshAlphaFromLayer(void *self, int layer, float a);

/* Colour the three guard shells alike. */
static __inline__ void cGmGuard_setShellColor(cGmGuard *self, float r, float g, float b)
{
    cOmBase_setMeshColorFromLayer(self, 2, r, g, b);
    cOmBase_setMeshColorFromLayer(self, 3, r, g, b);
    cOmBase_setMeshColorFromLayer(self, 4, r, g, b);
}

/* Show the gimmick's shell layers for its state and colour them by the guard left. */
__attribute__((section(".text.func_001AC370")))
void func_001AC370(cGmGuard *self)
{
    float r;

    switch (self->fadeMode) {
    case 0:
        if (self->broken == 0) {
            cOmBase_setMeshDispFromLayer(self, 1, 1);
            cOmBase_setMeshDispFromLayer(self, 2, 0);
            cOmBase_setMeshDispFromLayer(self, 3, 0);
            cOmBase_setMeshDispFromLayer(self, 4, 0);
            cOmBase_setMeshDispFromLayer(self, 5, 0);
        } else {
            cOmBase_setMeshDispFromLayer(self, 1, 0);
            if (self->base.hp > 0) {
                if (self->damage < 20) {
                    cOmBase_setMeshDispFromLayer(self, 2, 1);
                    cOmBase_setMeshDispFromLayer(self, 3, 0);
                    cOmBase_setMeshDispFromLayer(self, 4, 0);
                    cOmBase_setMeshDispFromLayer(self, 5, 0);
                } else if (self->damage < 40) {
                    cOmBase_setMeshDispFromLayer(self, 2, 0);
                    cOmBase_setMeshDispFromLayer(self, 3, 1);
                    cOmBase_setMeshDispFromLayer(self, 4, 0);
                    cOmBase_setMeshDispFromLayer(self, 5, 0);
                } else {
                    cOmBase_setMeshDispFromLayer(self, 2, 0);
                    cOmBase_setMeshDispFromLayer(self, 3, 0);
                    cOmBase_setMeshDispFromLayer(self, 4, 1);
                    cOmBase_setMeshDispFromLayer(self, 5, 0);
                }
            } else {
                cOmBase_setMeshDispFromLayer(self, 2, 0);
                cOmBase_setMeshDispFromLayer(self, 3, 0);
                cOmBase_setMeshDispFromLayer(self, 4, 0);
                cOmBase_setMeshDispFromLayer(self, 5, 1);
                cOmBase_setMeshColorFromLayer(self, 5, 0.8f, 0.2f, 0.2f);
            }
        }
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(self, 1, 1);
        cOmBase_setMeshDispFromLayer(self, 2, 1);
        cOmBase_setMeshDispFromLayer(self, 3, 0);
        cOmBase_setMeshDispFromLayer(self, 4, 0);
        cOmBase_setMeshDispFromLayer(self, 5, 0);
        self->fade += 0.05f;
        if (self->fade >= 1.0f) {
            self->fade = 1.0f;
            self->broken = 1;
            if (self->unit != 0)
                cDamageUnit_SetDamageCollActive(self->unit, 1);
            self->fadeMode = 0;
        }
        cOmBase_setMeshAlphaFromLayer(self, 1, 1.0f - self->fade);
        cOmBase_setMeshAlphaFromLayer(self, 2, self->fade);
        break;
    case 2:
        cOmBase_setMeshDispFromLayer(self, 1, 1);
        cOmBase_setMeshDispFromLayer(self, 2, 1);
        cOmBase_setMeshDispFromLayer(self, 3, 0);
        cOmBase_setMeshDispFromLayer(self, 4, 0);
        cOmBase_setMeshDispFromLayer(self, 5, 0);
        self->fade += 0.02f;
        if (self->fade >= 1.0f) {
            self->fade = 1.0f;
            self->broken = 0;
            self->fadeMode = 0;
        }
        cOmBase_setMeshAlphaFromLayer(self, 1, self->fade);
        cOmBase_setMeshAlphaFromLayer(self, 2, 1.0f - self->fade);
        break;
    }
    r = (float)self->base.hp / (float)self->base.hpMax;
    if (r >= 0.7f) {
        float c = (1.0f - r) / 0.3f * 0.8f + 0.2f;


        cGmGuard_setShellColor(self, 0.2f, c, 1.0f - c);
    } else {
        float c = (0.7f - r) / 0.7f * 0.8f + 0.2f;


        cGmGuard_setShellColor(self, c, 1.0f - c, 0.2f);
    }
}

#else
INCLUDE_ASM("asm/nonmatching", func_001AC370);
#endif

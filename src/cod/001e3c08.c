/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot1.h"
#include "godhand/scrollLayer.h"
#include "godhand/globals.h"

extern int cModel_setMeshDisplay(void *model, char *name, int on);

/* Costume hook for the objects with actor id 0x605 and 0x607: from costume 0x10 on, hide the first part mesh (and show the second one on 0x605). */
#define ACTOR_ID_COSTUME_A   0x605
#define ACTOR_ID_COSTUME_B   0x607
#define COSTUME_PART_MIN     0x10

typedef struct CostumeObj {
    char unk000[0x2FE];
    unsigned short actorId;             /* 0x2FE */
} CostumeObj;





__attribute__((section(".text.CostumeObj_applyPartMeshes")))
void CostumeObj_applyPartMeshes(CostumeObj *self, int unused, int costume)
{
    if (self == 0) {
        return;
    }
    switch (self->actorId) {
    case ACTOR_ID_COSTUME_A:
        if (costume >= COSTUME_PART_MIN) {
            cModel_setMeshDisplay(self, D_0044A9B0, 0);
            cModel_setMeshDisplay(self, D_0044A9B8, 1);
        }
        break;
    case ACTOR_ID_COSTUME_B:
        if (costume >= COSTUME_PART_MIN) {
            cModel_setMeshDisplay(self, D_0044A9B0, 0);
        }
        break;
    }
}

/* Show or hide the four scroll layers of a slot machine mark; showing also sets the mark's flag word (bit 15 start lit, bit 14 on). */
#define SLOT2MARK_F_START_LIT  0x8000
#define SLOT2MARK_F_ON         0x4000

__attribute__((section(".text.Slot2_setMarkLayers")))
void Slot2_setMarkLayers(Slot1 *self, int show, int startLit)
{
    self->markFlag[5] = 0;
    if (startLit) {
        self->markFlag[5] = SLOT2MARK_F_START_LIT;
    }
    if (show) {
        self->markFlag[5] = self->markFlag[5] | SLOT2MARK_F_ON;
        displayScrollLayer(self->scrollLayer[SLOT1_MARK_LAYER_A], 1);
        displayScrollLayer(self->scrollLayer[SLOT1_MARK_LAYER_B], 1);
        displayScrollLayer(self->scrollLayer[SLOT1_MARK5_LAYERS], 1);
        displayScrollLayer(self->scrollLayer[SLOT1_MARK5_LAYERS + 1], 1);
    } else {
        displayScrollLayer(self->scrollLayer[SLOT1_MARK_LAYER_A], 0);
        displayScrollLayer(self->scrollLayer[SLOT1_MARK_LAYER_B], 0);
        displayScrollLayer(self->scrollLayer[SLOT1_MARK5_LAYERS], 0);
        displayScrollLayer(self->scrollLayer[SLOT1_MARK5_LAYERS + 1], 0);
    }
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/PanelObj.h"
#include "godhand/Slot1.h"

/* Show or hide the two cursor elements: mode 0 hides the first and shows the second, mode 1 shows both, any other mode leaves them. */
#define PANEL_ELEM_LEFT   2
#define PANEL_ELEM_RIGHT  3

__attribute__((section(".text.PanelObj_setCursorMode")))
void PanelObj_setCursorMode(PanelObj *self, unsigned char mode)
{
    switch (mode) {
    case 0:
        func_001DEE60(self, PANEL_ELEM_LEFT, 0);
        func_001DEE60(self, PANEL_ELEM_RIGHT, 1);
        break;
    case 1:
        func_001DEE60(self, PANEL_ELEM_LEFT, 1);
        func_001DEE60(self, PANEL_ELEM_RIGHT, 1);
        break;
    }
}

/* Two-phase wait of the first slot machine: phase 0 counts the blink timer down and, when it runs out, clears the drift set-up flag and hides the drift layers; phase 1 resets the state machine. */
__attribute__((section(".text.Slot2Part_stepWait")))
void Slot2Part_stepWait(Slot1 *self)
{
    switch (self->phase) {
    case 0:
        if (self->blinkTimer != 0) {
            self->blinkTimer--;
            if (self->blinkTimer == 0) {
                self->flags &= ~SLOT1_F_DRIFT_SET;
                LayerScreen_hideLayers(self, 0);
            }
        }
        self->phase = self->phase + 1;
        break;
    case 1:
        self->state = 0;
        self->step = 0;
        self->phase = 0;
        break;
    }
}

/* 1 when no loaded bank entry uses this key (a zero key, or an idle table, counts as free); 0 when the current or any live entry holds it. */
#define BANKTAB_ENTRY_NUM  16

typedef struct BankEntry {
    unsigned int flags;                 /* 0x00 bit 0: entry in use */
    char unk04[0x7C];
    int key;                            /* 0x80 */
    char unk84[0x3C];
} BankEntry;                            /* 0xC0 */

typedef struct BankTable {
    BankEntry *cur;                     /* 0x00 entry being loaded, 0 when idle */
    char unk04[0x3C];
    BankEntry entry[BANKTAB_ENTRY_NUM]; /* 0x40 */
} BankTable;

extern int func_002D3210(BankEntry *entry);     /* entry in use */

__attribute__((section(".text.BankTable_isKeyFree")))
int BankTable_isKeyFree(BankTable *self, int key)
{
    BankEntry *e;
    int i;
    if (key == 0) {
        return 1;
    }
    if (self->cur == 0) {
        return 1;
    }
    if (self->cur->key == key) {
        return 0;
    }
    e = self->entry;
    for (i = 0; i < BANKTAB_ENTRY_NUM; i++) {
        if (func_002D3210(e) != 0) {
            if (e->key == key) {
                return 0;
            }
        }
        e++;
    }
    return 1;
}

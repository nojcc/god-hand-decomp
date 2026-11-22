/* sn-2.95.3-136 */
#include "godhand/gameWork.h"
#include "godhand/cCoreSave.h"
#include "godhand/CustomIDWork.h"
#include "godhand/Slot1.h"
#include "godhand/globals.h"

/* One row of the state table: this adjust and the state's handler. */
typedef struct Slot1StateEnt {
    short delta;
    short pad;
    void (*fn)();
} Slot1StateEnt;

extern Slot1StateEnt D_003BE0B0[];
extern void func_001E4010(Slot1 *self);
extern void func_001E7EA0(void *reel);
extern void func_001E33B0(Slot1 *self);

/* Per-frame update of the first slot machine: run the state handler, blink the marks, step the reels, the board and
 * the ui, and show the saved gold. */
__attribute__((section(".text.func_001E0210")))
void func_001E0210(Slot1 *self)
{
    SlotUi *ui = &self->ui;
    int v;
    int i = self->state;
    short off = D_003BE0B0[i].delta;
    void (*fn)() = D_003BE0B0[i].fn;
    fn((char *)self + off);
    Slot2_blinkMarkTick(self);
    Slot2_blinkMarksAt4A2(self);
    Slot2_blinkMarks(self);
    Slot2_blinkMarksAt4A6(self);
    Slot2_updateMarkAt4A8(self);
    func_001E4010(self);
    Slot2_stepMarkSelector(self);
    Slot2_updateMarkAt4C0(self);
    func_001E4610(self);
    func_001E79E8(&self->panel);
    func_001E7EA0(&self->reel[0]);
    func_001E7EA0(&self->reel[1]);
    func_001E7EA0(&self->reel[2]);
    v = cCoreSave_getGold(&D_00569B70);
    CustomIDWork_SetNumber(&self->ui.mark[0], v);
    func_001E73C0(ui);
    func_001E7440(ui);
    if (D_00747A2C.unk00 & 0x200)
        func_001E33B0(self);
}

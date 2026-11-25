/* sn-2.95.3-136 */
#include "godhand/CustomIDWork.h"
#include "godhand/CustomIDPanel.h"
#include "godhand/ColiseumEmSelectFn.h"

#define STAT_DISP_PIP      0x50     /* pip entries 0x50.. */
#define STAT_DISP_GAUGE0   0x57
#define STAT_DISP_GAUGE1   0x58
#define STAT_DISP_GAUGE2   0x5B
#define STAT_DISP_GAUGE3   0x5C
#define STAT_DISP_FRAME    0x60
#define STAT_MODE_HIDE     0
#define STAT_MODE_FRAME    1
#define STAT_MODE_FULL     2
#define PIP_LIT_COLOR      0x80808080
#define PIP_DIM_COLOR      0x626C6C6C


/* Rebuild the status panel: hide it, then show only the frame, or set the four gauges (percent) and light the first `lit` of `num` pips. */
__attribute__((section(".text.func_001F5650")))
void func_001F5650(ColiseumEmDisp *self, unsigned char mode, short gauge0, short gauge1, short gauge2, short gauge3,
                   short num, short lit)
{
    int i;
    int id;
    CustomIDWork *work;

    SetCustomIDDispOneOrAll_1F4778(self, 0x50, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x51, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x52, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x53, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x54, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x55, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x56, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x57, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x58, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x59, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x5A, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x5B, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x5C, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x5D, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x5E, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x5F, 0);
    SetCustomIDDispOneOrAll_1F4778(self, 0x60, 0);
    switch (mode) {
    case STAT_MODE_HIDE:
        break;
    case STAT_MODE_FRAME:
        SetCustomIDDispOneOrAll_1F4778(self, STAT_DISP_FRAME, 1);
        break;
    case STAT_MODE_FULL:
        func_002D69A8(&self->elem[STAT_DISP_GAUGE0], 1, gauge0 / 100.0f, gauge0 / 100.0f);
        func_002D69A8(&self->elem[STAT_DISP_GAUGE1], 1, gauge1 / 100.0f, gauge1 / 100.0f);
        func_002D69A8(&self->elem[STAT_DISP_GAUGE2], 1, gauge2 / 100.0f, gauge2 / 100.0f);
        func_002D69A8(&self->elem[STAT_DISP_GAUGE3], 1, gauge3 / 100.0f, gauge3 / 100.0f);
        SetCustomIDDispOneOrAll_1F4778(self, 0x56, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x57, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x58, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x59, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x5A, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x5B, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x5C, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x5D, 1);
        for (i = 0; i < num; i++) {
            id = STAT_DISP_PIP + i;
            work = &self->elem[id];
            if (i < lit) {
                CustomIDWork_SetColorAnimNormal_2D6898(work, PIP_LIT_COLOR, 1);
                func_002D65F8(work, 0.0f, 0.0f, 0.57f, 0.56f);
            } else {
                CustomIDWork_SetColorAnimNormal_2D6898(work, PIP_DIM_COLOR, 1);
                func_002D65F8(work, 0.49f, 0.5f, 1.0f, 1.0f);
            }
            SetCustomIDDispOneOrAll_1F4778(self, id, 1);
        }
        SetCustomIDDispOneOrAll_1F4778(self, 0x5E, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x5F, 1);
        SetCustomIDDispOneOrAll_1F4778(self, 0x60, 1);
        break;
    }
}

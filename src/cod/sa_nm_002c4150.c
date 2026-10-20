/* NON_MATCHING cScenario_execUpCutData (sn-2.95.3-136; PARK): stores and the taskExec call match; the slot index stays in v0 instead of t1 and the 0x58 scale adds into the base. Best 18. */
#include "include_asm.h"
#include "godhand/cScenario.h"
#include "godhand/cTaskWork.h"

#ifdef NON_MATCHING
extern void cScenario_upCutTask(void);

void cScenario_execUpCutData(cScenario *self, int no, int camData, int asTask,
                             unsigned char arg, int slot)
{
    self->upCutNo = no;
    self->upCutCam = camData;
    self->upCutArg = arg;
    self->upCutAsTask = asTask;
    if (asTask == 1) {
        slot = cScenario_taskExec_2C3890(self, cScenario_upCutTask, slot);
        if (slot >= 0) {
            int stride = 0x58;
            char *base = self->task.works;
            cTaskWork *w = (cTaskWork *)(base + slot * stride);
            w->attr |= 1;
        }
    } else {
        cScenario_upCutTask();
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cScenario_execUpCutData);
#endif

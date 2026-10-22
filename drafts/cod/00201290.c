/* NON_MATCHING func_00201290 (sn-2.95.3-136): 284 words vs 289.
 * Retail compares cDvdJob.arg6C unsigned (sltu), so the field is an unsigned priority.
 * Retail also keeps a second copy of &self->job[0] in s5 for the packing loop's state test,
 * which takes one more saved register and a 0x100-byte frame; register numbering differs throughout. */
#include "include_asm.h"
#include "godhand/cDvd.h"

#ifdef NON_MATCHING
extern void cDvd_startJobHeap(cDvd *self, cDvdJob *job);

/* Pack the queued jobs to the front, sort them by priority, and start the first one. */
__attribute__((section(".text.func_00201290")))
void func_00201290(cDvd *self)
{
    cDvdJob tmp;
    cDvdJob *best;
    int i, j;

    for (i = 0; i < CDVD_JOB_NUM; i++) {
        if (self->job[i].state == 0) {
            for (j = i + 1; j < CDVD_JOB_NUM; j++) {
                if (self->job[j].state != 0) {
                    self->job[i] = self->job[j];
                    func_00201228(self, &self->job[j]);
                    break;
                }
            }
            if (j == CDVD_JOB_NUM) break;
        }
    }
    if (self->job[0].state != 0) {
        for (i = 0; i < CDVD_JOB_NUM - 1 && self->job[i].state != 0; i++) {
            best = &self->job[i];
            for (j = i + 1; j < CDVD_JOB_NUM; j++) {
                if (self->job[j].state != 0
                    && (unsigned int)best->arg6C < (unsigned int)self->job[j].arg6C)
                    best = &self->job[j];
            }
            if (best != &self->job[i]) {
                tmp = self->job[i];
                self->job[i] = *best;
                *best = tmp;
            }
        }
    }
    if (self->job[0].state != 0) {
        self->cur = &self->job[0];
        cDvd_startJobHeap(self, &self->job[0]);
        self->queueNum = 2;
    } else {
        self->queueNum = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00201290);
#endif

/* TU: cDvd [system] - recovered C++ class. */
#include "godhand/cDvd.h"
extern char D_00580D40[];
extern int cDvd_Check(int a0, int a1);
extern int FindEntryValue_1FF9C0(char *table, char *name, int *size, char *key);
extern void *_MemoryAlloc(int size, int align, struct HeapArena *heap);
extern void cDvd_step(cDvd *self);

/* Queue a read of a named file. Returns the job id, 0 on failure. size overrides the size in bytes. */
__attribute__((section(".text.cDvd_ReadAlloc")))
int cDvd_ReadAlloc(cDvd *self, char *name, void **out, struct HeapArena *heap, int id, int size, int arg70, int arg6C)
{
    cDvdJob *job;

    *out = 0;
    job = cDvd_takeFreeJob(self);
    if (job == 0)
        return 0;

    {
        int fileNo = FindEntryValue_1FF9C0(D_00580D40, name, &job->size, job->unk0C);
        job->fileNo = fileNo;
        job->align = heap;
        job->blockNum = (unsigned int)(job->size + 0x7FF) >> 11;
        if (fileNo < 0)
            return 0;
    }

    job->state = 1;
    if (id == 0)
        job->id = func_00201788(self);
    else
        job->id = id;

    job->arg6C = arg6C;
    job->arg70 = arg70;
    job->buf = 0;
    if (size != 0)
        job->blockNum = (unsigned int)(size + 0x7FF) >> 11;

    {
        void *r = _MemoryAlloc(job->blockNum << 11, 0x80, heap);
        job->buf = r;
        if (r == 0) {
            func_00201228(self, job);
            return 0;
        }
        *out = r;
    }

    if (self->cur == 0)
        func_00201290(self);
    return job->id;
}
/* Wait until the job with the given id is no longer pending. */
__attribute__((section(".text.cDvd_CheckWait")))
void cDvd_CheckWait(cDvd *self, int id)
{
    while (cDvd_Check(self, id))
        cDvd_step(self);
}

/* NON_MATCHING func_0014B810 (sn-2.95.3-136): 56 vs 66 words
our build cross-jumps the six queue calls and keeps start in a3, retail keeps all six call blocks */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cModel.h"

#define CMODEL_NODE_SORTED 0x4080

extern int D_007476B0;
extern char D_00754C80[];
extern void func_0031A650(void *queue, int kind, int id, void *start, void *end);
extern void func_0031A600(void *queue, int kind, int id, void *start);

void func_0014B810(cModel *self, cModelNode *node, short id)
{
    char *start = node->packet[D_007476B0 & 1];
    unsigned int flags = node->dispFlags;
    int kind = self->drawKind;
    char *end = start + 0xA0;

    if (kind == CMODEL_KIND_PER_NODE) {
        if (flags & CMODEL_NODE_SORTED) {
            if (end == 0) func_0031A600(D_00754C80, 2, id, start);
            else func_0031A650(D_00754C80, 2, id, start, end);
        } else {
            if (end == 0) func_0031A600(D_00754C80, 1, 0xD, start);
            else func_0031A650(D_00754C80, 1, 0xD, start, end);
        }
    } else {
        if (end == 0) func_0031A600(D_00754C80, kind, self->id, start);
        else func_0031A650(D_00754C80, kind, self->id, start, end);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0014B810);
#endif

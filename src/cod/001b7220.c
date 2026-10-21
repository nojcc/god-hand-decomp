/* NON_MATCHING cOmBase_setMeshAlphaFromLayer (sn-2.95.3-136): set the alpha of one mesh layer.
 * Retail has a short-loop pad nop between the next load and the loop branch; ours has none. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"

extern cMeshNode *cModel_getMeshPtr(void *model, int idx);

/* Set the alpha of every mesh node on one layer. */
void cOmBase_setMeshAlphaFromLayer(void *model, int layer, float alpha) {
    cMeshNode *node = cModel_getMeshPtr(model, 0);
    if (node != 0) {
        do {
            if (node->layer == layer) {
                node->alpha = alpha;
            }
            node = node->next;
        } while (node != 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cOmBase_setMeshAlphaFromLayer);
#endif

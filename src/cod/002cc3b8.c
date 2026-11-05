/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern void cSndSeVoice_Ctor(void *a0);

/* sn-2.95.3-136 matched TU. */













/* Static constructor of the sound object: sets up its pools, then builds every slot, record, voice and node. */
__attribute__((section(".text.cSnd_StaticInit")))
void cSnd_StaticInit(int initialize, int priority) {
    cSeData *p;
    cBgmData *d;
    cSndSeVoice *v;
    cSndBgmNode *n;
    int i;
    int j;

    if (priority != 0xFFFF) return;
    if (initialize == 0) return;

    func_002C9C88(&D_005FEE00);

    p = D_005FEFF0;
    /* `i != -1` (retail materialises -1 and closes with `bne`), not `i >= 0`:
       the idiom picks the branch instruction. */
    for (i = 0x33; i != -1; i--) {
        cSeData_Init(p);
        p++;
    }

    d = D_005FFCF0;
    for (j = 1; j != -1; j--) {
        cBgmData_Init(d);
        d++;
    }

    v = D_005FFD80;
    for (j = 0x3F; j != -1; j--) {
        cSndSeVoice_Ctor(v);
        v++;
    }

    n = D_00601180;
    for (j = 0xF; j != -1; j--) {
        cSndBgmNode_Ctor(n);
        n++;
    }
}

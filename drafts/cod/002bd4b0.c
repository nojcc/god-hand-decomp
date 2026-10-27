/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"

int func_002BB868(cVec *pt, cVec *box, float margin);

/* Whether two boxes overlap: transforms the eight corners of each by its
 * matrix, then reports 1 when a corner of either lies in the other.
 * Retail keeps the return slot and temporary between the two corner arrays.
 * Still differs from retail: retail spills cornersB and keeps mtxB in a
 * saved register through the second loop; here mtxB is spilled and reloaded
 * each pass, and the second loop gets a second pointer for b. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_002BD4B0")))
int func_002BD4B0(void *mtxA, cVec *cornersA, void *mtxB, cVec *cornersB)
{
    cVec a[8];
    CVEC_TEMPS;
    cVec b[8];
    cVec *p;
    int n;
    unsigned int i;

    p = a;
    for (n = 7; n != -1; n--) {
        CVEC_ZERO(*p);
        p++;
    }
    for (i = 0; i < 8; i++) {
        CVEC_SET_APPLY(a[i], mtxA, &cornersA[i]);
    }
    p = b;
    for (n = 7; n != -1; n--) {
        CVEC_ZERO(*p);
        p++;
    }
    for (i = 0; i < 8; i++) {
        CVEC_SET_APPLY(b[i], mtxB, &cornersB[i]);
    }
    for (i = 0; i < 8; i++) {
        if (func_002BB868(&a[i], b, 0.0f) == 1) {
            return 1;
        }
    }
    for (i = 0; i < 8; i++) {
        if (func_002BB868(&b[i], a, 0.0f) == 1) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BD4B0);
#endif

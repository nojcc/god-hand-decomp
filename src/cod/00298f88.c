/* NON_MATCHING func_00298F88 (sn-2.95.3-136): 65 words off.
* This C hoists the high halves of D_00586AF0 and
 * func_002990A0 into saved registers at entry (frame 0x50, s0-s3); retail builds them just before the final
 * call (frame 0x30, s0-s1).
* Body otherwise as the matched func_002990A0. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_00754C58[];
extern signed char D_0044AC28[];
extern signed char D_0044AC30[];
extern char D_00586AF0[];
extern void *cObjBaseArray_SearchOM(char *arr, long mask);
extern void func_00297B60(char *list, void (*fn)(void));
extern void func_002990A0(void);

static inline void Set(char *tbl, signed char *str) {
    signed char *s;
    long acc = 0;
    int i = 0;
    void *om;
    if (str[0] != 0) {
        s = str;
        do {
            acc |= (long)*s << (i * 8);
            i++;
            s++;
            if (i >= 8) break;
        } while (*s != 0);
    }
    om = cObjBaseArray_SearchOM(tbl, acc);
    if (om != 0) {
        *(unsigned int *)((char *)om + 0x250) |= 2;
    }
}

__attribute__((section(".text.func_00298F88")))
void func_00298F88(void) {
    char *tbl = D_00754C58;
    Set(tbl, D_0044AC28);
    Set(tbl, D_0044AC30);
    func_00297B60(D_00586AF0, func_002990A0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00298F88);
#endif

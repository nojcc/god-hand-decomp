/* NON_MATCHING func_002C3058 (sn-2.95.3-136): 24 words vs 26; retail reloads the link word into v0 and copies it to v1 in the loop-back delay slot (plus an alignment nop), ours uses bnel with a duplicated load.
 * Loop/copy variants and as=sn tried. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cSceAtManager.h"

#define SCEAT_LIST_END   0xFFFFFFFF
#define SCEAT_LINK_UNIT  0x80000000

void func_002C3058(cSceAtManager *self, unsigned int *list, cSceAtUnit *unit)
{
    unsigned int v;

    while (*list != SCEAT_LIST_END) {
        v = *list;
        if ((v & SCEAT_LINK_UNIT) && (cSceAtUnit *)(v & 0x7FFFFFFF) == unit) {
            *list = *(unsigned int *)unit;
            return;
        }
        list = (unsigned int *)(v & 0x7FFFFFFF);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C3058);
#endif

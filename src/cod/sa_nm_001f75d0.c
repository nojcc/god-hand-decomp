#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cActionButton.h"

extern void cActionButtonEnt_reset(cActionButtonEnt *ent);
extern void TimedButton_tick(cActionButtonEnt *ent);

void func_001F75D0(cActionButton *mgr)
{
    cActionButtonEnt *ent = mgr->ent;
    int ofs = 0;
    unsigned int i = 0;

    do {
        int used = (ent->flags & 0x201) == ACTBTN_ENT_USED;

        if (used == 1) {
            if (ent->kind != ACTBTN_DEFAULT_KIND)
                cActionButtonEnt_reset(ent);
            else
                TimedButton_tick((cActionButtonEnt *)((char *)mgr + (ofs + 0x104)));
        }
        ofs += sizeof(cActionButtonEnt);
        i++;
        ent++;
    } while (i < 8);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F75D0);
#endif

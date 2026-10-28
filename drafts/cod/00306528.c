/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cObjBase.h"
#include "godhand/espSys.h"
#include "godhand/vu0.h"

#define EST_FILE_MAGIC  0x545345        /* "EST" */
#define SYSFLAG_NO_EFFECT 0x10000000    /* D_00747A78: effects are off */

extern unsigned int D_00747A78;         /* system flags */
extern int D_00747A84;                  /* system state word */
extern void getEffTypeString(char *dst, int type);
extern int func_003066D0(int count, int *ents, void *owner, unsigned int follow, cEffectParam *param, int kind,
                         int handle, unsigned short id);

/* Start effect id of the given kind on owner: look up its EST file, fill in the default parameters when
 * param is 0, and start each entry. Returns 1 when effects are off or id is 0 (for any kind but 3), 0 when
 * the file is missing or is not an EST file.
 * Still differs from retail: the -1 and 0xFF defaults take each other's registers and their byte
 * stores come after the unk44/flags stores. */
#ifdef NON_MATCHING
__attribute__((section(".text.SetEffect")))
int SetEffect(int kind, int id, void *owner, cEffectParam *param, int handle, unsigned int follow)
{
    char name[16];
    cEffectParam def;
    int *file;
    int *ents;
    unsigned long state;
    unsigned long quiet;

    if (D_00747A78 & SYSFLAG_NO_EFFECT)
        return 1;
    if (id == 0 && kind != 3)
        return 1;
    if (follow == 0xFFFFFFFF)
        follow = (unsigned int)owner;
    ents = func_00306030(D_007419A0, kind, id);
    file = ents;
    if (file == 0) {
        getEffTypeString(name, kind);
        return 0;
    }
    ents += 4;
    if (file[0] != EST_FILE_MAGIC)
        return 0;
    cEffectParam_init(&def);
    def.unk70 = 0;
    def.unk72 = 0;
    def.unk74 = 0;
    def.unk78 = 0;
    if (param == 0)
        param = &def;
    state = D_00747A84;
    quiet = (state >> 6) & 1;
    if (quiet != 0 && kind != 3)
        param->flags |= 2;
    return func_003066D0(file[1], ents, owner, follow, param, kind, handle, id);
}
#else
INCLUDE_ASM("asm/nonmatching", SetEffect);
#endif

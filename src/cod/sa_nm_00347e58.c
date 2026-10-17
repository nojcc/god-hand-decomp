/* NM, not registered. cygnus-2.96 (drop-reorder): MWSF handle concat / switch (0x347E58, 0x347FE0).
 * func_00347E58: 5 insns; retail reloads concat with lb after the concatSave store and hoists the
 *   sfd load into the delay slot; ours keeps an lbu copy.
 * func_00347FE0: 1 insn; case 1 reuses the busy=1 constant in a2 and reloads a0 (ours the reverse).
 *   Permuter matches only with a no-op "mw++; mw--;" before the case-1 call; not taken. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/mwsfHn.h"

extern char D_004591A0[];
extern char D_004591D0[];
extern char D_00459210[];

void func_00347FE0(MwsfHn *mw);
int func_00348098(MwsfHn *mw);

__attribute__((section(".text.func_00347E58")))
void func_00347E58(MwsfHn *mw, int on)
{
    int ok;
    char c;

    ok = GetField0OrZero_346828(mw);
    if (ok != 1) {
        MWSFSVM_Error(D_004591A0);
        return;
    }
    c = mw->concat;
    if (c == ok && on == 0) {
        mw->concatSave = c;
    }
    if (mw->concat == 0 && on == 1 && SFD_SetConcatPlay(mw->sfd) != 0) {
        MWSFSVM_Error(D_004591D0);
    }
    func_00348610(mw->sub284, on);
    func_00348610(mw->sub2A4, on);
    mw->concat = on;
}

#else

INCLUDE_ASM("asm/nonmatching", func_00347E58);

#endif

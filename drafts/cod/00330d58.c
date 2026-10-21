/* Direct-return error form scores 42. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int pad0;
    int pad4;
    int (*func)(char *info); /* 0x8 */
} CmdEntry;
extern char D_00453470[];
extern char D_004534C0[];
extern char D_004534E8[];
extern void func_00330920(char *work, char *info, char *name);
extern CmdEntry *variousProc(char *work, char *info, char *name);
extern void Tramp_003302B0_003302E0(char *msg);

int func_00330D58(char *name)
{
    char work[0x130];
    char info[0x130];
    CmdEntry *ent;
    char *msg;

    if (name == 0) {
        msg = D_00453470;
        goto error;
    }
    func_00330920(work, info, name);
    if (info[0] == 0) {
        msg = D_00453470;
        goto error;
    }
    ent = variousProc(work, info, name);
    if (ent == 0)
        Tramp_003302B0_003302E0(D_004534C0);
    if (ent->func == 0) {
        msg = D_004534E8;
        goto error;
    }
    return ent->func(info);
error:
    Tramp_003302B0_003302E0(msg);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00330D58);
#endif

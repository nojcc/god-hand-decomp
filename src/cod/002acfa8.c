/* sn-2.95.3-136 matched TU. */
#include "godhand/cDvd.h"

extern unsigned char D_0044AF78;
extern signed char D_00747A0C;
extern char D_0044AF80[];
extern char D_0044AF90[];
extern char D_0044AFA8[];
extern char D_0044AFC0[];
extern char D_0044AFD8[];
extern char D_0044AFF0[];
extern char D_0044B008[];
/* memset, declared void here: criStm.h's void * return changes the code. */
extern void func_003A52F0(void *a0, int a1, int a2);
extern void func_003A6C58(void *a0, void *a1, void *a2);
extern void func_003A57C4(void *a0, void *a1);

/* Append name's path for language lang (-1: the current one) to dst and
 * return 1 when that file exists; otherwise append the language 0 path and
 * return 0. mgr is not read. */
__attribute__((section(".text.cIDManager_getLocalFileName")))
int cIDManager_getLocalFileName(void *mgr, char *dst, char *name, signed char lang) {
    char buf[0x80];
    int idx = lang;
    buf[0] = D_0044AF78;
    func_003A52F0(&buf[1], 0, 0x7F);
    if (idx == -1) idx = D_00747A0C;
    if ((unsigned int)idx < 7) {
        switch (idx) {
        case 0: func_003A6C58(buf, D_0044AF80, name); break;
        case 1: func_003A6C58(buf, D_0044AF90, name); break;
        case 2: func_003A6C58(buf, D_0044AFA8, name); break;
        case 3: func_003A6C58(buf, D_0044AFC0, name); break;
        case 4: func_003A6C58(buf, D_0044AFD8, name); break;
        case 5: func_003A6C58(buf, D_0044AFF0, name); break;
        case 6: func_003A6C58(buf, D_0044B008, name); break;
        }
    }
    if (cDvd_FileExist(&D_00583F20, buf)) {
        func_003A57C4(dst, buf);
        return 1;
    }
    func_003A6C58(buf, D_0044AF80, name);
    func_003A57C4(dst, buf);
    return 0;
}

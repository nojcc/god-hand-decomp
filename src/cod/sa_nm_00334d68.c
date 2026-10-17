/* NON_MATCHING func_00334D68 (cygnus-2.96 dr): cc1 .s identical except first bne slot left unfilled (retail has lui in slot); loop .p2align nop follows from that shift */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_003DA4A0[];
extern char D_003DA398[];
extern char D_00454A00[];
extern int func_00334CA0(const char *name);
extern int htci_is_bgn_host(const char *path);
extern char *func_003A57C4(char *dst, const char *src);
extern char *func_003A53A8(char *dst, const char *src);
extern int strlen(const char *s);

void func_00334D68(const char *name, char *path)
{
    int i, n;
    char c;

    path[0] = 0;
    if (func_00334CA0(name) == 0)
        func_003A57C4(path, D_003DA4A0);
    if (htci_is_bgn_host(path) == 1) {
        func_003A53A8(path, D_003DA398);
        c = D_003DA398[strlen(D_003DA398) - 1];
        if (c != '\\' && c != '/' && c != 0 && name[0] != '\\' && name[0] != '/')
            func_003A53A8(path, D_00454A00);
    }
    func_003A53A8(path, name);
    n = strlen(path);
    for (i = 0; i < n; i++) {
        if (path[i] == '\\')
            path[i] = '/';
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00334D68);
#endif

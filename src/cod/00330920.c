#include "include_asm.h"

#ifdef NON_MATCHING
extern int strlen(const char *s);
extern void func_003A5148(char *dst, char *src, int n);
extern void toUpperStr(char *s);

void func_00330920(char *path, char *dev, char *fname)
{
    int i, j;

    if (fname == 0)
        return;

    for (i = 0; i < 0x129 && fname[i] != ':' && fname[i] != 0; i++)
        path[i] = fname[i];

    if (fname[i] == 0) {
        path[i] = 0;
        func_003A5148(dev, path, strlen(path) + 1);
        path[0] = 0;
        return;
    }

    path[i] = 0;
    i++;
    if (i == 2) {
        path[0] = 0;
        i = 0;
    }
    j = i;
    if (j < 0x129 && fname[j] != 0) {
        do {
            dev[j - i] = fname[j];
            j++;
        } while (j < 0x129 && fname[j] != 0);
    }
    dev[j - i] = 0;
    toUpperStr(path);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00330920);
#endif

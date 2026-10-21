/* NON_MATCHING func_00333880: CD file table build.
* The loop matches only with `ng` volatile, which frees fp for the hoisted config base; retail's ng is a real spill (reloads in v1, plain blez) under register pressure that a non-volatile ng doesn't reproduce. */
#include "include_asm.h"
#include "godhand/criStm.h"

#ifdef NON_MATCHING
typedef struct CdFile {
    unsigned int lsn;
    unsigned int size;
    char name[16];
    unsigned char date[8];
    unsigned int flag;
} CdFile;                         /* 0x24 */

typedef struct CdFileEnt {
    unsigned int lsn;
    unsigned int size;
} CdFileEnt;

typedef struct CdFileCfg {
    char unk00[8];
    int num;                            /* 0x08 table entries before the names */
    int len;                            /* 0x0C name length (without the nul) */
} CdFileCfg;

extern CdFileCfg D_003D9DC0;
extern char D_003D9EE8[];
extern char D_004544F8[];
extern char D_00454510[];
extern char D_00454528[];
extern char D_00454540[];

extern void func_00333390(char *name, char *path);
extern void PushGlobalD8478History_331C78(int code);
extern int func_00398DA0(int mode);
extern int func_00332838(CdFile *file, char *path);
extern void LogPrintf(char *fmt, ...);

__attribute__((section(".text.func_00333880")))
int func_00333880(char *tbl, int n)
{
    CdFile file;
    CdFileEnt *ent;
    char *name;
    int i;
    int off;
    int ok;
    int ng;

    i = 0;
    ok = 0;
    ng = 0;
    if (n > 0) {
        ent = (CdFileEnt *)tbl;
        do {
            off = D_003D9DC0.len * i + i;
            name = tbl + (D_003D9DC0.num * 8 + off);
            if (*name != 0) {
                func_00333390(name, D_003D9EE8);
                PushGlobalD8478History_331C78(0x9400);
                while (func_00398DA0(1) == 1)
                    ;
                PushGlobalD8478History_331C78(0x9401);
                PushGlobalD8478History_331C78(0x9500);
                if (func_00332838(&file, D_003D9EE8) == 1) {
                    ok++;
                    PushGlobalD8478History_331C78(0x9501);
                    ent->lsn = file.lsn;
                    ent->size = file.size;
                    LogPrintf(D_004544F8, name);
                } else {
                    ng++;
                    PushGlobalD8478History_331C78(0x9502);
                    LogPrintf(D_00454510, name);
                }
            }
            i++;
            ent++;
        } while (i < n);
    }
    LogPrintf(D_00454528, ok);
    if (ng > 0)
        func_003260C8(D_00454540, 10);
    return ok;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00333880);
#endif

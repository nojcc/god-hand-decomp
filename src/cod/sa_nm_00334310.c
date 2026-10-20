/* NON_MATCHING func_00334310 (cygnus-2.96 drop-reorder;
 * 2 diffs: retail reloads info.size into s1
 * with a second lw instead of copying v0, and the success return uses bgezl) */
#include "include_asm.h"

#ifdef NON_MATCHING
/* cygnus-2.96, -freorder-blocks dropped: func_00334310, file size lookup: cached entry first,
 * otherwise open the file, seek to the end for its size, and close it, with history markers. */
typedef struct FileInfo334 {
    int pad0;
    int size;
} FileInfo334;

extern char D_00454708[];
extern char D_00454738[];
extern char D_00454758[];
extern char D_00454780[];
extern char D_004547B8[];
extern char D_004547E0[];
extern char D_00454818[];
extern char D_00454848[];
extern char D_003DA250[];
extern void func_003351C0(char *name, FileInfo334 *info);
extern void func_00334D68(char *name, char *path);
extern void PushGlobalD8478History_331C78(int tag);
extern int func_00331EE8(char *path, int mode);
extern int func_00331DB8(int fd, int ofs, int whence);
extern int func_00331F50(int fd);
extern void func_003260C8(char *fmt, ...);
extern void func_00334008(void *obj, char *msg);

__attribute__((section(".text.func_00334310")))
int func_00334310(char *name)
{
    FileInfo334 info;
    char *path;
    int fd;
    int size;
    int r;

    if (name == 0) {
        func_00334008(0, D_00454708);
        return 0;
    }
    func_003351C0(name, &info);
    if (info.size == 0) {
        path = D_003DA250;
        func_00334D68(name, path);
        PushGlobalD8478History_331C78(0x4400);
        fd = func_00331EE8(path, 1);
        PushGlobalD8478History_331C78(0x4401);
        if (fd < 0) {
            func_003260C8(D_00454738, path);
            func_00334008(0, D_00454758);
            return 0;
        }
        if (fd == 0x10004) {
            func_003260C8(D_00454780);
            func_00334008(0, D_004547B8);
            return 0;
        }
        if (fd == 0x13) {
            func_003260C8(D_004547E0);
            func_00334008(0, D_004547B8);
            return 0;
        }
        PushGlobalD8478History_331C78(0x4600);
        func_00331DB8(fd, 0, 0);
        PushGlobalD8478History_331C78(0x4601);
        PushGlobalD8478History_331C78(0x4600);
        size = func_00331DB8(fd, 0, 2);
        PushGlobalD8478History_331C78(0x4601);
        if (size < 0) {
            func_00334008(0, D_00454818);
            PushGlobalD8478History_331C78(0x4500);
            func_00331F50(fd);
            PushGlobalD8478History_331C78(0x4501);
            return 0;
        }
        PushGlobalD8478History_331C78(0x5000);
        r = func_00331F50(fd);
        PushGlobalD8478History_331C78(0x5001);
        if (r < 0) {
            func_00334008(0, D_00454848);
            return 0;
        }
    } else
        size = info.size;
    return size;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00334310);
#endif

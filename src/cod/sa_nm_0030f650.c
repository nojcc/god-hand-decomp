/* NON_MATCHING ObjTrans (sn-2.95.3-136;
 * PARK, 7 diffs): toggle path sw/addiu delay-slot order, dead reorg addiu before vcall slot 3 */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    short delta;
    short idx;
    void (*fn)(void *, int);
} VEntry;

typedef struct {
    int pad;
    char **begin;
    char **end;
} PVec;

extern char **D_00754C30;
extern char **D_00754C38;
extern char **D_00754C50;
extern char **D_00754C58;
extern char D_005FEA60[];
extern char **func_00312DB8(char **first, char **last, char **val, int tag);
extern void *func_003A51F4(void *d, const void *s, unsigned int n);
extern int func_002C3190(void *a, int id);

static inline char **CopyTrivial(const char **f, const char **l, char **r)
{
    func_003A51F4(r, f, sizeof(char *) * (l - f));
    return r + (l - f);
}

static inline char **Copy(char **f, char **l, char **r)
{
    return CopyTrivial((const char **)f, (const char **)l, r);
}

static inline char **Erase(PVec *v, char **p)
{
    if (p + 1 != (*(char ***)((char *)v + 8)))
        Copy(p + 1, (*(char ***)((char *)v + 8)), p);
    --(*(char ***)((char *)v + 8));
    return p;
}

static inline void VCall(char *o, int slot, int arg)
{
    VEntry *e = &(*(VEntry **)(o + 0x214))[slot];
    e->fn(o + e->delta, arg);
}

static inline void VCall0(char *o, int slot)
{
    VEntry *e = &(*(VEntry **)(o + 0x214))[slot];
    ((void (*)(void *))e->fn)(o + e->delta);
}

__attribute__((section(".text.ObjTrans")))
void ObjTrans(void)
{
    char **it = ((PVec *)D_00754C30)->begin;

    if (it == ((PVec *)D_00754C30)->end)
        return;
    do {
        char *obj = *it;
        int f = *(int *)(obj + 0x250);

        if (f < 0) {
            if (f & 0x20000000) {
                char **p;
                if (*(unsigned short *)(obj + 0x2FE) == 0) {
                    Erase(((PVec *)D_00754C38), func_00312DB8(((PVec *)D_00754C38)->begin, ((PVec *)D_00754C38)->end, it, 0));
                    p = func_00312DB8(((PVec *)D_00754C50)->begin, ((PVec *)D_00754C50)->end, it, 0);
                    if (p < ((PVec *)D_00754C50)->end)
                        Erase(((PVec *)D_00754C50), p);
                } else {
                    Erase(((PVec *)D_00754C58), func_00312DB8(((PVec *)D_00754C58)->begin, ((PVec *)D_00754C58)->end, it, 0));
                }
                if (*it)
                    VCall(*it, 1, 3);
                Erase(((PVec *)D_00754C30), it);
            } else {
                if (f & 0x40000000)
                    *(int *)(obj + 0x250) = f | 0x20000000;
                else
                    *(int *)(obj + 0x250) = f | 0x40000000;
                it++;
            }
        } else if (f & 0x8000) {
            it++;
        } else {
            *(int *)(obj + 0x250) = f | 0x200000;
            obj = *it;
            if (!(*(int *)(obj + 0x250) & 0x80000)) {
                if (func_002C3190(D_005FEA60, *(unsigned char *)(obj + 0x2FD)))
                    VCall0(*it, 2);
                it++;
            } else {
                VCall0(obj, 3);
                it++;
            }
        }
    } while (it != ((PVec *)D_00754C30)->end);
}

#else
INCLUDE_ASM("asm/nonmatching", ObjTrans);
#endif

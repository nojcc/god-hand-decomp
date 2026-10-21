/* NON_MATCHING func_0030F8B0 (sn-2.95.3-136): inline vector erase gets pos copied to $a0 early and
 * the C50/C58 memmove tails are not cross-jumped as in retail. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* (drop them from the enemy or other side list, delete them and erase them from the object
 * list) and age the removal flag on the rest.
* The lists are vectors of object pointers. */
typedef struct {
    int unk00;
    char **begin;                       /* 0x04 */
    char **end;                         /* 0x08 */
} ObjVec;

extern ObjVec *D_00754C30;
extern ObjVec *D_00754C38;
extern ObjVec *D_00754C50;
extern ObjVec *D_00754C58;
extern char **func_00312DB8(char **first, char **last, char **value);
extern void *func_003A51F4(void *d, const void *s, unsigned int n);
extern void ReleaseObj(void *obj);

static inline void VecErase30F8B0(ObjVec *v, char **pos)
{
    char **next = pos + 1;

    if (next != v->end)
        func_003A51F4(pos, next, (v->end - next) * sizeof(char *));
    v->end--;
}

__attribute__((section(".text.func_0030F8B0")))
void func_0030F8B0(void)
{
    char **it;

    for (it = D_00754C30->begin; it != D_00754C30->end;) {
        char *e = *it;
        int flags = *(int *)(e + 0x250);

        if (flags < 0) {
        if (flags & 0x20000000) {
            char **p;

            if (*(unsigned short *)(e + 0x2FE) == 0) {
                p = func_00312DB8(D_00754C38->begin, D_00754C38->end, it, 0);
                VecErase30F8B0(D_00754C38, p);
                p = func_00312DB8(D_00754C50->begin, D_00754C50->end, it, 0);
                if (p < D_00754C50->end)
                    VecErase30F8B0(D_00754C50, p);
            } else {
                p = func_00312DB8(D_00754C58->begin, D_00754C58->end, it, 0);
                VecErase30F8B0(D_00754C58, p);
            }
            if (*it != 0) {
                char *vt = *(char **)(*it + 0x214);

                ((void (*)(char *, int))*(void **)(vt + 0xC))(*it + *(short *)(vt + 8), 3);
            }
            VecErase30F8B0(D_00754C30, it);
        } else {
            if (flags & 0x40000000)
                *(int *)(e + 0x250) = flags | 0x20000000;
            else
                *(int *)(e + 0x250) = flags | 0x40000000;
            it++;
        }
        } else {
            ReleaseObj(e);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0030F8B0);
#endif

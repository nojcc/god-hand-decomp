/* NON_MATCHING func_00321AD0 (ee-2.9-991111): heap sort of Elem* by key at +8 with inlined sift-down twice; frame and checks match, loop rotation and register allocation of the sift loops differ. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int pad0;
    int pad4;
    int key;
} Elem;

typedef struct {
    Elem **arr;
    unsigned int n;
} Heap;

typedef struct {
    int ret;
    int base;
    Heap h;
} Sorter;

extern void func_003A7B48(void);
extern void func_00322748(Sorter *s, Heap *h);
extern void func_003219D0(Sorter *s, Heap *h);
extern void UpdateGlobalPtrWithParam_3A7CC0(void *p);

static inline void Sift(Elem **a, unsigned int i, unsigned int n)
{
    unsigned int c;
    while ((c = i * 2) + 1 < n) {
        Elem *t;
        if (c + 2 < n && a[c + 2]->key - a[c + 1]->key > 0 && a[c + 2]->key - a[i]->key > 0) {
            t = a[i];
            a[i] = a[c + 2];
            a[c + 2] = t;
            i = c + 2;
        } else if (a[c + 1]->key - a[i]->key > 0) {
            t = a[i];
            a[i] = a[c + 1];
            a[c + 1] = t;
            i = c + 1;
        } else {
            break;
        }
    }
}

__attribute__((section(".text.func_00321AD0")))
int func_00321AD0(Sorter *s, int base)
{
    int b = s->base;
    Heap *h = &s->h;
    Elem **a;
    unsigned int n, i;

    if (b != base)
        func_003A7B48();
    func_00322748(s, h);
    if (s->base + (int)s->h.n != b)
        func_003A7B48();
    a = s->h.arr;
    n = h->n;
    for (i = n; i != 0;) {
        i--;
        Sift(a, i, n);
    }
    while (n >= 2) {
        Elem *t;
        n--;
        t = a[0];
        a[0] = a[n];
        a[n] = t;
        Sift(a, 0, n);
    }
    func_003219D0(s, h);
    UpdateGlobalPtrWithParam_3A7CC0(s->h.arr);
    return s->ret;
}

#else
INCLUDE_ASM("asm/nonmatching", func_00321AD0);
#endif

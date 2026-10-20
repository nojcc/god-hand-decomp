/* sn-2.95.3-136: func_0030FCC0, register an object in the main list and in the kind-specific list (0x2FE selects which) if both have spare capacity. Returns 1 when added, 0 when either list is full. */
typedef struct PtrVec {
    int unk00;
    void **begin;                       /* 0x04 */
    void **end;                         /* 0x08 */
    void **cap;                         /* 0x0C */
} PtrVec;

typedef struct PtrVecRef {
    PtrVec *v;
} PtrVecRef;

extern PtrVecRef D_00754C30;
extern PtrVecRef D_00754C38;
extern PtrVecRef D_00754C58;
extern void func_003129D0(PtrVecRef *list, void *obj);

static inline unsigned int vecSize(PtrVecRef *l)
{
    return l->v ? (unsigned int)(l->v->end - l->v->begin) : 0;
}

static inline unsigned int vecCap(PtrVecRef *l)
{
    PtrVec *v = l->v;
    if (v) {
        void **b = v->begin;
        void **c = v->cap;
        return c - b;
    }
    return 0;
}

static inline int vecHasRoom(PtrVecRef *l)
{
    return vecSize(l) < vecCap(l);
}

__attribute__((section(".text.func_0030FCC0")))
int func_0030FCC0(char *p)
{
    if (*(unsigned short *)(p + 0x2FE) == 0) {
        if (!vecHasRoom(&D_00754C30))
            return 0;
        if (!vecHasRoom(&D_00754C38))
            return 0;
        func_003129D0(&D_00754C30, p);
        func_003129D0(&D_00754C38, p);
        return 1;
    }
    if (!vecHasRoom(&D_00754C30))
        return 0;
    if (!vecHasRoom(&D_00754C58))
        return 0;
    func_003129D0(&D_00754C30, p);
    func_003129D0(&D_00754C58, p);
    return 1;
}

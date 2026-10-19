/* sn-2.95.3-136: func_0030FCC0, register an object in the main list and in the kind-specific list (0x2FE selects which) if both have spare capacity. Returns 1 when added, 0 when either list is full. */
typedef struct Vec30FCC0 {
    int unk00;
    void **begin;                       /* 0x04 */
    void **end;                         /* 0x08 */
    void **cap;                         /* 0x0C */
} Vec30FCC0;

typedef struct List30FCC0 {
    Vec30FCC0 *v;
} List30FCC0;

extern List30FCC0 D_00754C30;
extern List30FCC0 D_00754C38;
extern List30FCC0 D_00754C58;
extern void func_003129D0(List30FCC0 *list, void *obj);

static inline unsigned int Size30FCC0(List30FCC0 *l)
{
    return l->v ? (unsigned int)(l->v->end - l->v->begin) : 0;
}

static inline unsigned int Cap30FCC0(List30FCC0 *l)
{
    Vec30FCC0 *v = l->v;
    if (v) {
        void **b = v->begin;
        void **c = v->cap;
        return c - b;
    }
    return 0;
}

static inline int Room30FCC0(List30FCC0 *l)
{
    return Size30FCC0(l) < Cap30FCC0(l);
}

__attribute__((section(".text.func_0030FCC0")))
int func_0030FCC0(char *p)
{
    if (*(unsigned short *)(p + 0x2FE) == 0) {
        if (!Room30FCC0(&D_00754C30))
            return 0;
        if (!Room30FCC0(&D_00754C38))
            return 0;
        func_003129D0(&D_00754C30, p);
        func_003129D0(&D_00754C38, p);
        return 1;
    }
    if (!Room30FCC0(&D_00754C30))
        return 0;
    if (!Room30FCC0(&D_00754C58))
        return 0;
    func_003129D0(&D_00754C30, p);
    func_003129D0(&D_00754C58, p);
    return 1;
}

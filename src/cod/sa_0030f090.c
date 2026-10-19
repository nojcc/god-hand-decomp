/* sn-2.95.3-136: MoveObj, per-frame object update: time the pass on T0, run every live object's move virtual (unless paused), move the scroll array and print the object count. */
typedef struct VEnt30F090 {
    short delta;                        /* 0x0 this adjustment */
    short index;
    void (*fn)(void *self);             /* 0x4 */
} VEnt30F090;

typedef struct Obj30F090 {
    char pad000[0x214];
    VEnt30F090 *vtbl;                   /* 0x214 */
    char pad218[0x250 - 0x218];
    unsigned int state;                 /* 0x250 */
    char pad254[0x2F0 - 0x254];
    unsigned int flags2F0;              /* 0x2F0 */
} Obj30F090;

typedef struct ObjVec30F090 {
    int pad0;
    Obj30F090 **begin;                  /* 0x4 */
    Obj30F090 **end;                    /* 0x8 */
} ObjVec30F090;

extern unsigned int D_00747A78;
extern int D_00752CF8;
extern float D_00754C48;
extern ObjVec30F090 *D_00754C30;
extern char D_00754C38[];
extern char D_00450AF8[];

extern void cScrArray_move(void *arr);
extern void DebugPrintfWrapper(int x, int y, int a2, int a3, char *fmt, ...);

#define T0_COUNT (*(volatile int *)0x10000800)

__attribute__((section(".text.MoveObj")))
void MoveObj(void)
{
    Obj30F090 **it;
    Obj30F090 **end;
    Obj30F090 **cur;
    Obj30F090 *o;

    D_00752CF8 = T0_COUNT;
    /* only this read is volatile: the later ones reload but may sit in delay slots */
    if (!(*(volatile unsigned int *)&D_00747A78 & 0x8000000))
        D_00754C48 = 1.0f;
    if (!(D_00747A78 & 0x20000)) {
        end = D_00754C30->end;
        it = D_00754C30->begin;
        while (it != end) {
            cur = it++;
            o = *cur;
            if (o->state & 0x8000)
                continue;
            if (o->state & 0x80000000)
                continue;
            o->vtbl[10].fn((char *)o + o->vtbl[10].delta);
            (*cur)->flags2F0 &= ~3;
        }
    }
    if (!(D_00747A78 & 0x8000000))
        cScrArray_move(D_00754C38);
    D_00752CF8 = D_00752CF8 - T0_COUNT;
    DebugPrintfWrapper(100, 0x7C, 0, 4, D_00450AF8,
                       D_00754C30 != 0 ? D_00754C30->end - D_00754C30->begin : 0);
}

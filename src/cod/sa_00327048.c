/* cygnus-2.96: ADX SJ decoder: consume one block from the input SJ and hand
 * the decoded data to each output SJ. */
typedef struct Ck327048 { int f0; int f4; } Ck327048;

typedef struct OBJ OBJ;
struct OVT { char pad[0x1C]; void (*f1C)(OBJ *, int, Ck327048 *); void (*f20)(OBJ *, int, Ck327048 *); };
struct OBJ { struct OVT *vt; };

struct SJD {
    int f0;
    void *f4;
    OBJ *f8;
    OBJ *fC[2];
    Ck327048 f14;
    Ck327048 f1C[2];
    int f2C, f30, f34, f38, f3C, f40, f44;
    char pad48[0x50 - 0x48];
    void (*f50)(void *, int, int, int);
    void *f54;
};

extern int Obj33C8_GetField_18(void *sj);
extern int func_0033D2B8(void *sj);
extern int func_0033D2C0(void *sj);
extern int Obj33C8_GetShort_98(void *sj);
extern int func_003279A0(struct SJD *hn);
extern int func_0033CE98(void *sj);
extern void func_0033D278(void *sj);
extern void func_0033ACA0(Ck327048 *ck, int len, Ck327048 *head, Ck327048 *tail);

__attribute__((section(".text.func_00327048")))
void func_00327048(struct SJD *hn)
{
    Ck327048 ck, tail;
    void *sj = hn->f4;
    OBJ *in = hn->f8;
    int a, b, c, n, ch;
    int i;
    OBJ **o;
    Ck327048 *p;

    a = Obj33C8_GetField_18(sj);
    b = func_0033D2B8(sj);
    c = func_0033D2C0(sj);
    ch = Obj33C8_GetShort_98(sj);
    if (ch != 1 || func_003279A0(hn) != ch) {
        n = a - hn->f34;
        if (c >= n) c = n;
    }
    i = 0;
    func_0033ACA0(&hn->f14, b, &ck, &tail);
    in->vt->f20(in, 0, &ck);
    in->vt->f1C(in, 1, &tail);
    o = hn->fC;
    p = hn->f1C;
    for (; i < func_0033CE98(hn->f4); i++) {
        func_0033ACA0(p, c * 2, &ck, &tail);
        if (hn->f50 != 0)
            hn->f50(hn->f54, i, ck.f0, ck.f4);
        (*o)->vt->f20(*o, 1, &ck);
        p++;
        (*o)->vt->f1C(*o, 0, &tail);
        o++;
    }
    hn->f2C += c;
    hn->f30 += b;
    hn->f34 += c;
    hn->f40 += c;
    hn->f44 += b;
    func_0033D278(sj);
}

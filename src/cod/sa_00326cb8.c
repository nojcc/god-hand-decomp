/* func_00326CB8: ADX SJ header step: skip the 0x8001 header and zero padding, else hand the chunk to the decoder (cygnus-2.96, drop-reorder) */
typedef struct { char *f0; int f4; } Ck326C;

typedef struct OBJ326C OBJ326C;
struct OVT326C {
    char pad[0x18];
    void (*get)(OBJ326C *, int, int, Ck326C *);
    void (*put1)(OBJ326C *, int, Ck326C *);
    void (*put0)(OBJ326C *, int, Ck326C *);
    int (*avail)(OBJ326C *, int);
};
struct OBJ326C { struct OVT326C *vt; };

typedef struct {
    char f0;
    char st;
    char f2;
    signed char mode;
    void *sj;
    OBJ326C *in;
    OBJ326C *out;
    char pad10[4];
    Ck326C ck;
    char pad1C[0x34 - 0x1C];
    int f34;
    int f38;
    int f3C;
    int f40;
    char pad44[4];
    void (*cb)(void *);
    void *cbarg;
    char pad50[0x9C - 0x50];
    int f9C;
} Hn326C;

extern int Obj33C8_GetShort_98(void *sj);
extern int Obj3270_GetVia4_Obj33C8_18_77E8(Hn326C *hn);
extern int Obj3270_GetVia4_Obj33C8_10_77D0(Hn326C *hn);
extern int func_003279A0(Hn326C *hn);
extern int func_0033F050(char *p, int len, short *out);
extern void func_0033ACA0(Ck326C *ck, int len, Ck326C *head, Ck326C *tail);
extern void func_0033D198(void *sj, char *p, int len);
extern void func_0033D218(void *sj);

__attribute__((section(".text.func_00326CB8")))
void func_00326CB8(Hn326C *hn)
{
    Ck326C tail;
    short h;
    void *sj = hn->sj;
    OBJ326C *in = hn->in;
    int ch;

    if (hn->f3C >= 0 && hn->f40 >= hn->f3C && hn->cb != 0)
        hn->cb(hn->cbarg);
    if (hn->mode == 1 && in->vt->avail(in, 1) == 0) {
        hn->st = 3;
        return;
    }
    in->vt->get(in, 1, 0x7FFFFFFF, &hn->ck);
    if (Obj33C8_GetShort_98(sj) == 0 && hn->ck.f4 >= 4
        && (unsigned short)((*(unsigned short *)hn->ck.f0 << 8) | (unsigned char)hn->ck.f0[1]) == 0x8001) {
        hn->st = 3;
        if (func_0033F050(hn->ck.f0, hn->ck.f4, &h) == 0) {
            if (hn->ck.f4 < h) {
                in->vt->put1(in, 1, &hn->ck);
                return;
            }
            func_0033ACA0(&hn->ck, h, &hn->ck, &tail);
            in->vt->put0(in, 0, &hn->ck);
            in->vt->put1(in, 1, &tail);
        }
        if (hn->f9C == 0)
            return;
        {
            int n;
            int i;
            int found;

            while (in->vt->get(in, 1, 0x7FFFFFFF, &hn->ck), (n = hn->ck.f4) != 0) {
                for (i = 0; i < hn->ck.f4 && hn->ck.f0[i] == 0; i++)
                    ;
                found = i < n;
                func_0033ACA0(&hn->ck, i, &hn->ck, &tail);
                in->vt->put0(in, 0, &hn->ck);
                in->vt->put1(in, 1, &tail);
                if (found)
                    return;
            }
        }
        return;
    }
    if (Obj3270_GetVia4_Obj33C8_18_77E8(hn) <= hn->f34) {
        ch = Obj33C8_GetShort_98(sj);
        if (ch != 1 || func_003279A0(hn) != ch) {
            hn->st = 3;
            in->vt->put1(in, 1, &hn->ck);
            return;
        }
    }
    ch = Obj3270_GetVia4_Obj33C8_10_77D0(hn);
    if (hn->out->vt->avail(hn->out, 0) / 2 < ch) {
        in->vt->put1(in, 1, &hn->ck);
        return;
    }
    if (Obj33C8_GetShort_98(sj) == 10)
        in->vt->put1(in, 1, &hn->ck);
    if (Obj33C8_GetShort_98(sj) == 15)
        in->vt->put1(in, 1, &hn->ck);
    func_0033D198(sj, hn->ck.f0, hn->ck.f4);
    func_0033D218(sj);
}

/* cygnus-2.96, --f=-freorder-blocks: NM closer handoff. */
typedef struct {
    short type;
    short pad;
    void *id;
    int val;
    int extra;
} PadEv;

typedef struct {
    int n;
    int pad[3];
    PadEv ev[128];
} PadEvQ;

typedef struct {
    signed char active;
    char pad01[0x1F];
    void *id;
    char pad24[0xC];
    int a;
    int aPrev;
    int b;
    int bPrev;
    int cur[2];
    int prev[2];
    union {
        unsigned short h;
        struct {
            signed char c50;
            signed char c51;
        } c;
    } u50;
    signed char c52;
    signed char c53;
    signed char c54;
    signed char c55;
    signed char c56;
    signed char c57;
    char pad58[2];
    signed char c5A;
    signed char c5B;
    int i5C;
    int i60;
} PadSt;

extern PadSt D_003E2B68[];
extern int D_003DF768[];


__attribute__((section(".text.func_00337400")))
void func_00337400(int unused, PadEvQ *q)
{
    PadEv *e;
    PadSt *p;
    PadEv *base;
    int n;
    int i;
    int k;
    int one;
    int two;

    p = D_003E2B68;
    n = 0;
    base = q->ev;
    one = 1;
    for (i = 0, two = 2, e = base; i < 16; i++, p++) {
        if (p->active != one)
            continue;
        if (n == 128)
            goto done;
        if (p->c5B != p->c5A) {
            e->type = 8;
            e->id = p->id;
            e->val = p->c5B;
            e++;
            n++;
            p->c5A = p->c5B;
        }
        if (n == 128)
            goto done;
        if (p->u50.h == 0x100) {
            e->type = two;
            e->id = p->id;
            e->val = p->u50.c.c50;
            e++;
            n++;
            p->u50.c.c51 = p->u50.c.c50;
        }
        if (n == 128)
            goto done;
        if (p->c54 != p->c55) {
            e->type = 10;
            e->id = p->id;
            e->val = p->c54;
            e++;
            n++;
            p->c55 = p->c54;
        }
        if (n == 128)
            goto done;
        if (p->c56 != p->c57) {
            e->type = 12;
            e->id = p->id;
            e->val = p->c56;
            e++;
            n++;
            p->c57 = p->c56;
        }
        if (n == 128)
            goto done;
        if (p->c52 != p->c53) {
            e->type = 3;
            e->id = p->id;
            e->val = p->c52;
            e++;
            n++;
            p->c53 = p->c52;
        }
        if (n == 128)
            goto done;
        if (p->a != p->aPrev) {
            e->val = p->a;
            e->type = 4;
            e->id = p->id;
            e++;
            n++;
            p->aPrev = p->a;
        }
        if (n == 128)
            goto done;
        if (p->b != p->bPrev) {
            e->extra = D_003DF768[-p->b];
            e->val = 0;
            e->type = 5;
            e->id = p->id;
            e++;
            n++;
            p->bPrev = p->b;
        }
        if (n == 128)
            goto done;
        if (n == 127)
            goto done;
        for (k = 0; k < p->c52; k++) {
            if (p->cur[k] != p->prev[k]) {
                base[n].val = k;
                e++;
                base[n].type = 9;
                base[n].extra = p->cur[k];
                base[n].id = p->id;
                n++;
                p->prev[k] = p->cur[k];
            }
        }
        if (p->i5C != p->i60) {
            e->val = p->i5C;
            e->type = 13;
            e->id = p->id;
            e++;
            n++;
            p->i60 = p->i5C;
        }
        if (n == 128)
            goto done;
        if (p->u50.h == one) {
            e->type = two;
            e->id = p->id;
            e->val = p->u50.c.c50;
            e++;
            n++;
            p->u50.c.c51 = p->u50.c.c50;
        }
        if (n == 128)
            goto done;
    }
done:
    q->n = n;
}

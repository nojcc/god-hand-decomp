/* func_002B1C80: message draw setup with ruby scan (sn-2.95.3-136) */
typedef struct {
    char pad0[0x14];
    int flags;
    char pad18[0x54 - 0x18];
    float sx;
    float sy;
    short ox;
    short oy;
    signed char align;
    char pad61[0x68 - 0x61];
    int f68;
    char pad6C[0x74 - 0x6C];
    unsigned short *body;
    unsigned short *rubyTop;
    unsigned short *bodyEnd;
    unsigned short *ruby;
    int f84;
    char pad88[4];
    int f8C;
    char pad90[4];
    short f94;
    char pad96[0xA4 - 0x96];
    unsigned char kind;
    char padA5[0xAE - 0xA5];
    short x;
    short y;
} MessDrawWork;

extern char D_005E7510[];
extern int D_00747A0C;
extern void cMessDrawFont_setEnvInit(void *f);
extern void cMessDrawFont_setBodyData(void *f, void *body, void *end, int a3);
extern void cMessDrawFont_setRubyData(void *f, void *top, void *cur);
extern void cMessDrawFont_setDrawCounter(void *f, int a, int b);
extern void func_002ACC28(void *f, int a, int b);
extern void cMessDrawFont_setDrawPos(void *f, int mode, float x, float y);
extern void func_002AF698(void *f, float x, float y);
extern void func_002AF668(void *f, float x, float y);
extern void func_002AF6A8(void *f, int a, int b);
extern void func_002AF6B8(void *f, int a);
extern void func_002AF6E0(void *f, int a);
extern void func_002AF708(void *f, int a);
extern void cMessDrawFont_draw(void *f, int a, int b);

__attribute__((section(".text.func_002B1C80")))
void func_002B1C80(MessDrawWork *m)
{
    unsigned short *r;
    long t;

    t = m->flags;
    if (!(((unsigned long)t >> 4) & 1))
        return;
    m->ruby = m->rubyTop;
    while ((r = m->ruby) != 0) {
        if (r[0] == 0xFFFF)
            m->ruby = 0;
        else if (m->body + r[0] < m->bodyEnd)
            m->ruby = r + (r[2] + 3);
        else
            break;
    }
    cMessDrawFont_setEnvInit(D_005E7510);
    cMessDrawFont_setBodyData(D_005E7510, m->body, m->bodyEnd, m->f8C);
    cMessDrawFont_setRubyData(D_005E7510, m->rubyTop, m->ruby);
    cMessDrawFont_setDrawCounter(D_005E7510, m->f84, m->f68);
    func_002ACC28(D_005E7510, 4, 0);
    if (m->kind == 2) {
        cMessDrawFont_setDrawPos(D_005E7510, 0, (float)m->x, (float)m->y);
        func_002AF698(D_005E7510, m->sx, m->sy);
        func_002AF668(D_005E7510, (float)m->ox, (float)m->oy);
        func_002AF6A8(D_005E7510, m->align, 0);
    } else if (m->kind == 3) {
        cMessDrawFont_setDrawPos(D_005E7510, 0, (float)m->x, (float)m->y);
        func_002AF698(D_005E7510, m->sx, m->sy);
        func_002AF668(D_005E7510, (float)m->ox, (float)m->oy);
        func_002AF6A8(D_005E7510, 4, 0);
    } else {
        cMessDrawFont_setDrawPos(D_005E7510, 3, (float)m->x, (float)m->y);
        func_002AF6A8(D_005E7510, 4, 0);
        if (D_00747A0C == 0)
            func_002AF698(D_005E7510, 0.9f, 1.0f);
        else
            func_002AF698(D_005E7510, 0.9f, 1.1f);
    }
    func_002AF6B8(D_005E7510, 1);
    func_002AF6E0(D_005E7510, 0);
    t = m->flags;
    if ((((unsigned long)t >> 5) & 1UL) == 1UL)
        func_002AF708(D_005E7510, m->f94);
    cMessDrawFont_draw(D_005E7510, 0, 0);
    if (m->kind != 2) {
        func_002AF6E0(D_005E7510, 1);
        cMessDrawFont_draw(D_005E7510, 0, 0);
        func_002AF6E0(D_005E7510, 0);
    }
}

/* cygnus-2.96 | drop-freorder-blocks: SFD stream-joint write (0x36EE90). */
typedef struct {
    char *data;
    int len;
} Ck36EE90;

typedef struct Sj36EE90 Sj36EE90;

typedef struct {
    char pad0[0x18];
    void (*getChunk)(Sj36EE90 *sj, int id, int nbyte, Ck36EE90 *ck);
    char pad1C[4];
    void (*putChunk)(Sj36EE90 *sj, int id, Ck36EE90 *ck);
} SjVt36EE90;

struct Sj36EE90 {
    SjVt36EE90 *vt;
};

typedef struct {
    Sj36EE90 *sj;
    void (*cb)(int arg, int ch);
    int arg;
} Ch36EE90;

typedef struct {
    char pad0[0x11C];
    Ch36EE90 ch[4];
    int open;
    char pad150[0x524 - 0x150];
    int hdr;
    char pad528[0x580 - 0x528];
    int cur;
} Sfd36EE90;

extern char D_0045A578[];
extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern void func_0036F008(Sfd36EE90 *s, char *data, int n);

__attribute__((section(".text.func_0036EE90")))
void func_0036EE90(Sfd36EE90 *s, char *data, int n)
{
    int cur = s->cur;
    Sj36EE90 *sj = s->ch[cur].sj;
    Ck36EE90 ck;
    Ck36EE90 ck2;

    if (sj != 0) {
        sj->vt->getChunk(sj, 0, n, &ck);
        func_003A5148(ck.data, data, ck.len);
        sj->vt->putChunk(sj, 1, &ck);
        if (ck.len < n) {
            sj->vt->getChunk(sj, 0, n - ck.len, &ck2);
            func_003A5148(ck2.data, data + ck.len, ck2.len);
            sj->vt->putChunk(sj, 1, &ck2);
        }
        if (s->ch[cur].cb != 0) {
            s->ch[cur].cb(s->ch[cur].arg, cur);
        }
    }
    if (cur == 3 && s->open != 0) {
        if (s->hdr != 0) {
            func_0036F008(s, D_0045A578, 8);
        }
        func_0036F008(s, data, n);
    }
}

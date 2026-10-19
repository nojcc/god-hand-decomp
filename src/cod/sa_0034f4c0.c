/* cygnus-2.96, --f=-freorder-blocks: NM closer handoff. */
typedef struct {
    char pad0[0x3C];
    int ended;            /* 0x3C */
} Ctx34F4C0;

typedef struct {
    char pad0[0x8];
    Ctx34F4C0 *ctx;       /* 0x8 */
    char padC[0x4];
    int arg;              /* 0x10 */
    char pad14[0xC];
    int ofs;              /* 0x20 */
} Sub34F4C0;

typedef struct {
    char pad0[0x1F74];
    Sub34F4C0 sub;        /* 0x1F74 */
} Sfd34F4C0;

extern int func_00368A28(unsigned char *buf);
extern int func_0034C7D0(Sfd34F4C0 *w, int arg);
extern int sfmps_IsEffectiveEndcode(Sfd34F4C0 *w, int code);
extern void func_0034F390(Sfd34F4C0 *w, int flag);
extern void func_0034F658(Sfd34F4C0 *w, int *out);

__attribute__((section(".text.func_0034F4C0")))
int func_0034F4C0(Sfd34F4C0 *w, unsigned char *buf, int len, int len2)
{
    Sub34F4C0 *s = &w->sub;
    Ctx34F4C0 *c = s->ctx;
    int arg = s->arg;
    int code;
    int r;

    if (len >= 4) {
        code = func_00368A28(buf);
        if (code == 0x80000) {
            if (s->ofs < 0)
                s->ofs = func_0034C7D0(w, arg) + 4;
            c->ended = 1;
        } else if (code != 0) {
            c->ended = 0;
        }
    } else {
        code = 0;
    }
    if (sfmps_IsEffectiveEndcode(w, code)) {
        func_0034F390(w, 1);
        return 0;
    }
    if (len2 < 4) {
        func_0034F658(w, &r);
        if (r != 0)
            return 0;
    }
    if (len >= 0x40)
        return 1;
    if (code != 0x10000 && code != 0x40000)
        return 1;
    func_0034F658(w, 0);
    return 0;
}

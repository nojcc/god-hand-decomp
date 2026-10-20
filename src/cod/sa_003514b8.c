/* cygnus-2.96: func_003514B8, Sofdec per-picture decode step (term/endcode/skip dispatch). */
typedef struct {
    char pad0[0x78];
    int f78;
    char pad7C[0x170 - 0x7C];
    int f170;
} SfdStmView;

extern int func_00356E98(char *sfd);
extern int func_00351C00(char *sfd);
extern void func_003554D8(char *sfd);
extern int func_00351170(char *sfd);
extern int func_0034C890(char *sfd, int a, int *len);
extern void func_003554F8(char *sfd, int on);
extern void func_003517D0(char *sfd);
extern int SFCON_IsEndcodeSkip(char *sfd);
extern int SFCON_IsVideoEndcodeSkip(char *sfd);
extern int sfmpv_Concat(char *sfd, int len);
extern void sfmpv_DiscardSec(char *sfd, int len);
extern int sfmpv_IsTerm(char *sfd, int n, int code);
extern void func_00351780(char *sfd, int *buf);
extern int func_00351CB0(char *sfd, int *buf, int len, int code, int *st);
extern int func_00353250(char *sfd, int *buf);
extern int func_003537C0(char *sfd, int len);
extern int func_00353928(char *sfd);
extern int func_00354478(char *sfd, int len, int mask);

__attribute__((section(".text.func_003514B8")))
int func_003514B8(char *sfd, int n, int code, int cont, int *out)
{
    char *st = sfd + 0x950;
    char *w = sfd + 0x1FB8;
    int a;
    SfdStmView *s;
    int err;
    int buf[4];
    int len;
    int term;
    int t;

    *out = 0;
    s = (SfdStmView *)*(int *)(w + 8);
    a = *(int *)(w + 0x10);
    *(int *)(st + 0x28) = 0;
    if (func_00356E98(sfd) == 0) {
        if (func_00351C00(sfd) == 1) {
            func_003554D8(sfd);
            return 0;
        }
        *(int *)(st + 0x28) = 1;
        return func_00351170(sfd);
    }
    if (s->f78 != 0xCC || s->f170 == 0)
        code &= 0xCC;
    err = func_0034C890(sfd, a, &len);
    if (err != 0)
        return 0;
    if (len == 0)
        return err;
    if (code & 0xC8)
        func_003554F8(sfd, 1);
    if (code == 0x80) {
        func_003517D0(sfd);
        if (SFCON_IsEndcodeSkip(sfd)) {
            if (sfmpv_Concat(sfd, len) == 0)
                { *out = 1; goto end; }
            goto end;
        }
        if (SFCON_IsVideoEndcodeSkip(sfd)) {
            sfmpv_DiscardSec(sfd, len);
            { *out = 1; goto end; }
        }
    }
    if (cont == 0) {
        if (sfmpv_IsTerm(sfd, n, code)) {
            func_003554D8(sfd);
            goto end;
        }
        if (n < 5) {
            *(int *)(st + 0x28) = 1;
            goto end;
        }
    }
    if (code & 0x4C) {
        func_00351780(sfd, buf);
        err = func_00351CB0(sfd, buf, len, code, &term);
        if (err != 0)
            return err;
        t = term;
        if (t == 0) {
            if (code & s->f78)
                s->f78 = 0xCC;
            s->f170 = 1;
        }
        if (code == 0x40 && t == -2)
            s->f78 = 0xC0;
    } else if (code & 2) {
        func_00351780(sfd, buf);
        if (func_00353250(sfd, buf)) {
            err = func_003537C0(sfd, len);
            if (err == 0)
                { *out = 1; goto end; }
            goto end;
        } else {
            err = func_00353928(sfd);
            goto end;
        }
    } else {
        if (code == 0x80)
            goto end;
        if (func_00354478(sfd, len, 0xCC) <= 0)
            goto end;
    }
    *out = 1;
end:
    return err;
}

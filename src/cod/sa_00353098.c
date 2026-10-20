/* cygnus-2.96: func_00353098, check the configured frame size against
 * the work buffer, then split the buffer into per-frame pointers. */
typedef struct {
    int w;
    int h;
} Size353098;

typedef struct {
    int pad00;
    int pad04;
    int w;                      /* 0x08 */
    int h;                      /* 0x0C */
    int pad10;
    int bufW;                   /* 0x14 */
    int bufH;                   /* 0x18 */
    int nFrm;                   /* 0x1C */
    char *buf;                  /* 0x20 */
} Cfg353098;

typedef struct {
    int pad00;
    Cfg353098 cfg;              /* 0x04 */
    char pad28[0x30 - 0x28];
    char *frm[(0x178 - 0x30) / 4]; /* 0x30 */
    int nFrm;                   /* 0x178 */
    int pad17C;
    char sub[1];                /* 0x180 */
} Mgr353098;

typedef struct {
    char pad0000[0x38];
    int mode;                   /* 0x38 */
    char pad003C[0x1FC0 - 0x3C];
    Mgr353098 *mgr;             /* 0x1FC0 */
} Hn353098;

extern int func_0034DD70(void *a0, unsigned int a1);
extern void func_00354A70(void *sub, char **frm, int n);

static inline unsigned int FrmSize353098(int mode, int w, int h)
{
    int mbw = w / 16;
    int mbh = h / 16;

    if (mode == 2)
        return mbw * mbh * 1024 + 64;
    return mbw * mbh * 384 + 64;
}

__attribute__((section(".text.func_00353098")))
int func_00353098(Hn353098 *hn, Size353098 *sz)
{
    Mgr353098 *mgr = hn->mgr;
    Cfg353098 *cfg = &mgr->cfg;
    int mode = hn->mode;
    int n = cfg->nFrm;
    unsigned int size;
    int mbw;
    int mbh;
    char *p;
    char *buf;
    int i;

    if (cfg->w * cfg->h < sz->w * sz->h)
        return func_0034DD70(hn, 0xFF000F17);
    size = FrmSize353098(mode, sz->w, sz->h);
    mbw = cfg->bufW / 16;
    mbh = cfg->bufH / 16;
    if (mode == 2) {
        if (mbw * mbh * 1024 + 64 >= size)
            goto ok;
    } else {
        if (mbw * mbh * 384 + 64 >= size)
            goto ok;
    }
    return func_0034DD70(hn, 0xFF000F18);
ok:
    buf = cfg->buf;
    if (buf != 0) {
        for (i = 0; i < n; i++)
            mgr->frm[i] = buf + i * size;
    } else {
        for (i = 0; i < n; i++)
            ;
    }
    mgr->nFrm = n;
    func_00354A70(mgr->sub, mgr->frm, n);
    return 0;
}

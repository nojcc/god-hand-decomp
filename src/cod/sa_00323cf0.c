/* cygnus-2.96: func_00323CF0, read-request start: wrap buf in a stream joint of nsct sectors, issue the read and destroy the joint again on failure, with entry and exit trace calls. */
typedef struct SjIf323CF0 {
    void *fn[3];
    void (*destroy)(void *sj);          /* 0x0C */
} SjIf323CF0;

typedef struct Sj323CF0 {
    SjIf323CF0 *vt;
} Sj323CF0;

typedef struct Rd323CF0 {
    char unk00;
    signed char stat;                   /* 0x01 2 = busy */
    char busy;                          /* 0x02 */
    char unk03[5];
    Sj323CF0 *sj;                       /* 0x08 */
    char unk0C[0x18];
    void *buf;                          /* 0x24 */
    int size;                           /* 0x28 */
} Rd323CF0;

extern char D_00451718[];
extern char D_00451740[];
extern char D_00451770[];
extern char D_00451798[];
extern int D_003EB708;

extern void func_003228C0(int id, int phase, Rd323CF0 *h, int nsct, void *buf);
extern void func_0033F130(char *msg);
extern Sj323CF0 *func_003395A0(void *buf, int size, int mode);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void Forward3B0640_33F3D0(void *buf, int size);
extern int func_00323BE0(Rd323CF0 *h, int nsct, Sj323CF0 *sj);

__attribute__((section(".text.func_00323CF0")))
int func_00323CF0(Rd323CF0 *h, int nsct, void *buf)
{
    Sj323CF0 *sj;
    int size;
    int n;

    func_003228C0(4, 0, h, nsct, buf);
    if (h == 0) { func_0033F130(D_00451718); return -3; }
    if (nsct < 0) { func_0033F130(D_00451740); return -3; }
    if (buf == 0) { func_0033F130(D_00451770); return -3; }
    if (h->stat == 2)
        return 0;
    if (h->sj != 0) {
        func_0033F130(D_00451798);
        return -1;
    }
    size = nsct << 11;
    sj = func_003395A0(buf, size, 0);
    if (sj == 0)
        return -2;
    Forward33B658_33E678();
    h->buf = buf;
    h->sj = sj;
    h->size = size;
    if (D_003EB708 == 1)
        Forward3B0640_33F3D0(buf, size);
    Forward33B670_33E690();
    n = func_00323BE0(h, nsct, h->sj);
    if (n <= 0) {
        Forward33B658_33E678();
        if (h->sj != 0) {
            h->sj->vt->destroy(h->sj);
            h->sj = 0;
        }
        Forward33B670_33E690();
    }
    h->busy = 0;
    func_003228C0(4, 1, h, nsct, buf);
    return n;
}

/* cygnus-2.96, --f=-freorder-blocks: NM closer handoff. */
typedef struct Ck36DFF0 { char *data; int len; } Ck36DFF0;

typedef struct OBJ OBJ;
struct OVT {
    char pad[0x18];
    void (*getChunk)(OBJ *, int, int, Ck36DFF0 *);      /* 0x18 */
    void (*ungetChunk)(OBJ *, int, Ck36DFF0 *);         /* 0x1C */
    void (*putChunk)(OBJ *, int, Ck36DFF0 *);           /* 0x20 */
};
struct OBJ { struct OVT *vt; };

typedef struct Cnt36DFF0 {
    char pad000[0x308];
    int f308;                           /* 0x308 */
    int f30C;                           /* 0x30C */
    char pad310[0x494 - 0x310];
    int ready;                          /* 0x494 */
    int bytes;                          /* 0x498 */
    int readyTotal;                     /* 0x49C */
    int bytesTotal;                     /* 0x4A0 */
} Cnt36DFF0;

extern int MPV_GoNextDelimSj(OBJ *sj);
extern char *func_0036E380(char *dec, char *p);
extern char *func_0036EB58(char *dec, char *p);
extern char *func_0036EC78(char *dec, char *p);
extern char *func_0036F048(char *dec, char *p);
extern char *func_00372028(char *dec, char *p);
extern char *func_00372590(char *dec, char *p);
extern void func_0033ACA0(Ck36DFF0 *ck, int len, Ck36DFF0 *head, Ck36DFF0 *tail);

__attribute__((section(".text.func_0036DFF0")))
int func_0036DFF0(char *dec, OBJ *sj)
{
    Ck36DFF0 ck;
    Ck36DFF0 tail;
    Cnt36DFF0 *c;
    char *end;
    int d;

    c = (Cnt36DFF0 *)(dec + 0x160);
    c->ready = 0;
    c->bytes = 0;
    c->f308 = 0;
    c->f30C = 0;
    for (;;) {
        if ((d = MPV_GoNextDelimSj(sj)) == 0)
            break;
        sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
        end = 0;
        switch (d) {
        case 0x40:
            end = func_0036E380(dec, ck.data);
            break;
        case 0x80:
            end = func_0036EB58(dec, ck.data);
            break;
        case 0x20:
            end = func_0036EC78(dec, ck.data);
            break;
        case 0x10:
            end = func_0036F048(dec, ck.data);
            break;
        case 0x08:
            end = func_00372028(dec, ck.data);
            break;
        case 0x04:
            end = func_00372590(dec, ck.data);
            break;
        }
        if (end == 0) {
            sj->vt->ungetChunk(sj, 1, &ck);
            break;
        }
        func_0033ACA0(&ck, end - ck.data, &ck, &tail);
        sj->vt->putChunk(sj, 0, &ck);
        sj->vt->ungetChunk(sj, 1, &tail);
        if (c->ready != 0)
            break;
    }
    c->readyTotal += c->ready;
    c->bytesTotal += c->bytes;
    return c->ready != 0 ? -2 : 0;
}

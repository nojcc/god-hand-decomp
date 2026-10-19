/* cygnus-2.96, -freorder-blocks dropped. Once the decoder reports state 3 and neither open
 * slot still has data queued, finish the stream: stop, concat-play check, close both slots. */
typedef struct Sj348E18 Sj348E18;

typedef struct SjIf348E18 {
    void *fn[9];
    int (*Query)(Sj348E18 *sj, int id);     /* 0x24 */
} SjIf348E18;

struct Sj348E18 {
    SjIf348E18 *vt;
};

typedef struct Slot348E18 {
    int flag;           /* 0x00 */
    int pad4[4];
    Sj348E18 *sj;       /* 0x14 */
    int pad18[2];
} Slot348E18;

typedef struct Obj348E18 {
    char pad0[0x3C];
    void *sfd;                  /* 0x3C */
    char pad40[0x70 - 0x40];
    signed char concat;         /* 0x70 */
    char pad71;
    signed char stopped;        /* 0x72 */
    char pad73[0x284 - 0x73];
    Slot348E18 slot[2];         /* 0x284 */
} Obj348E18;

extern char D_004592D0[];
extern int func_00359E80(void *sfd);
extern int func_003484F0(Slot348E18 *s);
extern void func_00345B38(Obj348E18 *o);
extern void func_00345F48(Obj348E18 *o, int mode);
extern int SFD_SetConcatPlay(void *sfd);
extern void MWSFSVM_Error(char *msg);
extern void func_00348550(Slot348E18 *s, int a);

__attribute__((section(".text.func_00348E18")))
void func_00348E18(Obj348E18 *o)
{
    Slot348E18 *s;
    Slot348E18 *first;
    int c;

    if (func_00359E80(o->sfd) != 3)
        return;
    s = &o->slot[0];
    first = s;
    if (s->flag == 1 && func_003484F0(s) != 2 && s->sj->vt->Query(s->sj, 1) != 0)
        return;
    s = &o->slot[1];
    if (s->flag == 1 && func_003484F0(s) != 2 && s->sj->vt->Query(s->sj, 1) != 0)
        return;
    func_00345B38(o);
    c = o->stopped;
    if (c == 0)
        func_00345F48(o, 0);
    c = o->concat;
    if (c == 1 && SFD_SetConcatPlay(o->sfd) != 0)
        MWSFSVM_Error(D_004592D0);
    if (o->stopped != 0)
        return;
    func_00348550(first, 0);
    func_00348550(s, 0);
}

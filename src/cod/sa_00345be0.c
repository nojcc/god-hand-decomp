/* cygnus-2.96, as=sn, --f=-freorder-blocks: NM closer handoff. */
typedef struct Mwsf345BE0 {
    char pad0[4];
    int stat;
    char pad8[0x34];
    int reqStart;
    char pad40[0x31];
    char play;
    signed char mode;
    char pad73[0x11];
    int unk84;
    char pad88[0x1FC];
    char buf0[0x20];
    char buf1[0x30];
    int unk2D4;
} Mwsf345BE0;

extern char D_00457EF8[];
extern char D_00457F28[];
extern void GetD003EC7E0_3452B0(void);
extern int func_00343D68(Mwsf345BE0 *);
extern void MWSFSVM_Error(char *);
extern void func_003487C0(Mwsf345BE0 *, int);
extern void func_00347420(Mwsf345BE0 *);
extern int func_003473A0(Mwsf345BE0 *);
extern void func_00347400(Mwsf345BE0 *);
extern void Obj0000_Init_Fields_B4_B8_BC_Entries(Mwsf345BE0 *);
extern void func_00345D10(Mwsf345BE0 *);
extern void func_00345AF8(Mwsf345BE0 *);
extern void func_00345F48(Mwsf345BE0 *, int);
extern void func_00348550(char *, int);
extern void func_00348440(char *);

__attribute__((section(".text.func_00345BE0")))
void func_00345BE0(Mwsf345BE0 *m)
{
    char *b0 = m->buf0;

    GetD003EC7E0_3452B0();
    if (m->reqStart != 0) {
        if (func_00343D68(m) != 0) {
            MWSFSVM_Error(D_00457EF8);
            return;
        }
        func_003487C0(m, 0);
        func_003487C0(m, 1);
        func_00347420(m);
        if (func_003473A0(m) != 0) {
            MWSFSVM_Error(D_00457F28);
            return;
        }
        func_00347400(m);
        Obj0000_Init_Fields_B4_B8_BC_Entries(m);
    }
    func_00345D10(m);
    func_00345AF8(m);
    func_00345F48(m, m->mode);
    func_00348550(b0, 1);
    func_00348550(m->buf1, 1);
    func_00348440(b0);
    func_00348440(m->buf1);
    m->unk84 = 0;
    m->unk2D4 = 0;
    m->play = 0;
    m->stat = 1;
}

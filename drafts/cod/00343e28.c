/* NON_MATCHING func_00343E28 (cygnus-2.96): mwPly create; retail cross-jumps the Error(msg) tails with the message built straight in a0 (ours needs a msg variable, so %hi goes through v0), and its free-slot loop keeps one iterator copy with the constant 1 in a1 */
#include "include_asm.h"
#include "godhand/criStm.h"

#ifdef NON_MATCHING
typedef struct {
    int f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C;
} Cprm343;

typedef struct {
    int used;
    int f4;
    Cprm343 cprm;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    char pad60[8];
    int f68;
    int f6C;
    char f70, f71, f72, f73;
    int f74;
    char pad78[0x84 - 0x78];
    int f84;
    char pad88[0xA8 - 0x88];
    int fA8;
    int fAC;
    int fB0;
    char padB4[0x17C - 0xB4];
    int f17C;
    char pad180[0x1C0 - 0x180];
    int f1C0;
    char pad1C4[0x1E0 - 0x1C4];
    int f1E0;
    char pad1E4[0x2D8 - 0x1E4];
    int f2D8;
    int f2DC;
    int f2E0;
    int pad2E4;
    int f2E8;
    char pad2EC[0x2FC - 0x2EC];
    int f2FC;
    int f300;
} Ply343;

extern char D_00457448[];
extern char D_00457478[];
extern char D_004574C8[];
extern char D_00457508[];
extern char D_00457530[];
extern char D_00457558[];
extern char D_00457580[];
extern char D_004575A0[];
extern int func_00344278(int *a0);
extern char *GetD003EC7E0_3452B0(void);
extern void func_00345750(int err);
extern void MWSFSVM_Error(char *msg);
extern int mwsfcre_IsOkUsrMalloc(Cprm343 *cprm);
extern void Obj0000_Set_Fields_1EC_280_Zero(Ply343 *ply, Cprm343 *cprm);
extern int func_00343340(Ply343 *ply, Cprm343 *cprm);
extern void func_00346410(Ply343 *ply);
extern void func_00343AE8(Ply343 *ply);
extern void mwsfcre_CalcWorkStmBuf(Cprm343 *cprm, int *a, int *b, int *c, int *d, int *e, int *f);
extern void func_00343C18(Ply343 *ply, Cprm343 *cprm, int a, int b);
extern int Obj0000_Call_003395A0_Field_1C4_1C8_1CC(Ply343 *ply);
extern int func_00338B90(int a, int b);
extern int SFD_GetTrHn(int sfd, int type, int *out);
extern void func_00349718(Ply343 *ply, int a);
extern void func_00349728(Ply343 *ply, int a);
extern int Forward327D00_349AA0(int a);
extern void func_00346100(Ply343 *ply);
extern int func_003353C0(int a);
extern void func_00335580(int a, int b);
extern long func_00344300(Ply343 *ply);
extern int Forward35F970_346C18(int a, int b, int c, int d);
extern void func_003471B8(Ply343 *ply, int a);
extern int func_00347310(Ply343 *ply);
extern int func_003473A0(Ply343 *ply);
extern void func_00347400(Ply343 *ply);
extern void Obj0000_Init_Fields_B4_B8_BC_Entries(Ply343 *ply);
extern void func_00345040(Ply343 *ply);
extern void Forward3443E0_3443C8(Ply343 *ply);

Ply343 *func_00343E28(Cprm343 *cprm)
{
    int w[6];
    char *base;
    int *wk;
    Ply343 *ply;
    int sfd;
    int i;
    char *msg;
    int v;

    if (cprm == 0) {
        msg = D_00457448;
        goto err;
    }
    if (func_00344278() != 1)
        return 0;
    base = GetD003EC7E0_3452B0();
    ply = (Ply343 *)(base + 0x6C);
    wk = (int *)(base + 4);
    for (i = 0; i < 8; i++) {
        if (ply->used != 1)
            break;
        ply = (Ply343 *)(base + 0x6C) + i + 1;
    }
    if (i == 8) {
        func_00345750(-11);
        msg = D_00457478;
        goto err;
    }
    if (mwsfcre_IsOkUsrMalloc(cprm) == -1) {
        msg = D_004574C8;
err:
        MWSFSVM_Error(msg);
        return 0;
    }
    func_003A52F0(ply, 0, sizeof(Ply343));
    Obj0000_Set_Fields_1EC_280_Zero(ply, cprm);
    ply->cprm = *cprm;
    sfd = func_00343340(ply, cprm);
    ply->f3C = sfd;
    if (sfd == 0) {
        msg = D_00457508;
        goto errf;
    }
    func_00346410(ply);
    func_00343AE8(ply);
    mwsfcre_CalcWorkStmBuf(cprm, &w[0], &w[1], &w[2], &w[3], &w[4], &w[5]);
    func_00343C18(ply, cprm, wk[1], wk[2]);
    ply->f1C0 = Obj0000_Call_003395A0_Field_1C4_1C8_1CC(ply);
    if (ply->f1C0 == 0) {
        msg = D_00457530;
        goto errf;
    }
    ply->f1E0 = func_00338B90(0, 0);
    if (ply->f1E0 == 0) {
        msg = D_00457558;
        goto errf;
    }
    ply->f38 = 1;
    ply->f58 = w[0];
    ply->f68 = 0;
    ply->f4 = 0;
    ply->f4C = cprm->f20;
    ply->f50 = cprm->f20;
    if (SFD_GetTrHn(sfd, 3, &ply->f44) != 0)
        ply->f44 = 0;
    ply->f6C = 1;
    ply->f70 = 0;
    ply->f71 = 0;
    ply->f72 = 0;
    ply->f73 = 0;
    ply->f5C = 0;
    func_00349718(ply, 0);
    func_00349728(ply, 0);
    ply->f54 = 1;
    ply->f84 = 0;
    ply->f40 = Forward327D00_349AA0(ply->f1C0);
    if (ply->f40 == 0)
        goto fail;
    func_00346100(ply);
    ply->f48 = func_003353C0(ply->f1C0);
    ply->f74 = 0;
    func_00335580(ply->f48, ply->f40);
    if (func_00344300(ply) == -1)
        goto fail;
    v = Forward35F970_346C18(ply->fAC, ply->fB0, cprm->f8, cprm->fC);
    if (v == 0) {
        msg = D_00457580;
        goto errf;
    }
    ply->fA8 = v;
    func_003471B8(ply, ply->cprm.f20);
    ply->f17C = func_00347310(ply);
    if (func_003473A0(ply) != 0) {
        msg = D_004575A0;
errf:
        MWSFSVM_Error(msg);
fail:
        Forward3443E0_3443C8(ply);
        return 0;
    }
    func_00347400(ply);
    Obj0000_Init_Fields_B4_B8_BC_Entries(ply);
    func_00345040(ply);
    ply->used = 1;
    ply->f2FC = -1;
    ply->f2E8 = 0;
    ply->f2D8 = 0;
    ply->f2DC = 0;
    ply->f2E0 = 0;
    ply->f300 = 0;
    return ply;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00343E28);
#endif

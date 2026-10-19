/* cygnus-2.96, --f=-freorder-blocks: NM closer handoff. */
typedef struct TPrm325638 {
    int prio_lock;                      /* 0x00 */
    int prio_safe;                      /* 0x04 */
    int prio_mwidle;                    /* 0x08 */
    int prio_usridle;                   /* 0x0C */
    int prio_main;                      /* 0x10 */
    int prio_usrvsync;                  /* 0x14 */
} TPrm325638;

typedef struct TCur325638 {
    int prio_lock;                      /* 0x00 */
    int prio_safe;                      /* 0x04 */
    int unk08;
    int prio_mwidle;                    /* 0x0C */
    int prio_usridle;                   /* 0x10 */
    int prio_main;                      /* 0x14 */
    int prio_usrvsync;                  /* 0x18 */
} TCur325638;

typedef struct ThreadStat325638 {
    int status;
    void *func;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;                /* 0x18 */
    int pad[5];
} ThreadStat325638;

extern volatile int D_003C80A0;
extern int D_003C80A4;
extern volatile int D_003C80FC;
extern TCur325638 D_003C80B0;
extern volatile int D_003C8148;
extern int D_003CF9D8;
typedef struct Cb325638 { void (*fn)(int); int arg; } Cb325638;
extern Cb325638 D_00755C28;
extern Cb325638 D_00755C20;

extern void func_0033BE80(void);
extern void func_00324C90(void);
extern void func_00324D18(void);
extern void Forward324D88_324E70(void);
extern void Obj0000_Set_D_007588A0_Pair_33BC18(void (*fn)(void), int obj);
extern void Obj0000_Set_D_007588A8_XY_33BC30(void (*fn)(void), int obj);
extern int GetThreadId(void);
extern int ReferThreadStatus(int tid, ThreadStat325638 *st);
extern int ChangeThreadPriority(int tid, int prio);
extern void func_003253C0(void);
extern void func_00325468(void);
extern void func_003254F0(void);
extern void func_00325578(void);
extern void SVM_SetCbBdr(int id, void (*fn)(void), int obj);

__attribute__((section(".text.func_00325638")))
void func_00325638(TPrm325638 *prm)
{
    ThreadStat325638 st;

    D_003C80A0;
    D_003C80FC = 0;
    if (D_003C80A4 == 0) {
        func_0033BE80();
        Obj0000_Set_D_007588A0_Pair_33BC18(func_00324C90, 0);
        Obj0000_Set_D_007588A8_XY_33BC30(func_00324D18, 0);
        D_00755C20.fn = 0;
        D_00755C20.arg = 0;
        D_00755C28.fn = 0;
        D_00755C28.arg = 0;
        if (prm == 0) {
            D_003C80B0.prio_main = 0x18;
            D_003C80B0.prio_lock = 1;
            D_003C80B0.prio_safe = 8;
            D_003C80B0.prio_mwidle = 0x10;
            D_003C80B0.prio_usridle = 0x12;
            D_003C80B0.prio_usrvsync = 0x19;
        } else {
            D_003C80B0.prio_main = prm->prio_main;
            D_003C80B0.prio_lock = prm->prio_lock;
            D_003C80B0.prio_safe = prm->prio_safe;
            D_003C80B0.prio_mwidle = prm->prio_mwidle;
            D_003C80B0.prio_usridle = prm->prio_usridle;
            D_003C80B0.prio_usrvsync = prm->prio_usrvsync;
        }
        D_003C8148 = GetThreadId();
        ReferThreadStatus(D_003C8148, &st);
        D_003CF9D8 = st.currentPriority;
        func_003253C0();
        func_00325468();
        func_003254F0();
        func_00325578();
        ChangeThreadPriority(D_003C8148, D_003C80B0.prio_main);
        SVM_SetCbBdr(6, Forward324D88_324E70, 0);
    }
    D_003C80A4++;
}

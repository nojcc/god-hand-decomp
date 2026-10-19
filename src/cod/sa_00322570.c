/* ee-2.9-991111: __frame_state_for, libgcc frame.c: find the FDE for a PC, run its CIE and FDE
 * call-frame instructions up to that PC and copy the resulting frame state out. */
typedef struct FdeFS {
    unsigned int length;
    int CIE_delta;
    void *pc_begin;
    void *pc_range;
} FdeFS;

typedef struct CieInfoFS {
    char *augmentation;   /* 0x00 */
    void *eh_ptr;         /* 0x04 */
    int code_align;       /* 0x08 */
    int data_align;       /* 0x0C */
    unsigned int ra_regno; /* 0x10 */
} CieInfoFS;

typedef struct FrameStateFS {
    void *cfa;                          /* 0x000 */
    void *eh_ptr;                       /* 0x004 */
    char pad008[0x29A - 0x008];
    unsigned short retaddr_column;      /* 0x29A */
    char pad29C[0x2F0 - 0x29C];
} __attribute__((aligned(8))) FrameStateFS;

typedef struct FrameStateInternalFS {
    FrameStateFS s;
    char pad2F0[8];
} FrameStateInternalFS;

extern FdeFS *func_00321F48(void *pc);
extern void *func_00322030(FdeFS *f, CieInfoFS *c);
extern void *func_00322138(void *insn, FrameStateInternalFS *state, CieInfoFS *info, void **pc);
extern unsigned char *func_00321938(unsigned char *p, int *val);
extern void *func_003A52F0(void *d, int c, unsigned int n);
extern void *memcpy(void *d, const void *s, unsigned int n);

#define get_cie(f) ((FdeFS *)((char *)&(f)->CIE_delta - (f)->CIE_delta))
#define next_fde(f) ((FdeFS *)((char *)(f) + (f)->length + sizeof((f)->length)))

__attribute__((section(".text.__frame_state_for")))
FrameStateFS *__frame_state_for(void *pc_target, FrameStateFS *state_in)
{
    FdeFS *f;
    void *insn, *end, *pc;
    CieInfoFS info;
    FrameStateInternalFS state;

    f = func_00321F48(pc_target);
    if (f == 0)
        return 0;

    insn = func_00322030(f, &info);
    if (insn == 0)
        return 0;

    func_003A52F0(&state, 0, sizeof(state));
    state.s.retaddr_column = info.ra_regno;
    state.s.eh_ptr = info.eh_ptr;

    end = next_fde(get_cie(f));
    while (insn < end)
        insn = func_00322138(insn, &state, &info, 0);

    insn = ((FdeFS *)f) + 1;

    if (info.augmentation[0] == 'z') {
        int i;

        insn = func_00321938(insn, &i);
        insn += i;
    }

    end = next_fde(f);
    pc = f->pc_begin;
    while (insn < end && pc <= pc_target)
        insn = func_00322138(insn, &state, &info, &pc);

    memcpy(state_in, &state.s, sizeof(state.s));
    return state_in;
}

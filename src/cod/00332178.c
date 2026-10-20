/* NON_MATCHING func_00332178: DTX remote slot open with alignment checks.
* Remaining: retail keeps id in t0 (mine a1) and reuses t0 for the used byte, and retail fills the arg2-check beqz delay slot with the following bufsize andi; else-if chains and wrapped bodies are far worse (91-99). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct DtxRmt {
    signed char used;                   /* 0x00 */
    unsigned char unk01;                /* 0x01 */
    unsigned char unk02;                /* 0x02 */
    char pad03;
    int rmt;                            /* 0x04 */
    int unk08;                          /* 0x08 */
    char *buf;                          /* 0x0C */
    int size;                           /* 0x10 */
    char *end;                          /* 0x14 */
    int arg2;                           /* 0x18 */
    int bufsize;                        /* 0x1C */
    void (*fn20)(void);                 /* 0x20 */
    int unk24;                          /* 0x24 */
    void (*fn28)(void);                 /* 0x28 */
    int unk2C;                          /* 0x2C */
    char pad30[0x44 - 0x30];
} DtxRmt;

extern DtxRmt D_003D84C0[16];
extern char D_004541D8[];
extern char D_004541F8[];
extern char D_00454218[];
extern char D_00454230[];
extern char D_00454248[];
extern void func_003260C8(const char *fmt, ...);
extern int dtx_create_rmt(Sint32 a, Sint32 b, Sint32 c, Sint32 d);
extern void *func_003A52F0(void *dst, int c, int n);
extern void SyncDCache(void *start, void *end);
extern void func_003B0640(void *start, void *end);
extern void Obj0000_Increment_D_003D84B0_3320E0(void);
extern void func_003320F8(int a0, char *a1, int a2);

__attribute__((section(".text.func_00332178")))
DtxRmt *func_00332178(unsigned int id, char *buf, int arg2, int bufsize)
{
    DtxRmt *e;
    int rmt;
    int size;

    if ((int)buf & 0x3F) {
        func_003260C8(D_004541D8);
        return 0;
    }
    if (arg2 & 0x1F) {
        func_003260C8(D_004541F8);
        return 0;
    }
    if (bufsize & 0x3F) {
        func_003260C8(D_00454218, bufsize);
        return 0;
    }
    if (id >= 16) {
        func_003260C8(D_00454230, id);
        return 0;
    }
    e = &D_003D84C0[id];
    if (e->used != 0)
        return 0;
    rmt = dtx_create_rmt();
    e->rmt = rmt;
    if (rmt == 0) {
        func_003260C8(D_00454248);
        return 0;
    }
    size = bufsize - 0x40;
    e->size = size;
    e->bufsize = bufsize;
    e->arg2 = arg2;
    e->end = (char *)((int)(buf + size) | 0x20000000);
    e->unk08 = 0;
    e->buf = buf;
    e->unk01 = 0;
    func_003A52F0(buf, 0, size);
    SyncDCache(e->buf, e->buf + e->size + 0x3F);
    func_003B0640(e->buf, e->buf + e->size + 0x3F);
    e->fn20 = Obj0000_Increment_D_003D84B0_3320E0;
    e->fn28 = func_003320F8;
    e->used = 1;
    e->unk24 = 0;
    e->unk2C = 0;
    e->unk02 = 1;
    return e;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00332178);
#endif

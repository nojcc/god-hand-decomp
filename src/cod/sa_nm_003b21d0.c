/* NON_MATCHING func_003B21D0 (ee-2.9-991111; PARK, 13 diffs): sceSifInitCmd.  Only scheduling of
 * the cmd-data init (a3=0x20 / lui hi(D_0077E500) one slot off) and the v0/v1 swap of the
 * packet/pktbuf addresses before the final sceSifSendCmd remain.  Good permuter candidate. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SifCmdHandler {
    void (*handler)(void *pkt, void *harg);
    void *harg;
    int pad;
} SifCmdHandler;

typedef struct SifCmdData {
    void *pktbuf;               /* 0x00 */
    void *unused;               /* 0x04 */
    unsigned int iopbuf;        /* 0x08 */
    SifCmdHandler *sys;         /* 0x0C */
    int nr_sys;                 /* 0x10 */
    SifCmdHandler *usr;         /* 0x14 */
    int nr_usr;                 /* 0x18 */
    unsigned int *sregs;        /* 0x1C */
} SifCmdData;

typedef struct SifCmdPkt {
    int hdr[3];
    int opt;                    /* 0x0C */
    void *buf;                  /* 0x10 */
} SifCmdPkt;

extern int D_003FAE50;
extern char D_0077E440[];
extern char D_0077E4C0[];
extern SifCmdPkt D_0077E500;
extern int D_0077E514;
extern SifCmdData D_0077E518;
extern SifCmdHandler D_0077E540[];
extern unsigned int D_0077E6C0[];

extern void func_003B63A0(void);
extern void EIntr(void);
extern void FlushCache(int op);
extern void SifSetDChain(void);
extern int AddDmacHandler(int ch, int (*fn)(int), int next);
extern int func_003B0810(int chan);
extern unsigned int SifGetReg(unsigned int reg);
extern void SifSetReg(unsigned int reg, unsigned int val);
extern int sceSifSendCmd(unsigned int cmd, void *pkt, int size, void *src, void *dest, int dsize);
extern void func_003B2048(void *pkt, void *harg);
extern void func_003B2028(void *pkt, void *harg);
extern int func_003B2708(int ch);

__attribute__((section(".text.func_003B21D0")))
void func_003B21D0(void)
{
    int i;

    func_003B63A0();
    if (D_003FAE50) {
        EIntr();
        return;
    }
    D_003FAE50 = 1;
    D_0077E518.pktbuf = (void *)((unsigned int)D_0077E440 | 0x20000000);
    D_0077E518.unused = (void *)((unsigned int)D_0077E4C0 | 0x20000000);
    D_0077E518.iopbuf = 0;
    D_0077E518.sys = D_0077E540;
    D_0077E518.nr_sys = 0x20;
    D_0077E518.usr = 0;
    D_0077E518.nr_usr = 0;
    D_0077E518.sregs = D_0077E6C0;
    for (i = 0; i < 0x20; i++) {
        D_0077E540[i].handler = 0;
        D_0077E540[i].harg = 0;
    }
    for (i = 0; i < 0x20; i++)
        D_0077E6C0[i] = 0;
    D_0077E540[0].handler = func_003B2048;
    D_0077E540[0].harg = &D_0077E518;
    D_0077E540[1].handler = func_003B2028;
    D_0077E540[1].harg = &D_0077E518;
    EIntr();
    FlushCache(0);
    if (*(volatile unsigned int *)0x1000E010 & 0x20)
        *(volatile unsigned int *)0x1000E010 = 0x20;
    if (!(*(volatile unsigned int *)0x1000C000 & 0x100))
        SifSetDChain();
    D_0077E514 = AddDmacHandler(5, func_003B2708, 0);
    func_003B0810(5);
    D_0077E518.iopbuf = SifGetReg(0x80000000);
    if (D_0077E518.iopbuf) {
        D_0077E500.buf = D_0077E440;
        sceSifSendCmd(0x80000000, &D_0077E500, 0x14, 0, 0, 0);
        return;
    }
    while (!(SifGetReg(4) & 0x20000))
        ;
    D_0077E518.iopbuf = SifGetReg(2);
    SifSetReg(0x80000000, D_0077E518.iopbuf);
    SifSetReg(0x80000001, (unsigned int)&D_0077E518);
    D_0077E500.buf = D_0077E440;
    D_0077E500.opt = 0;
    sceSifSendCmd(0x80000002, &D_0077E500, 0x14, 0, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_003B21D0);
#endif

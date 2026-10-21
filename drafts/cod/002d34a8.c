/* NON_MATCHING func_002D34A8 (sn-2.95.3-136): loop combines p + i*4 into one s-reg (retail keeps i*4 in s2 and re-adds p at each dma/buf load) and the slots base lands before i = 0 instead of after the func_002D3388 join; stream buffer two-slot SifDma / sceSdRemote state machine */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int func_002D3210(char *p);
extern void func_002D3220(char *p);
extern void func_002D3388(char *p);
extern void StreamBuf_startRead(char *p, int slot);
extern int SifDmaStat(int id);
extern int sceSdRemote(int arg, int cmd, ...);
extern void Tramp_sceSifFreeSysMemory_3B5A50(void *mem);

__attribute__((section(".text.func_002D34A8"))) void func_002D34A8(char *p)
{
    int i;
    int st;
    int *q;
    int *slots;
    unsigned int n;

    if (!func_002D3210(p))
        return;
    if (*(int *)(p + 4) == 0) {
        if (*(int *)p & 2) {
            if (SifDmaStat(*(int *)(p + 0x60)) >= 0)
                return;
            func_002D3220(p);
        } else {
            StreamBuf_startRead(p, 0);
        }
        return;
    }
    if (!(*(int *)p & 2))
        func_002D3388(p);
    slots = (int *)(p + 0x10);
    for (i = 0; i < 2; i++) {
        st = slots[i];
        switch (st) {
        case 0:
            slots[i] = 1;
            StreamBuf_startRead(p, i);
            break;
        case 1:
            if (SifDmaStat(((int *)(p + 0x60))[i]) >= 0)
                break;
            if (*(int *)(p + 0x8C) != 0)
                break;
            n = *(unsigned int *)(p + 0x68);
            if (*(unsigned int *)(p + 0x7C) < n)
                n = *(unsigned int *)(p + 0x7C);
            *(int *)(p + 0x8C) = st;
            *(unsigned int *)(p + 0x90) = n;
            sceSdRemote(1, 0x80D0, 0, 0, ((int *)(p + 0x84))[i], *(int *)(p + 0x6C) + *(int *)(p + 0x78), n);
            slots[i] = 2;
            break;
        case 2:
            if (sceSdRemote(1, 0x80F0, 0, 0) == 1)
                *(int *)(p + 0x8C) = st;
            if (*(int *)(p + 0x8C) == st) {
                *(int *)(p + 0x78) += *(int *)(p + 0x90);
                *(int *)(p + 0x7C) -= *(int *)(p + 0x90);
                if (*(int *)(p + 0x74))
                    slots[i] = 0;
                else
                    slots[i] = 3;
                *(int *)(p + 0x8C) = 0;
            }
        case 3:
            if (*(int *)(p + 0x7C) == 0) {
                q = (int *)(p + 0x84);
                for (i = 1; i >= 0; i--, q++) {
                    if (*q) {
                        Tramp_sceSifFreeSysMemory_3B5A50((void *)*q);
                        *q = 0;
                    }
                }
                func_002D3220(p);
                return;
            }
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002D34A8);
#endif

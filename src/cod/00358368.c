/* NON_MATCHING func_00358368 (cygnus-2.96): only the block before the create-parameter
 * copy differs: retail computes work + 0x1F before loading the -0x20 mask and tests the source alignment earlier
 * (register / schedule order).
* Sofdec player create: check and clear the work buffer, align the handle to 32 bytes,
 * copy the create parameters into it and initialise the sub-blocks; returns the handle or 0. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SfCprm {
    int w00;
    int bufSize;                        /* 0x04 */
    int w08[13];
    void *work;                         /* 0x3C */
    unsigned int workSize;              /* 0x40 */
} SfCprm;

typedef struct SfHn {
    SfCprm cprm;                        /* 0x00 */
    int w44;                            /* 0x44 */
    int w48;                            /* 0x48 */
    int w4C;                            /* 0x4C */
    int w50;                            /* 0x50 */
    int w54;                            /* 0x54 */
    int w58;                            /* 0x58 */
    int w5C;                            /* 0x5C */
    int w60;                            /* 0x60 */
} SfHn;

extern unsigned int D_003EE300;
extern char D_003EE0C0[];
extern void func_00366C50(void *p, int c, unsigned int n);
extern void func_0034D080(void *p);
extern void sfply_InitMvInf(void *p);
extern void func_00358600(void *p);
extern void func_00358688(void *p);
extern void func_0034DD58(void *p);
extern void func_00366960(void *p, void *src, int n);
extern void func_0035A2B0(void *hn, void *p);
extern int func_0034BA88(void *hn, void *p, SfCprm *cprm);
extern void func_0035BCD0(void *hn, void *p, SfCprm *cprm);
extern void func_00359730(void *p);
extern int func_003587D0(void *hn);

__attribute__((section(".text.func_00358368")))
SfHn *func_00358368(SfCprm *cprm, void *a1)
{
    SfHn *hn;
    char *work;
    unsigned int size;
    unsigned int n;

    size = cprm->workSize;
    n = size >> 2;
    work = cprm->work;
    if (work == 0)
        return 0;
    if (size - 1 >= 0x6FA0)
        return 0;
    if (D_003EE300 != 0 && D_003EE300 != size)
        return 0;
    D_003EE300 = size;
    func_00366C50(work, 0, n);
    cprm->bufSize = (cprm->bufSize + 0x1F) & ~0x1F;
    hn = (SfHn *)(((int)work + 0x1F) & ~0x1F);
    hn->w4C = 0;
    hn->w48 = 0;
    hn->cprm = *cprm;
    hn->w50 = 0;
    hn->w44 = 1;
    hn->w54 = 0;
    hn->w58 = 0;
    hn->w5C = 0;
    hn->w60 = 0;
    func_0034D080((char *)hn + 0x78);
    sfply_InitMvInf((char *)hn + 0x90C);
    func_00358600((char *)hn + 0x950);
    func_00358688((char *)hn + 0x36C0);
    func_0034DD58((char *)hn + 0x9F8);
    func_00366960((char *)hn + 0xA0C, D_003EE0C0, 0x190);
    func_00366960((char *)hn + 0xB9C, D_003EE0C0, 0x190);
    func_0035A2B0(hn, (char *)hn + 0xD30);
    if (func_0034BA88(hn, (char *)hn + 0x1310, cprm) != 0)
        return 0;
    func_0035BCD0(hn, (char *)hn + 0x1F30, cprm, a1);
    func_00359730((char *)hn + 0x36B0);
    if (func_003587D0(hn) != 0)
        return 0;
    hn->w4C = 1;
    hn->w48 = 1;
    return hn;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00358368);
#endif

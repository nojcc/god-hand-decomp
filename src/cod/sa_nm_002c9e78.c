/* NON_MATCHING func_002C9E78 (sn-2.95.3-136, as=sn): 34 insns, 58 words vs 55.
 * The stack struct stores match; retail loads fields 2/8/A (lhu + sign-extend) and 0 (lh) straight into a0/v0/v1/a1 with no extra moves, ours stages them in a2/a3 and copies to the arg regs. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void SetGlobalToggle_375700(int a0);
extern void func_00375630(void *p);
extern void func_00375748(unsigned char f);
extern void func_00375380(int a0, int a1);
extern void func_00375500(void);

typedef struct {
    short x0;
    unsigned short y0;
    short z0;
    short w0;
    unsigned short x1;
    unsigned short y1;
    short z1;
    short w1;
} Rect2;

void func_002C9E78(float *out)
{
    Rect2 r;
    float fx;
    float fx1;

    SetGlobalToggle_375700(1);
    r.x0 = 0x7F;
    r.y0 = 0x7F;
    r.z0 = 0;
    r.w0 = 0x5A;
    r.x1 = 0x5A;
    r.y1 = 0x7F;
    r.z1 = 0x7F;
    r.w1 = 0x7F;
    func_00375630(&r);
    func_00375748(7);
    fx = r.x0;
    fx1 = (short)r.x1;
    out[2] = fx;
    out[5] = fx1;
    out[1] = (short)r.y0;
    out[4] = (short)r.y1;
    out[0] = fx;
    out[3] = fx1;
    func_00375380((short)r.y0, r.x0);
    func_00375500();
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C9E78);
#endif

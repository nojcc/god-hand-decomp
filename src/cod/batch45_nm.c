/* Batch 45 near-misses — not registered.
 * 140: cScenario_startSoftTask scenario task/entry schedule (s0 vs s1; mult order).
 * 148: ActorMove_resetMotion -1 store delay-slot (0x30/0x20) and trailing byte order.
 * 160: func_002CCB58 flag/movz control-flow shape.
 * 6-attempt cap. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void cScenario_startSoftEvent(void *sce, int a1);
extern int cScenario_taskExec(void *sce, void *fn, void *arg, int a3);
extern void *D_003C2F84;
extern int D_00747A84;
extern void func_0028E858(void);
extern void func_002B22E0(void *self, void *a1);
extern void func_002B21F0(void *self, int a1);

#endif

INCLUDE_ASM("asm/nonmatching", func_002CCB58);

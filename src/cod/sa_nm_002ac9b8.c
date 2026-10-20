/* NON_MATCHING func_002AC9B8 (sn-2.95.3-136;
 * PARK, 136 diffs): straight-line code and calls match; the child loop
 * hoists the ~0x4000 / ~0x2000 / ~0x1000 masks (s5-s7) where retail hoists ~0x2000 / ~0x1000 / ~0x800 / ~0x400
 * (fp, s7-s5) and reloads ~0x4000 in the loop, so the frame is 0x10 smaller and everything after shifts.
 * Step an ID
 * entry and all its child entries for one frame and set / clear the five 0x400..0x4000 update flags. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_002ABC18(void *self, void *ent);
extern void func_002ABC30(void *self, void *ent);
extern void func_002ABCE8(void *self, void *ent);
extern void func_002ABD30(void *self, void *ent);
extern void func_002ABD78(void *self, void *ent);
extern void func_002ABDC0(void *self, void *ent);
extern void cIDBase_stepMoveAnim(void *self, void *ent);
extern void func_002AC1C0(void *self, void *ent);
extern void IdEnt_stepCurveRotation(void *self, void *ent);
extern void func_002AC378(void *self, void *ent);

static inline void step_ent(char *p, char *e)
{
    *(short *)(e + 0xA0) = 0;
    *(short *)(e + 0xA2) = 0;
    *(short *)(e + 0xA6) = 0;
    *(short *)(e + 0xA8) = 0;
    *(short *)(e + 0xA4) = 0;
    func_002ABC18(p, e);
    func_002ABC30(p, e);
    func_002ABCE8(p, e);
    func_002ABD30(p, e);
    func_002ABD78(p, e);
    func_002ABDC0(p, e);
    cIDBase_stepMoveAnim(p, e);
    func_002AC1C0(p, e);
    IdEnt_stepCurveRotation(p, e);
    func_002AC378(p, e);
}

__attribute__((section(".text.func_002AC9B8")))
void func_002AC9B8(char *p, char *e, unsigned short on)
{
    char *c;
    int i;

    *(short *)(p + 0x1A) = 0;
    *(char *)(p + 0x1D) = 0;
    *(char *)(p + 0x1E) = 0;
    if (e == 0)
        return;
    step_ent(p, e);
    if (on == 0) {
        *(int *)(e + 0x2C) &= ~0x4000;
        *(int *)(e + 0x2C) &= ~0x2000;
        *(int *)(e + 0x2C) &= ~0x1000;
        *(int *)(e + 0x2C) &= ~0x800;
        *(int *)(e + 0x2C) &= ~0x400;
    } else {
        *(int *)(e + 0x2C) |= 0x7C00;
    }
    for (i = 0; i < *(int *)(p + 0xC); i++) {
        c = *(char **)(p + 4) + i * 0xAC;
        if (*(char **)(c + 0x20) == e) {
            step_ent(p, c);
            *(int *)(c + 0x2C) &= ~0x4000;
            *(int *)(c + 0x2C) &= ~0x2000;
            *(int *)(c + 0x2C) &= ~0x1000;
            *(int *)(c + 0x2C) &= ~0x800;
            *(int *)(c + 0x2C) &= ~0x400;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002AC9B8);
#endif

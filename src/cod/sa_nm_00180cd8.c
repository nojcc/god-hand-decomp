/* NON_MATCHING func_00180CD8 (sn-2.95.3-136 fp_hazard_rules mtc1;
 * PARK, 155 diffs): HP-ratio mesh layer disp/color; retail cross-jumps only the final jal of the three disp branches (sn also merges branch 1 into branch 2), FP tail regalloc differs */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x548];
    short max;
    short hp;
} Om180;

extern void cOmBase_setMeshDispFromLayer(Om180 *o, int layer, int on);
extern void cOmBase_setMeshColorFromLayer(Om180 *o, int layer, float r, float g, float b);

void func_00180CD8(Om180 *o)
{
    float r;
    float t;
    float a;
    float b;

    r = (float)o->hp / (float)o->max;
    if (o->hp > 0) {
        if (0.66f < r) {
            cOmBase_setMeshDispFromLayer(o, 2, 1);
            cOmBase_setMeshDispFromLayer(o, 3, 0);
            cOmBase_setMeshDispFromLayer(o, 4, 0);
        } else if (0.33f < r) {
            cOmBase_setMeshDispFromLayer(o, 2, 0);
            cOmBase_setMeshDispFromLayer(o, 3, 1);
            cOmBase_setMeshDispFromLayer(o, 4, 0);
        } else {
            cOmBase_setMeshDispFromLayer(o, 2, 0);
            cOmBase_setMeshDispFromLayer(o, 3, 0);
            cOmBase_setMeshDispFromLayer(o, 4, 1);
        }
        cOmBase_setMeshDispFromLayer(o, 5, 0);
    } else {
        cOmBase_setMeshDispFromLayer(o, 2, 0);
        cOmBase_setMeshDispFromLayer(o, 3, 0);
        cOmBase_setMeshDispFromLayer(o, 4, 0);
        cOmBase_setMeshDispFromLayer(o, 5, 1);
        cOmBase_setMeshColorFromLayer(o, 5, 0.8f, 0.2f, 0.2f);
    }
    r = (float)o->hp / (float)o->max;
    if (0.7f <= r) {
        t = (1.0f - r) / 0.3f;
        a = t * 0.8f + 0.2f;
        b = 1.0f - a;
        cOmBase_setMeshColorFromLayer(o, 2, 0.2f, a, b);
        cOmBase_setMeshColorFromLayer(o, 3, 0.2f, a, b);
        cOmBase_setMeshColorFromLayer(o, 4, 0.2f, a, b);
    } else {
        t = (0.7f - r) / 0.7f;
        a = t * 0.8f + 0.2f;
        b = 1.0f - a;
        cOmBase_setMeshColorFromLayer(o, 2, a, b, 0.2f);
        cOmBase_setMeshColorFromLayer(o, 3, a, b, 0.2f);
        cOmBase_setMeshColorFromLayer(o, 4, a, b, 0.2f);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00180CD8);
#endif

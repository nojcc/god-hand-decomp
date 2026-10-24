/* NON_MATCHING cObjSimple_UpdateHandMesh (sn-2.95.3-136, fp_hazard_rules fdiv): same length as
 * retail; retail loads the 10-degree step once into $f22 before the first call and reuses it for
 * both divisions, where this form loads it at each division. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cObjSimple.h"
#include "godhand/cOmBase.h"

#define HAND_CHILD   27             /* child whose rotation picks the hand meshes */
#define HAND_STEP    0.17453292f    /* one mesh per 10 degrees of bend */

extern int cModel_setMeshDisplay(void *model, char *name, int on);
extern char D_0044B4D8[];           /* "RH_00" */
extern char D_0044B4E0[];           /* "RH_01" */
extern char D_0044B4E8[];           /* "RH_02" */
extern char D_0044B4F0[];           /* "LH_00" */
extern char D_0044B4F8[];           /* "LH_01" */
extern char D_0044B500[];           /* "LH_02" */

/* Shows one of the three right and left hand meshes, picked by how far the
 * hand child is bent about x (right) and z (left); without the child, the
 * open hands. */
__attribute__((section(".text.cObjSimple_UpdateHandMesh")))
void cObjSimple_UpdateHandMesh(cObjSimple *self)
{
    int frame[3];
    cObjSimpleChild *hand;
    float bendR;
    float bendL;

    hand = (cObjSimpleChild *)cOmBase_childAt((cOmBase *)self, frame, HAND_CHILD);
    if (hand != 0) {
        bendR = hand->rot.x;
        bendL = hand->rot.z;
        cModel_setMeshDisplay(self, D_0044B4D8, 0);
        cModel_setMeshDisplay(self, D_0044B4E0, 0);
        cModel_setMeshDisplay(self, D_0044B4E8, 0);
        switch ((int)(bendR / HAND_STEP)) {
        case 1:
            cModel_setMeshDisplay(self, D_0044B4E0, 1);
            break;
        case 0:
        default:
            cModel_setMeshDisplay(self, D_0044B4D8, 1);
            break;
        case 2:
            cModel_setMeshDisplay(self, D_0044B4E8, 1);
            break;
        }
        cModel_setMeshDisplay(self, D_0044B4F0, 0);
        cModel_setMeshDisplay(self, D_0044B4F8, 0);
        cModel_setMeshDisplay(self, D_0044B500, 0);
        switch ((int)(bendL / HAND_STEP)) {
        case 1:
            cModel_setMeshDisplay(self, D_0044B4F8, 1);
            break;
        case 0:
        default:
            cModel_setMeshDisplay(self, D_0044B4F0, 1);
            break;
        case 2:
            cModel_setMeshDisplay(self, D_0044B500, 1);
            break;
        }
    } else {
        cModel_setMeshDisplay(self, D_0044B4D8, 1);
        cModel_setMeshDisplay(self, D_0044B4E0, 0);
        cModel_setMeshDisplay(self, D_0044B4E8, 0);
        cModel_setMeshDisplay(self, D_0044B4F0, 1);
        cModel_setMeshDisplay(self, D_0044B4F8, 0);
        cModel_setMeshDisplay(self, D_0044B500, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cObjSimple_UpdateHandMesh);
#endif

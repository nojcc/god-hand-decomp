/* sn-2.95.3-136 */
/* NON_MATCHING func_002A7CD0: 214 vs 217 words. The sort, the ChkLine calls
 * and the stack layout match; retail reloads ptNum in the point lookup where
 * this reuses the loop test's load (as in func_002A8038), so set gets a later
 * saved register, and retail takes fabsf of the height difference before it
 * loads near[far].key. cGameObjSortEnt's int id holds the PathLinePt pointer
 * (the sort helpers' only caller is this function): the casts wait on the
 * decision row. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameLoop.h"
#include "godhand/cGameObj.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/capVu0.h"
#include "godhand/cVec.h"

/* The sort helpers, as their definitions declare them (001212d0.c types the
 * entries with a private copy of cGameObjSortEnt). */
void func_002A8EF0(cGameObjSortEnt *first, cGameObjSortEnt *last, cGameObjSortEnt *dummy, int depth, void *comp);
void cGameObjSortEnt_finalInsertionSort(cGameObjSortEnt *first, cGameObjSortEnt *last, void *tag);

/* std::sort over [first, last): the introsort loop, then the final insertion sort. */
static __inline__ void nearSort(cGameObjSortEnt *first, cGameObjSortEnt *last)
{
    if (first != last) {
        int n = last - first;
        int lg = 0;

        while (n != 1) {
            n >>= 1;
            lg++;
        }
        func_002A8EF0(first, last, 0, lg * 2, 0);
        cGameObjSortEnt_finalInsertionSort(first, last, 0);
    }
}

/* The path point nearest pos (squared distance, within 1.0 in height): keeps
 * the eight nearest, sorts them, and when check is set drops the first four
 * that ChkLine finds blocked; when none of those is left it tests the other
 * four. Returns the first point left, or 0. */
__attribute__((section(".text.func_002A7CD0")))
PathLinePt *func_002A7CD0(cVec *pos, int check)
{
    cGameObjSortEnt near[8];
    CVEC_TEMPS;
    PathLineSet *set = &D_005CAC90.lines;
    int far = 0;
    int i;
    int j;
    int found;

    for (i = 0; i < 8; i++) {
        near[i].id = 0;
        near[i].key = 360000.0f;
    }
    for (i = 0; i < set->ptNum; i++) {
        PathLinePt *pt = PathLineSet_point(set, i);
        float d;
        float dy;

        CVEC_SUB(&pt->pos, pos);
        d = capVu0LengthSq(&ret_);
        dy = __builtin_fabsf(pt->pos.y - pos->y);
        if (d < near[far].key && dy < 1.0f) {
            near[far].id = (int)pt;
            near[far].key = d;
            far = 0;
            for (j = 1; j < 8; j++) {
                if (near[far].key < near[j].key) {
                    far = j;
                }
            }
        }
    }
    nearSort(near, near + 8);
    if (check != 0) {
        for (i = 0; i < 4; i++) {
            if (near[i].id != 0 && ChkLine(pos, (void *)near[i].id, 0, 0, 7, 0x60, 0, 0, 0, 0, 0, 0, 1) != 0) {
                near[i].id = 0;
            }
        }
    }
    found = 0;
    for (i = 0; i < 4; i++) {
        if (near[i].id != 0) {
            found = 1;
        }
    }
    if (found == 0) {
        for (i = 4; i < 8; i++) {
            if (near[i].id != 0 && ChkLine(pos, (void *)near[i].id, 0, 0, 7, 0x60, 0, 0, 0, 0, 0, 0, 1) != 0) {
                near[i].id = 0;
            }
        }
    } else {
        for (i = 4; i < 8; i++) {
            near[i].id = 0;
        }
    }
    for (i = 0; i < 8; i++) {
        if (near[i].id != 0) {
            return (PathLinePt *)near[i].id;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002A7CD0);
#endif

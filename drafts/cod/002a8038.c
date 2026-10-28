/* sn-2.95.3-136 */
/* NON_MATCHING func_002A8038: 279 vs 283 words. The lookups, the ChkLine
 * calls and the stack layout match; retail keeps the 0x40000000 mask and
 * &sum in registers across both loops (sum's address spilled to 0x98) and
 * reloads lineNum in the line lookup, where this reuses the loop test's load
 * and builds both values inside the loops. Retail copies the return slot of
 * func_00156BE8 into foot without operator='s self-check. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/criStm.h"
#include "godhand/vu0.h"

/* One point of the stage path lines. */
typedef struct PathLinePt {
    cVec pos;                           /* 0x00 */
    char unk10[0x10];
} PathLinePt;                           /* 0x20 */

/* One line between two path points. Bit 31 of flags turns the line off
 * unless bit 30 is set too. */
typedef struct PathLine {
    unsigned short a;                   /* 0x0 first point */
    unsigned short b;                   /* 0x2 second point */
    char unk4[0x4];
    int flags;                          /* 0x8 */
} PathLine;                             /* 0xC */

/* The stage path lines kept by the game loop object. */
typedef struct PathLineSet {
    char unk0[0x4];
    PathLine *lines;                    /* 0x04 */
    int lineNum;                        /* 0x08 */
    PathLinePt *pts;                    /* 0x0C */
    int ptNum;                          /* 0x10 */
} PathLineSet;

/* The game loop object (D_005CAC90): its mode byte and the path lines. */
typedef struct cGameLoop {
    unsigned char mode;                 /* 0x000 */
    char unk001[0x18B];
    PathLineSet lines;                  /* 0x18C */
} cGameLoop;

#define PATH_LINE_NEAR_NUM 4

extern cGameLoop D_005CAC90;
/* The four starting distances (FLT_MAX each) and FLT_MAX itself. */
extern const float D_0044AE10[PATH_LINE_NEAR_NUM];
extern const float D_0044AE20;

float LengthPositionToGivenLine(cVec *pos, cVec *a, cVec *b, int *where);
void func_001569A0(cVec *out, cVec *a, cVec *b, cVec *pos);
cVec *func_00156BE8(cVec *ret, cVec *a, cVec *b, cVec *pos, cVec *dir);

/* Line i of the set, or 0 when i is out of range. */
static __inline__ PathLine *PathLineSet_line(PathLineSet *set, int i)
{
    long in = 0;

    if (i >= 0) {
        int below = i < set->lineNum;

        in = below;
    }
    if ((in & 0xFF) == 0) {
        return 0;
    }
    return &set->lines[i];
}

/* Point i of the set, or 0 when i is out of range. */
static __inline__ PathLinePt *PathLineSet_point(PathLineSet *set, int i)
{
    long in = 0;

    if (i > -1) {
        int below = i < set->ptNum;

        in = below;
    }
    if ((in & 0xFF) == 0) {
        return 0;
    }
    return &set->pts[i];
}

/* The path line nearest pos: keeps the four nearest lines, and when check is
 * set drops those that ChkLine finds blocked from pos (toward the nearer end
 * point, or toward the foot of the perpendicular). Returns the nearest one
 * left, or 0. */
__attribute__((section(".text.func_002A8038")))
PathLine *func_002A8038(cVec *pos, int check)
{
    float dist[PATH_LINE_NEAR_NUM];
    PathLine *near[PATH_LINE_NEAR_NUM];
    cVec foot;
    cVec ret;
    cVec dir;
    cVec sum;
    int where;
    int end;
    cGameLoop *game = &D_005CAC90;
    PathLineSet *set = &game->lines;
    int far = 0;
    int i;
    int j;

    __builtin_memcpy(dist, D_0044AE10, sizeof(dist));
    func_003A52F0(near, 0, sizeof(near));
    for (i = 0; i < set->lineNum; i++) {
        PathLine *ln = PathLineSet_line(set, i);
        float d;

        if (!(ln->flags & 0x40000000) && ln->flags < 0) {
            continue;
        }
        d = LengthPositionToGivenLine(pos, &PathLineSet_point(set, ln->a)->pos,
                                      &PathLineSet_point(set, ln->b)->pos, &where);
        if (d < dist[far]) {
            dist[far] = d;
            near[far] = ln;
            far = 0;
            for (j = 1; j < PATH_LINE_NEAR_NUM; j++) {
                if (dist[far] < dist[j]) {
                    far = j;
                }
            }
        }
    }
    if (check != 0) {
        for (i = 0; i < PATH_LINE_NEAR_NUM; i++) {
            PathLinePt *a;
            PathLinePt *b;

            if (near[i] == 0) {
                continue;
            }
            a = PathLineSet_point(set, near[i]->a);
            b = PathLineSet_point(set, near[i]->b);
            LengthPositionToGivenLine(pos, &a->pos, &b->pos, &end);
            if (end == 0) {
                if (ChkLine(pos, a, 0, 0, 7, 0x60, 0, 0, 0, 0, 0, 0, 1) == 0) {
                    continue;
                }
            } else if (end == 1) {
                if (ChkLine(pos, b, 0, 0, 7, 0x60, 0, 0, 0, 0, 0, 0, 1) == 0) {
                    continue;
                }
            } else {
                func_001569A0(&foot, &a->pos, &b->pos, pos);
                VU0_LQC2(4, pos, 0);
                VU0_SQC2_MEM(4, &sum, 0);
                VU0_VADD_XYZ_IP(&sum, 0, &foot);
                VU0_LQC2(4, &sum, 0);
                VU0_SQC2_MEM(4, &dir, 0);
                func_00156BE8(&ret, &a->pos, &b->pos, pos, &dir);
                foot.x = ret.x;
                foot.y = ret.y;
                foot.z = ret.z;
                if (ChkLine(pos, &foot, 0, 0, 7, 0x60, 0, 0, 0, 0, 0, 0, 1) == 0) {
                    continue;
                }
            }
            near[i] = 0;
            dist[i] = D_0044AE20;
        }
    }
    far = 0;
    for (j = 1; j < PATH_LINE_NEAR_NUM; j++) {
        if (dist[j] < dist[far]) {
            far = j;
        }
    }
    return near[far];
}
#else
INCLUDE_ASM("asm/nonmatching", func_002A8038);
#endif

/* NON_MATCHING cEmManage_SetEmAnger (sn-2.95.3-136; 108 vs 110 words: both fabs tests
 * compile to bc1tl+neg.s in place, retail copies then negates under bc1f) */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef struct AngerVtEnt {
    short delta;
    short index;
    int (*pfn)(void *self);
} AngerVtEnt;

typedef struct AngerEm {
    char pad000[0xF0];
    float *pos;                 /* 0x0F0 */
    char pad0F4[0x214 - 0xF4];
    AngerVtEnt *vt;             /* 0x214 */
    char pad218[0x2FE - 0x218];
    unsigned short kind;        /* 0x2FE */
    char pad300[0x54A - 0x300];
    short hp;                   /* 0x54A */
} AngerEm;

typedef struct AngerEmNode {
    int pad00;
    struct AngerEmNode *next;   /* 0x04 */
    AngerEm *em;                /* 0x08 */
} AngerEmNode;

extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);

__attribute__((section(".text.cEmManage_SetEmAnger")))
AngerEm *cEmManage_SetEmAnger(char *mgr, float *pos, float dir, float dist, float angRange)
{
    AngerEmNode *node;
    AngerEm *em;
    AngerEm *best;
    float bestD;
    float d;
    float dy;
    float t;
    float at;
    float ady;
    float *p;
    long ok;
    int k;
    int tt;

    best = 0;
    bestD = dist * dist;
    node = *(AngerEmNode **)(mgr + 0x500);
    while (node != 0) {
        em = node->em;
        if (em != 0) {
            k = em->kind;
            ok = 0; if (k >= 0x200) { tt = (k < 0x300); ok = tt; }
            if (ok & 0xFF) {
                tt = k >= 0x280;
                if (tt)
                    goto next;
                if (em->hp <= 0)
                    goto next;
                p = em->pos;
                dy = pos[1] - p[1];
                ady = dy;
                if (dy < 0.0f)
                    ady = -dy;
                if (2.0f < ady)
                    goto next;
                d = capVu0MagnitudeSqXZ(pos, p);
                if (dist * dist < d)
                    goto next;
                t = Turn_dest(pos, em->pos, dir, 3.1415927f);
                at = t;
                if (t < 0.0f)
                    at = -t;
                if (angRange < at)
                    goto next;
                if (em->vt[24].pfn((char *)em + em->vt[24].delta) == 0)
                    goto next;
                if (d <= bestD) {
                    bestD = d;
                    best = em;
                }
            }
        }
    next:
        node = node->next;
    }
    return best;
}
#else
INCLUDE_ASM("asm/nonmatching", cEmManage_SetEmAnger);
#endif

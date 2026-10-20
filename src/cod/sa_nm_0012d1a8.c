/* NON_MATCHING func_0012D1A8 (sn-2.95.3-136; PARK, 62 diffs): world corners of a scaled unit square plus its bounding box.
 * Same length as retail; retail keeps self in $s1 (ours $s3) and addresses min/max/corners off self (0x10(s1), 0xC0(v0))
 * where ours goes through the min/max pointer locals. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct Plane12D1A8 {
    char pad00[0x08];
    unsigned int flags;                 /* 0x08 bit 2 = use parent matrix */
    char pad0C[0x04];
    Vec4 min;                           /* 0x10 */
    Vec4 max;                           /* 0x20 */
    char pad30[0x58 - 0x30];
    void *parent;                       /* 0x58 */
    char pad5C[0x04];
    Vec4 pos;                           /* 0x60 */
    Vec4 trans;                         /* 0x70 */
    Vec4 rot;                           /* 0x80 */
    Vec4 rot2;                          /* 0x90 */
    float sx;                           /* 0xA0 */
    float sy;                           /* 0xA4 */
    char padA8[0xC0 - 0xA8];
    Vec4 c[4];                          /* 0xC0 */
} Plane12D1A8;

extern Vec4 D_00462F00[4];
extern void MtxInitTransVec(void *m, void *v);
extern void MtxMulRotVec(void *dst, void *m, void *rot, int order);
extern void MtxMulTransVec(void *dst, void *m, void *v);
extern void sceVu0ApplyMatrix(void *dst, void *m, void *src);

__attribute__((section(".text.func_0012D1A8")))
void func_0012D1A8(Plane12D1A8 *p)
{
    float m[4][4];
    Vec4 *sq;
    Vec4 *c;
    Vec4 *c0;
    Vec4 *mn;
    Vec4 *mx;
    int i;
    long t;

    t = p->flags;
    if (((t >> 2) & 1) == 1) {
        MtxMulRotVec(m, p->parent, &p->rot2, 0);
        MtxMulTransVec(m, m, &p->trans);
    } else {
        MtxInitTransVec(m, &p->pos);
        MtxMulRotVec(m, m, &p->rot, 0);
        MtxMulTransVec(m, m, &p->trans);
    }
    c0 = p->c;
    sq = D_00462F00;
    mn = &p->min;
    mx = &p->max;
    c = c0;
    for (i = 0; i < 4; i++) {
        c->x = sq->x * p->sx;
        c->y = sq->y * p->sy;
        c->z = 0.0f;
        sceVu0ApplyMatrix(c, m, c);
        sq++;
        c++;
    }
    if (mn != c0) {
        mn->x = c0->x;
        mn->y = c0->y;
        mn->z = c0->z;
    }
    if (mx != mn) {
        mx->x = mn->x;
        mx->y = mn->y;
        mx->z = mn->z;
    }
    for (i = 1; i < 4; i++) {
        c = &p->c[i];
        if (c->x < mn->x) mn->x = c->x;
        if (c->y < mn->y) mn->y = c->y;
        if (c->z < mn->z) mn->z = c->z;
        if (mx->x < c->x) mx->x = c->x;
        if (mx->y < c->y) mx->y = c->y;
        if (mx->z < c->z) mx->z = c->z;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012D1A8);
#endif

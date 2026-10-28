/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING func_00130700: 676 words against retail's 680. The
 * control flow and the stack frame follow retail; the registers differ
 * throughout: retail
 * keeps the return slot's address in s6 and spills the temporary's, the
 * second edge's and the segment direction's addresses (0xB8, 0xB4, 0xAC),
 * where this C spills them in another order, adds the corner index to the
 * corner base with the operands the other way round, and swaps the
 * constructor loop's counter and limit registers. */
#include "godhand/cGrid.h"
#include "godhand/cVec.h"
#include "godhand/sceVu0.h"

extern int HitProbe_probeHitPoint(void *a0, void *a1, void *shape, void *a3, float *out);

#ifdef NON_MATCHING
/* Test the grid's segment against the active collision bodies whose bounds
 * meet the query box: each face of a wanted kind that faces the segment and
 * is hit is listed in hitFaces, its body's id in ids (each id once for a
 * box), and the nearest hit is kept as hitPos and hitNormal. The edges of
 * the nearest face are copied out of the return slot without operator='s
 * self-check, as retail does. */
__attribute__((section(".text.func_00130700")))
void func_00130700(cGrid *self, int *ids, unsigned int max, unsigned int *count)
{
    cVec hit;
    cVec quad[4];
    cVec normal;
    cVec edge[2];
    CVEC_TEMPS;
    cCollBody *body;
    cCollFace *face;
    cVec *corner;
    cVec *p;
    unsigned int i;
    unsigned int j;
    unsigned int n;
    int k;
    int id;
    int add;
    long flags;

    CVEC_ZERO(hit);
    if (count != 0)
        *count = 0;
    for (body = self->bodies; body != 0; body = body->next) {
        flags = (unsigned int)body->flags;
        if ((flags & 1) == 0)
            continue;
        if (func_00133408(self, &self->boxMin.x, &self->boxMax.x, &body->min.x, &body->max.x) == 0)
            continue;
        switch (body->type) {
        case CCOLLBODY_QUAD:
            face = &body->u.quad.face;
            if (!(face->kind & self->mask))
                continue;
            if (face->attr & self->exclude)
                continue;
            corner = body->u.quad.corner;
            p = quad;
            k = 3;
            do {
                cVec_zero(p);
                p++;
            } while (--k != -1);
            CVEC_ASSIGN(quad[0], &corner[D_0041D630[0]]);
            CVEC_ASSIGN(quad[1], &corner[D_0041D630[1]]);
            CVEC_ASSIGN(quad[2], &corner[D_0041D630[2]]);
            CVEC_ASSIGN(quad[3], &corner[D_0041D630[3]]);
            CVEC_ZERO(normal);
            p = edge;
            k = 1;
            do {
                cVec_zero(p);
                p++;
            } while (--k != -1);
            CVEC_INIT_SUB(ret_, &quad[1], &quad[0]);
            sceVu0Normalize(&edge[0], &ret_);
            CVEC_INIT_SUB(ret_, &quad[3], &quad[0]);
            sceVu0Normalize(&edge[1], &ret_);
            sceVu0OuterProduct(&normal, &edge[0], &edge[1]);
            if (!(sceVu0InnerProduct(&self->dir, &normal) < 0.0f))
                continue;
            if (HitProbe_probeHitPoint(&self->from, &self->to, quad, &normal, &hit.x) == 0)
                continue;
            if (self->hitFaces != 0) {
                if (self->single) {
                    self->hitFaces[0] = face;
                    self->hitCount = 1;
                } else if (self->room != 0) {
                    self->hitFaces[self->hitCount] = face;
                    self->hitCount++;
                    self->room--;
                }
            }
            if (ids != 0 && count != 0 && max != 0) {
                if (self->single) {
                    if (body->id != 0) {
                        ids[0] = body->id;
                        *count = 1;
                    }
                } else if (*count < max && body->id != 0) {
                    ids[*count] = body->id;
                    (*count)++;
                }
            }
            self->dist = cVec_distSq(&self->from, &hit);
            if (self->dist < self->best) {
                p = edge;
                k = 1;
                do {
                    cVec_zero(p);
                    p++;
                } while (--k != -1);
                CVEC_INIT_SUB(ret_, &corner[D_0041D630[1]], &corner[D_0041D630[0]]);
                edge[0].x = ret_.x;
                edge[0].y = ret_.y;
                edge[0].z = ret_.z;
                CVEC_INIT_SUB(ret_, &corner[D_0041D630[3]], &corner[D_0041D630[0]]);
                edge[1].x = ret_.x;
                edge[1].y = ret_.y;
                edge[1].z = ret_.z;
                sceVu0OuterProduct(&self->hitNormal, &edge[0], &edge[1]);
                sceVu0Normalize(&self->hitNormal, &self->hitNormal);
                self->best = self->dist;
                CVEC_PUT(&self->hitPos, hit);
                if (self->single)
                    CVEC_PUT(&self->to, self->hitPos);
            }
            self->hit = 1;
            break;
        case CCOLLBODY_BOX:
            for (i = 0; i < 6; i++) {
                face = &body->u.box.face[i];
                if (!(face->kind & self->mask))
                    continue;
                if (face->attr & self->exclude)
                    continue;
                corner = body->u.box.corner;
                p = quad;
                k = 3;
                do {
                    cVec_zero(p);
                    p++;
                } while (--k != -1);
                CVEC_ASSIGN(quad[0], &corner[D_0041D640[i][0]]);
                CVEC_ASSIGN(quad[1], &corner[D_0041D640[i][1]]);
                CVEC_ASSIGN(quad[2], &corner[D_0041D640[i][2]]);
                CVEC_ASSIGN(quad[3], &corner[D_0041D640[i][3]]);
                CVEC_ZERO(normal);
                p = edge;
                k = 1;
                do {
                    cVec_zero(p);
                    p++;
                } while (--k != -1);
                CVEC_INIT_SUB(ret_, &quad[1], &quad[0]);
                sceVu0Normalize(&edge[0], &ret_);
                CVEC_INIT_SUB(ret_, &quad[3], &quad[0]);
                sceVu0Normalize(&edge[1], &ret_);
                sceVu0OuterProduct(&normal, &edge[0], &edge[1]);
                if (!(sceVu0InnerProduct(&self->dir, &normal) < 0.0f))
                    continue;
                if (HitProbe_probeHitPoint(&self->from, &self->to, quad, &normal, &hit.x) == 0)
                    continue;
                if (self->hitFaces != 0) {
                    if (self->single) {
                        self->hitFaces[0] = face;
                        self->hitCount = 1;
                    } else if (self->room != 0) {
                        self->hitFaces[self->hitCount] = face;
                        self->hitCount++;
                        self->room--;
                    }
                }
                if (ids != 0 && count != 0 && max != 0) {
                    if (self->single) {
                        if (body->id != 0) {
                            ids[0] = body->id;
                            *count = 1;
                        }
                    } else {
                        n = *count;
                        if (n < max) {
                            add = 1;
                            id = body->id;
                            for (j = 0; j < n; j++) {
                                if (ids[j] == id) {
                                    add = 0;
                                    break;
                                }
                            }
                            if (add && body->id != 0) {
                                ids[n] = body->id;
                                (*count)++;
                            }
                        }
                    }
                }
                self->dist = cVec_distSq(&self->from, &hit);
                if (self->dist < self->best) {
                    p = edge;
                    k = 1;
                    do {
                        cVec_zero(p);
                        p++;
                    } while (--k != -1);
                    CVEC_INIT_SUB(ret_, &corner[D_0041D640[i][1]], &corner[D_0041D640[i][0]]);
                    edge[0].x = ret_.x;
                    edge[0].y = ret_.y;
                    edge[0].z = ret_.z;
                    CVEC_INIT_SUB(ret_, &corner[D_0041D640[i][3]], &corner[D_0041D640[i][0]]);
                    edge[1].x = ret_.x;
                    edge[1].y = ret_.y;
                    edge[1].z = ret_.z;
                    sceVu0OuterProduct(&self->hitNormal, &edge[0], &edge[1]);
                    sceVu0Normalize(&self->hitNormal, &self->hitNormal);
                    self->best = self->dist;
                    CVEC_PUT(&self->hitPos, hit);
                    if (self->single)
                        CVEC_PUT(&self->to, self->hitPos);
                }
                self->hit = 1;
            }
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00130700);
#endif

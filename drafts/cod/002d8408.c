/* NON_MATCHING cWorldLight_Light_curent_set (sn-2.95.3-136): 254 words vs 258.
 * Retail keeps two registers holding 0xFF in the compaction loop (compare and
 * store), hoists 0x4000000 out of the preset loop, tests the compaction loop's
 * entry against n's register, and returns 0 from the null preset in the
 * branch delay slot; this C merges the constants and saves two fewer
 * registers. Retail compares owner[0] unsigned against the player's child
 * count and stores the child pointer into the int key. */
#include "include_asm.h"
#ifdef NON_MATCHING
#include "godhand/cWorldLight.h"
#include "godhand/cVec.h"
#include "godhand/player.h"

extern cWorldLight D_00604700;

/* cOmBase_childAt and cOmBase_childAtIdx on the player, which Getplayer
 * returns as a cGameObj. */
static __inline__ struct cOmBase *plChildAt(cGameObj *b, int *frame, int idx)
{
    int n;

    *frame = n = b->partNum;
    if (idx >= 0 && idx < n) {
        return b->children[idx];
    }
    return 0;
}

static __inline__ struct cOmBase *plChildAtIdx(cGameObj *b, int *frame, int idx)
{
    int n;
    long in = 0;

    *frame = n = b->partNum;
    if (idx >= 0) {
        int below = idx < n;

        in = below;
    }
    if (in & 0xFF) {
        return b->children[idx];
    }
    return 0;
}

/* Make preset no current: copy its settings into the world light, drop the
 * lights no one owns, then append the preset's lights; a light flagged
 * 0x4000000 takes its key from the player's child owner[0]. */
__attribute__((section(".text.cWorldLight_Light_curent_set")))
cWorldLightPreset *cWorldLight_Light_curent_set(cWorldLight *self, int no)
{
    cWorldLightPreset *pre;
    cWorldLight *wl;
    int i, n;

    pre = &D_00604700.preset[no];
    wl = &D_00604700;
    if (pre != 0) {
    self->unk16288 = no;
    if ((float *)pre->v30 != wl->v30) {
        wl->v30[0] = pre->v30[0];
        wl->v30[1] = pre->v30[1];
        wl->v30[2] = pre->v30[2];
    }
    if ((float *)pre->ambient != wl->ambient) {
        wl->ambient[0] = pre->ambient[0];
        wl->ambient[1] = pre->ambient[1];
        wl->ambient[2] = pre->ambient[2];
    }
    wl->head.w[0] = pre->head.w[0];
    wl->head.w[1] = pre->head.w[1];
    wl->head.w[2] = pre->head.w[2];
    wl->head.w[3] = pre->head.w[3];
    wl->f10[0] = pre->f10[0];
    wl->f10[1] = pre->f10[1];
    wl->f10[2] = pre->f10[2];
    wl->f10[3] = pre->f10[3];
    wl->f10[4] = pre->f10[4];
    wl->f10[5] = pre->f10[5];
    wl->b60 = pre->b60;
    wl->f64 = pre->f64;
    wl->f68 = pre->f68;
    wl->b6C = pre->b6C;
    wl->f70 = pre->f70;
    wl->f74 = pre->f74;
    if (pre->lights != 0) {
        cWorldLightRec tmp;
        int frame[3];

        n = 0;
        CVEC_ZERO(*(cVec *)tmp.v10);
        CVEC_ZERO(*(cVec *)tmp.v20);
        CVEC_ZERO(*(cVec *)tmp.v30);
        for (i = 0; i < wl->lightNum; i++) {
            if (wl->light[i].state != WORLDLIGHT_LIGHT_FREE && wl->light[i].id != 0) {
                tmp = wl->light[i];
                wl->light[i].state = WORLDLIGHT_LIGHT_FREE;
                wl->light[n] = tmp;
                n++;
            }
        }
        wl->lightNum = n;
        for (i = 0; i < pre->lightNum; i++) {
            cWorldLightRec *src = &pre->lights[i];

            if (src->state == WORLDLIGHT_LIGHT_FREE) {
                continue;
            }
            if (src->owner[WORLDLIGHT_OWNER_USE] != 0) {
                wl->light[wl->lightNum] = *src;
                if (wl->light[wl->lightNum].flags & 0x4000000) {
                    wl->light[wl->lightNum].v10[3] = 1.0f;
                    if ((unsigned int)wl->light[wl->lightNum].owner[WORLDLIGHT_OWNER_IDX] > Getplayer()->partNum) {
                        wl->light[wl->lightNum].key = (int)plChildAt(Getplayer(), frame, 0);
                    } else {
                        wl->light[wl->lightNum].key = (int)plChildAtIdx(Getplayer(), frame, wl->light[wl->lightNum].owner[WORLDLIGHT_OWNER_IDX]);
                    }
                }
            } else {
                wl->light[wl->lightNum] = *src;
            }
            wl->lightNum++;
        }
    }
    }
    return pre;
}
#else
INCLUDE_ASM("asm/nonmatching", cWorldLight_Light_curent_set);
#endif

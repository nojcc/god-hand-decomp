/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cSnd.h"

/* One sound-effect table entry as SdeIssTblGet copies it out. */

#ifdef NON_MATCHING

typedef struct cSndSeParam {
    short bank;                 /* 0x00 */
    short idx;                  /* 0x02 */
    char unk04[5];
    unsigned char outMode;      /* 0x09 */
    char unk0A[0x16];
    unsigned char flags;        /* 0x20 bit 0x80 sets voice flag 4 */
    unsigned char randRange;    /* 0x21 */
    signed char maxPri;         /* 0x22 */
    unsigned char limit;        /* 0x23 */
    unsigned char stateHi;      /* 0x24 */
    unsigned char optLo;        /* 0x25 */
    unsigned char optHi;        /* 0x26 */
    char unk27[0x30 - 0x27];
} cSndSeParam;                  /* 0x30 */

extern int D_00747A84;

extern int cSnd_SeCheckParam(void *self, short a, short b, int c);
extern unsigned int irand(void);
extern int func_002CBD10(cSnd *self, short id, short code, int key, short lo, short hi, int n);
extern cSndSeVoice *func_002CBF78(cSnd *self, cSndSeVoice *skip, short a, short b, int mode, int maxPri);
extern float capVu0LengthAB(void *a0, void *a1);
extern int SdeSystemOutModeGet(void);
extern int func_00377FF8(void);

/* Starts a voice: looks up its sound-effect entry, picks a variant, drops it
 * when too many of the same play or a closer one wins, sets the output kind
 * and flags, then takes a driver handle and links it. Returns the handle, or 0. */
__attribute__((section(".text.cSndSeVoice_Setup")))
int cSndSeVoice_Setup(cSndSeVoice *v, short key0, short key1, int flags, int delay)
{
    cSndSeParam p;
    short base;
    int range;
    int limit;
    int i;
    int hi;
    cSndSeVoice *other;
    int found;
    float far;
    int opt;
    int state;

    if (key0 == 0) {
        if ((key1 >= 200 && key1 <= 232) || (key1 >= 0xEE && key1 <= 0xEF)
            || (key1 >= 0xF2 && key1 <= 0xF3) || (key1 >= 0xF8 && key1 <= 0xF9)
            || key1 == 0xEA || key1 == 0x109 || key1 == 0x10B) {
            key0 = 3;
            key1 -= 200;
        }
    }
    if (cSnd_SeCheckParam(v, key0, key1, (int)&p) == -1) {
        v->handle = 0;
        return 0;
    }
    range = p.randRange;
    base = key1;
    limit = p.limit;
    if (range != 0) {
        key1 += irand() % (range + 1);
        if (cSnd_SeCheckParam(v, key0, key1, (int)&p) == -1) {
            v->handle = 0;
            return 0;
        }
    }
    if (limit != 0) {
        i = 0;
        if (range != 0) {
        hi = base + range;
        do {
            if (func_002CBD10(&D_005FEE00, key0, key1, (int)v->obj, base, hi, limit) != 1) {
                cSnd_SeRecentPush(&D_005FEE00, key0, key1, (int)v->obj);
                break;
            }
            i++;
            key1++;
            if (hi < key1) {
                key1 = base;
            }
        } while (i < range);
        }
    }
    if (p.maxPri != 0) {
        other = func_002CBF78(&D_005FEE00, v, key0, key1, 2, (unsigned char)p.maxPri);
        found = 0;
        if (other != 0) {
            if (other->flags & 1) {
                found = 1;
            } else if (other->delay == v->delay) {
                far = capVu0LengthAB(&D_005FEE00.listenPos, other->pos);
                if (capVu0LengthAB(&D_005FEE00.listenPos, v->pos) < far) {
                    cSndSeVoice_Unlink(other);
                } else {
                    found = 1;
                }
            }
        }
        if (found == 1) {
            v->handle = 0;
            return 0;
        }
    }
    if (flags & 0x20000) {
        if (p.outMode != 0) {
            v->kind = 3;
        } else {
            v->kind = 0;
        }
    } else if (SdeSystemOutModeGet() != 0) {
        switch ((signed char)p.outMode) {
        case 0:
        case 1:
            v->kind = 0;
            break;
        case 2:
            break;
        case 3:
            if (v->kind != 0) {
                v->kind = 1;
            }
            break;
        }
    }
    if (p.flags & 0x80) {
        v->flags |= 4;
    }
    {
        unsigned long f = D_00747A84;
        unsigned long bit = (f >> 6) & 1;
        if (bit) {
            v->flags |= 8;
        }
    }
    state = flags | p.flags | (p.stateHi << 8);
    v->key0 = key0;
    opt = p.optLo | (p.optHi << 8);
    v->key1 = key1;
    v->stateFlags = state;
    v->optFlags = opt;
    v->delay = delay;
    if (opt & 6) {
        v->optFlags = opt | 1;
    }
    v->handle = func_00377FF8();
    cSndSeVoice_Link(v);
    return v->handle;
}
#else
INCLUDE_ASM("asm/nonmatching", cSndSeVoice_Setup);
#endif

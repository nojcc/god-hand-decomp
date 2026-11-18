/* ee-2.9-991111 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"
#include "godhand/cDamageManage.h"
#include "godhand/cMovie.h"

extern char D_00569B80[];
extern char D_0056C380[];

__attribute__((section(".text.func_001FE1E0")))
cDamageGive *func_001FE1E0(cDamageManage *self) {
    cDamageGive *p = self->give;
    cDamageGive *end = self->give + CDAMAGE_GIVE_MAX;

    for (;;) {
        if (p->live == 0) {
            return p;
        }
        p++;
        if (!(p < end)) {
            break;
        }
    }
    return &self->giveSpare;
}

__attribute__((section(".text.func_001FE5A8")))
char *func_001FE5A8(void) {
    char *p = D_00569B80;
    unsigned int i = 0;

    do {
        if (*(unsigned char *)(p + 0x2E) == 0) {
            return p;
        }
        i++;
        p += 0x40;
    } while (i < 0xA0);
    return 0;
}

__attribute__((section(".text.func_001FE660")))
char *func_001FE660(void) {
    char *p = D_0056C380;
    unsigned int i = 0;

    do {
        if (*(unsigned char *)(p + 0x2E) == 0) {
            return p;
        }
        i++;
        p += 0x40;
    } while (i < 0x200);
    return 0;
}

/* Phase 0xC at step 0 or 2 for kinds 0 and 1. */
__attribute__((section(".text.func_00283378")))
void func_00283378(cGameObj *self, unsigned char kind)
{
    switch (kind) {
    case 0:
        self->mode = 0;
        self->phase = 0xC;
        self->step = 0;
        self->stepArg = 0;
        break;
    case 1:
        self->mode = 0;
        self->phase = 0xC;
        self->step = 2;
        self->stepArg = 0;
        break;
    default:
        self->mode = 0;
        self->phase = 0xC;
        self->step = 0;
        self->stepArg = 0;
        break;
    }
}

__attribute__((section(".text.func_00295660")))
char *func_00295660(char *base) {
    char *q = base + 0x10;
    char *f = base + 0x23;
    unsigned int i = 0;

    do {
        if (*(unsigned char *)f == 0) {
            return q;
        }
        i++;
        q += 0x18;
        f += 0x18;
    } while (i < 2);
    return 0;
}

__attribute__((section(".text.func_002A9648")))
char *func_002A9648(void *unused, char *p, unsigned int n) {
    char *h = p - 0x20;
    unsigned int sz = n + 0x20;
    unsigned int cur = *(unsigned int *)(h + 0x10);

    if (cur < sz) {
        return 0;
    }
    *(unsigned int *)(h + 0x10) = sz;
    *(char **)(h + 0xC) = *(char **)(h + 0xC) + (cur - sz);
    return p;
}

__attribute__((section(".text.func_002B4FE8")))
cMovieAlloc *func_002B4FE8(cMovie *self, void *block) {
    cMovieAlloc *p = self->alloc;
    cMovieAlloc *q = self->alloc;
    int i = 0;

    do {
        if (p->block == block) {
            return q;
        }
        i++;
        q++;
        p++;
    } while (i < MOVIE_ALLOC_NUM);
    return 0;
}

__attribute__((section(".text.func_002C9060")))
int func_002C9060(int a0,unsigned int a1){int p=*(int*)a0;if(p==0)return 0;{unsigned int n=*(unsigned int*)(a0+0xC);if(n==0)return 0;if(a1<n)return p+a1*0x24;return 0;}}

/* Finds the block that holds the chunk at this address. */
__attribute__((section(".text.cSndMemHeap_FindBlk")))
cSndMemBlk *cSndMemHeap_FindBlk(cSndMemHeap *heap, int addr) {
    cSndMemBlk *p = &heap->self->blk[1];
    int i = 1;

    do {
        if (p->base == addr) {
            return p;
        }
        i++;
        p++;
    } while (i < CSND_HEAP_BLK_NUM);
    return 0;
}

/* Finds an unused block of the heap. */
__attribute__((section(".text.cSndMemHeap_FindUnusedBlk")))
cSndMemBlk *cSndMemHeap_FindUnusedBlk(cSndMemHeap *heap) {
    cSndMemBlk *p = &heap->self->blk[1];
    int i = 1;

    do {
        if (p->base == 0) {
            return p;
        }
        i++;
        p++;
    } while (i < CSND_HEAP_BLK_NUM);
    return 0;
}

__attribute__((section(".text.func_00306F88")))
char *func_00306F88(char *base) {
    char *p = base;
    char *end = base + 0x300;

    for (;;) {
        if (*(unsigned char *)(p + 0x8) == 0) {
            *(unsigned char *)(p + 0x8) = 1;
            return p;
        }
        p += 0x18;
        if (!(p < end)) {
            return 0;
        }
    }
}

__attribute__((section(".text.func_003078E0")))
int func_003078E0(unsigned int a) {
    int t;

    if (a == 0) {
        return -1;
    }
    t = a & 0xFF00;
    if (t == 0x500) {
        return -1;
    }
    if (t < 0x601) {
        return a | 0x40000000;
    }
    return -1;
}

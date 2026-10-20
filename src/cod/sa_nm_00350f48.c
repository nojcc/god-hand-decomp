/* NON_MATCHING func_00350F48 (cygnus-2.96 drop-reorder;
 * 112 vs 111 words, 50 diffs: retail keeps
 * ring p1/end in v1/v0 and returns through bare v0 sets; ours picks a0/a1 and presets v0) */
#include "include_asm.h"

#ifdef NON_MATCHING
/* cygnus-2.96, -freorder-blocks dropped: func_00350F48, read the 4 bytes at ptr from a split ring
 * buffer and decide whether they start a delimiter the caller wants to stop at. */
typedef struct {
    unsigned char *p0;
    int len0;
    unsigned char *p1;
    int len1;
} Ring350;

typedef struct {
    unsigned char b[4];
} Code350;

extern void func_003A5148(void *dst, void *src, int n);
extern int MPV_CheckDelim(void *code);
extern unsigned char *sfmpv_SearchDelim(Ring350 *rb, int type, int *flags);

__attribute__((section(".text.func_00350F48")))
int func_00350F48(Ring350 *rb, int flags, unsigned char *ptr)
{
    Code350 code;
    unsigned char *end;
    unsigned char *found;
    int n;
    int type;

    if (ptr == 0)
        return 1;
    if (ptr == rb->p0)
        return 1;
    if (rb->p0 < ptr && ptr - rb->p0 < 4)
        return 1;
    if (!(ptr < rb->p0) && ptr < rb->p0 + rb->len0) {
        n = ptr - (rb->p0 + rb->len0) + 4;
        if (n > 0) {
            if (rb->len1 < n)
                return 1;
            func_003A5148(&code, ptr, 4 - n);
            func_003A5148((char *)&code - n + 4, rb->p1, n);
            goto check;
        }
    } else {
        if (ptr < rb->p1)
            return 1;
        if (!(ptr < rb->p1 + rb->len1))
            return 1;
        n = ptr - (rb->p1 + rb->len1) + 4;
        if (n > 0)
            return 1;
    }
    code = *(Code350 *)ptr;
check:
    switch (MPV_CheckDelim(&code)) {
    case 8:
        if (!(flags & 0x40))
            return 0;
        type = 8;
        break;
    case 4:
        if (!(flags & 0x48))
            return 0;
        type = 4;
        break;
    case 0x40:
    case 0x80:
        return 0;
    default:
        return 1;
    }
    found = sfmpv_SearchDelim(rb, type, &flags);
    if (found == 0 || found == ptr)
        return 1;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00350F48);
#endif

/* Closest under sn-2.95.3-136: memcpy is 1 word short (retail moves dst0 to t0 and
 * uses a0 for loop temporaries; quad copies use v1/v0); memmove 4 words long. */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef unsigned int size_t;
typedef int TItype __attribute__((mode(TI)));

#define UNALIGNED(X, Y) \
    (((long)(X) & (sizeof(TItype) - 1)) | ((long)(Y) & (sizeof(TItype) - 1)))
#define BIGBLOCKSIZE (sizeof(TItype) << 1)
#define LITTLEBLOCKSIZE (sizeof(long))
#define TOO_SMALL(LEN) ((LEN) < BIGBLOCKSIZE)

__attribute__((section(".text.func_003A5148")))
void *func_003A5148(void *dst0, const void *src0, size_t len0)
{
    char *dst = dst0;
    const char *src = src0;
    TItype *aligned_dst;
    const TItype *aligned_src;
    int len = len0;
    void *save = dst0;

    if (!TOO_SMALL(len) && !UNALIGNED(src, dst)) {
        aligned_dst = (TItype *)dst;
        aligned_src = (const TItype *)src;
        while (len >= BIGBLOCKSIZE) {
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            len -= BIGBLOCKSIZE;
        }
        while (len >= LITTLEBLOCKSIZE) {
            *(long *)aligned_dst = *(const long *)aligned_src;
            aligned_dst = (TItype *)((long *)aligned_dst + 1);
            aligned_src = (const TItype *)((const long *)aligned_src + 1);
            len -= LITTLEBLOCKSIZE;
        }
        dst = (char *)aligned_dst;
        src = (const char *)aligned_src;
    }
    while (len--) {
        *dst++ = *src++;
    }
    return save;
}

__attribute__((section(".text.func_003A51F4")))
void *func_003A51F4(void *dst_void, const void *src_void, size_t length)
{
    char *dst = dst_void;
    const char *src = src_void;
    TItype *aligned_dst;
    const TItype *aligned_src;
    int len = length;

    if (src < dst && dst < src + len) {
        src += len;
        dst += len;
        while (len--) {
            *--dst = *--src;
        }
    } else {
        if (!TOO_SMALL(len) && !UNALIGNED(src, dst)) {
            aligned_dst = (TItype *)dst;
            aligned_src = (const TItype *)src;
            while (len >= BIGBLOCKSIZE) {
                *aligned_dst++ = *aligned_src++;
                *aligned_dst++ = *aligned_src++;
                len -= BIGBLOCKSIZE;
            }
            while (len >= LITTLEBLOCKSIZE) {
                *(long *)aligned_dst = *(const long *)aligned_src;
                aligned_dst = (TItype *)((long *)aligned_dst + 1);
                aligned_src = (const TItype *)((const long *)aligned_src + 1);
                len -= LITTLEBLOCKSIZE;
            }
            dst = (char *)aligned_dst;
            src = (const char *)aligned_src;
        }
        while (len--) {
            *dst++ = *src++;
        }
    }
    return dst_void;
}

#else

INCLUDE_ASM("asm/nonmatching", func_003A5148);
INCLUDE_ASM("asm/nonmatching", func_003A51F4);

#endif

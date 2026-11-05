/* include/godhand/newlibMalloc.h - newlib mallocr.c chunk types and the bin array (sn code at 0x3AC090..).
 *
 * Names are newlib's; offsets are exact.
 */
#ifndef GODHAND_NEWLIBMALLOC_H
#define GODHAND_NEWLIBMALLOC_H

typedef unsigned int INTERNAL_SIZE_T;

struct malloc_chunk {
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};

typedef struct malloc_chunk *mchunkptr;
typedef struct malloc_chunk *mbinptr;

extern mbinptr D_003FA9D0[];      /* __malloc_av_ */

/* Take and give back the allocator lock (recursive, per thread). */
void __malloc_lock(void *reent);
void __malloc_unlock(void *reent);
/* _malloc_r and _free_r: the allocator proper; reent is the caller's _reent. */
void *func_003AC2F8(void *RARG, unsigned int bytes);
void func_003ACA28(void *RARG, void *mem);
/* malloc and free: _malloc_r and _free_r on _impure_ptr, under the lock. */
void *func_003A7C70(unsigned int n);
void UpdateGlobalPtrWithParam_3A7CC0(void *p);

#endif /* GODHAND_NEWLIBMALLOC_H */

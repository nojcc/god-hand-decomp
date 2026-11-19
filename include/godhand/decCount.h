/* include/godhand/decCount.h - the wait counter the casino games step once a frame.
 */
#ifndef GODHAND_DECCOUNT_H
#define GODHAND_DECCOUNT_H

/* 1 once *p has run out; otherwise count it down by one and return 0. */
static __inline__ unsigned char DecCount(int *p)
{
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

#endif

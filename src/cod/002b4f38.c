/* sn-2.95.3-136 matched TU. */
#include "godhand/cMovie.h"

/* 1 while the track holds a player. The unsigned char result is what makes
 * the compiler build the 0/1 with a branch, as retail does. */
static __inline__ unsigned char cMovieTrack_inUse(cMovieTrack *t) {
    if (t->handle != 0) return 1;
    return 0;
}

/* The first free track (handle 0), or -1 when all MOVIE_TRACK_NUM play. */
__attribute__((section(".text.func_002B4F38")))
int func_002B4F38(cMovie *self)
{
    cMovieTrack *t = self->track;
    int no = 0;

    for (;;) {
        if (!cMovieTrack_inUse(t))
            return no;
        no++;
        if (no >= MOVIE_TRACK_NUM)
            return -1;
        t++;
    }
}

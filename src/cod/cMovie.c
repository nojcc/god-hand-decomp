/* TU: cMovie - recovered C++ class. */
#include "include_asm.h"

/* NON_MATCHING cMovie_Start (sn-2.95.3-136): 83 words vs 79. Retail reaches
 * GameWork's language, flags5E0 and flags5E4 through their own symbols
 * (D_00747A0C, D_00747A80, D_00747A84), each with its own lui; through
 * D_007474A0 the compiler shares one base across the calls. As plain int
 * symbols the scheduler moves their loads above the busyMask and player
 * stores (32 words differ); only an aggregate type per symbol matches. */
#ifdef NON_MATCHING
#include "godhand/cMovie.h"
#include "godhand/gameWork.h"

/* Start clip id (from the second table when language is set) on a free
 * track and return its new handle, or 0 when every track plays. A clip
 * with MOVIE_CLIP_LOCK_PAD marks its track busy and sets eight bits of
 * flags5E0. arg is not read. */
__attribute__((section(".text.cMovie_Start")))
int cMovie_Start(cMovie *self, int id, int arg)
{
    int no;
    cMovieTrack *track;
    cMovieClip *clip;

    no = func_002B4F38(self);
    if (no < 0) {
        return 0;
    }
    track = &self->track[no];
    if (D_007474A0.language == 0) {
        clip = &D_005E7BF0[id];
    } else {
        clip = &D_005E7D10[id];
    }
    cMovieTrack_start(track, &clip->name);
    self->player[no] = func_002B4F78(self);
    if (clip->flags & MOVIE_CLIP_LOCK_PAD) {
        self->busyMask |= 1 << no;
        D_007474A0.flags5E0 |= 0x800000;
        D_007474A0.flags5E0 |= 0x80000000;
        D_007474A0.flags5E0 |= 0x40000000;
        D_007474A0.flags5E0 |= 0x20000000;
        D_007474A0.flags5E0 |= 0x10000000;
        D_007474A0.flags5E0 |= 0x01000000;
        D_007474A0.flags5E0 |= 0x04000000;
        D_007474A0.flags5E0 |= 0x08000000;
    }
    D_003C3CD4 = 1;
    D_007474A0.flags5E4 |= MOVIE_SYS_PLAYING;
    return self->player[no];
}
#else
INCLUDE_ASM("nonmatching", cMovie_Start);
#endif

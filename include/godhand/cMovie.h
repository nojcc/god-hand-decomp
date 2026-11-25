/* include/godhand/cMovie.h - the movie player front end.
 *
 * cMovie drives the full motion video. The movie object holds a pointer to
 * a table of MOVIE_TRACK_NUM tracks (0xAC bytes each) and, per track, the
 * handle of the stream player that func_002D3BA8 set up. Starting a movie
 * takes a free track, picks the clip description (D_005E7BF0, or D_005E7D10
 * when D_00747A0C is set), queues it, and sets the "movie playing" bit
 * (0x2000) in the system state word D_00747A84. Stopping clears that bit.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CMOVIE_H
#define GODHAND_CMOVIE_H

#define MOVIE_TRACK_NUM    3
#define MOVIE_SYS_PLAYING  0x2000       /* bit of D_00747A84 */

/* cMovieTrack.flags bits read by the player setup (func_002D3D88). The sign
 * bit asks for the effect buffer at 0xA8; it is tested as flags < 0. */
#define MOVIE_TRACK_STREAM  0x01        /* allocate the two stream buffers */
#define MOVIE_TRACK_IMAGE   0x08        /* allocate a plain output image */
#define MOVIE_TRACK_LUMI    0x10        /* luminance effect argument */
#define MOVIE_TRACK_TEXIMG  0x40        /* output image with a texture header */

/* One movie track: the stream player handle, the heap buffers it owns, the
 * player setup and the effect buffer. ResHolder_release frees and resets it. */
typedef struct cMovieTrack {
    int handle;                         /* 0x00 stream player, 0 while the track is free */
    void *buf04;                        /* 0x04 heap buffer */
    void *work;                         /* 0x08 decoder work */
    void *stm[2];                       /* 0x0C stream buffers */
    void *img;                          /* 0x14 output image */
    int cell18;                         /* 0x18 */
    short w;                            /* 0x1C picture size */
    short h;                            /* 0x1E */
    char unk20[8];
    int f28;                            /* 0x28 0x31 enables the luminance effect */
    int f2C;                            /* 0x2C */
    int f30;                            /* 0x30 1 also needs an output image */
    int f34;                            /* 0x34 */
    int f38;                            /* 0x38 */
    int flags;                          /* 0x3C MOVIE_TRACK_* bits */
    short lumi0;                        /* 0x40 luminance parameters, 31 and 100 after a release */
    short lumi1;                        /* 0x42 */
    char unk44[0x14];
    int id58;                           /* 0x58 */
    int id5C;                           /* 0x5C */
    char unk60[0x48];
    void *fxbuf;                        /* 0xA8 effect buffer, only when flags < 0 */
} cMovieTrack;                          /* 0xAC */

extern void ResHolder_release(cMovieTrack *track);

struct cMovie;

/* The movie calls the scenario's movie object makes: cMovie_Start returns a handle, and the
 * other three take the movie manager (D_005E79D0) and that handle, which they don't read. */
extern int cMovie_Start(void *mgr, int id, int arg);
extern void cMovie_haltActive(void *mgr, int handle);
extern int cMovie_GetStatus(void *mgr, int handle);
extern void cMovie_Stop(void *mgr, int handle);

struct HeapArena;

/* One heap block the movie library took through the allocator hooks; a free slot has block 0. */
typedef struct cMovieAlloc {
    void *block;                        /* 0x00 */
    struct HeapArena *heap;             /* 0x04 the arena it came from */
} cMovieAlloc;

#define MOVIE_ALLOC_NUM  0x40

typedef struct cMovie {
    cMovieTrack *track;                 /* 0x00 MOVIE_TRACK_NUM entries */
    int player[MOVIE_TRACK_NUM];        /* 0x04 */
    int count;                          /* 0x10 cleared by MoviePool_init */
    unsigned char flag;                 /* 0x14 cleared by MoviePool_init */
    char unk15[3];
    unsigned int busyMask;              /* 0x18 bit n set while track n plays a flagged clip */
    cMovieAlloc alloc[MOVIE_ALLOC_NUM]; /* 0x1C */
} cMovie;


/* Set the movie player up: point it at the track table D_005E7E30, clear the
 * counters, hand the movie library a 59.94 fps setup record and the allocator
 * hooks func_002B48A0 and func_002B48C8, then free each track's resource node
 * and clear its player handle. */
void MoviePool_init(cMovie *self);

/* The slot whose block is `block` (0 finds a free slot), or 0. */
cMovieAlloc *func_002B4FE8(cMovie *self, void *block);
/* size bytes, 128-byte aligned, from the first movie arena with room, kept in a free slot. */
void *func_002B5AF8(cMovie *self, int unused, unsigned int size);
/* The movie library's allocator hooks on D_005E79D0; the first argument is passed on but not read.
 * The free hook returns whatever its callee leaves in v0. */
void *func_002B48A0(int unused, unsigned int size);
int func_002B48C8(int unused, void *block);

/* One clip description in the tables D_005E7BF0 (normal) and D_005E7D10
 * (when D_00747A0C is set), 0x30 bytes each. */
#define MOVIE_CLIP_LOCK_PAD  0x20       /* flags: hold the pad while the clip plays */

typedef struct cMovieClip {
    const char *name;                   /* 0x00 cMovieTrack_start copies it into the track */
    char unk04[0x28];
    unsigned int flags;                 /* 0x2C */
} cMovieClip;                           /* 0x30 */

extern cMovieClip D_005E7BF0[];
extern cMovieClip D_005E7D10[];

/* Set to 1 when a movie starts; func_0030B148 reads and clears it. */
extern int D_003C3CD4;

/* The first free track (handle 0), or -1 when all MOVIE_TRACK_NUM play. */
int func_002B4F38(cMovie *self);
/* The next movie handle from count, skipping 0. */
int func_002B4F78(cMovie *self);
/* Start the clip (its name is the first word) on track; 1 on success. */
int cMovieTrack_start(cMovieTrack *track, const char **clip);

typedef char cMovieTrack_size_check[(sizeof(cMovieTrack) == 0xAC) ? 1 : -1];

#endif

/* include/godhand/libcdvd.h - the libcdvd calls the game makes.
 */
#ifndef GODHAND_LIBCDVD_H
#define GODHAND_LIBCDVD_H

/* Ask the drive whether a disc is ready: 2 when it is, 6 when it is not. */
int sceCdDiskReady(int mode);

#endif

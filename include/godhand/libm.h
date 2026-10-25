/* include/godhand/libm.h - the newlib float math wrappers the game calls. */
#ifndef GODHAND_LIBM_H
#define GODHAND_LIBM_H

/* asinf: arc sine of x, in radians (definition in 003a1b78.c). */
float func_003A1B78(float x);

/* Square root; __builtin_sqrtf gives the inline sqrt.s. */
float sqrtf(float x);

#endif

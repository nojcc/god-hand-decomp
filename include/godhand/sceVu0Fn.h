/* include/godhand/sceVu0Fn.h - VU0 vector calls more than one unit makes.
 *
 * sceVu0.h holds the rest. Older units declare these themselves with their own
 * types, so the prototypes live here for the units that take them from a
 * header.
 */
#ifndef GODHAND_SCEVU0FN_H
#define GODHAND_SCEVU0FN_H

#include "godhand/sceVu0.h"

/* v0 = v1 (all four components). */
void sceVu0CopyVector(void *v0, void *v1);
/* dst = a * b (4x4 matrices). */
void sceVu0MulMatrix(void *dst, void *a, void *b);
float capVu0Length(void *a0);
/* sceVu0CopyVector(dst, src). */
void func_001506F0(cVec *dst, cVec *src);

#endif /* GODHAND_SCEVU0FN_H */

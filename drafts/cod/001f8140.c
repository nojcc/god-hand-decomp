/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/capVu0.h"

/* NON_MATCHING: retail keeps x in $f13 (the second argument register) from
 * entry and builds 1 - x * x in $f12; this build keeps x in $f12 and copies it. */

#ifdef NON_MATCHING
/* Arc cosine through the arc tangent: acos(x) = atan2(sqrt(1 - x * x), x). */
__attribute__((section(".text.capVu0Acos")))
float capVu0Acos(float x)
{
    return capVu0Atan2(__builtin_sqrtf(1.0f - x * x), x);
}
#else
INCLUDE_ASM("asm/nonmatching", capVu0Acos);
#endif

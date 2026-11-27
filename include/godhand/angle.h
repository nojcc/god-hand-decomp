/* include/godhand/angle.h - heading helpers. */
#ifndef GODHAND_ANGLE_H
#define GODHAND_ANGLE_H

#include "godhand/cVecType.h"

/* Signed yaw step from cur toward the XZ direction from -> to, clamped to max
 * (main's declaration, as in cCamera.h). */
float Turn_dest(const float *from, float cur, const float *to, float max);

/* Wrap the x, y and z angles of v into -pi..pi (VU0 code at 0x1F7DA0). */
void Adjust_theta_vec(cVec *v);

/* Magnitude of a signed angle. */
static inline float absf(float x)
{
    float r;

    if (x < 0.0f) {
        r = -x;
    } else {
        r = x;
    }
    return r;
}

#endif

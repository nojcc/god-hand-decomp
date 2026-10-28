/* include/godhand/angle.h - heading helpers. */
#ifndef GODHAND_ANGLE_H
#define GODHAND_ANGLE_H

/* Signed yaw step from cur toward the XZ direction from -> to, clamped to max. */
float Turn_dest(float *from, float *to, float cur, float max);

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

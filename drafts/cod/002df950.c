/* sn-2.95.3-136 */
/* NON_MATCHING func_002DF950: 1087 vs 1113 words. The stores match; the
 * register choice does not. Retail is a C++ array initialiser: for each table
 * the compiler keeps a count of the elements still to construct, and CSE
 * reuses those counts for bone numbers of the same value, so retail holds 4 in
 * three registers and spills one. The same counter in C would be a dead
 * variable. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cloth.h"

/* Static initialisation of the enemy cloth sphere tables. */
__attribute__((section(".text.func_002DF950")))
void func_002DF950(int init, int priority)
{
    if (priority == 0xFFFF && init) {
        {
            ClothSphere *p = D_0061A9A0;

            CLOTH_SPHERE_SET(p, 18, 18, 1.0f, 0.24f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 22, 1.0f, 0.24f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
        }

        {
            ClothSphere *p = D_0061AA00;

            CLOTH_SPHERE_SET(p, 18, 18, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.33f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 19, 0.66f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 19, 19, 1.0f, 0.11f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
        }

        {
            ClothSphere *p = D_0061AAC0;

            CLOTH_SPHERE_SET(p, 3, 2, 0.5f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 2, 2, 1.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 1, 1, 1.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 18, 18, 1.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 22, 22, 1.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
        }

        {
            ClothSphere *p = D_0061ABB0;

            CLOTH_SPHERE_SET(p, 3, 2, 0.7f, 0.13f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 2, 2, 0.33f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
        }

        {
            ClothSphere *p = D_0061AC10;

            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.05f, 0.0f, 0.12f, 0.08f, 0.0f, 0.12f, 0.08f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.06f, 0.0f, 0.08f, 0.08f, 0.0f, 0.08f, 0.08f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.055f, 0.0f, 0.03f, 0.08f, 0.0f, 0.03f, 0.08f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.08f, 0.0f, 0.06f, 0.04f, 0.0f, 0.06f, 0.04f)
        }

        {
            ClothSphere *p = D_0061ACD0;

            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.05f, 0.0f, 0.12f, 0.08f, 0.0f, 0.12f, 0.08f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.06f, 0.0f, 0.08f, 0.08f, 0.0f, 0.08f, 0.08f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.055f, 0.0f, 0.03f, 0.08f, 0.0f, 0.03f, 0.08f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.08f, 0.0f, 0.06f, 0.04f, 0.0f, 0.06f, 0.04f)
        }

        {
            ClothSphere *p = D_0061AD90;

            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.1f, 0.0f, 0.1f, 0.1f, 0.0f, 0.01f, 0.01f)
            p++;
            CLOTH_SPHERE_SET(p, 3, 3, 1.0f, 0.1f, 0.0f, 0.1f, 0.04f, 0.0f, 0.1f, 0.04f)
            p++;
            CLOTH_SPHERE_SET(p, 3, 3, 1.0f, 0.1f, 0.0f, 0.0f, 0.01f, 0.0f, 0.0f, 0.01f)
            p++;
            CLOTH_SPHERE_SET(p, 2, 2, 1.0f, 0.19f, 0.0f, 0.03f, 0.02f, 0.0f, 0.03f, 0.02f)
            p++;
            CLOTH_SPHERE_SET(p, 5, 5, 1.0f, 0.18f, 0.0f, -0.01f, 0.01f, 0.0f, -0.01f, 0.01f)
            p++;
            CLOTH_SPHERE_SET(p, 11, 11, 1.0f, 0.18f, 0.0f, -0.01f, 0.01f, 0.0f, -0.01f, 0.01f)
            p++;
            CLOTH_SPHERE_SET(p, 6, 6, 1.0f, 0.13f, 0.0f, -0.03f, 0.03f, 0.0f, -0.03f, 0.03f)
            p++;
            CLOTH_SPHERE_SET(p, 12, 12, 1.0f, 0.13f, 0.0f, -0.03f, 0.03f, 0.0f, -0.03f, 0.03f)
        }

        {
            ClothSphere *p = D_0061AF10;

            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.075f, 0.0f, 0.06f, 0.02f, 0.0f, 0.06f, 0.02f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.075f, 0.0f, 0.02f, 0.02f, 0.0f, 0.02f, 0.02f)
            p++;
            CLOTH_SPHERE_SET(p, 3, 3, 1.0f, 0.055f, 0.0f, 0.01f, 0.0f, 0.0f, 0.01f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 2, 2, 1.0f, 0.09f, 0.0f, 0.195f, -0.03f, 0.0f, 0.195f, -0.03f)
            p++;
            CLOTH_SPHERE_SET(p, 5, 5, 1.0f, 0.09f, -0.03f, -0.015f, 0.0f, -0.03f, -0.015f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 11, 11, 1.0f, 0.09f, 0.03f, -0.015f, 0.0f, 0.03f, -0.015f, 0.0f)
        }

        {
            ClothSphere *p = D_0061B030;

            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.075f, 0.0f, 0.06f, 0.02f, 0.0f, 0.06f, 0.02f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.075f, 0.0f, 0.02f, 0.02f, 0.0f, 0.02f, 0.02f)
            p++;
            CLOTH_SPHERE_SET(p, 3, 3, 1.0f, 0.055f, 0.0f, 0.01f, 0.0f, 0.0f, 0.01f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 2, 2, 1.0f, 0.09f, 0.0f, 0.195f, -0.03f, 0.0f, 0.195f, -0.03f)
            p++;
            CLOTH_SPHERE_SET(p, 5, 5, 1.0f, 0.09f, -0.03f, -0.015f, 0.0f, -0.03f, -0.015f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 11, 11, 1.0f, 0.09f, 0.03f, -0.015f, 0.0f, 0.03f, -0.015f, 0.0f)
        }

        {
            ClothSphere *p = D_0061B150;

            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.075f, 0.0f, 0.06f, 0.02f, 0.0f, 0.06f, 0.02f)
            p++;
            CLOTH_SPHERE_SET(p, 4, 4, 1.0f, 0.075f, 0.0f, 0.02f, 0.02f, 0.0f, 0.02f, 0.02f)
            p++;
            CLOTH_SPHERE_SET(p, 3, 3, 1.0f, 0.055f, 0.0f, 0.01f, 0.0f, 0.0f, 0.01f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 2, 2, 1.0f, 0.09f, 0.0f, 0.195f, -0.03f, 0.0f, 0.195f, -0.03f)
            p++;
            CLOTH_SPHERE_SET(p, 5, 5, 1.0f, 0.09f, -0.03f, -0.015f, 0.0f, -0.03f, -0.015f, 0.0f)
            p++;
            CLOTH_SPHERE_SET(p, 11, 11, 1.0f, 0.09f, 0.03f, -0.015f, 0.0f, 0.03f, -0.015f, 0.0f)
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002DF950);
#endif

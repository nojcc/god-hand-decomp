/* NON_MATCHING func_002C1AE0 (sn-2.95.3-136, as sn;
 * PARK, 39 diffs): the first 0x134 bytes match.
 * In the facing-arc check, retail loads the pi constant after the sub.s/abs.s pair (so ps2eeas adds an mtc1 hazard nop); ours hoists it above them, which shifts the rest of the tail by one word. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_002C1AE0: area hit check with a facing limit: build the check volume, turn its angle by
 * the attached part's yaw (and an extra offset), test it, then reject hits where the player's yaw
 * is outside the allowed arc.
 * Angles in the parameter block are in 2-degree steps. */
typedef struct {
    char pad00[0x30];
    int count;                          /* 0x30 */
    char pad34[0xC];
} AreaVol2C1AE0;

extern char *Getplayer(void);
extern void func_002C1D68(char *self, AreaVol2C1AE0 *vol, char *prm);
extern float func_002C31D0(char *self, float angle);
extern int cArea_HitCheck_1F83E8(AreaVol2C1AE0 *vol, void *area);

__attribute__((section(".text.func_002C1AE0")))
int func_002C1AE0(char *self, char *prm, void *areaA, void *areaB)
{
    AreaVol2C1AE0 vol;
    char *pl;
    char *obj;
    float ang;
    float yaw;
    float d;
    int hit;

    pl = Getplayer();
    ang = (float)(*(signed char *)(prm + 0x45) * 2) * 0.017453292f;
    func_002C1D68(self, &vol, prm);
    obj = *(char **)(prm + 0x48);
    if (obj != 0) {
        short idx = *(short *)(prm + 0x4C);

        if (idx < 0) {
            yaw = *(float *)(obj + 0x104);
        } else {
            char *part;

            if (idx < (vol.count = *(unsigned char *)(obj + 0x2B4)))
                part = ((char **)*(char **)(obj + 0x278))[idx];
            else
                part = 0;
            yaw = *(float *)(part + 0x104);
        }
        if (!(*(unsigned char *)(prm + 0x34) & 0x10))
            ang = func_002C31D0(self, ang + yaw);
        if (*(unsigned char *)(prm + 0x34) & 0x20)
            ang = func_002C31D0(self, ang + (float)(*(signed char *)(prm + 0x47) * 2) * 0.017453292f);
    }
    if (*(unsigned char *)(prm + 0x38))
        hit = cArea_HitCheck_1F83E8(&vol, areaA);
    else
        hit = cArea_HitCheck_1F83E8(&vol, areaB);
    if (hit == 1 && (*(unsigned char *)(prm + 0x38) & 2)) {
        d = __builtin_fabsf(ang - *(float *)(pl + 0x104));
        if (3.1415927f < d)
            d = 6.2831855f - d;
        if ((float)(*(signed char *)(prm + 0x46) * 2) * 0.017453292f < d)
            hit = 0;
    }
    return hit;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C1AE0);
#endif

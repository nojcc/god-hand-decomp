/* NON_MATCHING func_002CB278 (sn,cse-const): rest matches; retail keeps -1 in s3 (set after cSnd_EmSeFind) and compares the find result against it, while ours copies the find result into s3 (cse treats it as the -1) and recomputes -1 in v1; the early-out branch also lands before sd ra in ours.
 * Flat early-return forms score 20-32. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct cSnd cSnd;
typedef struct cSeData cSeData;
extern int D_00747A84;
extern int cSnd_EmSeFind(cSnd *snd, int id);
extern int cSnd_FindFreeSe(cSnd *snd);
extern int cSnd_getEmSeGroupOwner(cSnd *snd, int id);
extern cSeData *cSnd_GetSeData(cSnd *snd, int slot);
extern int cSeData_LoadNumbered(cSeData *se, int slot, int owner);

int func_002CB278(cSnd *snd, int id)
{
    int slot;
    int owner;
    int ret;

    if (!(D_00747A84 & 0x20000000)) {
        if ((unsigned int)(id - 0x200) < 0xFF) {
            ret = -1;
            if (cSnd_EmSeFind(snd, id) == ret) {
                slot = cSnd_FindFreeSe(snd);
                if (slot != ret) {
                    owner = cSnd_getEmSeGroupOwner(snd, id);
                    if (cSeData_LoadNumbered(cSnd_GetSeData(snd, slot), slot, owner) != 0)
                        ret = slot;
                    return ret;
                }
            }
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002CB278);
#endif

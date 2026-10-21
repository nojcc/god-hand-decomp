/* NON_MATCHING func_002FBB78: sn; same loop as Esp_killByGroupNumber;
* all from one register choice: retail keeps the slot pointer in a2 (the third call argument) while ours uses a3 and copies it to a2 before the vtable call, adding one insn; hoisted this-adjust, local fn pointer, re-derived slot pointer forms no fix */
#include "include_asm.h"

#ifdef NON_MATCHING
#define ESP_SLOT_NUM     0x400
#define ESP_SLOT_SIZE    0x400
#define ESP_SLOT_ID      0x23A          /* offset of the slot's short effect id */
#define ESP_SLOT_SUB     0x23C          /* offset of the slot's unsigned short sub id */
#define ESP_SLOT_VTBL    0xF0

typedef struct {
    short delta;
    short index;
    void (*func)(void *self, int flag, void *slot);
} EspGrpVtEnt;

typedef struct {
    char pad0[0x30];
    EspGrpVtEnt notify;   /* 0x30 */
} EspGrpVtbl;

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: slot paused */
extern int D_0071B8C0[];                /* bit set: slot hidden */
extern unsigned char D_0061B7C0[];      /* the 0x400 effect slots, 0x400 bytes each */

void func_002FBB78(int id, int sub, unsigned char flag, int mode) {
    unsigned char *p;
    EspGrpVtbl *vt;
    int i;
    unsigned int bit;
    int w;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0) goto next;
        if ((D_0071B840[w] & bit) != 0) goto next;
        if ((D_0071B8C0[w] & bit) != 0) goto next;
        p = D_0061B7C0 + i * ESP_SLOT_SIZE;
        if ((mode == 0 && *(short *)(p + ESP_SLOT_ID) == id && *(unsigned short *)(p + ESP_SLOT_SUB) == sub) ||
            (mode == 1 && (*(short *)(p + ESP_SLOT_ID) != id || *(unsigned short *)(p + ESP_SLOT_SUB) != sub))) {
            vt = *(EspGrpVtbl **)(p + ESP_SLOT_VTBL);
            vt->notify.func(p + vt->notify.delta, flag, p);
        }
next: ;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002FBB78);
#endif

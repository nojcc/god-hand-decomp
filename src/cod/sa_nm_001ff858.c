/* NON_MATCHING func_001FF858 (sn-2.95.3-136; PARK at attempt 3): reset the pack name to the lowercased default, load and allocate the pack, then relocate its entry table (data offsets, and the reference of type-1 entries). Everything after the name loop matches. Retail keeps the name pointer (s0) and the index (s2, reset to 0 before the load and reused by the second loop) live through the lowercase loop, loading p[i] by index and storing through a pointer, so it saves s2 and uses a 0x50 frame; ours strength-reduces the index away. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct PackEnt1FF858 {
    unsigned char type;                 /* 0x00 */
    char pad1[3];
    int data;                           /* 0x04 */
    int ref;                            /* 0x08 */
} PackEnt1FF858;

typedef struct Pack1FF858 {
    PackEnt1FF858 *ents;                /* 0x00 */
    char pad4[8];
    int count;                          /* 0x0C */
    char *data;                         /* 0x10 */
    char pad14[5];
    char name[0x20];                    /* 0x19 */
} Pack1FF858;

extern unsigned char D_0045F039[];
extern char D_0042C6B0[];
extern char D_0042C6B8[];
extern char D_0042C6C8[];

extern void func_003A52F0(void *dst, int val, int len);
extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern void LoadAndWaitReady_1FFBF0(Pack1FF858 *self, char *name);
extern char *AllocSlotEntry_1FFC60(Pack1FF858 *self, char *name);

#define isupper(c) (D_0045F039[(int)(c)] & 1)
#define tolower(c) ({ int __x = (c); isupper(__x) ? (__x - 'A' + 'a') : __x; })

int func_001FF858(Pack1FF858 *self)
{
    int hdr[4];
    PackEnt1FF858 *e;
    char *p;
    int i;

    p = self->name;
    func_003A52F0(p, 0, 0x20);
    __builtin_memcpy(self->name, D_0042C6B0, 8);
    for (i = 0; p[i] != 0; i++)
        p[i] = tolower(p[i]);
    i = 0;
    LoadAndWaitReady_1FFBF0(self, D_0042C6B8);
    self->data = AllocSlotEntry_1FFC60(self, D_0042C6C8);
    func_003A5148(hdr, self->data, 0x10);
    self->ents = (PackEnt1FF858 *)(self->data + hdr[3]);
    self->data = self->data + hdr[2];
    e = self->ents;
    for (; i < self->count; i++) {
        if (e->type == 1 && e->ref != 0)
            e->ref += (int)self->ents;
        e->data += (int)self->data;
        e++;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001FF858);
#endif

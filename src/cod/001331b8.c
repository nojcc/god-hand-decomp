/* NON_MATCHING func_001331B8: name pointer setup (retail keeps nodes+i*0x14+0xC in v1 and copies to a3) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct ModelHdr {
    char pad0[0x20];
    unsigned short count;
} ModelHdr;

typedef struct ModelNameNode {
    char pad0[0x8];
    unsigned short first;
    unsigned short num;
    char name[8];
} ModelNameNode;

typedef struct ModelPart {
    char pad0[0x10];
    unsigned int flags;
} ModelPart;

typedef struct ModelNames {
    ModelHdr *hdr;
    ModelNameNode *nodes;
    char pad8[0x14 - 0x8];
    ModelPart *parts;
} ModelNames;

void func_001331B8(ModelNames *m, long name, int show)
{
    unsigned int i;
    int k;
    unsigned int c;
    int j;
    char *s;
    long key;

    if (m->hdr == 0)
        return;
    for (i = 0; i < m->hdr->count; i++) {
        key = 0;
        k = 0;
        s = m->nodes[i].name;
        if (*s != 0) {
            do {
                key |= (long)*s << (k * 8);
                k++;
                s++;
                if (k >= 8)
                    break;
            } while (*s != 0);
        }
        if (name == key) {
            c = m->nodes[i].num;
            j = m->nodes[i].first;
            while (c-- != 0) {
                if (show)
                    m->parts[j].flags &= ~2;
                else
                    m->parts[j].flags |= 2;
                j++;
            }
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001331B8);
#endif

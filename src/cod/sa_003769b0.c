typedef struct SndRegEnt {
    unsigned short id;
    char pad2[2];
    int key;
    unsigned char flags;
    char pad9[0x40 - 9];
} SndRegEnt;

extern SndRegEnt D_0076F050[];

__attribute__((section(".text.func_003769B0")))
SndRegEnt *func_003769B0(int key)
{
    SndRegEnt *p = &D_0076F050[0];
    int i;

    for (i = 0; i < 0x60; i++, p++) {
        if (p->id != 0 && !(p->flags & 0x10)) {
            if (key == 0)
                return p;
            if (p->key == key)
                return p;
        }
    }
    return 0;
}

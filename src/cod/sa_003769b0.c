/* sn-2.95.3-136, call_loop_pad: NM closer handoff. */
typedef struct Ent3769B0 {
    unsigned short id;
    char pad2[2];
    int key;
    unsigned char flags;
    char pad9[0x40 - 9];
} Ent3769B0;

extern Ent3769B0 D_0076F050[];

__attribute__((section(".text.func_003769B0")))
Ent3769B0 *func_003769B0(int key)
{
    Ent3769B0 *p = &D_0076F050[0];
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

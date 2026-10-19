/* sn-2.95.3-136: func_00148420, set up a motion/stream object from a data header and allocate its work buffer. */
typedef struct Data148420 {
    char unk00[8];
    unsigned short count;       /* 0x08 */
} Data148420;

typedef struct Obj148420 {
    char unk000[0x380];
    unsigned int flags;         /* 0x380 */
    unsigned char b384;         /* 0x384 */
    char unk385;
    unsigned char count;        /* 0x386 */
    char unk387;
    Data148420 *data;           /* 0x388 */
    char unk38C[0x74];
    int f400;                   /* 0x400 */
    char unk404[4];
    void *buf;                  /* 0x408 */
    char unk40C[4];
    int f410;                   /* 0x410 */
} Obj148420;

extern void *D_003C3CF0;
extern void cHeap_free(void *heap, void *p);
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *region);
extern int func_00155138(Obj148420 *self);
extern int func_00155248(Obj148420 *self);
extern void func_00154A90(Obj148420 *self, void *buf, void *heap);
extern void func_00155358(Obj148420 *self, void *buf, void *heap);
extern void func_00148F50(Obj148420 *self, Data148420 **data, int a2);
extern void func_001490B0(Obj148420 *self, Data148420 **data, int a2);

__attribute__((section(".text.func_00148420")))
int func_00148420(Obj148420 *self, Data148420 *data, int a2, unsigned int flags,
                  int a4, int a5, void *heap)
{
    void *p;
    int n;
    int multi;
    Data148420 *d;

    self->f400 = a2;
    self->b384 = 0;
    self->flags = flags;
    self->f410 = 0;
    self->data = data;
    n = data->count;
    self->count = n;
    d = data;
    if (self->buf != 0)
        cHeap_free(((void **)self->buf)[-8], self->buf);

    multi = d->count >= 2;
    if (multi) {
        int size = func_00155138(self);
        if (heap == 0) {
            p = EnsureInitThenForward_2A9538_30EE08(size, 0x10, D_003C3CF0);
            self->buf = p;
            if (p == 0)
                return 0;
            func_00154A90(self, p, 0);
        } else {
            p = EnsureInitThenForward_2A9538_30EE08(size, 0x10, heap);
            self->buf = p;
            if (p == 0)
                return 0;
            func_00154A90(self, p, heap);
        }
    } else {
        int size = func_00155248(self);
        if (heap == 0)
            self->buf = EnsureInitThenForward_2A9538_30EE08(size, 0x10, D_003C3CF0);
        else
            self->buf = EnsureInitThenForward_2A9538_30EE08(size, 0x10, heap);
        if (self->buf == 0)
            return 0;
        func_00155358(self, self->buf, 0);
    }

    if (flags & 0x1000000)
        func_00148F50(self, &d, a5);
    else
        func_001490B0(self, &d, a5);
    return 1;
}

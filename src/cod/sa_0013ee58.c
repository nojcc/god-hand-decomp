/* sn-2.95.3-136: scroll two UV channels (0x03 per frame, wrapping) into ID works 0/1, drive the fade values at 0xB0/0xB8
 * from channel 0, push them to ID work 2, and show/hide ID work 3 by the index at 0xBE. */
typedef struct UvCh { float x, y, z, w; } UvCh;
typedef struct UvScrollObj {
    char pad00[0x90];
    UvCh ch[2];   /* 0x90 */
    float b0;     /* 0xB0 */
    float b4;     /* 0xB4 */
    float b8;     /* 0xB8 */
    short pad_bc;
    unsigned short idx; /* 0xBE */
} UvScrollObj;

extern char *cIDBase_getIDWork(void *self, int n);
extern void cIDBase_move(void *self);

__attribute__((section(".text.func_0013EE58")))
void func_0013EE58(UvScrollObj *p)
{
    char *w[3];
    char *w2;
    unsigned short i;
    float f;

    w[0] = cIDBase_getIDWork(p, 0);
    w[1] = cIDBase_getIDWork(p, 1);
    w2 = cIDBase_getIDWork(p, 2);
    w[2] = cIDBase_getIDWork(p, 3);
    for (i = 0; i < 2; i++) {
        p->ch[i].y += 0.03f;
        p->ch[i].x += 0.03f;
        if (p->ch[i].y >= 2.0f) {
            p->ch[i].y = 0.0f;
            p->b8 = 0.0f;
            p->b0 = 0.0f;
        }
        if (p->ch[i].x >= 3.0f)
            p->ch[i].x = 1.0f;
        *(float *)(w[i] + 0x70) = p->ch[i].x;
        *(float *)(w[i] + 0x78) = p->ch[i].y;
        *(float *)(w[i] + 0x74) = p->ch[i].z;
        *(float *)(w[i] + 0x7C) = p->ch[i].w;
    }
    f = p->ch[0].y;
    if (f < 1.0f)
        p->b8 = f * 256.0f;
    else if (1.0f < f)
        p->b0 = (f - 1.0f) * 256.0f;
    *(float *)(w2 + 0x38) = p->b4 + p->b0;
    *(float *)(w2 + 0x68) = p->b8;
    if ((short)p->idx != -1) {
        *(int *)(w[2] + 0x2C) &= ~0x08000000;
        *(unsigned short *)(w[2] + 0x90) = p->idx;
    } else {
        *(int *)(w[2] + 0x2C) |= 0x08000000;
        *(unsigned short *)(w[2] + 0x90) = 0xFFFF;
    }
    cIDBase_move(p);
}

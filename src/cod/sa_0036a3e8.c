/* cygnus-2.96 --drop-reorder: MPEG video header decode: peek the input SJ, check for a sequence end, then step
 * through the delimiters (sequence, GOP, picture, user data, extension) until a picture start or an error. */
typedef struct Ck36A3E8 { char *data; int len; } Ck36A3E8;

typedef struct OBJ OBJ;
struct OVT {
    char pad[0x18];
    void (*getChunk)(OBJ *, int, int, Ck36A3E8 *);      /* 0x18 */
    void (*ungetChunk)(OBJ *, int, Ck36A3E8 *);         /* 0x1C */
};
struct OBJ { struct OVT *vt; };

typedef struct Dec36A3E8 {
    char pad[0x3F4];
    int f3F4;                           /* 0x3F4 */
} Dec36A3E8;

extern int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(Dec36A3E8 *dec);
extern int func_00369F20(Dec36A3E8 *dec, int err);
extern int func_0036A708(Dec36A3E8 *dec, Ck36A3E8 *ck);
extern int func_0036C6C8(Dec36A3E8 *dec, OBJ *sj);
extern int func_0036BCD0(Dec36A3E8 *dec, int a, OBJ *sj);
extern int mpvhdec_GetCurDelim(OBJ *sj);
extern void func_0036B6D8(Dec36A3E8 *dec, OBJ *sj, int last);
extern void func_0036B798(Dec36A3E8 *dec, OBJ *sj, int last);
extern void func_0036B0F0(Dec36A3E8 *dec, OBJ *sj);
extern void func_0036AE70(Dec36A3E8 *dec, OBJ *sj);
extern void func_0036A7B0(Dec36A3E8 *dec, OBJ *sj);

__attribute__((section(".text.func_0036A3E8")))
int func_0036A3E8(Dec36A3E8 *dec, OBJ *sj)
{
    Ck36A3E8 ck;
    Ck36A3E8 ck2;
    int d;
    int last;
    int r;

    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(dec) != 0)
        return func_00369F20(0, 0xFF03020C);
    dec->f3F4 = 0;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
    sj->vt->ungetChunk(sj, 1, &ck);
    ck2.data = ck.data;
    ck2.len = ck.len;
    if (func_0036A708(dec, &ck2) == 2)
        return func_0036C6C8(dec, sj);
    last = 0;
    for (;;) {
        r = func_0036BCD0(dec, -1, sj);
        if (r != 0)
            return func_00369F20(dec, r);
        d = mpvhdec_GetCurDelim(sj);
        if (d == 0)
            break;
        if (d & 3)
            break;
        r = -2;
        if (d & 0x80)
            break;
        switch (d) {
        case 0x40:
            last = 0x40;
            func_0036A7B0(dec, sj);
            break;
        case 0x08:
            last = 0x08;
            func_0036AE70(dec, sj);
            break;
        case 0x04:
            last = 0x04;
            func_0036B0F0(dec, sj);
            break;
        case 0x10:
            func_0036B6D8(dec, sj, last);
            break;
        case 0x20:
            func_0036B798(dec, sj, last);
            break;
        }
    }
    return r;
}

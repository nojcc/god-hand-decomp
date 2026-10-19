/* cygnus-2.96: func_00354BD8, apply a pending request: copy its parameter blocks to the globals, run it and tail-call the state change on success, else clear the request. */
typedef struct A354BD8 { int w[9]; } A354BD8;      /* 0x24 */
typedef struct B354BD8 { int w[2]; } B354BD8;      /* 0x08 */
typedef struct C354BD8 { int w[16]; } C354BD8;     /* 0x40 */

typedef struct Req354BD8 {
    int id;                             /* 0x00 */
    A354BD8 a;                          /* 0x04 */
    B354BD8 b;                          /* 0x28 */
    C354BD8 c;                          /* 0x30 */
    char unk70[0x1080 - 0x70];
    int x;                              /* 0x1080 */
    int y;                              /* 0x1084 */
    int z;                              /* 0x1088 */
} Req354BD8;

extern A354BD8 D_00766BA8;
extern B354BD8 D_00766BD0;
extern C354BD8 D_00766BD8;
extern int D_00766C18;
extern int D_00766C1C;
extern int D_00766C20;

extern void func_003567E0(char *p);
extern int func_00354D68(int id);
extern int func_0034DD70(char *p, int state);

__attribute__((section(".text.func_00354BD8")))
int func_00354BD8(char *p)
{
    Req354BD8 *req = *(Req354BD8 **)(p + 0x1FC0);
    int id = req->id;

    if (id == 0)
        return 0;
    D_00766BA8 = req->a;
    D_00766BD0 = req->b;
    D_00766BD8 = req->c;
    D_00766C18 = req->x;
    D_00766C1C = req->y;
    D_00766C20 = req->z;
    func_003567E0(p);
    if (func_00354D68(id))
        return func_0034DD70(p, 0xFF000F0C);
    req->id = 0;
    return 0;
}

/* NON_MATCHING LightData_Load (sn-2.95.3-136 -fno-gcse;
 * PARK, 165 diffs): retail keeps i*0x80 in s3 from a temp and does not strength-reduce the inner j*0x70 (mult per iteration); base/s register pair swapped */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { float m[28]; } Light70;
typedef struct { unsigned char c[4]; } Tag4;
typedef struct {
    Light70 l;
    int n;
    Light70 *arr;
    int pad[2];
} LightEnt;
typedef struct {
    Tag4 tag;
    int pad[3];
    LightEnt e[8];
    void *p[8];
} LightData;

extern int D_00747A4C;
extern char D_0044D248[];
extern char D_0044D250[];
extern char D_0044D258[];
extern char D_00754220[];
extern char *SearchData(int, char *, int);
extern int func_003A5678(char *, char *);
extern int func_003A50B4(void *, char *, int);
extern void *EnsureInitThenForward_2A9538_30EE08(int, int, void *);

int LightData_Load(LightData *d)
{
    char *s;
    char *base;
    int i;
    int j;
    int ok;
    int off;

    i = 0;
    ok = 0;
    s = SearchData(D_00747A4C, D_0044D248, 0);
    base = s;
    if (s != 0 && func_003A5678(s, D_0044D250) == 0)
        return 0;
    d->tag = *(Tag4 *)s;
    if (func_003A50B4(d, D_0044D258, 4) != 0)
        return ok;
    s = base + 4;
    goto test;
body:
    {
        off = i * sizeof(LightEnt);
        (*(LightEnt *)((char *)d->e + off)).l = *(Light70 *)s;
        d->p[i] = s + 0x70;
        *(Tag4 *)&(*(LightEnt *)((char *)d->e + off)).n = *(Tag4 *)(s + 0x174);
        s += 0x178;
        if ((*(LightEnt *)((char *)d->e + off)).arr == 0 && (*(LightEnt *)((char *)d->e + off)).n > 0) {
            (*(LightEnt *)((char *)d->e + off)).arr = EnsureInitThenForward_2A9538_30EE08((*(LightEnt *)((char *)d->e + off)).n * 0x70, 0x10, D_00754220);
            if ((*(LightEnt *)((char *)d->e + off)).arr == 0)
                goto done;
        }
        for (j = 0; j < (*(LightEnt *)((char *)d->e + off)).n; j++) {
            (*(LightEnt *)((char *)d->e + off)).arr[j] = *(Light70 *)s;
            s += 0x70;
        }
    }
    i++;
test:
    if (i < 8)
        goto body;
    ok = 1;
done:
    return ok;
}
#else
INCLUDE_ASM("asm/nonmatching", LightData_Load);
#endif

/* NON_MATCHING func_0028EBF0: same inlined range-check idiom as func_001A6FB0: retail a1=0; slti; bnez; a1=slt; andi 0xFF.
 * C forms give movn or drop the a1 copy */
#include "godhand/vec.h"
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Src28EBF0 {
    char pad00[0x10];
    Vec3f pos;
    char pad1C[4];
    float rot;
} Src28EBF0;

typedef struct Mdl28EBF0 {
    char pad000[0xF0];
    Vec3f *pos;
    char pad0F4[0x104 - 0xF4];
    float rot;
    char pad108[0x254 - 0x108];
    int flags254;
    char pad258[0x2FE - 0x258];
    unsigned short kind;
    char pad300[0x3A8 - 0x300];
    float unk3A8;
    char pad3AC[0x490 - 0x3AC];
    Vec3f home;
    char pad49C[0x531 - 0x49C];
    unsigned char unk531;
    char pad532[0x570 - 0x532];
    short unk570;
    char pad572[2];
    int unk574;
    char pad578[0x610 - 0x578];
    int unk610;
    unsigned char unk614;
    unsigned char unk615;
    unsigned char unk616;
    unsigned char unk617;
    char pad618[0x622 - 0x618];
    unsigned char unk622;
    unsigned char unk623;
    char pad624[4];
    int unk628;
    short unk62C;
    char pad62E[2];
    float unk630;
    char pad634[0x644 - 0x634];
    float unk644;
    char pad648[0x660 - 0x648];
    void *anim;
} Mdl28EBF0;

extern char *D_003BD6E8;
extern void cIDBase_restartAnim(void *anim);

static inline void Vec28EBF0_copy(Vec3f *d, Vec3f *s)
{
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline unsigned char InRange28EBF0(int v, int lo, int hi)
{
    if (v >= lo) {
        return v < hi;
    }
    return 0;
}

int func_0028EBF0(Mdl28EBF0 *self, Src28EBF0 *src, int arg)
{
    Vec28EBF0_copy(self->pos, &src->pos);
    Vec28EBF0_copy(&self->home, self->pos);
    self->rot = src->rot;
    self->unk628 = arg;
    self->unk531 = 3;
    self->unk644 = 1.0f;
    self->unk610 = 0;
    self->unk614 = 0;
    self->unk615 = 0;
    self->unk616 = 0;
    self->unk623 = 0;
    self->unk62C = 0;
    self->unk617 = 0;
    self->unk622 = 0;
    self->unk630 = 1.0f;
    if (InRange28EBF0(self->kind, 0x2A0, 0x300)) {
        self->anim = D_003BD6E8 + 0xE50;
    } else {
        self->anim = D_003BD6E8 + 0xE00;
    }
    cIDBase_restartAnim(self->anim);
    self->unk3A8 = 1.0f;
    self->flags254 |= 0x08000000;
    self->unk570 = -1;
    self->unk574 = 2;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0028EBF0);
#endif

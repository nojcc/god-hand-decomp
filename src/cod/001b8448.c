#include "godhand/cOmBase.h"
extern void KillEffect(void *, int, int);

__attribute__((section(".text.func_001B8448")))
void func_001B8448(void *p)
{
    KillEffect(p, 0, 2);
    cOmBase_dieCommon(p);
}

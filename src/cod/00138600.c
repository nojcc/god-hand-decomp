#include "godhand/cCameraFn.h"
#include "godhand/cCockEmBar.h"

struct vtbl {
    char pad[0x10];
    short off;
    void (*fn)(int);
};

extern void cCamera_stepVib(struct cCamera *self);
extern void cCamera_update(struct cCamera *self);
/* One camera step: the subclass move method, the vibration, the update. */
__attribute__((section(".text.cCamera_move")))
void cCamera_move(struct cCamera *self) {
    cCamVt *vt = self->vt;
    vt->move((int)self + vt->moveDelta);
    cCamera_stepVib(self);
    cCamera_update(self);
}

/* Reset the animation of the bar and its four sub displays. */
__attribute__((section(".text.InitFiveSubstructs2ABA78_13D0B8")))
void InitFiveSubstructs2ABA78_13D0B8(cCockEmBar *self)
{
    cIDBase_resetAnim(&self->base);
    cIDBase_resetAnim(&self->sub[2].id);
    cIDBase_resetAnim(&self->sub[3].id);
    cIDBase_resetAnim(&self->sub[0].id);
    cIDBase_resetAnim(&self->sub[1].id);
}

/* Step the jitter of the bar and its four sub displays. */
__attribute__((section(".text.InitFiveSubstructs2AABA0_13D100")))
void InitFiveSubstructs2AABA0_13D100(cCockEmBar *self)
{
    cIDBase_stepJitter(&self->base);
    cIDBase_stepJitter(&self->sub[2].id);
    cIDBase_stepJitter(&self->sub[3].id);
    cIDBase_stepJitter(&self->sub[0].id);
    cIDBase_stepJitter(&self->sub[1].id);
}

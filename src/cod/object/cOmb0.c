/* TU: cOmb0 [object] - recovered C++ class. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cOmb0.h"
#include "include_asm.h"

struct sph { int a; float b; int c; float d; };


/* Raise the collision flag and register a 1.75 radius sphere at the object's position. */
__attribute__((section(".text.cOmb0_SetCollision")))
void cOmb0_SetCollision(cOmb0 *self)
{
    cOmb0Sphere s;
    self->collisionOn = 1;
    s.unk00 = 0;
    s.radius = 1.75f;
    s.unk08 = 0;
    s.scale = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, (struct cGameObj *)self, self->pos, (cVec *)&s, 1.75f);
}


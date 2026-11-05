/* include/godhand/cEmWeaponSpawn.h - an enemy creating a weapon object at its position. */
#ifndef GODHAND_CEMWEAPONSPAWN_H
#define GODHAND_CEMWEAPONSPAWN_H

#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/player.h"
#include "godhand/vecInline.h"

/* The body of an enemy method that creates weapon object `type` at the
 * enemy's position, unturned, and returns it; it returns 0 for a type that
 * isn't a weapon or when the object fails to start. Retail has two copies
 * (func_0026AA30, func_0028D048). A macro, because as an inline function the
 * result takes an extra move. */
#define CEM00_CREATE_WEAPON(self, type) \
    { \
        cGameObj *w_; \
 \
        switch (type) { \
        case 0x361: case 0x362: case 0x363: case 0x365: case 0x366: case 0x367: \
        case 0x368: case 0x369: case 0x36A: case 0x36B: case 0x36C: case 0x36D: \
        case 0x36E: case 0x36F: case 0x370: case 0x372: case 0x373: case 0x374: \
        case 0x375: case 0x377: case 0x378: case 0x379: case 0x37A: case 0x37D: \
        case 0x37E: case 0x37F: case 0x380: case 0x3B7: \
            w_ = CreateObj(type, 0xFFFF); \
            if (w_ == 0) { \
                return 0; \
            } \
            if (cGameObj_vt(w_)->initial((char *)w_ + cGameObj_vt(w_)->initialDelta) == 0) { \
                return 0; \
            } \
            cVec_copy3(w_->pos, (self)->pos); \
            cVec_copy3(&w_->posA, w_->pos); \
            vec3_set(&w_->rot.x, 0.0f, 0.0f, 0.0f); \
            return (cOmWeapon *)w_; \
        default: \
            return 0; \
        } \
    }

#endif

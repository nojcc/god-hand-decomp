/* include/godhand/objField.h - small field helpers the effect setup code calls.
 *
 * Obj0000_Set_Field_50_173998, Obj0000_Set_Byte_54 and the three CopyVec3
 * helpers write fixed offsets of the record the caller passes. In the setup
 * code at 0x160E78 and its siblings that record is a 0x60-byte slot from the
 * array at owner + 0x628, and field 0x50 gets a pointer to node + 0x80. The
 * breakable objects keep one per child body for its flying piece: cOmPiece.
 *
 * Set_Field_50 and Set_Byte_54 are defined in the monolith 000000.c, the
 * CopyVec3 helpers in the carved TU 0014b6f8.c, ForwardVec3At30_147C60 in
 * 00124f60.c. Each definition includes this header, so a drifted prototype
 * fails to compile.
 *
 * GetField_54_173900 is not here on purpose: callers declare it returning int
 * and the definition returns unsigned char, and one prototype would change
 * what the callers compile to.
 */
#ifndef GODHAND_OBJFIELD_H
#define GODHAND_OBJFIELD_H

#include "godhand/cOmBase.h"

/* A loose piece of a broken object: it moves by vel and turns by spin every
 * frame, falls by gravity, and writes its matrix to the child body's. */
typedef struct cOmPiece {
    cVec pos;                           /* 0x00 */
    cVec rot;                           /* 0x10 */
    cVec vel;                           /* 0x20 */
    cVec spin;                          /* 0x30 */
    cVec scale;                         /* 0x40 */
    float *mtx;                         /* 0x50 the child body's matrix */
    unsigned char active;               /* 0x54 GetField_54_173900 / Obj0000_Set_Byte_54 */
    char unk55[3];
    float gravity;                      /* 0x58 added to vel.y every frame */
    char unk5C[4];
} cOmPiece;

typedef char cOmPiece_size_check[sizeof(cOmPiece) == 0x60 ? 1 : -1];

/* Store the pointer value at offset 0x50 of rec. */
extern void Obj0000_Set_Field_50_173998(void *rec, void *value);

/* Store the low byte of value at offset 0x54 of rec. */
extern void Obj0000_Set_Byte_54(void *rec, int value);

/* Copy x, y and z from src into the vector at offset 0x20 of rec. */
extern void CopyVec3ToField20_173908(char *rec, float *src);

/* Copy x, y and z from src into the vector at offset 0x30 of rec. */
extern void CopyVec3ToField30_173938(char *rec, float *src);

/* Copy x, y and z from src into the vector at offset 0x40 of rec. */
extern void CopyVec3ToField40_173968(char *rec, float *src);

/* Write the translation row of the 4x4 matrix mtx (floats 12 to 14) to dst.
 * The body passes only the three floats: dst reaches func_00150710 untouched
 * in $a0. */
extern void ForwardVec3At30_147C60(void *dst, float *mtx);

#endif

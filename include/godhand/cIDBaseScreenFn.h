/* include/godhand/cIDBaseScreenFn.h - cIDBaseScreen methods that more than one unit calls.
 *
 * cIDBaseScreen.h holds the record. Older units (00126918.c among them)
 * declare some of these themselves with their own parameter types, so the
 * prototypes live here for the units that take them from a header.
 */
#ifndef GODHAND_CIDBASESCREENFN_H
#define GODHAND_CIDBASESCREENFN_H

#include "godhand/cIDBaseScreen.h"

void cIDBaseScreen_init(cIDBaseScreen *self);
void func_00144C90(cIDBaseScreen *self);
void func_00145238(cIDBaseScreen *self);
void func_00145410(cIDBaseScreen *self);
void func_00145460(cIDBaseScreen *self);
void func_00145810(cIDBaseScreen *self);
void func_00145FC8(cIDBaseScreen *self);
void func_00146190(cIDBaseScreen *self);
void BlendWork_copyTable(cIDBaseScreen *self, void **src, short num);
void BlendWork_copyShortTable(cIDBaseScreen *self, short *src, short num);
void SetFlagAfterCopy_145160(cIDBaseScreen *self, short *src);
void func_001451A0(cIDBaseScreen *self, unsigned char *src, short num);

void BlendSetup_load(cIDBaseScreen *self, void **tex, short *item, unsigned char *attr, short num,
                     unsigned short start);

#endif /* GODHAND_CIDBASESCREENFN_H */

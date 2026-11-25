/* include/godhand/vtables.h - the retail method tables of the classes that
 * have no header of their own yet.
 *
 * Each table is the one a class's constructor stores at 0x214 (and its
 * destructor stores back). The class is the one the table's type-info
 * function names: word 1 of each table points at that function, which
 * builds the type info from the class's mangled name. A class that gets its
 * own header takes its line from here.
 */
#ifndef GODHAND_VTABLES_H
#define GODHAND_VTABLES_H

#include "godhand/cModel.h"             /* cVtEnt */

extern cVtEnt D_0041EA90[];  /* cModel */
extern cVtEnt D_0041EAF0[];  /* cObj */
extern cVtEnt D_00427400[];  /* cOm51 */
extern cVtEnt D_00447D48[];  /* cEm32 */
extern cVtEnt D_00447E68[];  /* cEm3f */
extern cVtEnt D_004481A8[];  /* cEm63 */
extern cVtEnt D_004483A8[];  /* cEm66 */
extern cVtEnt D_00448598[];  /* cEm6b */
extern cVtEnt D_0044A408[];  /* cEma6 */
extern cVtEnt D_0044A528[];  /* cEmad */
extern cVtEnt D_0044E538[];  /* esp04 */
extern cVtEnt D_0044EE38[];  /* esp20 */
extern cVtEnt D_0044F1C8[];  /* esp25 */
extern cVtEnt D_00450B28[];  /* dbObj */
extern cVtEnt D_00450C38[];  /* objCock */
extern cVtEnt D_00450CE8[];  /* objScroll */

#endif /* GODHAND_VTABLES_H */

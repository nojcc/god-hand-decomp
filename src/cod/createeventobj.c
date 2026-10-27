/* CreateEventObj — allocate an event object (func_00312AB0) and initialise it
 * (func_0030FB20), returning the initialised object.  sn-2.95.3-136. */
#include "godhand/cObj.h"

__attribute__((section(".text.CreateEventObj")))
char *CreateEventObj(int id, int dataId) {
    return func_0030FB20(id, func_00312AB0(id, dataId));
}

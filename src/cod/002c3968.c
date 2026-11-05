#include "godhand/cScenario.h"
#include "godhand/criStm.h"

__attribute__((section(".text.cScenario_clearTaskData")))
void cScenario_clearTaskData(cScenario *scenario, int index)
{
    if (index >= 0)
        func_003A52F0(&scenario->taskData[index], 0, 8);
}

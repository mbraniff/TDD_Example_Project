#include <string.h>
#include "fff.h"
#include "mock_adder.h"

DEFINE_FAKE_VALUE_FUNC2(int, add, int, int)

void mock_adder_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(add)
}
void mock_adder_Verify(void)
{
}
void mock_adder_Destroy(void)
{
}

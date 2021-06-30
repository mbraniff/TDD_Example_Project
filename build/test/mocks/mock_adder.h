#ifndef mock_adder_H
#define mock_adder_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "adder.h"


DECLARE_FAKE_VALUE_FUNC2(int, add, int, int)

void mock_adder_Init(void);
void mock_adder_Verify(void);
void mock_adder_Destroy(void);

#endif // mock_adder_H

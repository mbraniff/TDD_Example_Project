#include "TurnOnLED.h"

bool LED(int time)
{
    if(time >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
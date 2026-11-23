#include "heartrate.h"
#include <iostream>
#include <cstdlib>

void heartrate::setRate()
{
    rate = 75 + rand() % 51;  // random number from 50 to 100
}

int heartrate::getRate() const
{
    return rate;
}
bool heartrate::isNormal(int age) const
{
    if (age < 3)
    {
        if (rate < 104 && rate > 98)
            return true;
        else
            return false;
    }
    else if (age < 12)
    {
        if (rate < 118 && rate > 80)
            return true;
        else
            return false;
    }
    else
    {
        if (rate < 100 && rate > 60)
            return true;
        else
            return false;
    }
}
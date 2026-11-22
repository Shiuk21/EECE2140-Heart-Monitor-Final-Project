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
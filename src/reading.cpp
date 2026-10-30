#include "reading.h"

Reading::Reading()
{
    live_reading = 0;
}

void Reading::setReading(bool a)
{
    live_reading = a;
}

bool Reading::getReading() const
{
    return live_reading;
}
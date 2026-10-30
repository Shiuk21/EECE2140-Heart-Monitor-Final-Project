#include "activity.h"

Activity::Activity()
{
    activity = 0; //set default to be at rest
}

void Activity::setActivity(int a)
{
    activity = a;
}

int Activity::getActivity() const
{
    return activity;
}
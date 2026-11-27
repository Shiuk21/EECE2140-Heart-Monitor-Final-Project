#include "heartrate.h"
#include <iostream>
#include <cstdlib>

void heartrate::setRate()
{
    std::cout << "What is your heart rate? " << std::endl;
    std::cin >> rate;
    //rate = 75 + rand() % 51;  // random number from 50 to 100
}

int heartrate::getRate() const
{
    return rate;
}

bool heartrate::isNormal(int age, int activity) const
{
    //Compares to age and current activity
    int low, high;

    if (age < 3)
    {
        if (activity == 0)
        { 
            low = 98;  
            high = 104; 
        }
        else                    
        { 
            low = 98;  
            high = 140; 
        }
    }
    else if (age < 12)
    {
        if (activity == 0)      
        { 
            low = 80;  
            high = 118; 
        }
        else if (activity == 1) 
        { 
            low = 80;  
            high = 125; 
        }
        else                    
        { 
            low = 90;  
            high = 160; 
        }
    }
    else if (age < 55)
    {
        if (activity == 0)      
        { 
            low = 60;  
            high = 100; 
        }
        else if (activity == 1) 
        { 
            low = 75;  
            high = 140; 
        }
        else                    
        { 
            low = 85;  
            high = 170; 
        }
    }
    else
    {
        if (activity == 0)      
        { 
            low = 60;  
            high = 100; 
        }
        else if (activity == 1) 
        { 
            low = 70;  
            high = 112; 
        }
        else                    
        { 
            low = 75;  
            high = 128; 
        }
    }

    return rate >= low && rate <= high;
}
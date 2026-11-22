#include <iostream>
#include <string>
#include "person.h"
#include "activity.h"
#include "reading.h"
#include "heartrate.h"
using namespace std;

int ageSet()
{
    int a;
    do
    {
        cout << "How old are you?  ";
        cin >> a;
        
        if (a < 0)
            cout << "Uh...I don't know if you can be not born. Enter your real age." << endl;
        
    }
    while (a < 0);
    return a;
}

int activitySet()
{
    int a;
    cout << "What activity are you doing? (0 = at rest, 1 = walking, 2 = working out): ";
    cin >> a;
    return a;
}

bool readingSet()
{
    char s;
    cout << "Would you like to view your live heartrate reading? (y/n): ";
    cin >> s;
    if (s == 'y')
        return true;
    else if (s == 'n')
        return false;
    else
    {
        cout << "Invalid input. Assuming no." << endl; //added a default case just in case the user inputs something other than y or n. - Michael
        return false;
    }
}

string activityIs(int a)
{
    if (a==0)
        return "at rest";
    if (a==1)
        return "walking";
    if (a==2)
        return "working out";
    return "unknown";
}

string readingIs(bool a)
{
    if (a == true)
        return "Yes";
    else
        return "No";
}

int main()
{
    int option;
    int age;
    int activity;
    bool reading;
    bool ageCheck = false; // New variable that checks if user has input their age -Michael
    bool infant = false;
    bool adolescent = false;
    bool adult = false;

    Person p;
    Activity a;
    Reading r;
    heartrate check;

    cout << "Welcome to the Heart Rate Monitor Program! Press enter to start.";
    cin.get();

    do 
    {
        cout << endl;
        cout << "What would you like to do?" << endl << "Enter: 1 to set your age; 2 to choose an activity; 3 to read your heart rate; 0 to exit the program ";
        cin >> option;
        cout << endl;

        if (!cin) // Reads for bad cin input. If a letter is typed then cin will read the value into badInput so that it's clear again and the loop can safely iterate again.
        {
            string badInput;
            cin.clear();
            cin >> badInput;
            option = -1;
        }

        switch (option)
        {
            case 1:
                age = ageSet();

                p.setAge(age);
                cout << "You've set your age to " << p.getAge() << endl;
                ageCheck = true;
                if (p.getAge() > 1 && p.getAge() < 3)
                {
                    infant = true;
                    adult = false;
                    adolescent = false;
                }
                else if (p.getAge() < 12)
                {
                    adolescent = true;
                    infant = false;
                    adult = false;
                }
                else
                {
                    adult = true;
                    infant = false;
                    adolescent = false;
                }


                break;
            case 2:
                activity = activitySet();

                a.setActivity(activity);
                cout << "The activity that you are doing is set to " << activityIs(a.getActivity()) << endl;
                break;
            case 3:
                if (!ageCheck) // Checks if user has input their age bbefore checking their heart rate.
                {
                    cout << "Please input your age before checking your heart rate." << endl;
                    break;
                }

                reading = readingSet();

                r.setReading(reading);
                if (r.getReading())
                {
                    check.setRate();
                    cout << "Your heart rate is currently: " << check.getRate() << endl;

                    if (infant)
                    {
                        if (check.getRate() < 104 && check.getRate() > 98)
                        {
                            cout << "Your heart rate seems normal." << endl;
                        }
                        else
                        {
                            cout << "Your heart rate doesn't seem normal. It might be worth going to see a doctor." << endl;
                        }
                    
                    }
                    else if (adolescent)
                    {
                        if (check.getRate() < 118 && check.getRate() > 80)
                        {
                            cout << "Your heart rate seems normal." << endl;
                        }
                        else
                        {
                            cout << "Your heart rate doesn't seem normal. It might be worth going to see a doctor." << endl;
                        }
                    
                        
                    }
                    else if (adult)
                    {
                        if (check.getRate() < 100 && check.getRate() > 60)
                        {
                            cout << "Your heart rate seems normal." << endl;
                        }
                        else
                        {
                            cout << "Your heart rate doesn't seem normal. It might be worth going to see a doctor." << endl;
                        }
                    
                    }

                    //1 - 3; 98 - 104
                    //4-12; 80 - 118
                    ///18+ 60 - 100
                }
                
                break;
            case 0:
                break;
            default:
                cout << "Invalid. Please choose a valid menu option." << endl;
                break;
        }
    }
    while (option != 0);

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}

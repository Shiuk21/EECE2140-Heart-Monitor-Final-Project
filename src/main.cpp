#include <iostream>
#include <string>
#include "person.h"
#include "activity.h"
#include "reading.h"
#include "heartrate.h"
using namespace std;

//Michael's Function
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

//Ella's Function
int activitySet()
{
    int a;
    cout << "What activity are you doing? (0 = at rest, 1 = walking, 2 = working out): ";
    cin >> a;
    //Makes a default case if user chooses something else other than those numbers.
    if (!cin || (a < 0 || a > 2))
    {
        cout << "Please choose a valid option. Defaulting to default." << endl;
        a = 0;
    }
    return a;
}

//Rachel's Function
bool readingSet()
{
    string s; // CHANGED TO STRING SO THAT CIN DOESNT BUFFER TWO INPUTS
    cout << "Would you like to view your live heartrate reading? (y/n): ";
    cin >> s;
    if (s == "y")
        return true;
    else if (s == "n")
        return false;
    else
    {
        cout << "Invalid input. Assuming no." << endl; //added a default case just in case the user inputs something other than y or n. - Michael
        return false;
    }
}

//Ella's Function
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

//Rachel's Function
string readingIs(bool a, int age, int activity)
{
    if (a == true)
        return "Your age is set to " + to_string(age) + " and you are currently " + activityIs(activity) + ".";
    else
    {
        return "Returning to menu.";
    }
}

//Everyone worked on main
int main()
{
    //Variables
    int option;
    int age;
    int activity = 0;
    bool reading;
    bool ageCheck = false; // New variable that checks if user has input their age -Michael

    //Objects
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
                break;
            case 2:
                activity = activitySet();

                a.setActivity(activity);
                cout << "The activity that you are doing is set to " << activityIs(a.getActivity()) << endl;
                break;
            case 3:
                if (!ageCheck) // Checks if user has input their age before checking their heart rate.
                {
                    cout << "Please input your age before checking your heart rate." << endl;
                    break;
                }

                //Asks user if they want to see a live reading, breaks if no 
                reading = readingSet();
                if (reading)
                {
                    r.setReading(reading);
                    cout << readingIs(r.getReading(), age, activity) << endl;
                }
                else
                {
                    r.setReading(reading);
                    cout << readingIs(r.getReading(), age, activity) << endl;
                    break;
                }

                check.setRate();
                cout << "Your heart rate is " << check.getRate() << " beats per minute." << endl;
                
                if (check.isNormal(p.getAge(), activity))
                    cout << "Your heart rate seems normal." << endl;
                else
                    cout << "Your heart doesn't seem normal. It might be worth going to a doctor to get checked." << endl;
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

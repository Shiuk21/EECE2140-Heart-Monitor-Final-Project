#include <iostream>
#include <string>
using namespace std;
#include "person.h"
#include "activity.h"

int ageSet()
{
    int a;
    cout << "Please enter age: ";
    cin >> a;
    return a;
}

int activitySet()
{
    int a;
    cout << "What activity are you doing? (0 = at rest, 1 = walking, 2 = working out): ";
    cin >> a;
    return a;
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

int main()
{
    int option;
    int age;
    int activity;

    Person p;
    Activity a;

    cout << "Welcome to the Heart Rate Monitor Program! Press enter to start.";
    cin.get();

    do 
    {
        cout << endl;
        cout << "What would you like to do?" << endl << "Enter: 1 to set your age; 2 to choose an activity; 3 to read your heart rate; 0 to exit the program) ";
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
                break;
            case 2:
                activity = activitySet();

                a.setActivity(activity);
                cout << "The activity that you are doing is set to " << activityIs(a.getActivity()) << endl;
                break;
            case 3:
                cout << "Whoah! This feature hasn't been implemented yet. So you don't have a heart rate. Yikes. Tough luck." << endl; // Replace this with the actual code later. This is just a placeholder for now. - Michael 
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

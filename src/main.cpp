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

    cout << "Welcome to the Heart Rate Monitor Program! Press enter to start." << endl;
    cin.get();

    do 
    {
        cout << "Please select an option: (1 to set your age, 2 to set your activity, 0 to exit): ";
        cin >> option;

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
    }
    }
    while (option != 0);

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}

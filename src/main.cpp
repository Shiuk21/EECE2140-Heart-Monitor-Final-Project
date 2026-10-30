#include <iostream>
using namespace std;
#include "person.h"

int ageSet()
{
    int a;
    cout << "Please enter age: ";
    cin >> a;
    return a;
}

int main()
{
    int option;
    int age;

    cout << "Welcome to the Heart Rate Monitor Program! Press anywhere to start." << endl;
    cin.get();

    do 
    {
        cout << "Please select an option: (1 to set your age, 0 to exit): ";
        cin >> option;

        switch (option)
    {
        case 1:
            age = ageSet();

            Person p;
            p.setAge(age);
            cout << "You've set your age to " << p.getAge() << endl;
    }
    }
    while (option != 0);
    cout << "Exiting the program. Goodbye!" << endl;
    
}

#include "vector.h"
#include <string>
using namespace std;


// ------------------- MAIN FUNCTION -------------------
int main() 
{
    string battleName;
    int capacity;

    cout << "Enter battle name: ";
    getline(cin, battleName);

    cout << "Enter max heroes allowed: ";
    cin >> capacity;

    // TODO: Initialize Battle object
    Battle b1(battleName, capacity);

    int choice;
    do {
        cout << "\n===== " << battleName << " Menu =====\n";
        cout << "1. Add Hero\n";
        cout << "2. Remove Hero\n";
        cout << "3. Display Heroes\n";
        cout << "4. Simulate Damage\n";
        cout << "5. Show Strongest Hero\n";
        cout << "6. Show Average Power\n";
        cout << "7. Level Up Hero\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;


        // TODO: Implement menu actions

        if(choice==1)
        {
            int id, level, power, health, level_up;

            string name;

            cout<<"Enter ID, Name, Level, Power, Health, LevelUpAmount:\n";

            cin>>id>>name>>level>>power>>health>>level_up;

            Hero h(id, name, level, power, health, level_up);

            b1.AddHero(h);

        } 

        else if(choice==2) 
        {
            int id;
            cout << "Enter Hero ID for remove: ";
            cin >> id;
            b1.removeHero(id);
        } 
        else if(choice==3) 
        {
            b1.Display();
        } 
        else if(choice==4) 
        {
            int damage;
            cout << "Enter damage amount: ";
            cin >>damage ;
            b1.Stimulate(damage);
        } 
        else if(choice==5) 
        {
            b1.strong();
        } 
        else if(choice==6) 
        {
            b1.avg();
        } 
        else if(choice==7) 
        {
            int id;
            cout << "Enter Hero ID for level up: ";
            cin >> id;
            b1.levelUP(id);
        }

    } 
    while (choice != 0);

    return 0;
}


#include <iostream>
#include <string>
#include "consoleui.h"
#include "person.h"
#include "dataaccess.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}
void ConsoleUI::run()
{
    int choice;
    char ch;

    //adds team logo
   cout <<  "made by:\n"
    <<"--------------------------------------------------\n"
    <<"|  _____ _____    _    __  __   _____    ____    |\n"
    <<"| |_   _|____ |  / \\  |  \\/  | |  ___|	||\"\"||	 |\n"
    <<"|   | |   |_  | / _ \\ | |\\/| |  \\ \\     ||__||   |\n"
    <<"|   | |  ___| |/ ___ \\| |  | |   \\ \\    [ -=.]`) |\n"
    <<"|   |_| |_____/_/   \\_|_|  |_|    \\_\\   ====== 0 |\n"
    <<"|________________________________________________|\n";

    do
    {
    cout << endl;
    cout << "Please choose from the following commands: \n";
    cout << "\t1. Add person.  \n";
    cout << "\t2. Read Data. \n";
    cout << "\t3. Sort Data. \n";
    cout << "\t4. Quit. \n";
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
         write();
            break;
        case 2:
         //read();
            break;
        case 3:
            break;
        default:
            cout<<"\tInvalid entry!"<<endl;
    }
    cout<<"\nTry again (y/n): ";
    cin>>ch;

    }
    while(ch == 'y' || ch == 'Y');
}
void ConsoleUI::write()
{
    string name;
    char gender;
    int birthYear;
    int deathYear;

    cout << "Name: ";
         cin >> name;
    cout << "If male enter m. If female enter f:  ";
        while(!(cin>>gender) | !((gender == 'm')|(gender == 'M') | (gender == 'f') | (gender == 'F')))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter only m/M or f/F: ";
        }
    cout << "Birth year: ";
        while(!(cin>>birthYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter only numbers: ";
         }
    cout << "Enter death year in numbers: ";
        while(!(cin>>deathYear) )
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter only numbers:  ";
        }
    while(deathYear<birthYear)
    {
       cout << "You cannot die before you are born.\n"
                << "Enter death year again: ";
       cin >> deathYear;
    }
    DataAccess DA;
    DA.writeToFile(name, gender, birthYear, deathYear);
}

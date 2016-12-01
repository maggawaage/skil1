#include <iostream>
#include <fstream>
#include <iomanip>
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
    cout << "\t2. Print list(sort). \n";
    cout << "\t3. Search list. \n";
    cout << "\t4. Delete from list. \n";
    cout << "\t5. Quit. \n";
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
         write();
            break;
        case 2:
            sortIt();
            break;
        case 3:
            //
            break;
        case 4:
            //
            break;
        case 5:
            //
            break;
        default:
            cout<<"\tInvalid entry!"<<endl;
    }
    cout<<"\nContinue? (y/n): ";
    cin>>ch;

    } while(ch == 'y' || ch == 'Y');

}

void ConsoleUI::displayVector(vector<Person> printIt)
{
    Person printperson;
    for(size_t i = 0; i < printIt.size(); i++)
    {
        //cout << setw(3);
        cout << "Gender" << '\t' << "Name"  << '\t' << "Birth Year" << '\t' << "Year of death" << endl;
        cout << i << printIt[i].getName() << '\t' << printIt[i].getGender() << '\t' << printIt[i].getBirthYear() << '\t' << printIt[i].getDeathYear() << endl;

    }
}

void ConsoleUI::sortIt()
{
    DataAccess fill;
    vector<Person> persons;
    persons = fill.fillVector(persons);
    for(size_t i = 0; i < persons.size(); i++)
    {
        cout << persons[i].getName();
    }
    int choice = 0;
    cout << "How would you like to sort?" << endl;
    cout << "\t1. By name.  \n";
    cout << "\t2. By birthyear. \n";
    cout << "\t3. By gender. \n";
    cout << "\t4. By year of death. \n";
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    if(choice == 1)
    {
        int choice1 = 0;
        cout << "\t1. From A-Z.  \n";
        cout << "\t2. From Z-A. \n";
        cout << "Your choice: ";
        cin >> choice1;
        if(choice1 == 1)
               _service.alpha(persons);
        else
               _service.reAlpha(persons);
    }
    else if(choice == 2)
    {
        int choice2 = 0;
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        cout << "Your choice: ";
        cin >> choice2;
        if(choice2 == 1)
               _service.year(persons);
        else
               _service.reYear(persons);
    }
    else if(choice == 3)
    {
        int choice3 = 0;
        cout << "\t1. From male to female.  \n";
        cout << "\t2. From female to male. \n";
        cout << "Your choice: ";
        cin >> choice3;
        if(choice3 == 1)
               _service.gender(persons);
        else
               _service.reGender(persons);
    }
    else if(choice == 4)
    {
        int choice4 = 0;
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        cout << "Your choice: ";
        cin >> choice4;
        if(choice4 == 1)
               _service.death(persons);
        else
               _service.reDeath(persons);
    }
    else
    {
        _service.alpha(persons);
    }

    displayVector(persons);
}

void ConsoleUI::write()
{
    string name;
    char gender;
    int birthYear;
    int deathYear;
    ofstream famousPersons ("person.txt", ios_base::app);
    if (famousPersons.is_open())
    {
        cout << "Name(English characters only): ";
        cin.ignore(10000,'\n');
        getline(cin, name);
        cout << "If male enter m. If female enter f:  ";
            while(!(cin>>gender) | !((gender == 'm')|(gender == 'M') | (gender == 'f') | (gender == 'F')))
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Enter only m/M for male or f/F for femaler: ";
            }
        cout << "Birth year: ";
            while(!(cin>>birthYear))
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Enter birth year only in numbers: ";
             }
        cout << "Enter death year (If person is not dead enter 0): ";
            while(!(cin>>deathYear) )
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Enter death year only in numbers:  ";
            }
        while(!(!(deathYear<birthYear)|(deathYear==0)))
        {
           cout << "You cannot die before you are born.\n"
                    << "Enter death year again: ";
           cin >> deathYear;
        }
        DataAccess DA;
        DA.writeToFile(name, gender, birthYear, deathYear);
    }
    else
    {
        cout << "Missing .txt file";
    }
}

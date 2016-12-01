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
        cout << i << " < i  " << printIt[i].getName() << endl;
        cout << i << " < i  " << printIt[i].getGender() << endl;
        cout << i << " < i  " << printIt[i].getbirthYear() << endl;
        cout << i << " < i  " << printIt[i].getdeathYear() << endl;
    }
}

void ConsoleUI::sortIt()
{
    DataAccess fylla;
    vector<Person> komasvo;
    komasvo = fylla.fillVector(komasvo);
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
               _service.alpha(komasvo);
        else
               _service.reAlpha(komasvo);
    }
    else if(choice == 2)
    {
        int choice2 = 0;
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        cout << "Your choice: ";
        cin >> choice2;
        if(choice2 == 1)
               _service.year(komasvo);
        else
               _service.reYear(komasvo);
    }
    else if(choice == 3)
    {
        int choice3 = 0;
        cout << "\t1. From male to female.  \n";
        cout << "\t2. From female to male. \n";
        cout << "Your choice: ";
        cin >> choice3;
        if(choice3 == 1)
               _service.gender(komasvo);
        else
               _service.reGender(komasvo);
    }
    else if(choice == 4)
    {
        int choice4 = 0;
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        cout << "Your choice: ";
        cin >> choice4;
        if(choice4 == 1)
               _service.death(komasvo);
        else
               _service.reDeath(komasvo);
    }
    else
    {
        _service.alpha(komasvo);
    }

    displayVector(komasvo);
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


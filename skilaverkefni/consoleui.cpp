#include <iostream>
#include <string>
#include "consoleui.h"
#include "person.h"
#include "dataaccess.h"
<<<<<<< HEAD

=======
>>>>>>> e57ccdbf4d59901be3feba07c5f9bc1fabf438a1

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
        cout << "\t3. Print Data. \n";
        cout << "\t4. Search Data. \n";
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
                //read();
                break;
            case 3:
<<<<<<< HEAD
                //sortIt();
                break;
            case 4:
                //
=======
>>>>>>> e57ccdbf4d59901be3feba07c5f9bc1fabf438a1
                break;
            default:
                cout<<"\tInvalid entry!"<<endl;
        }

        cout<<"\nTry again (y/n): ";
        cin>>ch;

    } while(ch == 'y' || ch == 'Y');

}
<<<<<<< HEAD
/*
void ConsoleUI::sortIt()
{
    //vector<Person> komasvo;
    //komasvo = writeToVector(komasvo);
    int choice;
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
        int choice1;
        cout << "\t1. From A-Z.  \n";
        cout << "\t2. From Z-A. \n";
        if(choice1 == 1)
               //_service.alpha();
        //else
              // _service.reAlpha();
    }
    else if(choice == 2)
    {
        int choice2;
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        if(choice2 == 1)
               //_service.year();
        //else
               //_service.reYear();
    }
    else if(choice == 3)
    {
        int choice3;
        cout << "\t1. From male to female.  \n";
        cout << "\t2. From female to male. \n";
        if(choice3 == 1)
              // _service.gender();
        //else
              // _service.reGender();
    }
    else if(choice == 4)
    {
        int choice3;
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        if(choice3 == 1)
               //_service.death();
        //else
              // _service.reDeath();
    }

    else
    {
        //_service.alpha();
    }

} */
=======
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
>>>>>>> e57ccdbf4d59901be3feba07c5f9bc1fabf438a1

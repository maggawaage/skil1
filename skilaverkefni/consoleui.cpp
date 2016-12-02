#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

    teamLogo();

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
            search();
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

    }
    while(ch == 'y' || ch == 'Y');

}

void ConsoleUI::write()
{
    string name;
    char gender;
    int birthYear;
    int deathYear;
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

void ConsoleUI::displayVector(vector<Person> printIt)
{
    cout << "\nGender"<< '\t' << "Name" << "\t\t\t" << "Birth year";
    cout.width(15);
    cout <<"Year of death";
    cout.width(15);
    cout <<"Age when died" << endl;;
    cout <<"========================================================================\n";
    for(size_t i = 0; i < printIt.size(); i++)
    {
        cout.setf(ios::left);

        if(printIt[i].getGender()=='m')
        {
            cout.width(8);
            cout << "Male";
        }
        else
        {
            cout.width(8);
            cout << "Female";
        }


        cout.width(24);
        cout << printIt[i].getName();
        cout.width(12);
        cout << printIt[i].getBirthYear();
        if (!(printIt[i].getDeathYear() == 0))
        {
            cout.width(15);
            cout << printIt[i].getDeathYear()
                     << (printIt[i].getDeathYear() - printIt[i].getBirthYear()) << endl;;
        }
        else
        {
            cout.width(15);
            cout << '-'
                     << "-\n";
        }
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


void ConsoleUI::search()
{
    DataAccess fylla;
    PersonService Pa;
    vector<Person> SearchPersons;
    SearchPersons= fylla.fillVector(SearchPersons);

    char keepSearching = 'y';

    while (keepSearching == 'y')
    {

        char more_conditions = 'y';

        bool kalli[] = {0,0,0,0}; // Verður 1 þegar búið er að velja skilyrði
        string palli[4]; // Geymir valmöguleikana á því hvað hægt er að leita eftir
        palli[0] = "\t 1. Name \n";
        palli[1] = "\t 2. Gender \n";
        palli[2] = "\t 3. Year of birth \n";
        palli[3] = "\t 4. Year of death  \n";



        while (more_conditions == 'y' & (!(kalli[0] & kalli[1] & kalli[2] & kalli[3]))) // Loopar þangað til notandi vill
        {
            int conditionNum;

            for (int i = 0; i < 4; i++)
            {
                if (!kalli[i])
                {
                    cout << palli[i];
                }
            }
            cout << "What do you want to search for? ";
            cin >> conditionNum;

            kalli[conditionNum-1] = 1;

            if (conditionNum == 1)
            {
                string nameForSearch;
                cout << "What name do you want to search for? ";
                cin >> nameForSearch;
                Pa.SearchName(SearchPersons, nameForSearch);
            }

            else if (conditionNum == 2)
            {
                char genderForSearch;
                cout << "Which gender do you want to search for (m/f)? ";
                cin >> genderForSearch;
                Pa.SearchGender(SearchPersons, genderForSearch);
            }

            else if (conditionNum == 3)
            {
                int birthYearForSearch;
                cout << "What birth year do you want to search for? ";
                cin >> birthYearForSearch;
                Pa.SearchBirthYear(SearchPersons, birthYearForSearch);
            }

            else if (conditionNum == 4)
            {
                int deathYearForSearch;
                cout << "What death year do you want to search for? ";
                cin >> deathYearForSearch;
                Pa.SearchDeathYear(SearchPersons, deathYearForSearch);
            }


            cout << "Do you want to add another condition (y/n)? ";
            cin >> more_conditions;


        }

        displayVector(SearchPersons);
        cout << "Do you want to search again(y/n)? ";
        cin >> keepSearching;

    }
}

void ConsoleUI::teamLogo()
{
    cout <<  "made by:\n"
         <<"--------------------------------------------------\n"
         <<"|  _____ _____    _    __  __   _____    ____    |\n"
         <<"| |_   _|____ |  / \\  |  \\/  | |  ___|	||\"\"||	 |\n"
         <<"|   | |   |_  | / _ \\ | |\\/| |  \\ \\     ||__||   |\n"
         <<"|   | |  ___| |/ ___ \\| |  | |   \\ \\    [ -=.]`) |\n"
         <<"|   |_| |_____/_/   \\_|_|  |_|    \\_\\   ====== 0 |\n"
         <<"|________________________________________________|\n";
}

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

    teamLogo();

    do
    {
        cout << endl;
        cout << "Please choose from the following commands: \n";
        cout << "\t1. Add person  \n";
        cout << "\t2. Print list(sort) \n";
        cout << "\t3. Search list\n";
        cout << "\t4. Delete from list\n";
        cout << "\t5. Edit list\n";
        cout << "\t6. Quit \n";
        cout << endl;
        cout << "Your choice: ";
        while(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter corresponding number from 1-6: ";
        }

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
            deleteFromFile();
            break;
        case 5:
            edit();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\tInvalid entry!"<<endl;
        }
    }
    while(true);
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
        cout << "Enter birth year only in numbers(YYYY): ";
    }
    cout << "Enter death year (If person is not dead enter 0): ";
    while(!(cin>>deathYear) )
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Enter death year only in numbers(YYYY):  ";
    }
    while(!(!(deathYear<birthYear)|(deathYear==0)))
    {
        cout << "You cannot die before you are born.\n"
             << "Enter death year again: ";
        cin >> deathYear;
    }

    //check if name is already in file
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    Person PER;
    PersonService PS;
    cout << "\nperson: "<< Persons.at(0).getName() << endl;;
    if(PER.checkIfSame(Persons, name))
    {
        PS.serviceToFile(name, gender, birthYear, deathYear);
    }
    else
    {
        cout << "\nError: This name has already been added.\n";
    }
}

void ConsoleUI::sortIt()
{
    vector<Person> Persons;
    Persons = _service.serviceToVector(Persons);
    int choice = 0;
    cout << "How would you like to sort?" << endl;
    cout << "\t1. By name  \n";
    cout << "\t2. By gender \n";
    cout << "\t3. By birthyear \n";
    cout << "\t4. By year of death \n";
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
        cout << "\t1. From A-Z  \n";
        cout << "\t2. From Z-A \n";
        cout << "Your choice: ";
        int choiceAlpha;
        cin >> choiceAlpha;
        switch(choiceAlpha)
        {
        case 2:
            _service.reAlpha(Persons);
            break;
        default:
            _service.alpha(Persons);
        }
        break;
    case 2:
        cout << "\t1. First female  \n";
        cout << "\t2. First male \n";
        cout << "Your choice: ";
        int choiceGender;
        cin >> choiceGender;
        switch(choiceGender)
        {
        case 2:
            _service.alpha(Persons);
            _service.reGender(Persons);
            break;
        default:
            _service.alpha(Persons);
            _service.gender(Persons);
        }
        break;
    case 3:
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        cout << "Your choice: ";
        int choiceBirthYear;
        cin >> choiceBirthYear;
        switch(choiceBirthYear)
        {
        case 2:
            _service.alpha(Persons);
            _service.year(Persons);
            break;
        default:
            _service.alpha(Persons);
            _service.reYear(Persons);
            break;
        }
        break;
    case 4:
        cout << "\t1. From highest to lowest. \n";
        cout << "\t2. From lowest to highest.\n";
        cout << "Your choice: ";
        int choiceDeathYear;
        cin >> choiceDeathYear;
        switch(choiceDeathYear)
        {
        case 2:
            _service.alpha(Persons);
            _service.death(Persons);
            break;
        default:
            _service.alpha(Persons);
            _service.reDeath(Persons);
        }
        break;
    }
    displayVector(Persons);
}

void ConsoleUI::search()
{
    DataAccess Fill;
    PersonService PA;
    vector<Person> SearchPersons;

    char keepSearching = 'y';

    while (keepSearching == 'y')
    {
        SearchPersons= Fill.fillVector(SearchPersons); // SearchPersons

        char moreConditions = 'y';

        bool conditionAvailable[] = {0,0,0,0,0}; // Geymir hvort búið er að setja skilyrði fyrir flokk.
        string searchString[5]; // Geymir leitarmöguleikana sem
        searchString[0] = "\t 1. Name \n";
        searchString[1] = "\t 2. Gender \n";
        searchString[2] = "\t 3. Year of birth \n";
        searchString[3] = "\t 4. Year of death  \n";
        searchString[4] = "\t 5. Still alive\n";

        while (moreConditions == 'y' && (!(conditionAvailable[0] && conditionAvailable[1] && conditionAvailable[2] && conditionAvailable[3]&& conditionAvailable[4])))
        {
            int conditionNum;
            for (int i = 0; i < 4; i++)
            {
                if (!conditionAvailable[i])
                {
                    cout << searchString[i];
                }
            }
            cout << "What do you want to search for? ";
            while(!(cin>>conditionNum))
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Enter corresponding number from 1-5: ";
            }

            if ((conditionNum == 1) & (conditionAvailable[0] == 0))
            {
                string nameForSearch;
                cout << "What name do you want to search for? ";
                cin >> nameForSearch;
                cin.ignore(10000,'\n');
                SearchPersons = PA.SearchName(SearchPersons, nameForSearch);
            }

            else if ((conditionNum == 2) & (conditionAvailable[1] == 0) )
            {
                char genderForSearch;
                cout << "Which gender do you want to search for (m/f)? ";
                while(!(cin>>genderForSearch) | !((genderForSearch == 'm')|(genderForSearch == 'M') | (genderForSearch == 'f') | (genderForSearch == 'F')))
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Enter only m/M for male or f/F for femaler: ";
                }
                SearchPersons = PA.SearchGender(SearchPersons, genderForSearch);
            }

            else if ((conditionNum == 3) & (conditionAvailable[2] == 0))
            {
                int birthYearForSearch;
                cout << "What birth year do you want to search for? ";
                while(!(cin>>birthYearForSearch))
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Enter birth year only in numbers(YYYY): ";
                }
                SearchPersons = PA.SearchBirthYear(SearchPersons, birthYearForSearch);
            }
            else if ((conditionNum == 4) & (conditionAvailable[3] == 0))
            {
                int deathYearForSearch;
                cout << "What death year do you want to search for? ";
                while(!(cin>>deathYearForSearch) )
                {
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Enter death year only in numbers(YYYY):  ";
                }
                SearchPersons = PA.SearchDeathYear(SearchPersons, deathYearForSearch);
            }
            else if ((conditionNum == 5) & (conditionAvailable[3] == 0))
            {
                SearchPersons = PA.SearchDeathYear(SearchPersons, 0);
            }

            conditionAvailable[conditionNum-1] = 1;

            cout << "Do you want to add another condition (y/n)? ";
            while(!(cin>>moreConditions) | (!((moreConditions== 'y')|(moreConditions == 'Y') | (moreConditions == 'n') | (moreConditions == 'N'))))
            {
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "Enter only y/Y for  or n/N: ";
            }
            cout << " \n";
        }

        PA.deleteDublicateVector(SearchPersons);


        if (SearchPersons.size() == 0)
        {
            cout << "No person matches this search \n";
        }
        else
        {
            cout << "Displaying search results: \n";
            displayVector(SearchPersons);
        }


        cout << "\nDo you want to search again(y/n)? ";
        while(!(cin>>keepSearching) | !((keepSearching== 'y')|(keepSearching == 'Y') | (keepSearching == 'n') | (keepSearching == 'N')))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter only y/Y for  or n/N: ";
        }

    }
}

void ConsoleUI::deleteFromFile()
{
    vector<Person> persons;
    persons = _service.serviceToVector(persons);
    string name;
    displayVector(persons);
    cout << "\nWhat person do you want to remove from the list? ";
    cin.ignore(10000,'\n');
    getline(cin, name);
    for(size_t i = 0; i < persons.size(); i++)
    {
        if(persons[i].getName() == name)
        {
            persons.erase(persons.begin()+i);
        }
    }
    _service.serviceToFile(persons);
    displayVector(persons);
}

void ConsoleUI::edit()
{
    string newName;
    int newYear;
    vector<Person> persons;
    persons = _service.serviceToVector(persons);
    string name;
    displayVector(persons);

    char female = 'f';
    char male = 'm';

    cout << "\nEnter the name of the person you want to edit? ";
    cin.ignore(10000,'\n');
    getline(cin, name);
    size_t count;
    for(size_t i = 0; i < persons.size(); i++)
    {
        if(persons[i].getName() == name)
        {
            count = i;
        }
    }
    cout << "What do you want to edit?\n "
         <<"\t 1. Name \n"
        <<"\t 2. Gender \n"
       <<"\t 3. Year of birth \n"
      <<"\t 4. Year of death  \n";

    cout << "Your choice: ";
    int editChoice;
    cin >> editChoice;
    switch(editChoice)
    {
    case 1:
        cout << "Enter new name";
        getline(cin, newName);
        persons.at(count).setName(newName);
        break;
    case 2:
        if((persons.at(count).getGender())==male)
        {
            persons.at(count).setGender(female);
        }
        else
        {
            persons.at(count).setGender(male);
        }
        break;
    case 3:
        cout << "Enter new year: ";
        while(!(cin>>newYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter year only in numbers(YYYY): ";
        }
        persons.at(count).setBirthYear(newYear);
        break;
    case 4:
        cout << "Enter new year: ";
        while(!(cin>>newYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter year only in numbers(YYYY): ";
        }
        persons.at(count).setDeathYear(newYear);
        break;
    default:
    {
        cout<<"\tInvalid entry!"<<endl;
    }

    }
    displayVector(persons);
}

void ConsoleUI::displayVector(vector<Person> printIt)
{
    cout << "\nName"<< "\t\t\t" << "Gender" << "\t" << "Birth year";
    cout.width(15);
    cout <<"Year of death";
    cout.width(15);
    cout <<"Age when died" << endl;;
    cout <<"========================================================================\n";

    for(size_t i = 0; i < printIt.size(); i++)
    {
        cout.setf(ios::left);
        cout.width(24);
        cout << printIt[i].getName();
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

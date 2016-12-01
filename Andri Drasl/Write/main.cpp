#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    string name;
    char gender;
    int birthYear;
    int deathYear;

    cout << "Name:\t";
         cin >> name;
    cout << "\nIf male enter m. If female enter f:  ";
        while(!(cin>>gender) | !((gender == 'm')|(gender == 'M') | (gender == 'f') | (gender == 'F')))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter only m/M or f/F: ";
        }
    cout << "\nBirth year: ";
        while(!(cin>>birthYear))
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Enter only numbers: ";
         }
    cout << "\nDeath year: ";
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


    cout << name << endl;
    if(gender=='m')
        cout << "male";
    else
        cout << "female";
    cout<< endl
            << birthYear << endl
            << deathYear << endl;




}


/*
    ofstream famusPersons ("myfile.txt", ios_base::app); // breyta nafin á skrá , ios_base::app
    if (famusPersons.is_open())
    {
        famusPersons <<name;
        famusPersons << "\n";
        famusPersons <<gender;
        famusPersons << "\n";
        famusPersons <<birthYear;
        famusPersons << "\n";
        famusPersons <<deathYear;
        famusPersons << "\n";
        famusPersons << "*********************\n";
        famusPersons.close();
    }
    else cout << "Unable to open file";
    return 0;
}
*/

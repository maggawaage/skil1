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
    cout << "\nIf male enter m. If female enter f: \t";
         cin >> gender;
    cout << "\nBirth year:\t";
         cin >>birthYear;
    cout << "\nDeath year:\t";
         cin >>deathYear;




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


#include <iostream>
#include <fstream>
#include "dataaccess.h"
//#include "person.h"

DataAccess::DataAccess()
{

}

//read    vector<Person> readToFile(const vector <Person>  famusComputerphiles);

vector<Person> DataAccess::readToFile(vector<Person>  famousComputerphiles)
{
    fstream inputFile;
    inputFile.open("person.txt"); // breyta nafni á skrá
    string name;
    char gender;
    int birthYear;
    int deathYear;
    if (inputFile.is_open())
    {
        while(! inputFile.eof() )
        {
            Person temp;
            inputFile >>  name;
            temp.setName(name);
            inputFile >> gender;
            temp.setGender(gender);
            inputFile >> birthYear;
            temp.setBirthYear(birthYear);
            inputFile >> deathYear;
            temp.setDeathYear(deathYear);
            famousComputerphiles.push_back(temp);
        }
    }

    inputFile.close();
    return famousComputerphiles;
}


//write
void DataAccess::write(string name, char gender, int birthYear, int deathYear)
{
    ofstream famousPersons ("person.txt", ios_base::app); // breyta nafni á skrá, ios_base::app
    if (famousPersons.is_open())
    {
        famousPersons <<name;
        famousPersons << "\n";
        famousPersons <<gender;
        famousPersons << "\n";
        famousPersons <<birthYear;
        famousPersons << "\n";
        famousPersons <<deathYear;
        famousPersons << "\n";
        famousPersons.close();
    }

    else cout << "Unable to open file";

}





















#include <iostream>
#include <fstream>
#include "dataaccess.h"
//#include "person.h"

DataAccess::DataAccess()
{

}

//read    vector<Person> readToFile(const vector <Person>  famusComputerphiles);

vector<Person> DataAccess::readToFile(vector<Person>  famusComputerphiles)
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
        famusComputerphiles.push_back(temp);
    }
}
inputFile.close();
return famusComputerphiles;
}


//write
void DataAccess::write(string name, char gender, int birthYear, int deathYear)
{
    ofstream famusPersons ("person.txt", ios_base::app); // breyta nafin á skrá , ios_base::app
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
        famusPersons.close();
    }
    else cout << "Unable to open file";

}





















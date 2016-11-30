#include "dataaccess.h"
#include "person.h"

DataAccess::DataAccess()
{

}

//read
vector<Person> DataAccess::read(const vector<Person>  famusComputerphiles)
{
fstream inputFile;
inputFile.open("myfile.txt"); // breyta nafni á skrá

if (inputFile.is_open())
{
    while(! inputFile.eof() )
    {
        Person temp;
        inputFile >> temp.name;
        inputFile >> temp.gender;
        inputFile >> temp.birthYear;
        inputFile >> temp.deathYear;
        famusComputerphiles.push_back(temp);
    }
}
inputFile.close();
return famusComputerphiles;
}


//write
DataAccess::write(string name, char gender, int bithYear, int deathYear)
{
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





















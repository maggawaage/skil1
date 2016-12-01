#include <fstream>
#include "dataaccess.h"
//#include "person.h"

DataAccess::DataAccess()
{

}
vector<Person> DataAccess::fillVector(vector<Person>  famousComputerphiles)
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

void DataAccess::writeToFile(string name, char gender, int birthYear, int deathYear)
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
}
void DataAccess::writeVectorToFile(vector<Person>famousComputerphiles)
{
    string name;
    char gender;
    int birthYear;
    int deathYear;
    ofstream famousPersons ("person.txt");
    if (famousPersons.is_open())
    {
        for(size_t i = 0; i < famousComputerphiles.size() ; i++ )
        {
            name = famousComputerphiles.at(i).getName();
            famousPersons << name;
            famousPersons << "\n";
            gender = famousComputerphiles.at(i).getGender();
            famousPersons << gender;
            famousPersons << "\n";
            birthYear = famousComputerphiles.at(i).getBirthYear();
            famousPersons << birthYear;
            famousPersons << "\n";
            deathYear = famousComputerphiles.at(i).getDeathYear();
            famousPersons << deathYear;
            famousPersons << "\n";
        }
        famousPersons.close();
    }
}


















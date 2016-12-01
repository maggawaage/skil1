#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <string>
#include "person.h"

class DataAccess
{
public:
    DataAccess();



    vector<Person> writeToVector(vector<Person>  famusComputerphiles);

    void writeToFile(string name, char gender, int birthYear, int deathYear);

    vector<Person> fillVector(vector<Person>  famousComputerphiles);

};


#endif // DATAACCESS_H


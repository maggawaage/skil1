#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <string>
#include "person.h"

class DataAccess
{
public:
    DataAccess();

    void writeToFile(string name, char gender, int birthYear, int deathYear);

    vector<Person> fillVector(vector<Person>  famusComputerphiles);

private:
    //vector<//private vector
};
/*vector<Person> readToFile(vector<Person>  famusComputerphiles){
    return vector<Person>();
}*/

#endif // DATAACCESS_H


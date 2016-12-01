#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <string>
#include "person.h"

class DataAccess
{
public:
    DataAccess();

<<<<<<< HEAD
    vector<Person> writeToVector(vector<Person>  famusComputerphiles);
=======
    void writeToFile(string name, char gender, int birthYear, int deathYear);

    vector<Person> fillVector(vector<Person>  famusComputerphiles);
>>>>>>> e57ccdbf4d59901be3feba07c5f9bc1fabf438a1

private:
    //vector<//private vector
};
/*vector<Person> readToFile(vector<Person>  famusComputerphiles){
    return vector<Person>();
}*/

#endif // DATAACCESS_H


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
    void writeToFile(string name, char gender, int birthYear, int deathYear);

    vector<Person> fillVector(vector<Person>  famusComputerphiles);

=======

    //vector<Person> writeToVector(vector<Person>  famusComputerphiles);

    void writeToFile(string name, char gender, int birthYear, int deathYear);

    vector<Person> fillVector(vector<Person>  famusComputerphiles);
>>>>>>> 1be60b5b3ee58995f2102395424777d310e27aa1

private:
    //vector<//private vector
};
/*vector<Person> readToFile(vector<Person>  famusComputerphiles){
    return vector<Person>();
}*/

#endif // DATAACCESS_H


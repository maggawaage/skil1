#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <vector>
#include "person.h"
using namespace std;

class PersonService
{
public:
    PersonService();

    //vector<Person> getPerformers(/*Todo parameters*/);
    vector<Person> alpha();

    /*
    vector<Person> realpha()
    vector<Person> year();
    vector<Person> reyear()
    vector<Person> gender();
    vector<Person> regender();
    vector<Person> death();
    vector<Person> redeath(); */

    vector<Person> alpha(vector<Person>& personlist);
    vector<Person> reAlpha(vector<Person>& personlist);
    vector<Person> year(vector<Person>& personlist);
    vector<Person> reYear(vector<Person>& personlist);
    vector<Person> gender(vector<Person>& personlist);
    vector<Person> reGender(vector<Person>& personlist);
    vector<Person> death(vector<Person>& personlist);
    vector<Person> reDeath(vector<Person>& personlist);
};

#endif // PERSONRSERVICE_H

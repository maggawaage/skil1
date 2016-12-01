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

    vector<Person> alpha(vector<Person>& personlist);
    vector<Person> reAlpha(vector<Person>& personlist);
    vector<Person> year(vector<Person>& personlist);
    vector<Person> reYear(vector<Person>& personlist);
    vector<Person> gender(vector<Person>& personlist);
    vector<Person> reGender(vector<Person>& personlist);
    vector<Person> death(vector<Person>& personlist);
    vector<Person> reDeath(vector<Person>& personlist);
    static vector<Person> SearchName(vector<Person> list, string name);
    static vector<Person> SearchGender(vector<Person> list, char gender);
    static vector<Person> SearchBirthYear(vector<Person> list, int birthYear);
    static vector<Person> SearchDeathYear(vector<Person> list, int deathYear);
};

#endif // PERSONRSERVICE_H

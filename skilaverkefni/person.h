#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
public:
    Person();
    Person(string name, int age, char gender, int death);

    string getName() const;
    int getYear() const;
    char getGender() const;
    int getDeath() const;

    static int compareName(Person a, Person b);
    static int compareNameReversed(Person a, Person b);
    static int compareYear(Person a, Person b);
    static int compareYearReversed(Person a, Person b);
    char compareGender(Person a, Person b);
    char compareGenderReversed(Person a, Person b);
    static int compareDeath(Person a, Person b);
    static int compareDeathReversed(Person a, Person b);

private:
    string _name;
    int _year;
    char _gender;
    int _death;
};

#endif // PERSON_H

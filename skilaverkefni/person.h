#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
public:
    Person();
    Person(string name, char gender, int birthYear, int deathYear);

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

    static vector<Person> SearchName(vector <Person> list, string name);
    static vector<Person> SearchGender(vector <Person> list, char gender);
    static vector<Person> SearchBirthYear(vector <Person> list, int birthYear);
    static vector<Person> SearchDeathYear(vector <Person> list, int deathYear);


private:
    string _name;
    int _year;
    char _gender;
    int _death;
};

#endif // PERSON_H

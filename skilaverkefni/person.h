#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
using namespace std;

class Person
{
public:
    Person();
    Person(string name, int birthYear, char gender,  int deathYear);

    string getName() const;
    char getGender() const;
    int getbirthYear() const;
    int getdeathYear() const;
    void setName(string name);
    void setGender(char gender);
    void setBirthYear(int birthYear);
    void setDeathYear(int deathYear);

    static bool compareName(Person a, Person b);
    static int compareNameReversed(Person a, Person b);
    static int compareYear(Person a, Person b);
    static int compareYearReversed(Person a, Person b);
    static char compareGender(Person a, Person b);
    static char compareGenderReversed(Person a, Person b);
    static int compareDeath(Person a, Person b);
    static int compareDeathReversed(Person a, Person b);

    static vector<Person> SearchName(vector<Person> list, string name);
    static vector<Person> SearchGender(vector<Person> list, char gender);
    static vector<Person> SearchBirthYear(vector<Person> list, int birthYear);
    static vector<Person> SearchDeathYear(vector<Person> list, int deathYear);


private:
    string _name;
    int _birthYear;
    char _gender;
    int _deathYear;
};

#endif // PERSON_H

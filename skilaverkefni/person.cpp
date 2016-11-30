#include "person.h"

Person::Person()
{

}
Person::Person(string name, int birthYear, char gender, int deathYear)
{
   _name = name;
   _birthYear = birthYear;
   _gender = gender;
   _deathYear = deathYear;
}
string Person::getName() const
{
    return _name;
}
char Person::getGender() const
{
    return _gender;
}
int Person::getbirthYear() const
{
    return _birthYear;
}
int Person::getdeathYear() const
{
    return _deathYear;
}
void Person::setName(string name)
{
    _name=name;
}
void Person::setGender(char gender)
{
    _gender=gender;
}
void Person::setBirthYear(int birthYear)
{
    _birthYear=birthYear;
}
void Person::setDeathYear(int deathYear)
{
     _deathYear=deathYear;
}
int Person::compareName(Person a, Person b)
{
    return a._name < b._name;
}
int Person::compareNameReversed(Person a, Person b)
{
    return a._name > b._name;
}
int Person::compareYear(Person a, Person b)
{
    return a._birthYear < b._birthYear;
}
int Person::compareYearReversed(Person a, Person b)
{
    return a._birthYear > b._birthYear;
}
char Person::compareGender(Person a, Person b)
{
    return a._gender < b._gender;
}
char Person::compareGenderReversed(Person a, Person b)
{
    return a._gender > b._gender;
}
int Person::compareDeath(Person a, Person b)
{
    return a._deathYear < b._deathYear;
}
int Person::compareDeathReversed(Person a, Person b)
{
    return a._deathYear > b._deathYear;
}

vector<Person> Person::SearchName(vector <Person> list, string searchName)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].name.find(searchName) != std::string::npos)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}

vector<Person> Person::SearchGender(vector <Person> list, char searchGender)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].gender == searchGender)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}

vector<Person> Person::SearchBirth(vector <Person> list, int searchBirth)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].birth == searchBirth)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}

vector<Person> Person::SearchDeath(vector <Person> list, int searchDeath)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].death == searchDeath)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}

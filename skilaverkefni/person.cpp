#include "person.h"

Person::Person()
{

}
Person::Person(string name, int year, char gender, int death)
{
   _name = name;
   _year = year;
   _gender = gender;
   _death = death;
}
string Person::getName() const
{
    return _name;
}
int Person::getYear() const
{
    return _year;
}
char Person::getGender() const
{
    return _gender;
}
int Person::getDeath() const
{
    return _death;
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
    return a._year < b._year;
}
int Person::compareYearReversed(Person a, Person b)
{
    return a._year > b._year;
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
    return a._death < b._death;
}
int Person::compareDeathReversed(Person a, Person b)
{
    return a._death > b._death;
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

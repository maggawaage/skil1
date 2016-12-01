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
int Person::getBirthYear() const
{
    return _birthYear;
}
int Person::getDeathYear() const
{
    return _deathYear;
}
void Person::setName(string name)
{
    _name = name;
}
void Person::setGender(char gender)
{
    _gender = gender;
}
void Person::setBirthYear(int birthYear)
{
    _birthYear = birthYear;
}
void Person::setDeathYear(int deathYear)
{
     _deathYear = deathYear;
}
bool Person::compareName(Person a, Person b)
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



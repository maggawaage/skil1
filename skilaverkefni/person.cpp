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

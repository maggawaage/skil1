#include "personservice.h"

PersonService::PersonService()
{

}
/*
vector<Performer> getPerformers()
{
    //vector<Performer> perfomers;

    Performer p("Duran Duran", 56);
    Performer p2("Madonna", 55);

    perfomers.push_back(p);
    perfomers.push_back(p2);
     //odruvisi hja okkur
    //TODO fullt stuff
    return performers;
}
*/

vector<Person> PersonService::alpha()
{
    sort(sortedPersons.begin(), sortedPersons.end(), Person::compareName);
    return sortedPersons;
}
vector<Person> PersonService::realpha()
{
    sort(sortedPersons.begin(), sortedPersons.end(), Person::compareNameReversed);
    return sortedPersons;
}
vector<Person> PersonService::year()
{
    sort(sortedPersons.begin(), soretdPersons.end(), Person::compareYear);
    return sortedPersons;
}
vector<Person> PersonService::reyear()
{
    sort(sortedPersons.begin(), sortedPersons.end(), Person::compareYearReversed);
    return sortedPersons;
}
vector<Person> PersonService::gender()
{
    sort(sortedPersons.begin(), sortedPersons.end(), Person::compareGenderReversed);
    return sortedPersons;
}
vector<Person> PersonService::regender()
{
    sort(sortedPersons.begin(), sortedPersons.end(), Person::compareGenderReversed);
    return sortedPersons;
}

vector<Person> PersonService::death()
{
    sort(sortedPersons.begin(), sortedPersons.end(), Person::compareDeathReversed);
    return sortedPersons;
}
vector<Person> PersonService::redeath()
{
    sort(sortedPersons.begin(), sortedPersons.end(), Person::compareDeathReversed);
    return sortedPersons;
}

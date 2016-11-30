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

vector<Person> PersonService::alpha(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareName);
    return personlist;
}
vector<Person> PersonService::reAlpha(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareNameReversed);
    return personlist;
}
vector<Person> PersonService::year(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareYear);
    return personlist;
}

vector<Person> PersonService::reYear(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareYearReversed);
    return personlist;
}
vector<Person> PersonService::gender(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareGender);
    return personlist;
}

vector<Person> PersonService::reGender(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareGenderReversed);
    return personlist;
}

vector<Person> PersonService::death(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareDeath);
    return personlist;
}

vector<Person> PersonService::reDeath(vector<Person>& personlist)
{
    sort(personlist.begin(), personlist.end(), Person::compareDeathReversed);
    return personlist;
}

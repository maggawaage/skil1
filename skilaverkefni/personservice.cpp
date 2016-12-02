#include "personservice.h"
#include <algorithm>

PersonService::PersonService()
{

}

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

vector<Person> PersonService::SearchName(vector <Person> list, string searchName)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].getName().find(searchName) != string::npos)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Person> PersonService::SearchGender(vector <Person> list, char searchGender)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].getGender() == searchGender)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Person> PersonService::SearchBirthYear(vector<Person> list, int searchBirth)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].getBirthYear() == searchBirth)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}
vector<Person> PersonService::SearchDeathYear(vector<Person> list, int searchDeath)
{
    vector <Person> newList;

    for (int i = 0; i < list.size(); i++)
    {

        if (list[i].getDeathYear() == searchDeath)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}


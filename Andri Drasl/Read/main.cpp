#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    char gender;
    int birthYear;
    int deathYear;
};

int main()
{
    vector<Person>  famusComputerphiles;

    fstream inputFile;
    inputFile.open("myfile.txt"); // breyta nafni á skrá

    if (inputFile.is_open())
    {
        while(! inputFile.eof() )
        {
            Person temp;
            inputFile >> temp.name;
            inputFile >> temp.gender;
            inputFile >> temp.birthYear;
            inputFile >> temp.deathYear;
            famusComputerphiles.push_back(temp);
        }
    }
    inputFile.close();

    cout << famusComputerphiles.at(0).name << endl;
    cout << famusComputerphiles.at(0).gender<< endl;
    cout << famusComputerphiles.at(0).birthYear<< endl;
    cout << famusComputerphiles.at(0).deathYear<< endl;

    return 0;
}

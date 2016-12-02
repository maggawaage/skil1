#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "personservice.h"
#include "dataaccess.h"
#include "person.h"

class ConsoleUI
{
public:
    ConsoleUI();

    void run();
    void write();
    void sortIt();
    void search();
    void deleteFromFile();
    void edit();
    void displayVector(vector<Person> printIt);
    void teamLogo();
private:
    PersonService _service;
};

#endif // CONSOLEUI_H

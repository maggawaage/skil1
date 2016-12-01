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
    void displayVector(vector<Person> printIt);
    void sortIt();
    void write();

private:
    PersonService _service;
};

#endif // CONSOLEUI_H

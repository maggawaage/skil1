#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "personservice.h"

class ConsoleUI
{
public:
    ConsoleUI();

    void run();

    void write();

private:
    PersonService _service;
};

#endif // CONSOLEUI_H

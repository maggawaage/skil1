#include <iostream>
#include <string>
#include "consoleui.h"
#include "person.h"
#include "dataaccess.h"


using namespace std;

ConsoleUI::ConsoleUI()
{

}
void ConsoleUI::run()
{
    //fall sem les úr vektor og skrifar út
    /*
    //string commmand;
    //cin >> command;
    while(true){

    cout << "Please enter one of the following commands: " << endl;
    cout << "list - This will list all performers in the system" << endl;
    cout << "add - This will add a new performer" << endl;
    cout << "sort - This will sort the list" << endl;
    //if(command == "list")
    {
       vector<Performer> performers = _service.getPerformers();
       for(size_t i = 0; i < performers.size(); ++i)
       {
           cout << performers[i].getName(); //floknara hja okkur
       }
    }
    //else if(command == "add")
    {
        //TODO
    }
    */
   // }
    int choice;
    char ch;

    do
    {
    cout << endl;
    cout << "Please choose from the following commands: \n";
    cout << "\t1. Add person.  \n";
    cout << "\t2. Read Data. \n";
    cout << "\t3. Print Data. \n";
    cout << "\t4. Search Data. \n";
    cout << "\t5. Quit. \n";
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        // write();
            break;
        case 2:
            //read();
            break;
        case 3:
            //sortIt();
            break;
        case 4:
            //
            break;
        default:
            cout<<"\tInvalid entry!"<<endl;
    }
    cout<<"\nTry again (y/n): ";
    cin>>ch;

    }
    while(ch == 'y' || ch == 'Y');
}
/*
void ConsoleUI::sortIt()
{
    //vector<Person> komasvo;
    //komasvo = writeToVector(komasvo);
    int choice;
    cout << "How would you like to sort?" << endl;
    cout << "\t1. By name.  \n";
    cout << "\t2. By birthyear. \n";
    cout << "\t3. By gender. \n";
    cout << "\t4. By year of death. \n";
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    if(choice == 1)
    {
        int choice1;
        cout << "\t1. From A-Z.  \n";
        cout << "\t2. From Z-A. \n";
        if(choice1 == 1)
               //_service.alpha();
        //else
              // _service.reAlpha();
    }
    else if(choice == 2)
    {
        int choice2;
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        if(choice2 == 1)
               //_service.year();
        //else
               //_service.reYear();
    }
    else if(choice == 3)
    {
        int choice3;
        cout << "\t1. From male to female.  \n";
        cout << "\t2. From female to male. \n";
        if(choice3 == 1)
              // _service.gender();
        //else
              // _service.reGender();
    }
    else if(choice == 4)
    {
        int choice3;
        cout << "\t1. From highest to lowest.  \n";
        cout << "\t2. From lowest to highest. \n";
        if(choice3 == 1)
               //_service.death();
        //else
              // _service.reDeath();
    }

    else
    {
        //_service.alpha();
    }

} */

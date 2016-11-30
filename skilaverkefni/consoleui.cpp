#include <iostream>
#include <string>
#include "consoleui.h"
#include "person.h"

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
    cout << "\t3. Sort Data. \n";
    cout << "\t4. Quit. \n";
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

            break;
        default:
            cout<<"\tInvalid entry!"<<endl;
    }
    cout<<"\nTry again (y/n): ";
    cin>>ch;

    }
    while(ch == 'y' || ch == 'Y');
}

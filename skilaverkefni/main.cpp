#include <iostream>
#include <fstream>
#include <iomanip>
#include "consoleui.h"

using namespace std ;

int main()
{
    ConsoleUI ui;

    ui.run();
    //Þetta á að vera það eina í main

    int choice;
    char ch;

    do{
    cout<<endl;
    cout<<"Please choose from the following: \n";
    cout<<"\t1. Write Data.  \n";
    cout<<"\t2. Read Data. \n";
    cout<<"\t3. Quit. \n";
    cout<<endl;
    cout<<"Your choice: ";
    cin>>choice;

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

}while(ch == 'y' || ch == 'Y');

return 0;
}

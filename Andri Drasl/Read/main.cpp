#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<double> Main;
    int count;
    string lineData;
    double tmp;

    ifstream myfile ("myfile.txt", ios::in);

    double number;

    myfile >> count;
    for(int i = 0; i < count; i++) {
        myfile >> tmp;
        Main.push_back(tmp);
        cout << count;
    }

    cout << "Numbers:\n";
    cout << Main.size();
    for (int i=0; i=((Main.size())-1); i++) {
        cout << Main[i] << '\n';
    }

    cin.get();
    return 0;
}

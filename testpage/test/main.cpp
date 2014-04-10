#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    string str ("Please split this =sentence =into tokens");

    stoi(str,10);
    cout << str << endl;
    return 0;
}


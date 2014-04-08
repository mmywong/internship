#include <iostream>

using namespace std;

template<class T>
void get(T propertyname) // prints out current value
{
    cout << propertyname;
}

template<class T>
void set(T propertyname, T newvalue)
{
    propertyname = newvalue;
}

template<class T>
void printall(T propertyname)
{
    while(propertyname)
        cout << propertyname;
}

int main()
{
    istream input;

    cout << "#--------Command Menu--------#" << endl;
    cout << "SET : Change value" << endl;
    cout << "GET : Output value" << endl;

    string command;
    char assign; // equals sign
    T propertyname,newvalue; // two variables of same typename

    input >> command >> propertyname >> assign >> newvalue;

    switch(command)
    {
        case 'SET':
            set(propertyname, newvalue);
            break;
        case 'GET':
            get(propertyname);
            break;
        case 'GET *':
            printall(propertyname);
            break;
        default:
            cout << "command does not exist" << endl;
            break;
    }

    return 0;
}




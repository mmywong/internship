#include <iostream>

using namespace std;

void Process(istream input); // fx that reads input and decides which function to call

template<class T>
void get(T propertyname) // prints out current value
{
    cout << propertyname;
}

template<class T>
void set(T propertyname, T newvalue)
{

}

int main()
{
    string input;

    cout << "#--------Command Menu--------#" << endl;
    cout << "SET : Change value" << endl;
    cout << "GET : Output value" << endl;

    cin >> input;

    Process(input);

    return 0;
}

template<class T>
void Process(istream input)
{
    string command;
    char assign; // equals sign
    T propertyname,newvalue; // two variables of same typename

    in >> command >> propertyname >> assign >> newvalue;

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
}

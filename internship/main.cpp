#include <iostream>
#include "propertytype.h"

using namespace std;

void Process(string input);

template<class T>
struct propertytype
{
public:
    string propertyname;
    T object;
};

int main()
{
    string input;

    cout << "#--------Command Menu--------#" << endl;
    cout << "SET : Change value" << endl;
    cout << "GET : Output value" << endl;
    cout << "GET* : Output list of values" << endl;
    cout << ">>";
    cin >> input;
    Process(input);


    return 0;
}

void Process(string input)
{
    char* command, propertyname, newvalue, type;
    char** A = new char *[3];

    for (int i=0; i < 3; i++)
        A[i] = new char [50];

    int i = 0;

    //chops the string into parts
    while(A[i])
    {
        A[i] = strtok(input," =");
        i++;
    }
    command = A[0]; //collects to read GET/SET/GET*
    propertyname = A[1]; //collects to read propertyname

    switch(toupper(command))
    {
        case 'ADD':
            type = A[2];
            break;
        case 'SET':
            newvalue = A[2];
            set(propertyname, newvalue);
            break;
        case 'GET':
            get(propertyname);
            break;
        case 'GET*':
            printall(propertyname);
            break;
        default:
            cout << "command does not exist" << endl;
            break;
    }
}





/*
 template<class T>
 void set(T propertyname, T newvalue)
 {
     propertyname = newvalue;
 }

 template<class T>
 void get(T propertyname) // prints out current value
 {
     cout << propertyname;
 }


 template<class T>
 void getall(T propertyname) // prints out list of all members
 {
     //how will we take into account of any object? for c-string, we use '\0' as marker. for array, also use '\0'
     while(propertyname) // while it's not null or null character
     {
         cout << propertyname;
         propertyname++; // as long as ++ operator is defined, it will move to print out the next item in the list?
     }
 }


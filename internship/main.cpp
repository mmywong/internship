#include <iostream>

using namespace std;

void Process(string input);

template<class T> // to accomodate for any type of object
struct propertytype
{
    string name;
    T object;
};

struct Data {
    string variable;
    string value;
};

Data& Search(const string &token, Data* database)
{
    //this look for the correct data to return
    while(database) {
        if(token == *database)
            return database;
        database++;
    }
    return NULL;
}

bool isNUMBER(const string &token) {
    int loop = 0;
    while(token[])
}

int main()
{
    string input;
    cin.get()
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

template<class T>
void set(char* propertyname, char* newvalue)
{
     object1, object2;
    object1. = propertyname;

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



#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void Process(string input); // processes the input, chops it into parts to
int FindBanned(char *banned, char *wholeline); //finds position of banned characters in wholeline
int StrLen(char *iPtr); //finds length of pointer array

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
    char* in = new char[50];
    strcpy(in, input.c_str()); // converts the string into char*

    char command, propertyname, newvalue;
    char* A = new char [3];

    int i = 0;

    //chops the string into parts
    while(A[i])
    {
        A[i] = strtok(in, " =");
        i++;
    }
    command = A[0]; //collects to read GET/SET/GET*
    propertyname = A[1]; //collects to read propertyname

    switch(toupper(command))
    {
        case 'SET':
            newvalue = A[2];
            cout << "set();" << endl;
//            set(propertyname, newvalue);
            break;
        case 'GET':
            cout << "get();" << endl;
//            get(propertyname);
            break;
        case 'GET*':
//            printall(propertyname);
            break;
        default:
            cout << "command does not exist" << endl;
            break;
    }
}

int FindBanned(char *banned, char *wholeline) // finds banned characters in wholeline
{
    char *walker;
    walker = wholeline;
    for(int i=0; i<StrLen(banned); i++)
    {
        for(int j=0; j<StrLen(wholeline); j++)
        {
            if(*walker == *banned)
                return j; // returns position of the banned character
            walker++;
        }
        banned++;
    }
    return -1; // these "banned" characters are not found
}

int StrLen(char *iPtr)
{
    int index = 0;
    while (*(iPtr+index) != '\0')
         index++;
    return index;
}

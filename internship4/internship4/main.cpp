#include <iostream>
#include <cstring>
#include <string>

#include "iterator.h"
#include "list.h"
#include "node.h"
#include "stringfx.h"

using namespace std;

int whattype(char* newvalue);
void set(char* propertyname, char* newvalue);
void Process(string input);

int main()
{
    string input = "GET property = value";
    Process(input);
    int type;
    char* testptr = "/";
    cout << "what is testptr? it is a : ";
    type = whattype(testptr);
    cout << type;
    cout << endl << endl;

    return 0;
}

void Process(string input)
{
    //convert input from string to char*
    char * in = new char [input.length()+1];
    strcpy (in, input.c_str());

    //breaks string into tokens
    char* p = strtok (in," ");

    //insert the tokens into an array
    int i = 0;
    char* A[3];
    while (p!=0)
    {
      A[i] = p;
      cout << A[i] << endl;
      p = strtok(NULL," =");
      i++;
    }
    //each element in the array is now a string pointed by a char*
//    char* command;
//    char* propertyname;
//    char* newvalue;

//    command = A[0]; //collects to read GET/SET/GET*
//    propertyname = A[1]; //collects to read propertyname

    //find out which command was typed in and call the appropriate function
    //***BUG***// : cannot compare string
//    cout << "find string status: " << FindStr("SET", command, 0)<< endl;
//    cout << "command : " << *command << endl;
    cout << "A[0] : " << A[0] << endl;
    if((FindStr("SET", A[0], 0) != -1) || (FindStr("set", A[0],0) != -1)) // "SET" is found in command
    {
        cout << "set(propertyname, newvalue);" << endl;
//        newvalue = A[2];
    }
    else if((FindStr("GET*", A[0], 0) != -1) || (FindStr("get*", A[0], 0)!= -1))
        cout << "getall();" << endl;
    else if((FindStr("GET", A[0], 0) != -1) || (FindStr("get", A[0], 0) != -1))
        cout << "get();" << endl;
    else
        cout << "command does not exist" << endl;

    delete[] in;


}






/*
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
*/

int whattype(char* newvalue)
{
    //===legend===//
    //1 : int
    //2 : char / string
    //3 : double
    //4 : other

    //check if double
    char* temp;
    temp = newvalue;
    while(*temp != '\0')
    {
        if(Find('.', temp, 0) != -1) //*walker == "." is found
           return 3;
        else
            temp++;
    }
    if(((*newvalue >= 65) && (*newvalue <91)) || ((*newvalue >= 97)&& (*newvalue < 123))) //ASCII
        return 2;
    else if((*newvalue >= 48) && (*newvalue < 58))
        return 1;

    return 4;
}

#include <iostream>
#include <cstring>
#include <string>

#include "iterator.h"
#include "list.h"
#include "node.h"
#include "stringfx.h"
#include "data.h"

using namespace std;

int whattype(char* newvalue); //detect int/char/string
void Process(list<data> database, string input); //take apart input into tokens
void set(list<data> database, char* propertyname, char* newvalue);

int main()
{
    data newdata;
    newdata.propertyname = "ramen";
    newdata.type = 1;
    newdata.value = "10";

    list<data> database;
    string input;
    cout << ": ";
    cin >> input;
    cout << endl << endl;

    Process(database, input);

    cout << "database : " << endl;
    database.Print();
    cout << endl << endl;

    return 0;
}

void Process(list<data> database, string input)
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

    cout << "A[0] : " << A[0] << endl;
    if((FindStr("SET", A[0], 0) != -1) || (FindStr("set", A[0],0) != -1)) // "SET" is found in command
    {
        cout << "set(database, name, newvalue);" << endl;
        set(database, A[1], A[2]);
    }
    else if((FindStr("GET*", A[0], 0) != -1) || (FindStr("get*", A[0], 0)!= -1))
        cout << "getall();" << endl;
    else if((FindStr("GET", A[0], 0) != -1) || (FindStr("get", A[0], 0) != -1))
        cout << "get();" << endl;
    else
        cout << "command does not exist" << endl;
    delete[] in;
}


void set(list<data> database, char* propertyname, char* newvalue)
{
    data newdata;
    newdata.propertyname = propertyname;
    newdata.type = whattype(newvalue);
    newdata.value = newvalue;

    //case 1: empty list
    if(database.isEmpty() == true)
        database.InsertHead(newdata);
    //case 2: name exists. search for it and set its value
    else if(database.Search(newdata) != -1) // found
    {
        Iterator<data> positionfound = database.Ithnode(database.Search(newdata));
        database.InsertBefore(positionfound,newdata);
        database.Delete(positionfound);
    }
    //case 3: name does not exist. add this new item
    else
        database.Append(newdata);
}

int whattype(char* newvalue)
{
    //===legend===//
    //1 : int
    //2 : char / string
    //3 : double
    //4 : other

    //check if double :
    char* temp;
    temp = newvalue;
    while(*temp != '\0')
    {
        if(Find('.', temp, 0) != -1) //*walker == "." is found
           return 3;
        else
            temp++;
    }

    //check if char/string :
    if(((*newvalue >= 65) && (*newvalue <91)) || ((*newvalue >= 97) && (*newvalue < 123))) //ASCII
        return 2;
    //check if int :
    else if((*newvalue >= 48) && (*newvalue < 58)) // ASCII
        return 1;
    //everything else :
    return 4;
}

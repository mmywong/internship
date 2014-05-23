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
void Process(list<data> database, char* input); //take apart input into tokens
void set(list<data> database, char* propertyname, char* newvalue);

int main()
{
    data newdata;
    newdata.propertyname = "ramen";
    newdata.type = 1;
    newdata.value = "3";

    list<data> database;
    database.InsertHead(newdata);
    cout << "current database: " << endl;
    database.Print();

    cout << endl << endl<< "=======================" << endl << endl;

    char* input;
    cout << ":";
    cin.getline(input, 50);
    cout << "checkpoint" << endl;
    cout << "input : " << input << endl;

    Process(database, input);

    cout << "new database : ";
    database.Print();
    cout << endl << endl;

    return 0;
}

void Process(list<data> database, char* input)
{
    int i=0;

    //convert input from string to char*
//    char * in = new char [StrLen(input)+1];
//    strcpy (in, input.c_str());

    char* A[3];
    char* p = strtok (input," ");
    while (p != NULL)
        {
          A[i] = p;
          cout << A[i] << endl;
          p = strtok(NULL," =");
          i++;
        }
    cout << endl;

    cout << "first chop : " << A[0] << endl;
    cout << "second chop : " << A[1] << endl;
    cout << "third chop : " << A[2] << endl;

//    cout << "A[0] : " << A[0] << endl;
    if((FindStr("SET", A[0], 0) != -1) || (FindStr("set", A[0],0) != -1)) // "SET" is found in command
    {
        cout << "calling function : set(database, name, newvalue);" << endl;
        cout << "A[1] : " << A[1] << endl;
        cout << "A[2] : " << A[2] << endl;
        set(database, A[1], A[2]);
    }
    else if((FindStr("GET*", A[0], 0) != -1) || (FindStr("get*", A[0], 0)!= -1))
        cout << "getall();" << endl;
    else if((FindStr("GET", A[0], 0) != -1) || (FindStr("get", A[0], 0) != -1))
        cout << "get();" << endl;
    else
        cout << "command does not exist" << endl;
//    delete[] in;
}


void set(list<data> database, char* propertyname, char* newvalue)
{
    data newdata;
    newdata.propertyname = propertyname;
    newdata.type = whattype(newvalue);
    newdata.value = newvalue;
    cout << "new data : " << newdata << endl;
    //case 1: empty list
    if(database.isEmpty() == true)
    {
        database.InsertHead(newdata);
        cout << "database empty" << endl;
    }
    //case 2: name exists. search for it and set its value
    else if(database.Search(newdata) != -1) // found
    {
        Iterator<data> positionfound = database.Ithnode(database.Search(newdata));
        cout << "what search-iterator is pointing at : " << *positionfound << endl;
        cout << "database now : ";
        database.Print();
        database.InsertBefore(positionfound,newdata);
        cout << "database now (2) : ";
        database.Print();
        cout << "what iterator is pointing at now : " << *positionfound << endl;

        //***DEBUG***//
        data tester;
        tester = database.Delete(positionfound);
        cout << "tester : " << tester << endl;
        database.Print();
    }
    //case 3: name does not exist. add this new item
    else
    {
        database.Append(newdata);
        cout << "supposed to append?" << endl;
    }
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

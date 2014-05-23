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
void Process(list<data> &database, char* input); //take apart input into tokens
void set(list<data>& database, char* propertyname, char* newvalue);
void get(list<data> database, char* propertyname);
void getall(list<data> database);

int main()
{
//    data newdata;
//    newdata.propertyname = "ramen";
//    newdata.type = 1;
//    newdata.value = "3";

//    data newdata2;
//    newdata2.propertyname = "miso";
//    newdata2.type = 2;
//    newdata2.value = "spicy";

    list<data> database;
    char* input = new char [50];
    cout << ":";
    cin.getline(input, 50);

//    database.InsertHead(newdata);
//    database.Append(newdata2);
//    cout << "current database: " << endl;
//    database.Print();
    while(input)
    {
        Process(database, input);
        database.Print();
        cout << endl << endl << ":";
        cin.getline(input, 50);
    }
    delete [] input;
    return 0;
}

void Process(list<data>& database, char* input)
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
          p = strtok(NULL," =");
          i++;
        }
    cout << endl;

    /*
    //***DEBUG*** : to test tokens
//    cout << "first chop : " << A[0] << endl;
//    cout << "second chop : " << A[1] << endl;
//    cout << "third chop : " << A[2] << endl;
    */

    if((FindStr("SET", A[0], 0) != -1) || (FindStr("set", A[0],0) != -1)) // "SET" is found in command
        set(database, A[1], A[2]);
    else if((FindStr("GET*", A[0], 0) != -1) || (FindStr("get*", A[0], 0)!= -1))
    {
        cout << "getall()" << endl;
        getall(database);
    }
    else if((FindStr("GET", A[0], 0) != -1) || (FindStr("get", A[0], 0) != -1))
        get(database, A[1]);
    else
        cout << "error : command does not exist" << endl;
//    delete[] in;
}


void set(list<data> &database, char* propertyname, char* newvalue)
{
    data newdata;
    newdata.propertyname = propertyname;
    newdata.type = whattype(newvalue);
    newdata.value = newvalue;
//    cout << "new data : " << newdata << endl;
    //case 1: empty list
    if(database.isEmpty() == true)
    {
        database.InsertHead(newdata);
    }
    //case 2: name exists. search for it and set its value
    else if(database.Search(newdata) != -1) // found
    {
        Iterator<data> searchptr = database.Ithnode(database.Search(newdata));
        //case : input type is incompatible (e.g. int set to string)
        if(newdata.type != (*searchptr).type)
            cout << "error : input value is incompatible" << endl;
        else
        {

            /***DEBUG***
            cout << "what iterator(of search result) is pointing at : " << *searchptr << endl;
            cout << "database before : ";
            database.Print();
            cout << endl;
            */

            database.InsertBefore(searchptr,newdata);

            /***DEBUG***
            cout << "database after insert: ";
            database.Print();
            cout << endl;
            cout << "what search-iterator is poiting at: " << *searchptr << endl;
            */

            database.Delete(searchptr);

            /***DEBUG***
            cout << "database after delete : ";
            database.Print();
            cout << endl;

            data tester;
            tester = database.Delete(searchptr);
            cout << "tester : " << tester << endl;
            database.Print();
            */
        }
    }
    //case 3: name does not exist. add this new item
    else
    {
        database.Append(newdata);
    }
}

void get(list<data> database, char* propertyname)
{
    data dummydata;
    dummydata.propertyname = propertyname;

    Iterator<data> searchptr = database.Ithnode(database.Search(dummydata));
    cout << "[" << *searchptr << "]";
}

void getall(list<data> database)
{
    database.Print();
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

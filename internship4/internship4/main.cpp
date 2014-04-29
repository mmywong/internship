#include <iostream>
#include <cstring>
#include <string>

#include "iterator.h"
#include "list.h"
#include "node.h"
#include "stringfx.h"
#include "data.h"
//#include "../../../CS2/stringfunctions2/strfx/arraystrfx.h"

using namespace std;

void shiftLeft(char* A, int index);
int deletenonchar(char* input); // returns the position of the first deleted nonchar
void insertnonchar(char* input);
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

    char* name;
    cout << ":";
    cin.getline(name, 50);
    cout << "check" << endl;
    cout << "input : " << name << endl;
    char* in = name;
    insertnonchar(in);

    cout << "string : " << in << endl;

    int token1_pos, token2_pos, token3_pos;
    int token1_length, token2_length;

    token1_pos = 0; //FindNotAny(hash, sentence, 0);
    token2_pos = Find('#', in, token1_pos);
    cout << "token 2 pos : " << token2_pos;

    shiftLeft(in, token2_pos);
    cout << "shift left : " << in << endl;

    token1_length = token2_pos - token1_pos;
    cout << "token 1 length : " << token1_length << endl;

    token3_pos = Find('#', in, token2_pos);

    shiftLeft(in, token3_pos)
    cout << "token 3 pos : " << token3_pos << endl;

    token2_length = token3_pos - token2_pos;
    cout << "token 2 length : " << token2_length << endl;

    char* A[3];
    SubStr(in, A[0], token1_pos, token1_length);
    SubStr(in, A[1], token2_pos, token2_length);
    A[2] = in + token3_pos;

    cout << "A[0]" << A[0] << endl;
    cout << "A[1]" << A[1] << endl;
    cout << "A[2]" << A[2] << endl;

//    string input;
//    cout << endl << endl<< ": ";
//    cin >> input;
//    cout << endl << endl;




//    Process(database, input);

//    cout << "new database : " << endl;
//    database.Print();
//    cout << endl << endl;

    return 0;
}

void Process(list<data> database, char* input)
{
    char* in = new char [input.length()+1];
    strcpy(in, input.c_str());

    insertnonchar(in);

    char* A[3];

    int token1_pos, token2_pos, token3_pos;
    int token1_length, token2_length, token3_length;

    token1_pos = FindNotAny("#", in, 0);
    token2_pos = FindAny("#", in, token1_pos);
    shiftLeft(in, token2_pos);
    token1_length = token2_pos - token1_pos;
    token3_pos = FindAny("#", in, token2_pos);
    token2_length = token3_pos - token2_pos;

    SubStr(in, A[0], token1_pos, token1_length);
    SubStr(in, A[1], token2_pos, token2_length);
    A[2] = in + token3_pos;

//    char* walker = in; // moves along the array






//    cout << input;
//    string test = "hello world = 123";
//    int i=0;
//    //convert input from string to char*
//    char * in = new char [input.length()+1];
//    strcpy (in, input.c_str());

//    char* A[3];
//    char* p = strtok (in," ");
//    while (p != NULL)
//        {
//          A[i] = p;
//          cout << A[i] << endl;
//          p = strtok(NULL," =");
//          i++;
//        }
//    cout << endl;
//    string slice2(A[1]);
//    string slice3(A[2]);
//    cout << "first chop : " << A[0] << endl;
//    cout << "second chop : " << slice2 << endl;
//    cout << "third chop : " << slice3 << endl;

//    cout << "A[0] : " << A[0] << endl;
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
*/

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

//char* gettoken(char* &input, start, ) // returns the position at which the token starts. puts a pointer at it.
//{
//    char* token; // to copy the substr later and return it.
//    int token1 = FindAny("#", input, 0);


//    SubStr(input, token, start, length);
//    return token;
//}

void shiftLeft(char* A, int index)
{
    //index is the position which will be "deleted" or replaced
    int size = StrLen(A);
    for(int i=index; i<size; i++)
    {
        *(A+i) = *(A+i+1);
    }
    *(A+size) = '\0';
}

void deletenonchar(char *input, int startpos)
{
    int newstartpoint = FindNotAny('#', input, startpos);
    for(int i = startpos; i<newstartpoint; i++)
    {
        if(Find('#', input, startpos) != -1) // if '#' is found,
            shiftLeft(input, Find('#', input, startpos));
    }
}

void insertnonchar(char *input)
{
    int pos = 0; //position at which the token starts
    for(int i=0; i<StrLen(input); i++)
    {
        pos = FindAny(" =", input, pos);
        *(input + pos) = '#';
        pos++;
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

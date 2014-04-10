#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void Process(string input);
//int FindBanned(char *banned, char *wholeline); //finds position of banned characters in wholeline
//int StrLen(char *iPtr); //finds length of pointer array

int main()
{
    string input = "set property = value";
    Process(input);

//    char* banned, wholeline;
//    string bans, sentence;
//    bans = " =";
//    sentence = "test value = 5";
//    banned.c_str();
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
    delete[] in;

    //each element in the array is now a string pointed by a char*
    char* command;
    char* propertyname;
    char* newvalue;

    command = A[0]; //collects to read GET/SET/GET*
    propertyname = A[1]; //collects to read propertyname

    //find out which command was typed in and call the appropriate function
    if(*command == "SET")
    {
        cout << "set();" << endl;
        newvalue = A[2];
    }
    else if(toupper(*command) == 'GET')
        cout << "get();" << endl;
    else if(toupper(*command) == 'GET*')
        cout << "getall();" << endl;
    else
        cout << "command does not exist" << endl;
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

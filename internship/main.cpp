#include <iostream>

using namespace std;

 void Process(istream input); // fx that reads input and decides which function to call

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

  int main()
  {
     istream input;

     cout << "#--------Command Menu--------#" << endl;
     cout << "SET : Change value" << endl;
     cout << "GET : Output value" << endl << endl;
     cout << ">";
//     cin >> input; // check this?
     Process(input);

     cout << "Hello World!" << endl;
     return 0;
 }

 template<class T>
 void Process(istream input)
 {
     string command;
     char assign; // equals sign
     T propertyname,newvalue; // two variables of same typename

     input >> command >> propertyname >> assign >> newvalue;

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

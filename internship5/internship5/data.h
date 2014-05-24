#ifndef DATA_H
#define DATA_H
#include <string>

using namespace std;

struct data{
    string propertyname;
    string value;
    int type; // int/char/double/other

    friend ostream& operator <<     (ostream& out, const data& avalue);
    friend bool operator !=         (data d1, data d2); // NOTE: checks only for their names, not their data
    friend bool operator ==         (data d1, data d2); // NOTE: checks only for their names, not their data
};

ostream &operator <<(ostream &out, const data& avalue)
{
    out << avalue.propertyname << ":" << avalue.value;
    return out;
}

bool operator !=(data d1, data d2)
{
    if (d1.propertyname != d2.propertyname)
        return true;
    else
        return false;
}

bool operator ==(data d1, data d2)
{
    if(d1.propertyname == d2.propertyname)
        return true;
    else
        return false;
}

#endif // DATA_H

#include "propertytype.h"

propertytype::propertytype()
{
}

template<class T>
void propertytype<T>::get(T propertyname) // prints out current value
{
    cout << propertyname;
}

template<class T>
void propertytype<T>::set(T propertyname, T newvalue)
{
    propertyname = newvalue;
}

template<class T>
void propertytype<T>::printall(T propertyname)
{
    while(propertyname)
        cout << propertyname;
}

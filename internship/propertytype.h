#ifndef PROPERTYTYPE_H
#define PROPERTYTYPE_H
#include <iostream>
#include <stdio.h>
#include <string.h>

template<class T>
struct propertytype
{
    string propertyname;
    T object;
};

#endif // PROPERTYTYPE_H

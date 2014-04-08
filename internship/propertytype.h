#ifndef PROPERTYTYPE_H
#define PROPERTYTYPE_H

template<class T>
class propertytype
{
public:
    propertytype();
    void get(T propertyname);
    void set(T propertyname, T newvalue);
    void printall(T propertyname);
};

#endif // PROPERTYTYPE_H

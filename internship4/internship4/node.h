#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
struct node{
    T item;
    node<T>* next;
};
#endif // NODE_H

#ifndef LIST_H
#define LIST_H
#include "iterator.h"
#include "data.h"
#include <iostream>

using namespace std;

template <class T>
class list
{
public:
    list                            ();

    //---big three---//
    list                            (list<T> &copythis); // copy constructor
    const list<T> &operator =       (list<T>& right); //assignment operator
    ~list                           ();  //destructor

    //---create---//
    void InsertHead                 (T num);//must return a node*
    void InsertAfter                (Iterator<T> marker, T num); // makes a node to the right of marker's node
    void InsertBefore               (Iterator<T> marker, T num); // makes a node to the left of marker's node
    void Append                     (T num); // makes a node at the very end of the list

    //---delete---//``
    T Delete                        (Iterator<T> marker); // returns the item you deleted

    //---search---//
    int Search                      (T key);

    //---show---//
    void Print                      () const;

    //---change---//
    T &operator []                  (int index);

    //---new lists---//
    void Reverse                    ();

    //---markers---//
    Iterator<T> Begin                  ();
    Iterator<T> End                    ();
    Iterator<T> Ithnode                (int i);
    int IthElement                     (); // returns the item of IthNode
    bool isEmpty                        ();

private:
    void InsertAfter                (node<T>* marker, T num); // makes a node to the right of marker's node
    void InsertBefore               (node<T>* marker, T num); // makes a node to the left of marker's node
    T Delete                        (node<T>* marker);
    node<T>* Remove                 (node<T>* marker);
    node<T>* nEnd                   ();

    node<T>* head;
};

//=============functions==============//
//---constructor---//
template <class T>
list<T>::list()
{
    head = NULL;
}

//---big three---//
//memory leak as well
template <class T>
list<T>::list(list<T> &copythis)
{
    InsertHead(copythis.head->item);
    node<T>* marker = copythis.head;
    node<T>* marker2 = head;
    head->next = NULL;
    marker = marker->next;
    while(marker != NULL)
    {
        Append(marker->item);
        marker = marker->next;
        marker2 = marker2->next;
    }
}

template <class T>
const list<T> &list<T>::operator =(list<T> &right)
{
    InsertHead(right.head->item);
    node<T>* marker = right.head;
    node<T>* marker2 = head;
    head->next = NULL;
    marker = marker->next;
    while(marker != NULL)
    {
        Append(marker->item);
        marker = marker->next;
        marker2 = marker2->next;
    }
}

template <class T>
list<T>::~list()
{
    while(head)
    {
        Delete(head);
    }
    head = NULL;
}

//---create---//
template <class T>
void list<T>::InsertHead(T num)
{
    node<T>* temp = new node<T>;

    temp->item = num;
    temp->next = head;
    head = temp;
}

template <class T>
void list<T>::InsertAfter(Iterator<T> marker, T num)
{
    node<T>* temp = new node<T>;
    temp->item = num;
    temp->next = marker.nodeptr->next;
    marker.nodeptr->next = temp;
}

template <class T>
void list<T>::InsertBefore(Iterator<T> marker, T num)
{
    if(marker == head)
        InsertHead(num);
    else{
        node<T>* temp = new node<T>;
        node<T>* walker = head;
        temp->item = num;

        while((walker->next != marker.nodeptr) && (walker->next != NULL))
            walker = walker->next;
        temp->next = walker->next;
        walker->next = temp;
    }
}

template <class T>
void list<T>::Append(T num)
{
    Iterator<T> marker = End();
    InsertAfter(marker, num);
}

//---delete---//
template <class T>
node<T>* list<T>::Remove(node<T> *marker)
{
    node<T>* walker = head;

    if(marker == head) // case: want to remove head
        head = head->next;
    else // case: want to remove something from pos 1 onwards
    {
        while(walker->next != marker && walker->next != NULL) // finds position before marker
            walker = walker->next;
        walker->next = marker->next; // makes the previous point at the node after marker
    }
    marker->next = NULL;
    return marker;
}

template <class T>
T list<T>::Delete(Iterator<T> marker)
{
    return Delete(marker.nodeptr);
}

template <class T>
T list<T>::Delete(node<T> *marker)
{
    T temp = marker->item;
    delete Remove(marker);
    return temp;
}

template <class T>
int list<T>::Search(T key)
{
    int pos = 0;
    node<T>* marker = head;
    while((marker != NULL) && (marker->item != key))
    {
        marker = marker->next;
        pos++;
    }
    if(marker == NULL)
        return -1; // not found
    return pos; // found
}

//---show---//
template <class T>
void list<T>::Print() const
{
    node<T>* walker = head;
    if(walker == NULL)
        cout << "-empty-";
    while(walker != NULL)
    {
        cout<<"["<<walker->item<<"]  ";
        walker = walker->next;
    }
}

template <class T>
T &list<T>::operator [](int index)
{
    return Ithnode(index).nodeptr->item;
}

template <class T>
void list<T>::Reverse()
{
    node<T>* first = head;
    node<T>* last = nEnd();
    list<T> newlist;

    newlist.InsertHead(Delete(last));

    while(first != NULL)
    {
        InsertAfter(newlist.head, Delete(last));
        last = nEnd();
    }
    head = newlist.head;
}

//---markers---//
template <class T>
Iterator<T> list<T>::Begin()
{
    return Iterator<T>(head);
}

template <class T>
node<T>* list<T>::nEnd()
{
    node<T>* walker = head;
    while(walker->next != NULL)
        walker = walker->next;
    return walker;
}

template <class T>
Iterator<T> list<T>::End()
{
    return Iterator<T>(nEnd());
}

template <class T>
Iterator<T> list<T>::Ithnode(int i)
{
    node<T>* walker = head;
    for(int j=0; j<i; j++)
       walker = walker->next; // makes walker point at the node we want
    return Iterator<T>(walker); // returns the address of the Ith node
}

template <class T>
bool list<T>::isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

template <class T>
void list<T>::InsertAfter(node<T> *marker, T num)
{
    node<T>* temp = new node<T>;
    temp->item = num;
    temp->next = marker->next;
    marker->next = temp;
}

template <class T>
void list<T>::InsertBefore(node<T> *marker, T num)
{
    if(marker==head)
        InsertHead(num);
    else
    {
        node<T>* temp = new node<T>;
        node<T>* walker = head;
        temp->item = num;

        while((walker->next != marker) && (walker->next != NULL))
            walker = walker->next;
        temp->next = walker->next;
        walker->next = temp;
    }
}

#endif // LIST_H

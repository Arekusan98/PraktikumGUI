#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "linkedlist.h"

template<class T>
class SortedLinkedList : public LinkedList<T>
{
public:
    SortedLinkedList();
    void insertNode(T* t);
};

#endif // SORTEDLINKEDLIST_H

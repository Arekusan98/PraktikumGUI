#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "linkedlist.h"


class SortedLinkedList : public LinkedList
{
public:
    SortedLinkedList();
    void insertNode(Booking* booking);
};

#endif // SORTEDLINKEDLIST_H

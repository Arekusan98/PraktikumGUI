#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"

using namespace std;
class LinkedList
{
public:
    LinkedList();
    void insertNode(Booking* booking);
    bool isAtEnd(){
        return (cursor == end);
    }
    void advance(){
        if(cursor && cursor->GetNextNode())
            cursor = cursor->GetNextNode();
    }
    void deleteNode();
    Booking* getNode() {
        return cursor->GetData();
                     }
protected:
    Node* root;
    Node* cursor;
    Node* end;
};

#endif // LINKEDLIST_H

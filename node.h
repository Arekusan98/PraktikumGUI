#ifndef NODE_H
#define NODE_H
#include "booking.h"

class Node {
public: Node (Booking* booking) : booking(booking), previousNode(NULL), nextNode(NULL) { }
    Node* GetNextNode() const { return nextNode;}
    void SetNextNode(Node* nextNode) { this->nextNode = nextNode;}
    Node* GetPreviousNode() const {return previousNode;}
    void SetPreviousNode(Node* previousNode){
        this->previousNode = previousNode;
    }
    Booking* GetData() const {return booking; }
    void SetData(Booking* booking) {this->booking = booking;}

private:
    Booking* booking;
    Node* previousNode;
    Node* nextNode;
};
#endif // NODE_H

#include "sortedlinkedlist.h"

SortedLinkedList::SortedLinkedList()
{

}
void SortedLinkedList::insertNode(Booking *booking){
    cursor = root;
    while(cursor->GetNextNode()){
        if(booking->getId() < cursor->GetNextNode()->GetData()->getId()){
            break;
        }
        cursor = cursor->GetNextNode();
    }

    Node* node = new Node(booking);
    node->SetPreviousNode(cursor);
    if(root->GetNextNode() == NULL){
        root->SetNextNode(node);
        node->SetPreviousNode(root);
    }
    else{
        node->SetNextNode(cursor->GetNextNode());
        if(cursor->GetNextNode() != NULL){
            cursor->GetNextNode()->SetPreviousNode(node);
        }
        cursor->SetNextNode(node);
    }
    cursor = node;
    return;
}
#include "linkedlist.h"

LinkedList::LinkedList()
{
    root = NULL;
    end = new Node(nullptr);
    cursor = end;
}
void LinkedList::insertNode(Booking *booking){
    Node* node = new Node(booking);
    if(root == NULL){
        root = node;
        node->SetNextNode(end);
        end->SetPreviousNode(node);
    }else{
        node->SetNextNode(cursor);
        node->SetPreviousNode(cursor->GetPreviousNode());
        if(cursor->GetPreviousNode()){
            cursor->GetPreviousNode()->SetNextNode(node);
        }
        cursor->SetPreviousNode(node);
    }
    cursor = node;

    if (!cursor->GetPreviousNode()){
        root = cursor;
    }
}

void LinkedList::deleteNode(){
    Node* tmpPrevious;
    Node* tmpNext;

    if(root ==NULL){
        throw underflow_error("Versuch aus leere Liste zu loeschen");
    }else{
        if(cursor->GetPreviousNode() == NULL){
            if(cursor->GetNextNode() == end){
                delete cursor;
                root = NULL;
                end->SetPreviousNode(NULL);
                cursor = end;
            }
            else{
                cursor = cursor->GetNextNode();
                delete root;
                cursor->SetPreviousNode(NULL);
                root = cursor;
            }
        }else{
            if(cursor->GetNextNode() == end){
                tmpPrevious=cursor->GetPreviousNode();
                delete cursor;
                cursor = end;
                end->SetPreviousNode(tmpPrevious);
                tmpPrevious->SetNextNode(end);
            }else{
                tmpPrevious = cursor->GetPreviousNode();
                tmpNext = cursor->GetNextNode();

                delete cursor;

                tmpPrevious->SetNextNode(tmpNext);
                tmpNext->SetPreviousNode(tmpPrevious);
                cursor = tmpPrevious;
            }
        }
    }
    return;
}

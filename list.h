#ifndef LIST_H
#define LIST_H
#include "node.h"

using namespace std;
template<typename T>
class List
{
public:
    List();
    void insertNode(T t);
    bool isAtEnd(){
        return (cursor == end);
    }
    void advance(){
        if(cursor && cursor->GetNextNode())
            cursor = cursor->GetNextNode();
    }
    void deleteNode();
    T getNode();
    void push_back(T t);
    T at(unsigned int i) const;
    void clear();
    unsigned int size() const;

protected:
    Node<T>* root = nullptr;
    Node<T>* cursor = nullptr;
    Node<T>* end = nullptr;
};

template<typename T>
List<T>::List()
{
    root = nullptr;
    end = new Node<T>(nullptr);
    cursor = end;
}
template<typename T>
void List<T>::insertNode(T t){
    cursor = root;
    while(cursor->GetNextNode()){
        if(t < cursor->GetNextNode()->GetData()){
            break;
        }
        cursor = cursor->GetNextNode();
    }

    Node<T>* node = new Node<T>(t);
    node->SetPreviousNode(cursor);
    if(root->GetNextNode() == nullptr){
        root->SetNextNode(node);
        node->SetPreviousNode(root);
    }
    else{
        node->SetNextNode(cursor->GetNextNode());
        if(cursor->GetNextNode() != nullptr){
            cursor->GetNextNode()->SetPreviousNode(node);
        }
        cursor->SetNextNode(node);
    }
    cursor = node;
    return;
}

template<typename T>
void List<T>::deleteNode(){
    Node<T>* tmpPrevious;
    Node<T>* tmpNext;

    if(root ==nullptr){
        return;
    }else{
        if(cursor->GetPreviousNode() == nullptr){
            if(cursor->GetNextNode() == end){
                delete cursor;
                root = nullptr;
                end->SetPreviousNode(nullptr);
                cursor = end;
            }
            else{
                cursor = cursor->GetNextNode();
                delete root;
                cursor->SetPreviousNode(nullptr);
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
template<typename T>
T List<T>::getNode() {
    return cursor->GetData();
}
template<typename T>
void List<T>::push_back(T newElem)
{
    Node<T>* newNode = new Node<T>(newElem);


    if (!root) {
        root = newNode;
        end = newNode;
        return;

    }//else

    Node<T>* cursor = root;
    while (cursor) {
        if ((cursor->GetData()) < (newNode->GetData())) {
            cursor = cursor->GetNextNode();
        } else {
            break;
        }
    }
    if (cursor) {
        if(cursor == root){
            root = newNode;
        }else{
            cursor->GetPreviousNode()->SetNextNode(newNode);
            newNode->SetPreviousNode(cursor->GetPreviousNode());
        }
        newNode->SetNextNode(cursor);
        cursor->SetPreviousNode(newNode);

    } else{
        end->SetNextNode(newNode);
        newNode->SetPreviousNode(end);
        end = newNode;
    }

}

template<typename T>
void List<T>::clear(){
    cursor = root;
}
template<typename T>
T List<T>::at(unsigned int i) const
{
    if (i >= this->size()) return nullptr;
    //else
    Node<T>* cursor = this->root;

    for (int j = i; j > 0; j--) {
        cursor=cursor->GetNextNode();
    }
    return cursor->GetData();
}

template<typename T>
unsigned int List<T>::size() const
{
    if (root==nullptr) return 0;
    //else
    if(root==end) return 1;
    //else
    Node<T>* cursor = root->GetNextNode();
    unsigned int count = 2;
    while(cursor != end){
        cursor = cursor->GetNextNode();
        count++;
    }
    return count;
}


#endif // LIST_H

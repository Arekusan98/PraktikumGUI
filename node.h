#ifndef NODE_H
#define NODE_H
template<class T>
class Node {
public: Node (T t) : t(t), previousNode(nullptr), nextNode(nullptr) { }
    Node* GetNextNode() const { return nextNode;}
    void SetNextNode(Node* nextNode) { this->nextNode = nextNode;}
    Node* GetPreviousNode() const {return previousNode;}
    void SetPreviousNode(Node* previousNode){
        this->previousNode = previousNode;
    }
    T GetData() const {return t; }
    void SetData(T t) {this->t = t;}

private:
    T t;
    Node* previousNode;
    Node* nextNode;
};
#endif // NODE_H

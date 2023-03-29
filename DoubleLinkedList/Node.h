#include <iostream>


#ifndef SDIZOPROJECT_NODE_H
#define SDIZOPROJECT_NODE_H


class Node {
    friend class DoubleLinkedList;

    int value;
    Node* prev;
    Node* next;

public:

    Node();

    ~Node();

    int getValue();

    Node* getPrev();

    Node* getNext();

    void setPrev(Node *prev);

    void setNext(Node *next);

    void setValue(int value);

};


#endif //SDIZOPROJECT_NODE_H

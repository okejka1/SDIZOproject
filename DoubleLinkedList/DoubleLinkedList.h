#ifndef SDIZOPROJECT_DOUBLELINKEDLIST_H
#define SDIZOPROJECT_DOUBLELINKEDLIST_H

#include <iostream>
#include "Node.h"



class DoubleLinkedList {

public:

    Node* head;
    Node* tail;

    int size;




    DoubleLinkedList();

    ~DoubleLinkedList();

    void displayList();

    void loadFromFile(std::string fileName);

    void pushFront(int val);

    void pushBack(int val);

    void removeElement(Node* element);

    void removeFront();

    void removeBack();

    void removeGiven(int val);

    bool isValueInList(int val);

    void generateList(int sizeOfList);

    void addElement(int index, int val);

    void clear();
};


#endif //SDIZOPROJECT_DOUBLELINKEDLIST_H

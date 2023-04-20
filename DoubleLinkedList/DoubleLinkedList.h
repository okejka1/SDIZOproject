#ifndef SDIZOPROJECT_DOUBLELINKEDLIST_H
#define SDIZOPROJECT_DOUBLELINKEDLIST_H

#include <iostream>
#include "Node.h"



class DoubleLinkedList {

public:

    Node* head;
    Node* tail;

    int size;
    long results[7]; // table to store time measurements for a doublelinkedlist tests
/*
result[0] ->  inserting an element at the beginning of a doublelinkedlist
result[1] ->  inserting an element at the end of a doublelinkedlist
result[2] ->  inserting an element at the random position of a doublelinkedlist
result[3] ->  deleting an element at the beginning of a doublelinkedlist
result[4] ->  deleting an element at the end  of a doublelinkedlist
result[5] ->  deleting an element at the random position of a doublelinkedlist
result[6] ->  searching for a random element of a doublelinkedlist
*/




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

    void measureTime(int numberOfTests, int sizeOfStructure);

    void removeFromIndex(int index);
};


#endif //SDIZOPROJECT_DOUBLELINKEDLIST_H

#include <iostream>

#ifndef SDIZOPROJECT_HEAP_H
#define SDIZOPROJECT_HEAP_H


class Heap {

    int size;


    Heap();

    ~Heap();

    void loadFromFile();

    void displayHeap();

    void generateHeap();

    void deleteRoot();

    void deleteValue(int val);

    void addValue(int val);

    void isValueInHeap(int val);







};


#endif //SDIZOPROJECT_HEAP_H

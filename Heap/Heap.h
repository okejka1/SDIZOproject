#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <random>

#ifndef SDIZOPROJECT_HEAP_H
#define SDIZOPROJECT_HEAP_H


class Heap {


public:


    int size; // current size of a heap
    int capacity; // max size of a heap
    int *heap; // pointer to an  array of heap elements

    long results[3];

    /*
    result[0] -> inserting a given value to the heap
    result[1] ->  deletion of a root from the heap
    result[2] ->  search for a random value in the heap
    */

    // methods

    int parent(int i);

    int left(int i);

    int right(int i);

    void heapify(int i);

    void generateHeap(int sizeOfHeap);

    void insertVal(int val);

    void swap(int &a, int &b);

    void displayHeap();

    int deleteRoot();

    int isValInHeap(int val);

    void deleteVal(int val);

    void deleteValByIndex(int index);

    void increaseValue(int i, int value);

    void loadFromFile(std::string fileName);

    void measureTime(int numberOfTests, int sizeOfStructure);

    Heap();

    ~Heap();

};


#endif //SDIZOPROJECT_HEAP_H

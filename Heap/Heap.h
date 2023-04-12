#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <random>

#ifndef SDIZOPROJECT_HEAP_H
#define SDIZOPROJECT_HEAP_H

using namespace std;

class Heap {


public:



    int size; // current size of a heap
    int capacity; // max size of a heap
    int *heap; // pointer to an  array of heap elements



    // methods

    int parent(int i);

    int left(int i);

    int right(int i);

    void heapify(int i);

    void generateHeap(int sizeOfHeap);

    void insertVal(int val);

    void swap(int &a, int &b);

    void displayHeap();

    void deleteVal(int val);

    Heap();

    ~Heap();








};


#endif //SDIZOPROJECT_HEAP_H

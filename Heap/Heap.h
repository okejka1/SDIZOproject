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

    int *heap; // pointer to the root of a heap

    int parent(int i);

    int left(int i);

    int right(int i);

    void heapify(int i);

    void generateHeap(int size);

    void insert(int val);

    void swap(int &a, int &b);

    void displayHeap();



    Heap();

    ~Heap();








};


#endif //SDIZOPROJECT_HEAP_H

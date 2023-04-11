#include "Heap.h"

using namespace std;


Heap::Heap() {
    size = 0;
    capacity = 1000000;
    heap = new int [capacity];
}

Heap::~Heap() {
    heap = nullptr;
    size = 0;

}

int Heap::parent(int i) {
    return (i - 1) / 2;
}

int Heap::left(int i) {
    return 2 * i + 1;
}

int Heap::right(int i) {
    return 2 * i + 2;
}

void Heap::swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;

}


void Heap::heapify(int i) { // maintaining the property of max heap

    // initial conditions
    int l = left(i);
    int r = right(i);
    int largest = i;


    if ((l < size) && (heap[l] > heap[i])) {
        largest = l;
    } else {
        largest = i;
    }
    if ((r < size) && (heap[r] > heap[largest])) {
        largest = r;
    }
    if (i != largest) {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void Heap::insertVal(int val) {

    size++;

    int i = size - 1;
    heap[i] = val;

    while (i != 0 && heap[parent(i)] < heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }

}

void Heap::deleteVal(int val) {


}


void Heap::generateHeap(int sizeOfHeap) {


    delete[] heap;

    srand(time(NULL));
    int *updated = new int [sizeOfHeap];
    for (int i = 0; i < sizeOfHeap; i++) {
        updated[i] = (rand() % 100);
    }

    heap = updated;
    size = sizeOfHeap;

    for(int i = 0; i < sizeOfHeap; i++)
    {
        cout << updated[i] << " ";
    }
    cout  << endl;

    for (int i = (size-1)/2; i >= 0; i--) {
        heapify(i);
    }




}

void Heap::displayHeap() {
    for(int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }

}












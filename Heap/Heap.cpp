#include "Heap.h"

using namespace std;


Heap::Heap() {
    size = 0;
    heap = nullptr;
}

Heap::~Heap() {

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
//         temp = heap[i];
//         heap[i] = heap[largest];
//         heap[largest] = temp;
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void Heap::insert(int val) {


    size++;

    int i = size - 1;
    heap[i] = val;

    while (i != 0 && heap[parent(i)] < heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }


}

void Heap::generateHeap(int val) {



    srand(time(NULL));

//    for (int i = 0; i < size; i++) {
//        heap[i] = (rand() % 100);
//    }

//    for (int i = (size - 1) / 2; i > 0; i--) {
//        heapify(i);
//    }


}

void Heap::displayHeap() {
    for(int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }

}












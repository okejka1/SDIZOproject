#include "Heap.h"

using namespace std;


Heap::Heap() {
    size = 0;
    capacity = 1000000;
    heap = new int[capacity];
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
    increaseKey(isValInHeap(val), INT_MAX);
    deleteRoot();

}


void Heap::generateHeap(int sizeOfHeap) {


    srand(time(NULL));

    for (int i = 0; i < sizeOfHeap; i++) {
        heap[i] = (rand() % 1000);
    }

    size = sizeOfHeap;


    for (int i = (size - 1) / 2; i >= 0; i--) {
        heapify(i);
    }


}

void Heap::displayHeap() {
    cout << endl;
    int levels = ceil(log2(size + 1)); // calculate the number of levels in the heap
    int index = 0;
    for (int i = 0; i < levels; i++) {
        // print spaces to align the nodes at each level
        for (int j = 0; j < pow(2, levels - i - 1) - 1; j++) {
            cout << " ";
        }
        // print the nodes at each level
        for (int j = 0; j < pow(2, i) && index < size; j++) {
            cout << heap[index++];
            // print spaces to align the nodes at each level
            for (int k = 0; k < pow(2, levels - i) - 1; k++) {
                cout << " ";
            }
        }
        cout << std::endl;

    }

    cout << "Displaying heap as an array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << "size: " << size << endl;
}

int Heap::deleteRoot() {
    if (size <= 0) {
        cout << "heap underflow" << endl;
        return -1;
    } else if (size == 1) {
        size--;
        return heap[0];
    }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
    return root;


}


int Heap::isValInHeap(int val) {

    for (int i = 0; i < size; i++) {
        if (heap[i] == val) {
            cout << "Value was found in the heap!" << endl;
            return i;
        }
    }
    cout << "Value was NOT found in the heap" << endl;
    return -1;

}

void Heap::increaseKey(int i, int key) {
    if (key < heap[i]) {
        cout << "new key is smaller than current key" << endl;
        return;
    }
    heap[i] = key;
    while ((i != 0) && (heap[parent(i)] < heap[i])) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }


}

void Heap::loadFromFile(string fileName) {
    int elementsCount;
    ifstream file;
    file.open(fileName);
    if (file.is_open()) {

        file >> elementsCount;
        if (file.fail()) {
            cout << "File error - READ SIZE\n";
            file.close();
        } else {
            size = elementsCount;
            int val;
            for (int i = 0; i < elementsCount; i++) {
                file >> val;
                if (file.fail()) {
                    cout << "File error - READ DATA\n";
                    break;
                } else
                    heap[i] = val;
            }
            for (int i = (size - 1) / 2; i >= 0; i--) {
                heapify(i);
            }
            file.close();
        }
    } else
        cout << "File error - OPEN\n";
}












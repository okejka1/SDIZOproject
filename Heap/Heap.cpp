#include "Heap.h"
#include "../Timer.h"


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


//    srand(time(NULL));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < sizeOfHeap; i++) {
//        heap[i] = (rand() % 1000);
        heap[i] = dis(gen);
    }

    size = sizeOfHeap;


    for (int i = (size - 1) / 2; i >= 0; i--) {
        heapify(i);
    }


}

void Heap::displayHeap() {
    std::cout << std::endl;
    int levels = ceil(log2(size + 1)); // calculate the number of levels in the heap
    int index = 0;
    for (int i = 0; i < levels; i++) {
        // print spaces to align the nodes at each level
        for (int j = 0; j < pow(2, levels - i - 1) - 1; j++) {
            std::cout << " ";
        }
        // print the nodes at each level
        for (int j = 0; j < pow(2, i) && index < size; j++) {
            std::cout << heap[index++];
            // print spaces to align the nodes at each level
            for (int k = 0; k < pow(2, levels - i) - 1; k++) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;

    }

    std::cout << "Displaying heap as an array:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << "size: " << size << std::endl;
}

int Heap::deleteRoot() {
    if (size <= 0) {
        std::cout << "heap underflow" << std::endl;
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
            std::cout << "Value was found in the heap!" << std::endl;
            return i;
        }
    }
    std::cout << "Value was NOT found in the heap" << std::endl;
    return -1;

}

void Heap::increaseKey(int i, int key) {
    if (key < heap[i]) {
        std::cout << "new key is smaller than current key" << std::endl;
        return;
    }
    heap[i] = key;
    while ((i != 0) && (heap[parent(i)] < heap[i])) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }


}

void Heap::loadFromFile(std::string fileName) {
    int elementsCount;
    std::ifstream file;
    file.open(fileName);
    if (file.is_open()) {

        file >> elementsCount;
        if (file.fail()) {
            std::cout << "File error - READ SIZE\n";
            file.close();
        } else {
            size = elementsCount;
            int val;
            for (int i = 0; i < elementsCount; i++) {
                file >> val;
                if (file.fail()) {
                    std::cout << "File error - READ DATA\n";
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
        std::cout << "File error - OPEN\n";
}

void Heap::measureTime(int numberOfTests, int sizeOfStructure) {
    std::ofstream file;

    for (int i = 0; i < 3; i++) {
        results[i] = 0;
    }

    Timer timer;

    int value;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000); // range for  random value


    for (int i = 0; i < numberOfTests; i++) {


        // insertion of the value to the heap
        value = dis(gen);
        timer.startTime();
        this->insertVal(value);
        timer.stopTime();
        std::cout << "Insertion of an element to the heap " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[0] += timer.nanoMeasuredTime();

        // deletion of the root from the heap
        timer.startTime();
        this->deleteRoot();
        timer.stopTime();
        std::cout << "Deletion of the root from the heap " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[1] += timer.nanoMeasuredTime();

        // search of the element from the heap
        value = dis(gen);
        timer.startTime();
        this->isValInHeap(value);
        timer.stopTime();
        std::cout << "Search of the element from the heap " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[2] += timer.nanoMeasuredTime();

    }

    std::string fileName = "..\\Heap\\heap" + std::to_string(sizeOfStructure) + ".txt";
    file.open(fileName);
    if (file.is_open()) {
        file << "TEST OF A  " << sizeOfStructure << " HEAP OUT OF " << numberOfTests << " PROBES\n";
        file << "Average results of each operation on the heap:\n";
        file << "Average time of the insertion of an element to the heap " << results[0]/numberOfTests << " [ns]\n";
        file << "Average time of the deletion of the heap's root " << results[1]/numberOfTests << " [ns]\n";
        file << "Average time of the search for a random value in the heap " << results[2]/numberOfTests << " [ns]\n";
    } else
        std::cout << "File error - OPEN\n";
}











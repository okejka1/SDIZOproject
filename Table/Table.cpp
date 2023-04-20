#include "Table.h"
#include "../Timer.h"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <random>

Table::Table() {
    tab = nullptr;
    size = 0;
}

Table::~Table() {
    delete[] tab;
}

void Table::loadFromFile(std::string fileName) {
    int elementsCount;
    std::ifstream file;
    file.open(fileName);
    if (file.is_open()) {

        file >> elementsCount;
        if (file.fail()) {
            std::cout << "File error - READ SIZE\n";
            file.close();
        } else {
            delete [] tab;
            tab = new int [elementsCount];
            size = elementsCount;
            int val;
            for (int i = 0; i < elementsCount; i++) {
                file >> val;
                if (file.fail()) {
                    std::cout << "File error - READ DATA\n";
                    break;
                } else
                    tab[i] = val;
            }
            file.close();
        }
    } else
        std::cout << "File error - OPEN\n";
}


bool Table::IsValueInTable(int val) {
    for (int i = 0; i < size; i++) {
        if (tab[i] == val) {
            std::cout << "There is value = " << val << " at index " << i << std::endl;
            return true;
        }
    }
    std::cout << "no value found\n";
    return false;
}

void Table::addValue(int index, int value) {

    if (index < 0 || index > size) {
        std::cout << "Wrong input of an index - chose an index in a range of the table \n";
    } else if (index == 0) {
        addValueFront(value);
    } else if (index == size) {
        addValueBack(value);
    } else {
        int *updated = new int[size + 1];
        int newIndex = 0;
        for (int i = 0; i < size; i++) {
            if (index == newIndex) {
                updated[newIndex] = value;
                newIndex++;
            }
            updated[newIndex] = tab[i];
            newIndex++;
        }

        delete[] tab;
        tab = updated;
        size++;
    }
}

void Table::addValueFront(int value) {
    int *updated = new int[size + 1];
    updated[0] = value;
    for (int i = 0; i < size; i++) {
        updated[i + 1] = tab[i];
    }

    delete[] tab;
    tab = updated;
    size++;
}

void Table::addValueBack(int value) {
    int *updated = new int[size + 1];
    updated[size] = value;

    for (int i = 0; i < size; i++) {
        updated[i] = tab[i];
    }

    delete[] tab;
    tab = updated;
    size++;

}

void Table::deleteFromTableFront() {
    if (size > 0) {
        int *updated = new int[size - 1];

        for (int i = 0; i < size - 1; i++) {
            updated[i] = tab[i + 1];
        }
        delete[] tab;
        tab = updated;
        size--;
    } else {
        std::cout << "The table is empty \n";
    }


}

void Table::deleteFromTableBack() {
    if (size > 0) {
        int *updated = new int[size - 1];

        for (int i = 0; i < size - 1; i++) {
            updated[i] = tab[i];
        }
        delete[] tab;
        tab = updated;
        size--;
    } else {
        std::cout << "The table is empty\n";
    }

}


void Table::deleteFromTable(int index) {
    if (size == 0) {
        std::cout << "No elements to delete - the table is empty \n";
    } else if (index >= size) {
        std::cout << "No such index in the table \n";
    } else {
        if (index == 0) {
            deleteFromTableFront();
        } else if (index == size - 1) {
            deleteFromTableBack();
        } else {
            int *updated = new int[size - 1];
            int newIndex = 0;
            for (int i = 0; i < size; i++) {
                if (newIndex == index) {
                    i++;
                    updated[newIndex] = tab[i];
                } else {
                    updated[newIndex] = tab[i];
                }
                newIndex++;
            }
            delete[] tab;
            tab = updated;
            size--;

        }

    }
}

void Table::display() {
    if (size == 0) {
        std::cout << "The table is empty!\n";
    }
    std::cout << "================================================" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "================================================" << std::endl;

}

void Table::generateTable(int sizeOfTable) {

    srand(time(NULL));
    int *updated = new int[sizeOfTable];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int i = 0; i < sizeOfTable; i++) {
//        updated[i] = (rand() % 1000);
        updated[i] = dis(gen);
    }
        delete[] tab;
        tab = updated;
        size = sizeOfTable;

    }


void Table::measureTime(int numberOfTests, int sizeOfStructure) {


    std::ofstream file;

    for(int i = 0; i < 7; i++){
        results[i] = 0;
    }

    Timer timer;

    int value;
    int index;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000); // range for  random value
    std::uniform_int_distribution<> distribution(1, size-2);  // range for random index


    for(int i = 0; i < numberOfTests; i++)
    {


        // adding an element at the beginning
        value = dis(gen);
        timer.startTime();
        this->addValueFront(value);
        timer.stopTime();
        std::cout << "Insertion of an element at the beginning of an array " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[0] += timer.nanoMeasuredTime();

        // adding an element from the end
        value = dis(gen);
        timer.startTime();
        this->addValueBack(value);
        timer.stopTime();
        std::cout << "Insertion of an element at the end of an array " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[1] += timer.nanoMeasuredTime();

        // adding an  element at the random index
        value = dis(gen);
        index = distribution(gen);
        timer.startTime();
        this->addValue(index,value);
        timer.stopTime();
        std::cout << "Insertion of an element at random index of an array " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[2] += timer.nanoMeasuredTime();

        // deleting an element at the beginning
        timer.startTime();
        this->deleteFromTableFront();
        timer.stopTime();
        std::cout << "Deletion of an element at the beginning of an array " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[3] += timer.nanoMeasuredTime();


        // deleting an element at the end of an array
        timer.startTime();
        this->deleteFromTableBack();
        timer.stopTime();
        std::cout << "Deletion of an element at the end of an array " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[4] += timer.nanoMeasuredTime();

        // deleting an element at  the random position

        index = distribution(gen);
        timer.startTime();
        this->deleteFromTable(index);
        timer.stopTime();
        std::cout << "Deletion of an element at the random index of an array " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[5] += timer.nanoMeasuredTime();


        // searching for a value in an array
        value = dis(gen);
        timer.startTime();
        this->IsValueInTable(value);
        timer.stopTime();
        std::cout << "Search of an element of an array " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[6] += timer.nanoMeasuredTime();

    }


    std::string fileName = "..\\Table\\table" + std::to_string(sizeOfStructure) + ".txt";
    file.open(fileName);
    if (file.is_open()) {
        file << "TEST OF AN  " << sizeOfStructure << " ARRAY OUT OF " << numberOfTests << " PROBES\n";
        file << "Average results of each operation on the array:\n";
        file << "Average time of the insertion of an element at the beginning of the array " << results[0]/numberOfTests << " [ns]\n";
        file << "Average time of the insertion of an element at the end of the array " << results[1]/numberOfTests << " [ns]\n";
        file << "Average time of the insertion of an element at the random index of the array " << results[2]/numberOfTests << " [ns]\n";
        file << "Average time of the deletion of an element at the beginning  of the array " << results[3]/numberOfTests << " [ns]\n";
        file << "Average time of the deletion of an element at the end  of the array " << results[4]/numberOfTests << " [ns]\n";
        file << "Average time of the deletion of an element at the random index  of the array " << results[5]/numberOfTests << " [ns]\n";
        file << "Average time of the search  of a random element in the array " << results[6]/numberOfTests << " [ns]\n";
        file.close();
    } else
        std::cout << "File error - OPEN\n";
}







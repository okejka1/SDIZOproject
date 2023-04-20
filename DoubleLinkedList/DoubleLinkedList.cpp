#include "DoubleLinkedList.h"
#include "../Timer.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <random>


DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;


}

DoubleLinkedList::~DoubleLinkedList() {
    if (head == tail)
        delete head;
    while (head != tail) {
        head = head->next;
        delete head->prev;
    }
}

void DoubleLinkedList::displayList() {
//    cout<<"Head: "<< head << endl;
//    cout<<"Tail: "<< tail << endl;
    if (head == nullptr) {
        std::cout << "list is empty!\n";
        return;
    }
    std::cout << "=============================================\n";
    Node *c = head;
    while (c != tail->next && c != nullptr) {
        std::cout << c->getValue() << " ";
        c = c->next;
    }
    std::cout << std::endl;

    c = tail;
    while (c != head->prev && c != nullptr) {
        std::cout << c->getValue() << " ";
        c = c->prev;
    }
    std::cout << std::endl;
    std::cout << "=============================================\n";
    std::cout << std::endl;


}


void DoubleLinkedList::pushFront(int val) {
//    cout << "Push front\n";
    Node *pushed = new Node;

    pushed->setValue(val);
    pushed->setPrev(nullptr);
    pushed->setNext(head);
    head = pushed;
    if (pushed->next) {
        pushed->next->setPrev(pushed);
//            cout << "wartosc ogona: " <<tail->getValue() << endl; //  testing where the tail is
//            cout << "wartosc glowy: " << head->getValue() << endl; // testing where the head is
    } else {
        tail = pushed; // head and tail on the same position
    }
    size++;
}

void DoubleLinkedList::pushBack(int val) {
//    cout << "Push back\n";
    Node *pushed = new Node;
    pushed->setValue(val);
    pushed->setNext(nullptr);
    pushed->setPrev(tail);
    tail = pushed;
    if (pushed->prev) {
        pushed->prev->setNext(pushed);
//        cout << "wartosc ogona: " << tail->getValue() << endl; //  testing where the tail is
//        cout << "wartosc glowy: " << head->getValue() << endl; // testing where the head is
    } else {
        head = pushed;
    }
    size++;
}


void DoubleLinkedList::addElement(int index, int val) {
    if (index >= 0 && index <= size) {
//        cout << "Add element " << index << ", " << val << ", size: " << size << '\n';
        if (index == 0) {
            pushFront(val);
        } else if (index == size) {
            pushBack(val);
        } else {
            Node *pushed = new Node;
            Node *temp;
            temp = head;
            int i = 0;
            while (temp && i < index) {
                temp = temp->next;
                i++;
            }
            Node *pre = temp->prev;

            pushed->setValue(val);
            pushed->setNext(temp);
            pushed->setPrev(temp->prev);
            pre->setNext(pushed);
            temp->setPrev(pushed);

            size++;
        }
//        cout << "Finished adding\n";

    } else {
        std::cout << "Enter index in range of a list\n";
    }

}

void DoubleLinkedList::loadFromFile(std::string fileName) {
    int elementsCount;
    std::ifstream file;
    file.open(fileName);
    if (file.is_open()) {

        file >> elementsCount;
        if (file.fail()) {
            std::cout << "File error - READ SIZE\n";
            file.close();
        } else {
//            cout << "test!\n";
            clear();
//            cout << "test12\n";
            int val;
            for (int i = 0; i < elementsCount; i++) {
                file >> val;
                if (file.fail()) {
                    std::cout << "File error - READ DATA\n";
                    break;
                } else
                    pushBack(val);
            }
            file.close();
//            cout << "size after:" << size << endl;
        }
    } else
        std::cout << "File error - OPEN\n";


}

void DoubleLinkedList::generateList(int sizeOfList) {

    while (head != nullptr) {
        removeBack();
    }
//    srand(time(NULL));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    int number;
    for (int i = 0; i < sizeOfList; i++) {
//        number = (rand() % 1000);
        number = dis(gen);
        pushFront(number);
    }
}

void DoubleLinkedList::removeElement(Node *element) {
    if (element->prev != nullptr) {
        element->prev->setNext(element->next);
    } else {
        head = element->next;
    }
    if (element->next != nullptr) {
        element->next->setPrev(element->prev);
    } else {
        tail = element->prev;
    }
    delete element;
    size--;

}

void DoubleLinkedList::removeFromIndex(int index){
    Node *element = head;
    for (int i = 0; i < index; i++)
    {
        element = element->next;
    }
    if (element == nullptr) {
        std::cout << "No such value in the list\n";
    } else if (element->prev == nullptr && element->next == nullptr) {

        head = nullptr;
        tail = nullptr;
        delete element;
        size = 0;
    } else if (element->prev == nullptr) {
        removeFront();
    } else if (element->next == nullptr) {
        removeBack();
    } else {
        removeElement(element);
    }



}

void DoubleLinkedList::removeFront() {
    removeElement(head);
}

void DoubleLinkedList::removeBack() {
    removeElement(tail);
}

void DoubleLinkedList::removeGiven(int val) { // removing element with given value from the list

    Node *element = head;
    while (element != nullptr) {
        if (element->getValue() == val) {
            break;
        }
        element = element->next;
    }
    if (element == nullptr) {
        std::cout << "No such value in the list\n";
    } else if (element->prev == nullptr && element->next == nullptr) {

        head = nullptr;
        tail = nullptr;
        delete element;
        size = 0;
    } else if (element->prev == nullptr) {
        removeFront();
    } else if (element->next == nullptr) {
        removeBack();
    } else {
        removeElement(element);
    }

}

bool DoubleLinkedList::isValueInList(int val) {
    if (head == nullptr)
        return false;

    Node *element = head;
    while (element != nullptr) {
        if (element->getValue() == val) {
            std::cout << "There is such a value in the list\n";
            return true;
        }
        element = element->next;
    }
    std::cout << "Value not found in the list\n";
    return false;
}

void DoubleLinkedList::clear() {

    while (head != tail) {
        head = head->next;
        delete head->prev;
        size--;
    }
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }


}

void DoubleLinkedList::measureTime(int numberOfTests, int sizeOfStructure) {
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
        this->pushFront(value);
        timer.stopTime();
        std::cout << "Insertion of an element at the beginning of a list" << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[0] += timer.nanoMeasuredTime();

        // adding an element from the end
        value = dis(gen);
        timer.startTime();
        this->pushBack(value);
        timer.stopTime();
        std::cout << "Insertion of an element at the end of a list " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[1] += timer.nanoMeasuredTime();

        // adding an  element at the random index
        value = dis(gen);
        index = distribution(gen);
        timer.startTime();
        this->addElement(index,value);
        timer.stopTime();
        std::cout << "Insertion of an element at random index of a list" << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[2] += timer.nanoMeasuredTime();

        // deleting an element at the beginning
        timer.startTime();
        this->removeFront();
        timer.stopTime();
        std::cout << "Deletion of an element at the beginning of a list " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[3] += timer.nanoMeasuredTime();


        // deleting an element at the end of a list
        timer.startTime();
        this->removeBack();
        timer.stopTime();
        std::cout << "Deletion of an element at the end of a list " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[4] += timer.nanoMeasuredTime();

        // deleting an element at  the random position

        index = distribution(gen);
        timer.startTime();
        this->removeFromIndex(index);
        timer.stopTime();
        std::cout << "Deletion of an element at the random index of a list " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[5] += timer.nanoMeasuredTime();


        // searching for a value in a list
        value = dis(gen);
        timer.startTime();
        this->isValueInList(value);
        timer.stopTime();
        std::cout << "Search of an element of a list " << timer.nanoMeasuredTime() << " [ns]" << endl;
        results[6] += timer.nanoMeasuredTime();

    }


    std::string fileName = "..\\DoubleLinkedList\\doublelinkedlist" + std::to_string(sizeOfStructure) + ".txt";
    file.open(fileName);
    if (file.is_open()) {
        file << "TEST OF AN  " << sizeOfStructure << " DOUBLELINKEDLIST OUT OF " << numberOfTests << " PROBES\n";
        file << "Average results of each operation on the list:\n";
        file << "Average time of the insertion of an element at the beginning of the list " << results[0]/numberOfTests << " [ns]\n";
        file << "Average time of the insertion of an element at the end of the list " << results[1]/numberOfTests << " [ns]\n";
        file << "Average time of the insertion of an element at the random index of the list " << results[2]/numberOfTests << " [ns]\n";
        file << "Average time of the deletion of an element at the beginning  of the list " << results[3]/numberOfTests << " [ns]\n";
        file << "Average time of the deletion of an element at the end  of the list " << results[4]/numberOfTests << " [ns]\n";
        file << "Average time of the deletion of an element at the random index  of the list " << results[5]/numberOfTests << " [ns]\n";
        file << "Average time of the search  of a random element in the list " << results[6]/numberOfTests << " [ns]\n";
        file.close();
    } else
        std::cout << "File error - OPEN\n";
}



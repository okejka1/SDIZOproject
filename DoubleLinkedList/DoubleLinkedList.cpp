#include "DoubleLinkedList.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>


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
        cout << "list is empty!\n";
        return;
    }
    cout << "=============================================\n";
    Node *c = head;
    while (c != tail->next && c != nullptr) {
        cout << c->getValue() << " ";
        c = c->next;
    }
    cout << endl;

    c = tail;
    while (c != head->prev && c != nullptr) {
        cout << c->getValue() << " ";
        c = c->prev;
    }
    cout << endl;
    cout << "=============================================\n";
    cout << endl;


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
        cout << "Enter index in range of a list\n";
    }

}

void DoubleLinkedList::loadFromFile(string fileName) {
    int elementsCount;
    ifstream file;
    file.open(fileName);
    if (file.is_open()) {

        file >> elementsCount;
        if (file.fail()) {
            cout << "File error - READ SIZE\n";
            file.close();
        } else {
//            cout << "test!\n";
            clear();
//            cout << "test12\n";
            int val;
            for (int i = 0; i < elementsCount; i++) {
                file >> val;
                if (file.fail()) {
                    cout << "File error - READ DATA\n";
                    break;
                } else
                    pushBack(val);
            }
            file.close();
//            cout << "size after:" << size << endl;
        }
    } else
        cout << "File error - OPEN\n";


}

void DoubleLinkedList::generateList(int sizeOfList) {

    while (head != nullptr) {
        removeBack();
    }
    srand(time(NULL));
    int number;
    for (int i = 0; i < sizeOfList; i++) {
        number = (rand() % 1000);
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
        cout << "No such value in the list\n";
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
            cout << "There is such a value in the list\n";
            return true;
        }
        element = element->next;
    }
    cout << "Value not found in the list\n";
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


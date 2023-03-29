#include "Node.h"

using namespace std;

Node::Node() {
    prev = nullptr;
    next = nullptr;
}

Node::~Node() {

}

int Node::getValue() {
    return value;
}

Node* Node::getPrev() {
    return prev;
}

Node* Node::getNext() {
    return next;
}

void Node::setPrev(Node *prev) {
    Node::prev = prev;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

void Node::setValue(int value) {
    Node::value = value;
}

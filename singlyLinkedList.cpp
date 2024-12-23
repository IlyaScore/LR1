#include "header.h"

void LinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void LinkedList::pushHead(const string& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

void LinkedList::pushTail(const string& value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void LinkedList::popHead() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (!head) tail = nullptr;
    delete temp;
    size--;
}

void LinkedList::popTail() {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    size--;
}

void LinkedList::popByValue(const string& value) {
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        if (current->data == value) {
            if (current == head) {
                popHead();
            } else if (current == tail) {
                popTail();
            } else {
                prev->next = current->next;
                delete current;
                size--;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

bool LinkedList::search(const string& value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::read() const {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
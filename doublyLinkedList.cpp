#include "header.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

void DoublyLinkedList::pushHead(const string& value) {
    NodeDL* newNode = new NodeDL(value, head, nullptr);
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::pushTail(const string& value) {
    NodeDL* newNode = new NodeDL(value, nullptr, tail);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

void DoublyLinkedList::popHead() {
    if (!head) return;
    NodeDL* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::popTail() {
    if (!tail) return;
    NodeDL* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::popByValue(const string& value) {
    NodeDL* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

bool DoublyLinkedList::search(const string& value) {
    NodeDL* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::read() {
    NodeDL* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
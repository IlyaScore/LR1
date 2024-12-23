#include "header.h"

Queue::Queue() : head(nullptr), tail(nullptr) {}

void Queue::push(const string& value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::pop() {
    if (head == nullptr) {
        cout << "Очередь пуста" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
}

void Queue::read() {
    if (head == nullptr) {
        cout << "Очередь пуста" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
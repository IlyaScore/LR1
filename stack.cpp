#include "header.h"

Stack::Stack() : top(nullptr) {}

void Stack::push(const string& value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

string Stack::pop() {
    if (top == nullptr) {
        cerr << "Стек пуст!" << endl;
        return "";
    }
    string value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

void Stack::read() {
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
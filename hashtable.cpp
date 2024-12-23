#include "header.h"

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(const string& key) {
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % TABLE_SIZE;
}

void HashTable::insert(const string& key, const string& value) {
    int index = hashFunction(key);
    NodeHT* newNode = new NodeHT(key, value);
    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        newNode->next = table[index];
        table[index] = newNode;
    }
}

string HashTable::get(const string& key) {
    int index = hashFunction(key);
    NodeHT* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return "";
}

void HashTable::remove(const string& key) {
    int index = hashFunction(key);
    NodeHT* current = table[index];
    NodeHT* prev = nullptr;
    while (current != nullptr && current->key != key) {
        prev = current;
        current = current->next;
    }
    if (current != nullptr) {
        if (prev == nullptr) {
            table[index] = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }
}

void HashTable::print() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        NodeHT* current = table[i];
        while (current != nullptr) {
            cout << "Key: " << current->key << ", Value: " << current->value << endl;
            current = current->next;
        }
    }
}
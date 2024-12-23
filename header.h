#pragma once

#include <iostream>
#include <string>
using namespace std;

// Структура узла для хеш-таблицы
struct NodeHT {
    string key;
    string value;
    NodeHT* next;
    NodeHT(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
};

// Хеш-таблица
struct HashTable {
    static const int TABLE_SIZE = 100;
    NodeHT* table[TABLE_SIZE];
    HashTable();
    void insert(const string& key, const string& value);
    string get(const string& key);
    void remove(const string& key);
    void print();
    int hashFunction(const string& key);
};

// Структура узла для списка, очереди, стека
struct Node {
    string data;
    Node* next;
    Node(const string& value) : data(value), next(nullptr) {}
};

// Очередь
struct Queue {
    Node* head;
    Node* tail;
    Queue();
    void push(const string& value);
    void pop();
    void read();
};

// Стек
struct Stack {
    Node* top;
    Stack();
    void push(const string& value);
    string pop();
    void read();
};

// Односвязный список
struct LinkedList {
    Node* head;
    Node* tail;
    int size;
    void init();
    void pushHead(const string& value);
    void pushTail(const string& value);
    void popHead();
    void popTail();
    void popByValue(const string& value);
    bool search(const string& value) const;
    void read() const;
};

// Двусвязный список
struct NodeDL {
    string data;
    NodeDL* next;
    NodeDL* prev;
    NodeDL(const string& value, NodeDL* nextNode = nullptr, NodeDL* prevNode = nullptr) : data(value), next(nextNode), prev(prevNode) {}
};

struct DoublyLinkedList {
    NodeDL* head;
    NodeDL* tail;
    DoublyLinkedList();
    void pushHead(const string& value);
    void pushTail(const string& value);
    void popHead();
    void popTail();
    void popByValue(const string& value);
    bool search(const string& value);
    void read();
};

// Массив
struct Array {
    string data[100];
    int size;
    void init();
    void push(int index, string value);
    void pushEnd(string value);
    string get(int index);
    void pop(int index);
    void replace(int index, string value);
    int length();
    void print();
};

// Узел бинарного дерева
struct TreeNode {
    int digit;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int dig) : digit(dig), left(nullptr), right(nullptr) {}
};

// Complete Binary Tree
struct CBTree {
    TreeNode* root;
    CBTree() : root(nullptr) {}

    // Объявляем функции, которые работают с указателем на TreeNode
    void insert(int value);
    bool find(int value);
    bool isCompleteBT(int index, int nodeCount);
    int countNodes();
    void read();

    // Добавляем объявления для внутренних функций
    TreeNode* insert(TreeNode* root, int value);
    bool find(TreeNode* root, int value);
    bool isCompleteBT(TreeNode* root, int index, int nodeCount);
    int countNodes(TreeNode* root);
    void readByLevels(TreeNode* root);
};
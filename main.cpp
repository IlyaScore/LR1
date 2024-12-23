#include "header.h"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

// Функция для сохранения хеш-таблицы в файл
void saveHashTableToFile(HashTable& ht) {
    ofstream file("txt/hashtable.txt");
    for (int i = 0; i < HashTable::TABLE_SIZE; ++i) {
        NodeHT* current = ht.table[i];
        while (current != nullptr) {
            file << current->key << " " << current->value << endl;
            current = current->next;
        }
    }
    file.close();
}

// Функция для загрузки хеш-таблицы из файла
void loadHashTableFromFile(HashTable& ht) {
    ifstream file("txt/hashtable.txt");
    string key, value;
    while (file >> key >> value) {
        ht.insert(key, value);
    }
    file.close();
}

// Функция для сохранения очереди в файл
void saveQueueToFile(Queue& q) {
    ofstream file("txt/queue.txt");
    Node* current = q.head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Функция для загрузки очереди из файла
void loadQueueFromFile(Queue& q) {
    ifstream file("txt/queue.txt");
    string value;
    while (file >> value) {
        q.push(value);
    }
    file.close();
}

// Функция для сохранения стека в файл
void saveStackToFile(Stack& s) {
    ofstream file("txt/stack.txt");
    Node* current = s.top;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Функция для загрузки стека из файла
void loadStackFromFile(Stack& s) {
    ifstream file("txt/stack.txt");
    string value;
    while (file >> value) {
        s.push(value);
    }
    file.close();
}

// Функция для сохранения односвязного списка в файл
void saveLinkedListToFile(LinkedList& list) {
    ofstream file("txt/singlylist.txt");
    Node* current = list.head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Функция для загрузки односвязного списка из файла
void loadLinkedListFromFile(LinkedList& list) {
    ifstream file("txt/singlylist.txt");
    string value;
    while (file >> value) {
        list.pushTail(value);
    }
    file.close();
}

// Функция для сохранения массива в файл
void saveArrayToFile(Array& arr) {
    ofstream file("txt/array.txt");
    for (int i = 0; i < arr.size; ++i) {
        file << arr.data[i] << endl;
    }
    file.close();
}

// Функция для загрузки массива из файла
void loadArrayFromFile(Array& arr) {
    ifstream file("txt/array.txt");
    string value;
    while (file >> value) {
        arr.pushEnd(value);
    }
    file.close();
}

// Функция для сохранения Complete Binary Tree в файл
void saveCBTreeToFile(CBTree& tree) {
    ofstream file("txt/cbt.txt");
    // Здесь можно реализовать сохранение дерева в файл
    file.close();
}

// Функция для загрузки Complete Binary Tree из файла
void loadCBTreeFromFile(CBTree& tree) {
    ifstream file("txt/cbt.txt");
    // Здесь можно реализовать загрузку дерева из файла
    file.close();
}

// Функция для сохранения двусвязного списка в файл
void saveDoublyLinkedListToFile(DoublyLinkedList& list) {
    ofstream file("txt/doublelist.txt");
    NodeDL* current = list.head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Функция для загрузки двусвязного списка из файла
void loadDoublyLinkedListFromFile(DoublyLinkedList& list) {
    ifstream file("txt/doublelist.txt");
    string value;
    while (file >> value) {
        list.pushTail(value);
    }
    file.close();
}

int main() {
    // Создание папки txt, если её нет
    fs::create_directory("txt");

    // Инициализация структур данных
    HashTable ht;
    Queue q;
    Stack s;
    LinkedList list;
    Array arr;
    CBTree tree;
    DoublyLinkedList dList;

    // Загрузка данных из файлов
    loadHashTableFromFile(ht);
    loadQueueFromFile(q);
    loadStackFromFile(s);
    loadLinkedListFromFile(list);
    loadArrayFromFile(arr);
    loadCBTreeFromFile(tree);
    loadDoublyLinkedListFromFile(dList);

    string command;
    string key, value;
    int index, nodeCount;

    while (true) {
        cout << "> ";
        cin >> command;

        // Работа с хеш-таблицей
        if (command == "HSET") {
            cin >> key >> value;
            ht.insert(key, value);
        } else if (command == "HGET") {
            cin >> key;
            cout << ht.get(key) << endl;
        } else if (command == "HDEL") {
            cin >> key;
            ht.remove(key);
        } else if (command == "HPRINT") {
            ht.print();
        } else if (command == "HEXIT") {
            saveHashTableToFile(ht);
            break;
        }

        // Работа с очередью
        else if (command == "QPUSH") {
            cin >> value;
            q.push(value);
        } else if (command == "QPOP") {
            q.pop();
        } else if (command == "QPRINT") {
            q.read();
        } else if (command == "QEXIT") {
            saveQueueToFile(q);
            break;
        }

        // Работа со стеком
        else if (command == "SPUSH") {
            cin >> value;
            s.push(value);
        } else if (command == "SPOP") {
            s.pop();
        } else if (command == "SPRINT") {
            s.read();
        } else if (command == "SEXIT") {
            saveStackToFile(s);
            break;
        }

        // Работа с односвязным списком
        else if (command == "LPUSHH") {
            cin >> value;
            list.pushHead(value);
        } else if (command == "LPUSHT") {
            cin >> value;
            list.pushTail(value);
        } else if (command == "LPOPH") {
            list.popHead();
        } else if (command == "LPOPT") {
            list.popTail();
        } else if (command == "LPOPV") {
            cin >> value;
            list.popByValue(value);
        } else if (command == "LSEARCH") {
            cin >> value;
            cout << (list.search(value) ? "found" : "not found") << endl;
        } else if (command == "LPRINT") {
            list.read();
        } else if (command == "LEXIT") {
            saveLinkedListToFile(list);
            break;
        }

        // Работа с массивом
        else if (command == "MPUSH") {
            cin >> index >> value;
            arr.push(index, value);
        } else if (command == "MPUSHEND") {
            cin >> value;
            arr.pushEnd(value);
        } else if (command == "MGET") {
            cin >> index;
            cout << arr.get(index) << endl;
        } else if (command == "MPOP") {
            cin >> index;
            arr.pop(index);
        } else if (command == "MREPLACE") {
            cin >> index >> value;
            arr.replace(index, value);
        } else if (command == "MLENGTH") {
            cout << "Array length: " << arr.length() << endl;
        } else if (command == "MPRINT") {
            arr.print();
        } else if (command == "MEXIT") {
            saveArrayToFile(arr);
            break;
        }

        // Работа с Complete Binary Tree
        else if (command == "TINSERT") {
            cin >> value;
            tree.insert(stoi(value));
        } else if (command == "TFIND") {
            cin >> value;
            cout << (tree.find(stoi(value)) ? "found" : "not found") << endl;
        } else if (command == "TISCBT") {
            nodeCount = tree.countNodes();
            cout << "Is Complete Binary Tree? " << (tree.isCompleteBT(0, nodeCount) ? "Yes" : "No") << endl;
        } else if (command == "TPRINT") {
            tree.read();
            cout << endl;
        } else if (command == "TEXIT") {
            saveCBTreeToFile(tree);
            break;
        }

        // Работа с двусвязным списком
        else if (command == "DPUSHH") {
            cin >> value;
            dList.pushHead(value);
        } else if (command == "DPUSHT") {
            cin >> value;
            dList.pushTail(value);
        } else if (command == "DPOPH") {
            dList.popHead();
        } else if (command == "DPOPT") {
            dList.popTail();
        } else if (command == "DPOPV") {
            cin >> value;
            dList.popByValue(value);
        } else if (command == "DSEARCH") {
            cin >> value;
            cout << (dList.search(value) ? "found" : "not found") << endl;
        } else if (command == "DPRINT") {
            dList.read();
        } else if (command == "DEXIT") {
            saveDoublyLinkedListToFile(dList);
            break;
        }

        // Выход из программы
        else if (command == "EXIT") {
            saveHashTableToFile(ht);
            saveQueueToFile(q);
            saveStackToFile(s);
            saveLinkedListToFile(list);
            saveArrayToFile(arr);
            saveCBTreeToFile(tree);
            saveDoublyLinkedListToFile(dList);
            break;
        } else {
            cout << "Unknown command." << endl;
        }
    }

    return 0;
}
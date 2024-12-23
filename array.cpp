#include "header.h"

void Array::init() {
    size = 0;
}

void Array::push(int index, string value) {
    if (index < 0 || index > size || size >= 100) {
        cout << "Ошибка: неверный индекс или массив заполнен." << endl;
        return;
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

void Array::pushEnd(string value) {
    if (size >= 100) {
        cout << "Ошибка: массив заполнен." << endl;
        return;
    }
    data[size] = value;
    size++;
}

string Array::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: неверный индекс." << endl;
        return "";
    }
    return data[index];
}

void Array::pop(int index) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: неверный индекс." << endl;
        return;
    }
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

void Array::replace(int index, string value) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: неверный индекс." << endl;
        return;
    }
    data[index] = value;
}

int Array::length() {
    return size;
}

void Array::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
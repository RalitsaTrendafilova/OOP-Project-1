//
// Created by User on 6.5.2022 г..
//

#include "Diary.h"
Diary::Diary () {
    size = 0;
    capacity = 8;
    users = new User*[capacity];
}
Diary::Diary (const Diary& other) {
    reallocate (other.size);
    size = other.size;
    users = new User*[size];
    for (int i = 0; i < size; ++i) {
        users[i] = other.users[i];
    }
}
Diary& Diary::operator = (const Diary& other) {
    if (this != &other) {
        reallocate (other.size);
        for (int i = 0; i < size; ++i) {
            delete users[i];
        }
        delete[] users;
        size = other.size;
        users = new User*[size];
        for (int i = 0; i < size; ++i) {
            users[i] = other.users[i];
        }
    }
    return *this;
}
void Diary::reallocate (size_t _size) {
    if (_size < capacity) return;
    capacity *= 2;
    User** newData = new User*[capacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = users[i];
    }
    delete[] users;
    users = newData;
}

Diary::~Diary() {
    for (int i = 0; i < size; ++i) {
        delete users[i];
    }
    delete[] users;
    size = 0;
    capacity = 0;
}

void Diary::insert(User* user) {
    size++;
    reallocate(size);
    users[size - 1] = user;
}

User **Diary::getUsers() const {
    return users;
}

int Diary::getSize() const {
    return size;
}

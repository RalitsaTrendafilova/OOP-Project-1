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
void Diary::insert(const User& user) {
    size++;
    reallocate(size);
    users[size - 1] = new User(user);
}
void Diary::checkReviews(const char* destination) {

}
bool Diary::validName(const char* name) {
    int len = strlen (name);
    for (int i = 0; i < len; ++i) {
        if (! ( (name[i] > 'a' && name[i] < 'z') ||
                (name[i] > 'A' && name[i] < 'Z') ||
                (name[i] > '0' && name[i] < '9'))) {
            return false;
        }
    }
    return true;
}
bool Diary::validDate (const Date& start, const Date& end) {
    if (start.year < 1 || end.year < 1) return false;
    if (start.month < 1 || start.month > 12 || end.month < 1 || end.month > 12) return false;
    if (start.day < 1 || start.day > 31 || end.day < 1 || end.day > 31) return  false;
    switch (start.month) {
        case 2:
            if (start.day > 28) return false;
        case 4:
            if (start.day > 30) return false;
        case 6:
            if (start.day > 30) return false;
        case 9:
            if (start.day > 30) return false;
        case 11:
            if (start.day > 30) return false;

    }
    switch (end.month) {
        case 2:
            if (end.day > 28) return false;
        case 4:
            if (end.day > 30) return false;
        case 6:
            if (end.day > 30) return false;
        case 9:
            if (end.day > 30) return false;
        case 11:
            if (end.day > 30) return false;
    }
    if (! (start < end)) return false;
    return true;
}
bool Diary::validPhoto (const char* photo) {
    size_t len = strlen (photo);
    for (int i = 0; i < len; ++i) {
        if (photo[i] == '.') {
            size_t rest = len - i - 1;
            if(rest != 3 && rest != 4) return false;
            char* extension = new char[rest + 1];
            for (int j = i + 1; j < len; ++j) {
                extension[len - i - 1] = photo[j];
            }
            if(extension != "gnp" && extension != "gepg") return false;
            else return true;
        }
        if (!((photo[i] > 'a' && photo[i] < 'z') ||
              (photo[i] > 'A' && photo[i] < 'Z') ||
              (photo[i] == '_'))) {
            return false;
        }
    }
    return true;
}
//snimka.png 10
bool Diary::validGrade(int grade) {
    return grade >= 1 && grade <= 5;
}

User **Diary::getUsers() const {
    return users;
}

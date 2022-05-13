#ifndef PROJECT1_DIARY_H
#define PROJECT1_DIARY_H

#include <iostream>
#include "User.h"
class Diary {
private:
    User** users;
    size_t size;
    size_t capacity;

    void reallocate(size_t _size);
public:
    Diary();
    Diary(const Diary& other);
    Diary& operator = (const Diary& other);
    ~Diary();
    void insert(User* user);
    User** getUsers() const;
    int getSize() const;
};


#endif //PROJECT1_DIARY_H

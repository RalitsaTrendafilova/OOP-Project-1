#ifndef PROJECT1_DIARY_H
#define PROJECT1_DIARY_H

#include <iostream>
#include "User.h"
class Diary {
    User** users;
    size_t size;
    size_t capacity;

    void reallocate(size_t _size);
public:
    Diary();
    //Diary(size_t _size, size_t _capacity, const User** _users);
    Diary(const Diary& other);
    Diary& operator = (const Diary& other);
    ~Diary();
    void insert(const User& user);
    void checkReviews(const char* destination);
    bool validName(const char* name);
    bool validDate(const Date& start, const Date& end);
    bool validPhoto(const char* photo);
    bool validGrade(int grade);
    User** getUsers() const;
};


#endif //PROJECT1_DIARY_H

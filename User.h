#ifndef PROJECT1_USER_H
#define PROJECT1_USER_H
#include <cstring>
#include <cassert>
#include "Trip.h"
class User {
private:
    char* name;
    char* password;
    char* email;

public:
    User();
    User(const char* _name, const char* _password, const char* _email);
    User(const User& other);
    User& operator = (const User& other);
    ~User();
    const char* getName() const;
    const char* getPassword() const;
};


#endif //PROJECT1_USER_H

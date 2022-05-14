#ifndef PROJECT1_USER_H
#define PROJECT1_USER_H
#include <cstring>
#include <cassert>
#include "Trip.h"
/**
 * The User class. An object of this class match an user that is added to the shared database.
 * */
class User {
private:
    char* name; /**< Username of the user. */
    char* password;
    char* email;

public:
    User();/**< Default constructor */
    /**
     * Parameter constructor that creates object of type User by given name, password and e-mail.
     * */
    User(const char* _name, const char* _password, const char* _email);
    User(const User& other);/**< Copy constructor. */
    User& operator = (const User& other);/**< Copy assignment operator. */
    ~User();/**< Destructor. */
    const char* getName() const;/**< Returns the username of the user. */
    const char* getPassword() const;/**< Returns the password of the user. */
};


#endif //PROJECT1_USER_H

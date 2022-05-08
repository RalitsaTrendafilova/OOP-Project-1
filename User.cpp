//
// Created by User on 6.5.2022 г..
//

#include "User.h"
User::User():name (nullptr), password (nullptr), email (nullptr) {}
User::User(const char* _name, const char* _password, const char* _email) {
    assert(_name);
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);

    assert(_password);
    password = new char[strlen(_password) + 1];
    strcpy(password, _password);

    assert(_email);
    email = new char[strlen(_email) + 1];
    strcpy(email, _email);
}
User::User(const User& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    password = new char[strlen(other.password) + 1];
    strcpy(password, other.password);

    email = new char[strlen(other.email) + 1];
    strcpy(email, other.email);
}
User& User::operator = (const User& other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        delete[] password;
        password = new char[strlen(other.password) + 1];
        strcpy(password, other.password);

        delete[] email;
        email = new char[strlen(other.email) + 1];
        strcpy(email, other.email);
    }
    return *this;
}
User::~User() {
    delete[] name;
    delete[] password;
    delete[] email;
}

const char *User::getName() const {
    return name;
}

const char *User::getPassword() const {
    return password;
}

#ifndef PROJECT1_DIARY_H
#define PROJECT1_DIARY_H

#include <iostream>
#include "User.h"
/**
 * The Diary class. This is the shared database that contains all users.
 * It contains function that adds a new user to the database.
 * */
class Diary {
private:
    User** users;/**< Contains pointers to all users in the database.*/
    size_t size;/**< Indicates how many users are signed up in the database */
    size_t capacity;/**< Indicates the capacity of the database. */

    void reallocate(size_t _size);/**< This function increases the capacity of the databes when needed. */
public:
    Diary();/**< Default constructor. */
    Diary(const Diary& other);/**<  Copy constructor.*/
    Diary& operator = (const Diary& other);/**<  Copy assignment operator.*/
    ~Diary();/**<  Destructor */
    void insert(User* user); /**< This function adds a new user to the database.*/
    User** getUsers() const;/**< This function returns pointer to the users in the database. */
    int getSize() const;/**< Returns how many users are there in the database. */
};


#endif //PROJECT1_DIARY_H

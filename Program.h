//
// Created by User on 12.5.2022 г..
//

#ifndef PROJECT1_PROGRAM_H
#define PROJECT1_PROGRAM_H

#include "Diary.h"
using std::cout;
using std::cin;
/**
 * The main Program class. It is a singleton class.
 * This class contains the function that starts the app, validation functions and the functions related to the main
 * actions of the program such as Log In, Sign Up and others.
 */

class Program {
public:
    /**
    * This creates a static Program instance
    * @return instance of type Program
    */
    static Program& getProgram();
    /**
    * This starts the app.
    */
    int start();

private:
    const int MAX_LENGTH = 1024; /**< Maximum length of char* data.*/
    Program() = default;
    bool validName(const char* name);/**< Check if the username is valid. */
    /**< Check if the dates are valid and
     * if the start date is before the end day of the trip. */
    bool validDate (const Date& start, const Date& end);
    bool validPhoto (const char* photo);/**< Check if the name of a photo has the right extension. */
    bool validGrade(int grade);/**< Check if the grade is between 1 and 5. */
    bool isLeapYear(int year);/**< Check if a given year is leap year. */
    /** Adds new user to the database of all users.
     * @return true if the action was successful.
     */
    bool SignUp(Diary& diary);
    /** With this function a user can access his personal database
     * after entering correct username and password.
     * @return true if ... */
    bool LogIn(Diary& diary);
    /** When an user has entered his own database, he can add new trip reviews. */
    bool addTrip(Diary& diary, const char* name);
    /** When an user has entered his own database,
     * he can check the reviews for a desired destination.*/
    bool checkReviews(Diary& diary);
    /** When a person wants to sign up, the system checks if the username
     * that the person want to use is not already token by another user.*/
    bool availableUsername(Diary& diary, const char* name);
};


#endif //PROJECT1_PROGRAM_H

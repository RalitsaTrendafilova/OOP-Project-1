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
 * functionalities of the program such as Log In, Sign Up, Checking the reviews for a given destination
 * and Adding data to the personal databases of the users.
 */

class Program {
public:
    /**
    * This creates a static Program instance
    * @return instance of type Program
    */
    static Program& getProgram();
    /**
    * This function starts the app.
    */
    int start();

private:
    const int MAX_LENGTH = 1024; /**< Maximum length of char* data.*/
    Program() = default;
    bool validName(const char* name);/**< Check if the username is valid. */
    /**
     * Check if the dates are valid and
     * if the start date is before the end date of the trip.
     * */
    bool validDate (const Date& start, const Date& end);
    bool validPhoto (const char* photo);/**< Check if the name of a photo has the right extension. */
    bool validGrade(int grade);/**< Check if the grade is between 1 and 5. */
    bool isLeapYear(int year);/**< Check if a given year is leap year. */
    /**
     * Adds new user to the database of all users after checking if the name is valid and available.
     */
    void SignUp(Diary& diary);
    /**
     * With this function a user can access his personal database
     *  after entering correct username and password.
     * */
    void LogIn(Diary& diary);
    /**
     * When an user has entered his own database, he can add new trip reviews.
     * @return true if the entered data for the trip is valid and no errors has occurred in opening the database file of the user.
     * */
    bool addTrip(Diary& diary, const char* name);
    /**
     * When an user has entered his own database,
     * he can use this function to check the reviews for a desired destination.
     * @return true if no error has occurred in opening the database files of the users.
     * */
    bool checkReviews(Diary& diary);
    /** When a person wants to sign up, the system checks if the username
     * which the person want to use is available.
     * @return true if the username is available.
     * */
    bool availableUsername(Diary& diary, const char* name);
};


#endif //PROJECT1_PROGRAM_H

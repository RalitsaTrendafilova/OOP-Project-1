#ifndef PROJECT1_TRIP_H
#define PROJECT1_TRIP_H
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
using std::cout;
/**
 *  A Date class. It is used to save the start and end date of any trip
 *  so it can be easier to work with this data.
 */
struct Date {
    int day;
    int month;
    int year;
    Date(): day(0), month(0), year(0) {};/**< Default constructor */
    /**
     * Creates object of type Date by given day, month and year.
     * */
    Date(int _day, int _month, int _year): day(_day), month(_month), year(_year) {};
    /**
     * Compares two dates based on which follows the other in time perspective.
     * */
    bool operator < (const Date& other) const {
        return  (this->year < other.year) ||
                (this->year == other.year && this->month < other.month) ||
                (this->year == other.year && this->month == other.month && this->day < other.day);
    };
    /**
     * Function that writes a given date in a file.
     * */
    friend std::ostream& operator <<(std::ostream &out, const Date &date) {
        out<<date.day<<"\n"<<date.month<<"\n"<<date.year<<"\n";
        return out;
    };
    /**
     * Function that reads a given date from a file.
     * */
    friend std::istream& operator >>(std::istream &in, Date &date) {
        in>>date.year>>date.month>>date.day;
        return in;
    };
    /**
     * Prints the date in format YY-MM-DD.
     * */
    void print() const {
        cout<<year<<"-";
        if (month < 10) {
            cout<<"0";
        }
        cout<<month<<"-";
        if (day < 10) {
            cout<<"0";
        }
        cout<<day<<"\n";
    }
};
/**
 * The Trip class. An object of this type matches a trip that an user want to upload to the database.
 * It is also used when an user wants to check the reviews for a given destination.
 * The functionalities of this class enable writing and
 * reading the data from the personal database files of the users.
 * */
class Trip {
private:
    char* destination;/**< Destination of the trip. */
    Date start;/**< Start date of the trip */
    Date end;/**< End date of the trip */
    int grade;/**< Grade that the user have given the trip. */
    char* comment;/**< How the user have commented on the trip. */
    char** photos;/**< Contains the photos which the user has uploaded for the trip. */
    int numPhotos;/**< Number of photos which an user has uploaded for a trip. */

public:
    Trip();/**< Default constructor */
    /**
     * Parameter constructor that is used to create an object of type Trip
     * by given destination, start and end date, comment and list of photos.
     * */
    Trip(char* _destination,  Date& _start,  Date& _end, int _grade,  char* _comment,  char** _photos, int _numPhotos);
    Trip(const Trip& other);/**< Copy constructor */
    Trip& operator = (const Trip& other);/**< Copy assignment operator */
    ~Trip();/**<  Destructor */
    /**
     * This function writes a trip in a file.
     * */
    friend std::ostream &operator<<(std::ostream &out, const Trip &trip);
    /**
     * This function reads a trip from a file.
     * */
    friend std::istream &operator>>(std::istream &in, Trip &trip);
    void print() const;/**< Prints a given trip. */
    int getGrade() const;/**< @return grade of a given trip. */
};
#endif //PROJECT1_TRIP_H

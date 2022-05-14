#ifndef PROJECT1_TRIP_H
#define PROJECT1_TRIP_H
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
using std::cout;
/**
 *  A test class. A more elaborate class description.
 */
struct Date {
    int day;
    int month;
    int year;
    Date(): day(0), month(0), year(0) {};/**< Default constructor */
    Date(int _day, int _month, int _year): day(_day), month(_month), year(_year) {};/**< Creates object of type Date by given day, month and year. */
    /** Compares */
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
        std::cout<<year<<"-"<<month<<"-"<<day<<"\n";
    }
};
/**
 * The Trip class.
 * */
class Trip {
private:
    char* destination;
    Date start;
    Date end;
    int grade;
    char* comment;
    char** photos;
    int numPhotos;

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

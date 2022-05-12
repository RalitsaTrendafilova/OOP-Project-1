#ifndef PROJECT1_TRIP_H
#define PROJECT1_TRIP_H
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
struct Date {
    int day;
    int month;
    int year;
    Date(): day(0), month(0), year(0) {};
    Date(int _day, int _month, int _year): day(_day), month(_month), year(_year) {};
    bool operator < (const Date& other) const {
        return  (this->year < other.year) ||
                (this->year == other.year && this->month < other.month) ||
                (this->year == other.year && this->month == other.month && this->day < other.day);
    };
    friend std::ostream& operator <<(std::ostream &out, const Date &date) {
        out<<date.day<<"\n"<<date.month<<"\n"<<date.year<<"\n";
        return out;
    };
    friend std::istream& operator >>(std::istream &in, Date &date) {
        in>>date.year>>date.month>>date.day;
        return in;
    };
    void print() const {
        std::cout<<year<<"-"<<month<<"-"<<day<<"\n";
    }
};
class Trip {
    char* destination;
    Date start;
    Date end;
    int grade;
    char* comment;
    char** photos;
    int numPhotos;

public:
    Trip();
    Trip(char* _destination,  Date& _start,  Date& _end, int _grade,  char* _comment,  char** _photos, int _numPhotos);
    Trip(const Trip& other);
    Trip& operator = (const Trip& other);
    ~Trip();
    friend std::ostream &operator<<(std::ostream &out, const Trip &trip);
    friend std::istream &operator>>(std::istream &in, Trip &trip);
    const char* getDestination () const;
    const int getGrade() const;
    const Date& getStartDate() const;
    const Date& getEndDate() const;
    const char* getComment() const;
    char** getPhotos() const;
    const int getNumPhotos() const;
};
#endif //PROJECT1_TRIP_H

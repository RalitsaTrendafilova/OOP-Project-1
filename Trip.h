//
// Created by User on 6.5.2022 г..
//

#ifndef PROJECT1_TRIP_H
#define PROJECT1_TRIP_H
#include <cstring>
#include <cassert>
#include <fstream>
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
        out<<date.year<<"-"<<date.month<<"-"<<date.day<<"\n";
        return out;
    };
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
    const char* getDestination () const;
    const int getGrade() const;
    //eventually change photos and others
};
#endif //PROJECT1_TRIP_H

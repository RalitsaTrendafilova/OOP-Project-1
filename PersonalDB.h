//
// Created by User on 7.5.2022 г..
//

#ifndef PROJECT1_PERSONALDB_H
#define PROJECT1_PERSONALDB_H

#include "Trip.h"
class PersonalDB {
    char* name;
    Trip** trips;
    int numTrips;

public:
    PersonalDB();
    PersonalDB(const char* _name);
    PersonalDB(const PersonalDB& other);
    PersonalDB& operator = (const PersonalDB& other);
    ~PersonalDB();
    void addTrip(Trip& trip);
    const char* getName() const;
    const int getNumTrips() const;
    Trip** getTrips() const;
    //operator <<
};


#endif //PROJECT1_PERSONALDB_H

//
// Created by User on 7.5.2022 г..
//

#include "PersonalDB.h"
PersonalDB::PersonalDB(): name(nullptr), trips(nullptr), numTrips(0) {}
PersonalDB::PersonalDB(const char *_name): numTrips(0), trips(nullptr) {
    assert(_name);
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}
PersonalDB::PersonalDB(const PersonalDB& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    numTrips = other.numTrips;
    trips = new Trip*[numTrips];
    for (int i = 0; i < numTrips; ++i) {
        trips[i] = other.trips[i];
    }
}
PersonalDB& PersonalDB::operator = (const PersonalDB& other) {
    if(this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        for (int i = 0; i < numTrips; ++i) {
            delete trips[i];
        }
        delete[] trips;
        numTrips = other.numTrips;
        trips = new Trip*[numTrips];
        for (int i = 0; i < numTrips; ++i) {
            trips[i] = other.trips[i];
        }
    }
    return *this;
}
PersonalDB::~PersonalDB() {
    delete[] name;
    for (int i = 0; i < numTrips; ++i) {
        delete trips[i];
    }
    delete[] trips;
}
void PersonalDB::addTrip(Trip& trip) {
    Trip** newTrips = new Trip*[numTrips + 1];
    for (int i = 0; i < numTrips; ++i) {
        newTrips[i] = trips[i];
    }
    newTrips[numTrips++] = &trip;
    delete[] trips;
    trips = newTrips;
}

const char *PersonalDB::getName() const {
    return name;
}

const int PersonalDB::getNumTrips() const {
    return numTrips;
}

Trip **PersonalDB::getTrips() const {
    return trips;
}



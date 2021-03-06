//
// Created by User on 6.5.2022 г..
//

#include "Trip.h"
Trip::Trip(): destination (nullptr), start(), end(), grade (0), comment (nullptr), photos (nullptr), numPhotos(0){}
Trip::Trip( char* _destination,  Date& _start,  Date& _end, int _grade,  char* _comment,  char** _photos, int _numPhotos) {
    assert(_destination);
    destination = new char[strlen(_destination) + 1];
    strcpy(destination, _destination);

    start = _start;
    end = _end;
    grade = _grade;

    assert(_comment);
    comment = new char[strlen(_comment) + 1];
    strcpy(comment, _comment);

    assert(_photos);
    numPhotos = _numPhotos;
    photos = new char*[numPhotos];
    for (int i = 0; i < numPhotos; ++i) {
        photos[i] = new char[strlen(_photos[i]) + 1];
        strcpy(photos[i], _photos[i]);
    }
}
Trip::Trip(const Trip& other) {
    destination = new char[strlen(other.destination) + 1];
    strcpy(destination, other.destination);

    start = other.start;
    end = other.end;
    grade = other.grade;

    comment = new char[strlen(other.comment) + 1];
    strcpy(comment, other.comment);

    numPhotos = other.numPhotos;
    photos = new char*[numPhotos];
    for (int i = 0; i < numPhotos; ++i) {
        photos[i] = new char[strlen(other.photos[i]) + 1];
        strcpy(photos[i], other.photos[i]);
    }
}
Trip& Trip::operator = (const Trip& other) {
    if(this != &other) {
        delete[] destination;
        destination = new char[strlen(other.destination) + 1];
        strcpy(destination, other.destination);

        start = other.start;
        end = other.end;
        grade = other.grade;

        delete[] comment;
        comment = new char[strlen(other.comment) + 1];
        strcpy(comment, other.comment);

        for (int i = 0; i < numPhotos; ++i) {
            delete[] photos[i];
        }
        delete[] photos;
        numPhotos = other.numPhotos;
        photos = new char*[numPhotos];
        for (int i = 0; i < numPhotos; ++i) {
            photos[i] = new char[strlen(other.photos[i]) + 1];
            strcpy(photos[i], other.photos[i]);
        }
    }
    return *this;
}
Trip::~Trip() {
    delete[] destination;
    delete[] comment;
    for (int i = 0; i < numPhotos; ++i) {
        delete[] photos[i];
    }
    delete[] photos;
}

std::ostream & operator<<(std::ostream &out, const Trip &trip) {
    out<<trip.destination<<'\n';
    out<<trip.start<<trip.end;
    out<<trip.grade<<"\n";
    out<<trip.comment<<"\n";
    out<<trip.numPhotos<<"\n";
    for (int i = 0; i < trip.numPhotos; ++i) {
        out<<trip.photos[i]<<'\n';
    }
    out<<"*\n";
    return out;
}

int Trip::getGrade() const {
    return grade;
}

std::istream &operator>>(std::istream &in, Trip &trip) {
    in >>trip.destination>>trip.start>>trip.end>>trip.grade>>trip.comment>>trip.numPhotos;
    for (int i = 0; i < trip.numPhotos; ++i) {
        in>>trip.photos[i];
    }
    return in;
}

void Trip::print() const {
    cout<<"Destination:\n"<<destination<<"\n";
    cout<<"Time period:\n";
    start.print();
    end.print();
    cout<<"Grade: "<<grade<<"\n";
    cout<<"Comment:\n"<<comment<<"\n";
    cout<<"Photos:\n";
    for (int k = 0; k < numPhotos; ++k) {
        cout<<photos[k]<<"\n";
    }
    cout<<"-----------------\n";
}

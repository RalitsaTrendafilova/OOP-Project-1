//
// Created by User on 12.5.2022 г..
//

#ifndef PROJECT1_PROGRAM_H
#define PROJECT1_PROGRAM_H

#include "Diary.h"
using std::cout;
using std::cin;
class Program {
public:
    static Program& getProgram();
    int start();

private:
    const int MAX_LENGTH = 1024;
    Program() = default;
    bool validName(const char* name);
    bool validDate (const Date& start, const Date& end);
    bool validPhoto (const char* photo);
    bool validGrade(int grade);
    bool SignUp(Diary& diary);
    bool LogIn(Diary& diary);
    bool addTrip(Diary& diary, const char* name);
    bool checkReviews(Diary& diary);
    bool availableUsername(Diary& diary, const char* name);
};


#endif //PROJECT1_PROGRAM_H

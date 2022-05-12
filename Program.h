//
// Created by User on 12.5.2022 г..
//

#ifndef PROJECT1_PROGRAM_H
#define PROJECT1_PROGRAM_H

#include "Diary.h"
using std::cout;
using std::cin;
static int MAX_LENGTH = 1024;
class Program {
public:
    static int start();

private:
    static bool validName(const char* name);
    static bool validDate (const Date& start, const Date& end);
    static bool validPhoto (const char* photo);
    static bool validGrade(int grade);
} program;


#endif //PROJECT1_PROGRAM_H

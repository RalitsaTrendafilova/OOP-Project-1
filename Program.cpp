//
// Created by User on 12.5.2022 г..
//

#include "Program.h"
bool Program::validName(const char* name) {
    size_t len = strlen (name);
    for (int i = 0; i < len; ++i) {
        if (! ( (name[i] >= 'a' && name[i] <= 'z') ||
                (name[i] >= 'A' && name[i] <= 'Z') ||
                (name[i] >= '0' && name[i] <= '9'))) {
            return false;
        }
    }
    return true;
}
bool Program::validDate (const Date& start, const Date& end) {
    if (start.year < 1 || end.year < 1) return false;
    if (start.month < 1 || start.month > 12 || end.month < 1 || end.month > 12) return false;
    if (start.day < 1 || start.day > 31 || end.day < 1 || end.day > 31) return  false;
    switch (start.month) {
        case 2:
            if (start.day > 28) return false;
        case 4:
            if (start.day > 30) return false;
        case 6:
            if (start.day > 30) return false;
        case 9:
            if (start.day > 30) return false;
        case 11:
            if (start.day > 30) return false;

    }
    switch (end.month) {
        case 2:
            if (end.day > 28) return false;
        case 4:
            if (end.day > 30) return false;
        case 6:
            if (end.day > 30) return false;
        case 9:
            if (end.day > 30) return false;
        case 11:
            if (end.day > 30) return false;
    }
    if (! (start < end)) return false;
    return true;
}
bool Program::validPhoto (const char* photo) {
    size_t len = strlen (photo);
    for (int i = 0; i < len; ++i) {
        if (photo[i] == '.') {
            size_t rest = len - i - 1;
            if(rest != 3 && rest != 4) return false;
            char* extension = new char[rest + 1];
            for (int j = i + 1; j < len; ++j) {
                extension[len - j - 1] = photo[j];
            }
            extension[rest] = '\0';
            if(strcmp(extension, "gnp") != 0 && strcmp(extension, "gepj") != 0)
                return false;
            else return true;
        }
        if (!((photo[i] >= 'a' && photo[i] <= 'z') ||
              (photo[i] >= 'A' && photo[i] <= 'Z') ||
              (photo[i] == '_'))) {
            return false;
        }
    }
    return true;
}
bool Program::validGrade(int grade) {
    return grade >= 1 && grade <= 5;
}
int Program::start() {
    bool flag = true;
    short command;
    Diary diary;
    bool successfulLogin = false;
    while (flag) {
        cout<<"Choose command:\n1. Sign up\n2. Log in\n3. Exit\n";
        cin>>command;
        if (command == 1) {
            char* name = new char[MAX_LENGTH];
            char* password = new char[MAX_LENGTH];
            char* email = new char[MAX_LENGTH];
            cout<<"Enter name:";
            cin>>name;
            if(!validName(name)) {
                cout<<"Invalid name!\n";
                return 1;
            }
            for (int i = 0; i < diary.getSize(); ++i) {
                if (strcmp(diary.getUsers()[i]->getName(), name ) == 0) {
                    cout<<"That username is already used!\n";
                    return 1;
                }
            }
            cout<<"\nEnter password:";
            cin>>password;
            cout<<"\nEnter e-mail:";
            cin>>email;
            User newUser(name, password, email);
            diary.insert(newUser);
            delete[] name;
            delete[] password;
            delete[] email;
        }
        else if (command == 2) {
            char* name = new char[MAX_LENGTH];
            char* password = new char[MAX_LENGTH];
            cout<<"Enter name:";
            cin>>name;
            cout<<"\nEnter password:";
            cin>>password;
            for (int i = 0; i < diary.getSize(); ++i) {
                if (strcmp(diary.getUsers()[i]->getName(), name ) == 0 && strcmp(diary.getUsers()[i]->getPassword(), password) == 0) {
                    successfulLogin = true;
                    cout<<"Choose option:\n1.Add trip\n2.Check reviews for destination\n";
                    cin>>command;
                    if (command == 1)  {
                        char* destination = new char[MAX_LENGTH];
                        int day, month, year, grade, numPhotos;
                        char* comment = new char[MAX_LENGTH];
                        char* curPhoto = new char[MAX_LENGTH];
                        cout<<"Enter destination:";
                        cin.clear();
                        cin.ignore();
                        cin.getline(destination, MAX_LENGTH);
                        cout<<"\nEnter start date in format YY-MM-DD:";
                        scanf("%d-%d-%d", &year, &month, &day);
                        Date start(day, month, year);
                        cout<<"\nEnter end date in format YY-MM-DD:";
                        scanf("%d-%d-%d", &year, &month, &day);
                        Date end(day, month, year);
                        if(!validDate(start, end)) {
                            cout<<"Invalid dates!\n";
                            return 1;
                        }
                        cout<<"\nEnter grade:";
                        cin>>grade;
                        if(!validGrade(grade)) {
                            cout<<"Invalid grade!\n";
                            return 1;
                        }
                        cout<<"\nEnter your comment:";
                        cin.clear();
                        cin.ignore();
                        cin.getline(comment, MAX_LENGTH);
                        cout<<"\nEnter how many photos you want to upload:";
                        cin>>numPhotos;
                        char** photos = new char*[numPhotos];
                        cout<<"\nEnter names of the photos:";
                        for (int k = 0; k < numPhotos; ++k) {
                            cin>>curPhoto;
                            if (!validPhoto(curPhoto)) {
                                cout<<"Invalid photo name!\n";
                                return 1;
                            }
                            photos[k] = new char[strlen(curPhoto) + 1];
                            strcpy(photos[k], curPhoto);
                        }
                        Trip newTrip(destination, start, end, grade, comment, photos, numPhotos);
                        char* filename = new char[strlen(name) + 5];
                        strcpy(filename, name);
                        strcat(filename, ".txt");
                        std::ofstream file(filename, std::ofstream::app);
                        if(!file.is_open()) {
                            cout<<"Could not open file for user: "<<name<<'\n';
                            return 1;
                        }
                        file<<newTrip;
                        file.close();
                        delete[] filename;
                        delete[] destination;
                        delete[] curPhoto;
                        delete[] comment;
                        for (int j = 0; j < numPhotos; ++j) {
                            delete[] photos[j];
                        }
                        delete[] photos;
                    }
                    else if (command == 2) {
                        char* searchDestination = new char[MAX_LENGTH];
                        cout<<"Enter destination:";
                        cin.clear();
                        cin.ignore();
                        cin.getline(searchDestination, MAX_LENGTH);
                        bool found = false;
                        int average = 0, count = 0;
                        for (int j = 0; j < diary.getSize(); ++j) {
                            char *filename = new char[strlen(diary.getUsers()[j]->getName()) + 5];
                            strcpy(filename, diary.getUsers()[j]->getName());
                            strcat(filename, ".txt");
                            std::fstream file(filename);
                            if (!file.is_open()) {
                                cout<<"Could not open database of: "<<name;
                                return 1;
                            }
                            char* buffer = new char[MAX_LENGTH];
                            char* destination = new char[MAX_LENGTH];
                            int day, month, year, grade, numPhotos;
                            Date start, end;
                            char* comment = new char[MAX_LENGTH];
                            char* curPhoto = new char[MAX_LENGTH];
                            char** photos;
                            int cnt = 1;
                            while (!file.eof()) {
                                file.getline(buffer, MAX_LENGTH);
                                if(strcmp(buffer, "*") == 0) {
                                    if(strcmp(destination, searchDestination) == 0) {
                                        found = true;
                                        Trip trip(destination, start, end, grade, comment, photos, numPhotos);
                                        cout<<"Destination:\n"<<trip.getDestination()<<"\n";
                                        cout<<"Time period:\n";
                                        trip.getStartDate().print();
                                        trip.getEndDate().print();
                                        cout<<"Grade: "<<trip.getGrade()<<"\n";
                                        cout<<"Comment:\n"<<trip.getComment()<<"\n";
                                        cout<<"Photos:\n";
                                        for (int k = 0; k < trip.getNumPhotos(); ++k) {
                                            cout<<trip.getPhotos()[k]<<"\n";
                                        }
                                        cout<<"-----------------\n";
                                        count++;
                                        average += trip.getGrade();
                                    }
                                    cnt = 1;
                                }
                                else {
                                    switch (cnt) {
                                        case 1:
                                            strcpy(destination, buffer);
                                            break;
                                        case 2:
                                            day = atoi(buffer);
                                            break;
                                        case 3:
                                            month = atoi(buffer);
                                            break;
                                        case 4: {
                                            year = atoi(buffer);
                                            Date date(day, month, year);
                                            start = date;
                                            break;
                                        }
                                        case 5:
                                            day = atoi(buffer);
                                            break;
                                        case 6:
                                            month = atoi(buffer);
                                            break;
                                        case 7: {
                                            year = atoi(buffer);
                                            Date date(day, month, year);
                                            end = date;
                                            break;
                                        }
                                        case 8:
                                            grade = atoi(buffer);
                                            break;
                                        case 9:
                                            strcpy(comment, buffer);
                                            break;
                                        case 10: {
                                            numPhotos = atoi(buffer);
                                            photos = new char*[numPhotos];
                                            break;
                                        }
                                        case 11: {
                                            strcpy(curPhoto, buffer);
                                            photos[0] = new char[strlen(curPhoto) + 1];
                                            strcpy(photos[0], curPhoto);
                                            for (int k = 1; k < numPhotos; ++k) {
                                                file.getline(buffer, MAX_LENGTH);
                                                strcpy(curPhoto, buffer);
                                                photos[k] = new char[strlen(curPhoto) + 1];
                                                strcpy(photos[k], curPhoto);
                                            }
                                            break;
                                        }
                                    }
                                    cnt++;
                                }
                            }

                        }
                        if(!found) {
                            cout<<"No trips to this destination."<<searchDestination<<"\n";
                        }
                        else {
                            cout<<"Average grade is:"<<(average / count)<<'\n';
                        }
                    }
                    else {
                        cout<<"Invalid command!\n";
                    }
                }
            }
            if(!successfulLogin) cout<<"Wrong username or password.\n";
        }
        else if (command == 3) {
            flag = false;
        }
        else {
            cout<<"Invalid command!\n";
            cin.clear();
            cin.ignore();
        }
    }
    return 0;
}
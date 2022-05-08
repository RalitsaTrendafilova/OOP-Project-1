#include <iostream>
#include "Diary.h"
#include "PersonalDB.h"
using std::cout;
using std::cin;
const int MAX_LENGTH = 1024;
void addPersonalDB(PersonalDB** databases, PersonalDB& user) {

}

int main() {
    bool flag = true;
    short command;
    Diary diary;
    int capacity = 8;
    PersonalDB **databases = new PersonalDB*[capacity];
    int num = 0;
    while (flag) {
        cout<<"Choose command:\n1. Sign up\n2.Log in\n3.Exit\n";
        cin>>command;
        if (command == 1) {
            char* name = new char[MAX_LENGTH];
            char* password = new char[MAX_LENGTH];
            char* email = new char[MAX_LENGTH];
            cout<<"Enter name:";
            cin>>name;
            cout<<"\nEnter password:";
            cin>>password;
            cout<<"\nEnter e-mail:";
            cin>>email;
            User newUser(name, password, email);
            diary.insert(newUser);
            num++;
            //create DB
        }
        else if (command == 2) {
            char* name = new char[MAX_LENGTH];
            char* password = new char[MAX_LENGTH];
            cout<<"Enter name:";
            cin>>name;
            cout<<"\nEnter password:";
            cin>>password;
            for (int i = 0; i < num; ++i) {
                if (diary.getUsers()[i]->getName() == name && diary.getUsers()[i]->getPassword() == password) {
                    cout<<"Choose option:\n1.Add trip\n2.Check reviews for destination\n3.See information for trips in file\n";
                    cin>>command;
                    if (command == 1) {
                        for (int j = 0; j < num; ++j) {
                            if (databases[j]->getName() == name) {
                                char* destination = new char[MAX_LENGTH];
                                int day, month, year, grade, numPhotos;
                                char* comment = new char[MAX_LENGTH];
                                char* curPhoto = new char[MAX_LENGTH];
                                cout<<"Enter destination:";
                                cin>>destination;
                                cout<<"\nEnter start date:";
                                cin>>day>>month>>year;
                                Date start(day, month, year);
                                cout<<"\nEnter end date:";
                                cin>>day>>month>>year;
                                Date end(day, month, year);
                                cout<<"\nEnter grade:";
                                cin>>grade;
                                cout<<"\nEnter your comment:";
                                cin>>comment;
                                cout<<"\nEnter how many photos you want to upload:";
                                cin>>numPhotos;
                                char** photos = new char*[numPhotos];
                                cout<<"\nEnter names of the photos:";
                                for (int k = 0; k < numPhotos; ++k) {
                                   cin>>curPhoto;
                                   photos[k] = new char[strlen(curPhoto) + 1];
                                   strcpy(photos[k], curPhoto);
                                }
                                Trip newTrip(destination, start, end, grade, comment, photos, numPhotos);
                                databases[i]->addTrip(newTrip);
                                delete[] destination;
                                delete[] curPhoto;
                                delete[] comment;
                                delete[] photos;
                                break;
                            }
                        }
                    }
                    if (command == 2) {
                        char* destination = new char[MAX_LENGTH];
                        cout<<"Enter destination:";
                        cin>>destination;
                        int average = 0, count = 0;
                        for (int j = 0; j < num; ++j) {
                            int n = databases[j]->getNumTrips();
                            for (int k = 0; k < n; ++k) {
                                if (databases[j]->getTrips()[k]->getDestination() == destination) {
                                    count++;
                                    average += databases[j]->getTrips()[k]->getGrade();
                                    cout<<databases[j]->getTrips()[k];
                                }
                            }
                        }
                        cout<<"Average grade is:"<<(average / count)<<'\n';
                    }
                    if (command == 3) {
                        //file work
                    }
                }
            }
            cout<<"Wrong username or password.\n";
        }
        else if (command == 3) {
            flag = false;
        }
        else {
            cout<<"Invalid command!\n";
        }
    }
    int day, month, year, grade, numPhotos;
    cout<<"Enter start date:";
    cin>>day>>month>>year;
    Date start(day, month, year);
    cout<<"Enter end date:";
    cin>>day>>month>>year;
    Date end(day, month, year);
    cout<<start.day<<start.month<<start.year<<"\n";
    User user("buba", "abs", "sldjcvd");
    diary.insert(user);
    cout<<diary.getUsers()[0]->getPassword();
    return 0;
}

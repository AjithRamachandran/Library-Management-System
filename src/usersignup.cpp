#include <iostream>

#include <usersignup.h>

usersignup::usersignup() {
    usersignup::connectdatabase();
}

usersignup::~usersignup() {
    sqlite3_close(db);
}

void usersignup::connectdatabase(){
    int exit = 0; 
    exit = sqlite3_open("example.db", &db);
    if(exit) {
        std::cout<<"couldnt connect!";
    }
}

void usersignup::createuser() {
    std::string username, password;
    std::cout<<"Enter the Username: ";
    std::cin>>username;
    std::cout<<"Enter the Password: ";
    std::cin>>password;

    // char *zErrMsg = 0;
    // const char* data = "";
    // int rc;
}
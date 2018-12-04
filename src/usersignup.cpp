#include <iostream>

#include <userlogin.h>
#include <usersignup.h>

bool username_exists;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    if(argc>0) {
        username_exists = true;
    }
    return 0;
}

void usersignup::connectdatabase(){
    int exit = 0; 
    exit = sqlite3_open("data/users.sqlite", &db);
    if(exit) {
        std::cout<<"couldnt connect!";
    }
}

void usersignup::createuser() {
    std::string userName, password;
    tryagain:
    std::cout<<"Enter the Username: ";
    std::cin>>userName;
    std::cout<<"Enter the Password: ";
    std::cin>>password;

    char *zErrMsg = 0;
    const char* data = "";
    int rc;

    std::string check = "select * from users where username= '" + userName + "';";
    char *checkError = 0;
    int check_ = sqlite3_exec(db, check.c_str(), callback, 0, &checkError);

    if(username_exists) {
        std::cout<<"Username already exists!"<<std::endl;
        goto tryagain;
    }

    std::string sql = "INSERT INTO users (username, password)" \
        " VALUES ('" + userName + "','" + password + "');";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        std::cout<<"SQL error:"<<zErrMsg;
        sqlite3_free(zErrMsg);
    }
    else {
        system("clear");
        std::cout<<"Records created successfully\nNow you can login!"<<std::endl;
        userlogin user;
        user.login();
    }
}

usersignup::usersignup() {
    usersignup::connectdatabase();
}

usersignup::~usersignup() {
    sqlite3_close(db);
}
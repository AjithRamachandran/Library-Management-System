#include <iostream>
#include <string>

#include <sqlite3.h>
#include <userlogin.h>
#include <usermenu.h>

std::string userlogin::password;

static int callback(void *data, int argc, char **argv, char **azColName){
        userlogin::password = argv[0] ? argv[0] : "NULL";
        return 0;
    }

void userlogin::connectDatabase() {
    int exit_ = 0; 
    exit_ = sqlite3_open("data/users.sqlite", &db);
    if(exit_) {
        std::cout<<"couldnt connect! Contact Admins!"<<std::endl;
        exit(EXIT_FAILURE);
    }
}

void userlogin::login(){
    std::string username, password;
    tryAgain:
    std::cout<<"Enter the Username: ";
    std::cin>>username;
    std::cout<<"Enter the Password: ";
    std::cin>>password;

    char *zErrMsg = 0;
    const char* data = "";
    std::string sql = "SELECT password from users WHERE username='" + username + "'";
    int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ) {
        std::cout<<"SQL error:"<<zErrMsg<<std::endl;
        goto tryAgain;
        sqlite3_free(zErrMsg);
    }
    if(password==userlogin::password){
        usermenu::username = username;
        system("clear");
        usermenu menu;
        menu.mainmenu();
    }
    else {
        system("clear");
        std::cout<<"Wrong Password. Try Again!\n";
        goto tryAgain;
    }
}

userlogin::userlogin() {
    userlogin::connectDatabase();
}

userlogin::~userlogin() {
    sqlite3_close(db);
}
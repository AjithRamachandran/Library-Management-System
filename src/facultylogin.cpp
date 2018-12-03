#include <iostream>
#include <string>
#include <sqlite3.h>

#include <facultylogin.h>
#include <usermenu.h>
#include <facultymenu.h>

std::string facultylogin::password;

static int callback(void *data, int argc, char **argv, char **azColName){
        std::cout<<data;
        std::cout<<azColName;
        std::cout<<argc;
        facultylogin::password = argv[0] ? argv[0] : "NULL";
        return 0;
    }


void facultylogin::connectDatabase() {
    int exit = 0; 
    exit = sqlite3_open("faculty.sqlite", &db);
    if(exit) {
        std::cout<<"couldnt connect!";
    }
}

void facultylogin::login(){
    std::string username, password;
    tryAgain:
    std::cout<<"Enter the Username: ";
    std::cin>>username;
    std::cout<<"Enter the Password: ";
    std::cin>>password;

    char *zErrMsg = 0;
    const char* data = "";
    std::string sql = "SELECT password from faculty WHERE username='" + username + "'";
    int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ) {
        std::cout<<"SQL error:"<<zErrMsg<<std::endl;
        goto tryAgain;
        sqlite3_free(zErrMsg);
    }
    if(password==facultylogin::password){
        system("clear");
        facultymenu menu;
        menu.mainmenu();
    }
    else {
        system("clear");
        std::cout<<"Wrong Password. Try Again!\n";
        goto tryAgain;
    }
}

facultylogin::facultylogin() {
    facultylogin::connectDatabase();
}

facultylogin::~facultylogin() {
    sqlite3_close(db);
}

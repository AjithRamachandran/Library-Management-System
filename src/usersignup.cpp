#include <iostream>

#include <usersignup.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void usersignup::connectdatabase(){
    int exit = 0; 
    exit = sqlite3_open("data/users.db", &db);
    if(exit) {
        std::cout<<"couldnt connect!";
    }
}

void usersignup::createuser() {
    std::string username, password;
    tryagain:
    std::cout<<"Enter the Username: ";
    std::cin>>username;
    std::cout<<"Enter the Password: ";
    std::cin>>password;

    char *zErrMsg = 0;
    const char* data = "";
    int rc;

    std::string check = "select " + username + "from Books;";
    char *checkError = 0;
    int check_ = sqlite3_exec(db, check.c_str(), callback, 0, &checkError);

    if(check_ == SQLITE_OK) {
        std::cout<<"UserName already exists!"<<std::endl;
        goto tryagain;
    }

    std::string sql = "INSERT INTO Books (Tusername, password)" \
        " VALUES ('" + username + "','" + password + "');";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    std::cout<<sql;
    if( rc != SQLITE_OK ){
        std::cout<<"inside if";
        std::cout<<"SQL error:"<<zErrMsg;
        sqlite3_free(zErrMsg);
    }
    else {
        std::cout<<"Records created successfully\n";
    }
}

usersignup::usersignup() {
    usersignup::connectdatabase();
}

usersignup::~usersignup() {
    sqlite3_close(db);
}
#include <iostream>
#include <string>
#include <cstdio>

#include <facultymenu.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void facultymenu::connectDatabase(std::string path, sqlite3 *db) {
    int exit = 0; 
    exit = sqlite3_open(path.c_str(), &db);
    if(exit) {
        std::cout<<"couldnt connect!";
    }
}

void facultymenu::addbook() {
    std::string bookName, authorName, category;
    tryagain:
    std::cout<<"Enter the name of the book to be added: "<<std::endl;
    std::cin>>bookName;
    std::cout<<"Enter the name of Author of the book: "<<std::endl;
    std::cin>>authorName;
    std::cout<<"Enter the name of category of the book: "<<std::endl;
    std::cin>>category;

    std::string check = "select " + bookName + "from Books;";
    char *checkError = 0;
    int check_ = sqlite3_exec(data_db, check.c_str(), callback, 0, &checkError);

    if(check_ == SQLITE_OK) {
        std::cout<<"Book already exists!"<<std::endl;
        goto tryagain;
    }

    std::string sql = "INSERT INTO Books (Title, Author, Category)" \
        " VALUES ('" + bookName + "','" + authorName + "','" + category + "');";
    char *zErrMsg = 0;
    int rc = sqlite3_exec(data_db, sql.c_str(), callback, 0, &zErrMsg);
    std::cout<<sql;
    if( rc != SQLITE_OK ){
        std::cout<<"SQL error:"<<zErrMsg;
        sqlite3_free(zErrMsg);
    }
    else {
        std::cout<<"Records created successfully\n";
    }
}

void facultymenu::deletebook() {
    std::string bookName;
    std::cout<<"Enter the name of the book to be removed: ";
    std::cin>>bookName;

    std::string sql = "DELETE from Books where Title='" + bookName + "';";

    char *zErrMsg = 0;
    const char* data = "";
    int rc = sqlite3_exec(data_db, sql.c_str(), callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}

void facultymenu::removeusers() {
    std::string userName;
    tryagain:
    std::cout<<"Enter the name of the user to be removed: ";
    std::cin>>userName;

    std::string sql = "DELETE from users where username='" + userName + "';";

    char *zErrMsg = 0;
    const char* data = "";
    int rc = sqlite3_exec(user_db, sql.c_str(), callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }

}

void facultymenu::mainmenu() {
    int choice;
    std::cout<<"Welcome!"<<std::endl;
    start:
    std::cout<<"1.Add a book\n2.Delete a book\n3.Remove Users\n4.Exit"<<std::endl;
    std::cin>>choice;
    if(choice==1){
        facultymenu::addbook();
    }
    else if(choice==2){
        facultymenu::deletebook();
    }
    else if(choice==3){
        facultymenu::removeusers();
    }
    else if(choice==4) {
        exit(EXIT_SUCCESS);
    }
    else {
        std::cout<<"Wrong Input! Try Again\n";
        goto start;
    }
}

facultymenu::facultymenu() {
    facultymenu::connectDatabase("data/data.sqlite", data_db);
    facultymenu::connectDatabase("data/users.sqlite", user_db);
}

facultymenu::~facultymenu() {
    sqlite3_close(data_db);
    sqlite3_close(user_db);
}
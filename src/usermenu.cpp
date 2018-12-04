#include <iostream>

#include <usermenu.h>
#include <sqlite3.h>

std::string usermenu::username;
std::string slot_1, slot_2, slot_3;
bool check_result = true;

static int callback2(void *data, int argc, char **argv, char **azColName){
        std::string check = argv[0] ? argv[0] : "NULL";
        if(check.c_str() == "0"){
            check_result = false;
        }
        return 0;
    }

static int callback(void *data, int argc, char **argv, char **azColName){
        slot_1 = azColName[0], argv[0] ? argv[0] : "NULL";
        slot_2 = azColName[0], argv[0] ? argv[0] : "NULL";
        slot_3 = azColName[0], argv[0] ? argv[0] : "NULL";
        return 0;
    }

void usermenu::connectDatabase() {
    int exit_ = 0; 
    exit_ = sqlite3_open("data/users.sqlite", &db);
    if(exit_) {
        std::cout<<"couldnt connect! Contact Admins!"<<std::endl;
        exit(EXIT_FAILURE);
    }
}


void usermenu::mainmenu() {
    int choice;
    std::cout<<"Welcome!"<<std::endl;
    start:
    std::cout<<"1.Borrow a book\n2.Return a book\n3.View current status\n4.Exit"<<std::endl;
    std::cin>>choice;
    if(choice==1){
        usermenu::borrowbook();
    }
    else if(choice==2){
        usermenu::returnbook();
    }
    else if(choice==3){
        usermenu::viewstatus();
    }
    else if(choice==4) {
        exit(EXIT_SUCCESS);
    }
    else {
        std::cout<<"Wrong Input! Try Again\n";
        goto start;
    }
}

void usermenu::borrowbook() {
    // std::string bookName;
    // if(usermenu::can_user_borrow(usermenu::username)) {
    //     std::cout<<"Enter the name of the book you need: "<<std::endl;
    //     std::cin>>bookName;
    //     std::cout<<"Searching if book is available..."<<std::endl;
    //     std::string check_book = "";
    //     int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
    // if( rc != SQLITE_OK ) {
    //     std::cout<<"SQL error:"<<zErrMsg<<std::endl;
    // sqlite3_free(zErrMsg);
    // }
    // if(check_result){
    //     /* code */
    // }
    // else{
    //     std::cout<<"Book not available right now"<<std::endl;
    // }

    // }
}

void usermenu::returnbook() {

}

void usermenu::viewstatus() {

}

// bool usermenu::can_user_borrow(std::string username){
//     bool can = true;
//     char *data = "";
//     char *zErrMsg = 0;
//     std::string sql = "select slot1, slot2, slot3 from users where username='" + username + "';";
//     int rc = sqlite3_exec(db, sql.c_str(), callback, NULL, &zErrMsg);
//     if( rc != SQLITE_OK ) {
//         std::cout<<"SQL error:"<<zErrMsg<<std::endl;
//         sqlite3_free(zErrMsg);
//     }
//     if(slot_1=="0" || slot_2=="0" || slot_3=="0") {
//         return true;
//     }
//     else {
//         return false;
//     }
// }

usermenu::usermenu() {
    usermenu::connectDatabase();
}

usermenu::~usermenu() {
    sqlite3_close(db);
}
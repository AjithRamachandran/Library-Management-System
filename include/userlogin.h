#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <string>
#include <sqlite3.h>

class userlogin {
    public:
        sqlite3 *db;
        static std::string password;
        userlogin();
        ~userlogin();
        void connectDatabase();
        void login();
};

#endif